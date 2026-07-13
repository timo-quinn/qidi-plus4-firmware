/*
 * Reverse-engineered Ghidra output. This is not original source code.
 * Program: frp_manager.so
 * Language: AARCH64:LE:64:v8A
 * Selected named functions: 22
 */


/* ================================================================
 * Address: 00106864
 * Symbol:  __pyx_pymod_exec_frp_manager
 * Signature: int __pyx_pymod_exec_frp_manager(PyObject * __pyx_pyinit_module)
 * ================================================================ */

int __pyx_pymod_exec_frp_manager(PyObject *__pyx_pyinit_module)

{
  byte bVar1;
  uint uVar2;
  Py_ssize_t *pPVar3;
  undefined *puVar4;
  PyObject *pPVar5;
  bool bVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  long *plVar12;
  long *plVar13;
  long *plVar14;
  PyObject *pPVar15;
  ulong uVar16;
  PyObject *extraout_x1;
  PyObject *extraout_x1_00;
  PyObject *extraout_x1_01;
  PyObject *extraout_x1_02;
  PyObject *extraout_x1_03;
  PyObject *extraout_x1_04;
  PyObject *extraout_x1_05;
  PyObject *extraout_x1_06;
  PyObject *extraout_x1_07;
  PyObject *extraout_x1_08;
  PyObject *extraout_x1_09;
  PyObject *extraout_x1_10;
  long lVar17;
  ulong uVar18;
  _typeobject *p_Var19;
  int iVar20;
  PyObject *pPVar21;
  ulong uVar22;
  undefined1 auVar23 [16];
  undefined8 in_stack_fffffffffffffe50;
  undefined4 uVar24;
  PyObject *margs [4];
  char message [200];
  
                    /* Unresolved local var: int stringtab_initialized@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  uVar24 = (undefined4)((ulong)in_stack_fffffffffffffe50 >> 0x20);
  lVar17 = *(long *)PTR___stack_chk_guard_00137f30;
  if (__pyx_m != (PyObject *)0x0) {
    iVar7 = 0;
    if (__pyx_m != __pyx_pyinit_module) {
      PyErr_SetString(*(undefined8 *)PTR_PyExc_RuntimeError_00137ee0,
                      "Module \'frp_manager\' has already been imported. Re-initialisation is not supported."
                      ,0);
      iVar7 = -1;
    }
    goto LAB_0010849c;
  }
  __pyx_m = __pyx_pyinit_module;
  __pyx_pyinit_module->ob_refcnt = __pyx_pyinit_module->ob_refcnt + 1;
  __pyx_mstate_global_static.__pyx_d = (PyObject *)PyModule_GetDict();
  if (__pyx_mstate_global_static.__pyx_d == (PyObject *)0x0) {
    iVar20 = 0x3639;
    iVar7 = 1;
    bVar6 = false;
LAB_001076f8:
    if (__pyx_m == (PyObject *)0x0) {
      lVar8 = PyErr_Occurred();
      if (lVar8 == 0) {
        PyErr_SetString(*(undefined8 *)PTR_PyExc_ImportError_00137f90,
                        "init moonraker.components.frp_manager");
      }
    }
    else {
      if ((__pyx_mstate_global_static.__pyx_d != (PyObject *)0x0) && (bVar6)) {
        __Pyx_AddTraceback("init moonraker.components.frp_manager",iVar20,iVar7,
                           "moonraker/components/frp_manager.py");
      }
                    /* Unresolved local var: PyObject * _py_tmp@[???] */
      pPVar21 = __pyx_m;
      if (__pyx_m != (PyObject *)0x0) {
        pPVar3 = &__pyx_m->ob_refcnt;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        __pyx_m = (PyObject *)0x0;
        lVar8 = *pPVar3 + -1;
        pPVar21->ob_refcnt = lVar8;
        if (lVar8 == 0) {
          (*pPVar21->ob_type->tp_dealloc)(pPVar21);
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
      iVar20 = 0x363b;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    (__pyx_mstate_global_static.__pyx_b)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_b)->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * module@[???] */
    __pyx_mstate_global_static.__pyx_cython_runtime =
         (PyObject *)PyImport_AddModule("cython_runtime");
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (__pyx_mstate_global_static.__pyx_cython_runtime == (PyObject *)0x0) {
      iVar20 = 0x363c;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt + 1;
    iVar7 = PyObject_SetAttrString(__pyx_m,"__builtins__",__pyx_mstate_global_static.__pyx_b);
    if (iVar7 < 0) {
      iVar20 = 0x363d;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
                    /* Unresolved local var: char * rt_version@[???]
                       Unresolved local var: ulong version@[???]
                       Unresolved local var: ulong factor@[???]
                       Unresolved local var: wchar_t digit@[???]
                       Unresolved local var: int i@[???] */
    lVar8 = Py_GetVersion();
    iVar20 = 4;
    iVar7 = 0;
    uVar22 = 0;
    uVar18 = 0x1000000;
    do {
      uVar16 = 0;
      while (bVar1 = *(byte *)(lVar8 + iVar7), (byte)(bVar1 - 0x30) < 10) {
        iVar7 = iVar7 + 1;
        uVar16 = (ulong)(((uint)bVar1 + (int)uVar16 * 10) - 0x30);
      }
      uVar22 = uVar22 + uVar16 * uVar18;
      if (bVar1 != 0x2e) break;
      uVar18 = uVar18 >> 8;
      iVar7 = iVar7 + 1;
      iVar20 = iVar20 + -1;
    } while (iVar20 != 0);
                    /* Unresolved local var: ulong MAJOR_MINOR@[???] */
    if (((uVar22 ^ 0x3070000) & 0xffff0000) != 0) {
      PyOS_snprintf(message,200,
                    "compile time Python version %d.%d of module \'%.100s\' %s runtime version %d.%d"
                    ,3,7,"moonraker.components.frp_manager","does not match",
                    uVar22 >> 0x18 & 0xffffffff,
                    CONCAT44(uVar24,(uint)uVar22 >> 0x10) & 0xffffffff000000ff);
      iVar7 = PyErr_WarnEx(0,message,1);
      if (iVar7 < 0) {
        iVar20 = 0x3648;
        iVar7 = 1;
        bVar6 = false;
        goto LAB_001076f8;
      }
    }
    __pyx_pyframe_localsplus_offset = *(long *)(PTR_PyFrame_Type_00137f80 + 0x20) - 8;
    __pyx_mstate_global_static.__pyx_empty_tuple = (PyObject *)PyTuple_New(0);
    if (__pyx_mstate_global_static.__pyx_empty_tuple == (PyObject *)0x0) {
      iVar20 = 0x364c;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    __pyx_mstate_global_static.__pyx_empty_bytes = (PyObject *)PyBytes_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_bytes == (PyObject *)0x0) {
      iVar20 = 0x364d;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    __pyx_mstate_global_static.__pyx_empty_unicode = (PyObject *)PyUnicode_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_unicode == (PyObject *)0x0) {
      iVar20 = 0x364e;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    __pyx_mstate_global_static.__pyx_CyFunctionType =
         __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (__pyx_mstate_global_static.__pyx_CyFunctionType == (PyTypeObject *)0x0) {
      iVar20 = 0x3650;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    __pyx_CoroutineType_type.tp_getattro = (getattrofunc)PTR_PyObject_GenericGetAttr_00137f38;
    __pyx_mstate_global_static.__pyx_CoroutineType =
         __Pyx_FetchCommonType(&__pyx_CoroutineType_type);
    if ((__pyx_mstate_global_static.__pyx_CoroutineType == (PyTypeObject *)0x0) ||
       (__pyx_mstate_global_static.__pyx_CoroutineAwaitType =
             __Pyx_FetchCommonType(&__pyx_CoroutineAwaitType_type),
       __pyx_mstate_global_static.__pyx_CoroutineAwaitType == (PyTypeObject *)0x0)) {
      iVar20 = 0x3656;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    iVar7 = __Pyx_CreateStringTabAndInitStrings();
    if ((((iVar7 < 0) ||
         (__pyx_mstate_global_static.__pyx_int_0 = (PyObject *)PyLong_FromLong(0),
         __pyx_mstate_global_static.__pyx_int_0 == (PyObject *)0x0)) ||
        (__pyx_mstate_global_static.__pyx_int_3 = (PyObject *)PyLong_FromLong(3),
        __pyx_mstate_global_static.__pyx_int_3 == (PyObject *)0x0)) ||
       ((__pyx_mstate_global_static.__pyx_int_neg_1 =
              (PyObject *)PyLong_FromLong(0xffffffffffffffff),
        __pyx_mstate_global_static.__pyx_int_neg_1 == (PyObject *)0x0 ||
        (__pyx_mstate_global_static.__pyx_int_neg_5 =
              (PyObject *)PyLong_FromLong(0xfffffffffffffffb),
        __pyx_mstate_global_static.__pyx_int_neg_5 == (PyObject *)0x0)))) {
      iVar20 = 0x3667;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_001076f8;
    }
    if ((*(int *)PTR___pyx_module_is_main_moonraker__components__frp_manager_00137eb0 != 0) &&
       (iVar7 = PyObject_SetAttr(__pyx_m,__pyx_mstate_global_static.__pyx_n_s_name,
                                 __pyx_mstate_global_static.__pyx_n_s_main), iVar7 < 0)) {
      iVar7 = 1;
      iVar20 = 0x366e;
      bVar6 = true;
      goto LAB_001076f8;
    }
                    /* Unresolved local var: PyObject * modules@[???] */
    lVar8 = PyImport_GetModuleDict();
    if (lVar8 == 0) {
      iVar7 = 1;
      iVar20 = 0x3672;
      bVar6 = true;
      goto LAB_001076f8;
    }
    lVar9 = PyDict_GetItemString(lVar8,"moonraker.components.frp_manager");
    if ((lVar9 == 0) &&
       (iVar7 = PyDict_SetItemString(lVar8,"moonraker.components.frp_manager",__pyx_m), iVar7 < 0))
    {
      iVar7 = 1;
      iVar20 = 0x3674;
      bVar6 = true;
      goto LAB_001076f8;
    }
    __pyx_mstate_global_static.__pyx_tuple__2 =
         (PyObject *)
         PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_u_command,
                      __pyx_mstate_global_static.__pyx_n_u_status);
    puVar4 = PTR__Py_NoneStruct_00137f48;
    if (((((((__pyx_mstate_global_static.__pyx_tuple__2 == (PyObject *)0x0) ||
            (__pyx_mstate_global_static.__pyx_tuple__6 =
                  (PyObject *)
                  PyTuple_Pack(3,PTR__Py_NoneStruct_00137f48,PTR__Py_NoneStruct_00137f48,
                               PTR__Py_NoneStruct_00137f48),
            __pyx_mstate_global_static.__pyx_tuple__6 == (PyObject *)0x0)) ||
           (__pyx_mstate_global_static.__pyx_slice__17 =
                 (PyObject *)PySlice_New(__pyx_mstate_global_static.__pyx_int_neg_5,puVar4,puVar4),
           __pyx_mstate_global_static.__pyx_slice__17 == (PyObject *)0x0)) ||
          (((__pyx_mstate_global_static.__pyx_tuple__20 =
                  (PyObject *)
                  PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                               __pyx_mstate_global_static.__pyx_n_s_config),
            __pyx_mstate_global_static.__pyx_tuple__20 == (PyObject *)0x0 ||
            (__pyx_mstate_global_static.__pyx_codeobj__21 =
                  (PyObject *)
                  PyCode_New(2,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__20,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.
                             __pyx_kp_s_moonraker_components_frp_manager_2,
                             __pyx_mstate_global_static.__pyx_n_s_init,9,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__21 == (PyObject *)0x0)) ||
           ((__pyx_mstate_global_static.__pyx_tuple__22 =
                  (PyObject *)
                  PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                               __pyx_mstate_global_static.__pyx_n_s_web_request,
                               __pyx_mstate_global_static.__pyx_n_s_command),
            __pyx_mstate_global_static.__pyx_tuple__22 == (PyObject *)0x0 ||
            ((__pyx_mstate_global_static.__pyx_codeobj_ =
                   (PyObject *)
                   PyCode_New(2,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_tuple__22,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.__pyx_empty_tuple,
                              __pyx_mstate_global_static.
                              __pyx_kp_s_moonraker_components_frp_manager_2,
                              __pyx_mstate_global_static.__pyx_n_s_handle_frp_control,0x1f,
                              __pyx_mstate_global_static.__pyx_empty_bytes),
             __pyx_mstate_global_static.__pyx_codeobj_ == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_tuple__23 =
                   (PyObject *)
                   PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                                __pyx_mstate_global_static.__pyx_n_s_web_request,
                                __pyx_mstate_global_static.__pyx_n_s_status),
             __pyx_mstate_global_static.__pyx_tuple__23 == (PyObject *)0x0)))))))) ||
         (__pyx_mstate_global_static.__pyx_codeobj__3 =
               (PyObject *)
               PyCode_New(2,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_tuple__23,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2,
                          __pyx_mstate_global_static.__pyx_n_s_handle_frp_update,0x24,
                          __pyx_mstate_global_static.__pyx_empty_bytes),
         __pyx_mstate_global_static.__pyx_codeobj__3 == (PyObject *)0x0)) ||
        ((((__pyx_mstate_global_static.__pyx_tuple__24 =
                 (PyObject *)
                 PyTuple_Pack(4,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_topic,
                              __pyx_mstate_global_static.__pyx_n_s_message,
                              __pyx_mstate_global_static.__pyx_n_s_command),
           __pyx_mstate_global_static.__pyx_tuple__24 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_codeobj__4 =
                 (PyObject *)
                 PyCode_New(3,0,4,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__24,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2
                            ,__pyx_mstate_global_static.__pyx_n_s_handle_mqtt_command,0x2f,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__4 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_tuple__25 =
                (PyObject *)
                PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                             __pyx_mstate_global_static.__pyx_n_s_command),
          __pyx_mstate_global_static.__pyx_tuple__25 == (PyObject *)0x0)) ||
         (((__pyx_mstate_global_static.__pyx_codeobj__5 =
                 (PyObject *)
                 PyCode_New(2,0,2,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__25,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2
                            ,__pyx_mstate_global_static.__pyx_n_s_process_command,0x34,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__5 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_tuple__26 =
                 (PyObject *)
                 PyTuple_Pack(9,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_command,
                              __pyx_mstate_global_static.__pyx_n_s_args,
                              __pyx_mstate_global_static.__pyx_n_s_cmd,
                              __pyx_mstate_global_static.__pyx_n_s_process,
                              __pyx_mstate_global_static.__pyx_n_s_stdout,
                              __pyx_mstate_global_static.__pyx_n_s_stderr,
                              __pyx_mstate_global_static.__pyx_n_s_returncode,
                              __pyx_mstate_global_static.__pyx_n_s_e),
           __pyx_mstate_global_static.__pyx_tuple__26 == (PyObject *)0x0)) ||
          ((__pyx_mstate_global_static.__pyx_codeobj__7 =
                 (PyObject *)
                 PyCode_New(3,0,9,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__26,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2
                            ,__pyx_mstate_global_static.__pyx_n_s_run_systemctl_command,0x46,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__7 == (PyObject *)0x0 ||
           ((__pyx_mstate_global_static.__pyx_tuple__27 =
                  (PyObject *)PyTuple_Pack(1,PTR__Py_NoneStruct_00137f48),
            __pyx_mstate_global_static.__pyx_tuple__27 == (PyObject *)0x0 ||
            (__pyx_mstate_global_static.__pyx_tuple__28 =
                  (PyObject *)
                  PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                               __pyx_mstate_global_static.__pyx_n_s_result,
                               __pyx_mstate_global_static.__pyx_n_s_error_msg),
            __pyx_mstate_global_static.__pyx_tuple__28 == (PyObject *)0x0)))))))))) ||
       ((__pyx_mstate_global_static.__pyx_codeobj__10 =
              (PyObject *)
              PyCode_New(1,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                         __pyx_mstate_global_static.__pyx_empty_tuple,
                         __pyx_mstate_global_static.__pyx_empty_tuple,
                         __pyx_mstate_global_static.__pyx_tuple__28,
                         __pyx_mstate_global_static.__pyx_empty_tuple,
                         __pyx_mstate_global_static.__pyx_empty_tuple,
                         __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2,
                         __pyx_mstate_global_static.__pyx_n_s_start_frp_service,0x69,
                         __pyx_mstate_global_static.__pyx_empty_bytes),
        __pyx_mstate_global_static.__pyx_codeobj__10 == (PyObject *)0x0 ||
        (((((__pyx_mstate_global_static.__pyx_codeobj__11 =
                  (PyObject *)
                  PyCode_New(1,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__28,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.
                             __pyx_kp_s_moonraker_components_frp_manager_2,
                             __pyx_mstate_global_static.__pyx_n_s_stop_frp_service,0x75,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__11 == (PyObject *)0x0 ||
            (__pyx_mstate_global_static.__pyx_codeobj__12 =
                  (PyObject *)
                  PyCode_New(1,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__28,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.
                             __pyx_kp_s_moonraker_components_frp_manager_2,
                             __pyx_mstate_global_static.__pyx_n_s_restart_frp_service,0x81,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__12 == (PyObject *)0x0)) ||
           (__pyx_mstate_global_static.__pyx_codeobj__13 =
                 (PyObject *)
                 PyCode_New(1,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__28,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2
                            ,__pyx_mstate_global_static.__pyx_n_s_enable_frp_service,0x8d,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__13 == (PyObject *)0x0)) ||
          ((__pyx_mstate_global_static.__pyx_codeobj__14 =
                 (PyObject *)
                 PyCode_New(1,0,3,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__28,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2
                            ,__pyx_mstate_global_static.__pyx_n_s_disable_frp_service,0x99,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__14 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_tuple__29 =
                 (PyObject *)
                 PyTuple_Pack(0xb,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_status_result,
                              __pyx_mstate_global_static.__pyx_n_s_enabled_result,
                              __pyx_mstate_global_static.__pyx_n_s_show_result,
                              __pyx_mstate_global_static.__pyx_n_s_status,
                              __pyx_mstate_global_static.__pyx_n_s_enabled,
                              __pyx_mstate_global_static.__pyx_n_s_result,
                              __pyx_mstate_global_static.__pyx_n_s_journal_process,
                              __pyx_mstate_global_static.__pyx_n_s_journal_stdout,
                              __pyx_mstate_global_static.__pyx_n_s_journal_stderr,
                              __pyx_mstate_global_static.__pyx_n_s_e),
           __pyx_mstate_global_static.__pyx_tuple__29 == (PyObject *)0x0)))) ||
         ((__pyx_mstate_global_static.__pyx_codeobj__15 =
                (PyObject *)
                PyCode_New(1,0,0xb,0,0x83,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__29,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2,
                           __pyx_mstate_global_static.__pyx_n_s_get_frp_service_status,0xa5,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__15 == (PyObject *)0x0 ||
          ((__pyx_mstate_global_static.__pyx_tuple__30 =
                 (PyObject *)PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_n_s_config),
           __pyx_mstate_global_static.__pyx_tuple__30 == (PyObject *)0x0 ||
           (pPVar21 = __pyx_mstate_global_static.__pyx_empty_tuple,
           __pyx_mstate_global_static.__pyx_codeobj__31 =
                (PyObject *)
                PyCode_New(1,0,1,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__30,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_moonraker_components_frp_manager_2,
                           __pyx_mstate_global_static.__pyx_n_s_load_component,0xe9,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__31 == (PyObject *)0x0)))))))))) {
      iVar7 = 1;
      iVar20 = 0x367b;
      bVar6 = true;
      goto LAB_001076f8;
    }
                    /* Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct___handle_frp_control =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct___handle_frp_control;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct___handle_frp_control
                              );
    if (iVar7 < 0) {
LAB_00107204:
      iVar7 = 1;
      iVar20 = 0x3680;
      bVar6 = true;
      goto LAB_001076f8;
    }
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_1__handle_frp_update =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_1__handle_frp_update;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_1__handle_frp_update
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_2__handle_mqtt_command =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_2__handle_mqtt_command
    ;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_2__handle_mqtt_command
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_3__process_command =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_3__process_command;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_3__process_command
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_4__run_systemctl_command =
         &
         __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_4__run_systemctl_command
    ;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_4__run_systemctl_command
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_5_start_frp_service =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_5_start_frp_service;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_5_start_frp_service
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_6_stop_frp_service =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_6_stop_frp_service;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_6_stop_frp_service
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_7_restart_frp_service =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_7_restart_frp_service;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_7_restart_frp_service
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_8_enable_frp_service =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_8_enable_frp_service;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_8_enable_frp_service
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_9_disable_frp_service =
         &__pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_9_disable_frp_service;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_9_disable_frp_service
                              );
    if (iVar7 < 0) goto LAB_00107204;
    __pyx_mstate_global_static.
    __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_10_get_frp_service_status =
         &
         __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_10_get_frp_service_status
    ;
    iVar7 = __Pyx_PyType_Ready(&
                               __pyx_type_9moonraker_10components_11frp_manager___pyx_scope_struct_10_get_frp_service_status
                              );
    if (iVar7 < 0) goto LAB_00107204;
    pPVar11 = extraout_x1;
    if (abc_patched_19624 == 0) {
                    /* Unresolved local var: PyObject * module@[???] */
      auVar23 = PyImport_ImportModule("collections.abc");
      if (auVar23._0_8_ == (PyObject *)0x0) {
        PyErr_WriteUnraisable();
        iVar7 = PyErr_WarnEx(*(undefined8 *)PTR_PyExc_RuntimeWarning_00137fa8,
                             "Cython module failed to register with collections.abc module",1);
        if (-1 < iVar7) {
LAB_00107340:
          auVar23 = PyImport_ImportModule("backports_abc");
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if ((auVar23._0_8_ == (PyObject *)0x0) ||
             (pPVar10 = __Pyx_Coroutine_patch_module(auVar23._0_8_,auVar23._8_8_),
             pPVar10 == (PyObject *)0x0)) {
            PyErr_Clear();
            pPVar11 = extraout_x1_10;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar8 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar8;
            pPVar11 = extraout_x1_00;
            if (lVar8 == 0) {
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
              pPVar11 = extraout_x1_01;
            }
          }
          goto LAB_00107374;
        }
      }
      else {
        pPVar11 = __Pyx_Coroutine_patch_module(auVar23._0_8_,auVar23._8_8_);
        abc_patched_19624 = 1;
        if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar8 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar8;
          if (lVar8 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          goto LAB_00107340;
        }
      }
      iVar7 = 1;
      iVar20 = 0x3686;
      bVar6 = true;
      goto LAB_001076f8;
    }
LAB_00107374:
    pPVar11 = __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_os,pPVar11);
    if (pPVar11 == (PyObject *)0x0) {
      iVar7 = 1;
      iVar20 = 0x368e;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_os,pPVar11);
    if (iVar7 < 0) {
      pPVar10 = (PyObject *)0x0;
      iVar20 = 0x3690;
      iVar7 = 1;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar8;
    pPVar10 = extraout_x1_02;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      pPVar10 = extraout_x1_03;
    }
    pPVar11 = __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_json,pPVar10);
    if (pPVar11 == (PyObject *)0x0) {
      iVar20 = 0x3699;
      iVar7 = 2;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_json,pPVar11);
    if (iVar7 < 0) {
      pPVar10 = (PyObject *)0x0;
      iVar20 = 0x369b;
      iVar7 = 2;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar8;
    pPVar10 = extraout_x1_04;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      pPVar10 = extraout_x1_05;
    }
    pPVar11 = __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_subprocess,pPVar10);
    if (pPVar11 == (PyObject *)0x0) {
      iVar20 = 0x36a5;
      iVar7 = 3;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_subprocess,pPVar11);
    if (iVar7 < 0) {
      pPVar10 = (PyObject *)0x0;
      iVar20 = 0x36a7;
      iVar7 = 3;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar8;
    pPVar10 = extraout_x1_06;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      pPVar10 = extraout_x1_07;
    }
    pPVar11 = __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_logging,pPVar10);
    if (pPVar11 == (PyObject *)0x0) {
      iVar20 = 0x36b1;
      iVar7 = 4;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_logging,pPVar11);
    if (iVar7 < 0) {
      pPVar10 = (PyObject *)0x0;
      iVar20 = 0x36b3;
      iVar7 = 4;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar8;
    pPVar10 = extraout_x1_08;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      pPVar10 = extraout_x1_09;
    }
    pPVar11 = __Pyx_ImportDottedModule(__pyx_mstate_global_static.__pyx_n_s_asyncio,pPVar10);
    if (pPVar11 == (PyObject *)0x0) {
      iVar20 = 0x36bd;
      iVar7 = 5;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_asyncio,pPVar11);
    if (iVar7 < 0) {
      pPVar10 = (PyObject *)0x0;
      iVar20 = 0x36bf;
      iVar7 = 5;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(1);
    pPVar10 = __pyx_mstate_global_static.__pyx_n_s_ConfigHelper;
    if (pPVar11 == (PyObject *)0x0) {
      iVar20 = 0x36c9;
      iVar7 = 6;
      bVar6 = true;
      goto LAB_001076f8;
    }
    p_Var19 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_n_s_ConfigHelper)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_ConfigHelper)->ob_refcnt + 1;
    (p_Var19->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar10;
    pPVar10 = __pyx_mstate_global_static.__pyx_n_s_confighelper;
                    /* Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * empty_dict@[???]
                       Unresolved local var: PyObject * empty_list@[???] */
    plVar12 = (long *)PyDict_New();
    if (plVar12 == (long *)0x0) {
      pPVar10 = (PyObject *)0x0;
      iVar20 = 0x36ce;
      iVar7 = 6;
LAB_00107840:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar8 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar8;
      if (lVar8 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      pPVar15 = (PyObject *)0x0;
      if (pPVar10 != (PyObject *)0x0) {
LAB_0010830c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar8 = pPVar10->ob_refcnt + -1;
        pPVar10->ob_refcnt = lVar8;
        if (lVar8 == 0) {
          (*pPVar10->ob_type->tp_dealloc)(pPVar10);
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((pPVar15 != (PyObject *)0x0) &&
           (lVar8 = pPVar15->ob_refcnt + -1, pPVar15->ob_refcnt = lVar8, lVar8 == 0)) {
          (*pPVar15->ob_type->tp_dealloc)(pPVar15);
          bVar6 = true;
          goto LAB_001076f8;
        }
      }
      bVar6 = true;
      goto LAB_001076f8;
    }
    pPVar10 = (PyObject *)
              PyImport_ImportModuleLevelObject
                        (pPVar10,__pyx_mstate_global_static.__pyx_d,plVar12,pPVar11,2);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = *plVar12;
    *plVar12 = lVar8 + -1;
    if (lVar8 + -1 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (pPVar10 == (PyObject *)0x0) {
      iVar20 = 0x36ce;
      iVar7 = 6;
      goto LAB_00107840;
    }
    lVar8 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar15 = __pyx_mstate_global_static.__pyx_n_s_ConfigHelper;
                    /* Unresolved local var: PyObject * value@[???] */
    pPVar11 = __Pyx_PyObject_GetAttrStr(pPVar10,__pyx_mstate_global_static.__pyx_n_s_ConfigHelper);
    if (pPVar11 == (PyObject *)0x0) {
      iVar7 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_AttributeError_00137f98);
      if (iVar7 != 0) {
                    /* Unresolved local var: char * module_name_str@[???]
                       Unresolved local var: PyObject * module_name@[???]
                       Unresolved local var: PyObject * module_dot@[???]
                       Unresolved local var: PyObject * full_name@[???] */
        PyErr_Clear();
        lVar8 = PyModule_GetName(pPVar10);
        if ((lVar8 != 0) && (plVar12 = (long *)PyUnicode_FromString(), plVar12 != (long *)0x0)) {
          plVar13 = (long *)PyUnicode_Concat(plVar12,__pyx_mstate_global_static.__pyx_kp_u__19);
          if (plVar13 == (long *)0x0) {
            pPVar11 = (PyObject *)0x0;
          }
          else {
            plVar14 = (long *)PyUnicode_Concat(plVar13,pPVar15);
            if (plVar14 == (long *)0x0) {
              pPVar11 = (PyObject *)0x0;
            }
            else {
              pPVar11 = (PyObject *)PyImport_GetModule();
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar8 = *plVar14;
              *plVar14 = lVar8 + -1;
              if (lVar8 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar8 = *plVar13;
            *plVar13 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar8 = *plVar12;
          *plVar12 = lVar8 + -1;
          if (lVar8 + -1 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (pPVar11 != (PyObject *)0x0) goto LAB_00107670;
        }
      }
      iVar20 = 0x36d1;
      iVar7 = 6;
      PyErr_Format(*(undefined8 *)PTR_PyExc_ImportError_00137f90,"cannot import name %S",pPVar15);
      pPVar15 = (PyObject *)0x0;
      goto LAB_0010830c;
    }
LAB_00107670:
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_ConfigHelper,pPVar11);
    if (iVar7 < 0) {
      iVar20 = 0x36d3;
      iVar7 = 6;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar15 = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_FrpManager;
                    /* Unresolved local var: PyObject * ns@[???] */
    pPVar10 = (PyObject *)PyDict_New();
    if (pPVar10 == (PyObject *)0x0) {
LAB_001076ec:
      iVar20 = 0x36de;
      iVar7 = 8;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_module,pPVar15);
    if ((iVar7 < 0) ||
       (iVar7 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_qualname,pPVar11),
       iVar7 < 0)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar8 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar8;
      if (lVar8 == 0) {
        iVar20 = 0x36de;
        iVar7 = 8;
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
        bVar6 = true;
        goto LAB_001076f8;
      }
      goto LAB_001076ec;
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      iVar20 = 0x36e8;
      iVar7 = 9;
      goto LAB_0010830c;
    }
    iVar7 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_config,
                           __pyx_mstate_global_static.__pyx_n_s_ConfigHelper);
    if (iVar7 < 0) {
      iVar20 = 0x36ea;
      iVar7 = 9;
      goto LAB_00107840;
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&__pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_1__init__,0,
                         __pyx_mstate_global_static.__pyx_n_s_FrpManager___init,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__21,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x36eb;
      iVar7 = 9;
      goto LAB_00107840;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar8 = pPVar11->ob_refcnt;
    pPVar15[0xb].ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_init,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_init,pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x36ef;
      iVar7 = 9;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_3_handle_frp_control
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager__handle_frp_control,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj_,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x36f9;
      iVar7 = 0x1f;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_handle_frp_control,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_handle_frp_control[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_handle_frp_control,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x36fb;
      iVar7 = 0x1f;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_6_handle_frp_update
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager__handle_frp_update,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__3,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3705;
      iVar7 = 0x24;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_handle_frp_update,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_handle_frp_update[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_handle_frp_update,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3707;
      iVar7 = 0x24;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_9_handle_mqtt_command
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager__handle_mqtt_command,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__4,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3711;
      iVar7 = 0x2f;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_handle_mqtt_command,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_handle_mqtt_command[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_handle_mqtt_command,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3713;
      iVar7 = 0x2f;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = (PyObject *)PyDict_New();
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x371d;
      iVar7 = 0x34;
      goto LAB_0010830c;
    }
    iVar7 = PyDict_SetItem(pPVar15,__pyx_mstate_global_static.__pyx_n_s_command,
                           __pyx_mstate_global_static.__pyx_n_s_str);
    if (iVar7 < 0) {
      iVar20 = 0x371f;
      iVar7 = 0x34;
      goto LAB_0010830c;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_12_process_command
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager__process_command,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__5,pPVar21);
    if (pPVar11 == (PyObject *)0x0) {
      iVar20 = 0x3720;
      iVar7 = 0x34;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar8 = pPVar15->ob_refcnt;
    pPVar11[0xb].ob_refcnt = (Py_ssize_t)pPVar15;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_process_command,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_process_command[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_process_command,pPVar11
                               );
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3724;
      iVar7 = 0x34;
      goto LAB_00107840;
    }
    lVar8 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyDict_New();
    if (pPVar11 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      iVar20 = 0x372e;
      iVar7 = 0x46;
      goto LAB_0010830c;
    }
    iVar7 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_command,
                           __pyx_mstate_global_static.__pyx_n_s_str);
    if (iVar7 < 0) {
      iVar20 = 0x3730;
      iVar7 = 0x46;
      goto LAB_00107840;
    }
    iVar7 = PyDict_SetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_args,
                           __pyx_mstate_global_static.__pyx_n_s_list);
    if (iVar7 < 0) {
      iVar20 = 0x3731;
      iVar7 = 0x46;
      goto LAB_00107840;
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_15_run_systemctl_command
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager__run_systemctl_comman,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__7,pPVar21);
    pPVar5 = __pyx_mstate_global_static.__pyx_tuple__27;
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3732;
      iVar7 = 0x46;
      goto LAB_00107840;
    }
                    /* Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar8 = (__pyx_mstate_global_static.__pyx_tuple__27)->ob_refcnt;
    pPVar15[9].ob_type = (_typeobject *)__pyx_mstate_global_static.__pyx_tuple__27;
    pPVar5->ob_refcnt = lVar8 + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???]
                       Unresolved local var: __pyx_CyFunctionObject * m@[???] */
    lVar8 = pPVar11->ob_refcnt;
    pPVar15[0xb].ob_refcnt = (Py_ssize_t)pPVar11;
    if (lVar8 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_run_systemctl_command,pPVar15
                          ,__pyx_mstate_global_static.__pyx_n_s_run_systemctl_command[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_run_systemctl_command,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3737;
      iVar7 = 0x46;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_18start_frp_service
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager_start_frp_service,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__10,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3741;
      iVar7 = 0x69;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_start_frp_service,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_start_frp_service[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_start_frp_service,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3743;
      iVar7 = 0x69;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_21stop_frp_service
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager_stop_frp_service,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__11,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x374d;
      iVar7 = 0x75;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_stop_frp_service,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_stop_frp_service[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_stop_frp_service,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x374f;
      iVar7 = 0x75;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_24restart_frp_service
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager_restart_frp_service,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__12,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3759;
      iVar7 = 0x81;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_restart_frp_service,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_restart_frp_service[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_restart_frp_service,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x375b;
      iVar7 = 0x81;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_27enable_frp_service
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager_enable_frp_service,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__13,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3765;
      iVar7 = 0x8d;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_enable_frp_service,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_enable_frp_service[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_enable_frp_service,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3767;
      iVar7 = 0x8d;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_30disable_frp_service
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager_disable_frp_service,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__14,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3771;
      iVar7 = 0x99;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_disable_frp_service,pPVar15,
                          __pyx_mstate_global_static.__pyx_n_s_disable_frp_service[1].ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_disable_frp_service,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x3773;
      iVar7 = 0x99;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
    pPVar15 = __Pyx_CyFunction_New
                        (&
                         __pyx_mdef_9moonraker_10components_11frp_manager_10FrpManager_33get_frp_service_status
                         ,8,__pyx_mstate_global_static.__pyx_n_s_FrpManager_get_frp_service_statu,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__15,pPVar21);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x377d;
      iVar7 = 0xa5;
      goto LAB_0010830c;
    }
    if (pPVar10->ob_type == (_typeobject *)PTR_PyDict_Type_00137f60) {
      uVar18 = _PyDict_SetItem_KnownHash
                         (pPVar10,__pyx_mstate_global_static.__pyx_n_s_get_frp_service_status,
                          pPVar15,__pyx_mstate_global_static.__pyx_n_s_get_frp_service_status[1].
                                  ob_type);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    else {
      uVar18 = PyObject_SetItem(pPVar10,__pyx_mstate_global_static.__pyx_n_s_get_frp_service_status,
                                pPVar15);
      uVar2 = (uint)(uVar18 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar20 = 0x377f;
      iVar7 = 0xa5;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: PyObject * owned_metaclass@[???] */
    margs[2] = __pyx_mstate_global_static.__pyx_empty_tuple;
    margs[0] = (PyObject *)0x0;
    margs[1] = __pyx_mstate_global_static.__pyx_n_s_FrpManager;
    margs[3] = pPVar10;
    pPVar15 = __Pyx_PyObject_FastCallDict
                        ((PyObject *)PTR_PyType_Type_00137f40,margs + 1,0x8000000000000003,
                         __pyx_mstate_global_static.__pyx_empty_tuple);
    if (pPVar15 == (PyObject *)0x0) {
      iVar20 = 0x3789;
      iVar7 = 8;
      goto LAB_0010830c;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_FrpManager,pPVar15);
    if (iVar7 < 0) {
      iVar20 = 0x378b;
      iVar7 = 8;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar10 = __Pyx_CyFunction_New
                        (&__pyx_mdef_9moonraker_10components_11frp_manager_1load_component,0,
                         __pyx_mstate_global_static.__pyx_n_s_load_component,
                         __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__31,pPVar21);
    if (pPVar10 == (PyObject *)0x0) {
      iVar20 = 0x3795;
      iVar7 = 0xe9;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_load_component,pPVar10);
    if (iVar7 < 0) {
      pPVar15 = (PyObject *)0x0;
      iVar20 = 0x3797;
      iVar7 = 0xe9;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    pPVar10 = (PyObject *)PyDict_New();
    if (pPVar10 == (PyObject *)0x0) {
      iVar7 = 1;
      iVar20 = 0x379f;
      bVar6 = true;
      goto LAB_001076f8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_test,pPVar10);
    if (iVar7 < 0) {
      pPVar15 = (PyObject *)0x0;
      iVar20 = 0x37a1;
      iVar7 = 1;
      goto LAB_0010830c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
  }
  iVar7 = -(uint)(__pyx_m == (PyObject *)0x0);
LAB_0010849c:
  if (lVar17 != *(long *)PTR___stack_chk_guard_00137f30) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}


/* ================================================================
 * Address: 001084d8
 * Symbol:  PyInit_frp_manager
 * Signature: PyObject * PyInit_frp_manager(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PyObject * PyInit_frp_manager(void)

{
  PyObject *pPVar1;
  
  pPVar1 = (PyObject *)PyModuleDef_Init(&__pyx_moduledef);
  return pPVar1;
}


/* ================================================================
 * Address: 001084e8
 * Symbol:  call_weak_fn
 * Signature: undefined call_weak_fn(void)
 * ================================================================ */

void call_weak_fn(void)

{
  if (PTR___gmon_start___00137f28 != (undefined *)0x0) {
    __gmon_start__();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00108500
 * Symbol:  deregister_tm_clones
 * Signature: undefined deregister_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x00108518) */
/* WARNING: Removing unreachable block (ram,0x00108524) */

void deregister_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 00108530
 * Symbol:  register_tm_clones
 * Signature: undefined register_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x00108554) */
/* WARNING: Removing unreachable block (ram,0x00108560) */

void register_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 001085ec
 * Symbol:  lexical_block_1_0
 * Signature: void lexical_block_1_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x1085ec 001085ec} (16 bytes)
   DWARF func body range[1]: {@address 0x108634 00108634} (20 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x00108630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(unaff_x19[1] + 0x30))();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00108600
 * Symbol:  lexical_block_2_0
 * Signature: void lexical_block_2_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x108600 00108600} (16 bytes)
   DWARF func body range[1]: {@address 0x10861c 0010861c} (8 bytes)
   DWARF func body range[2]: {@address 0x10862c 0010862c} (8 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x00108630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x19[1] + 0x30))();
  return;
}


/* ================================================================
 * Address: 00108694
 * Symbol:  lexical_block_1_0
 * Signature: void lexical_block_1_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x108694 00108694} (16 bytes)
   DWARF func body range[1]: {@address 0x1086dc 001086dc} (20 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x001086d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(unaff_x19[1] + 0x30))();
    return;
  }
  return;
}


/* ================================================================
 * Address: 001086a8
 * Symbol:  lexical_block_2_0
 * Signature: void lexical_block_2_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x1086a8 001086a8} (16 bytes)
   DWARF func body range[1]: {@address 0x1086c4 001086c4} (8 bytes)
   DWARF func body range[2]: {@address 0x1086d4 001086d4} (8 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x001086d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x19[1] + 0x30))();
  return;
}


/* ================================================================
 * Address: 00111478
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_6_handle_frp_update
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_6_handle_frp_update(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_6_handle_frp_update
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
  lVar16 = *(long *)PTR___stack_chk_guard_00137f30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar14 = PTR___stack_chk_guard_00137f30;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar19 = __pyx_kwds[1].ob_refcnt;
        goto LAB_00111628;
      }
      if (__pyx_nargs == 0) {
        lVar19 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar12 = __pyx_kwds[1].ob_refcnt;
          lVar19 = lVar19 + -1;
          goto LAB_00111664;
        }
        lVar19 = PyErr_Occurred();
        if (lVar19 != 0) {
          iVar10 = 0x11ea;
          goto LAB_00111528;
        }
      }
LAB_001114ec:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_frp_update","exactly",2,"s",__pyx_nargs);
      iVar10 = 0x1206;
      goto LAB_00111528;
    }
    lVar12 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar19 = lVar12;
LAB_00111664:
    pPVar21 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00137fb0;
    puVar4 = PTR__Py_TrueStruct_00137f50;
    puVar3 = PTR__Py_NoneStruct_00137f48;
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
            goto LAB_001116c8;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar23;
          lVar23 = lVar20;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar20];
      }
      goto LAB_001117d0;
    }
LAB_00111880:
    values[1] = (PyObject *)0x0;
    goto LAB_00111884;
  }
  if (__pyx_nargs != 2) goto LAB_001114ec;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_00111584:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_1__handle_frp_update
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_1__handle_frp_update
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_1__handle_frp_update
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_frp_update;
  qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager__handle_frp_update;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar21 = (PyObject *)PTR__Py_NoneStruct_00137f48;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x122d;
    *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011190c:
    p_Var18 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._handle_frp_update",iVar10,0x24,
                       "moonraker/components/frp_manager.py");
  }
  else {
    lVar19 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_refcnt = (Py_ssize_t)pPVar6;
    pPVar6->ob_refcnt = lVar19 + 1;
    lVar19 = pPVar7->ob_refcnt;
    closure[2].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar19 + 1;
    p_Var18 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_7generator1,
                         __pyx_mstate_global_static.__pyx_codeobj__3,closure,name,qualname,
                         module_name);
    pPVar21 = closure;
    if (p_Var18 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x1238;
      goto LAB_0011190c;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar19 = pPVar21->ob_refcnt + -1;
  pPVar21->ob_refcnt = lVar19;
  if (lVar19 == 0) {
    (*pPVar21->ob_type->tp_dealloc)(pPVar21);
  }
LAB_00111544:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var18->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar20 = lVar12 + 1;
    if (lVar12 == lVar23) goto LAB_00111880;
    p_Var22 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar20;
    if ((_typeobject *)pPVar21 == p_Var22) break;
LAB_001116c8:
    bVar8 = pPVar21->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var22->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar21 != (PyObject *)puVar3) && (bVar8 || p_Var22 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar21,p_Var22,2);
        if (plVar11 == (long *)0x0) goto LAB_00111880;
        uVar15 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar11 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar11;
        *plVar11 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_00111874:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_00111880;
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
      goto LAB_00111880;
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
              goto LAB_00111874;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar20];
LAB_001117d0:
  if (values[1] == (PyObject *)0x0) {
LAB_00111884:
    lVar19 = PyErr_Occurred();
    if (lVar19 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_frp_update","exactly",2,"s",1);
      iVar10 = 0x11f4;
    }
    else {
      iVar10 = 0x11f2;
    }
  }
  else {
    lVar19 = lVar19 + -1;
LAB_00111628:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar19 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x123688,pcVar14), -1 < iVar10))
    goto LAB_00111584;
    iVar10 = 0x11f9;
  }
LAB_00111528:
  p_Var18 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._handle_frp_update",iVar10,0x24,
                     "moonraker/components/frp_manager.py");
  goto LAB_00111544;
}


/* ================================================================
 * Address: 001152a0
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_12_process_command
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_12_process_command(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_12_process_command
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  Py_ssize_t *pPVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  PyTypeObject *type;
  PyObject *pPVar7;
  PyObject *name;
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *closure;
  undefined1 *puVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  PyObject *pPVar13;
  PyObject *pPVar14;
  char *pcVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  __pyx_CoroutineObject *p_Var19;
  long lVar20;
  _typeobject *p_Var21;
  PyObject *pPVar22;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_command@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar17 = *(long *)PTR___stack_chk_guard_00137f30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_command;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar14 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_00115314;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_001153ac;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  pcVar15 = PTR___stack_chk_guard_00137f30;
  if (__pyx_nargs == 1) {
    pPVar13 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar14 = pPVar13;
LAB_001154a0:
    pPVar7 = __pyx_mstate_global_static.__pyx_n_s_command;
    puVar6 = PTR_PyUnicode_Type_00137fb0;
    puVar5 = PTR__Py_TrueStruct_00137f50;
    puVar4 = PTR__Py_NoneStruct_00137f48;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar13) {
      p_Var21 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_command == p_Var21) {
        values[1] = *kwvalues;
      }
      else {
        pPVar22 = (PyObject *)0x0;
        do {
          pPVar1 = (PyObject *)((long)&pPVar22->ob_refcnt + 1);
          if (pPVar13 == pPVar1) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar13 = (PyObject *)0x0;
            goto LAB_00115508;
          }
          pPVar3 = &__pyx_kwds[2].ob_refcnt + (long)pPVar22;
          pPVar22 = pPVar1;
        } while (__pyx_mstate_global_static.__pyx_n_s_command != (PyObject *)*pPVar3);
        values[1] = kwvalues[(long)pPVar1];
      }
      goto LAB_00115610;
    }
LAB_001156c0:
    values[1] = (PyObject *)0x0;
    goto LAB_001156c4;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar11 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_00115464;
  }
  if (__pyx_nargs == 0) {
    lVar20 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar13 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      pPVar14 = (PyObject *)(lVar20 + -1);
      goto LAB_001154a0;
    }
    lVar20 = PyErr_Occurred();
    if (lVar20 != 0) {
      iVar10 = 0x14be;
      goto LAB_00115350;
    }
  }
LAB_00115314:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_process_command",
               "exactly",2,"s",__pyx_nargs);
  iVar10 = 0x14da;
  goto LAB_00115350;
  while( true ) {
    bVar8 = pPVar13 == pPVar22;
    pPVar3 = &pPVar13->ob_refcnt;
    pPVar13 = (PyObject *)((long)pPVar3 + 1);
    if (bVar8) goto LAB_001156c0;
    p_Var21 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar3];
    if ((_typeobject *)pPVar7 == p_Var21) break;
LAB_00115508:
    bVar8 = pPVar7->ob_type != (_typeobject *)puVar6;
    bVar9 = (p_Var21->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar7 != (PyObject *)puVar4) && (bVar8 || p_Var21 != (_typeobject *)puVar4)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar7,p_Var21,2);
        if (plVar12 == (long *)0x0) goto LAB_001156c0;
        uVar16 = (uint)(plVar12 == (long *)puVar5);
        if ((plVar12 != (long *)puVar5 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar4) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar20 = *plVar12;
        *plVar12 = lVar20 + -1;
        if (lVar20 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_001156b4:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_001156c0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar7[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar7), iVar10 < 0)) ||
         ((-1 < (char)p_Var21->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var21), iVar10 < 0))))
      goto LAB_001156c0;
      lVar20 = pPVar7[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar20 == (p_Var21->ob_base).ob_size) &&
         ((pPVar7[1].ob_type == (_typeobject *)p_Var21->tp_name ||
          (_typeobject *)p_Var21->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar7[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar7[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        if (((byte)((byte)p_Var21->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar7[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar7[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar7[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar7 + 3);
            }
          }
          bVar2 = (byte)p_Var21->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var21->tp_setattr;
          }
          else {
            __s2 = &p_Var21->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var21->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            uVar16 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            uVar16 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(ushort *)__s2;
          }
          else {
            uVar16 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar18 = *(uint *)__s2;
          }
          if (uVar18 == uVar16) {
            if (lVar20 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(__s1,__s2,(long)pcVar15 * lVar20);
              uVar16 = (uint)(iVar10 == 0);
              goto LAB_001156b4;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[(long)pPVar13];
LAB_00115610:
  if (values[1] != (PyObject *)0x0) {
    puVar11 = (undefined1 *)((long)&pPVar14[-1].ob_type + 7);
LAB_00115464:
    if (0 < (long)puVar11) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar14 = (PyObject *)values;
      iVar10 = __Pyx_ParseOptionalKeywords
                         (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar14,(PyObject **)__pyx_nargs,
                          0x123780,pcVar15);
      if (iVar10 < 0) {
        iVar10 = 0x14cd;
        goto LAB_00115350;
      }
    }
LAB_001153ac:
    pPVar7 = values[1];
    pPVar13 = values[0];
    if ((values[1]->ob_type == (_typeobject *)PTR_PyUnicode_Type_00137fb0) ||
       (iVar10 = __Pyx__ArgTypeTest((PyObject *)&values[1]->ob_type,
                                    (PyTypeObject *)PTR_PyUnicode_Type_00137fb0,"command",
                                    (int)pPVar14), iVar10 != 0)) {
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_3__process_command
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_3__process_command
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_3__process_command
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      name = __pyx_mstate_global_static.__pyx_n_s_process_command;
      pPVar1 = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      pPVar22 = __pyx_mstate_global_static.__pyx_n_s_FrpManager__process_command;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar14 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar10 = 0x1506;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
      }
      else {
        lVar20 = pPVar13->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[1].ob_type = (_typeobject *)pPVar13;
        pPVar13->ob_refcnt = lVar20 + 1;
        lVar20 = pPVar7->ob_refcnt;
        closure[1].ob_refcnt = (Py_ssize_t)pPVar7;
        pPVar7->ob_refcnt = lVar20 + 1;
        p_Var19 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_13generator3
                             ,__pyx_mstate_global_static.__pyx_codeobj__5,closure,name,pPVar22,
                             pPVar1);
        if (p_Var19 != (__pyx_CoroutineObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar20 = closure->ob_refcnt + -1;
          closure->ob_refcnt = lVar20;
          if (lVar20 == 0) {
            (*closure->ob_type->tp_dealloc)(closure);
          }
          goto LAB_0011536c;
        }
        iVar10 = 0x1511;
        pPVar14 = closure;
      }
      __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._process_command",iVar10,0x34,
                         "moonraker/components/frp_manager.py");
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar20 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar20;
      if (lVar20 == 0) {
        p_Var19 = (__pyx_CoroutineObject *)0x0;
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
        goto LAB_0011536c;
      }
    }
    p_Var19 = (__pyx_CoroutineObject *)0x0;
    goto LAB_0011536c;
  }
LAB_001156c4:
  lVar20 = PyErr_Occurred();
  if (lVar20 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_process_command",
                 "exactly",2,"s",1);
    iVar10 = 0x14c8;
  }
  else {
    iVar10 = 0x14c6;
  }
LAB_00115350:
  p_Var19 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._process_command",iVar10,0x34,
                     "moonraker/components/frp_manager.py");
LAB_0011536c:
  if (lVar17 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var19->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00118558
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_9_handle_mqtt_command
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_9_handle_mqtt_command(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_9_handle_mqtt_command
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
  PyObject *pPVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  long lVar12;
  _typeobject *p_Var13;
  PyObject *closure;
  long *plVar14;
  long lVar15;
  setattrfunc *pp_Var16;
  long lVar17;
  long lVar18;
  char *pcVar19;
  uint uVar20;
  long lVar21;
  uint uVar22;
  __pyx_CoroutineObject *p_Var23;
  _typeobject *p_Var24;
  PyObject *pPVar25;
  long lVar26;
  Py_ssize_t PVar27;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_topic@[???]
                       Unresolved local var: PyObject * __pyx_v_message@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg26(x26)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar21 = *(long *)PTR___stack_chk_guard_00137f30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_topic;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_message;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar19 = PTR___stack_chk_guard_00137f30;
    if (__pyx_nargs == 1) {
      lVar26 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      lVar15 = lVar26;
LAB_00118778:
      pPVar25 = __pyx_mstate_global_static.__pyx_n_s_topic;
      puVar5 = PTR_PyUnicode_Type_00137fb0;
      puVar4 = PTR__Py_TrueStruct_00137f50;
      puVar3 = PTR__Py_NoneStruct_00137f48;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar26) {
        p_Var24 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_topic == p_Var24) {
          values[1] = *kwvalues;
        }
        else {
          lVar12 = 0;
          do {
            lVar17 = lVar12 + 1;
            if (lVar17 == lVar26) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar12 = 0;
              goto LAB_001187d8;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar12;
            lVar12 = lVar17;
          } while (__pyx_mstate_global_static.__pyx_n_s_topic != (PyObject *)*pPVar1);
          values[1] = kwvalues[lVar17];
        }
        goto LAB_00118a78;
      }
LAB_00118c18:
      values[1] = (PyObject *)0x0;
      goto LAB_00118c1c;
    }
    if (__pyx_nargs < 2) {
      if (__pyx_nargs == 0) {
        PVar27 = __pyx_kwds[1].ob_refcnt;
LAB_00118754:
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar26 = __pyx_kwds[1].ob_refcnt;
          lVar15 = PVar27 + -1;
          goto LAB_00118778;
        }
        lVar15 = PyErr_Occurred();
        if (lVar15 == 0) goto LAB_001188c4;
        iVar11 = 0x1397;
      }
      else {
LAB_001188c4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                     "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                     "_handle_mqtt_command","exactly",3,"s",__pyx_nargs);
        iVar11 = 0x13bf;
      }
      goto LAB_00118900;
    }
    if (__pyx_nargs != 2) {
      if (__pyx_nargs != 3) goto LAB_001188c4;
      values[2] = __pyx_args[2];
    }
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    lVar26 = __pyx_kwds[1].ob_refcnt;
    lVar15 = lVar26;
    if (__pyx_nargs == 1) goto LAB_00118778;
    PVar27 = lVar26;
    if (__pyx_nargs == 2) goto LAB_00118608;
    if (__pyx_nargs == 0) goto LAB_00118754;
    goto LAB_0011894c;
  }
  if (__pyx_nargs != 3) goto LAB_001188c4;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
  values[2] = __pyx_args[2];
LAB_00118964:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_2__handle_mqtt_command
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar8 = values[2];
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_2__handle_mqtt_command
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_2__handle_mqtt_command
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_mqtt_command;
  qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager__handle_mqtt_command;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar25 = (PyObject *)PTR__Py_NoneStruct_00137f48;
  if (closure == (PyObject *)0x0) {
    iVar11 = 0x13e6;
    *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_00118cb4:
    p_Var23 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._handle_mqtt_command",iVar11,
                       0x2f,"moonraker/components/frp_manager.py");
  }
  else {
    lVar15 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[2].ob_refcnt = (Py_ssize_t)pPVar6;
    pPVar6->ob_refcnt = lVar15 + 1;
    lVar15 = pPVar7->ob_refcnt;
    closure[2].ob_type = (_typeobject *)pPVar7;
    pPVar7->ob_refcnt = lVar15 + 1;
    pPVar25 = __pyx_mstate_global_static.__pyx_codeobj__4;
    lVar15 = pPVar8->ob_refcnt;
    closure[1].ob_type = (_typeobject *)pPVar8;
    pPVar8->ob_refcnt = lVar15 + 1;
    p_Var23 = __Pyx__Coroutine_New
                        (type,
                         __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_10generator2,
                         pPVar25,closure,name,qualname,module_name);
    pPVar25 = closure;
    if (p_Var23 == (__pyx_CoroutineObject *)0x0) {
      iVar11 = 0x13f4;
      goto LAB_00118cb4;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar15 = pPVar25->ob_refcnt + -1;
  pPVar25->ob_refcnt = lVar15;
  if (lVar15 == 0) {
    (*pPVar25->ob_type->tp_dealloc)(pPVar25);
  }
  goto LAB_0011891c;
  while( true ) {
    lVar17 = lVar12 + 1;
    if (lVar17 == lVar26) goto LAB_00118c18;
    p_Var24 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar17;
    if ((_typeobject *)pPVar25 == p_Var24) break;
LAB_001187d8:
    bVar9 = pPVar25->ob_type != (_typeobject *)puVar5;
    bVar10 = (p_Var24->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar17 = lVar12;
    if (bVar9 || bVar10) {
      if ((bVar10 || pPVar25 != (PyObject *)puVar3) && (bVar9 || p_Var24 != (_typeobject *)puVar3))
      {
        plVar14 = (long *)PyObject_RichCompare(pPVar25,p_Var24,2);
        if (plVar14 == (long *)0x0) goto LAB_00118c18;
        uVar20 = (uint)(plVar14 == (long *)puVar4);
        if ((plVar14 != (long *)puVar4 && plVar14 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar14 != (long *)puVar3) {
          uVar20 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar18 = *plVar14;
        *plVar14 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_00118c08:
        if (uVar20 != 0) {
          if ((int)uVar20 < 0) goto LAB_00118c18;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar25[2].ob_refcnt) && (iVar11 = _PyUnicode_Ready(pPVar25), iVar11 < 0)) ||
         ((-1 < (char)p_Var24->tp_basicsize && (iVar11 = _PyUnicode_Ready(p_Var24), iVar11 < 0))))
      goto LAB_00118c18;
      lVar18 = pPVar25[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar18 == (p_Var24->ob_base).ob_size) &&
         ((pPVar25[1].ob_type == (_typeobject *)p_Var24->tp_name ||
          (_typeobject *)p_Var24->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar25[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar19 = (char *)((ulong)(byte)((byte)pPVar25[2].ob_refcnt >> 2) & 7);
        uVar20 = (uint)pcVar19;
        if (((byte)((byte)p_Var24->tp_basicsize >> 2) & 7) == uVar20) {
          bVar2 = (byte)pPVar25[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var13 = pPVar25[4].ob_type;
          }
          else {
            p_Var13 = (_typeobject *)&pPVar25[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var13 = (_typeobject *)(pPVar25 + 3);
            }
          }
          bVar2 = (byte)p_Var24->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var16 = (setattrfunc *)p_Var24->tp_setattr;
          }
          else {
            pp_Var16 = &p_Var24->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var16 = (setattrfunc *)&p_Var24->tp_dealloc;
            }
          }
          if (uVar20 == 1) {
            uVar20 = (uint)(byte)(p_Var13->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var16;
          }
          else if (uVar20 == 2) {
            uVar20 = (uint)(ushort)(p_Var13->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var16;
          }
          else {
            uVar20 = (uint)(p_Var13->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var16;
          }
          if (uVar22 == uVar20) {
            if (lVar18 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar11 = memcmp(p_Var13,pp_Var16,(long)pcVar19 * lVar18);
              uVar20 = (uint)(iVar11 == 0);
              goto LAB_00118c08;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar17];
LAB_00118a78:
  if (values[1] != (PyObject *)0x0) {
    PVar27 = lVar15 + -1;
    lVar26 = __pyx_kwds[1].ob_refcnt;
LAB_00118608:
    pPVar25 = __pyx_mstate_global_static.__pyx_n_s_message;
    puVar5 = PTR_PyUnicode_Type_00137fb0;
    puVar4 = PTR__Py_TrueStruct_00137f50;
    puVar3 = PTR__Py_NoneStruct_00137f48;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar26) {
      p_Var24 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_message == p_Var24) {
        values[2] = *kwvalues;
      }
      else {
        lVar15 = 0;
        do {
          lVar12 = lVar15 + 1;
          if (lVar12 == lVar26) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar15 = 0;
            goto LAB_00118668;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar15;
          lVar15 = lVar12;
        } while (__pyx_mstate_global_static.__pyx_n_s_message != (PyObject *)*pPVar1);
        values[2] = kwvalues[lVar12];
      }
      goto LAB_00118a44;
    }
LAB_00118b28:
    values[2] = (PyObject *)0x0;
    goto LAB_00118b2c;
  }
LAB_00118c1c:
  lVar15 = PyErr_Occurred();
  if (lVar15 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                 "_handle_mqtt_command","exactly",3,"s",1);
    iVar11 = 0x13a1;
  }
  else {
    iVar11 = 0x139f;
  }
  goto LAB_00118900;
  while( true ) {
    lVar12 = lVar15 + 1;
    if (lVar12 == lVar26) goto LAB_00118b28;
    p_Var24 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar15];
    lVar15 = lVar12;
    if ((_typeobject *)pPVar25 == p_Var24) break;
LAB_00118668:
    bVar9 = pPVar25->ob_type != (_typeobject *)puVar5;
    bVar10 = (p_Var24->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar12 = lVar15;
    if (bVar9 || bVar10) {
      if ((bVar10 || pPVar25 != (PyObject *)puVar3) && (bVar9 || p_Var24 != (_typeobject *)puVar3))
      {
        plVar14 = (long *)PyObject_RichCompare(pPVar25,p_Var24,2);
        if (plVar14 == (long *)0x0) goto LAB_00118b28;
        uVar20 = (uint)(plVar14 == (long *)puVar4);
        if ((plVar14 != (long *)puVar4 && plVar14 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar14 != (long *)puVar3) {
          uVar20 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar17 = *plVar14;
        *plVar14 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_00118b18:
        if (uVar20 != 0) {
          if ((int)uVar20 < 0) goto LAB_00118b28;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar25[2].ob_refcnt) && (iVar11 = _PyUnicode_Ready(pPVar25), iVar11 < 0)) ||
         ((-1 < (char)p_Var24->tp_basicsize && (iVar11 = _PyUnicode_Ready(p_Var24), iVar11 < 0))))
      goto LAB_00118b28;
      lVar17 = pPVar25[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar17 == (p_Var24->ob_base).ob_size) &&
         ((pPVar25[1].ob_type == (_typeobject *)p_Var24->tp_name ||
          (_typeobject *)p_Var24->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar25[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar19 = (char *)((ulong)(byte)((byte)pPVar25[2].ob_refcnt >> 2) & 7);
        uVar20 = (uint)pcVar19;
        if (((byte)((byte)p_Var24->tp_basicsize >> 2) & 7) == uVar20) {
          bVar2 = (byte)pPVar25[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var13 = pPVar25[4].ob_type;
          }
          else {
            p_Var13 = (_typeobject *)&pPVar25[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var13 = (_typeobject *)(pPVar25 + 3);
            }
          }
          bVar2 = (byte)p_Var24->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var16 = (setattrfunc *)p_Var24->tp_setattr;
          }
          else {
            pp_Var16 = &p_Var24->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var16 = (setattrfunc *)&p_Var24->tp_dealloc;
            }
          }
          if (uVar20 == 1) {
            uVar20 = (uint)(byte)(p_Var13->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var16;
          }
          else if (uVar20 == 2) {
            uVar20 = (uint)(ushort)(p_Var13->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var16;
          }
          else {
            uVar20 = (uint)(p_Var13->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var16;
          }
          if (uVar22 == uVar20) {
            if (lVar17 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar11 = memcmp(p_Var13,pp_Var16,(long)pcVar19 * lVar17);
              uVar20 = (uint)(iVar11 == 0);
              goto LAB_00118b18;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar12];
LAB_00118a44:
  if (values[2] == (PyObject *)0x0) {
LAB_00118b2c:
    lVar15 = PyErr_Occurred();
    if (lVar15 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_mqtt_command","exactly",3,"s",2);
      iVar11 = 0x13ab;
    }
    else {
      iVar11 = 0x13a9;
    }
  }
  else {
    lVar26 = PVar27 + -1;
LAB_0011894c:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar26 < 1) ||
       (iVar11 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x123668,pcVar19), -1 < iVar11))
    goto LAB_00118964;
    iVar11 = 0x13b0;
  }
LAB_00118900:
  p_Var23 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._handle_mqtt_command",iVar11,0x2f,
                     "moonraker/components/frp_manager.py");
LAB_0011891c:
  if (lVar21 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var23->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00118e58
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_15_run_systemctl_command
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_15_run_systemctl_command(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_15_run_systemctl_command
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  PyTypeObject *type;
  PyObject *qualname;
  PyObject *module_name;
  PyObject *name;
  PyObject *pPVar7;
  PyObject *pPVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var13;
  long lVar14;
  _typeobject *__s1;
  PyObject *pPVar15;
  long *plVar16;
  setattrfunc *__s2;
  long lVar17;
  PyObject *pPVar18;
  char *pcVar19;
  undefined8 uVar20;
  PyObject **function_name;
  long lVar21;
  ulong uVar22;
  uint uVar23;
  uint uVar24;
  _typeobject *p_Var25;
  long lVar26;
  long lVar27;
  long lVar28;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_command@[???]
                       Unresolved local var: PyObject * __pyx_v_args@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar21 = *(long *)PTR___stack_chk_guard_00137f30;
  function_name = &__pyx_mstate_global_static.__pyx_n_s_self;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)PTR__Py_NoneStruct_00137f48;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_command;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_args;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  pPVar18 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) {
      if (__pyx_nargs != 3) goto LAB_001191a0;
      values[2] = __pyx_args[2];
    }
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_00118f24;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  if (__pyx_nargs == 1) {
    lVar27 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar28 = lVar27;
LAB_0011904c:
    pPVar15 = __pyx_mstate_global_static.__pyx_n_s_command;
    puVar6 = PTR_PyUnicode_Type_00137fb0;
    puVar5 = PTR__Py_TrueStruct_00137f50;
    puVar3 = PTR__Py_FalseStruct_00137f20;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar27) {
      p_Var25 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_command == p_Var25) {
        values[1] = *kwvalues;
      }
      else {
        lVar14 = 0;
        do {
          lVar26 = lVar14 + 1;
          if (lVar26 == lVar27) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar14 = 0;
            goto LAB_001190b0;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar14;
          lVar14 = lVar26;
        } while (__pyx_mstate_global_static.__pyx_n_s_command != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar26];
      }
      goto LAB_00119298;
    }
LAB_00119378:
    values[1] = (PyObject *)0x0;
    goto LAB_0011937c;
  }
  if (1 < __pyx_nargs) {
    if (__pyx_nargs != 2) {
      if (__pyx_nargs != 3) goto LAB_001191a0;
      values[2] = __pyx_args[2];
    }
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    lVar27 = __pyx_kwds[1].ob_refcnt;
    lVar28 = lVar27;
    if (__pyx_nargs == 1) goto LAB_0011904c;
    if (__pyx_nargs == 2) goto joined_r0x001192a8;
    if (__pyx_nargs == 0) goto LAB_00119028;
    goto LAB_00119208;
  }
  if (__pyx_nargs == 0) {
    lVar28 = __pyx_kwds[1].ob_refcnt;
LAB_00119028:
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      lVar27 = __pyx_kwds[1].ob_refcnt;
      lVar28 = lVar28 + -1;
      goto LAB_0011904c;
    }
    lVar27 = PyErr_Occurred();
    if (lVar27 == 0) {
      uVar20 = 2;
      pcVar19 = "at least";
      goto LAB_001191b4;
    }
    iVar12 = 0x194d;
  }
  else {
LAB_001191a0:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    if (__pyx_nargs < 2) {
      uVar20 = 2;
      pcVar19 = "at least";
    }
    else {
      pcVar19 = "at most";
      uVar20 = 3;
    }
LAB_001191b4:
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                 "_run_systemctl_command",pcVar19,uVar20,"s",__pyx_nargs);
    iVar12 = 0x1975;
  }
  goto LAB_001191e4;
  while( true ) {
    lVar26 = lVar14 + 1;
    if (lVar26 == lVar27) goto LAB_00119378;
    p_Var25 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar14];
    lVar14 = lVar26;
    if ((_typeobject *)pPVar15 == p_Var25) break;
LAB_001190b0:
    puVar4 = PTR__Py_NoneStruct_00137f48;
    bVar9 = pPVar15->ob_type != (_typeobject *)puVar6;
    bVar10 = (p_Var25->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    lVar26 = lVar14;
    if (bVar9 || bVar10) {
      if ((bVar10 || pPVar15 != (PyObject *)PTR__Py_NoneStruct_00137f48) &&
         (bVar9 || p_Var25 != (_typeobject *)PTR__Py_NoneStruct_00137f48)) {
        plVar16 = (long *)PyObject_RichCompare(pPVar15,p_Var25,2);
        if (plVar16 == (long *)0x0) goto LAB_00119378;
        uVar23 = (uint)(plVar16 == (long *)puVar5);
        if ((plVar16 != (long *)puVar5 && plVar16 != (long *)puVar3) && plVar16 != (long *)puVar4) {
          uVar23 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar17 = *plVar16;
        *plVar16 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
LAB_00119368:
        if (uVar23 != 0) {
          if ((int)uVar23 < 0) goto LAB_00119378;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar15[2].ob_refcnt) && (iVar12 = _PyUnicode_Ready(pPVar15), iVar12 < 0)) ||
         ((-1 < (char)p_Var25->tp_basicsize && (iVar12 = _PyUnicode_Ready(p_Var25), iVar12 < 0))))
      goto LAB_00119378;
      lVar17 = pPVar15[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar17 == (p_Var25->ob_base).ob_size) &&
         ((pPVar15[1].ob_type == (_typeobject *)p_Var25->tp_name ||
          (_typeobject *)p_Var25->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar15[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar22 = (ulong)(byte)((byte)pPVar15[2].ob_refcnt >> 2) & 7;
        uVar23 = (uint)uVar22;
        if (((byte)((byte)p_Var25->tp_basicsize >> 2) & 7) == uVar23) {
          bVar2 = (byte)pPVar15[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar15[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar15[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar15 + 3);
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
          if (uVar23 == 1) {
            uVar23 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(byte *)__s2;
          }
          else if (uVar23 == 2) {
            uVar23 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(ushort *)__s2;
          }
          else {
            uVar23 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar24 = *(uint *)__s2;
          }
          if (uVar24 == uVar23) {
            if (lVar17 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar12 = memcmp(__s1,__s2,uVar22 * lVar17);
              uVar23 = (uint)(iVar12 == 0);
              goto LAB_00119368;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar26];
LAB_00119298:
  if (values[1] != (PyObject *)0x0) {
    lVar27 = lVar28 + -1;
joined_r0x001192a8:
    if (0 < lVar27) {
                    /* Unresolved local var: PyObject * value@[???] */
      pPVar15 = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_args);
      if (pPVar15 == (PyObject *)0x0) {
        lVar27 = PyErr_Occurred();
        if (lVar27 != 0) {
          iVar12 = 0x195e;
          goto LAB_001191e4;
        }
      }
      else {
        lVar27 = lVar27 + -1;
        values[2] = pPVar15;
LAB_00119208:
        if (lVar27 < 1) goto LAB_00118f24;
      }
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar18 = (PyObject *)values;
      iVar12 = __Pyx_ParseOptionalKeywords
                         (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar18,(PyObject **)__pyx_nargs,
                          0x123ad8,(char *)function_name);
      if (iVar12 < 0) {
        iVar12 = 0x1963;
        goto LAB_001191e4;
      }
    }
LAB_00118f24:
    pPVar8 = values[2];
    pPVar7 = values[1];
    pPVar15 = values[0];
    iVar12 = (int)pPVar18;
    if ((values[1]->ob_type == (_typeobject *)PTR_PyUnicode_Type_00137fb0) ||
       (iVar11 = __Pyx__ArgTypeTest((PyObject *)&values[1]->ob_type,
                                    (PyTypeObject *)PTR_PyUnicode_Type_00137fb0,"command",iVar12),
       iVar11 != 0)) {
      if ((pPVar8->ob_type != (_typeobject *)PTR_PyList_Type_00137fe0 &&
           pPVar8 != (PyObject *)PTR__Py_NoneStruct_00137f48) &&
         (iVar12 = __Pyx__ArgTypeTest((PyObject *)&pPVar8->ob_type,
                                      (PyTypeObject *)PTR_PyList_Type_00137fe0,"args",iVar12),
         iVar12 == 0)) {
        p_Var13 = (__pyx_CoroutineObject *)0x0;
        goto LAB_00118ff0;
      }
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_4__run_systemctl_command
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_4__run_systemctl_command
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_4__run_systemctl_command
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      name = __pyx_mstate_global_static.__pyx_n_s_run_systemctl_command;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager__run_systemctl_comman;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar18 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar12 = 0x19a2;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
      }
      else {
        lVar27 = pPVar15->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[4].ob_refcnt = (Py_ssize_t)pPVar15;
        pPVar15->ob_refcnt = lVar27 + 1;
        lVar27 = pPVar7->ob_refcnt;
        closure[2].ob_refcnt = (Py_ssize_t)pPVar7;
        pPVar7->ob_refcnt = lVar27 + 1;
        pPVar18 = __pyx_mstate_global_static.__pyx_codeobj__7;
        lVar27 = pPVar8->ob_refcnt;
        closure[1].ob_refcnt = (Py_ssize_t)pPVar8;
        pPVar8->ob_refcnt = lVar27 + 1;
        p_Var13 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_16generator4
                             ,pPVar18,closure,name,qualname,module_name);
        if (p_Var13 != (__pyx_CoroutineObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = closure->ob_refcnt + -1;
          closure->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*closure->ob_type->tp_dealloc)(closure);
          }
          goto LAB_00118ff0;
        }
        iVar12 = 0x19b0;
        pPVar18 = closure;
      }
      __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._run_systemctl_command",iVar12
                         ,0x46,"moonraker/components/frp_manager.py");
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar18->ob_refcnt + -1;
      pPVar18->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        p_Var13 = (__pyx_CoroutineObject *)0x0;
        (*pPVar18->ob_type->tp_dealloc)(pPVar18);
        goto LAB_00118ff0;
      }
    }
    p_Var13 = (__pyx_CoroutineObject *)0x0;
    goto LAB_00118ff0;
  }
LAB_0011937c:
  lVar27 = PyErr_Occurred();
  if (lVar27 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                 "_run_systemctl_command","at least",2,"s",1);
    iVar12 = 0x1957;
  }
  else {
    iVar12 = 0x1955;
  }
LAB_001191e4:
  p_Var13 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._run_systemctl_command",iVar12,
                     0x46,"moonraker/components/frp_manager.py");
LAB_00118ff0:
  if (lVar21 != *(long *)PTR___stack_chk_guard_00137f30) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return &p_Var13->ob_base;
}


