"""ESTIMATED reverse-engineered source outline.

This is not QIDI's original source and is intentionally non-runnable.
It reconstructs API shape from Cython symbols and Ghidra evidence.
Firmware: 1.8.2; subsystem: moonraker; module: mqtt.
"""

def load_component(config):
    """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_1load_component`.
    Ghidra reference: decompiled.c:43933.
    Evidence identifiers: config, MQTTClient.
    """
    raise NotImplementedError('Reverse-engineered outline only')

class AIOHelper:
    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_9AIOHelper_1__init__`.
        Ghidra reference: decompiled.c:24034.
        Evidence identifiers: asyncio, client, get_running_loop, loop, misc_task, on_socket_close, on_socket_close_2, on_socket_open, on_socket_open_2, on_socket_register_write, on_socket_unregister_write.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_socket_close(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_9AIOHelper_5_on_socket_close`.
        Ghidra reference: decompiled.c:22092.
        Evidence identifiers: cancel, client, info, logging, loop, misc_task, MQTT_Socket_Closed, remove_reader, sock, userdata, userdata_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_socket_open(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_9AIOHelper_3_on_socket_open`.
        Ghidra reference: decompiled.c:23008.
        Evidence identifiers: add_reader, client, create_task, info, logging, loop, loop_read, misc_loop, misc_task, MQTT_Socket_Opened, sock, userdata, userdata_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_socket_register_write(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_9AIOHelper_7_on_socket_register_write`.
        Ghidra reference: decompiled.c:12804.
        Evidence identifiers: add_writer, client, loop, loop_write, sock, userdata, userdata_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_socket_unregister_write(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_9AIOHelper_9_on_socket_unregister_write`.
        Ghidra reference: decompiled.c:12089.
        Evidence identifiers: client, loop, remove_writer, sock, userdata, userdata_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def misc_loop(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_9AIOHelper_11misc_loop`.
        Ghidra reference: decompiled.c:6900.
        Evidence identifiers: AIOHelper_misc_loop, misc_loop, moonraker_components_mqtt.
        """
        raise NotImplementedError('Reverse-engineered outline only')

class BrokerAckLogger:
    def __call__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_15BrokerAckLogger_3__call__`.
        Ghidra reference: decompiled.c:50845.
        Evidence identifiers: action, debug, fut, getName, Granted_QoS, log_msg, logging, MQTT_Subscriptions_Acknowledged, MQTT_Unsubscribe_Acknowledged, paho_mqtt, qos, QoS_responses, ReasonCodes, res, subscribe, topic, Topic, Topic_QOS_count_mismatch_Topics, topics, Unknown_action, unsubscribe.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_15BrokerAckLogger_1__init__`.
        Ghidra reference: decompiled.c:1501.
        Evidence identifiers: action, topics.
        """
        raise NotImplementedError('Reverse-engineered outline only')

class ExtPahoClient:
    def _v2_reconnect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_13ExtPahoClient_3_v2_reconnect`.
        Ghidra reference: decompiled.c:40426.
        Evidence identifiers: call_socket_open, callback_mutex, Caught_exception_in_on_pre_conne, clear, command, ConnectionState, create_socket, easy_log, enter, err, exit, have_remaining, in_packet, info, keepalive, last_msg_in, last_msg_out, messages_reconnect_reset, MQTT_CS_CONNECTING, MQTT_ERR_CONN_LOST, MQTT_LOG_ERR, msgtime_mutex, on_pre_connect, out_packet, packet, paho_mqtt, ping_t, pkt, pos, PUBLISH, qos, registered_write.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def reconnect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_13ExtPahoClient_1reconnect`.
        Ghidra reference: decompiled.c:39524.
        Evidence identifiers: sock.
        """
        raise NotImplementedError('Reverse-engineered outline only')

class MQTTClient:
    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_1__init__`.
        Ghidra reference: decompiled.c:37645.
        Evidence identifiers: config.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _async_connect_handler(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_26_async_connect_handler`.
        Ghidra reference: decompiled.c:6312.
        Evidence identifiers: async_connect_handler, moonraker_components_mqtt, MQTTClient__async_connect_handle_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _deferred_report(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_23_deferred_report`.
        Ghidra reference: decompiled.c:14076.
        Evidence identifiers: deferred_report, moonraker_components_mqtt, MQTTClient__deferred_report, stats_to_send.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _do_reconnect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_59_do_reconnect`.
        Ghidra reference: decompiled.c:39952.
        Evidence identifiers: do_reconnect, first, moonraker_components_mqtt, MQTTClient__do_reconnect.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _do_reconnect_1get_and_decrypt(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_13_do_reconnect_1get_and_decrypt`.
        Ghidra reference: decompiled.c:7753.
        Evidence identifiers: key_name.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _get_current_date(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_127_get_current_date`.
        Ghidra reference: decompiled.c:17551.
        Evidence identifiers: localtime, strftime, time, Y_m_d.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _get_dab_mqtt_traffic(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_14_get_dab_mqtt_traffic`.
        Ghidra reference: decompiled.c:6608.
        Evidence identifiers: get_dab_mqtt_traffic, moonraker_components_mqtt, MQTTClient__get_dab_mqtt_traffic.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_change_server_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_88_handle_change_server_request`.
        Ghidra reference: decompiled.c:7995.
        Evidence identifiers: handle_change_server_request, moonraker_components_mqtt, MQTTClient__handle_change_server, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_connect_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_82_handle_connect_request`.
        Ghidra reference: decompiled.c:10761.
        Evidence identifiers: handle_connect_request, moonraker_components_mqtt, MQTTClient__handle_connect_reque, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_disconnect_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_85_handle_disconnect_request`.
        Ghidra reference: decompiled.c:8917.
        Evidence identifiers: handle_disconnect_request, moonraker_components_mqtt, MQTTClient__handle_disconnect_re, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _handle_klippy_disconnect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_38_handle_klippy_disconnect`.
        Ghidra reference: decompiled.c:4260.
        Evidence identifiers: last_status_time, payload, publish_status_update, status_cache, status_update_timer, stop.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_klippy_started(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_35_handle_klippy_started`.
        Ghidra reference: decompiled.c:8456.
        Evidence identifiers: handle_klippy_started, moonraker_components_mqtt, MQTTClient__handle_klippy_starte, state, state_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_mqtt_status_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_91_handle_mqtt_status_request`.
        Ghidra reference: decompiled.c:9378.
        Evidence identifiers: handle_mqtt_status_request, moonraker_components_mqtt, MQTTClient__handle_mqtt_status_r, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_msg_to_ui_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_94_handle_msg_to_ui_request`.
        Ghidra reference: decompiled.c:11222.
        Evidence identifiers: handle_msg_to_ui_request, moonraker_components_mqtt, MQTTClient__handle_msg_to_ui_req, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_publish_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_76_handle_publish_request`.
        Ghidra reference: decompiled.c:9839.
        Evidence identifiers: handle_publish_request, moonraker_components_mqtt, MQTTClient__handle_publish_reque, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _handle_slice_download_print(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_42_handle_slice_download_print`.
        Ghidra reference: decompiled.c:13548.
        Evidence identifiers: jobstate_changed_topic, parms, publish_topic.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_subscription_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_79_handle_subscription_request`.
        Ghidra reference: decompiled.c:10300.
        Evidence identifiers: handle_subscription_request, moonraker_components_mqtt, MQTTClient__handle_subscription, web_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _handle_timed_status_update(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_111_handle_timed_status_update`.
        Ghidra reference: decompiled.c:16878.
        Evidence identifiers: eventtime, last_status_time, payload, publish_status_update, status_cache, status_interval.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _handle_update_job_status(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_104_handle_update_job_status`.
        Ghidra reference: decompiled.c:29330.
        Evidence identifiers: business_keys, cancelled, changed, cloud_slice_download_print, complete, completed, copy, CRITICAL_Failed_to_send_job_stat, current_uid, diff_detail, error, exc_info, failCause, get, info, job_state, jobState, logging, MQTT_Job_Status_Updated_s, native, new_state, print_stats, printing, printing_0, printing_2, Printing_paused_due_to_an_error, prog_raw, prog_val, progress, send_event, server, started.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _handle_update_traffic(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_20_handle_update_traffic`.
        Ghidra reference: decompiled.c:16409.
        Evidence identifiers: eventtime, handle_update_traffic, moonraker_components_mqtt, MQTTClient__handle_update_traffi.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _handle_user_login_status(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_40_handle_user_login_status`.
        Ghidra reference: decompiled.c:20924.
        Evidence identifiers: connect_task, create_task, do_reconnect, eventloop, first, info, is_connected, is_login, logging, safe_close.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_connect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_49_on_connect`.
        Ghidra reference: decompiled.c:52801.
        Evidence identifiers: add_done_callback, add_warning, async_connect_handler, BrokerAckLogger, client, connack_string, connect_evt, ConnectionStatus, create_future, err_str, eventloop, flags, getName, info, items, keys, logging, moonraker_status_topic, mqtt, MQTT_Client_Connected, mqtt_connected, MQTT_Connection_Failed, mqtt_disconnect_reson, mqtt_mqtt_change, mqtt_status, msg_id, ONLINE, online, paho_mqtt, pending_acks, properties, publish_topic.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_disconnect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_51_on_disconnect`.
        Ghidra reference: decompiled.c:56661.
        Evidence identifiers: active_subscriptions, asyncio, clear, Clearing_active_subscriptions_du, client, connect_evt, connect_task, ConnectionStatus, create_task, disconnect_evt, do_reconnect, error_string, frp_manager, info, is_connected, logging, mqtt_disconnected, mqtt_mqtt_change, MQTT_Server_Disconnected_reason, mqtt_status, OFFLINE, paho_mqtt, properties, reason_code, send_event, server, set, state_2, stop, stop_frp_if_needed, update_traffic_timer, user_data.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _on_job_state_changed(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_106_on_job_state_changed`.
        Ghidra reference: decompiled.c:28633.
        Evidence identifiers: job_event, moonraker_components_mqtt, MQTTClient__on_job_state_changed, new_stats, on_job_state_changed, prev_stats.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_job_state_changed_1send_fake(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_21_on_job_state_changed_1send_fake`.
        Ghidra reference: decompiled.c:11683.
        Evidence identifiers: state_name, uid.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_message(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_47_on_message`.
        Ghidra reference: decompiled.c:19293.
        Evidence identifiers: callback, cb_hdls, client, current_stats, debug, decode, encode, eventloop, hdl, logging, message, payload, payload_2, register_callback, rx_size, subscribed_topics, topic, Unregistered_MQTT_Topic_Received, user_data.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_publish(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_53_on_publish`.
        Ghidra reference: decompiled.c:15501.
        Evidence identifiers: client, done, msg_id, pending_acks, pop, pub_fut, set_result, user_data.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_subscribe(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_55_on_subscribe`.
        Ghidra reference: decompiled.c:38065.
        Evidence identifiers: client, done, flex, msg_id, pending_acks, pop, properties, set_result, sub_fut, user_data.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _on_unsubscribe(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_57_on_unsubscribe`.
        Ghidra reference: decompiled.c:31996.
        Evidence identifiers: client, done, msg_id, pending_acks, pop, properties, reasoncodes, set_result, unsub_fut, user_data.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _process_api_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_97_process_api_request`.
        Ghidra reference: decompiled.c:15026.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient__process_api_request, payload, process_api_request.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _publish_from_klipper(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_122_publish_from_klipper`.
        Ghidra reference: decompiled.c:44933.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient__publish_from_klipper, payload, publish_from_klipper, qos, retain, topic, use_prefix.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _publish_status_update(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_113_publish_status_update`.
        Ghidra reference: decompiled.c:1999.
        Evidence identifiers: eventtime, klipper_state_prefix, klipper_status_topic, objkey, objval, payload, publish_split_status, publish_topic, retain, statekey, status, value.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _qidiclient_decrypt_hex(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_3_qidiclient_decrypt_hex`.
        Ghidra reference: decompiled.c:44392.
        Evidence identifiers: hex_str, key, moonraker_components_mqtt, MQTTClient__qidiclient_decrypt_h, qidiclient_decrypt_hex, REDACTED_SECURITY_CONSTANT.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _safe_close(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_44_safe_close`.
        Ghidra reference: decompiled.c:4854.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient__safe_close, safe_close.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _start_frp_if_needed(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_29_start_frp_if_needed`.
        Ghidra reference: decompiled.c:5437.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient__start_frp_if_needed, start_frp_if_needed.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _stop_frp_if_needed(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_32_stop_frp_if_needed`.
        Ghidra reference: decompiled.c:6020.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient__stop_frp_if_needed, stop_frp_if_needed.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def _update_dab_mqtt_traffic(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_17_update_dab_mqtt_traffic`.
        Ghidra reference: decompiled.c:14551.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient__update_dab_mqtt_traf, playload, update_dab_mqtt_traffic.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def close(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_119close`.
        Ghidra reference: decompiled.c:7190.
        Evidence identifiers: close, moonraker_components_mqtt, MQTTClient_close.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def component_init(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_8component_init`.
        Ghidra reference: decompiled.c:5729.
        Evidence identifiers: component_init, moonraker_components_mqtt, MQTTClient_component_init.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def get_cpu_serial(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_125get_cpu_serial`.
        Ghidra reference: decompiled.c:58930.
        Evidence identifiers: ascii, cleaned_bytes, decode, enter, error, exit, logging, path, proc_device_tree_serial_number, raw, read, rstrip, serial, upper.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def get_instance_name(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_115get_instance_name`.
        Ghidra reference: decompiled.c:7480.
        Evidence identifiers: instance_name.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def get_status(self, eventtime=None):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_117get_status`.
        Ghidra reference: decompiled.c:39044.
        Evidence identifiers: eventtime, state_2, value.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def is_connected(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_65is_connected`.
        Ghidra reference: decompiled.c:64126.
        Evidence identifiers: connect_evt, is_set.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def publish_topic(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_71publish_topic`.
        Ghidra reference: decompiled.c:60594.
        Evidence identifiers: client, create_future, current_stats, Dict_or_List_is_not_json_encodab, dumps, encode, err_str, error, Error_calculating_TX_traffic, error_string, eventloop, is_published, JSONDecodeError, jsonw, logging, lower, mid, MQTT_ERR_SUCCESS, MQTT_Publish_Error, msg_info, p_size, paho_mqtt, payload, pending_acks, pub_fut, publish, qos, QOS_must_be_between_0_and_2, retain, server, set_exception, set_result.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def publish_topic_with_response(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_73publish_topic_with_response`.
        Ghidra reference: decompiled.c:311.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient_publish_topic_with_re, payload, publish_topic_with_response, qos, response_topic, retain, timeout, topic.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def screen_rpc_request(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_102screen_rpc_request`.
        Ghidra reference: decompiled.c:18021.
        Evidence identifiers: api_def, append, debug, DUP_API_REQ_CODE, Duplicate_MQTT_API_request_recei, Duplicate_MQTT_Request, error, logging, mqtt_timestamp, req_type, server, timestamp_deque.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def send_status(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_109send_status`.
        Ghidra reference: decompiled.c:3258.
        Evidence identifiers: eventtime, is_connected, key, last_status_time, publish_status_update, setdefault, status, status_cache, status_interval, update, val.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def subscribe_topic(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_67subscribe_topic`.
        Ghidra reference: decompiled.c:64768.
        Evidence identifiers: add_done_callback, append, BrokerAckLogger, callback, client, create_future, error, eventloop, hdl, is_connected, msg_id, need_sub, pending_acks, prev_qos, qos, QOS_must_be_between_0_and_2, res, server, sub_fut, sub_handles, subscribe, subscribed_topics, SubscriptionHandle, topic, Wildcards_may_not_be_used.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def switch_server_information(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_6switch_server_information`.
        Ghidra reference: decompiled.c:45445.
        Evidence identifiers: absolute, address, api_qos, api_request_topic, api_resp_topic, asyncio, CallbackAPIVersion, client, client_id, connect_evt, connect_task, disconnect_evt, Event, expanduser, ExtPahoClient, get, get_cpu_serial, gethostname, info, instance_name, job_state_changed, jobstate_changed_topic, klipper_state, klipper_state_prefix, klipper_status, klipper_status_topic, logging, moonraker_api_request, moonraker_api_response, moonraker_status, moonraker_status_topic, moonraker_traffic.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def transport_type(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_100transport_type`.
        Ghidra reference: decompiled.c:19005.
        Evidence identifiers: MQTT, TransportType.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def unsubscribe(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_69unsubscribe`.
        Ghidra reference: decompiled.c:49442.
        Evidence identifiers: add_done_callback, BrokerAckLogger, client, create_future, eventloop, hdl, msg_id, pending_acks, remove, res, sub_hdls, subscribed_topics, topic, unsub_fut, unsubscribe.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def update_mqtt_credentials(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_11update_mqtt_credentials`.
        Ghidra reference: decompiled.c:5145.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient_update_mqtt_credentia, update_mqtt_credentials.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    async def wait_connection(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_10MQTTClient_62wait_connection`.
        Ghidra reference: decompiled.c:43435.
        Evidence identifiers: moonraker_components_mqtt, MQTTClient_wait_connection, timeout, wait_connection.
        """
        raise NotImplementedError('Reverse-engineered outline only')

class SubscriptionHandle:
    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_9moonraker_10components_4mqtt_18SubscriptionHandle_1__init__`.
        Ghidra reference: decompiled.c:1007.
        Evidence identifiers: callback, topic.
        """
        raise NotImplementedError('Reverse-engineered outline only')
