/*
 * Reverse-engineered Ghidra output. This is not original source code.
 * Program: aht20_f.so
 * Language: AARCH64:LE:64:v8A
 * Selected named functions: 22
 */


/* ================================================================
 * Address: 00105b24
 * Symbol:  __pyx_pymod_exec_aht20_f
 * Signature: int __pyx_pymod_exec_aht20_f(PyObject * __pyx_pyinit_module)
 * ================================================================ */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pyx_pymod_exec_aht20_f(PyObject *__pyx_pyinit_module)

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
  PyObject *pPVar11;
  PyObject *pPVar12;
  PyObject *pPVar13;
  PyObject *pPVar14;
  long *plVar15;
  long *plVar16;
  ulong uVar17;
  long lVar18;
  ulong uVar19;
  _typeobject *p_Var20;
  int iVar21;
  char *code;
  ulong uVar22;
  char *__s;
  PyObject *margs [4];
  char message [200];
  
                    /* Unresolved local var: int stringtab_initialized@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  lVar18 = *(long *)PTR___stack_chk_guard_0012ff30;
  if (__pyx_m != (PyObject *)0x0) {
    iVar4 = 0;
    if (__pyx_m != __pyx_pyinit_module) {
      PyErr_SetString(*(undefined8 *)PTR_PyExc_RuntimeError_0012fee0,
                      "Module \'aht20_f\' has already been imported. Re-initialisation is not supported."
                      ,0);
      iVar4 = -1;
    }
    goto LAB_001075a4;
  }
  __pyx_m = __pyx_pyinit_module;
  __pyx_pyinit_module->ob_refcnt = __pyx_pyinit_module->ob_refcnt + 1;
  __pyx_mstate_global_static.__pyx_d = (PyObject *)PyModule_GetDict();
  if (__pyx_mstate_global_static.__pyx_d == (PyObject *)0x0) {
    iVar21 = 0x26d9;
    iVar4 = 1;
    bVar3 = false;
LAB_0010654c:
    if (__pyx_m == (PyObject *)0x0) {
      lVar6 = PyErr_Occurred();
      if (lVar6 == 0) {
        PyErr_SetString(*(undefined8 *)PTR_PyExc_ImportError_0012ff90,"init extras.aht20_f");
      }
    }
    else {
      if ((__pyx_mstate_global_static.__pyx_d != (PyObject *)0x0) && (bVar3)) {
        __Pyx_AddTraceback("init extras.aht20_f",iVar21,iVar4,"aht20_f.py");
      }
                    /* Unresolved local var: PyObject * _py_tmp@[???] */
      pPVar14 = __pyx_m;
      if (__pyx_m != (PyObject *)0x0) {
        pPVar2 = &__pyx_m->ob_refcnt;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        __pyx_m = (PyObject *)0x0;
        lVar6 = *pPVar2 + -1;
        pPVar14->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar14->ob_type->tp_dealloc)(pPVar14);
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
      iVar21 = 0x26db;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
    (__pyx_mstate_global_static.__pyx_b)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_b)->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * module@[???] */
    __pyx_mstate_global_static.__pyx_cython_runtime =
         (PyObject *)PyImport_AddModule("cython_runtime");
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (__pyx_mstate_global_static.__pyx_cython_runtime == (PyObject *)0x0) {
      iVar21 = 0x26dc;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
    (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_cython_runtime)->ob_refcnt + 1;
    iVar4 = PyObject_SetAttrString(__pyx_m,"__builtins__",__pyx_mstate_global_static.__pyx_b);
    if (iVar4 < 0) {
      iVar21 = 0x26dd;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
                    /* Unresolved local var: char * rt_version@[???]
                       Unresolved local var: ulong version@[???]
                       Unresolved local var: ulong factor@[???]
                       Unresolved local var: wchar_t digit@[???]
                       Unresolved local var: int i@[???] */
    lVar6 = Py_GetVersion();
    iVar21 = 4;
    iVar4 = 0;
    uVar22 = 0;
    uVar19 = 0x1000000;
    do {
      uVar17 = 0;
      while( true ) {
        bVar1 = *(byte *)(lVar6 + iVar4);
        code = (char *)(ulong)(uint)(byte)(bVar1 - 0x30);
        if (9 < (byte)(bVar1 - 0x30)) break;
        iVar4 = iVar4 + 1;
        uVar17 = (ulong)(((uint)bVar1 + (int)uVar17 * 10) - 0x30);
      }
      uVar22 = uVar22 + uVar17 * uVar19;
      if (bVar1 != 0x2e) break;
      uVar19 = uVar19 >> 8;
      iVar4 = iVar4 + 1;
      iVar21 = iVar21 + -1;
    } while (iVar21 != 0);
                    /* Unresolved local var: ulong MAJOR_MINOR@[???] */
    if (((uVar22 ^ 0x3070000) & 0xffff0000) != 0) {
      code = "does not match";
      PyOS_snprintf(message,200,
                    "compile time Python version %d.%d of module \'%.100s\' %s runtime version %d.%d"
                    ,3,7,"extras.aht20_f","does not match",uVar22 >> 0x18 & 0xffffffff,
                    (uint)uVar22 >> 0x10 & 0xff);
      iVar4 = PyErr_WarnEx(0,message,1);
      if (iVar4 < 0) {
        iVar21 = 0x26e8;
        iVar4 = 1;
        bVar3 = false;
        goto LAB_0010654c;
      }
    }
    __pyx_pyframe_localsplus_offset = *(long *)(PTR_PyFrame_Type_0012ff88 + 0x20) - 8;
    __pyx_mstate_global_static.__pyx_empty_tuple = (PyObject *)PyTuple_New(0);
    if (__pyx_mstate_global_static.__pyx_empty_tuple == (PyObject *)0x0) {
      iVar21 = 0x26ec;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
    __pyx_mstate_global_static.__pyx_empty_bytes = (PyObject *)PyBytes_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_bytes == (PyObject *)0x0) {
      iVar21 = 0x26ed;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
    __pyx_mstate_global_static.__pyx_empty_unicode = (PyObject *)PyUnicode_FromStringAndSize("",0);
    if (__pyx_mstate_global_static.__pyx_empty_unicode == (PyObject *)0x0) {
      iVar21 = 0x26ee;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
                    /* Unresolved local var: PyObject * abi_module@[???]
                       Unresolved local var: char * object_name@[???]
                       Unresolved local var: PyTypeObject * cached_type@[???]
                       Unresolved local var: PyObject * module@[???] */
    plVar7 = (long *)PyImport_AddModule("_cython_3_0_12");
    __s = __pyx_CyFunctionType_type.tp_name;
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
    if (plVar7 == (long *)0x0) {
      iVar21 = 0x26f0;
      iVar4 = 1;
      bVar3 = false;
      __pyx_mstate_global_static.__pyx_CyFunctionType = (PyTypeObject *)0x0;
      goto LAB_0010654c;
    }
    *plVar7 = *plVar7 + 1;
    pcVar8 = strrchr(__s,0x2e);
    if (pcVar8 != (char *)0x0) {
      __s = pcVar8 + 1;
    }
    pPVar9 = (PyTypeObject *)PyObject_GetAttrString(plVar7,__s);
    if (pPVar9 == (PyTypeObject *)0x0) {
      iVar4 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_AttributeError_0012ff98);
      if (iVar4 != 0) {
        PyErr_Clear();
        pPVar9 = &__pyx_CyFunctionType_type;
        iVar4 = PyType_Ready(&__pyx_CyFunctionType_type);
        if ((-1 < iVar4) &&
           (iVar4 = PyObject_SetAttrString(plVar7,__s,&__pyx_CyFunctionType_type), -1 < iVar4)) {
          __pyx_CyFunctionType_type.ob_base.ob_base.ob_refcnt =
               __pyx_CyFunctionType_type.ob_base.ob_base.ob_refcnt + 1;
          goto LAB_00105e68;
        }
      }
LAB_00105e2c:
      pPVar9 = (PyTypeObject *)0x0;
    }
    else if ((int)((pPVar9->ob_base).ob_base.ob_type)->tp_flags < 0) {
      if (pPVar9->tp_basicsize != __pyx_CyFunctionType_type.tp_basicsize) {
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                     "Shared Cython type %.200s has the wrong size, try recompiling",__s);
        goto LAB_00107368;
      }
    }
    else {
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "Shared Cython type %.200s is not a type object",__s);
LAB_00107368:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = (pPVar9->ob_base).ob_base.ob_refcnt + -1;
      (pPVar9->ob_base).ob_base.ob_refcnt = lVar6;
      if (lVar6 != 0) goto LAB_00105e2c;
      (*((pPVar9->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)pPVar9);
      pPVar9 = (PyTypeObject *)0x0;
    }
LAB_00105e68:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = *plVar7;
    *plVar7 = lVar6 + -1;
    if (lVar6 + -1 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    __pyx_mstate_global_static.__pyx_CyFunctionType = pPVar9;
    if (pPVar9 == (PyTypeObject *)0x0) {
      iVar21 = 0x26f0;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
    iVar4 = __Pyx_CreateStringTabAndInitStrings();
    if (((((((iVar4 < 0) ||
            (__pyx_mstate_global_static.__pyx_float_0_ = (PyObject *)PyFloat_FromDouble(0),
            __pyx_mstate_global_static.__pyx_float_0_ == (PyObject *)0x0)) ||
           (__pyx_mstate_global_static.__pyx_float__10 =
                 (PyObject *)PyFloat_FromDouble(_DAT_0011c830),
           __pyx_mstate_global_static.__pyx_float__10 == (PyObject *)0x0)) ||
          ((__pyx_mstate_global_static.__pyx_float_0_0 = (PyObject *)PyFloat_FromDouble(0),
           __pyx_mstate_global_static.__pyx_float_0_0 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_float_0_1 =
                 (PyObject *)PyFloat_FromDouble(_DAT_0011c830),
           __pyx_mstate_global_static.__pyx_float_0_1 == (PyObject *)0x0)))) ||
         ((__pyx_mstate_global_static.__pyx_float__600 =
                (PyObject *)PyFloat_FromDouble(0x3fe3333333333333),
          __pyx_mstate_global_static.__pyx_float__600 == (PyObject *)0x0 ||
          ((__pyx_mstate_global_static.__pyx_int_0 = (PyObject *)PyLong_FromLong(0),
           __pyx_mstate_global_static.__pyx_int_0 == (PyObject *)0x0 ||
           (__pyx_mstate_global_static.__pyx_int_1 = (PyObject *)PyLong_FromLong(1),
           __pyx_mstate_global_static.__pyx_int_1 == (PyObject *)0x0)))))) ||
        (((__pyx_mstate_global_static.__pyx_int_2 = (PyObject *)PyLong_FromLong(2),
          __pyx_mstate_global_static.__pyx_int_2 == (PyObject *)0x0 ||
          ((((__pyx_mstate_global_static.__pyx_int_3 = (PyObject *)PyLong_FromLong(3),
             __pyx_mstate_global_static.__pyx_int_3 == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_int_4 = (PyObject *)PyLong_FromLong(4),
             __pyx_mstate_global_static.__pyx_int_4 == (PyObject *)0x0)) ||
            (__pyx_mstate_global_static.__pyx_int_6 = (PyObject *)PyLong_FromLong(6),
            __pyx_mstate_global_static.__pyx_int_6 == (PyObject *)0x0)) ||
           (((__pyx_mstate_global_static.__pyx_int_7 = (PyObject *)PyLong_FromLong(7),
             __pyx_mstate_global_static.__pyx_int_7 == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_int_8 = (PyObject *)PyLong_FromLong(8),
             __pyx_mstate_global_static.__pyx_int_8 == (PyObject *)0x0)) ||
            ((__pyx_mstate_global_static.__pyx_int_27 = (PyObject *)PyLong_FromLong(0x1b),
             __pyx_mstate_global_static.__pyx_int_27 == (PyObject *)0x0 ||
             ((__pyx_mstate_global_static.__pyx_int_28 = (PyObject *)PyLong_FromLong(0x1c),
              __pyx_mstate_global_static.__pyx_int_28 == (PyObject *)0x0 ||
              (__pyx_mstate_global_static.__pyx_int_49 = (PyObject *)PyLong_FromLong(0x31),
              __pyx_mstate_global_static.__pyx_int_49 == (PyObject *)0x0)))))))))) ||
         (__pyx_mstate_global_static.__pyx_int_50 = (PyObject *)PyLong_FromLong(0x32),
         __pyx_mstate_global_static.__pyx_int_50 == (PyObject *)0x0)))) ||
       ((((__pyx_mstate_global_static.__pyx_int_51 = (PyObject *)PyLong_FromLong(0x33),
          __pyx_mstate_global_static.__pyx_int_51 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_int_56 = (PyObject *)PyLong_FromLong(0x38),
          __pyx_mstate_global_static.__pyx_int_56 == (PyObject *)0x0)) ||
         (__pyx_mstate_global_static.__pyx_int_100 = (PyObject *)PyLong_FromLong(100),
         __pyx_mstate_global_static.__pyx_int_100 == (PyObject *)0x0)) ||
        (((__pyx_mstate_global_static.__pyx_int_128 = (PyObject *)PyLong_FromLong(0x80),
          __pyx_mstate_global_static.__pyx_int_128 == (PyObject *)0x0 ||
          (__pyx_mstate_global_static.__pyx_int_172 = (PyObject *)PyLong_FromLong(0xac),
          __pyx_mstate_global_static.__pyx_int_172 == (PyObject *)0x0)) ||
         ((((__pyx_mstate_global_static.__pyx_int_186 = (PyObject *)PyLong_FromLong(0xba),
            __pyx_mstate_global_static.__pyx_int_186 == (PyObject *)0x0 ||
            ((__pyx_mstate_global_static.__pyx_int_187 = (PyObject *)PyLong_FromLong(0xbb),
             __pyx_mstate_global_static.__pyx_int_187 == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_int_188 = (PyObject *)PyLong_FromLong(0xbc),
             __pyx_mstate_global_static.__pyx_int_188 == (PyObject *)0x0)))) ||
           (__pyx_mstate_global_static.__pyx_int_190 = (PyObject *)PyLong_FromLong(0xbe),
           __pyx_mstate_global_static.__pyx_int_190 == (PyObject *)0x0)) ||
          ((((__pyx_mstate_global_static.__pyx_int_200 = (PyObject *)PyLong_FromLong(200),
             __pyx_mstate_global_static.__pyx_int_200 == (PyObject *)0x0 ||
             (__pyx_mstate_global_static.__pyx_int_255 = (PyObject *)PyLong_FromLong(0xff),
             __pyx_mstate_global_static.__pyx_int_255 == (PyObject *)0x0)) ||
            (__pyx_mstate_global_static.__pyx_int_100000 = (PyObject *)PyLong_FromLong(100000),
            __pyx_mstate_global_static.__pyx_int_100000 == (PyObject *)0x0)) ||
           (__pyx_mstate_global_static.__pyx_int_1048576 = (PyObject *)PyLong_FromLong(0x100000),
           __pyx_mstate_global_static.__pyx_int_1048576 == (PyObject *)0x0)))))))))) {
      iVar21 = 0x2707;
      iVar4 = 1;
      bVar3 = false;
      goto LAB_0010654c;
    }
    if ((*(int *)PTR___pyx_module_is_main_extras__aht20_f_0012fee8 != 0) &&
       (iVar4 = PyObject_SetAttr(__pyx_m,__pyx_mstate_global_static.__pyx_n_s_name_2,
                                 __pyx_mstate_global_static.__pyx_n_s_main), iVar4 < 0)) {
      iVar4 = 1;
      iVar21 = 0x270e;
      bVar3 = true;
      goto LAB_0010654c;
    }
                    /* Unresolved local var: PyObject * modules@[???] */
    lVar6 = PyImport_GetModuleDict();
    if (lVar6 == 0) {
      iVar4 = 1;
      iVar21 = 0x2712;
      bVar3 = true;
      goto LAB_0010654c;
    }
    lVar10 = PyDict_GetItemString(lVar6,"extras.aht20_f");
    if ((lVar10 == 0) && (iVar4 = PyDict_SetItemString(lVar6,"extras.aht20_f",__pyx_m), iVar4 < 0))
    {
      iVar4 = 1;
      iVar21 = 0x2714;
      bVar3 = true;
      goto LAB_0010654c;
    }
    __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_range);
    if ((__pyx_builtin_range == (PyObject *)0x0) ||
       (__pyx_builtin_round = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_round),
       __pyx_builtin_round == (PyObject *)0x0)) {
      iVar4 = 1;
      iVar21 = 0x2719;
      bVar3 = true;
      goto LAB_0010654c;
    }
    iVar4 = __Pyx_InitCachedConstants();
    pPVar14 = __pyx_mstate_global_static.__pyx_n_s_logging;
    if (iVar4 < 0) {
      iVar4 = 1;
      iVar21 = 0x271b;
      bVar3 = true;
      goto LAB_0010654c;
    }
                    /* Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * imported_module@[???] */
    pPVar11 = (PyObject *)PyImport_GetModule(__pyx_mstate_global_static.__pyx_n_s_logging);
    if (pPVar11 == (PyObject *)0x0) {
      lVar6 = PyErr_Occurred();
      if (lVar6 != 0) {
        PyErr_Clear();
      }
LAB_001062b8:
                    /* Unresolved local var: PyObject * imported_module@[???]
                       Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * empty_dict@[???]
                       Unresolved local var: PyObject * empty_list@[???] */
      plVar7 = (long *)PyDict_New();
      if (plVar7 != (long *)0x0) {
        pPVar11 = (PyObject *)
                  PyImport_ImportModuleLevelObject
                            (pPVar14,__pyx_mstate_global_static.__pyx_d,plVar7,0,0);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = *plVar7;
        *plVar7 = lVar6 + -1;
        if (lVar6 + -1 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (pPVar11 != (PyObject *)0x0) goto LAB_00106318;
      }
      iVar21 = 0x2730;
      iVar4 = 6;
      bVar3 = true;
      goto LAB_0010654c;
    }
                    /* Unresolved local var: PyObject * spec@[???] */
    pPVar12 = __Pyx_PyObject_GetAttrStrNoError(pPVar11,__pyx_mstate_global_static.__pyx_n_s_spec);
    if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * unsafe@[???] */
      pPVar13 = __Pyx_PyObject_GetAttrStrNoError
                          (pPVar12,__pyx_mstate_global_static.__pyx_n_s_initializing);
      if (pPVar13 == (PyObject *)0x0) {
LAB_001061d4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        if (pPVar13 == (PyObject *)0x0) goto LAB_001061bc;
        pPVar12 = (PyObject *)0x0;
      }
      else {
                    /* Unresolved local var: int is_true@[???] */
        uVar5 = (uint)(pPVar13 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
        if ((uVar5 == 0 && pPVar13 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
            pPVar13 != (PyObject *)PTR__Py_NoneStruct_0012ff50) {
          uVar5 = PyObject_IsTrue();
        }
        if (uVar5 == 0) goto LAB_001061d4;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = pPVar13->ob_refcnt + -1;
      pPVar13->ob_refcnt = lVar6;
      if (lVar6 == 0) {
        (*pPVar13->ob_type->tp_dealloc)(pPVar13);
      }
      if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        goto LAB_001062b8;
      }
    }
LAB_001061bc:
    PyErr_Clear();
LAB_00106318:
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_logging,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x2732;
      iVar4 = 6;
      pPVar14 = (PyObject *)0x0;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(1);
    pPVar14 = __pyx_mstate_global_static.__pyx_n_s_bus;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x273c;
      iVar4 = 7;
      bVar3 = true;
      goto LAB_0010654c;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_n_s_bus)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_n_s_bus)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar14;
    pPVar14 = __pyx_mstate_global_static.__pyx_n_s__4;
                    /* Unresolved local var: PyObject * module@[???]
                       Unresolved local var: PyObject * empty_dict@[???]
                       Unresolved local var: PyObject * empty_list@[???] */
    plVar7 = (long *)PyDict_New();
    if (plVar7 == (long *)0x0) {
      pPVar14 = (PyObject *)0x0;
      iVar21 = 0x2741;
      iVar4 = 7;
LAB_001064fc:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar6;
      if (lVar6 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (pPVar14 != (PyObject *)0x0) {
LAB_00106520:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar6 = pPVar14->ob_refcnt + -1;
        pPVar14->ob_refcnt = lVar6;
        if (lVar6 == 0) {
          (*pPVar14->ob_type->tp_dealloc)(pPVar14);
          bVar3 = true;
          goto LAB_0010654c;
        }
      }
      bVar3 = true;
      goto LAB_0010654c;
    }
    pPVar14 = (PyObject *)
              PyImport_ImportModuleLevelObject
                        (pPVar14,__pyx_mstate_global_static.__pyx_d,plVar7,pPVar11,1);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = *plVar7;
    *plVar7 = lVar6 + -1;
    if (lVar6 + -1 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (pPVar14 == (PyObject *)0x0) {
      iVar21 = 0x2741;
      iVar4 = 7;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar12 = __pyx_mstate_global_static.__pyx_n_s_bus;
                    /* Unresolved local var: PyObject * value@[???] */
    pPVar11 = __Pyx_PyObject_GetAttrStr(pPVar14,__pyx_mstate_global_static.__pyx_n_s_bus);
    if (pPVar11 == (PyObject *)0x0) {
      iVar4 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_AttributeError_0012ff98);
      if (iVar4 != 0) {
                    /* Unresolved local var: char * module_name_str@[???]
                       Unresolved local var: PyObject * module_name@[???]
                       Unresolved local var: PyObject * module_dot@[???]
                       Unresolved local var: PyObject * full_name@[???] */
        PyErr_Clear();
        lVar6 = PyModule_GetName(pPVar14);
        if ((lVar6 != 0) && (plVar7 = (long *)PyUnicode_FromString(), plVar7 != (long *)0x0)) {
          plVar15 = (long *)PyUnicode_Concat(plVar7,__pyx_mstate_global_static.__pyx_kp_u__5);
          if (plVar15 != (long *)0x0) {
            plVar16 = (long *)PyUnicode_Concat(plVar15,pPVar12);
            if (plVar16 != (long *)0x0) {
              pPVar11 = (PyObject *)PyImport_GetModule();
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar6 = *plVar16;
              *plVar16 = lVar6 + -1;
              if (lVar6 + -1 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
            }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar6 = *plVar15;
            *plVar15 = lVar6 + -1;
            if (lVar6 + -1 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar6 = *plVar7;
          *plVar7 = lVar6 + -1;
          if (lVar6 + -1 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (pPVar11 != (PyObject *)0x0) goto LAB_00106600;
        }
      }
      iVar21 = 0x2744;
      iVar4 = 7;
      PyErr_Format(*(undefined8 *)PTR_PyExc_ImportError_0012ff90,"cannot import name %S",pPVar12);
      goto LAB_00106520;
    }
LAB_00106600:
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_bus,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x2746;
      iVar4 = 7;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_AHT20_F_I2C_ADDR,
                           __pyx_mstate_global_static.__pyx_int_56);
    if (iVar4 < 0) {
      iVar21 = 0x2751;
      iVar4 = 10;
      bVar3 = true;
      goto LAB_0010654c;
    }
    pPVar14 = (PyObject *)PyDict_New();
    if (pPVar14 == (PyObject *)0x0) {
      iVar21 = 0x275a;
      iVar4 = 0xd;
      bVar3 = true;
      goto LAB_0010654c;
    }
    pPVar11 = (PyObject *)PyList_New(1);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_186;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x275c;
      iVar4 = 0xd;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_186)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_186)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_RESET,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x2761;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(3);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_187;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x276b;
      iVar4 = 0xe;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_187)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_187)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_0;
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_type = (_typeobject *)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_0;
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_size = (Py_ssize_t)pPVar12;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_AFE_CFG,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x2776;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(3);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_188;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2780;
      iVar4 = 0xf;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_188)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_188)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_0;
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_type = (_typeobject *)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_0;
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_size = (Py_ssize_t)pPVar12;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_CCP_CCN,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x278b;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(3);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_190;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2795;
      iVar4 = 0x10;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_190)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_190)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_8;
    (__pyx_mstate_global_static.__pyx_int_8)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_8)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_type = (_typeobject *)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_0;
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_size = (Py_ssize_t)pPVar12;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_SYS_CFG,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x27a0;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(1);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_28;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x27aa;
      iVar4 = 0x11;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_28)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_28)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_OTP_CCP,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x27af;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(1);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_27;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x27b9;
      iVar4 = 0x12;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_27)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_27)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_OTP_AFE,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x27be;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = (PyObject *)PyList_New(3);
    pPVar12 = __pyx_mstate_global_static.__pyx_int_172;
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x27c8;
      iVar4 = 0x13;
      goto LAB_00106520;
    }
    p_Var20 = pPVar11[1].ob_type;
    (__pyx_mstate_global_static.__pyx_int_172)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_172)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_refcnt = (Py_ssize_t)pPVar12;
    pPVar12 = __pyx_mstate_global_static.__pyx_int_51;
    (__pyx_mstate_global_static.__pyx_int_51)->ob_refcnt =
         (__pyx_mstate_global_static.__pyx_int_51)->ob_refcnt + 1;
    (p_Var20->ob_base).ob_base.ob_type = (_typeobject *)pPVar12;
    pPVar13 = __pyx_mstate_global_static.__pyx_int_0;
    pPVar12 = (PyObject *)((__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt + 1);
    (__pyx_mstate_global_static.__pyx_int_0)->ob_refcnt = (Py_ssize_t)pPVar12;
    (p_Var20->ob_base).ob_size = (Py_ssize_t)pPVar13;
    iVar4 = PyDict_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_MEASURE,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x27d3;
      iVar4 = 0xd;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,pPVar14);
    if (iVar4 < 0) {
      iVar21 = 0x27d5;
      iVar4 = 0xc;
      goto LAB_00106520;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_AHT20_F_MAX_BUSY_CYCLES,
                           __pyx_mstate_global_static.__pyx_int_3);
    pPVar13 = __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f;
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_AHT20_F;
    if (iVar4 < 0) {
      iVar21 = 0x27df;
      iVar4 = 0x17;
      bVar3 = true;
      goto LAB_0010654c;
    }
                    /* Unresolved local var: PyObject * ns@[???] */
    pPVar14 = (PyObject *)PyDict_New();
    if (pPVar14 == (PyObject *)0x0) {
LAB_00106a44:
      iVar21 = 0x27e8;
      iVar4 = 0x19;
      bVar3 = true;
      goto LAB_0010654c;
    }
    iVar4 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_module,pPVar13);
    if ((iVar4 < 0) ||
       (iVar4 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_qualname,pPVar11),
       iVar4 < 0)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar6 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar6;
      if (lVar6 == 0) {
        iVar21 = 0x27e8;
        iVar4 = 0x19;
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
        bVar3 = true;
        goto LAB_0010654c;
      }
      goto LAB_00106a44;
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_1__init__,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F___init,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__7,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x27f2;
      iVar4 = 0x1a;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_init,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_init[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_init,pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x27f4;
      iVar4 = 0x1a;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_3handle_connect,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_handle_connect,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__9,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x27fe;
      iVar4 = 0x2e;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_handle_connect,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_handle_connect[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_handle_connect,pPVar11)
      ;
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2800;
      iVar4 = 0x2e;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_5setup_minmax,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_setup_minmax,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__11,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x280a;
      iVar4 = 0x32;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_setup_minmax,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_setup_minmax[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_setup_minmax,pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x280c;
      iVar4 = 0x32;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_7setup_callback,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_setup_callback,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__13,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2816;
      iVar4 = 0x36;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_setup_callback,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_setup_callback[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_setup_callback,pPVar11)
      ;
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2818;
      iVar4 = 0x36;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_9get_report_time_delta,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_get_report_time_delta,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__14,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2822;
      iVar4 = 0x39;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_get_report_time_delta,pPVar11
                          ,__pyx_mstate_global_static.__pyx_n_s_get_report_time_delta[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_get_report_time_delta,
                                pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2824;
      iVar4 = 0x39;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_11cmd_READ_TEMP_RH,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_cmd_READ_TEMP_RH,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__16,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x282e;
      iVar4 = 0x3c;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_cmd_READ_TEMP_RH,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_cmd_READ_TEMP_RH[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_cmd_READ_TEMP_RH,
                                pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2830;
      iVar4 = 0x3c;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_13check_crc8,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_check_crc8,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__18,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x283a;
      iVar4 = 0x41;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_check_crc8,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_check_crc8[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_check_crc8,pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x283c;
      iVar4 = 0x41;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_15_make_measurement,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F__make_measurement,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__20,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2846;
      iVar4 = 0x4e;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_make_measurement,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_make_measurement[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_make_measurement,
                                pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2848;
      iVar4 = 0x4e;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_17_reset_device,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F__reset_device,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__22,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2852;
      iVar4 = 0x95;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_reset_device,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_reset_device[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_reset_device,pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2854;
      iVar4 = 0x95;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_19_init_aht20_f,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F__init_aht20_f,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__23,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x285e;
      iVar4 = 0xb9;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_init_aht20_f,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_init_aht20_f[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_init_aht20_f,pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2860;
      iVar4 = 0xb9;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_21_sample_aht20_f,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F__sample_aht20_f,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__25,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x286a;
      iVar4 = 0xc5;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_sample_aht20_f,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_sample_aht20_f[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_sample_aht20_f,pPVar11)
      ;
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x286c;
      iVar4 = 0xc5;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar11 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_7AHT20_F_23get_status,
                         (int)__pyx_mstate_global_static.__pyx_n_s_AHT20_F_get_status,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__27,pPVar12,(PyObject *)code);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2876;
      iVar4 = 0xeb;
      goto LAB_00106520;
    }
    if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      uVar19 = _PyDict_SetItem_KnownHash
                         (pPVar14,__pyx_mstate_global_static.__pyx_n_s_get_status,pPVar11,
                          __pyx_mstate_global_static.__pyx_n_s_get_status[1].ob_type);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    else {
      uVar19 = PyObject_SetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_get_status,pPVar11);
      uVar5 = (uint)(uVar19 >> 0x1f);
    }
    if ((uVar5 & 1) != 0) {
      iVar21 = 0x2878;
      iVar4 = 0xeb;
      goto LAB_001064fc;
    }
    lVar6 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: PyObject * owned_metaclass@[???] */
    margs[2] = __pyx_mstate_global_static.__pyx_empty_tuple;
    margs[0] = (PyObject *)0x0;
    margs[1] = __pyx_mstate_global_static.__pyx_n_s_AHT20_F;
    margs[3] = pPVar14;
    pPVar11 = __Pyx_PyObject_FastCallDict
                        ((PyObject *)PTR_PyType_Type_0012ff48,margs + 1,0x8000000000000003,
                         __pyx_mstate_global_static.__pyx_empty_tuple);
    if (pPVar11 == (PyObject *)0x0) {
      iVar21 = 0x2882;
      iVar4 = 0x19;
      goto LAB_00106520;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_AHT20_F,pPVar11);
    if (iVar4 < 0) {
      iVar21 = 0x2884;
      iVar4 = 0x19;
      goto LAB_001064fc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    pPVar14 = __Pyx_CyFunction_New
                        (&__pyx_mdef_6extras_7aht20_f_1load_config,
                         (int)__pyx_mstate_global_static.__pyx_n_s_load_config,
                         __pyx_mstate_global_static.__pyx_n_s_extras_aht20_f,
                         __pyx_mstate_global_static.__pyx_d,
                         __pyx_mstate_global_static.__pyx_codeobj__29,pPVar12,(PyObject *)code);
    if (pPVar14 == (PyObject *)0x0) {
      iVar21 = 0x288f;
      iVar4 = 0xf2;
      bVar3 = true;
      goto LAB_0010654c;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_load_config,pPVar14);
    if (iVar4 < 0) {
      iVar21 = 0x2891;
      iVar4 = 0xf2;
      goto LAB_00106520;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
    pPVar14 = (PyObject *)PyDict_New();
    if (pPVar14 == (PyObject *)0x0) {
      iVar4 = 1;
      iVar21 = 0x2899;
      bVar3 = true;
      goto LAB_0010654c;
    }
    iVar4 = PyDict_SetItem(__pyx_mstate_global_static.__pyx_d,
                           __pyx_mstate_global_static.__pyx_n_s_test,pPVar14);
    if (iVar4 < 0) {
      iVar21 = 0x289b;
      iVar4 = 1;
      goto LAB_00106520;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar6 = pPVar14->ob_refcnt + -1;
    pPVar14->ob_refcnt = lVar6;
    if (lVar6 == 0) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
  }
  iVar4 = -(uint)(__pyx_m == (PyObject *)0x0);
LAB_001075a4:
  if (lVar18 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 001075dc
 * Symbol:  PyInit_aht20_f
 * Signature: PyObject * PyInit_aht20_f(void)
 * ================================================================ */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PyObject * PyInit_aht20_f(void)

{
  PyObject *pPVar1;
  
  pPVar1 = (PyObject *)PyModuleDef_Init(&__pyx_moduledef);
  return pPVar1;
}


/* ================================================================
 * Address: 001075ec
 * Symbol:  call_weak_fn
 * Signature: undefined call_weak_fn(void)
 * ================================================================ */

void call_weak_fn(void)

{
  if (PTR___gmon_start___0012ff28 != (undefined *)0x0) {
    __gmon_start__();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00107600
 * Symbol:  deregister_tm_clones
 * Signature: undefined deregister_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x00107618) */
/* WARNING: Removing unreachable block (ram,0x00107624) */

void deregister_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 00107630
 * Symbol:  register_tm_clones
 * Signature: undefined register_tm_clones(void)
 * ================================================================ */

/* WARNING: Removing unreachable block (ram,0x00107654) */
/* WARNING: Removing unreachable block (ram,0x00107660) */

void register_tm_clones(void)

{
  return;
}


/* ================================================================
 * Address: 001076ec
 * Symbol:  lexical_block_1_0
 * Signature: void lexical_block_1_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x1076ec 001076ec} (16 bytes)
   DWARF func body range[1]: {@address 0x107734 00107734} (20 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x00107730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(unaff_x19[1] + 0x30))();
    return;
  }
  return;
}


/* ================================================================
 * Address: 00107700
 * Symbol:  lexical_block_2_0
 * Signature: void lexical_block_2_0(void)
 * ================================================================ */

/* DWARF func body range[0]: {@address 0x107700 00107700} (16 bytes)
   DWARF func body range[1]: {@address 0x10771c 0010771c} (8 bytes)
   DWARF func body range[2]: {@address 0x10772c 0010772c} (8 bytes) */

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
                    /* WARNING: Could not recover jumptable at 0x00107730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x19[1] + 0x30))();
  return;
}


/* ================================================================
 * Address: 0010b490
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_3handle_connect
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_3handle_connect(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_3handle_connect
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject *apPVar1 [1];
  int iVar2;
  PyObject *pPVar3;
  PyObject *pPVar4;
  PyObject *pPVar5;
  PyObject *pPVar6;
  long lVar7;
  getattrofunc p_Var8;
  _typeobject *p_Var9;
  long lVar10;
  char *in_x6;
  PyObject *pPVar11;
  int c_line;
  PyObject *func;
  _typeobject *p_Var12;
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
  lVar10 = *(long *)PTR___stack_chk_guard_0012ff30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  pPVar3 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 1) {
LAB_0010b4e4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","handle_connect",
                   "exactly",1,"",__pyx_nargs);
      iVar2 = 0x106b;
LAB_0010b520:
      __Pyx_AddTraceback("extras.aht20_f.AHT20_F.handle_connect",iVar2,0x2e,"aht20_f.py");
      pPVar3 = (PyObject *)0x0;
      goto LAB_0010b53c;
    }
    values[0] = *__pyx_args;
  }
  else {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar7 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,__pyx_args + __pyx_nargs,
                             __pyx_mstate_global_static.__pyx_n_s_self);
      lVar7 = lVar7 + -1;
      if (values[0] == (PyObject *)0x0) {
        lVar7 = PyErr_Occurred();
        if (lVar7 == 0) goto LAB_0010b4e4;
        iVar2 = 0x105b;
        goto LAB_0010b520;
      }
    }
    else {
      if (__pyx_nargs != 1) goto LAB_0010b4e4;
      values[0] = *__pyx_args;
      lVar7 = __pyx_kwds[1].ob_refcnt;
    }
    if (0 < lVar7) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar3 = (PyObject *)values;
      iVar2 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,__pyx_args + __pyx_nargs,__pyx_pyargnames,pPVar3,
                         (PyObject **)__pyx_nargs,0x11cf60,in_x6);
      if (iVar2 < 0) {
        iVar2 = 0x1060;
        goto LAB_0010b520;
      }
    }
  }
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
  apPVar1[0] = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var8 = values[0]->ob_type->tp_getattro;
  if (p_Var8 == (getattrofunc)0x0) {
    pPVar4 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar4 = (*p_Var8)(values[0],__pyx_mstate_global_static.__pyx_n_s_init_aht20_f);
  }
  if (pPVar4 == (PyObject *)0x0) {
    c_line = 0x109b;
    iVar2 = 0x2f;
  }
  else {
    p_Var9 = pPVar4->ob_type;
    if ((p_Var9 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var12 = pPVar4[1].ob_type, p_Var12 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)pPVar4[1].ob_refcnt;
      (p_Var12->ob_base).ob_base.ob_refcnt = (p_Var12->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar4->ob_refcnt + -1;
      pPVar4->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var9->tp_dealloc)(pPVar4);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var12;
      pPVar5 = __Pyx_PyObject_FastCallDict(pPVar11,(PyObject **)__pyx_pyargnames,1,pPVar3);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
      (p_Var12->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar4 = pPVar11;
      if (lVar7 == 0) {
        (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar5 = __Pyx_PyObject_FastCallDict(pPVar4,(PyObject **)(__pyx_pyargnames + 1),0,pPVar3);
    }
    if (pPVar5 == (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      c_line = 0x10af;
      iVar2 = 0x2f;
      lVar7 = pPVar4->ob_refcnt + -1;
LAB_0010b97c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar4->ob_refcnt = lVar7;
joined_r0x0010b980:
      if (lVar7 == 0) {
        (*pPVar4->ob_type->tp_dealloc)(pPVar4);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      }
    }
    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar4->ob_refcnt + -1;
      pPVar4->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*pPVar4->ob_type->tp_dealloc)(pPVar4);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar5->ob_refcnt + -1;
      pPVar5->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*pPVar5->ob_type->tp_dealloc)(pPVar5);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var8 = apPVar1[0]->ob_type->tp_getattro;
      if (p_Var8 == (getattrofunc)0x0) {
        pPVar4 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar4 = (*p_Var8)(apPVar1[0],__pyx_mstate_global_static.__pyx_n_s_reactor);
      }
      if (pPVar4 == (PyObject *)0x0) {
        c_line = 0x10bc;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var8 = pPVar4->ob_type->tp_getattro;
        if (p_Var8 == (getattrofunc)0x0) {
          pPVar5 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar5 = (*p_Var8)(pPVar4,__pyx_mstate_global_static.__pyx_n_s_update_timer);
        }
        lVar7 = pPVar4->ob_refcnt + -1;
        if (pPVar5 == (PyObject *)0x0) {
          c_line = 0x10be;
          iVar2 = 0x30;
          goto LAB_0010b97c;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar4->ob_refcnt = lVar7;
        if (lVar7 == 0) {
          (*pPVar4->ob_type->tp_dealloc)(pPVar4);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var8 = apPVar1[0]->ob_type->tp_getattro;
        if (p_Var8 == (getattrofunc)0x0) {
          pPVar11 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar11 = (*p_Var8)(apPVar1[0],__pyx_mstate_global_static.__pyx_n_s_sample_timer);
        }
        if (pPVar11 == (PyObject *)0x0) {
          c_line = 0x10c1;
LAB_0010b9c4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar7 = pPVar5->ob_refcnt + -1;
          pPVar5->ob_refcnt = lVar7;
          if (lVar7 != 0) goto LAB_0010ba50;
          pPVar4 = (PyObject *)0x0;
LAB_0010b9d8:
          (*pPVar5->ob_type->tp_dealloc)(pPVar5);
        }
        else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var8 = apPVar1[0]->ob_type->tp_getattro;
          if (p_Var8 == (getattrofunc)0x0) {
            pPVar4 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar4 = (*p_Var8)(apPVar1[0],__pyx_mstate_global_static.__pyx_n_s_reactor);
          }
          if (pPVar4 == (PyObject *)0x0) {
            c_line = 0x10c3;
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var8 = pPVar4->ob_type->tp_getattro;
            if (p_Var8 == (getattrofunc)0x0) {
              pPVar6 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar6 = (*p_Var8)(pPVar4,__pyx_mstate_global_static.__pyx_n_s_NOW);
            }
            if (pPVar6 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar7 = pPVar4->ob_refcnt + -1;
              pPVar4->ob_refcnt = lVar7;
              if (lVar7 == 0) {
                (*pPVar4->ob_type->tp_dealloc)(pPVar4);
              }
              p_Var9 = pPVar5->ob_type;
              if ((p_Var9 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                 (p_Var12 = pPVar5[1].ob_type, p_Var12 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                func = (PyObject *)pPVar5[1].ob_refcnt;
                (p_Var12->ob_base).ob_base.ob_refcnt = (p_Var12->ob_base).ob_base.ob_refcnt + 1;
                func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar7 = pPVar5->ob_refcnt + -1;
                pPVar5->ob_refcnt = lVar7;
                if (lVar7 == 0) {
                  (*p_Var9->tp_dealloc)(pPVar5);
                }
                __pyx_pyargnames[0] = (PyObject **)p_Var12;
                __pyx_pyargnames[1] = (PyObject **)pPVar11;
                pPVar4 = __Pyx_PyObject_FastCallDict(func,(PyObject **)__pyx_pyargnames,3,pPVar3);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar7 = (p_Var12->ob_base).ob_base.ob_refcnt + -1;
                (p_Var12->ob_base).ob_base.ob_refcnt = lVar7;
                pPVar5 = func;
                if (lVar7 != 0) goto LAB_0010b7c4;
                (*((p_Var12->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var12);
                lVar7 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar7;
                if (lVar7 == 0) goto LAB_0010b88c;
LAB_0010b7d4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar7 = pPVar6->ob_refcnt + -1;
                pPVar6->ob_refcnt = lVar7;
                pPVar5 = func;
              }
              else {
                __pyx_pyargnames[0] = (PyObject **)0x0;
                __pyx_pyargnames[1] = (PyObject **)pPVar11;
                pPVar4 = __Pyx_PyObject_FastCallDict
                                   (pPVar5,(PyObject **)(__pyx_pyargnames + 1),2,pPVar3);
LAB_0010b7c4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar7 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar7;
                func = pPVar5;
                if (lVar7 != 0) goto LAB_0010b7d4;
LAB_0010b88c:
                (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                lVar7 = pPVar6->ob_refcnt + -1;
                pPVar6->ob_refcnt = lVar7;
                pPVar5 = func;
              }
              if (lVar7 == 0) {
                (*pPVar6->ob_type->tp_dealloc)(pPVar6);
              }
              if (pPVar4 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar7 = pPVar5->ob_refcnt + -1;
                pPVar5->ob_refcnt = lVar7;
                if (lVar7 == 0) {
                  (*pPVar5->ob_type->tp_dealloc)(pPVar5);
                  lVar7 = pPVar4->ob_refcnt + -1;
                  pPVar4->ob_refcnt = lVar7;
                  pPVar3 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                }
                else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar7 = pPVar4->ob_refcnt + -1;
                  pPVar4->ob_refcnt = lVar7;
                  pPVar3 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                }
                PTR__Py_NoneStruct_0012ff50 = (undefined *)pPVar3;
                if (lVar7 == 0) {
                  (*pPVar4->ob_type->tp_dealloc)(pPVar4);
                  pPVar3 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                  *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
                }
                else {
                  pPVar3->ob_refcnt = pPVar3->ob_refcnt + 1;
                }
                goto LAB_0010b53c;
              }
              c_line = 0x10dc;
              goto LAB_0010b9c4;
            }
            c_line = 0x10c5;
          }
          lVar7 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar7;
          if (lVar7 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          lVar7 = pPVar5->ob_refcnt + -1;
          pPVar5->ob_refcnt = lVar7;
          if (lVar7 == 0) goto LAB_0010b9d8;
        }
        if (pPVar4 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          iVar2 = 0x30;
          lVar7 = pPVar4->ob_refcnt + -1;
          pPVar4->ob_refcnt = lVar7;
          goto joined_r0x0010b980;
        }
      }
LAB_0010ba50:
      iVar2 = 0x30;
    }
  }
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.handle_connect",c_line,iVar2,"aht20_f.py");
  pPVar3 = (PyObject *)0x0;
LAB_0010b53c:
  if (lVar10 != *(long *)PTR___stack_chk_guard_0012ff30) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar3;
}


/* ================================================================
 * Address: 0010bb20
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_11cmd_READ_TEMP_RH
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_11cmd_READ_TEMP_RH(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Exceeded maximum restarts with more pending */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_11cmd_READ_TEMP_RH
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
  long *plVar12;
  PyObject **ppPVar13;
  undefined1 *puVar14;
  setattrfunc *__s2;
  getattrofunc p_Var15;
  PyObject *pPVar16;
  char *pcVar17;
  uint uVar18;
  long lVar19;
  uint uVar20;
  _typeobject *p_Var21;
  long lVar22;
  _typeobject *p_Var23;
  PyObject *pPVar24;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_gcmd@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar19 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_gcmd;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar16 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0010bb94;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_0010bc28;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar13 = __pyx_args + __pyx_nargs;
  pcVar17 = PTR___stack_chk_guard_0012ff30;
  if (__pyx_nargs == 1) {
    pPVar16 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar9 = pPVar16;
LAB_0010be4c:
    pPVar10 = __pyx_mstate_global_static.__pyx_n_s_gcmd;
    puVar5 = PTR_PyUnicode_Type_0012ffb0;
    puVar4 = PTR__Py_TrueStruct_0012ff58;
    puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar9) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_gcmd == p_Var23) {
        values[1] = *ppPVar13;
      }
      else {
        pPVar24 = (PyObject *)0x0;
        do {
          pPVar11 = (PyObject *)((long)&pPVar24->ob_refcnt + 1);
          if (pPVar11 == pPVar9) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar24 = (PyObject *)0x0;
            goto LAB_0010beb0;
          }
          pPVar2 = &__pyx_kwds[2].ob_refcnt + (long)pPVar24;
          pPVar24 = pPVar11;
        } while (__pyx_mstate_global_static.__pyx_n_s_gcmd != (PyObject *)*pPVar2);
        values[1] = ppPVar13[(long)pPVar11];
      }
      goto LAB_0010c064;
    }
LAB_0010c118:
    values[1] = (PyObject *)0x0;
    goto LAB_0010c11c;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar14 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_0010be10;
  }
  if (__pyx_nargs == 0) {
    lVar22 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar13,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar16 = (PyObject *)(lVar22 + -1);
      pPVar9 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      goto LAB_0010be4c;
    }
    lVar22 = PyErr_Occurred();
    if (lVar22 != 0) {
      iVar8 = 0x131d;
      goto LAB_0010bbd0;
    }
  }
LAB_0010bb94:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","cmd_READ_TEMP_RH",
               "exactly",2,"s",__pyx_nargs);
  iVar8 = 0x1339;
  goto LAB_0010bbd0;
  while( true ) {
    pPVar2 = &pPVar24->ob_refcnt;
    pPVar24 = (PyObject *)((long)pPVar2 + 1);
    if (pPVar24 == pPVar9) goto LAB_0010c118;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar2];
    if ((_typeobject *)pPVar10 == p_Var23) break;
LAB_0010beb0:
    bVar6 = pPVar10->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar10 != (PyObject *)puVar3) && (bVar6 || p_Var23 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar10,p_Var23,2);
        if (plVar12 == (long *)0x0) goto LAB_0010c118;
        uVar18 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar12 != (long *)puVar3) {
          uVar18 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = *plVar12;
        *plVar12 = lVar22 + -1;
        if (lVar22 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_0010c108:
        if (uVar18 != 0) {
          if ((int)uVar18 < 0) goto LAB_0010c118;
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
      goto LAB_0010c118;
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
            p_Var21 = pPVar10[4].ob_type;
          }
          else {
            p_Var21 = (_typeobject *)&pPVar10[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              p_Var21 = (_typeobject *)(pPVar10 + 3);
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
            uVar18 = (uint)(byte)(p_Var21->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(byte *)__s2;
          }
          else if (uVar18 == 2) {
            uVar18 = (uint)(ushort)(p_Var21->ob_base).ob_base.ob_refcnt;
            uVar20 = (uint)*(ushort *)__s2;
          }
          else {
            uVar18 = (uint)(p_Var21->ob_base).ob_base.ob_refcnt;
            uVar20 = *(uint *)__s2;
          }
          if (uVar20 == uVar18) {
            if (lVar22 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var21,__s2,(long)pcVar17 * lVar22);
              uVar18 = (uint)(iVar8 == 0);
              goto LAB_0010c108;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar13[(long)pPVar24];
LAB_0010c064:
  if (values[1] != (PyObject *)0x0) {
    puVar14 = (undefined1 *)((long)&pPVar16[-1].ob_type + 7);
LAB_0010be10:
    if (0 < (long)puVar14) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar16 = (PyObject *)values;
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar13,__pyx_pyargnames,pPVar16,(PyObject **)__pyx_nargs,
                         0x11cfe0,pcVar17);
      if (iVar8 < 0) {
        iVar8 = 0x132c;
        goto LAB_0010bbd0;
      }
    }
LAB_0010bc28:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: wchar_t __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
    pPVar9 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = values[0]->ob_type->tp_getattro;
    if (p_Var15 == (getattrofunc)0x0) {
      pPVar10 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar10 = (*p_Var15)(values[0],__pyx_mstate_global_static.__pyx_n_s_gcode);
    }
    if (pPVar10 == (PyObject *)0x0) {
      iVar8 = 0x136a;
    }
    else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar10->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar24 = (PyObject *)
                  PyObject_GetAttr(pPVar10,__pyx_mstate_global_static.__pyx_n_s_respond_raw);
      }
      else {
        pPVar24 = (PyObject *)(*p_Var15)();
      }
      lVar22 = pPVar10->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar10->ob_refcnt = lVar22;
      if (pPVar24 == (PyObject *)0x0) {
        iVar8 = 0x136c;
        if (lVar22 == 0) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          (*pPVar10->ob_type->tp_dealloc)(pPVar10);
        }
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if (lVar22 == 0) {
          (*pPVar10->ob_type->tp_dealloc)(pPVar10);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var15 = pPVar9->ob_type->tp_getattro;
        if (p_Var15 == (getattrofunc)0x0) {
          pPVar10 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar10 = (*p_Var15)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_name);
        }
        if (pPVar10 == (PyObject *)0x0) {
          iVar8 = 0x136f;
          plVar12 = (long *)0x0;
LAB_0010c214:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            pPVar9 = (PyObject *)0x0;
            pPVar11 = (PyObject *)0x0;
            goto LAB_0010c22c;
          }
        }
        else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var15 = pPVar9->ob_type->tp_getattro;
          if (p_Var15 == (getattrofunc)0x0) {
            pPVar11 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar11 = (*p_Var15)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_temp);
          }
          if (pPVar11 == (PyObject *)0x0) {
            pPVar9 = (PyObject *)0x0;
            iVar8 = 0x1371;
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var15 = pPVar9->ob_type->tp_getattro;
            if (p_Var15 == (getattrofunc)0x0) {
              pPVar9 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar9 = (*p_Var15)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_humidity);
            }
            if (pPVar9 == (PyObject *)0x0) {
              iVar8 = 0x1373;
            }
            else {
              plVar12 = (long *)PyTuple_New(3);
              if (plVar12 != (long *)0x0) {
                plVar12[3] = (long)pPVar10;
                plVar12[4] = (long)pPVar11;
                plVar12[5] = (long)pPVar9;
                ppPVar13 = (PyObject **)
                           PyUnicode_Format(__pyx_mstate_global_static.
                                            __pyx_kp_s_s_temp_f_humidity_f,plVar12);
                if (ppPVar13 == (PyObject **)0x0) {
                  iVar8 = 0x1380;
                  goto LAB_0010c214;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar22 = *plVar12;
                *plVar12 = lVar22 + -1;
                if (lVar22 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                p_Var23 = pPVar24->ob_type;
                if ((p_Var23 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                   (p_Var21 = pPVar24[1].ob_type, p_Var21 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar9 = (PyObject *)pPVar24[1].ob_refcnt;
                  (p_Var21->ob_base).ob_base.ob_refcnt = (p_Var21->ob_base).ob_base.ob_refcnt + 1;
                  pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar22 = pPVar24->ob_refcnt + -1;
                  pPVar24->ob_refcnt = lVar22;
                  if (lVar22 == 0) {
                    (*p_Var23->tp_dealloc)(pPVar24);
                  }
                  __pyx_pyargnames[0] = (PyObject **)p_Var21;
                  __pyx_pyargnames[1] = ppPVar13;
                  pPVar16 = __Pyx_PyObject_FastCallDict
                                      (pPVar9,(PyObject **)__pyx_pyargnames,2,pPVar16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar22 = (p_Var21->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var21->ob_base).ob_base.ob_refcnt = lVar22;
                  pPVar24 = pPVar9;
                  if (lVar22 != 0) goto LAB_0010bdac;
                  (*((p_Var21->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var21);
                  pPVar9 = (PyObject *)((long)&(*ppPVar13)[-1].ob_type + 7);
                  *ppPVar13 = pPVar9;
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = ppPVar13;
                  pPVar16 = __Pyx_PyObject_FastCallDict
                                      (pPVar24,(PyObject **)(__pyx_pyargnames + 1),1,pPVar16);
LAB_0010bdac:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar9 = (PyObject *)((long)&(*ppPVar13)[-1].ob_type + 7);
                  *ppPVar13 = pPVar9;
                }
                if (pPVar9 == (PyObject *)0x0) {
                  (*(code *)ppPVar13[1][3].ob_refcnt)(ppPVar13);
                }
                if (pPVar16 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar22 = pPVar24->ob_refcnt + -1;
                  pPVar24->ob_refcnt = lVar22;
                  if (lVar22 == 0) {
                    (*pPVar24->ob_type->tp_dealloc)(pPVar24);
                    lVar22 = pPVar16->ob_refcnt + -1;
                    pPVar16->ob_refcnt = lVar22;
                    pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                  }
                  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar22 = pPVar16->ob_refcnt + -1;
                    pPVar16->ob_refcnt = lVar22;
                    pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                  }
                  PTR__Py_NoneStruct_0012ff50 = (undefined *)pPVar9;
                  if (lVar22 == 0) {
                    (*pPVar16->ob_type->tp_dealloc)(pPVar16);
                    pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                    *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
                  }
                  else {
                    pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                  }
                  goto LAB_0010bbec;
                }
                iVar8 = 0x1396;
                plVar12 = (long *)0x0;
                goto LAB_0010c214;
              }
              iVar8 = 0x1375;
            }
          }
          lVar22 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          plVar12 = (long *)0x0;
          lVar22 = pPVar24->ob_refcnt + -1;
          pPVar24->ob_refcnt = lVar22;
          if (lVar22 == 0) {
LAB_0010c22c:
            (*pPVar24->ob_type->tp_dealloc)(pPVar24);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar11 != (PyObject *)0x0) &&
             (lVar22 = pPVar11->ob_refcnt + -1, pPVar11->ob_refcnt = lVar22, lVar22 == 0)) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar9 != (PyObject *)0x0) &&
             (lVar22 = pPVar9->ob_refcnt + -1, pPVar9->ob_refcnt = lVar22, lVar22 == 0)) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
          }
        }
        if ((plVar12 != (long *)0x0) &&
           (lVar22 = *plVar12, *plVar12 = lVar22 + -1, lVar22 + -1 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
    }
    __Pyx_AddTraceback("extras.aht20_f.AHT20_F.cmd_READ_TEMP_RH",iVar8,0x3e,"aht20_f.py");
    pPVar9 = (PyObject *)0x0;
    goto LAB_0010bbec;
  }
LAB_0010c11c:
  lVar22 = PyErr_Occurred();
  if (lVar22 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","cmd_READ_TEMP_RH",
                 "exactly",2,"s",1);
    iVar8 = 0x1327;
  }
  else {
    iVar8 = 0x1325;
  }
LAB_0010bbd0:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.cmd_READ_TEMP_RH",iVar8,0x3c,"aht20_f.py");
  pPVar9 = (PyObject *)0x0;
LAB_0010bbec:
  if (lVar19 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010c408
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_23get_status
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_23get_status(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_23get_status
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
  PyObject *pPVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  PyObject *pPVar12;
  long lVar13;
  _typeobject *__s1;
  long *plVar14;
  setattrfunc *__s2;
  int iVar15;
  getattrofunc p_Var16;
  long lVar17;
  char *pcVar18;
  uint uVar19;
  long lVar20;
  uint uVar21;
  long lVar22;
  _typeobject *p_Var23;
  int iVar24;
  PyObject *pPVar25;
  long lVar26;
  ternaryfunc p_Var27;
  Py_ssize_t PVar28;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_eventtime@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar20 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_eventtime;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar18 = PTR___stack_chk_guard_0012ff30;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar22 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0010c6bc;
      }
      if (__pyx_nargs == 0) {
        lVar22 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar22 = lVar22 + -1;
          PVar28 = __pyx_kwds[1].ob_refcnt;
          goto LAB_0010c6f8;
        }
        lVar22 = PyErr_Occurred();
        if (lVar22 != 0) {
          iVar11 = 0x22c2;
          goto LAB_0010c4b8;
        }
      }
LAB_0010c47c:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","get_status",
                   "exactly",2,"s",__pyx_nargs);
      iVar11 = 0x22de;
      goto LAB_0010c4b8;
    }
    lVar22 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    PVar28 = lVar22;
LAB_0010c6f8:
    pPVar25 = __pyx_mstate_global_static.__pyx_n_s_eventtime;
    puVar5 = PTR_PyUnicode_Type_0012ffb0;
    puVar4 = PTR__Py_TrueStruct_0012ff58;
    puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < PVar28) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_eventtime == p_Var23) {
        values[1] = *kwvalues;
      }
      else {
        lVar13 = 0;
        do {
          lVar26 = lVar13 + 1;
          if (lVar26 == PVar28) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar13 = 0;
            goto LAB_0010c758;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar13;
          lVar13 = lVar26;
        } while (__pyx_mstate_global_static.__pyx_n_s_eventtime != (PyObject *)*pPVar1);
        values[1] = kwvalues[lVar26];
      }
      goto LAB_0010c86c;
    }
LAB_0010c920:
    values[1] = (PyObject *)0x0;
    goto LAB_0010c924;
  }
  if (__pyx_nargs != 2) goto LAB_0010c47c;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0010c514:
  pPVar8 = values[0];
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar25 = (PyObject *)PyDict_New();
  if (pPVar25 == (PyObject *)0x0) {
    iVar11 = 0xed;
    iVar24 = 0x2314;
  }
  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var16 = pPVar8->ob_type->tp_getattro;
    if (p_Var16 == (getattrofunc)0x0) {
      p_Var23 = (_typeobject *)PyObject_GetAttr();
    }
    else {
      p_Var23 = (_typeobject *)(*p_Var16)(pPVar8,__pyx_mstate_global_static.__pyx_n_s_temp);
    }
    if (p_Var23 == (_typeobject *)0x0) {
      iVar24 = 0x2316;
      iVar11 = 0xed;
LAB_0010ca34:
      lVar22 = pPVar25->ob_refcnt + -1;
      pPVar25->ob_refcnt = lVar22;
      if (lVar22 != 0) goto LAB_0010ca00;
      pPVar12 = (PyObject *)0x0;
      p_Var23 = (_typeobject *)0x0;
      iVar15 = iVar11;
LAB_0010ca4c:
      (*pPVar25->ob_type->tp_dealloc)(pPVar25);
      if (p_Var23 != (_typeobject *)0x0) {
LAB_0010ca68:
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        if (lVar22 == 0) goto LAB_0010c9bc;
      }
LAB_0010c9d4:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      iVar11 = iVar15;
      if (pPVar12 == (PyObject *)0x0) goto LAB_0010ca00;
    }
    else {
      pPVar12 = (PyObject *)PyTuple_New(2);
      if (pPVar12 == (PyObject *)0x0) {
        iVar24 = 0x2318;
LAB_0010c994:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar25->ob_refcnt + -1;
        pPVar25->ob_refcnt = lVar22;
        if (lVar22 == 0) {
LAB_0010cbd0:
          pPVar12 = (PyObject *)0x0;
          iVar15 = 0xed;
          goto LAB_0010ca4c;
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        iVar15 = 0xed;
        pPVar12 = (PyObject *)0x0;
        lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
        (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
        iVar11 = 0xed;
        if (lVar22 != 0) goto LAB_0010ca00;
LAB_0010c9bc:
        (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
        goto LAB_0010c9d4;
      }
      pPVar12[1].ob_type = p_Var23;
      pPVar7 = __pyx_builtin_round;
      pPVar6 = __pyx_mstate_global_static.__pyx_int_2;
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: ternaryfunc call@[???] */
      p_Var27 = __pyx_builtin_round->ob_type->tp_call;
      (__pyx_mstate_global_static.__pyx_int_2)->ob_refcnt =
           (__pyx_mstate_global_static.__pyx_int_2)->ob_refcnt + 1;
      pPVar12[2].ob_refcnt = (Py_ssize_t)pPVar6;
      if (p_Var27 == (ternaryfunc)0x0) {
        p_Var23 = (_typeobject *)PyObject_Call(pPVar7,pPVar12,0);
        if (p_Var23 == (_typeobject *)0x0) goto LAB_0010caa8;
LAB_0010c5f0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar22;
        if (lVar22 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        iVar11 = PyDict_SetItem(pPVar25,__pyx_mstate_global_static.__pyx_n_s_temperature,p_Var23);
        if (-1 < iVar11) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
          (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
          if (lVar22 == 0) {
            (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var16 = pPVar8->ob_type->tp_getattro;
          if (p_Var16 == (getattrofunc)0x0) {
            p_Var23 = (_typeobject *)PyObject_GetAttr();
          }
          else {
            p_Var23 = (_typeobject *)
                      (*p_Var16)(pPVar8,__pyx_mstate_global_static.__pyx_n_s_humidity);
          }
          if (p_Var23 == (_typeobject *)0x0) {
            iVar24 = 0x232d;
            iVar11 = 0xee;
            goto LAB_0010ca34;
          }
          iVar11 = PyDict_SetItem(pPVar25,__pyx_mstate_global_static.__pyx_n_s_humidity,p_Var23);
          if (-1 < iVar11) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar22 = (p_Var23->ob_base).ob_base.ob_refcnt + -1;
            (p_Var23->ob_base).ob_base.ob_refcnt = lVar22;
            if (lVar22 == 0) {
              (*((p_Var23->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var23);
            }
            goto LAB_0010c4d4;
          }
          iVar24 = 0x232f;
          goto LAB_0010c994;
        }
        iVar24 = 0x2323;
        pPVar12 = (PyObject *)0x0;
        iVar15 = 0xed;
        lVar22 = pPVar25->ob_refcnt + -1;
        pPVar25->ob_refcnt = lVar22;
        if (lVar22 == 0) goto LAB_0010cbd0;
        goto LAB_0010ca68;
      }
      lVar22 = PyThreadState_Get();
      puVar3 = PTR__Py_CheckRecursionLimit_0012ff08;
      iVar11 = *(int *)(lVar22 + 0x20) + 1;
      *(int *)(lVar22 + 0x20) = iVar11;
      if ((iVar11 <= *(int *)puVar3) ||
         (iVar11 = _Py_CheckRecursiveCall(" while calling a Python object"), iVar11 == 0)) {
        p_Var23 = (_typeobject *)(*p_Var27)(pPVar7,pPVar12,(PyObject *)0x0);
        lVar22 = PyThreadState_Get();
        puVar3 = PTR__Py_CheckRecursionLimit_0012ff08;
        iVar15 = *(int *)(lVar22 + 0x20) + -1;
        *(int *)(lVar22 + 0x20) = iVar15;
        iVar24 = *(int *)puVar3;
        iVar11 = iVar24 + -0x32;
        if (iVar24 < 0xc9) {
          iVar11 = (iVar24 >> 2) * 3;
        }
        if (iVar15 < iVar11) {
          lVar22 = PyThreadState_Get();
          *(undefined1 *)(lVar22 + 0x24) = 0;
        }
        if (p_Var23 != (_typeobject *)0x0) goto LAB_0010c5f0;
        lVar22 = PyErr_Occurred();
        if (lVar22 == 0) {
          PyErr_SetString(*(undefined8 *)PTR_PyExc_SystemError_0012fe98,
                          "NULL result without error in PyObject_Call");
        }
      }
LAB_0010caa8:
      iVar15 = 0xed;
      iVar24 = 0x2320;
      p_Var23 = (_typeobject *)0x0;
      lVar22 = pPVar25->ob_refcnt + -1;
      pPVar25->ob_refcnt = lVar22;
      if (lVar22 == 0) goto LAB_0010ca4c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar22 = pPVar12->ob_refcnt + -1;
    pPVar12->ob_refcnt = lVar22;
    iVar11 = iVar15;
    if (lVar22 == 0) {
      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
    }
  }
LAB_0010ca00:
  pPVar25 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.get_status",iVar24,iVar11,"aht20_f.py");
LAB_0010c4d4:
  if (lVar20 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar25;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar26 = lVar13 + 1;
    if (lVar26 == PVar28) goto LAB_0010c920;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar13];
    lVar13 = lVar26;
    if ((_typeobject *)pPVar25 == p_Var23) break;
LAB_0010c758:
    bVar9 = pPVar25->ob_type != (_typeobject *)puVar5;
    bVar10 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar26 = lVar13;
    if (bVar9 || bVar10) {
      if ((bVar10 || pPVar25 != (PyObject *)puVar3) && (bVar9 || p_Var23 != (_typeobject *)puVar3))
      {
        plVar14 = (long *)PyObject_RichCompare(pPVar25,p_Var23,2);
        if (plVar14 == (long *)0x0) goto LAB_0010c920;
        uVar19 = (uint)(plVar14 == (long *)puVar4);
        if ((plVar14 != (long *)puVar4 && plVar14 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar14 != (long *)puVar3) {
          uVar19 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar17 = *plVar14;
        *plVar14 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_0010c910:
        if (uVar19 != 0) {
          if ((int)uVar19 < 0) goto LAB_0010c920;
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
         ((-1 < (char)p_Var23->tp_basicsize && (iVar11 = _PyUnicode_Ready(p_Var23), iVar11 < 0))))
      goto LAB_0010c920;
      lVar17 = pPVar25[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar17 == (p_Var23->ob_base).ob_size) &&
         ((pPVar25[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar25[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar18 = (char *)((ulong)(byte)((byte)pPVar25[2].ob_refcnt >> 2) & 7);
        uVar19 = (uint)pcVar18;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar19) {
          bVar2 = (byte)pPVar25[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar25[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar25[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar25 + 3);
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
            uVar19 = (uint)(byte)(__s1->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(byte *)__s2;
          }
          else if (uVar19 == 2) {
            uVar19 = (uint)(ushort)(__s1->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(ushort *)__s2;
          }
          else {
            uVar19 = (uint)(__s1->ob_base).ob_base.ob_refcnt;
            uVar21 = *(uint *)__s2;
          }
          if (uVar21 == uVar19) {
            if (lVar17 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar11 = memcmp(__s1,__s2,(long)pcVar18 * lVar17);
              uVar19 = (uint)(iVar11 == 0);
              goto LAB_0010c910;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar26];
LAB_0010c86c:
  if (values[1] == (PyObject *)0x0) {
LAB_0010c924:
    lVar22 = PyErr_Occurred();
    if (lVar22 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","get_status",
                   "exactly",2,"s",1);
      iVar11 = 0x22cc;
    }
    else {
      iVar11 = 0x22ca;
    }
  }
  else {
    lVar22 = lVar22 + -1;
LAB_0010c6bc:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar22 < 1) ||
       (iVar11 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x11d020,pcVar18), -1 < iVar11))
    goto LAB_0010c514;
    iVar11 = 0x22d1;
  }
LAB_0010c4b8:
  pPVar25 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.get_status",iVar11,0xeb,"aht20_f.py");
  goto LAB_0010c4d4;
}


/* ================================================================
 * Address: 0010cc20
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_1__init__
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_1__init__(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_1__init__
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
  PyObject *pPVar11;
  PyObject **ppPVar12;
  Py_ssize_t PVar13;
  long *plVar14;
  setattrfunc *__s2;
  getattrofunc p_Var15;
  ssizeargfunc p_Var16;
  setattrofunc p_Var17;
  __pyx_mstate *kwargs;
  char *pcVar18;
  uint uVar19;
  long lVar20;
  uint uVar21;
  PyObject *pPVar22;
  PyMappingMethods *pPVar23;
  long lVar24;
  _typeobject *p_Var25;
  PySequenceMethods *pPVar26;
  _typeobject *p_Var27;
  PyObject *pPVar28;
  PyObject *pPVar29;
  int iVar30;
  PyObject *pPVar31;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar20 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_config;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  pPVar22 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0010cc90;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    goto LAB_0010cd2c;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  ppPVar12 = __pyx_args + __pyx_nargs;
  pcVar18 = PTR___stack_chk_guard_0012ff30;
  if (__pyx_nargs == 1) {
    pPVar22 = (PyObject *)__pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    pPVar31 = pPVar22;
LAB_0010d07c:
    pPVar11 = __pyx_mstate_global_static.__pyx_n_s_config;
    puVar5 = PTR_PyUnicode_Type_0012ffb0;
    puVar4 = PTR__Py_TrueStruct_0012ff58;
    puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < (long)pPVar31) {
      p_Var25 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var25) {
        values[1] = *ppPVar12;
      }
      else {
        pPVar28 = (PyObject *)0x0;
        do {
          pPVar9 = (PyObject *)((long)&pPVar28->ob_refcnt + 1);
          if (pPVar9 == pPVar31) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            pPVar28 = (PyObject *)0x0;
            goto LAB_0010d0e0;
          }
          pPVar2 = &__pyx_kwds[2].ob_refcnt + (long)pPVar28;
          pPVar28 = pPVar9;
        } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar2);
        values[1] = ppPVar12[(long)pPVar9];
      }
      goto LAB_0010df7c;
    }
LAB_0010e030:
    values[1] = (PyObject *)0x0;
    goto LAB_0010e034;
  }
  if (__pyx_nargs == 2) {
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    puVar10 = (undefined1 *)__pyx_kwds[1].ob_refcnt;
    goto LAB_0010d044;
  }
  if (__pyx_nargs == 0) {
    lVar24 = __pyx_kwds[1].ob_refcnt;
    values[0] = __Pyx_GetKwValue_FASTCALL
                          (__pyx_kwds,ppPVar12,__pyx_mstate_global_static.__pyx_n_s_self);
    if (values[0] != (PyObject *)0x0) {
      pPVar22 = (PyObject *)(lVar24 + -1);
      pPVar31 = (PyObject *)__pyx_kwds[1].ob_refcnt;
      goto LAB_0010d07c;
    }
    lVar24 = PyErr_Occurred();
    if (lVar24 != 0) {
      iVar8 = 0xddc;
      goto LAB_0010cccc;
    }
  }
LAB_0010cc90:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",2,
               "s",__pyx_nargs);
  iVar8 = 0xdf8;
  goto LAB_0010cccc;
  while( true ) {
    pPVar2 = &pPVar28->ob_refcnt;
    pPVar28 = (PyObject *)((long)pPVar2 + 1);
    if (pPVar28 == pPVar31) goto LAB_0010e030;
    p_Var25 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[(long)pPVar2];
    if ((_typeobject *)pPVar11 == p_Var25) break;
LAB_0010d0e0:
    bVar6 = pPVar11->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var25->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar11 != (PyObject *)puVar3) && (bVar6 || p_Var25 != (_typeobject *)puVar3)) {
        plVar14 = (long *)PyObject_RichCompare(pPVar11,p_Var25,2);
        if (plVar14 == (long *)0x0) goto LAB_0010e030;
        uVar19 = (uint)(plVar14 == (long *)puVar4);
        if ((plVar14 != (long *)puVar4 && plVar14 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar14 != (long *)puVar3) {
          uVar19 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = *plVar14;
        *plVar14 = lVar24 + -1;
        if (lVar24 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_0010e020:
        if (uVar19 != 0) {
          if ((int)uVar19 < 0) goto LAB_0010e030;
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
         ((-1 < (char)p_Var25->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var25), iVar8 < 0))))
      goto LAB_0010e030;
      lVar24 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar24 == (p_Var25->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var25->tp_name ||
          (_typeobject *)p_Var25->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar18 = (char *)((ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7);
        uVar19 = (uint)pcVar18;
        if (((byte)((byte)p_Var25->tp_basicsize >> 2) & 7) == uVar19) {
          bVar1 = (byte)pPVar11[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            p_Var27 = pPVar11[4].ob_type;
          }
          else {
            p_Var27 = (_typeobject *)&pPVar11[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              p_Var27 = (_typeobject *)(pPVar11 + 3);
            }
          }
          bVar1 = (byte)p_Var25->tp_basicsize;
          if ((bVar1 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var25->tp_setattr;
          }
          else {
            __s2 = &p_Var25->tp_setattr;
            if ((bVar1 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var25->tp_dealloc;
            }
          }
          if (uVar19 == 1) {
            uVar19 = (uint)(byte)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(byte *)__s2;
          }
          else if (uVar19 == 2) {
            uVar19 = (uint)(ushort)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar21 = (uint)*(ushort *)__s2;
          }
          else {
            uVar19 = (uint)(p_Var27->ob_base).ob_base.ob_refcnt;
            uVar21 = *(uint *)__s2;
          }
          if (uVar21 == uVar19) {
            if (lVar24 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var27,__s2,(long)pcVar18 * lVar24);
              uVar19 = (uint)(iVar8 == 0);
              goto LAB_0010e020;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar12[(long)pPVar28];
LAB_0010df7c:
  if (values[1] != (PyObject *)0x0) {
    puVar10 = (undefined1 *)((long)&pPVar22[-1].ob_type + 7);
LAB_0010d044:
    if (0 < (long)puVar10) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar22 = (PyObject *)values;
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,ppPVar12,__pyx_pyargnames,pPVar22,(PyObject **)__pyx_nargs,
                         0x11d058,pcVar18);
      if (iVar8 < 0) {
        iVar8 = 0xdeb;
        goto LAB_0010cccc;
      }
    }
LAB_0010cd2c:
                    /* Unresolved local var: PyObject * __pyx_v_gcode@[???]
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
    pPVar11 = values[1];
    pPVar31 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var15 = values[1]->ob_type->tp_getattro;
    if (p_Var15 == (getattrofunc)0x0) {
      pPVar28 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar28 = (*p_Var15)(values[1],__pyx_mstate_global_static.__pyx_n_s_get_printer);
    }
    if (pPVar28 == (PyObject *)0x0) {
      __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xe29,0x1b,"aht20_f.py");
      pPVar22 = (PyObject *)0x0;
      goto LAB_0010cce8;
    }
    p_Var25 = pPVar28->ob_type;
    if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var27 = pPVar28[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar29 = (PyObject *)pPVar28[1].ob_refcnt;
      (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
      pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*p_Var25->tp_dealloc)(pPVar28);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var27;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar29,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
      (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
      pPVar28 = pPVar29;
      if (lVar24 == 0) {
        (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar28,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22);
    }
    if (pPVar9 == (PyObject *)0x0) {
      iVar30 = 0x1b;
      iVar8 = 0xe3d;
LAB_0010e298:
      pPVar22 = (PyObject *)0x0;
      pPVar29 = (PyObject *)0x0;
LAB_0010e14c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9 = (PyObject *)0x0;
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
LAB_0010e1fc:
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
LAB_0010e160:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (pPVar29 != (PyObject *)0x0) {
LAB_0010e164:
        lVar24 = pPVar29->ob_refcnt + -1;
        goto LAB_0010e16c;
      }
LAB_0010e174:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (pPVar22 != (PyObject *)0x0) {
LAB_0010e178:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar22->ob_refcnt + -1;
        pPVar22->ob_refcnt = lVar24;
        if (lVar24 == 0) {
LAB_0010e188:
          (*pPVar22->ob_type->tp_dealloc)(pPVar22);
        }
      }
LAB_0010e198:
      pPVar22 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",iVar8,iVar30,"aht20_f.py");
      if (pPVar9 == (PyObject *)0x0) goto LAB_0010cce8;
    }
    else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      pPVar22 = (PyObject *)pPVar31->ob_type->tp_setattro;
      if (pPVar22 == (PyObject *)0x0) {
        iVar8 = PyObject_SetAttr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_printer,pPVar9);
      }
      else {
        iVar8 = (*(code *)pPVar22)();
      }
      lVar24 = pPVar9->ob_refcnt + -1;
      if (iVar8 < 0) {
        iVar8 = 0xe41;
        iVar30 = 0x1b;
        goto LAB_0010e124;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar11->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar29 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar29 = (*p_Var15)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_get_name);
      }
      if (pPVar29 == (PyObject *)0x0) {
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xe4b,0x1c,"aht20_f.py");
        pPVar22 = (PyObject *)0x0;
        goto LAB_0010cce8;
      }
      p_Var25 = pPVar29->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar9 = (PyObject *)pPVar29[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar29);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        pPVar28 = __Pyx_PyObject_FastCallDict(pPVar9,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar29 = pPVar9;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar28 = __Pyx_PyObject_FastCallDict(pPVar29,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22)
        ;
      }
      if (pPVar28 == (PyObject *)0x0) {
        iVar30 = 0x1c;
        iVar8 = 0xe5f;
        goto LAB_0010e218;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar28->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar29 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar29 = (*p_Var15)(pPVar28,__pyx_mstate_global_static.__pyx_n_s_split);
      }
      lVar24 = pPVar28->ob_refcnt + -1;
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x1c;
        iVar8 = 0xe63;
        goto LAB_0010e1e8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
      p_Var25 = pPVar29->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar28 = (PyObject *)pPVar29[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar28->ob_refcnt = pPVar28->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar29);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        pPVar9 = __Pyx_PyObject_FastCallDict(pPVar28,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar29 = pPVar28;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar9 = __Pyx_PyObject_FastCallDict(pPVar29,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22);
      }
      if (pPVar9 == (PyObject *)0x0) {
        iVar30 = 0x1c;
        iVar8 = 0xe78;
        goto LAB_0010e218;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
        p_Var25 = pPVar9->ob_type;
        if (p_Var25 == (_typeobject *)PTR_PyList_Type_0012ffe0) goto LAB_0010d20c;
LAB_0010cfc4:
        if (p_Var25 != (_typeobject *)PTR_PyTuple_Type_0012feb8) {
                    /* Unresolved local var: PyMappingMethods * mm@[???]
                       Unresolved local var: PySequenceMethods * sm@[???] */
          pPVar23 = p_Var25->tp_as_mapping;
          if ((pPVar23 == (PyMappingMethods *)0x0) || (pPVar23->mp_subscript == (binaryfunc)0x0)) {
            pPVar26 = p_Var25->tp_as_sequence;
            if ((pPVar26 == (PySequenceMethods *)0x0) ||
               (p_Var16 = pPVar26->sq_item, p_Var16 == (ssizeargfunc)0x0)) goto LAB_0010e458;
            if (pPVar26->sq_length == (lenfunc)0x0) {
              PVar13 = -1;
            }
            else {
                    /* Unresolved local var: Py_ssize_t l@[???] */
              PVar13 = (*pPVar26->sq_length)(pPVar9);
              if (PVar13 < 0) {
                iVar8 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_OverflowError_0012ff40);
                if (iVar8 == 0) goto LAB_0010e644;
                PyErr_Clear();
                PVar13 = -1;
                p_Var16 = pPVar26->sq_item;
              }
              else {
                p_Var16 = pPVar26->sq_item;
                PVar13 = PVar13 + -1;
              }
            }
            pPVar29 = (*p_Var16)(pPVar9,PVar13);
          }
          else {
                    /* Unresolved local var: PyObject * r@[???]
                       Unresolved local var: PyObject * key@[???] */
            pPVar22 = (PyObject *)PyLong_FromSsize_t(0xffffffffffffffff);
            if (pPVar22 == (PyObject *)0x0) goto LAB_0010e644;
            pPVar29 = (*pPVar23->mp_subscript)(pPVar9,pPVar22);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar24 = pPVar22->ob_refcnt + -1;
            pPVar22->ob_refcnt = lVar24;
            if (lVar24 == 0) {
              (*pPVar22->ob_type->tp_dealloc)(pPVar22);
            }
          }
          goto LAB_0010d018;
        }
                    /* Unresolved local var: Py_ssize_t n@[???] */
        if (pPVar9[1].ob_refcnt == 0) goto LAB_0010e458;
                    /* Unresolved local var: PyObject * r@[???] */
        pPVar29 = (PyObject *)(&pPVar9[1].ob_refcnt)[pPVar9[1].ob_refcnt];
LAB_0010d26c:
        pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
        lVar24 = pPVar9->ob_refcnt + -1;
      }
      else {
        p_Var25 = pPVar9->ob_type;
        if (p_Var25 != (_typeobject *)PTR_PyList_Type_0012ffe0) goto LAB_0010cfc4;
LAB_0010d20c:
                    /* Unresolved local var: Py_ssize_t n@[???] */
        if (pPVar9[1].ob_refcnt != 0) {
                    /* Unresolved local var: PyObject * r@[???] */
          pPVar29 = *(PyObject **)((long)pPVar9[1].ob_type + (pPVar9[1].ob_refcnt + -1) * 8);
          goto LAB_0010d26c;
        }
LAB_0010e458:
        plVar14 = (long *)PyLong_FromSsize_t(0xffffffffffffffff);
                    /* Unresolved local var: PyObject * r@[???] */
        if (plVar14 == (long *)0x0) {
LAB_0010e644:
          iVar8 = 0xe7c;
          iVar30 = 0x1c;
          lVar24 = pPVar9->ob_refcnt + -1;
          goto LAB_0010e124;
        }
        pPVar29 = (PyObject *)PyObject_GetItem(pPVar9,plVar14);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = *plVar14;
        *plVar14 = lVar24 + -1;
        if (lVar24 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
LAB_0010d018:
        lVar24 = pPVar9->ob_refcnt + -1;
        if (pPVar29 == (PyObject *)0x0) {
          iVar8 = 0xe7c;
          iVar30 = 0x1c;
          goto LAB_0010e124;
        }
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      pPVar22 = (PyObject *)pPVar31->ob_type->tp_setattro;
      if (pPVar22 == (PyObject *)0x0) {
        iVar8 = PyObject_SetAttr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_name,pPVar29);
      }
      else {
        iVar8 = (*(code *)pPVar22)();
      }
      if (iVar8 < 0) {
        iVar30 = 0x1c;
        iVar8 = 0xe7f;
        goto LAB_0010e218;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar31->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar9 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar9 = (*p_Var15)(pPVar31,__pyx_mstate_global_static.__pyx_n_s_printer);
      }
      if (pPVar9 == (PyObject *)0x0) {
        iVar8 = 0xe89;
        iVar30 = 0x1d;
LAB_0010e398:
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",iVar8,iVar30,"aht20_f.py");
        goto LAB_0010cce8;
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar9->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar28 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar28 = (*p_Var15)(pPVar9,__pyx_mstate_global_static.__pyx_n_s_get_reactor);
      }
      lVar24 = pPVar9->ob_refcnt + -1;
      if (pPVar28 == (PyObject *)0x0) {
        iVar8 = 0xe8b;
        iVar30 = 0x1d;
        goto LAB_0010e124;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
      p_Var25 = pPVar28->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar28[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar9 = (PyObject *)pPVar28[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar28->ob_refcnt + -1;
        pPVar28->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar28);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        pPVar29 = __Pyx_PyObject_FastCallDict(pPVar9,(PyObject **)__pyx_pyargnames,1,pPVar22);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar28 = pPVar9;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar29 = __Pyx_PyObject_FastCallDict(pPVar28,(PyObject **)(__pyx_pyargnames + 1),0,pPVar22)
        ;
      }
      lVar24 = pPVar28->ob_refcnt + -1;
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x1d;
        iVar8 = 0xea0;
        goto LAB_0010e1e8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var17 = pPVar31->ob_type->tp_setattro;
      if (p_Var17 == (setattrofunc)0x0) {
        iVar8 = PyObject_SetAttr();
      }
      else {
        iVar8 = (*p_Var17)(pPVar31,__pyx_mstate_global_static.__pyx_n_s_reactor,pPVar29);
      }
      lVar24 = pPVar29->ob_refcnt + -1;
      if (iVar8 < 0) {
        pPVar9 = (PyObject *)0x0;
        iVar30 = 0x1d;
        iVar8 = 0xea4;
        pPVar22 = (PyObject *)0x0;
LAB_0010e16c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar29->ob_refcnt = lVar24;
        if (lVar24 == 0) {
LAB_0010e230:
          (*pPVar29->ob_type->tp_dealloc)(pPVar29);
        }
        goto LAB_0010e174;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      pPVar29 = __pyx_dict_cached_value_16353;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16352) {
        if (__pyx_dict_cached_value_16353 == (PyObject *)0x0) {
          pPVar29 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_bus);
          goto LAB_0010e578;
        }
        __pyx_dict_cached_value_16353->ob_refcnt = __pyx_dict_cached_value_16353->ob_refcnt + 1;
      }
      else {
        pPVar29 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_bus,
                             (uint64_t *)&__pyx_dict_version_16352,&__pyx_dict_cached_value_16353);
LAB_0010e578:
        if (pPVar29 == (PyObject *)0x0) {
          pPVar22 = (PyObject *)0x0;
          __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xeae,0x1e,"aht20_f.py");
          goto LAB_0010cce8;
        }
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var15 = pPVar29->ob_type->tp_getattro;
      if (p_Var15 == (getattrofunc)0x0) {
        pPVar28 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar28 = (*p_Var15)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_MCU_I2C_from_config);
      }
      lVar24 = pPVar29->ob_refcnt + -1;
      if (pPVar28 == (PyObject *)0x0) {
        pPVar9 = (PyObject *)0x0;
        pPVar22 = (PyObject *)0x0;
        iVar30 = 0x1e;
        iVar8 = 0xeb0;
        goto LAB_0010e16c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      pPVar29 = (PyObject *)PyTuple_New(1);
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x1e;
        iVar8 = 0xebb;
        lVar24 = pPVar28->ob_refcnt + -1;
        goto LAB_0010e1e8;
      }
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
      pPVar29[1].ob_type = (_typeobject *)pPVar11;
      pPVar9 = (PyObject *)PyDict_New();
      pPVar22 = __pyx_dict_cached_value_16356;
      if (pPVar9 == (PyObject *)0x0) {
        pPVar22 = (PyObject *)0x0;
        iVar30 = 0x1f;
        iVar8 = 0xec0;
        lVar24 = pPVar28->ob_refcnt + -1;
        pPVar28->ob_refcnt = lVar24;
joined_r0x0010e610:
        pPVar9 = (PyObject *)0x0;
        if (lVar24 == 0) goto LAB_0010e1fc;
        goto LAB_0010e164;
      }
      kwargs = &__pyx_mstate_global_static;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_16355) {
        pPVar22 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_I2C_ADDR,
                             (uint64_t *)&__pyx_dict_version_16355,&__pyx_dict_cached_value_16356);
LAB_0010e62c:
        if (pPVar22 != (PyObject *)0x0) goto LAB_0010d504;
        iVar8 = 0xec2;
        iVar30 = 0x1f;
        lVar24 = pPVar9->ob_refcnt + -1;
LAB_0010e514:
        pPVar9->ob_refcnt = lVar24;
        if (lVar24 == 0) {
LAB_0010e138:
          (*pPVar9->ob_type->tp_dealloc)(pPVar9);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (pPVar28 != (PyObject *)0x0) goto LAB_0010e14c;
          pPVar9 = (PyObject *)0x0;
          goto LAB_0010e160;
        }
        lVar24 = pPVar28->ob_refcnt + -1;
        pPVar28->ob_refcnt = lVar24;
        goto joined_r0x0010e610;
      }
      if (__pyx_dict_cached_value_16356 == (PyObject *)0x0) {
        pPVar22 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_I2C_ADDR);
        goto LAB_0010e62c;
      }
      __pyx_dict_cached_value_16356->ob_refcnt = __pyx_dict_cached_value_16356->ob_refcnt + 1;
LAB_0010d504:
      iVar8 = PyDict_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_default_addr,pPVar22);
      if (iVar8 < 0) {
        iVar8 = 0xec4;
        iVar30 = 0x1f;
        lVar24 = pPVar9->ob_refcnt + -1;
        goto LAB_0010e514;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      iVar8 = PyDict_SetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_default_speed,
                             __pyx_mstate_global_static.__pyx_int_100000);
      if (iVar8 < 0) {
        iVar8 = 0xec6;
        iVar30 = 0x1f;
        pPVar22 = (PyObject *)0x0;
        lVar24 = pPVar9->ob_refcnt + -1;
        goto LAB_0010e514;
      }
      pPVar22 = __Pyx_PyObject_Call(pPVar28,pPVar29,pPVar9);
      if (pPVar22 == (PyObject *)0x0) {
        iVar8 = 0xecf;
        iVar30 = 0x1e;
        lVar24 = pPVar9->ob_refcnt + -1;
        goto LAB_0010e514;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_i2c,pPVar22);
      if (iVar8 < 0) {
        iVar30 = 0x1e;
        iVar8 = 0xed4;
        goto LAB_0010e690;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      pPVar9 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_i2c);
      if (pPVar9 == (PyObject *)0x0) {
        iVar8 = 0xede;
        iVar30 = 0x20;
        goto LAB_0010e398;
      }
      pPVar29 = __Pyx_PyObject_GetAttrStr(pPVar9,__pyx_mstate_global_static.__pyx_n_s_get_mcu);
      if (pPVar29 == (PyObject *)0x0) {
        iVar8 = 0xee0;
        iVar30 = 0x20;
        lVar24 = pPVar9->ob_refcnt + -1;
LAB_0010e124:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar9->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          pPVar22 = (PyObject *)0x0;
          pPVar29 = (PyObject *)0x0;
          pPVar28 = (PyObject *)0x0;
          goto LAB_0010e138;
        }
        pPVar9 = (PyObject *)0x0;
        goto LAB_0010e198;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
      p_Var25 = pPVar29->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar28 = (PyObject *)pPVar29[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar28->ob_refcnt = pPVar28->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar29);
        }
        __pyx_pyargnames[1] = (PyObject **)0x0;
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        pPVar22 = __Pyx_PyObject_FastCallDict
                            (pPVar28,(PyObject **)__pyx_pyargnames,1,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar29 = pPVar28;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)0x0;
        pPVar22 = __Pyx_PyObject_FastCallDict
                            (pPVar29,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)kwargs);
      }
      if (pPVar22 == (PyObject *)0x0) {
        iVar30 = 0x20;
        iVar8 = 0xef5;
        goto LAB_0010e218;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_mcu,pPVar22);
      if (iVar8 < 0) {
        iVar30 = 0x20;
        iVar8 = 0xef9;
LAB_0010e690:
        pPVar9 = (PyObject *)0x0;
        lVar24 = pPVar22->ob_refcnt + -1;
        pPVar22->ob_refcnt = lVar24;
        if (lVar24 != 0) goto LAB_0010e398;
        goto LAB_0010e188;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      pPVar22 = __Pyx_PyObject_GetAttrStr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_getfloat);
      if (pPVar22 == (PyObject *)0x0) {
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf03,0x22,"aht20_f.py");
        pPVar22 = (PyObject *)0x0;
        goto LAB_0010cce8;
      }
      pPVar29 = (PyObject *)PyDict_New();
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x22;
        iVar8 = 0xf05;
        goto LAB_0010e690;
      }
      iVar8 = PyDict_SetItem(pPVar29,__pyx_mstate_global_static.__pyx_n_s_minval,
                             __pyx_mstate_global_static.__pyx_float_0_1);
      if (iVar8 < 0) {
        pPVar9 = (PyObject *)0x0;
        iVar30 = 0x22;
        iVar8 = 0xf07;
        lVar24 = pPVar29->ob_refcnt + -1;
        goto LAB_0010e16c;
      }
      pPVar9 = __Pyx_PyObject_Call(pPVar22,__pyx_mstate_global_static.__pyx_tuple_,pPVar29);
      if (pPVar9 == (PyObject *)0x0) {
        iVar30 = 0x22;
        iVar8 = 0xf08;
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar9 = (PyObject *)0x0;
        goto LAB_0010e16c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_report_time,pPVar9);
      if (iVar8 < 0) {
        iVar8 = 0xf0c;
        iVar30 = 0x22;
        lVar24 = pPVar9->ob_refcnt + -1;
        goto LAB_0010e124;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_temp,
                         __pyx_mstate_global_static.__pyx_float_0_);
      if (iVar8 < 0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf16,0x23,"aht20_f.py");
        goto LAB_0010cce8;
      }
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_min_temp,
                         __pyx_mstate_global_static.__pyx_float_0_);
      if (iVar8 < 0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf17,0x23,"aht20_f.py");
        goto LAB_0010cce8;
      }
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_max_temp,
                         __pyx_mstate_global_static.__pyx_float_0_);
      if (iVar8 < 0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf18,0x23,"aht20_f.py");
        goto LAB_0010cce8;
      }
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_humidity,
                         __pyx_mstate_global_static.__pyx_float_0_);
      if (iVar8 < 0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf19,0x23,"aht20_f.py");
        goto LAB_0010cce8;
      }
      pPVar29 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_reactor);
      if (pPVar29 == (PyObject *)0x0) {
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf22,0x24,"aht20_f.py");
        goto LAB_0010cce8;
      }
      pPVar22 = __Pyx_PyObject_GetAttrStr
                          (pPVar29,__pyx_mstate_global_static.__pyx_n_s_register_timer);
      if (pPVar22 == (PyObject *)0x0) {
        pPVar9 = (PyObject *)0x0;
        iVar30 = 0x24;
        iVar8 = 0xf24;
        lVar24 = pPVar29->ob_refcnt + -1;
        goto LAB_0010e16c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      pPVar11 = __Pyx_PyObject_GetAttrStr
                          (pPVar31,__pyx_mstate_global_static.__pyx_n_s_sample_aht20_f);
      if (pPVar11 == (PyObject *)0x0) {
        iVar30 = 0x24;
        iVar8 = 0xf27;
        goto LAB_0010e690;
      }
      p_Var25 = pPVar22->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar22[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar28 = (PyObject *)pPVar22[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar28->ob_refcnt = pPVar28->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar22->ob_refcnt + -1;
        pPVar22->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar22);
        }
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        __pyx_pyargnames[1] = (PyObject **)pPVar11;
        pPVar9 = __Pyx_PyObject_FastCallDict
                           (pPVar28,(PyObject **)__pyx_pyargnames,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar22 = pPVar28;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)pPVar11;
        pPVar9 = __Pyx_PyObject_FastCallDict
                           (pPVar22,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)kwargs);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      if (pPVar9 == (PyObject *)0x0) {
        iVar8 = 0xf3c;
        iVar30 = 0x24;
        pPVar9 = (PyObject *)0x0;
        goto LAB_0010e178;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_sample_timer,pPVar9);
      if (iVar8 < 0) {
        iVar8 = 0xf40;
        iVar30 = 0x24;
        lVar24 = pPVar9->ob_refcnt + -1;
        goto LAB_0010e124;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
      pPVar22 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_printer);
      if (pPVar22 == (PyObject *)0x0) {
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf4a,0x25,"aht20_f.py");
        pPVar22 = (PyObject *)0x0;
        goto LAB_0010cce8;
      }
      pPVar29 = __Pyx_PyObject_GetAttrStr(pPVar22,__pyx_mstate_global_static.__pyx_n_s_add_object);
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x25;
        iVar8 = 0xf4c;
        goto LAB_0010e690;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      pPVar22 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_name);
      if (pPVar22 == (PyObject *)0x0) {
        pPVar9 = (PyObject *)0x0;
        iVar30 = 0x25;
        iVar8 = 0xf4f;
        lVar24 = pPVar29->ob_refcnt + -1;
        goto LAB_0010e16c;
      }
      ppPVar12 = (PyObject **)PyNumber_Add(__pyx_mstate_global_static.__pyx_kp_s_aht20_f,pPVar22);
      if (ppPVar12 == (PyObject **)0x0) {
        iVar30 = 0x25;
        iVar8 = 0xf51;
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar9 = (PyObject *)0x0;
        goto LAB_0010e16c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      p_Var25 = pPVar29->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar11 = (PyObject *)pPVar29[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar29);
        }
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        __pyx_pyargnames[1] = ppPVar12;
        __pyx_pyargnames[2] = (PyObject **)pPVar31;
        pPVar22 = __Pyx_PyObject_FastCallDict
                            (pPVar11,(PyObject **)__pyx_pyargnames,3,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar29 = pPVar11;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = ppPVar12;
        __pyx_pyargnames[2] = (PyObject **)pPVar31;
        pPVar22 = __Pyx_PyObject_FastCallDict
                            (pPVar29,(PyObject **)(__pyx_pyargnames + 1),2,(PyObject *)kwargs);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar11 = (PyObject *)((long)&(*ppPVar12)[-1].ob_type + 7);
      *ppPVar12 = pPVar11;
      if (pPVar11 == (PyObject *)0x0) {
        (*(code *)ppPVar12[1][3].ob_refcnt)(ppPVar12);
      }
      if (pPVar22 == (PyObject *)0x0) {
        iVar30 = 0x25;
        iVar8 = 0xf67;
LAB_0010e218:
        pPVar9 = (PyObject *)0x0;
LAB_0010e21c:
        lVar24 = pPVar29->ob_refcnt;
LAB_0010e224:
        pPVar29->ob_refcnt = lVar24 + -1;
        pPVar22 = (PyObject *)0x0;
        if (lVar24 + -1 != 0) goto LAB_0010e198;
        goto LAB_0010e230;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      pPVar29 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_printer);
      if (pPVar29 == (PyObject *)0x0) {
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xf74,0x26,"aht20_f.py");
        pPVar22 = (PyObject *)0x0;
        goto LAB_0010cce8;
      }
      pPVar28 = __Pyx_PyObject_GetAttrStr
                          (pPVar29,__pyx_mstate_global_static.__pyx_n_s_register_event_handler);
      if (pPVar28 == (PyObject *)0x0) {
        iVar30 = 0x26;
        iVar8 = 0xf76;
        pPVar22 = (PyObject *)0x0;
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar9 = (PyObject *)0x0;
        goto LAB_0010e16c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      pPVar22 = __Pyx_PyObject_GetAttrStr
                          (pPVar31,__pyx_mstate_global_static.__pyx_n_s_handle_connect);
      if (pPVar22 == (PyObject *)0x0) {
        iVar30 = 0x27;
        iVar8 = 0xf81;
        lVar24 = pPVar28->ob_refcnt + -1;
LAB_0010e1e8:
        pPVar28->ob_refcnt = lVar24;
        if (lVar24 != 0) goto LAB_0010e398;
        pPVar9 = (PyObject *)0x0;
        pPVar22 = (PyObject *)0x0;
        pPVar29 = (PyObject *)0x0;
        goto LAB_0010e1fc;
      }
      p_Var25 = pPVar28->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar28[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar9 = (PyObject *)pPVar28[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar28->ob_refcnt + -1;
        pPVar28->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar28);
        }
        __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_klippy_connect;
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        __pyx_pyargnames[2] = (PyObject **)pPVar22;
        pPVar11 = __Pyx_PyObject_FastCallDict
                            (pPVar9,(PyObject **)__pyx_pyargnames,3,
                             __pyx_mstate_global_static.__pyx_kp_s_klippy_connect);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar28 = pPVar9;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_klippy_connect;
        __pyx_pyargnames[2] = (PyObject **)pPVar22;
        pPVar11 = __Pyx_PyObject_FastCallDict
                            (pPVar28,(PyObject **)(__pyx_pyargnames + 1),2,
                             __pyx_mstate_global_static.__pyx_kp_s_klippy_connect);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar30 = 0x26;
        iVar8 = 0xf96;
        goto LAB_0010e298;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      pPVar28 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_printer);
      if (pPVar28 == (PyObject *)0x0) {
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",0xfa3,0x28,"aht20_f.py");
        pPVar22 = (PyObject *)0x0;
        goto LAB_0010cce8;
      }
      pPVar29 = __Pyx_PyObject_GetAttrStr
                          (pPVar28,__pyx_mstate_global_static.__pyx_n_s_lookup_object);
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x28;
        iVar8 = 0xfa5;
        lVar24 = pPVar28->ob_refcnt + -1;
        goto LAB_0010e1e8;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
      p_Var25 = pPVar29->ob_type;
      if ((p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar22 = (PyObject *)pPVar29[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar22->ob_refcnt = pPVar22->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar24;
        if (lVar24 == 0) {
          (*p_Var25->tp_dealloc)(pPVar29);
        }
        __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_gcode;
        __pyx_pyargnames[0] = (PyObject **)p_Var27;
        pPVar9 = __Pyx_PyObject_FastCallDict
                           (pPVar22,(PyObject **)__pyx_pyargnames,2,
                            __pyx_mstate_global_static.__pyx_n_s_gcode);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar24;
        pPVar29 = pPVar22;
        if (lVar24 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_pyargnames[0] = (PyObject **)0x0;
        __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_gcode;
        pPVar9 = __Pyx_PyObject_FastCallDict
                           (pPVar29,(PyObject **)(__pyx_pyargnames + 1),1,
                            __pyx_mstate_global_static.__pyx_n_s_gcode);
      }
      if (pPVar9 == (PyObject *)0x0) {
        iVar30 = 0x28;
        iVar8 = 0xfba;
        goto LAB_0010e218;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
      iVar8 = __Pyx_PyObject_SetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_gcode,pPVar9);
      if (iVar8 < 0) {
        iVar8 = 0xfbe;
        iVar30 = 0x28;
        lVar24 = pPVar9->ob_refcnt + -1;
        goto LAB_0010e124;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if (pPVar9->ob_refcnt == 0) {
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
      }
      pPVar29 = __Pyx_PyObject_GetAttrStr
                          (pPVar9,__pyx_mstate_global_static.__pyx_n_s_register_mux_command);
      if (pPVar29 == (PyObject *)0x0) {
        iVar30 = 0x29;
        iVar8 = 0xfca;
        goto LAB_0010e9ec;
      }
      pPVar28 = __Pyx_PyObject_GetAttrStr(pPVar31,__pyx_mstate_global_static.__pyx_n_s_name);
      if (pPVar28 == (PyObject *)0x0) {
        pPVar22 = (PyObject *)0x0;
        iVar30 = 0x2a;
        iVar8 = 0xfd4;
        lVar24 = pPVar29->ob_refcnt + -1;
        goto LAB_0010e16c;
      }
      pPVar22 = __Pyx_PyObject_GetAttrStr
                          (pPVar31,__pyx_mstate_global_static.__pyx_n_s_cmd_READ_TEMP_RH);
      if (pPVar22 == (PyObject *)0x0) {
        lVar24 = pPVar28->ob_refcnt + -1;
        pPVar28->ob_refcnt = lVar24;
        if (lVar24 != 0) {
          lVar24 = pPVar29->ob_refcnt;
          iVar30 = 0x2a;
          iVar8 = 0xfd6;
          goto LAB_0010e224;
        }
        iVar30 = 0x2a;
        iVar8 = 0xfd6;
        pPVar22 = (PyObject *)0x0;
        goto LAB_0010e1fc;
      }
      p_Var25 = pPVar29->ob_type;
      if (p_Var25 == (_typeobject *)PTR_PyMethod_Type_0012fea0) {
        p_Var27 = pPVar29[1].ob_type;
        if (p_Var27 == (_typeobject *)0x0) {
          lVar24 = 0;
        }
        else {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar11 = (PyObject *)pPVar29[1].ob_refcnt;
          (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
          pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar24 = pPVar29->ob_refcnt + -1;
          pPVar29->ob_refcnt = lVar24;
          if (lVar24 == 0) {
            (*p_Var25->tp_dealloc)(pPVar29);
            lVar24 = 1;
            pPVar29 = pPVar11;
          }
          else {
            lVar24 = 1;
            pPVar29 = pPVar11;
          }
        }
      }
      else {
        p_Var27 = (_typeobject *)0x0;
        lVar24 = 0;
      }
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_BOX_TEMP_READ;
      __pyx_pyargnames[2] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_INDEX;
      __pyx_pyargnames[0] = (PyObject **)p_Var27;
      pPVar11 = __Pyx_PyObject_FastCallDict
                          (pPVar29,(PyObject **)(__pyx_pyargnames + (1 - lVar24)),
                           (ulong)((int)lVar24 + 4),__pyx_mstate_global_static.__pyx_n_s_INDEX);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((p_Var27 != (_typeobject *)0x0) &&
         (lVar24 = (p_Var27->ob_base).ob_base.ob_refcnt + -1,
         (p_Var27->ob_base).ob_base.ob_refcnt = lVar24, lVar24 == 0)) {
        (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar28->ob_refcnt + -1;
      pPVar28->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar28->ob_type->tp_dealloc)(pPVar28);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar22->ob_refcnt + -1;
      pPVar22->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar22->ob_type->tp_dealloc)(pPVar22);
      }
      if (pPVar11 == (PyObject *)0x0) {
        iVar8 = 0xfec;
        iVar30 = 0x29;
        goto LAB_0010e21c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar29->ob_type->tp_dealloc)(pPVar29);
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar24 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar24;
      if (lVar24 == 0) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
      puVar3 = PTR__Py_FalseStruct_0012ff20;
      iVar8 = __Pyx_PyObject_SetAttrStr
                        (pPVar31,__pyx_mstate_global_static.__pyx_n_s_is_calibrated,
                         (PyObject *)PTR__Py_FalseStruct_0012ff20);
      if (iVar8 < 0) {
        iVar30 = 0x2b;
        iVar8 = 0xff9;
LAB_0010e9ec:
        pPVar22 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",iVar8,iVar30,"aht20_f.py");
      }
      else {
        iVar8 = __Pyx_PyObject_SetAttrStr
                          (pPVar31,__pyx_mstate_global_static.__pyx_n_s_init_sent,(PyObject *)puVar3
                          );
        pPVar22 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
        if (iVar8 < 0) {
          iVar30 = 0x2c;
          iVar8 = 0x1002;
          goto LAB_0010e9ec;
        }
        *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      }
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar24 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar24;
    if (lVar24 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
    goto LAB_0010cce8;
  }
LAB_0010e034:
  lVar24 = PyErr_Occurred();
  if (lVar24 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","__init__","exactly",
                 2,"s",1);
    iVar8 = 0xde6;
  }
  else {
    iVar8 = 0xde4;
  }
LAB_0010cccc:
  pPVar22 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.__init__",iVar8,0x1a,"aht20_f.py");
LAB_0010cce8:
  if (lVar20 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar22;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010eaf0
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_7setup_callback
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_7setup_callback(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_7setup_callback
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
  _typeobject *__s1;
  long *plVar10;
  setattrfunc *__s2;
  long lVar11;
  long lVar12;
  setattrofunc p_Var13;
  char *pcVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  long lVar18;
  long lVar19;
  _typeobject *p_Var20;
  long lVar21;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_cb@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar16 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_cb;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs != 2) goto LAB_0010eb60;
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
LAB_0010ed6c:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var13 = values[0]->ob_type->tp_setattro;
    if (p_Var13 == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var13)(values[0],__pyx_mstate_global_static.__pyx_n_s_callback,values[1]);
    }
    pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
    if (iVar8 < 0) {
      __Pyx_AddTraceback("extras.aht20_f.AHT20_F.setup_callback",0x1235,0x37,"aht20_f.py");
      pPVar9 = (PyObject *)0x0;
    }
    else {
      *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
    }
    goto LAB_0010ebb8;
  }
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
  kwvalues = __pyx_args + __pyx_nargs;
  pcVar14 = PTR___stack_chk_guard_0012ff30;
  if (__pyx_nargs != 1) {
    if (__pyx_nargs == 2) {
      values[0] = *__pyx_args;
      values[1] = __pyx_args[1];
      lVar18 = __pyx_kwds[1].ob_refcnt;
      goto LAB_0010edb8;
    }
    if (__pyx_nargs == 0) {
      lVar18 = __pyx_kwds[1].ob_refcnt;
      values[0] = __Pyx_GetKwValue_FASTCALL
                            (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
      if (values[0] != (PyObject *)0x0) {
        lVar11 = __pyx_kwds[1].ob_refcnt;
        lVar18 = lVar18 + -1;
        goto LAB_0010ec10;
      }
      lVar18 = PyErr_Occurred();
      if (lVar18 != 0) {
        iVar8 = 0x11ef;
        goto LAB_0010eb9c;
      }
    }
LAB_0010eb60:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_callback",
                 "exactly",2,"s",__pyx_nargs);
    iVar8 = 0x120b;
    goto LAB_0010eb9c;
  }
  lVar11 = __pyx_kwds[1].ob_refcnt;
  values[0] = *__pyx_args;
  lVar18 = lVar11;
LAB_0010ec10:
  pPVar9 = __pyx_mstate_global_static.__pyx_n_s_cb;
  puVar5 = PTR_PyUnicode_Type_0012ffb0;
  puVar4 = PTR__Py_TrueStruct_0012ff58;
  puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
  if (0 < lVar11) {
    p_Var20 = __pyx_kwds[1].ob_type;
    if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_cb == p_Var20) {
      values[1] = *kwvalues;
    }
    else {
      lVar21 = 0;
      do {
        lVar19 = lVar21 + 1;
        if (lVar11 == lVar19) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
          lVar11 = 0;
          goto LAB_0010ec78;
        }
        pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar21;
        lVar21 = lVar19;
      } while (__pyx_mstate_global_static.__pyx_n_s_cb != (PyObject *)*pPVar1);
      values[1] = kwvalues[lVar19];
    }
    goto LAB_0010edf0;
  }
LAB_0010eeac:
  values[1] = (PyObject *)0x0;
LAB_0010eeb0:
  lVar18 = PyErr_Occurred();
  if (lVar18 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_callback",
                 "exactly",2,"s",1);
    iVar8 = 0x11f9;
  }
  else {
    iVar8 = 0x11f7;
  }
  goto LAB_0010eb9c;
  while( true ) {
    lVar19 = lVar11 + 1;
    if (lVar11 == lVar21) goto LAB_0010eeac;
    p_Var20 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar19;
    if ((_typeobject *)pPVar9 == p_Var20) break;
LAB_0010ec78:
    bVar6 = pPVar9->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var20->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar19 = lVar11;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar9 != (PyObject *)puVar3) && (bVar6 || p_Var20 != (_typeobject *)puVar3)) {
        plVar10 = (long *)PyObject_RichCompare(pPVar9,p_Var20,2);
        if (plVar10 == (long *)0x0) goto LAB_0010eeac;
        uVar15 = (uint)(plVar10 == (long *)puVar4);
        if ((plVar10 != (long *)puVar4 && plVar10 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar10 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = *plVar10;
        *plVar10 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
LAB_0010ee98:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_0010eeac;
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
         ((-1 < (char)p_Var20->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var20), iVar8 < 0))))
      goto LAB_0010eeac;
      lVar12 = pPVar9[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar12 == (p_Var20->ob_base).ob_size) &&
         ((pPVar9[1].ob_type == (_typeobject *)p_Var20->tp_name ||
          (_typeobject *)p_Var20->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar9[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar9[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        if (((byte)((byte)p_Var20->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar9[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar9[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar9[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar9 + 3);
            }
          }
          bVar2 = (byte)p_Var20->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var20->tp_setattr;
          }
          else {
            __s2 = &p_Var20->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var20->tp_dealloc;
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
            if (lVar12 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(__s1,__s2,(long)pcVar14 * lVar12);
              uVar15 = (uint)(iVar8 == 0);
              goto LAB_0010ee98;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar19];
LAB_0010edf0:
  if (values[1] == (PyObject *)0x0) goto LAB_0010eeb0;
  lVar18 = lVar18 + -1;
LAB_0010edb8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
  if ((lVar18 < 1) ||
     (iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                         (PyObject **)__pyx_nargs,0x11d088,pcVar14), -1 < iVar8)) goto LAB_0010ed6c;
  iVar8 = 0x11fe;
LAB_0010eb9c:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.setup_callback",iVar8,0x36,"aht20_f.py");
  pPVar9 = (PyObject *)0x0;
LAB_0010ebb8:
  if (lVar16 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 0010f040
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_13check_crc8
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_13check_crc8(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_13check_crc8
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  PySequenceMethods *pPVar2;
  byte bVar3;
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
  PyObject *op1;
  long lVar14;
  Py_ssize_t PVar15;
  ulong uVar16;
  long *plVar17;
  PyThreadState *tstate;
  setattrfunc *pp_Var18;
  _typeobject *p_Var19;
  ulong uVar20;
  long lVar21;
  long lVar22;
  ssizeargfunc p_Var23;
  getattrofunc p_Var24;
  undefined *puVar25;
  char *pcVar26;
  long lVar27;
  uint uVar28;
  _typeobject *p_Var29;
  PyObject *pPVar30;
  PyObject *pPVar31;
  PyMappingMethods *pPVar32;
  int py_line;
  ulong uVar33;
  Py_ssize_t PVar34;
  PyObject *pPVar35;
  long local_78;
  iternextfunc local_60;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_data@[???]
                       Unresolved local var: PyObject * __pyx_v_length@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg25(x25)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar27 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_data;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_length;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar26 = PTR___stack_chk_guard_0012ff30;
    if (__pyx_nargs == 1) {
      PVar34 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      lVar14 = PVar34;
LAB_0010f260:
      pPVar35 = __pyx_mstate_global_static.__pyx_n_s_data;
      puVar4 = PTR_PyUnicode_Type_0012ffb0;
      puVar6 = PTR__Py_TrueStruct_0012ff58;
      puVar5 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < PVar34) {
        p_Var29 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_data == p_Var29) {
          values[1] = *kwvalues;
        }
        else {
          lVar12 = 0;
          do {
            lVar21 = lVar12 + 1;
            if (lVar21 == PVar34) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar12 = 0;
              goto LAB_0010f2c0;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar12;
            lVar12 = lVar21;
          } while (__pyx_mstate_global_static.__pyx_n_s_data != (PyObject *)*pPVar1);
          values[1] = kwvalues[lVar21];
        }
        goto LAB_0010f8f8;
      }
LAB_0010fa90:
      values[1] = (PyObject *)0x0;
      goto LAB_0010fa94;
    }
    if (__pyx_nargs < 2) {
      if (__pyx_nargs == 0) {
        PVar15 = __pyx_kwds[1].ob_refcnt;
LAB_0010f23c:
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          PVar34 = __pyx_kwds[1].ob_refcnt;
          lVar14 = PVar15 + -1;
          goto LAB_0010f260;
        }
        lVar14 = PyErr_Occurred();
        if (lVar14 == 0) goto LAB_0010f844;
        iVar10 = 0x13f9;
      }
      else {
LAB_0010f844:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                     "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","check_crc8",
                     "exactly",3,"s",__pyx_nargs);
        iVar10 = 0x1421;
      }
      goto LAB_0010f880;
    }
    if (__pyx_nargs != 2) {
      if (__pyx_nargs != 3) goto LAB_0010f844;
      values[2] = __pyx_args[2];
    }
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    PVar34 = __pyx_kwds[1].ob_refcnt;
    lVar14 = PVar34;
    if (__pyx_nargs == 1) goto LAB_0010f260;
    PVar15 = PVar34;
    if (__pyx_nargs == 2) goto LAB_0010f0f0;
    if (__pyx_nargs == 0) goto LAB_0010f23c;
    goto LAB_0010f3a8;
  }
  if (__pyx_nargs != 3) goto LAB_0010f844;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
  values[2] = __pyx_args[2];
  PVar34 = 0x130ce0;
LAB_0010f3bc:
                    /* Unresolved local var: PyObject * __pyx_v_crc@[???]
                       Unresolved local var: PyObject * __pyx_v_i@[???]
                       Unresolved local var: long __pyx_v_j@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_3@[???]
                       Unresolved local var: _func_PyObject_ptr_PyObject_ptr * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: long __pyx_t_6@[???]
                       Unresolved local var: int __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar7 = values[1];
  pPVar31 = __pyx_builtin_range;
  op1 = __pyx_mstate_global_static.__pyx_int_255;
  pPVar35 = (PyObject *)((__pyx_mstate_global_static.__pyx_int_255)->ob_refcnt + 1);
  (__pyx_mstate_global_static.__pyx_int_255)->ob_refcnt = (Py_ssize_t)pPVar35;
  __pyx_pyargnames[0] = (PyObject **)0x0;
  __pyx_pyargnames[1] = (PyObject **)values[2];
  p_Var29 = (_typeobject *)
            __Pyx_PyObject_FastCallDict
                      (pPVar31,(PyObject **)(__pyx_pyargnames + 1),0x8000000000000001,pPVar35);
  if (p_Var29 == (_typeobject *)0x0) {
    py_line = 0x43;
    iVar10 = 0x145f;
    pPVar31 = (PyObject *)0x0;
  }
  else {
    p_Var19 = (p_Var29->ob_base).ob_base.ob_type;
    pPVar35 = (PyObject *)PTR_PyTuple_Type_0012feb8;
    if (p_Var19 == (_typeobject *)PTR_PyTuple_Type_0012feb8 ||
        p_Var19 == (_typeobject *)PTR_PyList_Type_0012ffe0) {
      lVar14 = 0;
      lVar12 = (p_Var29->ob_base).ob_base.ob_refcnt;
      local_60 = (iternextfunc)0x0;
      p_Var19 = p_Var29;
LAB_0010f420:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar12;
      if (lVar12 == 0) {
        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
      }
                    /* Unresolved local var: PyTypeObject * tp@[???]
                       Unresolved local var: PyMappingMethods * mm@[???]
                       Unresolved local var: PySequenceMethods * sm@[???]
                       Unresolved local var: __Pyx_TypeName obj_type_name@[???]
                       Unresolved local var: PyObject * meth@[???]
                       Unresolved local var: PyObject * result@[???] */
      puVar6 = PTR__Py_TrueStruct_0012ff58;
      puVar5 = PTR_PyObject_GenericGetAttr_0012ff38;
                    /* Unresolved local var: int is_true@[???] */
      pPVar31 = (PyObject *)0x0;
LAB_0010f454:
      if (local_60 == (iternextfunc)0x0) {
        lVar12 = (p_Var19->ob_base).ob_size;
        if ((p_Var19->ob_base).ob_base.ob_type == (_typeobject *)PTR_PyList_Type_0012ffe0) {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
          if (lVar12 <= lVar14) goto LAB_0010fbd4;
          pPVar30 = *(PyObject **)(p_Var19->tp_name + lVar14 * 8);
          pPVar30->ob_refcnt = pPVar30->ob_refcnt + 1;
          lVar14 = lVar14 + 1;
        }
        else {
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
          if (lVar12 <= lVar14) goto LAB_0010fbd4;
          pPVar30 = (PyObject *)(&p_Var19->tp_name)[lVar14];
          pPVar30->ob_refcnt = pPVar30->ob_refcnt + 1;
          lVar14 = lVar14 + 1;
        }
      }
      else {
        pPVar30 = (*local_60)((PyObject *)p_Var19);
        if (pPVar30 == (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * exc_type@[???] */
          pPVar35 = (PyObject *)PyErr_Occurred();
          if (pPVar35 != (PyObject *)0x0) {
            if ((pPVar35 == *(PyObject **)PTR_PyExc_StopIteration_0012ffa0) ||
               (iVar10 = __Pyx_PyErr_GivenExceptionMatches
                                   (pPVar35,*(PyObject **)PTR_PyExc_StopIteration_0012ffa0),
               iVar10 != 0)) {
              PyErr_Clear();
              goto LAB_0010fbd4;
            }
            pPVar35 = (PyObject *)0x0;
            py_line = 0x43;
            iVar10 = 0x1490;
            goto LAB_0010f820;
          }
LAB_0010fbd4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar14 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
          (p_Var19->ob_base).ob_base.ob_refcnt = lVar14;
          if (lVar14 == 0) {
            (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
          }
          lVar14 = op1->ob_refcnt;
          op1->ob_refcnt = lVar14 + 1;
          pPVar35 = op1;
          goto LAB_0010f734;
        }
      }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar31 != (PyObject *)0x0) &&
         (lVar12 = pPVar31->ob_refcnt + -1, pPVar31->ob_refcnt = lVar12, lVar12 == 0)) {
        (*pPVar31->ob_type->tp_dealloc)(pPVar31);
      }
      p_Var29 = pPVar7->ob_type;
      pPVar32 = p_Var29->tp_as_mapping;
      pPVar31 = pPVar30;
      if ((pPVar32 == (PyMappingMethods *)0x0) || (pPVar32->mp_subscript == (binaryfunc)0x0)) {
        if ((p_Var29->tp_as_sequence == (PySequenceMethods *)0x0) ||
           (p_Var23 = p_Var29->tp_as_sequence->sq_item, p_Var23 == (ssizeargfunc)0x0)) {
          if ((int)p_Var29->tp_flags < 0) {
            p_Var24 = p_Var29->tp_getattro;
            if (p_Var24 == (getattrofunc)puVar5) {
              pPVar35 = (PyObject *)0x1;
              pPVar13 = (PyObject *)
                        _PyObject_GenericGetAttrWithDict
                                  (pPVar7,__pyx_mstate_global_static.__pyx_n_s_class_getitem,0);
              if (pPVar13 == (PyObject *)0x0) goto LAB_00110168;
            }
            else {
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: PyTypeObject * tp@[???] */
              if (p_Var24 == (getattrofunc)0x0) {
                pPVar13 = (PyObject *)PyObject_GetAttr();
              }
              else {
                pPVar13 = (*p_Var24)(pPVar7,__pyx_mstate_global_static.__pyx_n_s_class_getitem);
              }
              if (pPVar13 == (PyObject *)0x0) {
                    /* Unresolved local var: PyThreadState * __pyx_tstate@[???] */
                tstate = (PyThreadState *)_PyThreadState_UncheckedGet();
                pPVar35 = tstate->curexc_type;
                pPVar30 = *(PyObject **)PTR_PyExc_AttributeError_0012ff98;
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * exc_type@[???] */
                if (pPVar30 == pPVar35) {
LAB_00110154:
                  __Pyx_ErrRestoreInState(tstate,(PyObject *)0x0,(PyObject *)0x0,(PyObject *)0x0);
                }
                else if (pPVar35 != (PyObject *)0x0) {
                  if (((uint)pPVar30->ob_type->tp_flags >> 0x1a & 1) == 0) {
                    iVar10 = __Pyx_PyErr_GivenExceptionMatches(pPVar35,pPVar30);
                  }
                  else {
                    iVar10 = __Pyx_PyErr_ExceptionMatchesTuple(pPVar35,pPVar30);
                  }
                  if (iVar10 != 0) goto LAB_00110154;
                }
LAB_00110168:
                PyErr_Clear();
                p_Var29 = pPVar7->ob_type;
                goto LAB_00110170;
              }
            }
                    /* Unresolved local var: PyObject * result@[???] */
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)pPVar30;
            p_Var29 = (_typeobject *)
                      __Pyx_PyObject_FastCallDict
                                (pPVar13,(PyObject **)(__pyx_pyargnames + 1),0x8000000000000001,
                                 pPVar35);
LAB_0010ff28:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar12 = pPVar13->ob_refcnt + -1;
            pPVar13->ob_refcnt = lVar12;
            if (lVar12 == 0) {
              (*pPVar13->ob_type->tp_dealloc)(pPVar13);
            }
            goto LAB_0010f4d8;
          }
LAB_00110170:
          py_line = 0x44;
          iVar10 = 0x14a0;
          pPVar35 = (PyObject *)0x0;
          PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                       "\'%.200s\' object is not subscriptable",p_Var29->tp_name);
          goto LAB_0010f820;
        }
                    /* Unresolved local var: Py_ssize_t ival@[???]
                       Unresolved local var: PyObject * x@[???] */
        if (pPVar30->ob_type == (_typeobject *)PTR_PyLong_Type_0012ff80) {
          lVar12 = pPVar30[1].ob_refcnt;
          if (lVar12 + 1U < 3) {
            if (lVar12 != 0) {
              iVar10 = *(int *)&pPVar30[1].ob_type;
              if (lVar12 < 0) {
                iVar10 = -*(int *)&pPVar30[1].ob_type;
              }
              uVar16 = (ulong)iVar10;
              goto LAB_0010fc9c;
            }
            if (p_Var29 == (_typeobject *)PTR_PyList_Type_0012ffe0) {
              uVar16 = 0;
              uVar20 = pPVar7[1].ob_refcnt;
              uVar33 = 0;
              goto LAB_0010fd58;
            }
            if (p_Var29 == (_typeobject *)PTR_PyTuple_Type_0012feb8) {
              uVar16 = 0;
              uVar20 = pPVar7[1].ob_refcnt;
              uVar33 = 0;
              goto LAB_0010fffc;
            }
                    /* Unresolved local var: PyMappingMethods * mm@[???]
                       Unresolved local var: PySequenceMethods * sm@[???] */
            uVar16 = 0;
            if ((pPVar32 == (PyMappingMethods *)0x0) ||
               (uVar33 = 0, pPVar32->mp_subscript == (binaryfunc)0x0)) goto LAB_0010fb50;
          }
          else {
                    /* Unresolved local var: digit * digits@[???]
                       Unresolved local var: Py_ssize_t size@[???] */
            if (lVar12 == -2) {
              uVar16 = -((ulong)*(uint *)&pPVar30[1].ob_type |
                        (ulong)*(uint *)((long)&pPVar30[1].ob_type + 4) << 0x1e);
LAB_0010fc9c:
              if (uVar16 == 0xffffffffffffffff) goto LAB_00110074;
              p_Var29 = pPVar7->ob_type;
              uVar33 = uVar16;
              if (p_Var29 != (_typeobject *)PTR_PyList_Type_0012ffe0) {
                if (p_Var29 != (_typeobject *)PTR_PyTuple_Type_0012feb8) goto LAB_0010fcc8;
                    /* Unresolved local var: Py_ssize_t n@[???] */
                uVar20 = pPVar7[1].ob_refcnt;
                if (-1 < (long)uVar16) goto LAB_0010fffc;
                goto LAB_0010fff4;
              }
                    /* Unresolved local var: Py_ssize_t n@[???] */
              uVar20 = pPVar7[1].ob_refcnt;
              if (-1 < (long)uVar16) goto LAB_0010fd58;
              goto LAB_0010fd54;
            }
            if (lVar12 != 2) {
              uVar16 = PyLong_AsSsize_t(pPVar30);
              goto LAB_0010fc9c;
            }
            uVar16 = (ulong)*(uint *)&pPVar30[1].ob_type |
                     (ulong)*(uint *)((long)&pPVar30[1].ob_type + 4) << 0x1e;
            uVar33 = uVar16;
            if (p_Var29 == (_typeobject *)PTR_PyList_Type_0012ffe0) {
              uVar20 = pPVar7[1].ob_refcnt;
              goto LAB_0010fd58;
            }
            if (p_Var29 == (_typeobject *)PTR_PyTuple_Type_0012feb8) {
              uVar20 = pPVar7[1].ob_refcnt;
              goto LAB_0010fffc;
            }
LAB_0010fcc8:
            pPVar2 = p_Var29->tp_as_sequence;
            pPVar32 = p_Var29->tp_as_mapping;
            if ((pPVar32 == (PyMappingMethods *)0x0) ||
               (uVar33 = uVar16, pPVar32->mp_subscript == (binaryfunc)0x0)) {
              uVar33 = uVar16;
              if ((pPVar2 == (PySequenceMethods *)0x0) ||
                 (p_Var23 = pPVar2->sq_item, p_Var23 == (ssizeargfunc)0x0)) goto LAB_0010ffcc;
              if (((long)uVar16 < 0) && (pPVar2->sq_length != (lenfunc)0x0)) {
                    /* Unresolved local var: Py_ssize_t l@[???] */
                PVar15 = (*pPVar2->sq_length)(pPVar7);
                if (PVar15 < 0) {
                  iVar10 = PyErr_ExceptionMatches(*(undefined8 *)PTR_PyExc_OverflowError_0012ff40);
                  if (iVar10 == 0) goto LAB_00110264;
                  PyErr_Clear();
                  p_Var23 = pPVar2->sq_item;
                }
                else {
                  uVar16 = uVar16 + PVar15;
                  p_Var23 = pPVar2->sq_item;
                }
              }
LAB_0010fb50:
              p_Var29 = (_typeobject *)(*p_Var23)(pPVar7,uVar16);
              goto LAB_0010f4d8;
            }
          }
                    /* Unresolved local var: PyObject * r@[???]
                       Unresolved local var: PyObject * key@[???] */
          pPVar35 = (PyObject *)PyLong_FromSsize_t(uVar33);
          if (pPVar35 != (PyObject *)0x0) {
            p_Var29 = (_typeobject *)(*pPVar32->mp_subscript)(pPVar7,pPVar35);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar12 = pPVar35->ob_refcnt + -1;
            pPVar35->ob_refcnt = lVar12;
            if (lVar12 == 0) {
              (*pPVar35->ob_type->tp_dealloc)(pPVar35);
            }
            goto LAB_0010f4d8;
          }
          goto LAB_0010fc40;
        }
        plVar17 = (long *)PyNumber_Index(pPVar30);
        if (plVar17 != (long *)0x0) {
          uVar16 = PyLong_AsSsize_t();
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar12 = *plVar17;
          *plVar17 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          goto LAB_0010fc9c;
        }
LAB_00110074:
        lVar12 = PyErr_Occurred();
        if (lVar12 != 0) {
          iVar10 = PyErr_GivenExceptionMatches
                             (lVar12,*(undefined8 *)PTR_PyExc_OverflowError_0012ff40);
          if (iVar10 == 0) {
LAB_00110264:
            py_line = 0x44;
            iVar10 = 0x14a0;
            pPVar35 = (PyObject *)0x0;
          }
          else {
                    /* Unresolved local var: __Pyx_TypeName index_type_name@[???] */
            py_line = 0x44;
            iVar10 = 0x14a0;
            pPVar35 = (PyObject *)0x0;
            pcVar26 = pPVar30->ob_type->tp_name;
            PyErr_Clear();
            PyErr_Format(*(undefined8 *)PTR_PyExc_IndexError_0012ff68,
                         "cannot fit \'%.200s\' into an index-sized integer",pcVar26);
          }
          goto LAB_0010f820;
        }
        p_Var29 = pPVar7->ob_type;
        if (p_Var29 == (_typeobject *)PTR_PyList_Type_0012ffe0) {
          uVar33 = 0xffffffffffffffff;
          uVar20 = pPVar7[1].ob_refcnt;
LAB_0010fd54:
          uVar16 = uVar20 + uVar33;
LAB_0010fd58:
          if (uVar20 <= uVar16) {
LAB_0010ffcc:
            pPVar13 = (PyObject *)PyLong_FromSsize_t(uVar33);
                    /* Unresolved local var: PyObject * r@[DW_OP_reg25(x25)] */
            if (pPVar13 != (PyObject *)0x0) {
              p_Var29 = (_typeobject *)PyObject_GetItem(pPVar7,pPVar13);
              goto LAB_0010ff28;
            }
            goto LAB_0010fc40;
          }
                    /* Unresolved local var: PyObject * r@[???] */
          p_Var29 = (_typeobject *)(&((pPVar7[1].ob_type)->ob_base).ob_base.ob_refcnt)[uVar16];
          (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
        }
        else {
          uVar16 = 0xffffffffffffffff;
          if (p_Var29 != (_typeobject *)PTR_PyTuple_Type_0012feb8) goto LAB_0010fcc8;
          uVar20 = pPVar7[1].ob_refcnt;
          uVar33 = uVar16;
LAB_0010fff4:
          uVar16 = uVar20 + uVar33;
LAB_0010fffc:
          if (uVar20 <= uVar16) goto LAB_0010ffcc;
                    /* Unresolved local var: PyObject * r@[???] */
          p_Var29 = (&pPVar7[1].ob_type)[uVar16];
          (p_Var29->ob_base).ob_base.ob_refcnt = (p_Var29->ob_base).ob_base.ob_refcnt + 1;
        }
      }
      else {
        p_Var29 = (_typeobject *)(*pPVar32->mp_subscript)(pPVar7,pPVar30);
LAB_0010f4d8:
        if (p_Var29 == (_typeobject *)0x0) {
LAB_0010fc40:
          py_line = 0x44;
          pPVar35 = (PyObject *)0x0;
          iVar10 = 0x14a0;
          goto LAB_0010f820;
        }
      }
      pPVar13 = (PyObject *)PyNumber_InPlaceXor(op1,p_Var29);
      lVar12 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar12;
      if (pPVar13 == (PyObject *)0x0) {
        if (lVar12 == 0) {
          iVar10 = 0x14a2;
          py_line = 0x44;
          goto LAB_0010f6f8;
        }
        py_line = 0x44;
        pPVar35 = (PyObject *)0x0;
        iVar10 = 0x14a2;
        goto LAB_0010f820;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if (lVar12 == 0) {
        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
      }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar12 = op1->ob_refcnt + -1;
      op1->ob_refcnt = lVar12;
      if (lVar12 == 0) {
        (*op1->ob_type->tp_dealloc)(op1);
      }
      puVar4 = PTR__Py_FalseStruct_0012ff20;
                    /* Unresolved local var: PyObject * runerr@[???]
                       Unresolved local var: Py_ssize_t key_value@[???] */
      local_78 = 8;
      do {
        pPVar35 = __Pyx_PyInt_AndObjC(pPVar13,__pyx_mstate_global_static.__pyx_int_128,0x80,0,
                                      (int)PVar34);
        if (pPVar35 == (PyObject *)0x0) {
          py_line = 0x46;
          iVar10 = 0x14b9;
          op1 = pPVar13;
          goto LAB_0010f820;
        }
        uVar11 = (uint)(pPVar35 == (PyObject *)puVar6);
        puVar25 = puVar4;
        if (((uVar11 == 0 && pPVar35 != (PyObject *)puVar4) &&
             pPVar35 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
           (uVar11 = PyObject_IsTrue(), (int)uVar11 < 0)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          py_line = 0x46;
          iVar10 = 0x14bb;
          lVar14 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
          (p_Var19->ob_base).ob_base.ob_refcnt = lVar14;
          if (lVar14 != 0) goto LAB_0010f7c8;
          goto LAB_0010f830;
        }
        iVar10 = (int)puVar25;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = pPVar35->ob_refcnt + -1;
        pPVar35->ob_refcnt = lVar12;
        if (lVar12 == 0) {
          (*pPVar35->ob_type->tp_dealloc)(pPVar35);
        }
        if (uVar11 == 0) {
          op1 = __Pyx_PyInt_LshiftObjC
                          (pPVar13,__pyx_mstate_global_static.__pyx_int_1,1,iVar10,(int)PVar34);
          if (op1 == (PyObject *)0x0) {
            pPVar35 = (PyObject *)0x0;
            py_line = 0x49;
            iVar10 = 0x14e0;
            op1 = pPVar13;
            goto LAB_0010f820;
          }
        }
        else {
          pPVar35 = __Pyx_PyInt_LshiftObjC
                              (pPVar13,__pyx_mstate_global_static.__pyx_int_1,0,iVar10,(int)PVar34);
          op1 = __pyx_mstate_global_static.__pyx_int_49;
          if (pPVar35 == (PyObject *)0x0) {
            py_line = 0x47;
            iVar10 = 0x14c6;
            op1 = pPVar13;
            goto LAB_0010f820;
          }
          if (pPVar35->ob_type == (_typeobject *)PTR_PyLong_Type_0012ff80) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: long a@[???]
                       Unresolved local var: long x@[???]
                       Unresolved local var: longlong llb@[???]
                       Unresolved local var: longlong lla@[???]
                       Unresolved local var: longlong llx@[???] */
            lVar12 = pPVar35[1].ob_refcnt;
            if (lVar12 != 0) {
              if (lVar12 + 1U < 3) {
                iVar10 = *(int *)&pPVar35[1].ob_type;
                if (lVar12 < 0) {
                  iVar10 = -*(int *)&pPVar35[1].ob_type;
                }
                uVar16 = (ulong)iVar10;
              }
              else {
                    /* Unresolved local var: digit * digits@[???]
                       Unresolved local var: Py_ssize_t size@[???] */
                if (lVar12 == -2) {
                  uVar16 = -((ulong)*(uint *)&pPVar35[1].ob_type |
                            (ulong)*(uint *)((long)&pPVar35[1].ob_type + 4) << 0x1e);
                }
                else {
                  if (lVar12 != 2) {
                    op1 = (*pPVar35->ob_type->tp_as_number->nb_xor)
                                    (pPVar35,__pyx_mstate_global_static.__pyx_int_49);
                    goto LAB_0010f624;
                  }
                  uVar16 = (ulong)*(uint *)&pPVar35[1].ob_type |
                           (ulong)*(uint *)((long)&pPVar35[1].ob_type + 4) << 0x1e;
                }
              }
              op1 = (PyObject *)PyLong_FromLong(uVar16 ^ 0x31);
              goto LAB_0010f624;
            }
            (__pyx_mstate_global_static.__pyx_int_49)->ob_refcnt =
                 (__pyx_mstate_global_static.__pyx_int_49)->ob_refcnt + 1;
          }
          else {
            op1 = (PyObject *)PyNumber_Xor(pPVar35,__pyx_mstate_global_static.__pyx_int_49);
LAB_0010f624:
            if (op1 == (PyObject *)0x0) {
              py_line = 0x47;
              iVar10 = 0x14c8;
              op1 = pPVar13;
              goto LAB_0010f820;
            }
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar12 = pPVar35->ob_refcnt + -1;
          pPVar35->ob_refcnt = lVar12;
          if (lVar12 == 0) {
            (*pPVar35->ob_type->tp_dealloc)(pPVar35);
          }
        }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar12;
        if (lVar12 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        pPVar35 = (PyObject *)0x1;
        pPVar13 = __Pyx_PyInt_AndObjC(op1,__pyx_mstate_global_static.__pyx_int_255,0xff,1,
                                      (int)PVar34);
        if (pPVar13 == (PyObject *)0x0) {
          py_line = 0x4a;
          iVar10 = 0x14ee;
          pPVar35 = (PyObject *)0x0;
          goto LAB_0010f820;
        }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = op1->ob_refcnt + -1;
        op1->ob_refcnt = lVar12;
        if (lVar12 == 0) {
          (*op1->ob_type->tp_dealloc)(op1);
        }
        local_78 = local_78 + -1;
        op1 = pPVar13;
      } while (local_78 != 0);
      goto LAB_0010f454;
    }
    p_Var19 = (_typeobject *)PyObject_GetIter();
    if (p_Var19 == (_typeobject *)0x0) {
      lVar14 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar14;
      if (lVar14 == 0) {
        pPVar30 = (PyObject *)0x0;
        p_Var19 = (_typeobject *)0x0;
        iVar10 = 0x1466;
        py_line = 0x43;
LAB_0010f6f8:
        (*((p_Var29->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var29);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        pPVar31 = pPVar30;
        if (p_Var19 != (_typeobject *)0x0) {
          pPVar35 = (PyObject *)0x0;
          goto LAB_0010f820;
        }
      }
      else {
        pPVar31 = (PyObject *)0x0;
        py_line = 0x43;
        iVar10 = 0x1466;
      }
    }
    else {
      local_60 = ((p_Var19->ob_base).ob_base.ob_type)->tp_iternext;
      lVar12 = (p_Var29->ob_base).ob_base.ob_refcnt + -1;
      if (local_60 != (iternextfunc)0x0) {
        lVar14 = -1;
        goto LAB_0010f420;
      }
      (p_Var29->ob_base).ob_base.ob_refcnt = lVar12;
      if (lVar12 == 0) {
        iVar10 = 0x1468;
        py_line = 0x43;
        pPVar30 = (PyObject *)0x0;
        goto LAB_0010f6f8;
      }
      pPVar31 = (PyObject *)0x0;
      py_line = 0x43;
      iVar10 = 0x1468;
      pPVar35 = (PyObject *)0x0;
LAB_0010f820:
      lVar14 = (p_Var19->ob_base).ob_base.ob_refcnt + -1;
      (p_Var19->ob_base).ob_base.ob_refcnt = lVar14;
      pPVar30 = pPVar31;
      pPVar13 = op1;
      if (lVar14 == 0) {
LAB_0010f830:
        (*((p_Var19->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var19);
      }
LAB_0010f7c8:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      pPVar31 = pPVar30;
      op1 = pPVar13;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar35 != (PyObject *)0x0) &&
         (lVar14 = pPVar35->ob_refcnt + -1, pPVar35->ob_refcnt = lVar14, lVar14 == 0)) {
        (*pPVar35->ob_type->tp_dealloc)(pPVar35);
      }
    }
  }
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.check_crc8",iVar10,py_line,"aht20_f.py");
  lVar14 = op1->ob_refcnt + -1;
  pPVar35 = (PyObject *)0x0;
LAB_0010f734:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
  op1->ob_refcnt = lVar14;
  if (lVar14 == 0) {
    (*op1->ob_type->tp_dealloc)(op1);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar31 != (PyObject *)0x0) &&
     (lVar14 = pPVar31->ob_refcnt + -1, pPVar31->ob_refcnt = lVar14, lVar14 == 0)) {
    (*pPVar31->ob_type->tp_dealloc)(pPVar31);
  }
  goto LAB_0010f770;
  while( true ) {
    lVar21 = lVar12 + 1;
    if (lVar21 == PVar34) goto LAB_0010fa90;
    p_Var29 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar12];
    lVar12 = lVar21;
    if ((_typeobject *)pPVar35 == p_Var29) break;
LAB_0010f2c0:
    bVar8 = pPVar35->ob_type != (_typeobject *)puVar4;
    bVar9 = (p_Var29->ob_base).ob_base.ob_type != (_typeobject *)puVar4;
    lVar21 = lVar12;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar35 != (PyObject *)puVar5) && (bVar8 || p_Var29 != (_typeobject *)puVar5)) {
        plVar17 = (long *)PyObject_RichCompare(pPVar35,p_Var29,2);
        if (plVar17 == (long *)0x0) goto LAB_0010fa90;
        uVar11 = (uint)(plVar17 == (long *)puVar6);
        if ((plVar17 != (long *)puVar6 && plVar17 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar17 != (long *)puVar5) {
          uVar11 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar22 = *plVar17;
        *plVar17 = lVar22 + -1;
        if (lVar22 + -1 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
LAB_0010fa80:
        if (uVar11 != 0) {
          if ((int)uVar11 < 0) goto LAB_0010fa90;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar35[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar35), iVar10 < 0)) ||
         ((-1 < (char)p_Var29->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var29), iVar10 < 0))))
      goto LAB_0010fa90;
      lVar22 = pPVar35[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar22 == (p_Var29->ob_base).ob_size) &&
         ((pPVar35[1].ob_type == (_typeobject *)p_Var29->tp_name ||
          (_typeobject *)p_Var29->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar35[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar26 = (char *)((ulong)(byte)((byte)pPVar35[2].ob_refcnt >> 2) & 7);
        uVar11 = (uint)pcVar26;
        if (((byte)((byte)p_Var29->tp_basicsize >> 2) & 7) == uVar11) {
          bVar3 = (byte)pPVar35[2].ob_refcnt;
          if ((bVar3 >> 5 & 1) == 0) {
            p_Var19 = pPVar35[4].ob_type;
          }
          else {
            p_Var19 = (_typeobject *)&pPVar35[4].ob_type;
            if ((bVar3 & 0x40) != 0) {
              p_Var19 = (_typeobject *)(pPVar35 + 3);
            }
          }
          bVar3 = (byte)p_Var29->tp_basicsize;
          if ((bVar3 >> 5 & 1) == 0) {
            pp_Var18 = (setattrfunc *)p_Var29->tp_setattr;
          }
          else {
            pp_Var18 = &p_Var29->tp_setattr;
            if ((bVar3 & 0x40) != 0) {
              pp_Var18 = (setattrfunc *)&p_Var29->tp_dealloc;
            }
          }
          if (uVar11 == 1) {
            uVar11 = (uint)(byte)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar28 = (uint)*(byte *)pp_Var18;
          }
          else if (uVar11 == 2) {
            uVar11 = (uint)(ushort)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar28 = (uint)*(ushort *)pp_Var18;
          }
          else {
            uVar11 = (uint)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar28 = *(uint *)pp_Var18;
          }
          if (uVar28 == uVar11) {
            if (lVar22 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var19,pp_Var18,(long)pcVar26 * lVar22);
              uVar11 = (uint)(iVar10 == 0);
              goto LAB_0010fa80;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar21];
LAB_0010f8f8:
  if (values[1] != (PyObject *)0x0) {
    PVar15 = lVar14 + -1;
    PVar34 = __pyx_kwds[1].ob_refcnt;
LAB_0010f0f0:
    pPVar35 = __pyx_mstate_global_static.__pyx_n_s_length;
    puVar4 = PTR_PyUnicode_Type_0012ffb0;
    puVar6 = PTR__Py_TrueStruct_0012ff58;
    puVar5 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < PVar34) {
      p_Var29 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_length == p_Var29) {
        values[2] = *kwvalues;
      }
      else {
        lVar14 = 0;
        do {
          lVar12 = lVar14 + 1;
          if (lVar12 == PVar34) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar14 = 0;
            goto LAB_0010f150;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar14;
          lVar14 = lVar12;
        } while (__pyx_mstate_global_static.__pyx_n_s_length != (PyObject *)*pPVar1);
        values[2] = kwvalues[lVar12];
      }
      goto LAB_0010f8c4;
    }
LAB_0010f9a8:
    values[2] = (PyObject *)0x0;
    goto LAB_0010f9ac;
  }
LAB_0010fa94:
  lVar14 = PyErr_Occurred();
  if (lVar14 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","check_crc8",
                 "exactly",3,"s",1);
    iVar10 = 0x1403;
  }
  else {
    iVar10 = 0x1401;
  }
  goto LAB_0010f880;
  while( true ) {
    lVar12 = lVar14 + 1;
    if (lVar12 == PVar34) goto LAB_0010f9a8;
    p_Var29 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar14];
    lVar14 = lVar12;
    if ((_typeobject *)pPVar35 == p_Var29) break;
LAB_0010f150:
    bVar8 = pPVar35->ob_type != (_typeobject *)puVar4;
    bVar9 = (p_Var29->ob_base).ob_base.ob_type != (_typeobject *)puVar4;
    lVar12 = lVar14;
    if (bVar8 || bVar9) {
      if ((bVar9 || pPVar35 != (PyObject *)puVar5) && (bVar8 || p_Var29 != (_typeobject *)puVar5)) {
        plVar17 = (long *)PyObject_RichCompare(pPVar35,p_Var29,2);
        if (plVar17 == (long *)0x0) goto LAB_0010f9a8;
        uVar11 = (uint)(plVar17 == (long *)puVar6);
        if ((plVar17 != (long *)puVar6 && plVar17 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar17 != (long *)puVar5) {
          uVar11 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar21 = *plVar17;
        *plVar17 = lVar21 + -1;
        if (lVar21 + -1 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
LAB_0010f998:
        if (uVar11 != 0) {
          if ((int)uVar11 < 0) goto LAB_0010f9a8;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar35[2].ob_refcnt) && (iVar10 = _PyUnicode_Ready(pPVar35), iVar10 < 0)) ||
         ((-1 < (char)p_Var29->tp_basicsize && (iVar10 = _PyUnicode_Ready(p_Var29), iVar10 < 0))))
      goto LAB_0010f9a8;
      lVar21 = pPVar35[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar21 == (p_Var29->ob_base).ob_size) &&
         ((pPVar35[1].ob_type == (_typeobject *)p_Var29->tp_name ||
          (_typeobject *)p_Var29->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar35[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar26 = (char *)((ulong)(byte)((byte)pPVar35[2].ob_refcnt >> 2) & 7);
        uVar11 = (uint)pcVar26;
        if (((byte)((byte)p_Var29->tp_basicsize >> 2) & 7) == uVar11) {
          bVar3 = (byte)pPVar35[2].ob_refcnt;
          if ((bVar3 >> 5 & 1) == 0) {
            p_Var19 = pPVar35[4].ob_type;
          }
          else {
            p_Var19 = (_typeobject *)&pPVar35[4].ob_type;
            if ((bVar3 & 0x40) != 0) {
              p_Var19 = (_typeobject *)(pPVar35 + 3);
            }
          }
          bVar3 = (byte)p_Var29->tp_basicsize;
          if ((bVar3 >> 5 & 1) == 0) {
            pp_Var18 = (setattrfunc *)p_Var29->tp_setattr;
          }
          else {
            pp_Var18 = &p_Var29->tp_setattr;
            if ((bVar3 & 0x40) != 0) {
              pp_Var18 = (setattrfunc *)&p_Var29->tp_dealloc;
            }
          }
          if (uVar11 == 1) {
            uVar11 = (uint)(byte)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar28 = (uint)*(byte *)pp_Var18;
          }
          else if (uVar11 == 2) {
            uVar11 = (uint)(ushort)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar28 = (uint)*(ushort *)pp_Var18;
          }
          else {
            uVar11 = (uint)(p_Var19->ob_base).ob_base.ob_refcnt;
            uVar28 = *(uint *)pp_Var18;
          }
          if (uVar28 == uVar11) {
            if (lVar21 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar10 = memcmp(p_Var19,pp_Var18,(long)pcVar26 * lVar21);
              uVar11 = (uint)(iVar10 == 0);
              goto LAB_0010f998;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar12];
LAB_0010f8c4:
  if (values[2] == (PyObject *)0x0) {
LAB_0010f9ac:
    lVar14 = PyErr_Occurred();
    if (lVar14 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","check_crc8",
                   "exactly",3,"s",2);
      iVar10 = 0x140d;
    }
    else {
      iVar10 = 0x140b;
    }
  }
  else {
    lVar14 = PVar15 + -1;
LAB_0010f3a8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar14 < 1) ||
       (iVar10 = __Pyx_ParseOptionalKeywords
                           (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                            (PyObject **)__pyx_nargs,0x11d0c0,pcVar26), PVar34 = __pyx_nargs,
       -1 < iVar10)) goto LAB_0010f3bc;
    iVar10 = 0x1412;
  }
LAB_0010f880:
  pPVar35 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.check_crc8",iVar10,0x41,"aht20_f.py");
LAB_0010f770:
  if (lVar27 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar35;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00110308
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_5setup_minmax
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_5setup_minmax(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_5setup_minmax
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  Py_ssize_t *pPVar1;
  PyObject **kwvalues;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  PyObject *pPVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  long lVar10;
  _typeobject *p_Var11;
  PyObject *pPVar12;
  long *plVar13;
  long lVar14;
  setattrfunc *pp_Var15;
  int py_line;
  long lVar16;
  long lVar17;
  setattrofunc p_Var18;
  char *pcVar19;
  uint uVar20;
  long lVar21;
  uint uVar22;
  _typeobject *p_Var23;
  long lVar24;
  Py_ssize_t PVar25;
  PyObject *values [3];
  PyObject **__pyx_pyargnames [4];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_min_temp@[???]
                       Unresolved local var: PyObject * __pyx_v_max_temp@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[DW_OP_reg26(x26)]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar21 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  values[2] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_min_temp;
  __pyx_pyargnames[2] = &__pyx_mstate_global_static.__pyx_n_s_max_temp;
  __pyx_pyargnames[3] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    kwvalues = __pyx_args + __pyx_nargs;
    pcVar19 = PTR___stack_chk_guard_0012ff30;
    if (__pyx_nargs == 1) {
      lVar24 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      lVar14 = lVar24;
LAB_00110528:
      pPVar12 = __pyx_mstate_global_static.__pyx_n_s_min_temp;
      puVar5 = PTR_PyUnicode_Type_0012ffb0;
      puVar4 = PTR__Py_TrueStruct_0012ff58;
      puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar24) {
        p_Var23 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_min_temp == p_Var23) {
          values[1] = *kwvalues;
        }
        else {
          lVar10 = 0;
          do {
            lVar16 = lVar10 + 1;
            if (lVar16 == lVar24) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar10 = 0;
              goto LAB_00110588;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar10;
            lVar10 = lVar16;
          } while (__pyx_mstate_global_static.__pyx_n_s_min_temp != (PyObject *)*pPVar1);
          values[1] = kwvalues[lVar16];
        }
        goto LAB_001107e4;
      }
LAB_00110988:
      values[1] = (PyObject *)0x0;
      goto LAB_0011098c;
    }
    if (__pyx_nargs < 2) {
      if (__pyx_nargs == 0) {
        PVar25 = __pyx_kwds[1].ob_refcnt;
LAB_00110504:
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,kwvalues,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar24 = __pyx_kwds[1].ob_refcnt;
          lVar14 = PVar25 + -1;
          goto LAB_00110528;
        }
        lVar14 = PyErr_Occurred();
        if (lVar14 == 0) goto LAB_00110674;
        iVar9 = 0x113e;
      }
      else {
LAB_00110674:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
        PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                     "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_minmax",
                     "exactly",3,"s",__pyx_nargs);
        iVar9 = 0x1166;
      }
      goto LAB_001106b0;
    }
    if (__pyx_nargs != 2) {
      if (__pyx_nargs != 3) goto LAB_00110674;
      values[2] = __pyx_args[2];
    }
    values[0] = *__pyx_args;
    values[1] = __pyx_args[1];
    lVar24 = __pyx_kwds[1].ob_refcnt;
    lVar14 = lVar24;
    if (__pyx_nargs == 1) goto LAB_00110528;
    PVar25 = lVar24;
    if (__pyx_nargs == 2) goto LAB_001103b8;
    if (__pyx_nargs == 0) goto LAB_00110504;
    goto LAB_001106f8;
  }
  if (__pyx_nargs != 3) goto LAB_00110674;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
  values[2] = __pyx_args[2];
LAB_00110710:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
  pPVar6 = values[2];
  pPVar12 = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var18 = values[0]->ob_type->tp_setattro;
  if (p_Var18 == (setattrofunc)0x0) {
    iVar9 = PyObject_SetAttr();
  }
  else {
    iVar9 = (*p_Var18)(values[0],__pyx_mstate_global_static.__pyx_n_s_min_temp,values[1]);
  }
  if (iVar9 < 0) {
    iVar9 = 0x1190;
    py_line = 0x33;
  }
  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var18 = pPVar12->ob_type->tp_setattro;
    if (p_Var18 == (setattrofunc)0x0) {
      iVar9 = PyObject_SetAttr();
    }
    else {
      iVar9 = (*p_Var18)(pPVar12,__pyx_mstate_global_static.__pyx_n_s_max_temp,pPVar6);
    }
    pPVar12 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
    if (-1 < iVar9) {
      *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
      goto LAB_001106cc;
    }
    iVar9 = 0x1199;
    py_line = 0x34;
  }
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.setup_minmax",iVar9,py_line,"aht20_f.py");
  pPVar12 = (PyObject *)0x0;
  goto LAB_001106cc;
  while( true ) {
    lVar16 = lVar10 + 1;
    if (lVar16 == lVar24) goto LAB_00110988;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar10];
    lVar10 = lVar16;
    if ((_typeobject *)pPVar12 == p_Var23) break;
LAB_00110588:
    bVar7 = pPVar12->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar16 = lVar10;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar12 != (PyObject *)puVar3) && (bVar7 || p_Var23 != (_typeobject *)puVar3)) {
        plVar13 = (long *)PyObject_RichCompare(pPVar12,p_Var23,2);
        if (plVar13 == (long *)0x0) goto LAB_00110988;
        uVar20 = (uint)(plVar13 == (long *)puVar4);
        if ((plVar13 != (long *)puVar4 && plVar13 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar13 != (long *)puVar3) {
          uVar20 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar17 = *plVar13;
        *plVar13 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_00110978:
        if (uVar20 != 0) {
          if ((int)uVar20 < 0) goto LAB_00110988;
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
         ((-1 < (char)p_Var23->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var23), iVar9 < 0))))
      goto LAB_00110988;
      lVar17 = pPVar12[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar17 == (p_Var23->ob_base).ob_size) &&
         ((pPVar12[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar12[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar19 = (char *)((ulong)(byte)((byte)pPVar12[2].ob_refcnt >> 2) & 7);
        uVar20 = (uint)pcVar19;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar20) {
          bVar2 = (byte)pPVar12[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var11 = pPVar12[4].ob_type;
          }
          else {
            p_Var11 = (_typeobject *)&pPVar12[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var11 = (_typeobject *)(pPVar12 + 3);
            }
          }
          bVar2 = (byte)p_Var23->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var15 = (setattrfunc *)p_Var23->tp_setattr;
          }
          else {
            pp_Var15 = &p_Var23->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var15 = (setattrfunc *)&p_Var23->tp_dealloc;
            }
          }
          if (uVar20 == 1) {
            uVar20 = (uint)(byte)(p_Var11->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var15;
          }
          else if (uVar20 == 2) {
            uVar20 = (uint)(ushort)(p_Var11->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var15;
          }
          else {
            uVar20 = (uint)(p_Var11->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var15;
          }
          if (uVar22 == uVar20) {
            if (lVar17 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var11,pp_Var15,(long)pcVar19 * lVar17);
              uVar20 = (uint)(iVar9 == 0);
              goto LAB_00110978;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = kwvalues[lVar16];
LAB_001107e4:
  if (values[1] != (PyObject *)0x0) {
    PVar25 = lVar14 + -1;
    lVar24 = __pyx_kwds[1].ob_refcnt;
LAB_001103b8:
    pPVar12 = __pyx_mstate_global_static.__pyx_n_s_max_temp;
    puVar5 = PTR_PyUnicode_Type_0012ffb0;
    puVar4 = PTR__Py_TrueStruct_0012ff58;
    puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar24) {
      p_Var23 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_max_temp == p_Var23) {
        values[2] = *kwvalues;
      }
      else {
        lVar14 = 0;
        do {
          lVar10 = lVar14 + 1;
          if (lVar10 == lVar24) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar14 = 0;
            goto LAB_00110418;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar14;
          lVar14 = lVar10;
        } while (__pyx_mstate_global_static.__pyx_n_s_max_temp != (PyObject *)*pPVar1);
        values[2] = kwvalues[lVar10];
      }
      goto LAB_001107b0;
    }
LAB_00110890:
    values[2] = (PyObject *)0x0;
    goto LAB_00110894;
  }
LAB_0011098c:
  lVar14 = PyErr_Occurred();
  if (lVar14 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
    PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                 "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_minmax",
                 "exactly",3,"s",1);
    iVar9 = 0x1148;
  }
  else {
    iVar9 = 0x1146;
  }
  goto LAB_001106b0;
  while( true ) {
    lVar10 = lVar14 + 1;
    if (lVar10 == lVar24) goto LAB_00110890;
    p_Var23 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar14];
    lVar14 = lVar10;
    if ((_typeobject *)pPVar12 == p_Var23) break;
LAB_00110418:
    bVar7 = pPVar12->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var23->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar10 = lVar14;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar12 != (PyObject *)puVar3) && (bVar7 || p_Var23 != (_typeobject *)puVar3)) {
        plVar13 = (long *)PyObject_RichCompare(pPVar12,p_Var23,2);
        if (plVar13 == (long *)0x0) goto LAB_00110890;
        uVar20 = (uint)(plVar13 == (long *)puVar4);
        if ((plVar13 != (long *)puVar4 && plVar13 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar13 != (long *)puVar3) {
          uVar20 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar16 = *plVar13;
        *plVar13 = lVar16 + -1;
        if (lVar16 + -1 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_00110884:
        if (uVar20 != 0) {
          if ((int)uVar20 < 0) goto LAB_00110890;
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
         ((-1 < (char)p_Var23->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var23), iVar9 < 0))))
      goto LAB_00110890;
      lVar16 = pPVar12[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar16 == (p_Var23->ob_base).ob_size) &&
         ((pPVar12[1].ob_type == (_typeobject *)p_Var23->tp_name ||
          (_typeobject *)p_Var23->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar12[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar19 = (char *)((ulong)(byte)((byte)pPVar12[2].ob_refcnt >> 2) & 7);
        uVar20 = (uint)pcVar19;
        if (((byte)((byte)p_Var23->tp_basicsize >> 2) & 7) == uVar20) {
          bVar2 = (byte)pPVar12[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var11 = pPVar12[4].ob_type;
          }
          else {
            p_Var11 = (_typeobject *)&pPVar12[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var11 = (_typeobject *)(pPVar12 + 3);
            }
          }
          bVar2 = (byte)p_Var23->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            pp_Var15 = (setattrfunc *)p_Var23->tp_setattr;
          }
          else {
            pp_Var15 = &p_Var23->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              pp_Var15 = (setattrfunc *)&p_Var23->tp_dealloc;
            }
          }
          if (uVar20 == 1) {
            uVar20 = (uint)(byte)(p_Var11->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(byte *)pp_Var15;
          }
          else if (uVar20 == 2) {
            uVar20 = (uint)(ushort)(p_Var11->ob_base).ob_base.ob_refcnt;
            uVar22 = (uint)*(ushort *)pp_Var15;
          }
          else {
            uVar20 = (uint)(p_Var11->ob_base).ob_base.ob_refcnt;
            uVar22 = *(uint *)pp_Var15;
          }
          if (uVar22 == uVar20) {
            if (lVar16 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var11,pp_Var15,(long)pcVar19 * lVar16);
              uVar20 = (uint)(iVar9 == 0);
              goto LAB_00110884;
            }
            break;
          }
        }
      }
    }
  }
  values[2] = kwvalues[lVar10];
LAB_001107b0:
  if (values[2] == (PyObject *)0x0) {
LAB_00110894:
    lVar14 = PyErr_Occurred();
    if (lVar14 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","setup_minmax",
                   "exactly",3,"s",2);
      iVar9 = 0x1152;
    }
    else {
      iVar9 = 0x1150;
    }
  }
  else {
    lVar24 = PVar25 + -1;
LAB_001106f8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar24 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x11d150,pcVar19), -1 < iVar9))
    goto LAB_00110710;
    iVar9 = 0x1157;
  }
LAB_001106b0:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.setup_minmax",iVar9,0x32,"aht20_f.py");
  pPVar12 = (PyObject *)0x0;
LAB_001106cc:
  if (lVar21 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00110bc0
 * Symbol:  __pyx_pf_6extras_7aht20_f_7AHT20_F_14_make_measurement
 * Signature: PyObject * __pyx_pf_6extras_7aht20_f_7AHT20_F_14_make_measurement(PyObject * __pyx_self, PyObject * __pyx_v_self)
 * ================================================================ */

PyObject *
__pyx_pf_6extras_7aht20_f_7AHT20_F_14_make_measurement(PyObject *__pyx_self,PyObject *__pyx_v_self)

{
  Py_ssize_t *pPVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  PyObject *pPVar10;
  long lVar11;
  PyThreadState *tstate;
  _PyErr_StackItem *p_Var12;
  _typeobject *p_Var13;
  PyObject *pPVar14;
  PyObject *pPVar15;
  PyObject *pPVar16;
  PyObject *pPVar17;
  long lVar18;
  long *plVar19;
  PyObject *pPVar20;
  PyThreadState *tstate_00;
  ulong uVar21;
  _PyErr_StackItem *p_Var22;
  PyObject *pPVar23;
  getattrofunc p_Var24;
  size_t _nargs;
  undefined *puVar25;
  __pyx_mstate *kwargs;
  long lVar26;
  _typeobject *p_Var27;
  _typeobject *p_Var28;
  PyObject *pPVar29;
  PyObject *pPVar30;
  PyObject **local_90;
  PyObject *local_80;
  PyObject *local_78;
  PyObject *local_70;
  PyObject *__pyx_t_7;
  PyObject *__pyx_t_9;
  PyObject *__pyx_t_11;
  PyObject *__pyx_t_18;
  PyObject *__pyx_t_19;
  PyObject *__pyx_t_20;
  PyObject *__pyx_callargs [2];
  
                    /* Unresolved local var: PyObject * __pyx_v_data@[???]
                       Unresolved local var: int __pyx_v_is_busy@[???]
                       Unresolved local var: PyObject * __pyx_v_cycles@[???]
                       Unresolved local var: PyObject * __pyx_v_read@[???]
                       Unresolved local var: PyObject * __pyx_v_e@[???]
                       Unresolved local var: PyObject * __pyx_v_temp@[???]
                       Unresolved local var: PyObject * __pyx_v_hum@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: int __pyx_t_2@[???]
                       Unresolved local var: int __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: PyObject * __pyx_t_8@[???]
                       Unresolved local var: wchar_t __pyx_t_10@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_12@[???]
                       Unresolved local var: int __pyx_t_13@[???]
                       Unresolved local var: PyObject * __pyx_t_14@[???]
                       Unresolved local var: PyObject * __pyx_t_15@[???]
                       Unresolved local var: int __pyx_t_16@[???]
                       Unresolved local var: char * __pyx_t_17@[???]
                       Unresolved local var: PyObject * __pyx_t_21@[???]
                       Unresolved local var: PyObject * __pyx_t_22@[???]
                       Unresolved local var: PyObject * __pyx_t_23@[???]
                       Unresolved local var: int __pyx_t_24@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  lVar26 = *(long *)PTR___stack_chk_guard_0012ff30;
  p_Var24 = __pyx_self->ob_type->tp_getattro;
  __pyx_t_7 = (PyObject *)0x0;
  __pyx_t_9 = (PyObject *)0x0;
  __pyx_t_11 = (PyObject *)0x0;
  __pyx_t_18 = (PyObject *)0x0;
  __pyx_t_19 = (PyObject *)0x0;
  __pyx_t_20 = (PyObject *)0x0;
  if (p_Var24 == (getattrofunc)0x0) {
    pPVar10 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar10 = (*p_Var24)(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_init_sent);
  }
  if (pPVar10 == (PyObject *)0x0) {
    pPVar14 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    pPVar16 = (PyObject *)0x0;
    pPVar23 = (PyObject *)0x0;
    iVar3 = 0x4f;
    local_90._0_4_ = 0x15b7;
    pPVar15 = (PyObject *)0x0;
  }
  else {
                    /* Unresolved local var: int is_true@[???] */
    uVar5 = (uint)(pPVar10 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
    if (((uVar5 != 0 || pPVar10 == (PyObject *)PTR__Py_FalseStruct_0012ff20) ||
         pPVar10 == (PyObject *)PTR__Py_NoneStruct_0012ff50) ||
       (uVar5 = PyObject_IsTrue(pPVar10), -1 < (int)uVar5)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar11 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar11;
      pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
      pPVar15 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
      pPVar20 = __pyx_mstate_global_static.__pyx_int_0;
      if (lVar11 == 0) {
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
        pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
        pPVar15 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
        pPVar20 = __pyx_mstate_global_static.__pyx_int_0;
      }
      PTR__Py_FalseStruct_0012ff20 = (undefined *)pPVar29;
      PTR__Py_NoneStruct_0012ff50 = (undefined *)pPVar15;
      __pyx_mstate_global_static.__pyx_int_0 = pPVar20;
      if (uVar5 != 0) {
        pPVar15->ob_refcnt = pPVar15->ob_refcnt + 1;
        pPVar20->ob_refcnt = pPVar20->ob_refcnt + 1;
                    /* Unresolved local var: PyThreadState * __pyx_tstate@[???] */
        tstate = (PyThreadState *)_PyThreadState_UncheckedGet();
                    /* Unresolved local var: _PyErr_StackItem * exc_info@[???] */
        p_Var22 = tstate->exc_info;
                    /* Unresolved local var: _PyErr_StackItem * exc_info@[???] */
        do {
          p_Var12 = p_Var22;
          pPVar10 = p_Var12->exc_value;
          if (pPVar10 != (PyObject *)0x0 && pPVar10 != pPVar15) {
            local_78 = p_Var12->exc_type;
            local_80 = p_Var12->exc_traceback;
            if (local_78 == (PyObject *)0x0) goto LAB_00110d4c;
            local_78->ob_refcnt = local_78->ob_refcnt + 1;
            goto LAB_00110d48;
          }
          p_Var22 = p_Var12->previous_item;
        } while (p_Var12->previous_item != (_err_stackitem *)0x0);
        local_78 = p_Var12->exc_type;
        local_80 = p_Var12->exc_traceback;
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
        if (local_78 != (PyObject *)0x0) {
          local_78->ob_refcnt = local_78->ob_refcnt + 1;
        }
LAB_00110d48:
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
        if (pPVar10 != (PyObject *)0x0) {
LAB_00110d4c:
          pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
        }
                    /* Unresolved local var: PyObject * _py_xincref_tmp@[???] */
        if (local_80 != (PyObject *)0x0) {
          local_80->ob_refcnt = local_80->ob_refcnt + 1;
        }
                    /* Unresolved local var: PyObject * tmp@[???] */
        pPVar17 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
        pPVar30 = (PyObject *)0x0;
LAB_00110da0:
        pPVar15 = __pyx_dict_cached_value_16961;
        if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_16960) {
          pPVar15 = __Pyx__GetModuleGlobalName
                              (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_MAX_BUSY_CYCLES,
                               (uint64_t *)&__pyx_dict_version_16960,&__pyx_dict_cached_value_16961)
          ;
LAB_001120b4:
          if (pPVar15 != (PyObject *)0x0) goto LAB_00110dcc;
          iVar3 = 0x5b;
          local_90._0_4_ = 0x1616;
          pPVar14 = (PyObject *)0x0;
          goto LAB_00111a1c;
        }
        if (__pyx_dict_cached_value_16961 == (PyObject *)0x0) {
          pPVar15 = __Pyx_GetBuiltinName
                              (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_MAX_BUSY_CYCLES);
          goto LAB_001120b4;
        }
        __pyx_dict_cached_value_16961->ob_refcnt = __pyx_dict_cached_value_16961->ob_refcnt + 1;
LAB_00110dcc:
        __pyx_t_7 = (PyObject *)PyObject_RichCompare(pPVar20,pPVar15,4);
        if (__pyx_t_7 == (PyObject *)0x0) {
          iVar3 = 0x5b;
          lVar11 = pPVar15->ob_refcnt + -1;
          pPVar14 = (PyObject *)0x0;
          local_90._0_4_ = 0x1618;
          goto LAB_00111a00;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = pPVar15->ob_refcnt + -1;
        pPVar15->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          (*pPVar15->ob_type->tp_dealloc)(pPVar15);
        }
                    /* Unresolved local var: int is_true@[???] */
        uVar5 = (uint)(__pyx_t_7 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
        pPVar16 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
        if (((uVar5 == 0 && __pyx_t_7 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
             __pyx_t_7 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
           (uVar5 = PyObject_IsTrue(), (int)uVar5 < 0)) {
          iVar3 = 0x5b;
          pPVar14 = (PyObject *)0x0;
          local_90._0_4_ = 0x161a;
          goto LAB_00111a1c;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = __pyx_t_7->ob_refcnt + -1;
        __pyx_t_7->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
        }
        pPVar15 = __pyx_dict_cached_value_16966;
        pPVar14 = __pyx_mstate_global_static.__pyx_int_1;
        __pyx_t_7 = (PyObject *)0x0;
        if (uVar5 == 0) {
          p_Var13 = pPVar20->ob_type;
          if (p_Var13 == (_typeobject *)PTR_PyLong_Type_0012ff80) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: long a@[???]
                       Unresolved local var: long x@[???]
                       Unresolved local var: longlong llb@[???]
                       Unresolved local var: longlong lla@[???]
                       Unresolved local var: longlong llx@[???] */
            lVar11 = pPVar20[1].ob_refcnt;
            if (lVar11 != 0) {
              if (lVar11 + 1U < 3) {
                iVar3 = *(int *)&pPVar20[1].ob_type;
                if (lVar11 < 0) {
                  iVar3 = -*(int *)&pPVar20[1].ob_type;
                }
                uVar21 = (ulong)iVar3;
              }
              else {
                    /* Unresolved local var: digit * digits@[???]
                       Unresolved local var: Py_ssize_t size@[???] */
                if (lVar11 == -2) {
                  uVar21 = -((ulong)*(uint *)&pPVar20[1].ob_type |
                            (ulong)*(uint *)((long)&pPVar20[1].ob_type + 4) << 0x1e);
                }
                else {
                  if (lVar11 != 2) {
                    __pyx_t_7 = (*p_Var13->tp_as_number->nb_add)
                                          (pPVar20,__pyx_mstate_global_static.__pyx_int_1);
                    goto LAB_00110e8c;
                  }
                  uVar21 = (ulong)*(uint *)&pPVar20[1].ob_type |
                           (ulong)*(uint *)((long)&pPVar20[1].ob_type + 4) << 0x1e;
                }
              }
              __pyx_t_7 = (PyObject *)PyLong_FromLong(uVar21 + 1);
              goto LAB_00110e8c;
            }
            (__pyx_mstate_global_static.__pyx_int_1)->ob_refcnt =
                 (__pyx_mstate_global_static.__pyx_int_1)->ob_refcnt + 1;
            __pyx_t_7 = pPVar14;
          }
          else {
            if (p_Var13 == (_typeobject *)PTR_PyFloat_Type_0012feb0) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: double a@[???]
                       Unresolved local var: double result@[???] */
              __pyx_t_7 = (PyObject *)PyFloat_FromDouble((double)pPVar20[1].ob_refcnt + 1.0);
            }
            else {
              __pyx_t_7 = (PyObject *)
                          PyNumber_InPlaceAdd(pPVar20,__pyx_mstate_global_static.__pyx_int_1);
            }
LAB_00110e8c:
            if (__pyx_t_7 == (PyObject *)0x0) {
              pPVar14 = (PyObject *)0x0;
              iVar3 = 0x62;
              local_90._0_4_ = 0x16a1;
              __pyx_t_7 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
          }
          pPVar23 = __pyx_t_7;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar11 = pPVar20->ob_refcnt + -1;
          pPVar20->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*pPVar20->ob_type->tp_dealloc)(pPVar20);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          __pyx_t_7 = (PyObject *)0x0;
          p_Var24 = __pyx_self->ob_type->tp_getattro;
          if (p_Var24 == (getattrofunc)0x0) {
            pPVar14 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar14 = (*p_Var24)(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
          }
          pPVar20 = pPVar23;
          if (pPVar14 == (PyObject *)0x0) {
            iVar3 = 100;
            local_90._0_4_ = 0x16ad;
          }
          else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var24 = pPVar14->ob_type->tp_getattro;
            if (p_Var24 == (getattrofunc)0x0) {
              pPVar15 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar15 = (*p_Var24)(pPVar14,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
            }
            if (pPVar15 == (PyObject *)0x0) {
              iVar3 = 100;
              local_90._0_4_ = 0x16af;
              goto LAB_00111a1c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = pPVar14->ob_refcnt + -1;
            pPVar14->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar14->ob_type->tp_dealloc)(pPVar14);
              if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_16995)
              goto LAB_001119c8;
LAB_00110f10:
              pPVar14 = __pyx_dict_cached_value_16996;
              if (__pyx_dict_cached_value_16996 == (PyObject *)0x0) {
                pPVar14 = __Pyx_GetBuiltinName
                                    (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
                goto LAB_001119e4;
              }
              __pyx_dict_cached_value_16996->ob_refcnt =
                   __pyx_dict_cached_value_16996->ob_refcnt + 1;
            }
            else {
              if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16995)
              goto LAB_00110f10;
LAB_001119c8:
              pPVar14 = __Pyx__GetModuleGlobalName
                                  (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                                   (uint64_t *)&__pyx_dict_version_16995,
                                   &__pyx_dict_cached_value_16996);
LAB_001119e4:
              if (pPVar14 == (PyObject *)0x0) {
                iVar3 = 100;
                local_90._0_4_ = 0x16b2;
                lVar11 = pPVar15->ob_refcnt + -1;
                goto LAB_00111a00;
              }
            }
            if (pPVar14->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
              __pyx_t_9 = __Pyx_PyDict_GetItem(pPVar14,__pyx_mstate_global_static.__pyx_n_s_MEASURE)
              ;
            }
            else {
              __pyx_t_9 = (PyObject *)PyObject_GetItem();
            }
            if (__pyx_t_9 == (PyObject *)0x0) {
              iVar3 = 100;
              local_90._0_4_ = 0x16b4;
              lVar11 = pPVar15->ob_refcnt + -1;
              __pyx_t_9 = (PyObject *)0x0;
LAB_00111a00:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              pPVar15->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*pPVar15->ob_type->tp_dealloc)(pPVar15);
              }
              goto LAB_00111a1c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = pPVar14->ob_refcnt + -1;
            pPVar14->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar14->ob_type->tp_dealloc)(pPVar14);
            }
            local_70 = (PyObject *)0x12f000;
            p_Var13 = pPVar15->ob_type;
            if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (p_Var27 = pPVar15[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar14 = (PyObject *)pPVar15[1].ob_refcnt;
              (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
              pPVar14->ob_refcnt = pPVar14->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = pPVar15->ob_refcnt + -1;
              pPVar15->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*p_Var13->tp_dealloc)(pPVar15);
              }
              __pyx_callargs[1] = __pyx_t_9;
              __pyx_callargs[0] = (PyObject *)p_Var27;
              __pyx_t_7 = __Pyx_PyObject_FastCallDict(pPVar14,__pyx_callargs,2,pPVar16);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
              (p_Var27->ob_base).ob_base.ob_refcnt = lVar11;
              pPVar15 = pPVar14;
              if (lVar11 == 0) {
                (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
              }
            }
            else {
              __pyx_callargs[0] = (PyObject *)0x0;
              __pyx_callargs[1] = __pyx_t_9;
              __pyx_t_7 = __Pyx_PyObject_FastCallDict(pPVar15,__pyx_callargs + 1,1,pPVar16);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_9->ob_refcnt + -1;
            __pyx_t_9->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
            }
            __pyx_t_9 = (PyObject *)0x0;
            lVar11 = pPVar15->ob_refcnt + -1;
            if (__pyx_t_7 == (PyObject *)0x0) {
              iVar3 = 100;
              local_90._0_4_ = 0x16ca;
              pPVar14 = (PyObject *)0x0;
              goto LAB_00111a00;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            pPVar15->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar15->ob_type->tp_dealloc)(pPVar15);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_7->ob_refcnt + -1;
            __pyx_t_7->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
            }
            __pyx_t_7 = (PyObject *)0x0;
            pPVar15 = __Pyx_PyObject_GetAttrStr
                                (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
            if (pPVar15 == (PyObject *)0x0) {
              iVar3 = 0x66;
              local_90._0_4_ = 0x16d7;
              pPVar14 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
            __pyx_t_9 = __Pyx_PyObject_GetAttrStr
                                  (pPVar15,__pyx_mstate_global_static.__pyx_n_s_pause);
            if (__pyx_t_9 == (PyObject *)0x0) {
              iVar3 = 0x66;
              pPVar14 = (PyObject *)0x0;
              lVar11 = pPVar15->ob_refcnt + -1;
              local_90._0_4_ = 0x16d9;
              goto LAB_00111a00;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = pPVar15->ob_refcnt + -1;
            pPVar15->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar15->ob_type->tp_dealloc)(pPVar15);
            }
            pPVar14 = __Pyx_PyObject_GetAttrStr
                                (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
            if (pPVar14 == (PyObject *)0x0) {
              iVar3 = 0x66;
              local_90._0_4_ = 0x16dc;
              goto LAB_00111a1c;
            }
            __pyx_t_11 = __Pyx_PyObject_GetAttrStr
                                   (pPVar14,__pyx_mstate_global_static.__pyx_n_s_monotonic);
            if (__pyx_t_11 == (PyObject *)0x0) {
              iVar3 = 0x66;
              local_90._0_4_ = 0x16de;
              goto LAB_00111a40;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = pPVar14->ob_refcnt + -1;
            pPVar14->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar14->ob_type->tp_dealloc)(pPVar14);
            }
            pPVar15 = __pyx_t_11;
            p_Var13 = __pyx_t_11->ob_type;
            if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (p_Var27 = __pyx_t_11[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar14 = (PyObject *)__pyx_t_11[1].ob_refcnt;
              (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
              pPVar14->ob_refcnt = pPVar14->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_11->ob_refcnt + -1;
              __pyx_t_11->ob_refcnt = lVar11;
              __pyx_t_11 = pPVar14;
              if (lVar11 == 0) {
                (*p_Var13->tp_dealloc)(pPVar15);
              }
              iVar3 = 1;
              __pyx_callargs[1] = (PyObject *)0x0;
              __pyx_callargs[0] = (PyObject *)p_Var27;
              pPVar15 = __Pyx_PyObject_FastCallDict(__pyx_t_11,__pyx_callargs,1,(PyObject *)p_Var13)
              ;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
              (p_Var27->ob_base).ob_base.ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
              }
            }
            else {
              iVar3 = 0;
              __pyx_callargs[0] = (PyObject *)0x0;
              __pyx_callargs[1] = (PyObject *)0x0;
              pPVar15 = __Pyx_PyObject_FastCallDict
                                  (__pyx_t_11,__pyx_callargs + 1,0,(PyObject *)p_Var13);
            }
            if (pPVar15 == (PyObject *)0x0) {
              iVar3 = 0x66;
              local_90._0_4_ = 0x16f3;
              pPVar14 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_11->ob_refcnt + -1;
            __pyx_t_11->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
            }
            __pyx_t_11 = (PyObject *)0x0;
            __pyx_t_11 = __Pyx_PyFloat_AddObjC
                                   (pPVar15,__pyx_mstate_global_static.__pyx_float__600,0.6,iVar3,
                                    (int)p_Var13);
            if (__pyx_t_11 == (PyObject *)0x0) {
              iVar3 = 0x66;
              pPVar14 = (PyObject *)0x0;
              lVar11 = pPVar15->ob_refcnt + -1;
              local_90._0_4_ = 0x16f7;
              __pyx_t_11 = (PyObject *)0x0;
              goto LAB_00111a00;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = pPVar15->ob_refcnt + -1;
            pPVar15->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar15->ob_type->tp_dealloc)(pPVar15);
            }
            pPVar15 = __pyx_t_9;
            p_Var27 = __pyx_t_9->ob_type;
            if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (p_Var28 = __pyx_t_9[1].ob_type, p_Var28 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar14 = (PyObject *)__pyx_t_9[1].ob_refcnt;
              (p_Var28->ob_base).ob_base.ob_refcnt = (p_Var28->ob_base).ob_base.ob_refcnt + 1;
              pPVar14->ob_refcnt = pPVar14->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_9->ob_refcnt + -1;
              __pyx_t_9->ob_refcnt = lVar11;
              __pyx_t_9 = pPVar14;
              if (lVar11 == 0) {
                (*p_Var27->tp_dealloc)(pPVar15);
              }
              __pyx_callargs[1] = __pyx_t_11;
              __pyx_callargs[0] = (PyObject *)p_Var28;
              __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                    (__pyx_t_9,__pyx_callargs,2,(PyObject *)p_Var13);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = (p_Var28->ob_base).ob_base.ob_refcnt + -1;
              (p_Var28->ob_base).ob_base.ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
              }
            }
            else {
              __pyx_callargs[0] = (PyObject *)0x0;
              __pyx_callargs[1] = __pyx_t_11;
              p_Var13 = (_typeobject *)__pyx_t_11;
              __pyx_t_7 = __Pyx_PyObject_FastCallDict(__pyx_t_9,__pyx_callargs + 1,1,__pyx_t_11);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_11->ob_refcnt + -1;
            __pyx_t_11->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
            }
            __pyx_t_11 = (PyObject *)0x0;
            pPVar15 = pPVar17;
            if (__pyx_t_7 == (PyObject *)0x0) {
              iVar3 = 0x66;
              local_90._0_4_ = 0x170d;
              pPVar16 = pPVar30;
              goto LAB_00111a8c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_9->ob_refcnt + -1;
            __pyx_t_9->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            __pyx_t_9 = (PyObject *)0x0;
            lVar11 = __pyx_t_7->ob_refcnt + -1;
            __pyx_t_7->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
            }
            __pyx_t_7 = (PyObject *)0x0;
            __pyx_t_9 = __Pyx_PyObject_GetAttrStr
                                  (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
            if (__pyx_t_9 == (PyObject *)0x0) {
              iVar3 = 0x69;
              local_90._0_4_ = 0x171a;
              pPVar14 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
            __pyx_t_11 = __Pyx_PyObject_GetAttrStr
                                   (__pyx_t_9,__pyx_mstate_global_static.__pyx_n_s_i2c_read);
            if (__pyx_t_11 == (PyObject *)0x0) {
              iVar3 = 0x69;
              local_90._0_4_ = 0x171c;
              pPVar14 = (PyObject *)0x0;
              goto LAB_00111a40;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_9->ob_refcnt + -1;
            __pyx_t_9->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
            }
            __pyx_t_9 = (PyObject *)0x0;
            __pyx_t_9 = (PyObject *)PyList_New(0);
            pPVar14 = __pyx_t_11;
            if (__pyx_t_9 == (PyObject *)0x0) {
              iVar3 = 0x69;
              local_90._0_4_ = 0x171f;
              pPVar14 = (PyObject *)0x0;
              __pyx_t_9 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
            p_Var27 = __pyx_t_11->ob_type;
            if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (p_Var28 = __pyx_t_11[1].ob_type, p_Var28 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar16 = (PyObject *)__pyx_t_11[1].ob_refcnt;
              (p_Var28->ob_base).ob_base.ob_refcnt = (p_Var28->ob_base).ob_base.ob_refcnt + 1;
              pPVar16->ob_refcnt = pPVar16->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_11->ob_refcnt + -1;
              __pyx_t_11->ob_refcnt = lVar11;
              __pyx_t_11 = pPVar16;
              if (lVar11 == 0) {
                (*p_Var27->tp_dealloc)(pPVar14);
              }
              __pyx_callargs[0] = (PyObject *)p_Var28;
              __pyx_callargs[1] = __pyx_t_9;
              __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                    (__pyx_t_11,__pyx_callargs,3,(PyObject *)p_Var13);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = (p_Var28->ob_base).ob_base.ob_refcnt + -1;
              (p_Var28->ob_base).ob_base.ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
              }
            }
            else {
              __pyx_callargs[0] = (PyObject *)0x0;
              __pyx_callargs[1] = __pyx_t_9;
              __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                    (__pyx_t_11,__pyx_callargs + 1,2,(PyObject *)p_Var13);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_9->ob_refcnt + -1;
            __pyx_t_9->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
            }
            __pyx_t_9 = (PyObject *)0x0;
            if (__pyx_t_7 == (PyObject *)0x0) {
              iVar3 = 0x69;
              local_90._0_4_ = 0x1734;
              pPVar14 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_11->ob_refcnt + -1;
            __pyx_t_11->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
            }
            pPVar16 = __pyx_t_7;
            __pyx_t_11 = (PyObject *)0x0;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            if ((pPVar30 != (PyObject *)0x0) &&
               (lVar11 = pPVar30->ob_refcnt + -1, pPVar30->ob_refcnt = lVar11, lVar11 == 0)) {
              (*pPVar30->ob_type->tp_dealloc)(pPVar30);
            }
            pPVar14 = __pyx_dict_cached_value_17039;
            __pyx_t_7 = (PyObject *)0x0;
            pPVar30 = pPVar16;
            if (pPVar16 == (PyObject *)PTR__Py_NoneStruct_0012ff50) {
              if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17038) {
                if (__pyx_dict_cached_value_17039 == (PyObject *)0x0) {
                  pPVar14 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
                  goto LAB_001134ac;
                }
                __pyx_dict_cached_value_17039->ob_refcnt =
                     __pyx_dict_cached_value_17039->ob_refcnt + 1;
              }
              else {
                pPVar14 = __Pyx__GetModuleGlobalName
                                    (__pyx_mstate_global_static.__pyx_n_s_logging,
                                     (uint64_t *)&__pyx_dict_version_17038,
                                     &__pyx_dict_cached_value_17039);
LAB_001134ac:
                if (pPVar14 == (PyObject *)0x0) {
                  iVar3 = 0x6b;
                  pPVar14 = (PyObject *)0x0;
                  local_90._0_4_ = 0x174c;
                  goto LAB_00111a40;
                }
              }
              __pyx_t_11 = pPVar14;
              __pyx_t_9 = __Pyx_PyObject_GetAttrStr
                                    (pPVar14,__pyx_mstate_global_static.__pyx_n_s_warning);
              if (__pyx_t_9 == (PyObject *)0x0) {
                iVar3 = 0x6b;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x174e;
                goto LAB_00111a1c;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_11->ob_refcnt + -1;
              __pyx_t_11->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
              }
              __pyx_t_11 = (PyObject *)0x0;
              __pyx_t_11 = (PyObject *)
                           PyUnicode_Concat(__pyx_mstate_global_static.
                                            __pyx_kp_s_aht20_f_received_data_from,
                                            __pyx_mstate_global_static.__pyx_kp_s_i2c_read_is_None);
              pPVar14 = __pyx_t_9;
              if (__pyx_t_11 == (PyObject *)0x0) {
                iVar3 = 0x6b;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x1751;
                goto LAB_00111a40;
              }
              p_Var27 = __pyx_t_9->ob_type;
              if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                 (p_Var28 = __pyx_t_9[1].ob_type, p_Var28 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar29 = (PyObject *)__pyx_t_9[1].ob_refcnt;
                (p_Var28->ob_base).ob_base.ob_refcnt = (p_Var28->ob_base).ob_base.ob_refcnt + 1;
                pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar11 = __pyx_t_9->ob_refcnt + -1;
                __pyx_t_9->ob_refcnt = lVar11;
                __pyx_t_9 = pPVar29;
                if (lVar11 == 0) {
                  (*p_Var27->tp_dealloc)(pPVar14);
                }
                __pyx_callargs[1] = __pyx_t_11;
                __pyx_callargs[0] = (PyObject *)p_Var28;
                __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                      (__pyx_t_9,__pyx_callargs,2,(PyObject *)p_Var13);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar11 = (p_Var28->ob_base).ob_base.ob_refcnt + -1;
                (p_Var28->ob_base).ob_base.ob_refcnt = lVar11;
                if (lVar11 == 0) {
                  (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
                }
              }
              else {
                __pyx_callargs[0] = (PyObject *)0x0;
                __pyx_callargs[1] = __pyx_t_11;
                __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                      (__pyx_t_9,__pyx_callargs + 1,1,(PyObject *)p_Var13);
              }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_11->ob_refcnt + -1;
              __pyx_t_11->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
              }
              __pyx_t_11 = (PyObject *)0x0;
              if (__pyx_t_7 == (PyObject *)0x0) {
                iVar3 = 0x6b;
                local_90._0_4_ = 0x1766;
                goto LAB_00111a8c;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_9->ob_refcnt + -1;
              __pyx_t_9->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              __pyx_t_9 = (PyObject *)0x0;
              lVar11 = __pyx_t_7->ob_refcnt + -1;
              __pyx_t_7->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
              }
              __pyx_t_7 = (PyObject *)0x0;
              goto LAB_00110da0;
            }
            if (pPVar16->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
              __pyx_t_7 = __Pyx_PyDict_GetItem
                                    (pPVar16,__pyx_mstate_global_static.__pyx_n_s_response);
            }
            else {
              __pyx_t_7 = (PyObject *)PyObject_GetItem();
            }
            if (__pyx_t_7 == (PyObject *)0x0) {
              iVar3 = 0x6e;
              pPVar14 = (PyObject *)0x0;
              local_90._0_4_ = 0x1785;
              goto LAB_00111a1c;
            }
            iVar3 = 1;
            __pyx_callargs[0] = (PyObject *)0x0;
            __pyx_callargs[1] = __pyx_t_7;
            __pyx_t_9 = __Pyx_PyObject_FastCallDict
                                  ((PyObject *)PTR_PyByteArray_Type_0012fed0,__pyx_callargs + 1,
                                   0x8000000000000001,(PyObject *)p_Var13);
            if (__pyx_t_9 == (PyObject *)0x0) {
              iVar3 = 0x6e;
              pPVar14 = (PyObject *)0x0;
              local_90._0_4_ = 0x1787;
              __pyx_t_9 = (PyObject *)0x0;
              goto LAB_00111a1c;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_7->ob_refcnt + -1;
            __pyx_t_7->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
            }
            pPVar15 = __pyx_t_9;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            __pyx_t_7 = (PyObject *)0x0;
            lVar11 = pPVar17->ob_refcnt + -1;
            pPVar17->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar17->ob_type->tp_dealloc)(pPVar17);
            }
            pPVar29 = __pyx_dict_cached_value_17055;
            __pyx_t_9 = (PyObject *)0x0;
            pPVar17 = pPVar15;
            if (pPVar15[1].ob_refcnt == -1) {
              iVar3 = 0x6f;
              pPVar14 = (PyObject *)0x0;
              local_90._0_4_ = 0x1794;
              goto LAB_00111a1c;
            }
            if (6 < pPVar15[1].ob_refcnt) {
              uVar5 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,0,iVar3,(int)p_Var13);
              if (uVar5 == 0xffffffff) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17ef;
                goto LAB_00111a1c;
              }
              if ((uVar5 >> 7 & 1) != 0) goto LAB_00110da0;
              iVar3 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,6,iVar3,(int)p_Var13);
              if (iVar3 == -1) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17f6;
                goto LAB_00111a1c;
              }
                    /* Unresolved local var: int neg_one@[???]
                       Unresolved local var: int const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
              __pyx_t_9 = (PyObject *)PyLong_FromLong((long)iVar3);
              if (__pyx_t_9 == (PyObject *)0x0) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17f7;
                goto LAB_00111a1c;
              }
              __pyx_t_7 = __Pyx_PyObject_GetAttrStr
                                    (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_check_crc8);
              if (__pyx_t_7 == (PyObject *)0x0) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17f9;
                goto LAB_00111a1c;
              }
              pPVar14 = (PyObject *)PySequence_GetSlice(pPVar15,0,6);
              if (pPVar14 == (PyObject *)0x0) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17fb;
                goto LAB_00111a1c;
              }
              if ((__pyx_t_7->ob_type == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                 (p_Var13 = __pyx_t_7[1].ob_type, p_Var13 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                pPVar29 = (PyObject *)__pyx_t_7[1].ob_refcnt;
                (p_Var13->ob_base).ob_base.ob_refcnt = (p_Var13->ob_base).ob_base.ob_refcnt + 1;
                pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar11 = __pyx_t_7->ob_refcnt + -1;
                __pyx_t_7->ob_refcnt = lVar11;
                __pyx_t_7 = pPVar29;
                if (lVar11 == 0) {
                  (**(code **)(PTR_PyMethod_Type_0012fea0 + 0x30))();
                }
                pPVar29 = __pyx_mstate_global_static.__pyx_int_6;
                __pyx_callargs[0] = (PyObject *)p_Var13;
                __pyx_callargs[1] = pPVar14;
                __pyx_t_11 = __Pyx_PyObject_FastCallDict(__pyx_t_7,__pyx_callargs,3,local_70);
                iVar3 = (int)local_70;
                iVar4 = (int)pPVar29;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar11 = (p_Var13->ob_base).ob_base.ob_refcnt + -1;
                (p_Var13->ob_base).ob_base.ob_refcnt = lVar11;
                if (lVar11 == 0) {
                  (*((p_Var13->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var13);
                }
              }
              else {
                __pyx_callargs[0] = (PyObject *)0x0;
                pPVar29 = __pyx_mstate_global_static.__pyx_int_6;
                __pyx_callargs[1] = pPVar14;
                __pyx_t_11 = __Pyx_PyObject_FastCallDict
                                       (__pyx_t_7,__pyx_callargs + 1,2,(PyObject *)0x12f000);
                iVar3 = (int)local_70;
                iVar4 = (int)pPVar29;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = pPVar14->ob_refcnt + -1;
              pPVar14->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*pPVar14->ob_type->tp_dealloc)(pPVar14);
              }
              if (__pyx_t_11 == (PyObject *)0x0) {
                pPVar14 = (PyObject *)0x0;
                iVar3 = 0x77;
                local_90._0_4_ = 0x1810;
                goto LAB_00111a40;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_7->ob_refcnt + -1;
              __pyx_t_7->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
              }
              __pyx_t_7 = (PyObject *)0x0;
              __pyx_t_7 = (PyObject *)PyObject_RichCompare(__pyx_t_9,__pyx_t_11,2);
              if (__pyx_t_7 == (PyObject *)0x0) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x1814;
                goto LAB_00111a1c;
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_9->ob_refcnt + -1;
              __pyx_t_9->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              __pyx_t_9 = (PyObject *)0x0;
              lVar11 = __pyx_t_11->ob_refcnt + -1;
              __pyx_t_11->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
              }
                    /* Unresolved local var: int is_true@[???] */
              __pyx_t_11 = (PyObject *)0x0;
              uVar5 = (uint)(__pyx_t_7 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
              puVar25 = PTR__Py_FalseStruct_0012ff20;
              if (((__pyx_t_7 != (PyObject *)PTR__Py_TrueStruct_0012ff58 &&
                   __pyx_t_7 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
                   __pyx_t_7 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
                 (uVar5 = PyObject_IsTrue(), (int)uVar5 < 0)) {
                iVar3 = 0x77;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x1817;
                goto LAB_00111a1c;
              }
              iVar8 = (int)puVar25;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_7->ob_refcnt + -1;
              __pyx_t_7->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
              }
              __pyx_t_7 = (PyObject *)0x0;
              if (uVar5 != 0) goto code_r0x00112f98;
              goto LAB_00110da0;
            }
            if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17054) {
              if (__pyx_dict_cached_value_17055 == (PyObject *)0x0) {
                pPVar29 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
                goto LAB_00113448;
              }
              __pyx_dict_cached_value_17055->ob_refcnt =
                   __pyx_dict_cached_value_17055->ob_refcnt + 1;
            }
            else {
              pPVar29 = __Pyx__GetModuleGlobalName
                                  (__pyx_mstate_global_static.__pyx_n_s_logging,
                                   (uint64_t *)&__pyx_dict_version_17054,
                                   &__pyx_dict_cached_value_17055);
LAB_00113448:
              if (pPVar29 == (PyObject *)0x0) {
                iVar3 = 0x70;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x179f;
                __pyx_t_7 = pPVar29;
                goto LAB_00111a1c;
              }
            }
            __pyx_t_7 = pPVar29;
            __pyx_t_11 = __Pyx_PyObject_GetAttrStr
                                   (pPVar29,__pyx_mstate_global_static.__pyx_n_s_warning);
            if (__pyx_t_11 == (PyObject *)0x0) {
              iVar3 = 0x70;
              pPVar14 = (PyObject *)0x0;
              local_90._0_4_ = 0x17a1;
              goto LAB_00111a40;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_7->ob_refcnt + -1;
            __pyx_t_7->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
            }
            __pyx_t_7 = (PyObject *)0x0;
            if (pPVar15[1].ob_refcnt == -1) {
              iVar3 = 0x71;
              pPVar14 = (PyObject *)0x0;
              local_90._0_4_ = 0x17ac;
            }
            else {
              __pyx_t_7 = (PyObject *)PyLong_FromSsize_t();
              if (__pyx_t_7 == (PyObject *)0x0) {
                iVar3 = 0x71;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17ad;
              }
              else {
                pPVar15 = (PyObject *)
                          PyUnicode_Format(__pyx_mstate_global_static.__pyx_kp_s_expected_7_d,
                                           __pyx_t_7);
                if (pPVar15 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = __pyx_t_7->ob_refcnt + -1;
                  __pyx_t_7->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
                  }
                  __pyx_t_7 = (PyObject *)0x0;
                  __pyx_t_7 = (PyObject *)
                              PyUnicode_Concat(__pyx_mstate_global_static.
                                               __pyx_kp_s_aht20_f_received_bytes_less_than,pPVar15);
                  if (__pyx_t_7 == (PyObject *)0x0) {
                    pPVar14 = (PyObject *)0x0;
                    iVar3 = 0x70;
                    lVar11 = pPVar15->ob_refcnt + -1;
                    local_90._0_4_ = 0x17ba;
                    __pyx_t_7 = (PyObject *)0x0;
                    goto LAB_00111a00;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = pPVar15->ob_refcnt + -1;
                  pPVar15->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    (*pPVar15->ob_type->tp_dealloc)(pPVar15);
                  }
                  pPVar15 = __pyx_t_11;
                  p_Var27 = __pyx_t_11->ob_type;
                  if ((p_Var27 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                     (p_Var28 = __pyx_t_11[1].ob_type, p_Var28 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar14 = (PyObject *)__pyx_t_11[1].ob_refcnt;
                    (p_Var28->ob_base).ob_base.ob_refcnt = (p_Var28->ob_base).ob_base.ob_refcnt + 1;
                    pPVar14->ob_refcnt = pPVar14->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar11 = __pyx_t_11->ob_refcnt + -1;
                    __pyx_t_11->ob_refcnt = lVar11;
                    __pyx_t_11 = pPVar14;
                    if (lVar11 == 0) {
                      (*p_Var27->tp_dealloc)(pPVar15);
                    }
                    __pyx_callargs[1] = __pyx_t_7;
                    __pyx_callargs[0] = (PyObject *)p_Var28;
                    __pyx_t_9 = __Pyx_PyObject_FastCallDict
                                          (__pyx_t_11,__pyx_callargs,2,(PyObject *)p_Var13);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar11 = (p_Var28->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var28->ob_base).ob_base.ob_refcnt = lVar11;
                    if (lVar11 == 0) {
                      (*((p_Var28->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var28);
                    }
                  }
                  else {
                    __pyx_callargs[0] = (PyObject *)0x0;
                    __pyx_callargs[1] = __pyx_t_7;
                    __pyx_t_9 = __Pyx_PyObject_FastCallDict
                                          (__pyx_t_11,__pyx_callargs + 1,1,(PyObject *)p_Var13);
                  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = __pyx_t_7->ob_refcnt + -1;
                  __pyx_t_7->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
                  }
                  __pyx_t_7 = (PyObject *)0x0;
                  if (__pyx_t_9 == (PyObject *)0x0) {
                    pPVar14 = (PyObject *)0x0;
                    iVar3 = 0x70;
                    local_90._0_4_ = 0x17d0;
                    goto LAB_00111a1c;
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = __pyx_t_11->ob_refcnt + -1;
                  __pyx_t_11->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
                  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  __pyx_t_11 = (PyObject *)0x0;
                  lVar11 = __pyx_t_9->ob_refcnt + -1;
                  __pyx_t_9->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
                  }
                  __pyx_t_9 = (PyObject *)0x0;
                  goto LAB_00110da0;
                }
                iVar3 = 0x71;
                pPVar14 = (PyObject *)0x0;
                local_90._0_4_ = 0x17af;
              }
            }
          }
        }
        else {
          kwargs = &__pyx_mstate_global_static;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16965) {
            if (__pyx_dict_cached_value_16966 == (PyObject *)0x0) {
              pPVar15 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
              goto LAB_001137a0;
            }
            __pyx_dict_cached_value_16966->ob_refcnt = __pyx_dict_cached_value_16966->ob_refcnt + 1;
          }
          else {
            pPVar15 = __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_logging,
                                 (uint64_t *)&__pyx_dict_version_16965,
                                 &__pyx_dict_cached_value_16966);
LAB_001137a0:
            if (pPVar15 == (PyObject *)0x0) {
              pPVar14 = (PyObject *)0x0;
              iVar3 = 0x5c;
              local_90._0_4_ = 0x1627;
              goto LAB_00111a1c;
            }
          }
          pPVar14 = __Pyx_PyObject_GetAttrStr(pPVar15,__pyx_mstate_global_static.__pyx_n_s_warning);
          if (pPVar14 == (PyObject *)0x0) {
            iVar3 = 0x5c;
            lVar11 = pPVar15->ob_refcnt + -1;
            local_90._0_4_ = 0x1629;
            goto LAB_00111a00;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar11 = pPVar15->ob_refcnt + -1;
          pPVar15->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*pPVar15->ob_type->tp_dealloc)(pPVar15);
          }
          pPVar15 = __pyx_dict_cached_value_16969;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_16968) {
            if (__pyx_dict_cached_value_16969 == (PyObject *)0x0) {
              pPVar15 = __Pyx_GetBuiltinName
                                  (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_MAX_BUSY_CYCLES);
              goto LAB_00113948;
            }
            __pyx_dict_cached_value_16969->ob_refcnt = __pyx_dict_cached_value_16969->ob_refcnt + 1;
          }
          else {
            pPVar15 = __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_MAX_BUSY_CYCLES,
                                 (uint64_t *)&__pyx_dict_version_16968,
                                 &__pyx_dict_cached_value_16969);
LAB_00113948:
            if (pPVar15 == (PyObject *)0x0) {
              iVar3 = 0x5d;
              local_90._0_4_ = 0x1634;
              goto LAB_00111a1c;
            }
          }
          if ((__pyx_mstate_global_static.__pyx_kp_s_d_cycles_resetting_device ==
               (PyObject *)PTR__Py_NoneStruct_0012ff50) ||
             ((pPVar15->ob_type->tp_flags & 0x10000000) != 0 &&
              pPVar15->ob_type != (_typeobject *)PTR_PyUnicode_Type_0012ffb0)) {
            __pyx_t_9 = (PyObject *)
                        PyNumber_Remainder(__pyx_mstate_global_static.
                                           __pyx_kp_s_d_cycles_resetting_device,pPVar15);
          }
          else {
            __pyx_t_9 = (PyObject *)
                        PyUnicode_Format(__pyx_mstate_global_static.
                                         __pyx_kp_s_d_cycles_resetting_device,pPVar15);
          }
          lVar11 = pPVar15->ob_refcnt + -1;
          if (__pyx_t_9 == (PyObject *)0x0) {
            iVar3 = 0x5d;
            local_90._0_4_ = 0x1636;
            goto LAB_00111a00;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          pPVar15->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*pPVar15->ob_type->tp_dealloc)(pPVar15);
          }
          pPVar15 = (PyObject *)
                    PyUnicode_Concat(__pyx_mstate_global_static.
                                     __pyx_kp_s_aht20_f_device_reported_busy_aft,__pyx_t_9);
          if (pPVar15 == (PyObject *)0x0) {
            iVar3 = 0x5c;
            local_90._0_4_ = 0x1641;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = __pyx_t_9->ob_refcnt + -1;
            __pyx_t_9->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
            }
            _nargs = 1;
            __pyx_t_9 = (PyObject *)0x0;
            p_Var13 = pPVar14->ob_type;
            lVar11 = 8;
            if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (__pyx_t_9 = (PyObject *)pPVar14[1].ob_type,
               (_typeobject *)__pyx_t_9 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar23 = (PyObject *)pPVar14[1].ob_refcnt;
              (((_typeobject *)__pyx_t_9)->ob_base).ob_base.ob_refcnt =
                   (((_typeobject *)__pyx_t_9)->ob_base).ob_base.ob_refcnt + 1;
              pPVar23->ob_refcnt = pPVar23->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = pPVar14->ob_refcnt + -1;
              pPVar14->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*p_Var13->tp_dealloc)(pPVar14);
                _nargs = 2;
                lVar11 = 0;
                pPVar14 = pPVar23;
              }
              else {
                _nargs = 2;
                lVar11 = 0;
                pPVar14 = pPVar23;
              }
            }
            __pyx_callargs[0] = __pyx_t_9;
            __pyx_callargs[1] = pPVar15;
            __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                  (pPVar14,(PyObject **)((long)__pyx_callargs + lVar11),_nargs,
                                   (PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            if ((__pyx_t_9 != (PyObject *)0x0) &&
               (lVar11 = __pyx_t_9->ob_refcnt + -1, __pyx_t_9->ob_refcnt = lVar11, lVar11 == 0)) {
              (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            __pyx_t_9 = (PyObject *)0x0;
            lVar11 = pPVar15->ob_refcnt + -1;
            pPVar15->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              (*pPVar15->ob_type->tp_dealloc)(pPVar15);
            }
            if (__pyx_t_7 == (PyObject *)0x0) {
              iVar3 = 0x5c;
              local_90._0_4_ = 0x1657;
            }
            else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = pPVar14->ob_refcnt + -1;
              pPVar14->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*pPVar14->ob_type->tp_dealloc)(pPVar14);
              }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar11 = __pyx_t_7->ob_refcnt + -1;
              __pyx_t_7->ob_refcnt = lVar11;
              if (lVar11 == 0) {
                (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
              }
              __pyx_t_7 = (PyObject *)0x0;
              pPVar14 = __Pyx_PyObject_GetAttrStr
                                  (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reset_device);
              if (pPVar14 != (PyObject *)0x0) {
                p_Var13 = pPVar14->ob_type;
                if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                   (p_Var27 = pPVar14[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar15 = (PyObject *)pPVar14[1].ob_refcnt;
                  (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
                  pPVar15->ob_refcnt = pPVar15->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = pPVar14->ob_refcnt + -1;
                  pPVar14->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    (*p_Var13->tp_dealloc)(pPVar14);
                  }
                  __pyx_callargs[1] = (PyObject *)0x0;
                  __pyx_callargs[0] = (PyObject *)p_Var27;
                  __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                        (pPVar15,__pyx_callargs,1,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var27->ob_base).ob_base.ob_refcnt = lVar11;
                  pPVar14 = pPVar15;
                  if (lVar11 == 0) {
                    (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
                  }
                }
                else {
                  __pyx_callargs[0] = (PyObject *)0x0;
                  __pyx_callargs[1] = (PyObject *)0x0;
                  __pyx_t_7 = __Pyx_PyObject_FastCallDict
                                        (pPVar14,__pyx_callargs + 1,0,(PyObject *)kwargs);
                }
                if (__pyx_t_7 == (PyObject *)0x0) {
                  iVar3 = 0x5e;
                  local_90._0_4_ = 0x1678;
                  goto LAB_00111a1c;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar11 = pPVar14->ob_refcnt + -1;
                pPVar14->ob_refcnt = lVar11;
                if (lVar11 == 0) {
                  (*pPVar14->ob_type->tp_dealloc)(pPVar14);
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar11 = __pyx_t_7->ob_refcnt + -1;
                __pyx_t_7->ob_refcnt = lVar11;
                if (lVar11 == 0) {
                  (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
                }
                *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                __pyx_t_7 = (PyObject *)0x0;
                lVar11 = pPVar17->ob_refcnt + -1;
                pPVar17->ob_refcnt = lVar11;
                if (lVar11 == 0) {
                  (*pPVar17->ob_type->tp_dealloc)(pPVar17);
                }
                p_Var22 = tstate->exc_info;
                    /* Unresolved local var: PyObject * tmp_type@[???]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???]
                       Unresolved local var: _PyErr_StackItem * exc_info@[???] */
                pPVar15 = p_Var22->exc_type;
                pPVar17 = p_Var22->exc_value;
                *(long *)PTR__Py_FalseStruct_0012ff20 = *(long *)PTR__Py_FalseStruct_0012ff20 + 1;
                p_Var22->exc_type = local_78;
                p_Var22->exc_value = pPVar10;
                pPVar10 = p_Var22->exc_traceback;
                p_Var22->exc_traceback = local_80;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                if ((pPVar15 != (PyObject *)0x0) &&
                   (lVar11 = pPVar15->ob_refcnt + -1, pPVar15->ob_refcnt = lVar11, lVar11 == 0)) {
                  (*pPVar15->ob_type->tp_dealloc)(pPVar15);
                }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                if ((pPVar17 != (PyObject *)0x0) &&
                   (lVar11 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar11, lVar11 == 0)) {
                  (*pPVar17->ob_type->tp_dealloc)(pPVar17);
                }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                if (pPVar10 == (PyObject *)0x0) {
                  pPVar14 = (PyObject *)0x0;
                  pPVar17 = (PyObject *)0x0;
                  pPVar15 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                  pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
                }
                else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar11 = pPVar10->ob_refcnt + -1;
                  pPVar10->ob_refcnt = lVar11;
                  if (lVar11 == 0) {
                    pPVar14 = (PyObject *)0x0;
                    pPVar17 = (PyObject *)0x0;
                    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                    pPVar15 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                    pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
                  }
                  else {
                    pPVar14 = (PyObject *)0x0;
                    pPVar17 = (PyObject *)0x0;
                    pPVar15 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                    pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
                  }
                }
                goto LAB_00111764;
              }
              pPVar14 = (PyObject *)0x0;
              iVar3 = 0x5e;
              local_90._0_4_ = 0x1664;
            }
          }
        }
LAB_00111a1c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((__pyx_t_11 != (PyObject *)0x0) &&
           (lVar11 = __pyx_t_11->ob_refcnt + -1, __pyx_t_11->ob_refcnt = lVar11, lVar11 == 0)) {
          (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
        }
LAB_00111a40:
        __pyx_t_11 = (PyObject *)0x0;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((__pyx_t_7 != (PyObject *)0x0) &&
           (lVar11 = __pyx_t_7->ob_refcnt + -1, __pyx_t_7->ob_refcnt = lVar11, lVar11 == 0)) {
          (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
        }
        __pyx_t_7 = (PyObject *)0x0;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        pPVar15 = pPVar17;
        pPVar23 = pPVar20;
        pPVar16 = pPVar30;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((pPVar14 != (PyObject *)0x0) &&
           (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
          (*pPVar14->ob_type->tp_dealloc)(pPVar14);
        }
LAB_00111a8c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if ((__pyx_t_9 != (PyObject *)0x0) &&
           (lVar11 = __pyx_t_9->ob_refcnt + -1, __pyx_t_9->ob_refcnt = lVar11, lVar11 == 0)) {
          (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
        }
        __pyx_t_9 = (PyObject *)0x0;
        pPVar17 = tstate->curexc_type;
        pPVar14 = *(PyObject **)PTR_PyExc_Exception_0012fef0;
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * exc_type@[???] */
        if (pPVar14 == pPVar17) goto LAB_00111be8;
        if (pPVar17 == (PyObject *)0x0) goto LAB_00111b44;
        uVar5 = (uint)pPVar14->ob_type->tp_flags;
        if ((uVar5 >> 0x1a & 1) == 0) {
          if (((((int)pPVar17->ob_type->tp_flags < 0) &&
               (((uint)pPVar17[10].ob_type >> 0x1e & 1) != 0)) && ((int)uVar5 < 0)) &&
             (((uint)pPVar14[10].ob_type >> 0x1e & 1) != 0)) {
                    /* Unresolved local var: PyObject * mro@[???] */
            p_Var13 = pPVar17[0x15].ob_type;
            if (p_Var13 == (_typeobject *)0x0) goto LAB_00111bdc;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
            lVar11 = (p_Var13->ob_base).ob_size;
            if (lVar11 < 1) goto LAB_00111b44;
            if (pPVar14 == (PyObject *)p_Var13->tp_name) goto LAB_00111be8;
            lVar18 = 0;
            goto LAB_00111b38;
          }
          iVar4 = PyErr_GivenExceptionMatches();
        }
        else {
          iVar4 = __Pyx_PyErr_ExceptionMatchesTuple(pPVar17,pPVar14);
        }
        if (iVar4 == 0) goto LAB_00111b44;
        goto LAB_00111be8;
      }
      pPVar29->ob_refcnt = pPVar29->ob_refcnt + 1;
      goto LAB_00110c88;
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      iVar3 = 0x4f;
      local_90._0_4_ = 0x15b9;
      pPVar14 = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      pPVar23 = (PyObject *)0x0;
      pPVar15 = (PyObject *)0x0;
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    else {
      pPVar14 = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      pPVar16 = (PyObject *)0x0;
      pPVar23 = (PyObject *)0x0;
      pPVar15 = (PyObject *)0x0;
      iVar3 = 0x4f;
      local_90._0_4_ = 0x15b9;
    }
  }
  goto LAB_001116d4;
code_r0x00112f98:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_78 != (PyObject *)0x0) &&
     (lVar11 = local_78->ob_refcnt + -1, local_78->ob_refcnt = lVar11, lVar11 == 0)) {
    (*local_78->ob_type->tp_dealloc)(local_78);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar10 != (PyObject *)0x0) &&
     (lVar11 = pPVar10->ob_refcnt + -1, pPVar10->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_80 != (PyObject *)0x0) &&
     (lVar11 = local_80->ob_refcnt + -1, local_80->ob_refcnt = lVar11, lVar11 == 0)) {
    (*local_80->ob_type->tp_dealloc)(local_80);
  }
  uVar5 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,3,iVar8,iVar3);
  if (uVar5 == 0xffffffff) {
    pPVar14 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    iVar3 = 0x86;
    local_90._0_4_ = 0x194a;
    goto LAB_001116d4;
  }
  iVar6 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,4,iVar8,iVar3);
  if (iVar6 == -1) {
    pPVar14 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    iVar3 = 0x86;
    local_90._0_4_ = 0x194b;
    goto LAB_001116d4;
  }
  uVar7 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,5,iVar8,iVar3);
  if (uVar7 == 0xffffffff) {
    pPVar14 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    iVar3 = 0x86;
    local_90._0_4_ = 0x194c;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: long neg_one@[???]
                       Unresolved local var: long const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
  pPVar17 = (PyObject *)PyLong_FromLong((long)(int)((uVar5 & 0xf) << 0x10 | iVar6 << 8 | uVar7));
  if (pPVar17 == (PyObject *)0x0) {
    pPVar14 = (PyObject *)0x0;
    iVar3 = 0x86;
    local_90._0_4_ = 0x194d;
    __pyx_t_9 = (PyObject *)0x0;
LAB_001137e0:
    if (__pyx_t_7 != (PyObject *)0x0) goto LAB_001116dc;
    goto LAB_0011171c;
  }
  lVar11 = 200;
  __pyx_t_9 = (PyObject *)0x0;
  __pyx_t_9 = __Pyx_PyInt_MultiplyObjC
                        (pPVar17,__pyx_mstate_global_static.__pyx_int_200,200,iVar3,iVar4);
  if (__pyx_t_9 == (PyObject *)0x0) {
    iVar3 = 0x87;
    local_90._0_4_ = 0x1959;
    pPVar14 = (PyObject *)0x0;
    goto LAB_001137e0;
  }
  __pyx_t_11 = __Pyx_PyInt_TrueDivideObjC
                         (__pyx_t_9,__pyx_mstate_global_static.__pyx_int_1048576,lVar11,iVar3,iVar4)
  ;
  if (__pyx_t_11 == (PyObject *)0x0) {
    iVar3 = 0x87;
    local_90._0_4_ = 0x195b;
    pPVar14 = (PyObject *)0x0;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_9->ob_refcnt + -1;
  __pyx_t_9->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
  }
  __pyx_t_9 = (PyObject *)0x0;
  p_Var13 = __pyx_t_11->ob_type;
  if (p_Var13 == (_typeobject *)PTR_PyLong_Type_0012ff80) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: long a@[???]
                       Unresolved local var: long x@[???]
                       Unresolved local var: longlong llb@[???]
                       Unresolved local var: longlong lla@[???]
                       Unresolved local var: longlong llx@[???] */
    lVar11 = __pyx_t_11[1].ob_refcnt;
    if (lVar11 == 0) {
      __pyx_t_9 = (PyObject *)PyLong_FromLong(0xffffffffffffffce);
      iVar4 = (int)p_Var13;
    }
    else {
      if (lVar11 + 1U < 3) {
        iVar4 = *(int *)&__pyx_t_11[1].ob_type;
        if (lVar11 < 0) {
          iVar4 = -*(int *)&__pyx_t_11[1].ob_type;
        }
        uVar21 = (ulong)iVar4;
      }
      else {
                    /* Unresolved local var: digit * digits@[???]
                       Unresolved local var: Py_ssize_t size@[???] */
        if (lVar11 == -2) {
          uVar21 = -((ulong)*(uint *)&__pyx_t_11[1].ob_type |
                    (ulong)*(uint *)((long)&__pyx_t_11[1].ob_type + 4) << 0x1e);
        }
        else {
          if (lVar11 != 2) {
            __pyx_t_9 = (*p_Var13->tp_as_number->nb_subtract)
                                  (__pyx_t_11,__pyx_mstate_global_static.__pyx_int_50);
            iVar4 = (int)p_Var13;
            goto LAB_00113128;
          }
          uVar21 = (ulong)*(uint *)&__pyx_t_11[1].ob_type |
                   (ulong)*(uint *)((long)&__pyx_t_11[1].ob_type + 4) << 0x1e;
        }
      }
      __pyx_t_9 = (PyObject *)PyLong_FromLong(uVar21 - 0x32);
      iVar4 = (int)p_Var13;
    }
  }
  else if (p_Var13 == (_typeobject *)PTR_PyFloat_Type_0012feb0) {
                    /* Unresolved local var: long b@[???]
                       Unresolved local var: double a@[???]
                       Unresolved local var: double result@[???] */
    __pyx_t_9 = (PyObject *)PyFloat_FromDouble((double)__pyx_t_11[1].ob_refcnt - 50.0);
    iVar4 = (int)p_Var13;
  }
  else {
    __pyx_t_9 = (PyObject *)PyNumber_Subtract(__pyx_t_11);
    iVar4 = (int)p_Var13;
  }
LAB_00113128:
  if (__pyx_t_9 == (PyObject *)0x0) {
    iVar3 = 0x87;
    local_90._0_4_ = 0x195e;
    pPVar14 = (PyObject *)0x0;
    goto LAB_001137e0;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_11->ob_refcnt + -1;
  __pyx_t_11->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
  }
  __pyx_t_11 = (PyObject *)0x0;
  pPVar10 = __pyx_t_9;
  iVar8 = __Pyx_PyObject_SetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_temp,__pyx_t_9);
  iVar6 = (int)pPVar10;
  if (iVar8 < 0) {
    pPVar14 = (PyObject *)0x0;
    iVar3 = 0x87;
    local_90._0_4_ = 0x1961;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_9->ob_refcnt + -1;
  __pyx_t_9->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
  }
  __pyx_t_9 = (PyObject *)0x0;
  iVar8 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,1,iVar6,iVar3);
  if (iVar8 == -1) {
    pPVar14 = (PyObject *)0x0;
    iVar3 = 0x88;
    local_90._0_4_ = 0x196b;
    goto LAB_001116d4;
  }
  iVar9 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,2,iVar6,iVar3);
  if (iVar9 == -1) {
    pPVar14 = (PyObject *)0x0;
    iVar3 = 0x88;
    local_90._0_4_ = 0x196c;
    goto LAB_001116d4;
  }
  uVar5 = __Pyx_GetItemInt_ByteArray_Fast(pPVar15,3,iVar6,iVar3);
  if (uVar5 == 0xffffffff) {
    pPVar14 = (PyObject *)0x0;
    iVar3 = 0x88;
    local_90._0_4_ = 0x196d;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: long neg_one@[???]
                       Unresolved local var: long const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
  pPVar14 = (PyObject *)PyLong_FromLong((long)((int)(iVar9 << 8 | iVar8 << 0x10 | uVar5) >> 4));
  if (pPVar14 == (PyObject *)0x0) {
    iVar3 = 0x88;
    local_90._0_4_ = 0x196e;
    __pyx_t_9 = (PyObject *)0x0;
    goto LAB_001137e0;
  }
  lVar11 = 100;
  __pyx_t_9 = (PyObject *)0x0;
  __pyx_t_9 = __Pyx_PyInt_MultiplyObjC
                        (pPVar14,__pyx_mstate_global_static.__pyx_int_100,100,iVar3,iVar4);
  if (__pyx_t_9 == (PyObject *)0x0) {
    iVar3 = 0x89;
    local_90._0_4_ = 0x197a;
    goto LAB_001137e0;
  }
  __pyx_t_11 = __Pyx_PyInt_TrueDivideObjC
                         (__pyx_t_9,__pyx_mstate_global_static.__pyx_int_1048576,lVar11,iVar3,iVar4)
  ;
  if (__pyx_t_11 == (PyObject *)0x0) {
    iVar3 = 0x89;
    local_90._0_4_ = 0x197c;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_9->ob_refcnt + -1;
  __pyx_t_9->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
  }
  __pyx_t_9 = (PyObject *)0x0;
  if (__pyx_t_11->ob_type == (_typeobject *)PTR_PyLong_Type_0012ff80) {
    __pyx_t_11->ob_refcnt = __pyx_t_11->ob_refcnt + 1;
    __pyx_t_9 = __pyx_t_11;
  }
  else {
    __pyx_t_9 = (PyObject *)PyNumber_Long();
    if (__pyx_t_9 == (PyObject *)0x0) {
      iVar3 = 0x89;
      local_90._0_4_ = 0x197f;
      goto LAB_001137e0;
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_11->ob_refcnt + -1;
  __pyx_t_11->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
  }
  __pyx_t_11 = (PyObject *)0x0;
  iVar3 = __Pyx_PyObject_SetAttrStr
                    (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_humidity,__pyx_t_9);
  if (iVar3 < 0) {
    iVar3 = 0x89;
    local_90._0_4_ = 0x1982;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_9->ob_refcnt + -1;
  __pyx_t_9->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
  }
  __pyx_t_9 = (PyObject *)0x0;
  __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_humidity);
  if (__pyx_t_9 == (PyObject *)0x0) {
    iVar3 = 0x8e;
    local_90._0_4_ = 0x198c;
    goto LAB_001137e0;
  }
  __pyx_t_11 = (PyObject *)
               PyObject_RichCompare(__pyx_t_9,__pyx_mstate_global_static.__pyx_int_100,4);
  if (__pyx_t_11 == (PyObject *)0x0) {
    iVar3 = 0x8e;
    local_90._0_4_ = 0x198e;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_9->ob_refcnt + -1;
  __pyx_t_9->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
  }
                    /* Unresolved local var: int is_true@[???] */
  __pyx_t_9 = (PyObject *)0x0;
  uVar5 = (uint)(__pyx_t_11 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
  if (((__pyx_t_11 != (PyObject *)PTR__Py_TrueStruct_0012ff58 &&
       __pyx_t_11 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
       __pyx_t_11 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
     (uVar5 = PyObject_IsTrue(), (int)uVar5 < 0)) {
    iVar3 = 0x8e;
    local_90._0_4_ = 0x1990;
    goto LAB_001116d4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar11 = __pyx_t_11->ob_refcnt + -1;
  __pyx_t_11->ob_refcnt = lVar11;
  if (lVar11 == 0) {
    (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
  }
  __pyx_t_11 = (PyObject *)0x0;
  if (uVar5 == 0) {
    __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_humidity)
    ;
    if (__pyx_t_11 == (PyObject *)0x0) {
      iVar3 = 0x90;
      local_90._0_4_ = 0x19ae;
    }
    else {
      __pyx_t_9 = (PyObject *)
                  PyObject_RichCompare(__pyx_t_11,__pyx_mstate_global_static.__pyx_int_0,0);
      if (__pyx_t_9 == (PyObject *)0x0) {
        iVar3 = 0x90;
        local_90._0_4_ = 0x19b0;
        goto LAB_001137e0;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar11 = __pyx_t_11->ob_refcnt + -1;
      __pyx_t_11->ob_refcnt = lVar11;
      if (lVar11 == 0) {
        (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
      }
                    /* Unresolved local var: int is_true@[???] */
      __pyx_t_11 = (PyObject *)0x0;
      uVar5 = (uint)(__pyx_t_9 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
      if (((__pyx_t_9 == (PyObject *)PTR__Py_TrueStruct_0012ff58 ||
           __pyx_t_9 == (PyObject *)PTR__Py_FalseStruct_0012ff20) ||
           __pyx_t_9 == (PyObject *)PTR__Py_NoneStruct_0012ff50) ||
         (uVar5 = PyObject_IsTrue(), -1 < (int)uVar5)) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = __pyx_t_9->ob_refcnt + -1;
        __pyx_t_9->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
        }
        __pyx_t_9 = (PyObject *)0x0;
        if ((uVar5 == 0) ||
           (iVar3 = __Pyx_PyObject_SetAttrStr
                              (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_humidity,
                               __pyx_mstate_global_static.__pyx_int_0), -1 < iVar3))
        goto LAB_00113398;
        iVar3 = 0x91;
        local_90._0_4_ = 0x19bd;
      }
      else {
        iVar3 = 0x90;
        local_90._0_4_ = 0x19b2;
      }
    }
    goto LAB_001116d4;
  }
  iVar3 = __Pyx_PyObject_SetAttrStr
                    (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_humidity,
                     __pyx_mstate_global_static.__pyx_int_100);
  if (iVar3 < 0) {
    iVar3 = 0x8f;
    local_90._0_4_ = 0x199b;
    goto LAB_001116d4;
  }
LAB_00113398:
  pPVar29 = (PyObject *)PTR__Py_TrueStruct_0012ff58;
  *(long *)PTR__Py_TrueStruct_0012ff58 = *(long *)PTR__Py_TrueStruct_0012ff58 + 1;
  goto LAB_00111764;
  while (pPVar17 != (PyObject *)0x0) {
LAB_00111bdc:
    pPVar17 = (PyObject *)pPVar17[0x10].ob_refcnt;
    if (pPVar14 == pPVar17) goto LAB_00111be8;
  }
  if (pPVar14 == (PyObject *)PTR_PyBaseObject_Type_0012ff78) goto LAB_00111be8;
  goto LAB_00111b44;
  while (pPVar1 = &p_Var13->tp_basicsize + lVar18, lVar18 = lVar18 + 1,
        pPVar14 != (PyObject *)*pPVar1) {
LAB_00111b38:
    if (lVar11 == lVar18 + 1) goto LAB_00111b44;
  }
LAB_00111be8:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F._make_measurement",(int)local_90,iVar3,"aht20_f.py");
  iVar3 = __Pyx__GetException(tstate,&__pyx_t_7,&__pyx_t_11,&__pyx_t_9);
  pPVar17 = __pyx_t_11;
  p_Var13 = __pyx_dict_version_17103;
  if (iVar3 < 0) {
    iVar3 = 0x7f;
    local_90._0_4_ = 0x187a;
  }
  else {
    p_Var27 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
    __pyx_t_11->ob_refcnt = __pyx_t_11->ob_refcnt + 1;
    pPVar14 = __pyx_dict_cached_value_17104;
    if (p_Var27 == p_Var13) {
      if (__pyx_dict_cached_value_17104 == (PyObject *)0x0) {
        pPVar14 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
        goto LAB_00112258;
      }
      __pyx_dict_cached_value_17104->ob_refcnt = __pyx_dict_cached_value_17104->ob_refcnt + 1;
LAB_00111c5c:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var24 = pPVar14->ob_type->tp_getattro;
      if (p_Var24 == (getattrofunc)0x0) {
        pPVar29 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar29 = (*p_Var24)(pPVar14,__pyx_mstate_global_static.__pyx_n_s_exception);
      }
      if (pPVar29 == (PyObject *)0x0) {
        iVar3 = 0x80;
        local_90._0_4_ = 0x188b;
        goto LAB_00112268;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar11 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar11;
      if (lVar11 == 0) {
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      }
      pPVar20 = __pyx_mstate_global_static.__pyx_kp_s_reading_data_s;
      puVar2 = PTR_PyUnicode_Type_0012ffb0;
      puVar25 = PTR__Py_NoneStruct_0012ff50;
      if (pPVar17->ob_type != (_typeobject *)PTR_PyUnicode_Type_0012ffb0) {
        local_90._0_4_ = 0x1896;
        pPVar14 = (PyObject *)PyObject_Str(pPVar17);
        if (pPVar14 != (PyObject *)0x0) {
          pPVar20 = __pyx_mstate_global_static.__pyx_kp_s_reading_data_s;
          if ((__pyx_mstate_global_static.__pyx_kp_s_reading_data_s ==
               (PyObject *)PTR__Py_NoneStruct_0012ff50) ||
             ((pPVar14->ob_type->tp_flags & 0x10000000) != 0 &&
              pPVar14->ob_type != (_typeobject *)puVar2)) goto LAB_00112570;
          goto LAB_00111ce8;
        }
LAB_001124d0:
        tstate_00 = (PyThreadState *)_PyThreadState_UncheckedGet();
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        __pyx_t_18 = (PyObject *)0x0;
        __pyx_t_19 = (PyObject *)0x0;
        __pyx_t_20 = (PyObject *)0x0;
        lVar11 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          iVar3 = 0x81;
          plVar19 = (long *)0x0;
LAB_00112500:
          __pyx_t_20 = (PyObject *)0x0;
          __pyx_t_19 = (PyObject *)0x0;
          __pyx_t_18 = (PyObject *)0x0;
          (*pPVar29->ob_type->tp_dealloc)(pPVar29);
          if (plVar19 != (long *)0x0) {
LAB_0011251c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = *plVar19;
            *plVar19 = lVar11 + -1;
            if (lVar11 + -1 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
          }
        }
        else {
          iVar3 = 0x81;
        }
        goto LAB_00112280;
      }
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
      pPVar14 = pPVar17;
      if (pPVar20 == (PyObject *)puVar25) {
LAB_00112570:
        plVar19 = (long *)PyNumber_Remainder(pPVar20,pPVar14);
      }
      else {
LAB_00111ce8:
        plVar19 = (long *)PyUnicode_Format(pPVar20,pPVar14);
      }
      if (plVar19 == (long *)0x0) {
        local_90._0_4_ = 0x1898;
        goto LAB_001124d0;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar11 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar11;
      if (lVar11 == 0) {
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      }
      pPVar14 = (PyObject *)
                PyNumber_Add(__pyx_mstate_global_static.__pyx_kp_s_aht20_f_exception_encountered,
                             plVar19);
      if (pPVar14 == (PyObject *)0x0) {
        tstate_00 = (PyThreadState *)_PyThreadState_UncheckedGet();
        __pyx_t_18 = (PyObject *)0x0;
        __pyx_t_19 = (PyObject *)0x0;
        __pyx_t_20 = (PyObject *)0x0;
        lVar11 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar11;
        pPVar14 = (PyObject *)0x0;
        if (lVar11 == 0) {
          iVar3 = 0x80;
          local_90._0_4_ = 0x18a3;
          goto LAB_00112500;
        }
        iVar3 = 0x80;
        local_90._0_4_ = 0x18a3;
        goto LAB_0011251c;
      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar11 = *plVar19;
      *plVar19 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      p_Var13 = pPVar29->ob_type;
      if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
         (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
        pPVar30 = (PyObject *)pPVar29[1].ob_refcnt;
        (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
        pPVar30->ob_refcnt = pPVar30->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          (*p_Var13->tp_dealloc)(pPVar29);
        }
        __pyx_callargs[0] = (PyObject *)p_Var27;
        __pyx_callargs[1] = pPVar14;
        pPVar20 = __Pyx_PyObject_FastCallDict(pPVar30,__pyx_callargs,2,pPVar14);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
        (p_Var27->ob_base).ob_base.ob_refcnt = lVar11;
        pPVar29 = pPVar30;
        if (lVar11 == 0) {
          (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
        }
      }
      else {
        __pyx_callargs[0] = (PyObject *)0x0;
        __pyx_callargs[1] = pPVar14;
        pPVar20 = __Pyx_PyObject_FastCallDict(pPVar29,__pyx_callargs + 1,1,pPVar14);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      }
      local_90 = __pyx_callargs;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar11 = pPVar14->ob_refcnt + -1;
      pPVar14->ob_refcnt = lVar11;
      if (lVar11 == 0) {
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      }
      if (pPVar20 == (PyObject *)0x0) {
        iVar3 = 0x80;
        local_90._0_4_ = 0x18b9;
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = pPVar29->ob_refcnt + -1;
        pPVar29->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          (*pPVar29->ob_type->tp_dealloc)(pPVar29);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = pPVar20->ob_refcnt + -1;
        pPVar20->ob_refcnt = lVar11;
        if (lVar11 == 0) {
          (*pPVar20->ob_type->tp_dealloc)(pPVar20);
        }
        pPVar29 = __Pyx_PyObject_GetAttrStr
                            (__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reset_device);
        if (pPVar29 == (PyObject *)0x0) {
          iVar3 = 0x82;
          local_90._0_4_ = 0x18c6;
          pPVar14 = (PyObject *)0x0;
          goto LAB_00112268;
        }
        p_Var13 = pPVar29->ob_type;
        if ((p_Var13 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
           (p_Var27 = pPVar29[1].ob_type, p_Var27 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar20 = (PyObject *)pPVar29[1].ob_refcnt;
          (p_Var27->ob_base).ob_base.ob_refcnt = (p_Var27->ob_base).ob_base.ob_refcnt + 1;
          pPVar20->ob_refcnt = pPVar20->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar11 = pPVar29->ob_refcnt + -1;
          pPVar29->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*p_Var13->tp_dealloc)(pPVar29);
          }
          __pyx_callargs[1] = (PyObject *)0x0;
          __pyx_callargs[0] = (PyObject *)p_Var27;
          pPVar14 = __Pyx_PyObject_FastCallDict(pPVar20,local_90,1,pPVar29);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar11 = (p_Var27->ob_base).ob_base.ob_refcnt + -1;
          (p_Var27->ob_base).ob_base.ob_refcnt = lVar11;
          pPVar29 = pPVar20;
          if (lVar11 == 0) {
            (*((p_Var27->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var27);
          }
        }
        else {
          __pyx_callargs[0] = (PyObject *)0x0;
          __pyx_callargs[1] = (PyObject *)0x0;
          pPVar14 = __Pyx_PyObject_FastCallDict(pPVar29,__pyx_callargs + 1,0,pPVar29);
        }
        if (pPVar14 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar11 = pPVar29->ob_refcnt + -1;
          pPVar29->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*pPVar29->ob_type->tp_dealloc)(pPVar29);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar11 = pPVar14->ob_refcnt + -1;
          pPVar14->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*pPVar14->ob_type->tp_dealloc)(pPVar14);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          *(long *)PTR__Py_FalseStruct_0012ff20 = *(long *)PTR__Py_FalseStruct_0012ff20 + 1;
          lVar11 = __pyx_t_7->ob_refcnt + -1;
          __pyx_t_7->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          __pyx_t_7 = (PyObject *)0x0;
          lVar11 = __pyx_t_9->ob_refcnt + -1;
          __pyx_t_9->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          __pyx_t_9 = (PyObject *)0x0;
          lVar11 = __pyx_t_11->ob_refcnt + -1;
          __pyx_t_11->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          __pyx_t_11 = (PyObject *)0x0;
          lVar11 = pPVar17->ob_refcnt + -1;
          pPVar17->ob_refcnt = lVar11;
          if (lVar11 == 0) {
            (*pPVar17->ob_type->tp_dealloc)(pPVar17);
          }
                    /* Unresolved local var: PyObject * tmp_type@[DW_OP_reg0(x0)]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???]
                       Unresolved local var: _PyErr_StackItem * exc_info@[???] */
          p_Var22 = tstate->exc_info;
          pPVar17 = p_Var22->exc_type;
          pPVar14 = p_Var22->exc_value;
          p_Var22->exc_type = local_78;
          p_Var22->exc_value = pPVar10;
          pPVar10 = p_Var22->exc_traceback;
          p_Var22->exc_traceback = local_80;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar17 != (PyObject *)0x0) &&
             (lVar11 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar11, lVar11 == 0)) {
            (*pPVar17->ob_type->tp_dealloc)(pPVar17);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          if ((pPVar14 != (PyObject *)0x0) &&
             (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
            (*pPVar14->ob_type->tp_dealloc)(pPVar14);
          }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          pPVar20 = pPVar23;
          pPVar30 = pPVar16;
          if (pPVar10 == (PyObject *)0x0) {
            pPVar14 = (PyObject *)0x0;
            pPVar17 = (PyObject *)0x0;
            pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar11 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar11;
            if (lVar11 == 0) {
              pPVar14 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              (*pPVar10->ob_type->tp_dealloc)(pPVar10);
              pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
            }
            else {
              pPVar14 = (PyObject *)0x0;
              pPVar17 = (PyObject *)0x0;
              pPVar29 = (PyObject *)PTR__Py_FalseStruct_0012ff20;
            }
          }
          goto LAB_00111764;
        }
        iVar3 = 0x82;
        local_90._0_4_ = 0x18da;
      }
      tstate_00 = (PyThreadState *)_PyThreadState_UncheckedGet();
      __pyx_t_18 = (PyObject *)0x0;
      __pyx_t_19 = (PyObject *)0x0;
      __pyx_t_20 = (PyObject *)0x0;
      lVar11 = pPVar29->ob_refcnt + -1;
      pPVar29->ob_refcnt = lVar11;
      if (lVar11 == 0) {
        plVar19 = (long *)0x0;
        pPVar14 = (PyObject *)0x0;
        goto LAB_00112500;
      }
    }
    else {
      pPVar14 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_logging,
                           (uint64_t *)&__pyx_dict_version_17103,&__pyx_dict_cached_value_17104);
LAB_00112258:
      if (pPVar14 != (PyObject *)0x0) goto LAB_00111c5c;
      iVar3 = 0x80;
      local_90._0_4_ = 0x1889;
LAB_00112268:
                    /* Unresolved local var: PyThreadState * __pyx_tstate@[???] */
      tstate_00 = (PyThreadState *)_PyThreadState_UncheckedGet();
      __pyx_t_18 = (PyObject *)0x0;
      __pyx_t_19 = (PyObject *)0x0;
      __pyx_t_20 = (PyObject *)0x0;
LAB_00112280:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar14 != (PyObject *)0x0) &&
         (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
        (*pPVar14->ob_type->tp_dealloc)(pPVar14);
      }
    }
    p_Var22 = tstate_00->exc_info;
                    /* Unresolved local var: PyObject * tmp_type@[DW_OP_reg25(x25)]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???]
                       Unresolved local var: _PyErr_StackItem * exc_info@[???] */
    pPVar14 = p_Var22->exc_type;
    pPVar29 = p_Var22->exc_value;
    p_Var22->exc_type = (PyObject *)0x0;
    p_Var22->exc_value = (PyObject *)0x0;
    pPVar20 = p_Var22->exc_traceback;
    p_Var22->exc_traceback = (PyObject *)0x0;
    iVar4 = __Pyx__GetException(tstate_00,&__pyx_t_18,&__pyx_t_19,&__pyx_t_20);
    if (iVar4 < 0) {
      __pyx_t_18 = tstate_00->curexc_type;
      __pyx_t_19 = tstate_00->curexc_value;
      __pyx_t_20 = tstate_00->curexc_traceback;
      tstate_00->curexc_type = (PyObject *)0x0;
      tstate_00->curexc_value = (PyObject *)0x0;
      tstate_00->curexc_traceback = (PyObject *)0x0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    p_Var22 = tstate_00->exc_info;
                    /* Unresolved local var: PyObject * tmp_type@[???]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???]
                       Unresolved local var: _PyErr_StackItem * exc_info@[???] */
    pPVar17 = p_Var22->exc_type;
    p_Var22->exc_type = pPVar14;
    pPVar30 = p_Var22->exc_value;
    p_Var22->exc_value = pPVar29;
    pPVar14 = p_Var22->exc_traceback;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    p_Var22->exc_traceback = pPVar20;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar17 != (PyObject *)0x0) &&
       (lVar11 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar11, lVar11 == 0)) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar30 != (PyObject *)0x0) &&
       (lVar11 = pPVar30->ob_refcnt + -1, pPVar30->ob_refcnt = lVar11, lVar11 == 0)) {
      (*pPVar30->ob_type->tp_dealloc)(pPVar30);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar14 != (PyObject *)0x0) &&
       (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
                    /* Unresolved local var: PyObject * tmp_type@[???]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???] */
    pPVar17 = tstate_00->curexc_type;
    pPVar14 = tstate_00->curexc_value;
    tstate_00->curexc_type = __pyx_t_18;
    tstate_00->curexc_value = __pyx_t_19;
    pPVar29 = tstate_00->curexc_traceback;
    tstate_00->curexc_traceback = __pyx_t_20;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar17 != (PyObject *)0x0) &&
       (lVar11 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar11, lVar11 == 0)) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar14 != (PyObject *)0x0) &&
       (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
      (*pPVar14->ob_type->tp_dealloc)(pPVar14);
    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if ((pPVar29 != (PyObject *)0x0) &&
       (lVar11 = pPVar29->ob_refcnt + -1, pPVar29->ob_refcnt = lVar11, lVar11 == 0)) {
      (*pPVar29->ob_type->tp_dealloc)(pPVar29);
    }
    __pyx_t_18 = (PyObject *)0x0;
    __pyx_t_19 = (PyObject *)0x0;
    __pyx_t_20 = (PyObject *)0x0;
  }
LAB_00111b44:
                    /* Unresolved local var: PyObject * tmp_type@[DW_OP_reg0(x0)]
                       Unresolved local var: PyObject * tmp_value@[???]
                       Unresolved local var: PyObject * tmp_tb@[???]
                       Unresolved local var: _PyErr_StackItem * exc_info@[???] */
  p_Var22 = tstate->exc_info;
  pPVar17 = p_Var22->exc_type;
  pPVar14 = p_Var22->exc_value;
  p_Var22->exc_type = local_78;
  p_Var22->exc_value = pPVar10;
  pPVar10 = p_Var22->exc_traceback;
  p_Var22->exc_traceback = local_80;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar17 != (PyObject *)0x0) &&
     (lVar11 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar17->ob_type->tp_dealloc)(pPVar17);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar14 != (PyObject *)0x0) &&
     (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar14->ob_type->tp_dealloc)(pPVar14);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  pPVar14 = (PyObject *)0x0;
  pPVar17 = (PyObject *)0x0;
  if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      pPVar17 = (PyObject *)0x0;
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    else {
      pPVar17 = (PyObject *)0x0;
    }
  }
LAB_001116d4:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (__pyx_t_7 != (PyObject *)0x0) {
LAB_001116dc:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = __pyx_t_7->ob_refcnt + -1;
    __pyx_t_7->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*__pyx_t_7->ob_type->tp_dealloc)(__pyx_t_7);
    }
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((__pyx_t_9 != (PyObject *)0x0) &&
     (lVar11 = __pyx_t_9->ob_refcnt + -1, __pyx_t_9->ob_refcnt = lVar11, lVar11 == 0)) {
    (*__pyx_t_9->ob_type->tp_dealloc)(__pyx_t_9);
  }
LAB_0011171c:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((__pyx_t_11 != (PyObject *)0x0) &&
     (lVar11 = __pyx_t_11->ob_refcnt + -1, __pyx_t_11->ob_refcnt = lVar11, lVar11 == 0)) {
    (*__pyx_t_11->ob_type->tp_dealloc)(__pyx_t_11);
  }
  pPVar29 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F._make_measurement",(int)local_90,iVar3,"aht20_f.py");
  pPVar20 = pPVar23;
  pPVar30 = pPVar16;
  if (pPVar15 != (PyObject *)0x0) {
LAB_00111764:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar11 = pPVar15->ob_refcnt + -1;
    pPVar15->ob_refcnt = lVar11;
    if (lVar11 == 0) {
      (*pPVar15->ob_type->tp_dealloc)(pPVar15);
    }
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar20 != (PyObject *)0x0) &&
     (lVar11 = pPVar20->ob_refcnt + -1, pPVar20->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar20->ob_type->tp_dealloc)(pPVar20);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar30 != (PyObject *)0x0) &&
     (lVar11 = pPVar30->ob_refcnt + -1, pPVar30->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar30->ob_type->tp_dealloc)(pPVar30);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar17 != (PyObject *)0x0) &&
     (lVar11 = pPVar17->ob_refcnt + -1, pPVar17->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar17->ob_type->tp_dealloc)(pPVar17);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar14 != (PyObject *)0x0) &&
     (lVar11 = pPVar14->ob_refcnt + -1, pPVar14->ob_refcnt = lVar11, lVar11 == 0)) {
    (*pPVar14->ob_type->tp_dealloc)(pPVar14);
  }
LAB_00110c88:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (lVar26 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar29;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00113dc8
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_15_make_measurement
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_15_make_measurement(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_15_make_measurement
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject **kwvalues;
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  PyObject *pPVar8;
  long lVar9;
  _typeobject *__s1;
  long *plVar10;
  _typeobject *extraout_x1;
  _typeobject *extraout_x1_00;
  _typeobject *extraout_x1_01;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  char *in_x6;
  long lVar15;
  _typeobject *p_Var16;
  long lVar17;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar8 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar4 = PTR_PyUnicode_Type_0012ffb0;
  puVar3 = PTR__Py_TrueStruct_0012ff58;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar2 = PTR__Py_NoneStruct_0012ff50;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_0012ff30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      pPVar8 = __pyx_pf_6extras_7aht20_f_7AHT20_F_14_make_measurement
                         (values[0],(PyObject *)__pyx_args);
      goto LAB_00113e7c;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar15 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar15) {
        p_Var16 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var16) {
          values[0] = *kwvalues;
        }
        else {
          lVar9 = 0;
          do {
            lVar17 = lVar9 + 1;
            if (lVar17 == lVar15) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar9 = 0;
              goto LAB_00113f48;
            }
            __pyx_args = (PyObject **)(&__pyx_kwds[2].ob_refcnt)[lVar9];
            lVar9 = lVar17;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)__pyx_args);
          values[0] = kwvalues[lVar17];
        }
        goto LAB_00114094;
      }
LAB_00114050:
      values[0] = (PyObject *)0x0;
      goto LAB_00114054;
    }
    if (__pyx_nargs == 1) {
      lVar15 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_00113ea8;
    }
  }
LAB_00113e24:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_make_measurement",
               "exactly",1,"",__pyx_nargs);
  iVar7 = 0x156e;
  goto LAB_00113e60;
  while( true ) {
    lVar17 = lVar9 + 1;
    if (lVar17 == lVar15) goto LAB_00114050;
    p_Var16 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar9];
    lVar9 = lVar17;
    if ((_typeobject *)pPVar8 == p_Var16) break;
LAB_00113f48:
    bVar5 = pPVar8->ob_type == (_typeobject *)puVar4;
    __pyx_args = (PyObject **)(ulong)bVar5;
    bVar6 = (p_Var16->ob_base).ob_base.ob_type != (_typeobject *)puVar4;
    lVar17 = lVar9;
    if (!bVar5 || bVar6) {
      if ((bVar6 || pPVar8 != (PyObject *)puVar2) && (!bVar5 || p_Var16 != (_typeobject *)puVar2)) {
        plVar10 = (long *)PyObject_RichCompare(pPVar8,p_Var16,2);
        if (plVar10 == (long *)0x0) goto LAB_00114050;
        __pyx_args = (PyObject **)(ulong)(plVar10 == (long *)puVar3);
        if ((plVar10 != (long *)puVar3 && plVar10 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar10 != (long *)puVar2) {
          uVar12 = PyObject_IsTrue();
          __pyx_args = (PyObject **)(uVar12 & 0xffffffff);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = *plVar10;
        *plVar10 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
LAB_00114038:
        if ((int)__pyx_args != 0) {
          if ((int)__pyx_args < 0) goto LAB_00114050;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar8[2].ob_refcnt) &&
          (iVar7 = _PyUnicode_Ready(pPVar8), __pyx_args = (PyObject **)extraout_x1_00, iVar7 < 0))
         || ((-1 < (char)p_Var16->tp_basicsize &&
             (iVar7 = _PyUnicode_Ready(p_Var16), __pyx_args = (PyObject **)extraout_x1_01, iVar7 < 0
             )))) goto LAB_00114050;
      lVar11 = pPVar8[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar11 == (p_Var16->ob_base).ob_size) &&
         (__pyx_args = (PyObject **)p_Var16->tp_name,
         (pPVar8[1].ob_type == (_typeobject *)__pyx_args ||
         (_typeobject *)__pyx_args == (_typeobject *)0xffffffffffffffff) ||
         pPVar8[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar12 = (ulong)(byte)((byte)pPVar8[2].ob_refcnt >> 2) & 7;
        uVar13 = (uint)uVar12;
        if (((byte)((byte)p_Var16->tp_basicsize >> 2) & 7) == uVar13) {
          bVar1 = (byte)pPVar8[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            __s1 = pPVar8[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar8[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar8 + 3);
            }
          }
          bVar1 = (byte)p_Var16->tp_basicsize;
          if ((bVar1 >> 5 & 1) == 0) {
            __pyx_args = (PyObject **)p_Var16->tp_setattr;
          }
          else {
            __pyx_args = (PyObject **)&p_Var16->tp_setattr;
            if ((bVar1 & 0x40) != 0) {
              __pyx_args = (PyObject **)&p_Var16->tp_dealloc;
            }
          }
          if (uVar13 == 1) {
            uVar13 = (uint)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            in_x6 = (char *)(ulong)(byte)(((_typeobject *)__pyx_args)->ob_base).ob_base.ob_refcnt;
          }
          else if (uVar13 == 2) {
            uVar13 = (uint)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            in_x6 = (char *)(ulong)(ushort)(((_typeobject *)__pyx_args)->ob_base).ob_base.ob_refcnt;
          }
          else {
            uVar13 = *(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            in_x6 = (char *)(ulong)(uint)(((_typeobject *)__pyx_args)->ob_base).ob_base.ob_refcnt;
          }
          if ((uint)in_x6 == uVar13) {
            if (lVar11 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar7 = memcmp(__s1,__pyx_args,uVar12 * lVar11);
              __pyx_args = (PyObject **)(ulong)(iVar7 == 0);
              goto LAB_00114038;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar17];
LAB_00114094:
  if (values[0] == (PyObject *)0x0) {
LAB_00114054:
    lVar15 = PyErr_Occurred();
    if (lVar15 == 0) goto LAB_00113e24;
    iVar7 = 0x155e;
  }
  else {
    lVar15 = lVar15 + -1;
LAB_00113ea8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar15 < 1) ||
       (iVar7 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x11d1b8,in_x6),
       __pyx_args = (PyObject **)extraout_x1, -1 < iVar7)) {
      pPVar8 = __pyx_pf_6extras_7aht20_f_7AHT20_F_14_make_measurement
                         (values[0],(PyObject *)__pyx_args);
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
      goto LAB_00113e7c;
    }
    iVar7 = 0x1563;
  }
LAB_00113e60:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F._make_measurement",iVar7,0x4e,"aht20_f.py");
  pPVar8 = (PyObject *)0x0;
LAB_00113e7c:
  if (lVar14 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00114208
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_9get_report_time_delta
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_9get_report_time_delta(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_9get_report_time_delta
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
  _typeobject *__s1;
  long *plVar10;
  setattrfunc *__s2;
  getattrofunc p_Var11;
  long lVar12;
  long lVar13;
  char *pcVar14;
  char *in_x6;
  uint uVar15;
  PyObject *pPVar16;
  long lVar17;
  _typeobject *p_Var18;
  long lVar19;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar16 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_0012ffb0;
  puVar4 = PTR__Py_TrueStruct_0012ff58;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_0012ff50;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar13 = *(long *)PTR___stack_chk_guard_0012ff30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_00114308;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar17 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar17) {
        p_Var18 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var18) {
          values[0] = *kwvalues;
        }
        else {
          lVar9 = 0;
          do {
            lVar19 = lVar9 + 1;
            if (lVar19 == lVar17) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar9 = 0;
              goto LAB_001143c8;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar9;
            lVar9 = lVar19;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar19];
        }
        goto LAB_00114510;
      }
LAB_001144cc:
      values[0] = (PyObject *)0x0;
      goto LAB_001144d0;
    }
    if (__pyx_nargs == 1) {
      lVar17 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_001142f4;
    }
  }
LAB_00114268:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","get_report_time_delta"
               ,"exactly",1,"",__pyx_nargs);
  iVar8 = 0x1298;
  goto LAB_001142a4;
  while( true ) {
    lVar19 = lVar9 + 1;
    if (lVar19 == lVar17) goto LAB_001144cc;
    p_Var18 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar9];
    lVar9 = lVar19;
    if ((_typeobject *)pPVar16 == p_Var18) break;
LAB_001143c8:
    bVar6 = pPVar16->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var18->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar19 = lVar9;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar16 != (PyObject *)puVar3) && (bVar6 || p_Var18 != (_typeobject *)puVar3)) {
        plVar10 = (long *)PyObject_RichCompare(pPVar16,p_Var18,2);
        if (plVar10 == (long *)0x0) goto LAB_001144cc;
        uVar15 = (uint)(plVar10 == (long *)puVar4);
        if ((plVar10 != (long *)puVar4 && plVar10 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar10 != (long *)puVar3) {
          uVar15 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar12 = *plVar10;
        *plVar10 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
LAB_001144b8:
        if (uVar15 != 0) {
          if ((int)uVar15 < 0) goto LAB_001144cc;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar16[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar16), iVar8 < 0)) ||
         ((-1 < (char)p_Var18->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var18), iVar8 < 0))))
      goto LAB_001144cc;
      lVar12 = pPVar16[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar12 == (p_Var18->ob_base).ob_size) &&
         ((pPVar16[1].ob_type == (_typeobject *)p_Var18->tp_name ||
          (_typeobject *)p_Var18->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar16[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar14 = (char *)((ulong)(byte)((byte)pPVar16[2].ob_refcnt >> 2) & 7);
        uVar15 = (uint)pcVar14;
        in_x6 = pcVar14;
        if (((byte)((byte)p_Var18->tp_basicsize >> 2) & 7) == uVar15) {
          bVar2 = (byte)pPVar16[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            __s1 = pPVar16[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar16[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar16 + 3);
            }
          }
          bVar2 = (byte)p_Var18->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var18->tp_setattr;
          }
          else {
            __s2 = &p_Var18->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var18->tp_dealloc;
            }
          }
          if (uVar15 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar15 = (uint)*(byte *)__s2;
          }
          else if (uVar15 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar15 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            uVar15 = *(uint *)__s2;
          }
          if (uVar15 == (uint)in_x6) {
            if (lVar12 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(__s1,__s2,(long)pcVar14 * lVar12);
              uVar15 = (uint)(iVar8 == 0);
              goto LAB_001144b8;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar19];
LAB_00114510:
  if (values[0] == (PyObject *)0x0) {
LAB_001144d0:
    lVar17 = PyErr_Occurred();
    if (lVar17 == 0) goto LAB_00114268;
    iVar8 = 0x1288;
  }
  else {
    lVar17 = lVar17 + -1;
LAB_001142f4:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar17 < 1) ||
       (iVar8 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x11d1d0,in_x6), -1 < iVar8)) {
LAB_00114308:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var11 = values[0]->ob_type->tp_getattro;
      if (p_Var11 == (getattrofunc)0x0) {
        pPVar16 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar16 = (*p_Var11)(values[0],__pyx_mstate_global_static.__pyx_n_s_report_time);
      }
      if (pPVar16 == (PyObject *)0x0) {
        __Pyx_AddTraceback("extras.aht20_f.AHT20_F.get_report_time_delta",0x12c4,0x3a,"aht20_f.py");
      }
      goto LAB_001142c0;
    }
    iVar8 = 0x128d;
  }
LAB_001142a4:
  pPVar16 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F.get_report_time_delta",iVar8,0x39,"aht20_f.py");
LAB_001142c0:
  if (lVar13 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar16;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00114690
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_19_init_aht20_f
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_19_init_aht20_f(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Exceeded maximum restarts with more pending */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_19_init_aht20_f
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
  PyObject *pPVar13;
  PyObject **ppPVar14;
  long lVar15;
  long *plVar16;
  _typeobject *p_Var17;
  setattrfunc *__s2;
  getattrofunc p_Var18;
  long lVar19;
  __pyx_mstate *p_Var20;
  long lVar21;
  char *pcVar22;
  char *in_x6;
  long lVar23;
  _typeobject *p_Var24;
  int py_line;
  PyObject *func;
  _typeobject *p_Var25;
  long lVar26;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar11 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar5 = PTR_PyUnicode_Type_0012ffb0;
  puVar4 = PTR__Py_TrueStruct_0012ff58;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_0012ff50;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar21 = *(long *)PTR___stack_chk_guard_0012ff30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_00114784;
    }
  }
  else {
    ppPVar14 = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar23 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar23) {
        p_Var17 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var17) {
          values[0] = *ppPVar14;
        }
        else {
          lVar15 = 0;
          do {
            lVar26 = lVar15 + 1;
            if (lVar26 == lVar23) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar15 = 0;
              goto LAB_00114f50;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar15;
            lVar15 = lVar26;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)*pPVar1);
          values[0] = ppPVar14[lVar26];
        }
        goto LAB_001150ec;
      }
LAB_00115054:
      values[0] = (PyObject *)0x0;
      goto LAB_00115058;
    }
    if (__pyx_nargs == 1) {
      lVar23 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_00114778;
    }
  }
LAB_001146e8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_init_aht20_f",
               "exactly",1,"",__pyx_nargs);
  iVar9 = 0x1e41;
  goto LAB_00114724;
  while( true ) {
    lVar26 = lVar15 + 1;
    if (lVar26 == lVar23) goto LAB_00115054;
    p_Var17 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar15];
    lVar15 = lVar26;
    if ((_typeobject *)pPVar11 == p_Var17) break;
LAB_00114f50:
    bVar7 = pPVar11->ob_type != (_typeobject *)puVar5;
    bVar8 = (p_Var17->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar26 = lVar15;
    if (bVar7 || bVar8) {
      if ((bVar8 || pPVar11 != (PyObject *)puVar3) && (bVar7 || p_Var17 != (_typeobject *)puVar3)) {
        plVar16 = (long *)PyObject_RichCompare(pPVar11,p_Var17,2);
        if (plVar16 == (long *)0x0) goto LAB_00115054;
        uVar10 = (uint)(plVar16 == (long *)puVar4);
        if ((plVar16 != (long *)puVar4 && plVar16 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar16 != (long *)puVar3) {
          uVar10 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar19 = *plVar16;
        *plVar16 = lVar19 + -1;
        if (lVar19 + -1 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
LAB_00115040:
        if (uVar10 != 0) {
          if ((int)uVar10 < 0) goto LAB_00115054;
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
         ((-1 < (char)p_Var17->tp_basicsize && (iVar9 = _PyUnicode_Ready(p_Var17), iVar9 < 0))))
      goto LAB_00115054;
      lVar19 = pPVar11[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar19 == (p_Var17->ob_base).ob_size) &&
         ((pPVar11[1].ob_type == (_typeobject *)p_Var17->tp_name ||
          (_typeobject *)p_Var17->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar11[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar22 = (char *)((ulong)(byte)((byte)pPVar11[2].ob_refcnt >> 2) & 7);
        uVar10 = (uint)pcVar22;
        in_x6 = pcVar22;
        if (((byte)((byte)p_Var17->tp_basicsize >> 2) & 7) == uVar10) {
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
          bVar2 = (byte)p_Var17->tp_basicsize;
          if ((bVar2 >> 5 & 1) == 0) {
            __s2 = (setattrfunc *)p_Var17->tp_setattr;
          }
          else {
            __s2 = &p_Var17->tp_setattr;
            if ((bVar2 & 0x40) != 0) {
              __s2 = (setattrfunc *)&p_Var17->tp_dealloc;
            }
          }
          if (uVar10 == 1) {
            in_x6 = (char *)(ulong)*(byte *)&(p_Var24->ob_base).ob_base.ob_refcnt;
            uVar10 = (uint)*(byte *)__s2;
          }
          else if (uVar10 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(p_Var24->ob_base).ob_base.ob_refcnt;
            uVar10 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(p_Var24->ob_base).ob_base.ob_refcnt;
            uVar10 = *(uint *)__s2;
          }
          if (uVar10 == (uint)in_x6) {
            if (lVar19 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar9 = memcmp(p_Var24,__s2,(long)pcVar22 * lVar19);
              uVar10 = (uint)(iVar9 == 0);
              goto LAB_00115040;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = ppPVar14[lVar26];
LAB_001150ec:
  if (values[0] == (PyObject *)0x0) {
LAB_00115058:
    lVar23 = PyErr_Occurred();
    if (lVar23 == 0) goto LAB_001146e8;
    iVar9 = 0x1e31;
  }
  else {
    lVar23 = lVar23 + -1;
LAB_00114778:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar23 < 1) ||
       (iVar9 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,ppPVar14,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x11d218,in_x6), -1 < iVar9)) {
LAB_00114784:
                    /* Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: wchar_t __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: int __pyx_t_7@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
      apPVar6[0] = values[0];
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var18 = values[0]->ob_type->tp_getattro;
      if (p_Var18 == (getattrofunc)0x0) {
        pPVar11 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar11 = (*p_Var18)(values[0],__pyx_mstate_global_static.__pyx_n_s_i2c);
      }
      if (pPVar11 == (PyObject *)0x0) {
        py_line = 0xbb;
        iVar9 = 0x1e72;
        goto LAB_001151b8;
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var18 = pPVar11->ob_type->tp_getattro;
      if (p_Var18 == (getattrofunc)0x0) {
        pPVar12 = (PyObject *)
                  PyObject_GetAttr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
      }
      else {
        pPVar12 = (PyObject *)(*p_Var18)();
      }
      lVar23 = pPVar11->ob_refcnt + -1;
      if (pPVar12 == (PyObject *)0x0) {
        py_line = 0xbb;
        iVar9 = 0x1e74;
        pPVar13 = (PyObject *)0x0;
LAB_0011520c:
        pPVar11->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          p_Var17 = (_typeobject *)0x0;
LAB_00115218:
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
LAB_00115230:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
          if (p_Var17 != (_typeobject *)0x0) {
LAB_00115234:
            lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
LAB_0011523c:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
            if (lVar23 == 0) {
LAB_00115244:
              (*((p_Var17->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var17);
            }
          }
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        if (pPVar13 != (PyObject *)0x0) {
LAB_00115258:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*pPVar13->ob_type->tp_dealloc)(pPVar13);
          }
        }
      }
      else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar11->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        pPVar11 = __pyx_dict_cached_value_17553;
        p_Var20 = &__pyx_mstate_global_static;
        if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_17552) {
          pPVar11 = __Pyx__GetModuleGlobalName
                              (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                               (uint64_t *)&__pyx_dict_version_17552,&__pyx_dict_cached_value_17553)
          ;
LAB_00115290:
          if (pPVar11 != (PyObject *)0x0) goto LAB_0011481c;
          pPVar13 = (PyObject *)0x0;
          py_line = 0xbb;
          iVar9 = 0x1e77;
          p_Var17 = (_typeobject *)0x0;
          goto LAB_001152a0;
        }
        if (__pyx_dict_cached_value_17553 == (PyObject *)0x0) {
          pPVar11 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
          goto LAB_00115290;
        }
        __pyx_dict_cached_value_17553->ob_refcnt = __pyx_dict_cached_value_17553->ob_refcnt + 1;
LAB_0011481c:
        if (pPVar11->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
          pPVar13 = __Pyx_PyDict_GetItem(pPVar11,__pyx_mstate_global_static.__pyx_n_s_RESET);
        }
        else {
          pPVar13 = (PyObject *)PyObject_GetItem();
        }
        lVar23 = pPVar11->ob_refcnt + -1;
        if (pPVar13 == (PyObject *)0x0) {
          pPVar11->ob_refcnt = lVar23;
          if (lVar23 != 0) {
            iVar9 = 0x1e79;
            goto LAB_001153b4;
          }
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          lVar23 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar23;
          if (lVar23 != 0) {
            py_line = 0xbb;
            iVar9 = 0x1e79;
            goto LAB_001151b8;
          }
          p_Var17 = (_typeobject *)0x0;
          iVar9 = 0x1e79;
          py_line = 0xbb;
          pPVar13 = (PyObject *)0x0;
LAB_001152b0:
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          goto LAB_00115230;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar11->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        p_Var17 = pPVar12->ob_type;
        if ((p_Var17 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
           (p_Var24 = pPVar12[1].ob_type, p_Var24 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          func = (PyObject *)pPVar12[1].ob_refcnt;
          (p_Var24->ob_base).ob_base.ob_refcnt = (p_Var24->ob_base).ob_base.ob_refcnt + 1;
          func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*p_Var17->tp_dealloc)(pPVar12);
          }
          __pyx_pyargnames[0] = (PyObject **)p_Var24;
          __pyx_pyargnames[1] = (PyObject **)pPVar13;
          pPVar11 = __Pyx_PyObject_FastCallDict
                              (func,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var20);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = (p_Var24->ob_base).ob_base.ob_refcnt + -1;
          (p_Var24->ob_base).ob_base.ob_refcnt = lVar23;
          pPVar12 = func;
          if (lVar23 == 0) {
            (*((p_Var24->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var24);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)pPVar13;
          pPVar11 = __Pyx_PyObject_FastCallDict
                              (pPVar12,(PyObject **)(__pyx_pyargnames + 1),1,(PyObject *)p_Var20);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        if (pPVar11 == (PyObject *)0x0) {
          iVar9 = 0x1e8f;
LAB_001153b4:
          lVar23 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar23;
          if (lVar23 != 0) {
            py_line = 0xbb;
            goto LAB_001151b8;
          }
          pPVar13 = (PyObject *)0x0;
          p_Var17 = (_typeobject *)0x0;
          py_line = 0xbb;
          goto LAB_001152b0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var18 = apPVar6[0]->ob_type->tp_getattro;
        if (p_Var18 == (getattrofunc)0x0) {
          pPVar12 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar12 = (*p_Var18)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_reactor);
        }
        if (pPVar12 == (PyObject *)0x0) {
          py_line = 0xbd;
          iVar9 = 0x1e9c;
          goto LAB_001151b8;
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var18 = pPVar12->ob_type->tp_getattro;
        if (p_Var18 == (getattrofunc)0x0) {
          p_Var17 = (_typeobject *)PyObject_GetAttr();
        }
        else {
          p_Var17 = (_typeobject *)(*p_Var18)(pPVar12,__pyx_mstate_global_static.__pyx_n_s_pause);
        }
        lVar23 = pPVar12->ob_refcnt + -1;
        if (p_Var17 == (_typeobject *)0x0) {
          pPVar13 = (PyObject *)0x0;
          py_line = 0xbd;
          iVar9 = 0x1e9e;
          goto LAB_001152a0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar12->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var18 = apPVar6[0]->ob_type->tp_getattro;
        if (p_Var18 == (getattrofunc)0x0) {
          pPVar11 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar11 = (*p_Var18)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_reactor);
        }
        if (pPVar11 == (PyObject *)0x0) {
          py_line = 0xbd;
          iVar9 = 0x1ea1;
          lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
          pPVar13 = (PyObject *)0x0;
          goto LAB_0011523c;
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var18 = pPVar11->ob_type->tp_getattro;
        if (p_Var18 == (getattrofunc)0x0) {
          pPVar13 = (PyObject *)
                    PyObject_GetAttr(pPVar11,__pyx_mstate_global_static.__pyx_n_s_monotonic);
        }
        else {
          pPVar13 = (PyObject *)(*p_Var18)();
        }
        lVar23 = pPVar11->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
        pPVar11->ob_refcnt = lVar23;
        if (pPVar13 == (PyObject *)0x0) {
          if (lVar23 == 0) {
            py_line = 0xbd;
            iVar9 = 0x1ea3;
            goto LAB_00115218;
          }
          pPVar13 = (PyObject *)0x0;
          py_line = 0xbd;
          iVar9 = 0x1ea3;
          goto LAB_00115234;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        if (lVar23 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        p_Var24 = pPVar13->ob_type;
        if ((p_Var24 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
           (p_Var25 = pPVar13[1].ob_type, p_Var25 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          pPVar11 = (PyObject *)pPVar13[1].ob_refcnt;
          (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
          pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = pPVar13->ob_refcnt + -1;
          pPVar13->ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*p_Var24->tp_dealloc)(pPVar13);
          }
          iVar9 = 1;
          __pyx_pyargnames[1] = (PyObject **)0x0;
          __pyx_pyargnames[0] = (PyObject **)p_Var25;
          pPVar12 = __Pyx_PyObject_FastCallDict
                              (pPVar11,(PyObject **)__pyx_pyargnames,1,(PyObject *)p_Var20);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = (p_Var25->ob_base).ob_base.ob_refcnt + -1;
          (p_Var25->ob_base).ob_base.ob_refcnt = lVar23;
          pPVar13 = pPVar11;
          if (lVar23 == 0) {
            (*((p_Var25->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var25);
          }
        }
        else {
          iVar9 = 0;
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)0x0;
          pPVar12 = __Pyx_PyObject_FastCallDict
                              (pPVar13,(PyObject **)(__pyx_pyargnames + 1),0,(PyObject *)p_Var20);
        }
        if (pPVar12 == (PyObject *)0x0) {
          py_line = 0xbd;
          iVar9 = 0x1eb8;
          lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
          goto LAB_0011523c;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
        pPVar11 = __Pyx_PyFloat_AddObjC
                            (pPVar12,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar9,
                             (int)p_Var20);
        if (pPVar11 == (PyObject *)0x0) {
          py_line = 0xbd;
          iVar9 = 0x1ebc;
          pPVar13 = (PyObject *)0x0;
          goto LAB_001152a0;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar12->ob_refcnt + -1;
        pPVar12->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar12->ob_type->tp_dealloc)(pPVar12);
        }
        p_Var24 = (p_Var17->ob_base).ob_base.ob_type;
        if ((p_Var24 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
           (pPVar12 = (PyObject *)p_Var17->tp_name, pPVar12 != (PyObject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          p_Var25 = (_typeobject *)(p_Var17->ob_base).ob_size;
          pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
          (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
          (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*p_Var24->tp_dealloc)((PyObject *)p_Var17);
          }
          __pyx_pyargnames[0] = (PyObject **)pPVar12;
          __pyx_pyargnames[1] = (PyObject **)pPVar11;
          pPVar13 = __Pyx_PyObject_FastCallDict
                              ((PyObject *)p_Var25,(PyObject **)__pyx_pyargnames,2,
                               (PyObject *)p_Var20);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = pPVar12->ob_refcnt + -1;
          pPVar12->ob_refcnt = lVar23;
          p_Var17 = p_Var25;
          if (lVar23 == 0) {
            (*pPVar12->ob_type->tp_dealloc)(pPVar12);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)pPVar11;
          pPVar13 = __Pyx_PyObject_FastCallDict
                              ((PyObject *)p_Var17,(PyObject **)(__pyx_pyargnames + 1),1,
                               (PyObject *)p_Var20);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        if (pPVar13 == (PyObject *)0x0) {
          py_line = 0xbd;
          iVar9 = 0x1ed2;
LAB_00115524:
          lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
          (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
          if (lVar23 != 0) goto LAB_001151b8;
          pPVar13 = (PyObject *)0x0;
          goto LAB_00115244;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
        (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*((p_Var17->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var17);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = pPVar13->ob_refcnt + -1;
        pPVar13->ob_refcnt = lVar23;
        if (lVar23 == 0) {
          (*pPVar13->ob_type->tp_dealloc)(pPVar13);
        }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        pPVar11 = (PyObject *)apPVar6[0]->ob_type->tp_setattro;
        if (pPVar11 == (PyObject *)0x0) {
          iVar9 = PyObject_SetAttr(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_init_sent,
                                   PTR__Py_TrueStruct_0012ff58);
        }
        else {
          iVar9 = (*(code *)pPVar11)();
        }
        if (-1 < iVar9) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var18 = apPVar6[0]->ob_type->tp_getattro;
          if (p_Var18 == (getattrofunc)0x0) {
            p_Var17 = (_typeobject *)PyObject_GetAttr();
          }
          else {
            p_Var17 = (_typeobject *)
                      (*p_Var18)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_make_measurement);
          }
          if (p_Var17 == (_typeobject *)0x0) {
            py_line = 0xc1;
            iVar9 = 0x1ee8;
            goto LAB_001151b8;
          }
          p_Var24 = (p_Var17->ob_base).ob_base.ob_type;
          if ((p_Var24 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
             (pPVar12 = (PyObject *)p_Var17->tp_name, pPVar12 != (PyObject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            p_Var25 = (_typeobject *)(p_Var17->ob_base).ob_size;
            pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
            (p_Var25->ob_base).ob_base.ob_refcnt = (p_Var25->ob_base).ob_base.ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
            (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
            if (lVar23 == 0) {
              (*p_Var24->tp_dealloc)((PyObject *)p_Var17);
            }
            __pyx_pyargnames[1] = (PyObject **)0x0;
            __pyx_pyargnames[0] = (PyObject **)pPVar12;
            pPVar11 = __Pyx_PyObject_FastCallDict
                                ((PyObject *)p_Var25,(PyObject **)__pyx_pyargnames,1,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar23 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar23;
            p_Var17 = p_Var25;
            if (lVar23 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)0x0;
            pPVar11 = __Pyx_PyObject_FastCallDict
                                ((PyObject *)p_Var17,(PyObject **)(__pyx_pyargnames + 1),0,pPVar11);
          }
          if (pPVar11 == (PyObject *)0x0) {
            py_line = 0xc1;
            iVar9 = 0x1efc;
            goto LAB_00115524;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
          (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*((p_Var17->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var17);
          }
                    /* Unresolved local var: int is_true@[???] */
          uVar10 = (uint)(pPVar11 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
          if (((uVar10 == 0 && pPVar11 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
               pPVar11 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
             (uVar10 = PyObject_IsTrue(pPVar11), (int)uVar10 < 0)) {
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar23 = pPVar11->ob_refcnt + -1;
            pPVar11->ob_refcnt = lVar23;
            if (lVar23 == 0) {
              py_line = 0xc1;
              iVar9 = 0x1f00;
              (*pPVar11->ob_type->tp_dealloc)(pPVar11);
            }
            else {
              py_line = 0xc1;
              iVar9 = 0x1f00;
            }
            goto LAB_001151b8;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar23 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          p_Var17 = (_typeobject *)__pyx_dict_cached_value_17592;
          if (uVar10 == 0) {
LAB_00114eb4:
            pPVar11 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
            *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
            goto LAB_00114740;
          }
          p_Var20 = &__pyx_mstate_global_static;
          if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17591) {
            if (__pyx_dict_cached_value_17592 == (PyObject *)0x0) {
              p_Var17 = (_typeobject *)
                        __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
              goto LAB_001155f4;
            }
            __pyx_dict_cached_value_17592->ob_refcnt = __pyx_dict_cached_value_17592->ob_refcnt + 1;
          }
          else {
            p_Var17 = (_typeobject *)
                      __Pyx__GetModuleGlobalName
                                (__pyx_mstate_global_static.__pyx_n_s_logging,
                                 (uint64_t *)&__pyx_dict_version_17591,
                                 &__pyx_dict_cached_value_17592);
LAB_001155f4:
            if (p_Var17 == (_typeobject *)0x0) {
              py_line = 0xc2;
              iVar9 = 0x1f0b;
              goto LAB_001151b8;
            }
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var18 = ((p_Var17->ob_base).ob_base.ob_type)->tp_getattro;
          if (p_Var18 == (getattrofunc)0x0) {
            pPVar13 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar13 = (*p_Var18)((PyObject *)p_Var17,__pyx_mstate_global_static.__pyx_n_s_info);
          }
          lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
          if (pPVar13 == (PyObject *)0x0) {
            py_line = 0xc2;
            iVar9 = 0x1f0d;
            goto LAB_0011523c;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          (p_Var17->ob_base).ob_base.ob_refcnt = lVar23;
          if (lVar23 == 0) {
            (*((p_Var17->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var17);
          }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var18 = apPVar6[0]->ob_type->tp_getattro;
          if (p_Var18 == (getattrofunc)0x0) {
            p_Var17 = (_typeobject *)PyObject_GetAttr();
          }
          else {
            p_Var17 = (_typeobject *)
                      (*p_Var18)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_temp);
          }
          if (p_Var17 != (_typeobject *)0x0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var18 = apPVar6[0]->ob_type->tp_getattro;
            if (p_Var18 == (getattrofunc)0x0) {
              pPVar12 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar12 = (*p_Var18)(apPVar6[0],__pyx_mstate_global_static.__pyx_n_s_humidity);
            }
            if (pPVar12 != (PyObject *)0x0) {
              pPVar11 = (PyObject *)PyTuple_New(2);
              if (pPVar11 == (PyObject *)0x0) {
                py_line = 0xc3;
                iVar9 = 0x1f1c;
              }
              else {
                pPVar11[1].ob_type = p_Var17;
                pPVar11[2].ob_refcnt = (Py_ssize_t)pPVar12;
                pPVar12 = (PyObject *)
                          PyUnicode_Format(__pyx_mstate_global_static.__pyx_kp_s_3f_humidity_3f,
                                           pPVar11);
                if (pPVar12 == (PyObject *)0x0) {
                  py_line = 0xc3;
                  lVar23 = pPVar11->ob_refcnt + -1;
                  iVar9 = 0x1f24;
                  goto LAB_0011520c;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar23 = pPVar11->ob_refcnt + -1;
                pPVar11->ob_refcnt = lVar23;
                if (lVar23 == 0) {
                  (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                }
                ppPVar14 = (PyObject **)
                           PyUnicode_Concat(__pyx_mstate_global_static.
                                            __pyx_kp_s_aht20_f_successfully_initialized,pPVar12);
                if (ppPVar14 != (PyObject **)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar23 = pPVar12->ob_refcnt + -1;
                  pPVar12->ob_refcnt = lVar23;
                  if (lVar23 == 0) {
                    (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                  }
                  p_Var17 = pPVar13->ob_type;
                  if ((p_Var17 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                     (p_Var24 = pPVar13[1].ob_type, p_Var24 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar12 = (PyObject *)pPVar13[1].ob_refcnt;
                    (p_Var24->ob_base).ob_base.ob_refcnt = (p_Var24->ob_base).ob_base.ob_refcnt + 1;
                    pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar23 = pPVar13->ob_refcnt + -1;
                    pPVar13->ob_refcnt = lVar23;
                    if (lVar23 == 0) {
                      (*p_Var17->tp_dealloc)(pPVar13);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var24;
                    __pyx_pyargnames[1] = ppPVar14;
                    pPVar11 = __Pyx_PyObject_FastCallDict
                                        (pPVar12,(PyObject **)__pyx_pyargnames,2,(PyObject *)p_Var20
                                        );
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar23 = (p_Var24->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var24->ob_base).ob_base.ob_refcnt = lVar23;
                    pPVar13 = pPVar12;
                    if (lVar23 == 0) {
                      (*((p_Var24->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var24);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = ppPVar14;
                    pPVar11 = __Pyx_PyObject_FastCallDict
                                        (pPVar13,(PyObject **)(__pyx_pyargnames + 1),1,
                                         (PyObject *)p_Var20);
                  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar12 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                  *ppPVar14 = pPVar12;
                  if (pPVar12 == (PyObject *)0x0) {
                    (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
                  }
                  if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar23 = pPVar13->ob_refcnt + -1;
                    pPVar13->ob_refcnt = lVar23;
                    if (lVar23 == 0) {
                      (*pPVar13->ob_type->tp_dealloc)(pPVar13);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar23 = pPVar11->ob_refcnt + -1;
                    pPVar11->ob_refcnt = lVar23;
                    if (lVar23 == 0) {
                      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                    }
                    goto LAB_00114eb4;
                  }
                  py_line = 0xc2;
                  iVar9 = 0x1f45;
                  goto LAB_00115258;
                }
                py_line = 0xc2;
                iVar9 = 0x1f2f;
                p_Var17 = (_typeobject *)0x0;
              }
LAB_001152a0:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar23 = pPVar12->ob_refcnt + -1;
              pPVar12->ob_refcnt = lVar23;
              if (lVar23 != 0) goto LAB_00115230;
              goto LAB_001152b0;
            }
            py_line = 0xc3;
            iVar9 = 0x1f1a;
            lVar23 = (p_Var17->ob_base).ob_base.ob_refcnt + -1;
            goto LAB_0011523c;
          }
          py_line = 0xc3;
          iVar9 = 0x1f18;
          goto LAB_00115258;
        }
        py_line = 0xbf;
        iVar9 = 0x1edf;
      }
LAB_001151b8:
      __Pyx_AddTraceback("extras.aht20_f.AHT20_F._init_aht20_f",iVar9,py_line,"aht20_f.py");
      pPVar11 = (PyObject *)0x0;
      goto LAB_00114740;
    }
    iVar9 = 0x1e36;
  }
LAB_00114724:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F._init_aht20_f",iVar9,0xb9,"aht20_f.py");
  pPVar11 = (PyObject *)0x0;
LAB_00114740:
  if (lVar21 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00115778
 * Symbol:  __pyx_pw_6extras_7aht20_f_1load_config
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_1load_config(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_1load_config
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
  long lVar11;
  long *plVar12;
  setattrfunc *__s2;
  getattrofunc p_Var13;
  _typeobject *p_Var14;
  long lVar15;
  long lVar16;
  char *pcVar17;
  char *in_x6;
  uint uVar18;
  PyObject *pPVar19;
  PyObject *pPVar20;
  long lVar21;
  _typeobject *p_Var22;
  long lVar23;
  PyObject *func;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar9 = __pyx_mstate_global_static.__pyx_n_s_config;
  puVar5 = PTR_PyUnicode_Type_0012ffb0;
  puVar4 = PTR__Py_TrueStruct_0012ff58;
                    /* Unresolved local var: PyObject * __pyx_v_config@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar3 = PTR__Py_NoneStruct_0012ff50;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_config;
  lVar16 = *(long *)PTR___stack_chk_guard_0012ff30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  pPVar19 = __pyx_kwds;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      goto LAB_00115874;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar21 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar21) {
        p_Var14 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_config == p_Var14) {
          values[0] = *kwvalues;
        }
        else {
          lVar11 = 0;
          do {
            lVar23 = lVar11 + 1;
            if (lVar23 == lVar21) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar11 = 0;
              goto LAB_00115c30;
            }
            pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar11;
            lVar11 = lVar23;
          } while (__pyx_mstate_global_static.__pyx_n_s_config != (PyObject *)*pPVar1);
          values[0] = kwvalues[lVar23];
        }
        goto LAB_00115e10;
      }
LAB_00115d34:
      values[0] = (PyObject *)0x0;
      goto LAB_00115d38;
    }
    if (__pyx_nargs == 1) {
      lVar21 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_00115864;
    }
  }
LAB_001157d4:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","load_config","exactly"
               ,1,"",__pyx_nargs);
  iVar8 = 0x2397;
  goto LAB_00115810;
  while( true ) {
    lVar23 = lVar11 + 1;
    if (lVar23 == lVar21) goto LAB_00115d34;
    p_Var14 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar11];
    lVar11 = lVar23;
    if ((_typeobject *)pPVar9 == p_Var14) break;
LAB_00115c30:
    bVar6 = pPVar9->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var14->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar23 = lVar11;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar9 != (PyObject *)puVar3) && (bVar6 || p_Var14 != (_typeobject *)puVar3)) {
        plVar12 = (long *)PyObject_RichCompare(pPVar9,p_Var14,2);
        if (plVar12 == (long *)0x0) goto LAB_00115d34;
        uVar18 = (uint)(plVar12 == (long *)puVar4);
        if ((plVar12 != (long *)puVar4 && plVar12 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar12 != (long *)puVar3) {
          uVar18 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar15 = *plVar12;
        *plVar12 = lVar15 + -1;
        if (lVar15 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
LAB_00115d20:
        if (uVar18 != 0) {
          if ((int)uVar18 < 0) goto LAB_00115d34;
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
         ((-1 < (char)p_Var14->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var14), iVar8 < 0))))
      goto LAB_00115d34;
      lVar15 = pPVar9[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar15 == (p_Var14->ob_base).ob_size) &&
         ((pPVar9[1].ob_type == (_typeobject *)p_Var14->tp_name ||
          (_typeobject *)p_Var14->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar9[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        pcVar17 = (char *)((ulong)(byte)((byte)pPVar9[2].ob_refcnt >> 2) & 7);
        uVar18 = (uint)pcVar17;
        in_x6 = pcVar17;
        if (((byte)((byte)p_Var14->tp_basicsize >> 2) & 7) == uVar18) {
          bVar2 = (byte)pPVar9[2].ob_refcnt;
          if ((bVar2 >> 5 & 1) == 0) {
            p_Var22 = pPVar9[4].ob_type;
          }
          else {
            p_Var22 = (_typeobject *)&pPVar9[4].ob_type;
            if ((bVar2 & 0x40) != 0) {
              p_Var22 = (_typeobject *)(pPVar9 + 3);
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
            in_x6 = (char *)(ulong)*(byte *)&(p_Var22->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(byte *)__s2;
          }
          else if (uVar18 == 2) {
            in_x6 = (char *)(ulong)*(ushort *)&(p_Var22->ob_base).ob_base.ob_refcnt;
            uVar18 = (uint)*(ushort *)__s2;
          }
          else {
            in_x6 = (char *)(ulong)*(uint *)&(p_Var22->ob_base).ob_base.ob_refcnt;
            uVar18 = *(uint *)__s2;
          }
          if (uVar18 == (uint)in_x6) {
            if (lVar15 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var22,__s2,(long)pcVar17 * lVar15);
              uVar18 = (uint)(iVar8 == 0);
              goto LAB_00115d20;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar23];
LAB_00115e10:
  if (values[0] != (PyObject *)0x0) {
    lVar21 = lVar21 + -1;
LAB_00115864:
    if (0 < lVar21) {
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
      pPVar19 = (PyObject *)values;
      iVar8 = __Pyx_ParseOptionalKeywords
                        (__pyx_kwds,kwvalues,__pyx_pyargnames,pPVar19,(PyObject **)__pyx_nargs,
                         0x11d250,in_x6);
      if (iVar8 < 0) {
        iVar8 = 0x238c;
        goto LAB_00115810;
      }
    }
LAB_00115874:
                    /* Unresolved local var: PyObject * __pyx_v_pheater@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: wchar_t __pyx_t_5@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var13 = values[0]->ob_type->tp_getattro;
    if (p_Var13 == (getattrofunc)0x0) {
      pPVar9 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar9 = (*p_Var13)(values[0],__pyx_mstate_global_static.__pyx_n_s_get_printer);
    }
    if (pPVar9 == (PyObject *)0x0) {
      iVar8 = 0x23c6;
LAB_00115b9c:
      pPVar19 = (PyObject *)0x0;
      __Pyx_AddTraceback("extras.aht20_f.load_config",iVar8,0xf4,"aht20_f.py");
      goto LAB_0011582c;
    }
    p_Var14 = pPVar9->ob_type;
    if ((p_Var14 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var22 = pPVar9[1].ob_type, p_Var22 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar20 = (PyObject *)pPVar9[1].ob_refcnt;
      (p_Var22->ob_base).ob_base.ob_refcnt = (p_Var22->ob_base).ob_base.ob_refcnt + 1;
      pPVar20->ob_refcnt = pPVar20->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar21 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar21;
      if (lVar21 == 0) {
        (*p_Var14->tp_dealloc)(pPVar9);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var22;
      pPVar19 = __Pyx_PyObject_FastCallDict(pPVar20,(PyObject **)__pyx_pyargnames,1,pPVar19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar21 = (p_Var22->ob_base).ob_base.ob_refcnt + -1;
      (p_Var22->ob_base).ob_base.ob_refcnt = lVar21;
      pPVar9 = pPVar20;
      if (lVar21 == 0) {
        (*((p_Var22->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var22);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar19 = __Pyx_PyObject_FastCallDict(pPVar9,(PyObject **)(__pyx_pyargnames + 1),0,pPVar19);
    }
    if (pPVar19 == (PyObject *)0x0) {
      iVar8 = 0x23da;
LAB_00115f44:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar21 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar21;
      if (lVar21 == 0) {
        pPVar19 = (PyObject *)0x0;
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
        __Pyx_AddTraceback("extras.aht20_f.load_config",iVar8,0xf4,"aht20_f.py");
      }
      else {
        pPVar19 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.load_config",iVar8,0xf4,"aht20_f.py");
      }
      goto LAB_0011582c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar21 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar21;
    if (lVar21 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var13 = pPVar19->ob_type->tp_getattro;
    if (p_Var13 == (getattrofunc)0x0) {
      pPVar9 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar9 = (*p_Var13)(pPVar19,__pyx_mstate_global_static.__pyx_n_s_lookup_object);
    }
    lVar21 = pPVar19->ob_refcnt + -1;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar19->ob_refcnt = lVar21;
    if (pPVar9 == (PyObject *)0x0) {
      iVar8 = 0x23de;
      if (lVar21 == 0) {
        (*pPVar19->ob_type->tp_dealloc)(pPVar19);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      }
      goto LAB_00115b9c;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    if (lVar21 == 0) {
      (*pPVar19->ob_type->tp_dealloc)(pPVar19);
    }
    p_Var14 = pPVar9->ob_type;
    if ((p_Var14 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var22 = pPVar9[1].ob_type, p_Var22 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar19 = (PyObject *)pPVar9[1].ob_refcnt;
      (p_Var22->ob_base).ob_base.ob_refcnt = (p_Var22->ob_base).ob_base.ob_refcnt + 1;
      pPVar19->ob_refcnt = pPVar19->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar21 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar21;
      if (lVar21 == 0) {
        (*p_Var14->tp_dealloc)(pPVar9);
      }
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_heaters;
      __pyx_pyargnames[0] = (PyObject **)p_Var22;
      pPVar20 = __Pyx_PyObject_FastCallDict
                          (pPVar19,(PyObject **)__pyx_pyargnames,2,
                           __pyx_mstate_global_static.__pyx_n_s_heaters);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar21 = (p_Var22->ob_base).ob_base.ob_refcnt + -1;
      (p_Var22->ob_base).ob_base.ob_refcnt = lVar21;
      pPVar9 = pPVar19;
      if (lVar21 == 0) {
        (*((p_Var22->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var22);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_heaters;
      pPVar20 = __Pyx_PyObject_FastCallDict
                          (pPVar9,(PyObject **)(__pyx_pyargnames + 1),1,
                           __pyx_mstate_global_static.__pyx_n_s_heaters);
    }
    if (pPVar20 == (PyObject *)0x0) {
      iVar8 = 0x23f3;
      goto LAB_00115f44;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar21 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar21;
    if (lVar21 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var13 = pPVar20->ob_type->tp_getattro;
    if (p_Var13 == (getattrofunc)0x0) {
      pPVar9 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar9 = (*p_Var13)(pPVar20,__pyx_mstate_global_static.__pyx_n_s_add_sensor_factory);
    }
    pPVar19 = __pyx_dict_cached_value_17973;
    if (pPVar9 == (PyObject *)0x0) {
      __Pyx_AddTraceback("extras.aht20_f.load_config",0x23ff,0xf5,"aht20_f.py");
      pPVar19 = (PyObject *)0x0;
    }
    else {
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17972) {
        if (__pyx_dict_cached_value_17973 == (PyObject *)0x0) {
          pPVar19 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F);
          goto LAB_00116010;
        }
        __pyx_dict_cached_value_17973->ob_refcnt = __pyx_dict_cached_value_17973->ob_refcnt + 1;
LAB_00115a80:
        p_Var14 = pPVar9->ob_type;
        if ((p_Var14 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
           (p_Var22 = pPVar9[1].ob_type, p_Var22 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          func = (PyObject *)pPVar9[1].ob_refcnt;
          (p_Var22->ob_base).ob_base.ob_refcnt = (p_Var22->ob_base).ob_base.ob_refcnt + 1;
          func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar21 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar21;
          if (lVar21 == 0) {
            (*p_Var14->tp_dealloc)(pPVar9);
          }
          __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_AHT20_F;
          __pyx_pyargnames[0] = (PyObject **)p_Var22;
          pPVar10 = __Pyx_PyObject_FastCallDict
                              (func,(PyObject **)__pyx_pyargnames,3,
                               __pyx_mstate_global_static.__pyx_n_s_AHT20_F);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar21 = (p_Var22->ob_base).ob_base.ob_refcnt + -1;
          (p_Var22->ob_base).ob_base.ob_refcnt = lVar21;
          pPVar9 = func;
          if (lVar21 != 0) goto LAB_00115af8;
          (*((p_Var22->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var22);
          lVar21 = pPVar19->ob_refcnt + -1;
          pPVar19->ob_refcnt = lVar21;
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_AHT20_F;
          pPVar10 = __Pyx_PyObject_FastCallDict
                              (pPVar9,(PyObject **)(__pyx_pyargnames + 1),2,
                               __pyx_mstate_global_static.__pyx_n_s_AHT20_F);
LAB_00115af8:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar21 = pPVar19->ob_refcnt + -1;
          pPVar19->ob_refcnt = lVar21;
        }
        if (lVar21 == 0) {
          (*pPVar19->ob_type->tp_dealloc)(pPVar19);
        }
        if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar21 = pPVar9->ob_refcnt + -1;
          pPVar9->ob_refcnt = lVar21;
          if (lVar21 == 0) {
            (*pPVar9->ob_type->tp_dealloc)(pPVar9);
            lVar21 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar21;
          }
          else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar21 = pPVar10->ob_refcnt + -1;
            pPVar10->ob_refcnt = lVar21;
          }
          if (lVar21 == 0) {
            (*pPVar10->ob_type->tp_dealloc)(pPVar10);
          }
          pPVar19 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
          *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
          goto LAB_00115b44;
        }
        iVar8 = 0x2416;
      }
      else {
        pPVar19 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_AHT20_F,
                             (uint64_t *)&__pyx_dict_version_17972,&__pyx_dict_cached_value_17973);
LAB_00116010:
        iVar8 = 0x2401;
        if (pPVar19 != (PyObject *)0x0) goto LAB_00115a80;
      }
      lVar21 = pPVar9->ob_refcnt + -1;
      pPVar9->ob_refcnt = lVar21;
      if (lVar21 == 0) {
        pPVar19 = (PyObject *)0x0;
        (*pPVar9->ob_type->tp_dealloc)(pPVar9);
        __Pyx_AddTraceback("extras.aht20_f.load_config",iVar8,0xf5,"aht20_f.py");
      }
      else {
        pPVar19 = (PyObject *)0x0;
        __Pyx_AddTraceback("extras.aht20_f.load_config",iVar8,0xf5,"aht20_f.py");
      }
    }
LAB_00115b44:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar21 = pPVar20->ob_refcnt + -1;
    pPVar20->ob_refcnt = lVar21;
    if (lVar21 == 0) {
      (*pPVar20->ob_type->tp_dealloc)(pPVar20);
    }
    goto LAB_0011582c;
  }
LAB_00115d38:
  lVar21 = PyErr_Occurred();
  if (lVar21 == 0) goto LAB_001157d4;
  iVar8 = 0x2387;
LAB_00115810:
  pPVar19 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.load_config",iVar8,0xf2,"aht20_f.py");
LAB_0011582c:
  if (lVar16 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar19;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00116150
 * Symbol:  __pyx_pf_6extras_7aht20_f_7AHT20_F_16_reset_device
 * Signature: PyObject * __pyx_pf_6extras_7aht20_f_7AHT20_F_16_reset_device(PyObject * __pyx_self, PyObject * __pyx_v_self)
 * ================================================================ */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

PyObject *
__pyx_pf_6extras_7aht20_f_7AHT20_F_16_reset_device(PyObject *__pyx_self,PyObject *__pyx_v_self)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  PyObject *pPVar6;
  long lVar7;
  PyObject *d;
  PyObject *pPVar8;
  PyObject *pPVar9;
  PyObject *func;
  PyObject *pPVar10;
  PyObject *pPVar11;
  _typeobject *p_Var12;
  int wraparound;
  getattrofunc p_Var13;
  __pyx_mstate *kwargs;
  long lVar14;
  int in_w5;
  _typeobject *p_Var15;
  _typeobject *p_Var16;
  PyObject *pPVar17;
  PyObject **local_38;
  PyObject *local_30;
  PyObject *local_28;
  PyObject *__pyx_callargs [2];
  
                    /* Unresolved local var: PyObject * __pyx_v_read@[???]
                       Unresolved local var: PyObject * __pyx_v_data@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: int __pyx_t_2@[???]
                       Unresolved local var: int __pyx_t_3@[???]
                       Unresolved local var: PyObject * __pyx_t_4@[???]
                       Unresolved local var: PyObject * __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: wchar_t __pyx_t_7@[???]
                       Unresolved local var: PyObject * __pyx_t_8@[???]
                       Unresolved local var: int __pyx_t_9@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???] */
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  lVar14 = *(long *)PTR___stack_chk_guard_0012ff30;
  p_Var13 = __pyx_self->ob_type->tp_getattro;
  pPVar11 = (PyObject *)PTR___stack_chk_guard_0012ff30;
  if (p_Var13 == (getattrofunc)0x0) {
    pPVar6 = (PyObject *)PyObject_GetAttr();
    if (pPVar6 != (PyObject *)0x0) goto LAB_001161a4;
LAB_00118438:
    iVar1 = 0x96;
    iVar4 = 0x1a76;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_0011836c;
  }
  pPVar6 = (*p_Var13)(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_init_sent);
  if (pPVar6 == (PyObject *)0x0) goto LAB_00118438;
LAB_001161a4:
                    /* Unresolved local var: int is_true@[???] */
  uVar5 = (uint)(pPVar6 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
  if (((uVar5 == 0 && pPVar6 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
       pPVar6 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
     (uVar5 = PyObject_IsTrue(pPVar6), (int)uVar5 < 0)) {
    iVar4 = 0x1a78;
    iVar1 = 0x96;
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar17 = (PyObject *)0x0;
    pPVar8 = (PyObject *)0x0;
    d = (PyObject *)0x0;
    local_28 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    goto LAB_001182cc;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar6->ob_refcnt + -1;
  pPVar6->ob_refcnt = lVar7;
  pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
  if (lVar7 == 0) {
    (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
  }
  PTR__Py_NoneStruct_0012ff50 = (undefined *)pPVar9;
  if (uVar5 == 0) {
    pPVar9->ob_refcnt = pPVar9->ob_refcnt + 1;
    goto LAB_00116208;
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var13 = __pyx_self->ob_type->tp_getattro;
  if (p_Var13 == (getattrofunc)0x0) {
    d = (PyObject *)PyObject_GetAttr();
  }
  else {
    d = (*p_Var13)(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
  }
  if (d == (PyObject *)0x0) {
    iVar1 = 0x9a;
    iVar4 = 0x1a98;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_0011836c;
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var13 = d->ob_type->tp_getattro;
  if (p_Var13 == (getattrofunc)0x0) {
    pPVar8 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar8 = (*p_Var13)(d,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
  }
  lVar7 = d->ob_refcnt + -1;
  if (pPVar8 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    func = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    iVar1 = 0x9a;
    iVar4 = 0x1a9a;
    pPVar17 = (PyObject *)0x0;
    goto LAB_001182e4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  d->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*d->ob_type->tp_dealloc)(d);
  }
  d = __pyx_dict_cached_value_17248;
  if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_17247) {
    d = __Pyx__GetModuleGlobalName
                  (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                   (uint64_t *)&__pyx_dict_version_17247,&__pyx_dict_cached_value_17248);
LAB_001185a8:
    if (d != (PyObject *)0x0) goto LAB_001162d8;
    pPVar10 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    func = (PyObject *)0x0;
    iVar1 = 0x9a;
    iVar4 = 0x1a9d;
    lVar7 = pPVar8->ob_refcnt + -1;
    goto LAB_00118308;
  }
  if (__pyx_dict_cached_value_17248 == (PyObject *)0x0) {
    d = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
    goto LAB_001185a8;
  }
  __pyx_dict_cached_value_17248->ob_refcnt = __pyx_dict_cached_value_17248->ob_refcnt + 1;
LAB_001162d8:
  if (d->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
    pPVar6 = __Pyx_PyDict_GetItem(d,__pyx_mstate_global_static.__pyx_n_s_RESET);
  }
  else {
    pPVar6 = (PyObject *)PyObject_GetItem();
  }
  lVar7 = d->ob_refcnt + -1;
  if (pPVar6 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    iVar1 = 0x9a;
    iVar4 = 0x1a9f;
    pPVar17 = (PyObject *)0x0;
    func = (PyObject *)0x0;
    goto LAB_001182e4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  d->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*d->ob_type->tp_dealloc)(d);
  }
  p_Var12 = pPVar8->ob_type;
  __pyx_callargs[1] = pPVar6;
  if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
     (p_Var15 = pPVar8[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    pPVar17 = (PyObject *)pPVar8[1].ob_refcnt;
    (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
    pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*p_Var12->tp_dealloc)(pPVar8);
    }
    __pyx_callargs[0] = (PyObject *)p_Var15;
    pPVar9 = __Pyx_PyObject_FastCallDict(pPVar17,__pyx_callargs,2,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
    (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
    pPVar8 = pPVar17;
    if (lVar7 == 0) {
      (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
    }
  }
  else {
    __pyx_callargs[0] = (PyObject *)0x0;
    pPVar9 = __Pyx_PyObject_FastCallDict(pPVar8,__pyx_callargs + 1,1,pPVar11);
  }
  local_38 = __pyx_callargs;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar6->ob_refcnt + -1;
  pPVar6->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar6->ob_type->tp_dealloc)(pPVar6);
  }
  if (pPVar9 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    iVar1 = 0x9a;
    iVar4 = 0x1ab5;
    pPVar9 = (PyObject *)0x0;
LAB_00118638:
    pPVar17 = (PyObject *)0x0;
    func = (PyObject *)0x0;
    lVar7 = pPVar8->ob_refcnt + -1;
    goto LAB_00118308;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar8->ob_refcnt + -1;
  pPVar8->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar9->ob_refcnt + -1;
  pPVar9->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar9->ob_type->tp_dealloc)(pPVar9);
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var13 = __pyx_self->ob_type->tp_getattro;
  if (p_Var13 == (getattrofunc)0x0) {
    pPVar8 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar8 = (*p_Var13)(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
  }
  if (pPVar8 == (PyObject *)0x0) {
    iVar1 = 0x9c;
    iVar4 = 0x1ac2;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_0011836c;
  }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
  p_Var13 = pPVar8->ob_type->tp_getattro;
  if (p_Var13 == (getattrofunc)0x0) {
    func = (PyObject *)PyObject_GetAttr();
  }
  else {
    func = (*p_Var13)(pPVar8,__pyx_mstate_global_static.__pyx_n_s_pause);
  }
  lVar7 = pPVar8->ob_refcnt + -1;
  if (func == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    iVar1 = 0x9c;
    iVar4 = 0x1ac4;
    goto LAB_00118308;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  pPVar8->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
  }
  d = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
  if (d == (PyObject *)0x0) {
    iVar1 = 0x9c;
    iVar4 = 0x1ac7;
    pPVar17 = (PyObject *)0x0;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_00118324;
  }
  pPVar17 = __Pyx_PyObject_GetAttrStr(d,__pyx_mstate_global_static.__pyx_n_s_monotonic);
  if (pPVar17 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    iVar1 = 0x9c;
    lVar7 = d->ob_refcnt + -1;
    iVar4 = 0x1ac9;
    pPVar17 = (PyObject *)0x0;
    pPVar8 = (PyObject *)0x0;
    goto LAB_001182e4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = d->ob_refcnt + -1;
  d->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*d->ob_type->tp_dealloc)(d);
  }
  p_Var12 = pPVar17->ob_type;
  if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
     (p_Var15 = pPVar17[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    pPVar6 = (PyObject *)pPVar17[1].ob_refcnt;
    (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
    pPVar6->ob_refcnt = pPVar6->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*p_Var12->tp_dealloc)(pPVar17);
    }
    iVar4 = 1;
    __pyx_callargs[1] = (PyObject *)0x0;
    __pyx_callargs[0] = (PyObject *)p_Var15;
    pPVar8 = __Pyx_PyObject_FastCallDict(pPVar6,local_38,1,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
    (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
    pPVar17 = pPVar6;
    if (lVar7 == 0) {
      (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
    }
  }
  else {
    iVar4 = 0;
    __pyx_callargs[0] = (PyObject *)0x0;
    __pyx_callargs[1] = (PyObject *)0x0;
    pPVar8 = __Pyx_PyObject_FastCallDict(pPVar17,__pyx_callargs + 1,0,pPVar11);
  }
  if (pPVar8 == (PyObject *)0x0) {
    iVar1 = 0x9c;
    iVar4 = 0x1ade;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_00118324;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar17->ob_refcnt + -1;
  pPVar17->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar17->ob_type->tp_dealloc)(pPVar17);
  }
  pPVar6 = __Pyx_PyFloat_AddObjC
                     (pPVar8,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar4,
                      (int)pPVar11);
  if (pPVar6 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    lVar7 = pPVar8->ob_refcnt + -1;
    iVar1 = 0x9c;
    iVar4 = 0x1ae2;
    pPVar17 = (PyObject *)0x0;
    goto LAB_00118308;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar8->ob_refcnt + -1;
  pPVar8->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar8->ob_type->tp_dealloc)(pPVar8);
  }
  p_Var12 = func->ob_type;
  if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
     (p_Var15 = func[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    pPVar17 = (PyObject *)func[1].ob_refcnt;
    (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
    pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*p_Var12->tp_dealloc)(func);
    }
    __pyx_callargs[0] = (PyObject *)p_Var15;
    __pyx_callargs[1] = pPVar6;
    pPVar9 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
    (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
    func = pPVar17;
    if (lVar7 == 0) {
      (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
    }
  }
  else {
    __pyx_callargs[0] = (PyObject *)0x0;
    __pyx_callargs[1] = pPVar6;
    pPVar9 = __Pyx_PyObject_FastCallDict(func,__pyx_callargs + 1,1,pPVar11);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar6->ob_refcnt + -1;
  pPVar6->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar6->ob_type->tp_dealloc)(pPVar6);
  }
  if (pPVar9 == (PyObject *)0x0) {
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    iVar1 = 0x9c;
    iVar4 = 0x1af8;
    pPVar17 = (PyObject *)0x0;
    goto LAB_00118324;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = func->ob_refcnt + -1;
  func->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*func->ob_type->tp_dealloc)(func);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar9->ob_refcnt + -1;
  pPVar9->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar9->ob_type->tp_dealloc)(pPVar9);
  }
  func = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
  if (func == (PyObject *)0x0) {
    iVar1 = 0x9e;
    iVar4 = 0x1b05;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_0011836c;
  }
  pPVar17 = __Pyx_PyObject_GetAttrStr(func,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
  if (pPVar17 == (PyObject *)0x0) {
    iVar1 = 0x9e;
    iVar4 = 0x1b07;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_00118324;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = func->ob_refcnt + -1;
  func->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*func->ob_type->tp_dealloc)(func);
  }
  func = __pyx_dict_cached_value_17280;
  if (__pyx_mstate_global_static.__pyx_d[1].ob_type != __pyx_dict_version_17279) {
    func = __Pyx__GetModuleGlobalName
                     (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                      (uint64_t *)&__pyx_dict_version_17279,&__pyx_dict_cached_value_17280);
LAB_001187a0:
    if (func != (PyObject *)0x0) goto LAB_001166f0;
    pPVar10 = (PyObject *)0x0;
    iVar1 = 0x9e;
    iVar4 = 0x1b0a;
    pPVar9 = (PyObject *)0x0;
    goto LAB_00118348;
  }
  if (__pyx_dict_cached_value_17280 == (PyObject *)0x0) {
    func = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
    goto LAB_001187a0;
  }
  __pyx_dict_cached_value_17280->ob_refcnt = __pyx_dict_cached_value_17280->ob_refcnt + 1;
LAB_001166f0:
  if (func->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
    pPVar6 = __Pyx_PyDict_GetItem(func,__pyx_mstate_global_static.__pyx_n_s_OTP_CCP);
  }
  else {
    pPVar6 = (PyObject *)PyObject_GetItem();
  }
  if (pPVar6 == (PyObject *)0x0) {
    iVar1 = 0x9e;
    iVar4 = 0x1b0c;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_00118324;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = func->ob_refcnt + -1;
  func->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*func->ob_type->tp_dealloc)(func);
  }
  p_Var12 = pPVar17->ob_type;
  if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
     (p_Var15 = pPVar17[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    pPVar8 = (PyObject *)pPVar17[1].ob_refcnt;
    (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
    pPVar8->ob_refcnt = pPVar8->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*p_Var12->tp_dealloc)(pPVar17);
    }
    __pyx_callargs[0] = (PyObject *)p_Var15;
    __pyx_callargs[1] = pPVar6;
    pPVar9 = __Pyx_PyObject_FastCallDict(pPVar8,local_38,2,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
    (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
    pPVar17 = pPVar8;
    if (lVar7 == 0) {
      (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
    }
  }
  else {
    __pyx_callargs[0] = (PyObject *)0x0;
    __pyx_callargs[1] = pPVar6;
    pPVar9 = __Pyx_PyObject_FastCallDict(pPVar17,__pyx_callargs + 1,1,pPVar11);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar6->ob_refcnt + -1;
  pPVar6->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar6->ob_type->tp_dealloc)(pPVar6);
  }
  if (pPVar9 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    iVar1 = 0x9e;
    iVar4 = 0x1b22;
    pPVar9 = (PyObject *)0x0;
    goto LAB_00118348;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar17->ob_refcnt + -1;
  pPVar17->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar17->ob_type->tp_dealloc)(pPVar17);
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar9->ob_refcnt + -1;
  pPVar9->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar9->ob_type->tp_dealloc)(pPVar9);
  }
  pPVar17 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
  if (pPVar17 == (PyObject *)0x0) {
    iVar1 = 0x9f;
    iVar4 = 0x1b2f;
    local_28 = (PyObject *)0x0;
    local_30 = (PyObject *)0x0;
    goto LAB_0011836c;
  }
  pPVar8 = __Pyx_PyObject_GetAttrStr(pPVar17,__pyx_mstate_global_static.__pyx_n_s_pause);
  if (pPVar8 == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    iVar1 = 0x9f;
    iVar4 = 0x1b31;
    goto LAB_00118348;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = pPVar17->ob_refcnt + -1;
  pPVar17->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*pPVar17->ob_type->tp_dealloc)(pPVar17);
  }
  func = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
  if (func == (PyObject *)0x0) {
    pPVar10 = (PyObject *)0x0;
    pPVar9 = (PyObject *)0x0;
    pPVar17 = (PyObject *)0x0;
    iVar1 = 0x9f;
    iVar4 = 0x1b34;
    lVar7 = pPVar8->ob_refcnt + -1;
LAB_00118308:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar8->ob_refcnt = lVar7;
    local_28 = pPVar10;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
LAB_00118320:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    local_30 = pPVar9;
    if (func != (PyObject *)0x0) {
LAB_00118324:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar7;
      pPVar9 = local_30;
      if (lVar7 == 0) {
        (*func->ob_type->tp_dealloc)(func);
      }
    }
LAB_00118344:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
    pPVar10 = local_28;
    local_30 = pPVar9;
    if (pPVar17 != (PyObject *)0x0) {
LAB_00118348:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar7;
      local_28 = pPVar10;
      local_30 = pPVar9;
      if (lVar7 == 0) {
        (*pPVar17->ob_type->tp_dealloc)(pPVar17);
      }
    }
LAB_0011836c:
    __Pyx_AddTraceback("extras.aht20_f.AHT20_F._reset_device",iVar4,iVar1,"aht20_f.py");
    if (local_30 == (PyObject *)0x0) {
      pPVar9 = (PyObject *)0x0;
    }
    else {
LAB_0011838c:
      pPVar9 = (PyObject *)0x0;
      lVar7 = local_30->ob_refcnt + -1;
      local_30->ob_refcnt = lVar7;
      if (lVar7 == 0) {
LAB_001183a0:
        (*local_30->ob_type->tp_dealloc)(local_30);
      }
    }
    if (local_28 == (PyObject *)0x0) goto LAB_00116208;
  }
  else {
    d = __Pyx_PyObject_GetAttrStr(func,__pyx_mstate_global_static.__pyx_n_s_monotonic);
    if (d == (PyObject *)0x0) {
      pPVar10 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      iVar1 = 0x9f;
      iVar4 = 0x1b36;
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar17 = (PyObject *)0x0;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    p_Var12 = d->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = d[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar6 = (PyObject *)d[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar6->ob_refcnt = pPVar6->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = d->ob_refcnt + -1;
      d->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(d);
      }
      iVar4 = 1;
      __pyx_callargs[1] = (PyObject *)0x0;
      __pyx_callargs[0] = (PyObject *)p_Var15;
      pPVar17 = __Pyx_PyObject_FastCallDict(pPVar6,local_38,1,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      d = pPVar6;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      iVar4 = 0;
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = (PyObject *)0x0;
      pPVar17 = __Pyx_PyObject_FastCallDict(d,__pyx_callargs + 1,0,pPVar11);
    }
    if (pPVar17 == (PyObject *)0x0) {
      local_28 = (PyObject *)0x0;
      iVar1 = 0x9f;
      iVar4 = 0x1b4b;
      pPVar17 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
LAB_001182d8:
      func = (PyObject *)0x0;
      lVar7 = d->ob_refcnt + -1;
      pPVar10 = local_28;
LAB_001182e4:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      d->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*d->ob_type->tp_dealloc)(d);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      local_28 = pPVar10;
      if (pPVar8 != (PyObject *)0x0) {
LAB_00118300:
        lVar7 = pPVar8->ob_refcnt + -1;
        pPVar10 = local_28;
        goto LAB_00118308;
      }
      goto LAB_00118320;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    pPVar6 = __Pyx_PyFloat_AddObjC
                       (pPVar17,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar4,
                        (int)pPVar11);
    if (pPVar6 == (PyObject *)0x0) {
      pPVar10 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      iVar1 = 0x9f;
      iVar4 = 0x1b4f;
      lVar7 = pPVar8->ob_refcnt + -1;
      func = (PyObject *)0x0;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    p_Var12 = pPVar8->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = pPVar8[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)pPVar8[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar8->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(pPVar8);
      }
      __pyx_callargs[0] = (PyObject *)p_Var15;
      __pyx_callargs[1] = pPVar6;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar8 = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar6;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar8,__pyx_callargs + 1,1,pPVar11);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    if (pPVar9 == (PyObject *)0x0) {
      pPVar10 = (PyObject *)0x0;
      iVar1 = 0x9f;
      iVar4 = 0x1b65;
      pPVar9 = (PyObject *)0x0;
      goto LAB_00118638;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xa1;
      iVar4 = 0x1b72;
      local_28 = (PyObject *)0x0;
      local_30 = (PyObject *)0x0;
      goto LAB_0011836c;
    }
    d = __Pyx_PyObject_GetAttrStr(pPVar8,__pyx_mstate_global_static.__pyx_n_s_i2c_read);
    if (d == (PyObject *)0x0) {
      pPVar10 = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar9 = (PyObject *)0x0;
      iVar1 = 0xa1;
      iVar4 = 0x1b74;
      func = (PyObject *)0x0;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    pPVar6 = (PyObject *)PyList_New(0);
    if (pPVar6 == (PyObject *)0x0) {
      pPVar10 = (PyObject *)0x0;
      pPVar9 = (PyObject *)0x0;
      iVar1 = 0xa1;
      iVar4 = 0x1b77;
      lVar7 = d->ob_refcnt + -1;
      func = (PyObject *)0x0;
      pPVar17 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      goto LAB_001182e4;
    }
    p_Var12 = d->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = d[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)d[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = d->ob_refcnt + -1;
      d->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(d);
      }
      pPVar8 = __pyx_mstate_global_static.__pyx_int_3;
      __pyx_callargs[0] = (PyObject *)p_Var15;
      __pyx_callargs[1] = pPVar6;
      pPVar9 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,3,pPVar11);
      iVar4 = (int)pPVar8;
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      d = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      pPVar17 = __pyx_mstate_global_static.__pyx_int_3;
      __pyx_callargs[1] = pPVar6;
      pPVar9 = __Pyx_PyObject_FastCallDict(d,__pyx_callargs + 1,2,pPVar11);
      iVar4 = (int)pPVar17;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    if (pPVar9 == (PyObject *)0x0) {
      local_28 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      iVar1 = 0xa1;
      iVar4 = 0x1b8c;
      pPVar17 = (PyObject *)0x0;
      goto LAB_001182d8;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    if (pPVar9->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar6 = __Pyx_PyDict_GetItem(pPVar9,__pyx_mstate_global_static.__pyx_n_s_response);
    }
    else {
      pPVar6 = (PyObject *)PyObject_GetItem();
    }
    local_30 = pPVar9;
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa2;
      iVar4 = 0x1b9a;
      local_28 = (PyObject *)0x0;
      goto LAB_0011836c;
    }
    iVar1 = 1;
    __pyx_callargs[0] = (PyObject *)0x0;
    __pyx_callargs[1] = pPVar6;
    pPVar10 = __Pyx_PyObject_FastCallDict
                        ((PyObject *)PTR_PyByteArray_Type_0012fed0,__pyx_callargs + 1,
                         0x8000000000000001,pPVar11);
    iVar2 = (int)pPVar11;
    local_28 = pPVar10;
    if (pPVar10 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      d = (PyObject *)0x0;
      lVar7 = pPVar6->ob_refcnt + -1;
      iVar4 = 0x1b9c;
      iVar1 = 0xa2;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    iVar1 = __Pyx_GetItemInt_ByteArray_Fast(pPVar10,1,iVar1,iVar2);
    if (iVar1 == -1) {
      iVar1 = 0xa4;
      iVar4 = 0x1ba9;
      goto LAB_0011836c;
    }
                    /* Unresolved local var: int neg_one@[???]
                       Unresolved local var: int const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
    d = (PyObject *)PyLong_FromLong((long)iVar1);
    pPVar6 = __pyx_dict_cached_value_17321;
    if (d == (PyObject *)0x0) {
      iVar1 = 0xa4;
      iVar4 = 0x1baa;
      goto LAB_0011836c;
    }
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17320) {
      if (__pyx_dict_cached_value_17321 == (PyObject *)0x0) {
        pPVar6 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_001189e4;
      }
      __pyx_dict_cached_value_17321->ob_refcnt = __pyx_dict_cached_value_17321->ob_refcnt + 1;
    }
    else {
      pPVar6 = __Pyx__GetModuleGlobalName
                         (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                          (uint64_t *)&__pyx_dict_version_17320,&__pyx_dict_cached_value_17321);
LAB_001189e4:
      if (pPVar6 == (PyObject *)0x0) {
        pPVar8 = (PyObject *)0x0;
        iVar1 = 0xa4;
        iVar4 = 0x1bac;
        lVar7 = d->ob_refcnt + -1;
        pPVar17 = (PyObject *)0x0;
        func = (PyObject *)0x0;
        goto LAB_001182e4;
      }
    }
    if (pPVar6->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar8 = __Pyx_PyDict_GetItem(pPVar6,__pyx_mstate_global_static.__pyx_n_s_CCP_CCN);
    }
    else {
      pPVar8 = (PyObject *)PyObject_GetItem();
    }
    lVar7 = pPVar6->ob_refcnt + -1;
    if (pPVar8 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar4 = 0x1bae;
      iVar1 = 0xa4;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar11 = d;
    iVar1 = __Pyx_SetItemInt_Fast(pPVar8,1,d,iVar2,iVar4,in_w5);
    iVar3 = (int)pPVar11;
    if (iVar1 < 0) {
      iVar1 = 0xa4;
      iVar4 = 0x1bb1;
      func = (PyObject *)0x0;
      lVar7 = d->ob_refcnt + -1;
      pPVar17 = (PyObject *)0x0;
      goto LAB_001182e4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    iVar1 = __Pyx_GetItemInt_ByteArray_Fast(pPVar10,2,iVar3,iVar2);
    if (iVar1 == -1) {
      iVar1 = 0xa5;
      iVar4 = 0x1bbc;
      goto LAB_0011836c;
    }
                    /* Unresolved local var: int neg_one@[???]
                       Unresolved local var: int const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
    d = (PyObject *)PyLong_FromLong((long)iVar1);
    pPVar8 = __pyx_dict_cached_value_17326;
    if (d == (PyObject *)0x0) {
      iVar1 = 0xa5;
      iVar4 = 0x1bbd;
      goto LAB_0011836c;
    }
    iVar1 = 0x130ae8;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17325) {
      if (__pyx_dict_cached_value_17326 == (PyObject *)0x0) {
        iVar1 = 0x130ae8;
        pPVar8 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_00118a80;
      }
      __pyx_dict_cached_value_17326->ob_refcnt = __pyx_dict_cached_value_17326->ob_refcnt + 1;
    }
    else {
      iVar1 = 0x130ae8;
      pPVar8 = __Pyx__GetModuleGlobalName
                         (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                          (uint64_t *)&__pyx_dict_version_17325,&__pyx_dict_cached_value_17326);
LAB_00118a80:
      if (pPVar8 == (PyObject *)0x0) {
        func = (PyObject *)0x0;
        iVar1 = 0xa5;
        iVar4 = 0x1bbf;
        lVar7 = d->ob_refcnt + -1;
        pPVar17 = (PyObject *)0x0;
        goto LAB_001182e4;
      }
    }
    if (pPVar8->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar6 = __Pyx_PyDict_GetItem(pPVar8,__pyx_mstate_global_static.__pyx_n_s_CCP_CCN);
    }
    else {
      pPVar6 = (PyObject *)PyObject_GetItem();
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa5;
      iVar4 = 0x1bc1;
      pPVar17 = (PyObject *)0x0;
      lVar7 = d->ob_refcnt + -1;
      func = (PyObject *)0x0;
      goto LAB_001182e4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    iVar2 = __Pyx_SetItemInt_Fast(pPVar6,2,d,iVar2,iVar4,iVar1);
    if (iVar2 < 0) {
      iVar4 = 0x1bc4;
      iVar1 = 0xa5;
      pPVar17 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      lVar7 = pPVar6->ob_refcnt + -1;
LAB_001182cc:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      pPVar6->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*pPVar6->ob_type->tp_dealloc)(pPVar6);
      }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
      if (d != (PyObject *)0x0) goto LAB_001182d8;
      func = (PyObject *)0x0;
      if (pPVar8 != (PyObject *)0x0) goto LAB_00118300;
      goto LAB_00118344;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    pPVar6 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa6;
      iVar4 = 0x1bcf;
      goto LAB_0011836c;
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(pPVar6,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
    if (pPVar8 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      d = (PyObject *)0x0;
      iVar4 = 0x1bd1;
      lVar7 = pPVar6->ob_refcnt + -1;
      iVar1 = 0xa6;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar6 = __pyx_dict_cached_value_17332;
    kwargs = &__pyx_mstate_global_static;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17331) {
      if (__pyx_dict_cached_value_17332 == (PyObject *)0x0) {
        pPVar6 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_00118b50;
      }
      __pyx_dict_cached_value_17332->ob_refcnt = __pyx_dict_cached_value_17332->ob_refcnt + 1;
    }
    else {
      pPVar6 = __Pyx__GetModuleGlobalName
                         (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                          (uint64_t *)&__pyx_dict_version_17331,&__pyx_dict_cached_value_17332);
LAB_00118b50:
      if (pPVar6 == (PyObject *)0x0) {
        pPVar17 = (PyObject *)0x0;
        iVar1 = 0xa6;
        iVar4 = 0x1bd4;
        lVar7 = pPVar8->ob_refcnt + -1;
        func = (PyObject *)0x0;
        goto LAB_00118308;
      }
    }
    if (pPVar6->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar11 = __Pyx_PyDict_GetItem(pPVar6,__pyx_mstate_global_static.__pyx_n_s_CCP_CCN);
    }
    else {
      pPVar11 = (PyObject *)PyObject_GetItem();
    }
    lVar7 = pPVar6->ob_refcnt + -1;
    if (pPVar11 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar4 = 0x1bd6;
      iVar1 = 0xa6;
      d = (PyObject *)0x0;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    p_Var12 = pPVar8->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = pPVar8[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)pPVar8[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar8->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(pPVar8);
      }
      __pyx_callargs[0] = (PyObject *)p_Var15;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar8 = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar8,__pyx_callargs + 1,1,(PyObject *)kwargs);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa6;
      iVar4 = 0x1bec;
      goto LAB_00118638;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xa7;
      iVar4 = 0x1bf9;
      goto LAB_0011836c;
    }
    pPVar17 = __Pyx_PyObject_GetAttrStr(pPVar8,__pyx_mstate_global_static.__pyx_n_s_pause);
    if (pPVar17 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      func = (PyObject *)0x0;
      iVar1 = 0xa7;
      lVar7 = pPVar8->ob_refcnt + -1;
      iVar4 = 0x1bfb;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    pPVar6 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa7;
      iVar4 = 0x1bfe;
      goto LAB_00118348;
    }
    func = __Pyx_PyObject_GetAttrStr(pPVar6,__pyx_mstate_global_static.__pyx_n_s_monotonic);
    if (func == (PyObject *)0x0) {
      iVar4 = 0x1c00;
      d = (PyObject *)0x0;
      lVar7 = pPVar6->ob_refcnt + -1;
      iVar1 = 0xa7;
      pPVar8 = (PyObject *)0x0;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    p_Var12 = func->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = func[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)func[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(func);
      }
      iVar2 = 1;
      __pyx_callargs[1] = (PyObject *)0x0;
      __pyx_callargs[0] = (PyObject *)p_Var15;
      pPVar8 = __Pyx_PyObject_FastCallDict(pPVar11,local_38,1,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      func = pPVar11;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      iVar2 = 0;
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = (PyObject *)0x0;
      pPVar8 = __Pyx_PyObject_FastCallDict(func,__pyx_callargs + 1,0,(PyObject *)kwargs);
    }
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xa7;
      iVar4 = 0x1c15;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    pPVar11 = __Pyx_PyFloat_AddObjC
                        (pPVar8,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar2,
                         (int)kwargs);
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xa7;
      iVar4 = 0x1c19;
      lVar7 = pPVar8->ob_refcnt + -1;
      func = (PyObject *)0x0;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    p_Var12 = pPVar17->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = pPVar17[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar8 = (PyObject *)pPVar17[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar8->ob_refcnt = pPVar8->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(pPVar17);
      }
      __pyx_callargs[0] = (PyObject *)p_Var15;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar8,local_38,2,(PyObject *)kwargs);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar17 = pPVar8;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,__pyx_callargs + 1,1,(PyObject *)kwargs);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa7;
      iVar4 = 0x1c2f;
      goto LAB_00118348;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar17 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
    if (pPVar17 == (PyObject *)0x0) {
      iVar1 = 0xa9;
      iVar4 = 0x1c3c;
      goto LAB_0011836c;
    }
    func = __Pyx_PyObject_GetAttrStr(pPVar17,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
    if (func == (PyObject *)0x0) {
      iVar1 = 0xa9;
      iVar4 = 0x1c3e;
      goto LAB_00118348;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    pPVar17 = __pyx_dict_cached_value_17364;
    p_Var12 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
    if (p_Var12 == __pyx_dict_version_17363) {
      if (__pyx_dict_cached_value_17364 == (PyObject *)0x0) {
        pPVar17 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_00118dc4;
      }
      __pyx_dict_cached_value_17364->ob_refcnt = __pyx_dict_cached_value_17364->ob_refcnt + 1;
    }
    else {
      pPVar17 = __Pyx__GetModuleGlobalName
                          (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                           (uint64_t *)&__pyx_dict_version_17363,&__pyx_dict_cached_value_17364);
LAB_00118dc4:
      if (pPVar17 == (PyObject *)0x0) {
        iVar1 = 0xa9;
        iVar4 = 0x1c41;
        goto LAB_00118324;
      }
    }
    if (pPVar17->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar11 = __Pyx_PyDict_GetItem(pPVar17,__pyx_mstate_global_static.__pyx_n_s_OTP_AFE);
    }
    else {
      pPVar11 = (PyObject *)PyObject_GetItem();
    }
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xa9;
      iVar4 = 0x1c43;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    p_Var15 = func->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = func[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)func[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(func);
      }
      __pyx_callargs[0] = (PyObject *)p_Var16;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      func = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(func,__pyx_callargs + 1,1,(PyObject *)p_Var12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xa9;
      iVar4 = 0x1c59;
      pPVar17 = (PyObject *)0x0;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    func = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (func == (PyObject *)0x0) {
      iVar1 = 0xaa;
      iVar4 = 0x1c66;
      goto LAB_0011836c;
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(func,__pyx_mstate_global_static.__pyx_n_s_pause);
    if (pPVar8 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar1 = 0xaa;
      iVar4 = 0x1c68;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    pPVar17 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (pPVar17 == (PyObject *)0x0) {
      func = (PyObject *)0x0;
      iVar1 = 0xaa;
      iVar4 = 0x1c6b;
      lVar7 = pPVar8->ob_refcnt + -1;
      goto LAB_00118308;
    }
    pPVar6 = __Pyx_PyObject_GetAttrStr(pPVar17,__pyx_mstate_global_static.__pyx_n_s_monotonic);
    if (pPVar6 == (PyObject *)0x0) {
      func = (PyObject *)0x0;
      iVar1 = 0xaa;
      iVar4 = 0x1c6d;
      lVar7 = pPVar8->ob_refcnt + -1;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    p_Var15 = pPVar6->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = pPVar6[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)pPVar6[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar6->ob_refcnt + -1;
      pPVar6->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(pPVar6);
      }
      iVar2 = 1;
      __pyx_callargs[1] = (PyObject *)0x0;
      __pyx_callargs[0] = (PyObject *)p_Var16;
      func = __Pyx_PyObject_FastCallDict(pPVar11,local_38,1,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar6 = pPVar11;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      iVar2 = 0;
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = (PyObject *)0x0;
      func = __Pyx_PyObject_FastCallDict(pPVar6,__pyx_callargs + 1,0,(PyObject *)p_Var12);
    }
    lVar7 = pPVar6->ob_refcnt + -1;
    if (func == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar4 = 0x1c82;
      iVar1 = 0xaa;
      d = (PyObject *)0x0;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar11 = __Pyx_PyFloat_AddObjC
                        (func,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar2,
                         (int)p_Var12);
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xaa;
      iVar4 = 0x1c86;
      goto LAB_00118d28;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    p_Var15 = pPVar8->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = pPVar8[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)pPVar8[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar8->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(pPVar8);
      }
      __pyx_callargs[0] = (PyObject *)p_Var16;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar8 = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar8,__pyx_callargs + 1,1,(PyObject *)p_Var12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xaa;
      iVar4 = 0x1c9c;
      goto LAB_00118638;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xac;
      iVar4 = 0x1ca9;
      goto LAB_00118e2c;
    }
    pPVar6 = __Pyx_PyObject_GetAttrStr(pPVar8,__pyx_mstate_global_static.__pyx_n_s_i2c_read);
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xac;
      iVar4 = 0x1cab;
      func = (PyObject *)0x0;
      goto LAB_00118d28;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    pPVar11 = (PyObject *)PyList_New(0);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar4 = 0x1cae;
      iVar1 = 0xac;
      d = (PyObject *)0x0;
      lVar7 = pPVar6->ob_refcnt + -1;
      pPVar8 = (PyObject *)0x0;
      goto LAB_001182cc;
    }
    p_Var12 = pPVar6->ob_type;
    if ((p_Var12 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var15 = pPVar6[1].ob_type, p_Var15 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)pPVar6[1].ob_refcnt;
      (p_Var15->ob_base).ob_base.ob_refcnt = (p_Var15->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar6->ob_refcnt + -1;
      pPVar6->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var12->tp_dealloc)(pPVar6);
      }
      __pyx_callargs[0] = (PyObject *)p_Var15;
      __pyx_callargs[1] = pPVar11;
      local_30 = __Pyx_PyObject_FastCallDict
                           (pPVar17,local_38,3,__pyx_mstate_global_static.__pyx_int_3);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var15->ob_base).ob_base.ob_refcnt + -1;
      (p_Var15->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar6 = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var15->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var15);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      local_30 = __Pyx_PyObject_FastCallDict
                           (pPVar6,__pyx_callargs + 1,2,__pyx_mstate_global_static.__pyx_int_3);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    lVar7 = pPVar6->ob_refcnt + -1;
    if (local_30 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      d = (PyObject *)0x0;
      iVar4 = 0x1cc3;
      iVar1 = 0xac;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar9->ob_refcnt + -1;
    pPVar9->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar9->ob_type->tp_dealloc)(pPVar9);
    }
    pPVar11 = local_30;
    if (local_30->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      d = __Pyx_PyDict_GetItem(local_30,__pyx_mstate_global_static.__pyx_n_s_response);
    }
    else {
      d = (PyObject *)PyObject_GetItem(local_30);
    }
    if (d == (PyObject *)0x0) {
      iVar1 = 0xad;
      iVar4 = 0x1cd1;
      goto LAB_00118e2c;
    }
    iVar2 = 1;
    __pyx_callargs[0] = (PyObject *)0x0;
    __pyx_callargs[1] = d;
    local_28 = __Pyx_PyObject_FastCallDict
                         ((PyObject *)PTR_PyByteArray_Type_0012fed0,__pyx_callargs + 1,
                          0x8000000000000001,pPVar11);
    iVar3 = (int)pPVar11;
    pPVar9 = local_30;
    if (local_28 == (PyObject *)0x0) {
      func = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      iVar1 = 0xad;
      iVar4 = 0x1cd3;
      lVar7 = d->ob_refcnt + -1;
      pPVar17 = (PyObject *)0x0;
      goto LAB_001182e4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    iVar2 = __Pyx_GetItemInt_ByteArray_Fast(local_28,1,iVar2,iVar3);
    if (iVar2 == -1) {
      iVar1 = 0xaf;
      iVar4 = 0x1ce0;
LAB_00118e2c:
      __Pyx_AddTraceback("extras.aht20_f.AHT20_F._reset_device",iVar4,iVar1,"aht20_f.py");
      goto LAB_0011838c;
    }
                    /* Unresolved local var: int neg_one@[???]
                       Unresolved local var: int const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
    pPVar6 = (PyObject *)PyLong_FromLong((long)iVar2);
    d = __pyx_dict_cached_value_17409;
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xaf;
      iVar4 = 0x1ce1;
      goto LAB_00118e2c;
    }
    p_Var12 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
    if (p_Var12 == __pyx_dict_version_17408) {
      if (__pyx_dict_cached_value_17409 == (PyObject *)0x0) {
        d = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_001192d0;
      }
      __pyx_dict_cached_value_17409->ob_refcnt = __pyx_dict_cached_value_17409->ob_refcnt + 1;
    }
    else {
      d = __Pyx__GetModuleGlobalName
                    (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                     (uint64_t *)&__pyx_dict_version_17408,&__pyx_dict_cached_value_17409);
LAB_001192d0:
      if (d == (PyObject *)0x0) {
        pPVar17 = (PyObject *)0x0;
        pPVar8 = (PyObject *)0x0;
        iVar4 = 0x1ce3;
        iVar1 = 0xaf;
        lVar7 = pPVar6->ob_refcnt + -1;
        goto LAB_001182cc;
      }
    }
    iVar2 = (int)p_Var12;
    if (d->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar8 = __Pyx_PyDict_GetItem(d,__pyx_mstate_global_static.__pyx_n_s_AFE_CFG);
    }
    else {
      pPVar8 = (PyObject *)PyObject_GetItem();
    }
    if (pPVar8 == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar4 = 0x1ce5;
      iVar1 = 0xaf;
      lVar7 = pPVar6->ob_refcnt + -1;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    pPVar11 = pPVar6;
    iVar3 = __Pyx_SetItemInt_Fast(pPVar8,1,pPVar6,iVar2,iVar4,iVar1);
    wraparound = (int)pPVar11;
    if (iVar3 < 0) {
      iVar4 = 0x1ce8;
      iVar1 = 0xaf;
      pPVar17 = (PyObject *)0x0;
      d = (PyObject *)0x0;
      lVar7 = pPVar6->ob_refcnt + -1;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    iVar2 = __Pyx_GetItemInt_ByteArray_Fast(local_28,2,wraparound,iVar2);
    if (iVar2 == -1) {
      iVar1 = 0xb0;
      iVar4 = 0x1cf3;
      goto LAB_00118e2c;
    }
                    /* Unresolved local var: int neg_one@[???]
                       Unresolved local var: int const_zero@[???]
                       Unresolved local var: int is_unsigned@[???] */
    pPVar6 = (PyObject *)PyLong_FromLong((long)iVar2);
    pPVar8 = __pyx_dict_cached_value_17414;
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xb0;
      iVar4 = 0x1cf4;
      goto LAB_00118e2c;
    }
    p_Var12 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
    if (p_Var12 == __pyx_dict_version_17413) {
      if (__pyx_dict_cached_value_17414 == (PyObject *)0x0) {
        pPVar8 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_00119124;
      }
      __pyx_dict_cached_value_17414->ob_refcnt = __pyx_dict_cached_value_17414->ob_refcnt + 1;
    }
    else {
      pPVar8 = __Pyx__GetModuleGlobalName
                         (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                          (uint64_t *)&__pyx_dict_version_17413,&__pyx_dict_cached_value_17414);
LAB_00119124:
      if (pPVar8 == (PyObject *)0x0) {
        pPVar17 = (PyObject *)0x0;
        d = (PyObject *)0x0;
        iVar4 = 0x1cf6;
        iVar1 = 0xb0;
        lVar7 = pPVar6->ob_refcnt + -1;
        goto LAB_001182cc;
      }
    }
    iVar2 = (int)p_Var12;
    if (pPVar8->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      d = __Pyx_PyDict_GetItem(pPVar8,__pyx_mstate_global_static.__pyx_n_s_AFE_CFG);
    }
    else {
      d = (PyObject *)PyObject_GetItem();
    }
    if (d == (PyObject *)0x0) {
      pPVar17 = (PyObject *)0x0;
      iVar4 = 0x1cf8;
      iVar1 = 0xb0;
      lVar7 = pPVar6->ob_refcnt + -1;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    iVar4 = __Pyx_SetItemInt_Fast(d,2,pPVar6,iVar2,iVar4,iVar1);
    if (iVar4 < 0) {
      iVar4 = 0x1cfb;
      iVar1 = 0xb0;
      pPVar17 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      lVar7 = pPVar6->ob_refcnt + -1;
      goto LAB_001182cc;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    d = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
    if (d == (PyObject *)0x0) {
      iVar1 = 0xb1;
      iVar4 = 0x1d06;
      goto LAB_00118e2c;
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(d,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
    pPVar10 = local_28;
    if (pPVar8 == (PyObject *)0x0) {
      func = (PyObject *)0x0;
      lVar7 = d->ob_refcnt + -1;
      iVar1 = 0xb1;
      iVar4 = 0x1d08;
      pPVar17 = (PyObject *)0x0;
      goto LAB_001182e4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    d = __pyx_dict_cached_value_17420;
    p_Var12 = __pyx_mstate_global_static.__pyx_d[1].ob_type;
    if (p_Var12 == __pyx_dict_version_17419) {
      if (__pyx_dict_cached_value_17420 == (PyObject *)0x0) {
        d = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_001190c8;
      }
      __pyx_dict_cached_value_17420->ob_refcnt = __pyx_dict_cached_value_17420->ob_refcnt + 1;
    }
    else {
      d = __Pyx__GetModuleGlobalName
                    (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                     (uint64_t *)&__pyx_dict_version_17419,&__pyx_dict_cached_value_17420);
LAB_001190c8:
      if (d == (PyObject *)0x0) {
        iVar1 = 0xb1;
        iVar4 = 0x1d0b;
        func = (PyObject *)0x0;
        goto LAB_00118d28;
      }
    }
    if (d->ob_type == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar11 = __Pyx_PyDict_GetItem(d,__pyx_mstate_global_static.__pyx_n_s_AFE_CFG);
    }
    else {
      pPVar11 = (PyObject *)PyObject_GetItem();
    }
    lVar7 = d->ob_refcnt + -1;
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xb1;
      iVar4 = 0x1d0d;
      pPVar17 = (PyObject *)0x0;
      func = (PyObject *)0x0;
      goto LAB_001182e4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    p_Var15 = pPVar8->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = pPVar8[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)pPVar8[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar8->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(pPVar8);
      }
      __pyx_callargs[0] = (PyObject *)p_Var16;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar8 = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar8,__pyx_callargs + 1,1,(PyObject *)p_Var12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      func = (PyObject *)0x0;
      iVar1 = 0xb1;
      iVar4 = 0x1d23;
      pPVar17 = (PyObject *)0x0;
      goto LAB_00118300;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xb2;
      iVar4 = 0x1d30;
      goto LAB_00118e2c;
    }
    func = __Pyx_PyObject_GetAttrStr(pPVar8,__pyx_mstate_global_static.__pyx_n_s_pause);
    if (func == (PyObject *)0x0) {
      iVar1 = 0xb2;
      iVar4 = 0x1d32;
LAB_00118d28:
      pPVar17 = (PyObject *)0x0;
      pPVar9 = local_30;
      goto LAB_00118300;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    d = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (d == (PyObject *)0x0) {
      iVar1 = 0xb2;
      iVar4 = 0x1d35;
      pPVar17 = (PyObject *)0x0;
      goto LAB_00118324;
    }
    pPVar17 = __Pyx_PyObject_GetAttrStr(d,__pyx_mstate_global_static.__pyx_n_s_monotonic);
    if (pPVar17 == (PyObject *)0x0) {
      lVar7 = d->ob_refcnt + -1;
      iVar1 = 0xb2;
      iVar4 = 0x1d37;
      pPVar17 = (PyObject *)0x0;
      pPVar8 = (PyObject *)0x0;
      goto LAB_001182e4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    p_Var15 = pPVar17->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = pPVar17[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)pPVar17[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(pPVar17);
      }
      iVar4 = 1;
      __pyx_callargs[1] = (PyObject *)0x0;
      __pyx_callargs[0] = (PyObject *)p_Var16;
      pPVar8 = __Pyx_PyObject_FastCallDict(pPVar11,local_38,1,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar17 = pPVar11;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      iVar4 = 0;
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = (PyObject *)0x0;
      pPVar8 = __Pyx_PyObject_FastCallDict(pPVar17,__pyx_callargs + 1,0,(PyObject *)p_Var12);
    }
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xb2;
      iVar4 = 0x1d4c;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    pPVar11 = __Pyx_PyFloat_AddObjC
                        (pPVar8,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar4,
                         (int)p_Var12);
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xb2;
      iVar4 = 0x1d50;
      goto LAB_00118d28;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
    p_Var15 = func->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = func[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)func[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(func);
      }
      __pyx_callargs[0] = (PyObject *)p_Var16;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      func = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(func,__pyx_callargs + 1,1,(PyObject *)p_Var12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xb2;
      iVar4 = 0x1d66;
      pPVar17 = (PyObject *)0x0;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    func = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_i2c);
    if (func == (PyObject *)0x0) {
      iVar1 = 0xb4;
      iVar4 = 0x1d73;
      goto LAB_00118e2c;
    }
    pPVar17 = __Pyx_PyObject_GetAttrStr(func,__pyx_mstate_global_static.__pyx_n_s_i2c_write);
    if (pPVar17 == (PyObject *)0x0) {
      iVar1 = 0xb4;
      iVar4 = 0x1d75;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    func = __pyx_dict_cached_value_17452;
    if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17451) {
      if (__pyx_dict_cached_value_17452 == (PyObject *)0x0) {
        func = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS);
        goto LAB_00118ed8;
      }
      __pyx_dict_cached_value_17452->ob_refcnt = __pyx_dict_cached_value_17452->ob_refcnt + 1;
    }
    else {
      func = __Pyx__GetModuleGlobalName
                       (__pyx_mstate_global_static.__pyx_n_s_AHT20_F_COMMANDS,
                        (uint64_t *)&__pyx_dict_version_17451,&__pyx_dict_cached_value_17452);
LAB_00118ed8:
      if (func == (PyObject *)0x0) {
        iVar1 = 0xb4;
        iVar4 = 0x1d78;
        goto LAB_00118348;
      }
    }
    p_Var12 = func->ob_type;
    if (p_Var12 == (_typeobject *)PTR_PyDict_Type_0012ff70) {
      pPVar11 = __Pyx_PyDict_GetItem(func,__pyx_mstate_global_static.__pyx_n_s_SYS_CFG);
    }
    else {
      pPVar11 = (PyObject *)PyObject_GetItem();
    }
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xb4;
      iVar4 = 0x1d7a;
      goto LAB_00118324;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    p_Var15 = pPVar17->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = pPVar17[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar8 = (PyObject *)pPVar17[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar8->ob_refcnt = pPVar8->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar17->ob_refcnt + -1;
      pPVar17->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(pPVar17);
      }
      __pyx_callargs[0] = (PyObject *)p_Var16;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar8,local_38,2,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar17 = pPVar8;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,__pyx_callargs + 1,1,(PyObject *)p_Var12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xb4;
      iVar4 = 0x1d90;
      goto LAB_00118348;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar17 = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (pPVar17 == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1d9d;
      goto LAB_00118e2c;
    }
    pPVar8 = __Pyx_PyObject_GetAttrStr(pPVar17,__pyx_mstate_global_static.__pyx_n_s_pause);
    if (pPVar8 == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1d9f;
      goto LAB_00118348;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    func = __Pyx_PyObject_GetAttrStr(__pyx_self,__pyx_mstate_global_static.__pyx_n_s_reactor);
    if (func == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1da2;
      goto LAB_00118d28;
    }
    d = __Pyx_PyObject_GetAttrStr(func,__pyx_mstate_global_static.__pyx_n_s_monotonic);
    if (d == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1da4;
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar17 = (PyObject *)0x0;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    p_Var15 = d->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = d[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar11 = (PyObject *)d[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar11->ob_refcnt = pPVar11->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = d->ob_refcnt + -1;
      d->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(d);
      }
      iVar4 = 1;
      __pyx_callargs[1] = (PyObject *)0x0;
      __pyx_callargs[0] = (PyObject *)p_Var16;
      pPVar17 = __Pyx_PyObject_FastCallDict(pPVar11,local_38,1,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      d = pPVar11;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      iVar4 = 0;
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = (PyObject *)0x0;
      pPVar17 = __Pyx_PyObject_FastCallDict(d,__pyx_callargs + 1,0,(PyObject *)p_Var12);
    }
    if (pPVar17 == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1db9;
      pPVar17 = (PyObject *)0x0;
      goto LAB_001182d8;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = d->ob_refcnt + -1;
    d->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*d->ob_type->tp_dealloc)(d);
    }
    pPVar11 = __Pyx_PyFloat_AddObjC
                        (pPVar17,__pyx_mstate_global_static.__pyx_float__10,_DAT_0011c830,iVar4,
                         (int)p_Var12);
    if (pPVar11 == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1dbd;
      lVar7 = pPVar8->ob_refcnt + -1;
      func = (PyObject *)0x0;
      goto LAB_00118308;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar17->ob_refcnt + -1;
    pPVar17->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar17->ob_type->tp_dealloc)(pPVar17);
    }
    p_Var15 = pPVar8->ob_type;
    if ((p_Var15 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var16 = pPVar8[1].ob_type, p_Var16 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar17 = (PyObject *)pPVar8[1].ob_refcnt;
      (p_Var16->ob_base).ob_base.ob_refcnt = (p_Var16->ob_base).ob_base.ob_refcnt + 1;
      pPVar17->ob_refcnt = pPVar17->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = pPVar8->ob_refcnt + -1;
      pPVar8->ob_refcnt = lVar7;
      if (lVar7 == 0) {
        (*p_Var15->tp_dealloc)(pPVar8);
      }
      __pyx_callargs[0] = (PyObject *)p_Var16;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar17,local_38,2,(PyObject *)p_Var12);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar7 = (p_Var16->ob_base).ob_base.ob_refcnt + -1;
      (p_Var16->ob_base).ob_base.ob_refcnt = lVar7;
      pPVar8 = pPVar17;
      if (lVar7 == 0) {
        (*((p_Var16->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var16);
      }
    }
    else {
      __pyx_callargs[0] = (PyObject *)0x0;
      __pyx_callargs[1] = pPVar11;
      pPVar6 = __Pyx_PyObject_FastCallDict(pPVar8,__pyx_callargs + 1,1,(PyObject *)p_Var12);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    if (pPVar6 == (PyObject *)0x0) {
      iVar1 = 0xb5;
      iVar4 = 0x1dd3;
      goto LAB_00118638;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar8->ob_refcnt + -1;
    pPVar8->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar8->ob_type->tp_dealloc)(pPVar8);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar7 = pPVar6->ob_refcnt + -1;
    pPVar6->ob_refcnt = lVar7;
    if (lVar7 == 0) {
      (*pPVar6->ob_type->tp_dealloc)(pPVar6);
    }
    pPVar9 = (PyObject *)PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    *(long *)PTR__Py_NoneStruct_0012ff50 = *(long *)PTR__Py_NoneStruct_0012ff50 + 1;
    lVar7 = local_30->ob_refcnt + -1;
    local_30->ob_refcnt = lVar7;
    if (lVar7 == 0) goto LAB_001183a0;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar7 = local_28->ob_refcnt + -1;
  local_28->ob_refcnt = lVar7;
  if (lVar7 == 0) {
    (*local_28->ob_type->tp_dealloc)(local_28);
  }
LAB_00116208:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
  if (lVar14 != *(long *)PTR___stack_chk_guard_0012ff30) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pPVar9;
}


/* ================================================================
 * Address: 00119318
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_17_reset_device
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_17_reset_device(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_17_reset_device
          (PyObject *__pyx_self,PyObject **__pyx_args,Py_ssize_t __pyx_nargs,PyObject *__pyx_kwds)

{
  PyObject **kwvalues;
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  PyObject *pPVar8;
  long lVar9;
  _typeobject *__s1;
  long *plVar10;
  _typeobject *extraout_x1;
  _typeobject *extraout_x1_00;
  _typeobject *extraout_x1_01;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  char *in_x6;
  long lVar15;
  _typeobject *p_Var16;
  long lVar17;
  PyObject *values [1];
  PyObject **__pyx_pyargnames [2];
  
  pPVar8 = __pyx_mstate_global_static.__pyx_n_s_self;
  puVar4 = PTR_PyUnicode_Type_0012ffb0;
  puVar3 = PTR__Py_TrueStruct_0012ff58;
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  puVar2 = PTR__Py_NoneStruct_0012ff50;
  values[0] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  lVar14 = *(long *)PTR___stack_chk_guard_0012ff30;
  __pyx_pyargnames[1] = (PyObject **)0x0;
  if (__pyx_kwds == (PyObject *)0x0) {
    if (__pyx_nargs == 1) {
      values[0] = *__pyx_args;
      pPVar8 = __pyx_pf_6extras_7aht20_f_7AHT20_F_16_reset_device(values[0],(PyObject *)__pyx_args);
      goto LAB_001193cc;
    }
  }
  else {
    kwvalues = __pyx_args + __pyx_nargs;
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    if (__pyx_nargs == 0) {
      lVar15 = __pyx_kwds[1].ob_refcnt;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
      if (0 < lVar15) {
        p_Var16 = __pyx_kwds[1].ob_type;
        if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_self == p_Var16) {
          values[0] = *kwvalues;
        }
        else {
          lVar9 = 0;
          do {
            lVar17 = lVar9 + 1;
            if (lVar17 == lVar15) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
              lVar9 = 0;
              goto LAB_00119498;
            }
            __pyx_args = (PyObject **)(&__pyx_kwds[2].ob_refcnt)[lVar9];
            lVar9 = lVar17;
          } while (__pyx_mstate_global_static.__pyx_n_s_self != (PyObject *)__pyx_args);
          values[0] = kwvalues[lVar17];
        }
        goto LAB_001195e4;
      }
LAB_001195a0:
      values[0] = (PyObject *)0x0;
      goto LAB_001195a4;
    }
    if (__pyx_nargs == 1) {
      lVar15 = __pyx_kwds[1].ob_refcnt;
      values[0] = *__pyx_args;
      goto LAB_001193f8;
    }
  }
LAB_00119374:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
  PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
               "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_reset_device",
               "exactly",1,"",__pyx_nargs);
  iVar7 = 0x1a41;
  goto LAB_001193b0;
  while( true ) {
    lVar17 = lVar9 + 1;
    if (lVar17 == lVar15) goto LAB_001195a0;
    p_Var16 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar9];
    lVar9 = lVar17;
    if ((_typeobject *)pPVar8 == p_Var16) break;
LAB_00119498:
    bVar5 = pPVar8->ob_type == (_typeobject *)puVar4;
    __pyx_args = (PyObject **)(ulong)bVar5;
    bVar6 = (p_Var16->ob_base).ob_base.ob_type != (_typeobject *)puVar4;
    lVar17 = lVar9;
    if (!bVar5 || bVar6) {
      if ((bVar6 || pPVar8 != (PyObject *)puVar2) && (!bVar5 || p_Var16 != (_typeobject *)puVar2)) {
        plVar10 = (long *)PyObject_RichCompare(pPVar8,p_Var16,2);
        if (plVar10 == (long *)0x0) goto LAB_001195a0;
        __pyx_args = (PyObject **)(ulong)(plVar10 == (long *)puVar3);
        if ((plVar10 != (long *)puVar3 && plVar10 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar10 != (long *)puVar2) {
          uVar12 = PyObject_IsTrue();
          __pyx_args = (PyObject **)(uVar12 & 0xffffffff);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar11 = *plVar10;
        *plVar10 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
LAB_00119588:
        if ((int)__pyx_args != 0) {
          if ((int)__pyx_args < 0) goto LAB_001195a0;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar8[2].ob_refcnt) &&
          (iVar7 = _PyUnicode_Ready(pPVar8), __pyx_args = (PyObject **)extraout_x1_00, iVar7 < 0))
         || ((-1 < (char)p_Var16->tp_basicsize &&
             (iVar7 = _PyUnicode_Ready(p_Var16), __pyx_args = (PyObject **)extraout_x1_01, iVar7 < 0
             )))) goto LAB_001195a0;
      lVar11 = pPVar8[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar11 == (p_Var16->ob_base).ob_size) &&
         (__pyx_args = (PyObject **)p_Var16->tp_name,
         (pPVar8[1].ob_type == (_typeobject *)__pyx_args ||
         (_typeobject *)__pyx_args == (_typeobject *)0xffffffffffffffff) ||
         pPVar8[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar12 = (ulong)(byte)((byte)pPVar8[2].ob_refcnt >> 2) & 7;
        uVar13 = (uint)uVar12;
        if (((byte)((byte)p_Var16->tp_basicsize >> 2) & 7) == uVar13) {
          bVar1 = (byte)pPVar8[2].ob_refcnt;
          if ((bVar1 >> 5 & 1) == 0) {
            __s1 = pPVar8[4].ob_type;
          }
          else {
            __s1 = (_typeobject *)&pPVar8[4].ob_type;
            if ((bVar1 & 0x40) != 0) {
              __s1 = (_typeobject *)(pPVar8 + 3);
            }
          }
          bVar1 = (byte)p_Var16->tp_basicsize;
          if ((bVar1 >> 5 & 1) == 0) {
            __pyx_args = (PyObject **)p_Var16->tp_setattr;
          }
          else {
            __pyx_args = (PyObject **)&p_Var16->tp_setattr;
            if ((bVar1 & 0x40) != 0) {
              __pyx_args = (PyObject **)&p_Var16->tp_dealloc;
            }
          }
          if (uVar13 == 1) {
            uVar13 = (uint)*(byte *)&(__s1->ob_base).ob_base.ob_refcnt;
            in_x6 = (char *)(ulong)(byte)(((_typeobject *)__pyx_args)->ob_base).ob_base.ob_refcnt;
          }
          else if (uVar13 == 2) {
            uVar13 = (uint)*(ushort *)&(__s1->ob_base).ob_base.ob_refcnt;
            in_x6 = (char *)(ulong)(ushort)(((_typeobject *)__pyx_args)->ob_base).ob_base.ob_refcnt;
          }
          else {
            uVar13 = *(uint *)&(__s1->ob_base).ob_base.ob_refcnt;
            in_x6 = (char *)(ulong)(uint)(((_typeobject *)__pyx_args)->ob_base).ob_base.ob_refcnt;
          }
          if ((uint)in_x6 == uVar13) {
            if (lVar11 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar7 = memcmp(__s1,__pyx_args,uVar12 * lVar11);
              __pyx_args = (PyObject **)(ulong)(iVar7 == 0);
              goto LAB_00119588;
            }
            break;
          }
        }
      }
    }
  }
  values[0] = kwvalues[lVar17];
LAB_001195e4:
  if (values[0] == (PyObject *)0x0) {
LAB_001195a4:
    lVar15 = PyErr_Occurred();
    if (lVar15 == 0) goto LAB_00119374;
    iVar7 = 0x1a31;
  }
  else {
    lVar15 = lVar15 + -1;
LAB_001193f8:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar15 < 1) ||
       (iVar7 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,kwvalues,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x11d2a8,in_x6),
       __pyx_args = (PyObject **)extraout_x1, -1 < iVar7)) {
      pPVar8 = __pyx_pf_6extras_7aht20_f_7AHT20_F_16_reset_device(values[0],(PyObject *)__pyx_args);
                    /* Unresolved local var: Py_ssize_t __pyx_temp@[???] */
      goto LAB_001193cc;
    }
    iVar7 = 0x1a36;
  }
LAB_001193b0:
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F._reset_device",iVar7,0x95,"aht20_f.py");
  pPVar8 = (PyObject *)0x0;
LAB_001193cc:
  if (lVar14 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ================================================================
 * Address: 00119758
 * Symbol:  __pyx_pw_6extras_7aht20_f_7AHT20_F_21_sample_aht20_f
 * Signature: PyObject * __pyx_pw_6extras_7aht20_f_7AHT20_F_21_sample_aht20_f(PyObject * __pyx_self, PyObject * * __pyx_args, Py_ssize_t __pyx_nargs, PyObject * __pyx_kwds)
 * ================================================================ */

PyObject *
__pyx_pw_6extras_7aht20_f_7AHT20_F_21_sample_aht20_f
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
  PyObject *func;
  PyObject *pPVar11;
  PyObject *pPVar12;
  PyObject *pPVar13;
  PyObject *obj;
  PyObject **ppPVar14;
  PyObject *pPVar15;
  long *plVar16;
  PyMappingMethods *pPVar17;
  PyObject *pPVar18;
  setattrfunc *pp_Var19;
  undefined8 uVar20;
  byte bVar21;
  getattrofunc p_Var22;
  long lVar23;
  binaryfunc p_Var24;
  setattrofunc p_Var25;
  ulong uVar26;
  char *pcVar27;
  long lVar28;
  PyObject *pPVar29;
  long lVar30;
  _typeobject *p_Var31;
  PyObject *pPVar32;
  _typeobject *p_Var33;
  PyObject *pPVar34;
  long lVar35;
  _typeobject **pp_Var36;
  long lVar37;
  long lVar38;
  int py_line;
  PyObject *local_80;
  PyObject *local_78;
  PyObject *local_70;
  PyObject *values [2];
  PyObject **__pyx_pyargnames [3];
  
                    /* Unresolved local var: PyObject * __pyx_v_self@[???]
                       Unresolved local var: PyObject * __pyx_v_eventtime@[???]
                       Unresolved local var: PyObject * * __pyx_kwvalues@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyObject * __pyx_r@[???] */
  lVar28 = *(long *)PTR___stack_chk_guard_0012ff30;
  values[0] = (PyObject *)0x0;
  values[1] = (PyObject *)0x0;
  __pyx_pyargnames[0] = &__pyx_mstate_global_static.__pyx_n_s_self;
  __pyx_pyargnames[1] = &__pyx_mstate_global_static.__pyx_n_s_eventtime;
  __pyx_pyargnames[2] = (PyObject **)0x0;
  if (__pyx_kwds != (PyObject *)0x0) {
                    /* Unresolved local var: Py_ssize_t kw_args@[???] */
    ppPVar14 = __pyx_args + __pyx_nargs;
    pcVar27 = PTR___stack_chk_guard_0012ff30;
    if (__pyx_nargs != 1) {
      if (__pyx_nargs == 2) {
        values[0] = *__pyx_args;
        values[1] = __pyx_args[1];
        lVar30 = __pyx_kwds[1].ob_refcnt;
        goto LAB_0011a7cc;
      }
      if (__pyx_nargs == 0) {
        lVar30 = __pyx_kwds[1].ob_refcnt;
        values[0] = __Pyx_GetKwValue_FASTCALL
                              (__pyx_kwds,ppPVar14,__pyx_mstate_global_static.__pyx_n_s_self);
        if (values[0] != (PyObject *)0x0) {
          lVar37 = __pyx_kwds[1].ob_refcnt;
          lVar30 = lVar30 + -1;
          goto LAB_0011a808;
        }
        lVar30 = PyErr_Occurred();
        if (lVar30 != 0) {
          iVar8 = 0x1fad;
          goto LAB_00119804;
        }
      }
LAB_001197c8:
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_sample_aht20_f",
                   "exactly",2,"s",__pyx_nargs);
      iVar8 = 0x1fc9;
      goto LAB_00119804;
    }
    lVar37 = __pyx_kwds[1].ob_refcnt;
    values[0] = *__pyx_args;
    lVar30 = lVar37;
LAB_0011a808:
    pPVar29 = __pyx_mstate_global_static.__pyx_n_s_eventtime;
    puVar5 = PTR_PyUnicode_Type_0012ffb0;
    puVar4 = PTR__Py_TrueStruct_0012ff58;
    puVar3 = PTR__Py_NoneStruct_0012ff50;
                    /* Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t n@[???] */
    if (0 < lVar37) {
      p_Var31 = __pyx_kwds[1].ob_type;
      if ((_typeobject *)__pyx_mstate_global_static.__pyx_n_s_eventtime == p_Var31) {
        values[1] = *ppPVar14;
      }
      else {
        lVar38 = 0;
        do {
          lVar35 = lVar38 + 1;
          if (lVar35 == lVar37) {
                    /* Unresolved local var: int eq@[???]
                       Unresolved local var: int s1_is_unicode@[???]
                       Unresolved local var: int s2_is_unicode@[???] */
                    /* Unresolved local var: int result@[???]
                       Unresolved local var: PyObject * py_result@[???]
                       Unresolved local var: int is_true@[???] */
            lVar38 = 0;
            goto LAB_0011a870;
          }
          pPVar1 = &__pyx_kwds[2].ob_refcnt + lVar38;
          lVar38 = lVar35;
        } while (__pyx_mstate_global_static.__pyx_n_s_eventtime != (PyObject *)*pPVar1);
        values[1] = ppPVar14[lVar35];
      }
      goto LAB_0011aa9c;
    }
LAB_0011ab40:
    values[1] = (PyObject *)0x0;
    goto LAB_0011ab44;
  }
  if (__pyx_nargs != 2) goto LAB_001197c8;
  values[0] = *__pyx_args;
  values[1] = __pyx_args[1];
LAB_0011986c:
  pPVar29 = values[0];
                    /* Unresolved local var: PyObject * __pyx_v_mcu_name@[???]
                       Unresolved local var: PyObject * __pyx_v_suffix@[???]
                       Unresolved local var: PyObject * __pyx_v_heater_name@[???]
                       Unresolved local var: PyObject * __pyx_v_heaters@[???]
                       Unresolved local var: PyObject * __pyx_v_heater@[???]
                       Unresolved local var: PyObject * __pyx_v_measured_time@[???]
                       Unresolved local var: PyObject * __pyx_v_print_time@[???]
                       Unresolved local var: PyObject * __pyx_r@[???]
                       Unresolved local var: PyObject * __pyx_t_1@[???]
                       Unresolved local var: PyObject * __pyx_t_2@[???]
                       Unresolved local var: PyObject * __pyx_t_3@[???]
                       Unresolved local var: wchar_t __pyx_t_4@[???]
                       Unresolved local var: int __pyx_t_5@[???]
                       Unresolved local var: PyObject * __pyx_t_6@[???]
                       Unresolved local var: Py_ssize_t __pyx_t_7@[???]
                       Unresolved local var: Py_UCS4 __pyx_t_8@[???]
                       Unresolved local var: int __pyx_t_9@[???]
                       Unresolved local var: int __pyx_lineno@[???]
                       Unresolved local var: char * __pyx_filename@[???]
                       Unresolved local var: int __pyx_clineno@[???]
                       Unresolved local var: PyTypeObject * tp@[???] */
  p_Var22 = values[0]->ob_type->tp_getattro;
  if (p_Var22 == (getattrofunc)0x0) {
    pPVar10 = (PyObject *)PyObject_GetAttr();
  }
  else {
    pPVar10 = (*p_Var22)(values[0],__pyx_mstate_global_static.__pyx_n_s_make_measurement);
  }
  if (pPVar10 == (PyObject *)0x0) {
    pPVar15 = (PyObject *)0x0;
    pPVar34 = (PyObject *)0x0;
    obj = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
    pPVar18 = (PyObject *)0x0;
    pPVar32 = (PyObject *)0x0;
    py_line = 0xcd;
    iVar8 = 0x2003;
    local_80 = (PyObject *)0x0;
    goto LAB_0011a970;
  }
  p_Var31 = pPVar10->ob_type;
  if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
     (p_Var33 = pPVar10[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
    pPVar32 = (PyObject *)pPVar10[1].ob_refcnt;
    (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
    pPVar32->ob_refcnt = pPVar32->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*p_Var31->tp_dealloc)(pPVar10);
    }
    __pyx_pyargnames[1] = (PyObject **)0x0;
    __pyx_pyargnames[0] = (PyObject **)p_Var33;
    func = __Pyx_PyObject_FastCallDict(pPVar32,(PyObject **)__pyx_pyargnames,1,pPVar10);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
    (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
    pPVar10 = pPVar32;
    if (lVar30 == 0) {
      (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
    }
  }
  else {
    __pyx_pyargnames[0] = (PyObject **)0x0;
    __pyx_pyargnames[1] = (PyObject **)0x0;
    func = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)(__pyx_pyargnames + 1),0,pPVar10);
  }
  local_78 = (PyObject *)__pyx_pyargnames;
  if (func == (PyObject *)0x0) {
    pPVar15 = (PyObject *)0x0;
    pPVar34 = (PyObject *)0x0;
    obj = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
    pPVar18 = (PyObject *)0x0;
    pPVar32 = (PyObject *)0x0;
    pPVar11 = (PyObject *)0x0;
    py_line = 0xcd;
    iVar8 = 0x2017;
    local_80 = (PyObject *)0x0;
    goto LAB_0011abc4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar30 = pPVar10->ob_refcnt + -1;
  pPVar10->ob_refcnt = lVar30;
  if (lVar30 == 0) {
    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
  }
  pPVar10 = (PyObject *)PyObject_RichCompare(func,PTR__Py_FalseStruct_0012ff20,2);
  if (pPVar10 == (PyObject *)0x0) {
    py_line = 0xcd;
    lVar30 = func->ob_refcnt + -1;
    pPVar11 = (PyObject *)0x0;
    pPVar15 = (PyObject *)0x0;
    pPVar34 = (PyObject *)0x0;
    obj = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
    pPVar18 = (PyObject *)0x0;
    pPVar32 = (PyObject *)0x0;
    iVar8 = 0x201b;
    local_80 = (PyObject *)0x0;
    pPVar12 = (PyObject *)0x0;
    goto LAB_0011ad24;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar30 = func->ob_refcnt + -1;
  func->ob_refcnt = lVar30;
  if (lVar30 == 0) {
    (*func->ob_type->tp_dealloc)(func);
  }
                    /* Unresolved local var: int is_true@[???] */
  uVar9 = (uint)(pPVar10 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
  if (((uVar9 == 0 && pPVar10 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
       pPVar10 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
     (uVar9 = PyObject_IsTrue(pPVar10), (int)uVar9 < 0)) {
    py_line = 0xcd;
    pPVar15 = (PyObject *)0x0;
    pPVar34 = (PyObject *)0x0;
    obj = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
    pPVar18 = (PyObject *)0x0;
    pPVar32 = (PyObject *)0x0;
    iVar8 = 0x201d;
    pPVar11 = (PyObject *)0x0;
    local_80 = (PyObject *)0x0;
    goto LAB_0011abc4;
  }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  lVar30 = pPVar10->ob_refcnt + -1;
  pPVar10->ob_refcnt = lVar30;
  if (lVar30 == 0) {
    (*pPVar10->ob_type->tp_dealloc)(pPVar10);
  }
  p_Var31 = pPVar29->ob_type;
  if (uVar9 == 0) {
    obj = (PyObject *)0x0;
    pPVar13 = (PyObject *)0x0;
    pPVar18 = (PyObject *)0x0;
    pPVar32 = (PyObject *)0x0;
    local_80 = (PyObject *)0x0;
LAB_0011a168:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    if (p_Var31->tp_getattro == (getattrofunc)0x0) {
      pPVar10 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar10 = (*p_Var31->tp_getattro)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_temp);
    }
    if (pPVar10 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe0;
      iVar8 = 0x219e;
      goto LAB_0011a970;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var22 = pPVar29->ob_type->tp_getattro;
    if (p_Var22 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var22)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_min_temp);
    }
    if (pPVar11 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe0;
      iVar8 = 0x21a0;
LAB_0011abc4:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = pPVar10->ob_refcnt + -1;
      pPVar10->ob_refcnt = lVar30;
      if (lVar30 == 0) {
        pPVar12 = (PyObject *)0x0;
        (*pPVar10->ob_type->tp_dealloc)(pPVar10);
      }
      else {
        pPVar12 = (PyObject *)0x0;
      }
LAB_0011abf0:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar11 != (PyObject *)0x0) &&
         (lVar30 = pPVar11->ob_refcnt + -1, pPVar11->ob_refcnt = lVar30, lVar30 == 0)) {
        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
      }
LAB_0011ac14:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
      if ((pPVar12 != (PyObject *)0x0) &&
         (lVar30 = pPVar12->ob_refcnt + -1, pPVar12->ob_refcnt = lVar30, lVar30 == 0)) {
        (*pPVar12->ob_type->tp_dealloc)(pPVar12);
      }
      goto LAB_0011a970;
    }
    func = (PyObject *)PyObject_RichCompare(pPVar10,pPVar11,0);
    if (func == (PyObject *)0x0) {
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe0;
      iVar8 = 0x21a2;
      pPVar15 = (PyObject *)0x0;
      goto LAB_0011abc4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: int is_true@[???] */
    uVar9 = (uint)(func == (PyObject *)PTR__Py_TrueStruct_0012ff58);
    if (((uVar9 == 0 && func != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
         func != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
       (uVar9 = PyObject_IsTrue(func), (int)uVar9 < 0)) {
      iVar8 = 0x21a5;
      py_line = 0xe0;
      pPVar12 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      lVar30 = func->ob_refcnt + -1;
      pPVar15 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0011ad24;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    if (uVar9 != 0) goto LAB_0011a994;
    func = __Pyx_PyObject_GetAttrStr(pPVar29,__pyx_mstate_global_static.__pyx_n_s_temp);
    if (func == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe0;
      iVar8 = 0x21ac;
      goto LAB_0011a970;
    }
    pPVar11 = __Pyx_PyObject_GetAttrStr(pPVar29,__pyx_mstate_global_static.__pyx_n_s_max_temp);
    if (pPVar11 == (PyObject *)0x0) {
      pPVar12 = (PyObject *)0x0;
      pPVar15 = (PyObject *)0x0;
      iVar8 = 0x21ae;
      py_line = 0xe0;
      lVar30 = func->ob_refcnt + -1;
      pPVar34 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
LAB_0011ad24:
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      func->ob_refcnt = lVar30;
      if (lVar30 == 0) {
        (*func->ob_type->tp_dealloc)(func);
      }
      goto LAB_0011abf0;
    }
    pPVar10 = (PyObject *)PyObject_RichCompare(func,pPVar11,4);
    if (pPVar10 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      lVar30 = func->ob_refcnt + -1;
      pPVar34 = (PyObject *)0x0;
      iVar8 = 0x21b0;
      py_line = 0xe0;
      pPVar12 = (PyObject *)0x0;
      goto LAB_0011ad24;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = func->ob_refcnt + -1;
    func->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: int is_true@[???] */
    uVar9 = (uint)(pPVar10 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
    if (((uVar9 == 0 && pPVar10 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
         pPVar10 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
       (uVar9 = PyObject_IsTrue(pPVar10), (int)uVar9 < 0)) {
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe0;
      iVar8 = 0x21b3;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0011abc4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
      if (uVar9 == 0) goto LAB_0011a31c;
LAB_0011a994:
      pPVar11 = __pyx_dict_cached_value_17775;
      if (__pyx_mstate_global_static.__pyx_d[1].ob_type == __pyx_dict_version_17774) {
        if (__pyx_dict_cached_value_17775 == (PyObject *)0x0) {
          pPVar11 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
          goto LAB_0011b5e8;
        }
        __pyx_dict_cached_value_17775->ob_refcnt = __pyx_dict_cached_value_17775->ob_refcnt + 1;
      }
      else {
        pPVar11 = __Pyx__GetModuleGlobalName
                            (__pyx_mstate_global_static.__pyx_n_s_logging,
                             (uint64_t *)&__pyx_dict_version_17774,&__pyx_dict_cached_value_17775);
LAB_0011b5e8:
        if (pPVar11 == (PyObject *)0x0) {
          pPVar15 = (PyObject *)0x0;
          pPVar34 = (PyObject *)0x0;
          py_line = 0xe4;
          iVar8 = 0x21c0;
          goto LAB_0011a970;
        }
      }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var22 = pPVar11->ob_type->tp_getattro;
      if (p_Var22 == (getattrofunc)0x0) {
        pPVar10 = (PyObject *)PyObject_GetAttr();
      }
      else {
        pPVar10 = (*p_Var22)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_info);
      }
      if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar30 = pPVar11->ob_refcnt + -1;
        pPVar11->ob_refcnt = lVar30;
        if (lVar30 == 0) {
          (*pPVar11->ob_type->tp_dealloc)(pPVar11);
        }
        p_Var31 = pPVar10->ob_type;
        if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
           (p_Var33 = pPVar10[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
          func = (PyObject *)pPVar10[1].ob_refcnt;
          (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
          func->ob_refcnt = func->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar30 = pPVar10->ob_refcnt + -1;
          pPVar10->ob_refcnt = lVar30;
          if (lVar30 == 0) {
            (*p_Var31->tp_dealloc)(pPVar10);
          }
          __pyx_pyargnames[1] =
               (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_AHT20_F_temperature_outside_rang;
          __pyx_pyargnames[0] = (PyObject **)p_Var33;
          pPVar34 = __Pyx_PyObject_FastCallDict
                              (func,(PyObject **)local_78,2,
                               __pyx_mstate_global_static.
                               __pyx_kp_s_AHT20_F_temperature_outside_rang);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
          (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
          if (lVar30 == 0) {
            (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
          }
        }
        else {
          __pyx_pyargnames[0] = (PyObject **)0x0;
          __pyx_pyargnames[1] =
               (PyObject **)__pyx_mstate_global_static.__pyx_kp_s_AHT20_F_temperature_outside_rang;
          pPVar34 = __Pyx_PyObject_FastCallDict
                              (pPVar10,(PyObject **)(__pyx_pyargnames + 1),1,
                               __pyx_mstate_global_static.
                               __pyx_kp_s_AHT20_F_temperature_outside_rang);
          func = pPVar10;
        }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
        lVar30 = func->ob_refcnt + -1;
        if (pPVar34 == (PyObject *)0x0) {
          pPVar12 = (PyObject *)0x0;
          pPVar15 = (PyObject *)0x0;
          iVar8 = 0x21d7;
          py_line = 0xe4;
          pPVar34 = (PyObject *)0x0;
          pPVar11 = (PyObject *)0x0;
          goto LAB_0011ad24;
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        func->ob_refcnt = lVar30;
        if (lVar30 == 0) {
          (*func->ob_type->tp_dealloc)(func);
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar30 = pPVar34->ob_refcnt + -1;
        pPVar34->ob_refcnt = lVar30;
        if (lVar30 == 0) {
          (*pPVar34->ob_type->tp_dealloc)(pPVar34);
        }
        goto LAB_0011a31c;
      }
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe4;
      iVar8 = 0x21c2;
      pPVar12 = (PyObject *)0x0;
      goto LAB_0011abf0;
    }
    if (uVar9 != 0) goto LAB_0011a994;
LAB_0011a31c:
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var22 = pPVar29->ob_type->tp_getattro;
    if (p_Var22 == (getattrofunc)0x0) {
      func = (PyObject *)PyObject_GetAttr();
    }
    else {
      func = (*p_Var22)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_reactor);
    }
    if (func == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      py_line = 0xe6;
      iVar8 = 0x21ed;
      goto LAB_0011a970;
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var22 = func->ob_type->tp_getattro;
    if (p_Var22 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var22)(func,__pyx_mstate_global_static.__pyx_n_s_monotonic);
    }
    lVar30 = func->ob_refcnt + -1;
    if (pPVar11 == (PyObject *)0x0) {
      pPVar12 = (PyObject *)0x0;
      pPVar15 = (PyObject *)0x0;
      iVar8 = 0x21ef;
      py_line = 0xe6;
      pPVar34 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0011ad24;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    p_Var31 = pPVar11->ob_type;
    if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var33 = pPVar11[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar10 = (PyObject *)pPVar11[1].ob_refcnt;
      (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
      pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = pPVar11->ob_refcnt + -1;
      pPVar11->ob_refcnt = lVar30;
      if (lVar30 == 0) {
        (*p_Var31->tp_dealloc)(pPVar11);
      }
      __pyx_pyargnames[1] = (PyObject **)0x0;
      __pyx_pyargnames[0] = (PyObject **)p_Var33;
      pPVar34 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)local_78,1,pPVar10);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
      (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
      pPVar11 = pPVar10;
      if (lVar30 == 0) {
        (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)0x0;
      pPVar34 = __Pyx_PyObject_FastCallDict(pPVar11,(PyObject **)(__pyx_pyargnames + 1),0,func);
    }
    if (pPVar34 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      pPVar12 = (PyObject *)0x0;
      py_line = 0xe6;
      iVar8 = 0x2204;
      goto LAB_0011abf0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    p_Var22 = pPVar29->ob_type->tp_getattro;
    if (p_Var22 == (getattrofunc)0x0) {
      pPVar11 = (PyObject *)PyObject_GetAttr();
    }
    else {
      pPVar11 = (*p_Var22)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_mcu);
    }
    if (pPVar11 == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      py_line = 0xe7;
      iVar8 = 0x2212;
      goto LAB_0011a970;
    }
    func = __Pyx_PyObject_GetAttrStr
                     (pPVar11,__pyx_mstate_global_static.__pyx_n_s_estimated_print_time);
    if (func == (PyObject *)0x0) {
      pPVar15 = (PyObject *)0x0;
      py_line = 0xe7;
      iVar8 = 0x2214;
      pPVar12 = (PyObject *)0x0;
      goto LAB_0011abf0;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    p_Var31 = func->ob_type;
    if (p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) {
      p_Var33 = func[1].ob_type;
      pPVar11 = (PyObject *)0x0;
      if (p_Var33 == (_typeobject *)0x0) goto LAB_0011b210;
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar10 = (PyObject *)func[1].ob_refcnt;
      (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
      pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar30;
      if (lVar30 == 0) {
        (*p_Var31->tp_dealloc)(func);
      }
      __pyx_pyargnames[0] = (PyObject **)p_Var33;
      __pyx_pyargnames[1] = (PyObject **)pPVar34;
      pPVar15 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)local_78,2,(PyObject *)p_Var33);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
      (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
      func = pPVar10;
      if (lVar30 == 0) {
        (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
      }
    }
    else {
LAB_0011b210:
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)pPVar34;
      pPVar15 = __Pyx_PyObject_FastCallDict(func,(PyObject **)(__pyx_pyargnames + 1),1,pPVar11);
    }
    lVar30 = func->ob_refcnt + -1;
    if (pPVar15 == (PyObject *)0x0) {
      pPVar12 = (PyObject *)0x0;
      iVar8 = 0x2229;
      py_line = 0xe7;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0011ad24;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
    func = __Pyx_PyObject_GetAttrStr(pPVar29,__pyx_mstate_global_static.__pyx_n_s_callback);
    if (func == (PyObject *)0x0) {
      py_line = 0xe8;
      iVar8 = 0x2237;
      goto LAB_0011a970;
    }
    pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar29,__pyx_mstate_global_static.__pyx_n_s_temp);
    if (pPVar10 == (PyObject *)0x0) {
      iVar8 = 0x2239;
      py_line = 0xe8;
      lVar30 = func->ob_refcnt + -1;
      pPVar12 = (PyObject *)0x0;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0011ad24;
    }
    p_Var31 = func->ob_type;
    if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
       (p_Var33 = func[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
      pPVar12 = (PyObject *)func[1].ob_refcnt;
      (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
      pPVar12->ob_refcnt = pPVar12->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = func->ob_refcnt + -1;
      func->ob_refcnt = lVar30;
      if (lVar30 == 0) {
        (*p_Var31->tp_dealloc)(func);
      }
      __pyx_pyargnames[0] = (PyObject **)p_Var33;
      __pyx_pyargnames[1] = (PyObject **)pPVar15;
      __pyx_pyargnames[2] = (PyObject **)pPVar10;
      pPVar11 = __Pyx_PyObject_FastCallDict(pPVar12,(PyObject **)local_78,3,func);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
      lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
      (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
      func = pPVar12;
      if (lVar30 == 0) {
        (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
      }
    }
    else {
      __pyx_pyargnames[0] = (PyObject **)0x0;
      __pyx_pyargnames[1] = (PyObject **)pPVar15;
      __pyx_pyargnames[2] = (PyObject **)pPVar10;
      pPVar11 = __Pyx_PyObject_FastCallDict(func,(PyObject **)(__pyx_pyargnames + 1),2,func);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
    lVar30 = func->ob_refcnt + -1;
    if (pPVar11 == (PyObject *)0x0) {
      pPVar12 = (PyObject *)0x0;
      iVar8 = 0x224e;
      py_line = 0xe8;
      pPVar11 = (PyObject *)0x0;
      goto LAB_0011ad24;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    func->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*func->ob_type->tp_dealloc)(func);
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar11->ob_refcnt + -1;
    pPVar11->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
    }
    pPVar10 = __Pyx_PyObject_GetAttrStr(pPVar29,__pyx_mstate_global_static.__pyx_n_s_report_time);
    if (pPVar10 == (PyObject *)0x0) {
      py_line = 0xe9;
      iVar8 = 0x225c;
      goto LAB_0011a970;
    }
    pPVar29 = (PyObject *)PyNumber_Add(pPVar34,pPVar10);
    if (pPVar29 == (PyObject *)0x0) {
      py_line = 0xe9;
      pPVar11 = (PyObject *)0x0;
      iVar8 = 0x225e;
      goto LAB_0011abc4;
    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
    lVar30 = pPVar10->ob_refcnt + -1;
    pPVar10->ob_refcnt = lVar30;
    if (lVar30 == 0) {
      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
    }
  }
  else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
    if (p_Var31->tp_setattro == (setattrofunc)0x0) {
      iVar8 = PyObject_SetAttr();
    }
    else {
      iVar8 = (*p_Var31->tp_setattro)
                        (pPVar29,__pyx_mstate_global_static.__pyx_n_s_temp,
                         __pyx_mstate_global_static.__pyx_float_0_0);
    }
    if (iVar8 < 0) {
      py_line = 0xce;
      pPVar15 = (PyObject *)0x0;
      pPVar34 = (PyObject *)0x0;
      obj = (PyObject *)0x0;
      pPVar13 = (PyObject *)0x0;
      pPVar18 = (PyObject *)0x0;
      pPVar32 = (PyObject *)0x0;
      iVar8 = 0x2028;
      local_80 = (PyObject *)0x0;
    }
    else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
      p_Var25 = pPVar29->ob_type->tp_setattro;
      if (p_Var25 == (setattrofunc)0x0) {
        iVar8 = PyObject_SetAttr();
      }
      else {
        iVar8 = (*p_Var25)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_humidity,
                           __pyx_mstate_global_static.__pyx_float_0_0);
      }
      if (iVar8 < 0) {
        pPVar15 = (PyObject *)0x0;
        pPVar34 = (PyObject *)0x0;
        obj = (PyObject *)0x0;
        pPVar13 = (PyObject *)0x0;
        pPVar18 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        py_line = 0xcf;
        iVar8 = 0x2031;
        local_80 = (PyObject *)0x0;
      }
      else {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
        p_Var22 = pPVar29->ob_type->tp_getattro;
        if (p_Var22 == (getattrofunc)0x0) {
          pPVar11 = (PyObject *)PyObject_GetAttr();
        }
        else {
          pPVar11 = (*p_Var22)(pPVar29,__pyx_mstate_global_static.__pyx_n_s_i2c);
        }
        if (pPVar11 != (PyObject *)0x0) {
                    /* Unresolved local var: PyTypeObject * tp@[???] */
          p_Var22 = pPVar11->ob_type->tp_getattro;
          if (p_Var22 == (getattrofunc)0x0) {
            pPVar12 = (PyObject *)PyObject_GetAttr();
          }
          else {
            pPVar12 = (*p_Var22)(pPVar11,__pyx_mstate_global_static.__pyx_n_s_get_mcu);
          }
          if (pPVar12 == (PyObject *)0x0) {
            pPVar15 = (PyObject *)0x0;
            pPVar34 = (PyObject *)0x0;
            obj = (PyObject *)0x0;
            pPVar13 = (PyObject *)0x0;
            pPVar18 = (PyObject *)0x0;
            pPVar32 = (PyObject *)0x0;
            py_line = 0xd2;
            iVar8 = 0x203c;
            local_80 = (PyObject *)0x0;
            goto LAB_0011abf0;
          }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
          lVar30 = pPVar11->ob_refcnt + -1;
          pPVar11->ob_refcnt = lVar30;
          if (lVar30 == 0) {
            (*pPVar11->ob_type->tp_dealloc)(pPVar11);
          }
          p_Var31 = pPVar12->ob_type;
          if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
             (p_Var33 = pPVar12[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
            pPVar10 = (PyObject *)pPVar12[1].ob_refcnt;
            (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
            pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar30 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar30;
            if (lVar30 == 0) {
              (*p_Var31->tp_dealloc)(pPVar12);
            }
            __pyx_pyargnames[1] = (PyObject **)0x0;
            __pyx_pyargnames[0] = (PyObject **)p_Var33;
            func = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)local_78,1,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
            (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
            pPVar12 = pPVar10;
            if (lVar30 == 0) {
              (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
            }
          }
          else {
            __pyx_pyargnames[0] = (PyObject **)0x0;
            __pyx_pyargnames[1] = (PyObject **)0x0;
            func = __Pyx_PyObject_FastCallDict
                             (pPVar12,(PyObject **)(__pyx_pyargnames + 1),0,pPVar11);
          }
          if (func != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar30 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar30;
            if (lVar30 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var22 = func->ob_type->tp_getattro;
            if (p_Var22 == (getattrofunc)0x0) {
              pPVar12 = (PyObject *)PyObject_GetAttr();
            }
            else {
              pPVar12 = (*p_Var22)(func,__pyx_mstate_global_static.__pyx_n_s_get_name);
            }
            lVar30 = func->ob_refcnt + -1;
            if (pPVar12 == (PyObject *)0x0) {
              pPVar12 = (PyObject *)0x0;
              pPVar11 = (PyObject *)0x0;
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              pPVar18 = (PyObject *)0x0;
              iVar8 = 0x2055;
              py_line = 0xd2;
              local_80 = (PyObject *)0x0;
              pPVar32 = (PyObject *)0x0;
              goto LAB_0011ad24;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            func->ob_refcnt = lVar30;
            if (lVar30 == 0) {
              (*func->ob_type->tp_dealloc)(func);
            }
            p_Var31 = pPVar12->ob_type;
            if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (p_Var33 = pPVar12[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar10 = (PyObject *)pPVar12[1].ob_refcnt;
              (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
              pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar30 = pPVar12->ob_refcnt + -1;
              pPVar12->ob_refcnt = lVar30;
              if (lVar30 == 0) {
                (*p_Var31->tp_dealloc)(pPVar12);
              }
              __pyx_pyargnames[1] = (PyObject **)0x0;
              __pyx_pyargnames[0] = (PyObject **)p_Var33;
              pPVar32 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)local_78,1,pPVar11);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
              (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
              pPVar12 = pPVar10;
              if (lVar30 == 0) {
                (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = (PyObject **)0x0;
              pPVar32 = __Pyx_PyObject_FastCallDict
                                  (pPVar12,(PyObject **)(__pyx_pyargnames + 1),0,pPVar11);
            }
            if (pPVar32 == (PyObject *)0x0) {
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              pPVar18 = (PyObject *)0x0;
              py_line = 0xd2;
              iVar8 = 0x206a;
              local_80 = (PyObject *)0x0;
              goto LAB_0011ac14;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar30 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar30;
            if (lVar30 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
            }
                    /* Unresolved local var: PyTypeObject * tp@[???] */
            p_Var22 = pPVar32->ob_type->tp_getattro;
            if (p_Var22 == (getattrofunc)0x0) {
              func = (PyObject *)PyObject_GetAttr();
            }
            else {
              func = (*p_Var22)(pPVar32,__pyx_mstate_global_static.__pyx_n_s_startswith);
            }
            if (func == (PyObject *)0x0) {
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              pPVar18 = (PyObject *)0x0;
              py_line = 0xd3;
              iVar8 = 0x2078;
              local_80 = (PyObject *)0x0;
              goto LAB_0011a970;
            }
            p_Var31 = func->ob_type;
            if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
               (p_Var33 = func[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
              pPVar10 = (PyObject *)func[1].ob_refcnt;
              (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
              pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar30 = func->ob_refcnt + -1;
              func->ob_refcnt = lVar30;
              if (lVar30 == 0) {
                (*p_Var31->tp_dealloc)(func);
              }
              __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_mcu_2;
              __pyx_pyargnames[0] = (PyObject **)p_Var33;
              pPVar12 = __Pyx_PyObject_FastCallDict
                                  (pPVar10,(PyObject **)local_78,2,
                                   __pyx_mstate_global_static.__pyx_n_s_mcu_2);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
              lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
              (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
              func = pPVar10;
              if (lVar30 == 0) {
                (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
              }
            }
            else {
              __pyx_pyargnames[0] = (PyObject **)0x0;
              __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_mcu_2;
              pPVar12 = __Pyx_PyObject_FastCallDict
                                  (func,(PyObject **)(__pyx_pyargnames + 1),1,
                                   __pyx_mstate_global_static.__pyx_n_s_mcu_2);
            }
            lVar30 = func->ob_refcnt + -1;
            if (pPVar12 == (PyObject *)0x0) {
              pPVar11 = (PyObject *)0x0;
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              pPVar18 = (PyObject *)0x0;
              iVar8 = 0x208c;
              py_line = 0xd3;
              local_80 = (PyObject *)0x0;
              goto LAB_0011ad24;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            func->ob_refcnt = lVar30;
            if (lVar30 == 0) {
              (*func->ob_type->tp_dealloc)(func);
            }
                    /* Unresolved local var: int is_true@[???] */
            uVar9 = (uint)(pPVar12 == (PyObject *)PTR__Py_TrueStruct_0012ff58);
            if (((uVar9 == 0 && pPVar12 != (PyObject *)PTR__Py_FalseStruct_0012ff20) &&
                 pPVar12 != (PyObject *)PTR__Py_NoneStruct_0012ff50) &&
               (uVar9 = PyObject_IsTrue(pPVar12), (int)uVar9 < 0)) {
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              pPVar13 = (PyObject *)0x0;
              pPVar18 = (PyObject *)0x0;
              py_line = 0xd3;
              iVar8 = 0x2090;
              local_80 = (PyObject *)0x0;
              goto LAB_0011ac14;
            }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
            lVar30 = pPVar12->ob_refcnt + -1;
            pPVar12->ob_refcnt = lVar30;
            if (lVar30 == 0) {
              (*pPVar12->ob_type->tp_dealloc)(pPVar12);
              if (uVar9 != 0) goto LAB_0011af7c;
LAB_00119cdc:
              pPVar32->ob_refcnt = pPVar32->ob_refcnt + 1;
              pPVar18 = pPVar32;
            }
            else {
              if (uVar9 == 0) goto LAB_00119cdc;
LAB_0011af7c:
                    /* Unresolved local var: __Pyx_TypeName obj_type_name@[???]
                       Unresolved local var: PyMappingMethods * mp@[???] */
              pPVar17 = pPVar32->ob_type->tp_as_mapping;
              if ((pPVar17 == (PyMappingMethods *)0x0) ||
                 (p_Var24 = pPVar17->mp_subscript, p_Var24 == (binaryfunc)0x0)) {
                py_line = 0xd3;
                pPVar15 = (PyObject *)0x0;
                pPVar34 = (PyObject *)0x0;
                obj = (PyObject *)0x0;
                pPVar13 = (PyObject *)0x0;
                pPVar18 = (PyObject *)0x0;
                iVar8 = 0x2093;
                local_80 = (PyObject *)0x0;
                PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                             "\'%.200s\' object is unsliceable",pPVar32->ob_type->tp_name);
                goto LAB_0011a970;
              }
                    /* Unresolved local var: PyObject * result@[???]
                       Unresolved local var: PyObject * py_slice@[???]
                       Unresolved local var: PyObject * py_start@[???]
                       Unresolved local var: PyObject * py_stop@[???] */
              pPVar18 = (*p_Var24)(pPVar32,__pyx_mstate_global_static.__pyx_slice__2);
              if (pPVar18 == (PyObject *)0x0) {
                pPVar15 = (PyObject *)0x0;
                pPVar34 = (PyObject *)0x0;
                obj = (PyObject *)0x0;
                pPVar13 = (PyObject *)0x0;
                py_line = 0xd3;
                iVar8 = 0x2093;
                local_80 = (PyObject *)0x0;
                goto LAB_0011a970;
              }
            }
            pPVar13 = (PyObject *)PyNumber_Add(__pyx_mstate_global_static.__pyx_n_s_heater,pPVar18);
            if (pPVar13 == (PyObject *)0x0) {
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              py_line = 0xd4;
              iVar8 = 0x20a5;
              local_80 = (PyObject *)0x0;
            }
            else {
              pPVar12 = __Pyx_PyObject_GetAttrStr
                                  (pPVar29,__pyx_mstate_global_static.__pyx_n_s_printer);
              if (pPVar12 != (PyObject *)0x0) {
                func = __Pyx_PyObject_GetAttrStr
                                 (pPVar12,__pyx_mstate_global_static.__pyx_n_s_lookup_object);
                if (func == (PyObject *)0x0) {
                  pPVar15 = (PyObject *)0x0;
                  pPVar34 = (PyObject *)0x0;
                  obj = (PyObject *)0x0;
                  py_line = 0xd6;
                  iVar8 = 0x20b3;
                  local_80 = (PyObject *)0x0;
                  goto LAB_0011ac14;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar30 = pPVar12->ob_refcnt + -1;
                pPVar12->ob_refcnt = lVar30;
                if (lVar30 == 0) {
                  (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                }
                p_Var31 = func->ob_type;
                if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                   (p_Var33 = func[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar10 = (PyObject *)func[1].ob_refcnt;
                  (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
                  pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar30 = func->ob_refcnt + -1;
                  func->ob_refcnt = lVar30;
                  if (lVar30 == 0) {
                    (*p_Var31->tp_dealloc)(func);
                  }
                  __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_heaters;
                  __pyx_pyargnames[0] = (PyObject **)p_Var33;
                  obj = __Pyx_PyObject_FastCallDict
                                  (pPVar10,(PyObject **)local_78,2,
                                   __pyx_mstate_global_static.__pyx_n_s_heaters);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
                  func = pPVar10;
                  if (lVar30 == 0) {
                    (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
                  }
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_n_s_heaters;
                  obj = __Pyx_PyObject_FastCallDict
                                  (func,(PyObject **)(__pyx_pyargnames + 1),1,
                                   __pyx_mstate_global_static.__pyx_n_s_heaters);
                }
                lVar30 = func->ob_refcnt + -1;
                if (obj == (PyObject *)0x0) {
                  pPVar12 = (PyObject *)0x0;
                  pPVar11 = (PyObject *)0x0;
                  pPVar15 = (PyObject *)0x0;
                  pPVar34 = (PyObject *)0x0;
                  iVar8 = 0x20c8;
                  py_line = 0xd6;
                  local_80 = (PyObject *)0x0;
                  goto LAB_0011ad24;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                func->ob_refcnt = lVar30;
                if (lVar30 == 0) {
                  (*func->ob_type->tp_dealloc)(func);
                }
                func = __Pyx_PyObject_GetAttrStr
                                 (obj,__pyx_mstate_global_static.__pyx_n_s_lookup_heater);
                if (func == (PyObject *)0x0) {
                  pPVar15 = (PyObject *)0x0;
                  pPVar34 = (PyObject *)0x0;
                  py_line = 0xd7;
                  iVar8 = 0x20d6;
                  local_80 = (PyObject *)0x0;
                  goto LAB_0011a970;
                }
                p_Var31 = func->ob_type;
                if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                   (p_Var33 = func[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                  pPVar10 = (PyObject *)func[1].ob_refcnt;
                  (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
                  pPVar10->ob_refcnt = pPVar10->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar30 = func->ob_refcnt + -1;
                  func->ob_refcnt = lVar30;
                  if (lVar30 == 0) {
                    (*p_Var31->tp_dealloc)(func);
                  }
                  __pyx_pyargnames[0] = (PyObject **)p_Var33;
                  __pyx_pyargnames[1] = (PyObject **)pPVar13;
                  local_80 = __Pyx_PyObject_FastCallDict(pPVar10,(PyObject **)local_78,2,func);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
                  (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
                  func = pPVar10;
                  if (lVar30 == 0) {
                    (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
                  }
                }
                else {
                  __pyx_pyargnames[0] = (PyObject **)0x0;
                  __pyx_pyargnames[1] = (PyObject **)pPVar13;
                  local_80 = __Pyx_PyObject_FastCallDict
                                       (func,(PyObject **)(__pyx_pyargnames + 1),1,func);
                }
                lVar30 = func->ob_refcnt + -1;
                if (local_80 == (PyObject *)0x0) {
                  pPVar12 = (PyObject *)0x0;
                  pPVar11 = (PyObject *)0x0;
                  pPVar15 = (PyObject *)0x0;
                  pPVar34 = (PyObject *)0x0;
                  iVar8 = 0x20ea;
                  py_line = 0xd7;
                  goto LAB_0011ad24;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                func->ob_refcnt = lVar30;
                if (lVar30 == 0) {
                  (*func->ob_type->tp_dealloc)(func);
                }
                pPVar12 = __pyx_dict_cached_value_17747;
                func = __pyx_dict_cached_value_17733;
                if (local_80 == (PyObject *)PTR__Py_NoneStruct_0012ff50) {
                  if (__pyx_dict_version_17732 == __pyx_mstate_global_static.__pyx_d[1].ob_type) {
                    if (__pyx_dict_cached_value_17733 == (PyObject *)0x0) {
                      func = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
                      goto LAB_0011bc4c;
                    }
                    __pyx_dict_cached_value_17733->ob_refcnt =
                         __pyx_dict_cached_value_17733->ob_refcnt + 1;
                  }
                  else {
                    func = __Pyx__GetModuleGlobalName
                                     (__pyx_mstate_global_static.__pyx_n_s_logging,
                                      (uint64_t *)&__pyx_dict_version_17732,
                                      &__pyx_dict_cached_value_17733);
LAB_0011bc4c:
                    if (func == (PyObject *)0x0) {
                      pPVar15 = (PyObject *)0x0;
                      pPVar34 = (PyObject *)0x0;
                      py_line = 0xdb;
                      iVar8 = 0x2102;
                      goto LAB_0011a970;
                    }
                  }
                  pPVar12 = __Pyx_PyObject_GetAttrStr
                                      (func,__pyx_mstate_global_static.__pyx_n_s_info);
                  if (pPVar12 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = func->ob_refcnt + -1;
                    func->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      (*func->ob_type->tp_dealloc)(func);
                    }
                    func = (PyObject *)PyTuple_New(3);
                    pPVar10 = __pyx_mstate_global_static.__pyx_kp_u_heater_2;
                    if (func == (PyObject *)0x0) {
                      pPVar15 = (PyObject *)0x0;
                      pPVar34 = (PyObject *)0x0;
                      py_line = 0xdb;
                      iVar8 = 0x2107;
                      goto LAB_0011ac14;
                    }
                    p_Var31 = pPVar13->ob_type;
                    bVar6 = p_Var31 == (_typeobject *)PTR_PyUnicode_Type_0012ffb0;
                    (__pyx_mstate_global_static.__pyx_kp_u_heater_2)->ob_refcnt =
                         (__pyx_mstate_global_static.__pyx_kp_u_heater_2)->ob_refcnt + 1;
                    func[1].ob_type = (_typeobject *)pPVar10;
                    if (bVar6) {
                      pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                      pPVar10 = pPVar13;
                    }
                    else {
                      if ((p_Var31 == (_typeobject *)PTR_PyLong_Type_0012ff80) ||
                         (p_Var31 == (_typeobject *)PTR_PyFloat_Type_0012feb0)) {
                        pPVar10 = (*p_Var31->tp_repr)(pPVar13);
                      }
                      else {
                        pPVar10 = (PyObject *)
                                  PyObject_Format(pPVar13,__pyx_mstate_global_static.
                                                          __pyx_empty_unicode);
                      }
                      if (pPVar10 == (PyObject *)0x0) {
                        pPVar11 = (PyObject *)0x0;
                        pPVar15 = (PyObject *)0x0;
                        iVar8 = 0x210f;
                        py_line = 0xdb;
                        lVar30 = func->ob_refcnt + -1;
                        pPVar34 = (PyObject *)0x0;
                        goto LAB_0011ad24;
                      }
                    }
                    pPVar34 = __pyx_mstate_global_static.__pyx_kp_u_not_found_for_AHT20_F_sensor;
                    bVar21 = (byte)pPVar10[2].ob_refcnt;
                    lVar30 = pPVar10[1].ob_refcnt + 0x26;
                    lVar37 = (__pyx_mstate_global_static.__pyx_kp_u_not_found_for_AHT20_F_sensor)->
                             ob_refcnt + 1;
                    if ((bVar21 >> 6 & 1) == 0) {
                      bVar21 = bVar21 & 0x1c;
                      if (bVar21 == 4) {
                        uVar20 = 0xff;
                        goto LAB_0011ba0c;
                      }
                      if (bVar21 != 8) {
                        func[2].ob_refcnt = (Py_ssize_t)pPVar10;
                    /* Unresolved local var: PyObject * result_uval@[???]
                       Unresolved local var: int result_ukind@[???]
                       Unresolved local var: int kind_shift@[???]
                       Unresolved local var: Py_ssize_t i@[???]
                       Unresolved local var: Py_ssize_t char_pos@[???]
                       Unresolved local var: void * result_udata@[???] */
                        pPVar34->ob_refcnt = lVar37;
                        func[2].ob_type = (_typeobject *)pPVar34;
                        ppPVar14 = (PyObject **)PyUnicode_New(lVar30,0x10ffff);
                        if (ppPVar14 != (PyObject **)0x0) {
                          lVar30 = 0x1fffffffffffffff;
                          bVar21 = 4;
                          pPVar10 = (PyObject *)0x2;
                          goto LAB_0011b3fc;
                        }
                        goto LAB_0011bbe8;
                      }
                      func[2].ob_refcnt = (Py_ssize_t)pPVar10;
                      pPVar34->ob_refcnt = lVar37;
                      func[2].ob_type = (_typeobject *)pPVar34;
                      ppPVar14 = (PyObject **)PyUnicode_New(lVar30,0xffff);
                      if (ppPVar14 == (PyObject **)0x0) goto LAB_0011bbe8;
                      lVar30 = 0x3fffffffffffffff;
                      pPVar10 = (PyObject *)0x1;
                      bVar21 = 2;
                    }
                    else {
                      uVar20 = 0x7f;
LAB_0011ba0c:
                      func[2].ob_refcnt = (Py_ssize_t)pPVar10;
                      pPVar34->ob_refcnt = lVar37;
                      func[2].ob_type = (_typeobject *)pPVar34;
                      ppPVar14 = (PyObject **)PyUnicode_New(lVar30,uVar20);
                      if (ppPVar14 == (PyObject **)0x0) {
LAB_0011bbe8:
                        pPVar34 = (PyObject *)0x0;
                        pPVar11 = (PyObject *)0x0;
                        pPVar15 = (PyObject *)0x0;
                        iVar8 = 0x211a;
                        py_line = 0xdb;
                        lVar30 = func->ob_refcnt + -1;
                        goto LAB_0011ad24;
                      }
                      pPVar10 = (PyObject *)0x0;
                      lVar30 = 0x7fffffffffffffff;
                      bVar21 = 1;
                    }
LAB_0011b3fc:
                    if ((*(byte *)(ppPVar14 + 4) >> 5 & 1) == 0) {
                      local_70 = ppPVar14[9];
                    }
                    else {
                      local_70 = (PyObject *)(ppPVar14 + 9);
                      if ((*(byte *)(ppPVar14 + 4) & 0x40) != 0) {
                        local_70 = (PyObject *)(ppPVar14 + 6);
                      }
                    }
                    pp_Var36 = &func[1].ob_type;
                    lVar37 = 0;
                    pPVar34 = pPVar10;
                    do {
                    /* Unresolved local var: int ukind@[???]
                       Unresolved local var: Py_ssize_t ulength@[???]
                       Unresolved local var: void * udata@[???]
                       Unresolved local var: PyObject * uval@[???] */
                      p_Var31 = *pp_Var36;
                      if ((-1 < (char)p_Var31->tp_basicsize) &&
                         (iVar8 = _PyUnicode_Ready(p_Var31), iVar8 != 0)) {
LAB_0011b928:
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                        pPVar29 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                        *ppPVar14 = pPVar29;
                        if (pPVar29 == (PyObject *)0x0) {
                          py_line = 0xdb;
                          local_78 = (PyObject *)0x0;
                          iVar8 = 0x211a;
                          pPVar15 = (PyObject *)0x0;
                          pPVar34 = (PyObject *)0x0;
                          (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
                          lVar30 = func->ob_refcnt + -1;
                          pPVar11 = local_78;
                        }
                        else {
                          iVar8 = 0x211a;
                          py_line = 0xdb;
                          pPVar15 = (PyObject *)0x0;
                          pPVar34 = (PyObject *)0x0;
                          lVar30 = func->ob_refcnt + -1;
                          pPVar11 = (PyObject *)0x0;
                        }
                        goto LAB_0011ad24;
                      }
                      lVar38 = (p_Var31->ob_base).ob_size;
                      if (lVar38 != 0) {
                        if (lVar30 - lVar38 < lVar37) {
                          PyErr_SetString(*(undefined8 *)PTR_PyExc_OverflowError_0012ff40,
                                          "join() result is too long for a Python string");
                          goto LAB_0011b928;
                        }
                        bVar2 = (byte)p_Var31->tp_basicsize;
                        if ((bVar2 >> 5 & 1) == 0) {
                          pp_Var19 = (setattrfunc *)p_Var31->tp_setattr;
                        }
                        else {
                          pp_Var19 = &p_Var31->tp_setattr;
                          if ((bVar2 & 0x40) != 0) {
                            pp_Var19 = (setattrfunc *)&p_Var31->tp_dealloc;
                          }
                        }
                        if (((byte)p_Var31->tp_basicsize >> 2 & 7) == bVar21) {
                          pPVar34 = local_70;
                          memcpy((void *)((long)&local_70->ob_refcnt + (lVar37 << (long)pPVar10)),
                                 pp_Var19,lVar38 << (long)pPVar10);
                        }
                        else {
                          pPVar34 = (PyObject *)0x0;
                          _PyUnicode_FastCopyCharacters(ppPVar14,lVar37,p_Var31,0,lVar38);
                        }
                        lVar37 = lVar37 + lVar38;
                      }
                      pp_Var36 = pp_Var36 + 1;
                    } while (func + 3 != (PyObject *)pp_Var36);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = func->ob_refcnt + -1;
                    func->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      (*func->ob_type->tp_dealloc)(func);
                    }
                    p_Var31 = pPVar12->ob_type;
                    if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                       (p_Var33 = pPVar12[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar15 = (PyObject *)pPVar12[1].ob_refcnt;
                      (p_Var33->ob_base).ob_base.ob_refcnt =
                           (p_Var33->ob_base).ob_base.ob_refcnt + 1;
                      pPVar15->ob_refcnt = pPVar15->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar12->ob_refcnt + -1;
                      pPVar12->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        (*p_Var31->tp_dealloc)(pPVar12);
                      }
                      __pyx_pyargnames[0] = (PyObject **)p_Var33;
                      __pyx_pyargnames[1] = ppPVar14;
                      pPVar10 = __Pyx_PyObject_FastCallDict(pPVar15,(PyObject **)local_78,2,pPVar34)
                      ;
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
                      pPVar12 = pPVar15;
                      if (lVar30 == 0) {
                        (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = ppPVar14;
                      pPVar10 = __Pyx_PyObject_FastCallDict
                                          (pPVar12,(PyObject **)(__pyx_pyargnames + 1),1,pPVar34);
                    }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    pPVar34 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                    *ppPVar14 = pPVar34;
                    if (pPVar34 == (PyObject *)0x0) {
                      (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
                    }
                    if (pPVar10 == (PyObject *)0x0) {
                      pPVar34 = (PyObject *)0x0;
                      pPVar15 = (PyObject *)0x0;
                      py_line = 0xdb;
                      iVar8 = 0x2130;
                      goto LAB_0011ac14;
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = pPVar12->ob_refcnt + -1;
                    pPVar12->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = pPVar10->ob_refcnt + -1;
                    pPVar10->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      p_Var31 = pPVar10->ob_type;
LAB_0011a13c:
                      (*p_Var31->tp_dealloc)(pPVar10);
                    }
LAB_0011a144:
                    p_Var31 = pPVar29->ob_type;
                    goto LAB_0011a168;
                  }
                  pPVar15 = (PyObject *)0x0;
                  pPVar11 = (PyObject *)0x0;
                  lVar30 = func->ob_refcnt + -1;
                  pPVar34 = (PyObject *)0x0;
                  iVar8 = 0x2104;
                  py_line = 0xdb;
                  goto LAB_0011ad24;
                }
                if (__pyx_dict_version_17746 == __pyx_mstate_global_static.__pyx_d[1].ob_type) {
                  if (__pyx_dict_cached_value_17747 == (PyObject *)0x0) {
                    pPVar12 = __Pyx_GetBuiltinName(__pyx_mstate_global_static.__pyx_n_s_logging);
                    goto LAB_0011ba88;
                  }
                  __pyx_dict_cached_value_17747->ob_refcnt =
                       __pyx_dict_cached_value_17747->ob_refcnt + 1;
                }
                else {
                  pPVar12 = __Pyx__GetModuleGlobalName
                                      (__pyx_mstate_global_static.__pyx_n_s_logging,
                                       (uint64_t *)&__pyx_dict_version_17746,
                                       &__pyx_dict_cached_value_17747);
LAB_0011ba88:
                  if (pPVar12 == (PyObject *)0x0) {
                    pPVar15 = (PyObject *)0x0;
                    pPVar34 = (PyObject *)0x0;
                    py_line = 0xdd;
                    iVar8 = 0x2148;
                    goto LAB_0011a970;
                  }
                }
                pPVar11 = __Pyx_PyObject_GetAttrStr
                                    (pPVar12,__pyx_mstate_global_static.__pyx_n_s_info);
                if (pPVar11 == (PyObject *)0x0) {
                  pPVar15 = (PyObject *)0x0;
                  pPVar34 = (PyObject *)0x0;
                  py_line = 0xdd;
                  iVar8 = 0x214a;
                  goto LAB_0011ac14;
                }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                lVar30 = pPVar12->ob_refcnt + -1;
                pPVar12->ob_refcnt = lVar30;
                if (lVar30 == 0) {
                  (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                }
                p_Var31 = pPVar13->ob_type;
                if (p_Var31 == (_typeobject *)PTR_PyUnicode_Type_0012ffb0) {
                  pPVar13->ob_refcnt = pPVar13->ob_refcnt + 1;
                  pPVar12 = pPVar13;
                }
                else {
                  if ((p_Var31 == (_typeobject *)PTR_PyLong_Type_0012ff80) ||
                     (p_Var31 == (_typeobject *)PTR_PyFloat_Type_0012feb0)) {
                    pPVar12 = (*p_Var31->tp_repr)(pPVar13);
                  }
                  else {
                    pPVar12 = (PyObject *)
                              PyObject_Format(pPVar13,__pyx_mstate_global_static.__pyx_empty_unicode
                                             );
                  }
                  if (pPVar12 == (PyObject *)0x0) {
                    pPVar15 = (PyObject *)0x0;
                    pPVar34 = (PyObject *)0x0;
                    py_line = 0xdd;
                    iVar8 = 0x214d;
                    goto LAB_0011abf0;
                  }
                }
                ppPVar14 = (PyObject **)
                           PyUnicode_Concat(__pyx_mstate_global_static.
                                            __pyx_kp_u_AHT20_F_sensor_using_heater,pPVar12);
                if (ppPVar14 == (PyObject **)0x0) {
                  pPVar15 = (PyObject *)0x0;
                  py_line = 0xdd;
                  iVar8 = 0x214f;
                  pPVar34 = (PyObject *)0x0;
                }
                else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  lVar30 = pPVar12->ob_refcnt + -1;
                  pPVar12->ob_refcnt = lVar30;
                  if (lVar30 == 0) {
                    (*pPVar12->ob_type->tp_dealloc)(pPVar12);
                  }
                  p_Var31 = pPVar11->ob_type;
                  if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                     (p_Var33 = pPVar11[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                    pPVar34 = (PyObject *)pPVar11[1].ob_refcnt;
                    (p_Var33->ob_base).ob_base.ob_refcnt = (p_Var33->ob_base).ob_base.ob_refcnt + 1;
                    pPVar34->ob_refcnt = pPVar34->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = pPVar11->ob_refcnt + -1;
                    pPVar11->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      (*p_Var31->tp_dealloc)(pPVar11);
                    }
                    __pyx_pyargnames[0] = (PyObject **)p_Var33;
                    __pyx_pyargnames[1] = ppPVar14;
                    pPVar10 = __Pyx_PyObject_FastCallDict(pPVar34,(PyObject **)local_78,2,pPVar11);
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
                    (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
                    pPVar11 = pPVar34;
                    if (lVar30 == 0) {
                      (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
                    }
                  }
                  else {
                    __pyx_pyargnames[0] = (PyObject **)0x0;
                    __pyx_pyargnames[1] = ppPVar14;
                    pPVar10 = __Pyx_PyObject_FastCallDict
                                        (pPVar11,(PyObject **)(__pyx_pyargnames + 1),1,pPVar11);
                  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                  pPVar34 = (PyObject *)((long)&(*ppPVar14)[-1].ob_type + 7);
                  *ppPVar14 = pPVar34;
                  if (pPVar34 == (PyObject *)0x0) {
                    (*(code *)ppPVar14[1][3].ob_refcnt)(ppPVar14);
                  }
                  if (pPVar10 == (PyObject *)0x0) {
                    pPVar34 = (PyObject *)0x0;
                    pPVar15 = (PyObject *)0x0;
                    py_line = 0xdd;
                    iVar8 = 0x2165;
                    pPVar12 = (PyObject *)0x0;
                  }
                  else {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = pPVar11->ob_refcnt + -1;
                    pPVar11->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                    }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                    lVar30 = pPVar10->ob_refcnt + -1;
                    pPVar10->ob_refcnt = lVar30;
                    if (lVar30 == 0) {
                      (*pPVar10->ob_type->tp_dealloc)(pPVar10);
                    }
                    pPVar11 = __Pyx_PyObject_GetAttrStr
                                        (local_80,__pyx_mstate_global_static.__pyx_n_s_set_temp);
                    if (pPVar11 == (PyObject *)0x0) {
                      pPVar15 = (PyObject *)0x0;
                      pPVar34 = (PyObject *)0x0;
                      py_line = 0xde;
                      iVar8 = 0x2172;
                      goto LAB_0011a970;
                    }
                    p_Var31 = pPVar11->ob_type;
                    if ((p_Var31 == (_typeobject *)PTR_PyMethod_Type_0012fea0) &&
                       (p_Var33 = pPVar11[1].ob_type, p_Var33 != (_typeobject *)0x0)) {
                    /* Unresolved local var: PyObject * function@[???] */
                      pPVar34 = (PyObject *)pPVar11[1].ob_refcnt;
                      (p_Var33->ob_base).ob_base.ob_refcnt =
                           (p_Var33->ob_base).ob_base.ob_refcnt + 1;
                      pPVar34->ob_refcnt = pPVar34->ob_refcnt + 1;
                    /* Unresolved local var: PyObject * tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar11->ob_refcnt + -1;
                      pPVar11->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        (*p_Var31->tp_dealloc)(pPVar11);
                      }
                      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_float_0_0;
                      __pyx_pyargnames[0] = (PyObject **)p_Var33;
                      pPVar10 = __Pyx_PyObject_FastCallDict
                                          (pPVar34,(PyObject **)local_78,2,
                                           __pyx_mstate_global_static.__pyx_float_0_0);
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???]
                       Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = (p_Var33->ob_base).ob_base.ob_refcnt + -1;
                      (p_Var33->ob_base).ob_base.ob_refcnt = lVar30;
                      pPVar11 = pPVar34;
                      if (lVar30 == 0) {
                        (*((p_Var33->ob_base).ob_base.ob_type)->tp_dealloc)((PyObject *)p_Var33);
                      }
                    }
                    else {
                      __pyx_pyargnames[0] = (PyObject **)0x0;
                      __pyx_pyargnames[1] = (PyObject **)__pyx_mstate_global_static.__pyx_float_0_0;
                      pPVar10 = __Pyx_PyObject_FastCallDict
                                          (pPVar11,(PyObject **)(__pyx_pyargnames + 1),1,
                                           __pyx_mstate_global_static.__pyx_float_0_0);
                    }
                    if (pPVar10 != (PyObject *)0x0) {
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar11->ob_refcnt + -1;
                      pPVar11->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        (*pPVar11->ob_type->tp_dealloc)(pPVar11);
                      }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
                      lVar30 = pPVar10->ob_refcnt + -1;
                      pPVar10->ob_refcnt = lVar30;
                      if (lVar30 == 0) {
                        p_Var31 = pPVar10->ob_type;
                        goto LAB_0011a13c;
                      }
                      goto LAB_0011a144;
                    }
                    pPVar34 = (PyObject *)0x0;
                    pPVar15 = (PyObject *)0x0;
                    py_line = 0xde;
                    iVar8 = 0x2186;
                    pPVar12 = (PyObject *)0x0;
                  }
                }
                goto LAB_0011abf0;
              }
              pPVar15 = (PyObject *)0x0;
              pPVar34 = (PyObject *)0x0;
              obj = (PyObject *)0x0;
              py_line = 0xd6;
              iVar8 = 0x20b1;
              local_80 = (PyObject *)0x0;
            }
            goto LAB_0011a970;
          }
          pPVar34 = (PyObject *)0x0;
          pPVar15 = (PyObject *)0x0;
          obj = (PyObject *)0x0;
          pPVar13 = (PyObject *)0x0;
          pPVar18 = (PyObject *)0x0;
          pPVar32 = (PyObject *)0x0;
          py_line = 0xd2;
          iVar8 = 0x2051;
          local_80 = (PyObject *)0x0;
          goto LAB_0011ac14;
        }
        pPVar15 = (PyObject *)0x0;
        pPVar34 = (PyObject *)0x0;
        obj = (PyObject *)0x0;
        pPVar13 = (PyObject *)0x0;
        pPVar18 = (PyObject *)0x0;
        pPVar32 = (PyObject *)0x0;
        py_line = 0xd2;
        iVar8 = 0x203a;
        local_80 = (PyObject *)0x0;
      }
    }
LAB_0011a970:
    pPVar29 = (PyObject *)0x0;
    __Pyx_AddTraceback("extras.aht20_f.AHT20_F._sample_aht20_f",iVar8,py_line,"aht20_f.py");
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar32 != (PyObject *)0x0) &&
     (lVar30 = pPVar32->ob_refcnt + -1, pPVar32->ob_refcnt = lVar30, lVar30 == 0)) {
    (*pPVar32->ob_type->tp_dealloc)(pPVar32);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar18 != (PyObject *)0x0) &&
     (lVar30 = pPVar18->ob_refcnt + -1, pPVar18->ob_refcnt = lVar30, lVar30 == 0)) {
    (*pPVar18->ob_type->tp_dealloc)(pPVar18);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar13 != (PyObject *)0x0) &&
     (lVar30 = pPVar13->ob_refcnt + -1, pPVar13->ob_refcnt = lVar30, lVar30 == 0)) {
    (*pPVar13->ob_type->tp_dealloc)(pPVar13);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((obj != (PyObject *)0x0) &&
     (lVar30 = obj->ob_refcnt + -1, obj->ob_refcnt = lVar30, lVar30 == 0)) {
    (*obj->ob_type->tp_dealloc)(obj);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((local_80 != (PyObject *)0x0) &&
     (lVar30 = local_80->ob_refcnt + -1, local_80->ob_refcnt = lVar30, lVar30 == 0)) {
    (*local_80->ob_type->tp_dealloc)(local_80);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar34 != (PyObject *)0x0) &&
     (lVar30 = pPVar34->ob_refcnt + -1, pPVar34->ob_refcnt = lVar30, lVar30 == 0)) {
    (*pPVar34->ob_type->tp_dealloc)(pPVar34);
  }
                    /* Unresolved local var: PyObject * _py_xdecref_tmp@[???] */
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
  if ((pPVar15 != (PyObject *)0x0) &&
     (lVar30 = pPVar15->ob_refcnt + -1, pPVar15->ob_refcnt = lVar30, lVar30 == 0)) {
    (*pPVar15->ob_type->tp_dealloc)(pPVar15);
  }
LAB_00119820:
  if (lVar28 == *(long *)PTR___stack_chk_guard_0012ff30) {
    return pPVar29;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    lVar35 = lVar38 + 1;
    if (lVar35 == lVar37) goto LAB_0011ab40;
    p_Var31 = (_typeobject *)(&__pyx_kwds[2].ob_refcnt)[lVar38];
    lVar38 = lVar35;
    if ((_typeobject *)pPVar29 == p_Var31) break;
LAB_0011a870:
    bVar6 = pPVar29->ob_type != (_typeobject *)puVar5;
    bVar7 = (p_Var31->ob_base).ob_base.ob_type != (_typeobject *)puVar5;
    lVar35 = lVar38;
    if (bVar6 || bVar7) {
      if ((bVar7 || pPVar29 != (PyObject *)puVar3) && (bVar6 || p_Var31 != (_typeobject *)puVar3)) {
        plVar16 = (long *)PyObject_RichCompare(pPVar29,p_Var31,2);
        if (plVar16 == (long *)0x0) goto LAB_0011ab40;
        uVar9 = (uint)(plVar16 == (long *)puVar4);
        if ((plVar16 != (long *)puVar4 && plVar16 != (long *)PTR__Py_FalseStruct_0012ff20) &&
            plVar16 != (long *)puVar3) {
          uVar9 = PyObject_IsTrue();
        }
                    /* Unresolved local var: PyObject * _py_decref_tmp@[???] */
        lVar23 = *plVar16;
        *plVar16 = lVar23 + -1;
        if (lVar23 + -1 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
LAB_0011ab30:
        if (uVar9 != 0) {
          if ((int)uVar9 < 0) goto LAB_0011ab40;
          break;
        }
      }
    }
    else {
                    /* Unresolved local var: Py_ssize_t length@[???]
                       Unresolved local var: int kind@[???]
                       Unresolved local var: void * data1@[???]
                       Unresolved local var: void * data2@[???] */
      if (((-1 < (char)pPVar29[2].ob_refcnt) && (iVar8 = _PyUnicode_Ready(pPVar29), iVar8 < 0)) ||
         ((-1 < (char)p_Var31->tp_basicsize && (iVar8 = _PyUnicode_Ready(p_Var31), iVar8 < 0))))
      goto LAB_0011ab40;
      lVar23 = pPVar29[1].ob_refcnt;
                    /* Unresolved local var: Py_hash_t hash1@[???]
                       Unresolved local var: Py_hash_t hash2@[???] */
      if ((lVar23 == (p_Var31->ob_base).ob_size) &&
         ((pPVar29[1].ob_type == (_typeobject *)p_Var31->tp_name ||
          (_typeobject *)p_Var31->tp_name == (_typeobject *)0xffffffffffffffff) ||
          pPVar29[1].ob_type == (_typeobject *)0xffffffffffffffff)) {
        uVar26 = (ulong)(byte)((byte)pPVar29[2].ob_refcnt >> 2) & 7;
        uVar9 = (uint)uVar26;
        if (((byte)((byte)p_Var31->tp_basicsize >> 2) & 7) == uVar9) {
          bVar21 = (byte)pPVar29[2].ob_refcnt;
          if ((bVar21 >> 5 & 1) == 0) {
            p_Var33 = pPVar29[4].ob_type;
          }
          else {
            p_Var33 = (_typeobject *)&pPVar29[4].ob_type;
            if ((bVar21 & 0x40) != 0) {
              p_Var33 = (_typeobject *)(pPVar29 + 3);
            }
          }
          bVar21 = (byte)p_Var31->tp_basicsize;
          if ((bVar21 >> 5 & 1) == 0) {
            pp_Var19 = (setattrfunc *)p_Var31->tp_setattr;
          }
          else {
            pp_Var19 = &p_Var31->tp_setattr;
            if ((bVar21 & 0x40) != 0) {
              pp_Var19 = (setattrfunc *)&p_Var31->tp_dealloc;
            }
          }
          if (uVar9 == 1) {
            uVar9 = (uint)(byte)(p_Var33->ob_base).ob_base.ob_refcnt;
            pcVar27 = (char *)(ulong)*(byte *)pp_Var19;
          }
          else if (uVar9 == 2) {
            uVar9 = (uint)(ushort)(p_Var33->ob_base).ob_base.ob_refcnt;
            pcVar27 = (char *)(ulong)*(ushort *)pp_Var19;
          }
          else {
            uVar9 = (uint)(p_Var33->ob_base).ob_base.ob_refcnt;
            pcVar27 = (char *)(ulong)*(uint *)pp_Var19;
          }
          if ((uint)pcVar27 == uVar9) {
            if (lVar23 != 1) {
                    /* Unresolved local var: int result@[???] */
              iVar8 = memcmp(p_Var33,pp_Var19,uVar26 * lVar23);
              uVar9 = (uint)(iVar8 == 0);
              goto LAB_0011ab30;
            }
            break;
          }
        }
      }
    }
  }
  values[1] = ppPVar14[lVar35];
LAB_0011aa9c:
  if (values[1] == (PyObject *)0x0) {
LAB_0011ab44:
    lVar30 = PyErr_Occurred();
    if (lVar30 == 0) {
                    /* Unresolved local var: Py_ssize_t num_expected@[???]
                       Unresolved local var: char * more_or_less@[???] */
      PyErr_Format(*(undefined8 *)PTR_PyExc_TypeError_0012fef8,
                   "%.200s() takes %.8s %zd positional argument%.1s (%zd given)","_sample_aht20_f",
                   "exactly",2,"s",1);
      iVar8 = 0x1fb7;
    }
    else {
      iVar8 = 0x1fb5;
    }
  }
  else {
    lVar30 = lVar30 + -1;
LAB_0011a7cc:
                    /* Unresolved local var: Py_ssize_t kwd_pos_args@[???] */
    if ((lVar30 < 1) ||
       (iVar8 = __Pyx_ParseOptionalKeywords
                          (__pyx_kwds,ppPVar14,__pyx_pyargnames,(PyObject *)values,
                           (PyObject **)__pyx_nargs,0x11d2b8,pcVar27), -1 < iVar8))
    goto LAB_0011986c;
    iVar8 = 0x1fbc;
  }
LAB_00119804:
  pPVar29 = (PyObject *)0x0;
  __Pyx_AddTraceback("extras.aht20_f.AHT20_F._sample_aht20_f",iVar8,0xc5,"aht20_f.py");
  goto LAB_00119820;
}


/* Successfully decompiled 22 of 22 selected functions. */