/* ================================================================
 * Address: 0011b108
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_33get_frp_service_status
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_33get_frp_service_status(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_33get_frp_service_status
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
  PyObject *code;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var10;
  long lVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  long lVar13;
  long lVar14;
  char *pcVar15;
  char *in_x6;
  uint uVar16;
  PyObject *pPVar17;
  long lVar18;
  _typeobject *p_Var19;
  long lVar20;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar17 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011b180;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar18) {
        p_Var19 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var19) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar20 = lVar11 + 1;
            if (lVar20 == lVar18) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011b308;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar20;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar20];
        }
        goto LAB_0011b450;
      }
LAB_0011b40c:
      values[0] = (PyObject *)0x0;
      goto LAB_0011b410;
    }
    if (__pyx_nargs == 1) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011b16c;
    }
  }
LAB_0011b208:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
               "get_frp_service_status","exactly",1,"",__pyx_nargs);
  iVar9 = 0x2547;
  goto LAB_0011b244;
  while( true ) {
    lVar20 = lVar11 + 1;
    if (lVar20 == lVar18) goto LAB_0011b40c;
    p_Var19 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar20;
    if ((_typeobject *)pPVar17 == p_Var19) break;
LAB_0011b308:
    bVar7 = pPVar17->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var19->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar17 != (PyObject *)puVar3) && (bVar7 || p_Var19 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar17,p_Var19,2);
        if (plVar12 == (long *)0x0) goto LAB_0011b40c;
        uVar16 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar12;
        *plVar12 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011b3f8:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_0011b40c;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar17[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar17), iVar9 < 0)) ||
         ((-1 < (char)p_Var19->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var19), iVar9 < 0))))
      goto LAB_0011b40c;
      lVar13 = pPVar17[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var19->ob_base).ob_size) &&
         ((pPVar17[1].ob_type == (_typeobject *)p_Var19->tp_name ||
          (_typeobject *)p_Var19->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar17[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar17[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        in_x6 = pcVar15;
        if (((byte)((byte)p_Var19->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar17[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar17[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar17[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar17 + 3);
            }
          }
          bVar2 = (byte)p_Var19->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var19->tp_setattr;
          }
          else {
            __s2 = &p_Var19->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var19->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = *(uint *)__s2;
          }
          if (uVar16 == (uint)in_x6) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(__s1,__s2,(long)pcVar15 * lVar13);
              uVar16 = (uint)(iVar9 == 0);
              goto LAB_0011b3f8;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar20];
LAB_0011b450:
  if (values[0] == (PyObject *)0x0) {
LAB_0011b410:
    lVar18 = PyErr_Occurred();
    if (lVar18 == 0) goto LAB_0011b208;
    iVar9 = 0x2537;
  }
  else {
    lVar18 = lVar18 + -1;
LAB_0011b16c:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar18 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123a60,in_x6), -1 < iVar9)) {
LAB_0011b180:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_10_get_frp_service_status
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_10_get_frp_service_status
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_10_get_frp_service_status
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      code = __pyx_mstate_global_static.__pyx_codeobj__15;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      name = __pyx_mstate_global_static.__pyx_n_s_get_frp_service_status;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager_get_frp_service_statu;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar17 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar9 = 0x256e;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011b508:
        p_Var10 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.get_frp_service_status",
                           iVar9,0xa5,"moonraker/components/frp_manager.py");
      }
      else {
        lVar18 = apPVar6[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[4].ob_type = (_typeobject *)apPVar6[0];
        apPVar6[0]->ob_refcnt = lVar18 + 1;
        p_Var10 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_34generator10
                             ,code,closure,name,qualname,module_name);
        pPVar17 = closure;
        if (p_Var10 == (__pyx_CoroutineObject *)0x0) {
          iVar9 = 0x2576;
          goto LAB_0011b508;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar18 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar18;
      if (lVar18 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
      goto LAB_0011b260;
    }
    iVar9 = 0x253c;
  }
LAB_0011b244:
  p_Var10 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.get_frp_service_status",iVar9,0xa5
                     ,"moonraker/components/frp_manager.py");
LAB_0011b260:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var10->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011b600
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_18start_frp_service
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_18start_frp_service(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_18start_frp_service
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
  PyObject *code;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var10;
  long lVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  long lVar13;
  long lVar14;
  char *pcVar15;
  char *in_x6;
  uint uVar16;
  PyObject *pPVar17;
  long lVar18;
  _typeobject *p_Var19;
  long lVar20;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar17 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011b678;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar18) {
        p_Var19 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var19) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar20 = lVar11 + 1;
            if (lVar20 == lVar18) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011b800;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar20;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar20];
        }
        goto LAB_0011b948;
      }
LAB_0011b904:
      values[0] = (PyObject *)0x0;
      goto LAB_0011b908;
    }
    if (__pyx_nargs == 1) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011b664;
    }
  }
LAB_0011b700:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","start_frp_service",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x1d4a;
  goto LAB_0011b73c;
  while( true ) {
    lVar20 = lVar11 + 1;
    if (lVar20 == lVar18) goto LAB_0011b904;
    p_Var19 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar20;
    if ((_typeobject *)pPVar17 == p_Var19) break;
LAB_0011b800:
    bVar7 = pPVar17->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var19->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar17 != (PyObject *)puVar3) && (bVar7 || p_Var19 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar17,p_Var19,2);
        if (plVar12 == (long *)0x0) goto LAB_0011b904;
        uVar16 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar12;
        *plVar12 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011b8f0:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_0011b904;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar17[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar17), iVar9 < 0)) ||
         ((-1 < (char)p_Var19->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var19), iVar9 < 0))))
      goto LAB_0011b904;
      lVar13 = pPVar17[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var19->ob_base).ob_size) &&
         ((pPVar17[1].ob_type == (_typeobject *)p_Var19->tp_name ||
          (_typeobject *)p_Var19->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar17[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar17[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        in_x6 = pcVar15;
        if (((byte)((byte)p_Var19->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar17[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar17[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar17[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar17 + 3);
            }
          }
          bVar2 = (byte)p_Var19->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var19->tp_setattr;
          }
          else {
            __s2 = &p_Var19->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var19->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = *(uint *)__s2;
          }
          if (uVar16 == (uint)in_x6) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(__s1,__s2,(long)pcVar15 * lVar13);
              uVar16 = (uint)(iVar9 == 0);
              goto LAB_0011b8f0;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar20];
LAB_0011b948:
  if (values[0] == (PyObject *)0x0) {
LAB_0011b908:
    lVar18 = PyErr_Occurred();
    if (lVar18 == 0) goto LAB_0011b700;
    iVar9 = 0x1d3a;
  }
  else {
    lVar18 = lVar18 + -1;
LAB_0011b664:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar18 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x124308,in_x6), -1 < iVar9)) {
LAB_0011b678:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_5_start_frp_service
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_5_start_frp_service
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_5_start_frp_service
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      code = __pyx_mstate_global_static.__pyx_codeobj__10;
      name = __pyx_mstate_global_static.__pyx_n_s_start_frp_service;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager_start_frp_service;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar17 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar9 = 0x1d71;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011ba00:
        p_Var10 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.start_frp_service",iVar9,
                           0x69,"moonraker/components/frp_manager.py");
      }
      else {
        lVar18 = apPVar6[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[2].ob_refcnt = (Py_ssize_t)apPVar6[0];
        apPVar6[0]->ob_refcnt = lVar18 + 1;
        p_Var10 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_19generator5
                             ,code,closure,name,qualname,module_name);
        pPVar17 = closure;
        if (p_Var10 == (__pyx_CoroutineObject *)0x0) {
          iVar9 = 0x1d79;
          goto LAB_0011ba00;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar18 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar18;
      if (lVar18 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
      goto LAB_0011b758;
    }
    iVar9 = 0x1d3f;
  }
LAB_0011b73c:
  p_Var10 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.start_frp_service",iVar9,0x69,
                     "moonraker/components/frp_manager.py");
LAB_0011b758:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var10->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011baf8
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_27enable_frp_service
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_27enable_frp_service(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_27enable_frp_service
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
  PyObject *code;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var10;
  long lVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  long lVar13;
  long lVar14;
  char *pcVar15;
  char *in_x6;
  uint uVar16;
  PyObject *pPVar17;
  long lVar18;
  _typeobject *p_Var19;
  long lVar20;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar17 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011bb70;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar18) {
        p_Var19 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var19) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar20 = lVar11 + 1;
            if (lVar20 == lVar18) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011bcf8;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar20;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar20];
        }
        goto LAB_0011be40;
      }
LAB_0011bdfc:
      values[0] = (PyObject *)0x0;
      goto LAB_0011be00;
    }
    if (__pyx_nargs == 1) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011bb5c;
    }
  }
LAB_0011bbf8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","enable_frp_service",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x2215;
  goto LAB_0011bc34;
  while( true ) {
    lVar20 = lVar11 + 1;
    if (lVar20 == lVar18) goto LAB_0011bdfc;
    p_Var19 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar20;
    if ((_typeobject *)pPVar17 == p_Var19) break;
LAB_0011bcf8:
    bVar7 = pPVar17->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var19->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar17 != (PyObject *)puVar3) && (bVar7 || p_Var19 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar17,p_Var19,2);
        if (plVar12 == (long *)0x0) goto LAB_0011bdfc;
        uVar16 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar12;
        *plVar12 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011bde8:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_0011bdfc;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar17[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar17), iVar9 < 0)) ||
         ((-1 < (char)p_Var19->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var19), iVar9 < 0))))
      goto LAB_0011bdfc;
      lVar13 = pPVar17[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var19->ob_base).ob_size) &&
         ((pPVar17[1].ob_type == (_typeobject *)p_Var19->tp_name ||
          (_typeobject *)p_Var19->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar17[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar17[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        in_x6 = pcVar15;
        if (((byte)((byte)p_Var19->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar17[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar17[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar17[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar17 + 3);
            }
          }
          bVar2 = (byte)p_Var19->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var19->tp_setattr;
          }
          else {
            __s2 = &p_Var19->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var19->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = *(uint *)__s2;
          }
          if (uVar16 == (uint)in_x6) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(__s1,__s2,(long)pcVar15 * lVar13);
              uVar16 = (uint)(iVar9 == 0);
              goto LAB_0011bde8;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar20];
LAB_0011be40:
  if (values[0] == (PyObject *)0x0) {
LAB_0011be00:
    lVar18 = PyErr_Occurred();
    if (lVar18 == 0) goto LAB_0011bbf8;
    iVar9 = 0x2205;
  }
  else {
    lVar18 = lVar18 + -1;
LAB_0011bb5c:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar18 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123768,in_x6), -1 < iVar9)) {
LAB_0011bb70:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_8_enable_frp_service
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_8_enable_frp_service
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_8_enable_frp_service
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      code = __pyx_mstate_global_static.__pyx_codeobj__13;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      name = __pyx_mstate_global_static.__pyx_n_s_enable_frp_service;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager_enable_frp_service;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar17 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar9 = 0x223c;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011bef8:
        p_Var10 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.enable_frp_service",iVar9,
                           0x8d,"moonraker/components/frp_manager.py");
      }
      else {
        lVar18 = apPVar6[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[2].ob_refcnt = (Py_ssize_t)apPVar6[0];
        apPVar6[0]->ob_refcnt = lVar18 + 1;
        p_Var10 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_28generator8
                             ,code,closure,name,qualname,module_name);
        pPVar17 = closure;
        if (p_Var10 == (__pyx_CoroutineObject *)0x0) {
          iVar9 = 0x2244;
          goto LAB_0011bef8;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar18 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar18;
      if (lVar18 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
      goto LAB_0011bc50;
    }
    iVar9 = 0x220a;
  }
LAB_0011bc34:
  p_Var10 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.enable_frp_service",iVar9,0x8d,
                     "moonraker/components/frp_manager.py");
LAB_0011bc50:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var10->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011bff0
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_24restart_frp_service
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_24restart_frp_service(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_24restart_frp_service
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
  PyObject *code;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var10;
  long lVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  long lVar13;
  long lVar14;
  char *pcVar15;
  char *in_x6;
  uint uVar16;
  PyObject *pPVar17;
  long lVar18;
  _typeobject *p_Var19;
  long lVar20;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar17 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011c068;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar18) {
        p_Var19 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var19) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar20 = lVar11 + 1;
            if (lVar20 == lVar18) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011c1f0;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar20;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar20];
        }
        goto LAB_0011c338;
      }
LAB_0011c2f4:
      values[0] = (PyObject *)0x0;
      goto LAB_0011c2f8;
    }
    if (__pyx_nargs == 1) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011c054;
    }
  }
LAB_0011c0f0:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","restart_frp_service",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x207c;
  goto LAB_0011c12c;
  while( true ) {
    lVar20 = lVar11 + 1;
    if (lVar20 == lVar18) goto LAB_0011c2f4;
    p_Var19 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar20;
    if ((_typeobject *)pPVar17 == p_Var19) break;
LAB_0011c1f0:
    bVar7 = pPVar17->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var19->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar17 != (PyObject *)puVar3) && (bVar7 || p_Var19 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar17,p_Var19,2);
        if (plVar12 == (long *)0x0) goto LAB_0011c2f4;
        uVar16 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar12;
        *plVar12 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011c2e0:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_0011c2f4;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar17[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar17), iVar9 < 0)) ||
         ((-1 < (char)p_Var19->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var19), iVar9 < 0))))
      goto LAB_0011c2f4;
      lVar13 = pPVar17[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var19->ob_base).ob_size) &&
         ((pPVar17[1].ob_type == (_typeobject *)p_Var19->tp_name ||
          (_typeobject *)p_Var19->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar17[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar17[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        in_x6 = pcVar15;
        if (((byte)((byte)p_Var19->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar17[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar17[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar17[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar17 + 3);
            }
          }
          bVar2 = (byte)p_Var19->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var19->tp_setattr;
          }
          else {
            __s2 = &p_Var19->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var19->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = *(uint *)__s2;
          }
          if (uVar16 == (uint)in_x6) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(__s1,__s2,(long)pcVar15 * lVar13);
              uVar16 = (uint)(iVar9 == 0);
              goto LAB_0011c2e0;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar20];
LAB_0011c338:
  if (values[0] == (PyObject *)0x0) {
LAB_0011c2f8:
    lVar18 = PyErr_Occurred();
    if (lVar18 == 0) goto LAB_0011c0f0;
    iVar9 = 0x206c;
  }
  else {
    lVar18 = lVar18 + -1;
LAB_0011c054:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar18 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123738,in_x6), -1 < iVar9)) {
LAB_0011c068:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_7_restart_frp_service
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_7_restart_frp_service
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_7_restart_frp_service
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      code = __pyx_mstate_global_static.__pyx_codeobj__12;
      name = __pyx_mstate_global_static.__pyx_n_s_restart_frp_service;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager_restart_frp_service;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar17 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar9 = 0x20a3;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011c3f0:
        p_Var10 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.restart_frp_service",iVar9,
                           0x81,"moonraker/components/frp_manager.py");
      }
      else {
        lVar18 = apPVar6[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[2].ob_refcnt = (Py_ssize_t)apPVar6[0];
        apPVar6[0]->ob_refcnt = lVar18 + 1;
        p_Var10 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_25generator7
                             ,code,closure,name,qualname,module_name);
        pPVar17 = closure;
        if (p_Var10 == (__pyx_CoroutineObject *)0x0) {
          iVar9 = 0x20ab;
          goto LAB_0011c3f0;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar18 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar18;
      if (lVar18 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
      goto LAB_0011c148;
    }
    iVar9 = 0x2071;
  }
LAB_0011c12c:
  p_Var10 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.restart_frp_service",iVar9,0x81,
                     "moonraker/components/frp_manager.py");
LAB_0011c148:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var10->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011c4e8
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_30disable_frp_service
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_30disable_frp_service(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_30disable_frp_service
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
  PyObject *code;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var10;
  long lVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  long lVar13;
  long lVar14;
  char *pcVar15;
  char *in_x6;
  uint uVar16;
  PyObject *pPVar17;
  long lVar18;
  _typeobject *p_Var19;
  long lVar20;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar17 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011c560;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar18) {
        p_Var19 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var19) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar20 = lVar11 + 1;
            if (lVar20 == lVar18) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011c6e8;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar20;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar20];
        }
        goto LAB_0011c830;
      }
LAB_0011c7ec:
      values[0] = (PyObject *)0x0;
      goto LAB_0011c7f0;
    }
    if (__pyx_nargs == 1) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011c54c;
    }
  }
LAB_0011c5e8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","disable_frp_service",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x23ae;
  goto LAB_0011c624;
  while( true ) {
    lVar20 = lVar11 + 1;
    if (lVar20 == lVar18) goto LAB_0011c7ec;
    p_Var19 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar20;
    if ((_typeobject *)pPVar17 == p_Var19) break;
LAB_0011c6e8:
    bVar7 = pPVar17->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var19->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar17 != (PyObject *)puVar3) && (bVar7 || p_Var19 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar17,p_Var19,2);
        if (plVar12 == (long *)0x0) goto LAB_0011c7ec;
        uVar16 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar12;
        *plVar12 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011c7d8:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_0011c7ec;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar17[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar17), iVar9 < 0)) ||
         ((-1 < (char)p_Var19->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var19), iVar9 < 0))))
      goto LAB_0011c7ec;
      lVar13 = pPVar17[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var19->ob_base).ob_size) &&
         ((pPVar17[1].ob_type == (_typeobject *)p_Var19->tp_name ||
          (_typeobject *)p_Var19->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar17[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar17[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        in_x6 = pcVar15;
        if (((byte)((byte)p_Var19->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar17[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar17[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar17[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar17 + 3);
            }
          }
          bVar2 = (byte)p_Var19->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var19->tp_setattr;
          }
          else {
            __s2 = &p_Var19->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var19->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = *(uint *)__s2;
          }
          if (uVar16 == (uint)in_x6) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(__s1,__s2,(long)pcVar15 * lVar13);
              uVar16 = (uint)(iVar9 == 0);
              goto LAB_0011c7d8;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar20];
LAB_0011c830:
  if (values[0] == (PyObject *)0x0) {
LAB_0011c7f0:
    lVar18 = PyErr_Occurred();
    if (lVar18 == 0) goto LAB_0011c5e8;
    iVar9 = 0x239e;
  }
  else {
    lVar18 = lVar18 + -1;
LAB_0011c54c:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar18 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123750,in_x6), -1 < iVar9)) {
LAB_0011c560:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_9_disable_frp_service
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_9_disable_frp_service
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_9_disable_frp_service
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      code = __pyx_mstate_global_static.__pyx_codeobj__14;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      name = __pyx_mstate_global_static.__pyx_n_s_disable_frp_service;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager_disable_frp_service;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar17 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar9 = 0x23d5;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011c8e8:
        p_Var10 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.disable_frp_service",iVar9,
                           0x99,"moonraker/components/frp_manager.py");
      }
      else {
        lVar18 = apPVar6[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[2].ob_refcnt = (Py_ssize_t)apPVar6[0];
        apPVar6[0]->ob_refcnt = lVar18 + 1;
        p_Var10 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_31generator9
                             ,code,closure,name,qualname,module_name);
        pPVar17 = closure;
        if (p_Var10 == (__pyx_CoroutineObject *)0x0) {
          iVar9 = 0x23dd;
          goto LAB_0011c8e8;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar18 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar18;
      if (lVar18 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
      goto LAB_0011c640;
    }
    iVar9 = 0x23a3;
  }
LAB_0011c624:
  p_Var10 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.disable_frp_service",iVar9,0x99,
                     "moonraker/components/frp_manager.py");
LAB_0011c640:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var10->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011c9e0
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_1load_component
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_1load_component(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_1load_component
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *pPVar10;
  long lVar11;
  long *plVar12;
  PyObject *pPVar13;
  setattrfunc *__s2;
  _typeobject *p_Var14;
  long lVar15;
  __pyx_mstate *kwargs;
  long lVar16;
  char *pcVar17;
  char *in_x6;
  uint uVar18;
  PyObject *func;
  _typeobject *p_Var19;
  long lVar20;
  long lVar21;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar13 = __pyx_mstate_global_static.__pyx_n_s_config;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_config;
  lVar16 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011ca54;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar20 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar20) {
        p_Var14 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var14) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar21 = lVar11 + 1;
            if (lVar21 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011cbe0;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar21;
          } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar21];
        }
        goto LAB_0011cd24;
      }
LAB_0011cce4:
      values[0] = (PyObject *)0x0;
      goto LAB_0011cce8;
    }
    if (__pyx_nargs == 1) {
      lVar20 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011ca44;
    }
  }
LAB_0011cadc:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","load_component",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x2a96;
  goto LAB_0011cb18;
  while( true ) {
    lVar21 = lVar11 + 1;
    if (lVar21 == lVar20) goto LAB_0011cce4;
    p_Var14 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar21;
    if ((_typeobject *)pPVar13 == p_Var14) break;
LAB_0011cbe0:
    bVar7 = pPVar13->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var14->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar21 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar13 != (PyObject *)puVar3) && (bVar7 || p_Var14 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar13,p_Var14,2);
        if (plVar12 == (long *)0x0) goto LAB_0011cce4;
        uVar18 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar18 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = *plVar12;
        *plVar12 = lVar15 + -1;
        if (lVar15 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011ccd0:
        if (uVar18 != 0) {
          if ((int)uVar18 < 0) goto LAB_0011cce4;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar13[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar13), iVar9 < 0)) ||
         ((-1 < (char)p_Var14->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var14), iVar9 < 0))))
      goto LAB_0011cce4;
      lVar15 = pPVar13[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar15 == (p_Var14->ob_base).ob_size) &&
         ((pPVar13[1].ob_type == (_typeobject *)p_Var14->tp_name ||
          (_typeobject *)p_Var14->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar13[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar17 = (char *)((ulong)(byte)((byte)pPVar13[2].ob_refcnt >> 2) & 7);
        uVar18 = (uint)pcVar17;
        in_x6 = pcVar17;
        if (((byte)((byte)p_Var14->tp_basicsize >> 2) & 7) == uVar18) {
          bVar2 = (byte)pPVar13[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var19 = pPVar13[4].ob_type;
          }
          else {
            p_Var19 = (_typeobject *)&pPVar13[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var19 = (_typeobject *)(pPVar13 + 3);
            }
          }
          bVar2 = (byte)p_Var14->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var14->tp_setattr;
          }
          else {
            __s2 = &p_Var14->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var14->tp_dealloc;
            }
          }
          if (uVar18 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(byte *)__s2;
          }
          else if (uVar18 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar18 = *(uint *)__s2;
          }
          if (uVar18 == (uint)in_x6) {
            if (lVar15 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var19,__s2,(long)pcVar17 * lVar15);
              uVar18 = (uint)(iVar9 == 0);
              goto LAB_0011ccd0;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar21];
LAB_0011cd24:
  if (values[0] == (PyObject *)0x0) {
LAB_0011cce8:
    lVar20 = PyErr_Occurred();
    if (lVar20 == 0) goto LAB_0011cadc;
    iVar9 = 0x2a86;
  }
  else {
    lVar20 = lVar20 + -1;
LAB_0011ca44:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar20 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123c40,in_x6), -1 < iVar9)) {
LAB_0011ca54:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      pPVar13 = __pyx_dict_cached_value_18414;
      kwargs = &__pyx_mstate_global_static;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_18413) {
        if (__pyx_dict_cached_value_18414 == (PyObject *)0x0) {
          pPVar13 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_FrpManager);
          goto LAB_0011ce00;
        }
        __pyx_dict_cached_value_18414->ob_refcnt = __pyx_dict_cached_value_18414->ob_refcnt + 1;
LAB_0011ca84:
        p_Var14 = pPVar13->ob_type;
        if ((p_Var14 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
           (p_Var19 = pPVar13[1].ob_type, p_Var19 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          func = (PyObject *)pPVar13[1].ob_refcnt;
          (p_Var19->ob_base).ob_base.ob_refcnt = (p_Var19->ob_base).ob_base.ob_refcnt + 1;
          func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar20 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar20;
          if (lVar20 == 0) {
            (*p_Var14->tp_dealloc)(pPVar13);
          }
          __pyx_pyargnames[0] = (PyObject **)p_Var19;
          __pyx_pyargnames[1] = (PyObject **)apPVar6[0];
          pPVar10 = __Pyx_PyObject_FastCallDict
                              (func,(PyObject **)__pyx_pyargnames,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar20 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
          (p_Var19->ob_base).ob_base.ob_refcnt = lVar20;
          if (lVar20 == 0) {
            (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)apPVar6[0];
          pPVar10 = __Pyx_PyObject_FastCallDict
                              (pPVar13,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)kwargs);
          func = pPVar13;
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        lVar20 = func->ob_refcnt + -1;
        if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          func->ob_refcnt = lVar20;
          if (lVar20 == 0) {
            (*func->ob_type->tp_dealloc)(func);
          }
          goto LAB_0011cb34;
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        func->ob_refcnt = lVar20;
        iVar9 = 0x2ad7;
        if (lVar20 == 0) {
          (*func->ob_type->tp_dealloc)(func);
        }
      }
      else {
        pPVar13 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_FrpManager,
                             (uint64_t *)&__pyx_dict_version_18413,&__pyx_dict_cached_value_18414);
LAB_0011ce00:
        iVar9 = 0x2ac3;
        if (pPVar13 != (PyObject *)0x0) goto LAB_0011ca84;
      }
      pPVar10 = (PyObject *)0x0;
      __Pyx_AddTraceback("moonraker.components.frp_manager.load_component",iVar9,0xea,
                         "moonraker/components/frp_manager.py");
      goto LAB_0011cb34;
    }
    iVar9 = 0x2a8b;
  }
LAB_0011cb18:
  pPVar10 = (PyObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.load_component",iVar9,0xe9,
                     "moonraker/components/frp_manager.py");
LAB_0011cb34:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00137f30) {
    return pPVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011cf70
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_21stop_frp_service
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_21stop_frp_service(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_21stop_frp_service
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
  PyObject *code;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *closure;
  __pyx_CoroutineObject *p_Var10;
  long lVar11;
  _typeobject *__s1;
  long *plVar12;
  setattrfunc *__s2;
  long lVar13;
  long lVar14;
  char *pcVar15;
  char *in_x6;
  uint uVar16;
  PyObject *pPVar17;
  long lVar18;
  _typeobject *p_Var19;
  long lVar20;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar17 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_00137f30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0011cfe8;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar18) {
        p_Var19 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var19) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar20 = lVar11 + 1;
            if (lVar20 == lVar18) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_0011d170;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar20;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar20];
        }
        goto LAB_0011d2b8;
      }
LAB_0011d274:
      values[0] = (PyObject *)0x0;
      goto LAB_0011d278;
    }
    if (__pyx_nargs == 1) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0011cfd4;
    }
  }
LAB_0011d070:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","stop_frp_service",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x1ee3;
  goto LAB_0011d0ac;
  while( true ) {
    lVar20 = lVar11 + 1;
    if (lVar20 == lVar18) goto LAB_0011d274;
    p_Var19 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar20;
    if ((_typeobject *)pPVar17 == p_Var19) break;
LAB_0011d170:
    bVar7 = pPVar17->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var19->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar20 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar17 != (PyObject *)puVar3) && (bVar7 || p_Var19 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar17,p_Var19,2);
        if (plVar12 == (long *)0x0) goto LAB_0011d274;
        uVar16 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = *plVar12;
        *plVar12 = lVar13 + -1;
        if (lVar13 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011d260:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_0011d274;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar17[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar17), iVar9 < 0)) ||
         ((-1 < (char)p_Var19->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var19), iVar9 < 0))))
      goto LAB_0011d274;
      lVar13 = pPVar17[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar13 == (p_Var19->ob_base).ob_size) &&
         ((pPVar17[1].ob_type == (_typeobject *)p_Var19->tp_name ||
          (_typeobject *)p_Var19->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar17[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar17[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        in_x6 = pcVar15;
        if (((byte)((byte)p_Var19->tp_basicsize >> 2) & 7) == uVar16) {
          bVar2 = (byte)pPVar17[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar17[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar17[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar17 + 3);
            }
          }
          bVar2 = (byte)p_Var19->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var19->tp_setattr;
          }
          else {
            __s2 = &p_Var19->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var19->tp_dealloc;
            }
          }
          if (uVar16 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar16 = *(uint *)__s2;
          }
          if (uVar16 == (uint)in_x6) {
            if (lVar13 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(__s1,__s2,(long)pcVar15 * lVar13);
              uVar16 = (uint)(iVar9 == 0);
              goto LAB_0011d260;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar20];
LAB_0011d2b8:
  if (values[0] == (PyObject *)0x0) {
LAB_0011d278:
    lVar18 = PyErr_Occurred();
    if (lVar18 == 0) goto LAB_0011d070;
    iVar9 = 0x1ed3;
  }
  else {
    lVar18 = lVar18 + -1;
LAB_0011cfd4:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar18 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123720,in_x6), -1 < iVar9)) {
LAB_0011cfe8:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct_6_stop_frp_service
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct_6_stop_frp_service
                          (__pyx_mstate_global_static.
                           __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct_6_stop_frp_service
                           ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
      code = __pyx_mstate_global_static.__pyx_codeobj__11;
      name = __pyx_mstate_global_static.__pyx_n_s_stop_frp_service;
      module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
      qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager_stop_frp_service;
      type = __pyx_mstate_global_static.__pyx_CoroutineType;
      pPVar17 = (PyObject *)PTR__Py_NoneStruct_00137f48;
      if (closure == (PyObject *)0x0) {
        iVar9 = 0x1f0a;
        *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011d370:
        p_Var10 = (__pyx_CoroutineObject *)0x0;
        __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.stop_frp_service",iVar9,0x75
                           ,"moonraker/components/frp_manager.py");
      }
      else {
        lVar18 = apPVar6[0]->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
        closure[2].ob_refcnt = (Py_ssize_t)apPVar6[0];
        apPVar6[0]->ob_refcnt = lVar18 + 1;
        p_Var10 = __Pyx__Coroutine_New
                            (type,
                             __pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_22generator6
                             ,code,closure,name,qualname,module_name);
        pPVar17 = closure;
        if (p_Var10 == (__pyx_CoroutineObject *)0x0) {
          iVar9 = 0x1f12;
          goto LAB_0011d370;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar18 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar18;
      if (lVar18 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
      goto LAB_0011d0c8;
    }
    iVar9 = 0x1ed8;
  }
LAB_0011d0ac:
  p_Var10 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.stop_frp_service",iVar9,0x75,
                     "moonraker/components/frp_manager.py");
LAB_0011d0c8:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var10->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011d468
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_3_handle_frp_control
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_3_handle_frp_control(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_3_handle_frp_control
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
  long *plVar11;
  _typeobject *p_Var12;
  setattrfunc *pp_Var13;
  long lVar14;
  long lVar15;
  long lVar16;
  char *pcVar17;
  char *pcVar18;
  uint uVar19;
  long lVar20;
  uint uVar21;
  __pyx_CoroutineObject *p_Var22;
  PyObject *pPVar23;
  _typeobject *p_Var24;
  long lVar25;
  long lVar26;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
  pPVar23 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_web_request@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  lVar20 = *(long *)PTR___stack_chk_guard_00137f30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_web_request;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar18 = PTR___stack_chk_guard_00137f30;
    if (__pyx_nargs == 1) {
      lVar16 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      lVar26 = lVar16;
      goto LAB_0011d73c;
    }
    if (__pyx_nargs != 2) {
      if (__pyx_nargs == 0) {
        lVar26 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
        if (0 < lVar26) {
          p_Var24 = __pyx_kwds[1].ob_type;
          if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var24) {
            values[0] = *kwvalues;
          }
          else {
            lVar16 = 0;
            do {
              lVar14 = lVar16 + 1;
              if (lVar14 == lVar26) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
                lVar16 = 0;
                goto LAB_0011d690;
              }
              pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar16;
              lVar16 = lVar14;
            } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
            values[0] = kwvalues[lVar14];
          }
          goto LAB_0011d72c;
        }
LAB_0011da18:
        values[0] = (PyObject *)0x0;
        goto LAB_0011da1c;
      }
      goto LAB_0011d4dc;
    }
    values[0] = *__pyx_args;
    lVar26 = __pyx_kwds[1].ob_refcnt;
    values[1] = __pyx_args[1];
    goto LAB_0011d618;
  }
  if (__pyx_nargs != 2) {
LAB_0011d4dc:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_handle_frp_control"
                 ,"exactly",2,"s",__pyx_nargs);
    iVar10 = 0x10ee;
    goto LAB_0011d518;
  }
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011d574:
                    /* Unresolved local var:
                       __pyx_obj_9moonraker_10components_11frp_manager___pyx_scope_struct___handle_frp_control
                       * __pyx_cur_scope@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar6 = values[0];
  closure = __pyx_tp_new_9moonraker_10components_11frp_manager___pyx_scope_struct___handle_frp_control
                      (__pyx_mstate_global_static.
                       __pyx_ptype_9moonraker_10components_11frp_manager___pyx_scope_struct___handle_frp_control
                       ,__pyx_mstate_global_static.__pyx_empty_tuple,(PyObject *)0x0);
  module_name = __pyx_mstate_global_static.__pyx_n_s_moonraker_components_frp_manager;
  name = __pyx_mstate_global_static.__pyx_n_s_handle_frp_control;
  qualname = __pyx_mstate_global_static.__pyx_n_s_FrpManager__handle_frp_control;
  type = __pyx_mstate_global_static.__pyx_CoroutineType;
  pPVar23 = (PyObject *)PTR__Py_NoneStruct_00137f48;
  if (closure == (PyObject *)0x0) {
    iVar10 = 0x1115;
    *(long *)PTR__Py_NoneStruct_00137f48 = *(long *)PTR__Py_NoneStruct_00137f48 + 1;
LAB_0011da78:
    p_Var22 = (__pyx_CoroutineObject *)0x0;
    __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._handle_frp_control",iVar10,0x1f
                       ,"moonraker/components/frp_manager.py");
  }
  else {
    lVar26 = pPVar6->ob_refcnt;
                    /* Unresolved local var: __pyx_CoroutineObject * gen@[???] */
    closure[1].ob_type = (_typeobject *)pPVar6;
    pPVar6->ob_refcnt = lVar26 + 1;
    lVar26 = pPVar7->ob_refcnt;
    closure[2].ob_refcnt = (Py_ssize_t)pPVar7;
    pPVar7->ob_refcnt = lVar26 + 1;
    p_Var22 = __Pyx__Coroutine_New
                        (type,__pyx_gb_9moonraker_10components_11frp_manager_10FrpManager_4generator
                         ,__pyx_mstate_global_static.__pyx_codeobj_,closure,name,qualname,
                         module_name);
    pPVar23 = closure;
    if (p_Var22 == (__pyx_CoroutineObject *)0x0) {
      iVar10 = 0x1120;
      goto LAB_0011da78;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar26 = pPVar23->ob_refcnt + -1;
  pPVar23->ob_refcnt = lVar26;
  if (lVar26 == 0) {
    (*pPVar23->ob_type->tp_dealloc)(pPVar23);
  }
  goto LAB_0011d534;
  while( true ) {
    lVar14 = lVar16 + 1;
    if (lVar14 == lVar26) goto LAB_0011da18;
    p_Var24 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar16];
    lVar16 = lVar14;
    if ((_typeobject *)pPVar23 == p_Var24) break;
LAB_0011d690:
    bVar8 = pPVar23->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var24->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar23 != (PyObject *)puVar3) && (bVar8 || p_Var24 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar23,p_Var24,2);
        if (plVar11 == (long *)0x0) goto LAB_0011da18;
        uVar19 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar11 != (long *)puVar3) {
          uVar19 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = *plVar11;
        *plVar11 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011da08:
        if (uVar19 != 0) {
          if ((int)uVar19 < 0) goto LAB_0011da18;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar23[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar23), iVar10 < 0)) ||
         ((-1 < (char)p_Var24->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var24), iVar10 < 0))))
      goto LAB_0011da18;
      lVar14 = pPVar23[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar14 == (p_Var24->ob_base).ob_size) &&
         ((pPVar23[1].ob_type == (_typeobject *)p_Var24->tp_name ||
          (_typeobject *)p_Var24->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar23[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar17 = (char *)((ulong)(byte)((byte)pPVar23[2].ob_refcnt >> 2) & 7);
        uVar19 = (uint)pcVar17;
        pcVar18 = pcVar17;
        if (((byte)((byte)p_Var24->tp_basicsize >> 2) & 7) == uVar19) {
          bVar2 = (byte)pPVar23[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var12 = pPVar23[4].ob_type;
          }
          else {
            p_Var12 = (_typeobject *)&pPVar23[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var12 = (_typeobject *)(pPVar23 + 3);
            }
          }
          bVar2 = (byte)p_Var24->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var13 = (setattrfunc *)p_Var24->tp_setattr;
          }
          else {
            pp_Var13 = &p_Var24->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var13 = (setattrfunc *)&p_Var24->tp_dealloc;
            }
          }
          if (uVar19 == 1) {
            pcVar18 = (char *)(ulong)*(byte *)&(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar19 = (uint)*(byte *)pp_Var13;
          }
          else if (uVar19 == 2) {
            pcVar18 = (char *)(ulong)*(ushort *)&(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar19 = (uint)*(ushort *)pp_Var13;
          }
          else {
            pcVar18 = (char *)(ulong)*(uint *)&(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar19 = *(uint *)pp_Var13;
          }
          if (uVar19 == (uint)pcVar18) {
            if (lVar14 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var12,pp_Var13,(long)pcVar17 * lVar14);
              uVar19 = (uint)(iVar10 == 0);
              goto LAB_0011da08;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar16];
LAB_0011d72c:
  if (values[0] != (PyObject *)0x0) {
    lVar16 = __pyx_kwds[1].ob_refcnt;
    lVar26 = lVar26 + -1;
LAB_0011d73c:
    pPVar23 = __pyx_mstate_global_static.__pyx_n_s_web_request;
    puVar5 = PTR_PyUnicode_Type_00137fb0;
    puVar4 = PTR__Py_TrueStruct_00137f50;
    puVar3 = PTR__Py_NoneStruct_00137f48;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar16) {
      p_Var24 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_web_request == p_Var24) {
        values[1] = *kwvalues;
      }
      else {
        lVar14 = 0;
        do {
          lVar25 = lVar14 + 1;
          if (lVar25 == lVar16) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar14 = 0;
            goto LAB_0011d7a0;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar14;
          lVar14 = lVar25;
        } while (__pyx_mstate_global_static.__pyx_n_s_web_request != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar25];
      }
      goto LAB_0011d8a8;
    }
LAB_0011d950:
    values[1] = (PyObject *)0x0;
    goto LAB_0011d954;
  }
LAB_0011da1c:
  lVar26 = PyErr_Occurred();
  if (lVar26 == 0) goto LAB_0011d4dc;
  iVar10 = 0x10d2;
  goto LAB_0011d518;
  while( true ) {
    lVar25 = lVar14 + 1;
    if (lVar25 == lVar16) goto LAB_0011d950;
    p_Var24 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar14];
    lVar14 = lVar25;
    if ((_typeobject *)pPVar23 == p_Var24) break;
LAB_0011d7a0:
    bVar8 = pPVar23->ob_type != (_typeobject *)puVar5;
    bVar9 = (p_Var24->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar25 = lVar14;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar23 != (PyObject *)puVar3) && (bVar8 || p_Var24 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar23,p_Var24,2);
        if (plVar11 == (long *)0x0) goto LAB_0011d950;
        uVar19 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar11 != (long *)puVar3) {
          uVar19 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = *plVar11;
        *plVar11 = lVar15 + -1;
        if (lVar15 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_0011d944:
        if (uVar19 != 0) {
          if ((int)uVar19 < 0) goto LAB_0011d950;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar23[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar23), iVar10 < 0)) ||
         ((-1 < (char)p_Var24->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var24), iVar10 < 0))))
      goto LAB_0011d950;
      lVar15 = pPVar23[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar15 == (p_Var24->ob_base).ob_size) &&
         ((pPVar23[1].ob_type == (_typeobject *)p_Var24->tp_name ||
          (_typeobject *)p_Var24->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar23[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar18 = (char *)((ulong)(byte)((byte)pPVar23[2].ob_refcnt >> 2) & 7);
        uVar19 = (uint)pcVar18;
        if (((byte)((byte)p_Var24->tp_basicsize >> 2) & 7) == uVar19) {
          bVar2 = (byte)pPVar23[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var12 = pPVar23[4].ob_type;
          }
          else {
            p_Var12 = (_typeobject *)&pPVar23[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var12 = (_typeobject *)(pPVar23 + 3);
            }
          }
          bVar2 = (byte)p_Var24->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var13 = (setattrfunc *)p_Var24->tp_setattr;
          }
          else {
            pp_Var13 = &p_Var24->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var13 = (setattrfunc *)&p_Var24->tp_dealloc;
            }
          }
          if (uVar19 == 1) {
            uVar19 = (uint)(byte)(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(byte *)pp_Var13;
          }
          else if (uVar19 == 2) {
            uVar19 = (uint)(ushort)(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(ushort *)pp_Var13;
          }
          else {
            uVar19 = (uint)(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar21 = *(uint *)pp_Var13;
          }
          if (uVar21 == uVar19) {
            if (lVar15 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var12,pp_Var13,(long)pcVar18 * lVar15);
              uVar19 = (uint)(iVar10 == 0);
              goto LAB_0011d944;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar25];
LAB_0011d8a8:
  if (values[1] == (PyObject *)0x0) {
LAB_0011d954:
    lVar26 = PyErr_Occurred();
    if (lVar26 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                   "_handle_frp_control","exactly",2,"s",1);
      iVar10 = 0x10dc;
    }
    else {
      iVar10 = 0x10da;
    }
  }
  else {
    lVar26 = lVar26 + -1;
LAB_0011d618:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar26 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x123650,pcVar18), -1 < iVar10))
    goto LAB_0011d574;
    iVar10 = 0x10e1;
  }
LAB_0011d518:
  p_Var22 = (__pyx_CoroutineObject *)0x0;
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager._handle_frp_control",iVar10,0x1f,
                     "moonraker/components/frp_manager.py");
