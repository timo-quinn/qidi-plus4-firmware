/*
 * Reverse-engineered Ghidra output. This is not original source code.
 * Program: box_rfid.so
 * Language: AARCH64:LE:64:v8A
 * Selected named functions: 13
 */


/* ================================================================
 * Address: 001043b0
 * Symbol:  __pyx_pymod_exec_box_rfid
 * Signature: int __pyx_pymod_exec_box_rfid(PyObject * __pyx_pyinit_module)
 * ================================================================ */

int __pyx_pymod_exec_box_rfid(PyObject *__pyx_pyinit_module)

{
  byte bVar1;
  uint uVar2;
  PyTypeObject *pPVar3;
  Py_ssize_t *pPVar4;
  PyObject *pPVar5;
  bool bVar6;
  int iVar7;
  long lVar8;
  long *plVar9;
  char *pcVar10;
  PyTypeObject *pPVar11;
  long lVar12;
  PyObject *pPVar13;
  PyObject *pPVar14;
  long *plVar15;
  long *plVar16;
  ulong uVar17;
  long lVar18;
  _typeobject *p_Var19;
  ulong uVar20;
  int iVar21;
  PyObject *pPVar22;
  PyObject *code;
  ulong uVar23;
  PyTypeObject *pPVar24;
  char *__s;
  undefined8 in_stack_fffffffffffffe60;
  undefined4 uVar25;
  PyObject *margs [4];
  char message [200];
  
                    /* Unresolved local var: int stringtab_initialized@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  uVar25 = (undefined4)((ulong)in_stack_fffffffffffffe60 >> 0x20);
  lVar18 = *(long *)PTR___stack_chk_guard_00123f48;
  if (__pyx_m != (PyObject *)0x0) {
    iVar7 = 0;
    if (__pyx_m != __pyx_pyinit_module) {
      PyErr_SetString(*(undefined8 *)PTR_PyExc_RuntimeError_00123f18,
                      "Module \'box_rfid\' has already been imported. Re-initialisation is not supported."
                      ,0);
      iVar7 = -1;
    }
    goto LAB_0010563c;
  }
  __pyx_m = __pyx_pyinit_module;
  __pyx_pyinit_module->ob_refcnt = __pyx_pyinit_module->ob_refcnt + 1;
  __pyx_mstate_global_static.__pyx_d = (PyObject *)PyModule_GetDict();
  if (__pyx_mstate_global_static.__pyx_d == (PyObject *)0x0) {
    iVar21 = 0x198f;
    iVar7 = 1;
    bVar6 = false;
LAB_00104de8:
    if (__pyx_m == (PyObject *)0x0) {
      lVar8 = PyErr_Occurred();
      if (lVar8 == 0) {
        PyErr_SetString(*(undefined8 *)PTR_PyExc_ImportError_00123fa0,"init extras.box_rfid");
      }
    }
    else {
      if ((__pyx_mstate_global_static.__pyx_d != (PyObject *)0x0) && (bVar6)) {
        __Pyx_AddTraceback("init extras.box_rfid",iVar21,iVar7,"box_rfid.py");
      }
                    /* Unresolved local var: PyObject * _py_tmp@[???] */
      pPVar22 = __pyx_m;
      if (__pyx_m != (PyObject *)0x0) {
        pPVar4 = &__pyx_m->ob_refcnt;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        __pyx_m = (PyObject *)0x0;
        lVar8 = *pPVar4 + -1;
        pPVar22->ob_refcnt = lVar8;
        if (lVar8 == 0) {
          (*pPVar22->ob_type->tp_dealloc)(pPVar22);
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
      iVar21 = 0x1991;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
    (__pyx_mstate_global_static.__pyx_b)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_b)->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * module@[???] */
    __pyx_mstate_global_static.__pyx_cython_runtime =
         (PyObject *)PyImport_AddModule("cython_runtime");
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (__pyx_mstate_global_static.__pyx_cython_runtime == (PyObject *)0x0) {
      iVar21 = 0x1992;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
    (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt + 1;
    iVar7 = PyObject_SetAttrString(__pyx_m,"__builtins__",__pyx_mstate_global_static.__pyx_b);
    if (iVar7 < 0) {
      iVar21 = 0x1993;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
                    /* Unresolved local var: char * rt_version@[???]
                       Unresolved local var: ulong version@[???]
                       Unresolved local var: ulong factor@[???]
                       Unresolved local var: wchar_t digit@[???]
                       Unresolved local var: int i@[???] */
    lVar8 = Py_GetVersion();
    iVar21 = 4;
    iVar7 = 0;
    uVar23 = 0;
    uVar20 = 0x1000000;
    do {
      uVar17 = 0;
      while (bVar1 = *(byte *)(lVar8 + iVar7), (byte)(bVar1 - 0x30) < 10) {
        iVar7 = iVar7 + 1;
        uVar17 = (ulong)(((uint)bVar1 + (int)uVar17 * 10) - 0x30);
      }
      uVar23 = uVar23 + uVar17 * uVar20;
      if (bVar1 != 0x2e) break;
      uVar20 = uVar20 >> 8;
      iVar7 = iVar7 + 1;
      iVar21 = iVar21 + -1;
    } while (iVar21 != 0);
                    /* Unresolved local var: ulong MAJOR_MINOR@[???] */
    if (((uVar23 ^ 0x3070000) & 0xffff0000) != 0) {
      PyOS_snprintf(message,200,
                    "compile time Python version %d.%d of module \'%.100s\' %s runtime version %d.%d"
                    ,3,7,"extras.box_rfid","does not match",uVar23 >> 0x18 & 0xffffffff,
                    CONCAT44(uVar25,(uint)uVar23 >> 0x10) & 0xffffffff000000ff);
      iVar7 = PyErr_WarnEx(0,message,1);
      if (iVar7 < 0) {
        iVar21 = 0x199e;
        iVar7 = 1;
        bVar6 = false;
        goto LAB_00104de8;
      }
    }
    __pyx_pyframe_localsplus_offset = *(long *)(PTR_PyFrame_Type_00123f98 + 0x20) - 8;
    __pyx_mstate_global_static.__pyx_empty_tuple = (PyObject *)PyTuple_New(0);
    if (__pyx_mstate_global_static.__pyx_empty_tuple == (PyObject *)0x0) {
      iVar21 = 0x19a2;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
    __pyx_mstate_global_static.__pyx_empty_bytes = (PyObject *)PyBytes_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_bytes == (PyObject *)0x0) {
      iVar21 = 0x19a3;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
    __pyx_mstate_global_static.__pyx_empty_unicode = (PyObject *)PyUnicode_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_unicode == (PyObject *)0x0) {
      iVar21 = 0x19a4;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
                    /* Unresolved local var: PyObject * abi_module@[???]
                       Unresolved local var: char * object_name@[???]
                       Unresolved local var: PyTypeObject * cached_type@[???]
                       Unresolved local var: PyObject * module@[???] */
    plVar9 = (long *)PyImport_AddModule("_cython_3_0_12");
    __s = __pyx_CyFunctionType_type.tp_name;
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (plVar9 == (long *)0x0) {
      iVar21 = 0x19a6;
      iVar7 = 1;
      bVar6 = false;
      __pyx_mstate_global_static.__pyx_CyFunctionType = (PyTypeObject *)0x0;
      goto LAB_00104de8;
    }
    *plVar9 = *plVar9 + 1;
    pcVar10 = strrchr(__s,0x2e);
    if (pcVar10 != (char *)0x0) {
      __s = pcVar10 + 1;
    }
    pPVar11 = (PyTypeObject *)PyObject_GetAttrString(plVar9,__s);
    pPVar3 = (PyTypeObject *)0x0;
    pPVar24 = pPVar3;
    if (pPVar11 == (PyTypeObject *)0x0) {
      iVar7 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_AttributeError_00123fa8);
      if (iVar7 != 0) {
        PyErr_Clear();
        iVar7 = PyType_Ready(&__pyx_CyFunctionType_type);
        if ((-1 < iVar7) &&
           (iVar7 = PyObject_SetAttrString(plVar9,__s,&__pyx_CyFunctionType_type), -1 < iVar7)) {
          __pyx_CyFunctionType_type.ob_base.ob_base.ob_refcnt =
               __pyx_CyFunctionType_type.ob_base.ob_base.ob_refcnt + 1;
          pPVar24 = &__pyx_CyFunctionType_type;
        }
      }
    }
    else {
      if ((int)((pPVar11->ob_base).ob_base.ob_type)->tp_flags < 0) {
        pPVar24 = pPVar11;
        if (pPVar11->tp_basicsize == __pyx_CyFunctionType_type.tp_basicsize) goto LAB_001046f8;
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                     "Shared Cython type %.200s has the wrong size, try recompiling",__s);
      }
      else {
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                     "Shared Cython type %.200s is not a type object",__s);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar8 = (pPVar11->ob_base).ob_base.ob_refcnt + -1;
      (pPVar11->ob_base).ob_base.ob_refcnt = lVar8;
      pPVar24 = pPVar3;
      if (lVar8 == 0) {
        (*((pPVar11->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)pPVar11);
      }
    }
LAB_001046f8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = *plVar9;
    *plVar9 = lVar8 + -1;
    if (lVar8 + -1 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    __pyx_mstate_global_static.__pyx_CyFunctionType = pPVar24;
    if (pPVar24 == (PyTypeObject *)0x0) {
      iVar21 = 0x19a6;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
    iVar7 = __Pyx_CreateStringTabAndInitStrings();
    if ((((((iVar7 < 0) ||
           (__pyx_mstate_global_static.__pyx_float_0_1 =
                 (PyObject *)PyFloat_FromDouble(DAT_00111398),
           __pyx_mstate_global_static.__pyx_float_0_1 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_float_30_0 =
                (PyObject *)PyFloat_FromDouble(0x403e000000000000),
          __pyx_mstate_global_static.__pyx_float_30_0 == (PyObject *)0x0)) ||
         ((__pyx_mstate_global_static.__pyx_int_0 = (PyObject *)PyLong_FromLong(0),
          __pyx_mstate_global_static.__pyx_int_0 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_int_1 = (PyObject *)PyLong_FromLong(1),
          __pyx_mstate_global_static.__pyx_int_1 == (PyObject *)0x0)))) ||
        (__pyx_mstate_global_static.__pyx_int_2 = (PyObject *)PyLong_FromLong(2),
        __pyx_mstate_global_static.__pyx_int_2 == (PyObject *)0x0)) ||
       (((__pyx_mstate_global_static.__pyx_int_3 = (PyObject *)PyLong_FromLong(3),
         __pyx_mstate_global_static.__pyx_int_3 == (PyObject *)0x0 ||
         (__pyx_mstate_global_static.__pyx_int_24 = (PyObject *)PyLong_FromLong(0x18),
         __pyx_mstate_global_static.__pyx_int_24 == (PyObject *)0x0)) ||
        ((__pyx_mstate_global_static.__pyx_int_99 = (PyObject *)PyLong_FromLong(99),
         __pyx_mstate_global_static.__pyx_int_99 == (PyObject *)0x0 ||
         (__pyx_mstate_global_static.__pyx_int_5000000 = (PyObject *)PyLong_FromLong(5000000),
         __pyx_mstate_global_static.__pyx_int_5000000 == (PyObject *)0x0)))))) {
      iVar21 = 0x19bd;
      iVar7 = 1;
      bVar6 = false;
      goto LAB_00104de8;
    }
    if ((*(int *)PTR___pyx_module_is_main_extras__box_rfid_00123f60 != 0) &&
       (iVar7 = PyObject_SetAttr(__pyx_m,__pyx_mstate_global_static.__pyx_n_s_name_2,
                                 __pyx_mstate_global_static.__pyx_n_s_main), iVar7 < 0)) {
      iVar7 = 1;
      iVar21 = 0x19c4;
      bVar6 = true;
      goto LAB_00104de8;
    }
                    /* Unresolved local var: PyObject * modules@[???] */
    lVar8 = PyImport_GetModuleDict();
    if (lVar8 == 0) {
      iVar7 = 1;
      iVar21 = 0x19c8;
      bVar6 = true;
      goto LAB_00104de8;
    }
    lVar12 = PyDict_GetItemString(lVar8,"extras.box_rfid");
    if ((lVar12 == 0) && (iVar7 = PyDict_SetItemString(lVar8,"extras.box_rfid",__pyx_m), iVar7 < 0))
    {
      iVar7 = 1;
      iVar21 = 0x19ca;
      bVar6 = true;
      goto LAB_00104de8;
    }
    __pyx_mstate_global_static.__pyx_tuple_ =
         (PyObject *)
         PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_kp_s_fm17550_read_card_cb_oid_c,
                      __pyx_mstate_global_static.__pyx_kp_s_fm17550_read_card_return_oid_c_s);
    if ((((((__pyx_mstate_global_static.__pyx_tuple_ == (PyObject *)0x0) ||
           (__pyx_mstate_global_static.__pyx_tuple__4 =
                 (PyObject *)
                 PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_config),
           __pyx_mstate_global_static.__pyx_tuple__4 == (PyObject *)0x0)) ||
          (__pyx_mstate_global_static.__pyx_codeobj__5 =
                (PyObject *)
                PyCode_New(2,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__4,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                           __pyx_mstate_global_static.__pyx_n_s_init,4,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__5 == (PyObject *)0x0)) ||
         (((__pyx_mstate_global_static.__pyx_tuple__6 =
                 (PyObject *)
                 PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_cmdqueue),
           __pyx_mstate_global_static.__pyx_tuple__6 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_codeobj__7 =
                 (PyObject *)
                 PyCode_New(1,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_tuple__6,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_empty_tuple,
                            __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                            __pyx_mstate_global_static.__pyx_n_s_build_config,0x1c,
                            __pyx_mstate_global_static.__pyx_empty_bytes),
           __pyx_mstate_global_static.__pyx_codeobj__7 == (PyObject *)0x0)) ||
          ((__pyx_mstate_global_static.__pyx_tuple__8 =
                 (PyObject *)
                 PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                              __pyx_mstate_global_static.__pyx_n_s_params),
           __pyx_mstate_global_static.__pyx_tuple__8 == (PyObject *)0x0 ||
           ((__pyx_mstate_global_static.__pyx_codeobj__9 =
                  (PyObject *)
                  PyCode_New(1,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__8,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                             __pyx_mstate_global_static.__pyx_n_s_read_card,0x24,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__9 == (PyObject *)0x0 ||
            (__pyx_mstate_global_static.__pyx_codeobj__10 =
                  (PyObject *)
                  PyCode_New(1,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_tuple__8,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_empty_tuple,
                             __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                             __pyx_mstate_global_static.__pyx_n_s_read_card_from_slot,0x28,
                             __pyx_mstate_global_static.__pyx_empty_bytes),
            __pyx_mstate_global_static.__pyx_codeobj__10 == (PyObject *)0x0)))))))) ||
        (__pyx_mstate_global_static.__pyx_tuple__11 =
              (PyObject *)
              PyTuple_Pack(6,__pyx_mstate_global_static.__pyx_n_s_self,
                           __pyx_mstate_global_static.__pyx_n_s_eventtime,
                           __pyx_mstate_global_static.__pyx_n_s_params,
                           __pyx_mstate_global_static.__pyx_n_s_data,
                           __pyx_mstate_global_static.__pyx_n_s_filament_2,
                           __pyx_mstate_global_static.__pyx_n_s_color_2),
        __pyx_mstate_global_static.__pyx_tuple__11 == (PyObject *)0x0)) ||
       ((((__pyx_mstate_global_static.__pyx_codeobj__12 =
                (PyObject *)
                PyCode_New(2,0,6,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__11,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                           __pyx_mstate_global_static.__pyx_n_s_schedule_rfid_read,0x2b,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__12 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_tuple__13 =
                (PyObject *)
                PyTuple_Pack(2,__pyx_mstate_global_static.__pyx_n_s_self,
                             __pyx_mstate_global_static.__pyx_n_s_stepper),
          __pyx_mstate_global_static.__pyx_tuple__13 == (PyObject *)0x0)) ||
         (__pyx_mstate_global_static.__pyx_codeobj__14 =
               (PyObject *)
               PyCode_New(2,0,2,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_tuple__13,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_empty_tuple,
                          __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                          __pyx_mstate_global_static.__pyx_n_s_start_rfid_read,0x54,
                          __pyx_mstate_global_static.__pyx_empty_bytes),
         __pyx_mstate_global_static.__pyx_codeobj__14 == (PyObject *)0x0)) ||
        (((__pyx_mstate_global_static.__pyx_tuple__15 =
                (PyObject *)PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_n_s_self),
          __pyx_mstate_global_static.__pyx_tuple__15 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_codeobj__16 =
                (PyObject *)
                PyCode_New(1,0,1,0,3,__pyx_mstate_global_static.__pyx_empty_bytes,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_tuple__15,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_empty_tuple,
                           __pyx_mstate_global_static.__pyx_kp_s_box_rfid_py,
                           __pyx_mstate_global_static.__pyx_n_s_stop_read,0x62,
                           __pyx_mstate_global_static.__pyx_empty_bytes),
          __pyx_mstate_global_static.__pyx_codeobj__16 == (PyObject *)0x0)) ||
         ((__pyx_mstate_global_static.__pyx_tuple__17 =
                (PyObject *)PyTuple_Pack(1,__pyx_mstate_global_static.__pyx_n_s_config),
          __pyx_mstate_global_static.__pyx_tuple__17 == (PyObject *)0x0 ||
          (pPVar22 = __pyx_mstate_global_static.__pyx_empty_bytes,
          code = __pyx_mstate_global_static.__pyx_empty_tuple,
          __pyx_mstate_global_static.__pyx_codeobj__18 = (PyObject *)PyCode_New(1,0,1,0,3),
          __pyx_mstate_global_static.__pyx_codeobj__18 == (PyObject *)0x0)))))))) {
      iVar7 = 1;
      iVar21 = 0x19d1;
      bVar6 = true;
      goto LAB_00104de8;
    }
    pPVar13 = (PyObject *)PyList_New(1);
    pPVar14 = __pyx_mstate_global_static.__pyx_n_s_bus;
    if (pPVar13 == (PyObject *)0x0) {
      iVar7 = 1;
      iVar21 = 0x19e4;
      bVar6 = true;
      goto LAB_00104de8;
    }
    p_Var19 = pPVar13[1].ob_type;
    (__pyx_mstate_global_static.__pyx_n_s_bus)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_bus)->ob_refcnt + 1;
    (p_Var19->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar14;
    pPVar14 = __pyx_mstate_global_static.__pyx_n_s__2;
                    /* Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * empty_dict@[???]
                       Unresolved local var: PyObject * empty_list@[???] */
    plVar9 = (long *)PyDict_New();
    if (plVar9 == (long *)0x0) {
      pPVar14 = (PyObject *)0x0;
      iVar21 = 0x19e9;
      iVar7 = 1;
LAB_00104d98:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar8 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar8;
      if (lVar8 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (pPVar14 != (PyObject *)0x0) {
LAB_00104dbc:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar8 = pPVar14->ob_refcnt + -1;
        pPVar14->ob_refcnt = lVar8;
        if (lVar8 == 0) {
          (*pPVar14->ob_type->tp_dealloc)(pPVar14);
          bVar6 = true;
          goto LAB_00104de8;
        }
      }
      bVar6 = true;
      goto LAB_00104de8;
    }
    pPVar14 = (PyObject *)
              PyImport_ImportModuleLevelObject
                        (pPVar14,__pyx_mstate_global_static.__pyx_d,plVar9,pPVar13,1);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = *plVar9;
    *plVar9 = lVar8 + -1;
    if (lVar8 + -1 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (pPVar14 == (PyObject *)0x0) {
      iVar21 = 0x19e9;
      iVar7 = 1;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar5 = __pyx_mstate_global_static.__pyx_n_s_bus;
                    /* Unresolved local var: PyObject * value@[???] */
    pPVar13 = __Pyx_PyObject_GetAttrStr(pPVar14,__pyx_mstate_global_static.__pyx_n_s_bus);
    if (pPVar13 == (PyObject *)0x0) {
      iVar7 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_AttributeError_00123fa8);
      if (iVar7 != 0) {
                    /* Unresolved local var: char * module_name_str@[???]
                       Unresolved local var: PyObject * module_name@[???]
                       Unresolved local var: PyObject * module_dot@[???]
                       Unresolved local var: PyObject * full_name@[???] */
        PyErr_Clear();
        lVar8 = PyModule_GetName(pPVar14);
        if ((lVar8 != 0) && (plVar9 = (long *)PyUnicode_FromString(), plVar9 != (long *)0x0)) {
          plVar15 = (long *)PyUnicode_Concat(plVar9,__pyx_mstate_global_static.__pyx_kp_u__3);
          if (plVar15 != (long *)0x0) {
            plVar16 = (long *)PyUnicode_Concat(plVar15,pPVar5);
            if (plVar16 != (long *)0x0) {
              pPVar13 = (PyObject *)PyImport_GetModule();
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar8 = *plVar16;
              *plVar16 = lVar8 + -1;
              if (lVar8 + -1 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar8 = *plVar15;
            *plVar15 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar8 = *plVar9;
          *plVar9 = lVar8 + -1;
          if (lVar8 + -1 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (pPVar13 != (PyObject *)0x0) goto LAB_00104e8c;
        }
      }
      iVar21 = 0x19ec;
      iVar7 = 1;
      PyErr_Format(*(undefined8 *)PTR_PyExc_ImportError_00123fa0,"cannot import name %S",pPVar5);
      goto LAB_00104dbc;
    }
LAB_00104e8c:
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_bus,pPVar13);
    if (iVar7 < 0) {
      iVar21 = 0x19ee;
      iVar7 = 1;
      goto LAB_00104d98;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar13->ob_refcnt + -1;
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    pPVar5 = __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid;
    pPVar13 = __pyx_mstate_global_static.__pyx_n_s_BoxRFID;
                    /* Unresolved local var: PyObject * ns@[???] */
    pPVar14 = (PyObject *)PyDict_New();
    if (pPVar14 == (PyObject *)0x0) {
LAB_00104f08:
      iVar21 = 0x19f9;
      iVar7 = 3;
      bVar6 = true;
      goto LAB_00104de8;
    }
    iVar7 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_module,pPVar5);
    if ((iVar7 < 0) ||
       (iVar7 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_qualname,pPVar13),
       iVar7 < 0)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar8 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar8;
      if (lVar8 == 0) {
        iVar21 = 0x19f9;
        iVar7 = 3;
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
        bVar6 = true;
        goto LAB_00104de8;
      }
      goto LAB_00104f08;
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_1__init__,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID___init,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__5,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a03;
      iVar7 = 4;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_init,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_init,pPVar13);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a05;
      iVar7 = 4;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_3_build_config,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID__build_config,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__7,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a0f;
      iVar7 = 0x1c;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_build_config,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_build_config[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_build_config,pPVar13);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a11;
      iVar7 = 0x1c;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_5read_card,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID_read_card,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__9,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a1b;
      iVar7 = 0x24;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_read_card,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_read_card[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_read_card,pPVar13);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a1d;
      iVar7 = 0x24;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_7read_card_from_slot,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID_read_card_from_slot,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__10,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a27;
      iVar7 = 0x28;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_read_card_from_slot,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_read_card_from_slot[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_read_card_from_slot,
                                pPVar13);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a29;
      iVar7 = 0x28;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_9_schedule_rfid_read,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID__schedule_rfid_read,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__12,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a33;
      iVar7 = 0x2b;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_schedule_rfid_read,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_schedule_rfid_read[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_schedule_rfid_read,
                                pPVar13);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a35;
      iVar7 = 0x2b;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_11start_rfid_read,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID_start_rfid_read,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__14,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a3f;
      iVar7 = 0x54;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_start_rfid_read,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_start_rfid_read[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_start_rfid_read,pPVar13
                               );
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a41;
      iVar7 = 0x54;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    pPVar13 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_7BoxRFID_13stop_read,
                         (int)__pyx_mstate_global_static.__pyx_n_s_BoxRFID_stop_read,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__16,pPVar22,code);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a4b;
      iVar7 = 0x62;
      goto LAB_00104dbc;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
      uVar20 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_stop_read,pPVar13,
                          __pyx_mstate_global_static.__pyx_n_s_stop_read[1].ob_type);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    else {
      uVar20 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_stop_read,pPVar13);
      uVar2 = (uint)(uVar20 >> 0x1f);
    }
    if ((uVar2 & 1) != 0) {
      iVar21 = 0x1a4d;
      iVar7 = 0x62;
      goto LAB_00104d98;
    }
    lVar8 = pPVar13->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: PyObject * owned_metaclass@[???] */
    margs[2] = __pyx_mstate_global_static.__pyx_empty_tuple;
    margs[0] = (PyObject *)0x0;
    margs[1] = __pyx_mstate_global_static.__pyx_n_s_BoxRFID;
    margs[3] = pPVar14;
    pPVar13 = __Pyx_PyObject_FastCallDict
                        ((PyObject *)PTR_PyType_Type_00123f58,margs + 1,0x8000000000000003,
                         __pyx_mstate_global_static.__pyx_empty_tuple);
    if (pPVar13 == (PyObject *)0x0) {
      iVar21 = 0x1a57;
      iVar7 = 3;
      goto LAB_00104dbc;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_BoxRFID,pPVar13);
    if (iVar7 < 0) {
      iVar21 = 0x1a59;
      iVar7 = 3;
      goto LAB_00104d98;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar13->ob_refcnt + -1;
    pPVar13->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    pPVar14 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_8box_rfid_1load_config_prefix,
                         (int)__pyx_mstate_global_static.__pyx_n_s_load_config_prefix,
                         __pyx_mstate_global_static.__pyx_n_s_extras_box_rfid,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__18,pPVar22,code);
    if (pPVar14 == (PyObject *)0x0) {
      iVar21 = 0x1a63;
      iVar7 = 0x6a;
      bVar6 = true;
      goto LAB_00104de8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_load_config_prefix,pPVar14);
    if (iVar7 < 0) {
      iVar21 = 0x1a65;
      iVar7 = 0x6a;
      goto LAB_00104dbc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    pPVar14 = (PyObject *)PyDict_New();
    if (pPVar14 == (PyObject *)0x0) {
      iVar7 = 1;
      iVar21 = 0x1a6d;
      bVar6 = true;
      goto LAB_00104de8;
    }
    iVar7 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_test,pPVar14);
    if (iVar7 < 0) {
      iVar21 = 0x1a6f;
      iVar7 = 1;
      goto LAB_00104dbc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar8 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar8;
    if (lVar8 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
  }
  iVar7 = -(uint)(__pyx_m == (PyObject *)0x0);
LAB_0010563c:
  if (lVar18 != *(long *)PTR___stack_chk_guard_00123f48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}


/* ================================================================
 * Address: 00105674
 * Symbol:  PyInit_box_rfid
 * Signature: PyObject * PyInit_box_rfid(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PyObject * PyInit_box_rfid(void)

{
  PyObject *pPVar1;
  
  pPVar1 = (PyObject *)PyModuleDef_Init(&__pyx_moduledef);
  return pPVar1;
}


/* ================================================================
 * Address: 00105684
 * Symbol:  call_weak_fn
 * Signature: undefined call_weak_fn(void)
 * ================================================================ */

void call_weak_fn(void)

{
  if (PTR___gmon_start___00123f40 != (undefined *)0x0) {
    __gmon_start__();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00105698
 * Symbol:  deregister_tm_clones
 * Signature: undefined deregister_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x001056b0) */
/* WARNING: Removing unreachable block (ram,0x001056bc) */

void deregister_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 001056c8
 * Symbol:  register_tm_clones
 * Signature: undefined register_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x001056ec) */
/* WARNING: Removing unreachable block (ram,0x001056f8) */

void register_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 00108c48
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_5read_card
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_5read_card(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Exceeded maximum restarts with more pending */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_5read_card
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  undefined *puVar1;
  PyObject *apPVar2 [1];
  int iVar3;
  PyObject *pPVar4;
  PyObject *func;
  PyObject **ppPVar5;
  long lVar6;
  _typeobject *p_Var7;
  getattrofunc p_Var8;
  long lVar9;
  char *in_x6;
  PyObject *pPVar10;
  _typeobject *p_Var11;
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
  lVar9 = *(long *)PTR___stack_chk_guard_00123f48;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  pPVar10 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_00108c9c:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","read_card",
                   "exactly",1,"",__pyx_nargs);
      iVar3 = 0xefa;
LAB_00108cd8:
      pPVar10 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.box_rfid.BoxRFID.read_card",iVar3,0x24,"box_rfid.py");
      goto LAB_00108cf4;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar6 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,__pyx_args + __pyx_nargs,
                             __pyx_mstate_global_static.__pyx_n_s_self);
      lVar6 = lVar6 + -1;
      if (values[0] == (PyObject *)0x0) {
        lVar6 = PyErr_Occurred();
        if (lVar6 == 0) goto LAB_00108c9c;
        iVar3 = 0xeea;
        goto LAB_00108cd8;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_00108c9c;
      values[0] = *__pyx_args;
      lVar6 = __pyx_kwds[1].ob_refcnt;
    }
    if (0 < lVar6) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar10 = (PyObject *)values;
      iVar3 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,pPVar10,
                         (PyObject **)__pyx_nargs,0x111b18,in_x6);
      if (iVar3 < 0) {
        iVar3 = 0xeef;
        goto LAB_00108cd8;
      }
    }
  }
                    /* Unresolved local var: PyObject * __pyx_v_params@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: wchar_t __pyx_t_5@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  apPVar2[0] = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var8 = values[0]->ob_type->tp_getattro;
  if (p_Var8 == (getattrofunc)0x0) {
    pPVar4 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar4 = (*p_Var8)(values[0],__pyx_mstate_global_static.__pyx_n_s_fm17550_read_card);
  }
  if (pPVar4 == (PyObject *)0x0) {
    iVar3 = 0xf2a;
  }
  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var8 = pPVar4->ob_type->tp_getattro;
    if (p_Var8 == (getattrofunc)0x0) {
      func = (PyObject *)PyObject_GetAttr(pPVar4,__pyx_mstate_global_static.__pyx_n_s_send);
    }
    else {
      func = (PyObject *)(*p_Var8)();
    }
    lVar6 = pPVar4->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar4->ob_refcnt = lVar6;
    if (func == (PyObject *)0x0) {
      iVar3 = 0xf2c;
      if (lVar6 == 0) {
        (*pPVar4->ob_type->tp_dealloc)(pPVar4);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      }
    }
    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if (lVar6 == 0) {
        (*pPVar4->ob_type->tp_dealloc)(pPVar4);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var8 = apPVar2[0]->ob_type->tp_getattro;
      if (p_Var8 == (getattrofunc)0x0) {
        pPVar4 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar4 = (*p_Var8)(apPVar2[0],__pyx_mstate_global_static.__pyx_n_s_oid);
      }
      if (pPVar4 == (PyObject *)0x0) {
        iVar3 = 0xf2f;
      }
      else {
        ppPVar5 = (PyObject **)PyList_New(1);
        puVar1 = PTR_PyMethod_Type_00123ef0;
        if (ppPVar5 == (PyObject **)0x0) {
          iVar3 = 0xf31;
          lVar6 = pPVar4->ob_refcnt + -1;
          pPVar4->ob_refcnt = lVar6;
          if (lVar6 == 0) {
            (*pPVar4->ob_type->tp_dealloc)(pPVar4);
          }
        }
        else {
          p_Var7 = func->ob_type;
          ppPVar5[3]->ob_refcnt = (Py_ssize_t)pPVar4;
          if ((p_Var7 == (_typeobject *)puVar1) &&
             (p_Var11 = func[1].ob_type, p_Var11 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar4 = (PyObject *)func[1].ob_refcnt;
            (p_Var11->ob_base).ob_base.ob_refcnt = (p_Var11->ob_base).ob_base.ob_refcnt + 1;
            pPVar4->ob_refcnt = pPVar4->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar6 = func->ob_refcnt + -1;
            func->ob_refcnt = lVar6;
            if (lVar6 == 0) {
              (*p_Var7->tp_dealloc)(func);
            }
            __pyx_pyargnames[0] = (PyObject **)p_Var11;
            __pyx_pyargnames[1] = ppPVar5;
            pPVar10 = __Pyx_PyObject_FastCallDict(pPVar4,(PyObject **)__pyx_pyargnames,2,pPVar10);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar6 = (p_Var11->ob_base).ob_base.ob_refcnt + -1;
            (p_Var11->ob_base).ob_base.ob_refcnt = lVar6;
            func = pPVar4;
            if (lVar6 == 0) {
              (*((p_Var11->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var11);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = ppPVar5;
            pPVar10 = __Pyx_PyObject_FastCallDict
                                (func,(PyObject **)(__pyx_pyargnames + 1),1,pPVar10);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar4 = (PyObject *)((long)&(*ppPVar5)[-1].ob_type + 7);
          *ppPVar5 = pPVar4;
          if (pPVar4 == (PyObject *)0x0) {
            (*(code *)ppPVar5[1][3].ob_refcnt)(ppPVar5);
          }
          if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar6 = func->ob_refcnt + -1;
            func->ob_refcnt = lVar6;
            if (lVar6 == 0) {
              (*func->ob_type->tp_dealloc)(func);
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            if (pPVar10->ob_refcnt == 0) {
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
            }
            goto LAB_00108cf4;
          }
          iVar3 = 0xf49;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar6;
      if (lVar6 == 0) {
        (*func->ob_type->tp_dealloc)(func);
      }
    }
  }
  pPVar10 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID.read_card",iVar3,0x25,"box_rfid.py");
LAB_00108cf4:
  if (lVar9 != *(long *)PTR___stack_chk_guard_00123f48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar10;
}


/* ================================================================
 * Address: 00109038
 * Symbol:  __pyx_pw_6extras_8box_rfid_1load_config_prefix
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_1load_config_prefix(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_8box_rfid_1load_config_prefix
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
  puVar5 = PTR_PyUnicode_Type_00123fb8;
  puVar4 = PTR__Py_TrueStruct_00123f70;
                    /* Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00123f68;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_config;
  lVar16 = *(long *)PTR___stack_chk_guard_00123f48;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_001090ac;
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
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_00109238;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar21;
          } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar21];
        }
        goto LAB_0010937c;
      }
LAB_0010933c:
      values[0] = (PyObject *)0x0;
      goto LAB_00109340;
    }
    if (__pyx_nargs == 1) {
      lVar20 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0010909c;
    }
  }
LAB_00109134:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","load_config_prefix",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x1724;
  goto LAB_00109170;
  while( true ) {
    lVar21 = lVar11 + 1;
    if (lVar21 == lVar20) goto LAB_0010933c;
    p_Var14 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar21;
    if ((_typeobject *)pPVar13 == p_Var14) break;
LAB_00109238:
    bVar7 = pPVar13->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var14->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar21 = lVar11;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar13 != (PyObject *)puVar3) && (bVar7 || p_Var14 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar13,p_Var14,2);
        if (plVar12 == (long *)0x0) goto LAB_0010933c;
        uVar18 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar12 != (long *)puVar3) {
          uVar18 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = *plVar12;
        *plVar12 = lVar15 + -1;
        if (lVar15 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_00109328:
        if (uVar18 != 0) {
          if ((int)uVar18 < 0) goto LAB_0010933c;
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
      goto LAB_0010933c;
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
              goto LAB_00109328;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar21];
LAB_0010937c:
  if (values[0] == (PyObject *)0x0) {
LAB_00109340:
    lVar20 = PyErr_Occurred();
    if (lVar20 == 0) goto LAB_00109134;
    iVar9 = 0x1714;
  }
  else {
    lVar20 = lVar20 + -1;
LAB_0010909c:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar20 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x111b38,in_x6), -1 < iVar9)) {
LAB_001090ac:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
      pPVar13 = __pyx_dict_cached_value_16852;
      kwargs = &__pyx_mstate_global_static;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16851) {
        if (__pyx_dict_cached_value_16852 == (PyObject *)0x0) {
          pPVar13 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_BoxRFID);
          goto LAB_00109458;
        }
        __pyx_dict_cached_value_16852->ob_refcnt = __pyx_dict_cached_value_16852->ob_refcnt + 1;
LAB_001090dc:
        p_Var14 = pPVar13->ob_type;
        if ((p_Var14 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
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
          goto LAB_0010918c;
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        func->ob_refcnt = lVar20;
        iVar9 = 0x1765;
        if (lVar20 == 0) {
          (*func->ob_type->tp_dealloc)(func);
        }
      }
      else {
        pPVar13 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_BoxRFID,
                             (uint64_t *)&__pyx_dict_version_16851,&__pyx_dict_cached_value_16852);
LAB_00109458:
        iVar9 = 0x1751;
        if (pPVar13 != (PyObject *)0x0) goto LAB_001090dc;
      }
      pPVar10 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.box_rfid.load_config_prefix",iVar9,0x6b,"box_rfid.py");
      goto LAB_0010918c;
    }
    iVar9 = 0x1719;
  }
LAB_00109170:
  pPVar10 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.box_rfid.load_config_prefix",iVar9,0x6a,"box_rfid.py");
LAB_0010918c:
  if (lVar16 == *(long *)PTR___stack_chk_guard_00123f48) {
    return pPVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 001095c8
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_7read_card_from_slot
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_7read_card_from_slot(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_7read_card_from_slot
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
  long lVar10;
  long *plVar11;
  setattrfunc *__s2;
  getattrofunc p_Var12;
  _typeobject *p_Var13;
  long lVar14;
  long lVar15;
  char *pcVar16;
  char *in_x6;
  uint uVar17;
  PyObject *func;
  _typeobject *p_Var18;
  PyObject *pPVar19;
  long lVar20;
  long lVar21;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar9 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00123fb8;
  puVar4 = PTR__Py_TrueStruct_00123f70;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00123f68;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar15 = *(long *)PTR___stack_chk_guard_00123f48;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  pPVar19 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_001096c8;
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
        p_Var13 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var13) {
          values[0] = *kwvalues;
        }
        else {
          lVar10 = 0;
          do {
            lVar21 = lVar10 + 1;
            if (lVar21 == lVar20) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar10 = 0;
              goto LAB_00109828;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar10;
            lVar10 = lVar21;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar21];
        }
        goto LAB_00109970;
      }
LAB_0010992c:
      values[0] = (PyObject *)0x0;
      goto LAB_00109930;
    }
    if (__pyx_nargs == 1) {
      lVar20 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_001096b4;
    }
  }
LAB_00109628:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","read_card_from_slot",
               "exactly",1,"",__pyx_nargs);
  iVar8 = 0xfc0;
  goto LAB_00109664;
  while( true ) {
    lVar21 = lVar10 + 1;
    if (lVar21 == lVar20) goto LAB_0010992c;
    p_Var13 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar10];
    lVar10 = lVar21;
    if ((_typeobject *)pPVar9 == p_Var13) break;
LAB_00109828:
    bVar6 = pPVar9->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var13->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar21 = lVar10;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar9 != (PyObject *)puVar3) && (bVar6 || p_Var13 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar9,p_Var13,2);
        if (plVar11 == (long *)0x0) goto LAB_0010992c;
        uVar17 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar11 != (long *)puVar3) {
          uVar17 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar14 = *plVar11;
        *plVar11 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_00109918:
        if (uVar17 != 0) {
          if ((int)uVar17 < 0) goto LAB_0010992c;
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
         ((-1 < (char)p_Var13->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var13), iVar8 < 0))))
      goto LAB_0010992c;
      lVar14 = pPVar9[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar14 == (p_Var13->ob_base).ob_size) &&
         ((pPVar9[1].ob_type == (_typeobject *)p_Var13->tp_name ||
          (_typeobject *)p_Var13->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar9[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar16 = (char *)((ulong)(byte)((byte)pPVar9[2].ob_refcnt >> 2) & 7);
        uVar17 = (uint)pcVar16;
        in_x6 = pcVar16;
        if (((byte)((byte)p_Var13->tp_basicsize >> 2) & 7) == uVar17) {
          bVar2 = (byte)pPVar9[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var18 = pPVar9[4].ob_type;
          }
          else {
            p_Var18 = (_typeobject *)&pPVar9[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var18 = (_typeobject *)(pPVar9 + 3);
            }
          }
          bVar2 = (byte)p_Var13->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var13->tp_setattr;
          }
          else {
            __s2 = &p_Var13->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var13->tp_dealloc;
            }
          }
          if (uVar17 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(p_Var18->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(byte *)__s2;
          }
          else if (uVar17 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(p_Var18->ob_base).ob_base.ob_refcnt;
            uVar17 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(p_Var18->ob_base).ob_base.ob_refcnt;
            uVar17 = *(uint *)__s2;
          }
          if (uVar17 == (uint)in_x6) {
            if (lVar14 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var18,__s2,(long)pcVar16 * lVar14);
              uVar17 = (uint)(iVar8 == 0);
              goto LAB_00109918;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar21];
LAB_00109970:
  if (values[0] != (PyObject *)0x0) {
    lVar20 = lVar20 + -1;
LAB_001096b4:
    if (0 < lVar20) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar19 = (PyObject *)values;
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar19,(PyObject **)__pyx_nargs,
                         0x111b68,in_x6);
      if (iVar8 < 0) {
        iVar8 = 0xfb5;
        goto LAB_00109664;
      }
    }
LAB_001096c8:
                    /* Unresolved local var: PyObject * __pyx_v_params@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var12 = values[0]->ob_type->tp_getattro;
    if (p_Var12 == (getattrofunc)0x0) {
      pPVar9 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar9 = (*p_Var12)(values[0],__pyx_mstate_global_static.__pyx_n_s_read_card);
    }
    if (pPVar9 == (PyObject *)0x0) {
      iVar8 = 0xfef;
    }
    else {
      p_Var13 = pPVar9->ob_type;
      if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (p_Var18 = pPVar9[1].ob_type, p_Var18 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        func = (PyObject *)pPVar9[1].ob_refcnt;
        (p_Var18->ob_base).ob_base.ob_refcnt = (p_Var18->ob_base).ob_base.ob_refcnt + 1;
        func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar20 = pPVar9->ob_refcnt + -1;
        pPVar9->ob_refcnt = lVar20;
        if (lVar20 == 0) {
          (*p_Var13->tp_dealloc)(pPVar9);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var18;
        pPVar19 = __Pyx_PyObject_FastCallDict(func,(PyObject **)__pyx_pyargnames,1,pPVar19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar20 = (p_Var18->ob_base).ob_base.ob_refcnt + -1;
        (p_Var18->ob_base).ob_base.ob_refcnt = lVar20;
        pPVar9 = func;
        if (lVar20 == 0) {
          (*((p_Var18->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var18);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar19 = __Pyx_PyObject_FastCallDict(pPVar9,(PyObject **)(__pyx_pyargnames + 1),0,pPVar19);
      }
      lVar20 = pPVar9->ob_refcnt + -1;
      if (pPVar19 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar9->ob_refcnt = lVar20;
        if (lVar20 == 0) {
          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if (pPVar19->ob_refcnt == 0) {
          (*pPVar19->ob_type->tp_dealloc)(pPVar19);
        }
        goto LAB_00109680;
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9->ob_refcnt = lVar20;
      iVar8 = 0x1003;
      if (lVar20 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
    }
    pPVar19 = (PyObject *)0x0;
    __Pyx_AddTraceback("extras.box_rfid.BoxRFID.read_card_from_slot",iVar8,0x29,"box_rfid.py");
    goto LAB_00109680;
  }
LAB_00109930:
  lVar20 = PyErr_Occurred();
  if (lVar20 == 0) goto LAB_00109628;
  iVar8 = 0xfb0;
LAB_00109664:
  pPVar19 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID.read_card_from_slot",iVar8,0x28,"box_rfid.py");
LAB_00109680:
  if (lVar15 == *(long *)PTR___stack_chk_guard_00123f48) {
    return pPVar19;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00109b50
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_13stop_read
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_13stop_read(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Exceeded maximum restarts with more pending */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_13stop_read
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyObject *apPVar6 [1];
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  PyObject *pPVar11;
  PyObject *pPVar12;
  PyObject *func;
  long *plVar13;
  PyObject **ppPVar14;
  long lVar15;
  _typeobject *p_Var16;
  setattrfunc *__s2;
  getattrofunc p_Var17;
  long lVar18;
  setattrofunc p_Var19;
  long lVar20;
  char *pcVar21;
  char *in_x6;
  int c_line;
  long lVar22;
  _typeobject *p_Var23;
  PyObject *pPVar24;
  long lVar25;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar12 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_00123fb8;
  puVar4 = PTR__Py_TrueStruct_00123f70;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_00123f68;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar20 = *(long *)PTR___stack_chk_guard_00123f48;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  pPVar11 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_00109c48;
    }
  }
  else {
    ppPVar14 = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar22 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar22) {
        p_Var16 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var16) {
          values[0] = *ppPVar14;
        }
        else {
          lVar15 = 0;
          do {
            lVar25 = lVar15 + 1;
            if (lVar25 == lVar22) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar15 = 0;
              goto LAB_0010a170;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar15;
            lVar15 = lVar25;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = ppPVar14[lVar25];
        }
        goto LAB_0010a314;
      }
