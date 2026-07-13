/* Named Ghidra pseudocode; not original source. */
/* Program: xindi-1.8.2 */


/* ================================================================
 * Address: 006b9184
 * Symbol: reset_firmware
 * Signature: undefined reset_firmware(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* reset_firmware() */

void reset_firmware(void)

{
  MakerbaseClient *pMVar1;
  string asStack_48 [32];
  string asStack_28 [32];
  allocator aaStack_8 [8];
  
  pMVar1 = *(MakerbaseClient **)PTR_ep_009d2720;
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_28,"FIRMWARE_RESTART\n",aaStack_8);
  json_run_a_gcode(asStack_48,asStack_28);
  MakerbaseClient::Send(pMVar1,asStack_48);
  std::__cxx11::string::~string(asStack_48);
  std::__cxx11::string::~string(asStack_28);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_8);
  return;
}


/* ================================================================
 * Address: 006b9960
 * Symbol: firmware_reset
 * Signature: undefined firmware_reset(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* firmware_reset() */

void firmware_reset(void)

{
  MakerbaseClient *pMVar1;
  string asStack_48 [32];
  string asStack_28 [32];
  allocator aaStack_8 [8];
  
  pMVar1 = *(MakerbaseClient **)PTR_ep_009d2720;
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_28,"FIRMWARE_RESTART\n",aaStack_8);
  json_run_a_gcode(asStack_48,asStack_28);
  MakerbaseClient::Send(pMVar1,asStack_48);
  std::__cxx11::string::~string(asStack_48);
  std::__cxx11::string::~string(asStack_28);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_8);
  return;
}


/* ================================================================
 * Address: 006c1634
 * Symbol: check_offline_update
 * Signature: undefined check_offline_update(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* check_offline_update() */

void check_offline_update(void)

{
  undefined4 uVar1;
  char cVar2;
  MakerbaseClient *pMVar3;
  string asStack_110 [32];
  string asStack_f0 [32];
  allocator aaStack_d0 [8];
  string asStack_c8 [32];
  allocator aaStack_a8 [8];
  string asStack_a0 [32];
  allocator aaStack_80 [8];
  string asStack_78 [32];
  allocator aaStack_58 [8];
  string asStack_50 [32];
  allocator aaStack_30 [8];
  string asStack_28 [32];
  allocator aaStack_8 [8];
  
  pMVar3 = *(MakerbaseClient **)PTR_ep_009d2720;
  json_get_klippy_host_information_abi_cxx11_();
  MakerbaseClient::Send(pMVar3,asStack_110);
                    /* try { // try from 006c1668 to 007c166b has its CatchHandler @ 006c16b8 */
  std::__cxx11::string::~string(asStack_110);
  cVar2 = detect_update();
  if (cVar2 == '\0') {
                    /* try { // try from 006c17a0 to 007c17a3 has its CatchHandler @ 006c17f0 */
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_50,"t8",aaStack_30);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_28,"1",aaStack_8);
                    /* catch() { ... } // from try @ 006c17a0 with catch @ 006c17f0 */
    send_cmd_vis(uVar1,asStack_50,asStack_28);
    std::__cxx11::string::~string(asStack_28);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_8);
                    /* catch() { ... } // from try @ 006c1754 with catch @ 006c1818 */
    std::__cxx11::string::~string(asStack_50);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_30);
                    /* try { // try from 006c1828 to 007c182b has its CatchHandler @ 006c171c */
  }
  else {
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_f0,"t7",aaStack_d0);
    std::allocator<char>::allocator();
                    /* catch() { ... } // from try @ 006c1668 with catch @ 006c16b8 */
    std::__cxx11::string::string<std::allocator<char>>(asStack_c8,"1",aaStack_a8);
                    /* catch() { ... } // from try @ 006c161c with catch @ 006c16e0 */
    send_cmd_vis(uVar1,asStack_f0,asStack_c8);
                    /* try { // try from 006c16f0 to 007c16f3 has its CatchHandler @ 006c15e4 */
    std::__cxx11::string::~string(asStack_c8);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_a8);
    std::__cxx11::string::~string(asStack_f0);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_d0);
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
                    /* catch() { ... } // from try @ 006c1828 with catch @ 006c171c */
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_a0,"b6",aaStack_80);
    std::allocator<char>::allocator();
                    /* try { // try from 006c1754 to 007c1757 has its CatchHandler @ 006c1818 */
    std::__cxx11::string::string<std::allocator<char>>(asStack_78,"1",aaStack_58);
    send_cmd_vis(uVar1,asStack_a0,asStack_78);
    std::__cxx11::string::~string(asStack_78);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_58);
    std::__cxx11::string::~string(asStack_a0);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_80);
  }
  return;
}


/* ================================================================
 * Address: 006d59d8
 * Symbol: run_update_box
 * Signature: undefined run_update_box(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* run_update_box() */

void run_update_box(void)

{
  undefined4 uVar1;
  string asStack_50 [32];
  allocator aaStack_30 [8];
  string asStack_28 [32];
  allocator aaStack_8 [8];
  
  uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_50,"b5",aaStack_30);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_28,"1",aaStack_8);
  send_cmd_vis(uVar1,asStack_50,asStack_28);
  std::__cxx11::string::~string(asStack_28);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_8);
  std::__cxx11::string::~string(asStack_50);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_30);
  return;
}


/* ================================================================
 * Address: 0072d8e4
 * Symbol: u_disk_update
 * Signature: undefined u_disk_update(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* u_disk_update() */

undefined8 u_disk_update(void)

