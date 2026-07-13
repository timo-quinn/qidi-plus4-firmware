/*
 * Reverse-engineered Ghidra output. This is not original source code.
 * Program: buttons_irq.so
 * Language: AARCH64:LE:64:v8A
 * Selected named functions: 16
 */


/* ================================================================
 * Address: 0010435c
 * Symbol:  __pyx_pymod_exec_buttons_irq
 * Signature: int __pyx_pymod_exec_buttons_irq(PyObject * __pyx_pyinit_module)
 * ================================================================ */

int __pyx_pymod_exec_buttons_irq(PyObject *__pyx_pyinit_module)

{
  byte bVar1;
  Py_ssize_t *pPVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long *plVar7;
  char *pcVar8;
  PyTypeObject *pPVar9;
  long lVar10;
  PyObject *obj;
  PyObject *pPVar11;
  PyObject *pPVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  _typeobject *p_Var16;
  int iVar17;
  PyObject *pPVar18;
  PyObject *modname;
  PyObject *doc;
  ulong uVar19;
  PyObject *pPVar20;
  char *__s;
  undefined8 in_stack_fffffffffffffe90;
  undefined4 uVar21;
  char message [200];
  
                    /* Unresolved local var: int stringtab_initialized@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  uVar21 = (undefined4)((ulong)in_stack_fffffffffffffe90 >> 0x20);
  lVar14 = *(long *)PTR___stack_chk_guard_00123f40;
  if (__pyx_m != (PyObject *)0x0) {
    iVar4 = 0;
    if (__pyx_m != __pyx_pyinit_module) {
      PyErr_SetString(*(undefined8 *)PTR_PyExc_RuntimeError_00123f08,
                      "Module \'buttons_irq\' has already been imported. Re-initialisation is not supported."
                      ,0);
      iVar4 = -1;
    }
    goto LAB_00105538;
  }
  __pyx_m = __pyx_pyinit_module;
  __pyx_pyinit_module->ob_refcnt = __pyx_pyinit_module->ob_refcnt + 1;
  __pyx_mstate_global_static.__pyx_d = (PyObject *)PyModule_GetDict();
  if (__pyx_mstate_global_static.__pyx_d == (PyObject *)0x0) {
    iVar17 = 0x1999;
    iVar4 = 1;
    bVar3 = false;
LAB_00105288:
    if (__pyx_m == (PyObject *)0x0) {
      lVar6 = PyErr_Occurred();
      if (lVar6 == 0) {
        PyErr_SetString(*(undefined8 *)PTR_PyExc_ImportError_00123f98,"init extras.buttons_irq");
      }
    }
    else {
      if ((__pyx_mstate_global_static.__pyx_d != (PyObject *)0x0) && (bVar3)) {
        __Pyx_AddTraceback("init extras.buttons_irq",iVar17,iVar4,"buttons_irq.py");
      }
                    /* Unresolved local var: PyObject * _py_tmp@[???] */
      pPVar20 = __pyx_m;
      if (__pyx_m != (PyObject *)0x0) {
        pPVar2 = &__pyx_m->ob_refcnt;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        __pyx_m = (PyObject *)0x0;
        lVar6 = *pPVar2 + -1;
        pPVar20->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar20->ob_type->tp_dealloc)(pPVar20);
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
      iVar17 = 0x199b;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
    (__pyx_mstate_global_static.__pyx_b)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_b)->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * module@[???] */
    __pyx_mstate_global_static.__pyx_cython_runtime =
         (PyObject *)PyImport_AddModule("cython_runtime");
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (__pyx_mstate_global_static.__pyx_cython_runtime == (PyObject *)0x0) {
      iVar17 = 0x199c;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
    (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt + 1;
    iVar4 = PyObject_SetAttrString(__pyx_m,"__builtins__",__pyx_mstate_global_static.__pyx_b);
    if (iVar4 < 0) {
      iVar17 = 0x199d;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
                    /* Unresolved local var: char * rt_version@[???]
                       Unresolved local var: ulong version@[???]
                       Unresolved local var: ulong factor@[???]
                       Unresolved local var: wchar_t digit@[???]
                       Unresolved local var: int i@[???] */
    lVar6 = Py_GetVersion();
    iVar17 = 4;
    iVar4 = 0;
    uVar19 = 0;
    uVar15 = 0x1000000;
    do {
      uVar13 = 0;
      while (bVar1 = *(byte *)(lVar6 + iVar4), (byte)(bVar1 - 0x30) < 10) {
        iVar4 = iVar4 + 1;
        uVar13 = (ulong)(((uint)bVar1 + (int)uVar13 * 10) - 0x30);
      }
      uVar19 = uVar19 + uVar13 * uVar15;
      if (bVar1 != 0x2e) break;
      uVar15 = uVar15 >> 8;
      iVar4 = iVar4 + 1;
      iVar17 = iVar17 + -1;
    } while (iVar17 != 0);
                    /* Unresolved local var: ulong MAJOR_MINOR@[???] */
    if (((uVar19 ^ 0x3070000) & 0xffff0000) != 0) {
      PyOS_snprintf(message,200,
                    "compile time Python version %d.%d of module \'%.100s\' %s runtime version %d.%d"
                    ,3,7,"extras.buttons_irq","does not match",uVar19 >> 0x18 & 0xffffffff,
                    CONCAT44(uVar21,(uint)uVar19 >> 0x10) & 0xffffffff000000ff);
      iVar4 = PyErr_WarnEx(0,message,1);
      if (iVar4 < 0) {
        iVar17 = 0x19a8;
        iVar4 = 1;
        bVar3 = false;
        goto LAB_00105288;
      }
    }
    __pyx_pyframe_localsplus_offset = *(long *)(PTR_PyFrame_Type_00123f90 + 0x20) - 8;
    __pyx_mstate_global_static.__pyx_empty_tuple = (PyObject *)PyTuple_New(0);
    if (__pyx_mstate_global_static.__pyx_empty_tuple == (PyObject *)0x0) {
      iVar17 = 0x19ac;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
    __pyx_mstate_global_static.__pyx_empty_bytes = (PyObject *)PyBytes_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_bytes == (PyObject *)0x0) {
      iVar17 = 0x19ad;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
    __pyx_mstate_global_static.__pyx_empty_unicode = (PyObject *)PyUnicode_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_unicode == (PyObject *)0x0) {
      iVar17 = 0x19ae;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
                    /* Unresolved local var: PyObject * abi_module@[???]
                       Unresolved local var: char * object_name@[???]
                       Unresolved local var: PyTypeObject * cached_type@[???]
                       Unresolved local var: PyObject * module@[???] */
    plVar7 = (long *)PyImport_AddModule("_cython_3_0_12");
    __s = __pyx_CyFunctionType_type.tp_name;
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (plVar7 == (long *)0x0) {
      iVar17 = 0x19b0;
      iVar4 = 1;
      bVar3 = false;
      __pyx_mstate_global_static.__pyx_CyFunctionType = (PyTypeObject *)0x0;
      goto LAB_00105288;
    }
    *plVar7 = *plVar7 + 1;
    pcVar8 = strrchr(__s,0x2e);
    if (pcVar8 != (char *)0x0) {
      __s = pcVar8 + 1;
    }
    pPVar9 = (PyTypeObject *)PyObject_GetAttrString(plVar7,__s);
    if (pPVar9 == (PyTypeObject *)0x0) {
      iVar4 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_AttributeError_00123fa0);
      if (iVar4 != 0) {
        PyErr_Clear();
        pPVar9 = &__pyx_CyFunctionType_type;
        iVar4 = PyType_Ready(&__pyx_CyFunctionType_type);
        if ((-1 < iVar4) &&
           (iVar4 = PyObject_SetAttrString(plVar7,__s,&__pyx_CyFunctionType_type), -1 < iVar4)) {
          __pyx_CyFunctionType_type.ob_base.ob_base.ob_refcnt =
               __pyx_CyFunctionType_type.ob_base.ob_base.ob_refcnt + 1;
          goto LAB_001046a0;
        }
      }
LAB_00104664:
      pPVar9 = (PyTypeObject *)0x0;
    }
    else if ((int)((pPVar9->ob_base).ob_base.ob_type)->tp_flags < 0) {
      if (pPVar9->tp_basicsize != __pyx_CyFunctionType_type.tp_basicsize) {
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                     "Shared Cython type %.200s has the wrong size, try recompiling",__s);
        goto LAB_00105440;
      }
    }
    else {
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "Shared Cython type %.200s is not a type object",__s);
LAB_00105440:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = (pPVar9->ob_base).ob_base.ob_refcnt + -1;
      (pPVar9->ob_base).ob_base.ob_refcnt = lVar6;
      if (lVar6 != 0) goto LAB_00104664;
      (*((pPVar9->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)pPVar9);
      pPVar9 = (PyTypeObject *)0x0;
    }
LAB_001046a0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = *plVar7;
    *plVar7 = lVar6 + -1;
    if (lVar6 + -1 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    __pyx_mstate_global_static.__pyx_CyFunctionType = pPVar9;
    if (pPVar9 == (PyTypeObject *)0x0) {
      iVar17 = 0x19b0;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
    iVar4 = __Pyx_CreateStringTabAndInitStrings();
    if ((iVar4 < 0) ||
       (__pyx_mstate_global_static.__pyx_int_0 = (PyObject *)PyLong_FromLong(0),
       __pyx_mstate_global_static.__pyx_int_0 == (PyObject *)0x0)) {
      iVar17 = 0x19c7;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_00105288;
    }
    if ((*(int *)PTR___pyx_module_is_main_extras__buttons_irq_00123f58 != 0) &&
       (iVar4 = PyObject_SetAttr(__pyx_m,__pyx_mstate_global_static.__pyx_n_s_name,
                                 __pyx_mstate_global_static.__pyx_n_s_main), iVar4 < 0)) {
      iVar4 = 1;
      iVar17 = 0x19ce;
      bVar3 = true;
      goto LAB_00105288;
    }
                    /* Unresolved local var: PyObject * modules@[???] */
    lVar6 = PyImport_GetModuleDict();
    if (lVar6 == 0) {
      iVar4 = 1;
      iVar17 = 0x19d2;
      bVar3 = true;
      goto LAB_00105288;
    }
    lVar10 = PyDict_GetItemString(lVar6,"extras.buttons_irq");
    if ((lVar10 == 0) &&
       (iVar4 = PyDict_SetItemString(lVar6,"extras.buttons_irq",__pyx_m), iVar4 < 0)) {
      iVar4 = 1;
      iVar17 = 0x19d4;
      bVar3 = true;
      goto LAB_00105288;
    }
    __pyx_mstate_global_static.__pyx_tuple_ =
         (PyObject *)
         PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_invert,PTR__Py_FalseStruct_00123f30);
    if ((((((__pyx_mstate_global_static.__pyx_tuple_ == (PyObject *)0x0) ||
           (__pyx_mstate_global_static.__pyx_tuple__2 =
                 (PyObject *)
                 PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_pullup,
                              __pyx_mstate_global_static.__pyx_int_0),
           __pyx_mstate_global_static.__pyx_tuple__2 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_tuple__3 =
                (PyObject *)
                PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_invert,
                             __pyx_mstate_global_static.__pyx_int_0),
          __pyx_mstate_global_static.__pyx_tuple__3 == (PyObject *)0x0)) ||
         ((__pyx_mstate_global_static.__pyx_tuple__4 =
                (PyObject *)
                PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_kp_s_irq_button_ack_oid_c_count_c),
          __pyx_mstate_global_static.__pyx_tuple__4 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_tuple__6 =
                (PyObject *)
                PyTuple_Pack(4,__pyx_mstate_global_static.__pyx_n_s_self,
                             __pyx_mstate_global_static.__pyx_n_s_printer,
                             __pyx_mstate_global_static.__pyx_n_s_mcu,
                             __pyx_mstate_global_static.__pyx_n_s_debounce_us),
          __pyx_mstate_global_static.__pyx_tuple__6 == (PyObject *)0x0)))) ||
        (((__pyx_mstate_global_static.__pyx_codeobj__7 =
                (PyObject *)
                PyCode_New(4,0,4,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__6,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_buttons_irq_py,
                           __pyx_mstate_global_static.__pyx_n_s_init,10,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__7 == (PyObject *)0x0 ||
          ((__pyx_mstate_global_static.__pyx_tuple__8 =
                 (PyObject *)
                 PyTuple_Pack(6,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_pin_params_list,
                              __pyx_mstate_global_static.__pyx_n_s_callback,
                              __pyx_mstate_global_static.__pyx_n_s_mask,
                              __pyx_mstate_global_static.__pyx_n_s_shift,
                              __pyx_mstate_global_static.__pyx_n_s_pin_params),
           __pyx_mstate_global_static.__pyx_tuple__8 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_codeobj__9 =
                 (PyObject *)
                 PyCode_New(3,0,6,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__8,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_buttons_irq_py,
                            __pyx_mstate_global_static.__pyx_n_s_setup_buttons,0x19,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__9 == (PyObject *)0x0)))) ||
         (__pyx_mstate_global_static.__pyx_tuple__10 =
               (PyObject *)
               PyTuple_Pack(3,__pyx_mstate_global_static.__pyx_n_s_self,
                            __pyx_mstate_global_static.__pyx_n_s_pin,
                            __pyx_mstate_global_static.__pyx_n_s_cmd_queue),
         __pyx_mstate_global_static.__pyx_tuple__10 == (PyObject *)0x0)))) ||
       ((((__pyx_mstate_global_static.__pyx_codeobj__11 =
                (PyObject *)
                PyCode_New(1,0,3,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__10,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_buttons_irq_py,
                           __pyx_mstate_global_static.__pyx_n_s_build_config,0x23,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__11 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_tuple__12 =
                (PyObject *)
                PyTuple_Pack(10,__pyx_mstate_global_static.__pyx_n_s_self,
                             __pyx_mstate_global_static.__pyx_n_s_msg,
                             __pyx_mstate_global_static.__pyx_n_s_count,
                             __pyx_mstate_global_static.__pyx_n_s_states,
                             __pyx_mstate_global_static.__pyx_n_s_s,
                             __pyx_mstate_global_static.__pyx_n_s_changed,
                             __pyx_mstate_global_static.__pyx_n_s_mask,
                             __pyx_mstate_global_static.__pyx_n_s_shift,
                             __pyx_mstate_global_static.__pyx_n_s_callback,
                             __pyx_mstate_global_static.__pyx_n_s_value),
          __pyx_mstate_global_static.__pyx_tuple__12 == (PyObject *)0x0)) ||
         (__pyx_mstate_global_static.__pyx_codeobj__13 =
               (PyObject *)
               PyCode_New(2,0,10,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_tuple__12,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_kp_s_buttons_irq_py,
                          __pyx_mstate_global_static.__pyx_n_s_handle_state,0x2e,
                          __pyx_mstate_global_static.__pyx_empty_bytes),
         __pyx_mstate_global_static.__pyx_codeobj__13 == (PyObject *)0x0)) ||
        (((__pyx_mstate_global_static.__pyx_tuple__14 =
                (PyObject *)
                PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                             __pyx_mstate_global_static.__pyx_n_s_config),
          __pyx_mstate_global_static.__pyx_tuple__14 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_codeobj__15 =
                (PyObject *)
                PyCode_New(2,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__14,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_buttons_irq_py,
                           __pyx_mstate_global_static.__pyx_n_s_init,0x41,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__15 == (PyObject *)0x0)) ||
         ((__pyx_mstate_global_static.__pyx_tuple__16 =
                (PyObject *)
                PyTuple_Pack(0xb,__pyx_mstate_global_static.__pyx_n_s_self,
                             __pyx_mstate_global_static.__pyx_n_s_pins,
                             __pyx_mstate_global_static.__pyx_n_s_callback,
                             __pyx_mstate_global_static.__pyx_n_s_debounce_us,
                             __pyx_mstate_global_static.__pyx_n_s_ppins,
                             __pyx_mstate_global_static.__pyx_n_s_mcu,
                             __pyx_mstate_global_static.__pyx_n_s_mcu_name,
                             __pyx_mstate_global_static.__pyx_n_s_pin_params_list,
                             __pyx_mstate_global_static.__pyx_n_s_pin,
                             __pyx_mstate_global_static.__pyx_n_s_pin_params,
                             __pyx_mstate_global_static.__pyx_n_s_mcu_button),
          __pyx_mstate_global_static.__pyx_tuple__16 == (PyObject *)0x0 ||
          ((__pyx_mstate_global_static.__pyx_codeobj__17 =
                 (PyObject *)
                 PyCode_New(4,0,0xb,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__16,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_buttons_irq_py,
                            __pyx_mstate_global_static.__pyx_n_s_register_buttons,0x45,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__17 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_tuple__18 =
                 (PyObject *)PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_n_s_config),
           __pyx_mstate_global_static.__pyx_tuple__18 == (PyObject *)0x0)))))))))) {
LAB_001047d0:
      iVar4 = 1;
      iVar17 = 0x19db;
      bVar3 = true;
      goto LAB_00105288;
    }
    pPVar18 = (PyObject *)0x3;
    modname = __pyx_mstate_global_static.__pyx_empty_bytes;
    doc = __pyx_mstate_global_static.__pyx_empty_tuple;
    __pyx_mstate_global_static.__pyx_codeobj__19 = (PyObject *)PyCode_New(1,0,1,0);
    pPVar20 = __pyx_mstate_global_static.__pyx_n_s_logging;
    if (__pyx_mstate_global_static.__pyx_codeobj__19 == (PyObject *)0x0) goto LAB_001047d0;
                    /* Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * imported_module@[???] */
    obj = (PyObject *)PyImport_GetModule(__pyx_mstate_global_static.__pyx_n_s_logging);
    if (obj == (PyObject *)0x0) {
      lVar6 = PyErr_Occurred();
      if (lVar6 != 0) {
        PyErr_Clear();
      }
LAB_00104c88:
                    /* Unresolved local var: PyObject * imported_module@[???]
                       Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * empty_dict@[???]
                       Unresolved local var: PyObject * empty_list@[???] */
      plVar7 = (long *)PyDict_New();
      if (plVar7 != (long *)0x0) {
        pPVar18 = (PyObject *)0x0;
        obj = (PyObject *)
              PyImport_ImportModuleLevelObject(pPVar20,__pyx_mstate_global_static.__pyx_d,plVar7,0);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = *plVar7;
        *plVar7 = lVar6 + -1;
        if (lVar6 + -1 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (obj != (PyObject *)0x0) goto LAB_00104ce8;
      }
      iVar17 = 0x19f0;
      iVar4 = 7;
      bVar3 = true;
      goto LAB_00105288;
    }
                    /* Unresolved local var: PyObject * spec@[???] */
    pPVar11 = __Pyx_PyObject_GetAttrStrNoError(obj,__pyx_mstate_global_static.__pyx_n_s_spec);
    if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * unsafe@[???] */
      pPVar12 = __Pyx_PyObject_GetAttrStrNoError
                          (pPVar11,__pyx_mstate_global_static.__pyx_n_s_initializing);
      if (pPVar12 == (PyObject *)0x0) {
LAB_00104ba8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        if (pPVar12 == (PyObject *)0x0) goto LAB_00104b8c;
        pPVar11 = (PyObject *)0x0;
      }
      else {
                    /* Unresolved local var: int is_true@[???] */
        uVar5 = (uint)(pPVar12 == (PyObject *)PTR__Py_TrueStruct_00123f68);
        if ((uVar5 == 0 && pPVar12 != (PyObject *)PTR__Py_FalseStruct_00123f30) &&
            pPVar12 != (PyObject *)PTR__Py_NoneStruct_00123f60) {
          uVar5 = PyObject_IsTrue();
        }
        if (uVar5 == 0) goto LAB_00104ba8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar6;
      if (lVar6 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
      if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = obj->ob_refcnt + -1;
        obj->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*obj->ob_type->tp_dealloc)(obj);
        }
        goto LAB_00104c88;
      }
    }
LAB_00104b8c:
    PyErr_Clear();
LAB_00104ce8:
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_logging,obj);
    pPVar20 = (PyObject *)0x0;
    if (iVar4 < 0) {
      iVar17 = 0x19f2;
      iVar4 = 7;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*obj->ob_type->tp_dealloc)(obj);
    }
    obj = __Pyx_Py3MetaclassPrepare
                    (__pyx_mstate_global_static.__pyx_empty_tuple,
                     __pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU,
                     __pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU,
                     __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,pPVar18,modname,doc);
    if (obj == (PyObject *)0x0) {
      iVar17 = 0x19fc;
      iVar4 = 9;
      bVar3 = true;
      goto LAB_00105288;
    }
    pPVar18 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_11buttons_irq_13_IRQButtonMCU_1__init__,
                         (int)__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU___init,
                         __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__7,modname,doc);
    if (pPVar18 == (PyObject *)0x0) {
      pPVar20 = (PyObject *)0x0;
      iVar17 = 0x1a06;
      iVar4 = 10;
LAB_00105240:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = obj->ob_refcnt + -1;
      obj->ob_refcnt = lVar6;
      if (lVar6 == 0) {
        (*obj->ob_type->tp_dealloc)(obj);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar20 == (PyObject *)0x0) ||
         (lVar6 = pPVar20->ob_refcnt + -1, pPVar20->ob_refcnt = lVar6, lVar6 != 0)) {
        bVar3 = true;
      }
      else {
        (*pPVar20->ob_type->tp_dealloc)(pPVar20);
        bVar3 = true;
      }
      goto LAB_00105288;
    }
    if (obj->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      uVar15 = _PyDict_SetItem_KnownHash
                         (obj,__pyx_mstate_global_static.__pyx_n_s_init,pPVar18,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    else {
      uVar15 = PyObject_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_init,pPVar18);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar17 = 0x1a08;
      iVar4 = 10;
      pPVar20 = pPVar18;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar18->ob_refcnt + -1;
    pPVar18->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar18->ob_type->tp_dealloc)(pPVar18);
    }
    pPVar18 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_11buttons_irq_13_IRQButtonMCU_3setup_buttons,
                         (int)__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU_setup_buttons,
                         __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__9,modname,doc);
    if (pPVar18 == (PyObject *)0x0) {
      iVar17 = 0x1a12;
      iVar4 = 0x19;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    if (obj->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      uVar15 = _PyDict_SetItem_KnownHash
                         (obj,__pyx_mstate_global_static.__pyx_n_s_setup_buttons,pPVar18,
                          __pyx_mstate_global_static.__pyx_n_s_setup_buttons[1].ob_type);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    else {
      uVar15 = PyObject_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_setup_buttons,pPVar18);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar17 = 0x1a14;
      iVar4 = 0x19;
      pPVar20 = pPVar18;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar18->ob_refcnt + -1;
    pPVar18->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar18->ob_type->tp_dealloc)(pPVar18);
    }
    pPVar18 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_11buttons_irq_13_IRQButtonMCU_5_build_config,
                         (int)__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU__build_config,
                         __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__11,modname,doc);
    if (pPVar18 == (PyObject *)0x0) {
      iVar17 = 0x1a1e;
      iVar4 = 0x23;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    if (obj->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      uVar15 = _PyDict_SetItem_KnownHash
                         (obj,__pyx_mstate_global_static.__pyx_n_s_build_config,pPVar18,
                          __pyx_mstate_global_static.__pyx_n_s_build_config[1].ob_type);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    else {
      uVar15 = PyObject_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_build_config,pPVar18);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar17 = 0x1a20;
      iVar4 = 0x23;
      pPVar20 = pPVar18;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar18->ob_refcnt + -1;
    pPVar18->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar18->ob_type->tp_dealloc)(pPVar18);
    }
    p_Var16 = (_typeobject *)__pyx_mstate_global_static.__pyx_d;
    pPVar18 = __pyx_mstate_global_static.__pyx_codeobj__13;
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_11buttons_irq_13_IRQButtonMCU_7_handle_state,
                         (int)__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU__handle_state,
                         __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__13,modname,doc);
    if (pPVar11 == (PyObject *)0x0) {
      iVar17 = 0x1a2a;
      iVar4 = 0x2e;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    if (obj->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      p_Var16 = __pyx_mstate_global_static.__pyx_n_s_handle_state[1].ob_type;
      uVar15 = _PyDict_SetItem_KnownHash
                         (obj,__pyx_mstate_global_static.__pyx_n_s_handle_state,pPVar11);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    else {
      uVar15 = PyObject_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_handle_state,pPVar11);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar17 = 0x1a2c;
      iVar4 = 0x2e;
      pPVar20 = pPVar11;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_Py3ClassCreate
                        (__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU,
                         __pyx_mstate_global_static.__pyx_empty_tuple,obj,(PyObject *)p_Var16,
                         pPVar18,(int)modname,(int)doc);
    if (pPVar11 == (PyObject *)0x0) {
      iVar17 = 0x1a36;
      iVar4 = 9;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU,pPVar11);
    if (iVar4 < 0) {
      iVar17 = 0x1a38;
      iVar4 = 9;
      pPVar20 = pPVar11;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*obj->ob_type->tp_dealloc)(obj);
    }
    obj = __Pyx_Py3MetaclassPrepare
                    (__pyx_mstate_global_static.__pyx_empty_tuple,
                     __pyx_mstate_global_static.__pyx_n_s_MCU_irq_button,
                     __pyx_mstate_global_static.__pyx_n_s_MCU_irq_button,
                     __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,pPVar18,modname,doc);
    if (obj == (PyObject *)0x0) {
      iVar17 = 0x1a43;
      iVar4 = 0x40;
      bVar3 = true;
      goto LAB_00105288;
    }
    pPVar18 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_11buttons_irq_14MCU_irq_button_1__init__,
                         (int)__pyx_mstate_global_static.__pyx_n_s_MCU_irq_button___init,
                         __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__15,modname,doc);
    if (pPVar18 == (PyObject *)0x0) {
      iVar17 = 0x1a4d;
      iVar4 = 0x41;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    if (obj->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      uVar15 = _PyDict_SetItem_KnownHash
                         (obj,__pyx_mstate_global_static.__pyx_n_s_init,pPVar18,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    else {
      uVar15 = PyObject_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_init,pPVar18);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar4 = 0x41;
      iVar17 = 0x1a4f;
      pPVar20 = pPVar18;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar18->ob_refcnt + -1;
    pPVar18->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar18->ob_type->tp_dealloc)(pPVar18);
    }
    p_Var16 = (_typeobject *)__pyx_mstate_global_static.__pyx_d;
    pPVar18 = __pyx_mstate_global_static.__pyx_codeobj__17;
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_11buttons_irq_14MCU_irq_button_3register_buttons,
                         (int)__pyx_mstate_global_static.__pyx_n_s_MCU_irq_button_register_buttons,
                         __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__17,modname,doc);
    if (pPVar11 == (PyObject *)0x0) {
      iVar17 = 0x1a59;
      iVar4 = 0x45;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    if (obj->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      p_Var16 = __pyx_mstate_global_static.__pyx_n_s_register_buttons[1].ob_type;
      uVar15 = _PyDict_SetItem_KnownHash
                         (obj,__pyx_mstate_global_static.__pyx_n_s_register_buttons,pPVar11);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    else {
      uVar15 = PyObject_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_register_buttons,pPVar11);
      uVar5 = (uint)(uVar15 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar4 = 0x45;
      iVar17 = 0x1a5b;
      pPVar20 = pPVar11;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar18 = __Pyx_Py3ClassCreate
                        (__pyx_mstate_global_static.__pyx_n_s_MCU_irq_button,
                         __pyx_mstate_global_static.__pyx_empty_tuple,obj,(PyObject *)p_Var16,
                         pPVar18,(int)modname,(int)doc);
    if (pPVar18 == (PyObject *)0x0) {
      iVar17 = 0x1a65;
      iVar4 = 0x40;
      pPVar20 = (PyObject *)0x0;
      goto LAB_00105240;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_MCU_irq_button,pPVar18);
    if (iVar4 < 0) {
      iVar4 = 0x40;
      iVar17 = 0x1a67;
      pPVar20 = pPVar18;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar18->ob_refcnt + -1;
    pPVar18->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar18->ob_type->tp_dealloc)(pPVar18);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*obj->ob_type->tp_dealloc)(obj);
    }
    obj = __Pyx_CyFunction_New
                    (&__pyx_mdef_6extras_11buttons_irq_1load_config,
                     (int)__pyx_mstate_global_static.__pyx_n_s_load_config,
                     __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                     __pyx_mstate_global_static.__pyx_d,__pyx_mstate_global_static.__pyx_codeobj__19
                     ,modname,doc);
    if (obj == (PyObject *)0x0) {
      iVar17 = 0x1a71;
      iVar4 = 0x5d;
      bVar3 = true;
      goto LAB_00105288;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_load_config,obj);
    if (iVar4 < 0) {
      iVar17 = 0x1a73;
      iVar4 = 0x5d;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*obj->ob_type->tp_dealloc)(obj);
    }
    obj = (PyObject *)PyDict_New();
    if (obj == (PyObject *)0x0) {
      iVar4 = 1;
      iVar17 = 0x1a7b;
      bVar3 = true;
      goto LAB_00105288;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_test,obj);
    if (iVar4 < 0) {
      iVar17 = 0x1a7d;
      iVar4 = 1;
      goto LAB_00105240;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*obj->ob_type->tp_dealloc)(obj);
    }
  }
  iVar4 = -(uint)(__pyx_m == (PyObject *)0x0);
LAB_00105538:
  if (lVar14 == *(long *)PTR___stack_chk_guard_00123f40) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00105570
 * Symbol:  PyInit_buttons_irq
 * Signature: PyObject * PyInit_buttons_irq(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PyObject * PyInit_buttons_irq(void)

{
  PyObject *pPVar1;
  
  pPVar1 = (PyObject *)PyModuleDef_Init(&__pyx_moduledef);
  return pPVar1;
}


/* ================================================================
 * Address: 00105580
 * Symbol:  call_weak_fn
 * Signature: undefined call_weak_fn(void)
 * ================================================================ */

void call_weak_fn(void)

{
  if (PTR___gmon_start___00123f38 != (undefined *)0x0) {
    __gmon_start__();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00105598
 * Symbol:  deregister_tm_clones
 * Signature: undefined deregister_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x001055b0) */
/* WARNING: Removing unreachable block (ram,0x001055bc) */

void deregister_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 001055c8
 * Symbol:  register_tm_clones
 * Signature: undefined register_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x001055ec) */
/* WARNING: Removing unreachable block (ram,0x001055f8) */

void register_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 00105684
 * Symbol:  lexical_block_1_0
 * Signature: void lexical_block_1_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x105684 00105684} (16 bytes)
   DWARF func body range[1]: {@address 0x1056cc 001056cc} (20 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x001056c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(unaff_x19[1] + 0x30))();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00105698
 * Symbol:  lexical_block_2_0
 * Signature: void lexical_block_2_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x105698 00105698} (16 bytes)
   DWARF func body range[1]: {@address 0x1056b4 001056b4} (8 bytes)
   DWARF func body range[2]: {@address 0x1056c4 001056c4} (8 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x001056c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x19[1] + 0x30))();
  return;
}


/* ================================================================
 * Address: 00107ff8
 * Symbol:  __pyx_pf_6extras_11buttons_irq_2__defaults__
 * Signature: PyObject * __pyx_pf_6extras_11buttons_irq_2__defaults__(PyObject * __pyx_self)
 * ================================================================ */

PyObject * __pyx_pf_6extras_11buttons_irq_2__defaults__(PyObject *__pyx_self)

