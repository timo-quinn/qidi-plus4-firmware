/* Named Ghidra pseudocode; not original source. */
/* Program: box-hid-flash */


/* ================================================================
 * Address: 00402998
 * Symbol: main
 * Signature: undefined main(void)
 * ================================================================ */

undefined4 main(int param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  char local_1561;
  char *local_1560;
  char local_1552;
  byte local_1551;
  long local_1550;
  char local_1541 [9];
  undefined2 local_1538 [4];
  undefined2 local_1530 [4];
  undefined4 local_1528;
  undefined2 local_1524;
  undefined2 local_1520 [1028];
  undefined1 auStack_d18 [2048];
  byte abStack_518 [104];
  undefined1 auStack_4b0 [64];
  undefined1 local_470;
  undefined1 local_46f;
  undefined1 local_46e;
  undefined1 local_46d;
  undefined1 local_46c;
  undefined1 local_46b;
  undefined1 auStack_46a [1030];
  uint local_64;
  uint local_60;
  uint local_5c;
  FILE *local_58;
  undefined8 local_50;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  char local_32;
  char local_31;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined1 local_19;
  uint local_18;
  undefined4 local_14;
  size_t local_10;
  int local_8;
  char local_1;
  
  local_1 = '\0';
  local_8 = 0;
  local_40 = 0;
  local_44 = 0;
  local_1520[0] = 1;
  local_1528 = DAT_00406958;
  local_1524 = DAT_0040695c;
  local_1530[0] = 0x102;
  local_1538[0] = 0x202;
  local_1541[1] = 'o';
  local_1541[2] = 'k';
  local_50 = 0;
  local_58 = (FILE *)0x0;
  local_14 = 0;
  local_18 = 0;
  setbuf(*(FILE **)PTR_stdout_00418fd8,(char *)0x0);
  local_19 = 0;
  local_20 = 0;
  local_24 = 0;
  puts("\n+-----------------------------------------------------------------------+");
  puts("|        HID-Flash v2.5.1 (Uart) - STM32 HID Bootloader Flash Tool      |");
  puts("|     (c)      2018 - Bruno Freitas       http://www.brunofreitas.com   |");
  puts("|     (c) 2018-2019 - Vassilis Serasidis  https://www.serasidis.gr      |");
  puts("|     (c)      2024 - Makerbase           https://makerbase.com.cn/     |");
  puts("|   Customized for STM32duino ecosystem   https://www.stm32duino.com    |");
  puts("+-----------------------------------------------------------------------+\n");
  if (param_1 < 3) {
    puts(
        "Usage: hid-flash <bin_firmware_file> <comport> <delay (optional)>\nFor example:\n./hid-flash /home/mks/klipper/out/klipper.bin /dev/ttyACM0"
        );
    local_14 = 1;
  }
  else {
    if (param_1 == 4) {
      lVar2 = atol(*(char **)(param_2 + 0x18));
      local_19 = (undefined1)lVar2;
    }
    local_5c = 0;
    local_5c = getFileSize(*(undefined8 *)(param_2 + 8));
    if (local_5c == 0) {
      printf("> Error Reading firmware file: %s[%d]\n",*(undefined8 *)(param_2 + 8),0);
      local_14 = 2;
    }
    else {
      printf("Test: fileSize = %d.\n",(ulong)local_5c);
      local_1528 = CONCAT13((char)(local_5c >> 0x10),
                            CONCAT12((char)(local_5c >> 0x18),(undefined2)local_1528));
      local_1524 = CONCAT11((char)local_5c,(char)(local_5c >> 8));
      local_58 = fopen(*(char **)(param_2 + 8),"rb");
      if (local_58 == (FILE *)0x0) {
        printf("> Error opening firmware file: %s\n",*(undefined8 *)(param_2 + 8));
        local_14 = 2;
      }
      else {
        iVar1 = serial_init(*(undefined8 *)(param_2 + 0x10),local_19);
        if (iVar1 == 0) {
          printf("> Open the [%s] successfully\n",*(undefined8 *)(param_2 + 0x10));
          puts("\n> Sending <basic> command...");
          local_8 = set_sendBuf(auStack_d18,0,local_1520,2);
          for (local_20 = 0; local_20 < 2; local_20 = local_20 + 1) {
            local_40 = RS232_SendNBytes(auStack_d18,local_8);
            if ((int)local_40 < local_8) {
              printf("> Error while sending %d <bootloader> command.\n",(ulong)local_40);
              if (local_40 == 0xffffffff) {
                perror("ERROR: RS232_SendNBytes() failed...");
              }
              local_14 = 4;
              goto LAB_00403830;
            }
            printf("Test: RS232_SendNBytes(size: %d)\n",(ulong)local_40);
            local_1 = '\0';
            local_24 = 0;
LAB_00402cdc:
            memset(abStack_518,0,100);
            usleep(2000);
            local_44 = RS232_Receive(abStack_518,100);
            if ((int)local_44 < 1) {
              if ((local_44 == 0xffffffff) && (piVar3 = __errno_location(), *piVar3 != 0xb)) {
                perror("ERROR: RS232_Receive() failed...");
              }
LAB_00402db8:
              if ((local_1 != '\0') || (local_24 = local_24 + 1, 0x4e1 < local_24))
              goto LAB_00402de0;
              goto LAB_00402cdc;
            }
            printf("recv %d data:",(ulong)local_44);
            for (local_28 = 0; local_28 < (int)local_44; local_28 = local_28 + 1) {
              printf("%02hhX ",(ulong)abStack_518[local_28]);
            }
            putchar(10);
            if ((int)local_44 < 2) goto LAB_00402db8;
            local_1 = '\x01';
LAB_00402de0:
            if (local_1 != '\0') break;
          }
          if (local_1 == '\0') {
            puts("> Error, no ok receive, timeout(5s) and exit!!!");
            local_14 = 5;
          }
          else {
            puts("\n> Sending <start> command...");
            local_8 = set_sendBuf(auStack_d18,1,&local_1528,6);
            for (local_20 = 0; local_20 < 2; local_20 = local_20 + 1) {
              local_40 = RS232_SendNBytes(auStack_d18,local_8);
              if ((int)local_40 < local_8) {
                printf("> Error while sending %d <start> command.\n",(ulong)local_40);
                if (local_40 == 0xffffffff) {
                  perror("ERROR: RS232_SendNBytes() failed...");
                }
                local_14 = 6;
                goto LAB_00403830;
              }
              printf("Test: RS232_SendNBytes(size: %d)\n",(ulong)local_40);
              local_1 = '\0';
              local_24 = 0;
LAB_00402ed8:
              memset(abStack_518,0,100);
              usleep(2000);
              local_44 = RS232_Receive(abStack_518,100);
              if ((int)local_44 < 1) {
                if (local_44 == 0xffffffff) {
                  __errno_location();
                }
LAB_00402f9c:
                if ((local_1 != '\0') || (local_24 = local_24 + 1, 0x4e1 < local_24))
                goto LAB_00402fc4;
                goto LAB_00402ed8;
              }
              printf("recv %d data:\n",(ulong)local_44);
              for (local_2c = 0; local_2c < (int)local_44; local_2c = local_2c + 1) {
                printf("%02hhX ",(ulong)abStack_518[local_2c]);
              }
              putchar(10);
              if ((int)local_44 < 2) goto LAB_00402f9c;
              local_1 = '\x01';
LAB_00402fc4:
              if (local_1 != '\0') break;
            }
            if (local_1 == '\0') {
              puts("> Error, no ok receive, timeout(5s) and exit!!!");
              local_14 = 7;
            }
            else {
              local_30 = 0;
              memset(auStack_4b0,0,0x40);
              puts("> Flashing firmware...");
              memset(&local_470,0xff,0x406);
              puts("\n> Sending <file> command...");
              local_10 = fread(auStack_46a,1,0x400,local_58);
              local_470 = (undefined1)(local_30 >> 0x18);
              local_46f = (undefined1)(local_30 >> 0x10);
              local_46e = (undefined1)(local_30 >> 8);
              local_46d = (undefined1)local_30;
              local_46c = (undefined1)(local_10 >> 8);
              local_46b = (undefined1)local_10;
              local_8 = set_sendBuf(auStack_d18,2,&local_470,((uint)local_10 & 0xffff) + 6 & 0xffff)
              ;
              local_31 = '\0';
              local_32 = '\0';
              while (local_10 != 0) {
                local_30 = local_30 + 1;
                local_40 = RS232_SendNBytes(auStack_d18,local_8);
                if ((int)local_40 < local_8) {
                  puts("> Error while flashing firmware data.");
                  if (local_40 == 0xffffffff) {
                    perror("ERROR: RS232_SendNBytes(page_data) failed...");
                  }
                  local_14 = 8;
                  goto LAB_00403830;
                }
                printf("Test: RS232_SendNBytes_page_data(size: %d, pkg_cnt: %d, read_bytes: %d).\n",
                       (ulong)local_40,(ulong)local_30,local_10);
                local_18 = local_18 + 0x400;
                printf("Has sent %d Bytes\n",(ulong)local_18);
                local_1 = '\0';
                local_24 = 0;
                local_31 = '\0';
                do {
                  memset(abStack_518,0,100);
                  usleep(2000);
                  local_44 = RS232_Receive(abStack_518,100);
                  if ((int)local_44 < 1) {
                    if (local_44 == 0xffffffff) {
                      __errno_location();
                    }
                  }
                  else {
                    printf("recv %d data:\n",(ulong)local_44);
                    for (local_38 = 0; local_38 < (int)local_44; local_38 = local_38 + 1) {
                      printf("%02hhX ",(ulong)abStack_518[local_38]);
                    }
                    putchar(10);
                    if (0 < (int)local_44) {
                      local_1541[0] = '\0';
                      local_1550 = 0;
                      local_1551 = 0;
                      local_60 = parse_recvBuf(abStack_518,local_44,local_1541,&local_1550,
                                               &local_1551);
                      if ((int)local_60 < 0) {
                        printf("ERROR: parse_recvBuf() = %d.\n",(ulong)local_60);
                      }
                      else if ((local_1541[0] == '\x02') && (6 < local_1551)) {
                        if (*(char *)(local_1550 + 6) == '\x01') {
                          local_1 = '\x01';
                        }
                        else if (*(char *)(local_1550 + 6) == '\x02') {
                          local_40 = RS232_SendNBytes(auStack_d18,local_8);
                          if ((int)local_40 < local_8) {
                            puts("> Error while flashing firmware data.");
                            if (local_40 == 0xffffffff) {
                              perror(
                                    "ERROR: RS232_SendNBytes(page_data)-data_error-resend failed..."
                                    );
                            }
                            local_14 = 8;
                            goto LAB_00403830;
                          }
                          printf("Test: RS232_SendNBytes_page_data-resend(size: %d, pkg_cnt: %d, read_bytes: %d).\n"
                                 ,(ulong)local_40,(ulong)local_30,local_10);
                        }
                      }
                    }
                  }
                  if (((local_1 == '\0') && (0x9c3 < local_24)) && (local_31 == '\0')) {
                    local_31 = '\x01';
                    local_40 = RS232_SendNBytes(auStack_d18,local_8);
                    if ((int)local_40 < local_8) {
                      puts("> Error while flashing firmware data.");
                      if (local_40 == 0xffffffff) {
                        perror("ERROR: RS232_SendNBytes(page_data)-overtime-resend failed...");
                      }
                      local_14 = 8;
                      goto LAB_00403830;
                    }
                    printf("Test: RS232_SendNBytes_page_data-overtime-resend(size: %d, pkg_cnt: %d, read_bytes: %d).\n"
                           ,(ulong)local_40,(ulong)local_30,local_10);
                  }
                } while ((local_1 == '\0') && (local_24 = local_24 + 1, local_24 < 5000));
                if (local_1 == '\0') {
                  puts("> Error, no ok receive, timeout(10s) and exit!!!");
                  local_14 = 9;
                  break;
                }
                memset(&local_470,0xff,0x406);
                local_10 = fread(auStack_46a,1,0x400,local_58);
                if (local_10 == 0) {
                  printf("Test: fread() finish(%d).\n",0);
                  local_32 = '\x01';
                  break;
                }
                local_470 = (undefined1)(local_30 >> 0x18);
                local_46f = (undefined1)(local_30 >> 0x10);
                local_46e = (undefined1)(local_30 >> 8);
                local_46d = (undefined1)local_30;
                local_46c = (undefined1)(local_10 >> 8);
                local_46b = (undefined1)local_10;
                local_8 = set_sendBuf(auStack_d18,2,&local_470,
                                      ((uint)local_10 & 0xffff) + 6 & 0xffff);
              }
              puts("\n> Done!");
              if (local_32 == '\0') {
                puts("\n> Sending <Abort> command...");
                local_8 = set_sendBuf(auStack_d18,1,local_1538,2);
              }
              else {
                puts("\n> Sending <End> command...");
                local_8 = set_sendBuf(auStack_d18,1,local_1530,2);
              }
              for (local_20 = 0; local_20 < 2; local_20 = local_20 + 1) {
                local_40 = RS232_SendNBytes(auStack_d18,local_8);
                if ((int)local_40 < local_8) {
                  printf("> Error while sending %d <End/Abort> command.\n",(ulong)local_40);
                  if (local_40 == 0xffffffff) {
                    perror("ERROR: RS232_SendNBytes() failed...");
                  }
                  local_14 = 10;
                  goto LAB_00403830;
                }
                printf("Test: RS232_SendNBytes(size: %d)\n",(ulong)local_40);
                local_1 = '\0';
                local_24 = 0;
                do {
                  memset(abStack_518,0,100);
                  usleep(2000);
                  local_44 = RS232_Receive(abStack_518,100);
                  if ((int)local_44 < 1) {
                    if (local_44 == 0xffffffff) {
                      __errno_location();
                    }
                  }
                  else {
                    printf("recv %d data:\n",(ulong)local_44);
                    for (local_3c = 0; local_3c < (int)local_44; local_3c = local_3c + 1) {
                      printf("%02hhX ",(ulong)abStack_518[local_3c]);
                    }
                    putchar(10);
                    local_1552 = '\0';
                    local_1560 = (char *)0x0;
                    local_1561 = '\0';
                    local_64 = parse_recvBuf(abStack_518,local_44,&local_1552,&local_1560,
                                             &local_1561);
                    if ((int)local_64 < 0) {
                      printf("ERROR: parse_recvBuf() = %d.\n",(ulong)local_64);
                    }
                    else if (((local_1552 == '\x01') && (local_1561 == '\x02')) &&
                            (*local_1560 == '\x02')) {
                      local_1 = '\x01';
                    }
                  }
                } while ((local_1 == '\0') && (local_24 = local_24 + 1, local_24 < 0x4e2));
                if (local_1 != '\0') break;
              }
              if (local_1 == '\0') {
                puts("> Error, no ok receive, timeout(5s) and exit!!!");
                local_14 = 0xb;
              }
            }
          }
        }
        else {
          printf("> Unable to open the [%s]\n",*(undefined8 *)(param_2 + 0x10));
          perror("ERROR");
          local_14 = 3;
        }
LAB_00403830:
        iVar1 = 0;
        if (local_58 != (FILE *)0x0) {
          iVar1 = fclose(local_58);
        }
        RS232_CloseComport(iVar1);
        puts("> Finish");
      }
    }
  }
  return local_14;
}


/* ================================================================
 * Address: 00403868
 * Symbol: serial_init
 * Signature: undefined serial_init(void)
 * ================================================================ */

bool serial_init(undefined8 param_1)

{
  int iVar1;
  
  printf("> Trying to open the [%s]...\n",param_1);
  iVar1 = RS232_OpenComport(param_1);
  return iVar1 != 0;
}