{
  byte local_108 [120];
  char acStack_90 [64];
  char acStack_50 [68];
  uint local_c;
  int local_8;
  int local_4;
  
  local_4 = 1;
  local_8 = 0;
  local_108[0] = 0x61;
  local_108[1] = 0x62;
  local_108[2] = 99;
  local_108[3] = 100;
  local_108[4] = 0x65;
                    /* try { // try from 0072d924 to 0082daf7 has its CatchHandler @ 0072e5e0 */
  local_108[5] = 0x66;
  local_108[6] = 0x67;
  local_108[7] = 0x68;
  for (local_c = 0; (int)local_c < 4; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
      sprintf(acStack_50,"/home/mks/printer_data/gcodes/sd%c%d/QD_Update/QD_Plus4_SOC",
              (ulong)local_108[local_8],(ulong)local_c);
      local_4 = access(acStack_50,0);
      if (local_4 == 0) {
        printf(&DAT_00889130,acStack_50);
        sprintf(acStack_90,"dpkg -i %s; rm %s -f",acStack_50,acStack_50);
        system(acStack_90);
        break;
      }
    }
    if (local_4 == 0) break;
  }
  if (local_4 == -1) {
    puts(&DAT_00889188);
  }
  else {
    close(local_4);
  }
  return 0;
}


/* ================================================================
 * Address: 0072da48
 * Symbol: detect_update
 * Signature: undefined detect_update(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* detect_update() */

byte detect_update(void)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  string asStack_40 [32];
  allocator aaStack_20 [8];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  pcVar2 = (char *)std::__cxx11::string::c_str((string *)base_path_abi_cxx11_);
  dir = opendir(pcVar2);
  if (dir == (DIR *)0x0) {
    uVar5 = std::__cxx11::string::c_str((string *)base_path_abi_cxx11_);
    printf("Usb device path not found: %s\n",uVar5);
  }
  else {
    while (entry = readdir(dir), entry != (dirent *)0x0) {
      pcVar2 = entry->d_name;
      std::allocator<char>::allocator();
      std::__cxx11::string::string<std::allocator<char>>(asStack_40,pcVar2,aaStack_20);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_20);
      lVar3 = std::__cxx11::string::rfind(asStack_40,".bak",0xffffffffffffffff);
      lVar4 = std::__cxx11::string::length(asStack_40);
                    /* try { // try from 0072db2c to 0082db2f has its CatchHandler @ 0072e460 */
      if (lVar3 != lVar4 + -4) {
        lVar3 = std::__cxx11::string::find(asStack_40,"QD_Plus4_PATCH",0);
                    /* try { // try from 0072db68 to 0082db6b has its CatchHandler @ 0072e440 */
        if (lVar3 == 0) {
                    /* try { // try from 0072db84 to 0082db87 has its CatchHandler @ 0072e430 */
          detected_patch_data = 1;
        }
        else {
          lVar3 = std::__cxx11::string::find(asStack_40,"QD_Plus4_UI",0);
          if (lVar3 == 0) {
            detected_ui_data = 1;
          }
          else {
                    /* try { // try from 0072dbe8 to 0082dbeb has its CatchHandler @ 0072e5e0 */
            lVar3 = std::__cxx11::string::find(asStack_40,"QD_Plus4_SOC",0);
            if (lVar3 == 0) {
              detected_soc_data = 1;
            }
          }
        }
      }
                    /* try { // try from 0072dc20 to 0082dc23 has its CatchHandler @ 0072e4a8 */
      std::__cxx11::string::~string(asStack_40);
    }
    closedir(dir);
                    /* try { // try from 0072dc3c to 0082dc3f has its CatchHandler @ 0072e498 */
  }
                    /* try { // try from 0072dc5c to 0082dc5f has its CatchHandler @ 0072e488 */
  local_4 = access("/home/mks/printer_data/gcodes/USB/QD_MCU/MCU",0);
  detected_mcu_data = local_4 == 0;
                    /* try { // try from 0072dc78 to 0082dc7b has its CatchHandler @ 0072e478 */
  local_8 = access("/home/mks/printer_data/gcodes/USB/QD_Update/gcode_macro.cfg",0);
  detected_gcode_cfg = local_8 == 0;
  local_c = access("/home/mks/printer_data/gcodes/USB/QD_Update/printer.cfg",0);
  detected_printer_cfg = local_c == 0;
  local_10 = access("/home/mks/printer_data/gcodes/USB/QD_Update/MKS_THR.cfg",0);
  detected_MKS_THR_cfg = local_10 == 0;
  local_14 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_Gcode",0);
  detected_gcode = local_14 == 0;
  iVar1 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
  if (iVar1 == 0) {
    local_18 = access("/home/mks/printer_data/gcodes/USB/QD_Update/mks.deb",0);
    if (local_18 == 0) {
      detected_soc_deb = 1;
    }
    else {
      detected_soc_deb = 0;
    }
  }
  iVar1 = access("/home/mks/printer_data/gcodes/USB/QD_Update/config.mksini",0);
  detected_mksini = iVar1 == 0;
                    /* try { // try from 0072de6c to 0082de6f has its CatchHandler @ 0072e4f0 */
                    /* try { // try from 0072de88 to 0082de8b has its CatchHandler @ 0072e4e0 */
                    /* try { // try from 0072dea8 to 0082deab has its CatchHandler @ 0072e4d0 */
                    /* try { // try from 0072dec4 to 0082dec7 has its CatchHandler @ 0072e4c0 */
                    /* try { // try from 0072defc to 0082df73 has its CatchHandler @ 0072e5e0 */
  return detected_soc_data | detected_mcu_data | detected_ui_data | detected_printer_cfg |
         detected_MKS_THR_cfg | detected_gcode | detected_soc_deb | detected_gcode_cfg |
         detected_patch_data | iVar1 == 0;
}


/* ================================================================
 * Address: 0072df38
 * Symbol: start_update
 * Signature: undefined start_update(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* start_update() */

