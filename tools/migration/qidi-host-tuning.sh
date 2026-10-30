#!/usr/bin/env bash
set -euo pipefail

version=3
installed_path=/usr/local/sbin/qidi-plus4-host-tuning
unit_path=/etc/systemd/system/qidi-plus4-host-tuning.service
klipper_dropin=/etc/systemd/system/klipper.service.d/20-qidi-plus4-affinity.conf
background_services=(
    moonraker.service
    nginx.service
    crowsnest.service
    mjpg-streamer.service
    qidi-screen-bridge.service
)

die() {
    printf 'qidi-host-tuning: %s\n' "$*" >&2
    exit 1
}

need_root() {
    [[ $EUID -eq 0 ]] || die "the '$1' action must run as root"
}

cpu_is_online() {
    local wanted="$1" cpu
    for cpu in /sys/devices/system/cpu/cpu[0-9]*; do
        [[ ${cpu##*cpu} == "$wanted" ]] || continue
        [[ ! -r "$cpu/online" || $(<"$cpu/online") == 1 ]]
        return
    done
    return 1
}

validate_host() {
    local cpu
    [[ $(uname -m) == aarch64 ]] || die 'expected an aarch64 RK3328 host'
    grep -aq 'rockchip,rk3328' /proc/device-tree/compatible ||
        die 'device tree is not compatible with rockchip,rk3328'
    [[ -c /dev/ttyS0 ]] || die '/dev/ttyS0 is missing'
    [[ -c /dev/ttyS2 ]] || die '/dev/ttyS2 is missing'
    for cpu in 0 1 2 3; do
        cpu_is_online "$cpu" || die "CPU $cpu is not online; expected the four-core RK3328 host"
    done
}

irq_for_tty() {
    local tty="$1" address="$2" irq='' port_number
    if [[ -r "/sys/class/tty/$tty/device/irq" ]]; then
        irq=$(<"/sys/class/tty/$tty/device/irq")
        [[ $irq =~ ^[0-9]+$ ]] && {
            printf '%s\n' "$irq"
            return 0
        }
    fi
    # /proc/interrupts can omit an idle UART after Klipper has stopped.  The
    # serial driver table retains the platform IRQ assignment in that state.
    port_number=${tty#ttyS}
    if [[ $port_number =~ ^[0-9]+$ && -r /proc/tty/driver/serial ]]; then
        irq=$(awk -v port="$port_number" '
            $1 == (port ":") {
                for (field = 1; field <= NF; field++) {
                    if ($field ~ /^irq:[0-9]+$/) {
                        sub(/^irq:/, "", $field)
                        print $field
                        exit
                    }
                }
            }
        ' /proc/tty/driver/serial)
        [[ $irq =~ ^[0-9]+$ ]] && {
            printf '%s\n' "$irq"
            return 0
        }
    fi
    irq=$(awk -v tty="$tty" -v address="$address" '
        index($0, tty) || index($0, address) {
            gsub(":", "", $1)
            if ($1 ~ /^[0-9]+$/) {
                print $1
                exit
            }
        }
    ' /proc/interrupts)
    if [[ $irq =~ ^[0-9]+$ ]]; then
        printf '%s\n' "$irq"
        return 0
    fi

    # QIDI's Plus4 RK3328 image uses these stable GIC IRQ assignments.  Keep
    # this last, require the expected UART address, and verify that Linux
    # exposes an affinity control for the candidate before accepting it.
    case "$tty:$address" in
        ttyS0:ff110000) irq=25 ;;
        ttyS2:ff130000) irq=27 ;;
        *) return 1 ;;
    esac
    [[ -e "/proc/irq/$irq/smp_affinity_list" ]] || return 1
    printf '%s\n' "$irq"
}

set_governor() {
    local policy available found=0
    for policy in /sys/devices/system/cpu/cpufreq/policy*; do
        [[ -d $policy ]] || continue
        found=1
        available=''
        [[ -r "$policy/scaling_available_governors" ]] &&
            available=$(<"$policy/scaling_available_governors")
        [[ " $available " == *' performance '* ]] ||
            die "the performance governor is unavailable for ${policy##*/}: ${available:-unknown}"
        printf 'performance\n' >"$policy/scaling_governor"
        [[ $(<"$policy/scaling_governor") == performance ]] ||
            die "failed to select the performance governor for ${policy##*/}"
    done
    (( found )) || die 'no CPU frequency policies were found'
}

set_irq_cpu() {
    local tty="$1" address="$2" cpu="$3" irq requested effective
    irq=$(irq_for_tty "$tty" "$address") ||
        die "could not resolve the IRQ for $tty ($address)"
    requested="/proc/irq/$irq/smp_affinity_list"
    [[ -w $requested ]] || die "$requested is not writable"
    printf '%s\n' "$cpu" >"$requested"
    [[ $(<"$requested") == "$cpu" ]] ||
        die "$tty IRQ $irq rejected requested CPU $cpu"
    effective="/proc/irq/$irq/effective_affinity_list"
    if [[ -r $effective && $(<"$effective") != "$cpu" ]]; then
        die "$tty IRQ $irq requested CPU $cpu but effective affinity is $(<"$effective")"
    fi
    printf '%s IRQ=%s CPU=%s\n' "$tty" "$irq" "$cpu"
}

irq_affinity_is_writable() {
    local tty="$1" address="$2" irq
    irq=$(irq_for_tty "$tty" "$address") || return 1
    [[ -w "/proc/irq/$irq/smp_affinity_list" ]]
}

apply_tuning() {
    local wait_seconds="${1:-0}" settle_seconds="${2:-0}" deadline tty address
    need_root apply-late
    validate_host
    if (( wait_seconds > 0 )); then
        deadline=$((SECONDS + wait_seconds))
        while :; do
            if irq_affinity_is_writable ttyS2 ff130000 &&
                    irq_affinity_is_writable ttyS0 ff110000; then
                break
            fi
            (( SECONDS < deadline )) ||
                die "UART IRQs did not appear within ${wait_seconds}s of Klipper starting"
            sleep 1
        done
    fi
    if (( settle_seconds > 0 )); then
        printf 'settling_host_seconds=%s\n' "$settle_seconds"
        sleep "$settle_seconds"
    fi
    set_governor
    # Match QIDI's proven split: toolhead ttyS2 on CPU1, mainboard ttyS0 on CPU2.
    set_irq_cpu ttyS2 ff130000 1
    set_irq_cpu ttyS0 ff110000 2
}

apply_early_tuning() {
    need_root apply-early
    validate_host
    set_governor
}

service_cpu_list() {
    local service="$1" pid
    systemctl is-active --quiet "$service" || {
        printf 'inactive\n'
        return 0
    }
    pid=$(systemctl show "$service" --property MainPID --value)
    [[ $pid =~ ^[1-9][0-9]*$ && -r /proc/$pid/status ]] || {
        printf 'unknown\n'
        return 0
    }
    awk '/^Cpus_allowed_list:/ { print $2; exit }' "/proc/$pid/status"
}

audit_tuning() {
    local mode="${1:-runtime}"
    local failed=0 policy governor irq requested effective cpus policies=0 service
    local tuning_state klipper_state deadline
    printf 'QIDI Plus4 host tuning audit v%s\n' "$version"

    klipper_state=$(systemctl is-active klipper.service 2>/dev/null || true)
    if [[ $klipper_state == activating ]]; then
        printf 'waiting_for_klipper_tuning=90s\n'
        deadline=$((SECONDS + 90))
        while [[ $klipper_state == activating && $SECONDS -lt $deadline ]]; do
            sleep 1
            klipper_state=$(systemctl is-active klipper.service 2>/dev/null || true)
        done
    fi

    printf 'online_cpus=%s\n' "$(< /sys/devices/system/cpu/online)"

    if ! validate_host; then
        return 1
    fi

    for policy in /sys/devices/system/cpu/cpufreq/policy*; do
        [[ -r "$policy/scaling_governor" ]] || continue
        policies=1
        governor=$(<"$policy/scaling_governor")
        printf '%s_governor=%s\n' "${policy##*/}" "$governor"
        [[ $governor == performance ]] || failed=1
    done
    (( policies )) || {
        printf 'cpufreq_policies=missing\n'
        failed=1
    }

    if [[ $mode == runtime ]]; then
    for tty_address_cpu in 'ttyS2 ff130000 1' 'ttyS0 ff110000 2'; do
        read -r tty address cpu <<<"$tty_address_cpu"
        if ! irq=$(irq_for_tty "$tty" "$address"); then
            printf '%s_irq=unresolved\n' "$tty"
            failed=1
            continue
        fi
        requested=$(<"/proc/irq/$irq/smp_affinity_list")
        effective=$requested
        [[ -r "/proc/irq/$irq/effective_affinity_list" ]] &&
            effective=$(<"/proc/irq/$irq/effective_affinity_list")
        printf '%s_irq=%s requested_cpu=%s effective_cpu=%s\n' \
            "$tty" "$irq" "$requested" "$effective"
        [[ $requested == "$cpu" && $effective == "$cpu" ]] || failed=1
    done
    fi

    cpus=$(service_cpu_list klipper.service)
    printf 'klipper_cpus=%s\n' "$cpus"
    [[ $cpus == 1-2 || $cpus == '1,2' || $cpus == inactive ]] || failed=1

    for service in "${background_services[@]}"; do
        cpus=$(service_cpu_list "$service")
        printf '%s_cpus=%s\n' "${service%.service}" "$cpus"
        [[ $cpus == '0,3' || $cpus == inactive ]] || failed=1
    done

    if systemctl is-enabled --quiet qidi-plus4-host-tuning.service; then
        printf 'persistent_service=enabled\n'
    else
        printf 'persistent_service=not-enabled\n'
        failed=1
    fi
    tuning_state=$(systemctl is-active qidi-plus4-host-tuning.service 2>/dev/null || true)
    printf 'persistent_service_state=%s\n' "${tuning_state:-unknown}"
    [[ $tuning_state == active ]] || failed=1

    klipper_state=$(systemctl is-active klipper.service 2>/dev/null || true)
    printf 'klipper_service_state=%s\n' "${klipper_state:-unknown}"
    [[ $klipper_state == active || $klipper_state == inactive ]] || failed=1

    if systemctl is-active --quiet irqbalance.service; then
        printf 'irqbalance=active (warning: it may overwrite UART IRQ affinity)\n'
        failed=1
    else
        printf 'irqbalance=inactive\n'
    fi
    if systemctl is-active --quiet ondemand.service; then
        printf 'ondemand_service=active (warning: it may overwrite the CPU governor)\n'
        failed=1
    else
        printf 'ondemand_service=inactive\n'
    fi

    if (( failed )); then
        printf 'result=not-tuned\n'
        return 1
    fi
    printf 'result=%s\n' "$([[ $mode == runtime ]] && echo tuned || echo early-tuned)"
}

ensure_printer_idle() {
    local response state server_info klippy_state
    systemctl is-active --quiet moonraker.service || return 0
    if ! response=$(curl --fail --silent --max-time 5 \
            'http://127.0.0.1:7125/printer/objects/query?print_stats'); then
        if ! systemctl is-active --quiet klipper.service; then
            printf 'printer_state=klipper-inactive\n'
            return 0
        fi
        # A failed first installation can leave the tuning dependency failed and
        # Klipper unavailable.  Moonraker then returns 503 for printer objects.
        # Repair is safe only when our own unit is failed and Klipper cannot be
        # running a print; unknown failures continue to fail closed.
        if systemctl is-failed --quiet qidi-plus4-host-tuning.service; then
            if server_info=$(curl --fail --silent --max-time 5 \
                    'http://127.0.0.1:7125/server/info'); then
                klippy_state=$(python3 -c '
import json, sys
payload = json.load(sys.stdin)
print(payload.get("result", {}).get("klippy_state", "unknown"))
' <<<"$server_info")
                case "$klippy_state" in
                    disconnected|error|shutdown)
                        printf 'printer_state=klippy-%s-after-failed-tuning-install\n' \
                            "$klippy_state"
                        return 0
                        ;;
                esac
            fi
        fi
        die 'Moonraker is active but its local print state could not be read; refusing to restart'
    fi
    state=$(python3 -c '
import json, sys
payload = json.load(sys.stdin)
print(payload.get("result", {}).get("status", {}).get("print_stats", {}).get("state", "unknown"))
' <<<"$response")
    case "$state" in
        printing|paused)
            die "printer state is '$state'; wait for the job to finish or cancel it explicitly"
            ;;
        unknown)
            die 'Moonraker did not return print_stats.state; refusing to restart'
            ;;
    esac
    printf 'printer_state=%s\n' "$state"
}

install_file() {
    local target="$1" mode="$2"
    if [[ $(readlink -f "$0") != $(readlink -f "$target" 2>/dev/null || true) ]]; then
        install -D -m "$mode" "$0" "$target"
    fi
}

install_tuning() {
    local printer_user="$1" restart_services="$2" service dropin
    need_root install
    validate_host
    id "$printer_user" >/dev/null 2>&1 || die "printer user does not exist: $printer_user"
    if (( restart_services )); then
        ensure_printer_idle
    fi

    # Preflight platform validation and the governor write. UART IRQs may not
    # exist while Klipper is stopped, so they are validated by ExecStartPost
    # after Klipper opens both serial devices.
    apply_early_tuning

    if systemctl list-unit-files irqbalance.service --no-legend 2>/dev/null |
            grep -q '^irqbalance\.service'; then
        systemctl disable --now irqbalance.service 2>/dev/null || true
        systemctl mask irqbalance.service
    fi
    if systemctl list-unit-files ondemand.service --no-legend 2>/dev/null |
            grep -q '^ondemand\.service'; then
        systemctl disable --now ondemand.service 2>/dev/null || true
        systemctl mask ondemand.service
    fi

    install_file "$installed_path" 0755
    install -d -m 0755 "$(dirname "$klipper_dropin")"

    cat >"$unit_path" <<'EOF'
[Unit]
Description=QIDI Plus4 host latency tuning
After=systemd-udev-settle.service irqbalance.service cpufrequtils.service ondemand.service
After=armbian-hardware-monitor.service armbian-hardware-optimize.service
Before=klipper.service moonraker.service
ConditionPathExists=/dev/ttyS0
ConditionPathExists=/dev/ttyS2

[Service]
Type=oneshot
# Invoke Bash explicitly.  The QIDI image can execute the uploaded helper via
# "bash helper", but some builds do not execute scripts from /usr/local/sbin
# directly (or do not expose /usr/bin/env to systemd's service environment).
ExecStart=/bin/bash /usr/local/sbin/qidi-plus4-host-tuning apply-early
RemainAfterExit=yes

[Install]
WantedBy=multi-user.target
EOF

    cat >"$klipper_dropin" <<'EOF'
[Unit]
Requires=qidi-plus4-host-tuning.service
After=qidi-plus4-host-tuning.service

[Service]
CPUAffinity=1 2
# ttyS0's IRQ is registered only after Klipper opens the UART. The "+" prefix
# runs this root-owned host operation with full privileges even though Klipper
# itself runs as the unprivileged printer user. A failure prevents Klipper from
# completing startup.
ExecStartPost=+/bin/bash /usr/local/sbin/qidi-plus4-host-tuning apply-late --wait-seconds 60 --settle-seconds 60
EOF

    for service in "${background_services[@]}"; do
        dropin="/etc/systemd/system/$service.d/20-qidi-plus4-affinity.conf"
        install -d -m 0755 "$(dirname "$dropin")"
        cat >"$dropin" <<'EOF'
[Service]
CPUAffinity=0 3
EOF
    done

    systemctl daemon-reload
    systemctl enable qidi-plus4-host-tuning.service
    if ! systemctl restart qidi-plus4-host-tuning.service; then
        printf '%s\n' \
            'qidi-host-tuning: persistent service failed; systemd diagnostics follow:' >&2
        systemctl status --no-pager --full qidi-plus4-host-tuning.service >&2 || true
        journalctl --no-pager -u qidi-plus4-host-tuning.service -n 50 >&2 || true
        return 1
    fi

    if (( restart_services )); then
        ensure_printer_idle
        if ! systemctl restart klipper.service; then
            printf '%s\n' \
                'qidi-host-tuning: Klipper failed during its post-start tuning check; diagnostics follow:' >&2
            systemctl status --no-pager --full klipper.service >&2 || true
            journalctl --no-pager -u klipper.service -n 80 >&2 || true
            return 1
        fi
        for service in "${background_services[@]}"; do
            systemctl is-active --quiet "$service" || continue
            systemctl restart "$service"
        done
        audit_tuning
    else
        printf 'Host tuning installed; service affinity takes effect on the next service start.\n'
    fi
}

usage() {
    cat <<'EOF'
Usage:
  qidi-host-tuning.sh audit
  qidi-host-tuning.sh apply-early
  qidi-host-tuning.sh apply-late [--wait-seconds SECONDS] [--settle-seconds SECONDS]
  qidi-host-tuning.sh audit-early
  qidi-host-tuning.sh install --printer-user USER [--no-restart]
EOF
}

action="${1:-}"
[[ -n $action ]] || {
    usage
    exit 2
}
shift

case "$action" in
    audit-early)
        (($# == 0)) || die 'audit-early accepts no options'
        audit_tuning early
        ;;
    audit)
        (($# == 0)) || die 'audit accepts no options'
        audit_tuning
        ;;
    apply-early)
        (($# == 0)) || die 'apply-early accepts no options'
        apply_early_tuning
        ;;
    apply-late)
        wait_seconds=0
        settle_seconds=0
        while (($#)); do
            case "$1" in
                --wait-seconds)
                    (($# >= 2)) || die '--wait-seconds requires a value'
                    [[ $2 =~ ^[0-9]+$ ]] ||
                        die '--wait-seconds must be a non-negative integer'
                    wait_seconds="$2"
                    shift 2
                    ;;
                --settle-seconds)
                    (($# >= 2)) || die '--settle-seconds requires a value'
                    [[ $2 =~ ^[0-9]+$ ]] ||
                        die '--settle-seconds must be a non-negative integer'
                    settle_seconds="$2"
                    shift 2
                    ;;
                *)
                    die "unknown apply-late option: $1"
                    ;;
            esac
        done
        apply_tuning "$wait_seconds" "$settle_seconds"
        ;;
    install)
        printer_user="${SUDO_USER:-${USER:-mks}}"
        restart_services=1
        while (($#)); do
            case "$1" in
                --printer-user)
                    (($# >= 2)) || die '--printer-user requires a value'
                    printer_user="$2"
                    shift 2
                    ;;
                --no-restart)
                    restart_services=0
                    shift
                    ;;
                *)
                    die "unknown install option: $1"
                    ;;
            esac
        done
        install_tuning "$printer_user" "$restart_services"
        ;;
    *)
        usage
        exit 2
        ;;
esac