LAB_0010a274:
      values[0] = (PyObject *)0x0;
      goto LAB_0010a278;
    }
    if (__pyx_nargs == 1) {
      lVar22 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_00109c38;
    }
  }
LAB_00109bac:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","stop_read","exactly",1
               ,"",__pyx_nargs);
  iVar9 = 0x1600;
  goto LAB_00109be8;
  while( true ) {
    lVar25 = lVar15 + 1;
    if (lVar25 == lVar22) goto LAB_0010a274;
    p_Var16 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar15];
    lVar15 = lVar25;
    if ((_typeobject *)pPVar12 == p_Var16) break;
LAB_0010a170:
    bVar7 = pPVar12->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var16->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar25 = lVar15;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar12 != (PyObject *)puVar3) && (bVar7 || p_Var16 != (_typeobject *)puVar3)) {
        plVar13 = (long *)PyObject_RichCompare(pPVar12,p_Var16,2);
        if (plVar13 == (long *)0x0) goto LAB_0010a274;
        uVar10 = (uint)(plVar13 == (long *)puVar4);
        if ((plVar13 != (long *)puVar4 && plVar13 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar13 != (long *)puVar3) {
          uVar10 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar18 = *plVar13;
        *plVar13 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_0010a260:
        if (uVar10 != 0) {
          if ((int)uVar10 < 0) goto LAB_0010a274;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar12[2].ob_refcnt) && (iVar9 = _PyUnicode_Ready(pPVar12), iVar9 < 0)) ||
         ((-1 < (char)p_Var16->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var16), iVar9 < 0))))
      goto LAB_0010a274;
      lVar18 = pPVar12[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar18 == (p_Var16->ob_base).ob_size) &&
         ((pPVar12[1].ob_type == (_typeobject *)p_Var16->tp_name ||
          (_typeobject *)p_Var16->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar12[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar21 = (char *)((ulong)(byte)((byte)pPVar12[2].ob_refcnt >> 2) & 7);
        uVar10 = (uint)pcVar21;
        in_x6 = pcVar21;
        if (((byte)((byte)p_Var16->tp_basicsize >> 2) & 7) == uVar10) {
          bVar2 = (byte)pPVar12[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var23 = pPVar12[4].ob_type;
          }
          else {
            p_Var23 = (_typeobject *)&pPVar12[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var23 = (_typeobject *)(pPVar12 + 3);
            }
          }
          bVar2 = (byte)p_Var16->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var16->tp_setattr;
          }
          else {
            __s2 = &p_Var16->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var16->tp_dealloc;
            }
          }
          if (uVar10 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(p_Var23->ob_base).ob_base.ob_refcnt;
            uVar10 = (uint)*(byte *)__s2;
          }
          else if (uVar10 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(p_Var23->ob_base).ob_base.ob_refcnt;
            uVar10 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(p_Var23->ob_base).ob_base.ob_refcnt;
            uVar10 = *(uint *)__s2;
          }
          if (uVar10 == (uint)in_x6) {
            if (lVar18 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var23,__s2,(long)pcVar21 * lVar18);
              uVar10 = (uint)(iVar9 == 0);
              goto LAB_0010a260;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = ppPVar14[lVar25];
LAB_0010a314:
  if (values[0] != (PyObject *)0x0) {
    lVar22 = lVar22 + -1;
LAB_00109c38:
    if (0 < lVar22) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar11 = (PyObject *)values;
      iVar9 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar14,__pyx_pyargnames,pPVar11,(PyObject **)__pyx_nargs,
                         0x111b98,in_x6);
      if (iVar9 < 0) {
        iVar9 = 0x15f5;
        goto LAB_00109be8;
      }
    }
LAB_00109c48:
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
                       Unresolved local var: int __pyx_clineno@[???] */
    apPVar6[0] = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var17 = values[0]->ob_type->tp_getattro;
    if (p_Var17 == (getattrofunc)0x0) {
      pPVar12 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar12 = (*p_Var17)(values[0],__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer);
    }
    if (pPVar12 == (PyObject *)0x0) {
      iVar9 = 99;
      c_line = 0x1631;
      goto LAB_0010a380;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar22 = pPVar12->ob_refcnt + -1;
    pPVar12->ob_refcnt = lVar22;
    if (lVar22 == 0) {
      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
    }
    if (pPVar12 == (PyObject *)PTR__Py_NoneStruct_00123f68) {
LAB_0010a0d8:
      pPVar11 = (PyObject *)PTR__Py_NoneStruct_00123f68;
      *(long *)PTR__Py_NoneStruct_00123f68 = *(long *)PTR__Py_NoneStruct_00123f68 + 1;
      goto LAB_00109c04;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var17 = apPVar6[0]->ob_type->tp_getattro;
    if (p_Var17 == (getattrofunc)0x0) {
      pPVar12 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar12 = (*p_Var17)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_had_get_value);
    }
    if (pPVar12 == (PyObject *)0x0) {
      iVar9 = 100;
      c_line = 0x163e;
    }
    else {
                    /* Unresolved local var: int is_true@[???] */
      uVar10 = (uint)(pPVar12 == (PyObject *)PTR__Py_TrueStruct_00123f70);
      if (((uVar10 == 0 && pPVar12 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
           pPVar12 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
         (uVar10 = PyObject_IsTrue(pPVar12), (int)uVar10 < 0)) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          iVar9 = 100;
          c_line = 0x1640;
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        else {
          iVar9 = 100;
          c_line = 0x1640;
        }
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          p_Var17 = apPVar6[0]->ob_type->tp_getattro;
          if (uVar10 == 0) goto LAB_00109d10;
LAB_00109ef4:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          if (p_Var17 == (getattrofunc)0x0) {
            func = (PyObject *)PyObject_GetAttr();
          }
          else {
            func = (*p_Var17)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_stepper);
          }
          if (func == (PyObject *)0x0) {
            iVar9 = 0x66;
            c_line = 0x1682;
            goto LAB_0010a380;
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = func->ob_type->tp_getattro;
          if (p_Var17 == (getattrofunc)0x0) {
            pPVar12 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar12 = (*p_Var17)(func,__pyx_mstate_global_static.__pyx_n_s_reactor);
          }
          lVar22 = func->ob_refcnt + -1;
          if (pPVar12 == (PyObject *)0x0) {
            iVar9 = 0x66;
            c_line = 0x1684;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            func->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*func->ob_type->tp_dealloc)(func);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var17 = pPVar12->ob_type->tp_getattro;
            if (p_Var17 == (getattrofunc)0x0) {
              func = (PyObject *)
                     PyObject_GetAttr(pPVar12,__pyx_mstate_global_static.__pyx_n_s_unregister_timer)
              ;
            }
            else {
              func = (PyObject *)(*p_Var17)();
            }
            lVar22 = pPVar12->ob_refcnt + -1;
            if (func == (PyObject *)0x0) {
              iVar9 = 0x66;
              c_line = 0x1687;
LAB_0010a438:
              pPVar12->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                func = (PyObject *)0x0;
LAB_0010a444:
                (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                if (func != (PyObject *)0x0) goto LAB_0010a330;
              }
              goto LAB_0010a380;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar12->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              p_Var17 = apPVar6[0]->ob_type->tp_getattro;
              if (p_Var17 == (getattrofunc)0x0) goto LAB_0010a534;
LAB_00109f90:
              pPVar12 = (*p_Var17)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer);
            }
            else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              p_Var17 = apPVar6[0]->ob_type->tp_getattro;
              if (p_Var17 != (getattrofunc)0x0) goto LAB_00109f90;
LAB_0010a534:
              pPVar12 = (PyObject *)PyObject_GetAttr();
            }
            if (pPVar12 == (PyObject *)0x0) {
              iVar9 = 0x66;
              c_line = 0x168a;
            }
            else {
              p_Var16 = func->ob_type;
              if ((p_Var16 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                 (p_Var23 = func[1].ob_type, p_Var23 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar24 = (PyObject *)func[1].ob_refcnt;
                (p_Var23->ob_base).ob_base.ob_refcnt = (p_Var23->ob_base).ob_base.ob_refcnt + 1;
                pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = func->ob_refcnt + -1;
                func->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*p_Var16->tp_dealloc)(func);
                }
                __pyx_pyargnames[0] = (PyObject **)p_Var23;
                __pyx_pyargnames[1] = (PyObject **)pPVar12;
                pPVar11 = __Pyx_PyObject_FastCallDict
                                    (pPVar24,(PyObject **)__pyx_pyargnames,2,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
                (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
                func = pPVar24;
                if (lVar22 == 0) {
                  (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
                }
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = (PyObject **)pPVar12;
                pPVar11 = __Pyx_PyObject_FastCallDict
                                    (func,(PyObject **)(__pyx_pyargnames + 1),1,pPVar11);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar12->ob_refcnt + -1;
              pPVar12->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              }
              if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = func->ob_refcnt + -1;
                func->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*func->ob_type->tp_dealloc)(func);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                p_Var19 = apPVar6[0]->ob_type->tp_setattro;
                if (p_Var19 == (setattrofunc)0x0) {
                  iVar9 = PyObject_SetAttr();
                }
                else {
                  iVar9 = (*p_Var19)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer
                                     ,(PyObject *)PTR__Py_NoneStruct_00123f68);
                }
                if (iVar9 < 0) {
                  iVar9 = 0x67;
                  c_line = 0x16ac;
                }
                else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var19 = apPVar6[0]->ob_type->tp_setattro;
                  if (p_Var19 == (setattrofunc)0x0) {
                    iVar9 = PyObject_SetAttr();
                  }
                  else {
                    iVar9 = (*p_Var19)(apPVar6[0],
                                       __pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,
                                       __pyx_mstate_global_static.__pyx_int_0);
                  }
                  if (-1 < iVar9) goto LAB_0010a0d8;
                  iVar9 = 0x68;
                  c_line = 0x16b5;
                }
                goto LAB_0010a380;
              }
              iVar9 = 0x66;
              c_line = 0x169f;
            }
          }
LAB_0010a330:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = func->ob_refcnt + -1;
          func->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            plVar13 = (long *)0x0;
LAB_0010a344:
            (*func->ob_type->tp_dealloc)(func);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
            if (plVar13 != (long *)0x0) goto LAB_0010a358;
          }
        }
        else {
          p_Var17 = apPVar6[0]->ob_type->tp_getattro;
          if (uVar10 != 0) goto LAB_00109ef4;
LAB_00109d10:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          if (p_Var17 == (getattrofunc)0x0) {
            pPVar12 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar12 = (*p_Var17)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_gcode);
          }
          if (pPVar12 == (PyObject *)0x0) {
            iVar9 = 0x65;
            c_line = 0x164c;
            goto LAB_0010a380;
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = pPVar12->ob_type->tp_getattro;
          if (p_Var17 == (getattrofunc)0x0) {
            func = (PyObject *)
                   PyObject_GetAttr(pPVar12,__pyx_mstate_global_static.__pyx_n_s_respond_info);
          }
          else {
            func = (PyObject *)(*p_Var17)();
          }
          lVar22 = pPVar12->ob_refcnt + -1;
          if (func == (PyObject *)0x0) {
            iVar9 = 0x65;
            c_line = 0x164e;
            goto LAB_0010a438;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar12->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = apPVar6[0]->ob_type->tp_getattro;
          if (p_Var17 == (getattrofunc)0x0) {
            pPVar12 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar12 = (*p_Var17)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_stepper);
          }
          if (pPVar12 == (PyObject *)0x0) {
            iVar9 = 0x65;
            c_line = 0x1651;
            goto LAB_0010a330;
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = pPVar12->ob_type->tp_getattro;
          if (p_Var17 == (getattrofunc)0x0) {
            plVar13 = (long *)PyObject_GetAttr(pPVar12,__pyx_mstate_global_static.
                                                       __pyx_n_s_stepper_label);
          }
          else {
            plVar13 = (long *)(*p_Var17)();
          }
          lVar22 = pPVar12->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar12->ob_refcnt = lVar22;
          if (plVar13 == (long *)0x0) {
            iVar9 = 0x65;
            c_line = 0x1653;
            if (lVar22 != 0) goto LAB_0010a330;
            goto LAB_0010a444;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if (lVar22 == 0) {
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
          if ((__pyx_mstate_global_static.__pyx_kp_s_s_did_not_recognize_the_filamen ==
               (PyObject *)PTR__Py_NoneStruct_00123f68) ||
             (pPVar11 = *(PyObject **)((undefined *)plVar13[1] + 0xa8),
             ((ulong)pPVar11 & 0x10000000) != 0 &&
             (undefined *)plVar13[1] != PTR_PyUnicode_Type_00123fb8)) {
            ppPVar14 = (PyObject **)
                       PyNumber_Remainder(__pyx_mstate_global_static.
                                          __pyx_kp_s_s_did_not_recognize_the_filamen,plVar13);
          }
          else {
            ppPVar14 = (PyObject **)
                       PyUnicode_Format(__pyx_mstate_global_static.
                                        __pyx_kp_s_s_did_not_recognize_the_filamen,plVar13);
          }
          if (ppPVar14 != (PyObject **)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = *plVar13;
            *plVar13 = lVar22 + -1;
            if (lVar22 + -1 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            p_Var16 = func->ob_type;
            if ((p_Var16 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
               (p_Var23 = func[1].ob_type, p_Var23 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar24 = (PyObject *)func[1].ob_refcnt;
              (p_Var23->ob_base).ob_base.ob_refcnt = (p_Var23->ob_base).ob_base.ob_refcnt + 1;
              pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = func->ob_refcnt + -1;
              func->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*p_Var16->tp_dealloc)(func);
              }
              __pyx_pyargnames[0] = (PyObject **)p_Var23;
              __pyx_pyargnames[1] = ppPVar14;
              pPVar12 = __Pyx_PyObject_FastCallDict(pPVar24,(PyObject **)__pyx_pyargnames,2,pPVar11)
              ;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
              (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
              func = pPVar24;
              if (lVar22 == 0) {
                (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = ppPVar14;
              pPVar12 = __Pyx_PyObject_FastCallDict
                                  (func,(PyObject **)(__pyx_pyargnames + 1),1,pPVar11);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar24 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
            *ppPVar14 = pPVar24;
            if (pPVar24 == (PyObject *)0x0) {
              (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
            }
            if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = func->ob_refcnt + -1;
              func->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*func->ob_type->tp_dealloc)(func);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar12->ob_refcnt + -1;
              pPVar12->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              }
              p_Var17 = apPVar6[0]->ob_type->tp_getattro;
              goto LAB_00109ef4;
            }
            iVar9 = 0x65;
            c_line = 0x166c;
            goto LAB_0010a330;
          }
          lVar22 = func->ob_refcnt + -1;
          func->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            c_line = 0x1656;
            iVar9 = 0x65;
            goto LAB_0010a344;
          }
          iVar9 = 0x65;
          c_line = 0x1656;
LAB_0010a358:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = *plVar13;
          *plVar13 = lVar22 + -1;
          if (lVar22 + -1 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
        }
      }
    }
LAB_0010a380:
    __Pyx_AddTraceback("extras.box_rfid.BoxRFID.stop_read",c_line,iVar9,"box_rfid.py");
    pPVar11 = (PyObject *)0x0;
    goto LAB_00109c04;
  }
LAB_0010a278:
  lVar22 = PyErr_Occurred();
  if (lVar22 == 0) goto LAB_00109bac;
  iVar9 = 0x15f0;
LAB_00109be8:
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID.stop_read",iVar9,0x62,"box_rfid.py");
  pPVar11 = (PyObject *)0x0;
LAB_00109c04:
  if (lVar20 == *(long *)PTR___stack_chk_guard_00123f48) {
    return pPVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010a770
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_3_build_config
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_3_build_config(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_3_build_config
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  PyObject *apPVar7 [1];
  bool bVar8;
  bool bVar9;
  int iVar10;
  PyObject *pPVar11;
  PyObject *func;
  PyObject *pPVar12;
  long lVar13;
  long *plVar14;
  _typeobject *p_Var15;
  setattrfunc *__s2;
  getattrofunc p_Var16;
  long lVar17;
  setattrofunc p_Var18;
  long lVar19;
  char *pcVar20;
  char *in_x6;
  uint uVar21;
  PyObject *pPVar22;
  ternaryfunc p_Var23;
  long lVar24;
  _typeobject *p_Var25;
  int iVar26;
  long lVar27;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar11 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar6 = PTR_PyUnicode_Type_00123fb8;
  puVar5 = PTR__Py_TrueStruct_00123f70;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar4 = PTR__Py_NoneStruct_00123f68;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar19 = *(long *)PTR___stack_chk_guard_00123f48;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  pPVar22 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_0010a86c;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar24 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar24) {
        p_Var15 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var15) {
          values[0] = *kwvalues;
        }
        else {
          lVar13 = 0;
          do {
            lVar27 = lVar13 + 1;
            if (lVar27 == lVar24) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar13 = 0;
              goto LAB_0010ac08;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar13;
            lVar13 = lVar27;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar27];
        }
        goto LAB_0010adc4;
      }
LAB_0010ad0c:
      values[0] = (PyObject *)0x0;
      goto LAB_0010ad10;
    }
    if (__pyx_nargs == 1) {
      lVar24 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_0010a85c;
    }
  }
LAB_0010a7cc:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_build_config",
               "exactly",1,"",__pyx_nargs);
  iVar10 = 0xe1e;
  goto LAB_0010a808;
  while( true ) {
    lVar27 = lVar13 + 1;
    if (lVar27 == lVar24) goto LAB_0010ad0c;
    p_Var15 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar13];
    lVar13 = lVar27;
    if ((_typeobject *)pPVar11 == p_Var15) break;