void start_update(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  undefined8 uVar5;
  string asStack_258 [32];
  string asStack_238 [32];
  string asStack_218 [32];
  string asStack_1f8 [32];
  allocator aaStack_1d8 [8];
  string asStack_1d0 [32];
  string asStack_1b0 [32];
  string asStack_190 [32];
  string asStack_170 [32];
  string asStack_150 [32];
  string asStack_130 [32];
  string asStack_110 [32];
  string asStack_f0 [32];
  string asStack_d0 [32];
  allocator aaStack_b0 [8];
  string asStack_a8 [32];
  string asStack_88 [32];
  string asStack_68 [32];
  string asStack_48 [32];
  string asStack_28 [39];
  char local_1;
  
  iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
  if ((iVar2 == -1) &&
     (iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_factory_mode.txt",0),
     iVar2 == -1)) {
    local_1 = '\0';
  }
  else {
    local_1 = '\x01';
  }
  system("rm /home/mks/printer_data/gcodes/.cache/*");
                    /* try { // try from 0072dfa8 to 0082dfab has its CatchHandler @ 0072e538 */
  if ((detected_patch_data != '\0') || (detected_soc_data != '\0')) {
                    /* try { // try from 0072dfc4 to 0082dfc7 has its CatchHandler @ 0072e528 */
    pcVar3 = (char *)std::__cxx11::string::c_str((string *)base_path_abi_cxx11_);
    dir = opendir(pcVar3);
                    /* try { // try from 0072dfe4 to 0082dfe7 has its CatchHandler @ 0072e518 */
    if (dir == (DIR *)0x0) {
                    /* try { // try from 0072e308 to 0082e30b has its CatchHandler @ 0072e598 */
      uVar5 = std::__cxx11::string::c_str((string *)base_path_abi_cxx11_);
      printf("Directory not found: %s\n",uVar5);
    }
    else {
                    /* try { // try from 0072e000 to 0082e003 has its CatchHandler @ 0072e508 */
      while (entry = readdir(dir), entry != (dirent *)0x0) {
                    /* try { // try from 0072e048 to 0082e0d7 has its CatchHandler @ 0072e5e0 */
        pcVar3 = entry->d_name;
        std::allocator<char>::allocator();
        std::__cxx11::string::string<std::allocator<char>>(asStack_258,pcVar3,aaStack_1d8);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_1d8);
        lVar4 = std::__cxx11::string::rfind(asStack_258,".bak",0xffffffffffffffff);
        if (lVar4 == -1) {
          lVar4 = std::__cxx11::string::find(asStack_258,"QD_Plus4_PATCH",0);
          if ((lVar4 == 0) ||
             (lVar4 = std::__cxx11::string::find(asStack_258,"QD_Plus4_SOC",0), lVar4 == 0)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
                    /* try { // try from 0072e10c to 0082e10f has its CatchHandler @ 0072e580 */
            std::operator+((string *)base_path_abi_cxx11_,asStack_258);
                    /* try { // try from 0072e128 to 0082e12b has its CatchHandler @ 0072e570 */
            std::operator+("mv ",asStack_238);
                    /* try { // try from 0072e148 to 0082e14b has its CatchHandler @ 0072e560 */
            std::operator+(asStack_150," ");
                    /* try { // try from 0072e164 to 0082e167 has its CatchHandler @ 0072e550 */
            std::operator+(asStack_170,(string *)base_path_abi_cxx11_);
            std::operator+(asStack_190,"mks.deb; dpkg -i --force-overwrite ");
                    /* try { // try from 0072e19c to 0082e27b has its CatchHandler @ 0072e5e0 */
            std::operator+(asStack_1b0,(string *)base_path_abi_cxx11_);
            std::operator+(asStack_1d0,"mks.deb;");
            std::__cxx11::string::~string(asStack_1d0);
            std::__cxx11::string::~string(asStack_1b0);
            std::__cxx11::string::~string(asStack_190);
            std::__cxx11::string::~string(asStack_170);
            std::__cxx11::string::~string(asStack_150);
            pcVar3 = (char *)std::__cxx11::string::c_str(asStack_218);
            system(pcVar3);
            std::__cxx11::string::string(asStack_1f8,asStack_238);
            if (local_1 != '\x01') {
              std::__cxx11::string::operator+=(asStack_1f8,".bak");
            }
            std::operator+("mv ",(string *)base_path_abi_cxx11_);
            std::operator+(asStack_d0,"mks.deb ");
            std::operator+(asStack_f0,asStack_1f8);
            std::operator+(asStack_110,"; sync");
            std::__cxx11::string::operator=(asStack_218,asStack_130);
            std::__cxx11::string::~string(asStack_130);
            std::__cxx11::string::~string(asStack_110);
            std::__cxx11::string::~string(asStack_f0);
                    /* try { // try from 0072e2b0 to 0082e2b3 has its CatchHandler @ 0072e5c8 */
            std::__cxx11::string::~string(asStack_d0);
            pcVar3 = (char *)std::__cxx11::string::c_str(asStack_218);
            system(pcVar3);
            std::__cxx11::string::~string(asStack_1f8);
                    /* try { // try from 0072e2cc to 0082e2cf has its CatchHandler @ 0072e5b8 */
            std::__cxx11::string::~string(asStack_218);
            std::__cxx11::string::~string(asStack_238);
          }
        }
        std::__cxx11::string::~string(asStack_258);
                    /* try { // try from 0072e2ec to 0082e2ef has its CatchHandler @ 0072e5a8 */
      }
      closedir(dir);
    }
  }
  if (detected_gcode != '\0') {
    system("systemctl stop moonraker.service\n");
    system("cp -f /home/mks/gcode_files/USB/QD_Update/QD_gcode/*.gcode /home/mks/gcode_files/");
                    /* catch() { ... } // from try @ 0072d5a4 with catch @ 0072e350 */
    system(
          "find /home/mks/gcode_files/USB/QD_Update/QD_gcode -name \"*.gcode\" -exec basename {} \\; | xargs -I {} chmod 777 /home/mks/gcode_files/{}"
          );
                    /* catch() { ... } // from try @ 0072d588 with catch @ 0072e360 */
    system("chown -R mks:mks /home/mks/printer_data/gcodes\n");
    sleep(3);
                    /* catch() { ... } // from try @ 0072d568 with catch @ 0072e370 */
    system("systemctl restart moonraker.service\n");
  }
                    /* catch() { ... } // from try @ 0072d54c with catch @ 0072e380 */
                    /* catch() { ... } // from try @ 0072d708 with catch @ 0072e398 */
                    /* catch() { ... } // from try @ 0072d6ec with catch @ 0072e3a8 */
  if ((detected_soc_deb != '\0') &&
     (iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0), iVar2 == 0)) {
                    /* catch() { ... } // from try @ 0072d6cc with catch @ 0072e3b8 */
    system("dpkg -i --force-overwrite /home/mks/printer_data/gcodes/USB/QD_Update/mks.deb;sync");
  }
                    /* catch() { ... } // from try @ 0072d6b0 with catch @ 0072e3c8 */
  if (detected_mcu_data != '\0') {
    iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072d8d8 with catch @ 0072e3e0 */
                    /* catch() { ... } // from try @ 0072d8bc with catch @ 0072e3f0 */
    if (iVar2 == 0) {
      system("cp /home/mks/printer_data/gcodes/USB/QD_MCU/MCU /root/klipper.bin;");
                    /* catch() { ... } // from try @ 0072d8a4 with catch @ 0072e400 */
      close_mcu_port();
      system(
            "service klipper stop; /root/hid-flash /root/klipper.bin ttyS0; systemctl start klipper; "
            );
                    /* catch() { ... } // from try @ 0072d888 with catch @ 0072e410 */
    }
    else {
                    /* catch() { ... } // from try @ 0072d86c with catch @ 0072e420 */
      iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072db84 with catch @ 0072e430 */
      if (iVar2 == 0) {
                    /* catch() { ... } // from try @ 0072db68 with catch @ 0072e440 */
        system("cp /home/mks/printer_data/gcodes/USB/QD_MCU/MCU /root/klipper.bin;");
        close_mcu_port();
                    /* catch() { ... } // from try @ 0072db48 with catch @ 0072e450 */
        system(
              "service klipper stop; /root/hid-flash /root/klipper.bin ttyS0; systemctl start klipper; "
              );
      }
      else {
                    /* catch() { ... } // from try @ 0072db2c with catch @ 0072e460 */
        system("cp /home/mks/printer_data/gcodes/USB/QD_MCU/MCU /root/klipper.bin;");
        close_mcu_port();
        system(
              "service klipper stop; /root/hid-flash /root/klipper.bin ttyS0; systemctl start klipper; mv /home/mks/printer_data/gcodes/USB/QD_MCU/MCU /home/mks/printer_data/gcodes/USB/QD_MCU/MCU.bak"
              );
      }
    }
  }
                    /* catch() { ... } // from try @ 0072dc78 with catch @ 0072e478 */
  if (detected_gcode_cfg != '\0') {
                    /* catch() { ... } // from try @ 0072dc5c with catch @ 0072e488 */
    iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072dc3c with catch @ 0072e498 */
                    /* catch() { ... } // from try @ 0072dc20 with catch @ 0072e4a8 */
    if (iVar2 == 0) {
      system(
            "cp /home/mks/printer_data/gcodes/USB/QD_Update/gcode_macro.cfg /home/mks/printer_data/config/gcode_macro.cfg; chmod 777 /home/mks/printer_data/config/gcode_macro.cfg; sync"
            );
    }
    else {
                    /* catch() { ... } // from try @ 0072dec4 with catch @ 0072e4c0 */
      iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072dea8 with catch @ 0072e4d0 */
      if (iVar2 == 0) {
                    /* catch() { ... } // from try @ 0072de88 with catch @ 0072e4e0 */
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/gcode_macro.cfg /home/mks/printer_data/config/gcode_macro.cfg; chmod 777 /home/mks/printer_data/config/gcode_macro.cfg; sync"
              );
      }
      else {
                    /* catch() { ... } // from try @ 0072de6c with catch @ 0072e4f0 */
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/gcode_macro.cfg /home/mks/printer_data/config/gcode_macro.cfg; chmod 777 /home/mks/printer_data/config/gcode_macro.cfg; mv /home/mks/printer_data/gcodes/USB/QD_Update/gcode_macro.cfg /home/mks/printer_data/gcodes/USB/QD_Update/gcode_macro.cfg.bak; sync"
              );
      }
    }
  }
                    /* catch() { ... } // from try @ 0072e000 with catch @ 0072e508 */
  if (detected_printer_cfg != '\0') {
                    /* catch() { ... } // from try @ 0072dfe4 with catch @ 0072e518 */
    iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072dfc4 with catch @ 0072e528 */
    if (iVar2 == 0) {
                    /* catch() { ... } // from try @ 0072dfa8 with catch @ 0072e538 */
      system(
            "cp /home/mks/printer_data/gcodes/USB/QD_Update/printer.cfg /home/mks/printer_data/config/printer.cfg; chmod 777 /home/mks/printer_data/config/printer.cfg; sync"
            );
    }
    else {
                    /* catch() { ... } // from try @ 0072e164 with catch @ 0072e550 */
      iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072e148 with catch @ 0072e560 */
      if (iVar2 == 0) {
                    /* catch() { ... } // from try @ 0072e128 with catch @ 0072e570 */
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/printer.cfg /home/mks/printer_data/config/printer.cfg; chmod 777 /home/mks/printer_data/config/printer.cfg; sync"
              );
      }
      else {
                    /* catch() { ... } // from try @ 0072e10c with catch @ 0072e580 */
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/printer.cfg /home/mks/printer_data/config/printer.cfg; chmod 777 /home/mks/printer_data/config/printer.cfg; mv /home/mks/printer_data/gcodes/USB/QD_Update/printer.cfg /home/mks/printer_data/gcodes/USB/QD_Update/printer.cfg.bak; sync"
              );
      }
    }
  }
  if (detected_MKS_THR_cfg != '\0') {
                    /* catch() { ... } // from try @ 0072e308 with catch @ 0072e598 */
    iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072e2ec with catch @ 0072e5a8 */
                    /* catch() { ... } // from try @ 0072e2cc with catch @ 0072e5b8 */
    if (iVar2 == 0) {
      system(
            "cp /home/mks/printer_data/gcodes/USB/QD_Update/MKS_THR.cfg /home/mks/printer_data/config/MKS_THR.cfg; chmod 777 /home/mks/printer_data/config/MKS_THR.cfg; sync"
            );
                    /* catch() { ... } // from try @ 0072e2b0 with catch @ 0072e5c8 */
    }
    else {
      iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_factory_mode.txt",0);
                    /* catch() { ... } // from try @ 0072d444 with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072d5ec with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072d744 with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072d924 with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072dbe8 with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072dd3c with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072defc with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072e048 with catch @ 0072e5e0
                       catch() { ... } // from try @ 0072e19c with catch @ 0072e5e0 */
      if (iVar2 == 0) {
                    /* try { // try from 0072e5f0 to 0082e5f3 has its CatchHandler @ 0072d384 */
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/MKS_THR.cfg /home/mks/printer_data/config/MKS_THR.cfg; chmod 777 /home/mks/printer_data/config/MKS_THR.cfg; sync"
              );
      }
      else {
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/MKS_THR.cfg /home/mks/printer_data/config/MKS_THR.cfg; chmod 777 /home/mks/printer_data/config/MKS_THR.cfg; mv /home/mks/printer_data/gcodes/USB/QD_Update/MKS_THR.cfg /home/mks/printer_data/gcodes/USB/QD_Update/MKS_THR.cfg.bak; sync"
              );
      }
    }
  }
  if (detected_mksini != '\0') {
    iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_factory_mode.txt",0);
    if (iVar2 == 0) {
      system(
            "cp /home/mks/printer_data/gcodes/USB/QD_Update/config.mksini /home/mks/printer_data/config/config.mksini; chmod 777 /home/mks/printer_data/config/config.mksini; sync"
            );
    }
    else {
      iVar2 = access("/home/mks/printer_data/gcodes/USB/QD_Update/QD_factory_mode.txt",0);
      if (iVar2 == 0) {
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/config.mksini /home/mks/printer_data/config/config.mksini; chmod 777 /home/mks/printer_data/config/config.mksini; sync"
              );
      }
      else {
        system(
              "cp /home/mks/printer_data/gcodes/USB/QD_Update/config.mksini /home/mks/printer_data/config/config.mksini; chmod 777 /home/mks/printer_data/config/config.mksini; mv /home/mks/printer_data/gcodes/USB/QD_Update/config.mksini /home/mks/printer_data/gcodes/USB/QD_Update/config.mksini.bak; sync"
              );
      }
    }
  }
  if (detected_ui_data != '\0') {
    pcVar3 = (char *)std::__cxx11::string::c_str((string *)base_path_abi_cxx11_);
    dir = opendir(pcVar3);
    if (dir == (DIR *)0x0) {
      uVar5 = std::__cxx11::string::c_str((string *)base_path_abi_cxx11_);
      printf("Directory not found: %s\n",uVar5);
    }
    else {
      do {
        entry = readdir(dir);
        if (entry == (dirent *)0x0) break;
        pcVar3 = entry->d_name;
        std::allocator<char>::allocator();
        std::__cxx11::string::string<std::allocator<char>>(asStack_238,pcVar3,aaStack_b0);
        std::allocator<char>::~allocator((allocator<char> *)aaStack_b0);
        lVar4 = std::__cxx11::string::find(asStack_238,"QD_Plus4_UI",0);
        if (lVar4 == 0) {
          std::operator+((string *)base_path_abi_cxx11_,asStack_238);
          std::operator+("cp ",asStack_218);
          std::operator+(asStack_a8," /root/800_480.tft; ");
          std::__cxx11::string::~string(asStack_a8);
          if (local_1 != '\x01') {
            std::operator+("mv ",asStack_218);
            std::operator+(asStack_28," ");
            std::operator+(asStack_48,asStack_218);
            std::operator+(asStack_68,".bak; ");
            std::__cxx11::string::operator+=(asStack_1f8,asStack_88);
            std::__cxx11::string::~string(asStack_88);
            std::__cxx11::string::~string(asStack_68);
            std::__cxx11::string::~string(asStack_48);
            std::__cxx11::string::~string(asStack_28);
          }
          std::__cxx11::string::operator+=(asStack_1f8,"sync");
          pcVar3 = (char *)std::__cxx11::string::c_str(asStack_1f8);
          system(pcVar3);
          std::__cxx11::string::~string(asStack_1f8);
          std::__cxx11::string::~string(asStack_218);
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        std::__cxx11::string::~string(asStack_238);
      } while (bVar1);
      closedir(dir);
    }
  }
  update_finished_tips();
  return;
}