{
  long *plVar1;
  _typeobject *p_Var2;
  undefined *puVar3;
  _typeobject *p_Var4;
  PyObject *pPVar5;
  long lVar6;
  int c_line;
  
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  p_Var4 = (_typeobject *)PyTuple_New(2);
  if (p_Var4 == (_typeobject *)0x0) {
    c_line = 0x109b;
  }
  else {
    plVar1 = (long *)((__pyx_self[7].ob_type)->ob_base).ob_base.ob_refcnt;
    p_Var2 = ((__pyx_self[7].ob_type)->ob_base).ob_base.ob_type;
    *plVar1 = *plVar1 + 1;
    p_Var4->tp_name = (char *)plVar1;
    (p_Var2->ob_base).ob_base.ob_refcnt = (p_Var2->ob_base).ob_base.ob_refcnt + 1;
    p_Var4->tp_basicsize = (Py_ssize_t)p_Var2;
    pPVar5 = (PyObject *)PyTuple_New(2);
    puVar3 = PTR__Py_NoneStruct_00123f60;
    if (pPVar5 != (PyObject *)0x0) {
      pPVar5[1].ob_type = p_Var4;
      pPVar5[2].ob_refcnt = (Py_ssize_t)puVar3;
      *(long *)puVar3 = *(long *)puVar3 + 1;
      return pPVar5;
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    c_line = 0x10a3;
    lVar6 = (p_Var4->ob_base).ob_base.ob_refcnt + -1;
    (p_Var4->ob_base).ob_base.ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*((p_Var4->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var4);
    }
  }
  __Pyx_AddTraceback("extras.buttons_irq.__defaults__",c_line,0x3c,"buttons_irq.py");
  return (PyObject *)0x0;
}


/* ================================================================
 * Address: 00108c58
 * Symbol:  __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_13_handle_state_lambda
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_13_handle_state_lambda(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_13_handle_state_lambda
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject **kwvalues;
  undefined *puVar1;
  PyObject *pPVar2;
  int iVar3;
  PyObject *pPVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  _typeobject *kwargs;
  undefined8 uVar8;
  char *pcVar9;
  PyObject **function_name;
  long lVar10;
  PyObject *func;
  long lVar11;
  _typeobject *p_Var12;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_et@[???]
                       Unresolved local var: PyObject * __pyx_v_c@[???]
                       Unresolved local var: PyObject * __pyx_v_v@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
                    /* Unresolved local var: __pyx_defaults * __pyx_dynamic_args@[???] */
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)((__pyx_self[7].ob_type)->ob_base).ob_base.ob_refcnt;
  lVar10 = *(long *)PTR___stack_chk_guard_00123f40;
  values[2] = (PyObject *)((__pyx_self[7].ob_type)->ob_base).ob_base.ob_type;
  function_name = &__pyx_mstate_global_static.__pyx_n_s_c;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_et;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_c;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_v;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) {
      if (__pyx_nargs != 3) {
        if (__pyx_nargs != 1) goto LAB_00108d98;
        values[0] = *__pyx_args;
        goto LAB_00108e18;
      }
      values[2] = __pyx_args[2];
    }
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      lVar11 = __pyx_kwds[1].ob_refcnt;
joined_r0x00108f28:
      if (0 < lVar11) {
                    /* Unresolved local var: PyObject * value@[???] */
        pPVar4 = __Pyx_GetKwValue_FASTCALL
                           (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_c);
        if (pPVar4 == (PyObject *)0x0) {
          lVar6 = PyErr_Occurred();
          if (lVar6 != 0) {
            iVar3 = 0x1100;
            goto LAB_00108ddc;
          }
        }
        else {
          lVar11 = lVar11 + -1;
          values[1] = pPVar4;
LAB_00108d14:
          if (lVar11 < 1) goto LAB_00108e18;
        }
                    /* Unresolved local var: PyObject * value@[???] */
        pPVar4 = __Pyx_GetKwValue_FASTCALL
                           (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_v);
        if (pPVar4 != (PyObject *)0x0) {
          lVar11 = lVar11 + -1;
          values[2] = pPVar4;
          goto LAB_00108e00;
        }
        lVar11 = PyErr_Occurred();
        if (lVar11 != 0) {
          iVar3 = 0x1107;
          goto LAB_00108ddc;
        }
LAB_00108fa4:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
        iVar3 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x1124d8,(char *)function_name);
        if (iVar3 < 0) {
          iVar3 = 0x110c;
          goto LAB_00108ddc;
        }
      }
    }
    else {
      if (__pyx_nargs < 2) {
        if (__pyx_nargs == 0) {
          lVar11 = __pyx_kwds[1].ob_refcnt;
LAB_00108d48:
          values[0] = __Pyx_GetKwValue_FASTCALL
                                (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_et);
          if (values[0] != (PyObject *)0x0) {
            lVar11 = lVar11 + -1;
            goto joined_r0x00108f28;
          }
          lVar11 = PyErr_Occurred();
          if (lVar11 == 0) {
            uVar5 = *(undefined8 *)PTR_PyExc_TypeError_00123f18;
            goto LAB_00108ee0;
          }
          iVar3 = 0x10f9;
        }
        else {
LAB_00108d98:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
          uVar5 = *(undefined8 *)PTR_PyExc_TypeError_00123f18;
          if (__pyx_nargs < 1) {
LAB_00108ee0:
            pcVar7 = "at least";
            pcVar9 = "";
            uVar8 = 1;
          }
          else {
            pcVar7 = "at most";
            pcVar9 = "s";
            uVar8 = 3;
          }
          PyErr_Format(uVar5,"%.200s() takes %.8s %zd positional argument%.1s (%zd given)","lambda",
                       pcVar7,uVar8,pcVar9,__pyx_nargs);
          iVar3 = 0x111f;
        }
LAB_00108ddc:
        pPVar4 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU._handle_state.lambda",iVar3,0x3c,
                           "buttons_irq.py");
        goto LAB_00108e74;
      }
      if (__pyx_nargs != 2) {
        if (__pyx_nargs != 3) goto LAB_00108d98;
        values[2] = __pyx_args[2];
      }
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar11 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs == 1) goto joined_r0x00108f28;
      if (__pyx_nargs == 2) goto LAB_00108d14;
      if (__pyx_nargs == 0) goto LAB_00108d48;
LAB_00108e00:
      if (0 < lVar11) goto LAB_00108fa4;
    }
  }
LAB_00108e18:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar2 = values[2];
  func = values[1];
  pPVar4 = values[0];
  puVar1 = PTR_PyMethod_Type_00123ee8;
  kwargs = values[1]->ob_type;
  values[1]->ob_refcnt = values[1]->ob_refcnt + 1;
  if ((kwargs == (_typeobject *)puVar1) &&
     (p_Var12 = values[1][1].ob_type, p_Var12 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    func = (PyObject *)values[1][1].ob_refcnt;
    (p_Var12->ob_base).ob_base.ob_refcnt = (p_Var12->ob_base).ob_base.ob_refcnt + 1;
    func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = values[1]->ob_refcnt + -1;
    values[1]->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*kwargs->tp_dealloc)(values[1]);
    }
    __pyx_pyargnames[0] = (PyObject **)p_Var12;
    __pyx_pyargnames[1] = (PyObject **)pPVar4;
    __pyx_pyargnames[2] = (PyObject **)pPVar2;
    pPVar4 = __Pyx_PyObject_FastCallDict(func,(PyObject **)__pyx_pyargnames,3,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
    (p_Var12->ob_base).ob_base.ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
    }
  }
  else {
    __pyx_pyargnames[0] = (PyObject **)0x0;
    __pyx_pyargnames[1] = (PyObject **)values[0];
    __pyx_pyargnames[2] = (PyObject **)values[2];
    pPVar4 = __Pyx_PyObject_FastCallDict
                       (values[1],(PyObject **)(__pyx_pyargnames + 1),2,(PyObject *)kwargs);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  lVar11 = func->ob_refcnt + -1;
  if (pPVar4 == (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU._handle_state.lambda",0x1159,0x3c,
                       "buttons_irq.py");
  }
  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
  }
LAB_00108e74:
  if (lVar10 != *(long *)PTR___stack_chk_guard_00123f40) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar4;
}


/* ================================================================
 * Address: 00109070
 * Symbol:  __pyx_pw_6extras_11buttons_irq_1load_config
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_1load_config(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_1load_config
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
  lVar6 = *(long *)PTR___stack_chk_guard_00123f40;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_00109168:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","load_config",
                   "exactly",1,"",__pyx_nargs);
      iVar2 = 0x1726;
      goto LAB_001091a4;
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
        if (lVar4 == 0) goto LAB_00109168;
        iVar2 = 0x1716;
        goto LAB_001091a4;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_00109168;
      values[0] = *__pyx_args;
      lVar4 = __pyx_kwds[1].ob_refcnt;
    }
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((0 < lVar4) &&
       (iVar2 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x112558,in_x6), iVar2 < 0)) {
      iVar2 = 0x171b;
LAB_001091a4:
      pPVar3 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.buttons_irq.load_config",iVar2,0x5d,"buttons_irq.py");
      goto LAB_001091c0;
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
  func = __pyx_dict_cached_value_16946;
  kwargs = &__pyx_mstate_global_static;
  if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16945) {
    if (__pyx_dict_cached_value_16946 == (PyObject *)0x0) {
      func = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_MCU_irq_button);
      goto LAB_0010927c;
    }
    __pyx_dict_cached_value_16946->ob_refcnt = __pyx_dict_cached_value_16946->ob_refcnt + 1;
LAB_00109110:
    p_Var5 = func->ob_type;
    if ((p_Var5 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
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
      goto LAB_001091c0;
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func_00->ob_refcnt = lVar4;
    iVar2 = 0x1767;
    if (lVar4 == 0) {
      (*func_00->ob_type->tp_dealloc)(func_00);
    }
  }
  else {
    func = __Pyx__GetModuleGlobalName
                     (__pyx_mstate_global_static.__pyx_n_s_MCU_irq_button,
                      (uint64_t *)&__pyx_dict_version_16945,&__pyx_dict_cached_value_16946);
LAB_0010927c:
    iVar2 = 0x1753;
    if (func != (PyObject *)0x0) goto LAB_00109110;
  }
  pPVar3 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq.load_config",iVar2,0x5e,"buttons_irq.py");
LAB_001091c0:
  if (lVar6 != *(long *)PTR___stack_chk_guard_00123f40) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar3;
}


/* ================================================================
 * Address: 00109360
 * Symbol:  __pyx_pw_6extras_11buttons_irq_14MCU_irq_button_1__init__
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_14MCU_irq_button_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_14MCU_irq_button_1__init__
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  Py_ssize_t *pPVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  PyObject *pPVar12;
  undefined1 *puVar13;
  long *plVar14;
  setattrfunc *__s2;
  getattrofunc p_Var15;
  setattrofunc p_Var16;
  char *pcVar17;
  uint uVar18;
  long lVar19;
  uint uVar20;
  long lVar21;
  int c_line;
  PyObject *pPVar22;
  _typeobject *p_Var23;
  _typeobject *p_Var24;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar19 = *(long *)PTR___stack_chk_guard_00123f40;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_config;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar12 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_001093d4;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_00109468;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  pcVar17 = PTR___stack_chk_guard_00123f40;
  if (__pyx_nargs == 1) {
    pPVar10 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar12 = pPVar10;
LAB_00109668:
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_config;
    puVar6 = PTR_PyUnicode_Type_00123fb8;
    puVar5 = PTR__Py_TrueStruct_00123f68;
    puVar4 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar10) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var23) {
        values[1] = *kwvalues;
      }
      else {
        pPVar22 = (PyObject *)0x0;
        do {
          pPVar1 = (PyObject *)((long)&pPVar22->ob_refcnt + 1);
          if (pPVar10 == pPVar1) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar10 = (PyObject *)0x0;
            goto LAB_001096d0;
          }
          pPVar3 = &__pyx_kwds[2].ob_refcnt + (long)pPVar22;
          pPVar22 = pPVar1;
        } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar3);
        values[1] = kwvalues[(long)pPVar1];
      }
      goto LAB_00109810;
    }
LAB_001098c0:
    values[1] = (PyObject *)0x0;
    goto LAB_001098c4;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar13 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_0010962c;
  }
  if (__pyx_nargs == 0) {
    lVar21 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar10 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      pPVar12 = (PyObject *)(lVar21 + -1);
      goto LAB_00109668;
    }
    lVar21 = PyErr_Occurred();
    if (lVar21 != 0) {
      iVar9 = 0x13a8;
      goto LAB_00109410;
    }
  }
LAB_001093d4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",2,
               "s",__pyx_nargs);
  iVar9 = 0x13c4;
  goto LAB_00109410;
  while( true ) {
    bVar7 = pPVar10 == pPVar22;
    pPVar3 = &pPVar10->ob_refcnt;
    pPVar10 = (PyObject *)((long)pPVar3 + 1);
    if (bVar7) goto LAB_001098c0;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar3];
    if ((_typeobject *)pPVar11 == p_Var23) break;
LAB_001096d0:
    bVar7 = pPVar11->ob_type != (_typeobject *)puVar6;
    bVar8 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar11 != (PyObject *)puVar4) && (bVar7 || p_Var23 != (_typeobject *)puVar4)) {
        plVar14 = (long *)PyObject_RichCompare(pPVar11,p_Var23,2);
        if (plVar14 == (long *)0x0) goto LAB_001098c0;
        uVar18 = (uint)(plVar14 == (long *)puVar5);
        if ((plVar14 != (long *)puVar5 && plVar14 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar14 != (long *)puVar4) {
          uVar18 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = *plVar14;
        *plVar14 = lVar21 + -1;
        if (lVar21 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_001098b4:
        if (uVar18 != 0) {
          if ((int)uVar18 < 0) goto LAB_001098c0;
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
         ((-1 < (char)p_Var23->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var23), iVar9 < 0))))
      goto LAB_001098c0;
      lVar21 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar21 == (p_Var23->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar17 = (char *)((ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7);
        uVar18 = (uint)pcVar17;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar18) {
          bVar2 = (byte)pPVar11[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var24 = pPVar11[4].ob_type;
          }
          else {
            p_Var24 = (_typeobject *)&pPVar11[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var24 = (_typeobject *)(pPVar11 + 3);
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
          if (uVar18 == 1) {
            uVar18 = (uint)(byte)(p_Var24->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(byte *)__s2;
          }
          else if (uVar18 == 2) {
            uVar18 = (uint)(ushort)(p_Var24->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(ushort *)__s2;
          }
          else {
            uVar18 = (uint)(p_Var24->ob_base).ob_base.ob_refcnt;
            uVar20 = *(uint *)__s2;
          }
          if (uVar20 == uVar18) {
            if (lVar21 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var24,__s2,(long)pcVar17 * lVar21);
              uVar18 = (uint)(iVar9 == 0);
              goto LAB_001098b4;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[(long)pPVar10];
LAB_00109810:
  if (values[1] != (PyObject *)0x0) {
    puVar13 = (undefined1 *)((long)&pPVar12[-1].ob_type + 7);
LAB_0010962c:
    if (0 < (long)puVar13) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar12 = (PyObject *)values;
      iVar9 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar12,(PyObject **)__pyx_nargs,
                         0x112590,pcVar17);
      if (iVar9 < 0) {
        iVar9 = 0x13b7;
        goto LAB_00109410;
      }
    }
LAB_00109468:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar10 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = values[1]->ob_type->tp_getattro;
    if (p_Var15 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var15)(values[1],__pyx_mstate_global_static.__pyx_n_s_get_printer);
    }
    if (pPVar11 == (PyObject *)0x0) {
      iVar9 = 0x42;
      c_line = 0x13f2;
    }
    else {
      p_Var23 = pPVar11->ob_type;
      if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
         (p_Var24 = pPVar11[1].ob_type, p_Var24 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar22 = (PyObject *)pPVar11[1].ob_refcnt;
        (p_Var24->ob_base).ob_base.ob_refcnt = (p_Var24->ob_base).ob_base.ob_refcnt + 1;
        pPVar22->ob_refcnt = pPVar22->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar21;
        if (lVar21 == 0) {
          (*p_Var23->tp_dealloc)(pPVar11);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var24;
        pPVar12 = __Pyx_PyObject_FastCallDict(pPVar22,(PyObject **)__pyx_pyargnames,1,pPVar12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = (p_Var24->ob_base).ob_base.ob_refcnt + -1;
        (p_Var24->ob_base).ob_base.ob_refcnt = lVar21;
        pPVar11 = pPVar22;
        if (lVar21 == 0) {
          (*((p_Var24->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var24);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar12 = __Pyx_PyObject_FastCallDict(pPVar11,(PyObject **)(__pyx_pyargnames + 1),0,pPVar12)
        ;
      }
      lVar21 = pPVar11->ob_refcnt + -1;
      if (pPVar12 == (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar11->ob_refcnt = lVar21;
        if (lVar21 == 0) {
          c_line = 0x1406;
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          iVar9 = 0x42;
        }
        else {
          iVar9 = 0x42;
          c_line = 0x1406;
        }
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar11->ob_refcnt = lVar21;
        if (lVar21 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var16 = pPVar10->ob_type->tp_setattro;
        if (p_Var16 == (setattrofunc)0x0) {
          iVar9 = PyObject_SetAttr();
        }
        else {
          iVar9 = (*p_Var16)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_printer,pPVar12);
        }
        lVar21 = pPVar12->ob_refcnt + -1;
        if (iVar9 < 0) {
          c_line = 0x140a;
          iVar9 = 0x42;
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar12->ob_refcnt = lVar21;
          if (lVar21 == 0) {
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
          pPVar12 = (PyObject *)PyDict_New();
          if (pPVar12 == (PyObject *)0x0) {
            iVar9 = 0x43;
            c_line = 0x1414;
            goto LAB_001095f8;
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var16 = pPVar10->ob_type->tp_setattro;
          if (p_Var16 == (setattrofunc)0x0) {
            iVar9 = PyObject_SetAttr();
          }
          else {
            iVar9 = (*p_Var16)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_irq_buttons,pPVar12);
          }
          lVar21 = pPVar12->ob_refcnt + -1;
          if (-1 < iVar9) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar12->ob_refcnt = lVar21;
            pPVar10 = (PyObject *)PTR__Py_NoneStruct_00123f60;
            if (lVar21 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              pPVar10 = (PyObject *)PTR__Py_NoneStruct_00123f60;
              *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 1;
            }
            else {
              *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 1;
            }
            goto LAB_0010942c;
          }
          c_line = 0x1416;
          iVar9 = 0x43;
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar12->ob_refcnt = lVar21;
        if (lVar21 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
      }
    }
LAB_001095f8:
    __Pyx_AddTraceback("extras.buttons_irq.MCU_irq_button.__init__",c_line,iVar9,"buttons_irq.py");
    pPVar10 = (PyObject *)0x0;
    goto LAB_0010942c;
  }
LAB_001098c4:
  lVar21 = PyErr_Occurred();
  if (lVar21 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 2,"s",1);
    iVar9 = 0x13b2;
  }
  else {
    iVar9 = 0x13b0;
  }
LAB_00109410:
  __Pyx_AddTraceback("extras.buttons_irq.MCU_irq_button.__init__",iVar9,0x41,"buttons_irq.py");
  pPVar10 = (PyObject *)0x0;
LAB_0010942c:
  if (lVar19 == *(long *)PTR___stack_chk_guard_00123f40) {
    return pPVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00109a90
 * Symbol:  __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_5_build_config
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_5_build_config(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_5_build_config
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyObject *obj [1];
  int iVar6;
  PyObject *pPVar7;
  PyObject *pPVar8;
  _typeobject *p_Var9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  PyObject *pPVar12;
  _typeobject *p_Var13;
  PyObject **ppPVar14;
  long lVar15;
  getattrofunc p_Var16;
  __pyx_mstate *kwargs;
  setattrofunc p_Var17;
  long lVar18;
  char *in_x6;
  _typeobject *p_Var19;
  _typeobject *p_Var20;
  int iVar21;
  ternaryfunc p_Var22;
  PyObject *pPVar23;
  _typeobject *local_70;
  long local_68;
  iternextfunc local_60;
  PyObject **local_40;
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
  lVar18 = *(long *)PTR___stack_chk_guard_00123f40;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_0010a0d0:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_build_config",
                   "exactly",1,"",__pyx_nargs);
      iVar6 = 0xeac;
      goto LAB_0010a10c;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar15 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,__pyx_args + __pyx_nargs,
                             __pyx_mstate_global_static.__pyx_n_s_self);
      lVar15 = lVar15 + -1;
      if (values[0] == (PyObject *)0x0) {
        lVar15 = PyErr_Occurred();
        if (lVar15 == 0) goto LAB_0010a0d0;
        iVar6 = 0xe9c;
        goto LAB_0010a10c;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_0010a0d0;
      values[0] = *__pyx_args;
      lVar15 = __pyx_kwds[1].ob_refcnt;
    }
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((0 < lVar15) &&
       (iVar6 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x1125d0,in_x6), iVar6 < 0)) {
      iVar6 = 0xea1;
LAB_0010a10c:
      pPVar7 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU._build_config",iVar6,0x23,
                         "buttons_irq.py");
      goto LAB_0010a128;
    }
  }
                    /* Unresolved local var: PyObject * __pyx_v_pin@[???]
                       Unresolved local var: PyObject * __pyx_v_cmd_queue@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: wchar_t __pyx_t_5@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_6@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_7@[???]
                       Unresolved local var: PyObject * __pyx_t_8@[???]
                       Unresolved local var: PyObject * __pyx_t_9@[???]
                       Unresolved local var: PyObject * __pyx_t_10@[???]
                       Unresolved local var: PyObject * __pyx_t_11@[???]
                       Unresolved local var: PyObject * __pyx_t_12@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  obj[0] = values[0];
  p_Var9 = (_typeobject *)__pyx_dict_cached_value_16286;
  kwargs = &__pyx_mstate_global_static;
  if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16285) {
    if (__pyx_dict_cached_value_16286 == (PyObject *)0x0) {
      p_Var9 = (_typeobject *)__Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
      goto LAB_0010a228;
    }
    __pyx_dict_cached_value_16286->ob_refcnt = __pyx_dict_cached_value_16286->ob_refcnt + 1;
LAB_00109b34:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var16 = ((p_Var9->ob_base).ob_base.ob_type)->tp_getattro;
    if (p_Var16 == (getattrofunc)0x0) {
      pPVar7 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar7 = (*p_Var16)((PyObject *)p_Var9,__pyx_mstate_global_static.__pyx_n_s_info);
    }
    lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
    if (pPVar7 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      (p_Var9->ob_base).ob_base.ob_refcnt = lVar15;
      if (lVar15 == 0) {
        (*((p_Var9->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var9);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var16 = obj[0]->ob_type->tp_getattro;
      if (p_Var16 == (getattrofunc)0x0) {
        pPVar8 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar8 = (*p_Var16)(obj[0],__pyx_mstate_global_static.__pyx_n_s_debounce_us);
      }
      if (pPVar8 == (PyObject *)0x0) {
        pPVar23 = (PyObject *)0x0;
        p_Var20 = (_typeobject *)0x0;
        pPVar8 = (PyObject *)0x0;
        iVar21 = 0x24;
        iVar6 = 0xee9;
        pPVar10 = (PyObject *)0x0;
      }
      else {
        p_Var9 = pPVar7->ob_type;
        if ((p_Var9 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
           (p_Var20 = pPVar7[1].ob_type, p_Var20 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar23 = (PyObject *)pPVar7[1].ob_refcnt;
          (p_Var20->ob_base).ob_base.ob_refcnt = (p_Var20->ob_base).ob_base.ob_refcnt + 1;
          pPVar23->ob_refcnt = pPVar23->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar15 = pPVar7->ob_refcnt + -1;
          pPVar7->ob_refcnt = lVar15;
          if (lVar15 == 0) {
            (*p_Var9->tp_dealloc)(pPVar7);
          }
          __pyx_pyargnames[1] =
               (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_irq_button_debounce_us_d;
          __pyx_pyargnames[0] = (PyObject **)p_Var20;
          pPVar10 = __Pyx_PyObject_FastCallDict
                              (pPVar23,(PyObject **)__pyx_pyargnames,3,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar15 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
          (p_Var20->ob_base).ob_base.ob_refcnt = lVar15;
          pPVar7 = pPVar23;
          if (lVar15 == 0) {
            (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] =
               (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_irq_button_debounce_us_d;
          pPVar10 = __Pyx_PyObject_FastCallDict
                              (pPVar7,(PyObject **)(__pyx_pyargnames + 1),2,(PyObject *)kwargs);
        }
        local_40 = (PyObject **)__pyx_pyargnames;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = pPVar8->ob_refcnt + -1;
        pPVar8->ob_refcnt = lVar15;
        if (lVar15 == 0) {
          (*pPVar8->ob_type->tp_dealloc)(pPVar8);
        }
        if (pPVar10 == (PyObject *)0x0) {
          pPVar23 = (PyObject *)0x0;
          pPVar10 = (PyObject *)0x0;
          pPVar8 = (PyObject *)0x0;
          iVar21 = 0x24;
          iVar6 = 0xefe;
          p_Var20 = (_typeobject *)0x0;
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar15 = pPVar7->ob_refcnt + -1;
          pPVar7->ob_refcnt = lVar15;
          if (lVar15 == 0) {
            (*pPVar7->ob_type->tp_dealloc)(pPVar7);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar15 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar15;
          if (lVar15 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var16 = obj[0]->ob_type->tp_getattro;
          if (p_Var16 == (getattrofunc)0x0) {
            pPVar11 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar11 = (*p_Var16)(obj[0],__pyx_mstate_global_static.__pyx_n_s_pin_list);
          }
          if (pPVar11 == (PyObject *)0x0) {
            pPVar23 = (PyObject *)0x0;
            p_Var20 = (_typeobject *)0x0;
            pPVar10 = (PyObject *)0x0;
            pPVar7 = (PyObject *)0x0;
            iVar21 = 0x25;
            iVar6 = 0xf0b;
            pPVar8 = (PyObject *)0x0;
          }
          else if (pPVar11->ob_type == (_typeobject *)PTR_PyTuple_Type_00123ef8 ||
                   pPVar11->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
            lVar15 = pPVar11->ob_refcnt;
            local_68 = 0;
            local_60 = (iternextfunc)0x0;
            pPVar7 = pPVar11;
LAB_00109c94:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar11->ob_refcnt = lVar15;
            if (lVar15 == 0) {
              (*pPVar11->ob_type->tp_dealloc)(pPVar11);
            }
            puVar5 = PTR_PyList_Type_00123fe0;
            puVar4 = PTR_PyDict_Type_00123f78;
            puVar2 = PTR__Py_CheckRecursionLimit_00123f20;
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
            p_Var20 = (_typeobject *)0x0;
LAB_00109ccc:
            if (local_60 == (iternextfunc)0x0) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
              if (pPVar7->ob_type == (_typeobject *)puVar5) {
                if (pPVar7[1].ob_refcnt <= local_68) goto LAB_0010a4b0;
                p_Var19 = (_typeobject *)
                          (&((pPVar7[1].ob_type)->ob_base).ob_base.ob_refcnt)[local_68];
              }
              else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
                if (pPVar7[1].ob_refcnt <= local_68) goto LAB_0010a4b0;
                p_Var19 = (&pPVar7[1].ob_type)[local_68];
              }
              local_68 = local_68 + 1;
              (p_Var19->ob_base).ob_base.ob_refcnt = (p_Var19->ob_base).ob_base.ob_refcnt + 1;
            }
            else {
              p_Var19 = (_typeobject *)(*local_60)(pPVar7);
              if (p_Var19 == (_typeobject *)0x0) {
                    /* Unresolved local var: PyObject * exc_type@[???] */
                pPVar8 = (PyObject *)PyErr_Occurred();
                if (pPVar8 != (PyObject *)0x0) {
                  if ((pPVar8 == *(PyObject **)PTR_PyExc_StopIteration_00123fa8) ||
                     (iVar6 = __Pyx_PyErr_GivenExceptionMatches
                                        (pPVar8,*(PyObject **)PTR_PyExc_StopIteration_00123fa8),
                     iVar6 != 0)) {
                    PyErr_Clear();
                    goto LAB_0010a4b0;
                  }
                  pPVar23 = (PyObject *)0x0;
                  pPVar10 = (PyObject *)0x0;
                  pPVar8 = (PyObject *)0x0;
                  iVar21 = 0x25;
                  iVar6 = 0xf3c;
                  goto LAB_0010a248;
                }
