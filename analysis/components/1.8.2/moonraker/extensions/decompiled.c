/*
 * Reverse-engineered Ghidra output. This is not original source code.
 * Program: extensions.so
 * Language: AARCH64:LE:64:v8A
 * Selected named functions: 31
 */


/* ================================================================
 * Address: 00108250
 * Symbol:  __pyx_pymod_exec_extensions
 * Signature: int __pyx_pymod_exec_extensions(PyObject * __pyx_pyinit_module)
 * ================================================================ */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int __pyx_pymod_exec_extensions(PyObject *__pyx_pyinit_module)

{
  byte bVar1;
  bool bVar2;
  Py_ssize_t *pPVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  PyObject *pPVar9;
  _typeobject *p_Var10;
  PyObject *pPVar11;
  long lVar12;
  ulong uVar13;
  PyObject *extraout_x1;
  PyObject *extraout_x1_00;
  PyObject *extraout_x1_01;
  PyObject *extraout_x1_02;
  PyObject *extraout_x1_03;
  PyObject *extraout_x1_04;
  PyObject *extraout_x1_05;
  long *plVar14;
  PyObject *extraout_x1_06;
  long lVar15;
  long lVar16;
  ulong uVar17;
  _typeobject *p_Var18;
  int iVar19;
  PyObject *pPVar20;
  _typeobject *p_Var21;
  PyObject *pPVar22;
  PyObject *pPVar23;
  ulong uVar24;
  long *plVar25;
  PyObject *pPVar26;
  PyObject *pPVar27;
  undefined1 auVar28 [16];
  undefined8 in_stack_fffffffffffffe70;
  undefined4 uVar29;
  PyObject *args [2];
  char message [200];
  
                    /* Unresolved local var: int stringtab_initialized@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: int __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  uVar29 = (undefined4)((ulong)in_stack_fffffffffffffe70 >> 0x20);
  lVar15 = *(long *)PTR___stack_chk_guard_00143f20;
  if (__pyx_m != (PyObject *)0x0) {
    iVar5 = 0;
    if (__pyx_m != __pyx_pyinit_module) {
      PyErr_SetString(*(undefined8 *)PTR_PyExc_RuntimeError_00143ec8,
                      "Module \'extensions\' has already been imported. Re-initialisation is not supported."
                      ,0);
      iVar5 = -1;
    }
    goto LAB_0010c068;
  }
  __pyx_m = __pyx_pyinit_module;
  __pyx_pyinit_module->ob_refcnt = __pyx_pyinit_module->ob_refcnt + 1;
  __pyx_mstate_global_static.__pyx_d = (PyObject *)PyModule_GetDict();
  if (__pyx_mstate_global_static.__pyx_d == (PyObject *)0x0) {
    iVar19 = 0x4420;
    iVar5 = 1;
    bVar2 = false;
LAB_0010b26c:
    if (__pyx_m == (PyObject *)0x0) {
      lVar7 = PyErr_Occurred();
      if (lVar7 == 0) {
        PyErr_SetString(*(undefined8 *)PTR_PyExc_ImportError_00143f90,
                        "init moonraker.components.extensions");
      }
    }
    else {
      if ((__pyx_mstate_global_static.__pyx_d != (PyObject *)0x0) && (bVar2)) {
        __Pyx_AddTraceback("init moonraker.components.extensions",iVar19,iVar5,
                           "moonraker/components/extensions.py");
      }
                    /* Unresolved local var: PyObject * _py_tmp@[???] */
      pPVar23 = __pyx_m;
      if (__pyx_m != (PyObject *)0x0) {
        pPVar3 = &__pyx_m->ob_refcnt;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        __pyx_m = (PyObject *)0x0;
        lVar7 = *pPVar3 + -1;
        pPVar23->ob_refcnt = lVar7;
        if (lVar7 == 0) {
          (*pPVar23->ob_type->tp_dealloc)(pPVar23);
        }
      }
    }
  }
  else {
                    /* Unresolved local var: PyObject * module@[???] */
    (__pyx_mstate_global_static.__pyx_d)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_d)->ob_refcnt + 1;
    __pyx_mstate_global_static.__pyx_b = (PyObject *)PyImport_AddModule("builtins");
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (__pyx_mstate_global_static.__pyx_b == (PyObject *)0x0) {
      iVar19 = 0x4422;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    (__pyx_mstate_global_static.__pyx_b)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_b)->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * module@[???] */
    __pyx_mstate_global_static.__pyx_cython_runtime =
         (PyObject *)PyImport_AddModule("cython_runtime");
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (__pyx_mstate_global_static.__pyx_cython_runtime == (PyObject *)0x0) {
      iVar19 = 0x4423;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt + 1;
    iVar5 = PyObject_SetAttrString(__pyx_m,"__builtins__",__pyx_mstate_global_static.__pyx_b);
    if (iVar5 < 0) {
      iVar19 = 0x4424;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
                    /* Unresolved local var: char * rt_version@[???]
                       Unresolved local var: ulong version@[???]
                       Unresolved local var: ulong factor@[???]
                       Unresolved local var: wchar_t digit@[???]
                       Unresolved local var: int i@[???] */
    lVar7 = Py_GetVersion();
    iVar19 = 4;
    iVar5 = 0;
    uVar24 = 0;
    uVar17 = 0x1000000;
    do {
      uVar13 = 0;
      while (bVar1 = *(byte *)(lVar7 + iVar5), (byte)(bVar1 - 0x30) < 10) {
        iVar5 = iVar5 + 1;
        uVar13 = (ulong)(((uint)bVar1 + (int)uVar13 * 10) - 0x30);
      }
      uVar24 = uVar24 + uVar13 * uVar17;
      if (bVar1 != 0x2e) break;
      uVar17 = uVar17 >> 8;
      iVar5 = iVar5 + 1;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
                    /* Unresolved local var: ulong MAJOR_MINOR@[???] */
    if (((uVar24 ^ 0x3070000) & 0xffff0000) != 0) {
      PyOS_snprintf(message,200,
                    "compile time Python version %d.%d of module \'%.100s\' %s runtime version %d.%d"
                    ,3,7,"moonraker.components.extensions","does not match",
                    uVar24 >> 0x18 & 0xffffffff,
                    CONCAT44(uVar29,(uint)uVar24 >> 0x10) & 0xffffffff000000ff);
      iVar5 = PyErr_WarnEx(0,message,1);
      if (iVar5 < 0) {
        iVar19 = 0x442f;
        iVar5 = 1;
        bVar2 = false;
        goto LAB_0010b26c;
      }
    }
    __pyx_pyframe_localsplus_offset = *(long *)(PTR_PyFrame_Type_00143f80 + 0x20) - 8;
    __pyx_mstate_global_static.__pyx_empty_tuple = (PyObject *)PyTuple_New(0);
    if (__pyx_mstate_global_static.__pyx_empty_tuple == (PyObject *)0x0) {
      iVar19 = 0x4433;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    __pyx_mstate_global_static.__pyx_empty_bytes = (PyObject *)PyBytes_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_bytes == (PyObject *)0x0) {
      iVar19 = 0x4434;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    __pyx_mstate_global_static.__pyx_empty_unicode = (PyObject *)PyUnicode_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_unicode == (PyObject *)0x0) {
      iVar19 = 0x4435;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    __pyx_mstate_global_static.__pyx_CyFunctionType =
         __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (__pyx_mstate_global_static.__pyx_CyFunctionType == (PyTypeObject *)0x0) {
      iVar19 = 0x4437;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    __pyx_CoroutineType_type.tp_getattro = (getattrofunc)PTR_PyObject_GenericGetAttr_00143f28;
    __pyx_mstate_global_static.__pyx_CoroutineType =
         __Pyx_FetchCommonType(&__pyx_CoroutineType_type);
    if ((__pyx_mstate_global_static.__pyx_CoroutineType == (PyTypeObject *)0x0) ||
       (__pyx_mstate_global_static.__pyx_CoroutineAwaitType =
             __Pyx_FetchCommonType(&__pyx_CoroutineAwaitType_type),
       __pyx_mstate_global_static.__pyx_CoroutineAwaitType == (PyTypeObject *)0x0)) {
      iVar19 = 0x443d;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    iVar5 = __Pyx_CreateStringTabAndInitStrings();
    if ((((((iVar5 < 0) ||
           (__pyx_mstate_global_static.__pyx_int_1 = (PyObject *)PyLong_FromLong(1),
           __pyx_mstate_global_static.__pyx_int_1 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_int_10 = (PyObject *)PyLong_FromLong(10),
          __pyx_mstate_global_static.__pyx_int_10 == (PyObject *)0x0)) ||
         ((__pyx_mstate_global_static.__pyx_int_404 = (PyObject *)PyLong_FromLong(0x194),
          __pyx_mstate_global_static.__pyx_int_404 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_int_500 = (PyObject *)PyLong_FromLong(500),
          __pyx_mstate_global_static.__pyx_int_500 == (PyObject *)0x0)))) ||
        (__pyx_mstate_global_static.__pyx_int_20971520 = (PyObject *)PyLong_FromLong(0x1400000),
        __pyx_mstate_global_static.__pyx_int_20971520 == (PyObject *)0x0)) ||
       (__pyx_mstate_global_static.__pyx_int_neg_1 = (PyObject *)PyLong_FromLong(0xffffffffffffffff)
       , __pyx_mstate_global_static.__pyx_int_neg_1 == (PyObject *)0x0)) {
      iVar19 = 0x444e;
      iVar5 = 1;
      bVar2 = false;
      goto LAB_0010b26c;
    }
    if ((*(int *)PTR___pyx_module_is_main_moonraker__components__extensions_00143ef8 != 0) &&
       (iVar5 = PyObject_SetAttr(__pyx_m,__pyx_mstate_global_static.__pyx_n_s_name_2,
                                 __pyx_mstate_global_static.__pyx_n_s_main), iVar5 < 0)) {
      iVar5 = 1;
      iVar19 = 0x4455;
      bVar2 = true;
      goto LAB_0010b26c;
    }
                    /* Unresolved local var: PyObject * modules@[???] */
    lVar7 = PyImport_GetModuleDict();
    if (lVar7 == 0) {
      iVar5 = 1;
      iVar19 = 0x4459;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    lVar8 = PyDict_GetItemString(lVar7,"moonraker.components.extensions");
    if ((lVar8 == 0) &&
       (iVar5 = PyDict_SetItemString(lVar7,"moonraker.components.extensions",__pyx_m), iVar5 < 0)) {
      iVar5 = 1;
      iVar19 = 0x445b;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    puVar4 = PTR__Py_NoneStruct_00143f40;
    __pyx_mstate_global_static.__pyx_tuple__2 =
         (PyObject *)
         PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_u_data,PTR__Py_NoneStruct_00143f40);
    if ((((((__pyx_mstate_global_static.__pyx_tuple__2 == (PyObject *)0x0) ||
           (__pyx_mstate_global_static.__pyx_tuple__6 =
                 (PyObject *)PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_u_arguments,puVar4),
           __pyx_mstate_global_static.__pyx_tuple__6 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_tuple__7 =
                (PyObject *)PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_u_agent,puVar4),
          __pyx_mstate_global_static.__pyx_tuple__7 == (PyObject *)0x0)) ||
         (((__pyx_mstate_global_static.__pyx_tuple__8 =
                 (PyObject *)
                 PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_kp_u_No_qidiclient_agent_connected,
                              __pyx_mstate_global_static.__pyx_int_404),
           __pyx_mstate_global_static.__pyx_tuple__8 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_slice__17 =
                 (PyObject *)PySlice_New(puVar4,__pyx_mstate_global_static.__pyx_int_neg_1,puVar4),
           __pyx_mstate_global_static.__pyx_slice__17 == (PyObject *)0x0)) ||
          ((__pyx_mstate_global_static.__pyx_tuple__20 =
                 (PyObject *)
                 PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_kp_u_Client_Socket_Disconnected,
                              __pyx_mstate_global_static.__pyx_int_500),
           __pyx_mstate_global_static.__pyx_tuple__20 == (PyObject *)0x0 ||
           ((__pyx_mstate_global_static.__pyx_tuple__23 =
                  (PyObject *)
                  PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                               __pyx_mstate_global_static.__pyx_n_s_config),
            __pyx_mstate_global_static.__pyx_tuple__23 == (PyObject *)0x0 ||
            (__pyx_mstate_global_static.__pyx_codeobj__24 =
                  (PyObject *)
                  PyCode_New(2,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__23,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2
                             ,__pyx_mstate_global_static.__pyx_n_s_init,0x20,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__24 == (PyObject *)0x0)))))))) ||
        ((__pyx_mstate_global_static.__pyx_tuple__25 =
               (PyObject *)
               PyTuple_Pack(6,__pyx_mstate_global_static.__pyx_n_s_self,
                            __pyx_mstate_global_static.__pyx_n_s_connection,
                            __pyx_mstate_global_static.__pyx_n_s_data,
                            __pyx_mstate_global_static.__pyx_n_s_name,
                            __pyx_mstate_global_static.__pyx_n_s_client_type,
                            __pyx_mstate_global_static.__pyx_n_s_evt),
         __pyx_mstate_global_static.__pyx_tuple__25 == (PyObject *)0x0 ||
         (((__pyx_mstate_global_static.__pyx_codeobj__26 =
                 (PyObject *)
                 PyCode_New(2,0,6,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__25,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2,
                            __pyx_mstate_global_static.__pyx_n_s_register_agent,0x3e,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__26 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_tuple__27 =
                 (PyObject *)
                 PyTuple_Pack(7,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_connection,
                              __pyx_mstate_global_static.__pyx_n_s_name,
                              __pyx_mstate_global_static.__pyx_n_s_klippy,
                              __pyx_mstate_global_static.__pyx_n_s_registered_methods,
                              __pyx_mstate_global_static.__pyx_n_s_method,
                              __pyx_mstate_global_static.__pyx_n_s_evt),
           __pyx_mstate_global_static.__pyx_tuple__27 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_codeobj__28 =
                (PyObject *)
                PyCode_New(2,0,7,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__27,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2,
                           __pyx_mstate_global_static.__pyx_n_s_remove_agent,0x58,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__28 == (PyObject *)0x0)))))) ||
       (((((((__pyx_mstate_global_static.__pyx_tuple__29 =
                   (PyObject *)
                   PyTuple_Pack(7,__pyx_mstate_global_static.__pyx_n_s_self,
                                __pyx_mstate_global_static.__pyx_n_s_web_request,
                                __pyx_mstate_global_static.__pyx_n_s_conn,
                                __pyx_mstate_global_static.__pyx_n_s_name,
                                __pyx_mstate_global_static.__pyx_n_s_evt_name,
                                __pyx_mstate_global_static.__pyx_n_s_data,
                                __pyx_mstate_global_static.__pyx_n_s_evt),
             __pyx_mstate_global_static.__pyx_tuple__29 == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_codeobj_ =
                   (PyObject *)
                   PyCode_New(2,0,7,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_tuple__29,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.
                              __pyx_kp_s_moonraker_components_extensions_2,
                              __pyx_mstate_global_static.__pyx_n_s_handle_agent_event,99,
                              __pyx_mstate_global_static.__pyx_empty_bytes),
             __pyx_mstate_global_static.__pyx_codeobj_ == (PyObject *)0x0)) ||
            (((__pyx_mstate_global_static.__pyx_tuple__30 =
                    (PyObject *)
                    PyTuple_Pack(5,__pyx_mstate_global_static.__pyx_n_s_self,
                                 __pyx_mstate_global_static.__pyx_n_s_web_request,
                                 __pyx_mstate_global_static.__pyx_n_s_conn,
                                 __pyx_mstate_global_static.__pyx_n_s_method_name,
                                 __pyx_mstate_global_static.__pyx_n_s_klippy),
              __pyx_mstate_global_static.__pyx_tuple__30 == (PyObject *)0x0 ||
              ((__pyx_mstate_global_static.__pyx_codeobj__3 =
                     (PyObject *)
                     PyCode_New(2,0,5,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_tuple__30,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.
                                __pyx_kp_s_moonraker_components_extensions_2,
                                __pyx_mstate_global_static.__pyx_n_s_register_agent_method,0x77,
                                __pyx_mstate_global_static.__pyx_empty_bytes),
               __pyx_mstate_global_static.__pyx_codeobj__3 == (PyObject *)0x0 ||
               (__pyx_mstate_global_static.__pyx_tuple__31 =
                     (PyObject *)
                     PyTuple_Pack(4,__pyx_mstate_global_static.__pyx_n_s_self,
                                  __pyx_mstate_global_static.__pyx_n_s_web_request,
                                  __pyx_mstate_global_static.__pyx_n_s_agents,
                                  __pyx_mstate_global_static.__pyx_n_s_agt),
               __pyx_mstate_global_static.__pyx_tuple__31 == (PyObject *)0x0)))) ||
             (__pyx_mstate_global_static.__pyx_codeobj__4 =
                   (PyObject *)
                   PyCode_New(2,0,4,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_tuple__31,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.
                              __pyx_kp_s_moonraker_components_extensions_2,
                              __pyx_mstate_global_static.__pyx_n_s_handle_list_extensions,0x81,
                              __pyx_mstate_global_static.__pyx_empty_bytes),
             __pyx_mstate_global_static.__pyx_codeobj__4 == (PyObject *)0x0)))) ||
           ((((((__pyx_mstate_global_static.__pyx_tuple__32 =
                      (PyObject *)
                      PyTuple_Pack(6,__pyx_mstate_global_static.__pyx_n_s_self,
                                   __pyx_mstate_global_static.__pyx_n_s_web_request,
                                   __pyx_mstate_global_static.__pyx_n_s_agent,
                                   __pyx_mstate_global_static.__pyx_n_s_method,
                                   __pyx_mstate_global_static.__pyx_n_s_args,
                                   __pyx_mstate_global_static.__pyx_n_s_conn),
                __pyx_mstate_global_static.__pyx_tuple__32 == (PyObject *)0x0 ||
                (__pyx_mstate_global_static.__pyx_codeobj__5 =
                      (PyObject *)
                      PyCode_New(2,0,6,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.__pyx_tuple__32,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.
                                 __pyx_kp_s_moonraker_components_extensions_2,
                                 __pyx_mstate_global_static.__pyx_n_s_handle_call_agent,0x88,
                                 __pyx_mstate_global_static.__pyx_empty_bytes),
                __pyx_mstate_global_static.__pyx_codeobj__5 == (PyObject *)0x0)) ||
               (__pyx_mstate_global_static.__pyx_tuple__33 =
                     (PyObject *)
                     PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                                  __pyx_mstate_global_static.__pyx_n_s_web_request,
                                  __pyx_mstate_global_static.__pyx_n_s_agent_name),
               __pyx_mstate_global_static.__pyx_tuple__33 == (PyObject *)0x0)) ||
              ((__pyx_mstate_global_static.__pyx_codeobj__34 =
                     (PyObject *)
                     PyCode_New(2,0,3,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_tuple__33,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.
                                __pyx_kp_s_moonraker_components_extensions_2,
                                __pyx_mstate_global_static.__pyx_n_s_select_qidiclient,0x96,
                                __pyx_mstate_global_static.__pyx_empty_bytes),
               __pyx_mstate_global_static.__pyx_codeobj__34 == (PyObject *)0x0 ||
               (__pyx_mstate_global_static.__pyx_tuple__35 =
                     (PyObject *)
                     PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                                  __pyx_mstate_global_static.__pyx_n_s_web_request,
                                  __pyx_mstate_global_static.__pyx_n_s_conn),
               __pyx_mstate_global_static.__pyx_tuple__35 == (PyObject *)0x0)))) ||
             ((__pyx_mstate_global_static.__pyx_codeobj__9 =
                    (PyObject *)
                    PyCode_New(2,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.__pyx_tuple__35,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.
                               __pyx_kp_s_moonraker_components_extensions_2,
                               __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_list,
                               0xa2,__pyx_mstate_global_static.__pyx_empty_bytes),
              __pyx_mstate_global_static.__pyx_codeobj__9 == (PyObject *)0x0 ||
              ((__pyx_mstate_global_static.__pyx_codeobj__10 =
                     (PyObject *)
                     PyCode_New(2,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_tuple__35,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.
                                __pyx_kp_s_moonraker_components_extensions_2,
                                __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_stats,
                                0xa6,__pyx_mstate_global_static.__pyx_empty_bytes),
               __pyx_mstate_global_static.__pyx_codeobj__10 == (PyObject *)0x0 ||
               (__pyx_mstate_global_static.__pyx_codeobj__11 =
                     (PyObject *)
                     PyCode_New(2,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_tuple__35,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.
                                __pyx_kp_s_moonraker_components_extensions_2,
                                __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_config_offica
                                ,0xaa,__pyx_mstate_global_static.__pyx_empty_bytes),
               __pyx_mstate_global_static.__pyx_codeobj__11 == (PyObject *)0x0)))))) ||
            (__pyx_mstate_global_static.__pyx_tuple__36 =
                  (PyObject *)
                  PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                               __pyx_mstate_global_static.__pyx_n_s_sockfile,
                               __pyx_mstate_global_static.__pyx_n_s_sock_path),
            __pyx_mstate_global_static.__pyx_tuple__36 == (PyObject *)0x0)))) ||
          ((((((__pyx_mstate_global_static.__pyx_codeobj__12 =
                     (PyObject *)
                     PyCode_New(1,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_tuple__36,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.
                                __pyx_kp_s_moonraker_components_extensions_2,
                                __pyx_mstate_global_static.__pyx_n_s_start_unix_server,0xae,
                                __pyx_mstate_global_static.__pyx_empty_bytes),
               __pyx_mstate_global_static.__pyx_codeobj__12 == (PyObject *)0x0 ||
               (__pyx_mstate_global_static.__pyx_tuple__37 =
                     (PyObject *)
                     PyTuple_Pack(4,__pyx_mstate_global_static.__pyx_n_s_self,
                                  __pyx_mstate_global_static.__pyx_n_s_reader,
                                  __pyx_mstate_global_static.__pyx_n_s_writer,
                                  __pyx_mstate_global_static.__pyx_n_s_peercred),
               __pyx_mstate_global_static.__pyx_tuple__37 == (PyObject *)0x0)) ||
              (__pyx_mstate_global_static.__pyx_codeobj__38 =
                    (PyObject *)
                    PyCode_New(3,0,4,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.__pyx_tuple__37,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.__pyx_empty_tuple,
                               __pyx_mstate_global_static.
                               __pyx_kp_s_moonraker_components_extensions_2,
                               __pyx_mstate_global_static.__pyx_n_s_on_unix_socket_connected,0xbc,
                               __pyx_mstate_global_static.__pyx_empty_bytes),
              __pyx_mstate_global_static.__pyx_codeobj__38 == (PyObject *)0x0)) ||
             (((__pyx_mstate_global_static.__pyx_tuple__39 =
                     (PyObject *)PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_n_s_self),
               __pyx_mstate_global_static.__pyx_tuple__39 == (PyObject *)0x0 ||
               (__pyx_mstate_global_static.__pyx_codeobj__14 =
                     (PyObject *)
                     PyCode_New(1,0,1,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_tuple__39,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.__pyx_empty_tuple,
                                __pyx_mstate_global_static.
                                __pyx_kp_s_moonraker_components_extensions_2,
                                __pyx_mstate_global_static.__pyx_n_s_close,0xc3,
                                __pyx_mstate_global_static.__pyx_empty_bytes),
               __pyx_mstate_global_static.__pyx_codeobj__14 == (PyObject *)0x0)) ||
              ((__pyx_mstate_global_static.__pyx_tuple__40 =
                     (PyObject *)
                     PyTuple_Pack(8,__pyx_mstate_global_static.__pyx_n_s_self,
                                  __pyx_mstate_global_static.__pyx_n_s_server,
                                  __pyx_mstate_global_static.__pyx_n_s_reader,
                                  __pyx_mstate_global_static.__pyx_n_s_writer,
                                  __pyx_mstate_global_static.__pyx_n_s_peercred,
                                  __pyx_mstate_global_static.__pyx_n_s_pid,
                                  __pyx_mstate_global_static.__pyx_n_s_uid,
                                  __pyx_mstate_global_static.__pyx_n_s_gid),
               __pyx_mstate_global_static.__pyx_tuple__40 == (PyObject *)0x0 ||
               ((__pyx_mstate_global_static.__pyx_codeobj__41 =
                      (PyObject *)
                      PyCode_New(5,0,8,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.__pyx_tuple__40,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.__pyx_empty_tuple,
                                 __pyx_mstate_global_static.
                                 __pyx_kp_s_moonraker_components_extensions_2,
                                 __pyx_mstate_global_static.__pyx_n_s_init,0xca,
                                 __pyx_mstate_global_static.__pyx_empty_bytes),
                __pyx_mstate_global_static.__pyx_codeobj__41 == (PyObject *)0x0 ||
                (__pyx_mstate_global_static.__pyx_tuple__42 =
                      (PyObject *)
                      PyTuple_Pack(5,__pyx_mstate_global_static.__pyx_n_s_self,
                                   __pyx_mstate_global_static.__pyx_n_s_reader,
                                   __pyx_mstate_global_static.__pyx_n_s_errors_remaining,
                                   __pyx_mstate_global_static.__pyx_n_s_data,
                                   __pyx_mstate_global_static.__pyx_n_s_decoded),
                __pyx_mstate_global_static.__pyx_tuple__42 == (PyObject *)0x0)))))))) ||
            (__pyx_mstate_global_static.__pyx_codeobj__15 =
                  (PyObject *)
                  PyCode_New(2,0,5,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__42,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2
                             ,__pyx_mstate_global_static.__pyx_n_s_read_messages,0xdf,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__15 == (PyObject *)0x0)) ||
           (((__pyx_mstate_global_static.__pyx_tuple__43 =
                   (PyObject *)
                   PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                                __pyx_mstate_global_static.__pyx_n_s_message,
                                __pyx_mstate_global_static.__pyx_n_s_data),
             __pyx_mstate_global_static.__pyx_tuple__43 == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_codeobj__18 =
                   (PyObject *)
                   PyCode_New(2,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_tuple__43,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.
                              __pyx_kp_s_moonraker_components_extensions_2,
                              __pyx_mstate_global_static.__pyx_n_s_write_to_socket,0xf5,
                              __pyx_mstate_global_static.__pyx_empty_bytes),
             __pyx_mstate_global_static.__pyx_codeobj__18 == (PyObject *)0x0)) ||
            (__pyx_mstate_global_static.__pyx_tuple__44 =
                  (PyObject *)
                  PyTuple_Pack(6,__pyx_mstate_global_static.__pyx_n_s_self,
                               __pyx_mstate_global_static.__pyx_n_s_code,
                               __pyx_mstate_global_static.__pyx_n_s_reason,
                               __pyx_mstate_global_static.__pyx_n_s_kconn,
                               __pyx_mstate_global_static.__pyx_n_s_resp,
                               __pyx_mstate_global_static.__pyx_n_s_extensions),
            __pyx_mstate_global_static.__pyx_tuple__44 == (PyObject *)0x0)))))) ||
         (((__pyx_mstate_global_static.__pyx_codeobj__19 =
                 (PyObject *)
                 PyCode_New(3,0,6,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__44,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2,
                            __pyx_mstate_global_static.__pyx_n_s_on_close,0x103,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__19 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_tuple__45 =
                 (PyObject *)PyTuple_Pack(2,PTR__Py_NoneStruct_00143f40),
           __pyx_mstate_global_static.__pyx_tuple__45 == (PyObject *)0x0)) ||
          ((__pyx_mstate_global_static.__pyx_tuple__46 =
                 (PyObject *)
                 PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_code,
                              __pyx_mstate_global_static.__pyx_n_s_reason),
           __pyx_mstate_global_static.__pyx_tuple__46 == (PyObject *)0x0 ||
           ((__pyx_mstate_global_static.__pyx_codeobj__47 =
                  (PyObject *)
                  PyCode_New(3,0,3,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__46,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2
                             ,__pyx_mstate_global_static.__pyx_n_s_close_socket,0x124,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__47 == (PyObject *)0x0 ||
            (__pyx_mstate_global_static.__pyx_tuple__48 =
                  (PyObject *)PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_n_s_config),
            __pyx_mstate_global_static.__pyx_tuple__48 == (PyObject *)0x0)))))))) ||
        (pPVar23 = __pyx_mstate_global_static.__pyx_empty_tuple,
        __pyx_mstate_global_static.__pyx_codeobj__49 =
             (PyObject *)
             PyCode_New(1,0,1,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                        __pyx_mstate_global_static.__pyx_empty_tuple,
                        __pyx_mstate_global_static.__pyx_empty_tuple,
                        __pyx_mstate_global_static.__pyx_tuple__48,
                        __pyx_mstate_global_static.__pyx_empty_tuple,
                        __pyx_mstate_global_static.__pyx_empty_tuple,
                        __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_extensions_2,
                        __pyx_mstate_global_static.__pyx_n_s_load_component,0x129,
                        __pyx_mstate_global_static.__pyx_empty_bytes),
        __pyx_mstate_global_static.__pyx_codeobj__49 == (PyObject *)0x0)))) {
      iVar5 = 1;
      iVar19 = 0x4462;
      bVar2 = true;
      goto LAB_0010b26c;
    }
                    /* Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct___handle_agent_event =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct___handle_agent_event;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct___handle_agent_event
                              );
    if (iVar5 < 0) {
LAB_00108fb0:
      iVar5 = 1;
      iVar19 = 0x4467;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_1__register_agent_method =
         &
         __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_1__register_agent_method
    ;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_1__register_agent_method
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_2__handle_list_extensions =
         &
         __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_2__handle_list_extensions
    ;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_2__handle_list_extensions
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_3__handle_call_agent =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_3__handle_call_agent;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_3__handle_call_agent
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_4__handle_qidiclient_files_list
         = &
           __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_4__handle_qidiclient_files_list
    ;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_4__handle_qidiclient_files_list
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_5__handle_qidiclient_files_stats
         = &
           __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_5__handle_qidiclient_files_stats
    ;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_5__handle_qidiclient_files_stats
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_6__handle_qidiclient_config_offical_filament_list
         = &
           __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_6__handle_qidiclient_config_offical_filament_list
    ;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_6__handle_qidiclient_config_offical_filament_list
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_7_start_unix_server =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_7_start_unix_server;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_7_start_unix_server
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_8_close =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_8_close;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_8_close
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_9__read_messages =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_9__read_messages;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_9__read_messages
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_10_write_to_socket =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_10_write_to_socket;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_10_write_to_socket
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_11__on_close =
         &__pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_11__on_close;
    iVar5 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_10extensions___pyx_scope_struct_11__on_close
                              );
    if (iVar5 < 0) goto LAB_00108fb0;
    pPVar11 = extraout_x1;
    if (abc_patched_21164 == 0) {
                    /* Unresolved local var: PyObject * module@[???] */
      auVar28 = PyImport_ImportModule("collections.abc");
      if (auVar28._0_8_ == (PyObject *)0x0) {
        PyErr_WriteUnraisable();
        iVar5 = PyErr_WarnEx(*(undefined8 *)PTR_PyExc_RuntimeWarning_00143fa8,
                             "Cython module failed to register with collections.abc module",1);
        if (-1 < iVar5) {
LAB_00109100:
          auVar28 = PyImport_ImportModule("backports_abc");
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if ((auVar28._0_8_ == (PyObject *)0x0) ||
             (pPVar9 = __Pyx_Coroutine_patch_module(auVar28._0_8_,auVar28._8_8_),
             pPVar9 == (PyObject *)0x0)) {
            PyErr_Clear();
            pPVar11 = extraout_x1_06;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar7 = pPVar9->ob_refcnt + -1;
            pPVar9->ob_refcnt = lVar7;
            pPVar11 = extraout_x1_00;
            if (lVar7 == 0) {
              (*pPVar9->ob_type->tp_dealloc)(pPVar9);
              pPVar11 = extraout_x1_01;
            }
          }
          goto LAB_00109134;
        }
      }
      else {
        pPVar11 = __Pyx_Coroutine_patch_module(auVar28._0_8_,auVar28._8_8_);
        abc_patched_21164 = 1;
        if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar7 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar7;
          if (lVar7 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          goto LAB_00109100;
        }
      }
      iVar5 = 1;
      iVar19 = 0x446d;
      bVar2 = true;
      goto LAB_0010b26c;
    }
LAB_00109134:
    p_Var10 = (_typeobject *)
              __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_asyncio,pPVar11);
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x4477;
      iVar5 = 7;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_asyncio,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      p_Var18 = (_typeobject *)0x0;
      iVar19 = 0x4479;
      iVar5 = 7;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    pPVar11 = extraout_x1_02;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
      pPVar11 = extraout_x1_03;
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_pathlib,pPVar11);
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x4483;
      iVar5 = 8;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_pathlib,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      p_Var18 = (_typeobject *)0x0;
      iVar19 = 0x4485;
      iVar5 = 8;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    pPVar11 = extraout_x1_04;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
      pPVar11 = extraout_x1_05;
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_logging,pPVar11);
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x448f;
      iVar5 = 9;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_logging,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      p_Var18 = (_typeobject *)0x0;
      iVar19 = 0x4491;
      iVar5 = 9;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyList_New(3);
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection;
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x449b;
      iVar5 = 10;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    p_Var18 = ((PyObject *)((long)p_Var10 + 0x10))->ob_type;
    (__pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection)->ob_refcnt + 1;
    (p_Var18->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_RequestType;
    (__pyx_mstate_global_static.__pyx_n_s_RequestType)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_RequestType)->ob_refcnt + 1;
    (p_Var18->ob_base).ob_base.ob_type = (_typeobject *)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_TransportType;
    (__pyx_mstate_global_static.__pyx_n_s_TransportType)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_TransportType)->ob_refcnt + 1;
    (p_Var18->ob_base).ob_size = (Py_ssize_t)pPVar11;
    p_Var18 = (_typeobject *)
              __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_common,(PyObject *)p_Var10,2);
    if (p_Var18 == (_typeobject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44a6;
      iVar5 = 10;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,
                               __pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44a9;
      iVar5 = 10;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44ab;
      iVar5 = 10;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,__pyx_mstate_global_static.__pyx_n_s_RequestType)
    ;
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44ad;
      iVar5 = 10;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_RequestType,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44af;
      iVar5 = 10;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,
                               __pyx_mstate_global_static.__pyx_n_s_TransportType);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44b1;
      iVar5 = 10;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_TransportType,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44b3;
      iVar5 = 10;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    p_Var18 = (_typeobject *)PyList_New(1);
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials;
    if (p_Var18 == (_typeobject *)0x0) {
      iVar19 = 0x44be;
      iVar5 = 0xb;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    p_Var10 = *(_typeobject **)&((PyVarObject *)&p_Var18->tp_name)->ob_base;
    (__pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials)->ob_refcnt + 1;
    *(PyObject **)&p_Var10->ob_base = pPVar11;
    p_Var10 = (_typeobject *)
              __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_utils,(PyObject *)p_Var18,2);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44c3;
      iVar5 = 0xb;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    p_Var18 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var10,
                               __pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials);
    if (p_Var18 == (_typeobject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44c6;
      iVar5 = 0xb;
LAB_0010b214:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
      ((PyObject *)p_Var10)->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      pPVar26 = (PyObject *)0x0;
      pPVar27 = pPVar9;
      if (p_Var18 != (_typeobject *)0x0) {
        pPVar26 = (PyObject *)0x0;
LAB_0010b240:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
        (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
        if (lVar7 == 0) {
          (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
        }
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (pPVar11 != (PyObject *)0x0) {
LAB_0010b874:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar7 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar7;
        if (lVar7 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if ((pPVar27 != (PyObject *)0x0) &&
         (lVar7 = pPVar27->ob_refcnt + -1, pPVar27->ob_refcnt = lVar7, lVar7 == 0)) {
        (*pPVar27->ob_type->tp_dealloc)(pPVar27);
      }
      bVar2 = true;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar26 != (PyObject *)0x0) &&
         (lVar7 = pPVar26->ob_refcnt + -1, pPVar26->ob_refcnt = lVar7, lVar7 == 0)) {
        (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      }
      goto LAB_0010b26c;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials,p_Var18);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44c8;
      iVar5 = 0xb;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyList_New(6);
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING;
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x44d3;
      iVar5 = 0xf;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    p_Var18 = ((PyObject *)((long)p_Var10 + 0x10))->ob_type;
    (__pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING)->ob_refcnt + 1;
    (p_Var18->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_Any;
    (__pyx_mstate_global_static.__pyx_n_s_Any)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_Any)->ob_refcnt + 1;
    (p_Var18->ob_base).ob_base.ob_type = (_typeobject *)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_Dict;
    (__pyx_mstate_global_static.__pyx_n_s_Dict)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_Dict)->ob_refcnt + 1;
    (p_Var18->ob_base).ob_size = (Py_ssize_t)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_List;
    (__pyx_mstate_global_static.__pyx_n_s_List)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_List)->ob_refcnt + 1;
    p_Var18->tp_name = (char *)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_Optional;
    (__pyx_mstate_global_static.__pyx_n_s_Optional)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_Optional)->ob_refcnt + 1;
    p_Var18->tp_basicsize = (Py_ssize_t)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_Union;
    p_Var21 = (_typeobject *)((__pyx_mstate_global_static.__pyx_n_s_Union)->ob_refcnt + 1);
    (__pyx_mstate_global_static.__pyx_n_s_Union)->ob_refcnt = (Py_ssize_t)p_Var21;
    p_Var18->tp_itemsize = (Py_ssize_t)pPVar11;
    p_Var18 = (_typeobject *)
              __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_typing,(PyObject *)p_Var10,0);
    if (p_Var18 == (_typeobject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44ef;
      iVar5 = 0xe;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,
                               __pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44f2;
      iVar5 = 0xe;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44f4;
      iVar5 = 0xf;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,__pyx_mstate_global_static.__pyx_n_s_Any);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44f6;
      iVar5 = 0xe;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_Any,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44f8;
      iVar5 = 0x10;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,__pyx_mstate_global_static.__pyx_n_s_Dict);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44fa;
      iVar5 = 0xe;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_Dict,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x44fc;
      iVar5 = 0x11;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,__pyx_mstate_global_static.__pyx_n_s_List);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x44fe;
      iVar5 = 0xe;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_List,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4500;
      iVar5 = 0x12;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,__pyx_mstate_global_static.__pyx_n_s_Optional);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4502;
      iVar5 = 0xe;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_Optional,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4504;
      iVar5 = 0x13;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_ImportFrom((PyObject *)p_Var18,__pyx_mstate_global_static.__pyx_n_s_Union);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4506;
      iVar5 = 0xe;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_Union,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4508;
      iVar5 = 0x14;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    p_Var18 = (_typeobject *)__pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_cached_value;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type ==
        (_typeobject *)__pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_version) {
      if (__pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_cached_value == (PyObject *)0x0)
      {
        p_Var18 = (_typeobject *)
                  __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING);
        goto LAB_00109784;
      }
      __pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_cached_value->ob_refcnt =
           __pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_cached_value->ob_refcnt + 1;
    }
    else {
      p_Var18 = (_typeobject *)
                __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_TYPE_CHECKING,
                           &__pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_version,
                           &__pyx_pymod_exec_extensions::lexical_block_20::__pyx_dict_cached_value);
LAB_00109784:
      if (p_Var18 == (_typeobject *)0x0) {
        iVar19 = 0x4513;
        iVar5 = 0x17;
        bVar2 = true;
        goto LAB_0010b26c;
      }
    }
                    /* Unresolved local var: int is_true@[???] */
    uVar6 = (uint)(p_Var18 == (_typeobject *)PTR__Py_TrueStruct_00143f48);
    pPVar27 = (PyObject *)0x0;
    if (((p_Var18 != (_typeobject *)PTR__Py_TrueStruct_00143f48 &&
         p_Var18 != (_typeobject *)PTR__Py_FalseStruct_00143f10) &&
         p_Var18 != (_typeobject *)PTR__Py_NoneStruct_00143f40) &&
       (uVar6 = PyObject_IsTrue(p_Var18), (int)uVar6 < 0)) {
      pPVar26 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4515;
      iVar5 = 0x17;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    if (uVar6 != 0) {
      p_Var18 = (_typeobject *)PyList_New(1);
      pPVar11 = __pyx_mstate_global_static.__pyx_n_s_Server;
      if (p_Var18 != (_typeobject *)0x0) {
        p_Var10 = *(_typeobject **)&((PyVarObject *)&p_Var18->tp_name)->ob_base;
        (__pyx_mstate_global_static.__pyx_n_s_Server)->ob_refcnt =
             (__pyx_mstate_global_static.__pyx_n_s_Server)->ob_refcnt + 1;
        *(PyObject **)&p_Var10->ob_base = pPVar11;
        p_Var10 = (_typeobject *)
                  __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_server,(PyObject *)p_Var18,2);
        if (p_Var10 != (_typeobject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
          (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
          if (lVar7 == 0) {
            (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
          }
          p_Var18 = (_typeobject *)
                    __Pyx_ImportFrom((PyObject *)p_Var10,__pyx_mstate_global_static.__pyx_n_s_Server
                                    );
          if (p_Var18 == (_typeobject *)0x0) {
            pPVar9 = (PyObject *)0x0;
            pPVar11 = (PyObject *)0x0;
            iVar19 = 0x4528;
            iVar5 = 0x18;
          }
          else {
            iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                                   __pyx_mstate_global_static.__pyx_n_s_Server,p_Var18);
            if (iVar5 < 0) {
              pPVar9 = (PyObject *)0x0;
              pPVar11 = (PyObject *)0x0;
              iVar19 = 0x452a;
              iVar5 = 0x18;
            }
            else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
              (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
              if (lVar7 == 0) {
                (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
              ((PyObject *)p_Var10)->ob_refcnt = lVar7;
              if (lVar7 == 0) {
                (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
              }
              p_Var10 = (_typeobject *)PyList_New(1);
              pPVar11 = __pyx_mstate_global_static.__pyx_n_s_ConfigHelper;
              if (p_Var10 == (_typeobject *)0x0) {
                iVar19 = 0x4535;
                iVar5 = 0x19;
                bVar2 = true;
                goto LAB_0010b26c;
              }
              p_Var18 = ((PyObject *)((long)p_Var10 + 0x10))->ob_type;
              (__pyx_mstate_global_static.__pyx_n_s_ConfigHelper)->ob_refcnt =
                   (__pyx_mstate_global_static.__pyx_n_s_ConfigHelper)->ob_refcnt + 1;
              (p_Var18->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar11;
              p_Var18 = (_typeobject *)
                        __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_confighelper,
                                     (PyObject *)p_Var10,2);
              if (p_Var18 == (_typeobject *)0x0) {
                pPVar9 = (PyObject *)0x0;
                pPVar11 = (PyObject *)0x0;
                iVar19 = 0x453a;
                iVar5 = 0x19;
              }
              else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                ((PyObject *)p_Var10)->ob_refcnt = lVar7;
                if (lVar7 == 0) {
                  (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
                }
                p_Var10 = (_typeobject *)
                          __Pyx_ImportFrom((PyObject *)p_Var18,
                                           __pyx_mstate_global_static.__pyx_n_s_ConfigHelper);
                if (p_Var10 == (_typeobject *)0x0) {
                  pPVar26 = (PyObject *)0x0;
                  pPVar27 = (PyObject *)0x0;
                  iVar19 = 0x453d;
                  iVar5 = 0x19;
                  pPVar11 = (PyObject *)0x0;
                  goto LAB_0010b240;
                }
                iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                                       __pyx_mstate_global_static.__pyx_n_s_ConfigHelper,p_Var10);
                if (iVar5 < 0) {
                  pPVar9 = (PyObject *)0x0;
                  pPVar11 = (PyObject *)0x0;
                  iVar19 = 0x453f;
                  iVar5 = 0x19;
                }
                else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                  ((PyObject *)p_Var10)->ob_refcnt = lVar7;
                  if (lVar7 == 0) {
                    (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
                  if (lVar7 == 0) {
                    (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
                  }
                  p_Var18 = (_typeobject *)PyList_New(1);
                  pPVar11 = __pyx_mstate_global_static.__pyx_n_s_WebRequest;
                  if (p_Var18 == (_typeobject *)0x0) {
                    iVar19 = 0x454a;
                    iVar5 = 0x1a;
                    bVar2 = true;
                    goto LAB_0010b26c;
                  }
                  p_Var10 = *(_typeobject **)&((PyVarObject *)&p_Var18->tp_name)->ob_base;
                  (__pyx_mstate_global_static.__pyx_n_s_WebRequest)->ob_refcnt =
                       (__pyx_mstate_global_static.__pyx_n_s_WebRequest)->ob_refcnt + 1;
                  *(PyObject **)&p_Var10->ob_base = pPVar11;
                  p_Var10 = (_typeobject *)
                            __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_common,
                                         (PyObject *)p_Var18,2);
                  if (p_Var10 == (_typeobject *)0x0) {
                    pPVar26 = (PyObject *)0x0;
                    pPVar27 = (PyObject *)0x0;
                    pPVar11 = (PyObject *)0x0;
                    iVar19 = 0x454f;
                    iVar5 = 0x1a;
                    goto LAB_0010b240;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
                  if (lVar7 == 0) {
                    (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
                  }
                  p_Var18 = (_typeobject *)
                            __Pyx_ImportFrom((PyObject *)p_Var10,
                                             __pyx_mstate_global_static.__pyx_n_s_WebRequest);
                  if (p_Var18 == (_typeobject *)0x0) {
                    pPVar9 = (PyObject *)0x0;
                    pPVar11 = (PyObject *)0x0;
                    iVar19 = 0x4552;
                    iVar5 = 0x1a;
                  }
                  else {
                    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                                           __pyx_mstate_global_static.__pyx_n_s_WebRequest,p_Var18);
                    if (iVar5 < 0) {
                      pPVar9 = (PyObject *)0x0;
                      pPVar11 = (PyObject *)0x0;
                      iVar19 = 0x4554;
                      iVar5 = 0x1a;
                    }
                    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
                      if (lVar7 == 0) {
                        (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                      ((PyObject *)p_Var10)->ob_refcnt = lVar7;
                      if (lVar7 == 0) {
                        (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
                      }
                      p_Var10 = (_typeobject *)PyList_New(1);
                      pPVar11 = __pyx_mstate_global_static.__pyx_n_s_KlippyConnection;
                      if (p_Var10 == (_typeobject *)0x0) {
                        iVar19 = 0x455f;
                        iVar5 = 0x1b;
                        bVar2 = true;
                        goto LAB_0010b26c;
                      }
                      p_Var21 = ((PyObject *)((long)p_Var10 + 0x10))->ob_type;
                      (__pyx_mstate_global_static.__pyx_n_s_KlippyConnection)->ob_refcnt =
                           (__pyx_mstate_global_static.__pyx_n_s_KlippyConnection)->ob_refcnt + 1;
                      (p_Var21->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar11;
                      p_Var18 = (_typeobject *)
                                __Pyx_Import(__pyx_mstate_global_static.__pyx_n_s_klippy_connection,
                                             (PyObject *)p_Var10,1);
                      if (p_Var18 == (_typeobject *)0x0) {
                        pPVar9 = (PyObject *)0x0;
                        pPVar11 = (PyObject *)0x0;
                        iVar19 = 0x4564;
                        iVar5 = 0x1b;
                      }
                      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                        ((PyObject *)p_Var10)->ob_refcnt = lVar7;
                        if (lVar7 == 0) {
                          (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
                        }
                        p_Var10 = (_typeobject *)
                                  __Pyx_ImportFrom((PyObject *)p_Var18,
                                                   __pyx_mstate_global_static.
                                                   __pyx_n_s_KlippyConnection);
                        if (p_Var10 == (_typeobject *)0x0) {
                          pPVar26 = (PyObject *)0x0;
                          pPVar27 = (PyObject *)0x0;
                          iVar19 = 0x4567;
                          iVar5 = 0x1b;
                          pPVar11 = (PyObject *)0x0;
                          goto LAB_0010b240;
                        }
                        iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                                               __pyx_mstate_global_static.__pyx_n_s_Klippy,p_Var10);
                        if (-1 < iVar5) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                          ((PyObject *)p_Var10)->ob_refcnt = lVar7;
                          if (lVar7 == 0) {
                            (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
                          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
                          (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
                          if (lVar7 == 0) {
                            (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18)
                            ;
                          }
                          goto LAB_00109b40;
                        }
                        pPVar9 = (PyObject *)0x0;
                        pPVar11 = (PyObject *)0x0;
                        iVar19 = 0x4569;
                        iVar5 = 0x1b;
                      }
                    }
                  }
                }
              }
            }
          }
          goto LAB_0010b214;
        }
        pPVar26 = (PyObject *)0x0;
        pPVar27 = (PyObject *)0x0;
        pPVar11 = (PyObject *)0x0;
        iVar19 = 0x4525;
        iVar5 = 0x18;
        goto LAB_0010b240;
      }
      iVar19 = 0x4520;
      iVar5 = 0x18;
      bVar2 = true;
      goto LAB_0010b26c;
    }
LAB_00109b40:
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_UNIX_BUFFER_LIMIT,
                           __pyx_mstate_global_static.__pyx_int_20971520);
    if (iVar5 < 0) {
      iVar19 = 0x457d;
      iVar5 = 0x1d;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    p_Var18 = (_typeobject *)
              __Pyx_Py3MetaclassPrepare
                        ((PyObject *)0x0,__pyx_mstate_global_static.__pyx_empty_tuple,
                         __pyx_mstate_global_static.__pyx_n_s_ExtensionManager,
                         __pyx_mstate_global_static.__pyx_n_s_ExtensionManager,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         (PyObject *)p_Var21,pPVar23);
    if (p_Var18 == (_typeobject *)0x0) {
      iVar19 = 0x4586;
      iVar5 = 0x1f;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4590;
      iVar5 = 0x20;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_config,
                           __pyx_mstate_global_static.__pyx_n_s_ConfigHelper);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4592;
      iVar5 = 0x20;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4593;
      iVar5 = 0x20;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_1__init__
                         ,0,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager___init,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__24,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x4594;
      iVar5 = 0x20;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_init,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_init,pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4598;
      iVar5 = 0x20;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x45a2;
      iVar5 = 0x3e;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_connection,
                           __pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45a4;
      iVar5 = 0x3e;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45a5;
      iVar5 = 0x3e;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_3register_agent
                         ,0,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager_register_agent,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__26,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x45a6;
      iVar5 = 0x3e;
      pPVar26 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_register_agent,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_register_agent[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_register_agent,p_Var10)
      ;
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45aa;
      iVar5 = 0x3e;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45b4;
      iVar5 = 0x58;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_connection,
                           __pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45b6;
      iVar5 = 0x58;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45b7;
      iVar5 = 0x58;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_5remove_agent
                         ,0,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager_remove_agent,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__28,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x45b8;
      iVar5 = 0x58;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_remove_agent,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_remove_agent[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_remove_agent,pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45bc;
      iVar5 = 0x58;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x45c6;
      iVar5 = 99;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45c8;
      iVar5 = 99;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_str);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45c9;
      iVar5 = 99;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_7_handle_agent_event
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_agent_e,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj_,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x45ca;
      iVar5 = 99;
      pPVar26 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_agent_event,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_handle_agent_event[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_agent_event,
                                p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45ce;
      iVar5 = 99;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45d8;
      iVar5 = 0x77;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45da;
      iVar5 = 0x77;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_str);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45db;
      iVar5 = 0x77;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_10_register_agent_method
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__register_agent,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__3,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x45dc;
      iVar5 = 0x77;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_register_agent_method,pPVar11
                          ,__pyx_mstate_global_static.__pyx_n_s_register_agent_method[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_register_agent_method,
                                pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45e0;
      iVar5 = 0x77;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x45ea;
      iVar5 = 0x81;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45ec;
      iVar5 = 0x81;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_kp_s_Dict_str_List_Dict_str_Any);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x45ed;
      iVar5 = 0x81;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_13_handle_list_extensions
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_list_ex,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__4,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x45ee;
      iVar5 = 0x81;
      pPVar26 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_list_extensions,
                          p_Var10,__pyx_mstate_global_static.__pyx_n_s_handle_list_extensions[1].
                                  ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_list_extensions,
                                p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45f2;
      iVar5 = 0x81;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45fc;
      iVar5 = 0x88;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45fe;
      iVar5 = 0x88;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_Any);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x45ff;
      iVar5 = 0x88;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_16_handle_call_agent
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_call_ag,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__5,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x4600;
      iVar5 = 0x88;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_call_agent,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_handle_call_agent[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_call_agent,
                                pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4604;
      iVar5 = 0x88;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x460e;
      iVar5 = 0x96;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4610;
      iVar5 = 0x96;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4611;
      iVar5 = 0x96;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_19_select_qidiclient
                         ,0,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__select_qidicli,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__34,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4612;
      iVar5 = 0x96;
      pPVar26 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_select_qidiclient,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_select_qidiclient[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_select_qidiclient,
                                p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4616;
      iVar5 = 0x96;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4620;
      iVar5 = 0xa2;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4622;
      iVar5 = 0xa2;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_Any);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4623;
      iVar5 = 0xa2;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_21_handle_qidiclient_files_list
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_qidicli,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__9,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x4624;
      iVar5 = 0xa2;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_list,
                          pPVar11,__pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_list
                                  [1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.
                                        __pyx_n_s_handle_qidiclient_files_list,pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4628;
      iVar5 = 0xa2;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4632;
      iVar5 = 0xa6;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4634;
      iVar5 = 0xa6;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_Any);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4635;
      iVar5 = 0xa6;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_24_handle_qidiclient_files_stats
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_qidicli_2,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__10,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4636;
      iVar5 = 0xa6;
      pPVar26 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_stats
                          ,p_Var10,__pyx_mstate_global_static.
                                   __pyx_n_s_handle_qidiclient_files_stats[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.
                                        __pyx_n_s_handle_qidiclient_files_stats,p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x463a;
      iVar5 = 0xa6;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4644;
      iVar5 = 0xaa;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_web_request,
                           __pyx_mstate_global_static.__pyx_n_s_WebRequest);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4646;
      iVar5 = 0xaa;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_Any);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4647;
      iVar5 = 0xaa;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_27_handle_qidiclient_config_offical_filament_list
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_qidicli_3,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__11,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x4648;
      iVar5 = 0xaa;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.
                                  __pyx_n_s_handle_qidiclient_config_offica,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_config_offica[1].
                          ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.
                                        __pyx_n_s_handle_qidiclient_config_offica,pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x464c;
      iVar5 = 0xaa;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4656;
      iVar5 = 0xae;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4658;
      iVar5 = 0xae;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_30start_unix_server
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager_start_unix_serv,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__12,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x4659;
      iVar5 = 0xae;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_start_unix_server,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_start_unix_server[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_start_unix_server,
                                p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x465d;
      iVar5 = 0xae;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4667;
      iVar5 = 0xbc;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_reader,
                           __pyx_mstate_global_static.__pyx_kp_s_asyncio_StreamReader);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4669;
      iVar5 = 0xbc;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_writer,
                           __pyx_mstate_global_static.__pyx_kp_s_asyncio_StreamWriter);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x466a;
      iVar5 = 0xbc;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x466b;
      iVar5 = 0xbc;
      goto LAB_0010b214;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_33on_unix_socket_connected
                         ,0,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager_on_unix_socket,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__38,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar19 = 0x466c;
      iVar5 = 0xbc;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_on_unix_socket_connected,
                          pPVar11,__pyx_mstate_global_static.__pyx_n_s_on_unix_socket_connected[1].
                                  ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.
                                        __pyx_n_s_on_unix_socket_connected,pPVar11);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4670;
      iVar5 = 0xbc;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x467a;
      iVar5 = 0xc3;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x467c;
      iVar5 = 0xc3;
      goto LAB_0010b240;
    }
    pPVar9 = __pyx_mstate_global_static.__pyx_d;
    pPVar26 = __pyx_mstate_global_static.__pyx_codeobj__14;
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&__pyx_mdef_9moonraker_10components_10extensions_16ExtensionManager_35close
                         ,8,__pyx_mstate_global_static.__pyx_n_s_ExtensionManager_close,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__14,pPVar23);
    iVar5 = (int)pPVar26;
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x467d;
      iVar5 = 0xc3;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar11->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if ((p_Var18->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (p_Var18,__pyx_mstate_global_static.__pyx_n_s_close,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_close[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_close,p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4681;
      iVar5 = 0xc3;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)
              __Pyx_Py3ClassCreate
                        ((PyObject *)PTR_PyType_Type_00143f38,
                         __pyx_mstate_global_static.__pyx_n_s_ExtensionManager,
                         __pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)p_Var18,pPVar9,
                         iVar5,(int)pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      iVar19 = 0x468b;
      iVar5 = 0x1f;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_ExtensionManager,p_Var10);
    if (iVar5 < 0) {
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x468d;
      iVar5 = 0x1f;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    p_Var18 = (_typeobject *)
              __pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_cached_value_1;
    p_Var21 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
    if (p_Var21 ==
        (_typeobject *)__pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_version_1) {
      if (__pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_cached_value_1 ==
          (PyObject *)0x0) {
        p_Var18 = (_typeobject *)
                  __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection);
        goto LAB_0010a888;
      }
      __pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_cached_value_1->ob_refcnt =
           __pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_cached_value_1->ob_refcnt + 1;
    }
    else {
      p_Var18 = (_typeobject *)
                __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_BaseRemoteConnection,
                           &__pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_version_1,
                           &__pyx_pymod_exec_extensions::lexical_block_64::__pyx_dict_cached_value_1
                          );
LAB_0010a888:
      if (p_Var18 == (_typeobject *)0x0) {
        iVar19 = 0x4698;
        iVar5 = 0xc9;
        bVar2 = true;
        goto LAB_0010b26c;
      }
    }
    p_Var10 = (_typeobject *)PyTuple_New(1);
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x469a;
      iVar5 = 0xc9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t j@[???]
                       Unresolved local var: Py_ssize_t size_bases@[???]
                       Unresolved local var: PyObject * base@[???]
                       Unresolved local var: PyObject * meth@[???]
                       Unresolved local var: PyObject * new_base@[???]
                       Unresolved local var: PyObject * result@[???]
                       Unresolved local var: PyObject * new_bases@[???] */
    lVar8 = ((PyObject *)&(p_Var10->ob_base).ob_size)->ob_refcnt;
    *(_typeobject **)&((PyVarObject *)&p_Var10->tp_name)->ob_base = p_Var18;
    plVar25 = (long *)0x0;
    for (lVar7 = 0; lVar7 < lVar8; lVar7 = lVar7 + 1) {
      pPVar11 = (PyObject *)(&p_Var10->tp_name)[lVar7];
      if ((int)pPVar11->ob_type->tp_flags < 0) {
LAB_0010a8d0:
        if (plVar25 == (long *)0x0) {
          plVar25 = (long *)0x0;
        }
        else {
          iVar5 = PyList_Append(plVar25,pPVar11);
          if (iVar5 < 0) {
LAB_0010aa20:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar7 = *plVar25;
            *plVar25 = lVar7 + -1;
            if (lVar7 + -1 == 0) {
              pPVar9 = (PyObject *)0x0;
              pPVar11 = (PyObject *)0x0;
              iVar19 = 0x469f;
              iVar5 = 0xc9;
              p_Var18 = (_typeobject *)0x0;
              (**(code **)(plVar25[1] + 0x30))(plVar25);
            }
            else {
              pPVar9 = (PyObject *)0x0;
              pPVar11 = (PyObject *)0x0;
              p_Var18 = (_typeobject *)0x0;
              iVar19 = 0x469f;
              iVar5 = 0xc9;
            }
            goto LAB_0010b214;
          }
        }
      }
      else {
        pPVar9 = __Pyx_PyObject_GetAttrStrNoError
                           (pPVar11,__pyx_mstate_global_static.__pyx_n_s_mro_entries);
        if (pPVar9 == (PyObject *)0x0) {
          lVar12 = PyErr_Occurred();
          if (lVar12 != 0) goto LAB_0010aa1c;
          goto LAB_0010a8d0;
        }
        args[0] = (PyObject *)0x0;
        args[1] = (PyObject *)p_Var10;
        p_Var18 = (_typeobject *)
                  __Pyx_PyObject_FastCallDict
                            (pPVar9,args + 1,0x8000000000000001,(PyObject *)p_Var21);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = pPVar9->ob_refcnt + -1;
        pPVar9->ob_refcnt = lVar12;
        if (lVar12 == 0) {
          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
        }
        if (p_Var18 == (_typeobject *)0x0) {
LAB_0010aa1c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (plVar25 != (long *)0x0) goto LAB_0010aa20;
LAB_0010b764:
          p_Var18 = (_typeobject *)0x0;
          pPVar9 = (PyObject *)0x0;
          pPVar11 = (PyObject *)0x0;
          iVar19 = 0x469f;
          iVar5 = 0xc9;
          goto LAB_0010b214;
        }
        if (((uint)((p_Var18->ob_base).ob_base.ob_type)->tp_flags >> 0x1a & 1) == 0) {
          PyErr_SetString(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                          "__mro_entries__ must return a tuple");
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
          (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
          if (lVar7 == 0) {
            (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
          }
          goto LAB_0010aa1c;
        }
        if (plVar25 == (long *)0x0) {
          plVar25 = (long *)PyList_New(lVar7);
          if (plVar25 != (long *)0x0) {
            for (lVar12 = 0; lVar7 != lVar12; lVar12 = lVar12 + 1) {
              plVar14 = (long *)(&p_Var10->tp_name)[lVar12];
              lVar16 = *plVar14;
              *(long **)(plVar25[3] + lVar12 * 8) = plVar14;
              *plVar14 = lVar16 + 1;
            }
            goto LAB_0010a95c;
          }
          goto LAB_0010b764;
        }
LAB_0010a95c:
        p_Var21 = p_Var18;
        iVar5 = PyList_SetSlice(plVar25,plVar25[2]);
        if (iVar5 < 0) goto LAB_0010aa20;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
        (p_Var18->ob_base).ob_base.ob_refcnt = lVar12;
        if (lVar12 == 0) {
          (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
        }
      }
    }
    if (plVar25 == (long *)0x0) {
      *(long *)&p_Var10->ob_base = *(long *)&p_Var10->ob_base + 1;
      p_Var18 = p_Var10;
    }
    else {
      p_Var18 = (_typeobject *)PyList_AsTuple(plVar25);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = *plVar25;
      *plVar25 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar25[1] + 0x30))(plVar25);
      }
      if (p_Var18 == (_typeobject *)0x0) {
        pPVar9 = (PyObject *)0x0;
        p_Var18 = (_typeobject *)0x0;
        iVar19 = 0x469f;
        iVar5 = 0xc9;
        pPVar11 = (PyObject *)0x0;
        goto LAB_0010b214;
      }
    }
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t nbases@[???] */
    lVar8 = (p_Var18->ob_base).ob_size;
                    /* Unresolved local var: PyTypeObject * tmptype@[???]
                       Unresolved local var: PyObject * tmp@[???] */
    pPVar11 = (PyObject *)0x0;
    for (lVar7 = 0; pPVar26 = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
        pPVar9 = __pyx_mstate_global_static.__pyx_n_s_UnixSocketClient, lVar7 < lVar8;
        lVar7 = lVar7 + 1) {
      pPVar26 = *(PyObject **)((long)(&p_Var18->tp_name)[lVar7] + 8);
      pPVar9 = pPVar26;
      if (((pPVar11 != (PyObject *)0x0) &&
          (iVar5 = PyType_IsSubtype(pPVar11,pPVar26), pPVar9 = pPVar11, iVar5 == 0)) &&
         (iVar5 = PyType_IsSubtype(pPVar26,pPVar11), pPVar9 = pPVar26, iVar5 == 0)) {
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t nbases@[???]
                       Unresolved local var: PyTypeObject * tmptype@[???]
                       Unresolved local var: PyObject * tmp@[???] */
        pPVar9 = (PyObject *)0x0;
        pPVar11 = (PyObject *)0x0;
        iVar19 = 0x46a1;
        iVar5 = 0xc9;
        PyErr_SetString(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                        "metaclass conflict: the metaclass of a derived class must be a (non-strict) subclass of the metaclasses of all its bases"
                       );
        goto LAB_0010b214;
      }
      pPVar11 = pPVar9;
    }
    if (pPVar11 == (PyObject *)0x0) {
      pPVar11 = (PyObject *)PTR_PyType_Type_00143f38;
    }
    pPVar20 = (PyObject *)(pPVar11->ob_refcnt + 1);
    pPVar11->ob_refcnt = (Py_ssize_t)pPVar20;
    pPVar9 = __Pyx_Py3MetaclassPrepare
                       (pPVar11,(PyObject *)p_Var18,pPVar9,pPVar9,pPVar26,pPVar20,pPVar23);
    if (pPVar9 == (PyObject *)0x0) {
      iVar19 = 0x46a3;
      iVar5 = 0xc9;
      goto LAB_0010b214;
    }
    if ((p_Var10 != p_Var18) &&
       (iVar5 = PyDict_SetItemString(pPVar9,"__orig_bases__",p_Var10), iVar5 < 0)) {
      iVar19 = 0x46a6;
      iVar5 = 0xc9;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = *(long *)&p_Var10->ob_base + -1;
    *(long *)&p_Var10->ob_base = lVar7;
    if (lVar7 == 0) {
      (*((p_Var10->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x46b1;
      iVar5 = 0xca;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_server,
                           __pyx_mstate_global_static.__pyx_n_s_Server);
    if (iVar5 < 0) {
      iVar19 = 0x46b3;
      iVar5 = 0xca;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_reader,
                           __pyx_mstate_global_static.__pyx_kp_s_asyncio_StreamReader);
    if (iVar5 < 0) {
      iVar19 = 0x46b4;
      iVar5 = 0xca;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_writer,
                           __pyx_mstate_global_static.__pyx_kp_s_asyncio_StreamWriter);
    if (iVar5 < 0) {
      iVar19 = 0x46b5;
      iVar5 = 0xca;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_peercred,
                           __pyx_mstate_global_static.__pyx_kp_s_Dict_str_int);
    if (iVar5 < 0) {
      iVar19 = 0x46b6;
      iVar5 = 0xca;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      iVar19 = 0x46b7;
      iVar5 = 0xca;
      goto LAB_0010b214;
    }
    pPVar26 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16UnixSocketClient_1__init__
                         ,0,__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient___init,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__41,pPVar23);
    if (pPVar26 == (PyObject *)0x0) {
      iVar19 = 0x46b8;
      iVar5 = 0xca;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar26[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (pPVar9,__pyx_mstate_global_static.__pyx_n_s_init,pPVar26,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_init,pPVar26);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      iVar19 = 0x46bc;
      iVar5 = 0xca;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar26->ob_refcnt + -1;
    pPVar26->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
    }
    pPVar26 = (PyObject *)PyDict_New();
    if (pPVar26 == (PyObject *)0x0) {
      iVar19 = 0x46c6;
      iVar5 = 0xdf;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_reader,
                           __pyx_mstate_global_static.__pyx_kp_s_asyncio_StreamReader);
    if (iVar5 < 0) {
      iVar19 = 0x46c8;
      iVar5 = 0xdf;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      iVar19 = 0x46c9;
      iVar5 = 0xdf;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16UnixSocketClient_3_read_messages
                         ,8,__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient__read_messages,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__15,pPVar23);
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x46ca;
      iVar5 = 0xdf;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar26->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar26;
    if (lVar7 == 0) {
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
    }
    if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (pPVar9,__pyx_mstate_global_static.__pyx_n_s_read_messages,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_read_messages[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_read_messages,p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      iVar19 = 0x46ce;
      iVar5 = 0xdf;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x46d8;
      iVar5 = 0xf5;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_message,
                           __pyx_mstate_global_static.__pyx_kp_s_Union_bytes_str);
    if (iVar5 < 0) {
      iVar19 = 0x46da;
      iVar5 = 0xf5;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      iVar19 = 0x46db;
      iVar5 = 0xf5;
      goto LAB_0010b214;
    }
    pPVar26 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16UnixSocketClient_6write_to_socket
                         ,8,__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient_write_to_socket,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__18,pPVar23);
    if (pPVar26 == (PyObject *)0x0) {
      iVar19 = 0x46dc;
      iVar5 = 0xf5;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar26[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (pPVar9,__pyx_mstate_global_static.__pyx_n_s_write_to_socket,pPVar26,
                          __pyx_mstate_global_static.__pyx_n_s_write_to_socket[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_write_to_socket,pPVar26)
      ;
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      iVar19 = 0x46e0;
      iVar5 = 0xf5;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar26->ob_refcnt + -1;
    pPVar26->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
    }
    pPVar26 = (PyObject *)PyDict_New();
    if (pPVar26 == (PyObject *)0x0) {
      iVar19 = 0x46ea;
      iVar5 = 0x103;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_code,
                           __pyx_mstate_global_static.__pyx_kp_s_Optional_int);
    if (iVar5 < 0) {
      iVar19 = 0x46ec;
      iVar5 = 0x103;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_reason,
                           __pyx_mstate_global_static.__pyx_kp_s_Optional_str);
    if (iVar5 < 0) {
      iVar19 = 0x46ed;
      iVar5 = 0x103;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      iVar19 = 0x46ee;
      iVar5 = 0x103;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    p_Var10 = (_typeobject *)
              __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16UnixSocketClient_9_on_close
                         ,8,__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient__on_close,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__19,pPVar23);
    pPVar20 = __pyx_mstate_global_static.__pyx_tuple__45;
    if (p_Var10 == (_typeobject *)0x0) {
      iVar19 = 0x46ef;
      iVar5 = 0x103;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = (__pyx_mstate_global_static.__pyx_tuple__45)->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0x90))->ob_type =
         (_typeobject *)__pyx_mstate_global_static.__pyx_tuple__45;
    pPVar20->ob_refcnt = lVar7 + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = pPVar26->ob_refcnt;
    ((PyObject *)((long)p_Var10 + 0xb0))->ob_refcnt = (Py_ssize_t)pPVar26;
    if (lVar7 == 0) {
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
    }
    if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (pPVar9,__pyx_mstate_global_static.__pyx_n_s_on_close,p_Var10,
                          __pyx_mstate_global_static.__pyx_n_s_on_close[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_on_close,p_Var10);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      iVar19 = 0x46f4;
      iVar5 = 0x103;
      goto LAB_0010b214;
    }
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    ((PyObject *)p_Var10)->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    p_Var10 = (_typeobject *)PyDict_New();
    if (p_Var10 == (_typeobject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x46fe;
      iVar5 = 0x124;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_code,
                           __pyx_mstate_global_static.__pyx_n_s_int);
    if (iVar5 < 0) {
      iVar19 = 0x4700;
      iVar5 = 0x124;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_reason,
                           __pyx_mstate_global_static.__pyx_n_s_str);
    if (iVar5 < 0) {
      iVar19 = 0x4701;
      iVar5 = 0x124;
      goto LAB_0010b214;
    }
    iVar5 = PyDict_SetItem(p_Var10,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_None);
    if (iVar5 < 0) {
      iVar19 = 0x4702;
      iVar5 = 0x124;
      goto LAB_0010b214;
    }
    pPVar20 = __pyx_mstate_global_static.__pyx_d;
    pPVar22 = __pyx_mstate_global_static.__pyx_codeobj__47;
    pPVar26 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_10extensions_16UnixSocketClient_12close_socket
                         ,0,__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient_close_socket,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__47,pPVar23);
    iVar5 = (int)pPVar22;
    if (pPVar26 == (PyObject *)0x0) {
      iVar19 = 0x4703;
      iVar5 = 0x124;
      goto LAB_0010b214;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = ((PyObject *)p_Var10)->ob_refcnt;
    pPVar26[0xb].ob_refcnt = (Py_ssize_t)p_Var10;
    if (lVar7 == 0) {
      (*((PyObject *)p_Var10)->ob_type->tp_dealloc)((PyObject *)p_Var10);
    }
    if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      uVar17 = _PyDict_SetItem_KnownHash
                         (pPVar9,__pyx_mstate_global_static.__pyx_n_s_close_socket,pPVar26,
                          __pyx_mstate_global_static.__pyx_n_s_close_socket[1].ob_type);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    else {
      uVar17 = PyObject_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_close_socket,pPVar26);
      uVar6 = (uint)(uVar17 >> 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      iVar19 = 0x4707;
      iVar5 = 0x124;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar26->ob_refcnt + -1;
    pPVar26->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
    }
    pPVar26 = __Pyx_Py3ClassCreate
                        (pPVar11,__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient,
                         (PyObject *)p_Var18,pPVar9,pPVar20,iVar5,(int)pPVar23);
    if (pPVar26 == (PyObject *)0x0) {
      iVar19 = 0x4711;
      iVar5 = 0xc9;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_UnixSocketClient,pPVar26);
    if (iVar5 < 0) {
      iVar19 = 0x4713;
      iVar5 = 0xc9;
      pPVar27 = pPVar9;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar26->ob_refcnt + -1;
    pPVar26->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
    (p_Var18->ob_base).ob_base.ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    p_Var18 = (_typeobject *)PyDict_New();
    if (p_Var18 == (_typeobject *)0x0) {
      iVar19 = 0x471f;
      iVar5 = 0x129;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    iVar5 = PyDict_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_config,
                           __pyx_mstate_global_static.__pyx_n_s_ConfigHelper);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4721;
      iVar5 = 0x129;
      goto LAB_0010b240;
    }
    iVar5 = PyDict_SetItem(p_Var18,__pyx_mstate_global_static.__pyx_n_s_return,
                           __pyx_mstate_global_static.__pyx_n_s_ExtensionManager);
    if (iVar5 < 0) {
      pPVar26 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar19 = 0x4722;
      iVar5 = 0x129;
      goto LAB_0010b240;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_9moonraker_10components_10extensions_1load_component,0,
                         __pyx_mstate_global_static.__pyx_n_s_load_component,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__49,pPVar23);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar26 = (PyObject *)0x0;
      iVar19 = 0x4723;
      iVar5 = 0x129;
      pPVar27 = (PyObject *)0x0;
      goto LAB_0010b240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar7 = (p_Var18->ob_base).ob_base.ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)p_Var18;
    if (lVar7 == 0) {
      (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_load_component,pPVar11);
    if (iVar5 < 0) {
      iVar19 = 0x4727;
      iVar5 = 0x129;
LAB_0010b86c:
      pPVar26 = (PyObject *)0x0;
      pPVar27 = (PyObject *)0x0;
      goto LAB_0010b874;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      iVar5 = 1;
      iVar19 = 0x472f;
      bVar2 = true;
      goto LAB_0010b26c;
    }
    iVar5 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_test,pPVar11);
    if (iVar5 < 0) {
      iVar19 = 0x4731;
      iVar5 = 1;
      goto LAB_0010b86c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
  }
  iVar5 = -(uint)(__pyx_m == (PyObject *)0x0);
LAB_0010c068:
  if (lVar15 == *(long *)PTR___stack_chk_guard_00143f20) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010c0a4
 * Symbol:  PyInit_extensions
 * Signature: PyObject * PyInit_extensions(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PyObject * PyInit_extensions(void)

{
  PyObject *pPVar1;
  
  pPVar1 = (PyObject *)PyModuleDef_Init(&__pyx_moduledef);
  return pPVar1;
}


/* ================================================================
 * Address: 0010c0b4
 * Symbol:  call_weak_fn
 * Signature: undefined call_weak_fn(void)
 * ================================================================ */

void call_weak_fn(void)

{
  if (PTR___gmon_start___00143f18 != (undefined *)0x0) {
    __gmon_start__();
    return;
  }
  return;
}


/* ================================================================
 * Address: 0010c0c8
 * Symbol:  deregister_tm_clones
 * Signature: undefined deregister_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x0010c0e0) */
/* WARNING: Removing unreachable block (ram,0x0010c0ec) */

void deregister_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 0010c0f8
 * Symbol:  register_tm_clones
 * Signature: undefined register_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x0010c11c) */
/* WARNING: Removing unreachable block (ram,0x0010c128) */

void register_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 0010c1d4
 * Symbol:  lexical_block_1_0
 * Signature: void lexical_block_1_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x10c1d4 0010c1d4} (16 bytes)
   DWARF func body range[1]: {@address 0x10c21c 0010c21c} (20 bytes) */

void __Pyx_ErrRestoreInState::lexical_block_1::lexical_block_1_0(void)

{
  long lVar1;
  long *unaff_x19;
  long *unaff_x20;
  
                    /* Unresolved local var: PyObject * _py_decref_tmp@[DW_OP_reg20(x20)] */
  lVar1 = *unaff_x20;
  *unaff_x20 = lVar1 + -1;
  if (lVar1 + -1 == 0) {
    (**(code **)(unaff_x20[1] + 0x30))();
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if ((unaff_x19 != (long *)0x0) && (lVar1 = *unaff_x19, *unaff_x19 = lVar1 + -1, lVar1 + -1 == 0))
  {
                    /* WARNING: Could not recover jumptable at 0x0010c218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(unaff_x19[1] + 0x30))();
    return;
  }
  return;
}


/* ================================================================
 * Address: 0010c1e8
 * Symbol:  lexical_block_2_0
 * Signature: void lexical_block_2_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x10c1e8 0010c1e8} (16 bytes)
   DWARF func body range[1]: {@address 0x10c204 0010c204} (8 bytes)
   DWARF func body range[2]: {@address 0x10c214 0010c214} (8 bytes) */

void __Pyx_ErrRestoreInState::lexical_block_2::lexical_block_2_0(void)

{
  long lVar1;
  long *unaff_x19;
  
                    /* Unresolved local var: PyObject * _py_decref_tmp@[DW_OP_reg19(x19)] */
  lVar1 = *unaff_x19;
  *unaff_x19 = lVar1 + -1;
  if (lVar1 + -1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0010c218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x19[1] + 0x30))();
  return;
}


/* ================================================================
 * Address: 0010c27c
 * Symbol:  lexical_block_1_0
 * Signature: void lexical_block_1_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x10c27c 0010c27c} (16 bytes)
   DWARF func body range[1]: {@address 0x10c2c4 0010c2c4} (20 bytes) */

void __Pyx_Coroutine_ExceptionClear::lexical_block_1::lexical_block_1_0(void)

{
  long lVar1;
  long *unaff_x19;
  long *unaff_x20;
  
                    /* Unresolved local var: PyObject * _py_decref_tmp@[DW_OP_reg20(x20)] */
  lVar1 = *unaff_x20;
  *unaff_x20 = lVar1 + -1;
  if (lVar1 + -1 == 0) {
    (**(code **)(unaff_x20[1] + 0x30))();
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if ((unaff_x19 != (long *)0x0) && (lVar1 = *unaff_x19, *unaff_x19 = lVar1 + -1, lVar1 + -1 == 0))
  {
                    /* WARNING: Could not recover jumptable at 0x0010c2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(unaff_x19[1] + 0x30))();
    return;
  }
  return;
}


/* ================================================================
 * Address: 0010c290
 * Symbol:  lexical_block_2_0
 * Signature: void lexical_block_2_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x10c290 0010c290} (16 bytes)
   DWARF func body range[1]: {@address 0x10c2ac 0010c2ac} (8 bytes)
   DWARF func body range[2]: {@address 0x10c2bc 0010c2bc} (8 bytes) */

void __Pyx_Coroutine_ExceptionClear::lexical_block_2::lexical_block_2_0(void)

{
  long lVar1;
  long *unaff_x19;
  
                    /* Unresolved local var: PyObject * _py_decref_tmp@[DW_OP_reg19(x19)] */
  lVar1 = *unaff_x19;
  *unaff_x19 = lVar1 + -1;
  if (lVar1 + -1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0010c2c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x19[1] + 0x30))();
  return;
}


/* ================================================================
 * Address: 00110270
 * Symbol:  lexical_block_0
 * Signature: void lexical_block_0(__Pyx_PyUnicode_Equals * this)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x110270 00110270} (200 bytes)
   DWARF func body range[1]: {@address 0x1103e8 001103e8} (20 bytes)
   DWARF func body range[2]: {@address 0x110408 00110408} (68 bytes) */

void __thiscall __Pyx_PyUnicode_Equals::lexical_block_0(__Pyx_PyUnicode_Equals *this)

{
  int iVar1;
  uint *__s1;
  uint *__s2;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  long unaff_x19;
  long unaff_x20;
  
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
  if (((((char)this[0x20] < '\0') || (iVar1 = _PyUnicode_Ready(), -1 < iVar1)) &&
      ((*(char *)(unaff_x20 + 0x20) < '\0' || (iVar1 = _PyUnicode_Ready(), -1 < iVar1)))) &&
     ((lVar2 = *(long *)(unaff_x19 + 0x10), *(long *)(unaff_x20 + 0x10) == lVar2 &&
      ((*(long *)(unaff_x19 + 0x18) == *(long *)(unaff_x20 + 0x18) ||
       *(long *)(unaff_x19 + 0x18) == -1) || *(long *)(unaff_x20 + 0x18) == -1)))) {
    uVar3 = (ulong)(*(byte *)(unaff_x19 + 0x20) >> 2) & 7;
    uVar4 = (uint)uVar3;
    if ((*(byte *)(unaff_x20 + 0x20) >> 2 & 7) == uVar4) {
      if ((*(byte *)(unaff_x19 + 0x20) >> 5 & 1) == 0) {
        __s1 = *(uint **)(unaff_x19 + 0x48);
      }
      else {
        __s1 = (uint *)(unaff_x19 + 0x48);
        if ((*(byte *)(unaff_x19 + 0x20) & 0x40) != 0) {
          __s1 = (uint *)(unaff_x19 + 0x30);
        }
      }
      if ((*(byte *)(unaff_x20 + 0x20) >> 5 & 1) == 0) {
        __s2 = *(uint **)(unaff_x20 + 0x48);
      }
      else {
        __s2 = (uint *)(unaff_x20 + 0x48);
        if ((*(byte *)(unaff_x20 + 0x20) & 0x40) != 0) {
          __s2 = (uint *)(unaff_x20 + 0x30);
        }
      }
      if (uVar4 == 1) {
        uVar4 = (uint)(byte)*__s1;
        uVar5 = (uint)(byte)*__s2;
      }
      else if (uVar4 == 2) {
        uVar4 = (uint)(ushort)*__s1;
        uVar5 = (uint)(ushort)*__s2;
      }
      else {
        uVar4 = *__s1;
        uVar5 = *__s2;
      }
      if (uVar5 == uVar4) {
        if (lVar2 == 1) {
          return;
        }
        memcmp(__s1,__s2,uVar3 * lVar2);
      }
    }
  }
  return;
}


/* ================================================================
 * Address: 00110310
 * Symbol:  lexical_block_0_1
 * Signature: void lexical_block_0_1(void)
 * ================================================================ */

void __Pyx_PyUnicode_Equals::lexical_block_0::lexical_block_0_1(void)

{
  void *in_x0;
  void *in_x1;
  long in_x2;
  ulong in_x3;
  
                    /* Unresolved local var: int result@[???] */
  memcmp(in_x0,in_x1,(in_x3 & 0xff) * in_x2);
  return;
}


/* ================================================================
 * Address: 00113740
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_9_on_close
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_9_on_close(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_9_on_close
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject **kwvalues;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *module_name;
  PyObject *name;
  PyObject *pPVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  PyObject *pPVar5;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var6;
  undefined8 uVar7;
  long lVar8;
  PyObject *pPVar9;
  undefined8 uVar10;
  char *pcVar11;
  long lVar12;
  char *pcVar13;
  PyObject *pPVar14;
  long lVar15;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_code@[???]
                       Unresolved local var: PyObject * __pyx_v_reason@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg25(x25)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar12 = *(long *)PTR___stack_chk_guard_00143f20;
  pcVar13 = (char *)0x0;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)PTR__Py_NoneStruct_00143f40;
  values[2] = (PyObject *)PTR__Py_NoneStruct_00143f40;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_code;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_reason;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 2) {
LAB_00113a50:
      values[1] = __pyx_args[1];
      bVar2 = values[1] == (PyObject *)PTR__Py_NoneStruct_00143f40;
    }
    else {
      if (__pyx_nargs == 3) {
        values[2] = __pyx_args[2];
        goto LAB_00113a50;
      }
      if (__pyx_nargs != 1) goto LAB_00113888;
      bVar2 = true;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pPVar9 = __pyx_kwds;
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      lVar15 = __pyx_kwds[1].ob_refcnt;
joined_r0x00113a78:
      if (0 < lVar15) {
                    /* Unresolved local var: PyObject * value@[???] */
        pPVar5 = __Pyx_GetKwValue_FASTCALL
                           (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_code);
        if (pPVar5 == (PyObject *)0x0) {
          lVar8 = PyErr_Occurred();
          if (lVar8 != 0) {
            iVar4 = 0x324c;
            goto LAB_001138cc;
          }
        }
        else {
          lVar15 = lVar15 + -1;
          values[1] = pPVar5;
LAB_001137f0:
          if (lVar15 < 1) goto LAB_001138f8;
        }
                    /* Unresolved local var: PyObject * value@[???] */
        pPVar5 = __Pyx_GetKwValue_FASTCALL
                           (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_reason);
        if (pPVar5 != (PyObject *)0x0) {
          lVar15 = lVar15 + -1;
          values[2] = pPVar5;
          goto LAB_001138f0;
        }
        lVar15 = PyErr_Occurred();
        if (lVar15 != 0) {
          iVar4 = 0x3253;
          goto LAB_001138cc;
        }
LAB_00113b1c:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
        pPVar9 = (PyObject *)values;
        iVar4 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar9,(PyObject **)__pyx_nargs,
                           0x12f240,pcVar13);
        if (iVar4 < 0) {
          iVar4 = 0x3258;
          goto LAB_001138cc;
        }
      }
    }
    else {
      if (__pyx_nargs < 2) {
        if (__pyx_nargs == 0) {
          lVar15 = __pyx_kwds[1].ob_refcnt;
LAB_00113824:
          values[0] = __Pyx_GetKwValue_FASTCALL
                                (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
          if (values[0] != (PyObject *)0x0) {
            lVar15 = lVar15 + -1;
            goto joined_r0x00113a78;
          }
          lVar15 = PyErr_Occurred();
          if (lVar15 == 0) {
            uVar7 = *(undefined8 *)PTR_PyExc_TypeError_00143ee0;
            goto LAB_00113a20;
          }
          iVar4 = 0x3245;
        }
        else {
LAB_00113888:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
          uVar7 = *(undefined8 *)PTR_PyExc_TypeError_00143ee0;
          if (__pyx_nargs < 1) {
LAB_00113a20:
            pcVar13 = "at least";
            pcVar11 = "";
            uVar10 = 1;
          }
          else {
            pcVar13 = "at most";
            pcVar11 = "s";
            uVar10 = 3;
          }
          PyErr_Format(uVar7,"%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                       "_on_close",pcVar13,uVar10,pcVar11,__pyx_nargs);
          iVar4 = 0x326b;
        }
LAB_001138cc:
        p_Var6 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient._on_close",iVar4,0x103,
                           "moonraker/components/extensions.py");
        goto LAB_001139dc;
      }
      if (__pyx_nargs != 2) {
        if (__pyx_nargs != 3) goto LAB_00113888;
        values[2] = __pyx_args[2];
      }
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar15 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs == 1) goto joined_r0x00113a78;
      if (__pyx_nargs == 2) goto LAB_001137f0;
      if (__pyx_nargs == 0) goto LAB_00113824;
LAB_001138f0:
      if (0 < lVar15) goto LAB_00113b1c;
    }
LAB_001138f8:
    bVar2 = values[1] == (PyObject *)PTR__Py_NoneStruct_00143f40;
    __pyx_kwds = pPVar9;
  }
  pPVar1 = values[2];
  pPVar5 = values[1];
  pPVar9 = values[0];
  iVar4 = (int)__pyx_kwds;
  if ((bVar2 || values[1]->ob_type == (_typeobject *)PTR_PyLong_Type_00143f70) ||
     (iVar3 = __Pyx__ArgTypeTest((PyObject *)&values[1]->ob_type,
                                 (PyTypeObject *)PTR_PyLong_Type_00143f70,"code",iVar4), iVar3 != 0)
     ) {
    if ((pPVar1->ob_type != (_typeobject *)PTR_PyUnicode_Type_00143fb0 &&
         pPVar1 != (PyObject *)PTR__Py_NoneStruct_00143f40) &&
       (iVar4 = __Pyx__ArgTypeTest((PyObject *)&pPVar1->ob_type,
                                   (PyTypeObject *)PTR_PyUnicode_Type_00143fb0,"reason",iVar4),
       iVar4 == 0)) {
      p_Var6 = (__pyx_CoroutineObject *)0x0;
      goto LAB_001139dc;
    }
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_11__on_close
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_11__on_close
                        (__pyx_mstate_global_static.
                         __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_11__on_close
                         ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
    name = __pyx_mstate_global_static.__pyx_n_s_on_close;
    module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
    qualname = __pyx_mstate_global_static.__pyx_n_s_UnixSocketClient__on_close;
    type = __pyx_mstate_global_static.__pyx_CoroutineType;
    pPVar14 = (PyObject *)PTR__Py_NoneStruct_00143f40;
    if (closure == (PyObject *)0x0) {
      iVar4 = 0x32a0;
      *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
    }
    else {
      lVar15 = pPVar9->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
      closure[3].ob_type = (_typeobject *)pPVar9;
      pPVar9->ob_refcnt = lVar15 + 1;
      lVar15 = pPVar5->ob_refcnt;
      closure[1].ob_refcnt = (Py_ssize_t)pPVar5;
      pPVar5->ob_refcnt = lVar15 + 1;
      pPVar9 = __pyx_mstate_global_static.__pyx_codeobj__19;
      lVar15 = pPVar1->ob_refcnt;
      closure[2].ob_type = (_typeobject *)pPVar1;
      pPVar1->ob_refcnt = lVar15 + 1;
      p_Var6 = __Pyx__Coroutine_New
                         (type,
                          __pyx_gb_9moonraker_10components_10extensions_16UnixSocketClient_10generator11
                          ,pPVar9,closure,name,qualname,module_name);
      if (p_Var6 != (__pyx_CoroutineObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = closure->ob_refcnt + -1;
        closure->ob_refcnt = lVar15;
        if (lVar15 == 0) {
          (*closure->ob_type->tp_dealloc)(closure);
        }
        goto LAB_001139dc;
      }
      iVar4 = 0x32ae;
      pPVar14 = closure;
    }
    __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient._on_close",iVar4,0x103,
                       "moonraker/components/extensions.py");
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar15 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar15;
    if (lVar15 == 0) {
      p_Var6 = (__pyx_CoroutineObject *)0x0;
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      goto LAB_001139dc;
    }
  }
  p_Var6 = (__pyx_CoroutineObject *)0x0;
LAB_001139dc:
  if (lVar12 != *(long *)PTR___stack_chk_guard_00143f20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return &p_Var6->ob_base;
}


/* ================================================================
 * Address: 00113b78
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_35close
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_35close(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_35close
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *code;
  PyObject *apPVar1 [1];
  int iVar2;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var3;
  long lVar4;
  long lVar5;
  char *in_x6;
  PyObject *pPVar6;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar5 = *(long *)PTR___stack_chk_guard_00143f20;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_00113c6c:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","close","exactly",1
                   ,"",__pyx_nargs);
      iVar2 = 0x291c;
      goto LAB_00113ca8;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar4 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,__pyx_args + __pyx_nargs,
                             __pyx_mstate_global_static.__pyx_n_s_self);
      lVar4 = lVar4 + -1;
      if (values[0] == (PyObject *)0x0) {
        lVar4 = PyErr_Occurred();
        if (lVar4 == 0) goto LAB_00113c6c;
        iVar2 = 0x290c;
        goto LAB_00113ca8;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_00113c6c;
      values[0] = *__pyx_args;
      lVar4 = __pyx_kwds[1].ob_refcnt;
    }
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((0 < lVar4) &&
       (iVar2 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x12f308,in_x6), iVar2 < 0)) {
      iVar2 = 0x2911;
LAB_00113ca8:
      p_Var3 = (__pyx_CoroutineObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.close",iVar2,0xc3,
                         "moonraker/components/extensions.py");
      goto LAB_00113cc4;
    }
  }
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_8_close *
                       __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  apPVar1[0] = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_8_close
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_8_close,
                       __pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  code = __pyx_mstate_global_static.__pyx_codeobj__14;
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_close;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager_close;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar6 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar2 = 0x2943;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_00113d5c:
    p_Var3 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.close",iVar2,0xc3,
                       "moonraker/components/extensions.py");
  }
  else {
    lVar4 = apPVar1[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_refcnt = (Py_ssize_t)apPVar1[0];
    apPVar1[0]->ob_refcnt = lVar4 + 1;
    p_Var3 = __Pyx__Coroutine_New
                       (type,
                        __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_36generator8
                        ,code,closure,name,qualname,module_name);
    pPVar6 = closure;
    if (p_Var3 == (__pyx_CoroutineObject *)0x0) {
      iVar2 = 0x294b;
      goto LAB_00113d5c;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar4 = pPVar6->ob_refcnt + -1;
  pPVar6->ob_refcnt = lVar4;
  if (lVar4 == 0) {
    (*pPVar6->ob_type->tp_dealloc)(pPVar6);
  }
LAB_00113cc4:
  if (lVar5 != *(long *)PTR___stack_chk_guard_00143f20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return &p_Var3->ob_base;
}


/* ================================================================
 * Address: 00113dc0
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_30start_unix_server
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_30start_unix_server(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_30start_unix_server
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *module_name;
  PyObject *name;
  PyObject *code;
  PyObject *apPVar1 [1];
  int iVar2;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var3;
  long lVar4;
  long lVar5;
  char *in_x6;
  PyObject *pPVar6;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar5 = *(long *)PTR___stack_chk_guard_00143f20;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_00113eb4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","start_unix_server"
                   ,"exactly",1,"",__pyx_nargs);
      iVar2 = 0x254e;
      goto LAB_00113ef0;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar4 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,__pyx_args + __pyx_nargs,
                             __pyx_mstate_global_static.__pyx_n_s_self);
      lVar4 = lVar4 + -1;
      if (values[0] == (PyObject *)0x0) {
        lVar4 = PyErr_Occurred();
        if (lVar4 == 0) goto LAB_00113eb4;
        iVar2 = 0x253e;
        goto LAB_00113ef0;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_00113eb4;
      values[0] = *__pyx_args;
      lVar4 = __pyx_kwds[1].ob_refcnt;
    }
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((0 < lVar4) &&
       (iVar2 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x12f350,in_x6), iVar2 < 0)) {
      iVar2 = 0x2543;
LAB_00113ef0:
      p_Var3 = (__pyx_CoroutineObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.start_unix_server",iVar2,
                         0xae,"moonraker/components/extensions.py");
      goto LAB_00113f0c;
    }
  }
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_7_start_unix_server
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  apPVar1[0] = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_7_start_unix_server
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_7_start_unix_server
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  code = __pyx_mstate_global_static.__pyx_codeobj__12;
  name = __pyx_mstate_global_static.__pyx_n_s_start_unix_server;
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager_start_unix_serv;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar6 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar2 = 0x2575;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_00113fa4:
    p_Var3 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.start_unix_server",iVar2,
                       0xae,"moonraker/components/extensions.py");
  }
  else {
    lVar4 = apPVar1[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_refcnt = (Py_ssize_t)apPVar1[0];
    apPVar1[0]->ob_refcnt = lVar4 + 1;
    p_Var3 = __Pyx__Coroutine_New
                       (type,
                        __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_31generator7
                        ,code,closure,name,qualname,module_name);
    pPVar6 = closure;
    if (p_Var3 == (__pyx_CoroutineObject *)0x0) {
      iVar2 = 0x257d;
      goto LAB_00113fa4;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar4 = pPVar6->ob_refcnt + -1;
  pPVar6->ob_refcnt = lVar4;
  if (lVar4 == 0) {
    (*pPVar6->ob_type->tp_dealloc)(pPVar6);
  }
LAB_00113f0c:
  if (lVar5 != *(long *)PTR___stack_chk_guard_00143f20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return &p_Var3->ob_base;
}


/* ================================================================
 * Address: 00114458
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_1load_component
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_1load_component(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_1load_component
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject *apPVar1 [1];
  int iVar2;
  PyObject *pPVar3;
  PyObject *func;
  long lVar4;
  _typeobject *p_Var5;
  __pyx_mstate *kwargs;
  long lVar6;
  char *in_x6;
  PyObject *func_00;
  _typeobject *p_Var7;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
                    /* Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_config;
  lVar6 = *(long *)PTR___stack_chk_guard_00143f20;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_00114550:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","load_component",
                   "exactly",1,"",__pyx_nargs);
      iVar2 = 0x36e7;
      goto LAB_0011458c;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar4 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,__pyx_args + __pyx_nargs,
                             __pyx_mstate_global_static.__pyx_n_s_config);
      lVar4 = lVar4 + -1;
      if (values[0] == (PyObject *)0x0) {
        lVar4 = PyErr_Occurred();
        if (lVar4 == 0) goto LAB_00114550;
        iVar2 = 0x36d7;
        goto LAB_0011458c;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_00114550;
      values[0] = *__pyx_args;
      lVar4 = __pyx_kwds[1].ob_refcnt;
    }
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((0 < lVar4) &&
       (iVar2 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x12f3d0,in_x6), iVar2 < 0)) {
      iVar2 = 0x36dc;
LAB_0011458c:
      pPVar3 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.load_component",iVar2,0x129,
                         "moonraker/components/extensions.py");
      goto LAB_001145a8;
    }
  }
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  apPVar1[0] = values[0];
  func = __pyx_dict_cached_value_19623;
  kwargs = &__pyx_mstate_global_static;
  if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_19622) {
    if (__pyx_dict_cached_value_19623 == (PyObject *)0x0) {
      func = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_ExtensionManager);
      goto LAB_00114664;
    }
    __pyx_dict_cached_value_19623->ob_refcnt = __pyx_dict_cached_value_19623->ob_refcnt + 1;
LAB_001144f8:
    p_Var5 = func->ob_type;
    if ((p_Var5 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
       (p_Var7 = func[1].ob_type, p_Var7 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      func_00 = (PyObject *)func[1].ob_refcnt;
      (p_Var7->ob_base).ob_base.ob_refcnt = (p_Var7->ob_base).ob_base.ob_refcnt + 1;
      func_00->ob_refcnt = func_00->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar4 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar4;
      if (lVar4 == 0) {
        (*p_Var5->tp_dealloc)(func);
      }
      __pyx_pyargnames[0] = (PyObject **)p_Var7;
      __pyx_pyargnames[1] = (PyObject **)apPVar1[0];
      pPVar3 = __Pyx_PyObject_FastCallDict
                         (func_00,(PyObject **)__pyx_pyargnames,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar4 = (p_Var7->ob_base).ob_base.ob_refcnt + -1;
      (p_Var7->ob_base).ob_base.ob_refcnt = lVar4;
      if (lVar4 == 0) {
        (*((p_Var7->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var7);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)apPVar1[0];
      pPVar3 = __Pyx_PyObject_FastCallDict
                         (func,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)kwargs);
      func_00 = func;
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    lVar4 = func_00->ob_refcnt + -1;
    if (pPVar3 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      func_00->ob_refcnt = lVar4;
      if (lVar4 == 0) {
        (*func_00->ob_type->tp_dealloc)(func_00);
      }
      goto LAB_001145a8;
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func_00->ob_refcnt = lVar4;
    iVar2 = 0x3728;
    if (lVar4 == 0) {
      (*func_00->ob_type->tp_dealloc)(func_00);
    }
  }
  else {
    func = __Pyx__GetModuleGlobalName
                     (__pyx_mstate_global_static.__pyx_n_s_ExtensionManager,
                      (uint64_t *)&__pyx_dict_version_19622,&__pyx_dict_cached_value_19623);
LAB_00114664:
    iVar2 = 0x3714;
    if (func != (PyObject *)0x0) goto LAB_001144f8;
  }
  pPVar3 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.load_component",iVar2,0x12a,
                     "moonraker/components/extensions.py");
LAB_001145a8:
  if (lVar6 != *(long *)PTR___stack_chk_guard_00143f20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar3;
}


/* ================================================================
 * Address: 00118e88
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_5remove_agent
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_5remove_agent(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_5remove_agent
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  PyObject *pPVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  PyObject *pPVar12;
  PyObject *pPVar13;
  PyObject **ppPVar14;
  PyObject *pPVar15;
  long lVar16;
  long *plVar17;
  setattrfunc *__s2;
  getattrofunc p_Var18;
  long lVar19;
  PyObject *kwargs;
  _typeobject *p_Var20;
  PyObject *func;
  char *pcVar21;
  uint uVar22;
  long lVar23;
  uint uVar24;
  PyObject *pPVar25;
  _typeobject *p_Var26;
  long lVar27;
  _typeobject *p_Var28;
  long lVar29;
  int py_line;
  long lVar30;
  PyObject *pPVar31;
  PyObject **local_70;
  iternextfunc local_68;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_connection@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar23 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_connection;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    ppPVar14 = __pyx_args + __pyx_nargs;
    pcVar21 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar27 = __pyx_kwds[1].ob_refcnt;
        goto LAB_001195cc;
      }
      if (__pyx_nargs == 0) {
        lVar27 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,ppPVar14,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar30 = __pyx_kwds[1].ob_refcnt;
          lVar27 = lVar27 + -1;
          goto LAB_00119604;
        }
        lVar27 = PyErr_Occurred();
        if (lVar27 != 0) {
          iVar8 = 0x16de;
          goto LAB_00118f34;
        }
      }
LAB_00118ef8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","remove_agent",
                   "exactly",2,"s",__pyx_nargs);
      iVar8 = 0x16fa;
      goto LAB_00118f34;
    }
    lVar30 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar27 = lVar30;
LAB_00119604:
    pPVar25 = __pyx_mstate_global_static.__pyx_n_s_connection;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar30) {
      p_Var28 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_connection == p_Var28) {
        values[1] = *ppPVar14;
      }
      else {
        lVar16 = 0;
        do {
          lVar29 = lVar16 + 1;
          if (lVar29 == lVar30) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar16 = 0;
            goto LAB_00119668;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar16;
          lVar16 = lVar29;
        } while (__pyx_mstate_global_static.__pyx_n_s_connection != (PyObject *)*pPVar1);
        values[1] = ppPVar14[lVar29];
      }
      goto LAB_00119770;
    }
LAB_00119818:
    values[1] = (PyObject *)0x0;
    goto LAB_0011981c;
  }
  if (__pyx_nargs != 2) goto LAB_00118ef8;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_00118f98:
                    /* Unresolved local var: PyObject * __pyx_v_name@[???]
                       Unresolved local var: PyObject * __pyx_v_klippy@[???]
                       Unresolved local var: PyObject * __pyx_v_registered_methods@[???]
                       Unresolved local var: PyObject * __pyx_v_method@[???]
                       Unresolved local var: PyObject * __pyx_v_evt@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: int __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: wchar_t __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_8@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_9@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar31 = values[1];
  pPVar25 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var18 = values[1]->ob_type->tp_getattro;
  if (p_Var18 == (getattrofunc)0x0) {
    pPVar9 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar9 = (*p_Var18)(values[1],__pyx_mstate_global_static.__pyx_n_s_client_data);
  }
  if (pPVar9 == (PyObject *)0x0) {
    pPVar11 = (PyObject *)0x0;
    p_Var28 = (_typeobject *)0x0;
    pPVar15 = (PyObject *)0x0;
    pPVar10 = (PyObject *)0x0;
    py_line = 0x59;
    iVar8 = 0x1732;
    pPVar13 = (PyObject *)0x0;
    goto LAB_001198d8;
  }
  if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
    pPVar10 = __Pyx_PyDict_GetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_u_name);
  }
  else {
    pPVar10 = (PyObject *)PyObject_GetItem();
  }
  lVar27 = pPVar9->ob_refcnt + -1;
  if (pPVar10 == (PyObject *)0x0) {
    pPVar12 = (PyObject *)0x0;
    pPVar11 = (PyObject *)0x0;
    p_Var28 = (_typeobject *)0x0;
    pPVar15 = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
    iVar8 = 0x1734;
    py_line = 0x59;
    goto LAB_00119928;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  pPVar9->ob_refcnt = lVar27;
  if (lVar27 == 0) {
    (*pPVar9->ob_type->tp_dealloc)(pPVar9);
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var18 = pPVar25->ob_type->tp_getattro;
  if (p_Var18 == (getattrofunc)0x0) {
    pPVar11 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar11 = (*p_Var18)(pPVar25,__pyx_mstate_global_static.__pyx_n_s_agents);
  }
  if (pPVar11 == (PyObject *)0x0) {
    pPVar11 = (PyObject *)0x0;
    p_Var28 = (_typeobject *)0x0;
    pPVar15 = (PyObject *)0x0;
    py_line = 0x5a;
    iVar8 = 0x1741;
    pPVar13 = (PyObject *)0x0;
LAB_001198d8:
    pPVar25 = (PyObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.remove_agent",iVar8,py_line
                       ,"moonraker/components/extensions.py");
    if (pPVar10 != (PyObject *)0x0) goto LAB_00119504;
  }
  else {
                    /* Unresolved local var: int result@[???] */
    iVar8 = PySequence_Contains(pPVar11,pPVar10);
    if (iVar8 < 0) {
      p_Var28 = (_typeobject *)0x0;
      pPVar15 = (PyObject *)0x0;
      pPVar13 = (PyObject *)0x0;
      py_line = 0x5a;
      iVar8 = 0x1743;
LAB_001199a4:
      pPVar9 = (PyObject *)0x0;
LAB_001199a8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      pPVar11 = (PyObject *)0x0;
      if (pPVar9 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar9->ob_refcnt + -1;
        pPVar9->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          pPVar11 = (PyObject *)0x0;
          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
        }
        else {
          pPVar11 = (PyObject *)0x0;
        }
      }
      goto LAB_001198d8;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (iVar8 == 1) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var18 = pPVar25->ob_type->tp_getattro;
      if (p_Var18 == (getattrofunc)0x0) {
        pPVar9 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar9 = (*p_Var18)(pPVar25,__pyx_mstate_global_static.__pyx_n_s_server);
      }
      if (pPVar9 == (PyObject *)0x0) {
        pPVar11 = (PyObject *)0x0;
        p_Var28 = (_typeobject *)0x0;
        pPVar15 = (PyObject *)0x0;
        py_line = 0x5b;
        iVar8 = 0x174e;
        pPVar13 = (PyObject *)0x0;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var18 = pPVar9->ob_type->tp_getattro;
        if (p_Var18 == (getattrofunc)0x0) {
          pPVar12 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar12 = (*p_Var18)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_lookup_component);
        }
        lVar27 = pPVar9->ob_refcnt + -1;
        if (pPVar12 == (PyObject *)0x0) {
          pPVar12 = (PyObject *)0x0;
          pPVar11 = (PyObject *)0x0;
          p_Var28 = (_typeobject *)0x0;
          pPVar15 = (PyObject *)0x0;
          iVar8 = 0x1750;
          py_line = 0x5b;
          pPVar13 = (PyObject *)0x0;
LAB_00119928:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar9->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (pPVar12 == (PyObject *)0x0) goto LAB_001198d8;
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar9->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          p_Var28 = pPVar12->ob_type;
          if ((p_Var28 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (p_Var26 = pPVar12[1].ob_type, p_Var26 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar9 = (PyObject *)pPVar12[1].ob_refcnt;
            (p_Var26->ob_base).ob_base.ob_refcnt = (p_Var26->ob_base).ob_base.ob_refcnt + 1;
            pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*p_Var28->tp_dealloc)(pPVar12);
            }
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_n_u_klippy_connection;
            kwargs = __pyx_mstate_global_static.__pyx_n_u_klippy_connection;
            __pyx_pyargnames[0] = (PyObject **)p_Var26;
            pPVar13 = __Pyx_PyObject_FastCallDict
                                (pPVar9,(PyObject **)__pyx_pyargnames,2,
                                 __pyx_mstate_global_static.__pyx_n_u_klippy_connection);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = (p_Var26->ob_base).ob_base.ob_refcnt + -1;
            (p_Var26->ob_base).ob_base.ob_refcnt = lVar27;
            pPVar12 = pPVar9;
            if (lVar27 == 0) {
              (*((p_Var26->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var26);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_n_u_klippy_connection;
            kwargs = __pyx_mstate_global_static.__pyx_n_u_klippy_connection;
            pPVar13 = __Pyx_PyObject_FastCallDict
                                (pPVar12,(PyObject **)(__pyx_pyargnames + 1),1,
                                 __pyx_mstate_global_static.__pyx_n_u_klippy_connection);
          }
          local_70 = (PyObject **)__pyx_pyargnames;
          if (pPVar13 == (PyObject *)0x0) {
            py_line = 0x5b;
            iVar8 = 0x1765;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var18 = pPVar25->ob_type->tp_getattro;
            if (p_Var18 == (getattrofunc)0x0) {
              pPVar12 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar12 = (*p_Var18)(pPVar25,__pyx_mstate_global_static.__pyx_n_s_agent_methods);
            }
            if (pPVar12 == (PyObject *)0x0) {
              pPVar11 = (PyObject *)0x0;
              p_Var28 = (_typeobject *)0x0;
              py_line = 0x5c;
              iVar8 = 0x1773;
              pPVar15 = (PyObject *)0x0;
              goto LAB_001198d8;
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var18 = pPVar12->ob_type->tp_getattro;
            if (p_Var18 == (getattrofunc)0x0) {
              pPVar9 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar9 = (*p_Var18)(pPVar12,__pyx_mstate_global_static.__pyx_n_s_pop);
            }
            if (pPVar9 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar27 = pPVar12->ob_refcnt + -1;
              pPVar12->ob_refcnt = lVar27;
              if (lVar27 == 0) {
                (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var18 = pPVar31->ob_type->tp_getattro;
              if (p_Var18 == (getattrofunc)0x0) {
                pPVar12 = (PyObject *)PyObject_GetAttr();
              }
              else {
                pPVar12 = (*p_Var18)(pPVar31,__pyx_mstate_global_static.__pyx_n_s_uid);
              }
              if (pPVar12 == (PyObject *)0x0) {
                pPVar11 = (PyObject *)0x0;
                p_Var28 = (_typeobject *)0x0;
                pPVar15 = (PyObject *)0x0;
                iVar8 = 0x1778;
                py_line = 0x5c;
                lVar27 = pPVar9->ob_refcnt + -1;
              }
              else {
                ppPVar14 = (PyObject **)PyList_New(0);
                if (ppPVar14 == (PyObject **)0x0) {
                  pPVar11 = (PyObject *)0x0;
                  pPVar15 = (PyObject *)0x0;
                  iVar8 = 0x177a;
                  py_line = 0x5c;
                  lVar27 = pPVar9->ob_refcnt + -1;
                  p_Var28 = (_typeobject *)0x0;
                }
                else {
                  p_Var28 = pPVar9->ob_type;
                  if ((p_Var28 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var26 = pPVar9[1].ob_type, p_Var26 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar11 = (PyObject *)pPVar9[1].ob_refcnt;
                    (p_Var26->ob_base).ob_base.ob_refcnt = (p_Var26->ob_base).ob_base.ob_refcnt + 1;
                    pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = pPVar9->ob_refcnt + -1;
                    pPVar9->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*p_Var28->tp_dealloc)(pPVar9);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var26;
                    __pyx_pyargnames[1] = (PyObject **)pPVar12;
                    __pyx_pyargnames[2] = ppPVar14;
                    pPVar15 = __Pyx_PyObject_FastCallDict(pPVar11,local_70,3,kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = (p_Var26->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var26->ob_base).ob_base.ob_refcnt = lVar27;
                    pPVar9 = pPVar11;
                    if (lVar27 == 0) {
                      (*((p_Var26->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var26);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)pPVar12;
                    __pyx_pyargnames[2] = ppPVar14;
                    pPVar15 = __Pyx_PyObject_FastCallDict
                                        (pPVar9,(PyObject **)(__pyx_pyargnames + 1),2,kwargs);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = pPVar12->ob_refcnt + -1;
                  pPVar12->ob_refcnt = lVar27;
                  if (lVar27 == 0) {
                    (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar11 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                  *ppPVar14 = pPVar11;
                  if (pPVar11 == (PyObject *)0x0) {
                    (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
                  }
                  lVar27 = pPVar9->ob_refcnt + -1;
                  if (pPVar15 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar9->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                    }
                    if (pPVar15->ob_type == (_typeobject *)PTR_PyTuple_Type_00143eb8 ||
                        pPVar15->ob_type == (_typeobject *)PTR_PyList_Type_00143fe0) {
                      lVar27 = 0;
                      local_68 = (iternextfunc)0x0;
                      pPVar15->ob_refcnt = pPVar15->ob_refcnt + 1;
                      pPVar11 = pPVar15;
                    }
                    else {
                      pPVar11 = (PyObject *)PyObject_GetIter(pPVar15);
                      if (pPVar11 == (PyObject *)0x0) {
                        pPVar11 = (PyObject *)0x0;
                        p_Var28 = (_typeobject *)0x0;
                        py_line = 0x5d;
                        iVar8 = 0x17a3;
                        goto LAB_001198d8;
                      }
                      local_68 = pPVar11->ob_type->tp_iternext;
                      if (local_68 == (iternextfunc)0x0) {
                        p_Var28 = (_typeobject *)0x0;
                        py_line = 0x5d;
                        iVar8 = 0x17a5;
                        goto LAB_001199a4;
                      }
                      lVar27 = -1;
                    }
                    puVar4 = PTR_PyList_Type_00143fe0;
                    puVar3 = PTR_PyMethod_Type_00143ea0;
                    p_Var28 = (_typeobject *)0x0;
LAB_00119370:
                    if (local_68 == (iternextfunc)0x0) {
                      if (pPVar11->ob_type == (_typeobject *)puVar4) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
                        if (pPVar11[1].ob_refcnt <= lVar27) goto LAB_00119acc;
                        p_Var26 = (_typeobject *)
                                  (&((pPVar11[1].ob_type)->ob_base).ob_base.ob_refcnt)[lVar27];
                        (p_Var26->ob_base).ob_base.ob_refcnt =
                             (p_Var26->ob_base).ob_base.ob_refcnt + 1;
                        lVar27 = lVar27 + 1;
                      }
                      else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
                        if (pPVar11[1].ob_refcnt <= lVar27) goto LAB_00119acc;
                        p_Var26 = (&pPVar11[1].ob_type)[lVar27];
                        (p_Var26->ob_base).ob_base.ob_refcnt =
                             (p_Var26->ob_base).ob_base.ob_refcnt + 1;
                        lVar27 = lVar27 + 1;
                      }
                    }
                    else {
                      p_Var26 = (_typeobject *)(*local_68)(pPVar11);
                      if (p_Var26 == (_typeobject *)0x0) {
                    /* Unresolved local var: PyObject * exc_type@[???] */
                        pPVar9 = (PyObject *)PyErr_Occurred();
                        if (pPVar9 != (PyObject *)0x0) {
                          if ((pPVar9 == *(PyObject **)PTR_PyExc_StopIteration_00143fa0) ||
                             (iVar8 = __Pyx_PyErr_GivenExceptionMatches
                                                (pPVar9,*(PyObject **)
                                                         PTR_PyExc_StopIteration_00143fa0),
                             iVar8 != 0)) {
                            PyErr_Clear();
                            goto LAB_00119acc;
                          }
                          pPVar9 = (PyObject *)0x0;
                          py_line = 0x5d;
                          iVar8 = 0x17cc;
                          goto LAB_001199a8;
                        }
LAB_00119acc:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar27 = pPVar11->ob_refcnt + -1;
                        pPVar11->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                        }
                        pPVar11 = __Pyx_PyObject_GetAttrStr
                                            (pPVar25,__pyx_mstate_global_static.__pyx_n_s_agents);
                        if (pPVar11 == (PyObject *)0x0) {
                          py_line = 0x5f;
                          iVar8 = 0x1807;
                          pPVar11 = (PyObject *)0x0;
                          goto LAB_001198d8;
                        }
                        iVar8 = PyObject_DelItem(pPVar11,pPVar10);
                        if (iVar8 < 0) {
                          py_line = 0x5f;
                          iVar8 = 0x1809;
                          goto LAB_001199a4;
                        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar27 = pPVar11->ob_refcnt + -1;
                        pPVar11->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                        }
                        pPVar11 = (PyObject *)PyDict_New();
                        if (pPVar11 == (PyObject *)0x0) {
                          pPVar11 = (PyObject *)0x0;
                          py_line = 0x60;
                          iVar8 = 0x1813;
                          goto LAB_001198d8;
                        }
                        iVar8 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_u_agent,
                                               pPVar10);
                        if (iVar8 < 0) {
                          py_line = 0x60;
                          iVar8 = 0x1815;
                          goto LAB_001199a4;
                        }
                        iVar8 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_u_event,
                                               __pyx_mstate_global_static.__pyx_n_u_disconnected);
                        if (iVar8 < 0) {
                          py_line = 0x60;
                          iVar8 = 0x1816;
                          goto LAB_001199a4;
                        }
                        pPVar9 = __Pyx_PyObject_GetAttrStr
                                           (pPVar31,__pyx_mstate_global_static.
                                                    __pyx_n_s_send_notification);
                        if (pPVar9 == (PyObject *)0x0) {
                          py_line = 0x61;
                          iVar8 = 0x1821;
                          goto LAB_001198d8;
                        }
                        ppPVar14 = (PyObject **)PyList_New(1);
                        puVar3 = PTR_PyMethod_Type_00143ea0;
                        if (ppPVar14 == (PyObject **)0x0) {
                          pPVar12 = (PyObject *)0x0;
                          iVar8 = 0x1823;
                          lVar27 = pPVar9->ob_refcnt + -1;
                          py_line = 0x61;
                          goto LAB_00119928;
                        }
                        pPVar25 = ppPVar14[3];
                        p_Var26 = pPVar9->ob_type;
                        pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                        pPVar25->ob_refcnt = (Py_ssize_t)pPVar11;
                        if ((p_Var26 == (_typeobject *)puVar3) &&
                           (p_Var20 = pPVar9[1].ob_type, p_Var20 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                          pPVar31 = (PyObject *)pPVar9[1].ob_refcnt;
                          (p_Var20->ob_base).ob_base.ob_refcnt =
                               (p_Var20->ob_base).ob_base.ob_refcnt + 1;
                          pPVar31->ob_refcnt = pPVar31->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar27 = pPVar9->ob_refcnt + -1;
                          pPVar9->ob_refcnt = lVar27;
                          if (lVar27 == 0) {
                            (*p_Var26->tp_dealloc)(pPVar9);
                          }
                          __pyx_pyargnames[1] =
                               (PyObject **)__pyx_mstate_global_static.__pyx_n_u_agent_event;
                          __pyx_pyargnames[0] = (PyObject **)p_Var20;
                          __pyx_pyargnames[2] = ppPVar14;
                          pPVar25 = __Pyx_PyObject_FastCallDict(pPVar31,local_70,3,kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar27 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
                          (p_Var20->ob_base).ob_base.ob_refcnt = lVar27;
                          pPVar9 = pPVar31;
                          if (lVar27 == 0) {
                            (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20)
                            ;
                          }
                        }
                        else {
                          __pyx_pyargnames[0] = (PyObject **)0x0;
                          __pyx_pyargnames[1] =
                               (PyObject **)__pyx_mstate_global_static.__pyx_n_u_agent_event;
                          __pyx_pyargnames[2] = ppPVar14;
                          pPVar25 = __Pyx_PyObject_FastCallDict
                                              (pPVar9,(PyObject **)(__pyx_pyargnames + 1),2,kwargs);
                        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        pPVar31 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                        *ppPVar14 = pPVar31;
                        if (pPVar31 == (PyObject *)0x0) {
                          (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
                        }
                        lVar27 = pPVar9->ob_refcnt + -1;
                        if (pPVar25 == (PyObject *)0x0) {
                          iVar8 = 0x183b;
                          py_line = 0x61;
                          pPVar12 = (PyObject *)0x0;
                          goto LAB_00119928;
                        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        pPVar9->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                        }
                        lVar27 = pPVar25->ob_refcnt + -1;
                        pPVar25->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*pPVar25->ob_type->tp_dealloc)(pPVar25);
                        }
                        goto LAB_001194ec;
                      }
                    }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    if ((p_Var28 != (_typeobject *)0x0) &&
                       (lVar30 = (p_Var28->ob_base).ob_base.ob_refcnt + -1,
                       (p_Var28->ob_base).ob_base.ob_refcnt = lVar30, lVar30 == 0)) {
                      (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
                    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                    p_Var18 = pPVar13->ob_type->tp_getattro;
                    if (p_Var18 == (getattrofunc)0x0) {
                      pPVar9 = (PyObject *)PyObject_GetAttr();
                    }
                    else {
                      pPVar9 = (*p_Var18)(pPVar13,__pyx_mstate_global_static.
                                                  __pyx_n_s_unregister_method);
                    }
                    p_Var28 = p_Var26;
                    if (pPVar9 == (PyObject *)0x0) {
                      py_line = 0x5e;
                      iVar8 = 0x17dc;
                      goto LAB_001199a8;
                    }
                    if ((pPVar9->ob_type == (_typeobject *)puVar3) &&
                       (p_Var20 = pPVar9[1].ob_type, p_Var20 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      func = (PyObject *)pPVar9[1].ob_refcnt;
                      (p_Var20->ob_base).ob_base.ob_refcnt =
                           (p_Var20->ob_base).ob_base.ob_refcnt + 1;
                      func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar9->ob_refcnt + -1;
                      pPVar9->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        (**(code **)(puVar3 + 0x30))(pPVar9);
                      }
                      __pyx_pyargnames[0] = (PyObject **)p_Var20;
                      __pyx_pyargnames[1] = (PyObject **)p_Var26;
                      pPVar12 = __Pyx_PyObject_FastCallDict(func,local_70,2,kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var20->ob_base).ob_base.ob_refcnt = lVar30;
                      pPVar9 = func;
                      if (lVar30 == 0) {
                        (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = (PyObject **)p_Var26;
                      pPVar12 = __Pyx_PyObject_FastCallDict
                                          (pPVar9,(PyObject **)(__pyx_pyargnames + 1),1,kwargs);
                    }
                    if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar9->ob_refcnt + -1;
                      pPVar9->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar12->ob_refcnt + -1;
                      pPVar12->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                      }
                      goto LAB_00119370;
                    }
                    py_line = 0x5e;
                    iVar8 = 0x17f0;
                    goto LAB_001199a8;
                  }
                  pPVar12 = (PyObject *)0x0;
                  pPVar11 = (PyObject *)0x0;
                  p_Var28 = (_typeobject *)0x0;
                  iVar8 = 0x1790;
                  py_line = 0x5c;
                }
              }
              goto LAB_00119928;
            }
            py_line = 0x5c;
            iVar8 = 0x1775;
          }
          pPVar11 = (PyObject *)0x0;
          p_Var28 = (_typeobject *)0x0;
          pPVar15 = (PyObject *)0x0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
      }
      goto LAB_001198d8;
    }
    pPVar11 = (PyObject *)0x0;
    p_Var28 = (_typeobject *)0x0;
    pPVar15 = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
LAB_001194ec:
    pPVar25 = (PyObject *)PTR__Py_NoneStruct_00143f40;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_00119504:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar13 != (PyObject *)0x0) &&
     (lVar27 = pPVar13->ob_refcnt + -1, pPVar13->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar13->ob_type->tp_dealloc)(pPVar13);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar15 != (PyObject *)0x0) &&
     (lVar27 = pPVar15->ob_refcnt + -1, pPVar15->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar15->ob_type->tp_dealloc)(pPVar15);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((p_Var28 != (_typeobject *)0x0) &&
     (lVar27 = (p_Var28->ob_base).ob_base.ob_refcnt + -1,
     (p_Var28->ob_base).ob_base.ob_refcnt = lVar27, lVar27 == 0)) {
    (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar11 != (PyObject *)0x0) &&
     (lVar27 = pPVar11->ob_refcnt + -1, pPVar11->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
  }
LAB_00118f50:
  if (lVar23 == *(long *)PTR___stack_chk_guard_00143f20) {
    return pPVar25;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar29 = lVar16 + 1;
    if (lVar30 == lVar29) goto LAB_00119818;
    p_Var28 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar16];
    lVar16 = lVar29;
    if ((_typeobject *)pPVar25 == p_Var28) break;
LAB_00119668:
    bVar6 = pPVar25->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var28->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar29 = lVar16;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar25 != (PyObject *)puVar3) && (bVar6 || p_Var28 != (_typeobject *)puVar3)) {
        plVar17 = (long *)PyObject_RichCompare(pPVar25,p_Var28,2);
        if (plVar17 == (long *)0x0) goto LAB_00119818;
        uVar22 = (uint)(plVar17 == (long *)puVar4);
        if ((plVar17 != (long *)puVar4 && plVar17 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar17 != (long *)puVar3) {
          uVar22 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar19 = *plVar17;
        *plVar17 = lVar19 + -1;
        if (lVar19 + -1 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
LAB_00119808:
        if (uVar22 != 0) {
          if ((int)uVar22 < 0) goto LAB_00119818;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar25[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar25), iVar8 < 0)) ||
         ((-1 < (char)p_Var28->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var28), iVar8 < 0))))
      goto LAB_00119818;
      lVar19 = pPVar25[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar19 == (p_Var28->ob_base).ob_size) &&
         ((pPVar25[1].ob_type == (_typeobject *)p_Var28->tp_name ||
          (_typeobject *)p_Var28->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar25[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar21 = (char *)((ulong)(byte)((byte)pPVar25[2].ob_refcnt >> 2) & 7);
        uVar22 = (uint)pcVar21;
        if (((byte)((byte)p_Var28->tp_basicsize >> 2) & 7) == uVar22) {
          bVar2 = (byte)pPVar25[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var26 = pPVar25[4].ob_type;
          }
          else {
            p_Var26 = (_typeobject *)&pPVar25[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var26 = (_typeobject *)(pPVar25 + 3);
            }
          }
          bVar2 = (byte)p_Var28->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var28->tp_setattr;
          }
          else {
            __s2 = &p_Var28->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var28->tp_dealloc;
            }
          }
          if (uVar22 == 1) {
            uVar22 = (uint)(byte)(p_Var26->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(byte *)__s2;
          }
          else if (uVar22 == 2) {
            uVar22 = (uint)(ushort)(p_Var26->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(ushort *)__s2;
          }
          else {
            uVar22 = (uint)(p_Var26->ob_base).ob_base.ob_refcnt;
            uVar24 = *(uint *)__s2;
          }
          if (uVar24 == uVar22) {
            if (lVar19 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var26,__s2,(long)pcVar21 * lVar19);
              uVar22 = (uint)(iVar8 == 0);
              goto LAB_00119808;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar14[lVar29];
LAB_00119770:
  if (values[1] == (PyObject *)0x0) {
LAB_0011981c:
    lVar27 = PyErr_Occurred();
    if (lVar27 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","remove_agent",
                   "exactly",2,"s",1);
      iVar8 = 0x16e8;
    }
    else {
      iVar8 = 0x16e6;
    }
  }
  else {
    lVar27 = lVar27 + -1;
LAB_001195cc:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar27 < 1) ||
       (iVar8 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,ppPVar14,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x12f9d0,pcVar21), -1 < iVar8))
    goto LAB_00118f98;
    iVar8 = 0x16ed;
  }
LAB_00118f34:
  pPVar25 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.remove_agent",iVar8,0x58,
                     "moonraker/components/extensions.py");
  goto LAB_00118f50;
}


/* ================================================================
 * Address: 0011a090
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_19_select_qidiclient
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_19_select_qidiclient(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_19_select_qidiclient
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject **kwvalues;
  byte bVar1;
  int iVar2;
  Py_ssize_t *pPVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  PyObject *pPVar11;
  PyMappingMethods *pPVar12;
  undefined1 *puVar13;
  long *plVar14;
  long lVar15;
  PyThreadState *tstate;
  PySequenceMethods *pPVar16;
  PyObject *pPVar17;
  setattrfunc *__s2;
  getattrofunc p_Var18;
  binaryfunc p_Var19;
  PyObject *pPVar20;
  char *pcVar21;
  long lVar22;
  uint uVar23;
  PyObject *pPVar24;
  _typeobject *p_Var25;
  long lVar26;
  _typeobject *p_Var27;
  PyObject *func;
  ternaryfunc p_Var28;
  PyObject *pPVar29;
  iternextfunc p_Var30;
  int iVar31;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar22 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar24 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0011a104;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_0011a19c;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  pcVar21 = PTR___stack_chk_guard_00143f20;
  if (__pyx_nargs == 1) {
    pPVar24 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar20 = pPVar24;
LAB_0011a390:
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar6 = PTR_PyUnicode_Type_00143fb0;
    puVar5 = PTR__Py_TrueStruct_00143f48;
    puVar4 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar20) {
      p_Var27 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var27) {
        values[1] = *kwvalues;
      }
      else {
        pPVar29 = (PyObject *)0x0;
        do {
          pPVar17 = (PyObject *)((long)&pPVar29->ob_refcnt + 1);
          if (pPVar17 == pPVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar29 = (PyObject *)0x0;
            goto LAB_0011a3f0;
          }
          pPVar3 = &__pyx_kwds[2].ob_refcnt + (long)pPVar29;
          pPVar29 = pPVar17;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar3);
        values[1] = kwvalues[(long)pPVar17];
      }
      goto LAB_0011a52c;
    }
LAB_0011a5e0:
    values[1] = (PyObject *)0x0;
    goto LAB_0011a5e4;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar13 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_0011a354;
  }
  if (__pyx_nargs == 0) {
    lVar26 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar24 = (PyObject *)(lVar26 + -1);
      pPVar20 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      goto LAB_0011a390;
    }
    lVar26 = PyErr_Occurred();
    if (lVar26 != 0) {
      iVar9 = 0x2008;
      goto LAB_0011a140;
    }
  }
LAB_0011a104:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_select_qidiclient",
               "exactly",2,"s",__pyx_nargs);
  iVar9 = 0x2024;
  goto LAB_0011a140;
  while( true ) {
    pPVar3 = &pPVar29->ob_refcnt;
    pPVar29 = (PyObject *)((long)pPVar3 + 1);
    if (pPVar29 == pPVar20) goto LAB_0011a5e0;
    p_Var27 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar3];
    if ((_typeobject *)pPVar11 == p_Var27) break;
LAB_0011a3f0:
    bVar7 = pPVar11->ob_type != (_typeobject *)puVar6;
    bVar8 = (p_Var27->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar11 != (PyObject *)puVar4) && (bVar7 || p_Var27 != (_typeobject *)puVar4)) {
        plVar14 = (long *)PyObject_RichCompare(pPVar11,p_Var27,2);
        if (plVar14 == (long *)0x0) goto LAB_0011a5e0;
        uVar10 = (uint)(plVar14 == (long *)puVar5);
        if ((plVar14 != (long *)puVar5 && plVar14 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar14 != (long *)puVar4) {
          uVar10 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar26 = *plVar14;
        *plVar14 = lVar26 + -1;
        if (lVar26 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_0011a5d0:
        if (uVar10 != 0) {
          if ((int)uVar10 < 0) goto LAB_0011a5e0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar11[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar11), iVar9 < 0)) ||
         ((-1 < (char)p_Var27->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var27), iVar9 < 0))))
      goto LAB_0011a5e0;
      lVar26 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar26 == (p_Var27->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var27->tp_name ||
          (_typeobject *)p_Var27->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar21 = (char *)((ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7);
        uVar10 = (uint)pcVar21;
        if (((byte)((byte)p_Var27->tp_basicsize >> 2) & 7) == uVar10) {
          bVar1 = (byte)pPVar11[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            p_Var25 = pPVar11[4].ob_type;
          }
          else {
            p_Var25 = (_typeobject *)&pPVar11[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              p_Var25 = (_typeobject *)(pPVar11 + 3);
            }
          }
          bVar1 = (byte)p_Var27->tp_basicsize;
          if ((bVar1 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var27->tp_setattr;
          }
          else {
            __s2 = &p_Var27->tp_setattr;
            if ((bVar1 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var27->tp_dealloc;
            }
          }
          if (uVar10 == 1) {
            uVar10 = (uint)(byte)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar23 = (uint)*(byte *)__s2;
          }
          else if (uVar10 == 2) {
            uVar10 = (uint)(ushort)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar23 = (uint)*(ushort *)__s2;
          }
          else {
            uVar10 = (uint)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar23 = *(uint *)__s2;
          }
          if (uVar23 == uVar10) {
            if (lVar26 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var25,__s2,(long)pcVar21 * lVar26);
              uVar10 = (uint)(iVar9 == 0);
              goto LAB_0011a5d0;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[(long)pPVar29];
LAB_0011a52c:
  if (values[1] != (PyObject *)0x0) {
    puVar13 = (undefined1 *)((long)&pPVar24[-1].ob_type + 7);
LAB_0011a354:
    if (0 < (long)puVar13) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar24 = (PyObject *)values;
      iVar9 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar24,(PyObject **)__pyx_nargs,
                         0x12fa20,pcVar21);
      if (iVar9 < 0) {
        iVar9 = 0x2017;
        goto LAB_0011a140;
      }
    }
LAB_0011a19c:
                    /* Unresolved local var: PyObject * __pyx_v_agent_name@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: int __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_5@[???]
                       Unresolved local var: Py_UCS4 __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: wchar_t __pyx_t_8@[???]
                       Unresolved local var: int __pyx_t_9@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar20 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var18 = values[1]->ob_type->tp_getattro;
    if (p_Var18 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var18)(values[1],__pyx_mstate_global_static.__pyx_n_s_get_str);
    }
    pPVar29 = __pyx_mstate_global_static.__pyx_tuple__7;
    if (pPVar11 == (PyObject *)0x0) {
      pPVar24 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._select_qidiclient",
                         0x2058,0x97,"moonraker/components/extensions.py");
      goto LAB_0011a15c;
    }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
    p_Var28 = pPVar11->ob_type->tp_call;
    if (p_Var28 == (ternaryfunc)0x0) {
      pPVar29 = (PyObject *)PyObject_Call(pPVar11,__pyx_mstate_global_static.__pyx_tuple__7,0);
      if (pPVar29 == (PyObject *)0x0) {
LAB_0011a920:
        pPVar29 = (PyObject *)0x0;
        iVar9 = 0x205a;
        iVar31 = 0x97;
        goto LAB_0011a92c;
      }
LAB_0011a244:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar26 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar26;
      if (lVar26 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      p_Var18 = pPVar20->ob_type->tp_getattro;
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      if (pPVar29 != (PyObject *)PTR__Py_NoneStruct_00143f40) {
        if (p_Var18 == (getattrofunc)0x0) {
          pPVar11 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar11 = (*p_Var18)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_agents);
        }
        if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: int result@[???] */
          iVar9 = PySequence_Contains(pPVar11,pPVar29);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if (iVar9 < 0) {
            iVar31 = 0x99;
            iVar9 = 0x2073;
            lVar26 = pPVar11->ob_refcnt + -1;
LAB_0011a8a0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar11->ob_refcnt = lVar26;
            if (lVar26 != 0) goto LAB_0011ab2c;
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
            goto LAB_0011a8b8;
          }
          lVar26 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar26;
          if (lVar26 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          if (iVar9 != 0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var18 = pPVar20->ob_type->tp_getattro;
            if (p_Var18 == (getattrofunc)0x0) {
              pPVar11 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar11 = (*p_Var18)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_agents);
            }
            if (pPVar11 == (PyObject *)0x0) {
              iVar31 = 0x9b;
              iVar9 = 0x20c5;
              goto LAB_0011ab2c;
            }
                    /* Unresolved local var: PyTypeObject * tp@[???]
                       Unresolved local var: PyMappingMethods * mm@[???]
                       Unresolved local var: PySequenceMethods * sm@[???] */
            pPVar12 = pPVar11->ob_type->tp_as_mapping;
            if ((pPVar12 == (PyMappingMethods *)0x0) ||
               (p_Var19 = pPVar12->mp_subscript, p_Var19 == (binaryfunc)0x0)) {
              pPVar16 = pPVar11->ob_type->tp_as_sequence;
              if ((pPVar16 == (PySequenceMethods *)0x0) || (pPVar16->sq_item == (ssizeargfunc)0x0))
              {
                pPVar24 = __Pyx_PyObject_GetItem_Slow(pPVar11,pPVar29);
              }
              else {
                pPVar24 = __Pyx_PyObject_GetIndex(pPVar11,pPVar29);
              }
            }
            else {
              pPVar24 = (*p_Var19)(pPVar11,pPVar29);
            }
            lVar26 = pPVar11->ob_refcnt + -1;
            if (pPVar24 == (PyObject *)0x0) {
              iVar31 = 0x9b;
              iVar9 = 0x20c7;
              goto LAB_0011a8a0;
            }
LAB_0011a314:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar11->ob_refcnt = lVar26;
            if (lVar26 == 0) {
              (*pPVar11->ob_type->tp_dealloc)(pPVar11);
            }
            goto LAB_0011a31c;
          }
          pPVar11 = __Pyx_PyObject_GetAttrStr(pPVar20,__pyx_mstate_global_static.__pyx_n_s_server);
          if (pPVar11 == (PyObject *)0x0) {
            iVar31 = 0x9a;
            iVar9 = 0x207e;
            goto LAB_0011ab2c;
          }
          pPVar17 = __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_error);
          if (pPVar17 == (PyObject *)0x0) {
            iVar9 = 0x2080;
            iVar31 = 0x9a;
            goto LAB_0011a92c;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar26 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar26;
          if (lVar26 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          pPVar11 = (PyObject *)PyTuple_New(3);
          pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_Agent;
          if (pPVar11 == (PyObject *)0x0) {
            iVar31 = 0x9a;
            iVar9 = 0x2083;
            goto LAB_0011a954;
          }
          p_Var27 = pPVar29->ob_type;
          bVar7 = p_Var27 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
          (__pyx_mstate_global_static.__pyx_kp_u_Agent)->ob_refcnt =
               (__pyx_mstate_global_static.__pyx_kp_u_Agent)->ob_refcnt + 1;
          pPVar11[1].ob_type = (_typeobject *)pPVar24;
          if (bVar7) {
            pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
            pPVar24 = pPVar29;
LAB_0011ac04:
            bVar1 = (byte)pPVar24[2].ob_refcnt;
            pPVar20 = (PyObject *)0x7f;
            if ((bVar1 >> 6 & 1) == 0) {
              bVar1 = bVar1 & 0x1c;
              pPVar20 = (PyObject *)0xff;
              if (bVar1 != 4) {
                uVar10 = 0xffff;
                if (bVar1 != 8) {
                  uVar10 = 0x10ffff;
                }
                pPVar20 = (PyObject *)(ulong)uVar10;
              }
            }
            lVar26 = pPVar24[1].ob_refcnt;
            pPVar11[2].ob_refcnt = (Py_ssize_t)pPVar24;
            pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_not_connected;
            (__pyx_mstate_global_static.__pyx_kp_u_not_connected)->ob_refcnt =
                 (__pyx_mstate_global_static.__pyx_kp_u_not_connected)->ob_refcnt + 1;
            pPVar11[2].ob_type = (_typeobject *)pPVar24;
            pPVar24 = __Pyx_PyUnicode_Join(pPVar11,3,lVar26 + 0x14,(Py_UCS4)pPVar20);
            if (pPVar24 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
              p_Var27 = pPVar17->ob_type;
              if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                 (p_Var25 = pPVar17[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                func = (PyObject *)pPVar17[1].ob_refcnt;
                (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar26 = pPVar17->ob_refcnt + -1;
                pPVar17->ob_refcnt = lVar26;
                if (lVar26 == 0) {
                  (*p_Var27->tp_dealloc)(pPVar17);
                }
                __pyx_pyargnames[0] = (PyObject **)p_Var25;
                __pyx_pyargnames[1] = (PyObject **)pPVar24;
                pPVar11 = __Pyx_PyObject_FastCallDict(func,(PyObject **)__pyx_pyargnames,2,pPVar20);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar26 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                (p_Var25->ob_base).ob_base.ob_refcnt = lVar26;
                pPVar17 = func;
                if (lVar26 == 0) {
                  (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                }
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = (PyObject **)pPVar24;
                pPVar11 = __Pyx_PyObject_FastCallDict
                                    (pPVar17,(PyObject **)(__pyx_pyargnames + 1),1,pPVar20);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar24->ob_refcnt + -1;
              pPVar24->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar24->ob_type->tp_dealloc)(pPVar24);
              }
              if (pPVar11 == (PyObject *)0x0) {
                iVar31 = 0x9a;
                iVar9 = 0x20ac;
                goto LAB_0011a954;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar17->ob_refcnt + -1;
              pPVar17->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar17->ob_type->tp_dealloc)(pPVar17);
              }
              __Pyx_Raise(pPVar11,(PyObject *)0x0,(PyObject *)0x0,pPVar20);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                iVar31 = 0x9a;
                iVar9 = 0x20b2;
              }
              else {
                iVar31 = 0x9a;
                iVar9 = 0x20b2;
              }
              goto LAB_0011ad90;
            }
            iVar9 = 0x2096;
          }
          else {
            if ((p_Var27 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
               (p_Var27 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
              pPVar24 = (*p_Var27->tp_repr)(pPVar29);
            }
            else {
              pPVar24 = (PyObject *)
                        PyObject_Format(pPVar29,__pyx_mstate_global_static.__pyx_empty_unicode);
            }
            iVar9 = 0x208b;
            if (pPVar24 != (PyObject *)0x0) goto LAB_0011ac04;
          }
          lVar26 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar26;
          if (lVar26 == 0) {
            iVar31 = 0x9a;
            goto LAB_0011a940;
          }
          lVar26 = pPVar17->ob_refcnt + -1;
          pPVar17->ob_refcnt = lVar26;
          if (lVar26 != 0) {
            __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._select_qidiclient"
                               ,iVar9,0x9a,"moonraker/components/extensions.py");
            goto LAB_0011ab40;
          }
          iVar31 = 0x9a;
          goto LAB_0011a964;
        }
        iVar31 = 0x99;
        iVar9 = 0x2071;
LAB_0011ab2c:
        __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._select_qidiclient",
                           iVar9,iVar31,"moonraker/components/extensions.py");
        goto LAB_0011ab40;
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      if (p_Var18 == (getattrofunc)0x0) {
        pPVar17 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar17 = (*p_Var18)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_agents);
      }
      if (pPVar17 != (PyObject *)0x0) {
                    /* Unresolved local var: int is_true@[???] */
        uVar10 = (uint)(pPVar17 == (PyObject *)PTR__Py_TrueStruct_00143f48);
        if (((uVar10 != 0 || pPVar17 == (PyObject *)PTR__Py_FalseStruct_00143f10) ||
             pPVar17 == (PyObject *)PTR__Py_NoneStruct_00143f40) ||
           (uVar10 = PyObject_IsTrue(pPVar17), -1 < (int)uVar10)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar26 = pPVar17->ob_refcnt + -1;
          pPVar17->ob_refcnt = lVar26;
          if (lVar26 == 0) {
            (*pPVar17->ob_type->tp_dealloc)(pPVar17);
          }
          if (uVar10 == 0) {
            pPVar17 = __Pyx_PyObject_GetAttrStr(pPVar20,__pyx_mstate_global_static.__pyx_n_s_server)
            ;
            if (pPVar17 == (PyObject *)0x0) {
              iVar31 = 0x9d;
              iVar9 = 0x20ec;
            }
            else {
              pPVar11 = __Pyx_PyObject_GetAttrStr
                                  (pPVar17,__pyx_mstate_global_static.__pyx_n_s_error);
              if (pPVar11 == (PyObject *)0x0) {
                iVar31 = 0x9d;
                iVar9 = 0x20ee;
                goto LAB_0011a954;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar17->ob_refcnt + -1;
              pPVar17->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar17->ob_type->tp_dealloc)(pPVar17);
              }
              pPVar20 = __Pyx_PyObject_Call(pPVar11,__pyx_mstate_global_static.__pyx_tuple__8,
                                            (PyObject *)0x0);
              if (pPVar20 == (PyObject *)0x0) {
                iVar31 = 0x9d;
                iVar9 = 0x20f1;
                lVar26 = pPVar11->ob_refcnt + -1;
                goto LAB_0011a8a0;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
              __Pyx_Raise(pPVar20,(PyObject *)0x0,(PyObject *)0x0,pPVar24);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar26 = pPVar20->ob_refcnt + -1;
              pPVar20->ob_refcnt = lVar26;
              if (lVar26 == 0) {
                (*pPVar20->ob_type->tp_dealloc)(pPVar20);
                iVar31 = 0x9d;
                iVar9 = 0x20f6;
              }
              else {
                iVar31 = 0x9d;
                iVar9 = 0x20f6;
              }
            }
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var18 = pPVar20->ob_type->tp_getattro;
            if (p_Var18 == (getattrofunc)0x0) {
              pPVar17 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar17 = (*p_Var18)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_agents);
            }
            if (pPVar17 == (PyObject *)0x0) {
              iVar31 = 0x9e;
              iVar9 = 0x2108;
            }
            else {
              lVar26 = PyObject_Size(pPVar17);
              if (lVar26 == -1) {
                iVar31 = 0x9e;
                iVar9 = 0x210a;
                goto LAB_0011a954;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar15 = pPVar17->ob_refcnt + -1;
              pPVar17->ob_refcnt = lVar15;
              if (lVar15 == 0) {
                (*pPVar17->ob_type->tp_dealloc)(pPVar17);
              }
              if (lVar26 < 2) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                p_Var18 = pPVar20->ob_type->tp_getattro;
                if (p_Var18 == (getattrofunc)0x0) {
                  pPVar20 = (PyObject *)PyObject_GetAttr();
                }
                else {
                  pPVar20 = (*p_Var18)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_agents);
                }
                if (pPVar20 == (PyObject *)0x0) {
                  iVar31 = 0xa0;
                  iVar9 = 0x2146;
                }
                else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var18 = pPVar20->ob_type->tp_getattro;
                  if (p_Var18 == (getattrofunc)0x0) {
                    pPVar11 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar11 = (*p_Var18)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_values);
                  }
                  lVar26 = pPVar20->ob_refcnt + -1;
                  if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar20->ob_refcnt = lVar26;
                    if (lVar26 == 0) {
                      (*pPVar20->ob_type->tp_dealloc)(pPVar20);
                    }
                    p_Var27 = pPVar11->ob_type;
                    if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                       (p_Var25 = pPVar11[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar20 = (PyObject *)pPVar11[1].ob_refcnt;
                      (p_Var25->ob_base).ob_base.ob_refcnt =
                           (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                      pPVar20->ob_refcnt = pPVar20->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar26 = pPVar11->ob_refcnt + -1;
                      pPVar11->ob_refcnt = lVar26;
                      if (lVar26 == 0) {
                        (*p_Var27->tp_dealloc)(pPVar11);
                      }
                      __pyx_pyargnames[1] = (PyObject **)0x0;
                      __pyx_pyargnames[0] = (PyObject **)p_Var25;
                      pPVar17 = __Pyx_PyObject_FastCallDict
                                          (pPVar20,(PyObject **)__pyx_pyargnames,1,pPVar24);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar26 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var25->ob_base).ob_base.ob_refcnt = lVar26;
                      pPVar11 = pPVar20;
                      if (lVar26 == 0) {
                        (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = (PyObject **)0x0;
                      pPVar17 = __Pyx_PyObject_FastCallDict
                                          (pPVar11,(PyObject **)(__pyx_pyargnames + 1),0,pPVar24);
                    }
                    iVar31 = 0xa0;
                    iVar9 = 0x215d;
                    lVar26 = pPVar11->ob_refcnt + -1;
                    if (pPVar17 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      pPVar11->ob_refcnt = lVar26;
                      if (lVar26 == 0) {
                        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                      }
                      pPVar11 = (PyObject *)PyObject_GetIter(pPVar17);
                      if (pPVar11 == (PyObject *)0x0) {
                        iVar31 = 0xa0;
                        iVar9 = 0x2161;
                        goto LAB_0011a954;
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar26 = pPVar17->ob_refcnt + -1;
                      pPVar17->ob_refcnt = lVar26;
                      if (lVar26 == 0) {
                        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
                      }
                    /* Unresolved local var: PyObject * next@[???]
                       Unresolved local var: iternextfunc iternext@[???] */
                      p_Var30 = pPVar11->ob_type->tp_iternext;
                      if (p_Var30 == (iternextfunc)0x0) {
                    /* Unresolved local var: __Pyx_TypeName iterator_type_name@[???] */
                        iVar31 = 0xa0;
                        iVar9 = 0x2164;
                        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                                     "%.200s object is not an iterator",pPVar11->ob_type->tp_name);
                        lVar26 = pPVar11->ob_refcnt + -1;
                      }
                      else {
                        pPVar24 = (*p_Var30)(pPVar11);
                        if (pPVar24 != (PyObject *)0x0) {
                          lVar26 = pPVar11->ob_refcnt + -1;
                          goto LAB_0011a314;
                        }
                    /* Unresolved local var: PyObject * exc_type@[???]
                       Unresolved local var: PyThreadState * __pyx_tstate@[???] */
                        if ((p_Var30 == (iternextfunc)PTR__PyObject_NextNotImplemented_00143f78) ||
                           (tstate = (PyThreadState *)_PyThreadState_UncheckedGet(),
                           tstate->curexc_type != (PyObject *)0x0)) {
                          iVar31 = 0xa0;
                          iVar9 = 0x2164;
                          lVar26 = pPVar11->ob_refcnt + -1;
                        }
                        else {
                          iVar31 = 0xa0;
                          iVar9 = 0x2164;
                          pPVar24 = *(PyObject **)PTR_PyExc_StopIteration_00143fa0;
                          pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                          __Pyx_ErrRestoreInState(tstate,pPVar24,(PyObject *)0x0,(PyObject *)0x0);
                          lVar26 = pPVar11->ob_refcnt + -1;
                        }
                      }
                    }
                    goto LAB_0011a8a0;
                  }
                  iVar31 = 0xa0;
                  iVar9 = 0x2148;
LAB_0011b09c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar20->ob_refcnt = lVar26;
                  if (lVar26 == 0) {
                    (*pPVar20->ob_type->tp_dealloc)(pPVar20);
                  }
                }
              }
              else {
                pPVar11 = __Pyx_PyObject_GetAttrStr
                                    (pPVar20,__pyx_mstate_global_static.__pyx_n_s_server);
                if (pPVar11 == (PyObject *)0x0) {
                  iVar31 = 0x9f;
                  iVar9 = 0x2116;
                }
                else {
                  pPVar20 = __Pyx_PyObject_GetAttrStr
                                      (pPVar11,__pyx_mstate_global_static.__pyx_n_s_error);
                  if (pPVar20 == (PyObject *)0x0) {
                    iVar31 = 0x9f;
                    iVar9 = 0x2118;
                    lVar26 = pPVar11->ob_refcnt + -1;
                    goto LAB_0011a8a0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar26 = pPVar11->ob_refcnt + -1;
                  pPVar11->ob_refcnt = lVar26;
                  if (lVar26 == 0) {
                    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                  }
                  p_Var27 = pPVar20->ob_type;
                  if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var25 = pPVar20[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar17 = (PyObject *)pPVar20[1].ob_refcnt;
                    (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                    pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar26 = pPVar20->ob_refcnt + -1;
                    pPVar20->ob_refcnt = lVar26;
                    if (lVar26 == 0) {
                      (*p_Var27->tp_dealloc)(pPVar20);
                    }
                    __pyx_pyargnames[1] =
                         (PyObject **)
                         __pyx_mstate_global_static.__pyx_kp_u_Multiple_agents_connected_specif;
                    pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_Multiple_agents_connected_specif
                    ;
                    __pyx_pyargnames[0] = (PyObject **)p_Var25;
                    pPVar11 = __Pyx_PyObject_FastCallDict
                                        (pPVar17,(PyObject **)__pyx_pyargnames,2,
                                         __pyx_mstate_global_static.
                                         __pyx_kp_u_Multiple_agents_connected_specif);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar26 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var25->ob_base).ob_base.ob_refcnt = lVar26;
                    pPVar20 = pPVar17;
                    if (lVar26 == 0) {
                      (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] =
                         (PyObject **)
                         __pyx_mstate_global_static.__pyx_kp_u_Multiple_agents_connected_specif;
                    pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_Multiple_agents_connected_specif
                    ;
                    pPVar11 = __Pyx_PyObject_FastCallDict
                                        (pPVar20,(PyObject **)(__pyx_pyargnames + 1),1,
                                         __pyx_mstate_global_static.
                                         __pyx_kp_u_Multiple_agents_connected_specif);
                  }
                  if (pPVar11 == (PyObject *)0x0) {
                    iVar31 = 0x9f;
                    iVar9 = 0x212d;
                    lVar26 = pPVar20->ob_refcnt + -1;
                    goto LAB_0011b09c;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar26 = pPVar20->ob_refcnt + -1;
                  pPVar20->ob_refcnt = lVar26;
                  if (lVar26 == 0) {
                    (*pPVar20->ob_type->tp_dealloc)(pPVar20);
                  }
                  __Pyx_Raise(pPVar11,(PyObject *)0x0,(PyObject *)0x0,pPVar24);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar26 = pPVar11->ob_refcnt + -1;
                  pPVar11->ob_refcnt = lVar26;
                  if (lVar26 == 0) {
                    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                    iVar31 = 0x9f;
                    iVar9 = 0x2133;
                  }
                  else {
                    iVar31 = 0x9f;
                    iVar9 = 0x2133;
                  }
                }
              }
            }
          }
          goto LAB_0011ad90;
        }
        iVar31 = 0x9c;
        iVar9 = 0x20e0;
        goto LAB_0011a954;
      }
      iVar31 = 0x9c;
      iVar9 = 0x20de;
LAB_0011ad90:
      pPVar24 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._select_qidiclient",iVar9
                         ,iVar31,"moonraker/components/extensions.py");
    }
    else {
      lVar26 = PyThreadState_Get();
      pPVar24 = (PyObject *)PTR__Py_CheckRecursionLimit_00143f00;
      iVar9 = *(int *)(lVar26 + 0x20) + 1;
      *(int *)(lVar26 + 0x20) = iVar9;
      if ((*(int *)pPVar24 < iVar9) &&
         (iVar9 = _Py_CheckRecursiveCall(" while calling a Python object"), iVar9 != 0)) {
        iVar9 = 0x205a;
        iVar31 = 0x97;
        pPVar29 = (PyObject *)0x0;
      }
      else {
        pPVar29 = (*p_Var28)(pPVar11,pPVar29,(PyObject *)0x0);
        lVar26 = PyThreadState_Get();
        puVar4 = PTR__Py_CheckRecursionLimit_00143f00;
        iVar2 = *(int *)(lVar26 + 0x20) + -1;
        *(int *)(lVar26 + 0x20) = iVar2;
        iVar31 = *(int *)puVar4;
        iVar9 = iVar31 + -0x32;
        if (iVar31 < 0xc9) {
          iVar9 = (iVar31 >> 2) * 3;
        }
        if (iVar2 < iVar9) {
          lVar26 = PyThreadState_Get();
          *(undefined1 *)(lVar26 + 0x24) = 0;
        }
        if (pPVar29 != (PyObject *)0x0) goto LAB_0011a244;
        lVar26 = PyErr_Occurred();
        if (lVar26 != 0) goto LAB_0011a920;
        iVar9 = 0x205a;
        iVar31 = 0x97;
        PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00143e98,
                        "NULL result without error in PyObject_Call");
        pPVar29 = (PyObject *)0x0;
      }
LAB_0011a92c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar17 = (PyObject *)0x0;
      lVar26 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar26;
      if (lVar26 == 0) {
LAB_0011a940:
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        if (pPVar17 != (PyObject *)0x0) {
LAB_0011a954:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar26 = pPVar17->ob_refcnt + -1;
          pPVar17->ob_refcnt = lVar26;
          if (lVar26 == 0) {
LAB_0011a964:
            (*pPVar17->ob_type->tp_dealloc)(pPVar17);
          }
        }
      }
LAB_0011a8b8:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._select_qidiclient",iVar9
                         ,iVar31,"moonraker/components/extensions.py");
      pPVar24 = (PyObject *)0x0;
      if (pPVar29 == (PyObject *)0x0) goto LAB_0011a15c;
LAB_0011ab40:
      pPVar24 = (PyObject *)0x0;
    }
LAB_0011a31c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar26 = pPVar29->ob_refcnt + -1;
    pPVar29->ob_refcnt = lVar26;
    if (lVar26 == 0) {
      (*pPVar29->ob_type->tp_dealloc)(pPVar29);
    }
    goto LAB_0011a15c;
  }
LAB_0011a5e4:
  lVar26 = PyErr_Occurred();
  if (lVar26 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_select_qidiclient",
                 "exactly",2,"s",1);
    iVar9 = 0x2012;
  }
  else {
    iVar9 = 0x2010;
  }
LAB_0011a140:
  pPVar24 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._select_qidiclient",iVar9,
                     0x96,"moonraker/components/extensions.py");
LAB_0011a15c:
  if (lVar22 == *(long *)PTR___stack_chk_guard_00143f20) {
    return pPVar24;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011b2f0
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_6write_to_socket
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_6write_to_socket(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_6write_to_socket
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *module_name;
  PyObject *name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_message@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_message;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011b4a0;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011b4dc;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x2fc8;
          goto LAB_0011b3a0;
        }
      }
LAB_0011b364:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","write_to_socket",
                   "exactly",2,"s",__pyx_nargs);
      iVar10 = 0x2fe4;
      goto LAB_0011b3a0;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011b4dc:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_message;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_message == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011b540;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_message != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011b648;
    }
LAB_0011b6f8:
    values[1] = (PyObject *)0x0;
    goto LAB_0011b6fc;
  }
  if (__pyx_nargs != 2) goto LAB_0011b364;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011b3fc:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_10_write_to_socket
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_10_write_to_socket
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_10_write_to_socket
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  name = __pyx_mstate_global_static.__pyx_n_s_write_to_socket;
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  qualname = __pyx_mstate_global_static.__pyx_n_s_UnixSocketClient_write_to_socket;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x300b;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011b784:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.write_to_socket",iVar10,
                       0xf5,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[2].ob_refcnt = (Py_ssize_t)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[1].ob_type = (_typeobject *)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16UnixSocketClient_7generator10
                         ,__pyx_mstate_global_static.__pyx_codeobj__18,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x3016;
      goto LAB_0011b784;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011b3bc:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011b6f8;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011b540:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011b6f8;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011b6ec:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011b6f8;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011b6f8;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011b6ec;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011b648:
  if (values[1] == (PyObject *)0x0) {
LAB_0011b6fc:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","write_to_socket",
                   "exactly",2,"s",1);
      iVar10 = 0x2fd2;
    }
    else {
      iVar10 = 0x2fd0;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011b4a0:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12faa8,pcVar14), -1 < iVar10))
    goto LAB_0011b3fc;
    iVar10 = 0x2fd7;
  }
LAB_0011b3a0:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.write_to_socket",iVar10,0xf5,
                     "moonraker/components/extensions.py");
  goto LAB_0011b3bc;
}


/* ================================================================
 * Address: 0011b888
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_24_handle_qidiclient_files_stats
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_24_handle_qidiclient_files_stats(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_24_handle_qidiclient_files_stats
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011ba38;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011ba74;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x22ed;
          goto LAB_0011b938;
        }
      }
LAB_0011b8fc:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_qidiclient_files_stats","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x2309;
      goto LAB_0011b938;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011ba74:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011bad8;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011bbe0;
    }
LAB_0011bc90:
    values[1] = (PyObject *)0x0;
    goto LAB_0011bc94;
  }
  if (__pyx_nargs != 2) goto LAB_0011b8fc;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011b994:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_5__handle_qidiclient_files_stats
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_5__handle_qidiclient_files_stats
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_5__handle_qidiclient_files_stats
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_stats;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_qidicli_2;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x2330;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011bd1c:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_qidiclient_files_stats"
                       ,iVar10,0xa6,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_type = (_typeobject *)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[2].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_25generator5
                         ,__pyx_mstate_global_static.__pyx_codeobj__10,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x233b;
      goto LAB_0011bd1c;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011b954:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011bc90;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011bad8:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011bc90;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011bc84:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011bc90;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011bc90;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011bc84;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011bbe0:
  if (values[1] == (PyObject *)0x0) {
LAB_0011bc94:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_qidiclient_files_stats","exactly",2,"s",1);
      iVar10 = 0x22f7;
    }
    else {
      iVar10 = 0x22f5;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011ba38:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12f920,pcVar14), -1 < iVar10))
    goto LAB_0011b994;
    iVar10 = 0x22fc;
  }
LAB_0011b938:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_qidiclient_files_stats"
                     ,iVar10,0xa6,"moonraker/components/extensions.py");
  goto LAB_0011b954;
}


/* ================================================================
 * Address: 0011be20
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_13_handle_list_extensions
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_13_handle_list_extensions(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_13_handle_list_extensions
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011bfd0;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011c00c;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x1ce8;
          goto LAB_0011bed0;
        }
      }
LAB_0011be94:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_list_extensions","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x1d04;
      goto LAB_0011bed0;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011c00c:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011c070;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011c178;
    }
LAB_0011c228:
    values[1] = (PyObject *)0x0;
    goto LAB_0011c22c;
  }
  if (__pyx_nargs != 2) goto LAB_0011be94;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011bf2c:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_2__handle_list_extensions
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_2__handle_list_extensions
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_2__handle_list_extensions
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_list_extensions;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_list_ex;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x1d2b;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011c2b4:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_list_extensions",
                       iVar10,0x81,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[2].ob_refcnt = (Py_ssize_t)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[2].ob_type = (_typeobject *)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_14generator2
                         ,__pyx_mstate_global_static.__pyx_codeobj__4,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x1d36;
      goto LAB_0011c2b4;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011beec:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011c228;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011c070:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011c228;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011c21c:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011c228;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011c228;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011c21c;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011c178:
  if (values[1] == (PyObject *)0x0) {
LAB_0011c22c:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_list_extensions","exactly",2,"s",1);
      iVar10 = 0x1cf2;
    }
    else {
      iVar10 = 0x1cf0;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011bfd0:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12f4f8,pcVar14), -1 < iVar10))
    goto LAB_0011bf2c;
    iVar10 = 0x1cf7;
  }
LAB_0011bed0:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_list_extensions",
                     iVar10,0x81,"moonraker/components/extensions.py");
  goto LAB_0011beec;
}


/* ================================================================
 * Address: 0011c3b8
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_3_read_messages
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_3_read_messages(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_3_read_messages
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *module_name;
  PyObject *name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_reader@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_reader;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011c568;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011c5a4;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x2ca7;
          goto LAB_0011c468;
        }
      }
LAB_0011c42c:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_read_messages",
                   "exactly",2,"s",__pyx_nargs);
      iVar10 = 0x2cc3;
      goto LAB_0011c468;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011c5a4:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_reader;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_reader == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011c608;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_reader != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011c710;
    }
LAB_0011c7c0:
    values[1] = (PyObject *)0x0;
    goto LAB_0011c7c4;
  }
  if (__pyx_nargs != 2) goto LAB_0011c42c;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011c4c4:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_9__read_messages
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_9__read_messages
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_9__read_messages
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  name = __pyx_mstate_global_static.__pyx_n_s_read_messages;
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  qualname = __pyx_mstate_global_static.__pyx_n_s_UnixSocketClient__read_messages;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x2cea;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011c84c:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient._read_messages",iVar10,0xdf
                       ,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[3].ob_refcnt = (Py_ssize_t)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[2].ob_type = (_typeobject *)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16UnixSocketClient_4generator9
                         ,__pyx_mstate_global_static.__pyx_codeobj__15,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x2cf5;
      goto LAB_0011c84c;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011c484:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011c7c0;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011c608:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011c7c0;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011c7b4:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011c7c0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011c7c0;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011c7b4;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011c710:
  if (values[1] == (PyObject *)0x0) {
LAB_0011c7c4:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_read_messages",
                   "exactly",2,"s",1);
      iVar10 = 0x2cb1;
    }
    else {
      iVar10 = 0x2caf;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011c568:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12fba0,pcVar14), -1 < iVar10))
    goto LAB_0011c4c4;
    iVar10 = 0x2cb6;
  }
LAB_0011c468:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient._read_messages",iVar10,0xdf,
                     "moonraker/components/extensions.py");
  goto LAB_0011c484;
}


/* ================================================================
 * Address: 0011c950
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_21_handle_qidiclient_files_list
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_21_handle_qidiclient_files_list(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_21_handle_qidiclient_files_list
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011cb00;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011cb3c;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x21c3;
          goto LAB_0011ca00;
        }
      }
LAB_0011c9c4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_qidiclient_files_list","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x21df;
      goto LAB_0011ca00;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011cb3c:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011cba0;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011cca8;
    }
LAB_0011cd58:
    values[1] = (PyObject *)0x0;
    goto LAB_0011cd5c;
  }
  if (__pyx_nargs != 2) goto LAB_0011c9c4;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011ca5c:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_4__handle_qidiclient_files_list
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_4__handle_qidiclient_files_list
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_4__handle_qidiclient_files_list
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_files_list;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_qidicli;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x2206;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011cde4:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_qidiclient_files_list"
                       ,iVar10,0xa2,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_type = (_typeobject *)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[2].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_22generator4
                         ,__pyx_mstate_global_static.__pyx_codeobj__9,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x2211;
      goto LAB_0011cde4;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011ca1c:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011cd58;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011cba0:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011cd58;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011cd4c:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011cd58;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011cd58;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011cd4c;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011cca8:
  if (values[1] == (PyObject *)0x0) {
LAB_0011cd5c:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_qidiclient_files_list","exactly",2,"s",1);
      iVar10 = 0x21cd;
    }
    else {
      iVar10 = 0x21cb;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011cb00:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12f970,pcVar14), -1 < iVar10))
    goto LAB_0011ca5c;
    iVar10 = 0x21d2;
  }
LAB_0011ca00:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_qidiclient_files_list"
                     ,iVar10,0xa2,"moonraker/components/extensions.py");
  goto LAB_0011ca1c;
}


/* ================================================================
 * Address: 0011cee8
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_10_register_agent_method
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_10_register_agent_method(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_10_register_agent_method
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *module_name;
  PyObject *name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011d098;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011d0d4;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x1b16;
          goto LAB_0011cf98;
        }
      }
LAB_0011cf5c:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_register_agent_method","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x1b32;
      goto LAB_0011cf98;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011d0d4:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011d138;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011d240;
    }
LAB_0011d2f0:
    values[1] = (PyObject *)0x0;
    goto LAB_0011d2f4;
  }
  if (__pyx_nargs != 2) goto LAB_0011cf5c;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011cff4:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_1__register_agent_method
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_1__register_agent_method
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_1__register_agent_method
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  name = __pyx_mstate_global_static.__pyx_n_s_register_agent_method;
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__register_agent;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x1b59;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011d37c:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._register_agent_method",
                       iVar10,0x77,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[2].ob_type = (_typeobject *)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[3].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_11generator1
                         ,__pyx_mstate_global_static.__pyx_codeobj__3,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x1b64;
      goto LAB_0011d37c;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011cfb4:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011d2f0;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011d138:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011d2f0;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011d2e4:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011d2f0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011d2f0;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011d2e4;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011d240:
  if (values[1] == (PyObject *)0x0) {
LAB_0011d2f4:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_register_agent_method","exactly",2,"s",1);
      iVar10 = 0x1b20;
    }
    else {
      iVar10 = 0x1b1e;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011d098:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12f9b8,pcVar14), -1 < iVar10))
    goto LAB_0011cff4;
    iVar10 = 0x1b25;
  }
LAB_0011cf98:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._register_agent_method",
                     iVar10,0x77,"moonraker/components/extensions.py");
  goto LAB_0011cfb4;
}


/* ================================================================
 * Address: 0011d480
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_27_handle_qidiclient_config_offical_filament_list
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_27_handle_qidiclient_config_offical_filament_list(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_27_handle_qidiclient_config_offical_filament_list
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011d630;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011d66c;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x2417;
          goto LAB_0011d530;
        }
      }
LAB_0011d4f4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_qidiclient_config_offical_filament_list","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x2433;
      goto LAB_0011d530;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011d66c:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011d6d0;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011d7d8;
    }
LAB_0011d888:
    values[1] = (PyObject *)0x0;
    goto LAB_0011d88c;
  }
  if (__pyx_nargs != 2) goto LAB_0011d4f4;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011d58c:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_6__handle_qidiclient_config_offical_filament_list
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_6__handle_qidiclient_config_offical_filament_list
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_6__handle_qidiclient_config_offical_filament_list
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_qidiclient_config_offica;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_qidicli_3;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x245a;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011d914:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_qidiclient_config_offical_filament_list"
                       ,iVar10,0xaa,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_type = (_typeobject *)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[2].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_28generator6
                         ,__pyx_mstate_global_static.__pyx_codeobj__11,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x2465;
      goto LAB_0011d914;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011d54c:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011d888;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011d6d0:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011d888;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011d87c:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011d888;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011d888;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011d87c;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011d7d8:
  if (values[1] == (PyObject *)0x0) {
LAB_0011d88c:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_qidiclient_config_offical_filament_list","exactly",2,"s",1);
      iVar10 = 0x2421;
    }
    else {
      iVar10 = 0x241f;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011d630:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12f940,pcVar14), -1 < iVar10))
    goto LAB_0011d58c;
    iVar10 = 0x2426;
  }
LAB_0011d530:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_qidiclient_config_offical_filament_list"
                     ,iVar10,0xaa,"moonraker/components/extensions.py");
  goto LAB_0011d54c;
}


/* ================================================================
 * Address: 0011da18
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_16_handle_call_agent
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_16_handle_call_agent(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_16_handle_call_agent
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011dbc8;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011dc04;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x1df7;
          goto LAB_0011dac8;
        }
      }
LAB_0011da8c:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_call_agent","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x1e13;
      goto LAB_0011dac8;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011dc04:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011dc68;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011dd70;
    }
LAB_0011de20:
    values[1] = (PyObject *)0x0;
    goto LAB_0011de24;
  }
  if (__pyx_nargs != 2) goto LAB_0011da8c;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011db24:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct_3__handle_call_agent
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct_3__handle_call_agent
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct_3__handle_call_agent
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_call_agent;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_call_ag;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x1e3a;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011deac:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_call_agent",iVar10,
                       0x88,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[3].ob_refcnt = (Py_ssize_t)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[3].ob_type = (_typeobject *)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_17generator3
                         ,__pyx_mstate_global_static.__pyx_codeobj__5,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x1e45;
      goto LAB_0011deac;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011dae4:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011de20;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011dc68:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011de20;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011de14:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011de20;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011de20;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011de14;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011dd70:
  if (values[1] == (PyObject *)0x0) {
LAB_0011de24:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_call_agent","exactly",2,"s",1);
      iVar10 = 0x1e01;
    }
    else {
      iVar10 = 0x1dff;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011dbc8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12fcf0,pcVar14), -1 < iVar10))
    goto LAB_0011db24;
    iVar10 = 0x1e06;
  }
LAB_0011dac8:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_call_agent",iVar10,
                     0x88,"moonraker/components/extensions.py");
  goto LAB_0011dae4;
}


/* ================================================================
 * Address: 0011dfb0
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_7_handle_agent_event
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_7_handle_agent_event(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_7_handle_agent_event
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *name;
  PyObject *module_name;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  _typeobject *__s1;
  long *plVar11;
  setattrfunc *__s2;
  long lVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  __pyx_CoroutineObject *p_Var18;
  long lVar19;
  long lVar20;
  PyObject *pPVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011e160;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_0011e19c;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x18a9;
          goto LAB_0011e060;
        }
      }
LAB_0011e024:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_agent_event","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x18c5;
      goto LAB_0011e060;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_0011e19c:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar12) {
      p_Var22 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var22) {
        values[1] = *kwvalues;
      }
      else {
        lVar23 = 0;
        do {
          lVar20 = lVar23 + 1;
          if (lVar12 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0011e200;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_0011e308;
    }
LAB_0011e3b8:
    values[1] = (PyObject *)0x0;
    goto LAB_0011e3bc;
  }
  if (__pyx_nargs != 2) goto LAB_0011e024;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011e0bc:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_10extensions___pyx_scope_struct___handle_agent_event
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_10extensions___pyx_scope_struct___handle_agent_event
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_10extensions___pyx_scope_struct___handle_agent_event
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_extensions;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_agent_event;
  qualname = __pyx_mstate_global_static.__pyx_n_s_ExtensionManager__handle_agent_e;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00143f40;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x18ec;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
LAB_0011e444:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_agent_event",iVar10
                       ,99,"moonraker/components/extensions.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[3].ob_type = (_typeobject *)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[4].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_10extensions_16ExtensionManager_8generator
                         ,__pyx_mstate_global_static.__pyx_codeobj_,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x18f7;
      goto LAB_0011e444;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_0011e07c:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00143f20) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_0011e3b8;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_0011e200:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_0011e3b8;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011e3ac:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0011e3b8;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar21[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar21), iVar10 < 0)) ||
         ((-1 < (char)p_Var22->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var22), iVar10 < 0))))
      goto LAB_0011e3b8;
      lVar13 = pPVar21[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var22->ob_base).ob_size) &&
         ((pPVar21[1].ob_type == (_typeobject *)p_Var22->tp_name ||
          (_typeobject *)p_Var22->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar21[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar21[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var22->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar21[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar21[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar21[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar21 + 3);
            }
          }
          bVar2 = (byte)p_Var22->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var22->tp_setattr;
          }
          else {
            __s2 = &p_Var22->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var22->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            uVar15 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            uVar15 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            uVar15 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == uVar15) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar14 * lVar13);
              uVar15 = (uint)(iVar10 == 0);
              goto LAB_0011e3ac;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_0011e308:
  if (values[1] == (PyObject *)0x0) {
LAB_0011e3bc:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_agent_event","exactly",2,"s",1);
      iVar10 = 0x18b3;
    }
    else {
      iVar10 = 0x18b1;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_0011e160:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x12fd50,pcVar14), -1 < iVar10))
    goto LAB_0011e0bc;
    iVar10 = 0x18b8;
  }
LAB_0011e060:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager._handle_agent_event",iVar10,
                     99,"moonraker/components/extensions.py");
  goto LAB_0011e07c;
}


/* ================================================================
 * Address: 0011e548
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_33on_unix_socket_connected
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_33on_unix_socket_connected(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_33on_unix_socket_connected
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyObject *pPVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  long lVar10;
  PyObject *pPVar11;
  PyObject *pPVar12;
  PyObject *pPVar13;
  PyObject **ppPVar14;
  PyObject *pPVar15;
  PyObject *pPVar16;
  long *plVar17;
  setattrfunc *__s2;
  long lVar18;
  getattrofunc p_Var19;
  PyObject *pPVar20;
  __pyx_mstate *kwargs;
  char *pcVar21;
  uint uVar22;
  long lVar23;
  uint uVar24;
  _typeobject *p_Var25;
  PyObject *pPVar26;
  PyObject *func;
  int py_line;
  long lVar27;
  long lVar28;
  Py_ssize_t PVar29;
  _typeobject *p_Var30;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_reader@[???]
                       Unresolved local var: PyObject * __pyx_v_writer@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg26(x26)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar23 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_reader;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_writer;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 3) goto LAB_0011ec74;
    values[1] = __pyx_args[1];
    values[2] = __pyx_args[2];
    values[0] = *__pyx_args;
LAB_0011e7a8:
                    /* Unresolved local var: PyObject * __pyx_v_peercred@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar6 = values[2];
    pPVar16 = values[1];
    pPVar15 = values[0];
    pPVar26 = __pyx_dict_cached_value_18506;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_18505) {
      if (__pyx_dict_cached_value_18506 == (PyObject *)0x0) {
        pPVar26 = __Pyx_GetBuiltinName
                            (__pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials);
        goto LAB_0011ef48;
      }
      __pyx_dict_cached_value_18506->ob_refcnt = __pyx_dict_cached_value_18506->ob_refcnt + 1;
    }
    else {
      pPVar26 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_get_unix_peer_credentials,
                           (uint64_t *)&__pyx_dict_version_18505,&__pyx_dict_cached_value_18506);
LAB_0011ef48:
      if (pPVar26 == (PyObject *)0x0) {
        __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.on_unix_socket_connected"
                           ,0x2832,0xbf,"moonraker/components/extensions.py");
        pPVar26 = (PyObject *)0x0;
        goto LAB_0011eafc;
      }
    }
    p_Var25 = pPVar26->ob_type;
    if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
       (p_Var30 = pPVar26[1].ob_type, p_Var30 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar13 = (PyObject *)pPVar26[1].ob_refcnt;
      (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
      pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar28 = pPVar26->ob_refcnt + -1;
      pPVar26->ob_refcnt = lVar28;
      if (lVar28 == 0) {
        (*p_Var25->tp_dealloc)(pPVar26);
      }
      __pyx_pyargnames[2] =
           (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_Unix_Client_Connection;
      __pyx_pyargnames[0] = (PyObject **)p_Var30;
      __pyx_pyargnames[1] = (PyObject **)pPVar6;
      pPVar11 = __Pyx_PyObject_FastCallDict
                          (pPVar13,(PyObject **)__pyx_pyargnames,3,
                           __pyx_mstate_global_static.__pyx_kp_u_Unix_Client_Connection);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar28 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
      (p_Var30->ob_base).ob_base.ob_refcnt = lVar28;
      if (lVar28 != 0) goto LAB_0011e81c;
      (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
      if (pPVar11 == (PyObject *)0x0) goto LAB_0011ebe0;
LAB_0011e820:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar28 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar28;
      if (lVar28 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      pPVar13 = __pyx_dict_cached_value_18516;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_18515) {
        if (__pyx_dict_cached_value_18516 == (PyObject *)0x0) {
          pPVar13 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
          goto LAB_0011ef90;
        }
        __pyx_dict_cached_value_18516->ob_refcnt = __pyx_dict_cached_value_18516->ob_refcnt + 1;
LAB_0011e870:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var19 = pPVar13->ob_type->tp_getattro;
        if (p_Var19 == (getattrofunc)0x0) {
          pPVar26 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar26 = (*p_Var19)(pPVar13,__pyx_mstate_global_static.__pyx_n_s_info);
        }
        lVar28 = pPVar13->ob_refcnt + -1;
        if (pPVar26 == (PyObject *)0x0) {
          py_line = 0xc0;
          iVar9 = 0x2856;
          goto LAB_0011ebf0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar13->ob_refcnt = lVar28;
        if (lVar28 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var19 = pPVar11->ob_type->tp_getattro;
        if (p_Var19 == (getattrofunc)0x0) {
          pPVar12 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar12 = (*p_Var19)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_get);
        }
        if (pPVar12 == (PyObject *)0x0) {
          lVar28 = pPVar26->ob_refcnt + -1;
          pPVar26->ob_refcnt = lVar28;
          if (lVar28 != 0) {
            iVar9 = 0x2859;
            py_line = 0xc0;
            goto LAB_0011ec48;
          }
          pPVar12 = (PyObject *)0x0;
          iVar9 = 0x2859;
          py_line = 0xc0;
LAB_0011ec24:
          (*pPVar26->ob_type->tp_dealloc)(pPVar26);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (pPVar12 == (PyObject *)0x0) goto LAB_0011ec48;
        }
        else {
          p_Var25 = pPVar12->ob_type;
          if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (p_Var30 = pPVar12[1].ob_type, p_Var30 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            func = (PyObject *)pPVar12[1].ob_refcnt;
            (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
            func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar28 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar28;
            if (lVar28 == 0) {
              (*p_Var25->tp_dealloc)(pPVar12);
            }
            __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_process_id;
            pPVar20 = __pyx_mstate_global_static.__pyx_n_u_process_id;
            __pyx_pyargnames[0] = (PyObject **)p_Var30;
            pPVar13 = __Pyx_PyObject_FastCallDict
                                (func,(PyObject **)__pyx_pyargnames,2,
                                 __pyx_mstate_global_static.__pyx_n_u_process_id);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar28 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
            (p_Var30->ob_base).ob_base.ob_refcnt = lVar28;
            pPVar12 = func;
            if (lVar28 == 0) {
              (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_process_id;
            pPVar20 = __pyx_mstate_global_static.__pyx_n_u_process_id;
            pPVar13 = __Pyx_PyObject_FastCallDict
                                (pPVar12,(PyObject **)(__pyx_pyargnames + 1),1,
                                 __pyx_mstate_global_static.__pyx_n_u_process_id);
          }
          if (pPVar13 == (PyObject *)0x0) {
            iVar9 = 0x286d;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar28 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar28;
            if (lVar28 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
            p_Var25 = pPVar13->ob_type;
            if (p_Var25 == (_typeobject *)PTR_PyUnicode_Type_00143fb0) {
              lVar28 = pPVar13->ob_refcnt;
              pPVar12 = pPVar13;
            }
            else {
              if ((p_Var25 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
                 (p_Var25 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
                pPVar12 = (*p_Var25->tp_repr)(pPVar13);
              }
              else {
                pPVar12 = (PyObject *)
                          PyObject_Format(pPVar13,__pyx_mstate_global_static.__pyx_empty_unicode);
              }
              lVar28 = pPVar13->ob_refcnt + -1;
              if (pPVar12 == (PyObject *)0x0) {
                pPVar13->ob_refcnt = lVar28;
                py_line = 0xc0;
                iVar9 = 0x2871;
                if (lVar28 == 0) goto LAB_0011ebfc;
                goto LAB_0011ec10;
              }
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar13->ob_refcnt = lVar28;
            if (lVar28 == 0) {
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
            }
            ppPVar14 = (PyObject **)
                       PyUnicode_Concat(__pyx_mstate_global_static.
                                        __pyx_kp_u_New_Unix_socket_connection_from,pPVar12);
            if (ppPVar14 != (PyObject **)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = pPVar12->ob_refcnt + -1;
              pPVar12->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              }
              p_Var25 = pPVar26->ob_type;
              if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                 (p_Var30 = pPVar26[1].ob_type, p_Var30 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar12 = (PyObject *)pPVar26[1].ob_refcnt;
                (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
                pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = pPVar26->ob_refcnt + -1;
                pPVar26->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*p_Var25->tp_dealloc)(pPVar26);
                }
                __pyx_pyargnames[0] = (PyObject **)p_Var30;
                __pyx_pyargnames[1] = ppPVar14;
                pPVar13 = __Pyx_PyObject_FastCallDict
                                    (pPVar12,(PyObject **)__pyx_pyargnames,2,pPVar20);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
                (p_Var30->ob_base).ob_base.ob_refcnt = lVar28;
                if (lVar28 != 0) goto LAB_0011e9d4;
                (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
                pPVar20 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                *ppPVar14 = pPVar20;
                pPVar26 = pPVar12;
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = ppPVar14;
                pPVar13 = __Pyx_PyObject_FastCallDict
                                    (pPVar26,(PyObject **)(__pyx_pyargnames + 1),1,pPVar20);
                pPVar12 = pPVar26;
LAB_0011e9d4:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                pPVar20 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                *ppPVar14 = pPVar20;
                pPVar26 = pPVar12;
              }
              if (pPVar20 == (PyObject *)0x0) {
                (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
              }
              if (pPVar13 == (PyObject *)0x0) {
                py_line = 0xc0;
                iVar9 = 0x288a;
                goto LAB_0011ec10;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = pPVar26->ob_refcnt + -1;
              pPVar26->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*pPVar26->ob_type->tp_dealloc)(pPVar26);
                lVar28 = pPVar13->ob_refcnt + -1;
                pPVar13->ob_refcnt = lVar28;
              }
              else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = pPVar13->ob_refcnt + -1;
                pPVar13->ob_refcnt = lVar28;
              }
              if (lVar28 == 0) {
                (*pPVar13->ob_type->tp_dealloc)(pPVar13);
              }
              pPVar26 = __pyx_dict_cached_value_18537;
              kwargs = &__pyx_mstate_global_static;
              if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_18536) {
                if (__pyx_dict_cached_value_18537 == (PyObject *)0x0) {
                  pPVar26 = __Pyx_GetBuiltinName
                                      (__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient);
                  goto LAB_0011f1b8;
                }
                __pyx_dict_cached_value_18537->ob_refcnt =
                     __pyx_dict_cached_value_18537->ob_refcnt + 1;
              }
              else {
                pPVar26 = __Pyx__GetModuleGlobalName
                                    (__pyx_mstate_global_static.__pyx_n_s_UnixSocketClient,
                                     (uint64_t *)&__pyx_dict_version_18536,
                                     &__pyx_dict_cached_value_18537);
LAB_0011f1b8:
                if (pPVar26 == (PyObject *)0x0) {
                  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.on_unix_socket_connected"
                                     ,0x2897,0xc1,"moonraker/components/extensions.py");
                  pPVar26 = (PyObject *)0x0;
                  goto LAB_0011eadc;
                }
              }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var19 = pPVar15->ob_type->tp_getattro;
              if (p_Var19 == (getattrofunc)0x0) {
                pPVar15 = (PyObject *)PyObject_GetAttr();
              }
              else {
                pPVar15 = (*p_Var19)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_server);
              }
              if (pPVar15 == (PyObject *)0x0) {
                py_line = 0xc1;
                iVar9 = 0x2899;
              }
              else {
                p_Var25 = pPVar26->ob_type;
                if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                   (p_Var30 = pPVar26[1].ob_type, p_Var30 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar13 = (PyObject *)pPVar26[1].ob_refcnt;
                  (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
                  pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar28 = pPVar26->ob_refcnt + -1;
                  pPVar26->ob_refcnt = lVar28;
                  if (lVar28 == 0) {
                    (*p_Var25->tp_dealloc)(pPVar26);
                  }
                  __pyx_pyargnames[0] = (PyObject **)p_Var30;
                  __pyx_pyargnames[1] = (PyObject **)pPVar15;
                  __pyx_pyargnames[2] = (PyObject **)pPVar16;
                  __pyx_pyargnames[3] = (PyObject **)pPVar6;
                  pPVar16 = __Pyx_PyObject_FastCallDict
                                      (pPVar13,(PyObject **)__pyx_pyargnames,5,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar28 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var30->ob_base).ob_base.ob_refcnt = lVar28;
                  pPVar26 = pPVar13;
                  if (lVar28 == 0) {
                    (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
                  }
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = (PyObject **)pPVar15;
                  __pyx_pyargnames[2] = (PyObject **)pPVar16;
                  __pyx_pyargnames[3] = (PyObject **)pPVar6;
                  pPVar16 = __Pyx_PyObject_FastCallDict
                                      (pPVar26,(PyObject **)(__pyx_pyargnames + 1),4,
                                       (PyObject *)kwargs);
                }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = pPVar15->ob_refcnt + -1;
                pPVar15->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*pPVar15->ob_type->tp_dealloc)(pPVar15);
                }
                if (pPVar16 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar28 = pPVar26->ob_refcnt + -1;
                  pPVar26->ob_refcnt = lVar28;
                  if (lVar28 == 0) {
                    (*pPVar26->ob_type->tp_dealloc)(pPVar26);
                    lVar28 = pPVar16->ob_refcnt + -1;
                    pPVar16->ob_refcnt = lVar28;
                  }
                  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = pPVar16->ob_refcnt + -1;
                    pPVar16->ob_refcnt = lVar28;
                  }
                  if (lVar28 == 0) {
                    (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                  }
                  pPVar26 = (PyObject *)PTR__Py_NoneStruct_00143f40;
                  *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
                  goto LAB_0011eadc;
                }
                py_line = 0xc1;
                iVar9 = 0x28ae;
              }
LAB_0011ec10:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = pPVar26->ob_refcnt + -1;
              pPVar26->ob_refcnt = lVar28;
              if (lVar28 != 0) goto LAB_0011ec48;
              pPVar12 = (PyObject *)0x0;
              goto LAB_0011ec24;
            }
            iVar9 = 0x2874;
          }
          py_line = 0xc0;
          lVar28 = pPVar26->ob_refcnt + -1;
          pPVar26->ob_refcnt = lVar28;
          if (lVar28 == 0) goto LAB_0011ec24;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar28 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar28;
        if (lVar28 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        goto LAB_0011ec48;
      }
      pPVar13 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_logging,
                           (uint64_t *)&__pyx_dict_version_18515,&__pyx_dict_cached_value_18516);
LAB_0011ef90:
      if (pPVar13 != (PyObject *)0x0) goto LAB_0011e870;
      pPVar26 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.on_unix_socket_connected"
                         ,0x2854,0xc0,"moonraker/components/extensions.py");
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[2] =
           (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_Unix_Client_Connection;
      __pyx_pyargnames[1] = (PyObject **)pPVar6;
      pPVar11 = __Pyx_PyObject_FastCallDict
                          (pPVar26,(PyObject **)(__pyx_pyargnames + 1),2,
                           __pyx_mstate_global_static.__pyx_kp_u_Unix_Client_Connection);
      pPVar13 = pPVar26;
LAB_0011e81c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (pPVar11 != (PyObject *)0x0) goto LAB_0011e820;
LAB_0011ebe0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      py_line = 0xbf;
      iVar9 = 0x2846;
      lVar28 = pPVar13->ob_refcnt + -1;
LAB_0011ebf0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar13->ob_refcnt = lVar28;
      if (lVar28 == 0) {
        pPVar26 = (PyObject *)0x0;
LAB_0011ebfc:
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        if (pPVar26 != (PyObject *)0x0) goto LAB_0011ec10;
      }
LAB_0011ec48:
      pPVar26 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.on_unix_socket_connected"
                         ,iVar9,py_line,"moonraker/components/extensions.py");
      if (pPVar11 == (PyObject *)0x0) goto LAB_0011eafc;
      pPVar26 = (PyObject *)0x0;
    }
LAB_0011eadc:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar28 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    goto LAB_0011eafc;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar14 = __pyx_args + __pyx_nargs;
  pcVar21 = PTR___stack_chk_guard_00143f20;
  if (__pyx_nargs == 1) {
    values[0] = *__pyx_args;
    lVar28 = __pyx_kwds[1].ob_refcnt;
LAB_0011e76c:
    values[1] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar14,__pyx_mstate_global_static.__pyx_n_s_reader);
    if (values[1] != (PyObject *)0x0) {
      PVar29 = lVar28 + -1;
      lVar28 = __pyx_kwds[1].ob_refcnt;
LAB_0011e5fc:
      pPVar26 = __pyx_mstate_global_static.__pyx_n_s_writer;
      puVar5 = PTR_PyUnicode_Type_00143fb0;
      puVar4 = PTR__Py_TrueStruct_00143f48;
      puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar28) {
        p_Var25 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_writer == p_Var25) {
          values[2] = *ppPVar14;
        }
        else {
          lVar10 = 0;
          do {
            lVar27 = lVar10 + 1;
            if (lVar27 == lVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar10 = 0;
              goto LAB_0011e660;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar10;
            lVar10 = lVar27;
          } while (__pyx_mstate_global_static.__pyx_n_s_writer != (PyObject *)*pPVar1);
          values[2] = ppPVar14[lVar27];
        }
        goto LAB_0011edfc;
      }
LAB_0011eea8:
      values[2] = (PyObject *)0x0;
      goto LAB_0011eeac;
    }
    lVar28 = PyErr_Occurred();
    if (lVar28 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "on_unix_socket_connected","exactly",3,"s",1);
      iVar9 = 0x27e3;
    }
    else {
      iVar9 = 0x27e1;
    }
  }
  else {
    if (1 < __pyx_nargs) {
      if (__pyx_nargs != 2) {
        if (__pyx_nargs != 3) goto LAB_0011ec74;
        values[2] = __pyx_args[2];
      }
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar28 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs == 1) goto LAB_0011e76c;
      PVar29 = lVar28;
      if (__pyx_nargs == 2) goto LAB_0011e5fc;
      if (__pyx_nargs == 0) goto LAB_0011e74c;
      goto LAB_0011e798;
    }
    if (__pyx_nargs == 0) {
      lVar28 = __pyx_kwds[1].ob_refcnt;
LAB_0011e74c:
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,ppPVar14,__pyx_mstate_global_static.__pyx_n_s_self);
      if (values[0] != (PyObject *)0x0) {
        lVar28 = lVar28 + -1;
        goto LAB_0011e76c;
      }
      lVar28 = PyErr_Occurred();
      if (lVar28 == 0) goto LAB_0011ec74;
      iVar9 = 0x27d9;
    }
    else {
LAB_0011ec74:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "on_unix_socket_connected","exactly",3,"s",__pyx_nargs);
      iVar9 = 0x2801;
    }
  }
  goto LAB_0011ecb0;
  while( true ) {
    lVar27 = lVar10 + 1;
    if (lVar27 == lVar28) goto LAB_0011eea8;
    p_Var25 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar10];
    lVar10 = lVar27;
    if ((_typeobject *)pPVar26 == p_Var25) break;
LAB_0011e660:
    bVar7 = pPVar26->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var25->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar27 = lVar10;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar26 != (PyObject *)puVar3) && (bVar7 || p_Var25 != (_typeobject *)puVar3)) {
        plVar17 = (long *)PyObject_RichCompare(pPVar26,p_Var25,2);
        if (plVar17 == (long *)0x0) goto LAB_0011eea8;
        uVar22 = (uint)(plVar17 == (long *)puVar4);
        if ((plVar17 != (long *)puVar4 && plVar17 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar17 != (long *)puVar3) {
          uVar22 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar18 = *plVar17;
        *plVar17 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
LAB_0011ee98:
        if (uVar22 != 0) {
          if ((int)uVar22 < 0) goto LAB_0011eea8;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar26[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar26), iVar9 < 0)) ||
         ((-1 < (char)p_Var25->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var25), iVar9 < 0))))
      goto LAB_0011eea8;
      lVar18 = pPVar26[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar18 == (p_Var25->ob_base).ob_size) &&
         ((pPVar26[1].ob_type == (_typeobject *)p_Var25->tp_name ||
          (_typeobject *)p_Var25->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar26[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar21 = (char *)((ulong)(byte)((byte)pPVar26[2].ob_refcnt >> 2) & 7);
        uVar22 = (uint)pcVar21;
        if (((byte)((byte)p_Var25->tp_basicsize >> 2) & 7) == uVar22) {
          bVar2 = (byte)pPVar26[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var30 = pPVar26[4].ob_type;
          }
          else {
            p_Var30 = (_typeobject *)&pPVar26[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var30 = (_typeobject *)(pPVar26 + 3);
            }
          }
          bVar2 = (byte)p_Var25->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var25->tp_setattr;
          }
          else {
            __s2 = &p_Var25->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var25->tp_dealloc;
            }
          }
          if (uVar22 == 1) {
            uVar22 = (uint)(byte)(p_Var30->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(byte *)__s2;
          }
          else if (uVar22 == 2) {
            uVar22 = (uint)(ushort)(p_Var30->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(ushort *)__s2;
          }
          else {
            uVar22 = (uint)(p_Var30->ob_base).ob_base.ob_refcnt;
            uVar24 = *(uint *)__s2;
          }
          if (uVar24 == uVar22) {
            if (lVar18 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var30,__s2,(long)pcVar21 * lVar18);
              uVar22 = (uint)(iVar9 == 0);
              goto LAB_0011ee98;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = ppPVar14[lVar27];
LAB_0011edfc:
  if (values[2] == (PyObject *)0x0) {
LAB_0011eeac:
    lVar28 = PyErr_Occurred();
    if (lVar28 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "on_unix_socket_connected","exactly",3,"s",2);
      iVar9 = 0x27ed;
    }
    else {
      iVar9 = 0x27eb;
    }
  }
  else {
    lVar28 = PVar29 + -1;
LAB_0011e798:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar28 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,ppPVar14,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x12fdb0,pcVar21), -1 < iVar9))
    goto LAB_0011e7a8;
    iVar9 = 0x27f2;
  }
LAB_0011ecb0:
  pPVar26 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.on_unix_socket_connected",
                     iVar9,0xbc,"moonraker/components/extensions.py");
LAB_0011eafc:
  if (lVar23 == *(long *)PTR___stack_chk_guard_00143f20) {
    return pPVar26;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 001210b0
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_12close_socket
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_12close_socket(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Exceeded maximum restarts with more pending */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_12close_socket
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyObject *pPVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  PyObject *pPVar12;
  PyObject *pPVar13;
  PyObject *func;
  PyObject *pPVar14;
  long *plVar15;
  setattrfunc *__s2;
  long lVar16;
  getattrofunc p_Var17;
  char *pcVar18;
  long lVar19;
  uint uVar20;
  _typeobject *p_Var21;
  long lVar22;
  int c_line;
  _typeobject *p_Var23;
  long lVar24;
  long lVar25;
  long lVar26;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_code@[???]
                       Unresolved local var: PyObject * __pyx_v_reason@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg26(x26)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar19 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_code;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_reason;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  pPVar12 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 3) goto LAB_00121300;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    values[2] = __pyx_args[2];
    goto LAB_0012139c;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  pcVar18 = PTR___stack_chk_guard_00143f20;
  if (__pyx_nargs == 1) {
    values[0] = *__pyx_args;
    lVar24 = __pyx_kwds[1].ob_refcnt;
LAB_001212d4:
    values[1] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_code);
    if (values[1] != (PyObject *)0x0) {
      lVar25 = lVar24 + -1;
      lVar24 = __pyx_kwds[1].ob_refcnt;
LAB_00121160:
      pPVar14 = __pyx_mstate_global_static.__pyx_n_s_reason;
      puVar5 = PTR_PyUnicode_Type_00143fb0;
      puVar4 = PTR__Py_TrueStruct_00143f48;
      puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar24) {
        p_Var23 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_reason == p_Var23) {
          values[2] = *kwvalues;
        }
        else {
          lVar26 = 0;
          do {
            lVar22 = lVar26 + 1;
            if (lVar24 == lVar22) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar24 = 0;
              goto LAB_001211c8;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar26;
            lVar26 = lVar22;
          } while (__pyx_mstate_global_static.__pyx_n_s_reason != (PyObject *)*pPVar1);
          values[2] = kwvalues[lVar22];
        }
        goto LAB_0012166c;
      }
LAB_00121718:
      values[2] = (PyObject *)0x0;
      goto LAB_0012171c;
    }
    lVar24 = PyErr_Occurred();
    if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","close_socket",
                   "exactly",3,"s",1);
      iVar10 = 0x35f7;
    }
    else {
      iVar10 = 0x35f5;
    }
  }
  else {
    if (1 < __pyx_nargs) {
      if (__pyx_nargs != 2) {
        if (__pyx_nargs != 3) goto LAB_00121300;
        values[2] = __pyx_args[2];
      }
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar24 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs == 1) goto LAB_001212d4;
      lVar25 = lVar24;
      if (__pyx_nargs == 2) goto LAB_00121160;
      if (__pyx_nargs == 0) goto LAB_001212b4;
      goto LAB_00121388;
    }
    if (__pyx_nargs == 0) {
      lVar24 = __pyx_kwds[1].ob_refcnt;
LAB_001212b4:
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
      if (values[0] != (PyObject *)0x0) {
        lVar24 = lVar24 + -1;
        goto LAB_001212d4;
      }
      lVar24 = PyErr_Occurred();
      if (lVar24 == 0) goto LAB_00121300;
      iVar10 = 0x35ed;
    }
    else {
LAB_00121300:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","close_socket",
                   "exactly",3,"s",__pyx_nargs);
      iVar10 = 0x3615;
    }
  }
LAB_0012133c:
  __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.close_socket",iVar10,0x124,
                     "moonraker/components/extensions.py");
  goto LAB_00121354;
  while( true ) {
    lVar22 = lVar24 + 1;
    if (lVar24 == lVar26) goto LAB_00121718;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar24];
    lVar24 = lVar22;
    if ((_typeobject *)pPVar14 == p_Var23) break;
LAB_001211c8:
    bVar8 = pPVar14->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar22 = lVar24;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar14 != (PyObject *)puVar3) && (bVar8 || p_Var23 != (_typeobject *)puVar3)) {
        plVar15 = (long *)PyObject_RichCompare(pPVar14,p_Var23,2);
        if (plVar15 == (long *)0x0) goto LAB_00121718;
        uVar11 = (uint)(plVar15 == (long *)puVar4);
        if ((plVar15 != (long *)puVar4 && plVar15 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar15 != (long *)puVar3) {
          uVar11 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar16 = *plVar15;
        *plVar15 = lVar16 + -1;
        if (lVar16 + -1 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
LAB_00121708:
        if (uVar11 != 0) {
          if ((int)uVar11 < 0) goto LAB_00121718;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar14[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar14), iVar10 < 0)) ||
         ((-1 < (char)p_Var23->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var23), iVar10 < 0))))
      goto LAB_00121718;
      lVar16 = pPVar14[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar16 == (p_Var23->ob_base).ob_size) &&
         ((pPVar14[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar14[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar18 = (char *)((ulong)(byte)((byte)pPVar14[2].ob_refcnt >> 2) & 7);
        uVar11 = (uint)pcVar18;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar11) {
          bVar2 = (byte)pPVar14[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var21 = pPVar14[4].ob_type;
          }
          else {
            p_Var21 = (_typeobject *)&pPVar14[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var21 = (_typeobject *)(pPVar14 + 3);
            }
          }
          bVar2 = (byte)p_Var23->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var23->tp_setattr;
          }
          else {
            __s2 = &p_Var23->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var23->tp_dealloc;
            }
          }
          if (uVar11 == 1) {
            uVar11 = (uint)(byte)(p_Var21->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(byte *)__s2;
          }
          else if (uVar11 == 2) {
            uVar11 = (uint)(ushort)(p_Var21->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(ushort *)__s2;
          }
          else {
            uVar11 = (uint)(p_Var21->ob_base).ob_base.ob_refcnt;
            uVar20 = *(uint *)__s2;
          }
          if (uVar20 == uVar11) {
            if (lVar16 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var21,__s2,(long)pcVar18 * lVar16);
              uVar11 = (uint)(iVar10 == 0);
              goto LAB_00121708;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar22];
LAB_0012166c:
  if (values[2] == (PyObject *)0x0) {
LAB_0012171c:
    lVar24 = PyErr_Occurred();
    if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","close_socket",
                   "exactly",3,"s",2);
      iVar10 = 0x3601;
    }
    else {
      iVar10 = 0x35ff;
    }
    goto LAB_0012133c;
  }
  lVar24 = lVar25 + -1;
LAB_00121388:
  if (0 < lVar24) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    pPVar12 = (PyObject *)values;
    iVar10 = __Pyx_ParseOptionalKeywords
                       (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar12,(PyObject **)__pyx_nargs,
                        0x12fe20,pcVar18);
    if (iVar10 < 0) {
      iVar10 = 0x3606;
      goto LAB_0012133c;
    }
  }
LAB_0012139c:
  pPVar7 = values[2];
  pPVar6 = values[1];
  pPVar14 = values[0];
  if (((values[1]->ob_type == (_typeobject *)PTR_PyLong_Type_00143f70) ||
      (iVar10 = __Pyx__ArgTypeTest((PyObject *)&values[1]->ob_type,
                                   (PyTypeObject *)PTR_PyLong_Type_00143f70,"code",(int)pPVar12),
      iVar10 != 0)) &&
     ((pPVar7->ob_type == (_typeobject *)PTR_PyUnicode_Type_00143fb0 ||
      (iVar10 = __Pyx__ArgTypeTest((PyObject *)&pPVar7->ob_type,
                                   (PyTypeObject *)PTR_PyUnicode_Type_00143fb0,"reason",(int)pPVar12
                                  ), iVar10 != 0)))) {
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: int __pyx_t_2@[???]
                       Unresolved local var: int __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: wchar_t __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyTypeObject * tp@[???] */
    p_Var17 = pPVar14->ob_type->tp_getattro;
    if (p_Var17 == (getattrofunc)0x0) {
      pPVar13 = (PyObject *)PyObject_GetAttr(pPVar14);
    }
    else {
      pPVar13 = (*p_Var17)(pPVar14,__pyx_mstate_global_static.__pyx_n_s_is_closed);
    }
    if (pPVar13 == (PyObject *)0x0) {
      iVar10 = 0x125;
      c_line = 0x364c;
    }
    else {
                    /* Unresolved local var: int is_true@[???] */
      uVar11 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00143f48);
      if (((uVar11 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00143f10) &&
           pPVar13 != (PyObject *)PTR__Py_NoneStruct_00143f40) &&
         (uVar11 = PyObject_IsTrue(pPVar13), (int)uVar11 < 0)) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          c_line = 0x364e;
          iVar10 = 0x125;
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        else {
          iVar10 = 0x125;
          c_line = 0x364e;
        }
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        if (uVar11 != 0) {
LAB_001215b0:
          pPVar12 = (PyObject *)PTR__Py_NoneStruct_00143f40;
          *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
          goto LAB_00121358;
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var17 = pPVar14->ob_type->tp_getattro;
        if (p_Var17 == (getattrofunc)0x0) {
          pPVar13 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar13 = (*p_Var17)(pPVar14,__pyx_mstate_global_static.__pyx_n_s_eventloop);
        }
        if (pPVar13 == (PyObject *)0x0) {
          iVar10 = 0x126;
          c_line = 0x365a;
        }
        else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = pPVar13->ob_type->tp_getattro;
          if (p_Var17 == (getattrofunc)0x0) {
            func = (PyObject *)
                   PyObject_GetAttr(pPVar13,__pyx_mstate_global_static.__pyx_n_s_register_callback);
          }
          else {
            func = (PyObject *)(*p_Var17)();
          }
          lVar24 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar13->ob_refcnt = lVar24;
          if (func == (PyObject *)0x0) {
            if (lVar24 == 0) {
              c_line = 0x365c;
              iVar10 = 0x126;
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
            }
            else {
              iVar10 = 0x126;
              c_line = 0x365c;
            }
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            if (lVar24 == 0) {
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var17 = pPVar14->ob_type->tp_getattro;
            if (p_Var17 == (getattrofunc)0x0) {
              pPVar14 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar14 = (*p_Var17)(pPVar14,__pyx_mstate_global_static.__pyx_n_s_on_close);
            }
            if (pPVar14 == (PyObject *)0x0) {
              c_line = 0x365f;
            }
            else {
              p_Var23 = func->ob_type;
              if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                 (p_Var21 = func[1].ob_type, p_Var21 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar13 = (PyObject *)func[1].ob_refcnt;
                (p_Var21->ob_base).ob_base.ob_refcnt = (p_Var21->ob_base).ob_base.ob_refcnt + 1;
                pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar24 = func->ob_refcnt + -1;
                func->ob_refcnt = lVar24;
                if (lVar24 == 0) {
                  (*p_Var23->tp_dealloc)(func);
                }
                __pyx_pyargnames[0] = (PyObject **)p_Var21;
                __pyx_pyargnames[1] = (PyObject **)pPVar14;
                __pyx_pyargnames[2] = (PyObject **)pPVar6;
                __pyx_pyargnames[3] = (PyObject **)pPVar7;
                pPVar12 = __Pyx_PyObject_FastCallDict
                                    (pPVar13,(PyObject **)__pyx_pyargnames,4,pPVar12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar24 = (p_Var21->ob_base).ob_base.ob_refcnt + -1;
                (p_Var21->ob_base).ob_base.ob_refcnt = lVar24;
                func = pPVar13;
                if (lVar24 == 0) {
                  (*((p_Var21->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var21);
                }
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = (PyObject **)pPVar14;
                __pyx_pyargnames[2] = (PyObject **)pPVar6;
                __pyx_pyargnames[3] = (PyObject **)pPVar7;
                pPVar12 = __Pyx_PyObject_FastCallDict
                                    (func,(PyObject **)(__pyx_pyargnames + 1),3,pPVar12);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar24 = pPVar14->ob_refcnt + -1;
              pPVar14->ob_refcnt = lVar24;
              if (lVar24 == 0) {
                (*pPVar14->ob_type->tp_dealloc)(pPVar14);
              }
              if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar24 = func->ob_refcnt + -1;
                func->ob_refcnt = lVar24;
                if (lVar24 == 0) {
                  (*func->ob_type->tp_dealloc)(func);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar24 = pPVar12->ob_refcnt + -1;
                pPVar12->ob_refcnt = lVar24;
                if (lVar24 == 0) {
                  (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                }
                goto LAB_001215b0;
              }
              c_line = 0x3674;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            iVar10 = 0x126;
            lVar24 = func->ob_refcnt + -1;
            func->ob_refcnt = lVar24;
            if (lVar24 == 0) {
              (*func->ob_type->tp_dealloc)(func);
            }
          }
        }
      }
    }
    __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.close_socket",c_line,iVar10
                       ,"moonraker/components/extensions.py");
    pPVar12 = (PyObject *)0x0;
    goto LAB_00121358;
  }
LAB_00121354:
  pPVar12 = (PyObject *)0x0;
LAB_00121358:
  if (lVar19 == *(long *)PTR___stack_chk_guard_00143f20) {
    return pPVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 001219d8
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_3register_agent
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_3register_agent(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_3register_agent
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  PyObject *d;
  PyObject *key;
  PyObject *s1;
  PyObject *pPVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  PyObject **ppPVar12;
  long *plVar13;
  _typeobject *p_Var14;
  setattrfunc *__s2;
  getattrofunc p_Var15;
  long lVar16;
  binaryfunc p_Var17;
  long lVar18;
  PyObject *pPVar19;
  _typeobject *kwargs;
  __pyx_mstate *kwargs_00;
  char *pcVar20;
  uint uVar21;
  long lVar22;
  uint uVar23;
  PyObject *pPVar24;
  long lVar25;
  _typeobject *p_Var26;
  int iVar27;
  long lVar28;
  PyObject *pPVar29;
  Py_ssize_t PVar30;
  PyObject **local_40;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_connection@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar22 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_connection;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    ppPVar12 = __pyx_args + __pyx_nargs;
    pcVar20 = PTR___stack_chk_guard_00143f20;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar25 = __pyx_kwds[1].ob_refcnt;
        goto LAB_00122640;
      }
      if (__pyx_nargs == 0) {
        lVar25 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,ppPVar12,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar25 = lVar25 + -1;
          PVar30 = __pyx_kwds[1].ob_refcnt;
          goto LAB_0012267c;
        }
        lVar25 = PyErr_Occurred();
        if (lVar25 != 0) {
          iVar8 = 0x1452;
          goto LAB_00121a84;
        }
      }
LAB_00121a48:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","register_agent",
                   "exactly",2,"s",__pyx_nargs);
      iVar8 = 0x146e;
      goto LAB_00121a84;
    }
    lVar25 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    PVar30 = lVar25;
LAB_0012267c:
    pPVar24 = __pyx_mstate_global_static.__pyx_n_s_connection;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < PVar30) {
      p_Var26 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_connection == p_Var26) {
        values[1] = *ppPVar12;
      }
      else {
        lVar16 = 0;
        do {
          lVar28 = lVar16 + 1;
          if (lVar28 == PVar30) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar16 = 0;
            goto LAB_001226e0;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar16;
          lVar16 = lVar28;
        } while (__pyx_mstate_global_static.__pyx_n_s_connection != (PyObject *)*pPVar1);
        values[1] = ppPVar12[lVar28];
      }
      goto LAB_0012289c;
    }
LAB_00122950:
    values[1] = (PyObject *)0x0;
    goto LAB_00122954;
  }
  if (__pyx_nargs != 2) goto LAB_00121a48;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_00121ae8:
                    /* Unresolved local var: PyObject * __pyx_v_data@[???]
                       Unresolved local var: PyObject * __pyx_v_name@[???]
                       Unresolved local var: PyObject * __pyx_v_client_type@[???]
                       Unresolved local var: PyObject * __pyx_v_evt@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: int __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_5@[???]
                       Unresolved local var: Py_UCS4 __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: wchar_t __pyx_t_8@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar29 = values[1];
  pPVar24 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var15 = values[1]->ob_type->tp_getattro;
  if (p_Var15 == (getattrofunc)0x0) {
    d = (PyObject *)PyObject_GetAttr();
  }
  else {
    d = (*p_Var15)(values[1],__pyx_mstate_global_static.__pyx_n_s_client_data);
  }
  if (d == (PyObject *)0x0) {
    pPVar11 = (PyObject *)0x0;
    s1 = (PyObject *)0x0;
    key = (PyObject *)0x0;
    iVar8 = 0x3f;
    iVar27 = 0x14a4;
LAB_001229d0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.register_agent",iVar27,
                       iVar8,"moonraker/components/extensions.py");
    pPVar24 = (PyObject *)0x0;
    if (d != (PyObject *)0x0) {
LAB_00122ad8:
      lVar25 = d->ob_refcnt + -1;
      d->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        pPVar24 = (PyObject *)0x0;
LAB_00122aec:
        (*d->ob_type->tp_dealloc)(d);
      }
      else {
        pPVar24 = (PyObject *)0x0;
      }
    }
    if ((key != (PyObject *)0x0) &&
       (lVar25 = key->ob_refcnt + -1, key->ob_refcnt = lVar25, lVar25 == 0)) {
LAB_00122a00:
      (*key->ob_type->tp_dealloc)(key);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    if (s1 != (PyObject *)0x0) goto LAB_00122a14;
  }
  else {
    if (d->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      key = __Pyx_PyDict_GetItem(d,__pyx_mstate_global_static.__pyx_n_u_name);
    }
    else {
      key = (PyObject *)PyObject_GetItem();
    }
    if (key == (PyObject *)0x0) {
      pPVar11 = (PyObject *)0x0;
      s1 = (PyObject *)0x0;
      iVar8 = 0x40;
      iVar27 = 0x14b0;
      goto LAB_001229d0;
    }
    if (d->ob_type == (_typeobject *)PTR_PyDict_Type_00143f60) {
      s1 = __Pyx_PyDict_GetItem(d,__pyx_mstate_global_static.__pyx_n_u_type);
    }
    else {
      s1 = (PyObject *)PyObject_GetItem();
    }
    if (s1 == (PyObject *)0x0) {
      pPVar11 = (PyObject *)0x0;
      iVar8 = 0x41;
      iVar27 = 0x14bc;
      goto LAB_001229d0;
    }
    iVar8 = __Pyx_PyUnicode_Equals(s1,__pyx_mstate_global_static.__pyx_n_u_agent,3);
    pPVar10 = __pyx_dict_cached_value_17024;
    if (iVar8 < 0) {
      pPVar11 = (PyObject *)0x0;
      iVar8 = 0x42;
      iVar27 = 0x14c8;
      goto LAB_001229d0;
    }
    if (iVar8 != 0) {
      pPVar19 = __Pyx_PyObject_GetAttrStr(pPVar24,__pyx_mstate_global_static.__pyx_n_s_server);
      if (pPVar19 == (PyObject *)0x0) {
        iVar8 = 0x43;
        iVar27 = 0x14d2;
        pPVar11 = (PyObject *)0x0;
        goto LAB_001229d0;
      }
      pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar19,__pyx_mstate_global_static.__pyx_n_s_error);
      if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar25 = pPVar19->ob_refcnt + -1;
        pPVar19->ob_refcnt = lVar25;
        if (lVar25 == 0) {
          (*pPVar19->ob_type->tp_dealloc)(pPVar19);
        }
        pPVar19 = (PyObject *)PyTuple_New(3);
        pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_Cannot_register_client_type;
        if (pPVar19 == (PyObject *)0x0) {
          iVar27 = 0x44;
          iVar8 = 0x14df;
          pPVar9 = (PyObject *)0x0;
        }
        else {
          p_Var26 = s1->ob_type;
          bVar6 = p_Var26 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
          (__pyx_mstate_global_static.__pyx_kp_u_Cannot_register_client_type)->ob_refcnt =
               (__pyx_mstate_global_static.__pyx_kp_u_Cannot_register_client_type)->ob_refcnt + 1;
          pPVar19[1].ob_type = (_typeobject *)pPVar24;
          if (bVar6) {
            s1->ob_refcnt = s1->ob_refcnt + 1;
            pPVar24 = s1;
          }
          else {
            if ((p_Var26 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
               (p_Var26 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
              pPVar24 = (*p_Var26->tp_repr)(s1);
            }
            else {
              pPVar24 = (PyObject *)
                        PyObject_Format(s1,__pyx_mstate_global_static.__pyx_empty_unicode);
            }
            if (pPVar24 == (PyObject *)0x0) {
              pPVar11 = (PyObject *)0x0;
              iVar27 = 0x44;
              iVar8 = 0x14e7;
              pPVar9 = (PyObject *)0x0;
              goto LAB_001230d0;
            }
          }
          bVar2 = (byte)pPVar24[2].ob_refcnt;
          pPVar29 = (PyObject *)0x7f;
          if ((bVar2 >> 6 & 1) == 0) {
            bVar2 = bVar2 & 0x1c;
            pPVar29 = (PyObject *)0xff;
            if (bVar2 != 4) {
              uVar21 = 0xffff;
              if (bVar2 != 8) {
                uVar21 = 0x10ffff;
              }
              pPVar29 = (PyObject *)(ulong)uVar21;
            }
          }
          lVar25 = pPVar24[1].ob_refcnt;
          pPVar19[2].ob_refcnt = (Py_ssize_t)pPVar24;
          pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_as_an_agent;
          (__pyx_mstate_global_static.__pyx_kp_u_as_an_agent)->ob_refcnt =
               (__pyx_mstate_global_static.__pyx_kp_u_as_an_agent)->ob_refcnt + 1;
          pPVar19[2].ob_type = (_typeobject *)pPVar24;
          pPVar24 = __Pyx_PyUnicode_Join(pPVar19,3,lVar25 + 0x2a,(Py_UCS4)pPVar29);
          if (pPVar24 == (PyObject *)0x0) {
            pPVar11 = (PyObject *)0x0;
            iVar27 = 0x44;
            iVar8 = 0x14f2;
            pPVar9 = (PyObject *)0x0;
            goto LAB_001230d0;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar25 = pPVar19->ob_refcnt + -1;
          pPVar19->ob_refcnt = lVar25;
          if (lVar25 == 0) {
            (*pPVar19->ob_type->tp_dealloc)(pPVar19);
          }
          p_Var26 = pPVar10->ob_type;
          if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (p_Var14 = pPVar10[1].ob_type, p_Var14 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar11 = (PyObject *)pPVar10[1].ob_refcnt;
            (p_Var14->ob_base).ob_base.ob_refcnt = (p_Var14->ob_base).ob_base.ob_refcnt + 1;
            pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar25 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar25;
            if (lVar25 == 0) {
              (*p_Var26->tp_dealloc)(pPVar10);
            }
            __pyx_pyargnames[0] = (PyObject **)p_Var14;
            __pyx_pyargnames[1] = (PyObject **)pPVar24;
            pPVar19 = __Pyx_PyObject_FastCallDict(pPVar11,(PyObject **)__pyx_pyargnames,2,pPVar29);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar25 = (p_Var14->ob_base).ob_base.ob_refcnt + -1;
            (p_Var14->ob_base).ob_base.ob_refcnt = lVar25;
            pPVar10 = pPVar11;
            if (lVar25 == 0) {
              (*((p_Var14->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var14);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)pPVar24;
            pPVar19 = __Pyx_PyObject_FastCallDict
                                (pPVar10,(PyObject **)(__pyx_pyargnames + 1),1,pPVar29);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar25 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar25;
          if (lVar25 == 0) {
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
          iVar27 = 0x43;
          iVar8 = 0x1508;
          pPVar9 = (PyObject *)0x0;
          if (pPVar19 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar25 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar25;
            if (lVar25 == 0) {
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
            }
            __Pyx_Raise(pPVar19,(PyObject *)0x0,(PyObject *)0x0,pPVar29);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar25 = pPVar19->ob_refcnt + -1;
            pPVar19->ob_refcnt = lVar25;
            if (lVar25 == 0) {
              pPVar11 = (PyObject *)0x0;
              iVar27 = 0x150e;
              (*pPVar19->ob_type->tp_dealloc)(pPVar19);
              iVar8 = 0x43;
            }
            else {
              pPVar11 = (PyObject *)0x0;
              iVar8 = 0x43;
              iVar27 = 0x150e;
            }
            goto LAB_001229d0;
          }
        }
        goto LAB_00122a68;
      }
      pPVar9 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      iVar27 = 0x43;
      iVar8 = 0x14d4;
      goto LAB_001230d0;
    }
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17023) {
      if (__pyx_dict_cached_value_17024 == (PyObject *)0x0) {
        pPVar10 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
        goto LAB_00122ee8;
      }
      __pyx_dict_cached_value_17024->ob_refcnt = __pyx_dict_cached_value_17024->ob_refcnt + 1;
    }
    else {
      pPVar10 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_logging,
                           (uint64_t *)&__pyx_dict_version_17023,&__pyx_dict_cached_value_17024);
LAB_00122ee8:
      if (pPVar10 == (PyObject *)0x0) {
        iVar8 = 0x47;
        iVar27 = 0x1520;
        pPVar11 = (PyObject *)0x0;
        goto LAB_001229d0;
      }
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar10->ob_type->tp_getattro;
    if (p_Var15 == (getattrofunc)0x0) {
      pPVar9 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar9 = (*p_Var15)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_info);
    }
    if (pPVar9 == (PyObject *)0x0) {
      iVar27 = 0x47;
      iVar8 = 0x1522;
      goto LAB_00122a68;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar10 = (PyObject *)PyTuple_New(4);
    pPVar11 = __pyx_mstate_global_static.__pyx_kp_u_register;
    if (pPVar10 == (PyObject *)0x0) {
      iVar27 = 0x47;
      iVar8 = 0x1525;
LAB_00122f30:
      pPVar11 = (PyObject *)0x0;
      pPVar10 = pPVar9;
LAB_00122a9c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
        __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.register_agent",iVar8,
                           iVar27,"moonraker/components/extensions.py");
      }
      else {
LAB_00122bf0:
        __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.register_agent",iVar8,
                           iVar27,"moonraker/components/extensions.py");
      }
      goto LAB_00122ad8;
    }
    p_Var26 = key->ob_type;
    bVar6 = p_Var26 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
    (__pyx_mstate_global_static.__pyx_kp_u_register)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_kp_u_register)->ob_refcnt + 1;
    pPVar10[1].ob_type = (_typeobject *)pPVar11;
    if (bVar6) {
      key->ob_refcnt = key->ob_refcnt + 1;
      pPVar11 = key;
    }
    else {
      if ((p_Var26 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
         (p_Var26 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
        pPVar11 = (*p_Var26->tp_repr)(key);
      }
      else {
        pPVar11 = (PyObject *)PyObject_Format(key,__pyx_mstate_global_static.__pyx_empty_unicode);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar27 = 0x47;
        iVar8 = 0x152d;
        goto LAB_00122a68;
      }
    }
    bVar2 = (byte)pPVar11[2].ob_refcnt;
    uVar21 = 0x7f;
    if ((bVar2 >> 6 & 1) == 0) {
      bVar2 = bVar2 & 0x1c;
      uVar21 = 0xff;
      if ((bVar2 != 4) && (uVar21 = 0xffff, bVar2 != 8)) {
        uVar21 = 0x10ffff;
      }
    }
    p_Var26 = s1->ob_type;
    lVar25 = pPVar11[1].ob_refcnt;
    pPVar10[2].ob_refcnt = (Py_ssize_t)pPVar11;
    pPVar11 = __pyx_mstate_global_static.__pyx_kp_u_type_2;
    bVar6 = p_Var26 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
    (__pyx_mstate_global_static.__pyx_kp_u_type_2)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_kp_u_type_2)->ob_refcnt + 1;
    pPVar10[2].ob_type = (_typeobject *)pPVar11;
    if (bVar6) {
      s1->ob_refcnt = s1->ob_refcnt + 1;
      pPVar11 = s1;
    }
    else {
      if ((p_Var26 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
         (p_Var26 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
        pPVar11 = (*p_Var26->tp_repr)(s1);
      }
      else {
        pPVar11 = (PyObject *)PyObject_Format(s1,__pyx_mstate_global_static.__pyx_empty_unicode);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar27 = 0x47;
        iVar8 = 0x1538;
        goto LAB_00122a68;
      }
    }
    bVar2 = (byte)pPVar11[2].ob_refcnt;
    uVar23 = 0x7f;
    if ((bVar2 >> 6 & 1) == 0) {
      bVar2 = bVar2 & 0x1c;
      uVar23 = 0xff;
      if ((bVar2 != 4) && (uVar23 = 0xffff, bVar2 != 8)) {
        uVar23 = 0x10ffff;
      }
    }
    lVar16 = pPVar11[1].ob_refcnt;
    pPVar10[3].ob_refcnt = (Py_ssize_t)pPVar11;
    if (uVar21 < uVar23) {
      uVar21 = uVar23;
    }
    pPVar19 = (PyObject *)(ulong)uVar21;
    pPVar11 = __Pyx_PyUnicode_Join(pPVar10,4,lVar25 + 0x12 + lVar16,uVar21);
    if (pPVar11 == (PyObject *)0x0) {
      iVar27 = 0x47;
      iVar8 = 0x153f;
      goto LAB_00122a68;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    p_Var26 = pPVar9->ob_type;
    if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
       (p_Var14 = pPVar9[1].ob_type, p_Var14 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar10 = (PyObject *)pPVar9[1].ob_refcnt;
      (p_Var14->ob_base).ob_base.ob_refcnt = (p_Var14->ob_base).ob_base.ob_refcnt + 1;
      pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*p_Var26->tp_dealloc)(pPVar9);
      }
      __pyx_pyargnames[0] = (PyObject **)p_Var14;
      __pyx_pyargnames[1] = (PyObject **)pPVar11;
      pPVar19 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)__pyx_pyargnames,2,pPVar19);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = (p_Var14->ob_base).ob_base.ob_refcnt + -1;
      (p_Var14->ob_base).ob_base.ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*((p_Var14->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var14);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)pPVar11;
      pPVar19 = __Pyx_PyObject_FastCallDict(pPVar9,(PyObject **)(__pyx_pyargnames + 1),1,pPVar19);
      pPVar10 = pPVar9;
    }
    local_40 = (PyObject **)__pyx_pyargnames;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar19 == (PyObject *)0x0) {
      iVar8 = 0x1555;
      iVar27 = 0x47;
      pPVar11 = (PyObject *)0x0;
      goto LAB_00122a9c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
      lVar25 = pPVar19->ob_refcnt + -1;
      pPVar19->ob_refcnt = lVar25;
      if (lVar25 == 0) goto LAB_00122824;
LAB_00121d5c:
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17036)
      goto LAB_00121d78;
LAB_00122ba0:
      kwargs_00 = &__pyx_mstate_global_static;
      pPVar9 = __Pyx__GetModuleGlobalName
                         (__pyx_mstate_global_static.__pyx_n_s_logging,
                          (uint64_t *)&__pyx_dict_version_17036,&__pyx_dict_cached_value_17037);
LAB_00122bb4:
      if (pPVar9 == (PyObject *)0x0) {
        iVar8 = 0x48;
        iVar27 = 0x1562;
        pPVar11 = (PyObject *)0x0;
        goto LAB_001229d0;
      }
    }
    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar19->ob_refcnt + -1;
      pPVar19->ob_refcnt = lVar25;
      if (lVar25 != 0) goto LAB_00121d5c;
LAB_00122824:
      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_17036)
      goto LAB_00122ba0;
LAB_00121d78:
      pPVar9 = __pyx_dict_cached_value_17037;
      kwargs_00 = &__pyx_mstate_global_static;
      if (__pyx_dict_cached_value_17037 == (PyObject *)0x0) {
        pPVar9 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
        goto LAB_00122bb4;
      }
      __pyx_dict_cached_value_17037->ob_refcnt = __pyx_dict_cached_value_17037->ob_refcnt + 1;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar9->ob_type->tp_getattro;
    if (p_Var15 == (getattrofunc)0x0) {
      pPVar19 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar19 = (*p_Var15)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_info);
    }
    if (pPVar19 == (PyObject *)0x0) {
      iVar27 = 0x48;
      iVar8 = 0x1564;
      goto LAB_00122f30;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
    p_Var26 = d->ob_type;
    if (p_Var26 == (_typeobject *)PTR_PyUnicode_Type_00143fb0) {
      d->ob_refcnt = d->ob_refcnt + 1;
      pPVar9 = d;
    }
    else {
      if ((p_Var26 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
         (p_Var26 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
        pPVar9 = (*p_Var26->tp_repr)(d);
      }
      else {
        pPVar9 = (PyObject *)PyObject_Format(d,__pyx_mstate_global_static.__pyx_empty_unicode);
      }
      if (pPVar9 == (PyObject *)0x0) {
        pPVar11 = (PyObject *)0x0;
        pPVar9 = (PyObject *)0x0;
        iVar27 = 0x48;
        iVar8 = 0x1567;
        pPVar10 = (PyObject *)0x0;
        goto LAB_001230d0;
      }
    }
    ppPVar12 = (PyObject **)
               PyUnicode_Concat(__pyx_mstate_global_static.__pyx_kp_u_register_data,pPVar9);
    if (ppPVar12 == (PyObject **)0x0) {
      pPVar11 = (PyObject *)0x0;
      iVar27 = 0x48;
      iVar8 = 0x1569;
      pPVar10 = (PyObject *)0x0;
      goto LAB_001230d0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
    p_Var26 = pPVar19->ob_type;
    if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
       (p_Var14 = pPVar19[1].ob_type, p_Var14 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar10 = (PyObject *)pPVar19[1].ob_refcnt;
      (p_Var14->ob_base).ob_base.ob_refcnt = (p_Var14->ob_base).ob_base.ob_refcnt + 1;
      pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar19->ob_refcnt + -1;
      pPVar19->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*p_Var26->tp_dealloc)(pPVar19);
      }
      __pyx_pyargnames[0] = (PyObject **)p_Var14;
      __pyx_pyargnames[1] = ppPVar12;
      pPVar11 = __Pyx_PyObject_FastCallDict(pPVar10,local_40,2,(PyObject *)kwargs_00);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = (p_Var14->ob_base).ob_base.ob_refcnt + -1;
      (p_Var14->ob_base).ob_base.ob_refcnt = lVar25;
      pPVar19 = pPVar10;
      if (lVar25 == 0) {
        (*((p_Var14->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var14);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = ppPVar12;
      pPVar11 = __Pyx_PyObject_FastCallDict
                          (pPVar19,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)kwargs_00);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar10 = (PyObject *)((long)&(*ppPVar12)[-1].ob_type + 7);
    *ppPVar12 = pPVar10;
    if (pPVar10 == (PyObject *)0x0) {
      (*(code *)ppPVar12[1][3].ob_refcnt)(ppPVar12);
    }
    if (pPVar11 == (PyObject *)0x0) {
      iVar27 = 0x48;
      iVar8 = 0x157f;
      pPVar11 = (PyObject *)0x0;
LAB_001231a0:
      pPVar9 = (PyObject *)0x0;
      pPVar10 = (PyObject *)0x0;
      goto LAB_001230d0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar19->ob_refcnt + -1;
    pPVar19->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar24->ob_type->tp_getattro;
    if (p_Var15 == (getattrofunc)0x0) {
      pPVar10 = (PyObject *)PyObject_GetAttr(pPVar24);
    }
    else {
      pPVar10 = (*p_Var15)(pPVar24,__pyx_mstate_global_static.__pyx_n_s_agents);
    }
    if (pPVar10 == (PyObject *)0x0) {
      iVar8 = 0x4a;
      iVar27 = 0x158c;
      pPVar11 = (PyObject *)0x0;
      goto LAB_001229d0;
    }
                    /* Unresolved local var: int result@[???] */
    iVar8 = PySequence_Contains(pPVar10,key);
    if (iVar8 < 0) {
      iVar27 = 0x158e;
      iVar8 = 0x4a;
      goto LAB_00122bd0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar19 = __pyx_dict_cached_value_17051;
    if (iVar8 == 1) {
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17050) {
        if (__pyx_dict_cached_value_17051 == (PyObject *)0x0) {
          pPVar19 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
          goto LAB_001231f8;
        }
        __pyx_dict_cached_value_17051->ob_refcnt = __pyx_dict_cached_value_17051->ob_refcnt + 1;
      }
      else {
        pPVar19 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_logging,
                             (uint64_t *)&__pyx_dict_version_17050,&__pyx_dict_cached_value_17051);
LAB_001231f8:
        if (pPVar19 == (PyObject *)0x0) {
          iVar8 = 0x4b;
          iVar27 = 0x1599;
          pPVar11 = (PyObject *)0x0;
          goto LAB_001229d0;
        }
      }
      pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar19,__pyx_mstate_global_static.__pyx_n_s_warning);
      if (pPVar10 == (PyObject *)0x0) {
        pPVar9 = (PyObject *)0x0;
        pPVar11 = (PyObject *)0x0;
        iVar27 = 0x4b;
        iVar8 = 0x159b;
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar25 = pPVar19->ob_refcnt + -1;
        pPVar19->ob_refcnt = lVar25;
        if (lVar25 == 0) {
          (*pPVar19->ob_type->tp_dealloc)(pPVar19);
        }
        pPVar19 = (PyObject *)PyTuple_New(3);
        pPVar11 = __pyx_mstate_global_static.__pyx_kp_u_register_2;
        if (pPVar19 == (PyObject *)0x0) {
          iVar27 = 0x4b;
          iVar8 = 0x159e;
          pPVar9 = (PyObject *)0x0;
          goto LAB_00122a68;
        }
        p_Var26 = key->ob_type;
        bVar6 = p_Var26 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
        (__pyx_mstate_global_static.__pyx_kp_u_register_2)->ob_refcnt =
             (__pyx_mstate_global_static.__pyx_kp_u_register_2)->ob_refcnt + 1;
        pPVar19[1].ob_type = (_typeobject *)pPVar11;
        if (bVar6) {
          key->ob_refcnt = key->ob_refcnt + 1;
          pPVar11 = key;
        }
        else {
          if ((p_Var26 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
             (p_Var26 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
            pPVar11 = (*p_Var26->tp_repr)(key);
          }
          else {
            pPVar11 = (PyObject *)
                      PyObject_Format(key,__pyx_mstate_global_static.__pyx_empty_unicode);
          }
          if (pPVar11 == (PyObject *)0x0) {
            pPVar11 = (PyObject *)0x0;
            iVar27 = 0x4b;
            iVar8 = 0x15a6;
            pPVar9 = (PyObject *)0x0;
            goto LAB_001230d0;
          }
        }
        bVar2 = (byte)pPVar11[2].ob_refcnt;
        pPVar9 = (PyObject *)0x7f;
        if ((bVar2 >> 6 & 1) == 0) {
          bVar2 = bVar2 & 0x1c;
          pPVar9 = (PyObject *)0xff;
          if (bVar2 != 4) {
            uVar21 = 0xffff;
            if (bVar2 != 8) {
              uVar21 = 0x10ffff;
            }
            pPVar9 = (PyObject *)(ulong)uVar21;
          }
        }
        lVar25 = pPVar11[1].ob_refcnt;
        pPVar19[2].ob_refcnt = (Py_ssize_t)pPVar11;
        pPVar11 = __pyx_mstate_global_static.__pyx_kp_u_aleady_esist_replace;
        (__pyx_mstate_global_static.__pyx_kp_u_aleady_esist_replace)->ob_refcnt =
             (__pyx_mstate_global_static.__pyx_kp_u_aleady_esist_replace)->ob_refcnt + 1;
        pPVar19[2].ob_type = (_typeobject *)pPVar11;
        pPVar11 = __Pyx_PyUnicode_Join(pPVar19,3,lVar25 + 0x21,(Py_UCS4)pPVar9);
        if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar25 = pPVar19->ob_refcnt + -1;
          pPVar19->ob_refcnt = lVar25;
          if (lVar25 == 0) {
            (*pPVar19->ob_type->tp_dealloc)(pPVar19);
          }
          p_Var26 = pPVar10->ob_type;
          if (p_Var26 == (_typeobject *)PTR_PyMethod_Type_00143ea0) {
            p_Var14 = pPVar10[1].ob_type;
            pPVar9 = (PyObject *)0x0;
            if (p_Var14 == (_typeobject *)0x0) goto LAB_00122058;
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar9 = (PyObject *)pPVar10[1].ob_refcnt;
            (p_Var14->ob_base).ob_base.ob_refcnt = (p_Var14->ob_base).ob_base.ob_refcnt + 1;
            pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar25 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar25;
            if (lVar25 == 0) {
              (*p_Var26->tp_dealloc)(pPVar10);
            }
            __pyx_pyargnames[0] = (PyObject **)p_Var14;
            __pyx_pyargnames[1] = (PyObject **)pPVar11;
            pPVar19 = __Pyx_PyObject_FastCallDict(pPVar9,local_40,2,(PyObject *)p_Var14);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar25 = (p_Var14->ob_base).ob_base.ob_refcnt + -1;
            (p_Var14->ob_base).ob_base.ob_refcnt = lVar25;
            pPVar10 = pPVar9;
            if (lVar25 == 0) {
              (*((p_Var14->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var14);
            }
          }
          else {
LAB_00122058:
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)pPVar11;
            pPVar19 = __Pyx_PyObject_FastCallDict
                                (pPVar10,(PyObject **)(__pyx_pyargnames + 1),1,pPVar9);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar25 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar25;
          if (lVar25 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          if (pPVar19 == (PyObject *)0x0) {
            iVar27 = 0x4b;
            iVar8 = 0x15c7;
            pPVar9 = (PyObject *)0x0;
            goto LAB_00122a68;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar25 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar25;
          if (lVar25 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar25 = pPVar19->ob_refcnt + -1;
          pPVar19->ob_refcnt = lVar25;
          if (lVar25 == 0) {
            (*pPVar19->ob_type->tp_dealloc)(pPVar19);
          }
          pPVar10 = __Pyx_PyObject_GetAttrStr
                              (pPVar24,__pyx_mstate_global_static.__pyx_n_s_remove_agent);
          if (pPVar10 == (PyObject *)0x0) {
            iVar8 = 0x4c;
            iVar27 = 0x15d4;
            pPVar11 = (PyObject *)0x0;
            goto LAB_001229d0;
          }
          pPVar9 = __Pyx_PyObject_GetAttrStr(pPVar24,__pyx_mstate_global_static.__pyx_n_s_agents);
          if (pPVar9 == (PyObject *)0x0) {
            iVar27 = 0x4c;
            iVar8 = 0x15d6;
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???]
                       Unresolved local var: PyMappingMethods * mm@[???]
                       Unresolved local var: PySequenceMethods * sm@[???] */
            p_Var26 = pPVar9->ob_type;
            if ((p_Var26->tp_as_mapping == (PyMappingMethods *)0x0) ||
               (p_Var17 = p_Var26->tp_as_mapping->mp_subscript, p_Var17 == (binaryfunc)0x0)) {
              if ((p_Var26->tp_as_sequence == (PySequenceMethods *)0x0) ||
                 (p_Var26->tp_as_sequence->sq_item == (ssizeargfunc)0x0)) {
                pPVar11 = __Pyx_PyObject_GetItem_Slow(pPVar9,key);
              }
              else {
                pPVar11 = __Pyx_PyObject_GetIndex(pPVar9,key);
              }
            }
            else {
              pPVar11 = (*p_Var17)(pPVar9,key);
            }
            if (pPVar11 == (PyObject *)0x0) {
              iVar27 = 0x4c;
              iVar8 = 0x15d8;
            }
            else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar25 = pPVar9->ob_refcnt + -1;
              pPVar9->ob_refcnt = lVar25;
              if (lVar25 == 0) {
                (*pPVar9->ob_type->tp_dealloc)(pPVar9);
              }
              p_Var14 = pPVar10->ob_type;
              if (p_Var14 == (_typeobject *)PTR_PyMethod_Type_00143ea0) {
                kwargs = pPVar10[1].ob_type;
                p_Var26 = (_typeobject *)0x0;
                if (kwargs == (_typeobject *)0x0) goto LAB_00123298;
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar9 = (PyObject *)pPVar10[1].ob_refcnt;
                (kwargs->ob_base).ob_base.ob_refcnt = (kwargs->ob_base).ob_base.ob_refcnt + 1;
                pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar25 = pPVar10->ob_refcnt + -1;
                pPVar10->ob_refcnt = lVar25;
                if (lVar25 == 0) {
                  (*p_Var14->tp_dealloc)(pPVar10);
                }
                __pyx_pyargnames[0] = (PyObject **)kwargs;
                __pyx_pyargnames[1] = (PyObject **)pPVar11;
                pPVar19 = __Pyx_PyObject_FastCallDict(pPVar9,local_40,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar25 = (kwargs->ob_base).ob_base.ob_refcnt + -1;
                (kwargs->ob_base).ob_base.ob_refcnt = lVar25;
                pPVar10 = pPVar9;
                if (lVar25 == 0) {
                  (*((kwargs->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)kwargs);
                }
              }
              else {
LAB_00123298:
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = (PyObject **)pPVar11;
                pPVar19 = __Pyx_PyObject_FastCallDict
                                    (pPVar10,(PyObject **)(__pyx_pyargnames + 1),1,
                                     (PyObject *)p_Var26);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar25 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar25;
              if (lVar25 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
              if (pPVar19 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar25 = pPVar10->ob_refcnt + -1;
                pPVar10->ob_refcnt = lVar25;
                if (lVar25 == 0) {
                  (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar25 = pPVar19->ob_refcnt + -1;
                pPVar19->ob_refcnt = lVar25;
                if (lVar25 == 0) {
                  (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                }
                goto LAB_00122254;
              }
              iVar27 = 0x4c;
              iVar8 = 0x15ee;
              pPVar9 = (PyObject *)0x0;
            }
          }
          goto LAB_00122a68;
        }
        pPVar11 = (PyObject *)0x0;
        iVar27 = 0x4b;
        iVar8 = 0x15b1;
        pPVar9 = (PyObject *)0x0;
      }
      goto LAB_001230d0;
    }
LAB_00122254:
    pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar24,__pyx_mstate_global_static.__pyx_n_s_agents);
    if (pPVar10 == (PyObject *)0x0) {
      iVar8 = 0x4e;
      iVar27 = 0x1604;
      pPVar11 = (PyObject *)0x0;
      goto LAB_001229d0;
    }
    iVar8 = PyObject_SetItem(pPVar10,key,pPVar29);
    if (iVar8 < 0) {
      iVar27 = 0x1606;
      iVar8 = 0x4e;
      goto LAB_00122bd0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar10 = __pyx_dict_cached_value_17075;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17074) {
      if (__pyx_dict_cached_value_17075 == (PyObject *)0x0) {
        pPVar10 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
        goto LAB_00123304;
      }
      __pyx_dict_cached_value_17075->ob_refcnt = __pyx_dict_cached_value_17075->ob_refcnt + 1;
    }
    else {
      pPVar10 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_logging,
                           (uint64_t *)&__pyx_dict_version_17074,&__pyx_dict_cached_value_17075);
LAB_00123304:
      if (pPVar10 == (PyObject *)0x0) {
        iVar8 = 0x4f;
        iVar27 = 0x1610;
        pPVar11 = (PyObject *)0x0;
        goto LAB_001229d0;
      }
    }
    pPVar19 = __Pyx_PyObject_GetAttrStr(pPVar10,__pyx_mstate_global_static.__pyx_n_s_info);
    if (pPVar19 == (PyObject *)0x0) {
      iVar27 = 0x4f;
      iVar8 = 0x1612;
      pPVar9 = (PyObject *)0x0;
LAB_00122a68:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      pPVar11 = (PyObject *)0x0;
LAB_00122a78:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
      }
LAB_00122a98:
      pPVar10 = pPVar9;
      if (pPVar9 != (PyObject *)0x0) goto LAB_00122a9c;
      goto LAB_00122bf0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar10 = (PyObject *)PyTuple_New(3);
    pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_register_2;
    if (pPVar10 == (PyObject *)0x0) {
      pPVar11 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      iVar27 = 0x4f;
      iVar8 = 0x1615;
LAB_001230d0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar19->ob_refcnt + -1;
      pPVar19->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*pPVar19->ob_type->tp_dealloc)(pPVar19);
      }
      if (pPVar10 != (PyObject *)0x0) goto LAB_00122a78;
      goto LAB_00122a98;
    }
    p_Var26 = key->ob_type;
    bVar6 = p_Var26 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
    (__pyx_mstate_global_static.__pyx_kp_u_register_2)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_kp_u_register_2)->ob_refcnt + 1;
    pPVar10[1].ob_type = (_typeobject *)pPVar24;
    if (bVar6) {
      key->ob_refcnt = key->ob_refcnt + 1;
      pPVar24 = key;
    }
    else {
      if ((p_Var26 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
         (p_Var26 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
        pPVar24 = (*p_Var26->tp_repr)(key);
      }
      else {
        pPVar24 = (PyObject *)PyObject_Format(key,__pyx_mstate_global_static.__pyx_empty_unicode);
      }
      if (pPVar24 == (PyObject *)0x0) {
        pPVar11 = (PyObject *)0x0;
        iVar27 = 0x4f;
        iVar8 = 0x161d;
        pPVar9 = (PyObject *)0x0;
        goto LAB_001230d0;
      }
    }
    bVar2 = (byte)pPVar24[2].ob_refcnt;
    pPVar11 = (PyObject *)0x7f;
    if ((bVar2 >> 6 & 1) == 0) {
      bVar2 = bVar2 & 0x1c;
      pPVar11 = (PyObject *)0xff;
      if (bVar2 != 4) {
        uVar21 = 0xffff;
        if (bVar2 != 8) {
          uVar21 = 0x10ffff;
        }
        pPVar11 = (PyObject *)(ulong)uVar21;
      }
    }
    lVar25 = pPVar24[1].ob_refcnt;
    pPVar10[2].ob_refcnt = (Py_ssize_t)pPVar24;
    pPVar24 = __pyx_mstate_global_static.__pyx_kp_u_register_success;
    (__pyx_mstate_global_static.__pyx_kp_u_register_success)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_kp_u_register_success)->ob_refcnt + 1;
    pPVar10[2].ob_type = (_typeobject *)pPVar24;
    pPVar24 = __Pyx_PyUnicode_Join(pPVar10,3,lVar25 + 0x1c,(Py_UCS4)pPVar11);
    if (pPVar24 == (PyObject *)0x0) {
      pPVar11 = (PyObject *)0x0;
      iVar27 = 0x4f;
      iVar8 = 0x1628;
      pPVar9 = (PyObject *)0x0;
      goto LAB_001230d0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    p_Var26 = pPVar19->ob_type;
    if (p_Var26 == (_typeobject *)PTR_PyMethod_Type_00143ea0) {
      p_Var14 = pPVar19[1].ob_type;
      pPVar11 = (PyObject *)0x0;
      if (p_Var14 == (_typeobject *)0x0) goto LAB_001223ec;
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar10 = (PyObject *)pPVar19[1].ob_refcnt;
      (p_Var14->ob_base).ob_base.ob_refcnt = (p_Var14->ob_base).ob_base.ob_refcnt + 1;
      pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar19->ob_refcnt + -1;
      pPVar19->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*p_Var26->tp_dealloc)(pPVar19);
      }
      __pyx_pyargnames[0] = (PyObject **)p_Var14;
      __pyx_pyargnames[1] = (PyObject **)pPVar24;
      pPVar11 = __Pyx_PyObject_FastCallDict(pPVar10,local_40,2,(PyObject *)p_Var14);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = (p_Var14->ob_base).ob_base.ob_refcnt + -1;
      (p_Var14->ob_base).ob_base.ob_refcnt = lVar25;
      pPVar19 = pPVar10;
      if (lVar25 == 0) {
        (*((p_Var14->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var14);
      }
    }
    else {
LAB_001223ec:
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)pPVar24;
      pPVar11 = __Pyx_PyObject_FastCallDict(pPVar19,(PyObject **)(__pyx_pyargnames + 1),1,pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar24->ob_refcnt + -1;
    pPVar24->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar24->ob_type->tp_dealloc)(pPVar24);
    }
    if (pPVar11 == (PyObject *)0x0) {
      iVar27 = 0x4f;
      iVar8 = 0x163e;
      pPVar11 = (PyObject *)0x0;
      goto LAB_001231a0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar19->ob_refcnt + -1;
    pPVar19->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      iVar8 = 0x52;
      iVar27 = 0x164b;
      goto LAB_001229d0;
    }
    iVar8 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_u_agent,key);
    pPVar10 = pPVar11;
    if (iVar8 < 0) {
      iVar27 = 0x164d;
      iVar8 = 0x52;
LAB_00122bd0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        pPVar11 = (PyObject *)0x0;
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
      }
      else {
        pPVar11 = (PyObject *)0x0;
      }
      goto LAB_001229d0;
    }
    iVar8 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_u_event,
                           __pyx_mstate_global_static.__pyx_n_u_connected);
    if (iVar8 < 0) {
      iVar27 = 0x164e;
      iVar8 = 0x52;
      goto LAB_00122bd0;
    }
    iVar8 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_u_data,d);
    if (iVar8 < 0) {
      iVar27 = 0x1657;
      iVar8 = 0x52;
      goto LAB_00122bd0;
    }
    pPVar19 = __Pyx_PyObject_GetAttrStr
                        (pPVar29,__pyx_mstate_global_static.__pyx_n_s_send_notification);
    if (pPVar19 == (PyObject *)0x0) {
      iVar8 = 0x56;
      iVar27 = 0x1662;
      goto LAB_001229d0;
    }
    ppPVar12 = (PyObject **)PyList_New(1);
    puVar3 = PTR_PyMethod_Type_00143ea0;
    if (ppPVar12 == (PyObject **)0x0) {
      pPVar9 = (PyObject *)0x0;
      iVar27 = 0x56;
      iVar8 = 0x1664;
      pPVar10 = (PyObject *)0x0;
      goto LAB_001230d0;
    }
    pPVar24 = ppPVar12[3];
    p_Var26 = pPVar19->ob_type;
    pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
    pPVar24->ob_refcnt = (Py_ssize_t)pPVar11;
    if ((p_Var26 == (_typeobject *)puVar3) &&
       (p_Var14 = pPVar19[1].ob_type, p_Var14 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar29 = (PyObject *)pPVar19[1].ob_refcnt;
      (p_Var14->ob_base).ob_base.ob_refcnt = (p_Var14->ob_base).ob_base.ob_refcnt + 1;
      pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = pPVar19->ob_refcnt + -1;
      pPVar19->ob_refcnt = lVar25;
      if (lVar25 == 0) {
        (*p_Var26->tp_dealloc)(pPVar19);
      }
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_agent_event;
      __pyx_pyargnames[0] = (PyObject **)p_Var14;
      __pyx_pyargnames[2] = ppPVar12;
      pPVar24 = __Pyx_PyObject_FastCallDict
                          (pPVar29,local_40,3,__pyx_mstate_global_static.__pyx_n_u_agent_event);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar25 = (p_Var14->ob_base).ob_base.ob_refcnt + -1;
      (p_Var14->ob_base).ob_base.ob_refcnt = lVar25;
      pPVar19 = pPVar29;
      if (lVar25 == 0) {
        (*((p_Var14->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var14);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_agent_event;
      __pyx_pyargnames[2] = ppPVar12;
      pPVar24 = __Pyx_PyObject_FastCallDict
                          (pPVar19,(PyObject **)(__pyx_pyargnames + 1),2,
                           __pyx_mstate_global_static.__pyx_n_u_agent_event);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar29 = (PyObject *)((long)&(*ppPVar12)[-1].ob_type + 7);
    *ppPVar12 = pPVar29;
    if (pPVar29 == (PyObject *)0x0) {
      (*(code *)ppPVar12[1][3].ob_refcnt)(ppPVar12);
    }
    if (pPVar24 == (PyObject *)0x0) {
      iVar27 = 0x56;
      iVar8 = 0x167c;
      goto LAB_001231a0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar19->ob_refcnt + -1;
    pPVar19->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = pPVar24->ob_refcnt + -1;
    pPVar24->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*pPVar24->ob_type->tp_dealloc)(pPVar24);
    }
    pPVar24 = (PyObject *)PTR__Py_NoneStruct_00143f40;
    *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar25;
    if (lVar25 == 0) goto LAB_00122aec;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = key->ob_refcnt + -1;
    key->ob_refcnt = lVar25;
    if (lVar25 == 0) goto LAB_00122a00;
LAB_00122a14:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar25 = s1->ob_refcnt + -1;
    s1->ob_refcnt = lVar25;
    if (lVar25 == 0) {
      (*s1->ob_type->tp_dealloc)(s1);
    }
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar11 != (PyObject *)0x0) &&
     (lVar25 = pPVar11->ob_refcnt + -1, pPVar11->ob_refcnt = lVar25, lVar25 == 0)) {
    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
  }
LAB_00121aa0:
  if (lVar22 == *(long *)PTR___stack_chk_guard_00143f20) {
    return pPVar24;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar28 = lVar16 + 1;
    if (lVar28 == PVar30) goto LAB_00122950;
    p_Var26 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar16];
    lVar16 = lVar28;
    if ((_typeobject *)pPVar24 == p_Var26) break;
LAB_001226e0:
    bVar6 = pPVar24->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var26->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar28 = lVar16;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar24 != (PyObject *)puVar3) && (bVar6 || p_Var26 != (_typeobject *)puVar3)) {
        plVar13 = (long *)PyObject_RichCompare(pPVar24,p_Var26,2);
        if (plVar13 == (long *)0x0) goto LAB_00122950;
        uVar21 = (uint)(plVar13 == (long *)puVar4);
        if ((plVar13 != (long *)puVar4 && plVar13 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar13 != (long *)puVar3) {
          uVar21 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar18 = *plVar13;
        *plVar13 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_00122940:
        if (uVar21 != 0) {
          if ((int)uVar21 < 0) goto LAB_00122950;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar24[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar24), iVar8 < 0)) ||
         ((-1 < (char)p_Var26->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var26), iVar8 < 0))))
      goto LAB_00122950;
      lVar18 = pPVar24[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar18 == (p_Var26->ob_base).ob_size) &&
         ((pPVar24[1].ob_type == (_typeobject *)p_Var26->tp_name ||
          (_typeobject *)p_Var26->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar24[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar20 = (char *)((ulong)(byte)((byte)pPVar24[2].ob_refcnt >> 2) & 7);
        uVar21 = (uint)pcVar20;
        if (((byte)((byte)p_Var26->tp_basicsize >> 2) & 7) == uVar21) {
          bVar2 = (byte)pPVar24[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var14 = pPVar24[4].ob_type;
          }
          else {
            p_Var14 = (_typeobject *)&pPVar24[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var14 = (_typeobject *)(pPVar24 + 3);
            }
          }
          bVar2 = (byte)p_Var26->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var26->tp_setattr;
          }
          else {
            __s2 = &p_Var26->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var26->tp_dealloc;
            }
          }
          if (uVar21 == 1) {
            uVar21 = (uint)(byte)(p_Var14->ob_base).ob_base.ob_refcnt;
            uVar23 = (uint)*(byte *)__s2;
          }
          else if (uVar21 == 2) {
            uVar21 = (uint)(ushort)(p_Var14->ob_base).ob_base.ob_refcnt;
            uVar23 = (uint)*(ushort *)__s2;
          }
          else {
            uVar21 = (uint)(p_Var14->ob_base).ob_base.ob_refcnt;
            uVar23 = *(uint *)__s2;
          }
          if (uVar23 == uVar21) {
            if (lVar18 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var14,__s2,(long)pcVar20 * lVar18);
              uVar21 = (uint)(iVar8 == 0);
              goto LAB_00122940;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar12[lVar28];
LAB_0012289c:
  if (values[1] == (PyObject *)0x0) {
LAB_00122954:
    lVar25 = PyErr_Occurred();
    if (lVar25 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","register_agent",
                   "exactly",2,"s",1);
      iVar8 = 0x145c;
    }
    else {
      iVar8 = 0x145a;
    }
  }
  else {
    lVar25 = lVar25 + -1;
LAB_00122640:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar25 < 1) ||
       (iVar8 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,ppPVar12,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x12fe70,pcVar20), -1 < iVar8))
    goto LAB_00121ae8;
    iVar8 = 0x1461;
  }
LAB_00121a84:
  pPVar24 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.register_agent",iVar8,0x3e,
                     "moonraker/components/extensions.py");
  goto LAB_00121aa0;
}


/* ================================================================
 * Address: 00125760
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_1__init__
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16ExtensionManager_1__init__
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  byte bVar1;
  Py_ssize_t *pPVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  PyObject *pPVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  undefined1 *puVar12;
  long *plVar13;
  setattrfunc *__s2;
  getattrofunc p_Var14;
  setattrofunc p_Var15;
  __pyx_mstate *p_Var16;
  char *pcVar17;
  uint uVar18;
  long lVar19;
  uint uVar20;
  PyObject *pPVar21;
  long lVar22;
  _typeobject *p_Var23;
  int py_line;
  PyObject *pPVar24;
  _typeobject *p_Var25;
  PyObject **ppPVar26;
  _typeobject *p_Var27;
  _typeobject *func;
  _typeobject *p_Var28;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar19 = *(long *)PTR___stack_chk_guard_00143f20;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_config;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar9 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_001257d0;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_00125868;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar26 = __pyx_args + __pyx_nargs;
  pcVar17 = PTR___stack_chk_guard_00143f20;
  if (__pyx_nargs == 1) {
    pPVar9 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar11 = pPVar9;
LAB_00126850:
    pPVar10 = __pyx_mstate_global_static.__pyx_n_s_config;
    puVar5 = PTR_PyUnicode_Type_00143fb0;
    puVar4 = PTR__Py_TrueStruct_00143f48;
    puVar3 = PTR__Py_NoneStruct_00143f40;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar11) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var23) {
        values[1] = *ppPVar26;
      }
      else {
        pPVar24 = (PyObject *)0x0;
        do {
          pPVar21 = (PyObject *)((long)&pPVar24->ob_refcnt + 1);
          if (pPVar21 == pPVar11) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar24 = (PyObject *)0x0;
            goto LAB_001268b0;
          }
          pPVar2 = &__pyx_kwds[2].ob_refcnt + (long)pPVar24;
          pPVar24 = pPVar21;
        } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar2);
        values[1] = ppPVar26[(long)pPVar21];
      }
      goto LAB_001269fc;
    }
LAB_00126ab0:
    values[1] = (PyObject *)0x0;
    goto LAB_00126ab4;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar12 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_00126818;
  }
  if (__pyx_nargs == 0) {
    lVar22 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar26,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar9 = (PyObject *)(lVar22 + -1);
      pPVar11 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      goto LAB_00126850;
    }
    lVar22 = PyErr_Occurred();
    if (lVar22 != 0) {
      iVar8 = 0x11c4;
      goto LAB_0012580c;
    }
  }
LAB_001257d0:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",2,
               "s",__pyx_nargs);
  iVar8 = 0x11e0;
  goto LAB_0012580c;
  while( true ) {
    pPVar2 = &pPVar24->ob_refcnt;
    pPVar24 = (PyObject *)((long)pPVar2 + 1);
    if (pPVar24 == pPVar11) goto LAB_00126ab0;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar2];
    if ((_typeobject *)pPVar10 == p_Var23) break;
LAB_001268b0:
    bVar6 = pPVar10->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar10 != (PyObject *)puVar3) && (bVar6 || p_Var23 != (_typeobject *)puVar3)) {
        plVar13 = (long *)PyObject_RichCompare(pPVar10,p_Var23,2);
        if (plVar13 == (long *)0x0) goto LAB_00126ab0;
        uVar18 = (uint)(plVar13 == (long *)puVar4);
        if ((plVar13 != (long *)puVar4 && plVar13 != (long *)PTR__Py_FalseStruct_00143f10) &&
            plVar13 != (long *)puVar3) {
          uVar18 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = *plVar13;
        *plVar13 = lVar22 + -1;
        if (lVar22 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_00126aa0:
        if (uVar18 != 0) {
          if ((int)uVar18 < 0) goto LAB_00126ab0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar10[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar10), iVar8 < 0)) ||
         ((-1 < (char)p_Var23->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var23), iVar8 < 0))))
      goto LAB_00126ab0;
      lVar22 = pPVar10[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar22 == (p_Var23->ob_base).ob_size) &&
         ((pPVar10[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar10[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar17 = (char *)((ulong)(byte)((byte)pPVar10[2].ob_refcnt >> 2) & 7);
        uVar18 = (uint)pcVar17;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar18) {
          bVar1 = (byte)pPVar10[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            p_Var25 = pPVar10[4].ob_type;
          }
          else {
            p_Var25 = (_typeobject *)&pPVar10[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              p_Var25 = (_typeobject *)(pPVar10 + 3);
            }
          }
          bVar1 = (byte)p_Var23->tp_basicsize;
          if ((bVar1 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var23->tp_setattr;
          }
          else {
            __s2 = &p_Var23->tp_setattr;
            if ((bVar1 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var23->tp_dealloc;
            }
          }
          if (uVar18 == 1) {
            uVar18 = (uint)(byte)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(byte *)__s2;
          }
          else if (uVar18 == 2) {
            uVar18 = (uint)(ushort)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(ushort *)__s2;
          }
          else {
            uVar18 = (uint)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar20 = *(uint *)__s2;
          }
          if (uVar20 == uVar18) {
            if (lVar22 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var25,__s2,(long)pcVar17 * lVar22);
              uVar18 = (uint)(iVar8 == 0);
              goto LAB_00126aa0;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar26[(long)pPVar24];
LAB_001269fc:
  if (values[1] != (PyObject *)0x0) {
    puVar12 = (undefined1 *)((long)&pPVar9[-1].ob_type + 7);
LAB_00126818:
    if (0 < (long)puVar12) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar9 = (PyObject *)values;
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar26,__pyx_pyargnames,pPVar9,(PyObject **)__pyx_nargs,
                         0x12fee0,pcVar17);
      if (iVar8 < 0) {
        iVar8 = 0x11d3;
        goto LAB_0012580c;
      }
    }
LAB_00125868:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar11 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var14 = values[1]->ob_type->tp_getattro;
    if (p_Var14 == (getattrofunc)0x0) {
      pPVar10 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar10 = (*p_Var14)(values[1],__pyx_mstate_global_static.__pyx_n_s_get_server);
    }
    if (pPVar10 == (PyObject *)0x0) {
      py_line = 0x21;
      iVar8 = 0x1210;
      goto LAB_00126bfc;
    }
    p_Var23 = pPVar10->ob_type;
    if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
       (p_Var25 = pPVar10[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar24 = (PyObject *)pPVar10[1].ob_refcnt;
      (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
      pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*p_Var23->tp_dealloc)(pPVar10);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var25;
      p_Var23 = (_typeobject *)
                __Pyx_PyObject_FastCallDict(pPVar24,(PyObject **)__pyx_pyargnames,1,pPVar9);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
      (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
      pPVar10 = pPVar24;
      if (lVar22 == 0) {
        (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      p_Var23 = (_typeobject *)
                __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)(__pyx_pyargnames + 1),0,pPVar9);
    }
    if (p_Var23 == (_typeobject *)0x0) {
      pPVar9 = (PyObject *)0x0;
      pPVar24 = (PyObject *)0x0;
      p_Var25 = (_typeobject *)0x0;
      iVar8 = 0x1224;
      py_line = 0x21;
      goto LAB_00126b70;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar22 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar22;
    if (lVar22 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar11->ob_type->tp_setattro;
    if (p_Var15 == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server,(PyObject *)p_Var23);
    }
    lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
    if (iVar8 < 0) {
      iVar8 = 0x1228;
      py_line = 0x21;
      p_Var25 = (_typeobject *)0x0;
      pPVar24 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      pPVar10 = (PyObject *)0x0;
      goto LAB_00126b54;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
    if (lVar22 == 0) {
      (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
    }
    p_Var23 = (_typeobject *)PyDict_New();
    if (p_Var23 == (_typeobject *)0x0) {
      iVar8 = 0x1232;
      py_line = 0x22;
      goto LAB_00126bfc;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar11->ob_type->tp_setattro;
    if (p_Var15 == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_agents,(PyObject *)p_Var23);
    }
    lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
    if (iVar8 < 0) {
      iVar8 = 0x1234;
      py_line = 0x22;
      p_Var25 = (_typeobject *)0x0;
      pPVar24 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      pPVar10 = (PyObject *)0x0;
      goto LAB_00126b54;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
    if (lVar22 == 0) {
      (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
    }
    p_Var23 = (_typeobject *)PyDict_New();
    if (p_Var23 == (_typeobject *)0x0) {
      iVar8 = 0x123e;
      py_line = 0x23;
      goto LAB_00126bfc;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar11->ob_type->tp_setattro;
    if (p_Var15 == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_agent_methods,
                         (PyObject *)p_Var23);
    }
    lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
    if (iVar8 < 0) {
      iVar8 = 0x1240;
      py_line = 0x23;
      p_Var25 = (_typeobject *)0x0;
      pPVar24 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      pPVar10 = (PyObject *)0x0;
      goto LAB_00126b54;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
    if (lVar22 == 0) {
      (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = pPVar11->ob_type->tp_setattro;
    if (p_Var15 == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_uds_server,
                         (PyObject *)PTR__Py_NoneStruct_00143f40);
    }
    if (iVar8 < 0) {
      py_line = 0x24;
      iVar8 = 0x124a;
    }
    else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var14 = pPVar11->ob_type->tp_getattro;
      if (p_Var14 == (getattrofunc)0x0) {
        p_Var23 = (_typeobject *)PyObject_GetAttr();
      }
      else {
        p_Var23 = (_typeobject *)(*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server);
      }
      if (p_Var23 == (_typeobject *)0x0) {
        iVar8 = 0x1253;
        py_line = 0x25;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var14 = ((p_Var23->ob_base).ob_base.ob_type)->tp_getattro;
        if (p_Var14 == (getattrofunc)0x0) {
          pPVar10 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar10 = (*p_Var14)((PyObject *)p_Var23,
                               __pyx_mstate_global_static.__pyx_n_s_register_endpoint);
        }
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        if (pPVar10 == (PyObject *)0x0) {
          p_Var25 = (_typeobject *)0x0;
          pPVar24 = (PyObject *)0x0;
          pPVar9 = (PyObject *)0x0;
          iVar8 = 0x1255;
          py_line = 0x25;
          goto LAB_00126b54;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_16844)
          goto LAB_00126d54;
LAB_00125aac:
          p_Var23 = __pyx_dict_cached_value_16845;
          if (__pyx_dict_cached_value_16845 == (_typeobject *)0x0) {
            p_Var23 = (_typeobject *)
                      __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
            goto LAB_00126d68;
          }
          (__pyx_dict_cached_value_16845->ob_base).ob_base.ob_refcnt =
               (__pyx_dict_cached_value_16845->ob_base).ob_base.ob_refcnt + 1;
        }
        else {
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16844)
          goto LAB_00125aac;
LAB_00126d54:
          p_Var23 = (_typeobject *)
                    __Pyx__GetModuleGlobalName
                              (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                               (uint64_t *)&__pyx_dict_version_16844,
                               (PyObject **)&__pyx_dict_cached_value_16845);
LAB_00126d68:
          if (p_Var23 == (_typeobject *)0x0) {
            p_Var25 = (_typeobject *)0x0;
            pPVar24 = (PyObject *)0x0;
            py_line = 0x26;
            iVar8 = 0x1260;
            pPVar9 = (PyObject *)0x0;
            goto LAB_00126b70;
          }
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var14 = ((p_Var23->ob_base).ob_base.ob_type)->tp_getattro;
        if (p_Var14 == (getattrofunc)0x0) {
          pPVar9 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar9 = (*p_Var14)((PyObject *)p_Var23,__pyx_mstate_global_static.__pyx_n_s_POST);
        }
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        if (pPVar9 == (PyObject *)0x0) {
          p_Var25 = (_typeobject *)0x0;
          pPVar24 = (PyObject *)0x0;
          iVar8 = 0x1262;
          py_line = 0x26;
          goto LAB_00126b54;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var14 = pPVar11->ob_type->tp_getattro;
        if (p_Var14 == (getattrofunc)0x0) {
          p_Var23 = (_typeobject *)PyObject_GetAttr();
        }
        else {
          p_Var23 = (_typeobject *)
                    (*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_register_agent_method);
        }
        if (p_Var23 == (_typeobject *)0x0) {
          pPVar24 = (PyObject *)0x0;
          py_line = 0x27;
          iVar8 = 0x126d;
          p_Var25 = (_typeobject *)0x0;
LAB_00126b70:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
LAB_00126b80:
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
LAB_00126b90:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar9 != (PyObject *)0x0) &&
             (lVar22 = pPVar9->ob_refcnt + -1, pPVar9->ob_refcnt = lVar22, lVar22 == 0)) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar24 != (PyObject *)0x0) &&
             (lVar22 = pPVar24->ob_refcnt + -1, pPVar24->ob_refcnt = lVar22, lVar22 == 0)) {
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
LAB_00126bd8:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (p_Var25 == (_typeobject *)0x0) goto LAB_00126bfc;
        }
        else {
          pPVar24 = (PyObject *)PyTuple_New(3);
          pPVar21 = __pyx_mstate_global_static.__pyx_kp_u_connection_register_remote_meth;
          if (pPVar24 == (PyObject *)0x0) {
            iVar8 = 0x1277;
            py_line = 0x25;
            p_Var25 = (_typeobject *)0x0;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
          (__pyx_mstate_global_static.__pyx_kp_u_connection_register_remote_meth)->ob_refcnt =
               (__pyx_mstate_global_static.__pyx_kp_u_connection_register_remote_meth)->ob_refcnt +
               1;
          pPVar24[1].ob_type = (_typeobject *)pPVar21;
          pPVar24[2].ob_refcnt = (Py_ssize_t)pPVar9;
          pPVar24[2].ob_type = p_Var23;
          p_Var23 = (_typeobject *)PyDict_New();
          pPVar9 = __pyx_dict_cached_value_16848;
          if (p_Var23 == (_typeobject *)0x0) {
            p_Var25 = (_typeobject *)0x0;
            pPVar9 = (PyObject *)0x0;
            py_line = 0x28;
            iVar8 = 0x128a;
            goto LAB_00126b70;
          }
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16847) {
            if (__pyx_dict_cached_value_16848 == (PyObject *)0x0) {
              pPVar9 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_TransportType);
              goto LAB_00126f60;
            }
            __pyx_dict_cached_value_16848->ob_refcnt = __pyx_dict_cached_value_16848->ob_refcnt + 1;
          }
          else {
            pPVar9 = __Pyx__GetModuleGlobalName
                               (__pyx_mstate_global_static.__pyx_n_s_TransportType,
                                (uint64_t *)&__pyx_dict_version_16847,&__pyx_dict_cached_value_16848
                               );
LAB_00126f60:
            if (pPVar9 == (PyObject *)0x0) {
              p_Var25 = (_typeobject *)0x0;
              iVar8 = 0x128c;
              py_line = 0x28;
              lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
              goto LAB_00126b54;
            }
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var14 = pPVar9->ob_type->tp_getattro;
          if (p_Var14 == (getattrofunc)0x0) {
            p_Var25 = (_typeobject *)PyObject_GetAttr();
          }
          else {
            p_Var25 = (_typeobject *)
                      (*p_Var14)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_WEBSOCKET);
          }
          if (p_Var25 == (_typeobject *)0x0) {
            iVar8 = 0x128e;
            py_line = 0x28;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
LAB_00126b54:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
            if (pPVar10 != (PyObject *)0x0) goto LAB_00126b70;
            goto LAB_00126b90;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          iVar8 = PyDict_SetItem(p_Var23,__pyx_mstate_global_static.__pyx_n_s_transports,p_Var25);
          if (iVar8 < 0) {
            iVar8 = 0x1291;
            py_line = 0x28;
            pPVar9 = (PyObject *)0x0;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          pPVar9 = __Pyx_PyObject_Call(pPVar10,pPVar24,(PyObject *)p_Var23);
          if (pPVar9 == (PyObject *)0x0) {
            p_Var25 = (_typeobject *)0x0;
            iVar8 = 0x129b;
            py_line = 0x25;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            pPVar9 = (PyObject *)0x0;
            goto LAB_00126b54;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          p_Var25 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server);
          if (p_Var25 == (_typeobject *)0x0) {
            py_line = 0x2a;
            iVar8 = 0x12a9;
            goto LAB_00126bfc;
          }
          p_Var23 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr
                              ((PyObject *)p_Var25,
                               __pyx_mstate_global_static.__pyx_n_s_register_endpoint);
          if (p_Var23 == (_typeobject *)0x0) {
            py_line = 0x2a;
            iVar8 = 0x12ab;
            goto LAB_00126bdc;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          p_Var25 = __pyx_dict_cached_value_16857;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16856) {
            if (__pyx_dict_cached_value_16857 == (_typeobject *)0x0) {
              p_Var25 = (_typeobject *)
                        __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
              goto LAB_00126d8c;
            }
            (__pyx_dict_cached_value_16857->ob_base).ob_base.ob_refcnt =
                 (__pyx_dict_cached_value_16857->ob_base).ob_base.ob_refcnt + 1;
          }
          else {
            p_Var25 = (_typeobject *)
                      __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                                 (uint64_t *)&__pyx_dict_version_16856,
                                 (PyObject **)&__pyx_dict_cached_value_16857);
LAB_00126d8c:
            if (p_Var25 == (_typeobject *)0x0) {
              p_Var25 = (_typeobject *)0x0;
              pPVar24 = (PyObject *)0x0;
              pPVar9 = (PyObject *)0x0;
              iVar8 = 0x12b6;
              py_line = 0x2b;
              lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
              pPVar10 = (PyObject *)0x0;
              goto LAB_00126b54;
            }
          }
          pPVar24 = __Pyx_PyObject_GetAttrStr
                              ((PyObject *)p_Var25,__pyx_mstate_global_static.__pyx_n_s_POST);
          if (pPVar24 == (PyObject *)0x0) {
            pPVar9 = (PyObject *)0x0;
            pPVar10 = (PyObject *)0x0;
            iVar8 = 0x12b8;
            py_line = 0x2b;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          p_Var25 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr
                              (pPVar11,__pyx_mstate_global_static.__pyx_n_s_handle_agent_event);
          if (p_Var25 == (_typeobject *)0x0) {
            pPVar9 = (PyObject *)0x0;
            pPVar10 = (PyObject *)0x0;
            iVar8 = 0x12bb;
            py_line = 0x2b;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
          pPVar10 = (PyObject *)PyTuple_New(3);
          pPVar9 = __pyx_mstate_global_static.__pyx_kp_u_connection_send_event;
          if (pPVar10 == (PyObject *)0x0) {
            pPVar9 = (PyObject *)0x0;
            iVar8 = 0x12c5;
            py_line = 0x2a;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
          (__pyx_mstate_global_static.__pyx_kp_u_connection_send_event)->ob_refcnt =
               (__pyx_mstate_global_static.__pyx_kp_u_connection_send_event)->ob_refcnt + 1;
          pPVar10[1].ob_type = (_typeobject *)pPVar9;
          pPVar10[2].ob_refcnt = (Py_ssize_t)pPVar24;
          pPVar10[2].ob_type = p_Var25;
          p_Var25 = (_typeobject *)PyDict_New();
          pPVar24 = __pyx_dict_cached_value_16860;
          if (p_Var25 == (_typeobject *)0x0) {
            pPVar24 = (PyObject *)0x0;
            pPVar9 = (PyObject *)0x0;
            iVar8 = 0x12d8;
            py_line = 0x2c;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16859) {
            if (__pyx_dict_cached_value_16860 == (PyObject *)0x0) {
              pPVar24 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_TransportType);
              goto LAB_00127094;
            }
            __pyx_dict_cached_value_16860->ob_refcnt = __pyx_dict_cached_value_16860->ob_refcnt + 1;
          }
          else {
            pPVar24 = __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_TransportType,
                                 (uint64_t *)&__pyx_dict_version_16859,
                                 &__pyx_dict_cached_value_16860);
LAB_00127094:
            if (pPVar24 == (PyObject *)0x0) {
              pPVar9 = (PyObject *)0x0;
              iVar8 = 0x12da;
              py_line = 0x2c;
              lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
              goto LAB_00126b54;
            }
          }
          pPVar9 = __Pyx_PyObject_GetAttrStr(pPVar24,__pyx_mstate_global_static.__pyx_n_s_WEBSOCKET)
          ;
          if (pPVar9 == (PyObject *)0x0) {
            iVar8 = 0x12dc;
            py_line = 0x2c;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
          iVar8 = PyDict_SetItem(p_Var25,__pyx_mstate_global_static.__pyx_n_s_transports,pPVar9);
          if (iVar8 < 0) {
            iVar8 = 0x12df;
            py_line = 0x2c;
            pPVar24 = (PyObject *)0x0;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_00126b54;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          pPVar9 = __Pyx_PyObject_Call((PyObject *)p_Var23,pPVar10,(PyObject *)p_Var25);
          if (pPVar9 == (PyObject *)0x0) {
            pPVar24 = (PyObject *)0x0;
            iVar8 = 0x12e9;
            py_line = 0x2a;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            pPVar9 = (PyObject *)0x0;
            goto LAB_00126b54;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          p_Var25 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server);
          if (p_Var25 == (_typeobject *)0x0) {
            py_line = 0x2e;
            iVar8 = 0x12f7;
            goto LAB_00126bfc;
          }
          pPVar10 = __Pyx_PyObject_GetAttrStr
                              ((PyObject *)p_Var25,
                               __pyx_mstate_global_static.__pyx_n_s_register_endpoint);
          if (pPVar10 == (PyObject *)0x0) {
            iVar8 = 0x12f9;
            py_line = 0x2e;
            goto LAB_00126bdc;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          p_Var25 = __pyx_dict_cached_value_16869;
          p_Var16 = &__pyx_mstate_global_static;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_16868) {
            p_Var25 = (_typeobject *)
                      __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                                 (uint64_t *)&__pyx_dict_version_16868,
                                 (PyObject **)&__pyx_dict_cached_value_16869);
LAB_00127148:
            if (p_Var25 != (_typeobject *)0x0) goto LAB_00125ef0;
            iVar8 = 0x1304;
            py_line = 0x2f;
            lVar22 = pPVar10->ob_refcnt + -1;
            goto LAB_0012715c;
          }
          if (__pyx_dict_cached_value_16869 == (_typeobject *)0x0) {
            p_Var25 = (_typeobject *)
                      __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
            goto LAB_00127148;
          }
          (__pyx_dict_cached_value_16869->ob_base).ob_base.ob_refcnt =
               (__pyx_dict_cached_value_16869->ob_base).ob_base.ob_refcnt + 1;
LAB_00125ef0:
          p_Var23 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr
                              ((PyObject *)p_Var25,__pyx_mstate_global_static.__pyx_n_s_GET);
          if (p_Var23 == (_typeobject *)0x0) {
            pPVar24 = (PyObject *)0x0;
            py_line = 0x2f;
            iVar8 = 0x1306;
            pPVar9 = (PyObject *)0x0;
            goto LAB_00126b70;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          pPVar9 = __Pyx_PyObject_GetAttrStr
                             (pPVar11,__pyx_mstate_global_static.__pyx_n_s_handle_list_extensions);
          if (pPVar9 == (PyObject *)0x0) {
            p_Var25 = (_typeobject *)0x0;
            iVar8 = 0x1309;
            py_line = 0x2f;
            pPVar9 = (PyObject *)0x0;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            pPVar24 = (PyObject *)0x0;
            goto LAB_00126b54;
          }
          p_Var25 = pPVar10->ob_type;
          if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (p_Var28 = pPVar10[1].ob_type, p_Var28 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar21 = (PyObject *)pPVar10[1].ob_refcnt;
            (p_Var28->ob_base).ob_base.ob_refcnt = (p_Var28->ob_base).ob_base.ob_refcnt + 1;
            pPVar21->ob_refcnt = pPVar21->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*p_Var25->tp_dealloc)(pPVar10);
            }
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_server_extensions_list;
            __pyx_pyargnames[0] = (PyObject **)p_Var28;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar24 = __Pyx_PyObject_FastCallDict
                                (pPVar21,(PyObject **)__pyx_pyargnames,4,(PyObject *)p_Var16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var28->ob_base).ob_base.ob_refcnt + -1;
            (p_Var28->ob_base).ob_base.ob_refcnt = lVar22;
            pPVar10 = pPVar21;
            if (lVar22 == 0) {
              (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_server_extensions_list;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar24 = __Pyx_PyObject_FastCallDict
                                (pPVar10,(PyObject **)(__pyx_pyargnames + 1),3,(PyObject *)p_Var16);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          lVar22 = pPVar10->ob_refcnt + -1;
          if (pPVar24 == (PyObject *)0x0) {
            iVar8 = 0x131f;
            py_line = 0x2e;
            goto LAB_0012715c;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
          pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server);
          if (pPVar10 == (PyObject *)0x0) {
            py_line = 0x31;
            iVar8 = 0x132c;
            goto LAB_00126bfc;
          }
          p_Var25 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr
                              (pPVar10,__pyx_mstate_global_static.__pyx_n_s_register_endpoint);
          if (p_Var25 == (_typeobject *)0x0) {
            iVar8 = 0x132e;
            py_line = 0x31;
            lVar22 = pPVar10->ob_refcnt + -1;
            goto LAB_0012715c;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          pPVar10 = __pyx_dict_cached_value_16883;
          p_Var16 = &__pyx_mstate_global_static;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16882) {
            if (__pyx_dict_cached_value_16883 == (PyObject *)0x0) {
              pPVar10 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
              goto LAB_00127220;
            }
            __pyx_dict_cached_value_16883->ob_refcnt = __pyx_dict_cached_value_16883->ob_refcnt + 1;
          }
          else {
            pPVar10 = __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                                 (uint64_t *)&__pyx_dict_version_16882,
                                 &__pyx_dict_cached_value_16883);
LAB_00127220:
            if (pPVar10 == (PyObject *)0x0) {
              iVar8 = 0x1339;
              py_line = 0x32;
              goto LAB_00126bdc;
            }
          }
          p_Var23 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr(pPVar10,__pyx_mstate_global_static.__pyx_n_s_POST);
          if (p_Var23 == (_typeobject *)0x0) {
            iVar8 = 0x133b;
            py_line = 0x32;
LAB_00127248:
            lVar22 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              pPVar9 = (PyObject *)0x0;
              pPVar24 = (PyObject *)0x0;
              goto LAB_00126b80;
            }
            goto LAB_00126bd8;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          pPVar9 = __Pyx_PyObject_GetAttrStr
                             (pPVar11,__pyx_mstate_global_static.__pyx_n_s_handle_call_agent);
          if (pPVar9 == (PyObject *)0x0) {
            pPVar24 = (PyObject *)0x0;
            pPVar9 = (PyObject *)0x0;
            iVar8 = 0x133e;
            py_line = 0x32;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            pPVar10 = (PyObject *)0x0;
            goto LAB_00126b54;
          }
          p_Var28 = (p_Var25->ob_base).ob_base.ob_type;
          if ((p_Var28 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (ppPVar26 = (PyObject **)p_Var25->tp_name, ppPVar26 != (PyObject **)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            p_Var27 = (_typeobject *)(p_Var25->ob_base).ob_size;
            *ppPVar26 = (PyObject *)((long)&(*ppPVar26)->ob_refcnt + 1);
            (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
            (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*p_Var28->tp_dealloc)((PyObject *)p_Var25);
            }
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_server_extensions_request;
            __pyx_pyargnames[0] = ppPVar26;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar10 = __Pyx_PyObject_FastCallDict
                                ((PyObject *)p_Var27,(PyObject **)__pyx_pyargnames,4,
                                 (PyObject *)p_Var16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar24 = (PyObject *)((long)&(*ppPVar26)[-1].ob_type + 7);
            *ppPVar26 = pPVar24;
            p_Var25 = p_Var27;
            if (pPVar24 == (PyObject *)0x0) {
              (*(code *)ppPVar26[1][3].ob_refcnt)(ppPVar26);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_server_extensions_request;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar10 = __Pyx_PyObject_FastCallDict
                                ((PyObject *)p_Var25,(PyObject **)(__pyx_pyargnames + 1),3,
                                 __pyx_mstate_global_static.__pyx_kp_u_server_extensions_request);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          if (pPVar10 == (PyObject *)0x0) {
            iVar8 = 0x1354;
            py_line = 0x31;
            goto LAB_00126bdc;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          p_Var25 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server);
          if (p_Var25 == (_typeobject *)0x0) {
            py_line = 0x34;
            iVar8 = 0x1361;
            goto LAB_00126bfc;
          }
          pPVar10 = __Pyx_PyObject_GetAttrStr
                              ((PyObject *)p_Var25,
                               __pyx_mstate_global_static.__pyx_n_s_register_endpoint);
          if (pPVar10 == (PyObject *)0x0) {
            iVar8 = 0x1363;
            py_line = 0x34;
            goto LAB_00126bdc;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          p_Var25 = __pyx_dict_cached_value_16897;
          p_Var16 = &__pyx_mstate_global_static;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16896) {
            if (__pyx_dict_cached_value_16897 == (_typeobject *)0x0) {
              p_Var25 = (_typeobject *)
                        __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
              goto LAB_001272e8;
            }
            (__pyx_dict_cached_value_16897->ob_base).ob_base.ob_refcnt =
                 (__pyx_dict_cached_value_16897->ob_base).ob_base.ob_refcnt + 1;
          }
          else {
            p_Var25 = (_typeobject *)
                      __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                                 (uint64_t *)&__pyx_dict_version_16896,
                                 (PyObject **)&__pyx_dict_cached_value_16897);
LAB_001272e8:
            if (p_Var25 == (_typeobject *)0x0) {
              iVar8 = 0x136e;
              py_line = 0x35;
              lVar22 = pPVar10->ob_refcnt + -1;
              goto LAB_0012715c;
            }
          }
          p_Var23 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr
                              ((PyObject *)p_Var25,__pyx_mstate_global_static.__pyx_n_s_GET);
          if (p_Var23 == (_typeobject *)0x0) {
            pPVar24 = (PyObject *)0x0;
            py_line = 0x35;
            iVar8 = 0x1370;
            pPVar9 = (PyObject *)0x0;
            goto LAB_00126b70;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
          pPVar9 = __Pyx_PyObject_GetAttrStr
                             (pPVar11,__pyx_mstate_global_static.
                                      __pyx_n_s_handle_qidiclient_files_list);
          if (pPVar9 == (PyObject *)0x0) {
            p_Var25 = (_typeobject *)0x0;
            iVar8 = 0x1373;
            py_line = 0x35;
            pPVar9 = (PyObject *)0x0;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            pPVar24 = (PyObject *)0x0;
            goto LAB_00126b54;
          }
          p_Var25 = pPVar10->ob_type;
          if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (p_Var28 = pPVar10[1].ob_type, p_Var28 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar21 = (PyObject *)pPVar10[1].ob_refcnt;
            (p_Var28->ob_base).ob_base.ob_refcnt = (p_Var28->ob_base).ob_base.ob_refcnt + 1;
            pPVar21->ob_refcnt = pPVar21->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*p_Var25->tp_dealloc)(pPVar10);
            }
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_files_list;
            __pyx_pyargnames[0] = (PyObject **)p_Var28;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar24 = __Pyx_PyObject_FastCallDict
                                (pPVar21,(PyObject **)__pyx_pyargnames,4,(PyObject *)p_Var16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var28->ob_base).ob_base.ob_refcnt + -1;
            (p_Var28->ob_base).ob_base.ob_refcnt = lVar22;
            pPVar10 = pPVar21;
            if (lVar22 == 0) {
              (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_files_list;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar24 = __Pyx_PyObject_FastCallDict
                                (pPVar10,(PyObject **)(__pyx_pyargnames + 1),3,(PyObject *)p_Var16);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          lVar22 = pPVar10->ob_refcnt + -1;
          if (pPVar24 == (PyObject *)0x0) {
            iVar8 = 0x1389;
            py_line = 0x34;
LAB_0012715c:
            pPVar10->ob_refcnt = lVar22;
            if (lVar22 != 0) goto LAB_00126bfc;
            pPVar9 = (PyObject *)0x0;
            pPVar24 = (PyObject *)0x0;
            p_Var25 = (_typeobject *)0x0;
            goto LAB_00126b80;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
          pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server);
          if (pPVar10 == (PyObject *)0x0) {
            py_line = 0x37;
            iVar8 = 0x1396;
            goto LAB_00126bfc;
          }
          p_Var25 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr
                              (pPVar10,__pyx_mstate_global_static.__pyx_n_s_register_endpoint);
          if (p_Var25 == (_typeobject *)0x0) {
            iVar8 = 0x1398;
            py_line = 0x37;
            lVar22 = pPVar10->ob_refcnt + -1;
            goto LAB_0012715c;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          pPVar10 = __pyx_dict_cached_value_16911;
          p_Var28 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
          if (p_Var28 == __pyx_dict_version_16910) {
            if (__pyx_dict_cached_value_16911 == (PyObject *)0x0) {
              pPVar10 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
              goto LAB_001273a0;
            }
            __pyx_dict_cached_value_16911->ob_refcnt = __pyx_dict_cached_value_16911->ob_refcnt + 1;
          }
          else {
            pPVar10 = __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                                 (uint64_t *)&__pyx_dict_version_16910,
                                 &__pyx_dict_cached_value_16911);
LAB_001273a0:
            if (pPVar10 == (PyObject *)0x0) {
              iVar8 = 0x13a3;
              py_line = 0x38;
              goto LAB_00126bdc;
            }
          }
          p_Var23 = (_typeobject *)
                    __Pyx_PyObject_GetAttrStr(pPVar10,__pyx_mstate_global_static.__pyx_n_s_GET);
          if (p_Var23 == (_typeobject *)0x0) {
            iVar8 = 0x13a5;
            py_line = 0x38;
            goto LAB_00127248;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          pPVar9 = __Pyx_PyObject_GetAttrStr
                             (pPVar11,__pyx_mstate_global_static.
                                      __pyx_n_s_handle_qidiclient_files_stats);
          if (pPVar9 == (PyObject *)0x0) {
            pPVar24 = (PyObject *)0x0;
            pPVar9 = (PyObject *)0x0;
            iVar8 = 0x13a8;
            py_line = 0x38;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            pPVar10 = (PyObject *)0x0;
            goto LAB_00126b54;
          }
          p_Var27 = (p_Var25->ob_base).ob_base.ob_type;
          if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
             (ppPVar26 = (PyObject **)p_Var25->tp_name, ppPVar26 != (PyObject **)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            func = (_typeobject *)(p_Var25->ob_base).ob_size;
            *ppPVar26 = (PyObject *)((long)&(*ppPVar26)->ob_refcnt + 1);
            (func->ob_base).ob_base.ob_refcnt = (func->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
            (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*p_Var27->tp_dealloc)((PyObject *)p_Var25);
            }
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_files_stats;
            __pyx_pyargnames[0] = ppPVar26;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar10 = __Pyx_PyObject_FastCallDict
                                ((PyObject *)func,(PyObject **)__pyx_pyargnames,4,
                                 (PyObject *)p_Var28);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar24 = (PyObject *)((long)&(*ppPVar26)[-1].ob_type + 7);
            *ppPVar26 = pPVar24;
            p_Var25 = func;
            if (pPVar24 == (PyObject *)0x0) {
              (*(code *)ppPVar26[1][3].ob_refcnt)(ppPVar26);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_files_stats;
            __pyx_pyargnames[2] = (PyObject **)p_Var23;
            pPVar10 = __Pyx_PyObject_FastCallDict
                                ((PyObject *)p_Var25,(PyObject **)(__pyx_pyargnames + 1),3,
                                 __pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_files_stats);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
          if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
            (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
            }
            p_Var25 = (_typeobject *)
                      __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_server)
            ;
            if (p_Var25 == (_typeobject *)0x0) {
              py_line = 0x3a;
              iVar8 = 0x13cb;
              goto LAB_00126bfc;
            }
            pPVar10 = __Pyx_PyObject_GetAttrStr
                                ((PyObject *)p_Var25,
                                 __pyx_mstate_global_static.__pyx_n_s_register_endpoint);
            if (pPVar10 == (PyObject *)0x0) {
              iVar8 = 0x13cd;
              py_line = 0x3a;
              goto LAB_00126bdc;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
            (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
            }
            p_Var25 = __pyx_dict_cached_value_16925;
            p_Var28 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
            if (p_Var28 == __pyx_dict_version_16924) {
              if (__pyx_dict_cached_value_16925 == (_typeobject *)0x0) {
                p_Var25 = (_typeobject *)
                          __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_RequestType);
                goto LAB_00127498;
              }
              (__pyx_dict_cached_value_16925->ob_base).ob_base.ob_refcnt =
                   (__pyx_dict_cached_value_16925->ob_base).ob_base.ob_refcnt + 1;
            }
            else {
              p_Var25 = (_typeobject *)
                        __Pyx__GetModuleGlobalName
                                  (__pyx_mstate_global_static.__pyx_n_s_RequestType,
                                   (uint64_t *)&__pyx_dict_version_16924,
                                   (PyObject **)&__pyx_dict_cached_value_16925);
LAB_00127498:
              if (p_Var25 == (_typeobject *)0x0) {
                iVar8 = 0x13d8;
                py_line = 0x3b;
                lVar22 = pPVar10->ob_refcnt + -1;
                goto LAB_0012715c;
              }
            }
            p_Var23 = (_typeobject *)
                      __Pyx_PyObject_GetAttrStr
                                ((PyObject *)p_Var25,__pyx_mstate_global_static.__pyx_n_s_GET);
            if (p_Var23 == (_typeobject *)0x0) {
              pPVar24 = (PyObject *)0x0;
              py_line = 0x3b;
              iVar8 = 0x13da;
              pPVar9 = (PyObject *)0x0;
              goto LAB_00126b70;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
            (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
            }
            pPVar9 = __Pyx_PyObject_GetAttrStr
                               (pPVar11,__pyx_mstate_global_static.
                                        __pyx_n_s_handle_qidiclient_config_offica);
            if (pPVar9 == (PyObject *)0x0) {
              p_Var25 = (_typeobject *)0x0;
              iVar8 = 0x13dd;
              py_line = 0x3b;
              pPVar9 = (PyObject *)0x0;
              lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
              pPVar24 = (PyObject *)0x0;
              goto LAB_00126b54;
            }
            p_Var25 = pPVar10->ob_type;
            if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
               (p_Var27 = pPVar10[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar24 = (PyObject *)pPVar10[1].ob_refcnt;
              (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
              pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar10->ob_refcnt + -1;
              pPVar10->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*p_Var25->tp_dealloc)(pPVar10);
              }
              __pyx_pyargnames[1] =
                   (PyObject **)
                   __pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_config_offical_f;
              __pyx_pyargnames[0] = (PyObject **)p_Var27;
              __pyx_pyargnames[2] = (PyObject **)p_Var23;
              pPVar11 = __Pyx_PyObject_FastCallDict
                                  (pPVar24,(PyObject **)__pyx_pyargnames,4,(PyObject *)p_Var28);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
              (p_Var27->ob_base).ob_base.ob_refcnt = lVar22;
              pPVar10 = pPVar24;
              if (lVar22 == 0) {
                (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] =
                   (PyObject **)
                   __pyx_mstate_global_static.__pyx_kp_u_api_qidiclient_config_offical_f;
              __pyx_pyargnames[2] = (PyObject **)p_Var23;
              pPVar11 = __Pyx_PyObject_FastCallDict
                                  (pPVar10,(PyObject **)(__pyx_pyargnames + 1),3,(PyObject *)p_Var28
                                  );
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = pPVar9->ob_refcnt + -1;
            pPVar9->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*pPVar9->ob_type->tp_dealloc)(pPVar9);
            }
            lVar22 = pPVar10->ob_refcnt + -1;
            if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              pPVar10->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*pPVar10->ob_type->tp_dealloc)(pPVar10);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
              pPVar9 = (PyObject *)PTR__Py_NoneStruct_00143f40;
              *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
              goto LAB_00125828;
            }
            iVar8 = 0x13f3;
            py_line = 0x3a;
            goto LAB_0012715c;
          }
          iVar8 = 0x13be;
          py_line = 0x37;
        }
LAB_00126bdc:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
        (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
        }
      }
    }
LAB_00126bfc:
    __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.__init__",iVar8,py_line,
                       "moonraker/components/extensions.py");
    pPVar9 = (PyObject *)0x0;
    goto LAB_00125828;
  }
LAB_00126ab4:
  lVar22 = PyErr_Occurred();
  if (lVar22 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 2,"s",1);
    iVar8 = 0x11ce;
  }
  else {
    iVar8 = 0x11cc;
  }
LAB_0012580c:
  __Pyx_AddTraceback("moonraker.components.extensions.ExtensionManager.__init__",iVar8,0x20,
                     "moonraker/components/extensions.py");
  pPVar9 = (PyObject *)0x0;
LAB_00125828:
  if (lVar19 == *(long *)PTR___stack_chk_guard_00143f20) {
    return pPVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00128e40
 * Symbol:  __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_1__init__
 * Signature: PyObject * __pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_10extensions_16UnixSocketClient_1__init__
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject **kwvalues;
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  PyObject *pPVar7;
  PyObject *pPVar8;
  PyObject *pPVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  long lVar12;
  int iVar13;
  getattrofunc p_Var14;
  _typeobject *p_Var15;
  long lVar16;
  setattrofunc p_Var17;
  PyObject *pPVar18;
  long lVar19;
  PyObject **function_name;
  long lVar20;
  PyObject *pPVar21;
  PyObject *pPVar22;
  _typeobject *p_Var23;
  long lVar24;
  _typeobject *p_Var25;
  PyObject *pPVar26;
  PyObject *values [5];
  PyObject **__pyx_pyargnames [6];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_server@[???]
                       Unresolved local var: PyObject * __pyx_v_reader@[???]
                       Unresolved local var: PyObject * __pyx_v_writer@[???]
                       Unresolved local var: PyObject * __pyx_v_peercred@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg23(x23)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar20 = *(long *)PTR___stack_chk_guard_00143f20;
  function_name = &__pyx_mstate_global_static.__pyx_n_s_server;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  values[3] = (PyObject *)0x0;
  values[4] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_server;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_reader;
  __pyx_pyargnames[3] = &__pyx_mstate_global_static.__pyx_n_s_writer;
  __pyx_pyargnames[4] = &__pyx_mstate_global_static.__pyx_n_s_peercred;
  __pyx_pyargnames[5] = (PyObject **)0x0;
  pPVar8 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 5) {
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      values[2] = __pyx_args[2];
      values[3] = __pyx_args[3];
      values[4] = __pyx_args[4];
      goto LAB_00128f54;
    }
LAB_00129c18:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 5,"s",__pyx_nargs);
    iVar3 = 0x2a92;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    if (__pyx_nargs == 2) {
LAB_00128ef0:
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar24 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs == 2) goto LAB_00129b78;
      if (2 < __pyx_nargs) {
        if (__pyx_nargs == 3) goto LAB_00129b98;
        if (__pyx_nargs != 4) goto LAB_00128f40;
        goto LAB_00128f20;
      }
      if (__pyx_nargs == 0) goto LAB_00129bf4;
      if (__pyx_nargs == 1) goto LAB_00129b58;
LAB_00128f40:
      if (0 < lVar24) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
        pPVar8 = (PyObject *)values;
        iVar3 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar8,(PyObject **)__pyx_nargs,
                           0x12fee0,(char *)function_name);
        if (iVar3 < 0) {
          iVar3 = 0x2a7f;
          goto LAB_00129c54;
        }
      }
LAB_00128f54:
      pPVar9 = values[4];
      pPVar22 = values[3];
      pPVar11 = values[2];
      pPVar18 = values[1];
      pPVar10 = values[0];
      if ((values[4]->ob_type != (_typeobject *)PTR_PyDict_Type_00143f60) &&
         (iVar3 = __Pyx__ArgTypeTest((PyObject *)&values[4]->ob_type,
                                     (PyTypeObject *)PTR_PyDict_Type_00143f60,"peercred",(int)pPVar8
                                    ), iVar3 == 0)) {
        pPVar8 = (PyObject *)0x0;
        goto LAB_00129c70;
      }
                    /* Unresolved local var: PyObject * __pyx_v_pid@[???]
                       Unresolved local var: PyObject * __pyx_v_uid@[???]
                       Unresolved local var: PyObject * __pyx_v_gid@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_5@[???]
                       Unresolved local var: Py_UCS4 __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: PyObject * __pyx_t_8@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyTypeObject * tp@[???] */
      p_Var14 = pPVar10->ob_type->tp_getattro;
      if (p_Var14 == (getattrofunc)0x0) {
        pPVar7 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar7 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_on_create);
      }
      if (pPVar7 == (PyObject *)0x0) {
        iVar3 = 0x2acc;
        iVar13 = 0xd1;
        goto LAB_00129ce0;
      }
      p_Var15 = pPVar7->ob_type;
      if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
         (p_Var25 = pPVar7[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar21 = (PyObject *)pPVar7[1].ob_refcnt;
        (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
        pPVar21->ob_refcnt = pPVar21->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar7->ob_refcnt + -1;
        pPVar7->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var15->tp_dealloc)(pPVar7);
        }
        __pyx_pyargnames[0] = (PyObject **)p_Var25;
        __pyx_pyargnames[1] = (PyObject **)pPVar18;
        pPVar8 = __Pyx_PyObject_FastCallDict(pPVar21,(PyObject **)__pyx_pyargnames,2,pPVar8);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
        (p_Var25->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar7 = pPVar21;
        if (lVar24 == 0) {
          (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)pPVar18;
        pPVar8 = __Pyx_PyObject_FastCallDict(pPVar7,(PyObject **)(__pyx_pyargnames + 1),1,pPVar8);
      }
      if (pPVar8 == (PyObject *)0x0) {
        pPVar22 = (PyObject *)0x0;
        pPVar9 = (PyObject *)0x0;
        iVar13 = 0xd1;
        iVar3 = 0x2ae0;
        pPVar18 = (PyObject *)0x0;
        goto LAB_00129d90;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar7->ob_refcnt + -1;
      pPVar7->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar7->ob_type->tp_dealloc)(pPVar7);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar8->ob_refcnt + -1;
      pPVar8->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar8->ob_type->tp_dealloc)(pPVar8);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var17 = pPVar10->ob_type->tp_setattro;
      if (p_Var17 == (setattrofunc)0x0) {
        iVar3 = PyObject_SetAttr();
      }
      else {
        iVar3 = (*p_Var17)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_writer,pPVar22);
      }
      if (iVar3 < 0) {
        iVar3 = 0x2aed;
        iVar13 = 0xd2;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        pPVar8 = (PyObject *)pPVar10->ob_type->tp_setattro;
        if (pPVar8 == (PyObject *)0x0) {
          iVar3 = PyObject_SetAttr(pPVar10,__pyx_mstate_global_static.__pyx_n_s_peer_cred,pPVar9);
        }
        else {
          iVar3 = (*(code *)pPVar8)();
        }
        if (iVar3 < 0) {
          iVar3 = 0x2af6;
          iVar13 = 0xd3;
        }
        else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var14 = pPVar10->ob_type->tp_getattro;
          if (p_Var14 == (getattrofunc)0x0) {
            pPVar7 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar7 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_eventloop);
          }
          if (pPVar7 == (PyObject *)0x0) {
            iVar3 = 0x2aff;
            iVar13 = 0xd4;
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var14 = pPVar7->ob_type->tp_getattro;
            if (p_Var14 == (getattrofunc)0x0) {
              pPVar21 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar21 = (*p_Var14)(pPVar7,__pyx_mstate_global_static.__pyx_n_s_get_loop_time);
            }
            lVar24 = pPVar7->ob_refcnt + -1;
            if (pPVar21 == (PyObject *)0x0) {
              pPVar22 = (PyObject *)0x0;
              pPVar9 = (PyObject *)0x0;
              pPVar18 = (PyObject *)0x0;
              pPVar8 = (PyObject *)0x0;
              iVar13 = 0xd4;
              iVar3 = 0x2b01;
              goto LAB_00129da0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar7->ob_refcnt = lVar24;
            if (lVar24 == 0) {
              (*pPVar7->ob_type->tp_dealloc)(pPVar7);
            }
            p_Var15 = pPVar21->ob_type;
            if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
               (p_Var25 = pPVar21[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar18 = (PyObject *)pPVar21[1].ob_refcnt;
              (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
              pPVar18->ob_refcnt = pPVar18->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar24 = pPVar21->ob_refcnt + -1;
              pPVar21->ob_refcnt = lVar24;
              if (lVar24 == 0) {
                (*p_Var15->tp_dealloc)(pPVar21);
              }
              __pyx_pyargnames[1] = (PyObject **)0x0;
              __pyx_pyargnames[0] = (PyObject **)p_Var25;
              pPVar8 = __Pyx_PyObject_FastCallDict(pPVar18,(PyObject **)__pyx_pyargnames,1,pPVar18);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar24 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
              (p_Var25->ob_base).ob_base.ob_refcnt = lVar24;
              pPVar21 = pPVar18;
              if (lVar24 == 0) {
                (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = (PyObject **)0x0;
              pPVar8 = __Pyx_PyObject_FastCallDict
                                 (pPVar21,(PyObject **)(__pyx_pyargnames + 1),0,pPVar8);
            }
            if (pPVar8 == (PyObject *)0x0) {
              pPVar22 = (PyObject *)0x0;
              pPVar9 = (PyObject *)0x0;
              iVar13 = 0xd4;
              iVar3 = 0x2b16;
              pPVar18 = (PyObject *)0x0;
              goto LAB_0012a0a4;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar24 = pPVar21->ob_refcnt + -1;
            pPVar21->ob_refcnt = lVar24;
            if (lVar24 == 0) {
              (*pPVar21->ob_type->tp_dealloc)(pPVar21);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var17 = pPVar10->ob_type->tp_setattro;
            if (p_Var17 == (setattrofunc)0x0) {
              iVar3 = PyObject_SetAttr();
            }
            else {
              iVar3 = (*p_Var17)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_connected_time,pPVar8)
              ;
            }
            lVar24 = pPVar8->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar8->ob_refcnt = lVar24;
            if (iVar3 < 0) {
              if (lVar24 == 0) {
                (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                iVar3 = 0x2b1a;
                iVar13 = 0xd4;
              }
              else {
                iVar3 = 0x2b1a;
                iVar13 = 0xd4;
              }
            }
            else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              if (lVar24 == 0) {
                (*pPVar8->ob_type->tp_dealloc)(pPVar8);
              }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var14 = pPVar10->ob_type->tp_getattro;
              if (p_Var14 == (getattrofunc)0x0) {
                pPVar21 = (PyObject *)PyObject_GetAttr();
              }
              else {
                pPVar21 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_peer_cred);
              }
              if (pPVar21 != (PyObject *)0x0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                p_Var14 = pPVar21->ob_type->tp_getattro;
                if (p_Var14 == (getattrofunc)0x0) {
                  pPVar7 = (PyObject *)PyObject_GetAttr();
                }
                else {
                  pPVar7 = (*p_Var14)(pPVar21,__pyx_mstate_global_static.__pyx_n_s_get);
                }
                if (pPVar7 == (PyObject *)0x0) {
                  pPVar9 = (PyObject *)0x0;
                  iVar13 = 0xd5;
                  iVar3 = 0x2b26;
                  pPVar18 = (PyObject *)0x0;
LAB_0012a15c:
                  pPVar8 = (PyObject *)0x0;
                  pPVar22 = (PyObject *)0x0;
LAB_00129dc4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
LAB_00129dec:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  if ((pPVar8 != (PyObject *)0x0) &&
                     (lVar24 = pPVar8->ob_refcnt + -1, pPVar8->ob_refcnt = lVar24, lVar24 == 0)) {
                    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                  }
LAB_00129e10:
                  __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.__init__",
                                     iVar3,iVar13,"moonraker/components/extensions.py");
                  if (pPVar18 == (PyObject *)0x0) {
                    pPVar8 = (PyObject *)0x0;
                  }
                  else {
LAB_00129e30:
                    pPVar8 = (PyObject *)0x0;
                    lVar24 = pPVar18->ob_refcnt + -1;
                    pPVar18->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
LAB_00129e44:
                      (*pPVar18->ob_type->tp_dealloc)(pPVar18);
                    }
                  }
                  if ((pPVar9 != (PyObject *)0x0) &&
                     (lVar24 = pPVar9->ob_refcnt + -1, pPVar9->ob_refcnt = lVar24, lVar24 == 0)) {
LAB_00129e68:
                    (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                  if (pPVar22 == (PyObject *)0x0) goto LAB_00129c70;
                }
                else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                  p_Var15 = pPVar7->ob_type;
                  if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var25 = pPVar7[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar22 = (PyObject *)pPVar7[1].ob_refcnt;
                    (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                    pPVar22->ob_refcnt = pPVar22->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = pPVar7->ob_refcnt + -1;
                    pPVar7->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*p_Var15->tp_dealloc)(pPVar7);
                    }
                    __pyx_pyargnames[1] =
                         (PyObject **)__pyx_mstate_global_static.__pyx_n_u_process_id;
                    pPVar8 = __pyx_mstate_global_static.__pyx_n_u_process_id;
                    __pyx_pyargnames[0] = (PyObject **)p_Var25;
                    pPVar18 = __Pyx_PyObject_FastCallDict
                                        (pPVar22,(PyObject **)__pyx_pyargnames,2,
                                         __pyx_mstate_global_static.__pyx_n_u_process_id);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var25->ob_base).ob_base.ob_refcnt = lVar24;
                    pPVar7 = pPVar22;
                    if (lVar24 == 0) {
                      (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] =
                         (PyObject **)__pyx_mstate_global_static.__pyx_n_u_process_id;
                    pPVar8 = __pyx_mstate_global_static.__pyx_n_u_process_id;
                    pPVar18 = __Pyx_PyObject_FastCallDict
                                        (pPVar7,(PyObject **)(__pyx_pyargnames + 1),1,
                                         __pyx_mstate_global_static.__pyx_n_u_process_id);
                  }
                  if (pPVar18 == (PyObject *)0x0) {
                    pPVar22 = (PyObject *)0x0;
                    pPVar9 = (PyObject *)0x0;
                    iVar13 = 0xd5;
                    iVar3 = 0x2b3b;
LAB_00129d90:
                    pPVar8 = (PyObject *)0x0;
                    pPVar21 = (PyObject *)0x0;
                    lVar24 = pPVar7->ob_refcnt + -1;
                    goto LAB_00129da0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar7->ob_refcnt + -1;
                  pPVar7->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar10->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar7 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar7 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_peer_cred);
                  }
                  if (pPVar7 == (PyObject *)0x0) {
                    pPVar9 = (PyObject *)0x0;
                    iVar3 = 0x2b49;
                    iVar13 = 0xd6;
                    pPVar22 = (PyObject *)0x0;
LAB_0012a208:
                    __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.__init__",
                                       iVar3,iVar13,"moonraker/components/extensions.py");
                    goto LAB_00129e30;
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar7->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar21 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar21 = (*p_Var14)(pPVar7,__pyx_mstate_global_static.__pyx_n_s_get);
                  }
                  lVar24 = pPVar7->ob_refcnt + -1;
                  if (pPVar21 == (PyObject *)0x0) {
                    pPVar9 = (PyObject *)0x0;
                    pPVar8 = (PyObject *)0x0;
                    pPVar22 = (PyObject *)0x0;
                    iVar13 = 0xd6;
                    iVar3 = 0x2b4b;
                    goto LAB_00129da0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar7->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                  }
                  p_Var15 = pPVar21->ob_type;
                  if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var25 = pPVar21[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar8 = (PyObject *)pPVar21[1].ob_refcnt;
                    (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                    pPVar8->ob_refcnt = pPVar8->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = pPVar21->ob_refcnt + -1;
                    pPVar21->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*p_Var15->tp_dealloc)(pPVar21);
                    }
                    __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_user_id;
                    __pyx_pyargnames[0] = (PyObject **)p_Var25;
                    pPVar9 = __Pyx_PyObject_FastCallDict
                                       (pPVar8,(PyObject **)__pyx_pyargnames,2,pPVar8);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var25->ob_base).ob_base.ob_refcnt = lVar24;
                    pPVar21 = pPVar8;
                    if (lVar24 == 0) {
                      (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_user_id;
                    pPVar9 = __Pyx_PyObject_FastCallDict
                                       (pPVar21,(PyObject **)(__pyx_pyargnames + 1),1,pPVar8);
                  }
                  if (pPVar9 == (PyObject *)0x0) {
                    pPVar22 = (PyObject *)0x0;
                    iVar13 = 0xd6;
                    iVar3 = 0x2b60;
LAB_0012a0a4:
                    pPVar8 = (PyObject *)0x0;
                    goto LAB_00129dc4;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar10->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar21 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar21 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_peer_cred);
                  }
                  if (pPVar21 == (PyObject *)0x0) {
                    iVar3 = 0x2b6e;
                    iVar13 = 0xd7;
                    pPVar22 = (PyObject *)0x0;
                    goto LAB_0012a208;
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar21->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar7 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar7 = (*p_Var14)(pPVar21,__pyx_mstate_global_static.__pyx_n_s_get);
                  }
                  if (pPVar7 == (PyObject *)0x0) {
                    iVar13 = 0xd7;
                    iVar3 = 0x2b70;
                    goto LAB_0012a15c;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                  p_Var15 = pPVar7->ob_type;
                  if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var25 = pPVar7[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar8 = (PyObject *)pPVar7[1].ob_refcnt;
                    (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                    pPVar8->ob_refcnt = pPVar8->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = pPVar7->ob_refcnt + -1;
                    pPVar7->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*p_Var15->tp_dealloc)(pPVar7);
                    }
                    __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_group_id
                    ;
                    __pyx_pyargnames[0] = (PyObject **)p_Var25;
                    pPVar22 = __Pyx_PyObject_FastCallDict
                                        (pPVar8,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var25)
                    ;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var25->ob_base).ob_base.ob_refcnt = lVar24;
                    pPVar7 = pPVar8;
                    if (lVar24 == 0) {
                      (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_u_group_id
                    ;
                    p_Var25 = (_typeobject *)__pyx_mstate_global_static.__pyx_n_u_group_id;
                    pPVar22 = __Pyx_PyObject_FastCallDict
                                        (pPVar7,(PyObject **)(__pyx_pyargnames + 1),1,
                                         __pyx_mstate_global_static.__pyx_n_u_group_id);
                  }
                  if (pPVar22 == (PyObject *)0x0) {
                    iVar13 = 0xd7;
                    iVar3 = 0x2b85;
                    goto LAB_00129d90;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar7->ob_refcnt + -1;
                  pPVar7->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar10->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar7 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar7 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_wsm);
                  }
                  if (pPVar7 == (PyObject *)0x0) {
                    iVar3 = 0x2b93;
                    iVar13 = 0xd8;
                    goto LAB_0012a208;
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar7->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar21 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar21 = (*p_Var14)(pPVar7,__pyx_mstate_global_static.__pyx_n_s_add_client);
                  }
                  lVar24 = pPVar7->ob_refcnt + -1;
                  if (pPVar21 == (PyObject *)0x0) {
                    pPVar8 = (PyObject *)0x0;
                    iVar13 = 0xd8;
                    iVar3 = 0x2b95;
                    goto LAB_00129da0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar7->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                  }
                  p_Var15 = pPVar21->ob_type;
                  if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var23 = pPVar21[1].ob_type, p_Var23 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar7 = (PyObject *)pPVar21[1].ob_refcnt;
                    (p_Var23->ob_base).ob_base.ob_refcnt = (p_Var23->ob_base).ob_base.ob_refcnt + 1;
                    pPVar7->ob_refcnt = pPVar7->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = pPVar21->ob_refcnt + -1;
                    pPVar21->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*p_Var15->tp_dealloc)(pPVar21);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var23;
                    __pyx_pyargnames[1] = (PyObject **)pPVar10;
                    pPVar8 = __Pyx_PyObject_FastCallDict
                                       (pPVar7,(PyObject **)__pyx_pyargnames,2,pPVar7);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var23->ob_base).ob_base.ob_refcnt = lVar24;
                    pPVar21 = pPVar7;
                    if (lVar24 == 0) {
                      (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)pPVar10;
                    pPVar8 = __Pyx_PyObject_FastCallDict
                                       (pPVar21,(PyObject **)(__pyx_pyargnames + 1),1,
                                        (PyObject *)p_Var25);
                  }
                  if (pPVar8 == (PyObject *)0x0) {
                    iVar13 = 0xd8;
                    iVar3 = 0x2baa;
                    goto LAB_0012a0a4;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar8->ob_refcnt + -1;
                  pPVar8->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                  }
                  pPVar21 = __pyx_dict_cached_value_18794;
                  if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_18793) {
                    if (__pyx_dict_cached_value_18794 == (PyObject *)0x0) {
                      pPVar21 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
                      goto LAB_0012a31c;
                    }
                    __pyx_dict_cached_value_18794->ob_refcnt =
                         __pyx_dict_cached_value_18794->ob_refcnt + 1;
                  }
                  else {
                    pPVar21 = __Pyx__GetModuleGlobalName
                                        (__pyx_mstate_global_static.__pyx_n_s_logging,
                                         (uint64_t *)&__pyx_dict_version_18793,
                                         &__pyx_dict_cached_value_18794);
LAB_0012a31c:
                    if (pPVar21 == (PyObject *)0x0) {
                      iVar3 = 0x2bb7;
                      iVar13 = 0xd9;
                      goto LAB_0012a208;
                    }
                  }
                  pPVar7 = __Pyx_PyObject_GetAttrStr
                                     (pPVar21,__pyx_mstate_global_static.__pyx_n_s_info);
                  if (pPVar7 == (PyObject *)0x0) {
                    iVar13 = 0xd9;
                    iVar3 = 0x2bb9;
                    goto LAB_0012a0a4;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                  pPVar21 = (PyObject *)PyTuple_New(8);
                  pPVar26 = __pyx_mstate_global_static.__pyx_n_s_uid;
                  pPVar8 = __pyx_mstate_global_static.__pyx_kp_u_Unix_Socket_Opened_Client_ID;
                  if (pPVar21 == (PyObject *)0x0) {
                    pPVar8 = (PyObject *)0x0;
                    iVar13 = 0xda;
                    iVar3 = 0x2bc4;
                    lVar24 = pPVar7->ob_refcnt + -1;
LAB_00129da0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar7->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                    }
                    if (pPVar21 != (PyObject *)0x0) goto LAB_00129dc4;
                    goto LAB_00129dec;
                  }
                  (__pyx_mstate_global_static.__pyx_kp_u_Unix_Socket_Opened_Client_ID)->ob_refcnt =
                       (__pyx_mstate_global_static.__pyx_kp_u_Unix_Socket_Opened_Client_ID)->
                       ob_refcnt + 1;
                  pPVar21[1].ob_type = (_typeobject *)pPVar8;
                  pPVar8 = __Pyx_PyObject_GetAttrStr(pPVar10,pPVar26);
                  if (pPVar8 == (PyObject *)0x0) {
                    iVar13 = 0xda;
                    iVar3 = 0x2bcc;
                    lVar24 = pPVar7->ob_refcnt + -1;
                    goto LAB_00129da0;
                  }
                  p_Var15 = pPVar8->ob_type;
                  if (p_Var15 == (_typeobject *)PTR_PyUnicode_Type_00143fb0) {
                    lVar24 = pPVar8->ob_refcnt;
                    pPVar26 = pPVar8;
                  }
                  else {
                    if ((p_Var15 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
                       (p_Var15 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
                      pPVar26 = (*p_Var15->tp_repr)(pPVar8);
                    }
                    else {
                      pPVar26 = (PyObject *)
                                PyObject_Format(pPVar8,__pyx_mstate_global_static.
                                                       __pyx_empty_unicode);
                    }
                    if (pPVar26 == (PyObject *)0x0) {
                      iVar13 = 0xda;
                      iVar3 = 0x2bce;
                      lVar24 = pPVar7->ob_refcnt + -1;
                      goto LAB_00129da0;
                    }
                    lVar24 = pPVar8->ob_refcnt + -1;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar8->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                  }
                  bVar1 = (byte)pPVar26[2].ob_refcnt;
                  uVar4 = 0x7f;
                  if ((bVar1 >> 6 & 1) == 0) {
                    bVar1 = bVar1 & 0x1c;
                    uVar4 = 0xff;
                    if ((bVar1 != 4) && (uVar4 = 0xffff, bVar1 != 8)) {
                      uVar4 = 0x10ffff;
                    }
                  }
                  p_Var15 = pPVar18->ob_type;
                  lVar24 = pPVar26[1].ob_refcnt;
                  pPVar21[2].ob_refcnt = (Py_ssize_t)pPVar26;
                  pPVar8 = __pyx_mstate_global_static.__pyx_kp_u_Process_ID;
                  bVar2 = p_Var15 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
                  (__pyx_mstate_global_static.__pyx_kp_u_Process_ID)->ob_refcnt =
                       (__pyx_mstate_global_static.__pyx_kp_u_Process_ID)->ob_refcnt + 1;
                  pPVar21[2].ob_type = (_typeobject *)pPVar8;
                  if (bVar2) {
                    pPVar18->ob_refcnt = pPVar18->ob_refcnt + 1;
                    pPVar8 = pPVar18;
                  }
                  else {
                    if ((p_Var15 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
                       (p_Var15 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
                      pPVar8 = (*p_Var15->tp_repr)(pPVar18);
                    }
                    else {
                      pPVar8 = (PyObject *)
                               PyObject_Format(pPVar18,__pyx_mstate_global_static.
                                                       __pyx_empty_unicode);
                    }
                    if (pPVar8 == (PyObject *)0x0) {
                      iVar13 = 0xdb;
                      iVar3 = 0x2be2;
                      lVar24 = pPVar7->ob_refcnt + -1;
                      pPVar8 = (PyObject *)0x0;
                      goto LAB_00129da0;
                    }
                  }
                  bVar1 = (byte)pPVar8[2].ob_refcnt;
                  uVar5 = 0x7f;
                  if ((bVar1 >> 6 & 1) == 0) {
                    bVar1 = bVar1 & 0x1c;
                    uVar5 = 0xff;
                    if ((bVar1 != 4) && (uVar5 = 0xffff, bVar1 != 8)) {
                      uVar5 = 0x10ffff;
                    }
                  }
                  if (uVar4 < uVar5) {
                    uVar4 = uVar5;
                  }
                  p_Var15 = pPVar9->ob_type;
                  lVar16 = pPVar8[1].ob_refcnt;
                  pPVar21[3].ob_refcnt = (Py_ssize_t)pPVar8;
                  pPVar8 = __pyx_mstate_global_static.__pyx_kp_u_User_ID;
                  bVar2 = p_Var15 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
                  (__pyx_mstate_global_static.__pyx_kp_u_User_ID)->ob_refcnt =
                       (__pyx_mstate_global_static.__pyx_kp_u_User_ID)->ob_refcnt + 1;
                  pPVar21[3].ob_type = (_typeobject *)pPVar8;
                  if (bVar2) {
                    pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    pPVar8 = pPVar9;
                  }
                  else {
                    if ((p_Var15 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
                       (p_Var15 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
                      pPVar8 = (*p_Var15->tp_repr)(pPVar9);
                    }
                    else {
                      pPVar8 = (PyObject *)
                               PyObject_Format(pPVar9,__pyx_mstate_global_static.__pyx_empty_unicode
                                              );
                    }
                    if (pPVar8 == (PyObject *)0x0) {
                      iVar13 = 0xdb;
                      iVar3 = 0x2bed;
                      lVar24 = pPVar7->ob_refcnt + -1;
                      pPVar8 = (PyObject *)0x0;
                      goto LAB_00129da0;
                    }
                  }
                  bVar1 = (byte)pPVar8[2].ob_refcnt;
                  uVar5 = 0x7f;
                  if ((bVar1 >> 6 & 1) == 0) {
                    bVar1 = bVar1 & 0x1c;
                    uVar5 = 0xff;
                    if ((bVar1 != 4) && (uVar5 = 0xffff, bVar1 != 8)) {
                      uVar5 = 0x10ffff;
                    }
                  }
                  lVar12 = pPVar8[1].ob_refcnt;
                  p_Var15 = pPVar22->ob_type;
                  pPVar21[4].ob_refcnt = (Py_ssize_t)pPVar8;
                  pPVar8 = __pyx_mstate_global_static.__pyx_kp_u_Group_ID;
                  bVar2 = p_Var15 == (_typeobject *)PTR_PyUnicode_Type_00143fb0;
                  (__pyx_mstate_global_static.__pyx_kp_u_Group_ID)->ob_refcnt =
                       (__pyx_mstate_global_static.__pyx_kp_u_Group_ID)->ob_refcnt + 1;
                  pPVar21[4].ob_type = (_typeobject *)pPVar8;
                  if (bVar2) {
                    pPVar22->ob_refcnt = pPVar22->ob_refcnt + 1;
                    pPVar8 = pPVar22;
                  }
                  else {
                    if ((p_Var15 == (_typeobject *)PTR_PyLong_Type_00143f70) ||
                       (p_Var15 == (_typeobject *)PTR_PyFloat_Type_00143eb0)) {
                      pPVar8 = (*p_Var15->tp_repr)(pPVar22);
                    }
                    else {
                      pPVar8 = (PyObject *)
                               PyObject_Format(pPVar22,__pyx_mstate_global_static.
                                                       __pyx_empty_unicode);
                    }
                    if (pPVar8 == (PyObject *)0x0) {
                      iVar13 = 0xdb;
                      iVar3 = 0x2bf8;
                      lVar24 = pPVar7->ob_refcnt + -1;
                      pPVar8 = (PyObject *)0x0;
                      goto LAB_00129da0;
                    }
                  }
                  bVar1 = (byte)pPVar8[2].ob_refcnt;
                  uVar6 = 0x7f;
                  if ((bVar1 >> 6 & 1) == 0) {
                    bVar1 = bVar1 & 0x1c;
                    uVar6 = 0xff;
                    if ((bVar1 != 4) && (uVar6 = 0xffff, bVar1 != 8)) {
                      uVar6 = 0x10ffff;
                    }
                  }
                  if (uVar5 < uVar6) {
                    uVar5 = uVar6;
                  }
                  lVar19 = pPVar8[1].ob_refcnt;
                  pPVar21[5].ob_refcnt = (Py_ssize_t)pPVar8;
                  if (uVar5 < uVar4) {
                    uVar5 = uVar4;
                  }
                  p_Var15 = (_typeobject *)(ulong)uVar5;
                  pPVar8 = __Pyx_PyUnicode_Join
                                     (pPVar21,8,lVar16 + lVar12 + lVar24 + 0x46 + lVar19,uVar5);
                  if (pPVar8 == (PyObject *)0x0) {
                    iVar13 = 0xda;
                    iVar3 = 0x2c07;
                    lVar24 = pPVar7->ob_refcnt + -1;
                    pPVar8 = (PyObject *)0x0;
                    goto LAB_00129da0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                  p_Var25 = pPVar7->ob_type;
                  if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var15 = pPVar7[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar26 = (PyObject *)pPVar7[1].ob_refcnt;
                    (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
                    pPVar26->ob_refcnt = pPVar26->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = pPVar7->ob_refcnt + -1;
                    pPVar7->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*p_Var25->tp_dealloc)(pPVar7);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var15;
                    __pyx_pyargnames[1] = (PyObject **)pPVar8;
                    pPVar21 = __Pyx_PyObject_FastCallDict
                                        (pPVar26,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var15
                                        );
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var15->ob_base).ob_base.ob_refcnt = lVar24;
                    pPVar7 = pPVar26;
                    if (lVar24 == 0) {
                      (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)pPVar8;
                    pPVar21 = __Pyx_PyObject_FastCallDict
                                        (pPVar7,(PyObject **)(__pyx_pyargnames + 1),1,
                                         (PyObject *)p_Var15);
                  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar8->ob_refcnt + -1;
                  pPVar8->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                  }
                  if (pPVar21 == (PyObject *)0x0) {
                    iVar13 = 0xd9;
                    iVar3 = 0x2c1d;
                    goto LAB_00129d90;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar7->ob_refcnt + -1;
                  pPVar7->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar21->ob_refcnt + -1;
                  pPVar21->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
                  }
                  pPVar7 = __Pyx_PyObject_GetAttrStr
                                     (pPVar10,__pyx_mstate_global_static.__pyx_n_s_eventloop);
                  if (pPVar7 == (PyObject *)0x0) {
                    iVar3 = 0x2c2a;
                    iVar13 = 0xdd;
                    goto LAB_0012a208;
                  }
                  pPVar8 = __Pyx_PyObject_GetAttrStr
                                     (pPVar7,__pyx_mstate_global_static.__pyx_n_s_register_callback)
                  ;
                  if (pPVar8 == (PyObject *)0x0) {
                    pPVar8 = (PyObject *)0x0;
                    iVar13 = 0xdd;
                    iVar3 = 0x2c2c;
                    lVar24 = pPVar7->ob_refcnt + -1;
                    pPVar21 = (PyObject *)0x0;
                    goto LAB_00129da0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar7->ob_refcnt + -1;
                  pPVar7->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                  }
                  pPVar10 = __Pyx_PyObject_GetAttrStr
                                      (pPVar10,__pyx_mstate_global_static.__pyx_n_s_read_messages);
                  if (pPVar10 == (PyObject *)0x0) {
                    iVar3 = 0x2c2f;
LAB_0012a5bc:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    iVar13 = 0xdd;
                    lVar24 = pPVar8->ob_refcnt + -1;
                    pPVar8->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                    }
                    goto LAB_00129e10;
                  }
                  p_Var25 = pPVar8->ob_type;
                  if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_00143ea0) &&
                     (p_Var23 = pPVar8[1].ob_type, p_Var23 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar7 = (PyObject *)pPVar8[1].ob_refcnt;
                    (p_Var23->ob_base).ob_base.ob_refcnt = (p_Var23->ob_base).ob_base.ob_refcnt + 1;
                    pPVar7->ob_refcnt = pPVar7->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = pPVar8->ob_refcnt + -1;
                    pPVar8->ob_refcnt = lVar24;
                    if (lVar24 == 0) {
                      (*p_Var25->tp_dealloc)(pPVar8);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var23;
                    __pyx_pyargnames[1] = (PyObject **)pPVar10;
                    __pyx_pyargnames[2] = (PyObject **)pPVar11;
                    pPVar11 = __Pyx_PyObject_FastCallDict
                                        (pPVar7,(PyObject **)__pyx_pyargnames,3,(PyObject *)p_Var15)
                    ;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar24 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var23->ob_base).ob_base.ob_refcnt = lVar24;
                    pPVar8 = pPVar7;
                    if (lVar24 == 0) {
                      (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)pPVar10;
                    __pyx_pyargnames[2] = (PyObject **)pPVar11;
                    pPVar11 = __Pyx_PyObject_FastCallDict
                                        (pPVar8,(PyObject **)(__pyx_pyargnames + 1),2,
                                         (PyObject *)p_Var15);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar10->ob_refcnt + -1;
                  pPVar10->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                  }
                  if (pPVar11 == (PyObject *)0x0) {
                    iVar3 = 0x2c44;
                    goto LAB_0012a5bc;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar8->ob_refcnt + -1;
                  pPVar8->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar11->ob_refcnt + -1;
                  pPVar11->ob_refcnt = lVar24;
                  if (lVar24 == 0) {
                    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                  }
                  pPVar8 = (PyObject *)PTR__Py_NoneStruct_00143f40;
                  *(long *)PTR__Py_NoneStruct_00143f40 = *(long *)PTR__Py_NoneStruct_00143f40 + 1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar18->ob_refcnt + -1;
                  pPVar18->ob_refcnt = lVar24;
                  if (lVar24 == 0) goto LAB_00129e44;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar24 = pPVar9->ob_refcnt + -1;
                  pPVar9->ob_refcnt = lVar24;
                  if (lVar24 == 0) goto LAB_00129e68;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar24 = pPVar22->ob_refcnt + -1;
                pPVar22->ob_refcnt = lVar24;
                if (lVar24 == 0) {
                  (*pPVar22->ob_type->tp_dealloc)(pPVar22);
                }
                goto LAB_00129c70;
              }
              iVar3 = 0x2b24;
              iVar13 = 0xd5;
            }
          }
        }
      }
LAB_00129ce0:
      pPVar8 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.__init__",iVar3,iVar13,
                         "moonraker/components/extensions.py");
      goto LAB_00129c70;
    }
    if (2 < __pyx_nargs) {
      if (__pyx_nargs == 4) {
LAB_00128ee0:
        values[3] = __pyx_args[3];
      }
      else if (3 < __pyx_nargs) {
        if (__pyx_nargs != 5) goto LAB_00129c18;
        values[4] = __pyx_args[4];
        goto LAB_00128ee0;
      }
      values[2] = __pyx_args[2];
      goto LAB_00128ef0;
    }
    if (__pyx_nargs == 0) {
      lVar24 = __pyx_kwds[1].ob_refcnt;
LAB_00129bf4:
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
      if (values[0] == (PyObject *)0x0) {
        lVar24 = PyErr_Occurred();
        if (lVar24 == 0) goto LAB_00129c18;
        iVar3 = 0x2a52;
        goto LAB_00129c54;
      }
      lVar24 = lVar24 + -1;
    }
    else {
      if (__pyx_nargs != 1) goto LAB_00129c18;
      lVar24 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
    }
LAB_00129b58:
    values[1] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_server);
    if (values[1] == (PyObject *)0x0) {
      lVar24 = PyErr_Occurred();
      if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                     "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                     "exactly",5,"s",1);
        iVar3 = 0x2a5c;
      }
      else {
        iVar3 = 0x2a5a;
      }
      goto LAB_00129c54;
    }
    lVar24 = lVar24 + -1;
LAB_00129b78:
    values[2] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_reader);
    if (values[2] == (PyObject *)0x0) {
      lVar24 = PyErr_Occurred();
      if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                     "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                     "exactly",5,"s",2);
        iVar3 = 0x2a66;
      }
      else {
        iVar3 = 0x2a64;
      }
    }
    else {
      lVar24 = lVar24 + -1;
LAB_00129b98:
      values[3] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_writer);
      if (values[3] == (PyObject *)0x0) {
        lVar24 = PyErr_Occurred();
        if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
          PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                       "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                       "exactly",5,"s",3);
          iVar3 = 0x2a70;
        }
        else {
          iVar3 = 0x2a6e;
        }
      }
      else {
        lVar24 = lVar24 + -1;
LAB_00128f20:
        values[4] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_peercred);
        if (values[4] != (PyObject *)0x0) {
          lVar24 = lVar24 + -1;
          goto LAB_00128f40;
        }
        lVar24 = PyErr_Occurred();
        if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
          PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00143ee0,
                       "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                       "exactly",5,"s",4);
          iVar3 = 0x2a7a;
        }
        else {
          iVar3 = 0x2a78;
        }
      }
    }
  }
LAB_00129c54:
  pPVar8 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.extensions.UnixSocketClient.__init__",iVar3,0xca,
                     "moonraker/components/extensions.py");
LAB_00129c70:
  if (lVar20 != *(long *)PTR___stack_chk_guard_00143f20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar8;
}


/* Successfully decompiled 31 of 31 selected functions. */