/* ================================================================
 * Address: 0082b0cc
 * Symbol: btn_online_update_click_handler
 * Signature: undefined btn_online_update_click_handler(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* btn_online_update_click_handler() */

void btn_online_update_click_handler(void)

{
  undefined4 uVar1;
  char cVar2;
  bool bVar3;
  string asStack_2e8 [32];
  string asStack_2c8 [32];
  string asStack_2a8 [32];
  allocator aaStack_288 [8];
  string asStack_280 [32];
  string asStack_260 [32];
  allocator aaStack_240 [8];
  string asStack_238 [32];
  allocator aaStack_218 [8];
  string asStack_210 [32];
  allocator aaStack_1f0 [8];
  string asStack_1e8 [32];
  allocator aaStack_1c8 [8];
  string asStack_1c0 [32];
  allocator aaStack_1a0 [8];
  string asStack_198 [32];
  allocator aaStack_178 [8];
  string asStack_170 [32];
  allocator aaStack_150 [8];
  string asStack_148 [32];
  allocator aaStack_128 [8];
  string asStack_120 [32];
  string asStack_100 [32];
  allocator aaStack_e0 [8];
  string asStack_d8 [32];
  allocator aaStack_b8 [8];
  string asStack_b0 [32];
  allocator aaStack_90 [8];
  string asStack_88 [32];
  allocator aaStack_68 [8];
  string asStack_60 [32];
  allocator aaStack_40 [8];
  string asStack_38 [32];
  allocator aaStack_18 [8];
  thread atStack_10 [8];
  _lambda___1_ a_Stack_8 [8];
  
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_2a8,"wlan0",aaStack_288);
  get_ip_address(asStack_2a8);
  std::__cxx11::string::~string(asStack_2a8);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_288);
  cVar2 = std::__cxx11::string::empty(asStack_2c8);
  if (cVar2 != '\0') {
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_260,"eth0",aaStack_240);
    get_ip_address(asStack_260);
    std::__cxx11::string::operator=(asStack_2c8,asStack_280);
    std::__cxx11::string::~string(asStack_280);
    std::__cxx11::string::~string(asStack_260);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_240);
  }
  cVar2 = std::__cxx11::string::empty(asStack_2c8);
  if (cVar2 == '\0') {
    mksini_load();
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_198,"app_server",aaStack_178);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_170,"name",aaStack_150);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_148,"aws",aaStack_128);
    mksini_getstring(asStack_2e8,asStack_198,asStack_170,asStack_148);
    std::__cxx11::string::~string(asStack_148);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_128);
                    /* catch() { ... } // from try @ 0082b3f0 with catch @ 0082b36c */
    std::__cxx11::string::~string(asStack_170);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_150);
    std::__cxx11::string::~string(asStack_198);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_178);
    mksini_free();
    printf("%slocal server\n%s",&DAT_008aacc0,&DAT_008aacb8);
    mksini_load_from_path("/root/xindi/version");
    std::allocator<char>::allocator();
                    /* try { // try from 0082b3c0 to 0092b3c3 has its CatchHandler @ 0082b3d0 */
                    /* catch() { ... } // from try @ 0082b3c0 with catch @ 0082b3d0 */
    std::__cxx11::string::string<std::allocator<char>>(asStack_100,"version",aaStack_e0);
    std::allocator<char>::allocator();
                    /* try { // try from 0082b3f0 to 0092b3f3 has its CatchHandler @ 0082b36c */
    std::__cxx11::string::string<std::allocator<char>>(asStack_d8,"soc",aaStack_b8);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_b0,"V1.0.0",aaStack_90);
    mksini_getstring(asStack_120,asStack_100,asStack_d8,asStack_b0);
    std::__cxx11::string::operator=((string *)local_soc_version,asStack_120);
    std::__cxx11::string::~string(asStack_120);
    std::__cxx11::string::~string(asStack_b0);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_90);
    std::__cxx11::string::~string(asStack_d8);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_b8);
    std::__cxx11::string::~string(asStack_100);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_e0);
    mksini_free();
    printf("%slocal soc\n%s",&DAT_008aacc0,&DAT_008aacb8);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_88,"NA",aaStack_68);
                    /* catch() { ... } // from try @ 0082b554 with catch @ 0082b4d0 */
    bVar3 = std::operator==(asStack_88,"CN");
    std::__cxx11::string::~string(asStack_88);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_68);
    if (bVar3) {
      std::allocator<char>::allocator();
      std::__cxx11::string::string<std::allocator<char>>
                (asStack_60,"https://download_aliyun.qidi3dprinter.com/QD_Plus4",aaStack_40);
                    /* try { // try from 0082b524 to 0092b527 has its CatchHandler @ 0082b534 */
      std::__cxx11::string::operator=((string *)base_download_url,asStack_60);
                    /* catch() { ... } // from try @ 0082b524 with catch @ 0082b534 */
      std::__cxx11::string::~string(asStack_60);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_40);
    }
    else {
      std::allocator<char>::allocator();
                    /* try { // try from 0082b554 to 0092b557 has its CatchHandler @ 0082b4d0 */
      std::__cxx11::string::string<std::allocator<char>>
                (asStack_38,"https://download_aws.qidi3dprinter.com/QD_Plus4",aaStack_18);
      std::__cxx11::string::operator=((string *)base_download_url,asStack_38);
      std::__cxx11::string::~string(asStack_38);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_18);
    }
    std::thread::thread<btn_online_update_click_handler()::_lambda()_1_,,void>(atStack_10,a_Stack_8)
    ;
    std::thread::detach();
    std::thread::~thread(atStack_10);
    std::__cxx11::string::~string(asStack_2e8);
  }
  else {
    page_to(0x20);
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_238,"t8",aaStack_218);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_210,"1",aaStack_1f0);
    send_cmd_vis(uVar1,asStack_238,asStack_210);
    std::__cxx11::string::~string(asStack_210);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_1f0);
    std::__cxx11::string::~string(asStack_238);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_218);
    sleep(0);
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_1e8,"t8",aaStack_1c8);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_1c0,"1",aaStack_1a0);
    send_cmd_vis(uVar1,asStack_1e8,asStack_1c0);
    std::__cxx11::string::~string(asStack_1c0);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_1a0);
    std::__cxx11::string::~string(asStack_1e8);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_1c8);
  }
  std::__cxx11::string::~string(asStack_2c8);
  return;
}


