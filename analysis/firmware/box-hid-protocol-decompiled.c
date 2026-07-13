/* Named Ghidra pseudocode; not original source. */
/* Program: box-hid-flash */


/* ================================================================
 * Address: 004022a4
 * Symbol: getFileSize
 * Signature: undefined getFileSize(void)
 * ================================================================ */

undefined4 getFileSize(char *param_1)

{
  int iVar1;
  uint local_78;
  undefined4 local_58;
  int local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  local_8 = open(param_1,0);
  if (local_8 < 0) {
    local_4 = 0xffffffff;
  }
  else {
    iVar1 = fstat(local_8,(stat *)&stack0xffffffffffffff78);
    if ((iVar1 == 0) && ((local_78 & 0xf000) == 0x8000)) {
      local_4 = local_58;
    }
  }
  return local_4;
}


/* ================================================================
 * Address: 00402604
 * Symbol: set_sendBuf
 * Signature: undefined set_sendBuf(void)
 * ================================================================ */

uint set_sendBuf(undefined1 *param_1,undefined1 param_2,void *param_3,ushort param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int local_8;
  int local_4;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    memset(param_1,0,0x800);
    *param_1 = 0xa5;
    param_1[1] = param_2;
    param_1[2] = (char)(param_4 >> 8);
    param_1[3] = (char)param_4;
    local_4 = 4;
    if (param_4 != 0) {
      if (param_3 == (void *)0x0) {
        return 0xfffffffe;
      }
      memcpy(param_1 + 4,param_3,(ulong)param_4);
      local_4 = param_4 + 4;
    }
    uVar1 = nCrc16TabUSB(param_1 + 1,local_4 + -1);
    param_1[local_4] = (char)((ushort)uVar1 >> 8);
    uVar2 = local_4 + 2;
    param_1[local_4 + 1] = (char)uVar1;
    printf("Test: set_sendBuf(%d): \n",(ulong)uVar2);
    for (local_8 = 0; local_8 < (int)uVar2; local_8 = local_8 + 1) {
      printf("%02hhX ",(ulong)(byte)param_1[local_8]);
    }
    putchar(10);
  }
  return uVar2;
}


/* ================================================================
 * Address: 004027bc
 * Symbol: parse_recvBuf
 * Signature: undefined parse_recvBuf(void)
 * ================================================================ */

undefined8 parse_recvBuf(char *param_1,uint param_2,byte *param_3,long *param_4,ushort *param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  if (param_2 < 6) {
    uVar3 = 0xffffffff;
  }
  else if (*param_1 == -0x5b) {
    *param_5 = (ushort)(byte)param_1[2];
    *param_5 = *param_5 << 8;
    *param_5 = *param_5 + (ushort)(byte)param_1[3];
    puts("Test: parse_recvBuf():");
    printf("dataLen = %hu.\n",(ulong)*param_5);
    if (param_2 < *param_5 + 6) {
      uVar3 = 0xfffffffd;
    }
    else {
      uVar1 = (ushort)(byte)param_1[(ulong)*param_5 + 5] +
              (ushort)(byte)param_1[(ulong)*param_5 + 4] * 0x100;
      uVar2 = nCrc16TabUSB(param_1 + 1,*param_5 + 3);
      printf("crc16 = %04hX, crc16_cal = %04hX.\n",(ulong)uVar1,(ulong)uVar2);
      if (uVar1 == uVar2) {
        *param_3 = param_1[1];
        *param_4 = (long)(param_1 + 4);
        printf("type = %hu.\n",(ulong)*param_3);
        uVar3 = 0;
      }
      else {
        uVar3 = 0xfffffffc;
      }
    }
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


/* Requested 4 names; found 3. */