LAB_0010a4b0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar15 = pPVar7->ob_refcnt + -1;
                pPVar7->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                }
                pPVar11 = __Pyx_PyObject_GetAttrStr(obj[0],__pyx_mstate_global_static.__pyx_n_s_mcu)
                ;
                if (pPVar11 == (PyObject *)0x0) {
                  pPVar23 = (PyObject *)0x0;
                  pPVar10 = (PyObject *)0x0;
                  pPVar7 = (PyObject *)0x0;
                  iVar21 = 0x2a;
                  iVar6 = 0xfaf;
                  pPVar8 = (PyObject *)0x0;
                  goto LAB_0010a248;
                }
                pPVar8 = __Pyx_PyObject_GetAttrStr
                                   (pPVar11,__pyx_mstate_global_static.__pyx_n_s_alloc_command_queue
                                   );
                if (pPVar8 == (PyObject *)0x0) {
                  pPVar23 = (PyObject *)0x0;
                  iVar6 = 0xfb1;
                  iVar21 = 0x2a;
                  lVar15 = pPVar11->ob_refcnt + -1;
                  pPVar7 = (PyObject *)0x0;
                  goto LAB_0010ab98;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar15 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                }
                p_Var9 = pPVar8->ob_type;
                if ((p_Var9 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
                   (p_Var19 = pPVar8[1].ob_type, p_Var19 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar7 = (PyObject *)pPVar8[1].ob_refcnt;
                  (p_Var19->ob_base).ob_base.ob_refcnt = (p_Var19->ob_base).ob_base.ob_refcnt + 1;
                  pPVar7->ob_refcnt = pPVar7->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar15 = pPVar8->ob_refcnt + -1;
                  pPVar8->ob_refcnt = lVar15;
                  if (lVar15 == 0) {
                    (*p_Var9->tp_dealloc)(pPVar8);
                  }
                  __pyx_pyargnames[1] = (PyObject **)0x0;
                  __pyx_pyargnames[0] = (PyObject **)p_Var19;
                  pPVar23 = __Pyx_PyObject_FastCallDict(pPVar7,local_40,1,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar15 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var19->ob_base).ob_base.ob_refcnt = lVar15;
                  pPVar8 = pPVar7;
                  if (lVar15 == 0) {
                    (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
                  }
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = (PyObject **)0x0;
                  pPVar23 = __Pyx_PyObject_FastCallDict
                                      (pPVar8,(PyObject **)(__pyx_pyargnames + 1),0,
                                       (PyObject *)kwargs);
                }
                if (pPVar23 == (PyObject *)0x0) {
                  pPVar10 = (PyObject *)0x0;
                  pPVar7 = (PyObject *)0x0;
                  iVar21 = 0x2a;
                  iVar6 = 0xfc6;
                  goto LAB_0010a248;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar15 = pPVar8->ob_refcnt + -1;
                pPVar8->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                }
                pPVar7 = __Pyx_PyObject_GetAttrStr(obj[0],__pyx_mstate_global_static.__pyx_n_s_mcu);
                if (pPVar7 == (PyObject *)0x0) {
                  pPVar10 = (PyObject *)0x0;
                  pPVar8 = (PyObject *)0x0;
                  iVar21 = 0x2b;
                  iVar6 = 0xfd4;
                  goto LAB_0010a248;
                }
                pPVar8 = __Pyx_PyObject_GetAttrStr
                                   (pPVar7,__pyx_mstate_global_static.__pyx_n_s_lookup_command);
                if (pPVar8 == (PyObject *)0x0) {
                  pPVar10 = (PyObject *)0x0;
                  iVar21 = 0x2b;
                  iVar6 = 0xfd6;
                  goto LAB_0010a248;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar15 = pPVar7->ob_refcnt + -1;
                pPVar7->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                }
                pPVar7 = (PyObject *)PyDict_New();
                if (pPVar7 == (PyObject *)0x0) {
                  pPVar10 = (PyObject *)0x0;
                  iVar21 = 0x2c;
                  iVar6 = 0xfe1;
                  goto LAB_0010a248;
                }
                iVar6 = PyDict_SetItem(pPVar7,__pyx_mstate_global_static.__pyx_n_s_cq,pPVar23);
                pPVar10 = __pyx_mstate_global_static.__pyx_tuple__4;
                if (iVar6 < 0) {
                  iVar21 = 0x2c;
                  iVar6 = 0xfe3;
                  pPVar10 = (PyObject *)0x0;
                  goto LAB_0010a248;
                }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
                p_Var22 = pPVar8->ob_type->tp_call;
                if (p_Var22 == (ternaryfunc)0x0) {
                  pPVar11 = (PyObject *)
                            PyObject_Call(pPVar8,__pyx_mstate_global_static.__pyx_tuple__4,pPVar7);
                  if (pPVar11 == (PyObject *)0x0) goto LAB_0010acd4;
                }
                else {
                  lVar15 = PyThreadState_Get();
                  puVar2 = PTR__Py_CheckRecursionLimit_00123f20;
                  iVar6 = *(int *)(lVar15 + 0x20) + 1;
                  *(int *)(lVar15 + 0x20) = iVar6;
                  if ((*(int *)puVar2 < iVar6) &&
                     (iVar6 = _Py_CheckRecursiveCall(" while calling a Python object"), iVar6 != 0))
                  {
                    iVar21 = 0x2b;
                    iVar6 = 0xfec;
                    pPVar10 = (PyObject *)0x0;
                    goto LAB_0010a248;
                  }
                  pPVar11 = (*p_Var22)(pPVar8,pPVar10,pPVar7);
                  lVar15 = PyThreadState_Get();
                  puVar2 = PTR__Py_CheckRecursionLimit_00123f20;
                  iVar1 = *(int *)(lVar15 + 0x20) + -1;
                  *(int *)(lVar15 + 0x20) = iVar1;
                  iVar21 = *(int *)puVar2;
                  iVar6 = iVar21 + -0x32;
                  if (iVar21 < 0xc9) {
                    iVar6 = (iVar21 >> 2) * 3;
                  }
                  if (iVar1 < iVar6) {
                    lVar15 = PyThreadState_Get();
                    *(undefined1 *)(lVar15 + 0x24) = 0;
                  }
                  if (pPVar11 == (PyObject *)0x0) {
                    lVar15 = PyErr_Occurred();
                    pPVar10 = (PyObject *)0x0;
                    if (lVar15 == 0) {
                      iVar21 = 0x2b;
                      iVar6 = 0xfec;
                      PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00123ee0,
                                      "NULL result without error in PyObject_Call");
                    }
                    else {
LAB_0010acd4:
                      pPVar10 = (PyObject *)0x0;
                      iVar21 = 0x2b;
                      iVar6 = 0xfec;
                    }
                    goto LAB_0010a248;
                  }
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar15 = pPVar8->ob_refcnt + -1;
                pPVar8->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar8->ob_type->tp_dealloc)(pPVar8);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar15 = pPVar7->ob_refcnt + -1;
                pPVar7->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar7->ob_type->tp_dealloc)(pPVar7);
                }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                p_Var17 = obj[0]->ob_type->tp_setattro;
                if (p_Var17 == (setattrofunc)0x0) {
                  iVar6 = PyObject_SetAttr();
                }
                else {
                  iVar6 = (*p_Var17)(obj[0],__pyx_mstate_global_static.__pyx_n_s_ack_cmd,pPVar11);
                }
                lVar15 = pPVar11->ob_refcnt + -1;
                if (iVar6 < 0) {
                  iVar6 = 0xff0;
                  iVar21 = 0x2b;
                  pPVar7 = (PyObject *)0x0;
                  goto LAB_0010ab98;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                pPVar11->ob_refcnt = lVar15;
                if (lVar15 == 0) {
                  (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                }
                pPVar7 = (PyObject *)PTR__Py_NoneStruct_00123f60;
                *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 1;
                if ((p_Var20 == (_typeobject *)0x0) ||
                   (lVar15 = (p_Var20->ob_base).ob_base.ob_refcnt + -1,
                   (p_Var20->ob_base).ob_base.ob_refcnt = lVar15, lVar15 != 0)) goto LAB_0010a3a4;
                goto LAB_0010a38c;
              }
            }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            if ((p_Var20 != (_typeobject *)0x0) &&
               (lVar15 = (p_Var20->ob_base).ob_base.ob_refcnt + -1,
               (p_Var20->ob_base).ob_base.ob_refcnt = lVar15, lVar15 == 0)) {
              (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var16 = obj[0]->ob_type->tp_getattro;
            if (p_Var16 == (getattrofunc)0x0) {
              p_Var9 = (_typeobject *)PyObject_GetAttr();
            }
            else {
              p_Var9 = (_typeobject *)(*p_Var16)(obj[0],__pyx_mstate_global_static.__pyx_n_s_mcu);
            }
            p_Var20 = p_Var19;
            if (p_Var9 == (_typeobject *)0x0) {
              pPVar23 = (PyObject *)0x0;
              pPVar8 = (PyObject *)0x0;
              iVar21 = 0x26;
              iVar6 = 0xf4c;
              pPVar10 = (PyObject *)0x0;
              goto LAB_0010a248;
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var16 = ((p_Var9->ob_base).ob_base.ob_type)->tp_getattro;
            if (p_Var16 == (getattrofunc)0x0) {
              pPVar8 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar8 = (*p_Var16)((PyObject *)p_Var9,
                                  __pyx_mstate_global_static.__pyx_n_s_add_config_cmd);
            }
            lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
            if (pPVar8 == (PyObject *)0x0) {
              p_Var13 = (_typeobject *)0x0;
              pPVar12 = (PyObject *)0x0;
              pPVar11 = (PyObject *)0x0;
              pPVar10 = (PyObject *)0x0;
              iVar21 = 0x26;
              iVar6 = 0xf4e;
              local_70 = (_typeobject *)0x0;
              goto LAB_0010a420;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            (p_Var9->ob_base).ob_base.ob_refcnt = lVar15;
            if (lVar15 == 0) {
              (*((p_Var9->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var9);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var16 = obj[0]->ob_type->tp_getattro;
            if (p_Var16 == (getattrofunc)0x0) {
              p_Var9 = (_typeobject *)PyObject_GetAttr();
            }
            else {
              p_Var9 = (_typeobject *)(*p_Var16)(obj[0],__pyx_mstate_global_static.__pyx_n_s_oid);
            }
            if (p_Var9 == (_typeobject *)0x0) {
              pPVar10 = (PyObject *)0x0;
              iVar21 = 0x28;
              iVar6 = 0xf59;
              pPVar23 = (PyObject *)0x0;
              goto LAB_0010a248;
            }
            if ((p_Var19->ob_base).ob_base.ob_type == (_typeobject *)puVar4) {
              pPVar11 = __Pyx_PyDict_GetItem
                                  ((PyObject *)p_Var19,__pyx_mstate_global_static.__pyx_n_s_pin);
            }
            else {
              pPVar11 = (PyObject *)PyObject_GetItem();
            }
            if (pPVar11 == (PyObject *)0x0) {
              pPVar10 = (PyObject *)0x0;
              p_Var13 = (_typeobject *)0x0;
              pPVar12 = (PyObject *)0x0;
              iVar21 = 0x28;
              iVar6 = 0xf5b;
              lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
              local_70 = (_typeobject *)0x0;
              goto LAB_0010a420;
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var16 = ((p_Var19->ob_base).ob_base.ob_type)->tp_getattro;
            if (p_Var16 == (getattrofunc)0x0) {
              pPVar12 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar12 = (*p_Var16)((PyObject *)p_Var19,__pyx_mstate_global_static.__pyx_n_s_get);
            }
            pPVar10 = __pyx_mstate_global_static.__pyx_tuple__2;
            if (pPVar12 == (PyObject *)0x0) {
              pPVar10 = (PyObject *)0x0;
              p_Var13 = (_typeobject *)0x0;
              iVar21 = 0x28;
              iVar6 = 0xf5d;
              lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
              local_70 = (_typeobject *)0x0;
              goto LAB_0010a420;
            }
            p_Var22 = pPVar12->ob_type->tp_call;
            if (p_Var22 == (ternaryfunc)0x0) {
              p_Var13 = (_typeobject *)
                        PyObject_Call(pPVar12,__pyx_mstate_global_static.__pyx_tuple__2,0);
              if (p_Var13 == (_typeobject *)0x0) goto LAB_0010aa18;
            }
            else {
              lVar15 = PyThreadState_Get();
              iVar21 = *(int *)puVar2;
              iVar6 = *(int *)(lVar15 + 0x20) + 1;
              *(int *)(lVar15 + 0x20) = iVar6;
              if ((iVar21 < iVar6) &&
                 (iVar6 = _Py_CheckRecursiveCall(" while calling a Python object",pPVar10),
                 iVar6 != 0)) {
                iVar21 = 0x28;
                iVar6 = 0xf5f;
                pPVar10 = (PyObject *)0x0;
                p_Var13 = (_typeobject *)0x0;
                lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
                local_70 = (_typeobject *)0x0;
                goto LAB_0010a420;
              }
              p_Var13 = (_typeobject *)(*p_Var22)(pPVar12,pPVar10,(PyObject *)0x0);
              lVar15 = PyThreadState_Get();
              iVar1 = *(int *)(lVar15 + 0x20) + -1;
              *(int *)(lVar15 + 0x20) = iVar1;
              iVar21 = *(int *)PTR__Py_CheckRecursionLimit_00123f20;
              iVar6 = (iVar21 >> 2) * 3;
              if (200 < iVar21) {
                iVar6 = iVar21 + -0x32;
              }
              if (iVar1 < iVar6) {
                lVar15 = PyThreadState_Get();
                *(undefined1 *)(lVar15 + 0x24) = 0;
              }
              if (p_Var13 == (_typeobject *)0x0) {
                lVar15 = PyErr_Occurred();
                if (lVar15 == 0) {
                  pPVar10 = (PyObject *)0x0;
                  iVar21 = 0x28;
                  iVar6 = 0xf5f;
                  PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00123ee0,
                                  "NULL result without error in PyObject_Call");
                  lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
                  local_70 = (_typeobject *)0x0;
                }
                else {
LAB_0010aa18:
                  pPVar10 = (PyObject *)0x0;
                  iVar21 = 0x28;
                  iVar6 = 0xf5f;
                  lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
                  local_70 = (_typeobject *)0x0;
                }
                goto LAB_0010a420;
              }
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar15 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar15;
            if (lVar15 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var16 = obj[0]->ob_type->tp_getattro;
            if (p_Var16 == (getattrofunc)0x0) {
              pPVar12 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar12 = (*p_Var16)(obj[0],__pyx_mstate_global_static.__pyx_n_s_debounce_us);
            }
            if (pPVar12 == (PyObject *)0x0) {
              pPVar10 = (PyObject *)0x0;
              iVar21 = 0x28;
              iVar6 = 0xf62;
              lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
              local_70 = (_typeobject *)0x0;
              goto LAB_0010a420;
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var16 = ((p_Var19->ob_base).ob_base.ob_type)->tp_getattro;
            if (p_Var16 == (getattrofunc)0x0) {
              pPVar10 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar10 = (*p_Var16)((PyObject *)p_Var19,__pyx_mstate_global_static.__pyx_n_s_get);
            }
            pPVar23 = __pyx_mstate_global_static.__pyx_tuple__3;
            if (pPVar10 == (PyObject *)0x0) {
              iVar21 = 0x28;
              iVar6 = 0xf64;
              local_70 = (_typeobject *)0x0;
              lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
              goto LAB_0010a420;
            }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
            kwargs = (__pyx_mstate *)pPVar10->ob_type->tp_call;
            if (kwargs == (__pyx_mstate *)0x0) {
              local_70 = (_typeobject *)
                         PyObject_Call(pPVar10,__pyx_mstate_global_static.__pyx_tuple__3,0);
              if (local_70 == (_typeobject *)0x0) goto LAB_0010a8d0;
            }
            else {
              lVar15 = PyThreadState_Get();
              puVar3 = PTR__Py_CheckRecursionLimit_00123f20;
              iVar6 = *(int *)(lVar15 + 0x20) + 1;
              *(int *)(lVar15 + 0x20) = iVar6;
              if ((*(int *)puVar3 < iVar6) &&
                 (iVar6 = _Py_CheckRecursiveCall(" while calling a Python object",pPVar23),
                 iVar6 != 0)) {
                iVar21 = 0x28;
                iVar6 = 0xf66;
                local_70 = (_typeobject *)0x0;
                lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
                goto LAB_0010a420;
              }
              local_70 = (_typeobject *)(*(code *)kwargs)(pPVar10,pPVar23,0);
              lVar15 = PyThreadState_Get();
              iVar1 = *(int *)(lVar15 + 0x20) + -1;
              *(int *)(lVar15 + 0x20) = iVar1;
              iVar21 = *(int *)PTR__Py_CheckRecursionLimit_00123f20;
              iVar6 = (iVar21 >> 2) * 3;
              if (200 < iVar21) {
                iVar6 = iVar21 + -0x32;
              }
              if (iVar1 < iVar6) {
                lVar15 = PyThreadState_Get();
                *(undefined1 *)(lVar15 + 0x24) = 0;
              }
              if (local_70 == (_typeobject *)0x0) {
                lVar15 = PyErr_Occurred();
                if (lVar15 == 0) {
                  iVar21 = 0x28;
                  iVar6 = 0xf66;
                  PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00123ee0,
                                  "NULL result without error in PyObject_Call");
                  lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
                }
                else {
LAB_0010a8d0:
                  iVar21 = 0x28;
                  iVar6 = 0xf66;
                  lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
                }
                goto LAB_0010a420;
              }
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar15 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar15;
            if (lVar15 == 0) {
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
              pPVar10 = (PyObject *)PyTuple_New(5);
            }
            else {
              pPVar10 = (PyObject *)PyTuple_New(5);
            }
            if (pPVar10 == (PyObject *)0x0) {
              iVar21 = 0x28;
              iVar6 = 0xf69;
              lVar15 = (p_Var9->ob_base).ob_base.ob_refcnt + -1;
              goto LAB_0010a420;
            }
            pPVar10[1].ob_type = p_Var9;
            pPVar10[2].ob_refcnt = (Py_ssize_t)pPVar11;
            pPVar10[2].ob_type = p_Var13;
            pPVar10[3].ob_refcnt = (Py_ssize_t)pPVar12;
            pPVar10[3].ob_type = local_70;
            ppPVar14 = (PyObject **)
                       PyUnicode_Format(__pyx_mstate_global_static.
                                        __pyx_kp_s_config_irq_button_oid_d_pin_s_pu,pPVar10);
            if (ppPVar14 == (PyObject **)0x0) {
              iVar21 = 0x27;
              iVar6 = 0xf82;
              pPVar23 = (PyObject *)0x0;
              goto LAB_0010a248;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar15 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar15;
            if (lVar15 == 0) {
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
            }
            p_Var9 = pPVar8->ob_type;
            if ((p_Var9 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
               (p_Var19 = pPVar8[1].ob_type, p_Var19 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar23 = (PyObject *)pPVar8[1].ob_refcnt;
              (p_Var19->ob_base).ob_base.ob_refcnt = (p_Var19->ob_base).ob_base.ob_refcnt + 1;
              pPVar23->ob_refcnt = pPVar23->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar15 = pPVar8->ob_refcnt + -1;
              pPVar8->ob_refcnt = lVar15;
              if (lVar15 == 0) {
                (*p_Var9->tp_dealloc)(pPVar8);
              }
              __pyx_pyargnames[0] = (PyObject **)p_Var19;
              __pyx_pyargnames[1] = ppPVar14;
              pPVar10 = __Pyx_PyObject_FastCallDict(pPVar23,local_40,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar15 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
              (p_Var19->ob_base).ob_base.ob_refcnt = lVar15;
              pPVar8 = pPVar23;
              if (lVar15 == 0) {
                (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = ppPVar14;
              pPVar10 = __Pyx_PyObject_FastCallDict
                                  (pPVar8,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)kwargs);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar23 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
            *ppPVar14 = pPVar23;
            if (pPVar23 == (PyObject *)0x0) {
              (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
            }
            if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar15 = pPVar8->ob_refcnt + -1;
              pPVar8->ob_refcnt = lVar15;
              if (lVar15 == 0) {
                (*pPVar8->ob_type->tp_dealloc)(pPVar8);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar15 = pPVar10->ob_refcnt + -1;
              pPVar10->ob_refcnt = lVar15;
              if (lVar15 == 0) {
                (*pPVar10->ob_type->tp_dealloc)(pPVar10);
              }
              goto LAB_00109ccc;
            }
            pPVar23 = (PyObject *)0x0;
            iVar21 = 0x26;
            iVar6 = 0xf98;
            pPVar10 = (PyObject *)0x0;
          }
          else {
            pPVar7 = (PyObject *)PyObject_GetIter(pPVar11);
            if (pPVar7 == (PyObject *)0x0) {
              pPVar23 = (PyObject *)0x0;
              p_Var20 = (_typeobject *)0x0;
              iVar6 = 0xf12;
              lVar15 = pPVar11->ob_refcnt + -1;
              iVar21 = 0x25;
            }
            else {
              local_60 = pPVar7->ob_type->tp_iternext;
              lVar15 = pPVar11->ob_refcnt + -1;
              if (local_60 != (iternextfunc)0x0) {
                local_68 = -1;
                goto LAB_00109c94;
              }
              iVar6 = 0xf14;
              iVar21 = 0x25;
              pPVar23 = (PyObject *)0x0;
              p_Var20 = (_typeobject *)0x0;
            }
LAB_0010ab98:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar11->ob_refcnt = lVar15;
            if (lVar15 == 0) {
              pPVar10 = (PyObject *)0x0;
              pPVar8 = (PyObject *)0x0;
              (*pPVar11->ob_type->tp_dealloc)(pPVar11);
            }
            else {
              pPVar10 = (PyObject *)0x0;
              pPVar8 = (PyObject *)0x0;
            }
          }
        }
      }
      goto LAB_0010a248;
    }
    p_Var19 = (_typeobject *)0x0;
    pPVar10 = (PyObject *)0x0;
    p_Var13 = (_typeobject *)0x0;
    pPVar12 = (PyObject *)0x0;
    pPVar11 = (PyObject *)0x0;
    pPVar7 = (PyObject *)0x0;
    iVar21 = 0x24;
    iVar6 = 0xee6;
    local_70 = (_typeobject *)0x0;
    pPVar8 = (PyObject *)0x0;
LAB_0010a420:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    (p_Var9->ob_base).ob_base.ob_refcnt = lVar15;
    p_Var20 = p_Var19;
    if (lVar15 == 0) {
      pPVar23 = (PyObject *)0x0;
      (*((p_Var9->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var9);
    }
    else {
      pPVar23 = (PyObject *)0x0;
    }
  }
  else {
    p_Var9 = (_typeobject *)
             __Pyx__GetModuleGlobalName
                       (__pyx_mstate_global_static.__pyx_n_s_logging,
                        (uint64_t *)&__pyx_dict_version_16285,&__pyx_dict_cached_value_16286);
LAB_0010a228:
    if (p_Var9 != (_typeobject *)0x0) goto LAB_00109b34;
    pPVar23 = (PyObject *)0x0;
    p_Var20 = (_typeobject *)0x0;
    pPVar10 = (PyObject *)0x0;
    pPVar8 = (PyObject *)0x0;
    iVar21 = 0x24;
    iVar6 = 0xee4;
    pPVar7 = (PyObject *)0x0;
LAB_0010a248:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    p_Var13 = (_typeobject *)0x0;
    pPVar12 = (PyObject *)0x0;
    pPVar11 = (PyObject *)0x0;
    local_70 = (_typeobject *)0x0;
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar7 != (PyObject *)0x0) &&
     (lVar15 = pPVar7->ob_refcnt + -1, pPVar7->ob_refcnt = lVar15, lVar15 == 0)) {
    (*pPVar7->ob_type->tp_dealloc)(pPVar7);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar8 != (PyObject *)0x0) &&
     (lVar15 = pPVar8->ob_refcnt + -1, pPVar8->ob_refcnt = lVar15, lVar15 == 0)) {
    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar11 != (PyObject *)0x0) &&
     (lVar15 = pPVar11->ob_refcnt + -1, pPVar11->ob_refcnt = lVar15, lVar15 == 0)) {
    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar12 != (PyObject *)0x0) &&
     (lVar15 = pPVar12->ob_refcnt + -1, pPVar12->ob_refcnt = lVar15, lVar15 == 0)) {
    (*pPVar12->ob_type->tp_dealloc)(pPVar12);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((p_Var13 != (_typeobject *)0x0) &&
     (lVar15 = (p_Var13->ob_base).ob_base.ob_refcnt + -1,
     (p_Var13->ob_base).ob_base.ob_refcnt = lVar15, lVar15 == 0)) {
    (*((p_Var13->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var13);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar10 != (PyObject *)0x0) &&
     (lVar15 = pPVar10->ob_refcnt + -1, pPVar10->ob_refcnt = lVar15, lVar15 == 0)) {
    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_70 != (_typeobject *)0x0) &&
     (lVar15 = (local_70->ob_base).ob_base.ob_refcnt + -1,
     (local_70->ob_base).ob_base.ob_refcnt = lVar15, lVar15 == 0)) {
    (*((local_70->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)local_70);
  }
  __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU._build_config",iVar6,iVar21,"buttons_irq.py")
  ;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  pPVar7 = (PyObject *)0x0;
  if (p_Var20 != (_typeobject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar15 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
    (p_Var20->ob_base).ob_base.ob_refcnt = lVar15;
    if (lVar15 == 0) {
      pPVar7 = (PyObject *)0x0;
LAB_0010a38c:
      (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
    }
    else {
      pPVar7 = (PyObject *)0x0;
    }
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (pPVar23 != (PyObject *)0x0) {
LAB_0010a3a4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar15 = pPVar23->ob_refcnt + -1;
    pPVar23->ob_refcnt = lVar15;
    if (lVar15 == 0) {
      (*pPVar23->ob_type->tp_dealloc)(pPVar23);
    }
  }
LAB_0010a128:
  if (lVar18 == *(long *)PTR___stack_chk_guard_00123f40) {
    return pPVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010ad60
 * Symbol:  __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_3setup_buttons
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_3setup_buttons(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_3setup_buttons
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  _typeobject *p_Var12;
  long lVar13;
  long lVar14;
  PyObject *obj;
  PyObject *pPVar15;
  _typeobject *p_Var16;
  undefined8 *puVar17;
  PyObject *pPVar18;
  setattrfunc *__s2;
  long lVar19;
  getattrofunc p_Var20;
  _typeobject *p_Var21;
  size_t _nargs;
  _typeobject *p_Var22;
  setattrofunc p_Var23;
  PyTypeObject *pPVar24;
  char *pcVar25;
  long lVar26;
  long *plVar27;
  uint uVar28;
  descrgetfunc p_Var29;
  _typeobject *p_Var30;
  PyObject *pPVar31;
  PyObject *pPVar32;
  PyObject *pPVar33;
  int iVar34;
  PyObject *pPVar35;
  ternaryfunc p_Var36;
  long lVar37;
  Py_ssize_t PVar38;
  iternextfunc local_90;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_pin_params_list@[???]
                       Unresolved local var: PyObject * __pyx_v_callback@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg26(x26)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar26 = *(long *)PTR___stack_chk_guard_00123f40;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_pin_params_list;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_callback;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 3) goto LAB_0010b558;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    values[2] = __pyx_args[2];
LAB_0010afbc:
                    /* Unresolved local var: PyObject * __pyx_v_mask@[???]
                       Unresolved local var: Py_ssize_t __pyx_v_shift@[???]
                       Unresolved local var: PyObject * __pyx_v_pin_params@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_2@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: int __pyx_t_6@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_7@[???]
                       Unresolved local var: PyObject * __pyx_t_8@[???]
                       Unresolved local var: int __pyx_t_9@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar18 = values[2];
    pPVar15 = values[1];
    pPVar33 = values[0];
    pPVar35 = __pyx_mstate_global_static.__pyx_int_0;
    pPVar32 = __pyx_mstate_global_static.__pyx_n_s_pin_list;
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var30 = (_typeobject *)values[0]->ob_type->tp_getattro;
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1;
    if (p_Var30 == (_typeobject *)0x0) {
      p_Var12 = (_typeobject *)PyObject_GetAttr(values[0],pPVar32);
    }
    else {
      p_Var12 = (_typeobject *)(*(code *)p_Var30)();
    }
    if (p_Var12 != (_typeobject *)0x0) {
      lVar37 = PyObject_Size(p_Var12);
      if (lVar37 != -1) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar13 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
        (p_Var12->ob_base).ob_base.ob_refcnt = lVar13;
        if (lVar13 == 0) {
          (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
        }
        if (pPVar15->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0 ||
            pPVar15->ob_type == (_typeobject *)PTR_PyTuple_Type_00123ef8) {
          lVar13 = 0;
          local_90 = (iternextfunc)0x0;
          pPVar15->ob_refcnt = pPVar15->ob_refcnt + 1;
          p_Var12 = (_typeobject *)pPVar15;
        }
        else {
          p_Var12 = (_typeobject *)PyObject_GetIter(pPVar15);
          if (p_Var12 == (_typeobject *)0x0) {
            pPVar32 = (PyObject *)0x0;
            iVar34 = 0x1c;
            iVar10 = 0xda1;
            goto LAB_0010b4f0;
          }
          local_90 = ((p_Var12->ob_base).ob_base.ob_type)->tp_iternext;
          if (local_90 == (iternextfunc)0x0) {
            iVar10 = 0xda3;
            iVar34 = 0x1c;
            p_Var22 = (_typeobject *)0x0;
            pPVar15 = (PyObject *)0x0;
            pPVar32 = (PyObject *)0x0;
            goto LAB_0010b488;
          }
          lVar13 = -1;
        }
                    /* Unresolved local var: PyObject * retval@[???]
                       Unresolved local var: PyObject * method@[???]
                       Unresolved local var: PyObject * result@[???]
                       Unresolved local var: int is_method@[???] */
        puVar4 = PTR__Py_CheckRecursionLimit_00123f20;
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
        pPVar32 = (PyObject *)0x0;
LAB_0010b070:
        if (local_90 == (iternextfunc)0x0) {
          lVar14 = (p_Var12->ob_base).ob_size;
          if ((p_Var12->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
            if (lVar14 <= lVar13) goto LAB_0010b804;
            pPVar31 = *(PyObject **)(p_Var12->tp_name + lVar13 * 8);
            pPVar31->ob_refcnt = pPVar31->ob_refcnt + 1;
            lVar13 = lVar13 + 1;
          }
          else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
            if (lVar14 <= lVar13) goto LAB_0010b804;
            pPVar31 = (PyObject *)(&p_Var12->tp_name)[lVar13];
            pPVar31->ob_refcnt = pPVar31->ob_refcnt + 1;
            lVar13 = lVar13 + 1;
          }
        }
        else {
          pPVar31 = (*local_90)((PyObject *)p_Var12);
          if (pPVar31 == (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * exc_type@[???] */
            pPVar15 = (PyObject *)PyErr_Occurred();
            if (pPVar15 != (PyObject *)0x0) {
              if ((pPVar15 == *(PyObject **)PTR_PyExc_StopIteration_00123fa8) ||
                 (iVar10 = __Pyx_PyErr_GivenExceptionMatches
                                     (pPVar15,*(PyObject **)PTR_PyExc_StopIteration_00123fa8),
                 iVar10 != 0)) {
                PyErr_Clear();
                goto LAB_0010b804;
              }
              p_Var22 = (_typeobject *)0x0;
              pPVar15 = (PyObject *)0x0;
              iVar10 = 0xdca;
              iVar34 = 0x1c;
              goto LAB_0010b488;
            }
LAB_0010b804:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar13 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
            (p_Var12->ob_base).ob_base.ob_refcnt = lVar13;
            if (lVar13 == 0) {
              (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var20 = pPVar33->ob_type->tp_getattro;
            if (p_Var20 == (getattrofunc)0x0) {
              p_Var12 = (_typeobject *)PyObject_GetAttr();
            }
            else {
              p_Var12 = (_typeobject *)
                        (*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_callbacks);
            }
            if (p_Var12 == (_typeobject *)0x0) {
              iVar34 = 0x21;
              iVar10 = 0xe32;
              goto LAB_0010b4f0;
            }
            obj = (PyObject *)PyLong_FromSsize_t(lVar37);
            if (obj == (PyObject *)0x0) {
              p_Var22 = (_typeobject *)0x0;
              iVar10 = 0xe34;
              iVar34 = 0x21;
              pPVar15 = (PyObject *)0x0;
              goto LAB_0010b488;
            }
            p_Var22 = (_typeobject *)PyTuple_New(3);
            if (p_Var22 == (_typeobject *)0x0) {
              iVar10 = 0xe36;
              pPVar15 = (PyObject *)0x0;
              iVar34 = 0x21;
              goto LAB_0010b9d8;
            }
            p_Var21 = (p_Var12->ob_base).ob_base.ob_type;
            pPVar35->ob_refcnt = pPVar35->ob_refcnt + 1;
            puVar4 = PTR_PyList_Type_00123fe0;
            lVar37 = pPVar18->ob_refcnt;
            p_Var22->tp_name = (char *)pPVar35;
            p_Var22->tp_basicsize = (Py_ssize_t)obj;
            pPVar18->ob_refcnt = lVar37 + 1;
            p_Var22->tp_itemsize = (Py_ssize_t)pPVar18;
            pPVar33 = __pyx_mstate_global_static.__pyx_n_s_append;
            if (p_Var21 != (_typeobject *)puVar4) {
                    /* Unresolved local var: PyObject * retval@[???]
                       Unresolved local var: PyObject * method@[???]
                       Unresolved local var: PyObject * result@[???]
                       Unresolved local var: int is_method@[???]
                       Unresolved local var: PyObject * attr@[???]
                       Unresolved local var: __Pyx_TypeName type_name@[???]
                       Unresolved local var: PyTypeObject * tp@[???]
                       Unresolved local var: PyObject * descr@[???]
                       Unresolved local var: descrgetfunc f@[???]
                       Unresolved local var: PyObject * * dictptr@[???]
                       Unresolved local var: PyObject * dict@[???]
                       Unresolved local var: int meth_found@[???] */
              if (p_Var21->tp_getattro == (getattrofunc)PTR_PyObject_GenericGetAttr_00123f48) {
                if ((p_Var21->tp_dict != (PyObject *)0x0) ||
                   (iVar10 = PyType_Ready(p_Var21), -1 < iVar10)) {
                  pPVar18 = (PyObject *)_PyType_Lookup(p_Var21,pPVar33);
                  puVar5 = PTR_PyMethodDescr_Type_00123fd8;
                  puVar4 = PTR_PyFunction_Type_00123f70;
                  pPVar15 = pPVar18;
                  if (pPVar18 != (PyObject *)0x0) {
                    pPVar24 = pPVar18->ob_type;
                    pPVar18->ob_refcnt = pPVar18->ob_refcnt + 1;
                    if ((pPVar24 == (PyTypeObject *)puVar4 || pPVar24 == (PyTypeObject *)puVar5) ||
                       (iVar10 = __Pyx_IsSubtype(pPVar24,__pyx_mstate_global_static.
                                                         __pyx_CyFunctionType), iVar10 != 0)) {
                      plVar27 = (long *)_PyObject_GetDictPtr(p_Var12);
                      if ((plVar27 != (long *)0x0) &&
                         (p_Var30 = (_typeobject *)*plVar27, p_Var30 != (_typeobject *)0x0)) {
                        p_Var29 = (descrgetfunc)0x0;
                        bVar8 = true;
                        goto LAB_0010c138;
                      }
                      goto LAB_0010c294;
                    }
                    p_Var29 = pPVar24->tp_descr_get;
                    bVar8 = false;
                    if (p_Var29 != (descrgetfunc)0x0) {
                      if (((pPVar24->tp_descr_set == (descrsetfunc)0x0) &&
                          (puVar17 = (undefined8 *)_PyObject_GetDictPtr(p_Var12),
                          puVar17 != (undefined8 *)0x0)) &&
                         (p_Var30 = (_typeobject *)*puVar17, p_Var30 != (_typeobject *)0x0))
                      goto LAB_0010c138;
LAB_0010c364:
                      pPVar15 = (*p_Var29)(pPVar18,(PyObject *)p_Var12,
                                           (PyObject *)(p_Var12->ob_base).ob_base.ob_type);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar37 = pPVar18->ob_refcnt + -1;
                      pPVar18->ob_refcnt = lVar37;
                      if (lVar37 == 0) {
                        (*pPVar18->ob_type->tp_dealloc)(pPVar18);
                      }
                      goto joined_r0x0010c494;
                    }
                    puVar17 = (undefined8 *)_PyObject_GetDictPtr(p_Var12);
                    if ((puVar17 != (undefined8 *)0x0) &&
                       (p_Var30 = (_typeobject *)*puVar17, p_Var30 != (_typeobject *)0x0)) {
LAB_0010c138:
                    /* Unresolved local var: PyObject * res@[???] */
                      p_Var16 = pPVar33[1].ob_type;
                      (p_Var30->ob_base).ob_base.ob_refcnt =
                           (p_Var30->ob_base).ob_base.ob_refcnt + 1;
                      pPVar15 = (PyObject *)_PyDict_GetItem_KnownHash(p_Var30,pPVar33,p_Var16);
                      if (pPVar15 != (PyObject *)0x0) {
                        pPVar15->ob_refcnt = pPVar15->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar37 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
                        (p_Var30->ob_base).ob_base.ob_refcnt = lVar37;
                        if (lVar37 == 0) {
                          (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
                        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        if ((pPVar18 != (PyObject *)0x0) &&
                           (lVar37 = pPVar18->ob_refcnt + -1, pPVar18->ob_refcnt = lVar37,
                           lVar37 == 0)) {
                          (*pPVar18->ob_type->tp_dealloc)(pPVar18);
                        }
                        goto LAB_0010c1c4;
                      }
                      PyErr_Clear();
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar37 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var30->ob_base).ob_base.ob_refcnt = lVar37;
                      if (lVar37 == 0) {
                        (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
                      }
                      if (bVar8) goto LAB_0010c294;
                      if (p_Var29 != (descrgetfunc)0x0) goto LAB_0010c364;
                      pPVar15 = pPVar18;
                      if (pPVar18 == (PyObject *)0x0) goto LAB_0010c3b8;
                    }
LAB_0010c1dc:
                    /* Unresolved local var: PyObject * result@[???] */
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)p_Var22;
                    pPVar33 = __Pyx_PyObject_FastCallDict
                                        (pPVar15,(PyObject **)(__pyx_pyargnames + 1),
                                         0x8000000000000001,(PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar37 = pPVar15->ob_refcnt + -1;
                    pPVar15->ob_refcnt = lVar37;
                    pPVar18 = pPVar15;
                    goto joined_r0x0010c208;
                  }
                  puVar17 = (undefined8 *)_PyObject_GetDictPtr(p_Var12);
                  if ((puVar17 != (undefined8 *)0x0) &&
                     (p_Var30 = (_typeobject *)*puVar17, p_Var30 != (_typeobject *)0x0)) {
                    p_Var29 = (descrgetfunc)0x0;
                    bVar8 = false;
                    goto LAB_0010c138;
                  }
LAB_0010c3b8:
                  iVar10 = 0xe41;
                  iVar34 = 0x21;
                  pPVar15 = (PyObject *)0x0;
                  PyErr_Format(*(undefined8 *)PTR_PyExc_AttributeError_00123fa0,
                               "\'%.200s\' object has no attribute \'%U\'",p_Var21->tp_name,pPVar33)
                  ;
                  goto LAB_0010b488;
                }
              }
              else {
                pPVar15 = __Pyx_PyObject_GetAttrStr
                                    ((PyObject *)p_Var12,__pyx_mstate_global_static.__pyx_n_s_append
                                    );
joined_r0x0010c494:
                if (pPVar15 != (PyObject *)0x0) {
LAB_0010c1c4:
                  p_Var21 = pPVar15->ob_type;
                  if ((p_Var21 != (_typeobject *)PTR_PyMethod_Type_00123ee8) ||
                     (p_Var12 != pPVar15[1].ob_type)) goto LAB_0010c1dc;
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar18 = (PyObject *)pPVar15[1].ob_refcnt;
                  pPVar18->ob_refcnt = pPVar18->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar37 = pPVar15->ob_refcnt + -1;
                  pPVar15->ob_refcnt = lVar37;
                  if (lVar37 == 0) {
                    (*p_Var21->tp_dealloc)(pPVar15);
                  }
LAB_0010c294:
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = (PyObject **)p_Var12;
                  __pyx_pyargnames[2] = (PyObject **)p_Var22;
                  pPVar33 = __Pyx_PyObject_FastCallDict
                                      (pPVar18,(PyObject **)(__pyx_pyargnames + 1),
                                       0x8000000000000002,(PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar37 = pPVar18->ob_refcnt + -1;
                  pPVar18->ob_refcnt = lVar37;
joined_r0x0010c208:
                  if (lVar37 == 0) {
                    (*pPVar18->ob_type->tp_dealloc)(pPVar18);
                  }
                  if (pPVar33 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar37 = pPVar33->ob_refcnt + -1;
                    pPVar33->ob_refcnt = lVar37;
                    if (lVar37 == 0) {
                      (*pPVar33->ob_type->tp_dealloc)(pPVar33);
                    }
                    goto LAB_0010b8e8;
                  }
                }
              }
              pPVar15 = (PyObject *)0x0;
              iVar10 = 0xe41;
              iVar34 = 0x21;
              goto LAB_0010b488;
            }
                    /* Unresolved local var: PyListObject * L@[???]
                       Unresolved local var: Py_ssize_t len@[???] */
            lVar37 = (p_Var12->ob_base).ob_size;
            if (p_Var12->tp_basicsize >> 1 < lVar37 && lVar37 < p_Var12->tp_basicsize) {
              pcVar25 = p_Var12->tp_name;
              (p_Var22->ob_base).ob_base.ob_refcnt = (p_Var22->ob_base).ob_base.ob_refcnt + 1;
              *(_typeobject **)(pcVar25 + lVar37 * 8) = p_Var22;
              (p_Var12->ob_base).ob_size = lVar37 + 1;
            }
            else {
              iVar10 = PyList_Append(p_Var12,p_Var22);
              if (iVar10 < 0) {
                iVar10 = 0xe41;
                iVar34 = 0x21;
                pPVar15 = (PyObject *)0x0;
                goto LAB_0010b488;
              }
            }
LAB_0010b8e8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar37 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
            (p_Var12->ob_base).ob_base.ob_refcnt = lVar37;
            if (lVar37 == 0) {
              (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar37 = (p_Var22->ob_base).ob_base.ob_refcnt + -1;
            (p_Var22->ob_base).ob_base.ob_refcnt = lVar37;
            if (lVar37 == 0) {
              (*((p_Var22->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var22);
            }
            pPVar33 = (PyObject *)PTR__Py_NoneStruct_00123f60;
            *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 1;
            goto LAB_0010b510;
          }
        }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((pPVar32 != (PyObject *)0x0) &&
           (lVar14 = pPVar32->ob_refcnt + -1, pPVar32->ob_refcnt = lVar14, lVar14 == 0)) {
          (*pPVar32->ob_type->tp_dealloc)(pPVar32);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var20 = pPVar31->ob_type->tp_getattro;
        if (p_Var20 == (getattrofunc)0x0) {
          obj = (PyObject *)PyObject_GetAttr();
        }
        else {
          obj = (*p_Var20)(pPVar31,__pyx_mstate_global_static.__pyx_n_s_get);
        }
        pPVar15 = __pyx_mstate_global_static.__pyx_tuple_;
        pPVar32 = pPVar31;
        if (obj == (PyObject *)0x0) {
          p_Var22 = (_typeobject *)0x0;
          iVar10 = 0xdda;
          iVar34 = 0x1d;
          pPVar15 = (PyObject *)0x0;
          goto LAB_0010b488;
        }
        p_Var36 = obj->ob_type->tp_call;
        if (p_Var36 == (ternaryfunc)0x0) {
          pPVar15 = (PyObject *)PyObject_Call(obj,__pyx_mstate_global_static.__pyx_tuple_,0);
          if (pPVar15 == (PyObject *)0x0) goto LAB_0010b9c8;
        }
        else {
          lVar14 = PyThreadState_Get();
          iVar34 = *(int *)puVar4;
          iVar10 = *(int *)(lVar14 + 0x20) + 1;
          *(int *)(lVar14 + 0x20) = iVar10;
          if ((iVar34 < iVar10) &&
             (iVar10 = _Py_CheckRecursiveCall(" while calling a Python object"), iVar10 != 0)) {
            iVar10 = 0xddc;
            iVar34 = 0x1d;
            pPVar15 = (PyObject *)0x0;
            goto LAB_0010b9d8;
          }
          pPVar15 = (*p_Var36)(obj,pPVar15,(PyObject *)0x0);
          lVar14 = PyThreadState_Get();
          iVar3 = *(int *)(lVar14 + 0x20) + -1;
          *(int *)(lVar14 + 0x20) = iVar3;
          iVar34 = *(int *)PTR__Py_CheckRecursionLimit_00123f20;
          iVar10 = iVar34 + -0x32;
          if (iVar34 < 0xc9) {
            iVar10 = (iVar34 >> 2) * 3;
          }
          if (iVar3 < iVar10) {
            lVar14 = PyThreadState_Get();
            *(undefined1 *)(lVar14 + 0x24) = 0;
          }
          if (pPVar15 == (PyObject *)0x0) {
            lVar37 = PyErr_Occurred();
            if (lVar37 == 0) {
              pPVar15 = (PyObject *)0x0;
              iVar10 = 0xddc;
              iVar34 = 0x1d;
              PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00123ee0,
                              "NULL result without error in PyObject_Call");
            }
            else {
LAB_0010b9c8:
              iVar10 = 0xddc;
              pPVar15 = (PyObject *)0x0;
              iVar34 = 0x1d;
            }
            goto LAB_0010b9d8;
          }
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = obj->ob_refcnt + -1;
        obj->ob_refcnt = lVar14;
        if (lVar14 == 0) {
          (*obj->ob_type->tp_dealloc)(obj);
        }
                    /* Unresolved local var: int is_true@[???] */
        uVar11 = (uint)(pPVar15 == (PyObject *)PTR__Py_TrueStruct_00123f68);
        p_Var22 = (_typeobject *)PTR__Py_FalseStruct_00123f30;
        if (((uVar11 == 0 && pPVar15 != (PyObject *)PTR__Py_FalseStruct_00123f30) &&
             pPVar15 != (PyObject *)PTR__Py_NoneStruct_00123f60) &&
           (uVar11 = PyObject_IsTrue(pPVar15), (int)uVar11 < 0)) {
          iVar10 = 0xddf;
          iVar34 = 0x1d;
          p_Var22 = (_typeobject *)0x0;
          goto LAB_0010b488;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = pPVar15->ob_refcnt + -1;
        pPVar15->ob_refcnt = lVar14;
        if (lVar14 == 0) {
          p_Var22 = pPVar15->ob_type;
          (*p_Var22->tp_dealloc)(pPVar15);
        }
        p_Var20 = pPVar33->ob_type->tp_getattro;
        if (uVar11 != 0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          if (p_Var20 == (getattrofunc)0x0) {
            pPVar15 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar15 = (*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_invert);
          }
          if (pPVar15 == (PyObject *)0x0) {
            p_Var22 = (_typeobject *)0x0;
            iVar10 = 0xdea;
            iVar34 = 0x1e;
            goto LAB_0010b488;
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var20 = pPVar33->ob_type->tp_getattro;
          if (p_Var20 == (getattrofunc)0x0) {
            obj = (PyObject *)PyObject_GetAttr();
          }
          else {
            obj = (*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_pin_list);
          }
          if (obj == (PyObject *)0x0) {
            iVar10 = 0xdec;
            iVar34 = 0x1e;
            p_Var22 = (_typeobject *)0x0;
            goto LAB_0010b488;
          }
          lVar14 = PyObject_Size(obj);
          if (lVar14 == -1) {
            iVar10 = 0xdee;
            iVar34 = 0x1e;
            goto LAB_0010b9d8;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar19 = obj->ob_refcnt + -1;
          obj->ob_refcnt = lVar19;
          if (lVar19 == 0) {
            (*obj->ob_type->tp_dealloc)(obj);
            obj = (PyObject *)PyLong_FromSsize_t((long)(1 << (ulong)((uint)lVar14 & 0x1f)));
          }
          else {
            obj = (PyObject *)PyLong_FromSsize_t((long)(1 << (ulong)((uint)lVar14 & 0x1f)));
          }
          if (obj == (PyObject *)0x0) {
            p_Var22 = (_typeobject *)0x0;
            iVar10 = 0xdf0;
            iVar34 = 0x1e;
            goto LAB_0010b488;
          }
          p_Var22 = (_typeobject *)PyNumber_InPlaceOr(pPVar15,obj);
          if (p_Var22 == (_typeobject *)0x0) {
            iVar10 = 0xdf2;
            iVar34 = 0x1e;
            goto LAB_0010b9d8;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar14 = pPVar15->ob_refcnt + -1;
          pPVar15->ob_refcnt = lVar14;
          if (lVar14 == 0) {
            (*pPVar15->ob_type->tp_dealloc)(pPVar15);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar14 = obj->ob_refcnt + -1;
          obj->ob_refcnt = lVar14;
          if (lVar14 == 0) {
            (*obj->ob_type->tp_dealloc)(obj);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var23 = pPVar33->ob_type->tp_setattro;
          if (p_Var23 == (setattrofunc)0x0) {
            iVar10 = PyObject_SetAttr();
          }
          else {
            iVar10 = (*p_Var23)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_invert,
                                (PyObject *)p_Var22);
          }
          if (iVar10 < 0) {
            iVar10 = 0xdf6;
            iVar34 = 0x1e;
            pPVar15 = (PyObject *)0x0;
            goto LAB_0010b488;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar14 = (p_Var22->ob_base).ob_base.ob_refcnt + -1;
          (p_Var22->ob_base).ob_base.ob_refcnt = lVar14;
          if (lVar14 == 0) {
            (*((p_Var22->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var22);
          }
          p_Var20 = pPVar33->ob_type->tp_getattro;
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        if (p_Var20 == (getattrofunc)0x0) {
          p_Var30 = (_typeobject *)PyObject_GetAttr();
        }
        else {
          p_Var30 = (_typeobject *)(*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_pin_list)
          ;
        }
        if (p_Var30 == (_typeobject *)0x0) {
          pPVar15 = (PyObject *)0x0;
          iVar10 = 0xe09;
          iVar34 = 0x1f;
          p_Var22 = p_Var30;
          goto LAB_0010b488;
        }
        lVar14 = PyObject_Size(p_Var30);
        if (lVar14 == -1) {
          iVar10 = 0xe0b;
          iVar34 = 0x1f;
          pPVar15 = (PyObject *)0x0;
          p_Var22 = p_Var30;
          goto LAB_0010b488;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar19 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
        (p_Var30->ob_base).ob_base.ob_refcnt = lVar19;
        if (lVar19 == 0) {
          (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
        }
        p_Var30 = (_typeobject *)PyLong_FromSsize_t((long)(1 << (ulong)((uint)lVar14 & 0x1f)));
        if (p_Var30 == (_typeobject *)0x0) {
          pPVar15 = (PyObject *)0x0;
          iVar10 = 0xe0d;
          iVar34 = 0x1f;
          p_Var22 = p_Var30;
          goto LAB_0010b488;
        }
        pPVar15 = (PyObject *)PyNumber_InPlaceOr(pPVar35,p_Var30);
        if (pPVar15 == (PyObject *)0x0) {
          iVar10 = 0xe0f;
          iVar34 = 0x1f;
          pPVar15 = (PyObject *)0x0;
          p_Var22 = p_Var30;
          goto LAB_0010b488;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
        (p_Var30->ob_base).ob_base.ob_refcnt = lVar14;
        if (lVar14 == 0) {
          (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
          lVar14 = pPVar35->ob_refcnt + -1;
          pPVar35->ob_refcnt = lVar14;
          p_Var30 = p_Var22;
        }
        else {
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar14 = pPVar35->ob_refcnt + -1;
          pPVar35->ob_refcnt = lVar14;
          p_Var30 = p_Var22;
        }
        if (lVar14 == 0) {
          (*pPVar35->ob_type->tp_dealloc)(pPVar35);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var20 = pPVar33->ob_type->tp_getattro;
        if (p_Var20 == (getattrofunc)0x0) {
          obj = (PyObject *)PyObject_GetAttr();
        }
        else {
          obj = (*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_pin_list);
        }
        pPVar7 = __pyx_mstate_global_static.__pyx_n_s_append;
        pPVar35 = pPVar15;
        if (obj == (PyObject *)0x0) {
          iVar10 = 0xe1c;
          pPVar15 = (PyObject *)0x0;
          iVar34 = 0x20;
          p_Var22 = (_typeobject *)0x0;
          goto LAB_0010b488;
        }
        p_Var22 = obj->ob_type;
        if (p_Var22 != (_typeobject *)PTR_PyList_Type_00123fe0) {
                    /* Unresolved local var: PyObject * attr@[???]
                       Unresolved local var: __Pyx_TypeName type_name@[???]
                       Unresolved local var: PyTypeObject * tp@[???]
                       Unresolved local var: PyObject * descr@[???]
                       Unresolved local var: descrgetfunc f@[???]
                       Unresolved local var: PyObject * * dictptr@[???]
                       Unresolved local var: PyObject * dict@[???]
                       Unresolved local var: int meth_found@[???] */
          if (p_Var22->tp_getattro == (getattrofunc)PTR_PyObject_GenericGetAttr_00123f48) {
            if ((p_Var22->tp_dict != (PyObject *)0x0) ||
               (iVar10 = PyType_Ready(p_Var22), -1 < iVar10)) {
              p_Var16 = (_typeobject *)_PyType_Lookup(p_Var22,pPVar7);
              puVar6 = PTR_PyMethodDescr_Type_00123fd8;
              puVar5 = PTR_PyFunction_Type_00123f70;
              p_Var30 = p_Var16;
              if (p_Var16 != (_typeobject *)0x0) {
                pPVar24 = (p_Var16->ob_base).ob_base.ob_type;
                (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
                if ((pPVar24 == (PyTypeObject *)puVar6 || pPVar24 == (PyTypeObject *)puVar5) ||
                   (iVar10 = __Pyx_IsSubtype(pPVar24,__pyx_mstate_global_static.__pyx_CyFunctionType
                                            ), iVar10 != 0)) {
                  puVar17 = (undefined8 *)_PyObject_GetDictPtr(obj);
                  if ((puVar17 != (undefined8 *)0x0) &&
                     (plVar27 = (long *)*puVar17, plVar27 != (long *)0x0)) {
                    p_Var29 = (descrgetfunc)0x0;
                    bVar8 = true;
                    goto LAB_0010bc94;
                  }
                  goto LAB_0010be78;
                }
                p_Var29 = pPVar24->tp_descr_get;
                bVar8 = false;
                if (p_Var29 != (descrgetfunc)0x0) {
                  if (((pPVar24->tp_descr_set == (descrsetfunc)0x0) &&
                      (puVar17 = (undefined8 *)_PyObject_GetDictPtr(obj),
                      puVar17 != (undefined8 *)0x0)) &&
                     (plVar27 = (long *)*puVar17, plVar27 != (long *)0x0)) goto LAB_0010bc94;
LAB_0010bf24:
                  p_Var21 = (_typeobject *)
                            (*p_Var29)((PyObject *)p_Var16,obj,(PyObject *)obj->ob_type);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar14 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var16->ob_base).ob_base.ob_refcnt = lVar14;
                  if (lVar14 == 0) {
                    (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
                  }
                  goto LAB_0010bf6c;
                }
                puVar17 = (undefined8 *)_PyObject_GetDictPtr(obj);
                if ((puVar17 != (undefined8 *)0x0) &&
                   (plVar27 = (long *)*puVar17, plVar27 != (long *)0x0)) {
LAB_0010bc94:
                    /* Unresolved local var: PyObject * res@[???] */
                  p_Var21 = pPVar7[1].ob_type;
                  *plVar27 = *plVar27 + 1;
                  p_Var21 = (_typeobject *)_PyDict_GetItem_KnownHash(plVar27,pPVar7,p_Var21);
                  if (p_Var21 != (_typeobject *)0x0) {
                    (p_Var21->ob_base).ob_base.ob_refcnt = (p_Var21->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar14 = *plVar27;
                    *plVar27 = lVar14 + -1;
                    if (lVar14 + -1 == 0) {
                      (**(code **)(plVar27[1] + 0x30))(plVar27);
                    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    if ((p_Var16 != (_typeobject *)0x0) &&
                       (lVar14 = (p_Var16->ob_base).ob_base.ob_refcnt + -1,
                       (p_Var16->ob_base).ob_base.ob_refcnt = lVar14, lVar14 == 0)) {
                      (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
                    }
                    goto LAB_0010bd38;
                  }
                  PyErr_Clear();
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar14 = *plVar27;
                  *plVar27 = lVar14 + -1;
                  if (lVar14 + -1 == 0) {
                    (**(code **)(plVar27[1] + 0x30))(plVar27);
                  }
                  if (bVar8) goto LAB_0010be78;
                  if (p_Var29 != (descrgetfunc)0x0) goto LAB_0010bf24;
                  if (p_Var16 == (_typeobject *)0x0) goto LAB_0010bf88;
                }
LAB_0010bd4c:
                _nargs = 0x8000000000000001;
                p_Var30 = p_Var16;
                __pyx_pyargnames[1] = (PyObject **)pPVar31;
                goto LAB_0010bd60;
              }
              puVar17 = (undefined8 *)_PyObject_GetDictPtr(obj);
              if ((puVar17 != (undefined8 *)0x0) &&
                 (plVar27 = (long *)*puVar17, plVar27 != (long *)0x0)) {
                p_Var29 = (descrgetfunc)0x0;
                bVar8 = false;
                goto LAB_0010bc94;
              }
LAB_0010bf88:
              iVar10 = 0xe1e;
              iVar34 = 0x20;
              pPVar15 = (PyObject *)0x0;
              PyErr_Format(*(undefined8 *)PTR_PyExc_AttributeError_00123fa0,
                           "\'%.200s\' object has no attribute \'%U\'",p_Var22->tp_name,pPVar7);
              goto LAB_0010b9d8;
            }
          }
          else {
            p_Var21 = (_typeobject *)
                      __Pyx_PyObject_GetAttrStr(obj,__pyx_mstate_global_static.__pyx_n_s_append);
LAB_0010bf6c:
            if (p_Var21 != (_typeobject *)0x0) {
LAB_0010bd38:
              p_Var16 = p_Var21;
              p_Var22 = (p_Var16->ob_base).ob_base.ob_type;
              if ((p_Var22 != (_typeobject *)PTR_PyMethod_Type_00123ee8) ||
                 (obj != (PyObject *)p_Var16->tp_name)) goto LAB_0010bd4c;
                    /* Unresolved local var: PyObject * function@[???] */
              p_Var30 = (_typeobject *)(p_Var16->ob_base).ob_size;
              (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar14 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
              (p_Var16->ob_base).ob_base.ob_refcnt = lVar14;
              if (lVar14 == 0) {
                (*p_Var22->tp_dealloc)((PyObject *)p_Var16);
              }
LAB_0010be78:
              _nargs = 0x8000000000000002;
              __pyx_pyargnames[1] = (PyObject **)obj;
              __pyx_pyargnames[2] = (PyObject **)pPVar31;
LAB_0010bd60:
              __pyx_pyargnames[0] = (PyObject **)0x0;
              pPVar15 = __Pyx_PyObject_FastCallDict
                                  ((PyObject *)p_Var30,(PyObject **)(__pyx_pyargnames + 1),_nargs,
                                   (PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar14 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
              (p_Var30->ob_base).ob_base.ob_refcnt = lVar14;
              if (lVar14 == 0) {
                (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
              }
              if (pPVar15 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar14 = pPVar15->ob_refcnt + -1;
                pPVar15->ob_refcnt = lVar14;
                if (lVar14 == 0) {
                  (*pPVar15->ob_type->tp_dealloc)(pPVar15);
                }
                goto LAB_0010b41c;
              }
            }
          }
          iVar10 = 0xe1e;
          pPVar15 = (PyObject *)0x0;
          iVar34 = 0x20;
          goto LAB_0010b9d8;
        }
                    /* Unresolved local var: PyListObject * L@[???]
                       Unresolved local var: Py_ssize_t len@[???] */
        lVar14 = obj[1].ob_refcnt;
        if (obj[2].ob_refcnt >> 1 < lVar14 && lVar14 < obj[2].ob_refcnt) {
          p_Var30 = obj[1].ob_type;
          pPVar31->ob_refcnt = pPVar31->ob_refcnt + 1;
          (&(p_Var30->ob_base).ob_base.ob_refcnt)[lVar14] = (Py_ssize_t)pPVar31;
          obj[1].ob_refcnt = lVar14 + 1;
        }
        else {
          iVar10 = PyList_Append(obj,pPVar31);
          if (iVar10 < 0) goto code_r0x0010be24;
        }
LAB_0010b41c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = obj->ob_refcnt + -1;
        obj->ob_refcnt = lVar14;
        if (lVar14 == 0) {
          (*obj->ob_type->tp_dealloc)(obj);
        }
        goto LAB_0010b070;
      }
      iVar10 = 0xd91;
      iVar34 = 0x1b;
      p_Var22 = (_typeobject *)0x0;
      pPVar15 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
LAB_0010b488:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar37 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
      (p_Var12->ob_base).ob_base.ob_refcnt = lVar37;
      if (lVar37 == 0) {
        (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
      }
      goto LAB_0010b4a8;
    }
    iVar34 = 0x1b;
    iVar10 = 0xd8f;
    pPVar32 = (PyObject *)0x0;
    goto LAB_0010b4f0;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  pcVar25 = PTR___stack_chk_guard_00123f40;
  if (__pyx_nargs == 1) {
    values[0] = *__pyx_args;
    lVar37 = __pyx_kwds[1].ob_refcnt;
LAB_0010af7c:
    values[1] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_pin_params_list)
    ;
    if (values[1] != (PyObject *)0x0) {
      PVar38 = lVar37 + -1;
      lVar37 = __pyx_kwds[1].ob_refcnt;
LAB_0010ae10:
      pPVar32 = __pyx_mstate_global_static.__pyx_n_s_callback;
      puVar6 = PTR_PyUnicode_Type_00123fb8;
      puVar5 = PTR__Py_TrueStruct_00123f68;
      puVar4 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar37) {
        p_Var30 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_callback == p_Var30) {
          values[2] = *kwvalues;
        }
        else {
          lVar13 = 0;
          do {
            lVar14 = lVar13 + 1;
            if (lVar14 == lVar37) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar13 = 0;
              goto LAB_0010ae70;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar13;
            lVar13 = lVar14;
          } while (__pyx_mstate_global_static.__pyx_n_s_callback != (PyObject *)*pPVar1);
          values[2] = kwvalues[lVar14];
        }
        goto LAB_0010b6a4;
      }
LAB_0010b750:
      values[2] = (PyObject *)0x0;
      goto LAB_0010b754;
    }
    lVar37 = PyErr_Occurred();
    if (lVar37 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_buttons",
                   "exactly",3,"s",1);
      iVar10 = 0xd31;
    }
    else {
      iVar10 = 0xd2f;
    }
  }
  else {
    if (1 < __pyx_nargs) {
      if (__pyx_nargs != 2) {
        if (__pyx_nargs != 3) goto LAB_0010b558;
        values[2] = __pyx_args[2];
      }
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar37 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs == 1) goto LAB_0010af7c;
      PVar38 = lVar37;
      if (__pyx_nargs == 2) goto LAB_0010ae10;
      if (__pyx_nargs == 0) goto LAB_0010af5c;
      goto LAB_0010afa8;
    }
    if (__pyx_nargs == 0) {
      lVar37 = __pyx_kwds[1].ob_refcnt;
LAB_0010af5c:
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
      if (values[0] != (PyObject *)0x0) {
        lVar37 = lVar37 + -1;
        goto LAB_0010af7c;
      }
      lVar37 = PyErr_Occurred();
      if (lVar37 == 0) goto LAB_0010b558;
      iVar10 = 0xd27;
    }
    else {
LAB_0010b558:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_buttons",
                   "exactly",3,"s",__pyx_nargs);
      iVar10 = 0xd4f;
    }
  }
  goto LAB_0010b594;
code_r0x0010be24:
  iVar10 = 0xe1e;
  iVar34 = 0x20;
  pPVar15 = (PyObject *)0x0;
LAB_0010b9d8:
  lVar37 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
  (p_Var12->ob_base).ob_base.ob_refcnt = lVar37;
  if (lVar37 == 0) {
    (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
    lVar37 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar37;
    if (lVar37 != 0) goto LAB_0010ba30;
LAB_0010b9f8:
    p_Var22 = (_typeobject *)0x0;
    (*obj->ob_type->tp_dealloc)(obj);
  }
  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar37 = obj->ob_refcnt + -1;
    obj->ob_refcnt = lVar37;
    if (lVar37 == 0) goto LAB_0010b9f8;
LAB_0010ba30:
    p_Var22 = (_typeobject *)0x0;
  }
LAB_0010b4a8:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar15 != (PyObject *)0x0) &&
     (lVar37 = pPVar15->ob_refcnt + -1, pPVar15->ob_refcnt = lVar37, lVar37 == 0)) {
    (*pPVar15->ob_type->tp_dealloc)(pPVar15);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((p_Var22 != (_typeobject *)0x0) &&
     (lVar37 = (p_Var22->ob_base).ob_base.ob_refcnt + -1,
     (p_Var22->ob_base).ob_base.ob_refcnt = lVar37, lVar37 == 0)) {
    (*((p_Var22->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var22);
  }
LAB_0010b4f0:
  pPVar33 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU.setup_buttons",iVar10,iVar34,"buttons_irq.py"
                    );
LAB_0010b510:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar37 = pPVar35->ob_refcnt + -1;
  pPVar35->ob_refcnt = lVar37;
  if (lVar37 == 0) {
    (*pPVar35->ob_type->tp_dealloc)(pPVar35);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar32 != (PyObject *)0x0) &&
     (lVar37 = pPVar32->ob_refcnt + -1, pPVar32->ob_refcnt = lVar37, lVar37 == 0)) {
    (*pPVar32->ob_type->tp_dealloc)(pPVar32);
  }
  goto LAB_0010b5b0;
  while( true ) {
    lVar14 = lVar13 + 1;
    if (lVar14 == lVar37) goto LAB_0010b750;
    p_Var30 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar13];
    lVar13 = lVar14;
    if ((_typeobject *)pPVar32 == p_Var30) break;
LAB_0010ae70:
    bVar8 = pPVar32->ob_type != (_typeobject *)puVar6;
    bVar9 = (p_Var30->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    lVar14 = lVar13;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar32 != (PyObject *)puVar4) && (bVar8 || p_Var30 != (_typeobject *)puVar4)) {
        plVar27 = (long *)PyObject_RichCompare(pPVar32,p_Var30,2);
        if (plVar27 == (long *)0x0) goto LAB_0010b750;
        uVar11 = (uint)(plVar27 == (long *)puVar5);
        if ((plVar27 != (long *)puVar5 && plVar27 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar27 != (long *)puVar4) {
          uVar11 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar19 = *plVar27;
        *plVar27 = lVar19 + -1;
        if (lVar19 + -1 == 0) {
          (**(code **)(plVar27[1] + 0x30))(plVar27);
        }
LAB_0010b740:
        if (uVar11 != 0) {
          if ((int)uVar11 < 0) goto LAB_0010b750;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar32[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar32), iVar10 < 0)) ||
         ((-1 < (char)p_Var30->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var30), iVar10 < 0))))
      goto LAB_0010b750;
      lVar19 = pPVar32[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar19 == (p_Var30->ob_base).ob_size) &&
         ((pPVar32[1].ob_type == (_typeobject *)p_Var30->tp_name ||
          (_typeobject *)p_Var30->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar32[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar25 = (char *)((ulong)(byte)((byte)pPVar32[2].ob_refcnt >> 2) & 7);
        uVar11 = (uint)pcVar25;
        if (((byte)((byte)p_Var30->tp_basicsize >> 2) & 7) == uVar11) {
          bVar2 = (byte)pPVar32[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var12 = pPVar32[4].ob_type;
          }
          else {
            p_Var12 = (_typeobject *)&pPVar32[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var12 = (_typeobject *)(pPVar32 + 3);
            }
          }
          bVar2 = (byte)p_Var30->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var30->tp_setattr;
          }
          else {
            __s2 = &p_Var30->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var30->tp_dealloc;
            }
          }
          if (uVar11 == 1) {
            uVar11 = (uint)(byte)(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar28 = (uint)*(byte *)__s2;
          }
          else if (uVar11 == 2) {
            uVar11 = (uint)(ushort)(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar28 = (uint)*(ushort *)__s2;
          }
          else {
            uVar11 = (uint)(p_Var12->ob_base).ob_base.ob_refcnt;
            uVar28 = *(uint *)__s2;
          }
          if (uVar28 == uVar11) {
            if (lVar19 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var12,__s2,(long)pcVar25 * lVar19);
              uVar11 = (uint)(iVar10 == 0);
              goto LAB_0010b740;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar14];
LAB_0010b6a4:
  if (values[2] == (PyObject *)0x0) {
LAB_0010b754:
    lVar37 = PyErr_Occurred();
    if (lVar37 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_buttons",
                   "exactly",3,"s",2);
      iVar10 = 0xd3b;
    }
    else {
      iVar10 = 0xd39;
    }
  }
  else {
    lVar37 = PVar38 + -1;
LAB_0010afa8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar37 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x112610,pcVar25), -1 < iVar10))
    goto LAB_0010afbc;
    iVar10 = 0xd40;
  }
LAB_0010b594:
  pPVar33 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU.setup_buttons",iVar10,0x19,"buttons_irq.py");
LAB_0010b5b0:
  if (lVar26 == *(long *)PTR___stack_chk_guard_00123f40) {
    return pPVar33;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010c530
 * Symbol:  __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_7_handle_state
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_7_handle_state(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Type propagation algorithm not settling */

PyObject *
__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_7_handle_state
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
  uint uVar9;
  PyObject *pPVar10;
  _typeobject *p_Var11;
  PyObject *obj;
  PyObject *pPVar12;
  long *plVar13;
  PyObject **ppPVar14;
  PyObject *pPVar15;
  PyObject *pPVar16;
  PyObject *pPVar17;
  PyObject *pPVar18;
  long *plVar19;
  PyThreadState *tstate;
  setattrfunc *__s2;
  getattrofunc p_Var20;
  long lVar21;
  setattrofunc p_Var22;
  ulong uVar23;
  PyObject *kwargs;
  long lVar24;
  char *pcVar25;
  long lVar26;
  long lVar27;
  _typeobject *p_Var28;
  code *pcVar29;
  _typeobject *p_Var30;
  PyObject *pPVar31;
  PyObject *pPVar32;
  long lVar33;
  PyObject *func;
  _typeobject *p_Var34;
  PyObject *pPVar35;
  long lVar36;
  long *plVar37;
  int py_line;
  _typeobject *local_a0;
  PyObject *local_98;
  PyObject *local_90;
  PyObject *local_88;
  PyObject *local_80;
  iternextfunc local_68;
  long local_60;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_msg@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  pcVar25 = (char *)&__pyx_mstate_global_static.__pyx_n_s_self;
  lVar26 = *(long *)PTR___stack_chk_guard_00123f40;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_msg;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar32 = (PyObject *)PTR___stack_chk_guard_00123f40;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0010c5a0;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_0010c644;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar14 = __pyx_args + __pyx_nargs;
  if (__pyx_nargs == 1) {
    lVar36 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar27 = lVar36;
LAB_0010cc08:
    pPVar15 = __pyx_mstate_global_static.__pyx_n_s_msg;
    puVar5 = PTR_PyUnicode_Type_00123fb8;
    puVar4 = PTR__Py_TrueStruct_00123f68;
    puVar3 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar36) {
      p_Var28 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_msg == p_Var28) {
        values[1] = *ppPVar14;
      }
      else {
        lVar24 = 0;
        do {
          lVar33 = lVar24 + 1;
          if (lVar33 == lVar36) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar24 = 0;
            goto LAB_0010cc70;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar24;
          lVar24 = lVar33;
        } while (__pyx_mstate_global_static.__pyx_n_s_msg != (PyObject *)*pPVar1);
        values[1] = ppPVar14[lVar33];
      }
      goto LAB_0010cd70;
    }
LAB_0010ce08:
    values[1] = (PyObject *)0x0;
    goto LAB_0010ce0c;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    lVar27 = __pyx_kwds[1].ob_refcnt;
    goto LAB_0010cbcc;
  }
  if (__pyx_nargs == 0) {
    lVar27 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar14,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      lVar36 = __pyx_kwds[1].ob_refcnt;
      lVar27 = lVar27 + -1;
      goto LAB_0010cc08;
    }
    lVar27 = PyErr_Occurred();
    if (lVar27 != 0) {
      iVar8 = 0x1052;
      goto LAB_0010c5dc;
    }
  }
LAB_0010c5a0:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_handle_state",
               "exactly",2,"s",__pyx_nargs);
  iVar8 = 0x106e;
  goto LAB_0010c5dc;
code_r0x0010ce78:
  py_line = 0x35;
  iVar8 = 0x1207;
  pPVar16 = (PyObject *)0x0;
  local_80 = (PyObject *)0x0;
  pPVar17 = (PyObject *)0x0;
  pPVar12 = (PyObject *)0x0;
  p_Var11 = (_typeobject *)0x0;
LAB_0010cea0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar18 != (PyObject *)0x0) &&
     (lVar27 = pPVar18->ob_refcnt + -1, pPVar18->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar18->ob_type->tp_dealloc)(pPVar18);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((p_Var11 != (_typeobject *)0x0) &&
     (lVar27 = (p_Var11->ob_base).ob_base.ob_refcnt + -1,
     (p_Var11->ob_base).ob_base.ob_refcnt = lVar27, lVar27 == 0)) {
    (*((p_Var11->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var11);
  }
LAB_0010cf08:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((obj != (PyObject *)0x0) &&
     (lVar27 = obj->ob_refcnt + -1, obj->ob_refcnt = lVar27, lVar27 == 0)) {
    (*obj->ob_type->tp_dealloc)(obj);
  }
LAB_0010cf3c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar12 != (PyObject *)0x0) &&
     (lVar27 = pPVar12->ob_refcnt + -1, pPVar12->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar12->ob_type->tp_dealloc)(pPVar12);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar17 != (PyObject *)0x0) &&
     (lVar27 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar17->ob_type->tp_dealloc)(pPVar17);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_80 != (PyObject *)0x0) &&
     (lVar27 = local_80->ob_refcnt + -1, local_80->ob_refcnt = lVar27, lVar27 == 0)) {
    (*local_80->ob_type->tp_dealloc)(local_80);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar16 != (PyObject *)0x0) &&
     (lVar27 = pPVar16->ob_refcnt, pPVar16->ob_refcnt = lVar27 + -1, lVar27 + -1 == 0)) {
    (**(code **)(*(long *)((long)pPVar16 + 8) + 0x30))(pPVar16);
  }
  pPVar32 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU._handle_state",iVar8,py_line,"buttons_irq.py"
                    );
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (local_a0 != (_typeobject *)0x0) {
LAB_0010d01c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = (local_a0->ob_base).ob_base.ob_refcnt + -1;
    (local_a0->ob_base).ob_base.ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*((local_a0->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)local_a0);
    }
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar10 != (PyObject *)0x0) &&
     (lVar27 = pPVar10->ob_refcnt + -1, pPVar10->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
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
  if ((plVar37 != (long *)0x0) && (lVar27 = *plVar37, *plVar37 = lVar27 + -1, lVar27 + -1 == 0)) {
    (**(code **)(plVar37[1] + 0x30))(plVar37);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((p_Var34 != (_typeobject *)0x0) &&
     (lVar27 = (p_Var34->ob_base).ob_base.ob_refcnt + -1,
     (p_Var34->ob_base).ob_base.ob_refcnt = lVar27, lVar27 == 0)) {
    (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_98 != (PyObject *)0x0) &&
     (lVar27 = local_98->ob_refcnt + -1, local_98->ob_refcnt = lVar27, lVar27 == 0)) {
    (*local_98->ob_type->tp_dealloc)(local_98);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar35 != (PyObject *)0x0) &&
     (lVar27 = pPVar35->ob_refcnt + -1, pPVar35->ob_refcnt = lVar27, lVar27 == 0)) {
    (*pPVar35->ob_type->tp_dealloc)(pPVar35);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_88 != (PyObject *)0x0) &&
     (lVar27 = local_88->ob_refcnt + -1, local_88->ob_refcnt = lVar27, lVar27 == 0)) {
    (*local_88->ob_type->tp_dealloc)(local_88);
  }
  goto LAB_0010c5f8;
code_r0x0010d95c:
                    /* Unresolved local var: PyObject * exc_type@[???] */
  pPVar16 = (PyObject *)PyErr_Occurred();
  if (pPVar16 != (PyObject *)0x0) {
    if ((pPVar16 != *(PyObject **)PTR_PyExc_StopIteration_00123fa8) &&
       (iVar8 = __Pyx_PyErr_GivenExceptionMatches
                          (pPVar16,*(PyObject **)PTR_PyExc_StopIteration_00123fa8), iVar8 == 0)) {
      pPVar16 = (PyObject *)0x0;
      local_80 = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      p_Var11 = (_typeobject *)0x0;
      iVar8 = 0x125b;
      py_line = 0x38;
      goto LAB_0010cea0;
    }
    PyErr_Clear();
  }
LAB_0010d990:
  lVar36 = obj->ob_refcnt + -1;
  obj->ob_refcnt = lVar36;
  if (lVar36 == 0) {
    (*obj->ob_type->tp_dealloc)(obj);
  }
  goto LAB_0010c710;
  while( true ) {
    lVar33 = lVar24 + 1;
    if (lVar33 == lVar36) goto LAB_0010ce08;
    p_Var28 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar24];
    lVar24 = lVar33;
    if ((_typeobject *)pPVar15 == p_Var28) break;
LAB_0010cc70:
    bVar6 = pPVar15->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var28->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar33 = lVar24;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar15 != (PyObject *)puVar3) && (bVar6 || p_Var28 != (_typeobject *)puVar3)) {
        plVar37 = (long *)PyObject_RichCompare(pPVar15,p_Var28,2);
        if (plVar37 == (long *)0x0) goto LAB_0010ce08;
        uVar9 = (uint)(plVar37 == (long *)puVar4);
        if ((plVar37 != (long *)puVar4 && plVar37 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar37 != (long *)puVar3) {
          uVar9 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = *plVar37;
        *plVar37 = lVar21 + -1;
        if (lVar21 + -1 == 0) {
          (**(code **)(plVar37[1] + 0x30))(plVar37);
        }
LAB_0010cdfc:
        if (uVar9 != 0) {
          if ((int)uVar9 < 0) goto LAB_0010ce08;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar15[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar15), iVar8 < 0)) ||
         ((-1 < (char)p_Var28->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var28), iVar8 < 0))))
      goto LAB_0010ce08;
      lVar21 = pPVar15[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar21 == (p_Var28->ob_base).ob_size) &&
         ((pPVar15[1].ob_type == (_typeobject *)p_Var28->tp_name ||
          (_typeobject *)p_Var28->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar15[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar23 = (ulong)(byte)((byte)pPVar15[2].ob_refcnt >> 2) & 7;
        uVar9 = (uint)uVar23;
        if (((byte)((byte)p_Var28->tp_basicsize >> 2) & 7) == uVar9) {
          bVar2 = (byte)pPVar15[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var34 = pPVar15[4].ob_type;
          }
          else {
            p_Var34 = (_typeobject *)&pPVar15[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var34 = (_typeobject *)(pPVar15 + 3);
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
          if (uVar9 == 1) {
            uVar9 = (uint)(byte)(p_Var34->ob_base).ob_base.ob_refcnt;
            pcVar25 = (char *)(ulong)*(byte *)__s2;
          }
          else if (uVar9 == 2) {
            uVar9 = (uint)(ushort)(p_Var34->ob_base).ob_base.ob_refcnt;
            pcVar25 = (char *)(ulong)*(ushort *)__s2;
          }
          else {
            uVar9 = (uint)(p_Var34->ob_base).ob_base.ob_refcnt;
            pcVar25 = (char *)(ulong)*(uint *)__s2;
          }
          if ((uint)pcVar25 == uVar9) {
            if (lVar21 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var34,__s2,uVar23 * lVar21);
              uVar9 = (uint)(iVar8 == 0);
              goto LAB_0010cdfc;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar14[lVar33];
LAB_0010cd70:
  if (values[1] != (PyObject *)0x0) {
    lVar27 = lVar27 + -1;
LAB_0010cbcc:
    if (0 < lVar27) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pcVar25 = "_handle_state";
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar14,__pyx_pyargnames,(PyObject *)values,
                         (PyObject **)__pyx_nargs,0x112678,(char *)pPVar32);
      if (iVar8 < 0) {
        iVar8 = 0x1061;
        goto LAB_0010c5dc;
      }
    }
LAB_0010c644:
                    /* Unresolved local var: PyObject * __pyx_v_count@[???]
                       Unresolved local var: PyObject * __pyx_v_states@[???]
                       Unresolved local var: PyObject * __pyx_v_s@[???]
                       Unresolved local var: PyObject * __pyx_v_changed@[???]
                       Unresolved local var: PyObject * __pyx_v_mask@[???]
                       Unresolved local var: PyObject * __pyx_v_shift@[???]
                       Unresolved local var: PyObject * __pyx_v_callback@[???]
                       Unresolved local var: PyObject * __pyx_v_value@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_2@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: int __pyx_t_7@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_8@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_9@[???]
                       Unresolved local var: PyObject * __pyx_t_10@[???]
                       Unresolved local var: PyObject * __pyx_t_11@[???]
                       Unresolved local var: PyObject * __pyx_t_12@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_13@[???]
                       Unresolved local var: wchar_t __pyx_t_14@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar16 = values[1];
    pPVar15 = values[0];
    if (values[1]->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
      local_a0 = (_typeobject *)
                 __Pyx_PyDict_GetItem(values[1],__pyx_mstate_global_static.__pyx_n_s_count);
    }
    else {
      local_a0 = (_typeobject *)PyObject_GetItem();
    }
    if (local_a0 == (_typeobject *)0x0) {
      pPVar16 = (PyObject *)0x0;
      local_80 = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      pPVar12 = (PyObject *)0x0;
      pPVar35 = (PyObject *)0x0;
      p_Var34 = (_typeobject *)0x0;
      plVar37 = (long *)0x0;
      p_Var28 = (_typeobject *)0x0;
      pPVar10 = (PyObject *)0x0;
      iVar8 = 0x119b;
      py_line = 0x2f;
      local_98 = (PyObject *)0x0;
      local_88 = (PyObject *)0x0;
    }
    else {
      if (pPVar16->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
        pPVar10 = __Pyx_PyDict_GetItem(pPVar16,__pyx_mstate_global_static.__pyx_n_s_state);
      }
      else {
        pPVar10 = (PyObject *)PyObject_GetItem();
      }
      if (pPVar10 != (PyObject *)0x0) {
        if (pPVar10->ob_type == (_typeobject *)PTR_PyTuple_Type_00123ef8 ||
            pPVar10->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
          lVar27 = 0;
          local_90 = (PyObject *)0x0;
          pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
          pPVar18 = pPVar10;
        }
        else {
          pPVar18 = (PyObject *)PyObject_GetIter(pPVar10);
          if (pPVar18 == (PyObject *)0x0) {
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            pPVar12 = (PyObject *)0x0;
            pPVar35 = (PyObject *)0x0;
            p_Var34 = (_typeobject *)0x0;
            plVar37 = (long *)0x0;
            p_Var28 = (_typeobject *)0x0;
            iVar8 = 0x11b8;
            py_line = 0x33;
            local_98 = (PyObject *)0x0;
            local_88 = (PyObject *)0x0;
            goto LAB_0010cf3c;
          }
          local_90 = (PyObject *)pPVar18->ob_type->tp_iternext;
          if (local_90 == (PyObject *)0x0) {
            iVar8 = 0x11ba;
            py_line = 0x33;
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            pPVar12 = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            p_Var11 = (_typeobject *)0x0;
            pPVar35 = (PyObject *)0x0;
            p_Var34 = (_typeobject *)0x0;
            plVar37 = (long *)0x0;
            p_Var28 = (_typeobject *)0x0;
            local_98 = (PyObject *)0x0;
            local_88 = (PyObject *)0x0;
            goto LAB_0010cea0;
          }
          lVar27 = -1;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar35 = (PyObject *)0x0;
        p_Var34 = (_typeobject *)0x0;
        p_Var28 = (_typeobject *)0x0;
        local_98 = (PyObject *)0x0;
        local_88 = (PyObject *)0x0;
        plVar37 = (long *)0x0;
LAB_0010c710:
        if (local_90 == (PyObject *)0x0) {
          if (pPVar18->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
            if (pPVar18[1].ob_refcnt <= lVar27) goto LAB_0010d19c;
            p_Var30 = (_typeobject *)(&((pPVar18[1].ob_type)->ob_base).ob_base.ob_refcnt)[lVar27];
            (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
            lVar27 = lVar27 + 1;
          }
          else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
            if (pPVar18[1].ob_refcnt <= lVar27) goto LAB_0010d19c;
            p_Var30 = (&pPVar18[1].ob_type)[lVar27];
            (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
            lVar27 = lVar27 + 1;
          }
        }
        else {
          p_Var30 = (_typeobject *)(*(code *)local_90)(pPVar18);
          if (p_Var30 == (_typeobject *)0x0) {
                    /* Unresolved local var: PyObject * exc_type@[???] */
            pPVar32 = (PyObject *)PyErr_Occurred();
            if (pPVar32 != (PyObject *)0x0) {
              if ((pPVar32 == *(PyObject **)PTR_PyExc_StopIteration_00123fa8) ||
                 (iVar8 = __Pyx_PyErr_GivenExceptionMatches
                                    (pPVar32,*(PyObject **)PTR_PyExc_StopIteration_00123fa8),
                 iVar8 != 0)) {
                PyErr_Clear();
                goto LAB_0010d19c;
              }
              pPVar16 = (PyObject *)0x0;
              local_80 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              iVar8 = 0x11e1;
              py_line = 0x33;
              pPVar12 = (PyObject *)0x0;
              goto LAB_0010cea0;
            }
LAB_0010d19c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar18->ob_refcnt + -1;
            pPVar18->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar18->ob_type->tp_dealloc)(pPVar18);
            }
            obj = __Pyx_PyObject_GetAttrStr(pPVar15,__pyx_mstate_global_static.__pyx_n_s_ack_cmd);
            if (obj == (PyObject *)0x0) {
              pPVar16 = (PyObject *)0x0;
              local_80 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              pPVar12 = (PyObject *)0x0;
              iVar8 = 0x131d;
              py_line = 0x3d;
              goto LAB_0010cf3c;
            }
            local_80 = __Pyx_PyObject_GetAttrStr(obj,__pyx_mstate_global_static.__pyx_n_s_send);
            if (local_80 == (PyObject *)0x0) {
              pPVar16 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              pPVar12 = (PyObject *)0x0;
              iVar8 = 0x131f;
              py_line = 0x3d;
              goto LAB_0010cf08;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = obj->ob_refcnt + -1;
            obj->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*obj->ob_type->tp_dealloc)(obj);
            }
            obj = __Pyx_PyObject_GetAttrStr(pPVar15,__pyx_mstate_global_static.__pyx_n_s_oid);
            if (obj == (PyObject *)0x0) {
              pPVar16 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              pPVar12 = (PyObject *)0x0;
              iVar8 = 0x1322;
              py_line = 0x3d;
              goto LAB_0010cf3c;
            }
            ppPVar14 = (PyObject **)PyList_New(2);
            if (ppPVar14 == (PyObject **)0x0) {
              pPVar16 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              pPVar12 = (PyObject *)0x0;
              iVar8 = 0x1324;
              py_line = 0x3d;
              goto LAB_0010cf08;
            }
            pPVar32 = ppPVar14[3];
            lVar27 = (local_a0->ob_base).ob_base.ob_refcnt;
            pPVar32->ob_refcnt = (Py_ssize_t)obj;
            (local_a0->ob_base).ob_base.ob_refcnt = lVar27 + 1;
            puVar3 = PTR_PyMethod_Type_00123ee8;
            p_Var11 = local_80->ob_type;
            pPVar32->ob_type = local_a0;
            if ((p_Var11 == (_typeobject *)puVar3) &&
               (pPVar32 = (PyObject *)local_80[1].ob_type, pPVar32 != (PyObject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar16 = *(PyObject **)(local_80 + 1);
              pPVar32->ob_refcnt = pPVar32->ob_refcnt + 1;
              pPVar16->ob_refcnt = pPVar16->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar27 = local_80->ob_refcnt + -1;
              local_80->ob_refcnt = lVar27;
              p_Var30 = local_a0;
              if (lVar27 == 0) {
                (*p_Var11->tp_dealloc)(local_80);
              }
              __pyx_pyargnames[0] = (PyObject **)pPVar32;
              __pyx_pyargnames[1] = ppPVar14;
              pPVar15 = __Pyx_PyObject_FastCallDict
                                  (pPVar16,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar27 = pPVar32->ob_refcnt + -1;
              pPVar32->ob_refcnt = lVar27;
              local_80 = pPVar16;
              if (lVar27 == 0) {
                (*pPVar32->ob_type->tp_dealloc)(pPVar32);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = ppPVar14;
              pPVar15 = __Pyx_PyObject_FastCallDict
                                  (local_80,(PyObject **)(__pyx_pyargnames + 1),1,
                                   (PyObject *)local_a0);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar32 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
            *ppPVar14 = pPVar32;
            if (pPVar32 == (PyObject *)0x0) {
              (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
            }
            if (pPVar15 == (PyObject *)0x0) {
              pPVar16 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              pPVar12 = (PyObject *)0x0;
              iVar8 = 0x133f;
              py_line = 0x3d;
              goto LAB_0010cf3c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = local_80->ob_refcnt + -1;
            local_80->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*local_80->ob_type->tp_dealloc)(local_80);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar15->ob_refcnt + -1;
            pPVar15->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar15->ob_type->tp_dealloc)(pPVar15);
            }
            pPVar32 = (PyObject *)PTR__Py_NoneStruct_00123f60;
            *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 1;
            goto LAB_0010d01c;
          }
        }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((p_Var28 != (_typeobject *)0x0) &&
           (lVar36 = (p_Var28->ob_base).ob_base.ob_refcnt + -1,
           (p_Var28->ob_base).ob_base.ob_refcnt = lVar36, lVar36 == 0)) {
          (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
        }
        p_Var28 = p_Var30;
        if ((p_Var30->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyLong_Type_00123f88) {
          (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
          p_Var11 = p_Var30;
        }
        else {
          p_Var11 = (_typeobject *)PyNumber_Long(p_Var30);
          if (p_Var11 == (_typeobject *)0x0) {
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            pPVar12 = (PyObject *)0x0;
            iVar8 = 0x11f1;
            py_line = 0x34;
            goto LAB_0010cea0;
          }
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var20 = pPVar15->ob_type->tp_getattro;
        if (p_Var20 == (getattrofunc)0x0) {
          obj = (PyObject *)PyObject_GetAttr();
        }
        else {
          obj = (*p_Var20)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_invert);
        }
        if (obj == (PyObject *)0x0) {
          pPVar16 = (PyObject *)0x0;
          local_80 = (PyObject *)0x0;
          pPVar17 = (PyObject *)0x0;
          pPVar12 = (PyObject *)0x0;
          iVar8 = 0x11f3;
          py_line = 0x34;
          goto LAB_0010cea0;
        }
        p_Var28 = (_typeobject *)PyNumber_Xor(p_Var11,obj);
        if (p_Var28 == (_typeobject *)0x0) {
          pPVar16 = (PyObject *)0x0;
          local_80 = (PyObject *)0x0;
          pPVar17 = (PyObject *)0x0;
          pPVar12 = (PyObject *)0x0;
          iVar8 = 0x11f5;
          py_line = 0x34;
          p_Var28 = p_Var30;
          goto LAB_0010cea0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = (p_Var11->ob_base).ob_base.ob_refcnt + -1;
        (p_Var11->ob_base).ob_base.ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*((p_Var11->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var11);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = obj->ob_refcnt + -1;
        obj->ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*obj->ob_type->tp_dealloc)(obj);
        }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
        (p_Var30->ob_base).ob_base.ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var20 = pPVar15->ob_type->tp_getattro;
        if (p_Var20 == (getattrofunc)0x0) {
          pPVar12 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar12 = (*p_Var20)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_state);
        }
        if (pPVar12 == (PyObject *)0x0) {
          pPVar16 = (PyObject *)0x0;
          local_80 = (PyObject *)0x0;
          pPVar17 = (PyObject *)0x0;
          obj = (PyObject *)0x0;
          p_Var11 = (_typeobject *)0x0;
          iVar8 = 0x1203;
          py_line = 0x35;
          goto LAB_0010cea0;
        }
        obj = (PyObject *)PyObject_RichCompare(p_Var28,pPVar12,3);
        if (obj == (PyObject *)0x0) {
          pPVar16 = (PyObject *)0x0;
          local_80 = (PyObject *)0x0;
          pPVar17 = (PyObject *)0x0;
          p_Var11 = (_typeobject *)0x0;
          iVar8 = 0x1205;
          py_line = 0x35;
          goto LAB_0010cea0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: int is_true@[???] */
        uVar9 = (uint)(obj == (PyObject *)PTR__Py_TrueStruct_00123f68);
        if (((uVar9 == 0 && obj != (PyObject *)PTR__Py_FalseStruct_00123f30) &&
             obj != (PyObject *)PTR__Py_NoneStruct_00123f60) &&
           (uVar9 = PyObject_IsTrue(obj), (int)uVar9 < 0)) goto code_r0x0010ce78;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = obj->ob_refcnt + -1;
        obj->ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*obj->ob_type->tp_dealloc)(obj);
        }
        if (uVar9 != 0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var20 = pPVar15->ob_type->tp_getattro;
          if (p_Var20 == (getattrofunc)0x0) {
            obj = (PyObject *)PyObject_GetAttr();
          }
          else {
            obj = (*p_Var20)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_state);
          }
          if (obj == (PyObject *)0x0) {
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            pPVar12 = (PyObject *)0x0;
            p_Var11 = (_typeobject *)0x0;
            iVar8 = 0x1212;
            py_line = 0x36;
            goto LAB_0010cea0;
          }
          plVar13 = (long *)PyNumber_Xor(p_Var28,obj);
          if (plVar13 == (long *)0x0) {
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            pPVar12 = (PyObject *)0x0;
            iVar8 = 0x1214;
            py_line = 0x36;
            p_Var11 = (_typeobject *)0x0;
            goto LAB_0010cea0;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = obj->ob_refcnt + -1;
          obj->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*obj->ob_type->tp_dealloc)(obj);
          }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((plVar37 != (long *)0x0) &&
             (lVar36 = *plVar37, *plVar37 = lVar36 + -1, lVar36 + -1 == 0)) {
            (**(code **)(plVar37[1] + 0x30))(plVar37);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var22 = pPVar15->ob_type->tp_setattro;
          if (p_Var22 == (setattrofunc)0x0) {
            iVar8 = PyObject_SetAttr();
          }
          else {
            iVar8 = (*p_Var22)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_state,
                               (PyObject *)p_Var28);
          }
          plVar37 = plVar13;
          if (iVar8 < 0) {
            iVar8 = 0x1221;
            py_line = 0x37;
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            pPVar12 = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            p_Var11 = (_typeobject *)0x0;
            goto LAB_0010cea0;
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var20 = pPVar15->ob_type->tp_getattro;
          if (p_Var20 == (getattrofunc)0x0) {
            pPVar12 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar12 = (*p_Var20)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_callbacks);
          }
          if (pPVar12 == (PyObject *)0x0) {
            pPVar16 = (PyObject *)0x0;
            local_80 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            p_Var11 = (_typeobject *)0x0;
            iVar8 = 0x122a;
            py_line = 0x38;
            goto LAB_0010cea0;
          }
          if (pPVar12->ob_type == (_typeobject *)PTR_PyTuple_Type_00123ef8 ||
              pPVar12->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
            lVar36 = pPVar12->ob_refcnt;
            local_68 = (iternextfunc)0x0;
            local_60 = 0;
            obj = pPVar12;
          }
          else {
            obj = (PyObject *)PyObject_GetIter(pPVar12);
            if (obj == (PyObject *)0x0) {
              pPVar16 = (PyObject *)0x0;
              local_80 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              iVar8 = 0x1231;
              py_line = 0x38;
              goto LAB_0010cea0;
            }
            local_68 = obj->ob_type->tp_iternext;
            if (local_68 == (iternextfunc)0x0) {
              iVar8 = 0x1233;
LAB_0010dc60:
              py_line = 0x38;
              pPVar16 = (PyObject *)0x0;
              local_80 = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              pPVar17 = (PyObject *)0x0;
              goto LAB_0010cea0;
            }
            local_60 = -1;
            lVar36 = pPVar12->ob_refcnt + -1;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar12->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar31 = local_98;
LAB_0010ca18:
          local_98 = pPVar31;
          if (local_68 == (iternextfunc)0x0) {
            if (obj->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
              if (obj[1].ob_refcnt <= local_60) goto LAB_0010d990;
              pPVar12 = *(PyObject **)((long)obj[1].ob_type + local_60 * 8);
              pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
              local_60 = local_60 + 1;
            }
            else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
              if (obj[1].ob_refcnt <= local_60) goto LAB_0010d990;
              pPVar12 = (PyObject *)(&obj[1].ob_type)[local_60];
              pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
              local_60 = local_60 + 1;
            }
          }
          else {
            pPVar12 = (*local_68)(obj);
            if (pPVar12 == (PyObject *)0x0) goto code_r0x0010d95c;
          }
          p_Var30 = pPVar12->ob_type;
          if (p_Var30 == (_typeobject *)PTR_PyTuple_Type_00123ef8) {
                    /* Unresolved local var: PyObject * sequence@[???]
                       Unresolved local var: Py_ssize_t size@[???] */
            lVar36 = pPVar12[1].ob_refcnt;
            if (lVar36 != 3) {
LAB_0010d894:
              if (3 < lVar36) {
                py_line = 0x38;
                local_90 = (PyObject *)0x0;
                local_80 = (PyObject *)0x0;
                iVar8 = 0x1267;
                p_Var11 = (_typeobject *)0x0;
                PyErr_Format(*(undefined8 *)PTR_PyExc_ValueError_00123f10,
                             "too many values to unpack (expected %zd)",3);
                pPVar16 = (PyObject *)0x0;
                pPVar17 = local_90;
                goto LAB_0010cea0;
              }
              if (lVar36 < 0) {
                iVar8 = 0x1267;
                goto LAB_0010dc60;
              }
              py_line = 0x38;
              local_90 = (PyObject *)0x0;
              pcVar25 = "";
              if (lVar36 != 1) {
                pcVar25 = "s";
              }
              iVar8 = 0x1267;
              PyErr_Format(*(undefined8 *)PTR_PyExc_ValueError_00123f10,
                           "need more than %zd value%.1s to unpack",lVar36,pcVar25);
              p_Var11 = (_typeobject *)0x0;
              local_80 = (PyObject *)0x0;
              pPVar16 = local_90;
              pPVar17 = (PyObject *)0x0;
              goto LAB_0010cea0;
            }
            p_Var11 = pPVar12[1].ob_type;
            local_98 = *(PyObject **)(pPVar12 + 2);
            local_80 = (PyObject *)pPVar12[2].ob_type;
LAB_0010ca7c:
            (p_Var11->ob_base).ob_base.ob_refcnt = (p_Var11->ob_base).ob_base.ob_refcnt + 1;
            local_98->ob_refcnt = local_98->ob_refcnt + 1;
            local_80->ob_refcnt = local_80->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*p_Var30->tp_dealloc)(pPVar12);
            }
          }
          else {
            if (p_Var30 == (_typeobject *)PTR_PyList_Type_00123fe0) {
              lVar36 = pPVar12[1].ob_refcnt;
              if (lVar36 != 3) goto LAB_0010d894;
              lVar36 = (long)pPVar12[1].ob_type;
              p_Var11 = *(_typeobject **)lVar36;
              local_98 = *(PyObject **)(lVar36 + 8);
              local_80 = *(PyObject **)(lVar36 + 0x10);
              goto LAB_0010ca7c;
            }
            pPVar16 = (PyObject *)PyObject_GetIter(pPVar12);
            if (pPVar16 == (PyObject *)0x0) {
              local_80 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              iVar8 = 0x1281;
              py_line = 0x38;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
            pcVar29 = *(code **)(*(long *)((long)pPVar16 + 8) + 0xe0);
            p_Var11 = (_typeobject *)(*pcVar29)(pPVar16);
            if (p_Var11 == (_typeobject *)0x0) {
              lVar27 = 0;
              local_98 = (PyObject *)0x0;
LAB_0010dff8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = *(long *)pPVar16;
              *(long *)pPVar16 = lVar36 + -1;
              if (lVar36 + -1 == 0) {
                (**(code **)(*(long *)((long)pPVar16 + 8) + 0x30))(pPVar16);
              }
                    /* Unresolved local var: PyObject * exc_type@[???]
                       Unresolved local var: PyThreadState * __pyx_tstate@[???] */
              lVar36 = _PyThreadState_UncheckedGet();
              pPVar32 = *(PyObject **)(lVar36 + 0x58);
              pPVar17 = local_98;
              if (pPVar32 != (PyObject *)0x0) {
                if (pPVar32 == *(PyObject **)PTR_PyExc_StopIteration_00123fa8) {
                    /* Unresolved local var: PyObject * tmp_type@[???]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???] */
                  plVar13 = *(long **)(lVar36 + 0x60);
                  plVar19 = *(long **)(lVar36 + 0x68);
                  *(undefined8 *)(lVar36 + 0x58) = 0;
                  *(undefined8 *)(lVar36 + 0x60) = 0;
                  *(undefined8 *)(lVar36 + 0x68) = 0;
LAB_0010e284:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar36 = pPVar32->ob_refcnt + -1;
                  pPVar32->ob_refcnt = lVar36;
                  if (lVar36 == 0) {
                    (*pPVar32->ob_type->tp_dealloc)(pPVar32);
                  }
                }
                else {
                  iVar8 = __Pyx_PyErr_GivenExceptionMatches
                                    (pPVar32,*(PyObject **)PTR_PyExc_StopIteration_00123fa8);
                  if (iVar8 == 0) {
                    iVar8 = 0x1293;
                    py_line = 0x38;
                    pPVar16 = (PyObject *)0x0;
                    local_80 = (PyObject *)0x0;
                    pPVar12 = (PyObject *)0x0;
                    local_98 = pPVar31;
                    goto LAB_0010cea0;
                  }
                  pPVar32 = *(PyObject **)(lVar36 + 0x58);
                  plVar13 = *(long **)(lVar36 + 0x60);
                  *(undefined8 *)(lVar36 + 0x58) = 0;
                  *(undefined8 *)(lVar36 + 0x60) = 0;
                  plVar19 = *(long **)(lVar36 + 0x68);
                  *(undefined8 *)(lVar36 + 0x68) = 0;
                  if (pPVar32 != (PyObject *)0x0) goto LAB_0010e284;
                }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                if ((plVar13 != (long *)0x0) &&
                   (lVar36 = *plVar13, *plVar13 = lVar36 + -1, lVar36 + -1 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                if ((plVar19 != (long *)0x0) &&
                   (lVar36 = *plVar19, *plVar19 = lVar36 + -1, lVar36 + -1 == 0)) {
                  (**(code **)(plVar19[1] + 0x30))(plVar19);
                }
              }
              py_line = 0x38;
              pcVar25 = "";
              if (lVar27 != 1) {
                pcVar25 = "s";
              }
              PyErr_Format(*(undefined8 *)PTR_PyExc_ValueError_00123f10,
                           "need more than %zd value%.1s to unpack",lVar27,pcVar25);
              iVar8 = 0x1293;
              pPVar12 = (PyObject *)0x0;
              pPVar16 = (PyObject *)0x0;
              local_80 = (PyObject *)0x0;
              local_98 = pPVar31;
              goto LAB_0010cea0;
            }
            pPVar17 = (PyObject *)(*pcVar29)(pPVar16);
            local_98 = pPVar17;
            if (pPVar17 == (PyObject *)0x0) {
              lVar27 = 1;
              goto LAB_0010dff8;
            }
            local_80 = (PyObject *)(*pcVar29)(pPVar16);
            if (local_80 == (PyObject *)0x0) {
              lVar27 = 2;
              goto LAB_0010dff8;
            }
            plVar19 = (long *)(*pcVar29)(pPVar16);
            if (plVar19 != (long *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar27 = *plVar19;
              *plVar19 = lVar27 + -1;
              if (lVar27 + -1 == 0) {
                (**(code **)(plVar19[1] + 0x30))();
              }
              py_line = 0x38;
              iVar8 = 0x128b;
              pPVar12 = (PyObject *)0x0;
              PyErr_Format(*(undefined8 *)PTR_PyExc_ValueError_00123f10,
                           "too many values to unpack (expected %zd)",3);
              local_98 = pPVar31;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: PyObject * exc_type@[???]
                       Unresolved local var: PyThreadState * __pyx_tstate@[???] */
            tstate = (PyThreadState *)_PyThreadState_UncheckedGet();
            pPVar12 = tstate->curexc_type;
            if (pPVar12 != (PyObject *)0x0) {
              if ((pPVar12 != *(PyObject **)PTR_PyExc_StopIteration_00123fa8) &&
                 (iVar8 = __Pyx_PyErr_GivenExceptionMatches
                                    (pPVar12,*(PyObject **)PTR_PyExc_StopIteration_00123fa8),
                 iVar8 == 0)) {
                iVar8 = 0x128b;
                py_line = 0x38;
                pPVar12 = (PyObject *)0x0;
                local_98 = pPVar31;
                goto LAB_0010cea0;
              }
              __Pyx_ErrRestoreInState(tstate,(PyObject *)0x0,(PyObject *)0x0,(PyObject *)0x0);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = *(long *)pPVar16;
            *(long *)pPVar16 = lVar36 + -1;
            if (lVar36 + -1 == 0) {
              (**(code **)(*(long *)((long)pPVar16 + 8) + 0x30))(pPVar16);
            }
          }
                    /* Unresolved local var: Py_ssize_t index@[???]
                       Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((p_Var34 != (_typeobject *)0x0) &&
             (lVar36 = (p_Var34->ob_base).ob_base.ob_refcnt + -1,
             (p_Var34->ob_base).ob_base.ob_refcnt = lVar36, lVar36 == 0)) {
            (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
          }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar31 != (PyObject *)0x0) &&
             (lVar36 = pPVar31->ob_refcnt + -1, pPVar31->ob_refcnt = lVar36, lVar36 == 0)) {
            (*pPVar31->ob_type->tp_dealloc)(pPVar31);
          }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar35 != (PyObject *)0x0) &&
             (lVar36 = pPVar35->ob_refcnt + -1, pPVar35->ob_refcnt = lVar36, lVar36 == 0)) {
            (*pPVar35->ob_type->tp_dealloc)(pPVar35);
          }
          pPVar12 = (PyObject *)PyNumber_And(plVar13,p_Var11);
          p_Var34 = p_Var11;
          pPVar35 = local_80;
          if (pPVar12 == (PyObject *)0x0) {
            local_80 = (PyObject *)0x0;
            iVar8 = 0x12a4;
            py_line = 0x39;
            pPVar16 = (PyObject *)(long *)0x0;
            pPVar17 = (PyObject *)0x0;
            p_Var11 = (_typeobject *)0x0;
            goto LAB_0010cea0;
          }
                    /* Unresolved local var: int is_true@[???] */
          uVar9 = (uint)(pPVar12 == (PyObject *)PTR__Py_TrueStruct_00123f68);
          if (((uVar9 == 0 && pPVar12 != (PyObject *)PTR__Py_FalseStruct_00123f30) &&
               pPVar12 != (PyObject *)PTR__Py_NoneStruct_00123f60) &&
             (uVar9 = PyObject_IsTrue(), (int)uVar9 < 0)) {
            iVar8 = 0x12a6;
            py_line = 0x39;
            local_80 = (PyObject *)0x0;
            pPVar16 = (PyObject *)(long *)0x0;
            pPVar17 = (PyObject *)0x0;
            p_Var11 = (_typeobject *)0x0;
            goto LAB_0010cea0;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
          pPVar31 = local_98;
          if (uVar9 != 0) {
            pPVar12 = (PyObject *)PyNumber_And(p_Var28,p_Var11);
            if (pPVar12 == (PyObject *)0x0) {
              local_80 = (PyObject *)0x0;
              iVar8 = 0x12b1;
              py_line = 0x3a;
              pPVar16 = (PyObject *)(long *)0x0;
              pPVar17 = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
            pPVar16 = (PyObject *)PyNumber_Rshift(pPVar12,local_98);
            if (pPVar16 == (PyObject *)0x0) {
              iVar8 = 0x12b3;
              py_line = 0x3a;
              local_80 = (PyObject *)0x0;
              pPVar16 = (PyObject *)(long *)0x0;
              pPVar17 = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            if ((local_88 != (PyObject *)0x0) &&
               (lVar36 = local_88->ob_refcnt + -1, local_88->ob_refcnt = lVar36, lVar36 == 0)) {
              (*local_88->ob_type->tp_dealloc)(local_88);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var20 = pPVar15->ob_type->tp_getattro;
            if (p_Var20 == (getattrofunc)0x0) {
              pPVar12 = (PyObject *)PyObject_GetAttr(pPVar15);
            }
            else {
              pPVar12 = (*p_Var20)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_reactor);
            }
            local_88 = pPVar16;
            if (pPVar12 == (PyObject *)0x0) {
              iVar8 = 0x12c0;
              py_line = 0x3b;
              local_80 = (PyObject *)0x0;
              pPVar16 = (PyObject *)(long *)0x0;
              pPVar17 = (PyObject *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var20 = pPVar12->ob_type->tp_getattro;
            if (p_Var20 == (getattrofunc)0x0) {
              pPVar17 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar17 = (*p_Var20)(pPVar12,__pyx_mstate_global_static.
                                           __pyx_n_s_register_async_callback);
            }
            if (pPVar17 == (PyObject *)0x0) {
              iVar8 = 0x12c2;
              py_line = 0x3b;
              local_80 = (PyObject *)0x0;
              pPVar16 = (PyObject *)(long *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
            kwargs = __pyx_mstate_global_static.__pyx_d;
            pPVar12 = __Pyx_CyFunction_New
                                (&
                                 __pyx_mdef_6extras_11buttons_irq_13_IRQButtonMCU_13_handle_state_lambda
                                 ,(int)__pyx_mstate_global_static.
                                       __pyx_n_s_IRQButtonMCU__handle_state_loca,
                                 __pyx_mstate_global_static.__pyx_n_s_extras_buttons_irq,
                                 __pyx_mstate_global_static.__pyx_d,(PyObject *)0x0,
                                 (PyObject *)pcVar25,pPVar32);
            if (pPVar12 == (PyObject *)0x0) {
              iVar8 = 0x12cd;
              py_line = 0x3c;
              local_80 = (PyObject *)0x0;
              pPVar16 = (PyObject *)(long *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: __pyx_CyFunctionObject * m@[???] */
            lVar36 = PyObject_Malloc(0x10);
            pPVar12[7].ob_type = (_typeobject *)lVar36;
            if (lVar36 == 0) {
              lVar36 = PyErr_NoMemory();
            }
            else {
              *(undefined8 *)lVar36 = 0;
              *(undefined8 *)(lVar36 + 8) = 0;
              lVar36 = (long)pPVar12[7].ob_type;
              *(undefined4 *)(pPVar12 + 8) = 2;
              pPVar12[8].ob_type = (_typeobject *)0x10;
            }
            if (lVar36 == 0) {
              iVar8 = 0x12cf;
              py_line = 0x3c;
              local_80 = (PyObject *)0x0;
              pPVar16 = (PyObject *)(long *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
            lVar24 = (long)pPVar12[7].ob_type;
            local_80->ob_refcnt = local_80->ob_refcnt + 1;
            puVar3 = PTR_PyMethod_Type_00123ee8;
            lVar36 = pPVar16->ob_refcnt;
            *(PyObject **)lVar24 = local_80;
            pPVar16->ob_refcnt = lVar36 + 1;
            p_Var11 = pPVar17->ob_type;
            *(PyObject **)(lVar24 + 8) = pPVar16;
            pPVar12[10].ob_type = (_typeobject *)__pyx_pf_6extras_11buttons_irq_2__defaults__;
            if ((p_Var11 == (_typeobject *)puVar3) &&
               (pcVar25 = (char *)pPVar17[1].ob_type, (PyObject *)pcVar25 != (PyObject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              func = *(PyObject **)(pPVar17 + 1);
              ((PyObject *)pcVar25)->ob_refcnt = ((PyObject *)pcVar25)->ob_refcnt + 1;
              func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = pPVar17->ob_refcnt + -1;
              pPVar17->ob_refcnt = lVar36;
              if (lVar36 == 0) {
                (*p_Var11->tp_dealloc)(pPVar17);
              }
              __pyx_pyargnames[0] = (PyObject **)pcVar25;
              __pyx_pyargnames[1] = (PyObject **)pPVar12;
              pPVar16 = __Pyx_PyObject_FastCallDict(func,(PyObject **)__pyx_pyargnames,2,kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = ((PyObject *)pcVar25)->ob_refcnt + -1;
              ((PyObject *)pcVar25)->ob_refcnt = lVar36;
              pPVar17 = func;
              if (lVar36 == 0) {
                (*((PyObject *)pcVar25)->ob_type->tp_dealloc)((PyObject *)pcVar25);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = (PyObject **)pPVar12;
              pPVar16 = __Pyx_PyObject_FastCallDict
                                  (pPVar17,(PyObject **)(__pyx_pyargnames + 1),1,kwargs);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
            if (pPVar16 == (PyObject *)0x0) {
              pPVar12 = (PyObject *)0x0;
              iVar8 = 0x12ea;
              py_line = 0x3b;
              local_80 = (PyObject *)0x0;
              pPVar16 = (PyObject *)(long *)0x0;
              p_Var11 = (_typeobject *)0x0;
              goto LAB_0010cea0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar17->ob_refcnt + -1;
            pPVar17->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar17->ob_type->tp_dealloc)(pPVar17);
            }
            lVar36 = pPVar16->ob_refcnt + -1;
            pPVar16->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar16->ob_type->tp_dealloc)(pPVar16);
            }
          }
          goto LAB_0010ca18;
        }
        goto LAB_0010c710;
      }
      pPVar16 = (PyObject *)0x0;
      local_80 = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      pPVar12 = (PyObject *)0x0;
      pPVar35 = (PyObject *)0x0;
      p_Var34 = (_typeobject *)0x0;
      plVar37 = (long *)0x0;
      p_Var28 = (_typeobject *)0x0;
      iVar8 = 0x11a7;
      py_line = 0x30;
      local_98 = (PyObject *)0x0;
      local_88 = (PyObject *)0x0;
    }
    goto LAB_0010cf3c;
  }
LAB_0010ce0c:
  lVar27 = PyErr_Occurred();
  if (lVar27 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_handle_state",
                 "exactly",2,"s",1);
    iVar8 = 0x105c;
  }
  else {
    iVar8 = 0x105a;
  }
LAB_0010c5dc:
  pPVar32 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU._handle_state",iVar8,0x2e,"buttons_irq.py");
LAB_0010c5f8:
  if (lVar26 == *(long *)PTR___stack_chk_guard_00123f40) {
    return pPVar32;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010e3d0
 * Symbol:  __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_1__init__
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_1__init__
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
  long lVar9;
  PyObject *pPVar10;
  PyObject *pPVar11;
  long *plVar12;
  setattrfunc *pp_Var13;
  long lVar14;
  getattrofunc p_Var15;
  PyObject *pPVar16;
  setattrofunc p_Var17;
  PyObject *pPVar18;
  PyObject **function_name;
  ulong uVar19;
  uint uVar20;
  long lVar21;
  uint uVar22;
  int py_line;
  _typeobject *p_Var23;
  PyObject *pPVar24;
  PyObject *pPVar25;
  long lVar26;
  _typeobject *p_Var27;
  PyObject *func;
  long lVar28;
  long lVar29;
  PyObject *values [4];
  PyObject **__pyx_pyargnames [5];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_printer@[???]
                       Unresolved local var: PyObject * __pyx_v_mcu@[???]
                       Unresolved local var: PyObject * __pyx_v_debounce_us@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar21 = *(long *)PTR___stack_chk_guard_00123f40;
  function_name = &__pyx_mstate_global_static.__pyx_n_s_self;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  values[3] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_printer;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_mcu;
  __pyx_pyargnames[3] = &__pyx_mstate_global_static.__pyx_n_s_debounce_us;
  __pyx_pyargnames[4] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 4) goto LAB_0010eef4;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    values[2] = __pyx_args[2];
    values[3] = __pyx_args[3];
LAB_0010e7b0:
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
    pPVar18 = values[3];
    pPVar25 = values[2];
    pPVar10 = values[1];
    pPVar11 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    pPVar16 = (PyObject *)values[0]->ob_type->tp_setattro;
    if (pPVar16 == (PyObject *)0x0) {
      iVar8 = PyObject_SetAttr(values[0],__pyx_mstate_global_static.__pyx_n_s_printer,values[1]);
    }
    else {
      iVar8 = (*(code *)pPVar16)();
    }
    if (iVar8 < 0) {
      py_line = 0xb;
      iVar8 = 0xbef;
    }
    else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar10->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar10 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar10 = (*p_Var15)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_get_reactor);
      }
      if (pPVar10 == (PyObject *)0x0) {
        py_line = 0xc;
        iVar8 = 0xbf8;
      }
      else {
        p_Var23 = pPVar10->ob_type;
        if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
           (p_Var27 = pPVar10[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar24 = (PyObject *)pPVar10[1].ob_refcnt;
          (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
          pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar28 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            (*p_Var23->tp_dealloc)(pPVar10);
          }
          __pyx_pyargnames[1] = (PyObject **)0x0;
          __pyx_pyargnames[0] = (PyObject **)p_Var27;
          pPVar16 = __Pyx_PyObject_FastCallDict(pPVar24,(PyObject **)__pyx_pyargnames,1,pPVar16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar28 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
          (p_Var27->ob_base).ob_base.ob_refcnt = lVar28;
          pPVar10 = pPVar24;
          if (lVar28 == 0) {
            (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)0x0;
          pPVar16 = __Pyx_PyObject_FastCallDict
                              (pPVar10,(PyObject **)(__pyx_pyargnames + 1),0,pPVar16);
        }
        if (pPVar16 == (PyObject *)0x0) {
          py_line = 0xc;
          iVar8 = 0xc0c;
LAB_0010f2c0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          lVar28 = pPVar10->ob_refcnt + -1;
LAB_0010f2c8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar10->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            pPVar16 = (PyObject *)0x0;
LAB_0010f2d4:
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
            if (pPVar16 != (PyObject *)0x0) goto LAB_0010f2e8;
          }
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar28 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = pPVar11->ob_type->tp_setattro;
          if (p_Var17 == (setattrofunc)0x0) {
            iVar8 = PyObject_SetAttr();
          }
          else {
            iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_reactor,pPVar16);
          }
          lVar28 = pPVar16->ob_refcnt + -1;
          if (iVar8 < 0) {
            iVar8 = 0xc10;
            py_line = 0xc;
            goto LAB_0010f248;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar16->ob_refcnt = lVar28;
          if (lVar28 == 0) {
            (*pPVar16->ob_type->tp_dealloc)(pPVar16);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = pPVar11->ob_type->tp_setattro;
          if (p_Var17 == (setattrofunc)0x0) {
            iVar8 = PyObject_SetAttr();
          }
          else {
            iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_mcu,pPVar25);
          }
          if (iVar8 < 0) {
            py_line = 0xd;
            iVar8 = 0xc1a;
          }
          else {
            pPVar16 = (PyObject *)PyList_New(0);
            if (pPVar16 == (PyObject *)0x0) {
              iVar8 = 0xc23;
              py_line = 0xe;
            }
            else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var17 = pPVar11->ob_type->tp_setattro;
              if (p_Var17 == (setattrofunc)0x0) {
                iVar8 = PyObject_SetAttr();
              }
              else {
                iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_pin_list,pPVar16);
              }
              lVar28 = pPVar16->ob_refcnt + -1;
              if (iVar8 < 0) {
                iVar8 = 0xc25;
                py_line = 0xe;
LAB_0010f248:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                pPVar16->ob_refcnt = lVar28;
joined_r0x0010f24c:
                if (lVar28 == 0) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                }
              }
              else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                pPVar16->ob_refcnt = lVar28;
                if (lVar28 == 0) {
                  (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                }
                pPVar16 = (PyObject *)PyList_New(0);
                if (pPVar16 == (PyObject *)0x0) {
                  iVar8 = 0xc2f;
                  py_line = 0xf;
                }
                else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  pPVar24 = (PyObject *)pPVar11->ob_type->tp_setattro;
                  if (pPVar24 == (PyObject *)0x0) {
                    iVar8 = PyObject_SetAttr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_callbacks,
                                             pPVar16);
                  }
                  else {
                    iVar8 = (*(code *)pPVar24)();
                  }
                  lVar28 = pPVar16->ob_refcnt + -1;
                  if (iVar8 < 0) {
                    iVar8 = 0xc31;
                    py_line = 0xf;
                    goto LAB_0010f248;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar16->ob_refcnt = lVar28;
                  if (lVar28 == 0) {
                    (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var15 = pPVar25->ob_type->tp_getattro;
                  if (p_Var15 == (getattrofunc)0x0) {
                    pPVar10 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar10 = (*p_Var15)(pPVar25,__pyx_mstate_global_static.__pyx_n_s_create_oid);
                  }
                  if (pPVar10 == (PyObject *)0x0) {
                    py_line = 0x10;
                    iVar8 = 0xc3b;
                    goto LAB_0010f1d0;
                  }
                  p_Var23 = pPVar10->ob_type;
                  if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
                     (p_Var27 = pPVar10[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar25 = (PyObject *)pPVar10[1].ob_refcnt;
                    (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
                    pPVar25->ob_refcnt = pPVar25->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = pPVar10->ob_refcnt + -1;
                    pPVar10->ob_refcnt = lVar28;
                    if (lVar28 == 0) {
                      (*p_Var23->tp_dealloc)(pPVar10);
                    }
                    __pyx_pyargnames[1] = (PyObject **)0x0;
                    __pyx_pyargnames[0] = (PyObject **)p_Var27;
                    pPVar16 = __Pyx_PyObject_FastCallDict
                                        (pPVar25,(PyObject **)__pyx_pyargnames,1,pPVar24);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar28 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var27->ob_base).ob_base.ob_refcnt = lVar28;
                    pPVar10 = pPVar25;
                    if (lVar28 == 0) {
                      (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)0x0;
                    pPVar16 = __Pyx_PyObject_FastCallDict
                                        (pPVar10,(PyObject **)(__pyx_pyargnames + 1),0,pPVar24);
                  }
                  if (pPVar16 == (PyObject *)0x0) {
                    py_line = 0x10;
                    iVar8 = 0xc4f;
                    goto LAB_0010f2c0;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar28 = pPVar10->ob_refcnt + -1;
                  pPVar10->ob_refcnt = lVar28;
                  if (lVar28 == 0) {
                    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var17 = pPVar11->ob_type->tp_setattro;
                  if (p_Var17 == (setattrofunc)0x0) {
                    iVar8 = PyObject_SetAttr();
                  }
                  else {
                    iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_oid,pPVar16);
                  }
                  lVar28 = pPVar16->ob_refcnt + -1;
                  if (iVar8 < 0) {
                    iVar8 = 0xc53;
                    py_line = 0x10;
                    goto LAB_0010f248;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar16->ob_refcnt = lVar28;
                  if (lVar28 == 0) {
                    (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var17 = pPVar11->ob_type->tp_setattro;
                  if (p_Var17 == (setattrofunc)0x0) {
                    iVar8 = PyObject_SetAttr();
                  }
                  else {
                    iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_ack_count,
                                       __pyx_mstate_global_static.__pyx_int_0);
                  }
                  if (iVar8 < 0) {
                    py_line = 0x11;
                    iVar8 = 0xc5d;
                  }
                  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                    p_Var17 = pPVar11->ob_type->tp_setattro;
                    if (p_Var17 == (setattrofunc)0x0) {
                      iVar8 = PyObject_SetAttr();
                    }
                    else {
                      iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_state,
                                         __pyx_mstate_global_static.__pyx_int_0);
                    }
                    if (iVar8 < 0) {
                      py_line = 0x12;
                      iVar8 = 0xc66;
                    }
                    else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                      p_Var17 = pPVar11->ob_type->tp_setattro;
                      if (p_Var17 == (setattrofunc)0x0) {
                        iVar8 = PyObject_SetAttr();
                      }
                      else {
                        iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_invert,
                                           __pyx_mstate_global_static.__pyx_int_0);
                      }
                      if (iVar8 < 0) {
                        py_line = 0x13;
                        iVar8 = 0xc6f;
                      }
                      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                        p_Var17 = pPVar11->ob_type->tp_setattro;
                        if (p_Var17 == (setattrofunc)0x0) {
                          iVar8 = PyObject_SetAttr();
                        }
                        else {
                          iVar8 = (*p_Var17)(pPVar11,__pyx_mstate_global_static.
                                                     __pyx_n_s_debounce_us,pPVar18);
                        }
                        if (iVar8 < 0) {
                          py_line = 0x14;
                          iVar8 = 0xc78;
                        }
                        else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                          p_Var15 = pPVar11->ob_type->tp_getattro;
                          if (p_Var15 == (getattrofunc)0x0) {
                            pPVar10 = (PyObject *)PyObject_GetAttr();
                          }
                          else {
                            pPVar10 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_mcu);
                          }
                          if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                            p_Var15 = pPVar10->ob_type->tp_getattro;
                            if (p_Var15 == (getattrofunc)0x0) {
                              pPVar16 = (PyObject *)PyObject_GetAttr();
                            }
                            else {
                              pPVar16 = (*p_Var15)(pPVar10,__pyx_mstate_global_static.
                                                           __pyx_n_s_register_response);
                            }
                            lVar28 = pPVar10->ob_refcnt + -1;
                            if (pPVar16 == (PyObject *)0x0) {
                              py_line = 0x16;
                              iVar8 = 0xc83;
                              goto LAB_0010f2c8;
                            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            pPVar10->ob_refcnt = lVar28;
                            if (lVar28 == 0) {
                              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                            p_Var15 = pPVar11->ob_type->tp_getattro;
                            if (p_Var15 == (getattrofunc)0x0) {
                              pPVar10 = (PyObject *)PyObject_GetAttr();
                            }
                            else {
                              pPVar10 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.
                                                           __pyx_n_s_handle_state);
                            }
                            if (pPVar10 == (PyObject *)0x0) {
                              py_line = 0x16;
                              iVar8 = 0xc86;
                              lVar28 = pPVar16->ob_refcnt + -1;
                            }
                            else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                              p_Var15 = pPVar11->ob_type->tp_getattro;
                              if (p_Var15 == (getattrofunc)0x0) {
                                pPVar25 = (PyObject *)PyObject_GetAttr();
                              }
                              else {
                                pPVar25 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.
                                                             __pyx_n_s_oid);
                              }
                              if (pPVar25 == (PyObject *)0x0) {
                                py_line = 0x16;
                                iVar8 = 0xc88;
                                lVar28 = pPVar10->ob_refcnt + -1;
                                pPVar10->ob_refcnt = lVar28;
                                if (lVar28 == 0) goto LAB_0010f2d4;
                              }
                              else {
                                p_Var23 = pPVar16->ob_type;
                                if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
                                   (p_Var27 = pPVar16[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                                  func = (PyObject *)pPVar16[1].ob_refcnt;
                                  (p_Var27->ob_base).ob_base.ob_refcnt =
                                       (p_Var27->ob_base).ob_base.ob_refcnt + 1;
                                  func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                  lVar28 = pPVar16->ob_refcnt + -1;
                                  pPVar16->ob_refcnt = lVar28;
                                  if (lVar28 == 0) {
                                    (*p_Var23->tp_dealloc)(pPVar16);
                                  }
                                  __pyx_pyargnames[2] =
                                       (PyObject **)
                                       __pyx_mstate_global_static.__pyx_n_s_irq_button_state;
                                  pPVar18 = __pyx_mstate_global_static.__pyx_n_s_irq_button_state;
                                  __pyx_pyargnames[0] = (PyObject **)p_Var27;
                                  __pyx_pyargnames[1] = (PyObject **)pPVar10;
                                  __pyx_pyargnames[3] = (PyObject **)pPVar25;
                                  pPVar24 = __Pyx_PyObject_FastCallDict
                                                      (func,(PyObject **)__pyx_pyargnames,4,
                                                       __pyx_mstate_global_static.
                                                       __pyx_n_s_irq_button_state);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                  lVar28 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
                                  (p_Var27->ob_base).ob_base.ob_refcnt = lVar28;
                                  pPVar16 = func;
                                  if (lVar28 == 0) {
                                    (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)
                                              ((PyObject *)p_Var27);
                                  }
                                }
                                else {
                                  __pyx_pyargnames[0] = (PyObject **)0x0;
                                  __pyx_pyargnames[2] =
                                       (PyObject **)
                                       __pyx_mstate_global_static.__pyx_n_s_irq_button_state;
                                  pPVar18 = __pyx_mstate_global_static.__pyx_n_s_irq_button_state;
                                  __pyx_pyargnames[1] = (PyObject **)pPVar10;
                                  __pyx_pyargnames[3] = (PyObject **)pPVar25;
                                  pPVar24 = __Pyx_PyObject_FastCallDict
                                                      (pPVar16,(PyObject **)(__pyx_pyargnames + 1),3
                                                       ,__pyx_mstate_global_static.
                                                        __pyx_n_s_irq_button_state);
                                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                lVar28 = pPVar10->ob_refcnt + -1;
                                pPVar10->ob_refcnt = lVar28;
                                if (lVar28 == 0) {
                                  (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                lVar28 = pPVar25->ob_refcnt + -1;
                                pPVar25->ob_refcnt = lVar28;
                                if (lVar28 == 0) {
                                  (*pPVar25->ob_type->tp_dealloc)(pPVar25);
                                }
                                if (pPVar24 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                  lVar28 = pPVar16->ob_refcnt + -1;
                                  pPVar16->ob_refcnt = lVar28;
                                  if (lVar28 == 0) {
                                    (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                  lVar28 = pPVar24->ob_refcnt + -1;
                                  pPVar24->ob_refcnt = lVar28;
                                  if (lVar28 == 0) {
                                    (*pPVar24->ob_type->tp_dealloc)(pPVar24);
                                  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                                  p_Var15 = pPVar11->ob_type->tp_getattro;
                                  if (p_Var15 == (getattrofunc)0x0) {
                                    pPVar16 = (PyObject *)PyObject_GetAttr();
                                  }
                                  else {
                                    pPVar16 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.
                                                                 __pyx_n_s_mcu);
                                  }
                                  if (pPVar16 == (PyObject *)0x0) {
                                    py_line = 0x17;
                                    iVar8 = 0xcab;
                                  }
                                  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                                    p_Var15 = pPVar16->ob_type->tp_getattro;
                                    if (p_Var15 == (getattrofunc)0x0) {
                                      pPVar10 = (PyObject *)PyObject_GetAttr();
                                    }
                                    else {
                                      pPVar10 = (*p_Var15)(pPVar16,__pyx_mstate_global_static.
                                                                                                                                      
                                                  __pyx_n_s_register_config_callback);
                                    }
                                    lVar28 = pPVar16->ob_refcnt + -1;
                                    if (pPVar10 == (PyObject *)0x0) {
                                      py_line = 0x17;
                                      iVar8 = 0xcad;
                                      goto LAB_0010f2f0;
                                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                    pPVar16->ob_refcnt = lVar28;
                                    if (lVar28 == 0) {
                                      (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                                    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                                    p_Var15 = pPVar11->ob_type->tp_getattro;
                                    if (p_Var15 == (getattrofunc)0x0) {
                                      pPVar11 = (PyObject *)PyObject_GetAttr();
                                    }
                                    else {
                                      pPVar11 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.
                                                                   __pyx_n_s_build_config);
                                    }
                                    if (pPVar11 == (PyObject *)0x0) {
                                      iVar8 = 0xcb0;
                                    }
                                    else {
                                      p_Var23 = pPVar10->ob_type;
                                      if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
                                         (p_Var27 = pPVar10[1].ob_type,
                                         p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                                        pPVar16 = (PyObject *)pPVar10[1].ob_refcnt;
                                        (p_Var27->ob_base).ob_base.ob_refcnt =
                                             (p_Var27->ob_base).ob_base.ob_refcnt + 1;
                                        pPVar16->ob_refcnt = pPVar16->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                        lVar28 = pPVar10->ob_refcnt + -1;
                                        pPVar10->ob_refcnt = lVar28;
                                        if (lVar28 == 0) {
                                          (*p_Var23->tp_dealloc)(pPVar10);
                                        }
                                        __pyx_pyargnames[0] = (PyObject **)p_Var27;
                                        __pyx_pyargnames[1] = (PyObject **)pPVar11;
                                        pPVar25 = __Pyx_PyObject_FastCallDict
                                                            (pPVar16,(PyObject **)__pyx_pyargnames,2
                                                             ,pPVar18);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                        lVar28 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
                                        (p_Var27->ob_base).ob_base.ob_refcnt = lVar28;
                                        pPVar10 = pPVar16;
                                        if (lVar28 == 0) {
                                          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)
                                                    ((PyObject *)p_Var27);
                                        }
                                      }
                                      else {
                                        __pyx_pyargnames[0] = (PyObject **)0x0;
                                        __pyx_pyargnames[1] = (PyObject **)pPVar11;
                                        pPVar25 = __Pyx_PyObject_FastCallDict
                                                            (pPVar10,(PyObject **)
                                                                     (__pyx_pyargnames + 1),1,
                                                             pPVar18);
                                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                      lVar28 = pPVar11->ob_refcnt + -1;
                                      pPVar11->ob_refcnt = lVar28;
                                      if (lVar28 == 0) {
                                        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                                      }
                                      if (pPVar25 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                        lVar28 = pPVar10->ob_refcnt + -1;
                                        pPVar10->ob_refcnt = lVar28;
                                        if (lVar28 == 0) {
                                          (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                                        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                        lVar28 = pPVar25->ob_refcnt + -1;
                                        pPVar25->ob_refcnt = lVar28;
                                        if (lVar28 == 0) {
                                          (*pPVar25->ob_type->tp_dealloc)(pPVar25);
                                        }
                                        pPVar11 = (PyObject *)PTR__Py_NoneStruct_00123f60;
                                        *(long *)PTR__Py_NoneStruct_00123f60 =
                                             *(long *)PTR__Py_NoneStruct_00123f60 + 1;
                                        goto LAB_0010ef4c;
                                      }
                                      iVar8 = 0xcc5;
                                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                    py_line = 0x17;
                                    lVar28 = pPVar10->ob_refcnt + -1;
                                    pPVar10->ob_refcnt = lVar28;
                                    if (lVar28 == 0) {
                                      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                                    }
                                  }
                                  goto LAB_0010f1d0;
                                }
                                py_line = 0x16;
                                iVar8 = 0xc9e;
                              }
LAB_0010f2e8:
                              lVar28 = pPVar16->ob_refcnt + -1;
                            }
LAB_0010f2f0:
                            pPVar16->ob_refcnt = lVar28;
                            goto joined_r0x0010f24c;
                          }
                          py_line = 0x16;
                          iVar8 = 0xc81;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_0010f1d0:
    __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU.__init__",iVar8,py_line,"buttons_irq.py");
    pPVar11 = (PyObject *)0x0;
    goto LAB_0010ef4c;
  }
  kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  if (__pyx_nargs == 2) {
LAB_0010e470:
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    lVar28 = __pyx_kwds[1].ob_refcnt;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs < 2) {
        if (__pyx_nargs == 0) goto LAB_0010eeb4;
      }
      else {
        lVar29 = lVar28;
        if (__pyx_nargs == 2) goto LAB_0010e628;
        if (__pyx_nargs == 3) goto LAB_0010e4a4;
      }
      goto LAB_0010e7a0;
    }
LAB_0010e604:
    values[1] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_printer);
    lVar29 = lVar28;
joined_r0x0010eeec:
    if (values[1] != (PyObject *)0x0) {
      lVar28 = __pyx_kwds[1].ob_refcnt;
      lVar29 = lVar29 + -1;
LAB_0010e628:
      pPVar11 = __pyx_mstate_global_static.__pyx_n_s_mcu;
      puVar5 = PTR_PyUnicode_Type_00123fb8;
      puVar4 = PTR__Py_TrueStruct_00123f68;
      puVar3 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar28) {
        p_Var23 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_mcu == p_Var23) {
          values[2] = *kwvalues;
        }
        else {
          lVar9 = 0;
          do {
            lVar26 = lVar9 + 1;
            if (lVar26 == lVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar9 = 0;
              goto LAB_0010e688;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar9;
            lVar9 = lVar26;
          } while (__pyx_mstate_global_static.__pyx_n_s_mcu != (PyObject *)*pPVar1);
          values[2] = kwvalues[lVar26];
        }
        goto LAB_0010efcc;
      }
LAB_0010f168:
      values[2] = (PyObject *)0x0;
      goto LAB_0010f16c;
    }
    lVar28 = PyErr_Occurred();
    if (lVar28 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                   "exactly",4,"s",1);
      iVar8 = 0xb95;
    }
    else {
      iVar8 = 0xb93;
    }
  }
  else if (__pyx_nargs < 3) {
    if (__pyx_nargs != 0) {
      if (__pyx_nargs != 1) goto LAB_0010eef4;
      lVar28 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0010e604;
    }
    lVar28 = __pyx_kwds[1].ob_refcnt;
LAB_0010eeb4:
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      values[1] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_printer);
      lVar29 = lVar28 + -1;
      goto joined_r0x0010eeec;
    }
    lVar28 = PyErr_Occurred();
    if (lVar28 == 0) goto LAB_0010eef4;
    iVar8 = 0xb8b;
  }
  else {
    if (__pyx_nargs == 3) {
LAB_0010e468:
      values[2] = __pyx_args[2];
      goto LAB_0010e470;
    }
    if (__pyx_nargs == 4) {
      values[3] = __pyx_args[3];
      goto LAB_0010e468;
    }
LAB_0010eef4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 4,"s",__pyx_nargs);
    iVar8 = 0xbbf;
  }
  goto LAB_0010ef30;
  while( true ) {
    lVar26 = lVar9 + 1;
    if (lVar26 == lVar28) goto LAB_0010f168;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar9];
    lVar9 = lVar26;
    if ((_typeobject *)pPVar11 == p_Var23) break;
LAB_0010e688:
    bVar6 = pPVar11->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar26 = lVar9;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar11 != (PyObject *)puVar3) && (bVar6 || p_Var23 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar11,p_Var23,2);
        if (plVar12 == (long *)0x0) goto LAB_0010f168;
        uVar20 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar12 != (long *)puVar3) {
          uVar20 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = *plVar12;
        *plVar12 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0010f158:
        if (uVar20 != 0) {
          if ((int)uVar20 < 0) goto LAB_0010f168;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar11[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar11), iVar8 < 0)) ||
         ((-1 < (char)p_Var23->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var23), iVar8 < 0))))
      goto LAB_0010f168;
      lVar14 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar14 == (p_Var23->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar19 = (ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7;
        uVar20 = (uint)uVar19;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar20) {
          bVar2 = (byte)pPVar11[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var27 = pPVar11[4].ob_type;
          }
          else {
            p_Var27 = (_typeobject *)&pPVar11[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var27 = (_typeobject *)(pPVar11 + 3);
            }
          }
          bVar2 = (byte)p_Var23->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var13 = (setattrfunc *)p_Var23->tp_setattr;
          }
          else {
            pp_Var13 = &p_Var23->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var13 = (setattrfunc *)&p_Var23->tp_dealloc;
            }
          }
          if (uVar20 == 1) {
            uVar20 = (uint)(byte)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var13;
          }
          else if (uVar20 == 2) {
            uVar20 = (uint)(ushort)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var13;
          }
          else {
            uVar20 = (uint)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var13;
          }
          if (uVar22 == uVar20) {
            if (lVar14 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var27,pp_Var13,uVar19 * lVar14);
              uVar20 = (uint)(iVar8 == 0);
              goto LAB_0010f158;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar26];
  function_name = (PyObject **)puVar3;
LAB_0010efcc:
  if (values[2] == (PyObject *)0x0) {
LAB_0010f16c:
    lVar28 = PyErr_Occurred();
    if (lVar28 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__",
                   "exactly",4,"s",2);
      iVar8 = 0xb9f;
    }
    else {
      iVar8 = 0xb9d;
    }
    goto LAB_0010ef30;
  }
  lVar29 = lVar29 + -1;
  lVar28 = __pyx_kwds[1].ob_refcnt;
LAB_0010e4a4:
  pPVar11 = __pyx_mstate_global_static.__pyx_n_s_debounce_us;
  puVar5 = PTR_PyUnicode_Type_00123fb8;
  puVar4 = PTR__Py_TrueStruct_00123f68;
  puVar3 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
  if (0 < lVar28) {
    p_Var23 = __pyx_kwds[1].ob_type;
    if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_debounce_us == p_Var23) {
      values[3] = *kwvalues;
    }
    else {
      lVar9 = 0;
      do {
        lVar26 = lVar9 + 1;
        if (lVar26 == lVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
          lVar9 = 0;
          goto LAB_0010e508;
        }
        pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar9;
        lVar9 = lVar26;
      } while (__pyx_mstate_global_static.__pyx_n_s_debounce_us != (PyObject *)*pPVar1);
      values[3] = kwvalues[lVar26];
    }
    goto LAB_0010e794;
  }
LAB_0010f080:
  values[3] = (PyObject *)0x0;
LAB_0010f084:
  lVar28 = PyErr_Occurred();
  if (lVar28 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 4,"s",3);
    iVar8 = 0xba9;
  }
  else {
    iVar8 = 0xba7;
  }
  goto LAB_0010ef30;
  while( true ) {
    lVar26 = lVar9 + 1;
    if (lVar26 == lVar28) goto LAB_0010f080;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar9];
    lVar9 = lVar26;
    if ((_typeobject *)pPVar11 == p_Var23) break;
LAB_0010e508:
    bVar6 = pPVar11->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar26 = lVar9;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar11 != (PyObject *)puVar3) && (bVar6 || p_Var23 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar11,p_Var23,2);
        if (plVar12 == (long *)0x0) goto LAB_0010f080;
        uVar20 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar12 != (long *)puVar3) {
          uVar20 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = *plVar12;
        *plVar12 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0010f074:
        if (uVar20 != 0) {
          if ((int)uVar20 < 0) goto LAB_0010f080;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar11[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar11), iVar8 < 0)) ||
         ((-1 < (char)p_Var23->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var23), iVar8 < 0))))
      goto LAB_0010f080;
      lVar14 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar14 == (p_Var23->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar19 = (ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7;
        uVar20 = (uint)uVar19;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar20) {
          bVar2 = (byte)pPVar11[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var27 = pPVar11[4].ob_type;
          }
          else {
            p_Var27 = (_typeobject *)&pPVar11[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var27 = (_typeobject *)(pPVar11 + 3);
            }
          }
          bVar2 = (byte)p_Var23->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var13 = (setattrfunc *)p_Var23->tp_setattr;
          }
          else {
            pp_Var13 = &p_Var23->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var13 = (setattrfunc *)&p_Var23->tp_dealloc;
            }
          }
          if (uVar20 == 1) {
            uVar20 = (uint)(byte)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var13;
          }
          else if (uVar20 == 2) {
            uVar20 = (uint)(ushort)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var13;
          }
          else {
            uVar20 = (uint)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var13;
          }
          if (uVar22 == uVar20) {
            if (lVar14 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var27,pp_Var13,uVar19 * lVar14);
              uVar20 = (uint)(iVar8 == 0);
              goto LAB_0010f074;
            }
            break;
          }
        }
      }
    }
  }
  values[3] = kwvalues[lVar26];
  function_name = (PyObject **)puVar3;
LAB_0010e794:
  if (values[3] == (PyObject *)0x0) goto LAB_0010f084;
  lVar28 = lVar29 + -1;
LAB_0010e7a0:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
  if ((lVar28 < 1) ||
     (iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                         (PyObject **)__pyx_nargs,0x112590,(char *)function_name), -1 < iVar8))
  goto LAB_0010e7b0;
  iVar8 = 0xbae;
LAB_0010ef30:
  __Pyx_AddTraceback("extras.buttons_irq._IRQButtonMCU.__init__",iVar8,10,"buttons_irq.py");
  pPVar11 = (PyObject *)0x0;
LAB_0010ef4c:
  if (lVar21 == *(long *)PTR___stack_chk_guard_00123f40) {
    return pPVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010f698
 * Symbol:  __pyx_pw_6extras_11buttons_irq_14MCU_irq_button_3register_buttons
 * Signature: PyObject * __pyx_pw_6extras_11buttons_irq_14MCU_irq_button_3register_buttons(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_11buttons_irq_14MCU_irq_button_3register_buttons
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  PyObject *pPVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  PyObject *pPVar13;
  PyObject *pPVar14;
  PyObject *pPVar15;
  PyObject *obj;
  PyObject *pPVar16;
  PyObject *func;
  long lVar17;
  long *plVar18;
  long *plVar19;
  setattrfunc *pp_Var20;
  long lVar21;
  getattrofunc p_Var22;
  __pyx_mstate *kwargs;
  PyObject **ppPVar23;
  PyObject **ppPVar24;
  PyObject *pPVar25;
  PyObject *pPVar26;
  long lVar27;
  PyObject *pPVar28;
  _typeobject *p_Var29;
  ternaryfunc p_Var30;
  _typeobject *p_Var31;
  long lVar32;
  PyObject *pPVar33;
  _typeobject *p_Var34;
  PyObject *pPVar35;
  long lVar36;
  int iVar37;
  PyObject *local_98;
  PyObject *local_90;
  PyObject *local_88;
  iternextfunc local_70;
  PyObject **local_58;
  PyObject *values [4];
  PyObject **__pyx_pyargnames [5];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_pins@[???]
                       Unresolved local var: PyObject * __pyx_v_callback@[???]
                       Unresolved local var: PyObject * __pyx_v_debounce_us@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar27 = *(long *)PTR___stack_chk_guard_00123f40;
  ppPVar24 = &__pyx_mstate_global_static.__pyx_n_s_self;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  values[3] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_pins;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_callback;
  __pyx_pyargnames[3] = &__pyx_mstate_global_static.__pyx_n_s_debounce_us;
  __pyx_pyargnames[4] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    if (__pyx_nargs == 2) {
LAB_0010f738:
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar36 = __pyx_kwds[1].ob_refcnt;
      if (__pyx_nargs != 1) {
        if (__pyx_nargs < 2) {
          if (__pyx_nargs == 0) goto LAB_0010ffb8;
        }
        else {
          lVar17 = lVar36;
          if (__pyx_nargs == 2) goto LAB_0010f8f8;
          if (__pyx_nargs == 3) goto LAB_0010f76c;
        }
        goto LAB_0010fa84;
      }
LAB_0010f8d4:
      values[1] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_pins);
      lVar17 = lVar36;
joined_r0x0010fff0:
      if (values[1] != (PyObject *)0x0) {
        lVar36 = __pyx_kwds[1].ob_refcnt;
        lVar17 = lVar17 + -1;
LAB_0010f8f8:
        pPVar28 = __pyx_mstate_global_static.__pyx_n_s_callback;
        puVar6 = PTR_PyUnicode_Type_00123fb8;
        puVar5 = PTR__Py_TrueStruct_00123f68;
        puVar4 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
        if (0 < lVar36) {
          p_Var31 = __pyx_kwds[1].ob_type;
          if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_callback == p_Var31) {
            values[2] = *kwvalues;
          }
          else {
            lVar12 = 0;
            do {
              lVar32 = lVar12 + 1;
              if (lVar36 == lVar32) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
                lVar36 = 0;
                goto LAB_0010f970;
              }
              pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar12;
              lVar12 = lVar32;
            } while (__pyx_mstate_global_static.__pyx_n_s_callback != (PyObject *)*pPVar1);
            values[2] = kwvalues[lVar32];
          }
          goto LAB_00110158;
        }
LAB_001102e0:
        values[2] = (PyObject *)0x0;
        goto LAB_001102e4;
      }
      lVar36 = PyErr_Occurred();
      if (lVar36 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                     "%.200s() takes %.8s %zd positional argument%.1s (%zd given)",
                     "register_buttons","exactly",4,"s",1);
        iVar10 = 0x1480;
      }
      else {
        iVar10 = 0x147e;
      }
    }
    else if (__pyx_nargs < 3) {
      if (__pyx_nargs != 0) {
        if (__pyx_nargs != 1) goto LAB_0010fff8;
        lVar36 = __pyx_kwds[1].ob_refcnt;
        values[0] = *__pyx_args;
        goto LAB_0010f8d4;
      }
      lVar36 = __pyx_kwds[1].ob_refcnt;
LAB_0010ffb8:
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
      if (values[0] != (PyObject *)0x0) {
        values[1] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_pins);
        lVar17 = lVar36 + -1;
        goto joined_r0x0010fff0;
      }
      lVar36 = PyErr_Occurred();
      if (lVar36 == 0) goto LAB_0010fff8;
      iVar10 = 0x1476;
    }
    else {
      if (__pyx_nargs == 3) {
LAB_0010f730:
        values[2] = __pyx_args[2];
        goto LAB_0010f738;
      }
      if (__pyx_nargs == 4) {
        values[3] = __pyx_args[3];
        goto LAB_0010f730;
      }
LAB_0010fff8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","register_buttons",
                   "exactly",4,"s",__pyx_nargs);
      iVar10 = 0x14aa;
    }
    goto LAB_00110034;
  }
  if (__pyx_nargs != 4) goto LAB_0010fff8;
  values[2] = __pyx_args[2];
  values[3] = __pyx_args[3];
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0010fa98:
                    /* Unresolved local var: PyObject * __pyx_v_ppins@[???]
                       Unresolved local var: PyObject * __pyx_v_mcu@[???]
                       Unresolved local var: PyObject * __pyx_v_mcu_name@[???]
                       Unresolved local var: PyObject * __pyx_v_pin_params_list@[???]
                       Unresolved local var: PyObject * __pyx_v_pin@[???]
                       Unresolved local var: PyObject * __pyx_v_pin_params@[???]
                       Unresolved local var: PyObject * __pyx_v_mcu_button@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_5@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: PyObject * __pyx_t_8@[???]
                       Unresolved local var: int __pyx_t_9@[???]
                       Unresolved local var: int __pyx_t_10@[???]
                       Unresolved local var: int __pyx_t_11@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_12@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyTypeObject * tp@[???] */
  pPVar7 = values[3];
  pPVar26 = values[2];
  pPVar25 = values[1];
  pPVar28 = values[0];
  p_Var22 = values[0]->ob_type->tp_getattro;
  if (p_Var22 == (getattrofunc)0x0) {
    pPVar13 = (PyObject *)PyObject_GetAttr(values[0]);
  }
  else {
    pPVar13 = (*p_Var22)(values[0],__pyx_mstate_global_static.__pyx_n_s_printer);
  }
  if (pPVar13 == (PyObject *)0x0) {
    iVar37 = 0x46;
    pPVar16 = (PyObject *)0x0;
    pPVar35 = (PyObject *)0x0;
    p_Var31 = (_typeobject *)0x0;
    pPVar33 = (PyObject *)0x0;
    pPVar15 = (PyObject *)0x0;
    iVar10 = 0x14e7;
    local_98 = (PyObject *)0x0;
    local_90 = (PyObject *)0x0;
  }
  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var22 = pPVar13->ob_type->tp_getattro;
    if (p_Var22 == (getattrofunc)0x0) {
      pPVar14 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar14 = (*p_Var22)(pPVar13,__pyx_mstate_global_static.__pyx_n_s_lookup_object);
    }
    lVar36 = pPVar13->ob_refcnt + -1;
    if (pPVar14 == (PyObject *)0x0) {
      pPVar16 = (PyObject *)0x0;
      pPVar35 = (PyObject *)0x0;
      p_Var31 = (_typeobject *)0x0;
      pPVar33 = (PyObject *)0x0;
      pPVar15 = (PyObject *)0x0;
      func = (PyObject *)0x0;
      pPVar14 = (PyObject *)0x0;
      iVar37 = 0x46;
      iVar10 = 0x14e9;
      local_98 = (PyObject *)0x0;
      local_90 = (PyObject *)0x0;
      obj = (PyObject *)0x0;
      goto LAB_001108a4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar36;
    if (lVar36 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    p_Var31 = pPVar14->ob_type;
    if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
       (p_Var29 = pPVar14[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar13 = (PyObject *)pPVar14[1].ob_refcnt;
      (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
      pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar36;
      if (lVar36 == 0) {
        (*p_Var31->tp_dealloc)(pPVar14);
      }
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_pins;
      __pyx_pyargnames[0] = (PyObject **)p_Var29;
      pPVar15 = __Pyx_PyObject_FastCallDict
                          (pPVar13,(PyObject **)__pyx_pyargnames,2,
                           __pyx_mstate_global_static.__pyx_n_s_pins);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar36;
      pPVar14 = pPVar13;
      if (lVar36 == 0) {
        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_pins;
      pPVar15 = __Pyx_PyObject_FastCallDict
                          (pPVar14,(PyObject **)(__pyx_pyargnames + 1),1,
                           __pyx_mstate_global_static.__pyx_n_s_pins);
    }
    local_58 = (PyObject **)__pyx_pyargnames;
    if (pPVar15 == (PyObject *)0x0) {
      pPVar16 = (PyObject *)0x0;
      pPVar35 = (PyObject *)0x0;
      p_Var31 = (_typeobject *)0x0;
      pPVar33 = (PyObject *)0x0;
      func = (PyObject *)0x0;
      obj = (PyObject *)0x0;
      iVar37 = 0x46;
      iVar10 = 0x14fe;
      local_98 = (PyObject *)0x0;
      local_90 = (PyObject *)0x0;
      goto LAB_001108c4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar36 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar36;
    if (lVar36 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    pPVar33 = (PyObject *)PTR__Py_NoneStruct_00123f60;
    local_98 = (PyObject *)PTR__Py_NoneStruct_00123f60;
    *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 2;
    local_90 = (PyObject *)PyList_New(0);
    if (local_90 != (PyObject *)0x0) {
      if (pPVar25->ob_type == (_typeobject *)PTR_PyTuple_Type_00123ef8 ||
          pPVar25->ob_type == (_typeobject *)PTR_PyList_Type_00123fe0) {
        local_88 = (PyObject *)0x0;
        local_70 = (iternextfunc)0x0;
        pPVar25->ob_refcnt = pPVar25->ob_refcnt + 1;
      }
      else {
        pPVar25 = (PyObject *)PyObject_GetIter(pPVar25);
        if (pPVar25 == (PyObject *)0x0) {
          pPVar16 = (PyObject *)0x0;
          pPVar35 = (PyObject *)0x0;
          p_Var31 = (_typeobject *)0x0;
          iVar37 = 0x4a;
          iVar10 = 0x1529;
          goto LAB_001103a0;
        }
        local_70 = pPVar25->ob_type->tp_iternext;
        if (local_70 == (iternextfunc)0x0) {
          iVar10 = 0x152b;
          iVar37 = 0x4a;
          func = (PyObject *)0x0;
          obj = (PyObject *)0x0;
          pPVar14 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          pPVar35 = (PyObject *)0x0;
          p_Var31 = (_typeobject *)0x0;
          pPVar13 = (PyObject *)0x0;
          goto LAB_00110870;
        }
        local_88 = (PyObject *)0xffffffffffffffff;
      }
      puVar6 = PTR_PyList_Type_00123fe0;
      puVar5 = PTR__Py_TrueStruct_00123f68;
      puVar4 = PTR__Py_CheckRecursionLimit_00123f20;
      local_98 = (PyObject *)PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
      p_Var31 = (_typeobject *)0x0;
      pPVar33 = (PyObject *)PTR__Py_NoneStruct_00123f60;
      pPVar35 = (PyObject *)0x0;
LAB_0010fc54:
      if (local_70 == (iternextfunc)0x0) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
        if (pPVar25->ob_type == (_typeobject *)puVar6) {
          if (pPVar25[1].ob_refcnt <= (long)local_88) goto LAB_0011051c;
          p_Var29 = (_typeobject *)
                    (&((pPVar25[1].ob_type)->ob_base).ob_base.ob_refcnt)[(long)local_88];
        }
        else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
          if (pPVar25[1].ob_refcnt <= (long)local_88) goto LAB_0011051c;
          p_Var29 = (&pPVar25[1].ob_type)[(long)local_88];
        }
        local_88 = (PyObject *)((long)local_88 + 1);
        (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
      }
      else {
        p_Var29 = (_typeobject *)(*local_70)(pPVar25);
        if (p_Var29 == (_typeobject *)0x0) {
                    /* Unresolved local var: PyObject * exc_type@[???] */
          pPVar13 = (PyObject *)PyErr_Occurred();
          if (pPVar13 != (PyObject *)0x0) {
            if ((pPVar13 == *(PyObject **)PTR_PyExc_StopIteration_00123fa8) ||
               (iVar10 = __Pyx_PyErr_GivenExceptionMatches
                                   (pPVar13,*(PyObject **)PTR_PyExc_StopIteration_00123fa8),
               iVar10 != 0)) {
              PyErr_Clear();
              goto LAB_0011051c;
            }
            func = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            pPVar14 = (PyObject *)0x0;
            pPVar13 = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
            iVar10 = 0x1552;
            iVar37 = 0x4a;
            goto LAB_00110870;
          }
LAB_0011051c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = pPVar25->ob_refcnt + -1;
          pPVar25->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*pPVar25->ob_type->tp_dealloc)(pPVar25);
          }
          obj = __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_irq_buttons);
          if (obj == (PyObject *)0x0) {
            pPVar16 = (PyObject *)0x0;
            iVar37 = 0x52;
            iVar10 = 0x15ea;
            goto LAB_001103a0;
          }
          func = __Pyx_PyObject_GetAttrStr(obj,__pyx_mstate_global_static.__pyx_n_s_get);
          if (func == (PyObject *)0x0) {
            pPVar16 = (PyObject *)0x0;
            func = (PyObject *)0x0;
            iVar37 = 0x52;
            iVar10 = 0x15ec;
            goto LAB_001108f0;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = obj->ob_refcnt + -1;
          obj->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*obj->ob_type->tp_dealloc)(obj);
          }
          p_Var29 = func->ob_type;
          if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
             (p_Var34 = func[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar25 = (PyObject *)func[1].ob_refcnt;
            (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
            pPVar25->ob_refcnt = pPVar25->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = func->ob_refcnt + -1;
            func->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*p_Var29->tp_dealloc)(func);
            }
            __pyx_pyargnames[1] = (PyObject **)local_98;
            __pyx_pyargnames[0] = (PyObject **)p_Var34;
            pPVar16 = __Pyx_PyObject_FastCallDict(pPVar25,local_58,2,local_98);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
            (p_Var34->ob_base).ob_base.ob_refcnt = lVar36;
            func = pPVar25;
            if (lVar36 == 0) {
              (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)local_98;
            pPVar16 = __Pyx_PyObject_FastCallDict
                                (func,(PyObject **)(__pyx_pyargnames + 1),1,local_98);
          }
          if (pPVar16 == (PyObject *)0x0) {
            iVar37 = 0x52;
            iVar10 = 0x1601;
            goto LAB_0011091c;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = func->ob_refcnt + -1;
          func->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*func->ob_type->tp_dealloc)(func);
          }
          if (pPVar16 == (PyObject *)PTR__Py_NoneStruct_00123f60) {
LAB_00110f40:
            func = __pyx_dict_cached_value_16835;
            if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16834) {
              if (__pyx_dict_cached_value_16835 == (PyObject *)0x0) {
                func = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
                goto LAB_00111438;
              }
              __pyx_dict_cached_value_16835->ob_refcnt =
                   __pyx_dict_cached_value_16835->ob_refcnt + 1;
            }
            else {
              func = __Pyx__GetModuleGlobalName
                               (__pyx_mstate_global_static.__pyx_n_s_logging,
                                (uint64_t *)&__pyx_dict_version_16834,&__pyx_dict_cached_value_16835
                               );
LAB_00111438:
              if (func == (PyObject *)0x0) {
                iVar37 = 0x55;
                iVar10 = 0x1636;
                goto LAB_001103a0;
              }
            }
            obj = __Pyx_PyObject_GetAttrStr(func,__pyx_mstate_global_static.__pyx_n_s_warning);
            if (obj == (PyObject *)0x0) {
              iVar37 = 0x55;
              iVar10 = 0x1638;
              goto LAB_0011091c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = func->ob_refcnt + -1;
            func->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*func->ob_type->tp_dealloc)(func);
            }
            if (local_90[1].ob_refcnt == -1) {
              iVar37 = 0x57;
              iVar10 = 0x1643;
              func = (PyObject *)0x0;
              goto LAB_001108f0;
            }
            ppPVar24 = (PyObject **)PyLong_FromSsize_t();
            if (ppPVar24 == (PyObject **)0x0) {
              func = (PyObject *)0x0;
              iVar37 = 0x57;
              iVar10 = 0x1644;
              goto LAB_001108f0;
            }
            p_Var29 = obj->ob_type;
            if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
               (p_Var34 = obj[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar25 = (PyObject *)obj[1].ob_refcnt;
              (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
              pPVar25->ob_refcnt = pPVar25->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = obj->ob_refcnt + -1;
              obj->ob_refcnt = lVar36;
              if (lVar36 == 0) {
                (*p_Var29->tp_dealloc)(obj);
              }
              __pyx_pyargnames[1] =
                   (PyObject **)
                   __pyx_mstate_global_static.__pyx_kp_s_Creating_new_IRQ_button_object_f;
              __pyx_pyargnames[2] = (PyObject **)local_98;
              __pyx_pyargnames[0] = (PyObject **)p_Var34;
              __pyx_pyargnames[3] = ppPVar24;
              pPVar13 = __Pyx_PyObject_FastCallDict
                                  (pPVar25,local_58,4,
                                   __pyx_mstate_global_static.
                                   __pyx_kp_s_Creating_new_IRQ_button_object_f);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
              (p_Var34->ob_base).ob_base.ob_refcnt = lVar36;
              if (lVar36 == 0) {
                (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] =
                   (PyObject **)
                   __pyx_mstate_global_static.__pyx_kp_s_Creating_new_IRQ_button_object_f;
              __pyx_pyargnames[2] = (PyObject **)local_98;
              __pyx_pyargnames[3] = ppPVar24;
              pPVar13 = __Pyx_PyObject_FastCallDict
                                  (obj,(PyObject **)(__pyx_pyargnames + 1),3,
                                   __pyx_mstate_global_static.
                                   __pyx_kp_s_Creating_new_IRQ_button_object_f);
              pPVar25 = obj;
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar14 = (PyObject *)((long)&(*ppPVar24)[-1].ob_type + 7);
            *ppPVar24 = pPVar14;
            if (pPVar14 == (PyObject *)0x0) {
              (*(code *)ppPVar24[1][3].ob_refcnt)(ppPVar24);
            }
            if (pPVar13 == (PyObject *)0x0) {
              iVar37 = 0x55;
              iVar10 = 0x1659;
              func = (PyObject *)0x0;
              obj = pPVar25;
              goto LAB_001108f0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar25->ob_refcnt + -1;
            pPVar25->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar25->ob_type->tp_dealloc)(pPVar25);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar13->ob_refcnt + -1;
            pPVar13->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
            }
            obj = __pyx_dict_cached_value_16847;
            kwargs = &__pyx_mstate_global_static;
            if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16846) {
              if (__pyx_dict_cached_value_16847 == (PyObject *)0x0) {
                obj = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU);
                goto LAB_001115bc;
              }
              __pyx_dict_cached_value_16847->ob_refcnt =
                   __pyx_dict_cached_value_16847->ob_refcnt + 1;
            }
            else {
              obj = __Pyx__GetModuleGlobalName
                              (__pyx_mstate_global_static.__pyx_n_s_IRQButtonMCU,
                               (uint64_t *)&__pyx_dict_version_16846,&__pyx_dict_cached_value_16847)
              ;
LAB_001115bc:
              if (obj == (PyObject *)0x0) {
                iVar37 = 0x58;
                iVar10 = 0x1666;
                goto LAB_001103a0;
              }
            }
            pPVar25 = __Pyx_PyObject_GetAttrStr
                                (pPVar28,__pyx_mstate_global_static.__pyx_n_s_printer);
            if (pPVar25 == (PyObject *)0x0) {
              iVar37 = 0x58;
              iVar10 = 0x1668;
              func = (PyObject *)0x0;
              goto LAB_001108f0;
            }
            p_Var29 = obj->ob_type;
            if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
               (p_Var34 = obj[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar14 = (PyObject *)obj[1].ob_refcnt;
              (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
              pPVar14->ob_refcnt = pPVar14->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = obj->ob_refcnt + -1;
              obj->ob_refcnt = lVar36;
              if (lVar36 == 0) {
                (*p_Var29->tp_dealloc)(obj);
              }
              __pyx_pyargnames[0] = (PyObject **)p_Var34;
              __pyx_pyargnames[1] = (PyObject **)pPVar25;
              __pyx_pyargnames[2] = (PyObject **)pPVar33;
              __pyx_pyargnames[3] = (PyObject **)pPVar7;
              pPVar13 = __Pyx_PyObject_FastCallDict(pPVar14,local_58,4,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar36 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
              (p_Var34->ob_base).ob_base.ob_refcnt = lVar36;
              if (lVar36 == 0) {
                (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = (PyObject **)pPVar25;
              __pyx_pyargnames[2] = (PyObject **)pPVar33;
              __pyx_pyargnames[3] = (PyObject **)pPVar7;
              pPVar13 = __Pyx_PyObject_FastCallDict
                                  (obj,(PyObject **)(__pyx_pyargnames + 1),3,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
              pPVar14 = obj;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar25->ob_refcnt + -1;
            pPVar25->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar25->ob_type->tp_dealloc)(pPVar25);
            }
            if (pPVar13 == (PyObject *)0x0) {
              func = (PyObject *)0x0;
              iVar37 = 0x58;
              iVar10 = 0x167d;
              obj = pPVar14;
              goto LAB_001108f0;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar14->ob_refcnt + -1;
            pPVar14->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar14->ob_type->tp_dealloc)(pPVar14);
            }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar16->ob_refcnt + -1;
            pPVar16->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar16->ob_type->tp_dealloc)(pPVar16);
            }
            pPVar25 = __Pyx_PyObject_GetAttrStr
                                (pPVar28,__pyx_mstate_global_static.__pyx_n_s_irq_buttons);
            pPVar16 = pPVar13;
            if (pPVar25 == (PyObject *)0x0) {
              iVar37 = 0x59;
              iVar10 = 0x168b;
              goto LAB_001103a0;
            }
            iVar10 = PyObject_SetItem(pPVar25,local_98,pPVar13);
            if (iVar10 < 0) {
              iVar10 = 0x168d;
              iVar37 = 0x59;
              func = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar14 = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              goto LAB_00110870;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = pPVar25->ob_refcnt + -1;
            pPVar25->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*pPVar25->ob_type->tp_dealloc)(pPVar25);
            }
          }
          else {
            pPVar25 = __Pyx_PyObject_GetAttrStr
                                (pPVar16,__pyx_mstate_global_static.__pyx_n_s_pin_list);
            if (pPVar25 == (PyObject *)0x0) {
              iVar37 = 0x54;
              iVar10 = 0x161d;
              goto LAB_001103a0;
            }
            lVar36 = PyObject_Size();
            if (lVar36 == -1) {
              iVar10 = 0x161f;
              iVar37 = 0x54;
              func = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar14 = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              goto LAB_00110870;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar17 = pPVar25->ob_refcnt + -1;
            pPVar25->ob_refcnt = lVar17;
            if (lVar17 == 0) {
              (*pPVar25->ob_type->tp_dealloc)(pPVar25);
            }
            if (local_90[1].ob_refcnt == -1) {
              iVar37 = 0x54;
              iVar10 = 0x1621;
              goto LAB_001103a0;
            }
            pPVar13 = pPVar16;
            if (8 < lVar36 + local_90[1].ob_refcnt) goto LAB_00110f40;
          }
          obj = __Pyx_PyObject_GetAttrStr
                          (pPVar13,__pyx_mstate_global_static.__pyx_n_s_setup_buttons);
          pPVar16 = pPVar13;
          if (obj == (PyObject *)0x0) {
            iVar37 = 0x5b;
            iVar10 = 0x16a0;
            goto LAB_001103a0;
          }
          p_Var29 = obj->ob_type;
          if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
             (p_Var34 = obj[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar25 = (PyObject *)obj[1].ob_refcnt;
            (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
            pPVar25->ob_refcnt = pPVar25->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = obj->ob_refcnt + -1;
            obj->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*p_Var29->tp_dealloc)(obj);
            }
            __pyx_pyargnames[0] = (PyObject **)p_Var34;
            __pyx_pyargnames[1] = (PyObject **)local_90;
            __pyx_pyargnames[2] = (PyObject **)pPVar26;
            pPVar28 = __Pyx_PyObject_FastCallDict(pPVar25,local_58,3,local_90);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
            (p_Var34->ob_base).ob_base.ob_refcnt = lVar36;
            obj = pPVar25;
            if (lVar36 == 0) {
              (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)local_90;
            __pyx_pyargnames[2] = (PyObject **)pPVar26;
            pPVar28 = __Pyx_PyObject_FastCallDict
                                (obj,(PyObject **)(__pyx_pyargnames + 1),2,local_90);
          }
          iVar37 = 0x5b;
          iVar10 = 0x16b4;
          func = (PyObject *)0x0;
          if (pPVar28 == (PyObject *)0x0) goto LAB_001108f0;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = obj->ob_refcnt + -1;
          obj->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*obj->ob_type->tp_dealloc)(obj);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = pPVar28->ob_refcnt + -1;
          pPVar28->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*pPVar28->ob_type->tp_dealloc)(pPVar28);
          }
          pPVar28 = (PyObject *)PTR__Py_NoneStruct_00123f60;
          *(long *)PTR__Py_NoneStruct_00123f60 = *(long *)PTR__Py_NoneStruct_00123f60 + 1;
          goto LAB_001103c4;
        }
      }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((p_Var31 != (_typeobject *)0x0) &&
         (lVar36 = (p_Var31->ob_base).ob_base.ob_refcnt + -1,
         (p_Var31->ob_base).ob_base.ob_refcnt = lVar36, lVar36 == 0)) {
        (*((p_Var31->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var31);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var22 = pPVar15->ob_type->tp_getattro;
      if (p_Var22 == (getattrofunc)0x0) {
        pPVar14 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar14 = (*p_Var22)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_lookup_pin);
      }
      p_Var31 = p_Var29;
      if (pPVar14 == (PyObject *)0x0) {
        iVar37 = 0x4b;
        func = (PyObject *)0x0;
        obj = (PyObject *)0x0;
        pPVar13 = (PyObject *)0x0;
        iVar10 = 0x1562;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
      pPVar13 = (PyObject *)PyTuple_New(1);
      if (pPVar13 == (PyObject *)0x0) {
        func = (PyObject *)0x0;
        obj = (PyObject *)0x0;
        iVar10 = 0x1564;
        iVar37 = 0x4b;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
      (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
      pPVar13[1].ob_type = p_Var29;
      obj = (PyObject *)PyDict_New();
      if (obj == (PyObject *)0x0) {
        func = (PyObject *)0x0;
        iVar10 = 0x1569;
        iVar37 = 0x4b;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
      iVar10 = PyDict_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_can_invert,puVar5);
      if (iVar10 < 0) {
        iVar10 = 0x156b;
        iVar37 = 0x4b;
        func = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
      iVar10 = PyDict_SetItem(obj,__pyx_mstate_global_static.__pyx_n_s_can_pullup,puVar5);
      if (iVar10 < 0) {
        iVar10 = 0x156c;
        iVar37 = 0x4b;
        func = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
      p_Var30 = pPVar14->ob_type->tp_call;
      if (p_Var30 == (ternaryfunc)0x0) {
        pPVar16 = (PyObject *)PyObject_Call(pPVar14,pPVar13,obj);
        if (pPVar16 == (PyObject *)0x0) goto LAB_00110ae0;
      }
      else {
        lVar36 = PyThreadState_Get();
        iVar37 = *(int *)puVar4;
        iVar10 = *(int *)(lVar36 + 0x20) + 1;
        *(int *)(lVar36 + 0x20) = iVar10;
        if ((iVar37 < iVar10) &&
           (iVar10 = _Py_CheckRecursiveCall(" while calling a Python object"), iVar10 != 0)) {
          iVar10 = 0x156d;
          iVar37 = 0x4b;
          func = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          goto LAB_00110870;
        }
        pPVar16 = (*p_Var30)(pPVar14,pPVar13,obj);
        lVar36 = PyThreadState_Get();
        iVar3 = *(int *)(lVar36 + 0x20) + -1;
        *(int *)(lVar36 + 0x20) = iVar3;
        iVar37 = *(int *)PTR__Py_CheckRecursionLimit_00123f20;
        iVar10 = iVar37 + -0x32;
        if (iVar37 < 0xc9) {
          iVar10 = (iVar37 >> 2) * 3;
        }
        if (iVar3 < iVar10) {
          lVar36 = PyThreadState_Get();
          *(undefined1 *)(lVar36 + 0x24) = 0;
        }
        if (pPVar16 == (PyObject *)0x0) {
          lVar36 = PyErr_Occurred();
          if (lVar36 == 0) {
            iVar37 = 0x4b;
            iVar10 = 0x156d;
            PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00123ee0,
                            "NULL result without error in PyObject_Call");
            func = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
          }
          else {
LAB_00110ae0:
            func = (PyObject *)0x0;
            iVar10 = 0x156d;
            iVar37 = 0x4b;
            pPVar16 = (PyObject *)0x0;
          }
          goto LAB_00110870;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar36;
      if (lVar36 == 0) {
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar36;
      if (lVar36 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = obj->ob_refcnt + -1;
      obj->ob_refcnt = lVar36;
      if (lVar36 == 0) {
        (*obj->ob_type->tp_dealloc)(obj);
      }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar35 != (PyObject *)0x0) &&
         (lVar36 = pPVar35->ob_refcnt + -1, pPVar35->ob_refcnt = lVar36, lVar36 == 0)) {
        (*pPVar35->ob_type->tp_dealloc)(pPVar35);
      }
      p_Var29 = pPVar16->ob_type;
      pPVar35 = pPVar16;
      if (pPVar33 != (PyObject *)PTR__Py_NoneStruct_00123f60) {
        if (p_Var29 == (_typeobject *)PTR_PyDict_Type_00123f78) {
          func = __Pyx_PyDict_GetItem(pPVar16,__pyx_mstate_global_static.__pyx_n_s_chip);
        }
        else {
          func = (PyObject *)PyObject_GetItem();
        }
        if (func == (PyObject *)0x0) {
          obj = (PyObject *)0x0;
          pPVar14 = (PyObject *)0x0;
          pPVar13 = (PyObject *)0x0;
          iVar10 = 0x1582;
          iVar37 = 0x4c;
          pPVar16 = (PyObject *)0x0;
          goto LAB_00110870;
        }
        obj = (PyObject *)PyObject_RichCompare(func,pPVar33,3);
        if (obj == (PyObject *)0x0) {
          pPVar14 = (PyObject *)0x0;
          pPVar13 = (PyObject *)0x0;
          iVar10 = 0x1584;
          iVar37 = 0x4c;
          pPVar16 = (PyObject *)0x0;
          goto LAB_00110870;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = func->ob_refcnt + -1;
        func->ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*func->ob_type->tp_dealloc)(func);
        }
                    /* Unresolved local var: int is_true@[???] */
        uVar11 = (uint)(obj == (PyObject *)PTR__Py_TrueStruct_00123f68);
        if (((uVar11 == 0 && obj != (PyObject *)PTR__Py_FalseStruct_00123f30) &&
             obj != (PyObject *)PTR__Py_NoneStruct_00123f60) &&
           (uVar11 = PyObject_IsTrue(obj), (int)uVar11 < 0)) {
          iVar10 = 0x1586;
          iVar37 = 0x4c;
          func = (PyObject *)0x0;
          pPVar14 = (PyObject *)0x0;
          pPVar13 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          goto LAB_00110870;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar36 = obj->ob_refcnt + -1;
        obj->ob_refcnt = lVar36;
        if (lVar36 == 0) {
          (*obj->ob_type->tp_dealloc)(obj);
        }
        if (uVar11 != 0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var22 = pPVar15->ob_type->tp_getattro;
          if (p_Var22 == (getattrofunc)0x0) {
            func = (PyObject *)PyObject_GetAttr();
          }
          else {
            func = (*p_Var22)(pPVar15,__pyx_mstate_global_static.__pyx_n_s_error);
          }
          if (func == (PyObject *)0x0) {
            func = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            pPVar14 = (PyObject *)0x0;
            iVar10 = 0x1593;
            iVar37 = 0x4d;
            pPVar13 = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
            goto LAB_00110870;
          }
          p_Var29 = func->ob_type;
          if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ee8) &&
             (p_Var34 = func[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar26 = (PyObject *)func[1].ob_refcnt;
            (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
            pPVar26->ob_refcnt = pPVar26->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = func->ob_refcnt + -1;
            func->ob_refcnt = lVar36;
            if (lVar36 == 0) {
              (*p_Var29->tp_dealloc)(func);
            }
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_IRQ_button_pins_must_be_on_same;
            __pyx_pyargnames[0] = (PyObject **)p_Var34;
            pPVar28 = __Pyx_PyObject_FastCallDict
                                (pPVar26,local_58,2,
                                 __pyx_mstate_global_static.
                                 __pyx_kp_s_IRQ_button_pins_must_be_on_same);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar36 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
            (p_Var34->ob_base).ob_base.ob_refcnt = lVar36;
            func = pPVar26;
            if (lVar36 == 0) {
              (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] =
                 (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_IRQ_button_pins_must_be_on_same;
            pPVar28 = __Pyx_PyObject_FastCallDict
                                (func,(PyObject **)(__pyx_pyargnames + 1),1,
                                 __pyx_mstate_global_static.
                                 __pyx_kp_s_IRQ_button_pins_must_be_on_same);
          }
          if (pPVar28 == (PyObject *)0x0) {
            obj = (PyObject *)0x0;
            pPVar13 = (PyObject *)0x0;
            iVar10 = 0x15a7;
            iVar37 = 0x4d;
            pPVar14 = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
            goto LAB_00110870;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = func->ob_refcnt + -1;
          func->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            (*func->ob_type->tp_dealloc)(func);
          }
                    /* Unresolved local var: PyObject * owned_instance@[???] */
          uVar11 = (uint)pPVar28->ob_type->tp_flags;
          if ((uVar11 >> 0x1e & 1) == 0) {
            if (((int)uVar11 < 0) && (((uint)pPVar28[10].ob_type >> 0x1e & 1) != 0)) {
                    /* Unresolved local var: PyObject * instance_class@[???]
                       Unresolved local var: PyObject * args@[???] */
              plVar18 = (long *)PyTuple_New(0);
              if (plVar18 != (long *)0x0) {
                plVar19 = (long *)PyObject_Call(pPVar28,plVar18,0);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar36 = *plVar18;
                *plVar18 = lVar36 + -1;
                if (lVar36 + -1 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                if (plVar19 != (long *)0x0) {
                  if (((uint)*(undefined8 *)(plVar19[1] + 0xa8) >> 0x1e & 1) == 0) {
                    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                                 "calling %R should have returned an instance of BaseException, not %R"
                                 ,pPVar28);
                  }
                  else {
                    PyErr_SetObject(pPVar28,plVar19);
                  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar36 = *plVar19;
                  *plVar19 = lVar36 + -1;
                  if (lVar36 + -1 == 0) {
                    (**(code **)(plVar19[1] + 0x30))(plVar19);
                  }
                }
              }
            }
            else {
              PyErr_SetString(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                              "raise: exception class must be a subclass of BaseException");
            }
          }
          else {
            PyErr_SetObject(pPVar28->ob_type,pPVar28);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar36 = pPVar28->ob_refcnt + -1;
          pPVar28->ob_refcnt = lVar36;
          if (lVar36 == 0) {
            iVar37 = 0x4d;
            local_88 = (PyObject *)0x0;
            iVar10 = 0x15ad;
            obj = (PyObject *)0x0;
            pPVar13 = (PyObject *)0x0;
            pPVar14 = (PyObject *)0x0;
            (*pPVar28->ob_type->tp_dealloc)(pPVar28);
            func = local_88;
            pPVar16 = (PyObject *)0x0;
            goto LAB_00110870;
          }
          iVar10 = 0x15ad;
          iVar37 = 0x4d;
          goto LAB_00110e9c;
        }
        p_Var29 = pPVar16->ob_type;
      }
      if (p_Var29 == (_typeobject *)PTR_PyDict_Type_00123f78) {
        pPVar13 = __Pyx_PyDict_GetItem(pPVar16,__pyx_mstate_global_static.__pyx_n_s_chip);
      }
      else {
        pPVar13 = (PyObject *)PyObject_GetItem();
      }
      if (pPVar13 == (PyObject *)0x0) {
        obj = (PyObject *)0x0;
        pPVar14 = (PyObject *)0x0;
        iVar10 = 0x15bf;
        iVar37 = 0x4e;
        pPVar13 = (PyObject *)0x0;
        func = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = pPVar33->ob_refcnt + -1;
      pPVar33->ob_refcnt = lVar36;
      if (lVar36 == 0) {
        (*pPVar33->ob_type->tp_dealloc)(pPVar33);
      }
      if (pPVar16->ob_type == (_typeobject *)PTR_PyDict_Type_00123f78) {
        pPVar14 = __Pyx_PyDict_GetItem(pPVar16,__pyx_mstate_global_static.__pyx_n_s_chip_name);
      }
      else {
        pPVar14 = (PyObject *)PyObject_GetItem();
      }
      pPVar33 = pPVar13;
      if (pPVar14 == (PyObject *)0x0) {
        obj = (PyObject *)0x0;
        pPVar13 = (PyObject *)0x0;
        iVar10 = 0x15cb;
        iVar37 = 0x4f;
        pPVar14 = (PyObject *)0x0;
        func = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        goto LAB_00110870;
      }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar36 = local_98->ob_refcnt + -1;
      local_98->ob_refcnt = lVar36;
      if (lVar36 == 0) {
        (*local_98->ob_type->tp_dealloc)(local_98);
      }
                    /* Unresolved local var: PyListObject * L@[???]
                       Unresolved local var: Py_ssize_t len@[???] */
      lVar36 = local_90[1].ob_refcnt;
      local_98 = pPVar14;
      if (local_90[2].ob_refcnt >> 1 < lVar36 && lVar36 < local_90[2].ob_refcnt) {
        p_Var29 = local_90[1].ob_type;
        pPVar16->ob_refcnt = pPVar16->ob_refcnt + 1;
        (&(p_Var29->ob_base).ob_base.ob_refcnt)[lVar36] = (Py_ssize_t)pPVar16;
        local_90[1].ob_refcnt = lVar36 + 1;
        goto LAB_0010fc54;
      }
      iVar10 = PyList_Append(local_90,pPVar16);
      if (iVar10 == -1) goto code_r0x00110e88;
      goto LAB_0010fc54;
    }
    pPVar16 = (PyObject *)0x0;
    pPVar35 = (PyObject *)0x0;
    p_Var31 = (_typeobject *)0x0;
    iVar37 = 0x48;
    iVar10 = 0x1518;
    local_98 = pPVar33;
  }
  goto LAB_001103a0;
  while( true ) {
    lVar32 = lVar36 + 1;
    if (lVar12 == lVar36) goto LAB_001102e0;
    p_Var31 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar36];
    lVar36 = lVar32;
    if ((_typeobject *)pPVar28 == p_Var31) break;
LAB_0010f970:
    bVar8 = pPVar28->ob_type != (_typeobject *)puVar6;
    bVar9 = (p_Var31->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    lVar32 = lVar36;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar28 != (PyObject *)puVar4) && (bVar8 || p_Var31 != (_typeobject *)puVar4)) {
        plVar18 = (long *)PyObject_RichCompare(pPVar28,p_Var31,2);
        if (plVar18 == (long *)0x0) goto LAB_001102e0;
        uVar11 = (uint)(plVar18 == (long *)puVar5);
        if ((plVar18 != (long *)puVar5 && plVar18 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar18 != (long *)puVar4) {
          uVar11 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = *plVar18;
        *plVar18 = lVar21 + -1;
        if (lVar21 + -1 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
LAB_001102c8:
        if (uVar11 != 0) {
          if ((int)uVar11 < 0) goto LAB_001102e0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar28[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar28), iVar10 < 0)) ||
         ((-1 < (char)p_Var31->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var31), iVar10 < 0))))
      goto LAB_001102e0;
      lVar21 = pPVar28[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar21 == (p_Var31->ob_base).ob_size) &&
         ((pPVar28[1].ob_type == (_typeobject *)p_Var31->tp_name ||
          (_typeobject *)p_Var31->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar28[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        ppPVar23 = (PyObject **)((ulong)(byte)((byte)pPVar28[2].ob_refcnt >> 2) & 7);
        uVar11 = (uint)ppPVar23;
        ppPVar24 = ppPVar23;
        if (((byte)((byte)p_Var31->tp_basicsize >> 2) & 7) == uVar11) {
          bVar2 = (byte)pPVar28[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var29 = pPVar28[4].ob_type;
          }
          else {
            p_Var29 = (_typeobject *)&pPVar28[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var29 = (_typeobject *)(pPVar28 + 3);
            }
          }
          bVar2 = (byte)p_Var31->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var20 = (setattrfunc *)p_Var31->tp_setattr;
          }
          else {
            pp_Var20 = &p_Var31->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var20 = (setattrfunc *)&p_Var31->tp_dealloc;
            }
          }
          if (uVar11 == 1) {
            ppPVar24 = (PyObject **)(ulong)(byte)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar11 = (uint)*(byte *)pp_Var20;
          }
          else if (uVar11 == 2) {
            ppPVar24 = (PyObject **)(ulong)(ushort)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar11 = (uint)*(ushort *)pp_Var20;
          }
          else {
            ppPVar24 = (PyObject **)(ulong)(uint)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar11 = *(uint *)pp_Var20;
          }
          if (uVar11 == (uint)ppPVar24) {
            if (lVar21 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var29,pp_Var20,(long)ppPVar23 * lVar21);
              uVar11 = (uint)(iVar10 == 0);
              goto LAB_001102c8;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar32];
LAB_00110158:
  if (values[2] == (PyObject *)0x0) {
LAB_001102e4:
    lVar36 = PyErr_Occurred();
    if (lVar36 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","register_buttons",
                   "exactly",4,"s",2);
      iVar10 = 0x148a;
    }
    else {
      iVar10 = 0x1488;
    }
    goto LAB_00110034;
  }
  lVar17 = lVar17 + -1;
  lVar36 = __pyx_kwds[1].ob_refcnt;
LAB_0010f76c:
  pPVar28 = __pyx_mstate_global_static.__pyx_n_s_debounce_us;
  puVar6 = PTR_PyUnicode_Type_00123fb8;
  puVar5 = PTR__Py_TrueStruct_00123f68;
  puVar4 = PTR__Py_NoneStruct_00123f60;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
  if (0 < lVar36) {
    p_Var31 = __pyx_kwds[1].ob_type;
    if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_debounce_us == p_Var31) {
      values[3] = *kwvalues;
    }
    else {
      lVar12 = 0;
      do {
        lVar32 = lVar12 + 1;
        if (lVar32 == lVar36) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
          lVar12 = 0;
          goto LAB_0010f7e0;
        }
        pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar12;
        lVar12 = lVar32;
      } while (__pyx_mstate_global_static.__pyx_n_s_debounce_us != (PyObject *)*pPVar1);
      values[3] = kwvalues[lVar32];
    }
    goto LAB_0010fa78;
  }
LAB_00110200:
  values[3] = (PyObject *)0x0;
LAB_00110204:
  lVar36 = PyErr_Occurred();
  if (lVar36 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f18,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","register_buttons",
                 "exactly",4,"s",3);
    iVar10 = 0x1494;
  }
  else {
    iVar10 = 0x1492;
  }
  goto LAB_00110034;
code_r0x00110e88:
  iVar37 = 0x50;
  iVar10 = 0x15d7;
LAB_00110e9c:
  obj = (PyObject *)0x0;
  pPVar14 = (PyObject *)0x0;
  pPVar13 = (PyObject *)0x0;
  func = (PyObject *)0x0;
  pPVar16 = (PyObject *)0x0;
LAB_00110870:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar36 = pPVar25->ob_refcnt + -1;
  pPVar25->ob_refcnt = lVar36;
  if (lVar36 == 0) {
    (*pPVar25->ob_type->tp_dealloc)(pPVar25);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (pPVar13 != (PyObject *)0x0) {
    lVar36 = pPVar13->ob_refcnt + -1;
LAB_001108a4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar36;
    if (lVar36 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
  }
LAB_001108c4:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar14 != (PyObject *)0x0) &&
     (lVar36 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar36, lVar36 == 0)) {
    (*pPVar14->ob_type->tp_dealloc)(pPVar14);
  }
LAB_001108f0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((obj != (PyObject *)0x0) &&
     (lVar36 = obj->ob_refcnt + -1, obj->ob_refcnt = lVar36, lVar36 == 0)) {
    (*obj->ob_type->tp_dealloc)(obj);
  }
LAB_0011091c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((func != (PyObject *)0x0) &&
     (lVar36 = func->ob_refcnt + -1, func->ob_refcnt = lVar36, lVar36 == 0)) {
    (*func->ob_type->tp_dealloc)(func);
  }
LAB_001103a0:
  pPVar28 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq.MCU_irq_button.register_buttons",iVar10,iVar37,
                     "buttons_irq.py");
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  pPVar13 = pPVar16;
  if (pPVar15 != (PyObject *)0x0) {
LAB_001103c4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar36 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar36;
    if (lVar36 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar33 != (PyObject *)0x0) &&
     (lVar36 = pPVar33->ob_refcnt + -1, pPVar33->ob_refcnt = lVar36, lVar36 == 0)) {
    (*pPVar33->ob_type->tp_dealloc)(pPVar33);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_98 != (PyObject *)0x0) &&
     (lVar36 = local_98->ob_refcnt + -1, local_98->ob_refcnt = lVar36, lVar36 == 0)) {
    (*local_98->ob_type->tp_dealloc)(local_98);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_90 != (PyObject *)0x0) &&
     (lVar36 = local_90->ob_refcnt + -1, local_90->ob_refcnt = lVar36, lVar36 == 0)) {
    (*local_90->ob_type->tp_dealloc)(local_90);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((p_Var31 != (_typeobject *)0x0) &&
     (lVar36 = (p_Var31->ob_base).ob_base.ob_refcnt + -1,
     (p_Var31->ob_base).ob_base.ob_refcnt = lVar36, lVar36 == 0)) {
    (*((p_Var31->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var31);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar35 != (PyObject *)0x0) &&
     (lVar36 = pPVar35->ob_refcnt + -1, pPVar35->ob_refcnt = lVar36, lVar36 == 0)) {
    (*pPVar35->ob_type->tp_dealloc)(pPVar35);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar13 != (PyObject *)0x0) &&
     (lVar36 = pPVar13->ob_refcnt + -1, pPVar13->ob_refcnt = lVar36, lVar36 == 0)) {
    (*pPVar13->ob_type->tp_dealloc)(pPVar13);
  }
  goto LAB_00110050;
  while( true ) {
    lVar32 = lVar12 + 1;
    if (lVar32 == lVar36) goto LAB_00110200;
    p_Var31 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar32;
    if ((_typeobject *)pPVar28 == p_Var31) break;
LAB_0010f7e0:
    bVar8 = pPVar28->ob_type != (_typeobject *)puVar6;
    bVar9 = (p_Var31->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    lVar32 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar28 != (PyObject *)puVar4) && (bVar8 || p_Var31 != (_typeobject *)puVar4)) {
        plVar18 = (long *)PyObject_RichCompare(pPVar28,p_Var31,2);
        if (plVar18 == (long *)0x0) goto LAB_00110200;
        uVar11 = (uint)(plVar18 == (long *)puVar5);
        if ((plVar18 != (long *)puVar5 && plVar18 != (long *)PTR__Py_FalseStruct_00123f30) &&
            plVar18 != (long *)puVar4) {
          uVar11 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = *plVar18;
        *plVar18 = lVar21 + -1;
        if (lVar21 + -1 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
LAB_001101e8:
        if (uVar11 != 0) {
          if ((int)uVar11 < 0) goto LAB_00110200;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar28[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar28), iVar10 < 0)) ||
         ((-1 < (char)p_Var31->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var31), iVar10 < 0))))
      goto LAB_00110200;
      lVar21 = pPVar28[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar21 == (p_Var31->ob_base).ob_size) &&
         ((pPVar28[1].ob_type == (_typeobject *)p_Var31->tp_name ||
          (_typeobject *)p_Var31->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar28[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        ppPVar23 = (PyObject **)((ulong)(byte)((byte)pPVar28[2].ob_refcnt >> 2) & 7);
        uVar11 = (uint)ppPVar23;
        ppPVar24 = ppPVar23;
        if (((byte)((byte)p_Var31->tp_basicsize >> 2) & 7) == uVar11) {
          bVar2 = (byte)pPVar28[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var29 = pPVar28[4].ob_type;
          }
          else {
            p_Var29 = (_typeobject *)&pPVar28[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var29 = (_typeobject *)(pPVar28 + 3);
            }
          }
          bVar2 = (byte)p_Var31->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var20 = (setattrfunc *)p_Var31->tp_setattr;
          }
          else {
            pp_Var20 = &p_Var31->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var20 = (setattrfunc *)&p_Var31->tp_dealloc;
            }
          }
          if (uVar11 == 1) {
            ppPVar24 = (PyObject **)(ulong)(byte)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar11 = (uint)*(byte *)pp_Var20;
          }
          else if (uVar11 == 2) {
            ppPVar24 = (PyObject **)(ulong)(ushort)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar11 = (uint)*(ushort *)pp_Var20;
          }
          else {
            ppPVar24 = (PyObject **)(ulong)(uint)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar11 = *(uint *)pp_Var20;
          }
          if (uVar11 == (uint)ppPVar24) {
            if (lVar21 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var29,pp_Var20,(long)ppPVar23 * lVar21);
              uVar11 = (uint)(iVar10 == 0);
              goto LAB_001101e8;
            }
            break;
          }
        }
      }
    }
  }
  values[3] = kwvalues[lVar32];
LAB_0010fa78:
  if (values[3] == (PyObject *)0x0) goto LAB_00110204;
  lVar36 = lVar17 + -1;
LAB_0010fa84:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
  if ((lVar36 < 1) ||
     (iVar10 = __Pyx_ParseOptionalKeywords
                         (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                          (PyObject **)__pyx_nargs,0x112740,(char *)ppPVar24), -1 < iVar10))
  goto LAB_0010fa98;
  iVar10 = 0x1499;
LAB_00110034:
  pPVar28 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.buttons_irq.MCU_irq_button.register_buttons",iVar10,0x45,
                     "buttons_irq.py");
LAB_00110050:
  if (lVar27 == *(long *)PTR___stack_chk_guard_00123f40) {
    return pPVar28;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Successfully decompiled 16 of 16 selected functions. */