/* ================================================================
 * Address: 0082b7a8
 * Symbol: btn_update_click_handler
 * Signature: undefined btn_update_click_handler(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* btn_update_click_handler() */

void btn_update_click_handler(void)

{
  undefined4 uVar1;
  string asStack_100 [32];
  allocator aaStack_e0 [8];
  string asStack_d8 [32];
  allocator aaStack_b8 [8];
  string asStack_b0 [32];
  allocator aaStack_90 [8];
  string asStack_88 [32];
  allocator aaStack_68 [8];
  string asStack_60 [32];
  allocator aaStack_40 [8];
  string asStack_38 [32];
  allocator aaStack_18 [8];
  thread atStack_10 [8];
  _lambda___1_ a_Stack_8 [8];
  
  page_to(0x2f);
  uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_100,"j0",aaStack_e0);
                    /* try { // try from 0082b7ec to 0092b7ef has its CatchHandler @ 0082b7fc */
  std::allocator<char>::allocator();
                    /* catch() { ... } // from try @ 0082b7ec with catch @ 0082b7fc */
  std::__cxx11::string::string<std::allocator<char>>(asStack_d8,"1",aaStack_b8);
                    /* try { // try from 0082b81c to 0092b81f has its CatchHandler @ 0082b798 */
  send_cmd_vis(uVar1,asStack_100,asStack_d8);
  std::__cxx11::string::~string(asStack_d8);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_b8);
  std::__cxx11::string::~string(asStack_100);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_e0);
  uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_b0,"t1",aaStack_90);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_88,"1",aaStack_68);
  send_cmd_vis(uVar1,asStack_b0,asStack_88);
  std::__cxx11::string::~string(asStack_88);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_68);
  std::__cxx11::string::~string(asStack_b0);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_90);
  uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
  std::allocator<char>::allocator();
                    /* catch() { ... } // from try @ 0082b980 with catch @ 0082b8fc */
  std::__cxx11::string::string<std::allocator<char>>(asStack_60,"t2",aaStack_40);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_38,"1",aaStack_18);
  send_cmd_vis(uVar1,asStack_60,asStack_38);
  std::__cxx11::string::~string(asStack_38);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_18);
                    /* try { // try from 0082b950 to 0092b953 has its CatchHandler @ 0082b960 */
  std::__cxx11::string::~string(asStack_60);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_40);
                    /* catch() { ... } // from try @ 0082b950 with catch @ 0082b960 */
  puts("Downloading from remote server");
  std::thread::thread<btn_update_click_handler()::_lambda()_1_,,void>(atStack_10,a_Stack_8);
  std::thread::detach();
                    /* try { // try from 0082b980 to 0092b983 has its CatchHandler @ 0082b8fc */
  std::thread::~thread(atStack_10);
  return;
}