LAB_0011d534:
  if (lVar20 == *(long *)PTR___stack_chk_guard_00137f30) {
    return &p_Var22->ob_base;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0011dc78
 * Symbol:  __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_1__init__
 * Signature: PyObject * __pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_9moonraker_10components_11frp_manager_10FrpManager_1__init__
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  PyObject *pPVar9;
  PyObject *pPVar10;
  PyObject *func;
  PyObject *pPVar11;
  long *plVar12;
  setattrfunc *pp_Var13;
  getattrofunc p_Var14;
  long lVar15;
  long lVar16;
  long lVar17;
  setattrofunc p_Var18;
  PyObject *pPVar19;
  __pyx_mstate *kwargs;
  char *pcVar20;
  char *pcVar21;
  uint uVar22;
  long lVar23;
  uint uVar24;
  long lVar25;
  _typeobject *p_Var26;
  int py_line;
  PyObject *pPVar27;
  long lVar28;
  _typeobject *p_Var29;
  PyObject *func_00;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
  pPVar9 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00137fb0;
  puVar4 = PTR__Py_TrueStruct_00137f50;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00137f48;
  lVar23 = *(long *)PTR___stack_chk_guard_00137f30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_config;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar21 = PTR___stack_chk_guard_00137f30;
    if (__pyx_nargs == 1) {
      lVar16 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      lVar28 = lVar16;
      goto LAB_0011e73c;
    }
    if (__pyx_nargs != 2) {
      if (__pyx_nargs == 0) {
        lVar28 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
        if (0 < lVar28) {
          p_Var26 = __pyx_kwds[1].ob_type;
          if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var26) {
            values[0] = *kwvalues;
          }
          else {
            lVar16 = 0;
            do {
              lVar15 = lVar16 + 1;
              if (lVar15 == lVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
                lVar16 = 0;
                goto LAB_0011e690;
              }
              pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar16;
              lVar16 = lVar15;
            } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
            values[0] = kwvalues[lVar15];
          }
          goto LAB_0011e72c;
        }
LAB_0011ea60:
        values[0] = (PyObject *)0x0;
        goto LAB_0011ea64;
      }
      goto LAB_0011dcec;
    }
    values[0] = *__pyx_args;
    lVar28 = __pyx_kwds[1].ob_refcnt;
    values[1] = __pyx_args[1];
    goto LAB_0011e618;
  }
  if (__pyx_nargs != 2) {
LAB_0011dcec:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 2,"s",__pyx_nargs);
    iVar8 = 0xf32;
    goto LAB_0011dd28;
  }
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011dd80:
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
  pPVar9 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var18 = values[0]->ob_type->tp_setattro;
  if (p_Var18 == (setattrofunc)0x0) {
    iVar8 = PyObject_SetAttr();
  }
  else {
    iVar8 = (*p_Var18)(values[0],__pyx_mstate_global_static.__pyx_n_s_config,values[1]);
  }
  pPVar19 = __pyx_dict_cached_value_16503;
  if (iVar8 < 0) {
    py_line = 10;
    iVar8 = 0xf62;
    goto LAB_0011eaa0;
  }
  if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16502) {
    if (__pyx_dict_cached_value_16503 == (PyObject *)0x0) {
      pPVar19 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
      goto LAB_0011eaec;
    }
    __pyx_dict_cached_value_16503->ob_refcnt = __pyx_dict_cached_value_16503->ob_refcnt + 1;
  }
  else {
    pPVar19 = __Pyx__GetModuleGlobalName
                        (__pyx_mstate_global_static.__pyx_n_s_logging,
                         (uint64_t *)&__pyx_dict_version_16502,&__pyx_dict_cached_value_16503);
LAB_0011eaec:
    if (pPVar19 == (PyObject *)0x0) {
      py_line = 0xb;
      iVar8 = 0xf6b;
      goto LAB_0011eaa0;
    }
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var14 = pPVar19->ob_type->tp_getattro;
  if (p_Var14 == (getattrofunc)0x0) {
    pPVar10 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar10 = (*p_Var14)(pPVar19,__pyx_mstate_global_static.__pyx_n_s_getLogger);
  }
  lVar28 = pPVar19->ob_refcnt + -1;
  if (pPVar10 == (PyObject *)0x0) {
    py_line = 0xb;
    iVar8 = 0xf6d;
    func = (PyObject *)0x0;
    goto LAB_0011eb34;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  pPVar19->ob_refcnt = lVar28;
  if (lVar28 == 0) {
    (*pPVar19->ob_type->tp_dealloc)(pPVar19);
  }
  p_Var26 = pPVar10->ob_type;
  if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
     (p_Var29 = pPVar10[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    pPVar11 = (PyObject *)pPVar10[1].ob_refcnt;
    (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
    pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar28 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*p_Var26->tp_dealloc)(pPVar10);
    }
    __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_moonraker_frp;
    __pyx_pyargnames[0] = (PyObject **)p_Var29;
    func = __Pyx_PyObject_FastCallDict
                     (pPVar11,(PyObject **)__pyx_pyargnames,2,
                      __pyx_mstate_global_static.__pyx_kp_u_moonraker_frp);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
    (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
    }
  }
  else {
    __pyx_pyargnames[0] = (PyObject **)0x0;
    __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_moonraker_frp;
    func = __Pyx_PyObject_FastCallDict
                     (pPVar10,(PyObject **)(__pyx_pyargnames + 1),1,
                      __pyx_mstate_global_static.__pyx_kp_u_moonraker_frp);
    pPVar11 = pPVar10;
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (func == (PyObject *)0x0) {
    py_line = 0xb;
    iVar8 = 0xf82;
LAB_0011ec14:
    lVar28 = pPVar11->ob_refcnt + -1;
LAB_0011ec1c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    goto LAB_0011eaa0;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar28 = pPVar11->ob_refcnt + -1;
  pPVar11->ob_refcnt = lVar28;
  if (lVar28 == 0) {
    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var18 = pPVar9->ob_type->tp_setattro;
  if (p_Var18 == (setattrofunc)0x0) {
    iVar8 = PyObject_SetAttr();
  }
  else {
    iVar8 = (*p_Var18)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_logger,func);
  }
  lVar28 = func->ob_refcnt + -1;
  if (iVar8 < 0) {
    iVar8 = 0xf86;
    py_line = 0xb;
LAB_0011eb04:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar28;
    if (lVar28 != 0) goto LAB_0011eaa0;
LAB_0011eb0c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    (*func->ob_type->tp_dealloc)(func);
  }
  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    pPVar11 = __pyx_dict_cached_value_16514;
    kwargs = &__pyx_mstate_global_static;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16513) {
      if (__pyx_dict_cached_value_16514 == (PyObject *)0x0) {
        pPVar11 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_asyncio);
        goto LAB_0011ee74;
      }
      __pyx_dict_cached_value_16514->ob_refcnt = __pyx_dict_cached_value_16514->ob_refcnt + 1;
    }
    else {
      pPVar11 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_asyncio,
                           (uint64_t *)&__pyx_dict_version_16513,&__pyx_dict_cached_value_16514);
LAB_0011ee74:
      if (pPVar11 == (PyObject *)0x0) {
        py_line = 0xc;
        iVar8 = 0xf90;
        goto LAB_0011eaa0;
      }
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var14 = pPVar11->ob_type->tp_getattro;
    if (p_Var14 == (getattrofunc)0x0) {
      pPVar10 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar10 = (*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_Lock);
    }
    lVar28 = pPVar11->ob_refcnt + -1;
    if (pPVar10 == (PyObject *)0x0) {
      py_line = 0xc;
      iVar8 = 0xf92;
      goto LAB_0011ec1c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    p_Var26 = pPVar10->ob_type;
    if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
       (p_Var29 = pPVar10[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar19 = (PyObject *)pPVar10[1].ob_refcnt;
      (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
      pPVar19->ob_refcnt = pPVar19->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar28 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar28;
      if (lVar28 == 0) {
        (*p_Var26->tp_dealloc)(pPVar10);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var29;
      func = __Pyx_PyObject_FastCallDict(pPVar19,(PyObject **)__pyx_pyargnames,1,(PyObject *)kwargs)
      ;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
      if (lVar28 == 0) {
        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      func = __Pyx_PyObject_FastCallDict
                       (pPVar10,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)kwargs);
      pPVar19 = pPVar10;
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    if (func == (PyObject *)0x0) {
      py_line = 0xc;
      iVar8 = 0xfa7;
LAB_0011eec8:
      func = (PyObject *)0x0;
      lVar28 = pPVar19->ob_refcnt + -1;
      goto LAB_0011eb34;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar28 = pPVar19->ob_refcnt + -1;
    pPVar19->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var18 = pPVar9->ob_type->tp_setattro;
    if (p_Var18 == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var18)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_frp_lock,func);
    }
    lVar28 = func->ob_refcnt + -1;
    if (iVar8 < 0) {
      iVar8 = 0xfab;
      py_line = 0xc;
      goto LAB_0011eb04;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar28;
    if (lVar28 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    pPVar19 = (PyObject *)pPVar9->ob_type->tp_setattro;
    if (pPVar19 == (PyObject *)0x0) {
      iVar8 = PyObject_SetAttr(pPVar9,__pyx_mstate_global_static.__pyx_n_s_service_name,
                               __pyx_mstate_global_static.__pyx_kp_u_QIDILink_client_service);
    }
    else {
      iVar8 = (*(code *)pPVar19)();
    }
    if (iVar8 < 0) {
      py_line = 0xd;
      iVar8 = 0xfb5;
    }
    else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var14 = pPVar9->ob_type->tp_getattro;
      if (p_Var14 == (getattrofunc)0x0) {
        pPVar11 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar11 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_config);
      }
      if (pPVar11 == (PyObject *)0x0) {
        py_line = 0x10;
        iVar8 = 0xfbe;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var14 = pPVar11->ob_type->tp_getattro;
        if (p_Var14 == (getattrofunc)0x0) {
          func = (PyObject *)PyObject_GetAttr();
        }
        else {
          func = (*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_get_server);
        }
        lVar28 = pPVar11->ob_refcnt + -1;
        if (func == (PyObject *)0x0) {
          py_line = 0x10;
          iVar8 = 0xfc0;
          goto LAB_0011ec1c;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar11->ob_refcnt = lVar28;
        if (lVar28 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        p_Var26 = func->ob_type;
        if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
           (p_Var29 = func[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar10 = (PyObject *)func[1].ob_refcnt;
          (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
          pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar28 = func->ob_refcnt + -1;
          func->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            (*p_Var26->tp_dealloc)(func);
          }
          __pyx_pyargnames[1] = (PyObject **)0x0;
          __pyx_pyargnames[0] = (PyObject **)p_Var29;
          pPVar19 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)__pyx_pyargnames,1,pPVar19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
          (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
          func = pPVar10;
          if (lVar28 == 0) {
            (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)0x0;
          pPVar19 = __Pyx_PyObject_FastCallDict(func,(PyObject **)(__pyx_pyargnames + 1),0,pPVar19);
        }
        if (pPVar19 == (PyObject *)0x0) {
          iVar8 = 0xfd5;
          py_line = 0x10;
LAB_0011eb40:
          lVar28 = func->ob_refcnt + -1;
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar28 = func->ob_refcnt + -1;
          func->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            (*func->ob_type->tp_dealloc)(func);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var14 = pPVar19->ob_type->tp_getattro;
          if (p_Var14 == (getattrofunc)0x0) {
            func = (PyObject *)PyObject_GetAttr();
          }
          else {
            func = (*p_Var14)(pPVar19,__pyx_mstate_global_static.__pyx_n_s_register_endpoint);
          }
          lVar28 = pPVar19->ob_refcnt + -1;
          if (func == (PyObject *)0x0) {
            py_line = 0x10;
            iVar8 = 0xfd9;
LAB_0011eb34:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar19->ob_refcnt = lVar28;
            if (lVar28 == 0) {
              (*pPVar19->ob_type->tp_dealloc)(pPVar19);
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
            if (func == (PyObject *)0x0) goto LAB_0011eaa0;
            goto LAB_0011eb40;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar19->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            (*pPVar19->ob_type->tp_dealloc)(pPVar19);
          }
          pPVar19 = (PyObject *)PyList_New(1);
          pPVar10 = __pyx_mstate_global_static.__pyx_n_u_POST;
          if (pPVar19 != (PyObject *)0x0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var26 = pPVar19[1].ob_type;
            p_Var14 = pPVar9->ob_type->tp_getattro;
            (__pyx_mstate_global_static.__pyx_n_u_POST)->ob_refcnt =
                 (__pyx_mstate_global_static.__pyx_n_u_POST)->ob_refcnt + 1;
            (p_Var26->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar10;
            if (p_Var14 == (getattrofunc)0x0) {
              pPVar10 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar10 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_handle_frp_control);
            }
            if (pPVar10 == (PyObject *)0x0) {
              py_line = 0x11;
              iVar8 = 0xfe9;
              lVar28 = pPVar19->ob_refcnt + -1;
            }
            else {
              p_Var26 = func->ob_type;
              if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
                 (p_Var29 = func[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                func_00 = (PyObject *)func[1].ob_refcnt;
                (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                func_00->ob_refcnt = func_00->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = func->ob_refcnt + -1;
                func->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*p_Var26->tp_dealloc)(func);
                }
                __pyx_pyargnames[1] =
                     (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_printer_frp_control;
                pPVar27 = __pyx_mstate_global_static.__pyx_kp_u_printer_frp_control;
                __pyx_pyargnames[0] = (PyObject **)p_Var29;
                __pyx_pyargnames[2] = (PyObject **)pPVar19;
                pPVar11 = __Pyx_PyObject_FastCallDict
                                    (func_00,(PyObject **)__pyx_pyargnames,4,
                                     __pyx_mstate_global_static.__pyx_kp_u_printer_frp_control);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
                func = func_00;
                if (lVar28 == 0) {
                  (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                }
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] =
                     (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_printer_frp_control;
                pPVar27 = __pyx_mstate_global_static.__pyx_kp_u_printer_frp_control;
                __pyx_pyargnames[2] = (PyObject **)pPVar19;
                pPVar11 = __Pyx_PyObject_FastCallDict
                                    (func,(PyObject **)(__pyx_pyargnames + 1),3,
                                     __pyx_mstate_global_static.__pyx_kp_u_printer_frp_control);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = pPVar19->ob_refcnt + -1;
              pPVar19->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*pPVar19->ob_type->tp_dealloc)(pPVar19);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = pPVar10->ob_refcnt + -1;
              pPVar10->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*pPVar10->ob_type->tp_dealloc)(pPVar10);
              }
              if (pPVar11 == (PyObject *)0x0) {
                iVar8 = 0xfff;
                py_line = 0x10;
                goto LAB_0011eb40;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = func->ob_refcnt + -1;
              func->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*func->ob_type->tp_dealloc)(func);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar28 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var14 = pPVar9->ob_type->tp_getattro;
              if (p_Var14 == (getattrofunc)0x0) {
                pPVar11 = (PyObject *)PyObject_GetAttr();
              }
              else {
                pPVar11 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_config);
              }
              if (pPVar11 == (PyObject *)0x0) {
                py_line = 0x14;
                iVar8 = 0x100c;
                goto LAB_0011eaa0;
              }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var14 = pPVar11->ob_type->tp_getattro;
              if (p_Var14 == (getattrofunc)0x0) {
                pPVar19 = (PyObject *)PyObject_GetAttr();
              }
              else {
                pPVar19 = (*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_get_server);
              }
              lVar28 = pPVar11->ob_refcnt + -1;
              if (pPVar19 == (PyObject *)0x0) {
                py_line = 0x14;
                iVar8 = 0x100e;
                goto LAB_0011ec1c;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              pPVar11->ob_refcnt = lVar28;
              if (lVar28 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
              p_Var26 = pPVar19->ob_type;
              if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
                 (p_Var29 = pPVar19[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar10 = (PyObject *)pPVar19[1].ob_refcnt;
                (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = pPVar19->ob_refcnt + -1;
                pPVar19->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*p_Var26->tp_dealloc)(pPVar19);
                }
                __pyx_pyargnames[1] = (PyObject **)0x0;
                __pyx_pyargnames[0] = (PyObject **)p_Var29;
                func = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)__pyx_pyargnames,1,pPVar27);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
                pPVar19 = pPVar10;
                if (lVar28 == 0) {
                  (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                }
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = (PyObject **)0x0;
                func = __Pyx_PyObject_FastCallDict
                                 (pPVar19,(PyObject **)(__pyx_pyargnames + 1),0,pPVar27);
              }
              lVar28 = pPVar19->ob_refcnt + -1;
              if (func == (PyObject *)0x0) {
                py_line = 0x14;
                iVar8 = 0x1023;
              }
              else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                pPVar19->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                p_Var14 = func->ob_type->tp_getattro;
                if (p_Var14 == (getattrofunc)0x0) {
                  pPVar19 = (PyObject *)PyObject_GetAttr();
                }
                else {
                  pPVar19 = (*p_Var14)(func,__pyx_mstate_global_static.__pyx_n_s_register_endpoint);
                }
                lVar28 = func->ob_refcnt + -1;
                if (pPVar19 == (PyObject *)0x0) {
                  py_line = 0x14;
                  iVar8 = 0x1027;
                  goto LAB_0011eb48;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                func->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*func->ob_type->tp_dealloc)(func);
                }
                func = (PyObject *)PyList_New(1);
                pPVar10 = __pyx_mstate_global_static.__pyx_n_u_POST;
                if (func == (PyObject *)0x0) {
                  py_line = 0x15;
                  iVar8 = 0x1032;
                  lVar28 = pPVar19->ob_refcnt + -1;
                }
                else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var26 = func[1].ob_type;
                  p_Var14 = pPVar9->ob_type->tp_getattro;
                  (__pyx_mstate_global_static.__pyx_n_u_POST)->ob_refcnt =
                       (__pyx_mstate_global_static.__pyx_n_u_POST)->ob_refcnt + 1;
                  (p_Var26->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar10;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar10 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar10 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.
                                                __pyx_n_s_handle_frp_update);
                  }
                  if (pPVar10 == (PyObject *)0x0) {
                    py_line = 0x15;
                    iVar8 = 0x1037;
                    lVar28 = pPVar19->ob_refcnt + -1;
                  }
                  else {
                    p_Var26 = pPVar19->ob_type;
                    if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
                       (p_Var29 = pPVar19[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar27 = (PyObject *)pPVar19[1].ob_refcnt;
                      (p_Var29->ob_base).ob_base.ob_refcnt =
                           (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                      pPVar27->ob_refcnt = pPVar27->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar28 = pPVar19->ob_refcnt + -1;
                      pPVar19->ob_refcnt = lVar28;
                      if (lVar28 == 0) {
                        (*p_Var26->tp_dealloc)(pPVar19);
                      }
                      __pyx_pyargnames[1] =
                           (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_printer_frp_update;
                      __pyx_pyargnames[0] = (PyObject **)p_Var29;
                      __pyx_pyargnames[2] = (PyObject **)func;
                      pPVar11 = __Pyx_PyObject_FastCallDict
                                          (pPVar27,(PyObject **)__pyx_pyargnames,4,
                                           __pyx_mstate_global_static.__pyx_kp_u_printer_frp_update)
                      ;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
                      pPVar19 = pPVar27;
                      if (lVar28 == 0) {
                        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] =
                           (PyObject **)__pyx_mstate_global_static.__pyx_kp_u_printer_frp_update;
                      __pyx_pyargnames[2] = (PyObject **)func;
                      pPVar11 = __Pyx_PyObject_FastCallDict
                                          (pPVar19,(PyObject **)(__pyx_pyargnames + 1),3,
                                           __pyx_mstate_global_static.__pyx_kp_u_printer_frp_update)
                      ;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = func->ob_refcnt + -1;
                    func->ob_refcnt = lVar28;
                    if (lVar28 == 0) {
                      (*func->ob_type->tp_dealloc)(func);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = pPVar10->ob_refcnt + -1;
                    pPVar10->ob_refcnt = lVar28;
                    if (lVar28 == 0) {
                      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                    }
                    if (pPVar11 == (PyObject *)0x0) {
                      py_line = 0x14;
                      iVar8 = 0x104d;
                      goto LAB_0011eec8;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = pPVar19->ob_refcnt + -1;
                    pPVar19->ob_refcnt = lVar28;
                    if (lVar28 == 0) {
                      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = pPVar11->ob_refcnt + -1;
                    pPVar11->ob_refcnt = lVar28;
                    if (lVar28 == 0) {
                      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                    p_Var14 = pPVar9->ob_type->tp_getattro;
                    if (p_Var14 == (getattrofunc)0x0) {
                      pPVar19 = (PyObject *)PyObject_GetAttr();
                    }
                    else {
                      pPVar19 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_logger);
                    }
                    if (pPVar19 == (PyObject *)0x0) {
                      py_line = 0x1d;
                      iVar8 = 0x105a;
                      goto LAB_0011eaa0;
                    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                    p_Var14 = pPVar19->ob_type->tp_getattro;
                    if (p_Var14 == (getattrofunc)0x0) {
                      pPVar11 = (PyObject *)PyObject_GetAttr();
                    }
                    else {
                      pPVar11 = (*p_Var14)(pPVar19,__pyx_mstate_global_static.__pyx_n_s_info);
                    }
                    lVar28 = pPVar19->ob_refcnt + -1;
                    if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      pPVar19->ob_refcnt = lVar28;
                      if (lVar28 == 0) {
                        (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                      }
                      p_Var26 = pPVar11->ob_type;
                      if ((p_Var26 == (_typeobject *)PTR_PyMethod_Type_00137eb8) &&
                         (p_Var29 = pPVar11[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                        pPVar19 = (PyObject *)pPVar11[1].ob_refcnt;
                        (p_Var29->ob_base).ob_base.ob_refcnt =
                             (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                        pPVar19->ob_refcnt = pPVar19->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar28 = pPVar11->ob_refcnt + -1;
                        pPVar11->ob_refcnt = lVar28;
                        if (lVar28 == 0) {
                          (*p_Var26->tp_dealloc)(pPVar11);
                        }
                        __pyx_pyargnames[1] =
                             (PyObject **)
                             __pyx_mstate_global_static.__pyx_kp_u_FRP_Manager_initialized_service;
                        __pyx_pyargnames[0] = (PyObject **)p_Var29;
                        pPVar9 = __Pyx_PyObject_FastCallDict
                                           (pPVar19,(PyObject **)__pyx_pyargnames,2,
                                            __pyx_mstate_global_static.
                                            __pyx_kp_u_FRP_Manager_initialized_service);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar28 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                        (p_Var29->ob_base).ob_base.ob_refcnt = lVar28;
                        pPVar11 = pPVar19;
                        if (lVar28 == 0) {
                          (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                        }
                      }
                      else {
                        __pyx_pyargnames[0] = (PyObject **)0x0;
                        __pyx_pyargnames[1] =
                             (PyObject **)
                             __pyx_mstate_global_static.__pyx_kp_u_FRP_Manager_initialized_service;
                        pPVar9 = __Pyx_PyObject_FastCallDict
                                           (pPVar11,(PyObject **)(__pyx_pyargnames + 1),1,
                                            __pyx_mstate_global_static.
                                            __pyx_kp_u_FRP_Manager_initialized_service);
                      }
                      if (pPVar9 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar28 = pPVar11->ob_refcnt + -1;
                        pPVar11->ob_refcnt = lVar28;
                        if (lVar28 == 0) {
                          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar28 = pPVar9->ob_refcnt + -1;
                        pPVar9->ob_refcnt = lVar28;
                        if (lVar28 == 0) {
                          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                        }
                        pPVar9 = (PyObject *)PTR__Py_NoneStruct_00137f48;
                        *(long *)PTR__Py_NoneStruct_00137f48 =
                             *(long *)PTR__Py_NoneStruct_00137f48 + 1;
                        goto LAB_0011dd44;
                      }
                      py_line = 0x1d;
                      iVar8 = 0x1071;
                      goto LAB_0011ec14;
                    }
                    py_line = 0x1d;
                    iVar8 = 0x105c;
                    func = (PyObject *)0x0;
                  }
                }
              }
            }
            goto LAB_0011eb34;
          }
          py_line = 0x11;
          iVar8 = 0xfe4;
          lVar28 = func->ob_refcnt + -1;
        }
LAB_0011eb48:
        func->ob_refcnt = lVar28;
        if (lVar28 == 0) goto LAB_0011eb0c;
      }
    }
  }
LAB_0011eaa0:
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.__init__",iVar8,py_line,
                     "moonraker/components/frp_manager.py");
  pPVar9 = (PyObject *)0x0;
  goto LAB_0011dd44;
  while( true ) {
    lVar15 = lVar16 + 1;
    if (lVar15 == lVar28) goto LAB_0011ea60;
    p_Var26 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar16];
    lVar16 = lVar15;
    if ((_typeobject *)pPVar9 == p_Var26) break;
LAB_0011e690:
    bVar6 = pPVar9->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var26->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar9 != (PyObject *)puVar3) && (bVar6 || p_Var26 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar9,p_Var26,2);
        if (plVar12 == (long *)0x0) goto LAB_0011ea60;
        uVar22 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar22 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = *plVar12;
        *plVar12 = lVar15 + -1;
        if (lVar15 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011ea50:
        if (uVar22 != 0) {
          if ((int)uVar22 < 0) goto LAB_0011ea60;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar9[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar9), iVar8 < 0)) ||
         ((-1 < (char)p_Var26->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var26), iVar8 < 0))))
      goto LAB_0011ea60;
      lVar15 = pPVar9[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar15 == (p_Var26->ob_base).ob_size) &&
         ((pPVar9[1].ob_type == (_typeobject *)p_Var26->tp_name ||
          (_typeobject *)p_Var26->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar9[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar20 = (char *)((ulong)(byte)((byte)pPVar9[2].ob_refcnt >> 2) & 7);
        uVar22 = (uint)pcVar20;
        pcVar21 = pcVar20;
        if (((byte)((byte)p_Var26->tp_basicsize >> 2) & 7) == uVar22) {
          bVar2 = (byte)pPVar9[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var29 = pPVar9[4].ob_type;
          }
          else {
            p_Var29 = (_typeobject *)&pPVar9[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var29 = (_typeobject *)(pPVar9 + 3);
            }
          }
          bVar2 = (byte)p_Var26->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var13 = (setattrfunc *)p_Var26->tp_setattr;
          }
          else {
            pp_Var13 = &p_Var26->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var13 = (setattrfunc *)&p_Var26->tp_dealloc;
            }
          }
          if (uVar22 == 1) {
            pcVar21 = (char *)(ulong)*(byte *)&(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var13;
          }
          else if (uVar22 == 2) {
            pcVar21 = (char *)(ulong)*(ushort *)&(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var13;
          }
          else {
            pcVar21 = (char *)(ulong)*(uint *)&(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var13;
          }
          if (uVar22 == (uint)pcVar21) {
            if (lVar15 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var29,pp_Var13,(long)pcVar20 * lVar15);
              uVar22 = (uint)(iVar8 == 0);
              goto LAB_0011ea50;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar16];
LAB_0011e72c:
  if (values[0] != (PyObject *)0x0) {
    lVar16 = __pyx_kwds[1].ob_refcnt;
    lVar28 = lVar28 + -1;
LAB_0011e73c:
    pPVar9 = __pyx_mstate_global_static.__pyx_n_s_config;
    puVar5 = PTR_PyUnicode_Type_00137fb0;
    puVar4 = PTR__Py_TrueStruct_00137f50;
    puVar3 = PTR__Py_NoneStruct_00137f48;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar16) {
      p_Var26 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var26) {
        values[1] = *kwvalues;
      }
      else {
        lVar15 = 0;
        do {
          lVar25 = lVar15 + 1;
          if (lVar16 == lVar25) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar16 = 0;
            goto LAB_0011e7a0;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar15;
          lVar15 = lVar25;
        } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar25];
      }
      goto LAB_0011e8e4;
    }
LAB_0011e998:
    values[1] = (PyObject *)0x0;
    goto LAB_0011e99c;
  }
LAB_0011ea64:
  lVar28 = PyErr_Occurred();
  if (lVar28 == 0) goto LAB_0011dcec;
  iVar8 = 0xf16;
  goto LAB_0011dd28;
  while( true ) {
    lVar25 = lVar16 + 1;
    if (lVar15 == lVar16) goto LAB_0011e998;
    p_Var26 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar16];
    lVar16 = lVar25;
    if ((_typeobject *)pPVar9 == p_Var26) break;
LAB_0011e7a0:
    bVar6 = pPVar9->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var26->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar25 = lVar16;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar9 != (PyObject *)puVar3) && (bVar6 || p_Var26 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar9,p_Var26,2);
        if (plVar12 == (long *)0x0) goto LAB_0011e998;
        uVar22 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00137f20) &&
            plVar12 != (long *)puVar3) {
          uVar22 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar17 = *plVar12;
        *plVar12 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0011e988:
        if (uVar22 != 0) {
          if ((int)uVar22 < 0) goto LAB_0011e998;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar9[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar9), iVar8 < 0)) ||
         ((-1 < (char)p_Var26->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var26), iVar8 < 0))))
      goto LAB_0011e998;
      lVar17 = pPVar9[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar17 == (p_Var26->ob_base).ob_size) &&
         ((pPVar9[1].ob_type == (_typeobject *)p_Var26->tp_name ||
          (_typeobject *)p_Var26->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar9[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar21 = (char *)((ulong)(byte)((byte)pPVar9[2].ob_refcnt >> 2) & 7);
        uVar22 = (uint)pcVar21;
        if (((byte)((byte)p_Var26->tp_basicsize >> 2) & 7) == uVar22) {
          bVar2 = (byte)pPVar9[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var29 = pPVar9[4].ob_type;
          }
          else {
            p_Var29 = (_typeobject *)&pPVar9[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var29 = (_typeobject *)(pPVar9 + 3);
            }
          }
          bVar2 = (byte)p_Var26->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var13 = (setattrfunc *)p_Var26->tp_setattr;
          }
          else {
            pp_Var13 = &p_Var26->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var13 = (setattrfunc *)&p_Var26->tp_dealloc;
            }
          }
          if (uVar22 == 1) {
            uVar22 = (uint)(byte)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(byte *)pp_Var13;
          }
          else if (uVar22 == 2) {
            uVar22 = (uint)(ushort)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar24 = (uint)*(ushort *)pp_Var13;
          }
          else {
            uVar22 = (uint)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar24 = *(uint *)pp_Var13;
          }
          if (uVar24 == uVar22) {
            if (lVar17 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var29,pp_Var13,(long)pcVar21 * lVar17);
              uVar22 = (uint)(iVar8 == 0);
              goto LAB_0011e988;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar25];
LAB_0011e8e4:
  if (values[1] == (PyObject *)0x0) {
LAB_0011e99c:
    lVar28 = PyErr_Occurred();
    if (lVar28 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00137ef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                   "exactly",2,"s",1);
      iVar8 = 0xf20;
    }
    else {
      iVar8 = 0xf1e;
    }
  }
  else {
    lVar28 = lVar28 + -1;
LAB_0011e618:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar28 < 1) ||
       (iVar8 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x123d00,pcVar21), -1 < iVar8))
    goto LAB_0011dd80;
    iVar8 = 0xf25;
  }
LAB_0011dd28:
  __Pyx_AddTraceback("moonraker.components.frp_manager.FrpManager.__init__",iVar8,9,
                     "moonraker/components/frp_manager.py");
  pPVar9 = (PyObject *)0x0;
LAB_0011dd44:
  if (lVar23 == *(long *)PTR___stack_chk_guard_00137f30) {
    return pPVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Successfully decompiled 22 of 22 selected functions. */