LAB_0010ac08:
    bVar8 = pPVar11->ob_type != (_typeobject *)puVar6;
    bVar9 = (p_Var15->ob_base).ob_base.ob_type != (_typeobject *)puVar6;
    lVar27 = lVar13;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar11 != (PyObject *)puVar4) && (bVar8 || p_Var15 != (_typeobject *)puVar4)) {
        plVar14 = (long *)PyObject_RichCompare(pPVar11,p_Var15,2);
        if (plVar14 == (long *)0x0) goto LAB_0010ad0c;
        uVar21 = (uint)(plVar14 == (long *)puVar5);
        if ((plVar14 != (long *)puVar5 && plVar14 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar14 != (long *)puVar4) {
          uVar21 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar17 = *plVar14;
        *plVar14 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_0010acf8:
        if (uVar21 != 0) {
          if ((int)uVar21 < 0) goto LAB_0010ad0c;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar11[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar11), iVar10 < 0)) ||
         ((-1 < (char)p_Var15->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var15), iVar10 < 0))))
      goto LAB_0010ad0c;
      lVar17 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar17 == (p_Var15->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var15->tp_name ||
          (_typeobject *)p_Var15->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar20 = (char *)((ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7);
        uVar21 = (uint)pcVar20;
        in_x6 = pcVar20;
        if (((byte)((byte)p_Var15->tp_basicsize >> 2) & 7) == uVar21) {
          bVar2 = (byte)pPVar11[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var25 = pPVar11[4].ob_type;
          }
          else {
            p_Var25 = (_typeobject *)&pPVar11[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var25 = (_typeobject *)(pPVar11 + 3);
            }
          }
          bVar2 = (byte)p_Var15->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var15->tp_setattr;
          }
          else {
            __s2 = &p_Var15->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var15->tp_dealloc;
            }
          }
          if (uVar21 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(byte *)__s2;
          }
          else if (uVar21 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar21 = *(uint *)__s2;
          }
          if (uVar21 == (uint)in_x6) {
            if (lVar17 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var25,__s2,(long)pcVar20 * lVar17);
              uVar21 = (uint)(iVar10 == 0);
              goto LAB_0010acf8;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar27];
LAB_0010adc4:
  if (values[0] != (PyObject *)0x0) {
    lVar24 = lVar24 + -1;
LAB_0010a85c:
    if (0 < lVar24) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar22 = (PyObject *)values;
      iVar10 = __Pyx_ParseOptionalKeywords
                         (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar22,(PyObject **)__pyx_nargs,
                          0x111bc0,in_x6);
      if (iVar10 < 0) {
        iVar10 = 0xe13;
        goto LAB_0010a808;
      }
    }
LAB_0010a86c:
                    /* Unresolved local var: PyObject * __pyx_v_cmdqueue@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    apPVar7[0] = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var16 = values[0]->ob_type->tp_getattro;
    if (p_Var16 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var16)(values[0],__pyx_mstate_global_static.__pyx_n_s_spi);
    }
    if (pPVar11 == (PyObject *)0x0) {
      __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",0xe4d,0x1d,"box_rfid.py");
      pPVar22 = (PyObject *)0x0;
      goto LAB_0010a824;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var16 = pPVar11->ob_type->tp_getattro;
    if (p_Var16 == (getattrofunc)0x0) {
      func = (PyObject *)PyObject_GetAttr();
    }
    else {
      func = (*p_Var16)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_get_command_queue);
    }
    lVar24 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar24;
    if (func == (PyObject *)0x0) {
      if (lVar24 != 0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",0xe4f,0x1d,"box_rfid.py");
        goto LAB_0010a824;
      }
      pPVar12 = (PyObject *)0x0;
      iVar26 = 0x1d;
      iVar10 = 0xe4f;
      goto LAB_0010ade4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if (lVar24 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    p_Var15 = func->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
       (p_Var25 = func[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)func[1].ob_refcnt;
      (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*p_Var15->tp_dealloc)(func);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var25;
      pPVar12 = __Pyx_PyObject_FastCallDict(pPVar11,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
      (p_Var25->ob_base).ob_base.ob_refcnt = lVar24;
      func = pPVar11;
      if (lVar24 == 0) {
        (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar12 = __Pyx_PyObject_FastCallDict(func,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22);
    }
    if (pPVar12 == (PyObject *)0x0) {
      lVar24 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar24;
      if (lVar24 != 0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",0xe64,0x1d,"box_rfid.py");
        goto LAB_0010a824;
      }
      iVar10 = 0xe64;
      iVar26 = 0x1d;
LAB_0010ae08:
      (*func->ob_type->tp_dealloc)(func);
      goto LAB_0010ae18;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar24 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar24;
    if (lVar24 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var16 = apPVar7[0]->ob_type->tp_getattro;
    if (p_Var16 == (getattrofunc)0x0) {
      pPVar22 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar22 = (*p_Var16)(apPVar7[0],__pyx_mstate_global_static.__pyx_n_s_mcu);
    }
    if (pPVar22 == (PyObject *)0x0) {
      pPVar22 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",0xe72,0x1e,"box_rfid.py");
      goto LAB_0010ab64;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var16 = pPVar22->ob_type->tp_getattro;
    if (p_Var16 == (getattrofunc)0x0) {
      func = (PyObject *)PyObject_GetAttr();
    }
    else {
      func = (*p_Var16)(pPVar22,__pyx_mstate_global_static.__pyx_n_s_lookup_query_command);
    }
    lVar24 = pPVar22->ob_refcnt + -1;
    if (func == (PyObject *)0x0) {
      iVar10 = 0xe74;
      iVar26 = 0x1e;
LAB_0010af2c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      if (func != (PyObject *)0x0) {
LAB_0010af50:
        lVar24 = func->ob_refcnt + -1;
        func->ob_refcnt = lVar24;
        if (lVar24 == 0) goto LAB_0010ae08;
      }
      pPVar22 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",iVar10,iVar26,"box_rfid.py");
    }
    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      pPVar22 = (PyObject *)PyDict_New();
      if (pPVar22 == (PyObject *)0x0) {
        iVar26 = 0x21;
        iVar10 = 0xe7f;
        goto LAB_0010af50;
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var16 = apPVar7[0]->ob_type->tp_getattro;
      if (p_Var16 == (getattrofunc)0x0) {
        pPVar11 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar11 = (*p_Var16)(apPVar7[0],__pyx_mstate_global_static.__pyx_n_s_oid);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar10 = 0xe81;
        iVar26 = 0x21;
        lVar24 = pPVar22->ob_refcnt + -1;
        goto LAB_0010af2c;
      }
      iVar10 = PyDict_SetItem(pPVar22,__pyx_mstate_global_static.__pyx_n_s_oid,pPVar11);
      if (-1 < iVar10) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        iVar10 = PyDict_SetItem(pPVar22,__pyx_mstate_global_static.__pyx_n_s_cq,pPVar12);
        pPVar11 = __pyx_mstate_global_static.__pyx_tuple_;
        if (iVar10 < 0) {
          iVar10 = 0xe85;
          iVar26 = 0x21;
          lVar24 = pPVar22->ob_refcnt + -1;
          goto LAB_0010af2c;
        }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
        p_Var23 = func->ob_type->tp_call;
        if (p_Var23 != (ternaryfunc)0x0) {
          lVar24 = PyThreadState_Get();
          puVar4 = PTR__Py_CheckRecursionLimit_00123f28;
          iVar10 = *(int *)(lVar24 + 0x20) + 1;
          *(int *)(lVar24 + 0x20) = iVar10;
          if ((iVar10 <= *(int *)puVar4) ||
             (iVar10 = _Py_CheckRecursiveCall(" while calling a Python object"), iVar10 == 0)) {
            pPVar11 = (*p_Var23)(func,pPVar11,pPVar22);
            lVar24 = PyThreadState_Get();
            puVar4 = PTR__Py_CheckRecursionLimit_00123f28;
            iVar3 = *(int *)(lVar24 + 0x20) + -1;
            *(int *)(lVar24 + 0x20) = iVar3;
            iVar26 = *(int *)puVar4;
            iVar10 = (iVar26 >> 2) * 3;
            if (200 < iVar26) {
              iVar10 = iVar26 + -0x32;
            }
            if (iVar3 < iVar10) {
              lVar24 = PyThreadState_Get();
              *(undefined1 *)(lVar24 + 0x24) = 0;
            }
            if (pPVar11 != (PyObject *)0x0) goto LAB_0010aae8;
            lVar24 = PyErr_Occurred();
            if (lVar24 == 0) {
              iVar10 = 0xe8e;
              iVar26 = 0x1e;
              PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_00123ee8,
                              "NULL result without error in PyObject_Call");
              lVar24 = pPVar22->ob_refcnt + -1;
              goto LAB_0010af2c;
            }
          }
LAB_0010b070:
          iVar10 = 0xe8e;
          iVar26 = 0x1e;
          lVar24 = pPVar22->ob_refcnt + -1;
          goto LAB_0010af2c;
        }
        pPVar11 = (PyObject *)PyObject_Call(func,__pyx_mstate_global_static.__pyx_tuple_,pPVar22);
        if (pPVar11 == (PyObject *)0x0) goto LAB_0010b070;
LAB_0010aae8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = func->ob_refcnt + -1;
        func->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*func->ob_type->tp_dealloc)(func);
          lVar24 = pPVar22->ob_refcnt + -1;
          pPVar22->ob_refcnt = lVar24;
          if (lVar24 != 0) goto LAB_0010ab08;
LAB_0010ad38:
          (*pPVar22->ob_type->tp_dealloc)(pPVar22);
          p_Var18 = apPVar7[0]->ob_type->tp_setattro;
          if (p_Var18 != (setattrofunc)0x0) goto LAB_0010ab24;
LAB_0010b050:
          iVar10 = PyObject_SetAttr();
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar24 = pPVar22->ob_refcnt + -1;
          pPVar22->ob_refcnt = lVar24;
          if (lVar24 == 0) goto LAB_0010ad38;
LAB_0010ab08:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var18 = apPVar7[0]->ob_type->tp_setattro;
          if (p_Var18 == (setattrofunc)0x0) goto LAB_0010b050;
LAB_0010ab24:
          iVar10 = (*p_Var18)(apPVar7[0],__pyx_mstate_global_static.__pyx_n_s_fm17550_read_card,
                              pPVar11);
        }
        lVar24 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar24;
        if (iVar10 < 0) {
          if (lVar24 == 0) {
            func = (PyObject *)0x0;
            iVar26 = 0x1e;
            iVar10 = 0xe92;
            goto LAB_0010ade4;
          }
          pPVar22 = (PyObject *)0x0;
          __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",0xe92,0x1e,"box_rfid.py");
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if (lVar24 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          pPVar22 = (PyObject *)PTR__Py_NoneStruct_00123f68;
          *(long *)PTR__Py_NoneStruct_00123f68 = *(long *)PTR__Py_NoneStruct_00123f68 + 1;
        }
        goto LAB_0010ab64;
      }
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        iVar26 = 0x21;
        iVar10 = 0xe83;
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
        lVar24 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar24;
        if (lVar24 == 0) goto LAB_0010ade4;
LAB_0010adf8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = func->ob_refcnt + -1;
        func->ob_refcnt = lVar24;
        if (lVar24 == 0) goto LAB_0010ae08;
LAB_0010ae18:
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",iVar10,iVar26,"box_rfid.py");
        if (pPVar12 == (PyObject *)0x0) goto LAB_0010a824;
      }
      else {
        iVar26 = 0x21;
        iVar10 = 0xe83;
        lVar24 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar24;
        if (lVar24 == 0) {
LAB_0010ade4:
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (func != (PyObject *)0x0) goto LAB_0010adf8;
          goto LAB_0010ae18;
        }
        lVar24 = func->ob_refcnt + -1;
        func->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          iVar10 = 0xe83;
          iVar26 = 0x21;
          goto LAB_0010ae08;
        }
        __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",0xe83,0x21,"box_rfid.py");
      }
      pPVar22 = (PyObject *)0x0;
    }
LAB_0010ab64:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar24 = pPVar12->ob_refcnt + -1;
    pPVar12->ob_refcnt = lVar24;
    if (lVar24 == 0) {
      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
    }
    goto LAB_0010a824;
  }
LAB_0010ad10:
  lVar24 = PyErr_Occurred();
  if (lVar24 == 0) goto LAB_0010a7cc;
  iVar10 = 0xe0e;
LAB_0010a808:
  pPVar22 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID._build_config",iVar10,0x1c,"box_rfid.py");
LAB_0010a824:
  if (lVar19 != *(long *)PTR___stack_chk_guard_00123f48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar22;
}


/* ================================================================
 * Address: 0010b290
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_9_schedule_rfid_read
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_9_schedule_rfid_read(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_9_schedule_rfid_read
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
  int iVar9;
  int iVar10;
  PyObject *pPVar11;
  PyObject *pPVar12;
  PyObject *pPVar13;
  PyObject *pPVar14;
  PyObject **ppPVar15;
  PyObject *pPVar16;
  undefined1 *puVar17;
  long *plVar18;
  PyObject *pPVar19;
  setattrfunc *__s2;
  getattrofunc p_Var20;
  size_t *intval;
  setattrofunc p_Var21;
  PyObject *pPVar22;
  _typeobject **pp_Var23;
  char *pcVar24;
  long lVar25;
  uint uVar26;
  long lVar27;
  uint uVar28;
  _typeobject *p_Var29;
  _typeobject *p_Var30;
  PyObject *pPVar31;
  PyObject *pPVar32;
  PyObject *pPVar33;
  _typeobject *p_Var34;
  double dVar35;
  PyObject **local_50;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_eventtime@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar25 = *(long *)PTR___stack_chk_guard_00123f48;
  pp_Var23 = (_typeobject **)&__pyx_mstate_global_static.__pyx_n_s_eventtime;
  iVar10 = 0x124b00;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_eventtime;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar22 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0010b300;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_0010b39c;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar15 = __pyx_args + __pyx_nargs;
  pcVar24 = PTR___stack_chk_guard_00123f48;
  if (__pyx_nargs == 1) {
    pPVar33 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar22 = pPVar33;
LAB_0010bc00:
    pPVar16 = __pyx_mstate_global_static.__pyx_n_s_eventtime;
    puVar5 = PTR_PyUnicode_Type_00123fb8;
    puVar4 = PTR__Py_TrueStruct_00123f70;
    puVar3 = PTR__Py_NoneStruct_00123f68;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar33) {
      p_Var30 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_eventtime == p_Var30) {
        values[1] = *ppPVar15;
      }
      else {
        pp_Var23 = &__pyx_kwds[1].ob_type;
        pPVar11 = (PyObject *)0x0;
        do {
          pPVar32 = (PyObject *)((long)&pPVar11->ob_refcnt + 1);
          if (pPVar33 == pPVar32) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar33 = (PyObject *)0x0;
            goto LAB_0010bc68;
          }
          pPVar11 = pPVar32;
        } while ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_eventtime !=
                 pp_Var23[(long)pPVar32]);
        values[1] = ppPVar15[(long)pPVar32];
      }
      goto LAB_0010be38;
    }
LAB_0010bee8:
    values[1] = (PyObject *)0x0;
    goto LAB_0010beec;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar17 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    iVar10 = 0x124b00;
    goto LAB_0010bbc8;
  }
  if (__pyx_nargs == 0) {
    lVar27 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar15,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar33 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      pPVar22 = (PyObject *)(lVar27 + -1);
      goto LAB_0010bc00;
    }
    lVar27 = PyErr_Occurred();
    if (lVar27 != 0) {
      iVar10 = 0x106c;
      goto LAB_0010b33c;
    }
  }
LAB_0010b300:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_schedule_rfid_read",
               "exactly",2,"s",__pyx_nargs);
  iVar10 = 0x1088;
  goto LAB_0010b33c;
  while( true ) {
    bVar6 = pPVar33 == pPVar11;
    pPVar2 = &pPVar33->ob_refcnt;
    pPVar33 = (PyObject *)((long)pPVar2 + 1);
    if (bVar6) goto LAB_0010bee8;
    p_Var30 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar2];
    if ((_typeobject *)pPVar16 == p_Var30) break;
LAB_0010bc68:
    bVar6 = pPVar16->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var30->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar16 != (PyObject *)puVar3) && (bVar6 || p_Var30 != (_typeobject *)puVar3)) {
        plVar18 = (long *)PyObject_RichCompare(pPVar16,p_Var30,2);
        if (plVar18 == (long *)0x0) goto LAB_0010bee8;
        uVar28 = (uint)(plVar18 == (long *)puVar4);
        if ((plVar18 != (long *)puVar4 && plVar18 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar18 != (long *)puVar3) {
          uVar28 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = *plVar18;
        *plVar18 = lVar27 + -1;
        if (lVar27 + -1 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
LAB_0010bedc:
        if (uVar28 != 0) {
          if ((int)uVar28 < 0) goto LAB_0010bee8;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar16[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar16), iVar10 < 0)) ||
         ((-1 < (char)p_Var30->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var30), iVar10 < 0))))
      goto LAB_0010bee8;
      lVar27 = pPVar16[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar27 == (p_Var30->ob_base).ob_size) &&
         ((pPVar16[1].ob_type == (_typeobject *)p_Var30->tp_name ||
          (_typeobject *)p_Var30->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar16[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar24 = (char *)((ulong)(byte)((byte)pPVar16[2].ob_refcnt >> 2) & 7);
        uVar28 = (uint)pcVar24;
        if (((byte)((byte)p_Var30->tp_basicsize >> 2) & 7) == uVar28) {
          bVar1 = (byte)pPVar16[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            p_Var29 = pPVar16[4].ob_type;
          }
          else {
            p_Var29 = (_typeobject *)&pPVar16[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              p_Var29 = (_typeobject *)(pPVar16 + 3);
            }
          }
          bVar1 = (byte)p_Var30->tp_basicsize;
          if ((bVar1 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var30->tp_setattr;
          }
          else {
            __s2 = &p_Var30->tp_setattr;
            if ((bVar1 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var30->tp_dealloc;
            }
          }
          if (uVar28 == 1) {
            uVar28 = (uint)(byte)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar26 = (uint)*(byte *)__s2;
          }
          else if (uVar28 == 2) {
            uVar28 = (uint)(ushort)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar26 = (uint)*(ushort *)__s2;
          }
          else {
            uVar28 = (uint)(p_Var29->ob_base).ob_base.ob_refcnt;
            uVar26 = *(uint *)__s2;
          }
          if (uVar26 == uVar28) {
            if (lVar27 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var29,__s2,(long)pcVar24 * lVar27);
              uVar28 = (uint)(iVar10 == 0);
              goto LAB_0010bedc;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar15[(long)pPVar33];
  pp_Var23 = (_typeobject **)puVar3;
LAB_0010be38:
  if (values[1] != (PyObject *)0x0) {
    puVar17 = (undefined1 *)((long)&pPVar22[-1].ob_type + 7);
    iVar10 = (int)pp_Var23;
LAB_0010bbc8:
    if (0 < (long)puVar17) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar22 = (PyObject *)values;
      iVar9 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar15,__pyx_pyargnames,pPVar22,(PyObject **)__pyx_nargs,
                         0x111be8,pcVar24);
      iVar10 = (int)__pyx_nargs;
      if (iVar9 < 0) {
        iVar10 = 0x107b;
        goto LAB_0010b33c;
      }
    }
LAB_0010b39c:
                    /* Unresolved local var: PyObject * __pyx_v_params@[???]
                       Unresolved local var: PyObject * __pyx_v_data@[???]
                       Unresolved local var: PyObject * __pyx_v_filament@[???]
                       Unresolved local var: PyObject * __pyx_v_color@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: int __pyx_t_4@[???]
                       Unresolved local var: int __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: wchar_t __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar16 = values[1];
    pPVar33 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var20 = values[0]->ob_type->tp_getattro;
    if (p_Var20 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var20)(values[0],__pyx_mstate_global_static.__pyx_n_s_rfid_read_start_time);
    }
    if (pPVar11 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      iVar9 = 0x2c;
      iVar10 = 0x10bd;
      pPVar22 = (PyObject *)0x0;
      goto LAB_0010bfb0;
    }
    pPVar12 = (PyObject *)PyNumber_Subtract(pPVar16,pPVar11);
    if (pPVar12 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      pPVar22 = (PyObject *)0x0;
      iVar10 = 0x10bf;
      iVar9 = 0x2c;
      goto LAB_0010c080;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var20 = pPVar33->ob_type->tp_getattro;
    if (p_Var20 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_max_read_time);
    }
    if (pPVar11 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      pPVar22 = (PyObject *)0x0;
      pPVar14 = (PyObject *)0x0;
      iVar9 = 0x2c;
      iVar10 = 0x10c2;
      pPVar13 = (PyObject *)0x0;
      goto LAB_0010c134;
    }
    pPVar13 = (PyObject *)PyObject_RichCompare(pPVar12,pPVar11,4);
    if (pPVar13 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      iVar10 = 0x10c4;
      iVar9 = 0x2c;
      pPVar22 = (PyObject *)0x0;
      goto LAB_0010c080;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar12->ob_refcnt + -1;
    pPVar12->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: int is_true@[???] */
    uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
    if (((pPVar13 != (PyObject *)PTR__Py_TrueStruct_00123f70 &&
         pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
         pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
       (uVar28 = PyObject_IsTrue(pPVar13), (int)uVar28 < 0)) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      pPVar22 = (PyObject *)0x0;
      iVar9 = 0x2c;
      iVar10 = 0x10c7;
      goto LAB_0010bf70;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar13->ob_refcnt + -1;
    pPVar13->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
    }
    if (uVar28 != 0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var21 = pPVar33->ob_type->tp_setattro;
      if (p_Var21 == (setattrofunc)0x0) {
        iVar10 = PyObject_SetAttr();
      }
      else {
        iVar10 = (*p_Var21)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer,
                            (PyObject *)PTR__Py_NoneStruct_00123f68);
      }
      if (iVar10 < 0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        pPVar22 = (PyObject *)0x0;
        iVar9 = 0x2d;
        iVar10 = 0x10d2;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        pPVar22 = (PyObject *)pPVar33->ob_type->tp_setattro;
        if (pPVar22 == (PyObject *)0x0) {
          iVar10 = PyObject_SetAttr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,
                                    __pyx_mstate_global_static.__pyx_int_0);
        }
        else {
          iVar10 = (*(code *)pPVar22)();
        }
        if (iVar10 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          pPVar22 = (PyObject *)0x0;
          iVar9 = 0x2e;
          iVar10 = 0x10db;
        }
        else {
          pPVar13 = __Pyx_PyObject_GetAttrStr
                              (pPVar33,__pyx_mstate_global_static.__pyx_n_s_had_get_value);
          if (pPVar13 == (PyObject *)0x0) {
            pPVar31 = (PyObject *)0x0;
            pPVar32 = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
            iVar9 = 0x2f;
            iVar10 = 0x10e4;
            pPVar22 = (PyObject *)0x0;
          }
          else {
                    /* Unresolved local var: int is_true@[???] */
            uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
            if (((uVar28 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
                 pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
               (uVar28 = PyObject_IsTrue(), (int)uVar28 < 0)) {
              pPVar31 = (PyObject *)0x0;
              pPVar32 = (PyObject *)0x0;
              pPVar16 = (PyObject *)0x0;
              pPVar22 = (PyObject *)0x0;
              iVar9 = 0x2f;
              iVar10 = 0x10e6;
              goto LAB_0010bf70;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar13->ob_refcnt + -1;
            pPVar13->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
            }
            if (uVar28 == 0) {
              pPVar11 = __Pyx_PyObject_GetAttrStr
                                  (pPVar33,__pyx_mstate_global_static.__pyx_n_s_gcode);
              if (pPVar11 != (PyObject *)0x0) {
                pPVar12 = __Pyx_PyObject_GetAttrStr
                                    (pPVar11,__pyx_mstate_global_static.__pyx_n_s_respond_info);
                if (pPVar12 == (PyObject *)0x0) {
                  pPVar31 = (PyObject *)0x0;
                  pPVar32 = (PyObject *)0x0;
                  pPVar16 = (PyObject *)0x0;
                  pPVar22 = (PyObject *)0x0;
                  iVar10 = 0x10f4;
                  iVar9 = 0x30;
                  goto LAB_0010c080;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar27 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar27;
                if (lVar27 == 0) {
                  (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                }
                pPVar11 = __Pyx_PyObject_GetAttrStr
                                    (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
                if (pPVar11 == (PyObject *)0x0) {
                  pPVar31 = (PyObject *)0x0;
                  pPVar32 = (PyObject *)0x0;
                  pPVar16 = (PyObject *)0x0;
                  pPVar22 = (PyObject *)0x0;
                  pPVar14 = (PyObject *)0x0;
                  iVar9 = 0x30;
                  iVar10 = 0x10f7;
                  pPVar13 = (PyObject *)0x0;
                }
                else {
                  pPVar14 = __Pyx_PyObject_GetAttrStr
                                      (pPVar11,__pyx_mstate_global_static.__pyx_n_s_stepper_label);
                  if (pPVar14 == (PyObject *)0x0) {
                    pPVar31 = (PyObject *)0x0;
                    pPVar32 = (PyObject *)0x0;
                    pPVar16 = (PyObject *)0x0;
                    iVar10 = 0x10f9;
                    iVar9 = 0x30;
                    pPVar22 = (PyObject *)0x0;
                    goto LAB_0010c080;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = pPVar11->ob_refcnt + -1;
                  pPVar11->ob_refcnt = lVar27;
                  if (lVar27 == 0) {
                    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                  }
                  if ((__pyx_mstate_global_static.__pyx_kp_s_s_did_not_recognize_the_filamen ==
                       (PyObject *)PTR__Py_NoneStruct_00123f68) ||
                     ((pPVar14->ob_type->tp_flags & 0x10000000) != 0 &&
                      pPVar14->ob_type != (_typeobject *)PTR_PyUnicode_Type_00123fb8)) {
                    ppPVar15 = (PyObject **)
                               PyNumber_Remainder(__pyx_mstate_global_static.
                                                  __pyx_kp_s_s_did_not_recognize_the_filamen,pPVar14
                                                 );
                  }
                  else {
                    ppPVar15 = (PyObject **)
                               PyUnicode_Format(__pyx_mstate_global_static.
                                                __pyx_kp_s_s_did_not_recognize_the_filamen,pPVar14);
                  }
                  if (ppPVar15 != (PyObject **)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = pPVar14->ob_refcnt + -1;
                    pPVar14->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
                    }
                    p_Var30 = pPVar12->ob_type;
                    if ((p_Var30 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                       (p_Var29 = pPVar12[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar11 = (PyObject *)pPVar12[1].ob_refcnt;
                      (p_Var29->ob_base).ob_base.ob_refcnt =
                           (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar27 = pPVar12->ob_refcnt + -1;
                      pPVar12->ob_refcnt = lVar27;
                      if (lVar27 == 0) {
                        (*p_Var30->tp_dealloc)(pPVar12);
                      }
                      __pyx_pyargnames[0] = (PyObject **)p_Var29;
                      __pyx_pyargnames[1] = ppPVar15;
                      pPVar16 = __Pyx_PyObject_FastCallDict
                                          (pPVar11,(PyObject **)__pyx_pyargnames,2,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar27 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var29->ob_base).ob_base.ob_refcnt = lVar27;
                      pPVar12 = pPVar11;
                      if (lVar27 == 0) {
                        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = ppPVar15;
                      pPVar16 = __Pyx_PyObject_FastCallDict
                                          (pPVar12,(PyObject **)(__pyx_pyargnames + 1),1,pPVar22);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar11 = (PyObject *)((long)&(*ppPVar15)[-1].ob_type + 7);
                    *ppPVar15 = pPVar11;
                    if (pPVar11 == (PyObject *)0x0) {
                      (*(code *)ppPVar15[1][3].ob_refcnt)(ppPVar15);
                    }
                    if (pPVar16 == (PyObject *)0x0) {
                      pPVar31 = (PyObject *)0x0;
                      pPVar32 = (PyObject *)0x0;
                      pPVar16 = (PyObject *)0x0;
                      iVar9 = 0x30;
                      iVar10 = 0x1112;
                      pPVar22 = (PyObject *)0x0;
                      goto LAB_0010c0a4;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = pPVar12->ob_refcnt + -1;
                    pPVar12->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = pPVar16->ob_refcnt + -1;
                    pPVar16->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                    }
                    goto LAB_0010b770;
                  }
                  pPVar31 = (PyObject *)0x0;
                  pPVar32 = (PyObject *)0x0;
                  pPVar16 = (PyObject *)0x0;
                  pPVar22 = (PyObject *)0x0;
                  iVar9 = 0x30;
                  iVar10 = 0x10fc;
                  pPVar13 = (PyObject *)0x0;
                }
                goto LAB_0010c134;
              }
              pPVar31 = (PyObject *)0x0;
              pPVar32 = (PyObject *)0x0;
              pPVar16 = (PyObject *)0x0;
              iVar9 = 0x30;
              iVar10 = 0x10f2;
              pPVar22 = (PyObject *)0x0;
            }
            else {
LAB_0010b770:
              pPVar12 = __Pyx_PyObject_GetAttrStr
                                  (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stop_read);
              if (pPVar12 == (PyObject *)0x0) {
                pPVar31 = (PyObject *)0x0;
                pPVar32 = (PyObject *)0x0;
                pPVar16 = (PyObject *)0x0;
                iVar9 = 0x31;
                iVar10 = 0x1128;
                pPVar22 = (PyObject *)0x0;
              }
              else {
                p_Var30 = pPVar12->ob_type;
                if ((p_Var30 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                   (p_Var29 = pPVar12[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar16 = (PyObject *)pPVar12[1].ob_refcnt;
                  (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                  pPVar16->ob_refcnt = pPVar16->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = pPVar12->ob_refcnt + -1;
                  pPVar12->ob_refcnt = lVar27;
                  if (lVar27 == 0) {
                    (*p_Var30->tp_dealloc)(pPVar12);
                  }
                  __pyx_pyargnames[1] = (PyObject **)0x0;
                  __pyx_pyargnames[0] = (PyObject **)p_Var29;
                  pPVar22 = __Pyx_PyObject_FastCallDict
                                      (pPVar16,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var29->ob_base).ob_base.ob_refcnt = lVar27;
                  pPVar12 = pPVar16;
                  if (lVar27 == 0) {
                    (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                  }
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = (PyObject **)0x0;
                  pPVar22 = __Pyx_PyObject_FastCallDict
                                      (pPVar12,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22);
                }
                if (pPVar22 == (PyObject *)0x0) {
                  pPVar31 = (PyObject *)0x0;
                  pPVar32 = (PyObject *)0x0;
                  pPVar22 = (PyObject *)0x0;
                  iVar9 = 0x31;
                  iVar10 = 0x113c;
                  pPVar16 = (PyObject *)0x0;
                  goto LAB_0010c0a4;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar27 = pPVar12->ob_refcnt + -1;
                pPVar12->ob_refcnt = lVar27;
                if (lVar27 == 0) {
                  (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar27 = pPVar22->ob_refcnt + -1;
                pPVar22->ob_refcnt = lVar27;
                if (lVar27 == 0) {
                  (*pPVar22->ob_type->tp_dealloc)(pPVar22);
                }
                pPVar13 = __Pyx_PyObject_GetAttrStr
                                    (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
                if (pPVar13 != (PyObject *)0x0) {
                  pPVar12 = __Pyx_PyObject_GetAttrStr
                                      (pPVar13,__pyx_mstate_global_static.__pyx_n_s_reactor);
                  if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = pPVar13->ob_refcnt + -1;
                    pPVar13->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
                    }
                    pPVar33 = __Pyx_PyObject_GetAttrStr
                                        (pPVar12,__pyx_mstate_global_static.__pyx_n_s_NEVER);
                    if (pPVar33 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar27 = pPVar12->ob_refcnt + -1;
                      pPVar12->ob_refcnt = lVar27;
                      if (lVar27 == 0) {
                        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                      }
                      goto LAB_0010b358;
                    }
                    pPVar31 = (PyObject *)0x0;
                    pPVar32 = (PyObject *)0x0;
                    pPVar16 = (PyObject *)0x0;
                    pPVar22 = (PyObject *)0x0;
                    pPVar14 = (PyObject *)0x0;
                    iVar9 = 0x32;
                    iVar10 = 0x114f;
                    pPVar13 = (PyObject *)0x0;
                    goto LAB_0010c134;
                  }
                  pPVar31 = (PyObject *)0x0;
                  pPVar32 = (PyObject *)0x0;
                  pPVar16 = (PyObject *)0x0;
                  iVar9 = 0x32;
                  iVar10 = 0x114c;
                  pPVar22 = (PyObject *)0x0;
                  goto LAB_0010bf70;
                }
                pPVar31 = (PyObject *)0x0;
                pPVar32 = (PyObject *)0x0;
                pPVar16 = (PyObject *)0x0;
                iVar9 = 0x32;
                iVar10 = 0x114a;
                pPVar22 = (PyObject *)0x0;
              }
            }
          }
        }
      }
      goto LAB_0010bfb0;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var20 = pPVar33->ob_type->tp_getattro;
    if (p_Var20 == (getattrofunc)0x0) {
      pPVar12 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar12 = (*p_Var20)(pPVar33,__pyx_mstate_global_static.__pyx_n_s_read_card_from_slot);
    }
    if (pPVar12 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      iVar9 = 0x34;
      iVar10 = 0x1166;
      pPVar22 = (PyObject *)0x0;
      goto LAB_0010bfb0;
    }
    p_Var30 = pPVar12->ob_type;
    if ((p_Var30 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
       (p_Var29 = pPVar12[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)pPVar12[1].ob_refcnt;
      (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*p_Var30->tp_dealloc)(pPVar12);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var29;
      pPVar22 = __Pyx_PyObject_FastCallDict(pPVar11,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar27;
      pPVar12 = pPVar11;
      if (lVar27 == 0) {
        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar22 = __Pyx_PyObject_FastCallDict(pPVar12,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22);
    }
    local_50 = (PyObject **)__pyx_pyargnames;
    if (pPVar22 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      iVar9 = 0x34;
      iVar10 = 0x117a;
      goto LAB_0010c0a4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar27 = pPVar12->ob_refcnt + -1;
    pPVar12->ob_refcnt = lVar27;
    if (lVar27 == 0) {
      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
    }
    p_Var29 = pPVar22->ob_type;
    p_Var30 = (_typeobject *)PTR_PyDict_Type_00123f80;
    if (p_Var29 == (_typeobject *)PTR_PyDict_Type_00123f80) {
      pPVar13 = __Pyx_PyDict_GetItem(pPVar22,__pyx_mstate_global_static.__pyx_n_s_status);
    }
    else {
      pPVar13 = (PyObject *)PyObject_GetItem();
    }
    iVar9 = (int)p_Var29;
    if (pPVar13 == (PyObject *)0x0) {
      pPVar31 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      iVar9 = 0x35;
      iVar10 = 0x1188;
      pPVar16 = (PyObject *)0x0;
      goto LAB_0010bfb0;
    }
    if (pPVar13 == __pyx_mstate_global_static.__pyx_int_1) {
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      goto LAB_0010b9f0;
    }
    p_Var30 = pPVar13->ob_type;
    if (p_Var30 == (_typeobject *)PTR_PyLong_Type_00123f90) {
                    /* Unresolved local var: int unequal@[???]
                       Unresolved local var: ulong uintval@[???]
                       Unresolved local var: Py_ssize_t size@[???]
                       Unresolved local var: digit * digits@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      if (-1 < pPVar13[1].ob_refcnt) {
        uVar28 = 0;
        if (pPVar13[1].ob_refcnt == 1) {
          uVar28 = (uint)(*(int *)&pPVar13[1].ob_type == 1);
        }
        goto LAB_0010b9e4;
      }
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*p_Var30->tp_dealloc)(pPVar13);
      }
LAB_0010bd60:
      iVar9 = (int)p_Var29;
      pPVar13 = __Pyx_PyObject_GetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x51;
        iVar10 = 0x13f3;
        pPVar16 = (PyObject *)0x0;
LAB_0010bfb0:
        pPVar33 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.box_rfid.BoxRFID._schedule_rfid_read",iVar10,iVar9,"box_rfid.py")
        ;
        if (pPVar22 != (PyObject *)0x0) {
LAB_0010bfd4:
          lVar27 = pPVar22->ob_refcnt + -1;
          pPVar22->ob_refcnt = lVar27;
          if (lVar27 == 0) goto LAB_0010bfe4;
        }
      }
      else {
        pPVar12 = __Pyx_PyInt_AddObjC(pPVar13,__pyx_mstate_global_static.__pyx_int_1,(long)p_Var30,
                                      iVar9,iVar10);
        if (pPVar12 == (PyObject *)0x0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          iVar9 = 0x51;
          iVar10 = 0x13f5;
          pPVar16 = (PyObject *)0x0;
LAB_0010bf70:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar14 = (PyObject *)0x0;
LAB_0010c0d0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*pPVar13->ob_type->tp_dealloc)(pPVar13);
          }
LAB_0010c0f0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar14 != (PyObject *)0x0) &&
             (lVar27 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar27, lVar27 == 0)) {
            (*pPVar14->ob_type->tp_dealloc)(pPVar14);
          }
          goto LAB_0010bfb0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        iVar10 = __Pyx_PyObject_SetAttrStr
                           (pPVar33,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,pPVar12)
        ;
        if (iVar10 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x51;
          iVar10 = 0x13f8;
          pPVar14 = (PyObject *)0x0;
          pPVar13 = (PyObject *)0x0;
LAB_0010c134:
          lVar27 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar27;
          if (lVar27 == 0) {
LAB_0010c0bc:
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
          if (pPVar13 != (PyObject *)0x0) goto LAB_0010c0d0;
          goto LAB_0010c0f0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: double b@[???]
                       Unresolved local var: double a@[???]
                       Unresolved local var: double result@[???] */
        if (pPVar16->ob_type == (_typeobject *)PTR_PyFloat_Type_00123f00) {
          dVar35 = (double)pPVar16[1].ob_refcnt + DAT_00111398;
          goto LAB_0010bde8;
        }
        if (pPVar16->ob_type == (_typeobject *)PTR_PyLong_Type_00123f90) {
          lVar27 = pPVar16[1].ob_refcnt;
          dVar35 = DAT_00111398;
          if (lVar27 == 0) {
LAB_0010bde8:
            pPVar33 = (PyObject *)PyFloat_FromDouble(dVar35);
            goto LAB_0010bdf0;
          }
          if (lVar27 + 1U < 3) {
            if (lVar27 < 0) {
              dVar35 = (double)-*(int *)&pPVar16[1].ob_type + DAT_00111398;
            }
            else {
              dVar35 = (double)*(int *)&pPVar16[1].ob_type + DAT_00111398;
            }
            goto LAB_0010bde8;
          }
                    /* Unresolved local var: digit * digits@[???]
                       Unresolved local var: Py_ssize_t size@[???] */
          if (((lVar27 == -2) || (lVar27 == 2)) &&
             (dVar35 = (double)((ulong)*(uint *)&pPVar16[1].ob_type |
                               (ulong)*(uint *)((long)&pPVar16[1].ob_type + 4) << 0x1e),
             dVar35 < 9007199254740992.0)) {
            if (lVar27 == -2) {
              dVar35 = DAT_00111398 - dVar35;
            }
            else {
              dVar35 = dVar35 + DAT_00111398;
            }
            goto LAB_0010bde8;
          }
          dVar35 = (double)PyLong_AsDouble(pPVar16);
          if (dVar35 != -1.0) {
            dVar35 = dVar35 + DAT_00111398;
            goto LAB_0010bde8;
          }
          lVar27 = PyErr_Occurred();
          dVar35 = DAT_001113a0;
          if (lVar27 == 0) goto LAB_0010bde8;
LAB_0010cd4c:
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x52;
          iVar10 = 0x1403;
          goto LAB_0010bfb0;
        }
        pPVar33 = (PyObject *)PyNumber_Add(pPVar16,__pyx_mstate_global_static.__pyx_float_0_1);
LAB_0010bdf0:
        if (pPVar33 == (PyObject *)0x0) goto LAB_0010cd4c;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar22->ob_refcnt + -1;
        pPVar22->ob_refcnt = lVar27;
        if (lVar27 != 0) goto LAB_0010b358;
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
LAB_0010bfe4:
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar16 != (PyObject *)0x0) &&
         (lVar27 = pPVar16->ob_refcnt + -1, pPVar16->ob_refcnt = lVar27, lVar27 == 0)) {
LAB_0010c008:
        (*pPVar16->ob_type->tp_dealloc)(pPVar16);
      }
      if (pPVar32 != (PyObject *)0x0) goto LAB_0010c01c;
    }
    else {
      if (p_Var30 == (_typeobject *)PTR_PyFloat_Type_00123f00) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: double a@[???] */
        lVar27 = pPVar13->ob_refcnt + -1;
        uVar28 = (uint)((double)pPVar13[1].ob_refcnt == 1.0);
        goto LAB_0010b9e4;
      }
      plVar18 = (long *)PyObject_RichCompare(pPVar13,__pyx_mstate_global_static.__pyx_int_1,2);
      p_Var30 = (_typeobject *)PTR__Py_NoneStruct_00123f68;
                    /* Unresolved local var: int retval@[???] */
      if (plVar18 == (long *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x35;
        iVar10 = 0x118a;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: int is_true@[???] */
      uVar28 = (uint)(plVar18 == (long *)PTR__Py_TrueStruct_00123f70);
      if ((uVar28 == 0 && plVar18 != (long *)PTR__Py_FalseStruct_00123f38) &&
          plVar18 != (long *)PTR__Py_NoneStruct_00123f68) {
        uVar28 = PyObject_IsTrue();
        lVar27 = *plVar18;
        *plVar18 = lVar27 + -1;
        if (lVar27 + -1 == 0) goto LAB_0010cc3c;
LAB_0010cc4c:
        if ((int)uVar28 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x35;
          iVar10 = 0x118a;
          goto LAB_0010bf70;
        }
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = *plVar18;
        *plVar18 = lVar27 + -1;
        if (lVar27 + -1 == 0) {
LAB_0010cc3c:
          p_Var30 = *(_typeobject **)(plVar18[1] + 0x30);
          (*(code *)p_Var30)(plVar18);
          goto LAB_0010cc4c;
        }
      }
      lVar27 = pPVar13->ob_refcnt + -1;
LAB_0010b9e4:
      iVar9 = (int)p_Var29;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        p_Var30 = (_typeobject *)pPVar13->ob_type->tp_dealloc;
        (*(code *)p_Var30)(pPVar13);
        iVar9 = (int)p_Var29;
        if (uVar28 != 0) goto LAB_0010b9f0;
        goto LAB_0010bd60;
      }
      if (uVar28 == 0) goto LAB_0010bd60;
LAB_0010b9f0:
      pPVar13 = __Pyx_PyObject_GetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x36;
        iVar10 = 0x1195;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bfb0;
      }
      pPVar12 = __Pyx_PyInt_RemainderObjC
                          (pPVar13,__pyx_mstate_global_static.__pyx_int_2,(long)p_Var30,iVar9,iVar10
                          );
      if (pPVar12 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x36;
        iVar10 = 0x1197;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      if (pPVar12 == __pyx_mstate_global_static.__pyx_int_0) {
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
LAB_0010c298:
        pPVar11 = pPVar22;
        iVar8 = __Pyx_PyObject_SetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_temp_message_1,pPVar22);
        if (iVar8 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x37;
          iVar10 = 0x11a5;
        }
        else {
          pPVar12 = __Pyx_PyObject_GetAttrStr
                              (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count);
          if (pPVar12 != (PyObject *)0x0) {
            pPVar13 = __Pyx_PyInt_AddObjC(pPVar12,__pyx_mstate_global_static.__pyx_int_1,
                                          (long)pPVar11,iVar9,iVar10);
            if (pPVar13 == (PyObject *)0x0) {
              pPVar31 = (PyObject *)0x0;
              pPVar32 = (PyObject *)0x0;
              pPVar14 = (PyObject *)0x0;
              pPVar16 = (PyObject *)0x0;
              iVar9 = 0x38;
              iVar10 = 0x11b0;
              goto LAB_0010c134;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
            iVar9 = __Pyx_PyObject_SetAttrStr
                              (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count,
                               pPVar13);
            if (iVar9 < 0) {
              pPVar31 = (PyObject *)0x0;
              pPVar32 = (PyObject *)0x0;
              pPVar16 = (PyObject *)0x0;
              iVar9 = 0x38;
              iVar10 = 0x11b3;
              goto LAB_0010bf70;
            }
LAB_0010c310:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar13->ob_refcnt + -1;
            pPVar13->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
            }
            goto LAB_0010c330;
          }
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          iVar9 = 0x38;
          iVar10 = 0x11ae;
          pPVar16 = (PyObject *)0x0;
        }
        goto LAB_0010bfb0;
      }
      if (pPVar12->ob_type == (_typeobject *)PTR_PyLong_Type_00123f90) {
                    /* Unresolved local var: int unequal@[???]
                       Unresolved local var: ulong uintval@[???]
                       Unresolved local var: Py_ssize_t size@[???]
                       Unresolved local var: digit * digits@[???] */
        uVar28 = (uint)(pPVar12[1].ob_refcnt == 0);
      }
      else if (pPVar12->ob_type == (_typeobject *)PTR_PyFloat_Type_00123f00) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: double a@[???] */
        uVar28 = (uint)((double)pPVar12[1].ob_refcnt == 0.0);
      }
      else {
        plVar18 = (long *)PyObject_RichCompare(pPVar12,__pyx_mstate_global_static.__pyx_int_0,2);
                    /* Unresolved local var: int retval@[???] */
        if (plVar18 == (long *)0x0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          pPVar14 = (PyObject *)0x0;
          iVar9 = 0x36;
          iVar10 = 0x119a;
          pPVar13 = (PyObject *)0x0;
          goto LAB_0010c134;
        }
                    /* Unresolved local var: int is_true@[???] */
        uVar28 = (uint)(plVar18 == (long *)PTR__Py_TrueStruct_00123f70);
        if ((uVar28 == 0 && plVar18 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar18 != (long *)PTR__Py_NoneStruct_00123f68) {
          uVar28 = PyObject_IsTrue();
          lVar27 = *plVar18;
          *plVar18 = lVar27 + -1;
          if (lVar27 + -1 == 0) goto LAB_0010ce58;
        }
        else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = *plVar18;
          *plVar18 = lVar27 + -1;
          if (lVar27 + -1 != 0) goto LAB_0010ba5c;
LAB_0010ce58:
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        if ((int)uVar28 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x36;
          iVar10 = 0x119a;
          pPVar14 = (PyObject *)0x0;
          pPVar13 = (PyObject *)0x0;
          goto LAB_0010c134;
        }
      }
LAB_0010ba5c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
      if (uVar28 != 0) goto LAB_0010c298;
      intval = &__pyx_pyframe_localsplus_offset;
      pPVar13 = __Pyx_PyObject_GetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x39;
        iVar10 = 0x11c7;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bfb0;
      }
      pPVar12 = __Pyx_PyInt_RemainderObjC
                          (pPVar13,__pyx_mstate_global_static.__pyx_int_2,(long)intval,iVar9,iVar10)
      ;
      if (pPVar12 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x39;
        iVar10 = 0x11c9;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      if (pPVar12 != __pyx_mstate_global_static.__pyx_int_0) {
        if (pPVar12->ob_type == (_typeobject *)PTR_PyLong_Type_00123f90) {
                    /* Unresolved local var: int unequal@[???]
                       Unresolved local var: ulong uintval@[???]
                       Unresolved local var: Py_ssize_t size@[???]
                       Unresolved local var: digit * digits@[???] */
          uVar28 = (uint)(pPVar12[1].ob_refcnt == 0);
        }
        else if (pPVar12->ob_type == (_typeobject *)PTR_PyFloat_Type_00123f00) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: double a@[???] */
          uVar28 = (uint)((double)pPVar12[1].ob_refcnt == 0.0);
        }
        else {
          plVar18 = (long *)PyObject_RichCompare(pPVar12,__pyx_mstate_global_static.__pyx_int_0,2);
                    /* Unresolved local var: int retval@[???] */
          if (plVar18 == (long *)0x0) {
            pPVar31 = (PyObject *)0x0;
            pPVar32 = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
            pPVar14 = (PyObject *)0x0;
            iVar9 = 0x39;
            iVar10 = 0x11cc;
            pPVar13 = (PyObject *)0x0;
            goto LAB_0010c134;
          }
                    /* Unresolved local var: int is_true@[???] */
          bVar6 = plVar18 == (long *)PTR__Py_TrueStruct_00123f70;
          uVar28 = (uint)bVar6;
          if ((uVar28 == 0 && plVar18 != (long *)PTR__Py_FalseStruct_00123f38) &&
              plVar18 != (long *)PTR__Py_NoneStruct_00123f68) {
            uVar28 = PyObject_IsTrue();
            lVar27 = *plVar18;
            *plVar18 = lVar27 + -1;
            uVar26 = uVar28;
            if (lVar27 + -1 == 0) goto LAB_0010d2ec;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = *plVar18;
            *plVar18 = lVar27 + -1;
            uVar26 = (uint)bVar6;
            if (lVar27 + -1 != 0) goto LAB_0010baf8;
LAB_0010d2ec:
            uVar28 = uVar26;
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if ((int)uVar28 < 0) {
            pPVar31 = (PyObject *)0x0;
            pPVar32 = (PyObject *)0x0;
            pPVar16 = (PyObject *)0x0;
            iVar9 = 0x39;
            iVar10 = 0x11cc;
            pPVar14 = (PyObject *)0x0;
            pPVar13 = (PyObject *)0x0;
            goto LAB_0010c134;
          }
        }
LAB_0010baf8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        if (uVar28 != 0) goto LAB_0010c330;
        pPVar11 = pPVar22;
        iVar8 = __Pyx_PyObject_SetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_temp_message_2,pPVar22);
        if (iVar8 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x3a;
          iVar10 = 0x11d8;
          goto LAB_0010bfb0;
        }
        pPVar12 = __Pyx_PyObject_GetAttrStr
                            (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count);
        if (pPVar12 == (PyObject *)0x0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          iVar9 = 0x3b;
          iVar10 = 0x11e1;
          pPVar16 = (PyObject *)0x0;
          goto LAB_0010bfb0;
        }
        pPVar13 = __Pyx_PyInt_AddObjC(pPVar12,__pyx_mstate_global_static.__pyx_int_1,(long)pPVar11,
                                      iVar9,iVar10);
        if (pPVar13 == (PyObject *)0x0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar14 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x3b;
          iVar10 = 0x11e3;
          goto LAB_0010c134;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        iVar9 = __Pyx_PyObject_SetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count,pPVar13);
        if (iVar9 < 0) {
          pPVar31 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          pPVar16 = (PyObject *)0x0;
          iVar9 = 0x3b;
          iVar10 = 0x11e6;
          goto LAB_0010bf70;
        }
        goto LAB_0010c310;
      }
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
LAB_0010c330:
      pPVar13 = __Pyx_PyObject_GetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_get_message_count);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x3c;
        iVar10 = 0x11fa;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bfb0;
      }
      if (pPVar13 == __pyx_mstate_global_static.__pyx_int_3) {
        lVar27 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
      }
      else {
        p_Var30 = pPVar13->ob_type;
        if (p_Var30 == (_typeobject *)PTR_PyLong_Type_00123f90) {
                    /* Unresolved local var: int unequal@[???]
                       Unresolved local var: ulong uintval@[???]
                       Unresolved local var: Py_ssize_t size@[???]
                       Unresolved local var: digit * digits@[???] */
          p_Var29 = (_typeobject *)pPVar13[1].ob_refcnt;
          lVar27 = pPVar13->ob_refcnt + -1;
          if ((long)p_Var29 < 0) {
            pPVar13->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*p_Var30->tp_dealloc)(pPVar13);
            }
            goto LAB_0010bd60;
          }
          uVar28 = 0;
          if (p_Var29 == (_typeobject *)0x1) {
            uVar28 = (uint)(*(int *)&pPVar13[1].ob_type == 3);
          }
        }
        else {
          p_Var29 = (_typeobject *)PTR_PyFloat_Type_00123f00;
          if (p_Var30 == (_typeobject *)PTR_PyFloat_Type_00123f00) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: double a@[???] */
            lVar27 = pPVar13->ob_refcnt + -1;
            uVar28 = (uint)((double)pPVar13[1].ob_refcnt == 3.0);
          }
          else {
            plVar18 = (long *)PyObject_RichCompare(pPVar13,__pyx_mstate_global_static.__pyx_int_3,2)
            ;
            p_Var30 = (_typeobject *)PTR__Py_FalseStruct_00123f38;
                    /* Unresolved local var: int retval@[???] */
            if (plVar18 == (long *)0x0) {
              pPVar31 = (PyObject *)0x0;
              pPVar32 = (PyObject *)0x0;
              iVar9 = 0x3c;
              iVar10 = 0x11fc;
              pPVar16 = (PyObject *)0x0;
              goto LAB_0010bf70;
            }
                    /* Unresolved local var: int is_true@[???] */
            uVar28 = (uint)(plVar18 == (long *)PTR__Py_TrueStruct_00123f70);
            if ((uVar28 == 0 && plVar18 != (long *)PTR__Py_FalseStruct_00123f38) &&
                plVar18 != (long *)PTR__Py_NoneStruct_00123f68) {
              uVar28 = PyObject_IsTrue();
              lVar27 = *plVar18;
              *plVar18 = lVar27 + -1;
              if (lVar27 + -1 == 0) goto LAB_0010d07c;
LAB_0010d08c:
              if ((int)uVar28 < 0) {
                pPVar31 = (PyObject *)0x0;
                pPVar32 = (PyObject *)0x0;
                pPVar16 = (PyObject *)0x0;
                iVar9 = 0x3c;
                iVar10 = 0x11fc;
                goto LAB_0010bf70;
              }
            }
            else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar27 = *plVar18;
              *plVar18 = lVar27 + -1;
              if (lVar27 + -1 == 0) {
LAB_0010d07c:
                (**(code **)(plVar18[1] + 0x30))(plVar18);
                goto LAB_0010d08c;
              }
            }
            lVar27 = pPVar13->ob_refcnt + -1;
          }
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar13->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        if (uVar28 == 0) goto LAB_0010bd60;
      }
      pPVar13 = __Pyx_PyObject_GetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_temp_message_1);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x3d;
        iVar10 = 0x1207;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bfb0;
      }
      p_Var30 = pPVar13->ob_type;
      if (p_Var30 == (_typeobject *)PTR_PyDict_Type_00123f80) {
        pPVar12 = __Pyx_PyDict_GetItem(pPVar13,__pyx_mstate_global_static.__pyx_n_s_data);
      }
      else {
        pPVar12 = (PyObject *)PyObject_GetItem();
      }
      if (pPVar12 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x3d;
        iVar10 = 0x1209;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      pPVar13 = __Pyx_PyObject_GetAttrStr
                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_temp_message_2);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        pPVar14 = (PyObject *)0x0;
        iVar9 = 0x3d;
        iVar10 = 0x120c;
        goto LAB_0010c134;
      }
      if (pPVar13->ob_type == (_typeobject *)PTR_PyDict_Type_00123f80) {
        pPVar11 = __Pyx_PyDict_GetItem(pPVar13,__pyx_mstate_global_static.__pyx_n_s_data);
      }
      else {
        pPVar11 = (PyObject *)PyObject_GetItem();
      }
      if (pPVar11 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        iVar9 = 0x3d;
        iVar10 = 0x120e;
        pPVar14 = (PyObject *)0x0;
        goto LAB_0010c134;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      pPVar13 = (PyObject *)PyObject_RichCompare(pPVar12,pPVar11,2);
      if (pPVar13 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar10 = 0x1211;
        iVar9 = 0x3d;
        pPVar16 = (PyObject *)0x0;
        goto LAB_0010c080;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
                    /* Unresolved local var: int is_true@[???] */
      uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
      if (((uVar28 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
           pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
         (uVar28 = PyObject_IsTrue(pPVar13), (int)uVar28 < 0)) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        iVar9 = 0x3d;
        iVar10 = 0x1214;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      if (uVar28 == 0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
LAB_0010d0bc:
        iVar10 = __Pyx_PyObject_SetAttrStr
                           (pPVar33,__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer,
                            (PyObject *)PTR__Py_NoneStruct_00123f68);
        if (iVar10 < 0) {
          iVar9 = 0x4d;
          iVar10 = 0x139a;
          goto LAB_0010bfb0;
        }
        iVar10 = __Pyx_PyObject_SetAttrStr
                           (pPVar33,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,
                            __pyx_mstate_global_static.__pyx_int_0);
        if (iVar10 < 0) {
          iVar9 = 0x4e;
          iVar10 = 0x13a3;
          goto LAB_0010bfb0;
        }
        pPVar12 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_stop_read);
        if (pPVar12 == (PyObject *)0x0) {
          iVar9 = 0x4f;
          iVar10 = 0x13ac;
          goto LAB_0010bfb0;
        }
        p_Var29 = pPVar12->ob_type;
        if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
           (p_Var34 = pPVar12[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar13 = (PyObject *)pPVar12[1].ob_refcnt;
          (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
          pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*p_Var29->tp_dealloc)(pPVar12);
          }
          __pyx_pyargnames[1] = (PyObject **)0x0;
          __pyx_pyargnames[0] = (PyObject **)p_Var34;
          pPVar11 = __Pyx_PyObject_FastCallDict(pPVar13,local_50,1,(PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
          (p_Var34->ob_base).ob_base.ob_refcnt = lVar27;
          pPVar12 = pPVar13;
          if (lVar27 == 0) {
            (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)0x0;
          pPVar11 = __Pyx_PyObject_FastCallDict
                              (pPVar12,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)p_Var30);
        }
        if (pPVar11 == (PyObject *)0x0) {
          iVar9 = 0x4f;
          iVar10 = 0x13c0;
          goto LAB_0010c0a4;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        pPVar13 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
        if (pPVar13 == (PyObject *)0x0) {
          iVar9 = 0x50;
          iVar10 = 0x13ce;
          goto LAB_0010bfb0;
        }
        pPVar12 = __Pyx_PyObject_GetAttrStr(pPVar13,__pyx_mstate_global_static.__pyx_n_s_reactor);
        if (pPVar12 == (PyObject *)0x0) {
          iVar9 = 0x50;
          iVar10 = 0x13d0;
          goto LAB_0010bf70;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        pPVar33 = __Pyx_PyObject_GetAttrStr(pPVar12,__pyx_mstate_global_static.__pyx_n_s_NEVER);
        if (pPVar33 == (PyObject *)0x0) {
          pPVar14 = (PyObject *)0x0;
          iVar9 = 0x50;
          iVar10 = 0x13d3;
          pPVar13 = (PyObject *)0x0;
          goto LAB_0010c134;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        goto LAB_0010bfd4;
      }
      iVar9 = __Pyx_PyObject_SetAttrStr
                        (pPVar33,__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer,
                         (PyObject *)PTR__Py_NoneStruct_00123f68);
      iVar8 = (int)p_Var30;
      if (iVar9 < 0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        iVar9 = 0x3e;
        iVar10 = 0x121f;
        goto LAB_0010bfb0;
      }
      iVar9 = __Pyx_PyObject_SetAttrStr
                        (pPVar33,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,
                         __pyx_mstate_global_static.__pyx_int_0);
      if (iVar9 < 0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        pPVar16 = (PyObject *)0x0;
        iVar9 = 0x3f;
        iVar10 = 0x1228;
        goto LAB_0010bfb0;
      }
      p_Var30 = pPVar22->ob_type;
      if (p_Var30 == (_typeobject *)PTR_PyDict_Type_00123f80) {
        pPVar16 = __Pyx_PyDict_GetItem(pPVar22,__pyx_mstate_global_static.__pyx_n_s_data);
        iVar9 = (int)p_Var30;
      }
      else {
        pPVar16 = (PyObject *)PyObject_GetItem();
        iVar9 = (int)p_Var30;
      }
      if (pPVar16 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        iVar9 = 0x40;
        iVar10 = 0x1231;
        goto LAB_0010bfb0;
      }
      pPVar32 = __Pyx_GetItemInt_Fast(pPVar16,0,iVar9,iVar8,iVar10);
      if (pPVar32 == (PyObject *)0x0) {
        pPVar31 = (PyObject *)0x0;
        iVar9 = 0x41;
        iVar10 = 0x123d;
        goto LAB_0010bfb0;
      }
      pPVar31 = __Pyx_GetItemInt_Fast(pPVar16,1,iVar9,iVar8,iVar10);
      if (pPVar31 == (PyObject *)0x0) {
        iVar9 = 0x42;
        iVar10 = 0x1249;
        goto LAB_0010bfb0;
      }
      pPVar13 = (PyObject *)PyObject_RichCompare(pPVar32,__pyx_mstate_global_static.__pyx_int_1,0);
      if (pPVar13 == (PyObject *)0x0) {
        iVar9 = 0x43;
        iVar10 = 0x1255;
        goto LAB_0010bfb0;
      }
                    /* Unresolved local var: int is_true@[???] */
      uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
      p_Var30 = (_typeobject *)PTR__Py_FalseStruct_00123f38;
      if (((uVar28 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
           pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
         (uVar28 = PyObject_IsTrue(), (int)uVar28 < 0)) {
        iVar9 = 0x43;
        iVar10 = 0x1256;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      if (uVar28 == 0) {
        pPVar13 = (PyObject *)
                  PyObject_RichCompare(pPVar32,__pyx_mstate_global_static.__pyx_int_99,4);
        if (pPVar13 != (PyObject *)0x0) {
                    /* Unresolved local var: int is_true@[???] */
          uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
          p_Var30 = (_typeobject *)PTR__Py_FalseStruct_00123f38;
          if (((uVar28 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
               pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
             (uVar28 = PyObject_IsTrue(), (int)uVar28 < 0)) {
            iVar9 = 0x43;
            iVar10 = 0x125e;
            goto LAB_0010bf70;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*pPVar13->ob_type->tp_dealloc)(pPVar13);
          }
          if (uVar28 != 0) goto LAB_0010c614;
          pPVar13 = (PyObject *)
                    PyObject_RichCompare(pPVar31,__pyx_mstate_global_static.__pyx_int_1,0);
          if (pPVar13 == (PyObject *)0x0) {
            iVar9 = 0x43;
            iVar10 = 0x1265;
            goto LAB_0010bfb0;
          }
                    /* Unresolved local var: int is_true@[???] */
          uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
          p_Var30 = (_typeobject *)PTR__Py_FalseStruct_00123f38;
          if (((uVar28 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
               pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
             (uVar28 = PyObject_IsTrue(), (int)uVar28 < 0)) {
            iVar9 = 0x43;
            iVar10 = 0x1266;
            goto LAB_0010bf70;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*pPVar13->ob_type->tp_dealloc)(pPVar13);
          }
          if (uVar28 != 0) goto LAB_0010c614;
          pPVar13 = (PyObject *)
                    PyObject_RichCompare(pPVar31,__pyx_mstate_global_static.__pyx_int_24,4);
          if (pPVar13 == (PyObject *)0x0) {
            iVar9 = 0x43;
            iVar10 = 0x126d;
            goto LAB_0010bfb0;
          }
                    /* Unresolved local var: int is_true@[???] */
          uVar28 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_00123f70);
          p_Var30 = (_typeobject *)PTR__Py_FalseStruct_00123f38;
          if (((uVar28 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_00123f38) &&
               pPVar13 != (PyObject *)PTR__Py_NoneStruct_00123f68) &&
             (uVar28 = PyObject_IsTrue(), (int)uVar28 < 0)) {
            iVar9 = 0x43;
            iVar10 = 0x126e;
            goto LAB_0010bf70;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar27 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar27;
          if (lVar27 == 0) {
            (*pPVar13->ob_type->tp_dealloc)(pPVar13);
          }
          if (uVar28 != 0) goto LAB_0010c614;
          pPVar12 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
          if (pPVar12 == (PyObject *)0x0) {
            iVar9 = 0x49;
            iVar10 = 0x12f8;
            goto LAB_0010bfb0;
          }
          pPVar11 = __Pyx_PyObject_GetAttrStr
                              (pPVar12,__pyx_mstate_global_static.__pyx_n_s_box_extras);
          if (pPVar11 == (PyObject *)0x0) {
            pPVar14 = (PyObject *)0x0;
            iVar9 = 0x49;
            iVar10 = 0x12fa;
            pPVar13 = (PyObject *)0x0;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
            pPVar12 = __Pyx_PyObject_GetAttrStr
                                (pPVar11,__pyx_mstate_global_static.__pyx_n_s_save_variable);
            if (pPVar12 == (PyObject *)0x0) {
              iVar10 = 0x12fd;
              iVar9 = 0x49;
              goto LAB_0010c080;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar27 = pPVar11->ob_refcnt + -1;
            pPVar11->ob_refcnt = lVar27;
            if (lVar27 == 0) {
              (*pPVar11->ob_type->tp_dealloc)(pPVar11);
            }
            pPVar11 = __Pyx_PyObject_GetAttrStr
                                (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
            if (pPVar11 == (PyObject *)0x0) {
              pPVar14 = (PyObject *)0x0;
              iVar9 = 0x49;
              iVar10 = 0x1300;
              pPVar13 = (PyObject *)0x0;
            }
            else {
              pPVar14 = __Pyx_PyObject_GetAttrStr
                                  (pPVar11,__pyx_mstate_global_static.__pyx_n_s_stepper_name);
              if (pPVar14 == (PyObject *)0x0) {
                iVar10 = 0x1302;
                iVar9 = 0x49;
                goto LAB_0010c080;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar27 = pPVar11->ob_refcnt + -1;
              pPVar11->ob_refcnt = lVar27;
              if (lVar27 == 0) {
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
              }
              ppPVar15 = (PyObject **)
                         PyNumber_Add(__pyx_mstate_global_static.__pyx_n_s_filament,pPVar14);
              if (ppPVar15 == (PyObject **)0x0) {
                iVar9 = 0x49;
                iVar10 = 0x1305;
                pPVar13 = (PyObject *)0x0;
              }
              else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar27 = pPVar14->ob_refcnt + -1;
                pPVar14->ob_refcnt = lVar27;
                if (lVar27 == 0) {
                  (*pPVar14->ob_type->tp_dealloc)(pPVar14);
                }
                p_Var29 = pPVar12->ob_type;
                if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                   (p_Var34 = pPVar12[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar13 = (PyObject *)pPVar12[1].ob_refcnt;
                  (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
                  pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = pPVar12->ob_refcnt + -1;
                  pPVar12->ob_refcnt = lVar27;
                  if (lVar27 == 0) {
                    (*p_Var29->tp_dealloc)(pPVar12);
                  }
                  __pyx_pyargnames[0] = (PyObject **)p_Var34;
                  __pyx_pyargnames[1] = ppPVar15;
                  __pyx_pyargnames[2] = (PyObject **)pPVar32;
                  pPVar11 = __Pyx_PyObject_FastCallDict(pPVar13,local_50,3,pPVar13);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var34->ob_base).ob_base.ob_refcnt = lVar27;
                  pPVar12 = pPVar13;
                  if (lVar27 == 0) {
                    (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
                  }
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = ppPVar15;
                  __pyx_pyargnames[2] = (PyObject **)pPVar32;
                  pPVar11 = __Pyx_PyObject_FastCallDict
                                      (pPVar12,(PyObject **)(__pyx_pyargnames + 1),2,
                                       (PyObject *)p_Var30);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                pPVar13 = (PyObject *)((long)&(*ppPVar15)[-1].ob_type + 7);
                *ppPVar15 = pPVar13;
                if (pPVar13 == (PyObject *)0x0) {
                  (*(code *)ppPVar15[1][3].ob_refcnt)(ppPVar15);
                }
                if (pPVar11 == (PyObject *)0x0) {
                  iVar9 = 0x49;
                  iVar10 = 0x131b;
                  goto LAB_0010c0a4;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar27 = pPVar12->ob_refcnt + -1;
                pPVar12->ob_refcnt = lVar27;
                if (lVar27 == 0) {
                  (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar27 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar27;
                if (lVar27 == 0) {
                  (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                }
                pPVar19 = __Pyx_PyObject_GetAttrStr
                                    (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
                if (pPVar19 == (PyObject *)0x0) {
                  iVar9 = 0x4a;
                  iVar10 = 0x1328;
                  goto LAB_0010bfb0;
                }
                pPVar11 = __Pyx_PyObject_GetAttrStr
                                    (pPVar19,__pyx_mstate_global_static.__pyx_n_s_box_extras);
                if (pPVar11 == (PyObject *)0x0) {
                  pPVar14 = (PyObject *)0x0;
                  iVar9 = 0x4a;
                  iVar10 = 0x132a;
                  pPVar13 = (PyObject *)0x0;
                  pPVar12 = pPVar19;
                }
                else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = pPVar19->ob_refcnt + -1;
                  pPVar19->ob_refcnt = lVar27;
                  if (lVar27 == 0) {
                    (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                  }
                  pPVar19 = __Pyx_PyObject_GetAttrStr
                                      (pPVar11,__pyx_mstate_global_static.__pyx_n_s_save_variable);
                  if (pPVar19 == (PyObject *)0x0) {
                    iVar10 = 0x132d;
                    iVar9 = 0x4a;
                    pPVar12 = pPVar19;
                    goto LAB_0010c080;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar27 = pPVar11->ob_refcnt + -1;
                  pPVar11->ob_refcnt = lVar27;
                  if (lVar27 == 0) {
                    (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                  }
                  pPVar11 = __Pyx_PyObject_GetAttrStr
                                      (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
                  if (pPVar11 == (PyObject *)0x0) {
                    pPVar14 = (PyObject *)0x0;
                    iVar9 = 0x4a;
                    iVar10 = 0x1330;
                    pPVar13 = (PyObject *)0x0;
                    pPVar12 = pPVar19;
                  }
                  else {
                    pPVar14 = __Pyx_PyObject_GetAttrStr
                                        (pPVar11,__pyx_mstate_global_static.__pyx_n_s_stepper_name);
                    if (pPVar14 == (PyObject *)0x0) {
                      iVar10 = 0x1332;
                      iVar9 = 0x4a;
                      pPVar12 = pPVar19;
                      goto LAB_0010c080;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar27 = pPVar11->ob_refcnt + -1;
                    pPVar11->ob_refcnt = lVar27;
                    if (lVar27 == 0) {
                      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                    }
                    ppPVar15 = (PyObject **)
                               PyNumber_Add(__pyx_mstate_global_static.__pyx_n_s_color,pPVar14);
                    if (ppPVar15 == (PyObject **)0x0) {
                      iVar9 = 0x4a;
                      iVar10 = 0x1335;
                      pPVar13 = (PyObject *)0x0;
                      pPVar12 = pPVar19;
                    }
                    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar27 = pPVar14->ob_refcnt + -1;
                      pPVar14->ob_refcnt = lVar27;
                      if (lVar27 == 0) {
                        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
                      }
                      p_Var30 = pPVar19->ob_type;
                      if ((p_Var30 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                         (p_Var29 = pPVar19[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                        pPVar12 = (PyObject *)pPVar19[1].ob_refcnt;
                        (p_Var29->ob_base).ob_base.ob_refcnt =
                             (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                        pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar27 = pPVar19->ob_refcnt + -1;
                        pPVar19->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*p_Var30->tp_dealloc)(pPVar19);
                        }
                        __pyx_pyargnames[0] = (PyObject **)p_Var29;
                        __pyx_pyargnames[1] = ppPVar15;
                        __pyx_pyargnames[2] = (PyObject **)pPVar31;
                        pPVar11 = __Pyx_PyObject_FastCallDict(pPVar12,local_50,3,pPVar12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar27 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                        (p_Var29->ob_base).ob_base.ob_refcnt = lVar27;
                        pPVar19 = pPVar12;
                        if (lVar27 == 0) {
                          (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                        }
                      }
                      else {
                        __pyx_pyargnames[0] = (PyObject **)0x0;
                        __pyx_pyargnames[1] = ppPVar15;
                        __pyx_pyargnames[2] = (PyObject **)pPVar31;
                        pPVar11 = __Pyx_PyObject_FastCallDict
                                            (pPVar19,(PyObject **)(__pyx_pyargnames + 1),2,pPVar12);
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      pPVar12 = (PyObject *)((long)&(*ppPVar15)[-1].ob_type + 7);
                      *ppPVar15 = pPVar12;
                      if (pPVar12 == (PyObject *)0x0) {
                        (*(code *)ppPVar15[1][3].ob_refcnt)(ppPVar15);
                      }
                      if (pPVar11 == (PyObject *)0x0) {
                        iVar9 = 0x4a;
                        iVar10 = 0x134b;
                        pPVar12 = pPVar19;
                        goto LAB_0010c0a4;
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar27 = pPVar19->ob_refcnt + -1;
                      pPVar19->ob_refcnt = lVar27;
                      if (lVar27 == 0) {
                        (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar27 = pPVar11->ob_refcnt + -1;
                      pPVar11->ob_refcnt = lVar27;
                      if (lVar27 == 0) {
                        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                      }
                      pPVar12 = __Pyx_PyObject_GetAttrStr
                                          (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
                      if (pPVar12 == (PyObject *)0x0) {
                        iVar9 = 0x4b;
                        iVar10 = 0x1358;
                        goto LAB_0010bfb0;
                      }
                      pPVar11 = __Pyx_PyObject_GetAttrStr
                                          (pPVar12,__pyx_mstate_global_static.__pyx_n_s_box_extras);
                      if (pPVar11 == (PyObject *)0x0) {
                        pPVar14 = (PyObject *)0x0;
                        iVar9 = 0x4b;
                        iVar10 = 0x135a;
                        pPVar13 = (PyObject *)0x0;
                      }
                      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar27 = pPVar12->ob_refcnt + -1;
                        pPVar12->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                        }
                        pPVar12 = __Pyx_PyObject_GetAttrStr
                                            (pPVar11,__pyx_mstate_global_static.
                                                     __pyx_n_s_save_variable);
                        if (pPVar12 == (PyObject *)0x0) {
                          iVar10 = 0x135d;
                          iVar9 = 0x4b;
                          goto LAB_0010c080;
                        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar27 = pPVar11->ob_refcnt + -1;
                        pPVar11->ob_refcnt = lVar27;
                        if (lVar27 == 0) {
                          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                        }
                        pPVar11 = __Pyx_PyObject_GetAttrStr
                                            (pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
                        if (pPVar11 == (PyObject *)0x0) {
                          pPVar14 = (PyObject *)0x0;
                          iVar9 = 0x4b;
                          iVar10 = 0x1360;
                          pPVar13 = (PyObject *)0x0;
                        }
                        else {
                          pPVar14 = __Pyx_PyObject_GetAttrStr
                                              (pPVar11,__pyx_mstate_global_static.
                                                       __pyx_n_s_stepper_name);
                          if (pPVar14 == (PyObject *)0x0) {
                            iVar10 = 0x1362;
                            iVar9 = 0x4b;
                            goto LAB_0010c080;
                          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar27 = pPVar11->ob_refcnt + -1;
                          pPVar11->ob_refcnt = lVar27;
                          if (lVar27 == 0) {
                            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                          }
                          ppPVar15 = (PyObject **)
                                     PyNumber_Add(__pyx_mstate_global_static.__pyx_n_s_vendor,
                                                  pPVar14);
                          if (ppPVar15 != (PyObject **)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            lVar27 = pPVar14->ob_refcnt + -1;
                            pPVar14->ob_refcnt = lVar27;
                            if (lVar27 == 0) {
                              (*pPVar14->ob_type->tp_dealloc)(pPVar14);
                            }
                            p_Var30 = pPVar12->ob_type;
                            if ((p_Var30 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                               (p_Var29 = pPVar12[1].ob_type, p_Var29 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                              pPVar13 = (PyObject *)pPVar12[1].ob_refcnt;
                              (p_Var29->ob_base).ob_base.ob_refcnt =
                                   (p_Var29->ob_base).ob_base.ob_refcnt + 1;
                              pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                              lVar27 = pPVar12->ob_refcnt + -1;
                              pPVar12->ob_refcnt = lVar27;
                              if (lVar27 == 0) {
                                (*p_Var30->tp_dealloc)(pPVar12);
                              }
                              __pyx_pyargnames[2] =
                                   (PyObject **)__pyx_mstate_global_static.__pyx_int_1;
                              p_Var30 = (_typeobject *)__pyx_mstate_global_static.__pyx_int_1;
                              __pyx_pyargnames[0] = (PyObject **)p_Var29;
                              __pyx_pyargnames[1] = ppPVar15;
                              pPVar11 = __Pyx_PyObject_FastCallDict
                                                  (pPVar13,local_50,3,
                                                   __pyx_mstate_global_static.__pyx_int_1);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                              lVar27 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                              (p_Var29->ob_base).ob_base.ob_refcnt = lVar27;
                              pPVar12 = pPVar13;
                              if (lVar27 == 0) {
                                (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)
                                          ((PyObject *)p_Var29);
                              }
                            }
                            else {
                              __pyx_pyargnames[0] = (PyObject **)0x0;
                              __pyx_pyargnames[2] =
                                   (PyObject **)__pyx_mstate_global_static.__pyx_int_1;
                              p_Var30 = (_typeobject *)__pyx_mstate_global_static.__pyx_int_1;
                              __pyx_pyargnames[1] = ppPVar15;
                              pPVar11 = __Pyx_PyObject_FastCallDict
                                                  (pPVar12,(PyObject **)(__pyx_pyargnames + 1),2,
                                                   __pyx_mstate_global_static.__pyx_int_1);
                            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            pPVar13 = (PyObject *)((long)&(*ppPVar15)[-1].ob_type + 7);
                            *ppPVar15 = pPVar13;
                            if (pPVar13 == (PyObject *)0x0) {
                              (*(code *)ppPVar15[1][3].ob_refcnt)(ppPVar15);
                            }
                            if (pPVar11 == (PyObject *)0x0) {
                              iVar9 = 0x4b;
                              iVar10 = 0x137b;
                              goto LAB_0010c0a4;
                            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            lVar27 = pPVar12->ob_refcnt + -1;
                            pPVar12->ob_refcnt = lVar27;
                            if (lVar27 == 0) {
                              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            lVar27 = pPVar11->ob_refcnt + -1;
                            pPVar11->ob_refcnt = lVar27;
                            if (lVar27 == 0) {
                              (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                            }
                            iVar10 = __Pyx_PyObject_SetAttrStr
                                               (pPVar33,__pyx_mstate_global_static.
                                                        __pyx_n_s_had_get_value,
                                                (PyObject *)PTR__Py_TrueStruct_00123f70);
                            if (-1 < iVar10) goto LAB_0010d0bc;
                            iVar9 = 0x4c;
                            iVar10 = 5000;
                            goto LAB_0010bfb0;
                          }
                          iVar9 = 0x4b;
                          iVar10 = 0x1365;
                          pPVar13 = (PyObject *)0x0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          goto LAB_0010c134;
        }
        iVar9 = 0x43;
        iVar10 = 0x125d;
        goto LAB_0010bfb0;
      }
LAB_0010c614:
      iVar10 = __Pyx_PyObject_SetAttrStr
                         (pPVar33,__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer,
                          (PyObject *)PTR__Py_NoneStruct_00123f68);
      if (iVar10 < 0) {
        iVar9 = 0x44;
        iVar10 = 0x127b;
        goto LAB_0010bfb0;
      }
      iVar10 = __Pyx_PyObject_SetAttrStr
                         (pPVar33,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,
                          __pyx_mstate_global_static.__pyx_int_0);
      if (iVar10 < 0) {
        iVar9 = 0x45;
        iVar10 = 0x1284;
        goto LAB_0010bfb0;
      }
      pPVar11 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_gcode);
      if (pPVar11 == (PyObject *)0x0) {
        iVar9 = 0x46;
        iVar10 = 0x128d;
        goto LAB_0010bfb0;
      }
      pPVar12 = __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_respond_info)
      ;
      if (pPVar12 == (PyObject *)0x0) {
        iVar10 = 0x128f;
        iVar9 = 0x46;
LAB_0010c080:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        if (pPVar12 == (PyObject *)0x0) goto LAB_0010bfb0;
LAB_0010c0a4:
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 != 0) goto LAB_0010bfb0;
        pPVar13 = (PyObject *)0x0;
        pPVar14 = (PyObject *)0x0;
        goto LAB_0010c0bc;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      pPVar11 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
      if (pPVar11 == (PyObject *)0x0) {
        pPVar14 = (PyObject *)0x0;
        iVar9 = 0x46;
        iVar10 = 0x1292;
        pPVar13 = (PyObject *)0x0;
        goto LAB_0010c134;
      }
      pPVar14 = __Pyx_PyObject_GetAttrStr
                          (pPVar11,__pyx_mstate_global_static.__pyx_n_s_stepper_label);
      if (pPVar14 == (PyObject *)0x0) {
        iVar10 = 0x1294;
        iVar9 = 0x46;
        goto LAB_0010c080;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      if ((__pyx_mstate_global_static.__pyx_kp_s_Unrecognized_label_read_in_s ==
           (PyObject *)PTR__Py_NoneStruct_00123f68) ||
         ((pPVar14->ob_type->tp_flags & 0x10000000) != 0 &&
          pPVar14->ob_type != (_typeobject *)PTR_PyUnicode_Type_00123fb8)) {
        ppPVar15 = (PyObject **)
                   PyNumber_Remainder(__pyx_mstate_global_static.
                                      __pyx_kp_s_Unrecognized_label_read_in_s,pPVar14);
      }
      else {
        ppPVar15 = (PyObject **)
                   PyUnicode_Format(__pyx_mstate_global_static.
                                    __pyx_kp_s_Unrecognized_label_read_in_s,pPVar14);
      }
      if (ppPVar15 == (PyObject **)0x0) {
        iVar9 = 0x46;
        iVar10 = 0x1297;
        pPVar13 = (PyObject *)0x0;
        goto LAB_0010c134;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      }
      p_Var29 = pPVar12->ob_type;
      if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (p_Var30 = pPVar12[1].ob_type, p_Var30 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar13 = (PyObject *)pPVar12[1].ob_refcnt;
        (p_Var30->ob_base).ob_base.ob_refcnt = (p_Var30->ob_base).ob_base.ob_refcnt + 1;
        pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*p_Var29->tp_dealloc)(pPVar12);
        }
        __pyx_pyargnames[0] = (PyObject **)p_Var30;
        __pyx_pyargnames[1] = ppPVar15;
        pPVar11 = __Pyx_PyObject_FastCallDict(pPVar13,local_50,2,(PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = (p_Var30->ob_base).ob_base.ob_refcnt + -1;
        (p_Var30->ob_base).ob_base.ob_refcnt = lVar27;
        pPVar12 = pPVar13;
        if (lVar27 == 0) {
          (*((p_Var30->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var30);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = ppPVar15;
        pPVar11 = __Pyx_PyObject_FastCallDict
                            (pPVar12,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)p_Var30);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar13 = (PyObject *)((long)&(*ppPVar15)[-1].ob_type + 7);
      *ppPVar15 = pPVar13;
      if (pPVar13 == (PyObject *)0x0) {
        (*(code *)ppPVar15[1][3].ob_refcnt)(ppPVar15);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar9 = 0x46;
        iVar10 = 0x12ad;
        goto LAB_0010c0a4;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      pPVar12 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_stop_read);
      if (pPVar12 == (PyObject *)0x0) {
        iVar9 = 0x47;
        iVar10 = 0x12ba;
        goto LAB_0010bfb0;
      }
      p_Var29 = pPVar12->ob_type;
      if ((p_Var29 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (p_Var34 = pPVar12[1].ob_type, p_Var34 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar13 = (PyObject *)pPVar12[1].ob_refcnt;
        (p_Var34->ob_base).ob_base.ob_refcnt = (p_Var34->ob_base).ob_base.ob_refcnt + 1;
        pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar27;
        if (lVar27 == 0) {
          (*p_Var29->tp_dealloc)(pPVar12);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var34;
        pPVar11 = __Pyx_PyObject_FastCallDict(pPVar13,local_50,1,(PyObject *)p_Var30);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar27 = (p_Var34->ob_base).ob_base.ob_refcnt + -1;
        (p_Var34->ob_base).ob_base.ob_refcnt = lVar27;
        pPVar12 = pPVar13;
        if (lVar27 == 0) {
          (*((p_Var34->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var34);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar11 = __Pyx_PyObject_FastCallDict
                            (pPVar12,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)p_Var30);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar9 = 0x47;
        iVar10 = 0x12ce;
        goto LAB_0010c0a4;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      pPVar13 = __Pyx_PyObject_GetAttrStr(pPVar33,__pyx_mstate_global_static.__pyx_n_s_stepper);
      if (pPVar13 == (PyObject *)0x0) {
        iVar9 = 0x48;
        iVar10 = 0x12dc;
        goto LAB_0010bfb0;
      }
      pPVar12 = __Pyx_PyObject_GetAttrStr(pPVar13,__pyx_mstate_global_static.__pyx_n_s_reactor);
      if (pPVar12 == (PyObject *)0x0) {
        iVar9 = 0x48;
        iVar10 = 0x12de;
        goto LAB_0010bf70;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      pPVar33 = __Pyx_PyObject_GetAttrStr(pPVar12,__pyx_mstate_global_static.__pyx_n_s_NEVER);
      if (pPVar33 == (PyObject *)0x0) {
        pPVar14 = (PyObject *)0x0;
        iVar9 = 0x48;
        iVar10 = 0x12e1;
        pPVar13 = (PyObject *)0x0;
        goto LAB_0010c134;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar12->ob_refcnt + -1;
      pPVar12->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
      lVar27 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar27;
      if (lVar27 == 0) goto LAB_0010bfe4;
      lVar27 = pPVar16->ob_refcnt + -1;
      pPVar16->ob_refcnt = lVar27;
      if (lVar27 == 0) goto LAB_0010c008;
LAB_0010c01c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar27 = pPVar32->ob_refcnt + -1;
      pPVar32->ob_refcnt = lVar27;
      if (lVar27 == 0) {
        (*pPVar32->ob_type->tp_dealloc)(pPVar32);
      }
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar31 != (PyObject *)0x0) &&
       (lVar27 = pPVar31->ob_refcnt + -1, pPVar31->ob_refcnt = lVar27, lVar27 == 0)) {
      (*pPVar31->ob_type->tp_dealloc)(pPVar31);
    }
    goto LAB_0010b358;
  }
LAB_0010beec:
  lVar27 = PyErr_Occurred();
  if (lVar27 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_schedule_rfid_read"
                 ,"exactly",2,"s",1);
    iVar10 = 0x1076;
  }
  else {
    iVar10 = 0x1074;
  }
LAB_0010b33c:
  pPVar33 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID._schedule_rfid_read",iVar10,0x2b,"box_rfid.py");
LAB_0010b358:
  if (lVar25 == *(long *)PTR___stack_chk_guard_00123f48) {
    return pPVar33;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010e258
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_11start_rfid_read
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_11start_rfid_read(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Exceeded maximum restarts with more pending */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_11start_rfid_read
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
  PyObject *pPVar11;
  long lVar12;
  long *plVar13;
  setattrfunc *__s2;
  int py_line;
  getattrofunc p_Var14;
  long lVar15;
  PyObject *pPVar16;
  setattrofunc p_Var17;
  char *pcVar18;
  uint uVar19;
  long lVar20;
  uint uVar21;
  long lVar22;
  _typeobject *p_Var23;
  PyObject *pPVar24;
  _typeobject *p_Var25;
  PyObject *pPVar26;
  long lVar27;
  Py_ssize_t PVar28;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_stepper@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar20 = *(long *)PTR___stack_chk_guard_00123f48;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_stepper;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar18 = PTR___stack_chk_guard_00123f48;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar22 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0010e9cc;
      }
      if (__pyx_nargs == 0) {
        lVar22 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar22 = lVar22 + -1;
          PVar28 = __pyx_kwds[1].ob_refcnt;
          goto LAB_0010ea04;
        }
        lVar22 = PyErr_Occurred();
        if (lVar22 != 0) {
          iVar8 = 0x1463;
          goto LAB_0010e304;
        }
      }
LAB_0010e2c8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","start_rfid_read",
                   "exactly",2,"s",__pyx_nargs);
      iVar8 = 0x147f;
      goto LAB_0010e304;
    }
    lVar22 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    PVar28 = lVar22;
LAB_0010ea04:
    pPVar9 = __pyx_mstate_global_static.__pyx_n_s_stepper;
    puVar5 = PTR_PyUnicode_Type_00123fb8;
    puVar4 = PTR__Py_TrueStruct_00123f70;
    puVar3 = PTR__Py_NoneStruct_00123f68;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < PVar28) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_stepper == p_Var23) {
        values[1] = *kwvalues;
      }
      else {
        lVar12 = 0;
        do {
          lVar27 = lVar12 + 1;
          if (lVar27 == PVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar12 = 0;
            goto LAB_0010ea68;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar12;
          lVar12 = lVar27;
        } while (__pyx_mstate_global_static.__pyx_n_s_stepper != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar27];
      }
      goto LAB_0010eb84;
    }
LAB_0010ec38:
    values[1] = (PyObject *)0x0;
    goto LAB_0010ec3c;
  }
  if (__pyx_nargs != 2) goto LAB_0010e2c8;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0010e360:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar11 = values[1];
  pPVar9 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  pPVar16 = (PyObject *)values[0]->ob_type->tp_setattro;
  if (pPVar16 == (PyObject *)0x0) {
    iVar8 = PyObject_SetAttr(values[0],__pyx_mstate_global_static.__pyx_n_s_stepper,values[1]);
  }
  else {
    iVar8 = (*(code *)pPVar16)();
  }
  if (iVar8 < 0) {
    py_line = 0x55;
    iVar8 = 0x14b0;
  }
  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var14 = pPVar9->ob_type->tp_getattro;
    if (p_Var14 == (getattrofunc)0x0) {
      pPVar10 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar10 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_read_card);
    }
    if (pPVar10 == (PyObject *)0x0) {
      py_line = 0x56;
      iVar8 = 0x14b9;
    }
    else {
      p_Var23 = pPVar10->ob_type;
      if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
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
        pPVar16 = __Pyx_PyObject_FastCallDict(pPVar24,(PyObject **)__pyx_pyargnames,1,pPVar16);
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
        pPVar16 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)(__pyx_pyargnames + 1),0,pPVar16)
        ;
      }
      if (pPVar16 == (PyObject *)0x0) {
        py_line = 0x56;
        iVar8 = 0x14cd;
LAB_0010ed34:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        lVar22 = pPVar10->ob_refcnt + -1;
        goto LAB_0010ed40;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar16->ob_refcnt + -1;
      pPVar16->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar16->ob_type->tp_dealloc)(pPVar16);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var17 = pPVar9->ob_type->tp_setattro;
      if (p_Var17 == (setattrofunc)0x0) {
        iVar8 = PyObject_SetAttr();
      }
      else {
        iVar8 = (*p_Var17)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_get_message_count,
                           __pyx_mstate_global_static.__pyx_int_1);
      }
      if (iVar8 < 0) {
        py_line = 0x57;
        iVar8 = 0x14da;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var17 = pPVar9->ob_type->tp_setattro;
        if (p_Var17 == (setattrofunc)0x0) {
          iVar8 = PyObject_SetAttr();
        }
        else {
          iVar8 = (*p_Var17)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_temp_message_1,
                             (PyObject *)PTR__Py_NoneStruct_00123f68);
        }
        if (iVar8 < 0) {
          py_line = 0x58;
          iVar8 = 0x14e3;
        }
        else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var17 = pPVar9->ob_type->tp_setattro;
          if (p_Var17 == (setattrofunc)0x0) {
            iVar8 = PyObject_SetAttr();
          }
          else {
            iVar8 = (*p_Var17)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_temp_message_2,
                               (PyObject *)PTR__Py_NoneStruct_00123f68);
          }
          if (iVar8 < 0) {
            py_line = 0x59;
            iVar8 = 0x14ec;
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var17 = pPVar9->ob_type->tp_setattro;
            if (p_Var17 == (setattrofunc)0x0) {
              iVar8 = PyObject_SetAttr();
            }
            else {
              iVar8 = (*p_Var17)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_rfid_read_attempts,
                                 __pyx_mstate_global_static.__pyx_int_0);
            }
            if (iVar8 < 0) {
              py_line = 0x5a;
              iVar8 = 0x14f5;
            }
            else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
              pPVar16 = (PyObject *)pPVar9->ob_type->tp_setattro;
              if (pPVar16 == (PyObject *)0x0) {
                iVar8 = PyObject_SetAttr(pPVar9,__pyx_mstate_global_static.__pyx_n_s_had_get_value,
                                         PTR__Py_FalseStruct_00123f38);
              }
              else {
                iVar8 = (*(code *)pPVar16)();
              }
              if (iVar8 < 0) {
                py_line = 0x5b;
                iVar8 = 0x14fe;
              }
              else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                p_Var14 = pPVar11->ob_type->tp_getattro;
                if (p_Var14 == (getattrofunc)0x0) {
                  pPVar10 = (PyObject *)PyObject_GetAttr();
                }
                else {
                  pPVar10 = (*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_reactor);
                }
                if (pPVar10 == (PyObject *)0x0) {
                  py_line = 0x5c;
                  iVar8 = 0x1507;
                }
                else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                  p_Var14 = pPVar10->ob_type->tp_getattro;
                  if (p_Var14 == (getattrofunc)0x0) {
                    pPVar24 = (PyObject *)PyObject_GetAttr();
                  }
                  else {
                    pPVar24 = (*p_Var14)(pPVar10,__pyx_mstate_global_static.__pyx_n_s_monotonic);
                  }
                  lVar22 = pPVar10->ob_refcnt + -1;
                  if (pPVar24 == (PyObject *)0x0) {
                    py_line = 0x5c;
                    iVar8 = 0x1509;
LAB_0010ed40:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar10->ob_refcnt = lVar22;
                    pPVar16 = pPVar10;
joined_r0x0010ed44:
                    if (lVar22 == 0) {
                      (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    }
                  }
                  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar10->ob_refcnt = lVar22;
                    if (lVar22 == 0) {
                      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                    }
                    p_Var23 = pPVar24->ob_type;
                    if (p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) {
                      p_Var25 = pPVar24[1].ob_type;
                      pPVar16 = (PyObject *)0x0;
                      if (p_Var25 == (_typeobject *)0x0) goto LAB_0010eec8;
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar10 = (PyObject *)pPVar24[1].ob_refcnt;
                      (p_Var25->ob_base).ob_base.ob_refcnt =
                           (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                      pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar22 = pPVar24->ob_refcnt + -1;
                      pPVar24->ob_refcnt = lVar22;
                      if (lVar22 == 0) {
                        (*p_Var23->tp_dealloc)(pPVar24);
                      }
                      __pyx_pyargnames[1] = (PyObject **)0x0;
                      __pyx_pyargnames[0] = (PyObject **)p_Var25;
                      pPVar16 = __Pyx_PyObject_FastCallDict
                                          (pPVar10,(PyObject **)__pyx_pyargnames,1,
                                           (PyObject *)p_Var25);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
                      pPVar24 = pPVar10;
                      if (lVar22 == 0) {
                        (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
                      }
                    }
                    else {
LAB_0010eec8:
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = (PyObject **)0x0;
                      pPVar16 = __Pyx_PyObject_FastCallDict
                                          (pPVar24,(PyObject **)(__pyx_pyargnames + 1),0,pPVar16);
                    }
                    if (pPVar16 == (PyObject *)0x0) {
                      py_line = 0x5c;
                      iVar8 = 0x151e;
LAB_0010ef64:
                      lVar22 = pPVar24->ob_refcnt + -1;
LAB_0010ef6c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      pPVar24->ob_refcnt = lVar22;
                      if (lVar22 == 0) {
                        pPVar11 = (PyObject *)0x0;
LAB_0010ef78:
                        (*pPVar24->ob_type->tp_dealloc)(pPVar24);
LAB_0010ef90:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        if ((pPVar11 != (PyObject *)0x0) &&
                           (lVar22 = pPVar11->ob_refcnt + -1, pPVar11->ob_refcnt = lVar22,
                           lVar22 == 0)) {
                          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                        }
                      }
                    }
                    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar22 = pPVar24->ob_refcnt + -1;
                      pPVar24->ob_refcnt = lVar22;
                      if (lVar22 == 0) {
                        (*pPVar24->ob_type->tp_dealloc)(pPVar24);
                      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                      pPVar10 = (PyObject *)pPVar9->ob_type->tp_setattro;
                      if (pPVar10 == (PyObject *)0x0) {
                        iVar8 = PyObject_SetAttr(pPVar9,__pyx_mstate_global_static.
                                                        __pyx_n_s_rfid_read_start_time,pPVar16);
                      }
                      else {
                        iVar8 = (*(code *)pPVar10)();
                      }
                      lVar22 = pPVar16->ob_refcnt + -1;
                      if (iVar8 < 0) {
                        iVar8 = 0x1522;
                        py_line = 0x5c;
LAB_0010ef38:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        pPVar16->ob_refcnt = lVar22;
                        goto joined_r0x0010ed44;
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      pPVar16->ob_refcnt = lVar22;
                      if (lVar22 == 0) {
                        (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                      p_Var14 = pPVar9->ob_type->tp_getattro;
                      if (p_Var14 == (getattrofunc)0x0) {
                        pPVar16 = (PyObject *)PyObject_GetAttr();
                      }
                      else {
                        pPVar16 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.
                                                    __pyx_n_s_read_rfid_timer);
                      }
                      if (pPVar16 == (PyObject *)0x0) {
                        py_line = 0x5d;
                        iVar8 = 0x152c;
                      }
                      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        lVar22 = pPVar16->ob_refcnt + -1;
                        pPVar16->ob_refcnt = lVar22;
                        if (lVar22 == 0) {
                          (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                        }
                        if (pPVar16 != (PyObject *)PTR__Py_NoneStruct_00123f68) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                          p_Var14 = pPVar9->ob_type->tp_getattro;
                          if (p_Var14 == (getattrofunc)0x0) {
                            pPVar24 = (PyObject *)PyObject_GetAttr();
                          }
                          else {
                            pPVar24 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.
                                                        __pyx_n_s_stop_read);
                          }
                          if (pPVar24 == (PyObject *)0x0) {
                            py_line = 0x5e;
                            iVar8 = 0x1539;
                            goto LAB_0010eca0;
                          }
                          p_Var23 = pPVar24->ob_type;
                          if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                             (p_Var25 = pPVar24[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                            pPVar26 = (PyObject *)pPVar24[1].ob_refcnt;
                            (p_Var25->ob_base).ob_base.ob_refcnt =
                                 (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                            pPVar26->ob_refcnt = pPVar26->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            lVar22 = pPVar24->ob_refcnt + -1;
                            pPVar24->ob_refcnt = lVar22;
                            if (lVar22 == 0) {
                              (*p_Var23->tp_dealloc)(pPVar24);
                            }
                            __pyx_pyargnames[1] = (PyObject **)0x0;
                            __pyx_pyargnames[0] = (PyObject **)p_Var25;
                            pPVar16 = __Pyx_PyObject_FastCallDict
                                                (pPVar26,(PyObject **)__pyx_pyargnames,1,pPVar10);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                            lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                            (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
                            pPVar24 = pPVar26;
                            if (lVar22 == 0) {
                              (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)
                                        ((PyObject *)p_Var25);
                            }
                          }
                          else {
                            __pyx_pyargnames[0] = (PyObject **)0x0;
                            __pyx_pyargnames[1] = (PyObject **)0x0;
                            pPVar16 = __Pyx_PyObject_FastCallDict
                                                (pPVar24,(PyObject **)(__pyx_pyargnames + 1),0,
                                                 pPVar10);
                          }
                          if (pPVar16 == (PyObject *)0x0) {
                            py_line = 0x5e;
                            iVar8 = 0x154d;
                            goto LAB_0010ef64;
                          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar22 = pPVar24->ob_refcnt + -1;
                          pPVar24->ob_refcnt = lVar22;
                          if (lVar22 == 0) {
                            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
                          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          lVar22 = pPVar16->ob_refcnt + -1;
                          pPVar16->ob_refcnt = lVar22;
                          if (lVar22 == 0) {
                            (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                          }
                        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                        p_Var14 = pPVar11->ob_type->tp_getattro;
                        if (p_Var14 == (getattrofunc)0x0) {
                          pPVar24 = (PyObject *)PyObject_GetAttr();
                        }
                        else {
                          pPVar24 = (*p_Var14)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_reactor)
                          ;
                        }
                        if (pPVar24 != (PyObject *)0x0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                          p_Var14 = pPVar24->ob_type->tp_getattro;
                          if (p_Var14 == (getattrofunc)0x0) {
                            pPVar10 = (PyObject *)PyObject_GetAttr();
                          }
                          else {
                            pPVar10 = (*p_Var14)(pPVar24,__pyx_mstate_global_static.
                                                         __pyx_n_s_register_timer);
                          }
                          lVar22 = pPVar24->ob_refcnt + -1;
                          if (pPVar10 == (PyObject *)0x0) {
                            py_line = 0x5f;
                            iVar8 = 0x1565;
                            goto LAB_0010ef6c;
                          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                          pPVar24->ob_refcnt = lVar22;
                          if (lVar22 == 0) {
                            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
                          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                          p_Var14 = pPVar9->ob_type->tp_getattro;
                          if (p_Var14 == (getattrofunc)0x0) {
                            pPVar24 = (PyObject *)PyObject_GetAttr();
                          }
                          else {
                            pPVar24 = (*p_Var14)(pPVar9,__pyx_mstate_global_static.
                                                        __pyx_n_s_schedule_rfid_read);
                          }
                          if (pPVar24 == (PyObject *)0x0) {
                            py_line = 0x60;
                            iVar8 = 0x1570;
                            lVar22 = pPVar10->ob_refcnt + -1;
                            goto LAB_0010ed40;
                          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                          p_Var14 = pPVar11->ob_type->tp_getattro;
                          if (p_Var14 == (getattrofunc)0x0) {
                            pPVar11 = (PyObject *)PyObject_GetAttr();
                          }
                          else {
                            pPVar11 = (*p_Var14)(pPVar11,__pyx_mstate_global_static.
                                                         __pyx_n_s_reactor);
                          }
                          if (pPVar11 == (PyObject *)0x0) {
                            iVar8 = 0x1572;
                          }
                          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
                            p_Var14 = pPVar11->ob_type->tp_getattro;
                            if (p_Var14 == (getattrofunc)0x0) {
                              pPVar26 = (PyObject *)
                                        PyObject_GetAttr(pPVar11,__pyx_mstate_global_static.
                                                                 __pyx_n_s_NOW);
                            }
                            else {
                              pPVar26 = (PyObject *)(*p_Var14)();
                            }
                            if (pPVar26 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                              lVar22 = pPVar11->ob_refcnt + -1;
                              pPVar11->ob_refcnt = lVar22;
                              if (lVar22 == 0) {
                                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                              }
                              p_Var23 = pPVar10->ob_type;
                              if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                                 (p_Var25 = pPVar10[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                                pPVar11 = (PyObject *)pPVar10[1].ob_refcnt;
                                (p_Var25->ob_base).ob_base.ob_refcnt =
                                     (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                                pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                lVar22 = pPVar10->ob_refcnt + -1;
                                pPVar10->ob_refcnt = lVar22;
                                if (lVar22 == 0) {
                                  (*p_Var23->tp_dealloc)(pPVar10);
                                }
                                __pyx_pyargnames[0] = (PyObject **)p_Var25;
                                __pyx_pyargnames[1] = (PyObject **)pPVar24;
                                __pyx_pyargnames[2] = (PyObject **)pPVar26;
                                pPVar16 = __Pyx_PyObject_FastCallDict
                                                    (pPVar11,(PyObject **)__pyx_pyargnames,3,pPVar26
                                                    );
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                lVar22 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
                                (p_Var25->ob_base).ob_base.ob_refcnt = lVar22;
                                pPVar10 = pPVar11;
                                if (lVar22 == 0) {
                                  (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)
                                            ((PyObject *)p_Var25);
                                }
                              }
                              else {
                                __pyx_pyargnames[0] = (PyObject **)0x0;
                                __pyx_pyargnames[1] = (PyObject **)pPVar24;
                                __pyx_pyargnames[2] = (PyObject **)pPVar26;
                                pPVar16 = __Pyx_PyObject_FastCallDict
                                                    (pPVar10,(PyObject **)(__pyx_pyargnames + 1),2,
                                                     pPVar26);
                              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                              lVar22 = pPVar24->ob_refcnt + -1;
                              pPVar24->ob_refcnt = lVar22;
                              if (lVar22 == 0) {
                                (*pPVar24->ob_type->tp_dealloc)(pPVar24);
                              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                              lVar22 = pPVar26->ob_refcnt + -1;
                              pPVar26->ob_refcnt = lVar22;
                              if (lVar22 == 0) {
                                (*pPVar26->ob_type->tp_dealloc)(pPVar26);
                              }
                              if (pPVar16 == (PyObject *)0x0) {
                                py_line = 0x5f;
                                iVar8 = 0x158b;
                                goto LAB_0010ed34;
                              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                              lVar22 = pPVar10->ob_refcnt + -1;
                              pPVar10->ob_refcnt = lVar22;
                              if (lVar22 == 0) {
                                (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                              }
                              iVar8 = __Pyx_PyObject_SetAttrStr
                                                (pPVar9,__pyx_mstate_global_static.
                                                        __pyx_n_s_read_rfid_timer,pPVar16);
                              if (-1 < iVar8) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                                lVar22 = pPVar16->ob_refcnt + -1;
                                pPVar16->ob_refcnt = lVar22;
                                if (lVar22 == 0) {
                                  (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                                }
                                pPVar9 = (PyObject *)PTR__Py_NoneStruct_00123f68;
                                *(long *)PTR__Py_NoneStruct_00123f68 =
                                     *(long *)PTR__Py_NoneStruct_00123f68 + 1;
                                goto LAB_0010e320;
                              }
                              iVar8 = 0x1597;
                              py_line = 0x5f;
                              lVar22 = pPVar16->ob_refcnt + -1;
                              goto LAB_0010ef38;
                            }
                            iVar8 = 0x1574;
                          }
                          lVar22 = pPVar10->ob_refcnt + -1;
                          pPVar10->ob_refcnt = lVar22;
                          if (lVar22 == 0) {
                            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                          }
                          py_line = 0x60;
                          lVar22 = pPVar24->ob_refcnt + -1;
                          pPVar24->ob_refcnt = lVar22;
                          if (lVar22 == 0) goto LAB_0010ef78;
                          goto LAB_0010ef90;
                        }
                        py_line = 0x5f;
                        iVar8 = 0x1563;
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
LAB_0010eca0:
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID.start_rfid_read",iVar8,py_line,"box_rfid.py");
  pPVar9 = (PyObject *)0x0;
LAB_0010e320:
  if (lVar20 == *(long *)PTR___stack_chk_guard_00123f48) {
    return pPVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar27 = lVar12 + 1;
    if (lVar27 == PVar28) goto LAB_0010ec38;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar27;
    if ((_typeobject *)pPVar9 == p_Var23) break;
LAB_0010ea68:
    bVar6 = pPVar9->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar27 = lVar12;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar9 != (PyObject *)puVar3) && (bVar6 || p_Var23 != (_typeobject *)puVar3)) {
        plVar13 = (long *)PyObject_RichCompare(pPVar9,p_Var23,2);
        if (plVar13 == (long *)0x0) goto LAB_0010ec38;
        uVar19 = (uint)(plVar13 == (long *)puVar4);
        if ((plVar13 != (long *)puVar4 && plVar13 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar13 != (long *)puVar3) {
          uVar19 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = *plVar13;
        *plVar13 = lVar15 + -1;
        if (lVar15 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_0010ec28:
        if (uVar19 != 0) {
          if ((int)uVar19 < 0) goto LAB_0010ec38;
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
         ((-1 < (char)p_Var23->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var23), iVar8 < 0))))
      goto LAB_0010ec38;
      lVar15 = pPVar9[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar15 == (p_Var23->ob_base).ob_size) &&
         ((pPVar9[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar9[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar18 = (char *)((ulong)(byte)((byte)pPVar9[2].ob_refcnt >> 2) & 7);
        uVar19 = (uint)pcVar18;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar19) {
          bVar2 = (byte)pPVar9[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var25 = pPVar9[4].ob_type;
          }
          else {
            p_Var25 = (_typeobject *)&pPVar9[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var25 = (_typeobject *)(pPVar9 + 3);
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
          if (uVar19 == 1) {
            uVar19 = (uint)(byte)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(byte *)__s2;
          }
          else if (uVar19 == 2) {
            uVar19 = (uint)(ushort)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(ushort *)__s2;
          }
          else {
            uVar19 = (uint)(p_Var25->ob_base).ob_base.ob_refcnt;
            uVar21 = *(uint *)__s2;
          }
          if (uVar21 == uVar19) {
            if (lVar15 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var25,__s2,(long)pcVar18 * lVar15);
              uVar19 = (uint)(iVar8 == 0);
              goto LAB_0010ec28;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar27];
LAB_0010eb84:
  if (values[1] == (PyObject *)0x0) {
LAB_0010ec3c:
    lVar22 = PyErr_Occurred();
    if (lVar22 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","start_rfid_read",
                   "exactly",2,"s",1);
      iVar8 = 0x146d;
    }
    else {
      iVar8 = 0x146b;
    }
  }
  else {
    lVar22 = lVar22 + -1;
LAB_0010e9cc:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar22 < 1) ||
       (iVar8 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x111c18,pcVar18), -1 < iVar8))
    goto LAB_0010e360;
    iVar8 = 0x1472;
  }
LAB_0010e304:
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID.start_rfid_read",iVar8,0x54,"box_rfid.py");
  pPVar9 = (PyObject *)0x0;
  goto LAB_0010e320;
}


/* ================================================================
 * Address: 0010f108
 * Symbol:  __pyx_pw_6extras_8box_rfid_7BoxRFID_1__init__
 * Signature: PyObject * __pyx_pw_6extras_8box_rfid_7BoxRFID_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_8box_rfid_7BoxRFID_1__init__
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
  undefined1 *puVar10;
  long *plVar11;
  setattrfunc *__s2;
  getattrofunc p_Var12;
  ssizeargfunc p_Var13;
  setattrofunc p_Var14;
  char *pcVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  _typeobject *p_Var19;
  _typeobject *p_Var20;
  PyMappingMethods *pPVar21;
  long lVar22;
  _typeobject *p_Var23;
  _typeobject *func;
  PyObject *pPVar24;
  PyObject **ppPVar25;
  PyObject *pPVar26;
  PyObject *pPVar27;
  int py_line;
  PyObject *pPVar28;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar17 = *(long *)PTR___stack_chk_guard_00123f48;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_config;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar9 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0010f178;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_0010f210;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar25 = __pyx_args + __pyx_nargs;
  pcVar15 = PTR___stack_chk_guard_00123f48;
  if (__pyx_nargs == 1) {
    pPVar9 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar28 = pPVar9;
LAB_0010f554:
    pPVar27 = __pyx_mstate_global_static.__pyx_n_s_config;
    puVar5 = PTR_PyUnicode_Type_00123fb8;
    puVar4 = PTR__Py_TrueStruct_00123f70;
    puVar3 = PTR__Py_NoneStruct_00123f68;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar28) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var23) {
        values[1] = *ppPVar25;
      }
      else {
        pPVar26 = (PyObject *)0x0;
        do {
          pPVar24 = (PyObject *)((long)&pPVar26->ob_refcnt + 1);
          if (pPVar24 == pPVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar26 = (PyObject *)0x0;
            goto LAB_0010f5b8;
          }
          pPVar2 = &__pyx_kwds[2].ob_refcnt + (long)pPVar26;
          pPVar26 = pPVar24;
        } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar2);
        values[1] = ppPVar25[(long)pPVar24];
      }
      goto LAB_00110330;
    }
LAB_001103e0:
    values[1] = (PyObject *)0x0;
    goto LAB_001103e4;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar10 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_0010f51c;
  }
  if (__pyx_nargs == 0) {
    lVar22 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar25,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar9 = (PyObject *)(lVar22 + -1);
      pPVar28 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      goto LAB_0010f554;
    }
    lVar22 = PyErr_Occurred();
    if (lVar22 != 0) {
      iVar8 = 0xb94;
      goto LAB_0010f1b4;
    }
  }
LAB_0010f178:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",2,
               "s",__pyx_nargs);
  iVar8 = 0xbb0;
  goto LAB_0010f1b4;
  while( true ) {
    pPVar2 = &pPVar26->ob_refcnt;
    pPVar26 = (PyObject *)((long)pPVar2 + 1);
    if (pPVar26 == pPVar28) goto LAB_001103e0;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar2];
    if ((_typeobject *)pPVar27 == p_Var23) break;
LAB_0010f5b8:
    bVar6 = pPVar27->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar27 != (PyObject *)puVar3) && (bVar6 || p_Var23 != (_typeobject *)puVar3)) {
        plVar11 = (long *)PyObject_RichCompare(pPVar27,p_Var23,2);
        if (plVar11 == (long *)0x0) goto LAB_001103e0;
        uVar16 = (uint)(plVar11 == (long *)puVar4);
        if ((plVar11 != (long *)puVar4 && plVar11 != (long *)PTR__Py_FalseStruct_00123f38) &&
            plVar11 != (long *)puVar3) {
          uVar16 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = *plVar11;
        *plVar11 = lVar22 + -1;
        if (lVar22 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_001103d4:
        if (uVar16 != 0) {
          if ((int)uVar16 < 0) goto LAB_001103e0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar27[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar27), iVar8 < 0)) ||
         ((-1 < (char)p_Var23->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var23), iVar8 < 0))))
      goto LAB_001103e0;
      lVar22 = pPVar27[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar22 == (p_Var23->ob_base).ob_size) &&
         ((pPVar27[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar27[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar15 = (char *)((ulong)(byte)((byte)pPVar27[2].ob_refcnt >> 2) & 7);
        uVar16 = (uint)pcVar15;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar16) {
          bVar1 = (byte)pPVar27[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            p_Var19 = pPVar27[4].ob_type;
          }
          else {
            p_Var19 = (_typeobject *)&pPVar27[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              p_Var19 = (_typeobject *)(pPVar27 + 3);
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
          if (uVar16 == 1) {
            uVar16 = (uint)(byte)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(byte *)__s2;
          }
          else if (uVar16 == 2) {
            uVar16 = (uint)(ushort)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(ushort *)__s2;
          }
          else {
            uVar16 = (uint)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar18 = *(uint *)__s2;
          }
          if (uVar18 == uVar16) {
            if (lVar22 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var19,__s2,(long)pcVar15 * lVar22);
              uVar16 = (uint)(iVar8 == 0);
              goto LAB_001103d4;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar25[(long)pPVar26];
LAB_00110330:
  if (values[1] != (PyObject *)0x0) {
    puVar10 = (undefined1 *)((long)&pPVar9[-1].ob_type + 7);
LAB_0010f51c:
    if (0 < (long)puVar10) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar9 = (PyObject *)values;
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar25,__pyx_pyargnames,pPVar9,(PyObject **)__pyx_nargs,
                         0x111c40,pcVar15);
      if (iVar8 < 0) {
        iVar8 = 0xba3;
        goto LAB_0010f1b4;
      }
    }
LAB_0010f210:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar27 = values[1];
    pPVar28 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var12 = values[1]->ob_type->tp_getattro;
    if (p_Var12 == (getattrofunc)0x0) {
      pPVar26 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar26 = (*p_Var12)(values[1],__pyx_mstate_global_static.__pyx_n_s_get_printer);
    }
    if (pPVar26 == (PyObject *)0x0) {
      py_line = 5;
      iVar8 = 0xbe1;
      goto LAB_00110584;
    }
    p_Var23 = pPVar26->ob_type;
    if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
       (p_Var19 = pPVar26[1].ob_type, p_Var19 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar24 = (PyObject *)pPVar26[1].ob_refcnt;
      (p_Var19->ob_base).ob_base.ob_refcnt = (p_Var19->ob_base).ob_base.ob_refcnt + 1;
      pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar26->ob_refcnt + -1;
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*p_Var23->tp_dealloc)(pPVar26);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var19;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar24,(PyObject **)__pyx_pyargnames,1,pPVar9);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
      (p_Var19->ob_base).ob_base.ob_refcnt = lVar22;
      pPVar26 = pPVar24;
      if (lVar22 == 0) {
        (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar26,(PyObject **)(__pyx_pyargnames + 1),0,pPVar9);
    }
    if (pPVar9 == (PyObject *)0x0) {
      py_line = 5;
      iVar8 = 0xbf5;
      p_Var23 = (_typeobject *)0x0;
LAB_001104d8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar26->ob_refcnt + -1;
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 != 0) {
LAB_001104e8:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        pPVar27 = (PyObject *)0x0;
        if (p_Var23 == (_typeobject *)0x0) goto LAB_00110584;
LAB_001104f0:
        pPVar24 = (PyObject *)0x0;
        pPVar9 = (PyObject *)0x0;
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
LAB_00110500:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((pPVar27 != (PyObject *)0x0) &&
           (lVar22 = pPVar27->ob_refcnt + -1, pPVar27->ob_refcnt = lVar22, lVar22 == 0)) {
LAB_0011052c:
          (*pPVar27->ob_type->tp_dealloc)(pPVar27);
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((pPVar9 != (PyObject *)0x0) &&
           (lVar22 = pPVar9->ob_refcnt + -1, pPVar9->ob_refcnt = lVar22, lVar22 == 0)) {
          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
        }
        goto LAB_00110560;
      }
      pPVar27 = (PyObject *)0x0;
LAB_001105ac:
      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      if (p_Var23 != (_typeobject *)0x0) goto LAB_001104f0;
      if (pPVar27 != (PyObject *)0x0) {
LAB_001105c4:
        lVar22 = pPVar27->ob_refcnt + -1;
        pPVar27->ob_refcnt = lVar22;
        if (lVar22 != 0) goto LAB_00110584;
        pPVar9 = (PyObject *)0x0;
        pPVar24 = (PyObject *)0x0;
        goto LAB_0011052c;
      }
    }
    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar26->ob_refcnt + -1;
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      pPVar24 = (PyObject *)pPVar28->ob_type->tp_setattro;
      if (pPVar24 == (PyObject *)0x0) {
        iVar8 = PyObject_SetAttr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_printer,pPVar9);
      }
      else {
        iVar8 = (*(code *)pPVar24)();
      }
      lVar22 = pPVar9->ob_refcnt + -1;
      if (iVar8 < 0) {
        iVar8 = 0xbf9;
        py_line = 5;
LAB_001104b4:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar9->ob_refcnt = lVar22;
        if (lVar22 != 0) goto LAB_00110584;
        p_Var23 = (_typeobject *)0x0;
        pPVar26 = (PyObject *)0x0;
LAB_001104c4:
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        if (pPVar26 != (PyObject *)0x0) goto LAB_001104d8;
        goto LAB_001104e8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var12 = pPVar27->ob_type->tp_getattro;
      if (p_Var12 == (getattrofunc)0x0) {
        p_Var23 = (_typeobject *)PyObject_GetAttr();
      }
      else {
        p_Var23 = (_typeobject *)(*p_Var12)(pPVar27,__pyx_mstate_global_static.__pyx_n_s_get_name);
      }
      if (p_Var23 == (_typeobject *)0x0) {
        py_line = 6;
        iVar8 = 0xc03;
        goto LAB_00110584;
      }
      p_Var19 = (p_Var23->ob_base).ob_base.ob_type;
      if ((p_Var19 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (ppPVar25 = (PyObject **)p_Var23->tp_name, ppPVar25 != (PyObject **)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        p_Var20 = (_typeobject *)(p_Var23->ob_base).ob_size;
        *ppPVar25 = (PyObject *)((long)&(*ppPVar25)->ob_refcnt + 1);
        (p_Var20->ob_base).ob_base.ob_refcnt = (p_Var20->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*p_Var19->tp_dealloc)((PyObject *)p_Var23);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = ppPVar25;
        pPVar26 = __Pyx_PyObject_FastCallDict
                            ((PyObject *)p_Var20,(PyObject **)__pyx_pyargnames,1,pPVar24);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar9 = (PyObject *)((long)&(*ppPVar25)[-1].ob_type + 7);
        *ppPVar25 = pPVar9;
        p_Var23 = p_Var20;
        if (pPVar9 == (PyObject *)0x0) {
          (*(code *)ppPVar25[1][3].ob_refcnt)(ppPVar25);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar26 = __Pyx_PyObject_FastCallDict
                            ((PyObject *)p_Var23,(PyObject **)(__pyx_pyargnames + 1),0,pPVar24);
      }
      if (pPVar26 == (PyObject *)0x0) {
        py_line = 6;
        iVar8 = 0xc17;
        pPVar27 = (PyObject *)0x0;
        goto LAB_001104f0;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var12 = pPVar26->ob_type->tp_getattro;
      if (p_Var12 == (getattrofunc)0x0) {
        p_Var23 = (_typeobject *)PyObject_GetAttr();
      }
      else {
        p_Var23 = (_typeobject *)(*p_Var12)(pPVar26,__pyx_mstate_global_static.__pyx_n_s_split);
      }
      lVar22 = pPVar26->ob_refcnt + -1;
      if (p_Var23 == (_typeobject *)0x0) {
        py_line = 6;
        iVar8 = 0xc1b;
        goto LAB_00110774;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      }
      p_Var19 = (p_Var23->ob_base).ob_base.ob_type;
      if ((p_Var19 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (ppPVar25 = (PyObject **)p_Var23->tp_name, ppPVar25 != (PyObject **)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        p_Var20 = (_typeobject *)(p_Var23->ob_base).ob_size;
        *ppPVar25 = (PyObject *)((long)&(*ppPVar25)->ob_refcnt + 1);
        (p_Var20->ob_base).ob_base.ob_refcnt = (p_Var20->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*p_Var19->tp_dealloc)((PyObject *)p_Var23);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = ppPVar25;
        pPVar9 = __Pyx_PyObject_FastCallDict
                           ((PyObject *)p_Var20,(PyObject **)__pyx_pyargnames,1,pPVar24);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar26 = (PyObject *)((long)&(*ppPVar25)[-1].ob_type + 7);
        *ppPVar25 = pPVar26;
        p_Var23 = p_Var20;
        if (pPVar26 == (PyObject *)0x0) {
          (*(code *)ppPVar25[1][3].ob_refcnt)(ppPVar25);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar9 = __Pyx_PyObject_FastCallDict
                           ((PyObject *)p_Var23,(PyObject **)(__pyx_pyargnames + 1),0,pPVar24);
      }
      if (pPVar9 == (PyObject *)0x0) {
        py_line = 6;
        iVar8 = 0xc30;
        pPVar27 = (PyObject *)0x0;
        goto LAB_001104f0;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
        p_Var23 = pPVar9->ob_type;
        if (p_Var23 == (_typeobject *)PTR_PyList_Type_00123fe0) goto LAB_0010f6e0;
LAB_0010f49c:
        if (p_Var23 != (_typeobject *)PTR_PyTuple_Type_00123f08) {
                    /* Unresolved local var: PyMappingMethods * mm@[???]
                       Unresolved local var: PySequenceMethods * sm@[???] */
          pPVar21 = p_Var23->tp_as_mapping;
          if ((pPVar21 != (PyMappingMethods *)0x0) && (pPVar21->mp_subscript != (binaryfunc)0x0)) {
                    /* Unresolved local var: PyObject * r@[DW_OP_reg19(x19)]
                       Unresolved local var: PyObject * key@[???] */
            pPVar26 = (PyObject *)PyLong_FromSsize_t(1);
            if (pPVar26 == (PyObject *)0x0) goto LAB_00110910;
            p_Var23 = (_typeobject *)(*pPVar21->mp_subscript)(pPVar9,pPVar26);
            goto LAB_0010f4dc;
          }
          if ((p_Var23->tp_as_sequence == (PySequenceMethods *)0x0) ||
             (p_Var13 = p_Var23->tp_as_sequence->sq_item, p_Var13 == (ssizeargfunc)0x0))
          goto LAB_001107e0;
          p_Var23 = (_typeobject *)(*p_Var13)(pPVar9,1);
          goto LAB_0010f4f0;
        }
                    /* Unresolved local var: Py_ssize_t n@[???] */
        if ((ulong)pPVar9[1].ob_refcnt < 2) goto LAB_001107e0;
                    /* Unresolved local var: PyObject * r@[???] */
        p_Var23 = (_typeobject *)pPVar9[2].ob_refcnt;
LAB_0010f740:
        (p_Var23->ob_base).ob_base.ob_refcnt = (p_Var23->ob_base).ob_base.ob_refcnt + 1;
        lVar22 = pPVar9->ob_refcnt + -1;
      }
      else {
        p_Var23 = pPVar9->ob_type;
        if (p_Var23 != (_typeobject *)PTR_PyList_Type_00123fe0) goto LAB_0010f49c;
LAB_0010f6e0:
                    /* Unresolved local var: Py_ssize_t n@[???] */
        if (1 < (ulong)pPVar9[1].ob_refcnt) {
                    /* Unresolved local var: PyObject * r@[???] */
          p_Var23 = ((pPVar9[1].ob_type)->ob_base).ob_base.ob_type;
          goto LAB_0010f740;
        }
LAB_001107e0:
        pPVar26 = (PyObject *)PyLong_FromSsize_t(1);
        if (pPVar26 == (PyObject *)0x0) {
LAB_00110910:
          iVar8 = 0xc34;
          py_line = 6;
          lVar22 = pPVar9->ob_refcnt + -1;
          goto LAB_001104b4;
        }
        p_Var23 = (_typeobject *)PyObject_GetItem(pPVar9,pPVar26);
LAB_0010f4dc:
                    /* Unresolved local var: PyObject * r@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar26->ob_refcnt + -1;
        pPVar26->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar26->ob_type->tp_dealloc)(pPVar26);
        }
LAB_0010f4f0:
        lVar22 = pPVar9->ob_refcnt + -1;
        if (p_Var23 == (_typeobject *)0x0) {
          iVar8 = 0xc34;
          py_line = 6;
          goto LAB_001104b4;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var14 = pPVar28->ob_type->tp_setattro;
      if (p_Var14 == (setattrofunc)0x0) {
        iVar8 = PyObject_SetAttr();
      }
      else {
        iVar8 = (*p_Var14)(pPVar28,__pyx_mstate_global_static.__pyx_n_s_name,(PyObject *)p_Var23);
      }
      if (iVar8 < 0) {
        py_line = 6;
        iVar8 = 0xc37;
        pPVar27 = (PyObject *)0x0;
        goto LAB_001104f0;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
      }
      p_Var23 = __pyx_dict_cached_value_16082;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16081) {
        if (__pyx_dict_cached_value_16082 == (_typeobject *)0x0) {
          p_Var23 = (_typeobject *)__Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_bus);
          goto LAB_00110830;
        }
        (__pyx_dict_cached_value_16082->ob_base).ob_base.ob_refcnt =
             (__pyx_dict_cached_value_16082->ob_base).ob_base.ob_refcnt + 1;
      }
      else {
        p_Var23 = (_typeobject *)
                  __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_bus,
                             (uint64_t *)&__pyx_dict_version_16081,
                             (PyObject **)&__pyx_dict_cached_value_16082);
LAB_00110830:
        if (p_Var23 == (_typeobject *)0x0) {
          py_line = 7;
          iVar8 = 0xc41;
          goto LAB_00110584;
        }
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var12 = ((p_Var23->ob_base).ob_base.ob_type)->tp_getattro;
      if (p_Var12 == (getattrofunc)0x0) {
        pPVar9 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar9 = (*p_Var12)((PyObject *)p_Var23,
                            __pyx_mstate_global_static.__pyx_n_s_MCU_SPI_from_config);
      }
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
      if (pPVar9 == (PyObject *)0x0) {
        pPVar24 = (PyObject *)0x0;
        pPVar9 = (PyObject *)0x0;
        py_line = 7;
        iVar8 = 0xc43;
        pPVar27 = (PyObject *)0x0;
        goto LAB_00110500;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
      }
      p_Var23 = (_typeobject *)PyTuple_New(2);
      pPVar26 = __pyx_mstate_global_static.__pyx_int_0;
      if (p_Var23 == (_typeobject *)0x0) {
        iVar8 = 0xc46;
        py_line = 7;
        lVar22 = pPVar9->ob_refcnt + -1;
        goto LAB_001104b4;
      }
      pPVar27->ob_refcnt = pPVar27->ob_refcnt + 1;
      lVar22 = pPVar26->ob_refcnt;
      p_Var23->tp_name = (char *)pPVar27;
      pPVar26->ob_refcnt = lVar22 + 1;
      p_Var23->tp_basicsize = (Py_ssize_t)pPVar26;
      pPVar26 = (PyObject *)PyDict_New();
      if (pPVar26 == (PyObject *)0x0) {
        lVar22 = pPVar9->ob_refcnt + -1;
        pPVar9->ob_refcnt = lVar22;
        if (lVar22 != 0) {
          pPVar27 = (PyObject *)0x0;
          py_line = 7;
          iVar8 = 0xc4e;
          goto LAB_001104f0;
        }
        iVar8 = 0xc4e;
        py_line = 7;
        goto LAB_001104c4;
      }
      iVar8 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_default_speed,
                             __pyx_mstate_global_static.__pyx_int_5000000);
      if (iVar8 < 0) {
        iVar8 = 0xc50;
LAB_00110794:
        py_line = 7;
        lVar22 = pPVar9->ob_refcnt + -1;
        pPVar9->ob_refcnt = lVar22;
        if (lVar22 == 0) goto LAB_001104c4;
        pPVar27 = (PyObject *)0x0;
LAB_001107ac:
        lVar22 = pPVar26->ob_refcnt + -1;
        pPVar26->ob_refcnt = lVar22;
        if (lVar22 != 0) goto LAB_001104f0;
        goto LAB_001105ac;
      }
      iVar8 = PyDict_SetItem(pPVar26,__pyx_mstate_global_static.__pyx_n_s_share_type,
                             __pyx_mstate_global_static.__pyx_n_s_spi_cs);
      if (iVar8 < 0) {
        iVar8 = 0xc51;
        goto LAB_00110794;
      }
      pPVar27 = __Pyx_PyObject_Call(pPVar9,(PyObject *)p_Var23,pPVar26);
      if (pPVar27 == (PyObject *)0x0) {
        iVar8 = 0xc52;
        goto LAB_00110794;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar26->ob_refcnt + -1;
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var19 = (_typeobject *)pPVar28->ob_type->tp_setattro;
      if (p_Var19 == (_typeobject *)0x0) {
        iVar8 = PyObject_SetAttr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_spi,pPVar27);
      }
      else {
        iVar8 = (*(code *)p_Var19)();
      }
      lVar22 = pPVar27->ob_refcnt + -1;
      if (iVar8 < 0) {
        py_line = 7;
        iVar8 = 0xc57;
        pPVar24 = (PyObject *)0x0;
        goto LAB_001108f8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar27->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar27->ob_type->tp_dealloc)(pPVar27);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var12 = pPVar28->ob_type->tp_getattro;
      if (p_Var12 == (getattrofunc)0x0) {
        pPVar26 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar26 = (*p_Var12)(pPVar28,__pyx_mstate_global_static.__pyx_n_s_spi);
      }
      if (pPVar26 == (PyObject *)0x0) {
        py_line = 8;
        iVar8 = 0xc61;
        goto LAB_00110584;
      }
      p_Var23 = (_typeobject *)
                __Pyx_PyObject_GetAttrStr(pPVar26,__pyx_mstate_global_static.__pyx_n_s_get_mcu);
      if (p_Var23 == (_typeobject *)0x0) {
        py_line = 8;
        iVar8 = 0xc63;
        lVar22 = pPVar26->ob_refcnt + -1;
        goto LAB_00110774;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar26->ob_refcnt + -1;
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      }
      p_Var20 = (p_Var23->ob_base).ob_base.ob_type;
      if ((p_Var20 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (ppPVar25 = (PyObject **)p_Var23->tp_name, ppPVar25 != (PyObject **)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        func = (_typeobject *)(p_Var23->ob_base).ob_size;
        *ppPVar25 = (PyObject *)((long)&(*ppPVar25)->ob_refcnt + 1);
        (func->ob_base).ob_base.ob_refcnt = (func->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*p_Var20->tp_dealloc)((PyObject *)p_Var23);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = ppPVar25;
        pPVar27 = __Pyx_PyObject_FastCallDict
                            ((PyObject *)func,(PyObject **)__pyx_pyargnames,1,(PyObject *)p_Var19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar9 = (PyObject *)((long)&(*ppPVar25)[-1].ob_type + 7);
        *ppPVar25 = pPVar9;
        p_Var23 = func;
        if (pPVar9 == (PyObject *)0x0) {
          (*(code *)ppPVar25[1][3].ob_refcnt)(ppPVar25);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar27 = __Pyx_PyObject_FastCallDict
                            ((PyObject *)p_Var23,(PyObject **)(__pyx_pyargnames + 1),0,
                             (PyObject *)p_Var19);
      }
      if (pPVar27 == (PyObject *)0x0) {
        py_line = 8;
        iVar8 = 0xc78;
        pPVar27 = (PyObject *)0x0;
        goto LAB_001104f0;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_mcu,pPVar27);
      if (iVar8 < 0) {
        py_line = 8;
        iVar8 = 0xc7c;
        pPVar24 = (PyObject *)0x0;
        lVar22 = pPVar27->ob_refcnt + -1;
        goto LAB_001108f8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = pPVar27->ob_refcnt + -1;
      pPVar27->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar27->ob_type->tp_dealloc)(pPVar27);
      }
      p_Var23 = (_typeobject *)
                __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_mcu);
      if (p_Var23 == (_typeobject *)0x0) {
        py_line = 9;
        iVar8 = 0xc86;
        goto LAB_00110584;
      }
      pPVar26 = __Pyx_PyObject_GetAttrStr
                          ((PyObject *)p_Var23,__pyx_mstate_global_static.__pyx_n_s_create_oid);
      lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt;
      if (pPVar26 == (PyObject *)0x0) {
        pPVar24 = (PyObject *)0x0;
        pPVar27 = (PyObject *)0x0;
        py_line = 9;
        lVar22 = lVar22 + -1;
        iVar8 = 0xc88;
        pPVar9 = (PyObject *)0x0;
        goto LAB_00110500;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar22 = lVar22 + -1;
      (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
      }
      p_Var23 = pPVar26->ob_type;
      if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
         (p_Var20 = pPVar26[1].ob_type, p_Var20 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar9 = (PyObject *)pPVar26[1].ob_refcnt;
        (p_Var20->ob_base).ob_base.ob_refcnt = (p_Var20->ob_base).ob_base.ob_refcnt + 1;
        pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar26->ob_refcnt + -1;
        pPVar26->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*p_Var23->tp_dealloc)(pPVar26);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var20;
        pPVar27 = __Pyx_PyObject_FastCallDict
                            (pPVar9,(PyObject **)__pyx_pyargnames,1,(PyObject *)p_Var19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
        (p_Var20->ob_base).ob_base.ob_refcnt = lVar22;
        pPVar26 = pPVar9;
        if (lVar22 == 0) {
          (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar27 = __Pyx_PyObject_FastCallDict
                            (pPVar26,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)p_Var19);
      }
      lVar22 = pPVar26->ob_refcnt + -1;
      if (pPVar27 == (PyObject *)0x0) {
        py_line = 9;
        iVar8 = 0xc9d;
        goto LAB_00110774;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar26->ob_refcnt = lVar22;
      if (lVar22 == 0) {
        (*pPVar26->ob_type->tp_dealloc)(pPVar26);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_oid,pPVar27);
      if (-1 < iVar8) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar27->ob_refcnt + -1;
        pPVar27->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar27->ob_type->tp_dealloc)(pPVar27);
        }
        iVar8 = __Pyx_PyObject_SetAttrStr
                          (pPVar28,__pyx_mstate_global_static.__pyx_n_s_fm17550_read_card,
                           (PyObject *)PTR__Py_NoneStruct_00123f68);
        if (iVar8 < 0) {
          py_line = 0xb;
          iVar8 = 0xcab;
          goto LAB_00110584;
        }
        pPVar27 = __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_mcu);
        if (pPVar27 == (PyObject *)0x0) {
          py_line = 0xc;
          iVar8 = 0xcb4;
          goto LAB_00110584;
        }
        pPVar26 = __Pyx_PyObject_GetAttrStr
                            (pPVar27,__pyx_mstate_global_static.__pyx_n_s_add_config_cmd);
        if (pPVar26 == (PyObject *)0x0) {
          py_line = 0xc;
          iVar8 = 0xcb6;
          lVar22 = pPVar27->ob_refcnt + -1;
          pPVar24 = (PyObject *)0x0;
          goto LAB_001108f8;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar27->ob_refcnt + -1;
        pPVar27->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar27->ob_type->tp_dealloc)(pPVar27);
        }
        pPVar27 = __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_oid);
        if (pPVar27 == (PyObject *)0x0) {
          py_line = 0xc;
          iVar8 = 0xcb9;
          lVar22 = pPVar26->ob_refcnt + -1;
          goto LAB_00110774;
        }
        if ((__pyx_mstate_global_static.__pyx_kp_s_query_fm17550_oid_d_rest_ticks_0 ==
             (PyObject *)PTR__Py_NoneStruct_00123f68) ||
           (p_Var19 = (_typeobject *)pPVar27->ob_type->tp_flags,
           ((ulong)p_Var19 & 0x10000000) != 0 &&
           pPVar27->ob_type != (_typeobject *)PTR_PyUnicode_Type_00123fb8)) {
          p_Var23 = (_typeobject *)
                    PyNumber_Remainder(__pyx_mstate_global_static.
                                       __pyx_kp_s_query_fm17550_oid_d_rest_ticks_0,pPVar27);
        }
        else {
          p_Var23 = (_typeobject *)
                    PyUnicode_Format(__pyx_mstate_global_static.
                                     __pyx_kp_s_query_fm17550_oid_d_rest_ticks_0,pPVar27);
        }
        if (p_Var23 == (_typeobject *)0x0) {
          lVar22 = pPVar26->ob_refcnt;
          iVar8 = 0xcbb;
LAB_00110a4c:
          pPVar26->ob_refcnt = lVar22 + -1;
          py_line = 0xc;
          if (lVar22 + -1 == 0) {
            p_Var23 = (_typeobject *)0x0;
            goto LAB_001105ac;
          }
          goto LAB_001105c4;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar27->ob_refcnt + -1;
        pPVar27->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar27->ob_type->tp_dealloc)(pPVar27);
        }
        pPVar27 = (PyObject *)PyTuple_New(1);
        if (pPVar27 == (PyObject *)0x0) {
          py_line = 0xc;
          iVar8 = 0xcbe;
          goto LAB_001107ac;
        }
        pPVar27[1].ob_type = p_Var23;
        p_Var23 = (_typeobject *)PyDict_New();
        if (p_Var23 == (_typeobject *)0x0) {
          lVar22 = pPVar26->ob_refcnt;
          iVar8 = 0xcc3;
          goto LAB_00110a4c;
        }
        iVar8 = PyDict_SetItem(p_Var23,__pyx_mstate_global_static.__pyx_n_s_on_restart,
                               PTR__Py_TrueStruct_00123f70);
        if (iVar8 < 0) {
          py_line = 0xc;
          iVar8 = 0xcc5;
          goto LAB_001107ac;
        }
        pPVar9 = __Pyx_PyObject_Call(pPVar26,pPVar27,(PyObject *)p_Var23);
        if (pPVar9 == (PyObject *)0x0) {
          py_line = 0xc;
          iVar8 = 0xcc6;
          goto LAB_001107ac;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar26->ob_refcnt + -1;
        pPVar26->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar26->ob_type->tp_dealloc)(pPVar26);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar27->ob_refcnt + -1;
        pPVar27->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar27->ob_type->tp_dealloc)(pPVar27);
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
        p_Var23 = (_typeobject *)
                  __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_mcu);
        if (p_Var23 == (_typeobject *)0x0) {
          py_line = 0xd;
          iVar8 = 0xcd4;
          goto LAB_00110584;
        }
        pPVar27 = __Pyx_PyObject_GetAttrStr
                            ((PyObject *)p_Var23,__pyx_mstate_global_static.__pyx_n_s_add_config_cmd
                            );
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt;
        if (pPVar27 == (PyObject *)0x0) {
          pPVar24 = (PyObject *)0x0;
          pPVar9 = (PyObject *)0x0;
          py_line = 0xd;
          lVar22 = lVar22 + -1;
          iVar8 = 0xcd6;
          goto LAB_00110500;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = lVar22 + -1;
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
        }
        p_Var23 = (_typeobject *)
                  __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_oid);
        if (p_Var23 == (_typeobject *)0x0) {
          pPVar24 = (PyObject *)0x0;
          py_line = 0xd;
          iVar8 = 0xcd9;
          lVar22 = pPVar27->ob_refcnt + -1;
          goto LAB_001108f8;
        }
        pPVar9 = __Pyx_PyObject_GetAttrStr(pPVar28,__pyx_mstate_global_static.__pyx_n_s_spi);
        if (pPVar9 == (PyObject *)0x0) {
          pPVar24 = (PyObject *)0x0;
          py_line = 0xd;
          iVar8 = 0xcdb;
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        }
        else {
          pPVar24 = __Pyx_PyObject_GetAttrStr(pPVar9,__pyx_mstate_global_static.__pyx_n_s_get_oid);
          if (pPVar24 == (PyObject *)0x0) {
            py_line = 0xd;
            iVar8 = 0xcdd;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = pPVar9->ob_refcnt + -1;
            pPVar9->ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*pPVar9->ob_type->tp_dealloc)(pPVar9);
            }
            p_Var20 = pPVar24->ob_type;
            if ((p_Var20 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
               (p_Var19 = pPVar24[1].ob_type, p_Var19 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar9 = (PyObject *)pPVar24[1].ob_refcnt;
              (p_Var19->ob_base).ob_base.ob_refcnt = (p_Var19->ob_base).ob_base.ob_refcnt + 1;
              pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar24->ob_refcnt + -1;
              pPVar24->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*p_Var20->tp_dealloc)(pPVar24);
              }
              __pyx_pyargnames[1] = (PyObject **)0x0;
              __pyx_pyargnames[0] = (PyObject **)p_Var19;
              pPVar26 = __Pyx_PyObject_FastCallDict
                                  (pPVar9,(PyObject **)__pyx_pyargnames,1,(PyObject *)p_Var19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
              (p_Var19->ob_base).ob_base.ob_refcnt = lVar22;
              pPVar24 = pPVar9;
              if (lVar22 == 0) {
                (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = (PyObject **)0x0;
              pPVar26 = __Pyx_PyObject_FastCallDict
                                  (pPVar24,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)p_Var19
                                  );
            }
            if (pPVar26 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar24->ob_refcnt + -1;
              pPVar24->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*pPVar24->ob_type->tp_dealloc)(pPVar24);
              }
              pPVar24 = (PyObject *)PyTuple_New(2);
              if (pPVar24 == (PyObject *)0x0) {
                py_line = 0xd;
                iVar8 = 0xcf6;
                goto LAB_001107ac;
              }
              pPVar24[1].ob_type = p_Var23;
              pPVar24[2].ob_refcnt = (Py_ssize_t)pPVar26;
              ppPVar25 = (PyObject **)
                         PyUnicode_Format(__pyx_mstate_global_static.
                                          __pyx_kp_s_config_fm17550_oid_d_spi_oid_d,pPVar24);
              if (ppPVar25 == (PyObject **)0x0) {
                py_line = 0xd;
                iVar8 = 0xcfe;
                lVar22 = pPVar27->ob_refcnt + -1;
                goto LAB_001108f8;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar22 = pPVar24->ob_refcnt + -1;
              pPVar24->ob_refcnt = lVar22;
              if (lVar22 == 0) {
                (*pPVar24->ob_type->tp_dealloc)(pPVar24);
              }
              p_Var23 = pPVar27->ob_type;
              if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                 (p_Var20 = pPVar27[1].ob_type, p_Var20 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar26 = (PyObject *)pPVar27[1].ob_refcnt;
                (p_Var20->ob_base).ob_base.ob_refcnt = (p_Var20->ob_base).ob_base.ob_refcnt + 1;
                pPVar26->ob_refcnt = pPVar26->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = pPVar27->ob_refcnt + -1;
                pPVar27->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*p_Var23->tp_dealloc)(pPVar27);
                }
                __pyx_pyargnames[0] = (PyObject **)p_Var20;
                __pyx_pyargnames[1] = ppPVar25;
                pPVar9 = __Pyx_PyObject_FastCallDict
                                   (pPVar26,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
                (p_Var20->ob_base).ob_base.ob_refcnt = lVar22;
                pPVar27 = pPVar26;
                if (lVar22 == 0) {
                  (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
                }
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = ppPVar25;
                pPVar9 = __Pyx_PyObject_FastCallDict
                                   (pPVar27,(PyObject **)(__pyx_pyargnames + 1),1,
                                    (PyObject *)p_Var19);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              pPVar26 = (PyObject *)((long)&(*ppPVar25)[-1].ob_type + 7);
              *ppPVar25 = pPVar26;
              if (pPVar26 == (PyObject *)0x0) {
                (*(code *)ppPVar25[1][3].ob_refcnt)(ppPVar25);
              }
              if (pPVar9 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = pPVar27->ob_refcnt + -1;
                pPVar27->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*pPVar27->ob_type->tp_dealloc)(pPVar27);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = pPVar9->ob_refcnt + -1;
                pPVar9->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                }
                pPVar27 = __Pyx_PyObject_GetAttrStr
                                    (pPVar28,__pyx_mstate_global_static.__pyx_n_s_mcu);
                if (pPVar27 == (PyObject *)0x0) {
                  py_line = 0xe;
                  iVar8 = 0xd21;
                  goto LAB_00110584;
                }
                pPVar26 = __Pyx_PyObject_GetAttrStr
                                    (pPVar27,__pyx_mstate_global_static.
                                             __pyx_n_s_register_config_callback);
                if (pPVar26 == (PyObject *)0x0) {
                  pPVar24 = (PyObject *)0x0;
                  py_line = 0xe;
                  iVar8 = 0xd23;
                  lVar22 = pPVar27->ob_refcnt + -1;
                  goto LAB_001108f8;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = pPVar27->ob_refcnt + -1;
                pPVar27->ob_refcnt = lVar22;
                if (lVar22 == 0) {
                  (*pPVar27->ob_type->tp_dealloc)(pPVar27);
                }
                pPVar9 = __Pyx_PyObject_GetAttrStr
                                   (pPVar28,__pyx_mstate_global_static.__pyx_n_s_build_config);
                if (pPVar9 == (PyObject *)0x0) {
                  py_line = 0xe;
                  iVar8 = 0xd26;
                  lVar22 = pPVar26->ob_refcnt + -1;
LAB_00110774:
                  pPVar26->ob_refcnt = lVar22;
                  if (lVar22 == 0) {
                    pPVar27 = (PyObject *)0x0;
                    p_Var23 = (_typeobject *)0x0;
                    goto LAB_001105ac;
                  }
                }
                else {
                  p_Var23 = pPVar26->ob_type;
                  if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                     (p_Var20 = pPVar26[1].ob_type, p_Var20 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar24 = (PyObject *)pPVar26[1].ob_refcnt;
                    (p_Var20->ob_base).ob_base.ob_refcnt = (p_Var20->ob_base).ob_base.ob_refcnt + 1;
                    pPVar24->ob_refcnt = pPVar24->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar22 = pPVar26->ob_refcnt + -1;
                    pPVar26->ob_refcnt = lVar22;
                    if (lVar22 == 0) {
                      (*p_Var23->tp_dealloc)(pPVar26);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var20;
                    __pyx_pyargnames[1] = (PyObject **)pPVar9;
                    pPVar27 = __Pyx_PyObject_FastCallDict
                                        (pPVar24,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var19
                                        );
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar22 = (p_Var20->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var20->ob_base).ob_base.ob_refcnt = lVar22;
                    pPVar26 = pPVar24;
                    if (lVar22 == 0) {
                      (*((p_Var20->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var20);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = (PyObject **)pPVar9;
                    pPVar27 = __Pyx_PyObject_FastCallDict
                                        (pPVar26,(PyObject **)(__pyx_pyargnames + 1),1,
                                         (PyObject *)p_Var19);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar22 = pPVar9->ob_refcnt + -1;
                  pPVar9->ob_refcnt = lVar22;
                  if (lVar22 == 0) {
                    (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                  }
                  if (pPVar27 == (PyObject *)0x0) {
                    py_line = 0xe;
                    iVar8 = 0xd3b;
                    p_Var23 = (_typeobject *)0x0;
                    goto LAB_001104d8;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar22 = pPVar26->ob_refcnt + -1;
                  pPVar26->ob_refcnt = lVar22;
                  if (lVar22 == 0) {
                    (*pPVar26->ob_type->tp_dealloc)(pPVar26);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar22 = pPVar27->ob_refcnt + -1;
                  pPVar27->ob_refcnt = lVar22;
                  if (lVar22 == 0) {
                    (*pPVar27->ob_type->tp_dealloc)(pPVar27);
                  }
                  pPVar26 = __Pyx_PyObject_GetAttrStr
                                      (pPVar28,__pyx_mstate_global_static.__pyx_n_s_printer);
                  if (pPVar26 == (PyObject *)0x0) {
                    py_line = 0x10;
                    iVar8 = 0xd48;
                  }
                  else {
                    pPVar27 = __Pyx_PyObject_GetAttrStr
                                        (pPVar26,__pyx_mstate_global_static.__pyx_n_s_lookup_object)
                    ;
                    if (pPVar27 == (PyObject *)0x0) {
                      py_line = 0x10;
                      iVar8 = 0xd4a;
                      lVar22 = pPVar26->ob_refcnt + -1;
                      goto LAB_00110774;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar22 = pPVar26->ob_refcnt + -1;
                    pPVar26->ob_refcnt = lVar22;
                    if (lVar22 == 0) {
                      (*pPVar26->ob_type->tp_dealloc)(pPVar26);
                    }
                    p_Var23 = pPVar27->ob_type;
                    if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_00123ef0) &&
                       (p_Var19 = pPVar27[1].ob_type, p_Var19 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar26 = (PyObject *)pPVar27[1].ob_refcnt;
                      (p_Var19->ob_base).ob_base.ob_refcnt =
                           (p_Var19->ob_base).ob_base.ob_refcnt + 1;
                      pPVar26->ob_refcnt = pPVar26->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar22 = pPVar27->ob_refcnt + -1;
                      pPVar27->ob_refcnt = lVar22;
                      if (lVar22 == 0) {
                        (*p_Var23->tp_dealloc)(pPVar27);
                      }
                      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_gcode;
                      __pyx_pyargnames[0] = (PyObject **)p_Var19;
                      pPVar9 = __Pyx_PyObject_FastCallDict
                                         (pPVar26,(PyObject **)__pyx_pyargnames,2,
                                          __pyx_mstate_global_static.__pyx_n_s_gcode);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar22 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var19->ob_base).ob_base.ob_refcnt = lVar22;
                      pPVar27 = pPVar26;
                      if (lVar22 == 0) {
                        (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_gcode;
                      pPVar9 = __Pyx_PyObject_FastCallDict
                                         (pPVar27,(PyObject **)(__pyx_pyargnames + 1),1,
                                          __pyx_mstate_global_static.__pyx_n_s_gcode);
                    }
                    if (pPVar9 == (PyObject *)0x0) {
                      py_line = 0x10;
                      iVar8 = 0xd5f;
                      goto LAB_001105c4;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar22 = pPVar27->ob_refcnt + -1;
                    pPVar27->ob_refcnt = lVar22;
                    if (lVar22 == 0) {
                      (*pPVar27->ob_type->tp_dealloc)(pPVar27);
                    }
                    iVar8 = __Pyx_PyObject_SetAttrStr
                                      (pPVar28,__pyx_mstate_global_static.__pyx_n_s_gcode,pPVar9);
                    if (iVar8 < 0) {
                      iVar8 = 0xd63;
                      py_line = 0x10;
                      lVar22 = pPVar9->ob_refcnt + -1;
                      goto LAB_001104b4;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar22 = pPVar9->ob_refcnt + -1;
                    pPVar9->ob_refcnt = lVar22;
                    if (lVar22 == 0) {
                      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                    }
                    pPVar9 = (PyObject *)PTR__Py_NoneStruct_00123f68;
                    iVar8 = __Pyx_PyObject_SetAttrStr
                                      (pPVar28,__pyx_mstate_global_static.__pyx_n_s_read_rfid_timer,
                                       (PyObject *)PTR__Py_NoneStruct_00123f68);
                    if (iVar8 < 0) {
                      py_line = 0x12;
                      iVar8 = 0xd6d;
                    }
                    else {
                      iVar8 = __Pyx_PyObject_SetAttrStr
                                        (pPVar28,__pyx_mstate_global_static.
                                                 __pyx_n_s_rfid_read_attempts,
                                         __pyx_mstate_global_static.__pyx_int_0);
                      if (iVar8 < 0) {
                        py_line = 0x13;
                        iVar8 = 0xd76;
                      }
                      else {
                        iVar8 = __Pyx_PyObject_SetAttrStr
                                          (pPVar28,__pyx_mstate_global_static.
                                                   __pyx_n_s_rfid_read_start_time,
                                           __pyx_mstate_global_static.__pyx_int_0);
                        if (iVar8 < 0) {
                          py_line = 0x14;
                          iVar8 = 0xd7f;
                        }
                        else {
                          iVar8 = __Pyx_PyObject_SetAttrStr
                                            (pPVar28,__pyx_mstate_global_static.
                                                     __pyx_n_s_max_read_time,
                                             __pyx_mstate_global_static.__pyx_float_30_0);
                          if (iVar8 < 0) {
                            py_line = 0x15;
                            iVar8 = 0xd88;
                          }
                          else {
                            iVar8 = __Pyx_PyObject_SetAttrStr
                                              (pPVar28,__pyx_mstate_global_static.
                                                       __pyx_n_s_get_message_count,
                                               __pyx_mstate_global_static.__pyx_int_1);
                            if (iVar8 < 0) {
                              py_line = 0x16;
                              iVar8 = 0xd91;
                            }
                            else {
                              iVar8 = __Pyx_PyObject_SetAttrStr
                                                (pPVar28,__pyx_mstate_global_static.
                                                         __pyx_n_s_temp_message_1,pPVar9);
                              if (iVar8 < 0) {
                                py_line = 0x17;
                                iVar8 = 0xd9a;
                              }
                              else {
                                iVar8 = __Pyx_PyObject_SetAttrStr
                                                  (pPVar28,__pyx_mstate_global_static.
                                                           __pyx_n_s_temp_message_2,pPVar9);
                                if (iVar8 < 0) {
                                  py_line = 0x18;
                                  iVar8 = 0xda3;
                                }
                                else {
                                  iVar8 = __Pyx_PyObject_SetAttrStr
                                                    (pPVar28,__pyx_mstate_global_static.
                                                             __pyx_n_s_stepper,pPVar9);
                                  if (iVar8 < 0) {
                                    py_line = 0x19;
                                    iVar8 = 0xdac;
                                  }
                                  else {
                                    iVar8 = __Pyx_PyObject_SetAttrStr
                                                      (pPVar28,__pyx_mstate_global_static.
                                                               __pyx_n_s_had_get_value,
                                                       (PyObject *)PTR__Py_FalseStruct_00123f38);
                                    if (-1 < iVar8) {
                                      pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                                      goto LAB_0010f1d0;
                                    }
                                    py_line = 0x1a;
                                    iVar8 = 0xdb5;
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
                goto LAB_00110584;
              }
              py_line = 0xd;
              iVar8 = 0xd14;
              goto LAB_001105c4;
            }
            py_line = 0xd;
            pPVar9 = (PyObject *)0x0;
            iVar8 = 0xcf2;
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          }
        }
        goto LAB_00110500;
      }
      py_line = 9;
      iVar8 = 0xca1;
      pPVar24 = (PyObject *)0x0;
      lVar22 = pPVar27->ob_refcnt + -1;
LAB_001108f8:
      pPVar27->ob_refcnt = lVar22;
      pPVar9 = (PyObject *)0x0;
      if (lVar22 == 0) goto LAB_0011052c;
LAB_00110560:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar24 != (PyObject *)0x0) &&
         (lVar22 = pPVar24->ob_refcnt + -1, pPVar24->ob_refcnt = lVar22, lVar22 == 0)) {
        (*pPVar24->ob_type->tp_dealloc)(pPVar24);
      }
    }
LAB_00110584:
    __Pyx_AddTraceback("extras.box_rfid.BoxRFID.__init__",iVar8,py_line,"box_rfid.py");
    pPVar9 = (PyObject *)0x0;
    goto LAB_0010f1d0;
  }
LAB_001103e4:
  lVar22 = PyErr_Occurred();
  if (lVar22 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_00123f20,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 2,"s",1);
    iVar8 = 0xb9e;
  }
  else {
    iVar8 = 0xb9c;
  }
LAB_0010f1b4:
  __Pyx_AddTraceback("extras.box_rfid.BoxRFID.__init__",iVar8,4,"box_rfid.py");
  pPVar9 = (PyObject *)0x0;
LAB_0010f1d0:
  if (lVar17 == *(long *)PTR___stack_chk_guard_00123f48) {
    return pPVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Successfully decompiled 13 of 13 selected functions. */