/* ================================================================
 * Address: 0082e6cc
 * Symbol: install_update
 * Signature: undefined install_update(string * param_1, string * param_2)
 * ================================================================ */

/* install_update(std::__cxx11::string const&, std::__cxx11::string const&) */

undefined4 install_update(string *param_1,string *param_2)

{
  bool bVar1;
  long lVar2;
  char *pcVar3;
  undefined4 unaff_w19;
  string asStack_150 [32];
  string asStack_130 [32];
  string asStack_110 [32];
  string asStack_f0 [32];
  path apStack_d0 [32];
  string asStack_b0 [32];
  string asStack_90 [32];
  string asStack_70 [32];
  path apStack_50 [32];
  string asStack_30 [40];
  int local_8;
  int local_4;
  
  std::__cxx11::string::string(asStack_130,param_1);
  printf("Start installing %s\n",asStack_130);
  std::__cxx11::string::~string(asStack_130);
  lVar2 = std::__cxx11::string::find(param_1,"SOC",0);
  if (lVar2 == -1) {
                    /* try { // try from 0082e810 to 0092e813 has its CatchHandler @ 0082ea54 */
    lVar2 = std::__cxx11::string::find(param_1,"UI",0);
    if (lVar2 == -1) {
                    /* catch() { ... } // from try @ 0082e1b8 with catch @ 0082e92c */
      std::__cxx11::string::string(asStack_30,param_1);
                    /* catch() { ... } // from try @ 0082e19c with catch @ 0082e93c */
                    /* catch() { ... } // from try @ 0082e180 with catch @ 0082e94c */
      printf("%sComponent %s not found.\n%s",&DAT_008aadd8,asStack_30,&DAT_008aacb8);
      std::__cxx11::string::~string(asStack_30);
      return 0xfffffffa;
                    /* catch() { ... } // from try @ 0082e164 with catch @ 0082e95c */
    }
                    /* try { // try from 0082e82c to 0092e82f has its CatchHandler @ 0082ea44 */
                    /* try { // try from 0082e840 to 0092e843 has its CatchHandler @ 0082ea34 */
    std::operator+("cp ",param_2);
                    /* try { // try from 0082e85c to 0092e85f has its CatchHandler @ 0082ea24 */
    std::operator+(asStack_b0," /root/800_480.tft");
    std::__cxx11::string::~string(asStack_b0);
                    /* try { // try from 0082e868 to 0092e86b has its CatchHandler @ 0082ea14 */
    pcVar3 = (char *)std::__cxx11::string::c_str(asStack_150);
    local_8 = system(pcVar3);
    bVar1 = local_8 == 0;
    if (bVar1) {
      std::__cxx11::string::string(asStack_70,param_1);
      printf("Successfully installed %s\n",asStack_70);
                    /* try { // try from 0082e8ec to 0092ea87 has its CatchHandler @ 0082df38 */
      std::__cxx11::string::~string(asStack_70);
      boost::filesystem::path::path(apStack_50,param_2);
      boost::filesystem::remove(apStack_50);
      boost::filesystem::path::~path(apStack_50);
    }
    else {
      std::__cxx11::string::string(asStack_90,param_1);
                    /* try { // try from 0082e89c to 0092e8ab has its CatchHandler @ 0082ea54 */
      printf("%sError: Failed to install %s\n%s",&DAT_008aadd8,asStack_90,&DAT_008aacb8);
      std::__cxx11::string::~string(asStack_90);
      unaff_w19 = 0xfffffffa;
    }
    std::__cxx11::string::~string(asStack_150);
                    /* catch() { ... } // from try @ 0082e064 with catch @ 0082e918 */
  }
  else {
    std::operator+("dpkg -i --force-overwrite ",param_2);
    pcVar3 = (char *)std::__cxx11::string::c_str(asStack_150);
                    /* try { // try from 0082e750 to 0092e753 has its CatchHandler @ 0082e9f0 */
    local_4 = system(pcVar3);
    bVar1 = local_4 == 0;
    if (bVar1) {
      std::__cxx11::string::string(asStack_f0,param_1);
                    /* try { // try from 0082e7bc to 0092e7bf has its CatchHandler @ 0082ea64 */
      printf("Successfully installed %s\n",asStack_f0);
      std::__cxx11::string::~string(asStack_f0);
                    /* try { // try from 0082e7d8 to 0092e7db has its CatchHandler @ 0082ea04 */
      boost::filesystem::path::path(apStack_d0,param_2);
      boost::filesystem::remove(apStack_d0);
      boost::filesystem::path::~path(apStack_d0);
    }
    else {
      std::__cxx11::string::string(asStack_110,param_1);
      printf("%sError: Failed to install %s\n%s",&DAT_008aadd8,asStack_110,&DAT_008aacb8);
      std::__cxx11::string::~string(asStack_110);
      unaff_w19 = 0xfffffffa;
                    /* try { // try from 0082e7a0 to 0092e7a3 has its CatchHandler @ 0082ea74 */
    }
    std::__cxx11::string::~string(asStack_150);
  }
  if (bVar1) {
    unaff_w19 = 0;
  }
                    /* catch() { ... } // from try @ 0082e148 with catch @ 0082e96c */
  return unaff_w19;
}


/* ================================================================
 * Address: 0082eaec
 * Symbol: update_system
 * Signature: undefined update_system(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* update_system() */

int update_system(void)

{
  undefined4 uVar1;
  int iVar2;
  string asStack_280 [32];
  string asStack_260 [32];
  string asStack_240 [32];
  allocator aaStack_220 [8];
  string asStack_218 [32];
  allocator aaStack_1f8 [8];
  string asStack_1f0 [32];
  allocator aaStack_1d0 [8];
  string asStack_1c8 [32];
  allocator aaStack_1a8 [8];
  string asStack_1a0 [32];
  allocator aaStack_180 [8];
  string asStack_178 [32];
  allocator aaStack_158 [8];
  string asStack_150 [32];
  allocator aaStack_130 [8];
  string asStack_128 [32];
  allocator aaStack_108 [8];
  string asStack_100 [32];
  allocator aaStack_e0 [8];
  string asStack_d8 [32];
  allocator aaStack_b8 [8];
  string asStack_b0 [32];
  allocator aaStack_90 [8];
  string asStack_88 [32];
  allocator aaStack_68 [8];
  string asStack_60 [32];
  allocator aaStack_40 [8];
  string asStack_38 [32];
  allocator aaStack_18 [8];
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  std::operator+((string *)base_download_url,"/QD_Plus4_SOC");
  std::operator+((string *)base_download_url,"/QD_Plus4_UI");
  uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_240,"t2",aaStack_220);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_218,"Downloading file SOC",aaStack_1f8)
  ;
  send_cmd_txt(uVar1,asStack_240,asStack_218);
  std::__cxx11::string::~string(asStack_218);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1f8);
  std::__cxx11::string::~string(asStack_240);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_220);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_1f0,"/tmp/QD_Plus4_SOC",aaStack_1d0);
  local_4 = download_to_file(asStack_260,asStack_1f0,(double *)&progress);
  std::__cxx11::string::~string(asStack_1f0);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1d0);
  uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
  std::allocator<char>::allocator();
                    /* try { // try from 0082ec30 to 0092ec33 has its CatchHandler @ 0082ed9c */
  std::__cxx11::string::string<std::allocator<char>>(asStack_1c8,"t2",aaStack_1a8);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_1a0,"Downloading file UI",aaStack_180);
                    /* try { // try from 0082ec70 to 0092ed7f has its CatchHandler @ 0082ea98 */
  send_cmd_txt(uVar1,asStack_1c8,asStack_1a0);
  std::__cxx11::string::~string(asStack_1a0);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_180);
  std::__cxx11::string::~string(asStack_1c8);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1a8);
  std::allocator<char>::allocator();
  std::__cxx11::string::string<std::allocator<char>>(asStack_178,"/tmp/QD_Plus4_UI",aaStack_158);
  local_8 = download_to_file(asStack_280,asStack_178,(double *)&progress);
  std::__cxx11::string::~string(asStack_178);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_158);
  iVar2 = local_4;
  if ((local_4 == 0) && (iVar2 = local_8, local_8 == 0)) {
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_150,"t2",aaStack_130);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_128,"Installing SOC",aaStack_108);
    send_cmd_txt(uVar1,asStack_150,asStack_128);
    std::__cxx11::string::~string(asStack_128);
                    /* try { // try from 0082ed8c to 0092ed8f has its CatchHandler @ 0082edb0 */
    std::allocator<char>::~allocator((allocator<char> *)aaStack_108);
    std::__cxx11::string::~string(asStack_150);
                    /* catch() { ... } // from try @ 0082ec30 with catch @ 0082ed9c */
    std::allocator<char>::~allocator((allocator<char> *)aaStack_130);
    std::allocator<char>::allocator();
                    /* try { // try from 0082edac to 0092edc3 has its CatchHandler @ 0082ea98 */
                    /* catch() { ... } // from try @ 0082ed8c with catch @ 0082edb0 */
    std::__cxx11::string::string<std::allocator<char>>(asStack_100,"SOC",aaStack_e0);
    std::allocator<char>::allocator();
                    /* catch() { ... } // from try @ 0082ee28 with catch @ 0082edd4
                       catch() { ... } // from try @ 0082ef88 with catch @ 0082edd4 */
    std::__cxx11::string::string<std::allocator<char>>(asStack_d8,"/tmp/QD_Plus4_SOC",aaStack_b8);
    local_c = install_update(asStack_100,asStack_d8);
    std::__cxx11::string::~string(asStack_d8);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_b8);
    std::__cxx11::string::~string(asStack_100);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_e0);
    uVar1 = *(undefined4 *)PTR_tty_fd_009d2e70;
                    /* try { // try from 0082ee28 to 0092eea3 has its CatchHandler @ 0082edd4 */
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_b0,"t2",aaStack_90);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_88,"Installing UI",aaStack_68);
    send_cmd_txt(uVar1,asStack_b0,asStack_88);
    std::__cxx11::string::~string(asStack_88);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_68);
    std::__cxx11::string::~string(asStack_b0);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_90);
    std::allocator<char>::allocator();
                    /* try { // try from 0082eeac to 0092ef6b has its CatchHandler @ 0082ef78 */
    std::__cxx11::string::string<std::allocator<char>>(asStack_60,"UI",aaStack_40);
    std::allocator<char>::allocator();
    std::__cxx11::string::string<std::allocator<char>>(asStack_38,"/tmp/QD_Plus4_UI",aaStack_18);
    local_10 = install_update(asStack_60,asStack_38);
    std::__cxx11::string::~string(asStack_38);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_18);
    std::__cxx11::string::~string(asStack_60);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_40);
    iVar2 = local_c;
    if ((local_c == 0) && (iVar2 = local_10, local_10 == 0)) {
      iVar2 = 0;
    }
  }
  std::__cxx11::string::~string(asStack_280);
  std::__cxx11::string::~string(asStack_260);
  return iVar2;
}


/* Requested 21 names; found 11. */
