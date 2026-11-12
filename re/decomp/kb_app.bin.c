// ===== thunk_FUN_01010482 @ 01010408

void thunk_FUN_01010482(void)

{
  (*DAT_0101040c)();
  return;
}


// ===== FUN_01010418 @ 01010418

void FUN_01010418(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined3 uStack_f;
  int local_c;
  
  local_c = DAT_010106e0 * param_1;
  _local_10 = CONCAT31((int3)((uint)param_3 >> 8),2);
  FUN_0101b6ce(&local_10);
  FUN_0101b724(2,1);
  FUN_0101b686(2,1);
  FUN_0101e1c4(0xf);
  return;
}


// ===== FUN_01010444 @ 01010444

void FUN_01010444(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined3 uStack_f;
  undefined4 local_c;
  
  local_c = DAT_010106e4;
  _local_10 = CONCAT31((int3)((uint)param_3 >> 8),1);
  FUN_0101b6ce(&local_10);
  FUN_0101b724(1);
  FUN_0101b686(1);
  FUN_0101e1c4(0xe);
  return;
}


// ===== FUN_0101046e @ 0101046e

void FUN_0101046e(void)

{
  FUN_0101c3fc(0x1d);
  FUN_0101c438(0);
  FUN_0101c42a();
  return;
}


// ===== FUN_01010482 @ 01010482

void FUN_01010482(void)

{
  byte bVar1;
  int iVar2;
  
  FUN_0101c036(0);
  FUN_0101ccc6();
  FUN_0101046e();
  FUN_0101bc92();
  FUN_0101c236();
  FUN_0101bc92();
  FUN_0101e178(0,1);
  FUN_0101e178(5,1);
  FUN_0101e178(0xe,2);
  FUN_0101e178(6,3);
  FUN_0101e178(0xffffffff);
  FUN_01018f0c();
  *DAT_010106e8 = 1;
  FUN_01018f48();
  FUN_010107b8();
  FUN_01011efc();
  FUN_01011894();
  FUN_010118a6();
  FUN_01017860();
  iVar2 = DAT_010106f0;
  if (-1 < (int)((uint)*(ushort *)(DAT_010106ec + 0x1c) << 0x17)) {
    FUN_0101e358();
    *(undefined1 *)(iVar2 + 0x1b) = 1;
  }
  *(undefined1 *)(DAT_010106f0 + 0x23) = 1;
  FUN_01011782();
  FUN_010109d6();
  FUN_0101385c();
  FUN_0101be90(DAT_010106f4);
  FUN_01010444();
  FUN_01010418(0x60);
  *(undefined1 *)(DAT_010106ec + -8) = 0;
  *DAT_010106f8 = *DAT_010106f8 | 1;
  do {
    FUN_0101c420();
    bVar1 = *(byte *)(iVar2 + 0xc);
    if (bVar1 == 5) {
LAB_01010562:
      FUN_01011444();
    }
    else if (bVar1 < 6) {
      if (((bVar1 == 0) || (bVar1 == 1)) || (bVar1 == 2)) goto LAB_01010562;
    }
    else if (bVar1 == 6) {
      FUN_01011072();
    }
    else if (bVar1 == 0xfd) {
      FUN_010118e0();
    }
    else if (bVar1 == 0xfe) {
      FUN_01011ab4();
    }
    FUN_010109f2();
  } while( true );
}


// ===== FUN_0101071c @ 0101071c

void FUN_0101071c(void)

{
  int iVar1;
  uint uVar2;
  
  *DAT_0101083c = 0;
  iVar1 = DAT_01010840;
  uVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + uVar2) = 0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 200);
  return;
}


// ===== FUN_01010730 @ 01010730

void FUN_01010730(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  
  iVar1 = DAT_01010844;
  iVar2 = 0;
  iVar3 = DAT_01010844 + -0x15;
  do {
    if (param_1 == 2) {
      uVar4 = 0x40;
LAB_01010752:
      *(undefined1 *)
       ((uint)*(byte *)(iVar1 + iVar2) +
       (uint)*(byte *)(DAT_01010844 + -0x24 + (uint)*(byte *)(iVar3 + iVar2)) * 0x10 + DAT_01010848)
           = uVar4;
    }
    else {
      if (param_1 == 1) {
        uVar4 = 0;
        goto LAB_01010752;
      }
      if (param_1 == 6) {
        uVar4 = 0x3f;
        goto LAB_01010752;
      }
      if (param_1 == 7) {
        uVar4 = 0x3e;
        goto LAB_01010752;
      }
    }
    iVar2 = iVar2 + 1;
    if (0x10 < iVar2) {
      return;
    }
  } while( true );
}


// ===== FUN_01010774 @ 01010774

void FUN_01010774(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  
  iVar1 = 0;
  iVar2 = DAT_01010844 + -0x1b;
  iVar3 = DAT_01010844 + -0x21;
  do {
    if (param_1 == 2) {
      uVar4 = 0x40;
LAB_01010796:
      *(undefined1 *)
       ((uint)*(byte *)(iVar2 + iVar1) +
       (uint)*(byte *)(DAT_01010844 + -0x24 + (uint)*(byte *)(iVar3 + iVar1)) * 0x10 + DAT_01010848)
           = uVar4;
    }
    else {
      if (param_1 == 1) {
        uVar4 = 0;
        goto LAB_01010796;
      }
      if (param_1 == 6) {
        uVar4 = 0x3f;
        goto LAB_01010796;
      }
      if (param_1 == 7) {
        uVar4 = 0x3e;
        goto LAB_01010796;
      }
    }
    iVar1 = iVar1 + 1;
    if (5 < iVar1) {
      return;
    }
  } while( true );
}


// ===== FUN_010107b8 @ 010107b8

void FUN_010107b8(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  puVar2 = DAT_0101084c;
  FUN_0101abd8(0,DAT_0101084c[6]);
  iVar1 = DAT_01010848;
  *(undefined1 *)(DAT_01010848 + 6) = 0x40;
  FUN_0101abd8(0,puVar2[7]);
  *(undefined1 *)(iVar1 + 7) = 0x40;
  FUN_0101c3bc();
  FUN_0101abd8(2,*puVar2,0);
  FUN_01010774(2);
  FUN_01010730(7);
  FUN_0101071c();
  FUN_0101abd8(0,puVar2[2]);
  *(undefined1 *)(iVar1 + 2) = 0x3e;
  FUN_0101abd8(0,puVar2[3]);
  *(undefined1 *)(iVar1 + 3) = 0x40;
  FUN_0101abd8(0,puVar2[4]);
  *(undefined1 *)(iVar1 + 4) = 0x40;
  *(undefined1 *)(DAT_01010848 + 0x21) = 0;
  FUN_0101abd8(0,puVar2[0xf],0);
  *(undefined1 *)(iVar1 + 0xf) = 0x40;
  *(undefined1 *)(iVar1 + 8) = 0x40;
  return;
}


// ===== FUN_01010850 @ 01010850

void FUN_01010850(void)

{
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined2 local_c;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined4 local_8;
  
  _local_10 = CONCAT13(*DAT_01010c58,
                       CONCAT12(*(undefined1 *)(DAT_01010c54 + -0x13),
                                CONCAT11(*(undefined1 *)(DAT_01010c54 + -0x14),
                                         *(undefined1 *)(DAT_01010c54 + 3))));
  _local_c = CONCAT13(*(undefined1 *)(DAT_01010c60 + 0x1a),
                      CONCAT12(*(undefined1 *)(DAT_01010c60 + 0x18),
                               *(undefined2 *)(DAT_01010c5c + 10)));
  local_8 = (uint)CONCAT11(*(undefined1 *)(DAT_01010c54 + -10),*(undefined1 *)(DAT_01010c60 + 0xc));
  FUN_0101c82e(&local_10,3,0);
  return;
}


// ===== FUN_0101089c @ 0101089c

void FUN_0101089c(void)

{
  FUN_0101c1ec(DAT_01010c64,0x12,1);
  FUN_0101c1ec(DAT_01010c64 + -4,0,0x20,0x73800);
  return;
}


// ===== FUN_010108bc @ 010108bc

void FUN_010108bc(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  FUN_0101bec6();
  FUN_0101b686(1,0);
  FUN_0101b686(0);
  FUN_0101b686(2,0);
  FUN_0101b29a(0);
  FUN_0101abd8(0,2,0x40);
  FUN_0101abd8(0,1,0x40);
  FUN_0101b29a(1);
  iVar2 = DAT_01010c6c;
  pbVar1 = DAT_01010c68;
  iVar3 = (uint)*DAT_01010c68 * 0x10 + DAT_01010c6c;
  *(undefined1 *)(iVar3 + 8) = 0x3e;
  FUN_0101abd8(0,0x200);
  FUN_0101abd8(0,0x400);
  FUN_01010774(2);
  FUN_01010730(7);
  FUN_0101394a();
  *(undefined1 *)((uint)pbVar1[2] * 0x10 + iVar2 + 1) = 0;
  *(undefined1 *)(iVar3 + 0xf) = 0x3e;
  *(undefined1 *)(iVar3 + 3) = 0x3e;
  *(undefined1 *)(iVar3 + 4) = 0x3e;
  *(undefined1 *)(iVar3 + 7) = 0;
  return;
}


// ===== FUN_01010944 @ 01010944

void FUN_01010944(void)

{
  FUN_0101c20c();
  FUN_010108bc();
  FUN_0101089c();
  FUN_01010850();
  *(undefined1 *)((uint)*DAT_01010c68 * 0x10 + DAT_01010c6c + 2) = 0x3f;
  FUN_0101c9a0();
  FUN_0101c236();
  FUN_0101c1ec(DAT_01010c64,0x11,1,0);
  thunk_EXT_FUN_0000425c(10);
  thunk_EXT_FUN_00004d68();
  return;
}


// ===== FUN_01010984 @ 01010984

void FUN_01010984(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = DAT_01010c54;
  puVar2 = (undefined1 *)(DAT_01010c54 + 0x18);
  *(undefined1 *)(DAT_01010c54 + 0x1a) = 0;
  *puVar2 = 0;
  *(undefined1 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return;
}


// ===== FUN_01010996 @ 01010996

void FUN_01010996(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = DAT_01010c54;
  puVar3 = (undefined1 *)(DAT_01010c54 + 0x18);
  *(char *)(DAT_01010c54 + 0x1a) = (char)param_1;
  if (param_1 != 0) {
    if (param_1 == 1) {
      *puVar3 = 1;
      *(undefined1 *)(iVar1 + 0x28) = 2;
      uVar2 = 0x708;
      *(undefined4 *)(iVar1 + 0x1c) = 1;
    }
    else if (param_1 == 2) {
      *puVar3 = 1;
      *(undefined1 *)(iVar1 + 0x28) = 0;
      uVar2 = 200;
      *(undefined4 *)(iVar1 + 0x1c) = 1;
    }
    else {
      if (param_1 != 3) {
        return;
      }
      *puVar3 = 1;
      *(undefined1 *)(iVar1 + 0x28) = 0;
      uVar2 = 900;
      *(undefined4 *)(iVar1 + 0x1c) = 1;
    }
    *(undefined4 *)(iVar1 + 0x20) = uVar2;
  }
  return;
}


// ===== FUN_010109d6 @ 010109d6

void FUN_010109d6(void)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = DAT_01010c54;
  pbVar2 = (byte *)(DAT_01010c54 + 0xc);
  *pbVar2 = *pbVar2 | 2;
  *pbVar2 = *pbVar2 & 0xfe;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined2 *)(iVar1 + 0x14) = 0;
  return;
}


// ===== FUN_010109f2 @ 010109f2

void FUN_010109f2(void)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = DAT_01010c54;
  if (*(char *)(DAT_01010c54 + -0x13) != *(char *)(DAT_01010c54 + -0x14)) {
    bVar1 = *(byte *)(DAT_01010c54 + -0x13);
    if (bVar1 == 5) {
LAB_01010b18:
      FUN_01019b5a();
      FUN_0101071c();
      DAT_000f6000 = 0;
      *DAT_01010c80 = 0;
      iVar4 = (uint)*DAT_01010c68 * 0x10 + DAT_01010c6c;
      *(undefined1 *)(iVar4 + 2) = 0x3f;
      thunk_EXT_FUN_0000425c(10);
      *(undefined1 *)(iVar4 + 2) = 0x3e;
      FUN_01010984();
      *DAT_01010c84 = 0;
      puVar3 = DAT_01010c74;
      *DAT_01010c58 = 0;
      *(undefined2 *)(DAT_01010c5c + 8) = 0;
      pbVar2 = DAT_01010c70;
      pbVar2[0] = 0;
      pbVar2[1] = 0;
      pbVar2[2] = 0;
      pbVar2[3] = 0;
      *puVar3 = 0;
      *(undefined1 *)(iVar5 + -0x14) = *(undefined1 *)(iVar5 + -0x13);
      if ((*(char *)(iVar5 + 3) == '\0') &&
         (*(char *)(DAT_01010c88 + 1) != *(char *)(iVar5 + -0x14))) {
        *(undefined1 *)(DAT_01010c88 + 1) = *(undefined1 *)(iVar5 + -0x14);
        *DAT_01010c8c = 1;
      }
      *pbVar2 = *pbVar2 | 1;
      *DAT_01010c7c = 0;
      FUN_01011cec();
      *(undefined1 *)(iVar5 + -6) = 1;
      return;
    }
    if (bVar1 < 6) {
      if (((bVar1 == 0) || (bVar1 == 1)) || (bVar1 == 2)) goto LAB_01010b18;
    }
    else {
      if (bVar1 == 6) {
        *(undefined1 *)(DAT_01010c54 + -0x14) = *(undefined1 *)(DAT_01010c54 + -0x13);
        *(undefined1 *)(iVar5 + 8) = 1;
        pbVar2 = DAT_01010c78;
        *DAT_01010c78 = *DAT_01010c78 & 0xfd;
        FUN_010109d6();
        FUN_01019b5a();
        FUN_0101b686(1,0);
        FUN_01010730(7);
        iVar5 = (uint)*DAT_01010c68 * 0x10 + DAT_01010c6c;
        *(undefined1 *)(iVar5 + 2) = 0x3e;
        thunk_EXT_FUN_0000425c(2);
        FUN_0101b5b4(0,0x44);
        FUN_0101b5b4(0,3);
        FUN_0101b5b4(0,1);
        FUN_0101b5b4(0,6);
        FUN_0101b5b4(0,10);
        thunk_EXT_FUN_0000425c(10);
        *(undefined1 *)(iVar5 + 2) = 0x3f;
        FUN_0101c9f2();
        iVar5 = 0;
        do {
          thunk_EXT_FUN_0000425c(1);
          if ((int)((uint)*pbVar2 << 0x1e) < 0) break;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 800);
        *DAT_01010c58 = 0;
        FUN_01010984();
        FUN_01010996(1);
        *DAT_01010c7c = 0;
        FUN_01011cb6();
        FUN_0101b686(1);
        iVar5 = DAT_01010c60;
        *(undefined1 *)(DAT_01010c60 + 0x18) = 0;
        *(undefined1 *)(iVar5 + 0x1a) = 0;
        *(undefined1 *)(DAT_01010c54 + -6) = 1;
        FUN_0101e318(1,0);
        return;
      }
      if (bVar1 == 0xfd) {
        DAT_000f6000 = 0;
        *(undefined1 *)(DAT_01010c54 + -0x14) = 0xfd;
        *(undefined1 *)(iVar5 + 3) = 1;
        *DAT_01010c58 = 0;
        *(undefined2 *)(DAT_01010c5c + 8) = 0;
        pbVar2 = DAT_01010c70;
        pbVar2[0] = 0;
        pbVar2[1] = 0;
        pbVar2[2] = 0;
        pbVar2[3] = 0;
        *DAT_01010c74 = 0;
        *(undefined1 *)(iVar5 + 9) = 0;
LAB_01010a52:
        thunk_EXT_FUN_0000425c(0x32);
        return;
      }
      if (bVar1 == 0xfe) {
        *(undefined1 *)(DAT_01010c54 + -0x14) = 0xfe;
        *(undefined4 *)(iVar5 + -0x1c) = 0;
        goto LAB_01010a52;
      }
    }
    *(undefined1 *)(DAT_01010c54 + -0x14) = 0;
  }
  return;
}


// ===== FUN_01010b8c @ 01010b8c

void FUN_01010b8c(void)

{
  if (*(byte *)(DAT_01010c54 + -0x14) < 6) {
    if (*(char *)(DAT_01010c54 + -0x14) != -3) {
      FUN_01017a78();
      FUN_010178e4();
      FUN_0101795c();
      FUN_01017d4c();
    }
  }
  else if ((int)((uint)*DAT_01010c78 << 0x1e) < 0) {
    if (*(char *)(DAT_01010c54 + 8) != '\0') {
      *(undefined1 *)(DAT_01010c54 + 8) = 0;
    }
    FUN_0101ca6c();
    return;
  }
  return;
}


// ===== FUN_01010bcc @ 01010bcc

void FUN_01010bcc(void)

{
  if (*(char *)(DAT_01010c90 + 0x13) == '\0') {
    if (*DAT_01010c58 == '\a') {
      *DAT_01010c94 = 0;
    }
    if ((*DAT_01010c98 & 1) != 0) {
      *DAT_01010c98 = *DAT_01010c98 & 0xfe;
    }
  }
  return;
}


// ===== FUN_01010bf4 @ 01010bf4

void FUN_01010bf4(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  
  if (*(char *)(DAT_01010c54 + 1) != '\0') {
    if (*(char *)(DAT_01010c54 + -0x14) == '\x06') {
      FUN_0101c20c();
      FUN_010108bc();
      FUN_0101089c();
      FUN_01010850();
      *(undefined1 *)((uint)*DAT_01010c68 * 0x10 + DAT_01010c6c + 2) = 0x3f;
      iVar7 = DAT_01010c6c;
      do {
        FUN_0101c420();
        uVar1 = *(ushort *)(iVar7 + 0x3e);
        uVar2 = *(ushort *)(iVar7 + 0x3e);
        uVar3 = *(ushort *)(iVar7 + 0x3e);
        uVar4 = *(ushort *)(iVar7 + 0x3c);
        uVar5 = *(ushort *)(iVar7 + 0x3c);
        uVar6 = *(ushort *)(iVar7 + 0x3c);
        thunk_EXT_FUN_0000425c(5);
      } while (((uVar1 & 7) >> 2 | uVar2 & 2 | (uVar3 & 1) << 2 | ((uVar4 & 0x3fff) >> 0xd) << 3 |
                ((uVar5 & 0x1fff) >> 0xc) << 4 | ((uVar6 & 0xfff) >> 0xb) << 5 | 0xc0) != 0xff);
      FUN_0101c9a0();
      FUN_0101c236();
      FUN_0101c1ec(DAT_010110e0,0x11,1,0);
      thunk_EXT_FUN_0000425c(10);
      thunk_EXT_FUN_00004d68();
      return;
    }
    if (*(byte *)(DAT_01010c54 + -0x14) < 6) {
      *DAT_01010c70 = *DAT_01010c70 | 0x20;
      *DAT_01010c74 = *DAT_01010c74 | 0x40;
    }
  }
  return;
}


// ===== FUN_01010cf6 @ 01010cf6

void FUN_01010cf6(void)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = DAT_010110e8;
  if ((int)((uint)*(ushort *)(DAT_010110e4 + 0x1c) * 0x800000) < 0) {
    *(undefined1 *)(DAT_010110e8 + 0x1e) = 1;
    *(undefined1 *)(iVar1 + 0x1d) = 0;
    *(undefined1 *)(iVar1 + 0x1b) = 0;
    if ((*(char *)(iVar1 + 0x1c) != '\0') &&
       (bVar2 = *(char *)(iVar1 + 0x1f) + 1, *(byte *)(iVar1 + 0x1f) = bVar2, 0x31 < bVar2)) {
      *(undefined1 *)(iVar1 + 0x1f) = 0;
      *(undefined1 *)(iVar1 + 0x1c) = 0;
      FUN_0101b29a(1);
      FUN_0101abd8(0,0x400);
      FUN_0101abd8(0,0x200);
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_010110e8 + 0x1c) = 1;
    *(undefined1 *)(iVar1 + 0x1f) = 0;
    if (*(char *)(iVar1 + 0x1e) != '\0') {
      bVar2 = *(char *)(iVar1 + 0x1d) + 1;
      *(byte *)(iVar1 + 0x1d) = bVar2;
      if (0x31 < bVar2) {
        *(undefined1 *)(iVar1 + 0x1e) = 0;
        *(undefined1 *)(iVar1 + 0x1d) = 0;
        FUN_0101e358();
        FUN_0101e318(1,0);
        *(undefined1 *)(iVar1 + 0x1b) = 1;
      }
    }
  }
  return;
}


// ===== FUN_01010d6e @ 01010d6e

void FUN_01010d6e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_010107b8();
  if (*(char *)(DAT_010110e8 + 0x25) == '\0') {
    FUN_0101385c();
    uVar4 = DAT_010110f0;
  }
  else {
    FUN_0101c036(0xe);
    thunk_EXT_FUN_0000425c(1);
    uVar4 = DAT_010110ec;
  }
  FUN_0101be90(uVar4);
  FUN_01017860();
  iVar2 = DAT_010110e8;
  iVar1 = DAT_010110e4;
  if (-1 < (int)((uint)*(ushort *)(DAT_010110e4 + 0x1c) * 0x800000)) {
    FUN_0101e358();
    *(undefined1 *)(iVar2 + 0x1b) = 1;
    FUN_0101e318(1,0);
  }
  *DAT_010110f4 = *DAT_010110f4 | 1;
  if (*(char *)(iVar2 + 0xc) == '\x06') {
    *(undefined1 *)((uint)*DAT_010110f8 * 0x10 + DAT_010110e4 + -0x1e) = 0x3f;
  }
  FUN_01011efc();
  FUN_0101b686(1);
  FUN_0101b686(2,1);
  iVar3 = DAT_010110fc;
  if ((int)((uint)*(ushort *)(iVar1 + 0x1c) * 0x2000000) < 0) {
    if (*(char *)(iVar2 + 0x16) == '\x01') {
      *(undefined1 *)(DAT_010110fc + 0x15) = 1;
    }
    else if (*(char *)(iVar2 + 0x16) == '\x02') {
      *(undefined1 *)(DAT_010110fc + 0x15) = 2;
    }
    else {
      *(undefined1 *)(iVar2 + 0x16) = 0;
    }
    if (*(char *)(iVar3 + 0xc) == '\0') {
      *(undefined1 *)(iVar3 + 0x16) = 1;
    }
  }
  else if ((int)((uint)*(ushort *)(iVar1 + 0x1c) << 0x18) < 0) {
    *(undefined1 *)(iVar2 + 0x16) = 2;
    *(undefined1 *)(iVar3 + 0x15) = 2;
  }
  else {
    *(undefined1 *)(iVar2 + 0x16) = 1;
    *(undefined1 *)(iVar3 + 0x15) = 1;
  }
  FUN_0101e318(1,0);
  return;
}


// ===== FUN_01010ee4 @ 01010ee4

void FUN_01010ee4(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  
  iVar7 = DAT_010110e8;
  if (((int)((uint)*(byte *)(DAT_010110e8 + 0x2c) << 0x1e) < 0) &&
     (uVar11 = *(int *)(DAT_010110e8 + 0x30) + 1, *(uint *)(DAT_010110e8 + 0x30) = uVar11,
     DAT_01011108 <= uVar11)) {
    *(undefined4 *)(iVar7 + 0x30) = 0;
    pbVar9 = DAT_01011100;
    if (*(short *)(iVar7 + 0x34) == *(short *)(DAT_01011104 + 9)) {
      *DAT_01011100 = *DAT_01011100 & 0xfe;
      *pbVar9 = *pbVar9 & 0xfb;
      FUN_0101c20c();
      FUN_010108bc();
      FUN_0101c9a0();
      FUN_0101c236();
      FUN_0101c2b0();
      thunk_EXT_FUN_0000425c(5);
      FUN_010109d6();
      iVar10 = DAT_01011104;
      iVar8 = DAT_010110e8;
      *(undefined2 *)(DAT_010110e8 + 0x34) = *(undefined2 *)(DAT_01011104 + 9);
      FUN_0101c420();
      iVar7 = DAT_010110e4;
      do {
        FUN_0101c420();
        uVar1 = *(ushort *)(iVar7 + 0x1e);
        uVar2 = *(ushort *)(iVar7 + 0x1e);
        uVar3 = *(ushort *)(iVar7 + 0x1e);
        uVar4 = *(ushort *)(iVar7 + 0x1c);
        uVar5 = *(ushort *)(iVar7 + 0x1c);
        uVar6 = *(ushort *)(iVar7 + 0x1c);
        thunk_EXT_FUN_0000425c(1);
        if (*(short *)(iVar8 + 0x34) != *(short *)(iVar10 + 9)) break;
      } while (((uVar1 & 7) >> 2 | uVar2 & 2 | (uVar3 & 1) << 2 | ((uVar4 & 0x3fff) >> 0xd) << 3 |
                ((uVar5 & 0x1fff) >> 0xc) << 4 | ((uVar6 & 0xfff) >> 0xb) << 5 | 0xc0) == 0xff);
      FUN_0101c036(0);
      FUN_0101bc92();
      FUN_01010d6e();
      FUN_0101c420();
      return;
    }
    *(short *)(iVar7 + 0x34) = *(short *)(DAT_01011104 + 9);
  }
  return;
}


// ===== FUN_01010f14 @ 01010f14

void FUN_01010f14(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  bool bVar6;
  
  pbVar3 = DAT_0101110c;
  bVar6 = -1 < *(short *)(DAT_010110e4 + 0x1c);
  bVar1 = *DAT_0101110c;
  bVar2 = DAT_0101110c[(uint)bVar1 * 2 + 10];
  if ((bVar2 & 7) >> 1 == (uint)bVar6) {
    *(undefined1 *)(DAT_010110e8 + 0x15) = 0;
    return;
  }
  bVar5 = *(char *)(DAT_010110e8 + 0x15) + 1;
  *(byte *)(DAT_010110e8 + 0x15) = bVar5;
  pbVar4 = DAT_01011110;
  if (0x31 < bVar5) {
    bVar5 = bVar6 << 1;
    pbVar3[(uint)bVar1 * 2 + 10] = bVar2 & 0xf9 | bVar5;
    *pbVar4 = *pbVar4 | 1;
    pbVar3[(uint)*pbVar3 * 2 + 10] = bVar2 & 0xf8 | bVar5;
    FUN_0101351e();
    FUN_010134d8();
    FUN_01013738();
    FUN_01013768();
    FUN_0101233e(3,(pbVar3[(uint)*pbVar3 * 2 + 10] & 7) >> 1,2);
    FUN_0101e318(1,0);
  }
  return;
}


// ===== FUN_01010f94 @ 01010f94

byte FUN_01010f94(void)

{
  byte bVar1;
  
  if (-1 < (int)((uint)*(ushort *)(DAT_010110e4 + 0x20) << 0x1e)) {
    return 6;
  }
  bVar1 = *(byte *)(DAT_0101110c + 1);
  if (5 < bVar1) {
    bVar1 = 0;
  }
  return bVar1;
}


// ===== FUN_01010fae @ 01010fae

void FUN_01010fae(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = FUN_01010f94();
  iVar1 = DAT_010110e8;
  if (*(byte *)(DAT_010110e8 + 0xc) == uVar2) {
    *(undefined1 *)(DAT_010110e8 + 0xe) = 0;
    return;
  }
  bVar3 = *(char *)(DAT_010110e8 + 0xe) + 1;
  *(byte *)(DAT_010110e8 + 0xe) = bVar3;
  if (0x31 < bVar3) {
    *(undefined1 *)(iVar1 + 0xe) = 0;
    *(char *)(iVar1 + 0xd) = (char)uVar2;
  }
  return;
}


// ===== FUN_01011072 @ 01011072

void FUN_01011072(void)

{
  int iVar1;
  
  if (*(char *)(DAT_010110e8 + 0x23) != '\0') {
    *(undefined1 *)(DAT_010110e8 + 0x23) = 0;
  }
  if ((int)((uint)*DAT_01011100 << 0x1d) < 0) {
    thunk_EXT_FUN_0000425c(100);
    if ((int)((uint)*(ushort *)(DAT_010110e4 + 0x1c) << 0x19) < 0) {
      FUN_01010944();
    }
    else {
      FUN_0101cb6e();
    }
  }
  iVar1 = DAT_010110e8;
  if (*(char *)(DAT_010110e8 + 0x2b) == '\0') {
    if (*(char *)(DAT_010110e8 + 0x12) == '\x05') {
      *(undefined1 *)(DAT_010110e8 + 0x12) = 0;
      FUN_01013c80();
    }
  }
  else {
    *(undefined1 *)(DAT_010110e8 + 0x2b) = 0;
    FUN_010170dc();
  }
  if (*(char *)(iVar1 + 0x10) == '\x02') {
    *(undefined1 *)(iVar1 + 0x10) = 0;
    FUN_01010fae();
    FUN_01010f14();
    FUN_01010ee4();
    FUN_01010cf6();
    FUN_01011ef8();
    FUN_01010bf4();
    FUN_01018f48();
    FUN_01019070();
    FUN_0101920e();
    FUN_01019670();
    FUN_010192a0();
    FUN_01019672();
    FUN_01019730();
    FUN_01019514();
    FUN_0101935c();
    FUN_01019424();
    FUN_010198ac();
    FUN_010195a4();
    FUN_01019966();
    FUN_01010bcc();
  }
  return;
}


// ===== FUN_01011082 @ 01011082

void FUN_01011082(void)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if ((*DAT_01011114 == '\x04') && (*(byte *)(DAT_010110e8 + 0xc) < 5)) {
    if (*(char *)(DAT_010110fc + 0x1b) == '\0') goto LAB_010110b8;
  }
  else if (*(char *)(DAT_010110fc + 0x1b) == '\0') {
    if (*(char *)(DAT_010110e8 + 0xc) != '\x05') {
      return;
    }
    goto LAB_010110b8;
  }
  *(undefined1 *)(DAT_010110fc + 0x1b) = 0;
  FUN_0101351e();
  FUN_010134d8();
  FUN_01013738();
LAB_010110b8:
  pbVar2 = DAT_0101111c;
  pbVar1 = DAT_01011118;
  if ((int)((uint)*DAT_01011118 << 0x1b) < 0) {
    *DAT_01011118 = *DAT_01011118 & 0xef;
    *pbVar2 = *pbVar2 | 0x80;
  }
  if ((int)((uint)*pbVar1 * 0x4000000) < 0) {
    *pbVar1 = *pbVar1 & 0xdf;
    pbVar2[1] = pbVar2[1] | 4;
  }
  if ((int)((uint)*pbVar1 * 0x40000000) < 0) {
    *pbVar1 = *pbVar1 & 0xfd;
    pbVar2[1] = pbVar2[1] | 2;
  }
  if ((*pbVar1 & 1) != 0) {
    *pbVar1 = *pbVar1 & 0xfe;
    pbVar2[2] = pbVar2[2] | 2;
  }
  if ((int)((uint)*pbVar1 << 0x1d) < 0) {
    *pbVar1 = *pbVar1 & 0xfb;
    pbVar2[2] = pbVar2[2] | 8;
  }
  if ((int)((uint)*pbVar1 << 0x1c) < 0) {
    *pbVar1 = *pbVar1 & 0xf7;
    pbVar2[2] = pbVar2[2] | 4;
    return;
  }
  return;
}


// ===== FUN_0101118c @ 0101118c

void FUN_0101118c(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  byte *pbVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  
  pbVar10 = DAT_01011588;
  iVar15 = DAT_01011584;
  if ((char)*DAT_01011580 < '\0') {
    *DAT_01011580 = *DAT_01011580 & 0x3f;
    FUN_0101c20c();
    FUN_010108bc();
    FUN_0101089c();
    FUN_01010850();
    *(undefined1 *)((uint)*pbVar10 * 0x10 + DAT_01011584 + -0x1e) = 0x3f;
    do {
      FUN_0101c420();
      uVar4 = *(ushort *)(iVar15 + 0x1e);
      uVar5 = *(ushort *)(iVar15 + 0x1e);
      uVar6 = *(ushort *)(iVar15 + 0x1e);
      uVar7 = *(ushort *)(iVar15 + 0x1c);
      uVar8 = *(ushort *)(iVar15 + 0x1c);
      uVar9 = *(ushort *)(iVar15 + 0x1c);
      thunk_EXT_FUN_0000425c(5);
    } while (((uVar4 & 7) >> 2 | uVar5 & 2 | (uVar6 & 1) << 2 | ((uVar7 & 0x3fff) >> 0xd) << 3 |
              ((uVar8 & 0x1fff) >> 0xc) << 4 | ((uVar9 & 0xfff) >> 0xb) << 5 | 0xc0) != 0xff);
    FUN_0101c9a0();
    FUN_0101c236();
    FUN_0101c1ec(DAT_0101158c,0x11,1,0);
    thunk_EXT_FUN_00004d68();
  }
  else if (*DAT_01011590 == '\x05') {
    bVar1 = DAT_01011580[1];
    if (((int)((uint)bVar1 << 0x1c) < 0) && ((int)((uint)bVar1 << 0x1b) < 0)) {
      DAT_01011580[1] = bVar1 & 0xe7;
      piVar11 = DAT_01011594;
      *DAT_01011594 = 0;
      *(undefined1 *)(piVar11 + 1) = 0;
      uVar14 = 0xff;
      FUN_0101c20c();
      FUN_010108bc();
      iVar15 = (uint)*pbVar10 * 0x10 + DAT_01011584 + -0x20;
      *(undefined1 *)(iVar15 + 3) = 0x40;
      *(undefined1 *)(iVar15 + 4) = 0x40;
      *(undefined1 *)(iVar15 + 2) = 0x3e;
      FUN_0101c9a0();
      FUN_0101c1ec(DAT_0101158c,0x11,1,0);
      FUN_0101c2b0();
      thunk_EXT_FUN_0000425c(5);
      uVar4 = *(ushort *)(DAT_01011584 + 0x1c);
      uVar5 = *(ushort *)(DAT_01011584 + 0x1c);
      FUN_0101c420();
      if ((char)piVar11[1] == '\0') {
        FUN_0101c420();
        iVar12 = DAT_01011598;
LAB_01011360:
        if (uVar14 == 0xff) {
          FUN_0101c420();
          uVar14 = (*(ushort *)(DAT_01011584 + 0x1e) & 7) >> 2 |
                   *(ushort *)(DAT_01011584 + 0x1e) & 2 |
                   (*(ushort *)(DAT_01011584 + 0x1e) & 1) << 2 |
                   ((*(ushort *)(DAT_01011584 + 0x1c) & 0x3fff) >> 0xd) << 3 |
                   ((*(ushort *)(DAT_01011584 + 0x1c) & 0x1fff) >> 0xc) << 4 |
                   ((*(ushort *)(DAT_01011584 + 0x1c) & 0xfff) >> 0xb) << 5 | 0xc0;
          if (((*(ushort *)(DAT_01011584 + 0x1c) & 0xf) >> 3 |
              ((*(ushort *)(DAT_01011584 + 0x1c) & 0x1f) >> 4) << 1) ==
              ((uVar4 & 0xf) >> 3 | ((uVar5 & 0x1f) >> 4) << 1)) {
            thunk_EXT_FUN_0000425c(1);
            iVar13 = *piVar11;
            if (*(char *)(DAT_0101159c + 0xc) == '\x05') {
              *piVar11 = iVar13 + 1;
              uVar2 = *(undefined1 *)(iVar12 + 0xd);
              uVar3 = *(undefined1 *)(iVar12 + 0xc);
            }
            else {
              *piVar11 = iVar13 + 1;
              uVar2 = *(undefined1 *)(iVar12 + 9);
              uVar3 = *(undefined1 *)(iVar12 + 8);
            }
            if (iVar13 + 1U < (uint)CONCAT11(uVar2,uVar3) * 1000) goto LAB_0101132a;
            *(undefined1 *)((int)piVar11 + 5) = 1;
            goto LAB_01011330;
          }
        }
        FUN_0101c036(0);
        *(undefined1 *)(piVar11 + 1) = 1;
      }
      FUN_0101c420();
      *(undefined1 *)(iVar15 + 2) = 0x3e;
      FUN_01017c52(4);
      FUN_01017b64(4);
      FUN_01010d6e();
      *DAT_0101157c = 0;
      return;
    }
  }
  return;
LAB_0101132a:
  if (*(char *)((int)piVar11 + 5) != '\0') {
LAB_01011330:
    *(undefined1 *)((int)piVar11 + 5) = 0;
    FUN_0101c420();
    FUN_01017c52(4);
    FUN_01017b64(4);
    FUN_0101c20c();
    FUN_010108bc();
    FUN_0101089c();
    FUN_01010850();
    *(undefined1 *)(iVar15 + 2) = 0x3f;
    FUN_0101c236();
    thunk_EXT_FUN_00004d68();
  }
  goto LAB_01011360;
}


// ===== FUN_01011444 @ 01011444

void FUN_01011444(void)

{
  int iVar1;
  
  if (*(char *)(DAT_0101159c + 0x23) != '\0') {
    *(undefined1 *)(DAT_0101159c + 0x23) = 0;
  }
  iVar1 = DAT_0101159c;
  if (*(char *)(DAT_0101159c + 0x2b) == '\0') {
    if (*(char *)(DAT_0101159c + 0x12) == '\x05') {
      *(undefined1 *)(DAT_0101159c + 0x12) = 0;
      FUN_01013c80();
    }
  }
  else {
    *(undefined1 *)(DAT_0101159c + 0x2b) = 0;
    FUN_010170dc();
  }
  if (*(char *)(iVar1 + 0x10) == '\x02') {
    *(undefined1 *)(iVar1 + 0x10) = 0;
    FUN_01010cf6();
    FUN_010182d8();
    FUN_0101118c();
    FUN_01010fae();
    FUN_01010f14();
    FUN_01011ef8();
    FUN_01010bf4();
    FUN_01018f48();
    FUN_01019070();
    FUN_0101920e();
    FUN_01019670();
    FUN_010192a0();
    FUN_01019672();
    FUN_01019730();
    FUN_01019514();
    FUN_0101935c();
    FUN_01019424();
    FUN_010198ac();
    FUN_010195a4();
    FUN_01019966();
    FUN_01011dbe();
    FUN_01010bcc();
  }
  if (*(char *)(iVar1 + 0x11) == '\x05') {
    *(undefined1 *)(iVar1 + 0x11) = 0;
    if ((*(char *)(iVar1 + 0x25) != '\0') && (FUN_01011f48(), *(char *)(iVar1 + 0x25) != '\0')) {
      if (*(char *)(iVar1 + 0xc) == *(char *)(iVar1 + 0xd)) {
        FUN_01017b1e();
        FUN_01011082();
        FUN_010180e2();
        FUN_010178a0();
      }
    }
  }
  return;
}


// ===== FUN_01011454 @ 01011454

void FUN_01011454(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pbVar1 = DAT_010115a4;
  if (*(char *)(DAT_010115a0 + 0x13) != '\0') {
    return;
  }
  if (*DAT_01011590 == '\a') {
    *DAT_010115a4 = 0;
  }
  pbVar2 = (byte *)(DAT_0101159c + 0x20);
  *pbVar2 = *pbVar1 & 3;
  *pbVar2 = *pbVar2 | (((byte *)(DAT_01011598 + -0x22))
                       [(uint)*(byte *)(DAT_01011598 + -0x22) * 2 + 10] & 1) << 2;
  if (*pbVar2 == 7) {
    uVar4 = 0xff;
LAB_010114e6:
    uVar5 = 0xff;
  }
  else {
    if (*pbVar2 == 6) {
      uVar4 = 0xff;
    }
    else {
      if (*pbVar2 == 5) {
        uVar4 = 0;
        goto LAB_010114e6;
      }
      if (*pbVar2 != 4) {
        if (*pbVar2 == 3) {
          uVar4 = 0xff;
LAB_010114fa:
          uVar5 = 0xff;
        }
        else {
          if (*pbVar2 == 2) {
            uVar4 = 0xff;
          }
          else {
            if (*pbVar2 == 1) {
              uVar4 = 0;
              goto LAB_010114fa;
            }
            if (*pbVar2 != 0) {
              return;
            }
            uVar4 = 0;
          }
          uVar5 = 0;
        }
        uVar3 = 0;
        goto LAB_010114d8;
      }
      uVar4 = 0;
    }
    uVar5 = 0;
  }
  uVar3 = 0xff;
LAB_010114d8:
  FUN_01016926(5,7,100,uVar3,uVar4,uVar5,1);
  return;
}


// ===== FUN_010114fe @ 010114fe
// decompile failed
// ===== FUN_01011734 @ 01011734

void FUN_01011734(void)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  pcVar2 = DAT_010118c8;
  if ((*DAT_010118c8 != '\0') &&
     (iVar4 = *(int *)(DAT_010118c8 + 4), *(int *)(DAT_010118c8 + 4) = iVar4 + -1, iVar4 + -1 == 0))
  {
    *(undefined4 *)(pcVar2 + 4) = *(undefined4 *)(pcVar2 + 8);
    cVar1 = pcVar2[2];
    cVar3 = pcVar2[0x10] + -1;
    if (cVar1 == '\x01') {
      pcVar2[0x10] = cVar3;
      if (cVar3 == '\0') {
        *pcVar2 = '\0';
        return;
      }
    }
    else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
      pcVar2[0x10] = cVar3;
    }
  }
  return;
}


// ===== FUN_0101176c @ 0101176c

void FUN_0101176c(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  FUN_0101c82e(&local_10,3,0);
  return;
}


// ===== FUN_01011782 @ 01011782

void FUN_01011782(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  
  iVar1 = DAT_010118c8;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  *(undefined1 *)(DAT_010118c8 + -0x21) = 0xff;
  FUN_0101c7ec(&local_28,3,0);
  iVar2 = DAT_010118cc;
  local_1c = (uint)local_24._2_1_;
  if (((((((char)local_28 == '\0' && local_28._1_1_ == '\0') &&
         (local_28._3_1_ == '\0' && local_28._2_1_ == '\0')) && (char)local_24 == '\0') &&
       local_24._1_1_ == '\0') && local_24._2_1_ == 0) && local_24._3_1_ == '\0') {
    if ((int)((uint)*(ushort *)(DAT_010118d8 + 0x1c) << 0x19) < 0) {
      *(undefined1 *)(DAT_010118cc + 0x16) = 1;
    }
    else if ((int)((uint)*(ushort *)(DAT_010118d8 + 0x1c) << 0x18) < 0) {
      *(undefined1 *)(iVar1 + -0x22) = 2;
      *(undefined1 *)(iVar2 + 0x15) = 2;
    }
    else {
      *(undefined1 *)(iVar1 + -0x22) = 1;
      *(undefined1 *)(iVar2 + 0x15) = 1;
    }
    FUN_01011a7a();
    FUN_01011996();
  }
  else {
    *(bool *)(DAT_010118c8 + -0x15) = (char)local_28 != '\0';
    *(char *)(iVar1 + -0x2c) = local_28._1_1_;
    *(char *)(iVar1 + -0x2b) = local_28._2_1_;
    *DAT_010118d0 = local_28._3_1_;
    *(undefined2 *)(DAT_010118d4 + 10) = (undefined2)local_24;
    bVar3 = local_24._2_1_;
    if (local_1c != 0) {
      bVar3 = 1;
    }
    *(byte *)(iVar2 + 0x18) = bVar3;
    *(bool *)(iVar2 + 0x1a) = local_24._3_1_ != '\0';
    *(undefined1 *)(iVar2 + 0xc) = (undefined1)local_20;
    *(undefined1 *)(iVar1 + -0x22) = local_20._1_1_;
    if (*(char *)(iVar1 + -0x2c) == '\x06') {
      *(undefined1 *)(iVar1 + -0x2c) = 0xff;
      *(undefined1 *)(iVar1 + -0x2b) = 6;
    }
    else {
      if ((int)((uint)*(ushort *)(DAT_010118d8 + 0x1c) << 0x19) < 0) {
        if (*(char *)(iVar1 + -0x22) == '\x01') {
          *(undefined1 *)(iVar2 + 0x15) = 1;
        }
        else if (*(char *)(iVar1 + -0x22) == '\x02') {
          *(undefined1 *)(iVar2 + 0x15) = 2;
        }
        else {
          *(undefined1 *)(iVar1 + -0x22) = 0;
        }
        if ((local_20 & 0xff) == 0) {
          *(undefined1 *)(iVar2 + 0x16) = 1;
        }
      }
      else if ((int)((uint)*(ushort *)(DAT_010118d8 + 0x1c) << 0x18) < 0) {
        *(undefined1 *)(iVar1 + -0x22) = 2;
        *(undefined1 *)(iVar2 + 0x15) = 2;
      }
      else {
        *(undefined1 *)(iVar1 + -0x22) = 1;
        *(undefined1 *)(iVar2 + 0x15) = 1;
      }
      FUN_0101e318(1,0);
    }
  }
  return;
}


// ===== FUN_01011894 @ 01011894

void FUN_01011894(void)

{
  undefined1 uVar1;
  int extraout_r1;
  
  *(undefined1 *)(DAT_010118c8 + -0x2c) = 0xff;
  uVar1 = FUN_01010f94();
  *(undefined1 *)(extraout_r1 + 0xd) = uVar1;
  return;
}


// ===== FUN_010118a6 @ 010118a6

void FUN_010118a6(void)

{
  byte bVar1;
  
  bVar1 = DAT_010118dc[(uint)*DAT_010118dc * 2 + 10] & 0xf9;
  if (-1 < *(short *)(DAT_010118d8 + 0x1c)) {
    bVar1 = bVar1 + 2;
  }
  DAT_010118dc[(uint)*DAT_010118dc * 2 + 10] = bVar1;
  return;
}


// ===== FUN_010118e0 @ 010118e0

void FUN_010118e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_01011b9c;
  iVar1 = DAT_01011b98;
  if (*(char *)(DAT_01011b98 + 3) != '\0') {
    *(undefined1 *)(DAT_01011b98 + 3) = 0;
    FUN_0101f1de(DAT_01011ba0,0x2a0,param_3,param_4,param_2,param_3,param_4);
    FUN_0101abd8(*DAT_01011ba8,*(undefined2 *)(DAT_01011ba4 + 4),0);
    *(undefined1 *)((uint)*DAT_01011ba8 * 0x10 + DAT_01011bac + 2) = 0x3e;
    FUN_01017860();
    thunk_EXT_FUN_0000425c(100);
    FUN_0101071c();
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_010184cc(5);
    *pbVar2 = *pbVar2 | 3;
    *(undefined1 *)(iVar1 + 9) = 0;
  }
  if (*(char *)(DAT_01011b98 + -0x11) != '\0') {
    *(undefined1 *)(DAT_01011b98 + -0x11) = 0;
    FUN_01017a78();
    FUN_010178e4();
    FUN_0101795c();
    if (*(char *)(iVar1 + 10) != '\0') {
      FUN_0101c420();
      thunk_EXT_FUN_0000425c(500);
      *(undefined1 *)(iVar1 + 10) = 0;
      FUN_010184fc(1);
      *pbVar2 = *pbVar2 | 3;
    }
    if (*(char *)(iVar1 + 9) != '\0') {
      FUN_01016926(0,0,100,0xff,0xff,0xff,1);
      FUN_010170dc();
    }
  }
  return;
}


// ===== FUN_01011996 @ 01011996

void FUN_01011996(void)

{
  int iVar1;
  int iVar2;
  
  FUN_01011f48();
  iVar1 = DAT_01011b98;
  iVar2 = 0;
  do {
    if (*(char *)(DAT_01011bb0 + 0x2a) != -0x22) {
      return;
    }
    while( true ) {
      iVar2 = iVar2 + 1;
      if (0x10 < iVar2) {
        *(undefined1 *)(DAT_01011b98 + -0x13) = 0xfd;
        *(undefined1 *)(iVar1 + -0x14) = 0xff;
        return;
      }
      if (iVar2 == 0) break;
      if (*(char *)(DAT_01011bb0 + iVar2 + 0x2a) != -1) {
        return;
      }
    }
  } while( true );
}


// ===== FUN_010119d0 @ 010119d0

void FUN_010119d0(void)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  
  iVar2 = DAT_01011bb4;
  iVar1 = DAT_01011b98;
  uVar4 = 0;
  do {
    iVar6 = DAT_01011bb0 + uVar4;
    if (*(char *)(iVar6 + 0x54) != '\0') {
      uVar5 = 0;
      do {
        pbVar3 = DAT_01011bb8;
        if ((*(byte *)(iVar6 + 0x54) >> uVar5 & 1) != 0) {
          *DAT_01011bb8 = *DAT_01011bb8 & 0xfb;
          if ((~(*(byte *)(iVar6 + 0x2a) >> uVar5) & 1) != 0) {
            *DAT_01011bb8 = *pbVar3 | 4;
          }
          if (((int)((uint)*DAT_01011bb8 << 0x1d) < 0) && (uVar5 == 1)) {
            if (uVar4 == 1) {
              uVar7 = 3;
            }
            else if (uVar4 == 2) {
              uVar7 = 4;
            }
            else if (uVar4 == 3) {
              uVar7 = 5;
            }
            else if (uVar4 == 7) {
              uVar7 = 0;
            }
            else if (uVar4 == 8) {
              uVar7 = 1;
            }
            else {
              if (uVar4 != 9) goto LAB_01011a5a;
              uVar7 = 2;
            }
            *(undefined1 *)(iVar1 + -0xc) = uVar7;
            *(byte *)(iVar2 + 1) = *(byte *)(iVar2 + 1) | 0x20;
          }
LAB_01011a5a:
          *(byte *)(iVar6 + 0x54) = *(byte *)(iVar6 + 0x54) & ~(byte)(1 << uVar5);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 6);
    }
    uVar4 = uVar4 + 1 & 0xff;
    if (0x10 < uVar4) {
      return;
    }
  } while( true );
}


// ===== FUN_01011a7a @ 01011a7a

void FUN_01011a7a(void)

{
  int iVar1;
  int iVar2;
  
  FUN_01011f48();
  iVar1 = DAT_01011b98;
  iVar2 = 0;
  do {
    if (*(char *)(DAT_01011bb0 + 0x2a) != -0x21) {
      return;
    }
    while( true ) {
      iVar2 = iVar2 + 1;
      if (0x10 < iVar2) {
        *(undefined1 *)(DAT_01011b98 + -0x13) = 0xfe;
        *(undefined1 *)(iVar1 + -0x14) = 0xff;
        return;
      }
      if (iVar2 == 0) break;
      if (*(char *)(DAT_01011bb0 + iVar2 + 0x2a) != -1) {
        return;
      }
    }
  } while( true );
}


// ===== FUN_01011ab4 @ 01011ab4

void FUN_01011ab4(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_01011b98;
  if (*(char *)(DAT_01011b98 + -0x10) != '\x02') {
    return;
  }
  *(undefined1 *)(DAT_01011b98 + -0x10) = 0;
  *(int *)(iVar1 + -0x1c) = *(int *)(iVar1 + -0x1c) + 1;
  iVar4 = DAT_01011bc0;
  pcVar2 = DAT_01011bbc;
  if (*(int *)(iVar1 + -0x1c) == 1) {
    *(undefined1 *)(DAT_01011bc0 + 9) = 0xff;
LAB_01011b1c:
    *(undefined1 *)(iVar4 + 10) = 0;
LAB_01011ae6:
    *(undefined1 *)(iVar4 + 0xb) = 0;
  }
  else {
    if (*(int *)(DAT_01011bc0 + 4) == 1000) {
      *(undefined1 *)(DAT_01011bc0 + 9) = 0;
      *(undefined1 *)(iVar4 + 10) = 0xff;
      goto LAB_01011ae6;
    }
    if (*(int *)(DAT_01011bc0 + 4) == 2000) {
      *(undefined1 *)(DAT_01011bc0 + 9) = 0;
      *(undefined1 *)(iVar4 + 10) = 0;
    }
    else {
      if (*(int *)(DAT_01011bc0 + 4) != DAT_01011bc4) {
        if (*(int *)(DAT_01011bc0 + 4) != 4000) {
          if (*(int *)(DAT_01011bc0 + 4) == DAT_01011bc8) {
            FUN_0101e1de();
          }
          if (*pcVar2 == '\0') {
            return;
          }
          goto LAB_01011b32;
        }
        *(undefined1 *)(DAT_01011bc0 + 9) = 0;
        goto LAB_01011b1c;
      }
      *(undefined1 *)(DAT_01011bc0 + 9) = 0xff;
      *(undefined1 *)(iVar4 + 10) = 0xff;
    }
    *(undefined1 *)(iVar4 + 0xb) = 0xff;
  }
  *pcVar2 = '\x01';
LAB_01011b32:
  iVar1 = DAT_01011bcc;
  *pcVar2 = '\0';
  *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 4;
  FUN_01016926(5,7,100,0xff,0xff,0xff,1);
  *(undefined1 *)((uint)*DAT_01011ba8 * 0x10 + DAT_01011bac + 7) = 0x3f;
  iVar1 = DAT_01011bc0;
  iVar4 = 0;
  do {
    iVar3 = 0;
    iVar5 = iVar4 * 0x10 + DAT_01011bd0;
    do {
      FUN_01016926(*(undefined1 *)(iVar5 + iVar3 * 2),*(undefined1 *)(iVar5 + iVar3 * 2 + 1),100,
                   *(undefined1 *)(iVar1 + 9),*(undefined1 *)(iVar1 + 10),
                   *(undefined1 *)(iVar1 + 0xb),1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x15);
  FUN_010170dc();
  return;
}


// ===== FUN_01011cb6 @ 01011cb6

void FUN_01011cb6(void)

{
  if (*(char *)(DAT_01011ecc + 0x1c) != '\0') {
    *(undefined1 *)(DAT_01011ed0 + 5) = 0;
    FUN_0101c420();
    thunk_EXT_FUN_0000425c(10);
    FUN_0101c036(0);
    FUN_0101385c();
    FUN_01010418(0x60);
    FUN_0101be90(DAT_01011edc);
    FUN_01010444();
  }
  return;
}


// ===== FUN_01011cec @ 01011cec

void FUN_01011cec(void)

{
  if ((*(char *)(DAT_01011ecc + 0x1c) != '\0') && (*(char *)(DAT_01011ed0 + 5) != '\0')) {
    *(undefined1 *)(DAT_01011ed0 + 5) = 0;
    FUN_0101c420();
    thunk_EXT_FUN_0000425c(10);
    FUN_0101c036(0);
    FUN_0101385c();
    thunk_EXT_FUN_0000425c(3);
    FUN_01010418(0x60);
    FUN_0101be90(DAT_01011edc);
    FUN_01010444();
    *DAT_01011ed8 = *DAT_01011ed8 & 0xfd | 1;
    FUN_01014bc4();
    FUN_0101e318(1,0);
  }
  return;
}


// ===== FUN_01011d48 @ 01011d48

void FUN_01011d48(void)

{
  if (((*(char *)(DAT_01011ecc + 0x1c) != '\0') && (*DAT_01011ee0 == '\x04')) &&
     (*(byte *)(DAT_01011ed0 + -0x14) < 6)) {
    if (*(char *)(DAT_01011ed0 + 5) == '\0') {
      *(undefined1 *)(DAT_01011ed0 + 5) = 1;
      FUN_0101c420();
      FUN_0101e1d2(0xe);
      FUN_0101b686(1,0);
      FUN_0101394a();
      thunk_EXT_FUN_0000425c(5);
      FUN_0101c036(0xe);
      thunk_EXT_FUN_0000425c(1);
      FUN_01010418(0xc);
      FUN_0101be90(DAT_01011ec8);
      *DAT_01011ed8 = *DAT_01011ed8 & 0xfd | 1;
      FUN_01014bc4();
      FUN_0101e318(1,0);
    }
  }
  return;
}


// ===== FUN_01011dbe @ 01011dbe

void FUN_01011dbe(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_01011ef0;
  iVar3 = DAT_01011eec;
  pcVar2 = DAT_01011ee8;
  iVar1 = DAT_01011ee4;
  if (((((int)((uint)*(ushort *)(DAT_01011ee4 + 0x1c) * 0x2000000) < 0) &&
       (*(char *)(DAT_01011ef0 + 0x18) == '\0')) && (*(char *)(DAT_01011ef0 + 0x1a) == '\0')) &&
     ((*DAT_01011ee8 == '\0' && (*(char *)(DAT_01011eec + 2) == '\0')))) {
    FUN_01011d48();
  }
  if (((-1 < (int)((uint)*(ushort *)(iVar1 + 0x1c) << 0x19)) || (*(char *)(iVar4 + 0x18) != '\0'))
     || ((*(char *)(iVar4 + 0x1a) != '\0' || ((*pcVar2 != '\0' || (*(char *)(iVar3 + 2) != '\0')))))
     ) {
    FUN_01011cec();
  }
  return;
}


// ===== FUN_01011ef8 @ 01011ef8

void FUN_01011ef8(void)

{
  return;
}


// ===== FUN_01011efc @ 01011efc

void FUN_01011efc(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_010122e0;
  *(undefined4 *)(DAT_010122e0 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  puVar1 = DAT_010122e4;
  *DAT_010122e4 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined1 *)(iVar2 + 3) = 0;
  *(undefined1 *)(iVar2 + 4) = 0;
  FUN_0101f1de(iVar2 + 5,3);
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined1 *)(DAT_010122e4 + 5) = 0;
  puVar1 = DAT_010122e4;
  iVar2 = 0;
  do {
    *(undefined1 *)((int)puVar1 + iVar2 + 0x6f) = 0xff;
    *(undefined1 *)((int)puVar1 + iVar2 + 0x5a) = 0xff;
    *(undefined1 *)((int)puVar1 + iVar2 + 0x84) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x15);
  return;
}


// ===== FUN_01011f48 @ 01011f48

void FUN_01011f48(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar5 = DAT_010122e8;
  *(undefined1 *)(DAT_010122e8 + 7) = 1;
  iVar9 = DAT_010122f4;
  iVar6 = DAT_010122f0;
  iVar1 = DAT_010122ec;
  if (*(char *)(iVar5 + 7) != '\0') {
    iVar5 = 0;
    do {
      *(undefined1 *)
       ((uint)*(byte *)(iVar1 + iVar5) +
       (uint)*(byte *)(iVar6 + (uint)*(byte *)(DAT_010122f8 + iVar5)) * 0x10 + iVar9) = 0x40;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
    iVar5 = 0;
    do {
      *(undefined1 *)
       ((uint)*(byte *)(DAT_010122fc + iVar5) +
       (uint)*(byte *)(iVar6 + (uint)*(byte *)(DAT_01012300 + iVar5)) * 0x10 + iVar9) = 0x3f;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x11);
    thunk_EXT_FUN_00004238(1);
    uVar10 = 0;
    do {
      iVar1 = DAT_010122f8;
      iVar5 = DAT_010122ec;
      iVar6 = 0;
      do {
        *(undefined1 *)
         ((uint)*(byte *)(iVar5 + iVar6) +
         (uint)*(byte *)(DAT_010122f0 + (uint)*(byte *)(iVar1 + iVar6)) * 0x10 + DAT_010122f4) =
             0x40;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 6);
      *(undefined1 *)
       ((uint)*(byte *)(DAT_010122fc + uVar10) +
       (uint)*(byte *)(DAT_010122f0 + (uint)*(byte *)(DAT_01012300 + uVar10)) * 0x10 + DAT_010122f4)
           = 0x3e;
      thunk_EXT_FUN_00004238(1);
      uVar7 = (*(ushort *)(DAT_010122f4 + 0x3e) & 7) >> 2 | *(ushort *)(DAT_010122f4 + 0x3e) & 2 |
              (*(ushort *)(DAT_010122f4 + 0x3e) & 1) << 2 |
              ((*(ushort *)(DAT_010122f4 + 0x3c) & 0x3fff) >> 0xd) << 3 |
              ((*(ushort *)(DAT_010122f4 + 0x3c) & 0x1fff) >> 0xc) << 4 |
              ((*(ushort *)(DAT_010122f4 + 0x3c) & 0xfff) >> 0xb) << 5 | 0xc0;
      *(undefined1 *)
       ((uint)*(byte *)(DAT_010122fc + uVar10) +
       (uint)*(byte *)(DAT_010122f0 + (uint)*(byte *)(DAT_01012300 + uVar10)) * 0x10 + DAT_010122f4)
           = 0x3f;
      iVar1 = DAT_010122f4;
      iVar5 = DAT_010122f0;
      iVar6 = 0;
      do {
        *(undefined1 *)
         ((uint)*(byte *)(DAT_010122ec + iVar6) +
         (uint)*(byte *)(iVar5 + (uint)*(byte *)(DAT_010122f8 + iVar6)) * 0x10 + iVar1) = 0x3f;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 6);
      iVar6 = DAT_010122e4 + 0x30;
      iVar9 = iVar6 + uVar10;
      if (*(byte *)(iVar9 + 0x2a) == uVar7) {
        cVar4 = *(char *)(iVar6 + uVar10) + -1;
        *(char *)(iVar6 + uVar10) = cVar4;
        if ((cVar4 == '\0') && (*(char *)(iVar9 + 0x2a) != *(char *)(iVar9 + 0x3f))) {
          *(byte *)(iVar9 + 0x54) = *(byte *)(iVar9 + 0x2a) ^ *(byte *)(iVar9 + 0x3f);
          *(undefined1 *)(iVar9 + 0x3f) = *(undefined1 *)(iVar9 + 0x2a);
        }
      }
      else {
        *(char *)(iVar9 + 0x2a) = (char)uVar7;
        *(undefined1 *)(iVar6 + uVar10) = *(undefined1 *)(DAT_01012304 + 0x1b);
      }
      iVar9 = DAT_010122f8;
      iVar6 = DAT_010122ec;
      uVar10 = uVar10 + 1 & 0xff;
    } while (uVar10 < 0x11);
    iVar8 = 0;
    do {
      *(undefined1 *)
       ((uint)*(byte *)(iVar6 + iVar8) +
       (uint)*(byte *)(iVar5 + (uint)*(byte *)(iVar9 + iVar8)) * 0x10 + iVar1) = 0x3e;
      iVar3 = DAT_01012300;
      iVar2 = DAT_010122fc;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 6);
    iVar6 = 0;
    do {
      *(undefined1 *)
       ((uint)*(byte *)(iVar2 + iVar6) +
       (uint)*(byte *)(iVar5 + (uint)*(byte *)(iVar3 + iVar6)) * 0x10 + iVar1) = 0x3e;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x11);
  }
  return;
}


// ===== FUN_010120dc @ 010120dc

void FUN_010120dc(uint param_1)

{
  byte *pbVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  puVar2 = DAT_010122e4;
  pbVar1 = DAT_010122e0;
  if (param_1 - 0xe0 < 8) {
    DAT_010122e0[0xc] = DAT_010122e0[0xc] | (byte)(1 << (param_1 & 0xf));
  }
  else {
    if (param_1 < 4) {
      return;
    }
    if (5 < (byte)DAT_010122e4[0x14]) {
      if (*DAT_01012308 != '\0') {
        return;
      }
      DAT_010122e4[(param_1 >> 3) + 1] =
           DAT_010122e4[(param_1 >> 3) + 1] | (byte)(1 << (param_1 & 7));
      *puVar2 = 1;
      bVar3 = *pbVar1 | 0x20;
      goto LAB_01012144;
    }
    DAT_010122e0[(byte)DAT_010122e4[0x14] + 0xe] = (byte)param_1;
    puVar2[0x14] = puVar2[0x14] + '\x01';
  }
  bVar3 = *pbVar1 | 0x10;
LAB_01012144:
  *pbVar1 = bVar3;
  return;
}


// ===== FUN_01012148 @ 01012148

void FUN_01012148(uint param_1)

{
  byte *pbVar1;
  undefined1 *puVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  
  puVar2 = DAT_010122e4;
  pbVar1 = DAT_010122e0;
  pbVar5 = DAT_010122e0 + 0xc;
  if (param_1 - 0xe0 < 8) {
    *pbVar5 = *pbVar5 & ~(byte)(1 << (param_1 & 0xf));
LAB_0101219e:
    bVar3 = *pbVar1 | 0x10;
  }
  else {
    if (param_1 < 4) {
      return;
    }
    iVar4 = 0;
LAB_010121a6:
    if (iVar4 < (int)(uint)(byte)DAT_010122e4[0x14]) {
      if (pbVar5[iVar4 + 2] != param_1) goto LAB_010121a4;
      DAT_010122e4[0x14] = DAT_010122e4[0x14] + -1;
      for (; iVar4 < (int)(uint)(byte)puVar2[0x14]; iVar4 = iVar4 + 1) {
        pbVar5[iVar4 + 2] = pbVar5[iVar4 + 3];
      }
      DAT_010122e0[(byte)puVar2[0x14] + 0xe] = 0;
      goto LAB_0101219e;
    }
    if (*DAT_01012308 != '\0') {
      return;
    }
    DAT_010122e4[(param_1 >> 3) + 1] =
         DAT_010122e4[(param_1 >> 3) + 1] & ~(byte)(1 << (param_1 & 7));
    *puVar2 = 1;
    bVar3 = *pbVar1 | 0x20;
  }
  *pbVar1 = bVar3;
  return;
LAB_010121a4:
  iVar4 = iVar4 + 1;
  goto LAB_010121a6;
}


// ===== FUN_01012232 @ 01012232

void FUN_01012232(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_010122e4 + 0x9c);
  if (param_2 == 0) {
    uVar1 = uVar1 & ~param_1;
  }
  else {
    uVar1 = uVar1 | param_1;
  }
  *(uint *)(DAT_010122e4 + 0x9c) = uVar1;
  return;
}


// ===== FUN_01012246 @ 01012246
// decompile failed
// ===== FUN_0101233e @ 0101233e

void FUN_0101233e(byte param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  
  pbVar1 = DAT_01012730;
  if (((*(char *)(DAT_01012724 + 0xc) == '\x06') && ((int)((uint)*DAT_01012728 << 0x1e) < 0)) ||
     ((*(char *)(DAT_01012724 + 0xc) != '\x06' && (*DAT_0101272c == '\x04')))) {
    *DAT_01012730 = *DAT_01012730 | 8;
    pbVar1[8] = 5;
    pbVar1[9] = param_1;
    pbVar1[10] = param_2;
    pbVar1[0xb] = param_3;
  }
  return;
}


// ===== FUN_01012bee @ 01012bee
// decompile failed
// ===== FUN_01012c98 @ 01012c98
// decompile failed
// ===== FUN_01012d10 @ 01012d10

undefined4 FUN_01012d10(int param_1)

{
  if ((((DAT_01012f84[(uint)*DAT_01012f84 * 2 + 10] & 1) == 0) ||
      ((DAT_01012f84[(uint)*DAT_01012f84 * 2 + 10] & 7) >> 1 == 1)) ||
     ((param_1 != 0xe30000 && ((param_1 != 0xe70000 && (param_1 != 0x650000)))))) {
    return 1;
  }
  return 0;
}


// ===== FUN_01012d46 @ 01012d46

undefined1 FUN_01012d46(uint param_1)

{
  char local_b;
  char local_a;
  
  if ((*(char *)(DAT_01012f88 + 6) == '\0') || (*(char *)(DAT_01012f84 + 0x1a) != '\r')) {
    return 1;
  }
  local_b = (char)(param_1 >> 8);
  if ((param_1 & 0xff) == 0xd) {
    if ((local_b == '\x06') && (local_a = (char)(param_1 >> 0x10), local_a == -0x80)) {
      return 1;
    }
  }
  else if (((param_1 & 0xff) == 10) && (local_b == '\x01')) {
    return 1;
  }
  return 0;
}


// ===== FUN_01012d82 @ 01012d82

void FUN_01012d82(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  
  iVar1 = DAT_01012f80;
  bVar3 = *(byte *)(DAT_01012f80 + -3);
  if (param_1 == 1) {
    if (param_2 == 0) {
      if (param_3 == 0) {
        *(byte *)(DAT_01012f80 + -3) = bVar3 & 0xfe;
        goto LAB_01012dd2;
      }
      bVar2 = 1;
    }
    else {
      if (param_2 != 0xd) goto LAB_01012dd2;
      if (param_3 == 0) {
        bVar2 = 0xfd;
        goto LAB_01012df0;
      }
      bVar2 = 2;
    }
    goto LAB_01012dea;
  }
  if (param_1 != 5) goto LAB_01012dd2;
  if (param_2 == 0) {
    if (param_3 != 0) {
      bVar2 = 4;
      goto LAB_01012dea;
    }
    bVar2 = 0xfb;
LAB_01012df0:
    bVar3 = bVar3 & bVar2;
  }
  else {
    if (param_2 != 0xe) goto LAB_01012dd2;
    if (param_3 == 0) {
      bVar2 = 0xf7;
      goto LAB_01012df0;
    }
    bVar2 = 8;
LAB_01012dea:
    bVar3 = bVar3 | bVar2;
  }
  *(byte *)(DAT_01012f80 + -3) = bVar3;
LAB_01012dd2:
  FUN_01012232(0x10,(~*(byte *)(iVar1 + -3) & 0xf) == 0);
  return;
}


// ===== FUN_01012df8 @ 01012df8

int FUN_01012df8(int param_1,int param_2,int param_3)

{
  if (-1 < (int)((uint)DAT_01012f84[(uint)*DAT_01012f84 * 2 + 10] << 0x1c)) {
    return param_3;
  }
  if (param_1 == 2) {
    if (param_2 != 2) {
      return param_3;
    }
    if (param_3 == 0x1a0000) {
      return 0x520000;
    }
    return param_3;
  }
  if (param_1 == 4) {
    if (param_2 != 0xd) {
      return param_3;
    }
    if (param_3 == 0x520000) {
      return 0x1a0000;
    }
    return param_3;
  }
  if (param_1 == 5) {
    if (param_2 == 0xc) {
      if (param_3 == 0x500000) {
        return 0x40000;
      }
      return param_3;
    }
LAB_01012e70:
    if (param_2 == 0xd) {
      if (param_3 == 0x510000) {
        return 0x160000;
      }
      return param_3;
    }
LAB_01012e74:
    if ((param_2 == 0xe) && (param_3 == 0x4f0000)) {
      return 0x70000;
    }
    return param_3;
  }
  if (param_1 == 3) {
    if (param_2 == 1) {
      if (param_3 == 0x40000) {
        return 0x500000;
      }
      return param_3;
    }
  }
  else {
    if (param_1 == 5) goto LAB_01012e70;
    if (param_1 != 3) {
      if (param_1 == 5) goto LAB_01012e74;
      if (param_1 != 3) {
        return param_3;
      }
      goto LAB_01012e48;
    }
  }
  if (param_2 == 2) {
    if (param_3 == 0x160000) {
      return 0x510000;
    }
    return param_3;
  }
LAB_01012e48:
  if ((param_2 == 3) && (param_3 == 0x70000)) {
    param_3 = 0x4f0000;
  }
  return param_3;
}


// ===== FUN_01012ea8 @ 01012ea8

int FUN_01012ea8(int param_1,int param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (DAT_01012f84[(uint)*DAT_01012f84 * 2 + 10] & 7) >> 1;
  bVar1 = DAT_01012f84[(uint)*DAT_01012f84 * 2 + 0xb];
  iVar2 = uVar4 * 0x400 + DAT_01012f8c + (bVar1 & 1) * 0x200 + param_3 * 0x18;
  iVar5 = *(int *)(iVar2 + param_2 * 4);
  if (iVar5 != 0) {
    uVar3 = 1 << (param_3 & 0xff);
    if (param_4 == 0) {
      if ((*(uint *)(DAT_01012f90 + param_2 * 4 + 8) & uVar3) == 0) {
        return param_1;
      }
      uVar3 = *(uint *)(DAT_01012f90 + param_2 * 4 + 8) & ~uVar3;
    }
    else {
      if (-1 < (int)((uint)*DAT_01012f90 << 0x1e)) {
        return param_1;
      }
      uVar3 = *(uint *)(DAT_01012f90 + param_2 * 4 + 8) | uVar3;
    }
    *(uint *)(DAT_01012f90 + param_2 * 4 + 8) = uVar3;
    if ((((uVar4 != 1) || (param_2 != 1)) || (param_3 == 0)) || (0xc < param_3)) {
      return iVar5;
    }
    if ((int)((uint)bVar1 << 0x1e) < 0) {
      return *(int *)(DAT_01012f80 + 0x17 + param_3 * 4);
    }
    param_1 = *(int *)(iVar2 + 4);
  }
  return param_1;
}


// ===== FUN_01012f32 @ 01012f32

int FUN_01012f32(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((DAT_01012f84[(uint)*DAT_01012f84 * 2 + 10] & 7) >> 1 == 1) && (param_1 != 1)) &&
     (param_1 == 5)) {
    if (param_2 == 2) {
      iVar1 = 0xe20000;
      if (param_3 != 0xe30000) {
        return param_3;
      }
    }
    else {
      if (param_2 == 3) {
        if (param_3 == 0xe20000) {
          param_3 = 0xe30000;
        }
        return param_3;
      }
      if (param_2 == 8) {
        if (param_3 == 0xe60000) {
          return 0xe70000;
        }
        return param_3;
      }
      if (param_2 != 9) {
        return param_3;
      }
      iVar1 = 0xe60000;
      if (param_3 != 0x650000) {
        return param_3;
      }
    }
    param_3 = iVar1;
  }
  return param_3;
}


// ===== FUN_01012fa6 @ 01012fa6

void FUN_01012fa6(void)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 extraout_r12;
  undefined4 extraout_r12_00;
  undefined4 extraout_r12_01;
  
  pbVar1 = DAT_010133a0;
  if (*(char *)(DAT_0101339c + 0x1a) == '\0') {
    uVar8 = 0;
    do {
      pbVar2 = DAT_010133a0;
      if (DAT_010133a0[uVar8 + 0x74] != 0) {
        uVar7 = 0;
        do {
          if ((pbVar2[uVar8 + 0x74] >> uVar7 & 1) != 0) {
            *pbVar1 = *pbVar1 & 0xfb;
            if ((~(pbVar2[uVar8 + 0x4a] >> uVar7) & 1) != 0) {
              *pbVar1 = *pbVar1 | 4;
            }
            FUN_01016c70(uVar7,uVar8,(*pbVar1 & 7) >> 2);
            FUN_01017992((*pbVar1 & 7) >> 2);
            uVar3 = (uint)*DAT_010133a4;
            if ((int)((uint)DAT_010133a4[uVar3 * 2 + 10] << 0x19) < 0) {
              iVar6 = uVar8 * 0x18;
              iVar5 = DAT_010133ac;
            }
            else {
              iVar6 = uVar3 * 0x200 + DAT_010133a8;
              iVar5 = uVar8 * 0x18;
            }
            if ((*(byte *)(uVar3 * 0x14 + DAT_010133b0 + uVar8) >> uVar7 & 1) != 0) {
              uVar4 = FUN_01012f32(uVar7,uVar8,*(undefined4 *)(iVar6 + iVar5 + uVar7 * 4));
              uVar4 = FUN_01012ea8(uVar4,uVar7,uVar8,(*pbVar1 & 7) >> 2);
              FUN_01012df8(uVar7,uVar8,uVar4);
              FUN_01012d82(uVar7,uVar8,(*pbVar1 & 7) >> 2);
              iVar5 = FUN_01012d46(extraout_r12,(*pbVar1 & 7) >> 2);
              if ((iVar5 != 0) && (iVar5 = FUN_01012d10(extraout_r12_00), iVar5 != 0)) {
                FUN_01012c98(extraout_r12_01,(*pbVar1 & 7) >> 2);
              }
            }
            pbVar2[uVar8 + 0x74] = pbVar2[uVar8 + 0x74] & ~(byte)(1 << uVar7);
          }
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 6);
      }
      uVar8 = uVar8 + 1 & 0xff;
    } while (uVar8 < 0x11);
  }
  return;
}


// ===== FUN_010130d0 @ 010130d0

void FUN_010130d0(void)

{
  uint *puVar1;
  undefined1 uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_010133b8;
  if (*(char *)((int)DAT_010133b8 + 0xd) != '\0') {
    puVar1 = DAT_010133b8 + 1;
    uVar2 = *(undefined1 *)((int)DAT_010133b8 + 9);
    if (*puVar1 < 300) {
      uVar4 = *DAT_010133b8;
      *DAT_010133b8 = uVar4 + 1;
      if (300 - *puVar1 <= uVar4 + 1) {
        *puVar3 = 0;
        FUN_01012148(uVar2);
        *(undefined1 *)((int)puVar3 + 0xd) = 0;
        *(undefined1 *)(puVar3 + 3) = 1;
        return;
      }
    }
    else {
      FUN_01012148(uVar2);
      FUN_01012148((char)puVar3[2]);
      *(undefined1 *)((int)puVar3 + 0xd) = 0;
      *(undefined1 *)((int)puVar3 + 0xf) = 0;
      *(undefined1 *)((int)puVar3 + 0xe) = 0;
      puVar3[1] = 0;
    }
  }
  if (((char)puVar3[3] == '\0') || (uVar4 = *puVar3, *puVar3 = uVar4 + 1, uVar4 + 1 < 10)) {
    return;
  }
  *puVar3 = 0;
  FUN_01012148((char)puVar3[2]);
  *(undefined1 *)(puVar3 + 3) = 0;
  *(undefined1 *)((int)puVar3 + 0xe) = 0;
  *(undefined1 *)((int)puVar3 + 0xf) = 0;
  return;
}


// ===== FUN_010131dc @ 010131dc

void FUN_010131dc(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  undefined1 *puVar5;
  
  pbVar1 = DAT_010133bc;
  bVar2 = (byte)((uint)param_1 >> 8);
  uVar3 = (uint)bVar2;
  if (param_2 == 0) {
    if (uVar3 - 0xe0 < 8) {
      bVar2 = (byte)(1 << (uVar3 & 0xf));
      DAT_010133bc[0xc] = DAT_010133bc[0xc] & ~bVar2;
      *(byte *)(DAT_010133c0 + 0x10) = *(byte *)(DAT_010133c0 + 0x10) & ~bVar2;
      bVar2 = *pbVar1;
      bVar4 = 0x10;
    }
    else {
      if (uVar3 < 4) {
        return;
      }
      puVar5 = (undefined1 *)(DAT_010133a0 + -0x10);
      puVar5[(bVar2 >> 3) + 1] = puVar5[(bVar2 >> 3) + 1] & ~(byte)(1 << (uVar3 & 7));
      *puVar5 = 1;
      bVar2 = *pbVar1;
      bVar4 = 0x20;
    }
    *pbVar1 = bVar2 | bVar4;
    return;
  }
  if (uVar3 - 0xe0 < 8) {
    bVar2 = (byte)(1 << (uVar3 & 0xf));
    DAT_010133bc[0xc] = DAT_010133bc[0xc] | bVar2;
    *(byte *)(DAT_010133c0 + 0x10) = *(byte *)(DAT_010133c0 + 0x10) | bVar2;
    bVar2 = *pbVar1;
    bVar4 = 0x10;
  }
  else {
    if (uVar3 < 4) {
      return;
    }
    puVar5 = (undefined1 *)(DAT_010133a0 + -0x10);
    puVar5[(bVar2 >> 3) + 1] = puVar5[(bVar2 >> 3) + 1] | (byte)(1 << (uVar3 & 7));
    *puVar5 = 1;
    bVar2 = *pbVar1;
    bVar4 = 0x20;
  }
  *pbVar1 = bVar2 | bVar4;
  return;
}


// ===== FUN_010131ee @ 010131ee

void FUN_010131ee(int param_1,byte param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = DAT_010133bc;
  pbVar2 = DAT_010133bc + 0x14;
  if (param_1 * 0x1000000 < 0) {
    DAT_010133bc[0x17] = 0xff;
  }
  pbVar1[0x16] = (byte)param_1;
  if ((int)((uint)param_2 << 0x18) < 0) {
    pbVar1[0x19] = 0xff;
  }
  pbVar1[0x18] = param_2;
  *pbVar2 = 6;
  *DAT_010133bc = *DAT_010133bc | 1;
  return;
}


// ===== FUN_01013218 @ 01013218
// decompile failed
// ===== FUN_01013310 @ 01013310
// decompile failed
// ===== FUN_01013422 @ 01013422

void FUN_01013422(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_010134d0;
  iVar2 = DAT_010134c4;
  iVar3 = (uint)*DAT_010134c8 * 0x200 + DAT_010134cc;
  if (*(char *)(DAT_010134c4 + 8) == '\0') {
    if (*(char *)(DAT_010134c4 + 10) == '\0') {
      cVar1 = *(char *)(DAT_010134d4 + 1);
      if (cVar1 == '\0') {
        return;
      }
      *(char *)(DAT_010134d4 + 1) = cVar1 + -1;
      if (cVar1 != '\x01') {
        return;
      }
      iVar4 = param_4;
      if (*(char *)(iVar2 + 9) != '\0') {
        iVar4 = 0;
        param_3 = 0x11;
        *(undefined1 *)(iVar2 + 9) = 0;
      }
      if (*(char *)(iVar2 + 0xb) != '\0') {
        iVar4 = 1;
        param_3 = 0x11;
        *(undefined1 *)(iVar2 + 0xb) = 0;
      }
      FUN_01012c98(*(undefined4 *)(iVar3 + param_3 * 0x18 + iVar4 * 4),0,param_3 * 0x18,iVar4,
                   param_4);
      return;
    }
    FUN_01012c98(*(undefined4 *)(iVar3 + 0x19c),1,param_3,param_4,param_4);
    *(undefined1 *)(iVar4 + 0x13) = 2;
    *(char *)(iVar4 + 0x14) = *(char *)(iVar4 + 0x14) + '\x01';
    *(undefined1 *)(iVar2 + 10) = 0;
    *(undefined1 *)(iVar2 + 0xb) = 1;
  }
  else {
    FUN_01012c98(*(undefined4 *)(iVar3 + 0x198),1,param_3,param_4,param_4);
    *(undefined1 *)(iVar4 + 0x13) = 1;
    *(char *)(iVar4 + 0x14) = *(char *)(iVar4 + 0x14) + '\x01';
    *(undefined1 *)(iVar2 + 8) = 0;
    *(undefined1 *)(iVar2 + 9) = 1;
  }
  FUN_0101e318(1,0);
  return;
}


// ===== FUN_010134d8 @ 010134d8

void FUN_010134d8(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  pbVar2 = DAT_01013798;
  bVar5 = 0;
  uVar4 = 1;
  do {
    pbVar1 = (byte *)(DAT_01013794 + uVar4);
    uVar4 = uVar4 + 1;
    bVar5 = bVar5 | *pbVar1;
  } while (uVar4 < 0x10);
  if (bVar5 != 0) {
    FUN_0101f1de(DAT_01013794,0x10);
    *pbVar2 = *pbVar2 | 0x20;
  }
  iVar3 = DAT_0101379c;
  if (*(byte *)(DAT_0101379c + 0x10) != 0) {
    *DAT_010137a0 = *DAT_010137a0 ^ *(byte *)(DAT_0101379c + 0x10);
    *(undefined1 *)(iVar3 + 0x10) = 0;
    *pbVar2 = *pbVar2 | 0x10;
  }
  return;
}


// ===== FUN_0101351e @ 0101351e

void FUN_0101351e(void)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = 0;
  uVar2 = 1;
  do {
    pbVar1 = (byte *)(DAT_010137a4 + uVar2);
    uVar2 = uVar2 + 1;
    bVar3 = bVar3 | *pbVar1;
  } while (uVar2 < 8);
  if (bVar3 != 0) {
    FUN_0101f1de(DAT_010137a4,8);
    *DAT_01013798 = *DAT_01013798 | 1;
  }
  return;
}


// ===== FUN_01013548 @ 01013548

void FUN_01013548(void)

{
  *DAT_010137a8 = 0;
  FUN_0101351e();
  FUN_010134d8();
  return;
}


// ===== FUN_010135bc @ 010135bc

void FUN_010135bc(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 local_18;
  
  if ((*DAT_010137a8 == '\0') ||
     (iVar7 = *(int *)(DAT_0101379c + 4), *(int *)(DAT_0101379c + 4) = iVar7 + -1, iVar7 + -1 != 0))
  {
    return;
  }
LAB_010135d4:
  do {
    pcVar6 = DAT_0101379c;
    bVar4 = false;
    iVar7 = *(int *)(DAT_0101379c + 8);
    bVar5 = false;
    bVar2 = (byte)DAT_010137b0[iVar7 + 1];
    uVar8 = (uint)bVar2;
    bVar1 = *(byte *)((int)DAT_010137b0 + iVar7 * 2 + 3);
    if (bVar2 == 0 && bVar1 == 0) {
      cVar3 = *DAT_0101379c;
      if (cVar3 == '\0') {
        iVar7 = *(int *)(DAT_0101379c + 0xc);
        *(int *)(DAT_0101379c + 0xc) = iVar7 + -1;
        if (iVar7 + -1 == 0) {
          *DAT_010137a8 = '\0';
          return;
        }
        FUN_0101f1ac(DAT_010137b0,(uint)(byte)pcVar6[1] * 0x100 + DAT_010137ac,0x100);
      }
      else {
        if ((cVar3 != '\x01') && (cVar3 != '\x02')) {
          return;
        }
        FUN_0101f1ac(DAT_010137b0,(uint)(byte)DAT_0101379c[1] * 0x100 + DAT_010137ac,0x100);
        *(uint *)(pcVar6 + 0xc) = (uint)*DAT_010137b0;
      }
      pcVar6[8] = '\0';
      pcVar6[9] = '\0';
      pcVar6[10] = '\0';
      pcVar6[0xb] = '\0';
      pcVar6[4] = '\x05';
      pcVar6[5] = '\0';
      pcVar6[6] = '\0';
      pcVar6[7] = '\0';
      return;
    }
    if (uVar8 - 4 < 0xec) {
      local_18 = (uint)bVar2 << 8;
      FUN_010131dc(local_18,bVar1 >> 7);
    }
    else if (uVar8 - 0xf0 < 9) {
      local_18 = (uint)CONCAT12(bVar2,1);
      FUN_01012bee(local_18,bVar1 >> 7);
    }
    else {
      if (uVar8 != 0xf9) {
        if (uVar8 != 0xfa) {
          return;
        }
        FUN_0101f1ac(DAT_0101379c + -0x100,(uint)bVar1 * 0x100 + DAT_010137ac);
        pcVar6[8] = '\0';
        pcVar6[9] = '\0';
        pcVar6[10] = '\0';
        pcVar6[0xb] = '\0';
        goto LAB_010135d4;
      }
      FUN_010131ee((char)DAT_010137b0[iVar7 + 2],*(undefined1 *)((int)DAT_010137b0 + iVar7 * 2 + 5))
      ;
      bVar4 = true;
    }
    pcVar6 = DAT_0101379c;
    iVar7 = *(int *)(DAT_0101379c + 8);
    bVar2 = *(byte *)((int)DAT_010137b0 + iVar7 * 2 + 3);
    if ((bVar2 & 0x7f) == 0) {
      if (bVar4) {
        iVar7 = iVar7 + 1;
        *(int *)(DAT_0101379c + 8) = iVar7;
      }
      *(int *)(pcVar6 + 8) = iVar7 + 1;
      uVar8 = (uint)DAT_010137b0[iVar7 + 2];
      *(uint *)(pcVar6 + 4) = uVar8;
      if (uVar8 == 0) {
        bVar5 = true;
        pcVar6[4] = '\x01';
        pcVar6[5] = '\0';
        pcVar6[6] = '\0';
        pcVar6[7] = '\0';
      }
      else {
        if ((((*(char *)(DAT_010137b4 + 0xc) == '\x05') || (*(char *)(DAT_010137b4 + 0xc) == '\0'))
            || (*(char *)(DAT_010137b4 + 0xc) == '\x01')) ||
           (*(char *)(DAT_010137b4 + 0xc) == '\x02')) goto joined_r0x01013732;
        if (uVar8 < 6) {
          uVar9 = 6;
          goto LAB_0101371a;
        }
      }
    }
    else {
      uVar8 = bVar2 & 0x7f;
      *(uint *)(DAT_0101379c + 4) = uVar8;
      if (bVar4) {
        *(int *)(pcVar6 + 8) = iVar7 + 1;
      }
      if (((*(char *)(DAT_010137b4 + 0xc) == '\x05') || (*(char *)(DAT_010137b4 + 0xc) == '\0')) ||
         ((*(char *)(DAT_010137b4 + 0xc) == '\x01' || (*(char *)(DAT_010137b4 + 0xc) == '\x02')))) {
joined_r0x01013732:
        if (uVar8 < 0x10) {
          pcVar6[4] = '\x10';
          pcVar6[5] = '\0';
          pcVar6[6] = '\0';
          pcVar6[7] = '\0';
        }
      }
      else if (uVar8 < 6) {
        uVar9 = 5;
LAB_0101371a:
        *(undefined4 *)(pcVar6 + 4) = uVar9;
      }
    }
    *(int *)(pcVar6 + 8) = *(int *)(pcVar6 + 8) + 1;
    if (!bVar5) {
      return;
    }
  } while( true );
}


// ===== FUN_01013738 @ 01013738

void FUN_01013738(void)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = 0;
  uVar2 = 0;
  do {
    pbVar1 = (byte *)(DAT_010137a0 + uVar2);
    uVar2 = uVar2 + 1;
    bVar3 = bVar3 | *pbVar1;
  } while (uVar2 < 8);
  if (bVar3 != 0) {
    FUN_0101f1de(DAT_010137a0,8);
    *DAT_01013798 = *DAT_01013798 | 0x10;
  }
  *(undefined1 *)(DAT_010137b8 + 4) = 0;
  return;
}


// ===== FUN_01013768 @ 01013768

void FUN_01013768(void)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = 0;
  uVar2 = 1;
  do {
    pbVar1 = (byte *)(DAT_010137bc + uVar2);
    uVar2 = uVar2 + 1;
    bVar3 = bVar3 | *pbVar1;
  } while (uVar2 < 3);
  if (bVar3 != 0) {
    FUN_0101f1de(DAT_010137bc,3);
    *DAT_01013798 = *DAT_01013798 | 2;
  }
  return;
}


// ===== FUN_010137c0 @ 010137c0

undefined8 FUN_010137c0(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_18 = param_1 & 0xffffff00;
  local_14 = 0xc;
  local_10 = 0xc;
  local_c = param_4 & 0xffffff00;
  FUN_0101abd8(2,0x1000);
  FUN_0101b7a0(&local_18);
  FUN_0101b724(0);
  FUN_0101b686(0,1);
  return CONCAT44(local_14,local_18);
}


// ===== FUN_010137f4 @ 010137f4

void FUN_010137f4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_01013bf4;
  *(undefined1 *)(DAT_01013bf4 + 10) = 0x3e;
  iVar2 = DAT_01013bf4;
  iVar3 = 0;
  do {
    *(undefined1 *)(iVar1 + 0xb) = 0x3e;
    if (param_1 < 0) {
      *(undefined1 *)(iVar2 + -0x1b) = 0x3f;
    }
    else {
      *(undefined1 *)(iVar2 + -0x1b) = 0x3e;
    }
    if (param_2 < 0) {
      *(undefined1 *)(iVar1 + 10) = 0x3f;
    }
    else {
      *(undefined1 *)(iVar1 + 10) = 0x3e;
    }
    *(undefined1 *)(iVar1 + 0xb) = 0x3f;
    param_2 = param_2 << 1;
    param_1 = param_1 << 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  *(undefined1 *)(iVar1 + 0xb) = 0x3e;
  *(undefined1 *)(iVar1 + 10) = 0x3e;
  *(undefined1 *)(iVar2 + -0x1b) = 0x3e;
  return;
}


// ===== FUN_0101382e @ 0101382e

void FUN_0101382e(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_01013bf4;
  iVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + 0xb) = 0x3e;
    if ((int)(param_1 << 0x10) < 0) {
      *(undefined1 *)(iVar1 + 10) = 0x3f;
    }
    else {
      *(undefined1 *)(iVar1 + 10) = 0x3e;
    }
    *(undefined1 *)(iVar1 + 0xb) = 0x3f;
    param_1 = (param_1 & 0x7fff) << 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  *(undefined1 *)(iVar1 + 10) = 0x3e;
  *(undefined1 *)(DAT_01013bf4 + -0x1b) = 0x3e;
  *(undefined1 *)(iVar1 + 0xb) = 0x3e;
  return;
}


// ===== FUN_0101385c @ 0101385c

void FUN_0101385c(void)

{
  int iVar1;
  int iVar2;
  
  FUN_0101f1de(DAT_01013bf8,0x2a0);
  iVar1 = DAT_01013bfc;
  FUN_0101abd8(2,*(undefined2 *)(DAT_01013bfc + 0x14),0);
  FUN_0101abd8(2,*(undefined2 *)(iVar1 + 0x16),0);
  FUN_0101abd8(2,*(undefined2 *)(iVar1 + 0x18),0);
  FUN_0101abd8(0,*(undefined2 *)(iVar1 + 10));
  iVar1 = DAT_01013bf4;
  *(undefined1 *)(DAT_01013bf4 + -0x1b) = 0x3e;
  iVar2 = DAT_01013bf4;
  *(undefined1 *)(DAT_01013bf4 + 0xc) = 0x3e;
  *(undefined1 *)(iVar2 + 0xb) = 0x3e;
  *(undefined1 *)(iVar2 + 10) = 0x3e;
  *(undefined1 *)(iVar1 + -0x12) = 0x3f;
  thunk_EXT_FUN_0000425c(5);
  iVar1 = DAT_01013c00;
  FUN_0101382e(DAT_01013c00,0);
  FUN_0101382e(iVar1 >> 2,0);
  FUN_0101382e(iVar1,0);
  FUN_0101b686(0);
  FUN_010137f4(DAT_01013c04,0xf);
  FUN_0101b686(0,1);
  FUN_0101382e(iVar1,0);
  FUN_0101b686(0);
  FUN_010137f4(DAT_01013c08,0x3f);
  FUN_0101b686(0,1);
  FUN_0101382e(iVar1,0);
  FUN_0101b686(0);
  FUN_010137f4(DAT_01013c0c,0xff);
  FUN_0101b686(0,1);
  FUN_0101382e(iVar1,0);
  FUN_0101b686(0);
  FUN_010137f4(DAT_01013c10,iVar1 >> 4);
  FUN_0101b686(0,1);
  FUN_010137c0();
  *DAT_01013c14 = 0;
  return;
}


// ===== FUN_0101394a @ 0101394a

void FUN_0101394a(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_01013bf4;
  *(undefined1 *)(DAT_01013bf4 + 10) = 0x3e;
  *(undefined1 *)(iVar1 + 0xb) = 0x3e;
  iVar2 = DAT_01013bf4;
  *(undefined1 *)(DAT_01013bf4 + -0x1b) = 0x3e;
  FUN_0101b686(0);
  FUN_0101abd8(2,0x1000,0);
  *(undefined1 *)(iVar1 + 0xc) = 0x3e;
  *(undefined1 *)(iVar2 + -0x12) = 0x3e;
  FUN_0101f1de(DAT_01013bf8,0x2a0);
  return;
}


// ===== FUN_01013996 @ 01013996

void FUN_01013996(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_01013bf4;
  *(undefined1 *)(DAT_01013bf4 + 10) = 0x3e;
  iVar2 = DAT_01013bf4;
  iVar3 = 0;
  do {
    *(undefined1 *)(iVar1 + 0xb) = 0x3e;
    if (iVar3 == 0x1f) {
      *(undefined1 *)(iVar1 + 10) = 0x3f;
    }
    if (param_1 < 0) {
      *(undefined1 *)(iVar2 + -0x1b) = 0x3f;
    }
    else {
      *(undefined1 *)(iVar2 + -0x1b) = 0x3e;
    }
    *(undefined1 *)(iVar1 + 0xb) = 0x3f;
    param_1 = param_1 << 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  *(undefined1 *)(iVar1 + 10) = 0x3e;
  *(undefined1 *)(iVar2 + -0x1b) = 0x3e;
  *(undefined1 *)(iVar1 + 0xb) = 0x3e;
  return;
}


// ===== FUN_010139ca @ 010139ca

void FUN_010139ca(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_01013bf4;
  iVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + 0xb) = 0x3f;
    *(undefined1 *)(iVar1 + 0xb) = 0x3e;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  return;
}


// ===== FUN_010139de @ 010139de

void FUN_010139de(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = DAT_01013c1c;
  iVar3 = param_1 * 4 + DAT_01013c18;
  DAT_01013c1c[0xf] = (uint)*(byte *)(iVar3 + 1) * 0x101;
  puVar1[0xe] = (uint)*(byte *)(iVar3 + 2) * 0x101;
  puVar1[0xd] = (uint)*(byte *)(iVar3 + 3) * 0x101;
  puVar1[0xc] = (uint)*(byte *)(iVar3 + 0x55) * 0x101;
  puVar1[0xb] = (uint)*(byte *)(iVar3 + 0x56) * 0x101;
  iVar2 = DAT_01013c20;
  puVar1[10] = (uint)*(byte *)(iVar3 + 0x57) * 0x101 |
               (uint)*(byte *)(DAT_01013c20 + 0x15) * 0x1010000;
  puVar1[9] = (uint)*(byte *)(iVar3 + 0xa9) * 0x101 | (uint)*(byte *)(iVar2 + 0x16) * 0x1010000;
  puVar1[8] = (uint)*(byte *)(iVar3 + 0xaa) * 0x101 | (uint)*(byte *)(iVar2 + 0x17) * 0x1010000;
  puVar1[7] = (uint)*(byte *)(iVar3 + 0xab) * 0x101 | (uint)*(byte *)(iVar3 + 0x1a5) * 0x1010000;
  puVar1[6] = (uint)*(byte *)(iVar3 + 0xfd) * 0x101 | (uint)*(byte *)(iVar3 + 0x1a6) * 0x1010000;
  puVar1[5] = (uint)*(byte *)(iVar3 + 0xfe) * 0x101 | (uint)*(byte *)(iVar3 + 0x1a7) * 0x1010000;
  puVar1[4] = (uint)*(byte *)(iVar3 + 0xff) * 0x101;
  puVar1[3] = (uint)*(byte *)(iVar3 + 0x151) * 0x101;
  puVar1[2] = (uint)*(byte *)(iVar3 + 0x152) * 0x101;
  puVar1[1] = (uint)*(byte *)(iVar3 + 0x153) * 0x101;
  *puVar1 = 0;
  return;
}


// ===== FUN_01013aba @ 01013aba

void FUN_01013aba(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = DAT_01013c28;
  iVar4 = DAT_01013c24;
  iVar5 = DAT_01013c1c;
  pbVar2 = DAT_01013c14;
  bVar1 = *DAT_01013c14;
  if (*(char *)(DAT_01013c24 + 0xc) == -3) {
    if (bVar1 < 0x11) {
      FUN_010139de();
      iVar4 = 0;
      do {
        FUN_01013996(*(undefined4 *)(iVar5 + iVar4 * 4),0);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x10);
      FUN_01010730(7);
      FUN_0101b686(0);
      FUN_0101382e(7,0);
      FUN_0101b686(0,1);
      FUN_010139ca();
      *(undefined1 *)
       ((uint)*(byte *)(iVar3 + (uint)*pbVar2) +
       (uint)*(byte *)(DAT_01013c30 + (uint)*(byte *)(DAT_01013c2c + (uint)*pbVar2)) * 0x10 +
       DAT_01013bf4 + -0x20) = 0x3f;
    }
    else if (bVar1 == 0x11) {
      iVar5 = 0;
      do {
        FUN_01013996(0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x10);
      FUN_01010730(7);
      FUN_0101b686(0);
      FUN_0101382e(7,0);
      FUN_0101b686(0,1);
      FUN_010139ca();
      FUN_01011f48();
      FUN_010119d0();
      FUN_010180e2();
      FUN_010178a0();
    }
  }
  else if (bVar1 < 0x11) {
    FUN_010139de();
    iVar4 = 0;
    do {
      FUN_01013996(*(undefined4 *)(iVar5 + iVar4 * 4),0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    FUN_01010730(7);
    thunk_EXT_FUN_00004238(10);
    FUN_0101b686(0);
    FUN_0101382e(7,0);
    FUN_0101b686(0,1);
    FUN_010139ca();
    *(undefined1 *)
     ((uint)*(byte *)(iVar3 + (uint)*pbVar2) +
     (uint)*(byte *)(DAT_01013c30 + (uint)*(byte *)(DAT_01013c2c + (uint)*pbVar2)) * 0x10 +
     DAT_01013bf4 + -0x20) = 0x3f;
    if (*pbVar2 == 0x10) {
      *(undefined1 *)(DAT_01013c24 + 0x2b) = 1;
    }
  }
  else if (bVar1 == 0x11) {
    iVar5 = 0;
    do {
      FUN_01013996(0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x10);
    FUN_01010730(7);
    FUN_0101b686(0);
    FUN_0101382e(7,0);
    FUN_0101b686(0,1);
    FUN_010139ca();
    if (*(byte *)(iVar4 + 0xc) < 6) {
      if (*(char *)(iVar4 + 0xc) == *(char *)(iVar4 + 0xd)) {
        FUN_01017b1e();
        FUN_01011082();
        FUN_010180e2();
        FUN_010178a0();
      }
    }
    FUN_01011f48();
  }
  bVar1 = *pbVar2;
  *pbVar2 = bVar1 + 1;
  if (0x11 < (byte)(bVar1 + 1)) {
    *pbVar2 = 0;
  }
  return;
}


// ===== FUN_01013c80 @ 01013c80

void FUN_01013c80(void)

{
  int iVar1;
  byte *pbVar2;
  
  if (-1 < (int)((uint)*DAT_01013ce8 << 0x1d)) {
    *DAT_01013ce8 = *DAT_01013ce8 | 4;
    pbVar2 = DAT_01013cf4;
    iVar1 = DAT_01013cf0;
    if (*(char *)(DAT_01013cec + 0xc) != -2) {
      if ((*(char *)(DAT_01013cf0 + 0x1a) == '\0') && (*(char *)(DAT_01013cf0 + 0x1c) == '\0')) {
        if (-1 < (int)((uint)DAT_01013cf4[(uint)*DAT_01013cf4 * 2 + 10] << 0x1b)) {
          FUN_01016f9e();
          if ((*(char *)(iVar1 + 0x1a) != '\0') || (*(char *)(iVar1 + 0x1c) != '\0'))
          goto LAB_01013cd4;
        }
        if (-1 < (int)((uint)pbVar2[(uint)*pbVar2 * 2 + 10] << 0x1a)) {
          FUN_0101700c();
        }
      }
    }
  }
LAB_01013cd4:
  FUN_01014bfc();
  FUN_010171bc();
  FUN_0101669a();
  FUN_010171be();
  return;
}


// ===== FUN_01013cf8 @ 01013cf8

void FUN_01013cf8(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = DAT_010140fc;
  iVar6 = DAT_010140f4;
  uVar5 = (uint)*(byte *)(DAT_010140f4 + 0x1a);
  uVar3 = *(undefined4 *)(DAT_010140f8 + (uint)*(byte *)(uVar5 + DAT_010140f4 + 0x40) * 4);
  DAT_010140fc[1] = uVar3;
  *puVar2 = uVar3;
  *(undefined1 *)(puVar2 + 0x14) =
       *(undefined1 *)(DAT_01014100 + (uint)*(byte *)(uVar5 + iVar6 + 0x60));
  bVar1 = *(byte *)(uVar5 + iVar6 + 0x80);
  *(byte *)((int)puVar2 + 0xd) = bVar1 >> 4;
  *(byte *)(puVar2 + 3) = bVar1 & 0xf;
  iVar6 = uVar5 * 3 + iVar6;
  *(undefined1 *)((int)puVar2 + 0x51) = *(undefined1 *)(iVar6 + 0xa0);
  *(undefined1 *)((int)puVar2 + 0x52) = *(undefined1 *)(iVar6 + 0xa1);
  *(undefined1 *)((int)puVar2 + 0x53) = *(undefined1 *)(iVar6 + 0xa2);
  puVar2[2] = 0;
  *(undefined1 *)((int)puVar2 + 0xe) = 1;
  iVar6 = 0;
  do {
    *(undefined1 *)(puVar2 + iVar6 + 4) = 0;
    *(undefined1 *)((int)puVar2 + iVar6 * 4 + 0x11) = 0;
    iVar4 = iVar6 + 1;
    *(undefined2 *)((int)puVar2 + iVar6 * 4 + 0x12) = 0;
    iVar6 = iVar4;
  } while (iVar4 < 0x10);
  *DAT_01014104 = *DAT_01014104 | 2;
  return;
}


// ===== FUN_01013d6a @ 01013d6a

void FUN_01013d6a(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = DAT_01014100;
  puVar2 = DAT_010140fc;
  iVar4 = DAT_010140f4;
  uVar3 = (uint)*(byte *)(DAT_010140f4 + 0x1a);
  uVar6 = *(undefined4 *)(DAT_010140f8 + -0x18 + (uint)*(byte *)(uVar3 + DAT_010140f4 + 0x40) * 4);
  DAT_010140fc[1] = uVar6;
  *puVar2 = uVar6;
  *(undefined1 *)((int)puVar2 + 10) = *(undefined1 *)(iVar5 + (uint)*(byte *)(uVar3 + iVar4 + 0x60))
  ;
  bVar1 = *(byte *)(uVar3 + iVar4 + 0x80);
  *(byte *)(puVar2 + 2) = bVar1 >> 4;
  *(byte *)((int)puVar2 + 9) = bVar1 & 0xf;
  iVar4 = uVar3 * 3 + iVar4;
  *(undefined1 *)((int)puVar2 + 0x17) = *(undefined1 *)(iVar4 + 0xa0);
  *(undefined1 *)(puVar2 + 6) = *(undefined1 *)(iVar4 + 0xa1);
  *(undefined1 *)((int)puVar2 + 0x19) = *(undefined1 *)(iVar4 + 0xa2);
  puVar2[3] = 0;
  *(undefined1 *)(puVar2 + 4) = 0;
  iVar4 = 0;
  do {
    iVar5 = iVar4 + 1;
    *(undefined1 *)((int)puVar2 + iVar4 + 0x11) = 0;
    iVar4 = iVar5;
  } while (iVar5 < 6);
  *DAT_01014104 = *DAT_01014104 | 2;
  return;
}


// ===== FUN_01013dd2 @ 01013dd2

void FUN_01013dd2(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 in_r3;
  undefined1 *puVar7;
  undefined4 local_18;
  
  local_18 = in_r3;
  FUN_0101f1de(DAT_010140fc,0x2fc);
  iVar5 = DAT_010140f4;
  uVar4 = (uint)*(byte *)(DAT_010140f4 + 0x1a);
  puVar7 = (undefined1 *)(DAT_010140fc + 0xc0);
  *(undefined1 *)(DAT_010140fc + 0xc1) =
       *(undefined1 *)(DAT_01014100 + (uint)*(byte *)(uVar4 + DAT_010140f4 + 0x60));
  iVar2 = DAT_010140fc;
  bVar1 = *(byte *)(uVar4 + iVar5 + 0x80);
  *(byte *)(DAT_010140fc + 6) = bVar1 >> 4;
  *(byte *)(iVar2 + 7) = bVar1 & 0xf;
  *(undefined1 *)(iVar2 + 8) = 0;
  iVar5 = uVar4 * 3 + iVar5;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined1 *)(iVar2 + 0xbe) = *(undefined1 *)(iVar5 + 0xa0);
  *(undefined1 *)(iVar2 + 0xbf) = *(undefined1 *)(iVar5 + 0xa1);
  *puVar7 = *(undefined1 *)(iVar5 + 0xa2);
  *(undefined1 *)(iVar2 + 0x6c) = 0;
  *(undefined1 *)(iVar2 + 0x6d) = 0;
  *(undefined1 *)(iVar2 + 0x6e) = 0;
  *(undefined1 *)(iVar2 + 0x6f) = 0;
  if ((bVar1 & 0xf) == 0) {
    local_18 = 0;
    iVar5 = 0;
    do {
      FUN_010169e6(&local_18,0x3f,1);
      iVar6 = (0x14 - iVar5) * 4 + iVar2;
      *(undefined1 *)(iVar6 + 0x10) = (undefined1)local_18;
      *(undefined1 *)(iVar6 + 0x11) = local_18._1_1_;
      *(undefined1 *)(iVar6 + 0x12) = local_18._2_1_;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(iVar6 + 0x13) = local_18._3_1_;
    } while (iVar5 < 0x15);
  }
  else if ((bVar1 & 0xf) == 1) {
    iVar5 = 0;
    local_18 = 0;
    do {
      FUN_010169e6(&local_18,0x3f,1);
      iVar6 = (0x14 - iVar5) * 4 + iVar2;
      *(undefined1 *)(iVar6 + 0x10) = 0;
      *(undefined1 *)(iVar6 + 0x11) = 0;
      *(undefined1 *)(iVar6 + 0x12) = 0;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(iVar6 + 0x13) = 0;
    } while (iVar5 < 0x15);
  }
  pbVar3 = DAT_01014104;
  *(undefined1 *)(iVar2 + 3) = 1;
  *pbVar3 = *pbVar3 | 2;
  return;
}


// ===== FUN_01013ea0 @ 01013ea0

void FUN_01013ea0(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = DAT_010140fc;
  iVar3 = DAT_010140f4;
  bVar1 = *(byte *)(DAT_010140f4 + 0x1a);
  *DAT_010140fc = *(undefined1 *)(DAT_01014100 + (uint)*(byte *)((uint)bVar1 + DAT_010140f4 + 0x60))
  ;
  iVar3 = (uint)bVar1 * 3 + iVar3;
  puVar2[1] = *(undefined1 *)(iVar3 + 0xa0);
  puVar2[2] = *(undefined1 *)(iVar3 + 0xa1);
  puVar2[3] = *(undefined1 *)(iVar3 + 0xa2);
  *DAT_01014104 = *DAT_01014104 | 2;
  return;
}


// ===== FUN_01013ed2 @ 01013ed2

void FUN_01013ed2(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 in_r3;
  undefined1 *puVar7;
  undefined4 local_18;
  
  local_18 = in_r3;
  FUN_0101f1de(DAT_010140fc,0x2fc);
  iVar5 = DAT_010140f4;
  uVar4 = (uint)*(byte *)(DAT_010140f4 + 0x1a);
  puVar7 = (undefined1 *)(DAT_010140fc + 0xc0);
  *(undefined1 *)(DAT_010140fc + 0xc1) =
       *(undefined1 *)(DAT_01014100 + (uint)*(byte *)(uVar4 + DAT_010140f4 + 0x60));
  iVar2 = DAT_010140fc;
  bVar1 = *(byte *)(uVar4 + iVar5 + 0x80);
  *(byte *)(DAT_010140fc + 6) = bVar1 >> 4;
  *(byte *)(iVar2 + 7) = bVar1 & 0xf;
  *(undefined1 *)(iVar2 + 8) = 0;
  iVar5 = uVar4 * 3 + iVar5;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined1 *)(iVar2 + 0xbe) = *(undefined1 *)(iVar5 + 0xa0);
  *(undefined1 *)(iVar2 + 0xbf) = *(undefined1 *)(iVar5 + 0xa1);
  *puVar7 = *(undefined1 *)(iVar5 + 0xa2);
  *(undefined1 *)(iVar2 + 0x6c) = 0;
  *(undefined1 *)(iVar2 + 0x6d) = 0;
  *(undefined1 *)(iVar2 + 0x6e) = 0;
  *(undefined1 *)(iVar2 + 0x6f) = 0;
  if ((bVar1 & 0xf) == 0) {
    local_18 = 0;
    iVar5 = 0;
    do {
      FUN_010169e6(&local_18,0x3f,1);
      iVar6 = (0x14 - iVar5) * 4 + iVar2;
      *(undefined1 *)(iVar6 + 0x10) = (undefined1)local_18;
      *(undefined1 *)(iVar6 + 0x11) = local_18._1_1_;
      *(undefined1 *)(iVar6 + 0x12) = local_18._2_1_;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(iVar6 + 0x13) = local_18._3_1_;
    } while (iVar5 < 0x15);
  }
  else if ((bVar1 & 0xf) == 1) {
    iVar5 = 0;
    local_18 = 0;
    do {
      FUN_010169e6(&local_18,0x3f,1);
      iVar6 = (0x14 - iVar5) * 4 + iVar2;
      *(undefined1 *)(iVar6 + 0x10) = 0;
      *(undefined1 *)(iVar6 + 0x11) = 0;
      *(undefined1 *)(iVar6 + 0x12) = 0;
      iVar5 = iVar5 + 1;
      *(undefined1 *)(iVar6 + 0x13) = 0;
    } while (iVar5 < 0x15);
  }
  pbVar3 = DAT_01014104;
  *(undefined1 *)(iVar2 + 3) = 1;
  *pbVar3 = *pbVar3 | 2;
  return;
}


// ===== FUN_010143d0 @ 010143d0

void FUN_010143d0(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  puVar4 = DAT_0101454c;
  *(undefined1 *)((int)DAT_0101454c + 5) = 0;
  iVar14 = DAT_01014554;
  *puVar4 = 0;
  iVar5 = DAT_01014560;
  bVar1 = *(byte *)(iVar14 + 0x1a);
  *(undefined1 *)(DAT_01014560 + 1) =
       *(undefined1 *)(DAT_0101455c + (uint)*(byte *)((uint)bVar1 + DAT_01014554 + 0x60));
  *(byte *)(puVar4 + 1) = *(byte *)((uint)bVar1 + DAT_01014554 + 0x80) >> 4;
  *(undefined1 *)((int)puVar4 + 6) = 0;
  iVar14 = 0;
  do {
    iVar13 = 0;
    iVar15 = iVar14 * 0x12;
    do {
      iVar7 = (uint)*(byte *)(DAT_0101454c + 1) * 0x180 + DAT_01014564 + iVar15;
      iVar12 = iVar13 * 3;
      iVar11 = iVar7 + iVar12;
      iVar8 = iVar13 * 0x2a + DAT_01014568;
      FUN_01016926(*(undefined1 *)(iVar8 + iVar14 * 2),*(undefined1 *)(iVar8 + iVar14 * 2 + 1),
                   *(undefined1 *)(iVar5 + 1),*(undefined1 *)(iVar7 + iVar12),
                   *(undefined1 *)(iVar11 + 1),*(undefined1 *)(iVar11 + 2),1);
      puVar4 = DAT_0101454c;
      cVar3 = *(char *)((uint)*(byte *)(DAT_0101454c + 1) * 0x180 + DAT_01014564 + iVar15 + iVar12);
      iVar7 = iVar14 * 3 + iVar13 * 0x3f;
      *(char *)((int)DAT_0101454c + iVar7 + 7) = cVar3;
      cVar6 = *(char *)((uint)*(byte *)(DAT_0101454c + 1) * 0x180 + DAT_01014564 + iVar15 + iVar12 +
                       1);
      *(char *)((int)puVar4 + iVar7 + 8) = cVar6;
      cVar2 = *(char *)((uint)*(byte *)(DAT_0101454c + 1) * 0x180 + DAT_01014564 + iVar15 + iVar12 +
                       2);
      *(char *)((int)puVar4 + iVar7 + 9) = cVar2;
      uVar9 = 0;
      do {
        if (((cVar3 == *(char *)(DAT_0101456c + uVar9 * 3)) &&
            (iVar12 = uVar9 * 3 + DAT_0101456c, cVar6 == *(char *)(iVar12 + 1))) &&
           (cVar2 == *(char *)(iVar12 + 2))) {
          cVar6 = (char)uVar9;
          goto LAB_010144e8;
        }
        uVar10 = uVar9 + 1;
        uVar9 = uVar10 & 0xff;
      } while (uVar9 < 9);
      cVar6 = (char)uVar10 + -1;
LAB_010144e8:
      iVar12 = iVar13 * 0x15;
      iVar13 = iVar13 + 1;
      *(char *)((int)DAT_0101454c + iVar14 + iVar12 + 0x184) = cVar6;
    } while (iVar13 < 6);
    iVar14 = iVar14 + 1;
    if (0x14 < iVar14) {
      *DAT_01014550 = *DAT_01014550 | 2;
      return;
    }
  } while( true );
}


// ===== FUN_01014bc4 @ 01014bc4

void FUN_01014bc4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  FUN_0101f1de(DAT_01014de0,0x2fc,param_3,param_4,param_2,param_3,param_4);
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      FUN_01016926(uVar2 & 0xff,uVar1 & 0xff,0,0,0,0,1);
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 0x11);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 6);
  FUN_010170dc();
  return;
}


// ===== FUN_01014bfc @ 01014bfc
// decompile failed
// ===== FUN_01014d34 @ 01014d34

void FUN_01014d34(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
  pbVar3 = DAT_01014e10;
  if (DAT_01014e10[2] != 0) {
    bVar1 = DAT_01014e10[1];
    DAT_01014e10[1] = bVar1 + 1;
    if (99 < (byte)(bVar1 + 1)) {
      pbVar3[1] = 0;
      *pbVar3 = *pbVar3 - 1;
    }
    if ((*pbVar3 & 1) == 0) {
      uVar6 = 0;
      uVar5 = 0;
      uVar7 = 0;
    }
    else {
      iVar2 = (uint)*(byte *)(DAT_01014de4 + 0x1e) * 3;
      iVar4 = iVar2 + DAT_01014df0;
      uVar7 = *(undefined1 *)(iVar4 + 2);
      uVar6 = *(undefined1 *)(iVar4 + 1);
      uVar5 = *(undefined1 *)(DAT_01014df0 + iVar2);
    }
    FUN_01016926(3,0,100,uVar5,uVar6,uVar7,1);
    if (*pbVar3 == 0) {
      pbVar3[2] = 0;
    }
  }
  return;
}


// ===== FUN_01014d94 @ 01014d94

void FUN_01014d94(void)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  ushort uVar4;
  uint uVar5;
  
  iVar1 = DAT_01014e04;
  if (*(char *)(DAT_01014e04 + 0x1c) != '\0') {
    if (*(byte *)(DAT_01014e04 + 0xe) < 4) {
      uVar4 = 0xff;
    }
    else {
      if (*(byte *)(DAT_01014e04 + 0xe) < 6) {
        uVar3 = 0xff;
      }
      else {
        uVar3 = 0;
      }
      uVar4 = CONCAT11(0xff,uVar3);
    }
    uVar5 = (uint)uVar4;
    if (*(char *)(DAT_01014e04 + 0x1d) != '\0') {
      *(undefined1 *)(DAT_01014e04 + 0x1d) = 0;
      FUN_01014bc4();
    }
    for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(iVar1 + 0xe); iVar2 = iVar2 + 1) {
      FUN_01016926(*(undefined1 *)(DAT_01015200 + iVar2 * 2),
                   *(undefined1 *)(iVar2 * 2 + DAT_01015200 + 1),100,uVar5 & 0xff,uVar5 >> 8 & 0xff,
                   uVar5 >> 0x10 & 0xff,1);
    }
  }
  return;
}


// ===== FUN_01014e3a @ 01014e3a

void FUN_01014e3a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = DAT_01015204;
  if ((*(char *)(DAT_01015204 + 8) != '\0') &&
     (pbVar4 = (byte *)(DAT_01015204 + -0x100),
     (uint)*(byte *)((uint)*pbVar4 + DAT_01015204 + -0xfe) * 10 <= *(uint *)(DAT_01015204 + 4))) {
    *(undefined4 *)(DAT_01015204 + 4) = 0;
    FUN_0101f61c((uint)*pbVar4 * 0x200 + DAT_01015208,DAT_01015204 + 10,0x200,10,param_2,param_3,
                 param_4);
    bVar1 = *pbVar4;
    *pbVar4 = bVar1 + 1;
    if (*(byte *)(iVar6 + -0xff) <= (byte)(bVar1 + 1)) {
      *pbVar4 = 0;
    }
    iVar6 = 0;
    do {
      iVar5 = 0;
      iVar7 = iVar6 * 0x12 + DAT_0101520c;
      do {
        iVar2 = iVar7 + iVar5 * 3;
        iVar3 = iVar5 * 0x2a + DAT_01015210;
        FUN_01016926(*(undefined1 *)(iVar3 + iVar6 * 2),*(undefined1 *)(iVar3 + iVar6 * 2 + 1),100,
                     *(undefined1 *)(iVar2 + 0x10a),*(undefined1 *)(iVar2 + 0x10b),
                     *(undefined1 *)(iVar2 + 0x10c),1);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x15);
  }
  return;
}


// ===== FUN_01014eca @ 01014eca

void FUN_01014eca(void)

{
  undefined4 *puVar1;
  char *pcVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = DAT_01015214;
  iVar5 = DAT_01015214[1];
  DAT_01015214[1] = iVar5 + -1;
  if (iVar5 + -1 != 0) {
    return;
  }
  puVar1[1] = *puVar1;
  cVar3 = *(char *)((int)puVar1 + 0xe) + -1;
  *(char *)((int)puVar1 + 0xe) = cVar3;
  if (cVar3 == '\0') {
    *(undefined1 *)((int)puVar1 + 0xe) = 0xf;
    *DAT_01015218 = '\x01';
  }
  else if (*DAT_01015218 == '\0') goto LAB_01014f40;
  *DAT_01015218 = '\0';
  if (puVar1[2] != DAT_0101521c) {
    uVar7 = 0;
    uVar6 = 0;
    do {
      if ((puVar1[2] & 1 << (uVar6 & 0xff)) == 0) {
        if (*(char *)((int)puVar1 + 0xd) == '\0') {
          *(undefined1 *)(puVar1 + uVar7 + 4) = 5;
          *(undefined1 *)((int)puVar1 + uVar7 * 4 + 0x11) = 0;
        }
        else {
          *(undefined1 *)(puVar1 + uVar7 + 4) = 0;
          *(undefined1 *)((int)puVar1 + uVar7 * 4 + 0x11) = 0x16;
        }
        *(undefined2 *)((int)puVar1 + uVar7 * 4 + 0x12) = 0;
        puVar1[2] = puVar1[2] | 1 << (uVar6 & 0xff);
        break;
      }
      uVar6 = uVar6 + 1;
      uVar7 = uVar7 + 1 & 0xffff;
    } while ((int)uVar6 < 0x10);
  }
LAB_01014f40:
  uVar6 = 0;
  for (uVar7 = (uint)*(ushort *)(puVar1 + 2); uVar7 != 0; uVar7 = uVar7 >> 1) {
    if ((uVar7 & 1) != 0) {
      uVar4 = FUN_01016bb2(*(undefined1 *)(puVar1 + uVar6 + 4),
                           *(undefined1 *)((int)puVar1 + uVar6 * 4 + 0x11),
                           *(undefined2 *)((int)puVar1 + uVar6 * 4 + 0x12));
      pcVar2 = DAT_01015218;
      *(undefined2 *)(DAT_01015218 + 6) = uVar4;
      if (*(short *)(pcVar2 + 6) == 0) {
        puVar1[2] = puVar1[2] & ~(1 << (uVar6 & 0xff));
      }
      else {
        *(short *)((int)puVar1 + uVar6 * 4 + 0x12) = *(short *)((int)puVar1 + uVar6 * 4 + 0x12) + 1;
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  }
  return;
}


// ===== FUN_01014f8e @ 01014f8e

void FUN_01014f8e(void)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  char cVar7;
  byte bVar8;
  byte extraout_r1;
  int iVar9;
  undefined2 uVar10;
  uint in_stack_ffffffd8;
  
  puVar1 = DAT_01015214;
  iVar3 = DAT_01015214[1];
  DAT_01015214[1] = iVar3 + -1;
  if (iVar3 + -1 != 0) {
    return;
  }
  puVar1[1] = *puVar1;
  if (puVar1[3] != 0) {
    puVar1[3] = puVar1[3] + -1;
    return;
  }
  iVar3 = 0;
  if (*(char *)(puVar1 + 4) == '\0') {
    do {
      bVar8 = *(char *)((int)puVar1 + iVar3 + 0x11) + 1;
      *(byte *)((int)puVar1 + iVar3 + 0x11) = bVar8;
      if (0x13 < bVar8) {
        *(undefined1 *)(puVar1 + 4) = 1;
        puVar1[3] = 0x14;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  else {
    iVar3 = 0;
    do {
      cVar7 = *(char *)((int)puVar1 + iVar3 + 0x11) + -1;
      *(char *)((int)puVar1 + iVar3 + 0x11) = cVar7;
      if (cVar7 == '\0') {
        *(undefined1 *)(puVar1 + 4) = 0;
        puVar1[3] = 0x14;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  iVar3 = DAT_01015220;
  uVar4 = (uint)*(byte *)((int)puVar1 + 9);
  if (uVar4 < 7) {
LAB_01014ff6:
    iVar5 = uVar4 * 3 + iVar3;
    uVar10 = CONCAT11(*(undefined1 *)(iVar5 + 1),*(undefined1 *)(iVar3 + uVar4 * 3));
    uVar2 = *(undefined1 *)(iVar5 + 2);
  }
  else {
    if (uVar4 == 8) {
      uVar6 = FUN_0101f188();
      FUN_0101f160(uVar6,6);
      uVar4 = (uint)extraout_r1;
      goto LAB_01014ff6;
    }
    if (uVar4 != 7) goto LAB_01015030;
    uVar10 = *(undefined2 *)((int)puVar1 + 0x17);
    uVar2 = *(undefined1 *)((int)puVar1 + 0x19);
  }
  in_stack_ffffffd8 = (uint)CONCAT12(uVar2,uVar10);
LAB_01015030:
  iVar3 = 0;
  do {
    iVar9 = iVar3 * 0x2a + DAT_01015224;
    iVar5 = (uint)*(byte *)((int)puVar1 + iVar3 + 0x11) * 2;
    FUN_01016926(*(undefined1 *)(iVar9 + iVar5),*(undefined1 *)(iVar9 + iVar5 + 1),
                 *(undefined1 *)((int)puVar1 + 10),in_stack_ffffffd8 & 0xff,
                 in_stack_ffffffd8 >> 8 & 0xff,in_stack_ffffffd8 >> 0x10 & 0xff,1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  return;
}


// ===== FUN_0101506a @ 0101506a

void FUN_0101506a(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  
  iVar5 = DAT_01015214;
  if (*(char *)(DAT_01015214 + 3) != '\0') {
    *(undefined1 *)(DAT_01015214 + 1) = 0;
    uVar6 = *(int *)(iVar5 + 0xc) + 1;
    *(uint *)(iVar5 + 0xc) = uVar6;
    if (2 < uVar6) {
      *(undefined4 *)(iVar5 + 0xc) = 0;
      iVar13 = DAT_01015220;
      cVar1 = *(char *)(iVar5 + 7);
      if (cVar1 == '\x02') {
        if (*(byte *)(DAT_01015214 + 8) == 8) {
          iVar7 = 0xff;
        }
        else {
          iVar7 = 1;
        }
        iVar7 = ((uint)*(byte *)(DAT_01015214 + 8) + iVar7) * 3;
        iVar8 = 0;
        uVar4 = *(undefined1 *)(DAT_01015220 + iVar7);
        iVar7 = iVar7 + DAT_01015220;
        uVar2 = *(undefined1 *)(iVar7 + 1);
        uVar3 = *(undefined1 *)(iVar7 + 2);
        do {
          *(undefined1 *)(iVar5 + 0x6d) = uVar4;
          *(undefined1 *)(iVar5 + 0x6e) = uVar2;
          iVar8 = iVar8 + 1;
          *(undefined1 *)(iVar5 + 0x6f) = uVar3;
        } while (iVar8 < 0x15);
      }
      else {
        *(undefined1 *)(iVar5 + 0x6d) = 0;
        *(undefined1 *)(iVar5 + 0x6e) = 0;
        *(undefined1 *)(iVar5 + 0x6f) = 0;
      }
      iVar7 = DAT_01015214;
      if (cVar1 == '\0') {
        iVar13 = 0;
        do {
          FUN_010169e6(iVar13 * 4 + iVar7 + 0x10,8,1);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0x15);
      }
      else if (cVar1 == '\x01') {
        iVar13 = 0;
        do {
          FUN_010169e6(iVar13 * 4 + iVar7 + 0x10,8,1);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0x15);
      }
      else if (cVar1 == '\x02') {
        iVar8 = 0;
        do {
          iVar9 = iVar8 * 4 + iVar7;
          *(undefined1 *)(iVar9 + 0x11) = *(undefined1 *)(iVar13 + (uint)*(byte *)(iVar7 + 8) * 3);
          iVar8 = iVar8 + 1;
          *(undefined1 *)(iVar9 + 0x12) =
               *(undefined1 *)((uint)*(byte *)(iVar7 + 8) * 3 + iVar13 + 1);
          *(undefined1 *)(iVar9 + 0x13) =
               *(undefined1 *)((uint)*(byte *)(iVar7 + 8) * 3 + iVar13 + 2);
        } while (iVar8 < 0x15);
      }
      else if (cVar1 == '\x03') {
        iVar8 = 0;
        do {
          iVar9 = iVar8 * 4 + iVar7;
          *(undefined1 *)(iVar9 + 0x11) = *(undefined1 *)(iVar13 + (uint)*(byte *)(iVar7 + 8) * 3);
          iVar8 = iVar8 + 1;
          *(undefined1 *)(iVar9 + 0x12) =
               *(undefined1 *)((uint)*(byte *)(iVar7 + 8) * 3 + iVar13 + 1);
          *(undefined1 *)(iVar9 + 0x13) =
               *(undefined1 *)((uint)*(byte *)(iVar7 + 8) * 3 + iVar13 + 2);
        } while (iVar8 < 0x15);
      }
      else if (cVar1 == '\x04') {
        iVar13 = 0;
        do {
          iVar8 = iVar13 * 4 + iVar7;
          *(undefined1 *)(iVar8 + 0x11) = *(undefined1 *)(iVar7 + 0xbe);
          *(undefined1 *)(iVar8 + 0x12) = *(undefined1 *)(iVar7 + 0xbf);
          iVar13 = iVar13 + 1;
          *(undefined1 *)(iVar8 + 0x13) = *(undefined1 *)(iVar5 + 0xc0);
        } while (iVar13 < 0x15);
      }
      uVar6 = 0;
      do {
        uVar11 = 0;
        do {
          FUN_01016926(uVar6 & 0xff,uVar11 & 0xff,*(undefined1 *)(iVar5 + 0xc1),
                       *(undefined1 *)(iVar5 + 0x6d),*(undefined1 *)(iVar5 + 0x6e),
                       *(undefined1 *)(iVar5 + 0x6f),1);
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < 0x11);
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 6);
    }
    iVar13 = DAT_01015214;
    if (*(char *)(DAT_01015214 + 6) == '\x01') {
      iVar7 = 0;
      do {
        iVar8 = iVar7 * 2 + iVar13;
        uVar6 = (uint)*(byte *)(iVar8 + 0x70) + (uint)*(byte *)(iVar8 + 0x71);
        if (uVar6 < 0xb) {
          *(char *)(iVar13 + iVar7 + 0xa7) = (char)uVar6;
        }
        else {
          *(undefined1 *)(iVar13 + iVar7 + 0xa7) = 0xb;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
    }
    else if (*(char *)(DAT_01015214 + 6) == '\x02') {
      iVar7 = 0;
      do {
        iVar8 = iVar7 * 2 + iVar13;
        uVar6 = (uint)*(byte *)(iVar8 + 0x70) + (uint)*(byte *)(iVar8 + 0x71);
        if (uVar6 < 0x15) {
          *(char *)(iVar13 + iVar7 + 0xa7) = (char)uVar6;
        }
        else {
          *(undefined1 *)(iVar13 + iVar7 + 0xa7) = 0x15;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
    }
    else {
      iVar7 = 0;
      do {
        iVar8 = iVar13 + iVar7;
        iVar7 = iVar7 + 1;
        *(undefined1 *)(iVar8 + 0xa7) = *(undefined1 *)(iVar8 + 0x70);
      } while (iVar7 < 0x15);
    }
    if (*(char *)(DAT_01015214 + 6) == '\x02') {
      iVar13 = 0;
      do {
        iVar7 = DAT_0101565c + iVar13;
        if (*(char *)(iVar7 + 0xa7) != '\0') {
          for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(iVar7 + 0xa7); iVar8 = iVar8 + 1) {
            iVar9 = iVar8 * 4 + DAT_0101565c;
            iVar10 = iVar13 * 0x2a + DAT_01015660;
            FUN_01016926(*(undefined1 *)(iVar10 + iVar8 * 2),*(undefined1 *)(iVar10 + iVar8 * 2 + 1)
                         ,*(undefined1 *)(iVar5 + 0xc1),*(undefined1 *)(iVar9 + 0x11),
                         *(undefined1 *)(iVar9 + 0x12),*(undefined1 *)(iVar9 + 0x13),1);
          }
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 6);
    }
    if (*(char *)(DAT_0101565c + 6) == '\x01') {
      iVar13 = 0;
      do {
        iVar7 = DAT_0101565c + iVar13;
        if (*(char *)(iVar7 + 0xa7) != '\0') {
          for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(iVar7 + 0xa7); iVar8 = iVar8 + 1) {
            iVar12 = iVar8 * 4 + DAT_0101565c;
            iVar9 = iVar13 * 0x16 + DAT_01015660 + 0xfc;
            iVar10 = (10 - iVar8) * 2;
            FUN_01016926(*(undefined1 *)(iVar9 + iVar10),*(undefined1 *)(iVar9 + iVar10 + 1),
                         *(undefined1 *)(iVar5 + 0xc1),*(undefined1 *)(iVar12 + 0x11),
                         *(undefined1 *)(iVar12 + 0x12),*(undefined1 *)(iVar12 + 0x13),1);
            iVar9 = iVar13 * 0x16 + DAT_01015664;
            FUN_01016926(*(undefined1 *)(iVar9 + iVar8 * 2),*(undefined1 *)(iVar9 + iVar8 * 2 + 1),
                         *(undefined1 *)(iVar5 + 0xc1),*(undefined1 *)(iVar12 + 0x11),
                         *(undefined1 *)(iVar12 + 0x12),*(undefined1 *)(iVar12 + 0x13),1);
          }
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 6);
    }
    if (*(char *)(DAT_0101565c + 6) == '\0') {
      iVar13 = 0;
      do {
        iVar7 = DAT_0101565c + iVar13;
        if (*(char *)(iVar7 + 0xa7) != '\0') {
          for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(iVar7 + 0xa7); iVar8 = iVar8 + 1) {
            iVar9 = iVar13 * 4 + DAT_0101565c;
            iVar10 = (5 - iVar8) * 0x2a + DAT_01015660;
            FUN_01016926(*(undefined1 *)(iVar10 + iVar13 * 2),
                         *(undefined1 *)(iVar10 + iVar13 * 2 + 1),*(undefined1 *)(iVar5 + 0xc1),
                         *(undefined1 *)(iVar9 + 0x11),*(undefined1 *)(iVar9 + 0x12),
                         *(undefined1 *)(iVar9 + 0x13),1);
          }
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0x15);
    }
  }
  return;
}


// ===== FUN_01015384 @ 01015384

void FUN_01015384(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  do {
    uVar1 = DAT_0101565c[1];
    uVar2 = DAT_0101565c[2];
    uVar3 = DAT_0101565c[3];
    iVar4 = 0;
    iVar6 = iVar5 * 0x10 + DAT_01015668;
    do {
      FUN_01016926(*(undefined1 *)(iVar6 + iVar4 * 2),*(undefined1 *)(iVar6 + iVar4 * 2 + 1),
                   *DAT_0101565c,uVar1,uVar2,uVar3,1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x15);
  return;
}


// ===== FUN_010153d6 @ 010153d6

void FUN_010153d6(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  iVar6 = DAT_0101566c;
  iVar5 = DAT_0101565c;
  if (*(char *)(DAT_0101565c + 3) != '\0') {
    cVar1 = *(char *)(DAT_0101565c + 7);
    if (cVar1 == '\x02') {
      if (*(byte *)(DAT_0101565c + 8) == 8) {
        iVar8 = 0xff;
      }
      else {
        iVar8 = 1;
      }
      iVar8 = ((uint)*(byte *)(DAT_0101565c + 8) + iVar8) * 3;
      iVar7 = 0;
      uVar4 = *(undefined1 *)(DAT_0101566c + iVar8);
      iVar8 = iVar8 + DAT_0101566c;
      uVar2 = *(undefined1 *)(iVar8 + 1);
      uVar3 = *(undefined1 *)(iVar8 + 2);
      do {
        *(undefined1 *)(iVar5 + 0x6d) = uVar4;
        *(undefined1 *)(iVar5 + 0x6e) = uVar2;
        iVar7 = iVar7 + 1;
        *(undefined1 *)(iVar5 + 0x6f) = uVar3;
      } while (iVar7 < 0x15);
    }
    else {
      *(undefined1 *)(DAT_0101565c + 0x6d) = 0;
      *(undefined1 *)(iVar5 + 0x6e) = 0;
      *(undefined1 *)(iVar5 + 0x6f) = 0;
    }
    iVar8 = DAT_0101565c;
    puVar11 = (undefined1 *)(DAT_0101565c + 0xc0);
    if (cVar1 == '\0') {
      iVar6 = 0;
      do {
        FUN_010169e6(iVar6 * 4 + iVar8 + 0x10,1);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x15);
    }
    else if (cVar1 == '\x01') {
      iVar6 = 0;
      do {
        FUN_010169e6(iVar6 * 4 + iVar8 + 0x10,1);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x15);
    }
    else if (cVar1 == '\x02') {
      iVar7 = 0;
      do {
        iVar10 = iVar7 * 4 + iVar8;
        *(undefined1 *)(iVar10 + 0x11) = *(undefined1 *)(iVar6 + (uint)*(byte *)(iVar8 + 8) * 3);
        iVar7 = iVar7 + 1;
        *(undefined1 *)(iVar10 + 0x12) = *(undefined1 *)((uint)*(byte *)(iVar8 + 8) * 3 + iVar6 + 1)
        ;
        *(undefined1 *)(iVar10 + 0x13) = *(undefined1 *)((uint)*(byte *)(iVar8 + 8) * 3 + iVar6 + 2)
        ;
      } while (iVar7 < 0x15);
    }
    else if (cVar1 == '\x03') {
      iVar7 = 0;
      do {
        iVar10 = iVar7 * 4 + iVar8;
        *(undefined1 *)(iVar10 + 0x11) = *(undefined1 *)(iVar6 + (uint)*(byte *)(iVar8 + 8) * 3);
        iVar7 = iVar7 + 1;
        *(undefined1 *)(iVar10 + 0x12) = *(undefined1 *)((uint)*(byte *)(iVar8 + 8) * 3 + iVar6 + 1)
        ;
        *(undefined1 *)(iVar10 + 0x13) = *(undefined1 *)((uint)*(byte *)(iVar8 + 8) * 3 + iVar6 + 2)
        ;
      } while (iVar7 < 0x15);
    }
    else if (cVar1 == '\x04') {
      iVar6 = 0;
      do {
        iVar7 = iVar6 * 4 + iVar8;
        *(undefined1 *)(iVar7 + 0x11) = *(undefined1 *)(iVar8 + 0xbe);
        *(undefined1 *)(iVar7 + 0x12) = *(undefined1 *)(iVar8 + 0xbf);
        iVar6 = iVar6 + 1;
        *(undefined1 *)(iVar7 + 0x13) = *puVar11;
      } while (iVar6 < 0x15);
    }
    uVar14 = 0;
    do {
      uVar12 = 0;
      do {
        FUN_01016926(uVar14 & 0xff,uVar12 & 0xff,*(undefined1 *)(iVar8 + 0xc1),
                     *(undefined1 *)(iVar5 + 0x6d),*(undefined1 *)(iVar5 + 0x6e),
                     *(undefined1 *)(iVar5 + 0x6f),1);
        iVar6 = DAT_0101565c;
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < 0x11);
      uVar14 = uVar14 + 1;
    } while ((int)uVar14 < 6);
    if (*(char *)(DAT_0101565c + 6) == '\x01') {
      iVar5 = 0;
      do {
        iVar7 = iVar5 * 2 + iVar6;
        uVar14 = (uint)*(byte *)(iVar7 + 0x70) + (uint)*(byte *)(iVar7 + 0x71);
        if (uVar14 < 0xb) {
          *(char *)(iVar6 + iVar5 + 0xa7) = (char)uVar14;
        }
        else {
          *(undefined1 *)(iVar6 + iVar5 + 0xa7) = 0xb;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
    }
    else if (*(char *)(DAT_0101565c + 6) == '\x02') {
      iVar5 = 0;
      do {
        iVar7 = iVar5 * 2 + iVar6;
        uVar14 = (uint)*(byte *)(iVar7 + 0x70) + (uint)*(byte *)(iVar7 + 0x71);
        if (uVar14 < 0x15) {
          *(char *)(iVar6 + iVar5 + 0xa7) = (char)uVar14;
        }
        else {
          *(undefined1 *)(iVar6 + iVar5 + 0xa7) = 0x15;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
    }
    else {
      iVar5 = 0;
      do {
        iVar7 = iVar6 + iVar5;
        iVar5 = iVar5 + 1;
        *(undefined1 *)(iVar7 + 0xa7) = *(undefined1 *)(iVar7 + 0x70);
      } while (iVar5 < 0x15);
    }
    if (*(char *)(DAT_0101565c + 6) == '\x02') {
      iVar5 = 0;
      do {
        iVar6 = DAT_0101565c + iVar5;
        if (*(char *)(iVar6 + 0xa7) != '\0') {
          for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar6 + 0xa7); iVar7 = iVar7 + 1) {
            iVar10 = iVar7 * 4 + DAT_0101565c;
            iVar9 = iVar5 * 0x2a + DAT_01015660;
            FUN_01016926(*(undefined1 *)(iVar9 + iVar7 * 2),*(undefined1 *)(iVar9 + iVar7 * 2 + 1),
                         *(undefined1 *)(iVar8 + 0xc1),*(undefined1 *)(iVar10 + 0x11),
                         *(undefined1 *)(iVar10 + 0x12),*(undefined1 *)(iVar10 + 0x13),1);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
    }
    if (*(char *)(DAT_0101565c + 6) == '\x01') {
      iVar5 = 0;
      do {
        iVar6 = DAT_0101565c + iVar5;
        if (*(char *)(iVar6 + 0xa7) != '\0') {
          for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar6 + 0xa7); iVar7 = iVar7 + 1) {
            iVar13 = iVar7 * 4 + DAT_0101565c;
            iVar10 = iVar5 * 0x16 + DAT_01015664 + -0x84;
            iVar9 = (10 - iVar7) * 2;
            FUN_01016926(*(undefined1 *)(iVar10 + iVar9),*(undefined1 *)(iVar10 + iVar9 + 1),
                         *(undefined1 *)(iVar8 + 0xc1),*(undefined1 *)(iVar13 + 0x11),
                         *(undefined1 *)(iVar13 + 0x12),*(undefined1 *)(iVar13 + 0x13),1);
            iVar10 = iVar5 * 0x16 + DAT_01015664;
            FUN_01016926(*(undefined1 *)(iVar10 + iVar7 * 2),*(undefined1 *)(iVar10 + iVar7 * 2 + 1)
                         ,*(undefined1 *)(iVar8 + 0xc1),*(undefined1 *)(iVar13 + 0x11),
                         *(undefined1 *)(iVar13 + 0x12),*(undefined1 *)(iVar13 + 0x13),1);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
    }
    if (*(char *)(DAT_01015a6c + 6) == '\0') {
      iVar5 = 0;
      do {
        iVar6 = DAT_01015a6c + iVar5;
        if (*(char *)(iVar6 + 0xa7) != '\0') {
          for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar6 + 0xa7); iVar7 = iVar7 + 1) {
            iVar10 = iVar5 * 4 + DAT_01015a6c;
            FUN_01016926(PTR_DAT_01015a70[iVar5 * 2 + (5 - iVar7) * 0x2a],
                         PTR_DAT_01015a70[iVar5 * 2 + (5 - iVar7) * 0x2a + 1],
                         *(undefined1 *)(iVar8 + 0xc1),*(undefined1 *)(iVar10 + 0x11),
                         *(undefined1 *)(iVar10 + 0x12),*(undefined1 *)(iVar10 + 0x13),1);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x15);
    }
  }
  return;
}


// ===== FUN_01015ca0 @ 01015ca0

void FUN_01015ca0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  iVar3 = DAT_01015e8c;
  piVar2 = DAT_01015e7c;
  if (*(char *)((int)DAT_01015e7c + 6) == '\0') {
    iVar8 = 0;
    do {
      iVar7 = 0;
      do {
        iVar5 = (uint)*(byte *)(DAT_01015e7c + 1) * 0x180 + DAT_01015e90 + iVar8 * 0x12;
        iVar4 = iVar5 + iVar7 * 3;
        iVar1 = iVar7 * 0x2a + 0xd0;
        FUN_01016926(PTR_DAT_01015e84[iVar8 * 2 + iVar1],PTR_DAT_01015e84[iVar8 * 2 + iVar1 + 1],
                     *(undefined1 *)(iVar3 + 1),*(undefined1 *)(iVar5 + iVar7 * 3),
                     *(undefined1 *)(iVar4 + 1),*(undefined1 *)(iVar4 + 2),1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x15);
  }
  else {
    iVar3 = *DAT_01015e7c;
    *DAT_01015e7c = iVar3 + 1;
    if (iVar3 + 1 == 0x28) {
      *piVar2 = 0;
      if (*(char *)((int)piVar2 + 5) == '\0') {
        uVar10 = *(undefined1 *)((int)DAT_01015e7c + 0x75);
        uVar9 = (undefined1)DAT_01015e7c[0x1d];
        uVar6 = *(undefined1 *)((int)DAT_01015e7c + 0x73);
      }
      else {
        uVar9 = 0xfe;
        uVar6 = 0xfe;
        uVar10 = 0xfe;
      }
      FUN_01016926(1,0xf,100,uVar6,uVar9,uVar10,1);
      *(bool *)((int)piVar2 + 5) = *(char *)((int)piVar2 + 5) != '\x01';
    }
  }
  return;
}


// ===== FUN_0101669a @ 0101669a
// decompile failed
// ===== FUN_01016926 @ 01016926

void FUN_01016926(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0xff) && (param_2 != 0xff)) {
    uVar1 = FUN_0101f134(param_7 * param_3 * param_4,100,param_3,param_3 * param_4,param_4);
    iVar2 = param_1 * 0x54 + DAT_01016d38;
    iVar3 = iVar2 + param_2 * 4;
    *(undefined1 *)(iVar3 + 1) = uVar1;
    uVar1 = FUN_0101f134(param_7 * param_3 * param_5,100);
    *(undefined1 *)(iVar3 + 2) = uVar1;
    uVar1 = FUN_0101f134(param_7 * param_3 * param_6,100);
    *(undefined1 *)(iVar3 + 3) = uVar1;
    *(char *)(iVar2 + param_2 * 4) = (char)param_3;
  }
  return;
}


// ===== FUN_010169e6 @ 010169e6

void FUN_010169e6(char *param_1,uint param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  
LAB_01016a60:
  while( true ) {
    uVar1 = param_2 - 1 & 0xff;
    if (param_2 == 0) {
      return;
    }
    cVar2 = *param_1;
    param_2 = uVar1;
    if (cVar2 != '\0') break;
    uVar1 = (uint)(byte)param_1[1] + param_3;
    if (uVar1 < 0xff) {
LAB_01016a10:
      param_1[1] = (char)uVar1;
    }
    else {
      param_1[1] = -1;
LAB_01016a54:
      *param_1 = '\x01';
    }
  }
  if (cVar2 == '\x01') {
    if ((uint)(byte)param_1[2] + param_3 < 0xff) {
      param_1[2] = (char)((uint)(byte)param_1[2] + param_3);
      uVar1 = (uint)(byte)param_1[1] - param_3;
      goto LAB_01016a10;
    }
    param_1[2] = -1;
    param_1[1] = '\0';
    cVar2 = '\x02';
  }
  else {
    if (cVar2 != '\x02') {
      if (cVar2 == '\x03') {
        if (0xfe < (uint)(byte)param_1[1] + param_3) {
          param_1[1] = -1;
          param_1[3] = '\0';
          goto LAB_01016a54;
        }
        param_1[1] = (char)((uint)(byte)param_1[1] + param_3);
        param_1[3] = param_1[3] - (char)param_3;
      }
      goto LAB_01016a60;
    }
    if ((uint)(byte)param_1[3] + param_3 < 0xff) {
      param_1[3] = (char)((uint)(byte)param_1[3] + param_3);
      param_1[2] = param_1[2] - (char)param_3;
      goto LAB_01016a60;
    }
    param_1[3] = -1;
    param_1[2] = '\0';
    cVar2 = '\x03';
  }
  *param_1 = cVar2;
  goto LAB_01016a60;
}


// ===== FUN_01016a6c @ 01016a6c

void FUN_01016a6c(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  byte extraout_r1;
  uint uVar8;
  undefined1 uVar9;
  bool bVar10;
  undefined1 local_1c;
  undefined1 local_1b;
  
  iVar5 = param_1 * 0x34 + DAT_01016d40;
  uVar3 = *(undefined1 *)(iVar5 + param_2 * 2);
  uVar1 = *(undefined1 *)(iVar5 + param_2 * 2 + 1);
  uVar6 = FUN_0101f188();
  FUN_0101f160(uVar6,6);
  cVar2 = *(char *)(DAT_01016d44 + 0x1a);
  uVar8 = (uint)extraout_r1;
  if (cVar2 != '\x05') {
    if (cVar2 == '\n') {
      uVar7 = (uint)*(byte *)(DAT_01016d4c + 0x8e);
      if ((uVar7 < 7) || (bVar10 = uVar7 == 8, uVar7 = uVar8, bVar10)) {
        local_1c = *(undefined1 *)(DAT_01016d48 + uVar7 * 3);
        iVar5 = uVar7 * 3 + DAT_01016d48;
        local_1b = *(undefined1 *)(iVar5 + 1);
        uVar4 = *(undefined1 *)(iVar5 + 2);
      }
      else {
        local_1c = *(undefined1 *)(DAT_01016d4c + 0x91);
        local_1b = *(undefined1 *)(DAT_01016d4c + 0x92);
        uVar4 = *(undefined1 *)(DAT_01016d4c + 0x93);
      }
      uVar9 = *(undefined1 *)(DAT_01016d4c + 0x8d);
      goto LAB_01016b64;
    }
    if (cVar2 != '\x0e') {
      if (cVar2 != '\x18') {
        return;
      }
      uVar7 = (uint)*(byte *)(DAT_01016d4c + 0xc);
      if ((uVar7 < 7) || (bVar10 = uVar7 == 8, uVar7 = uVar8, bVar10)) {
        local_1c = *(undefined1 *)(DAT_01016d48 + uVar7 * 3);
        iVar5 = uVar7 * 3 + DAT_01016d48;
        local_1b = *(undefined1 *)(iVar5 + 1);
        uVar4 = *(undefined1 *)(iVar5 + 2);
      }
      else {
        local_1c = *(undefined1 *)(DAT_01016d4c + 0x51);
        local_1b = *(undefined1 *)(DAT_01016d4c + 0x52);
        uVar4 = *(undefined1 *)(DAT_01016d4c + 0x53);
      }
      uVar9 = *(undefined1 *)(DAT_01016d4c + 0x50);
      goto LAB_01016b64;
    }
  }
  uVar7 = (uint)*(byte *)(DAT_01016d4c + 0xc);
  if ((uVar7 < 7) || (bVar10 = uVar7 == 8, uVar7 = uVar8, bVar10)) {
    local_1c = *(undefined1 *)(DAT_01016d48 + uVar7 * 3);
    iVar5 = uVar7 * 3 + DAT_01016d48;
    local_1b = *(undefined1 *)(iVar5 + 1);
    uVar4 = *(undefined1 *)(iVar5 + 2);
  }
  else {
    local_1c = *(undefined1 *)(DAT_01016d4c + 0x4f);
    local_1b = *(undefined1 *)(DAT_01016d4c + 0x50);
    uVar4 = *(undefined1 *)(DAT_01016d4c + 0x51);
  }
  uVar9 = *(undefined1 *)(DAT_01016d4c + 0x4e);
LAB_01016b64:
  FUN_01016926(uVar3,uVar1,uVar9,local_1c,local_1b,uVar4,1);
  return;
}


// ===== FUN_01016bb2 @ 01016bb2

longlong FUN_01016bb2(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint local_20;
  
  local_20 = param_3;
  for (uVar1 = 0; local_20 = local_20 & 0xff, uVar1 <= param_3; uVar1 = uVar1 + 1 & 0xff) {
    if ((uVar1 <= param_1) && (local_20 <= param_2)) {
      FUN_01016a6c(param_1 - uVar1 & 0xff,param_2 - local_20 & 0xff);
    }
    if ((uVar1 <= param_1) && (param_2 + param_3 < 0x1a)) {
      FUN_01016a6c(param_1 - uVar1 & 0xff,param_2 + param_3 & 0xff);
    }
    uVar2 = param_1 + uVar1;
    if (uVar2 < 6) {
      if (param_2 + local_20 < 0x1a) {
        FUN_01016a6c(uVar2 & 0xff,param_2 + local_20 & 0xff);
      }
      if (param_3 <= param_2) {
        FUN_01016a6c(uVar2 & 0xff,param_2 - param_3 & 0xff);
      }
    }
    local_20 = local_20 - 1;
  }
  uVar1 = param_1 + param_3;
  for (uVar2 = 0; uVar2 <= param_3; uVar2 = uVar2 + 1 & 0xff) {
    if ((param_3 <= param_1) && (param_2 + uVar2 < 0x1a)) {
      FUN_01016a6c(param_1 - param_3 & 0xff,param_2 + uVar2 & 0xff);
    }
    if ((uVar1 < 6) && (uVar2 <= param_2)) {
      FUN_01016a6c(uVar1 & 0xff,param_2 - uVar2 & 0xff);
    }
  }
  if (param_3 < 0x1a) {
    return CONCAT44(uVar1,1);
  }
  return (ulonglong)uVar1 << 0x20;
}


// ===== FUN_01016c70 @ 01016c70

void FUN_01016c70(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  byte extraout_r1;
  byte bVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined2 uVar13;
  
  iVar11 = DAT_01017138;
  iVar5 = DAT_01016d4c;
  iVar9 = param_1 * 0x2a + DAT_01016d50;
  bVar2 = *(byte *)(iVar9 + param_2 * 2);
  uVar8 = (uint)bVar2;
  bVar7 = *(byte *)(iVar9 + param_2 * 2 + 1);
  uVar10 = (uint)bVar7;
  bVar1 = *(byte *)(DAT_01016d44 + 0x1a);
  uVar12 = *(uint *)(DAT_01016d4c + 8);
  if (bVar1 != 0xd) {
    if (0xd < bVar1) {
      if (bVar1 != 0xe) {
        if (bVar1 != 0x13) {
          return;
        }
        if (param_3 == 0) {
          iVar5 = uVar8 * 0x34 + DAT_0101712c;
          uVar8 = (uint)*(byte *)(iVar5 + uVar10 * 2);
          if (5 < uVar8) {
            return;
          }
          uVar10 = (uint)*(byte *)(iVar5 + uVar10 * 2 + 1);
          if (0x14 < uVar10) {
            return;
          }
          uVar3 = 2;
        }
        else {
          iVar5 = uVar8 * 0x34 + DAT_01016d40;
          uVar8 = (uint)*(byte *)(iVar5 + uVar10 * 2);
          if (5 < uVar8) {
            return;
          }
          uVar10 = (uint)*(byte *)(iVar5 + uVar10 * 2 + 1);
          if (0x14 < uVar10) {
            return;
          }
          uVar3 = 1;
        }
        iVar11 = uVar10 + DAT_01016d4c;
        *(undefined1 *)(iVar11 + uVar8 * 0x15 + 0xc6) = uVar3;
        uVar3 = 0;
        iVar5 = uVar8 * 0x15 + 0x45;
LAB_01016e36:
        *(undefined1 *)(iVar11 + iVar5) = uVar3;
        return;
      }
      if (param_3 == 0) {
        return;
      }
      iVar11 = uVar8 * 0x34 + DAT_0101712c;
      if (5 < *(byte *)(iVar11 + uVar10 * 2)) {
        return;
      }
      if (0x14 < *(byte *)(iVar11 + uVar10 * 2 + 1)) {
        return;
      }
      if (uVar12 == DAT_01017130) {
        return;
      }
      uVar10 = 0;
      uVar8 = 0;
      while ((uVar12 & 1 << (uVar8 & 0xff)) != 0) {
        uVar8 = uVar8 + 1;
        uVar10 = uVar10 + 1 & 0xffff;
        if (0xf < (int)uVar8) {
          return;
        }
      }
LAB_01016d58:
      iVar11 = uVar10 * 4 + DAT_01016d4c;
      *(byte *)(iVar11 + 0xe) = bVar2;
      *(byte *)(iVar11 + 0xf) = bVar7;
      *(undefined2 *)(iVar11 + 0x10) = 0;
      *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 1 << (uVar8 & 0xff);
      return;
    }
    if (bVar1 == 5) {
      if (param_3 == 0) {
        return;
      }
      iVar11 = uVar8 * 0x34 + DAT_01016d40;
      if (5 < *(byte *)(iVar11 + uVar10 * 2)) {
        return;
      }
      if (0x14 < *(byte *)(iVar11 + uVar10 * 2 + 1)) {
        return;
      }
      if (uVar12 == DAT_01016d54) {
        return;
      }
      uVar10 = 0;
      uVar8 = 0;
      while ((uVar12 & 1 << (uVar8 & 0xff)) != 0) {
        uVar8 = uVar8 + 1;
        uVar10 = uVar10 + 1 & 0xffff;
        if (0xf < (int)uVar8) {
          return;
        }
      }
      goto LAB_01016d58;
    }
    if (bVar1 != 8) {
      return;
    }
    if (param_3 == 0) {
      iVar5 = uVar8 * 0x34 + DAT_0101712c;
      uVar8 = (uint)*(byte *)(iVar5 + uVar10 * 2);
      if (5 < uVar8) {
        return;
      }
      uVar10 = (uint)*(byte *)(iVar5 + uVar10 * 2 + 1);
      if (0x14 < uVar10) {
        return;
      }
      iVar5 = uVar8 * 0x15;
      iVar11 = uVar10 + DAT_01016d4c;
      *(undefined1 *)(iVar11 + iVar5 + 0x200) = 2;
      uVar3 = 100;
      iVar5 = iVar5 + 0x17f;
      goto LAB_01016e36;
    }
    iVar11 = uVar10 * 2;
    iVar9 = uVar8 * 0x34 + DAT_01016d40;
    if (5 < *(byte *)(iVar9 + iVar11)) {
      return;
    }
    if (0x14 < *(byte *)(iVar9 + iVar11 + 1)) {
      return;
    }
    uVar8 = (uint)*(byte *)(DAT_01016d4c + 3);
    if (6 < uVar8) {
      if (uVar8 != 8) {
        uVar13 = *(undefined2 *)(DAT_01017134 + 0x1d);
        uVar3 = *(undefined1 *)(DAT_01017134 + 0x1f);
        goto LAB_01016dc6;
      }
      uVar6 = FUN_0101f188();
      FUN_0101f160(uVar6,6);
      uVar8 = (uint)extraout_r1;
    }
    iVar4 = uVar8 * 3 + DAT_01016d48;
    uVar13 = CONCAT11(*(undefined1 *)(iVar4 + 1),*(undefined1 *)(DAT_01016d48 + uVar8 * 3));
    uVar3 = *(undefined1 *)(iVar4 + 2);
LAB_01016dc6:
    bVar7 = *(byte *)(iVar9 + iVar11);
    uVar8 = (uint)*(byte *)(iVar9 + iVar11 + 1);
    *(undefined1 *)(uVar8 + iVar5 + (uint)bVar7 * 0x15 + 0x200) = 1;
    iVar5 = (uint)bVar7 * 0x3f + iVar5 + uVar8 * 3;
    *(char *)(iVar5 + 4) = (char)uVar13;
    *(char *)(iVar5 + 5) = (char)((ushort)uVar13 >> 8);
    *(undefined1 *)(iVar5 + 6) = uVar3;
    return;
  }
  if (*(char *)(DAT_01016d4c + 6) == '\0') {
    return;
  }
  if (5 < param_1) {
    return;
  }
  if (0x14 < param_2) {
    return;
  }
  iVar5 = param_1 * 0x3f + DAT_01017138 + param_2 * 3;
  iVar9 = param_1 * 0x15 + DAT_01017138 + param_2;
  if (param_1 == 5) {
    if (param_2 != 10) goto LAB_01016eaa;
  }
  else if ((param_1 != 1) || (param_2 != 0xf)) {
LAB_01016eaa:
    if (param_3 == 0) {
      return;
    }
    goto LAB_01016ede;
  }
  if (param_3 != 0) {
    return;
  }
  if (param_1 == 5) {
    if ((param_2 == 10) && (*(char *)(DAT_01017138 + 0x182) != '\0')) {
      *(undefined1 *)(DAT_01017138 + 0x182) = 0;
      return;
    }
  }
  else if (((param_1 == 1) && (param_2 == 0xf)) && (*(char *)(DAT_01017138 + 0x183) != '\0')) {
    *(undefined1 *)(DAT_01017138 + 0x183) = 0;
    return;
  }
LAB_01016ede:
  bVar7 = *(char *)(iVar9 + 0x184) + 1;
  *(byte *)(iVar9 + 0x184) = bVar7;
  if (8 < bVar7) {
    bVar7 = 0;
    *(undefined1 *)(iVar9 + 0x184) = 0;
  }
  iVar4 = DAT_0101713c;
  *(undefined1 *)(iVar5 + 7) = *(undefined1 *)(DAT_0101713c + (uint)bVar7 * 3);
  *(undefined1 *)(iVar5 + 8) = *(undefined1 *)((uint)*(byte *)(iVar9 + 0x184) * 3 + iVar4 + 1);
  uVar3 = *(undefined1 *)((uint)*(byte *)(iVar9 + 0x184) * 3 + iVar4 + 2);
  *(undefined1 *)(iVar5 + 9) = uVar3;
  FUN_01016926(param_1 & 0xff,param_2 & 0xff,*(undefined1 *)(iVar11 + 0x181),
               *(undefined1 *)(iVar5 + 7),*(undefined1 *)(iVar5 + 8),uVar3,1);
  return;
}


// ===== FUN_01016f2a @ 01016f2a

void FUN_01016f2a(uint param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  do {
    iVar9 = 0;
    iVar3 = iVar10 * 0x34 + DAT_0101712c;
    do {
      uVar5 = (uint)*(byte *)(iVar3 + iVar9 * 2);
      if ((uVar5 < 6) && (uVar4 = (uint)*(byte *)(iVar3 + iVar9 * 2 + 1), uVar4 < 0x15)) {
        iVar8 = uVar5 * 0x54 + DAT_01017140;
        iVar6 = uVar4 * 4;
        bVar1 = *(byte *)(iVar8 + iVar6);
        if (bVar1 != 0) {
          if (bVar1 < param_1) {
            cVar2 = '\0';
          }
          else {
            cVar2 = bVar1 - (char)param_1;
          }
          *(char *)(iVar8 + iVar6) = cVar2;
          iVar7 = iVar8 + iVar6;
          FUN_01016926(uVar5,uVar4,*(undefined1 *)(iVar8 + iVar6),*(undefined1 *)(iVar7 + 1),
                       *(undefined1 *)(iVar7 + 2),*(undefined1 *)(iVar7 + 3),1);
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x1a);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 6);
  return;
}


// ===== FUN_01016f9e @ 01016f9e
// decompile failed
// ===== FUN_0101700c @ 0101700c

void FUN_0101700c(void)

{
  return;
}


// ===== FUN_010170dc @ 010170dc

void FUN_010170dc(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  do {
    iVar3 = iVar6 * 0x54 + DAT_01017164;
    iVar4 = 0;
    iVar2 = iVar6 * 0x54 + DAT_01017140;
    do {
      iVar5 = iVar4 * 4;
      *(undefined1 *)(iVar3 + iVar5) = *(undefined1 *)(iVar2 + iVar5);
      iVar7 = iVar2 + iVar5;
      uVar1 = FUN_0101f134((uint)*(byte *)(iVar7 + 1) * 0x32,100);
      iVar4 = iVar4 + 1;
      iVar5 = iVar3 + iVar5;
      *(undefined1 *)(iVar5 + 1) = uVar1;
      *(undefined1 *)(iVar5 + 2) = *(undefined1 *)(iVar7 + 2);
      *(undefined1 *)(iVar5 + 3) = *(undefined1 *)(iVar7 + 3);
    } while (iVar4 < 0x15);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 6);
  return;
}


// ===== FUN_010171bc @ 010171bc

void FUN_010171bc(void)

{
  return;
}


// ===== FUN_010171be @ 010171be

void FUN_010171be(void)

{
  return;
}


// ===== FUN_01017860 @ 01017860

ulonglong FUN_01017860(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_0101e1c4(5);
  FUN_0101abd8(0,2,9);
  FUN_0101abd8(0,1,8);
  uVar1 = DAT_01017c68;
  FUN_0101b326();
  FUN_0101b1e8(0,2,1);
  FUN_0101b600(0,1);
  return CONCAT44(uVar1,param_1) & 0xffffffffffffff00;
}


// ===== FUN_010178a0 @ 010178a0

void FUN_010178a0(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = DAT_01017c70;
  pbVar1 = DAT_01017c6c;
  if ((int)((uint)*DAT_01017c6c << 0x1e) < 0) {
    FUN_0101b5b4(0,*DAT_01017c70);
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)puVar2[1]; iVar3 = iVar3 + 1) {
      FUN_0101b5b4(0,puVar2[iVar3 + 1]);
    }
    FUN_0101b5b4(0,DAT_01017c70[0x53]);
    *pbVar1 = *pbVar1 & 0xfd | 4;
  }
  return;
}


// ===== FUN_010178e4 @ 010178e4

void FUN_010178e4(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = DAT_01017c6c;
  bVar1 = *DAT_01017c6c;
  if ((int)((uint)bVar1 << 0x1d) < 0) {
    pbVar4 = DAT_01017c6c + -0xf;
    bVar2 = *pbVar4;
    *pbVar4 = bVar2 + 1;
    if (199 < (byte)(bVar2 + 1)) {
      *pbVar4 = 0;
      *pbVar3 = bVar1 | 3;
      bVar1 = pbVar3[-0xe];
      pbVar3[-0xe] = bVar1 + 1;
      if (0x13 < (byte)(bVar1 + 1)) {
        pbVar3[-0xffffffff00000004] = 0;
        pbVar3[-0xffffffff00000003] = 0;
        pbVar3[-0xffffffff00000002] = 0;
        pbVar3[-0xffffffff00000001] = 0;
        pbVar3[-0xe] = 0;
      }
    }
  }
  return;
}


// ===== FUN_0101791c @ 0101791c

void FUN_0101791c(void)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = DAT_01017c6c;
  pbVar2 = DAT_01017c6c + -0xf;
  DAT_01017c6c[-0xe] = 0;
  *pbVar1 = *pbVar1 & 0xfb;
  *pbVar2 = 0;
  return;
}


// ===== FUN_01017934 @ 01017934

void FUN_01017934(void)

{
  *DAT_01017c6c = *DAT_01017c6c | 8;
  DAT_01017c6c[-0xc] = 0;
  return;
}


// ===== FUN_01017948 @ 01017948

void FUN_01017948(void)

{
  DAT_01017c6c[-0xb] = 0;
  *DAT_01017c6c = *DAT_01017c6c & 0xf7;
  return;
}


// ===== FUN_0101795c @ 0101795c

void FUN_0101795c(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = DAT_01017c6c;
  bVar1 = *DAT_01017c6c;
  if ((int)((uint)bVar1 << 0x1c) < 0) {
    pbVar4 = DAT_01017c6c + -0xc;
    bVar2 = *pbVar4;
    *pbVar4 = bVar2 + 1;
    if (199 < (byte)(bVar2 + 1)) {
      *pbVar4 = 0;
      bVar1 = bVar1 | 3;
      *pbVar3 = bVar1;
      bVar2 = pbVar3[-0xb];
      pbVar3[-0xb] = bVar2 + 1;
      if (0x27 < (byte)(bVar2 + 1)) {
        *pbVar3 = bVar1 & 0xfd;
      }
    }
  }
  return;
}


// ===== FUN_01017992 @ 01017992

void FUN_01017992(void)

{
  if ((*(char *)(DAT_01017c6c + -0x10) == '\x01') || (*(char *)(DAT_01017c6c + -0x10) == '\x04')) {
    *(undefined4 *)(DAT_01017c6c + -4) = 0;
  }
  return;
}


// ===== FUN_010179aa @ 010179aa

void FUN_010179aa(void)

{
  byte bVar1;
  int extraout_r2;
  int extraout_r2_00;
  
  bVar1 = *(byte *)(DAT_01017c70 + 0xb2);
  if (bVar1 == 0x96) {
    FUN_01018c0e(DAT_01017c70 + 0xb3);
    return;
  }
  if (0x96 < bVar1) {
    if (bVar1 == 0xc1) {
      FUN_01018c46(DAT_01017c70 + 0xb3);
      return;
    }
    if (bVar1 < 0xc2) {
      if (bVar1 == 0xa1) {
        FUN_01018c1c(DAT_01017c70 + 0xb3);
        return;
      }
      if (bVar1 == 0xa2) {
        FUN_01018c2a(DAT_01017c70 + 0xb3);
        return;
      }
      if (bVar1 != 0xb1) {
        return;
      }
      FUN_01018c38(DAT_01017c70 + 0xb3);
    }
    else {
      if (bVar1 == 0xf1) {
        FUN_01017992(1);
        FUN_01018c5c(extraout_r2 + 1);
        return;
      }
      if (bVar1 == 0xf5) {
        FUN_01017992(1);
        FUN_01018c80(extraout_r2_00 + 3);
        return;
      }
      if (bVar1 == 0xff) {
        FUN_01018c54(DAT_01017c70 + 0xb3);
        return;
      }
    }
    return;
  }
  if (bVar1 == 0x91) {
    FUN_01018bc8(DAT_01017c70 + 0xb3);
    return;
  }
  if (bVar1 < 0x92) {
    if (bVar1 == 0x81) {
      FUN_01018a38(DAT_01017c70 + 0xb3);
      return;
    }
    if (bVar1 == 0x82) {
      FUN_01018a66(DAT_01017c70 + 0xb3);
      return;
    }
    if (bVar1 == 0x86) {
      FUN_01018b6c(DAT_01017c70 + 0xb3);
    }
  }
  else {
    if (bVar1 == 0x92) {
      FUN_01018bf2(DAT_01017c70 + 0xb3);
      return;
    }
    if (bVar1 == 0x94) {
      FUN_01018bd6(DAT_01017c70 + 0xb3);
      return;
    }
    if (bVar1 == 0x95) {
      FUN_01018c00(DAT_01017c70 + 0xb3);
      return;
    }
  }
  return;
}


// ===== FUN_01017a78 @ 01017a78

void FUN_01017a78(void)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  
  iVar2 = DAT_01017c70;
  cVar5 = '\0';
  pcVar7 = (char *)(DAT_01017c70 + 0x54);
  if (*pcVar7 == '\0') {
    return;
  }
  bVar3 = *(char *)(DAT_01017c70 + 0x55) + 1;
  *(byte *)(DAT_01017c70 + 0x55) = bVar3;
  if (bVar3 < 2) {
    return;
  }
  *(undefined1 *)(iVar2 + 0x55) = 0;
  pbVar1 = DAT_01017c6c;
  *pcVar7 = '\0';
  if (-1 < (int)((uint)*pbVar1 << 0x1d)) goto LAB_01017b0e;
  iVar6 = *(int *)(DAT_01017c6c + 4);
  if ((uint)*(byte *)(iVar2 + 0xb1) == iVar6 - 2U) {
    for (uVar4 = 1; uVar4 < iVar6 - 1U; uVar4 = uVar4 + 1) {
      cVar5 = *(char *)(iVar2 + 0xb0 + uVar4) + cVar5;
    }
    if (*(char *)(iVar2 + 0xb0 + iVar6 + -1) != cVar5) goto LAB_01017ad4;
    *(undefined1 *)(iVar2 + 0x56) = 1;
LAB_01017ada:
    *(undefined1 *)(iVar2 + 0x56) = 0;
    *(undefined1 *)(iVar2 + 0x5a) = 0;
    FUN_010179aa();
    if (*(char *)(iVar2 + 0x5a) == '\0') {
      FUN_01017948();
      goto LAB_01017b0e;
    }
    if (((DAT_01017c6c[-0x10] == 3) && (*(char *)(DAT_01017c74 + 0xc) == '\x05')) &&
       ((cVar5 = *(char *)(DAT_01017c70 + 2), cVar5 == '\x11' ||
        ((cVar5 == '\x14' || (cVar5 == '\x12')))))) goto LAB_01017b0e;
  }
  else {
LAB_01017ad4:
    if (*(char *)(iVar2 + 0x56) != '\0') goto LAB_01017ada;
  }
  FUN_01017934();
LAB_01017b0e:
  FUN_0101071c();
  FUN_0101791c();
  return;
}


// ===== FUN_01017b1e @ 01017b1e

void FUN_01017b1e(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  
  iVar2 = DAT_01017c70;
  cVar1 = *(char *)(DAT_01017c6c + -0x10);
  if ((((cVar1 == '\x01') || (cVar1 == '\x03')) || (cVar1 == '\x04')) ||
     ((cVar1 == '\b' || (cVar1 == '\a')))) {
    uVar3 = FUN_0101f134(*(undefined2 *)(DAT_01017c70 + 0x5e),5);
    uVar4 = *(short *)(iVar2 + 0x5c) + 1;
    *(ushort *)(iVar2 + 0x5c) = uVar4;
    if (uVar3 <= uVar4) {
      *(undefined2 *)(iVar2 + 0x5c) = 0;
      *(byte *)(DAT_01017c6c + -8) = *(byte *)(DAT_01017c6c + -8) | 0x40;
    }
  }
  return;
}


// ===== FUN_01017b64 @ 01017b64

void FUN_01017b64(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_01017c70;
  if ((param_1 == 0) || (param_1 == 1)) {
    *(undefined2 *)(DAT_01017c70 + 0x5e) = 0xff;
  }
  else {
    if (param_1 == 3) {
      uVar2 = 500;
    }
    else {
      if (param_1 != 4) goto LAB_01017b8a;
      uVar2 = 5;
    }
    *(undefined2 *)(DAT_01017c70 + 0x5e) = uVar2;
  }
LAB_01017b8a:
  *(byte *)(DAT_01017c6c + -8) = *(byte *)(DAT_01017c6c + -8) & 0xbf;
  *(undefined2 *)(iVar1 + 0x5c) = 0;
  return;
}


// ===== FUN_01017b9c @ 01017b9c

void FUN_01017b9c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  
  iVar4 = DAT_01017c74;
  iVar3 = DAT_01017c70;
  if (-1 < (int)((uint)*(ushort *)(DAT_01017c78 + 0x1c) << 0x19)) {
    return;
  }
  cVar1 = *(char *)(DAT_01017c70 + 0xa2);
  uVar7 = (uint)*(byte *)(DAT_01017c70 + 0xa1);
  bVar2 = *(byte *)(DAT_01017c70 + 0x98);
  if ((cVar1 == '\0') && (uVar7 == 0)) {
    *(char *)(DAT_01017c70 + 0x99) = (char)param_1;
    uVar7 = iVar3 + 0x6c;
    if (bVar2 <= param_1) {
      *(undefined4 *)(iVar3 + 0x9c) = 0;
      goto LAB_01017c3e;
    }
    uVar6 = *(int *)(iVar3 + 0x9c) + 1;
    *(uint *)(iVar3 + 0x9c) = uVar6;
    if (uVar6 < 4000) goto LAB_01017c3e;
    *(undefined4 *)(iVar3 + 0x9c) = 0;
    *(byte *)(iVar3 + 0x98) = bVar2 - 1;
  }
  else {
    bVar8 = *(char *)(DAT_01017c70 + 0xa3) + 1;
    *(byte *)(DAT_01017c70 + 0xa3) = bVar8;
    if ((bVar8 < 10) || (*(undefined1 *)(iVar3 + 0xa3) = 0, param_1 == 0)) goto LAB_01017c3e;
    if (cVar1 == '\0') {
      if (uVar7 == 1) {
        if (param_1 <= bVar2) {
          *(undefined1 *)(iVar4 + 0x16) = 0;
          *(undefined1 *)(iVar3 + 0xa1) = 0;
          FUN_0101e318(1,0,1,0,param_4);
          if (*(char *)(iVar3 + 0x98) == '\0') {
            *(undefined1 *)(iVar3 + 0xa2) = 1;
          }
          goto LAB_01017c3e;
        }
        *(undefined1 *)(iVar3 + 0xa1) = 0;
        if (99 < param_1) {
          param_1 = 99;
        }
      }
      else {
        if (uVar7 != 2) goto LAB_01017c3e;
        *(undefined1 *)(iVar3 + 0xa1) = 0;
        param_1 = 100;
      }
    }
    else {
      *(undefined1 *)(iVar3 + 0xa2) = 0;
      *(undefined1 *)(iVar3 + 0xa1) = 0;
    }
    *(char *)(iVar3 + 0x98) = (char)param_1;
    *(char *)(iVar3 + 0x99) = (char)param_1;
  }
  *(undefined1 *)(iVar4 + 0x16) = 0;
  FUN_0101e318(1,0,uVar7,0,param_4);
LAB_01017c3e:
  if (*(char *)(iVar3 + 0xa8) == '\0') {
    uVar5 = FUN_0101f134(*(byte *)(iVar3 + 0x98) + 5,10);
    *(undefined1 *)(iVar3 + 0x9a) = uVar5;
  }
  return;
}


// ===== FUN_01017c52 @ 01017c52

void FUN_01017c52(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_01017c6c;
  if (*(byte *)(DAT_01017c6c + -0x10) != param_1) {
    *(byte *)(DAT_01017c6c + -0x10) = (byte)param_1;
    *(undefined4 *)(iVar1 + -4) = 0;
  }
  return;
}


// ===== FUN_01017c7e @ 01017c7e

void FUN_01017c7e(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  byte *extraout_r3;
  
  pbVar2 = DAT_01018084;
  iVar1 = DAT_01018080;
  if ((int)((uint)*(ushort *)(DAT_0101807c + 0x1c) * 0x2000000) < 0) {
    if ((*(char *)(DAT_01018080 + 0x36) == '\0') && (*(char *)(DAT_01018080 + 0x35) == '\0')) {
      if ((*(byte *)(DAT_01018080 + 0x2c) < 0x1e) &&
         ((*(byte *)(DAT_01018080 + 0x2c) != 0 && (*(char *)(DAT_01018080 + 0x38) == '\0')))) {
        *(undefined1 *)(DAT_01018080 + 0x38) = 1;
        iVar3 = DAT_01018088;
        *(undefined1 *)(iVar1 + 0x39) = 0;
        *(undefined1 *)(iVar3 + 0x16) = 3;
        FUN_0101e318(1,0,param_3,param_4,param_4);
      }
      if (*(byte *)(iVar1 + 0x3a) == param_2) {
        *(undefined2 *)(iVar1 + 6) = 0;
        return;
      }
      uVar4 = FUN_0101f134(DAT_0101808c,*(undefined2 *)(DAT_01018080 + -0xe));
      uVar5 = *(short *)(iVar1 + 6) + 1;
      *(ushort *)(iVar1 + 6) = uVar5;
      if (uVar4 <= uVar5) {
        *(char *)(iVar1 + 0x3a) = (char)param_2;
        if (param_2 == 0) {
          FUN_01010984();
          return;
        }
        *DAT_01018084 = *DAT_01018084 | 1;
        *(undefined1 *)(iVar1 + 0x3b) = 1;
        FUN_01017c52(7);
        *(undefined1 *)(iVar1 + 0x38) = 1;
        *(undefined1 *)(iVar1 + 0x39) = 0;
        iVar1 = DAT_01018088;
        *extraout_r3 = *extraout_r3 | 1;
        *(undefined1 *)(iVar1 + 0x16) = 3;
        FUN_0101e318(1,0);
        return;
      }
    }
  }
  else {
    if (*(char *)(DAT_01018080 + 0x38) != '\0') {
      *(undefined1 *)(DAT_01018080 + 0x38) = 0;
      *pbVar2 = *pbVar2 | 1;
      *(undefined1 *)(iVar1 + 0x39) = 0;
      *(undefined2 *)(iVar1 + 2) = 0;
    }
    pbVar2 = DAT_01018084;
    if (*(char *)(iVar1 + 0x3a) != '\0') {
      *(undefined1 *)(iVar1 + 0x3a) = 0;
      *pbVar2 = *pbVar2 | 1;
      FUN_01010984();
      *(undefined2 *)(iVar1 + 4) = 0;
    }
  }
  return;
}


// ===== FUN_01017d4c @ 01017d4c
// decompile failed
// ===== FUN_010180e2 @ 010180e2

void FUN_010180e2(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  
  iVar6 = DAT_0101849c;
  pbVar5 = DAT_01018498;
  if (*(int *)DAT_01018498 == 0) {
    return;
  }
  pbVar11 = DAT_01018498 + 8;
  if ((int)((uint)*pbVar11 << 0x1e) < 0) {
    return;
  }
  if ((int)((uint)*pbVar11 << 0x1d) < 0) {
    return;
  }
  bVar1 = DAT_01018498[2];
  uVar10 = (uint)bVar1;
  bVar2 = *DAT_01018498;
  uVar9 = (uint)bVar2;
  bVar4 = bVar2 & 0xbf;
  if ((bVar1 & 1) == 0) {
    bVar3 = DAT_01018498[1];
    uVar7 = (uint)bVar3;
    if (-1 < (char)bVar3) {
      if ((bVar2 & 1) != 0) {
        *DAT_01018498 = bVar2 & 0xfe;
        FUN_010184cc(*(undefined1 *)(iVar6 + 0xc));
        *pbVar11 = *pbVar11 | 3;
        if (*(char *)(iVar6 + 0xc) == '\x06') {
          return;
        }
        FUN_01010996(3);
        FUN_01017c52(0);
        FUN_01017b64(0);
        FUN_0101e318(1,0);
        return;
      }
      if ((int)(uVar9 << 0x1e) < 0) {
        *DAT_01018498 = bVar2 & 0xfd;
        uVar8 = 0;
      }
      else {
        if (((-1 < (int)(uVar9 << 0x1d)) && (-1 < (int)(uVar9 << 0x1c))) &&
           (-1 < (int)(uVar9 << 0x1b))) {
          if ((int)(uVar10 << 0x1b) < 0) {
            DAT_01018498[2] = bVar1 & 0xef;
            FUN_0101852c();
          }
          else if ((int)(uVar10 << 0x1a) < 0) {
            DAT_01018498[2] = bVar1 & 0xdf;
            FUN_0101855e();
          }
          else if ((int)(uVar9 << 0x1a) < 0) {
            *DAT_01018498 = bVar2 & 0xdf;
            FUN_010184fc(3);
          }
          else if ((int)(uVar9 << 0x19) < 0) {
            *DAT_01018498 = bVar4;
            if ((char)bVar2 < '\0') {
              *pbVar5 = bVar2 & 0x3f;
              FUN_010185c0(DAT_010184a0);
            }
            else if ((int)(uVar7 << 0x1e) < 0) {
              pbVar5[1] = bVar3 & 0xfd;
              FUN_01018610(DAT_010184a4);
            }
            else if ((int)(uVar10 << 0x1c) < 0) {
              pbVar5[2] = bVar1 & 0xf7;
              FUN_01018736(DAT_010184a8);
            }
            else if ((int)(uVar10 << 0x1e) < 0) {
              pbVar5[2] = bVar1 & 0xfd;
              FUN_0101864a(DAT_010184ac);
              iVar6 = DAT_010184ac;
              *(undefined1 *)(DAT_010184ac + 2) = 0;
              *(undefined1 *)(iVar6 + 3) = 0;
              *(undefined1 *)(iVar6 + 4) = 0;
              *(undefined1 *)(iVar6 + 5) = 0;
              *(undefined1 *)(iVar6 + 6) = 0;
              *(undefined1 *)(iVar6 + 7) = 0;
            }
            else if ((int)(uVar10 << 0x1d) < 0) {
              *DAT_010184b0 = *DAT_010184b0 & 0xf7;
              pbVar5[2] = bVar1 & 0xfb;
              FUN_0101868c(DAT_010184b4);
            }
            else if ((int)(uVar7 << 0x1d) < 0) {
              pbVar5[1] = bVar3 & 0xfb;
              FUN_010186c8(DAT_010184b8);
            }
            else {
              FUN_01018590();
            }
          }
          else if ((int)(uVar7 << 0x1c) < 0) {
            DAT_01018498[1] = bVar3 & 0xf7;
            FUN_010188ee();
          }
          else if ((int)(uVar7 << 0x1b) < 0) {
            DAT_01018498[1] = bVar3 & 0xef;
            FUN_0101891c();
          }
          else if ((int)(uVar7 << 0x19) < 0) {
            DAT_01018498[1] = bVar3 & 0xbf;
            FUN_0101897a();
          }
          else {
            if (-1 < (int)(uVar7 << 0x1a)) {
              return;
            }
            DAT_01018498[1] = bVar3 & 0xdf;
            FUN_0101894a(*(undefined1 *)(DAT_0101849c + 0x14));
          }
          goto LAB_01018142;
        }
        *DAT_01018498 = bVar2 & 0xe3;
        uVar8 = 2;
      }
      FUN_010184fc(uVar8);
      *pbVar11 = *pbVar11 | 3;
      FUN_01017c52(2);
      return;
    }
    *(undefined2 *)(DAT_01018494 + -4) = 0;
    pbVar5 = DAT_01018498;
    *DAT_01018498 = bVar4;
    pbVar5[1] = bVar3 & 0x7f;
    FUN_01018a04();
  }
  else {
    *(undefined2 *)(DAT_01018494 + -4) = 0;
    *pbVar5 = bVar4;
    pbVar5[2] = bVar1 & 0xfe;
    FUN_010189d6();
  }
LAB_01018142:
  *pbVar11 = *pbVar11 | 3;
  return;
}


// ===== FUN_010182d8 @ 010182d8

void FUN_010182d8(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  uint *puVar9;
  
  iVar7 = DAT_0101849c;
  if (*(char *)(DAT_0101849c + 0x13) == '\0') {
    return;
  }
  *(undefined1 *)(DAT_0101849c + 0x13) = 0;
  pbVar6 = DAT_01018498;
  bVar1 = DAT_01018498[-8];
  bVar2 = *DAT_01018498;
  pbVar8 = DAT_01018498 + 8;
  bVar3 = *pbVar8;
  puVar9 = (uint *)(DAT_01018498 + 4);
  if ((bVar1 == 0) || (bVar1 == 1)) {
    *puVar9 = *puVar9 + 1;
    if ((*(char *)(iVar7 + 0xc) != '\x05') && (4 < *(byte *)(iVar7 + 0xc))) {
      return;
    }
  }
  else {
    if ((bVar1 == 2) || (bVar1 == 3)) {
      *puVar9 = *puVar9 + 1;
      if (*(char *)(iVar7 + 0xc) == '\x05') {
        if (*puVar9 < 0x1e) {
          return;
        }
      }
      else {
        if (4 < *(byte *)(iVar7 + 0xc)) {
          return;
        }
        if (*puVar9 < 0x78) {
          return;
        }
      }
      goto LAB_01018342;
    }
    if (bVar1 == 4) {
      *puVar9 = *puVar9 + 1;
      bVar1 = DAT_01018498[2];
      bVar2 = DAT_01018498[9];
      if (*(char *)(iVar7 + 0xc) == '\x05') {
        uVar4 = *(undefined1 *)(DAT_010184bc + 0xd);
        uVar5 = *(undefined1 *)(DAT_010184bc + 0xc);
      }
      else {
        uVar4 = *(undefined1 *)(DAT_010184bc + 9);
        uVar5 = *(undefined1 *)(DAT_010184bc + 8);
      }
      if (CONCAT11(uVar4,uVar5) == 0) {
        *puVar9 = 0;
        return;
      }
      if (*puVar9 < (uint)CONCAT11(uVar4,uVar5)) {
        return;
      }
      *puVar9 = 0;
      DAT_01018498[-8] = 5;
      pbVar6[2] = bVar1 | 0x10;
      pbVar6[9] = bVar2 | 8;
      return;
    }
    if (bVar1 != 7) {
      if (bVar1 != 8) {
        return;
      }
      *puVar9 = *puVar9 + 1;
      if (*puVar9 < 0xf) {
        return;
      }
      goto LAB_01018342;
    }
    *puVar9 = *puVar9 + 1;
  }
  if (*puVar9 < 10) {
    return;
  }
LAB_01018342:
  *puVar9 = 0;
  *pbVar6 = bVar2 | 0x20;
  *pbVar8 = bVar3 | 0x40;
  return;
}


// ===== FUN_010183c0 @ 010183c0

void FUN_010183c0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 uVar5;
  ushort uVar6;
  ushort uVar7;
  char *pcVar8;
  int iVar9;
  undefined4 in_r3;
  int iVar10;
  
  iVar3 = DAT_010184c4;
  iVar10 = DAT_0101849c;
  iVar2 = DAT_01018494;
  if (*(char *)(DAT_010184c0 + 0x13) == '\0') {
    iVar9 = DAT_01018494 + 0xc;
    uVar6 = *(short *)(DAT_01018494 + 0x14) + 1;
    pcVar8 = (char *)(DAT_01018494 + 0x4c);
    if ((int)((uint)*(ushort *)(DAT_010184c4 + 0x1c) * 0x2000000) < 0) {
      *(undefined1 *)(DAT_0101849c + 0x16) = 0;
      *(undefined1 *)(iVar10 + 0x17) = 0xff;
      pbVar4 = DAT_010184c8;
      if (*(char *)(iVar10 + 0xc) != '\x06') {
        iVar10 = DAT_010184c4 + -0x20;
        cVar1 = *(char *)(DAT_01018494 + 0x4c);
        if (*(char *)(iVar2 + 0x44) == '\0') {
          if (cVar1 == '\0') {
            return;
          }
          *pcVar8 = '\0';
          uVar5 = 0x40;
        }
        else {
          *(ushort *)(iVar2 + 0x14) = uVar6;
          if (0x31 < uVar6) {
            *(undefined2 *)(iVar2 + 0x14) = 0;
            *pcVar8 = cVar1 != '\x01';
          }
          if (*pcVar8 == '\0') {
            *(undefined1 *)((uint)*pbVar4 * 0x10 + iVar10 + 7) = 0x3e;
            return;
          }
          uVar5 = 0x3f;
        }
        *(undefined1 *)((uint)*pbVar4 * 0x10 + iVar10 + 7) = uVar5;
        return;
      }
    }
    else {
      *pcVar8 = '\x01';
      if ((int)((uint)*(ushort *)(iVar3 + 0x1c) << 0x18) < 0) {
        *(undefined2 *)(iVar2 + 0x14) = 0;
        uVar7 = *(short *)(iVar2 + 0x18) + 1;
        *(ushort *)(iVar2 + 0x18) = uVar7;
        if (99 < uVar7) {
          *(undefined2 *)(iVar2 + 0x18) = 0;
          *(undefined1 *)(iVar10 + 0x16) = 2;
          *(undefined1 *)(iVar2 + 0x41) = 2;
        }
      }
      else {
        *(undefined2 *)(iVar2 + 0x18) = 0;
        *(ushort *)(iVar2 + 0x14) = uVar6;
        if (99 < uVar6) {
          *(undefined2 *)(iVar2 + 0x14) = 0;
          *(undefined1 *)(iVar10 + 0x16) = 1;
          *(undefined1 *)(iVar2 + 0x41) = 1;
        }
      }
      if (*(char *)(iVar10 + 0x16) != *(char *)(iVar10 + 0x17)) {
        *(undefined1 *)(iVar10 + 0x17) = *(undefined1 *)(iVar10 + 0x16);
        FUN_0101e318(1,0,iVar9,uVar6,in_r3);
      }
    }
  }
  return;
}


// ===== FUN_010184cc @ 010184cc

void FUN_010184cc(undefined1 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 3;
  puVar1[2] = 1;
  puVar1[3] = param_1;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_010184fc @ 010184fc

void FUN_010184fc(undefined1 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 3;
  puVar1[2] = 2;
  puVar1[3] = param_1;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101852c @ 0101852c

void FUN_0101852c(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 3;
  puVar1[2] = 2;
  puVar1[3] = 4;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101855e @ 0101855e

void FUN_0101855e(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 3;
  puVar1[2] = 2;
  puVar1[3] = 5;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_01018590 @ 01018590

void FUN_01018590(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 3;
  puVar1[2] = 6;
  puVar1[3] = 0;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_010185c0 @ 010185c0

void FUN_010185c0(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 10;
  puVar1[2] = 6;
  puVar1[3] = 0x11;
  puVar1[4] = *param_1;
  puVar1[5] = param_1[2];
  puVar1[6] = param_1[3];
  puVar1[7] = param_1[4];
  puVar1[8] = param_1[5];
  puVar1[9] = param_1[6];
  puVar1[10] = param_1[7];
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 0xb; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_01018610 @ 01018610

void FUN_01018610(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 5;
  puVar1[2] = 6;
  puVar1[3] = 0x12;
  puVar1[4] = *(undefined1 *)(param_1 + 1);
  puVar1[5] = *(undefined1 *)(param_1 + 2);
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 6; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101864a @ 0101864a

void FUN_0101864a(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 7;
  puVar1[2] = 6;
  puVar1[3] = 0x15;
  puVar1[4] = *(undefined1 *)(param_1 + 1);
  puVar1[5] = *(undefined1 *)(param_1 + 2);
  puVar1[6] = *(undefined1 *)(param_1 + 4);
  puVar1[7] = *(undefined1 *)(param_1 + 6);
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101868c @ 0101868c

void FUN_0101868c(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 6;
  puVar1[2] = 6;
  puVar1[3] = 0x16;
  puVar1[4] = *param_1;
  puVar1[5] = param_1[1];
  puVar1[6] = param_1[2];
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 7; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_010186c8 @ 010186c8

void FUN_010186c8(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar1[1] = 0x12;
  puVar1[2] = 6;
  puVar1[3] = 0x14;
  puVar1[4] = *(undefined1 *)(param_1 + 1);
  puVar1[5] = *(undefined1 *)(param_1 + 2);
  puVar1[6] = *(undefined1 *)(param_1 + 3);
  puVar1[7] = *(undefined1 *)(param_1 + 4);
  puVar1[8] = *(undefined1 *)(param_1 + 5);
  puVar1[9] = *(undefined1 *)(param_1 + 6);
  puVar1[10] = *(undefined1 *)(param_1 + 7);
  puVar1[0xb] = *(undefined1 *)(param_1 + 8);
  puVar1[0xc] = *(undefined1 *)(param_1 + 9);
  puVar1[0xd] = *(undefined1 *)(param_1 + 10);
  puVar1[0xe] = *(undefined1 *)(param_1 + 0xb);
  puVar1[0xf] = *(undefined1 *)(param_1 + 0xc);
  puVar1[0x10] = *(undefined1 *)(param_1 + 0xd);
  puVar1[0x11] = *(undefined1 *)(param_1 + 0xe);
  puVar1[0x12] = *(undefined1 *)(param_1 + 0xf);
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 0x13; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_01018736 @ 01018736

void FUN_01018736(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar2 = DAT_010188cc;
  *DAT_010188cc = 0x44;
  puVar2[1] = 4;
  puVar2[2] = 6;
  puVar2[3] = 0x13;
  if ((*(byte *)(DAT_010188d0 + 0xc) < 5) && (*(char *)(param_1 + 1) == '\x04')) {
    *(undefined1 *)(param_1 + 1) = 3;
  }
  puVar3 = DAT_010188cc;
  puVar2[4] = *(undefined1 *)(param_1 + 1);
  puVar3[0x53] = 0;
  bVar1 = puVar2[1];
  for (iVar4 = 1; iVar4 < (int)(bVar1 + 1); iVar4 = iVar4 + 1) {
    puVar3[0x53] = puVar3[0x53] + puVar2[iVar4];
  }
  return;
}


// ===== FUN_010188ee @ 010188ee

void FUN_010188ee(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_01018c90;
  *DAT_01018c90 = 0x44;
  puVar1[1] = 2;
  puVar1[2] = 0x21;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 3; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101891c @ 0101891c

void FUN_0101891c(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_01018c90;
  *DAT_01018c90 = 0x44;
  puVar1[1] = 2;
  puVar1[2] = 0x22;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 3; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101894a @ 0101894a

void FUN_0101894a(undefined1 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_01018c90;
  *DAT_01018c90 = 0x44;
  puVar1[1] = 3;
  puVar1[2] = 0x31;
  puVar1[3] = param_1;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101897a @ 0101897a

void FUN_0101897a(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_01018c90;
  *DAT_01018c90 = 0x44;
  puVar1[1] = 2;
  puVar1[2] = 0x41;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 3; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_010189d6 @ 010189d6

void FUN_010189d6(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_01018c90;
  *DAT_01018c90 = 0x44;
  puVar1[1] = 2;
  puVar1[2] = 0x71;
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < 3; iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_01018a04 @ 01018a04

void FUN_01018a04(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_01018c90;
  *DAT_01018c90 = 0x44;
  puVar1[1] = 0x42;
  puVar1[2] = 0x75;
  FUN_01018cf2();
  puVar1[0x53] = 0;
  for (iVar2 = 1; iVar2 < (int)((byte)puVar1[1] + 1); iVar2 = iVar2 + 1) {
    puVar1[0x53] = puVar1[0x53] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_01018a38 @ 01018a38

void FUN_01018a38(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
    return;
  }
  if (*(char *)(DAT_01018c98 + 0xc) == -3) {
    *(undefined1 *)(DAT_01018c98 + 0x2a) = 1;
    return;
  }
  FUN_01017c52(1);
  FUN_01017b64(1);
  return;
}


// ===== FUN_01018a66 @ 01018a66

void FUN_01018a66(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
    return;
  }
  if (*(char *)(DAT_01018c98 + 0xc) == -3) {
    *(undefined1 *)(DAT_01018c98 + 0x29) = 1;
    return;
  }
  if ((int)((uint)*DAT_01018c9c << 0x19) < 0) {
    *DAT_01018c9c = *DAT_01018c9c | 0x80;
    return;
  }
  if ((int)((uint)DAT_01018c9c[1] << 0x1c) < 0) {
    DAT_01018c9c[1] = DAT_01018c9c[1] | 0x10;
    return;
  }
  FUN_01017c52(3);
  FUN_01017b64(3);
  return;
}


// ===== FUN_01018ab2 @ 01018ab2

void FUN_01018ab2(int param_1,byte *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_01018ca4;
  cVar1 = *(char *)(DAT_01018ca0 + 0x1a);
  if (cVar1 == '\x16') {
    for (iVar3 = 0; iVar3 < param_1; iVar3 = iVar3 + 1) {
      if ((*param_2 & 0xf) < 7) {
        *(byte *)(iVar3 * 2 + iVar2 + 0x70) = *param_2 & 0xf;
      }
      else {
        *(undefined1 *)(iVar3 * 2 + iVar2 + 0x70) = 0;
      }
      if (*param_2 >> 4 < 7) {
        *(byte *)(iVar3 * 2 + iVar2 + 0x71) = *param_2 >> 4;
      }
      else {
        *(undefined1 *)(iVar3 * 2 + iVar2 + 0x71) = 0;
      }
      param_2 = param_2 + 1;
      *(undefined1 *)(iVar2 + 1) = 1;
    }
  }
  if (cVar1 == '\x14') {
    for (iVar3 = 0; iVar3 < param_1; iVar3 = iVar3 + 1) {
      if ((*param_2 & 0xf) < 7) {
        *(byte *)(iVar3 * 2 + iVar2 + 0x70) = *param_2 & 0xf;
      }
      else {
        *(undefined1 *)(iVar3 * 2 + iVar2 + 0x70) = 0;
      }
      if (*param_2 >> 4 < 7) {
        *(byte *)(iVar3 * 2 + iVar2 + 0x71) = *param_2 >> 4;
      }
      else {
        *(undefined1 *)(iVar3 * 2 + iVar2 + 0x71) = 0;
      }
      param_2 = param_2 + 1;
      *(undefined1 *)(iVar2 + 1) = 1;
    }
  }
  return;
}


// ===== FUN_01018b54 @ 01018b54

void FUN_01018b54(undefined1 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_01018ca4;
  if (*(char *)(DAT_01018ca0 + 0x1a) == '\x15') {
    *(undefined1 *)(DAT_01018ca4 + 1) = *param_1;
    *(undefined1 *)(iVar1 + 2) = param_1[1];
    *(undefined1 *)(iVar1 + 3) = param_1[2];
  }
  return;
}


// ===== FUN_01018b6c @ 01018b6c

void FUN_01018b6c(undefined1 *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  uint extraout_r3;
  
  puVar1 = DAT_01018ca8;
  *DAT_01018ca8 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  if (param_1[3] != '\0') {
    FUN_01017992(1);
  }
  if ((int)((uint)(byte)param_1[3] * 0x1000000) < 0) {
    *(byte *)(DAT_01018cac + 2) = *(byte *)(DAT_01018cac + 2) | 1;
  }
  uVar2 = (byte)param_1[3] & 0x3f;
  if ((param_1[3] & 0x3f) != 0) {
    if (param_1[4] == '\x0e') {
      FUN_01018b54(param_1 + 5);
      uVar2 = extraout_r3;
    }
    if (param_1[4] == '\r') {
      FUN_01018ab2(uVar2,param_1 + 5);
    }
  }
  puVar1[6] = 1;
  puVar1[4] = 1;
  puVar1[7] = 1;
  puVar1[5] = 1;
  return;
}


// ===== FUN_01018bc8 @ 01018bc8

void FUN_01018bc8(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018bd6 @ 01018bd6

void FUN_01018bd6(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018bf2 @ 01018bf2

void FUN_01018bf2(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c00 @ 01018c00

void FUN_01018c00(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c0e @ 01018c0e

void FUN_01018c0e(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c1c @ 01018c1c

void FUN_01018c1c(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c2a @ 01018c2a

void FUN_01018c2a(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c38 @ 01018c38

void FUN_01018c38(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c46 @ 01018c46

void FUN_01018c46(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018c54 @ 01018c54

void FUN_01018c54(void)

{
  *(undefined1 *)(DAT_01018c94 + 6) = 1;
  return;
}


// ===== FUN_01018c5c @ 01018c5c

void FUN_01018c5c(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = DAT_01018cb0;
  *DAT_01018cb0 = *param_1;
  for (iVar2 = 0; iVar2 < (int)(*pbVar1 - 2); iVar2 = iVar2 + 1) {
    pbVar1[iVar2 + 1] = param_1[iVar2 + 2];
  }
  FUN_01018cb4();
  return;
}


// ===== FUN_01018c80 @ 01018c80

void FUN_01018c80(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_01018c94 + 6) = 1;
  }
  return;
}


// ===== FUN_01018cb4 @ 01018cb4

void FUN_01018cb4(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_01018d00;
  pbVar2 = DAT_01018cfc;
  bVar1 = *DAT_01018cfc;
  for (iVar4 = 0; iVar4 < (int)(bVar1 - 2); iVar4 = iVar4 + 1) {
    *(byte *)(iVar3 + iVar4) = pbVar2[iVar4 + 1];
  }
  *DAT_01018d04 = 1;
  FUN_0101a85c();
  bVar1 = pbVar2[1];
  if ((((int)((uint)bVar1 << 0x18) < 0) && (bVar1 != 0xa5)) && (bVar1 != 0xad)) {
    *(byte *)(DAT_01018d08 + 1) = *(byte *)(DAT_01018d08 + 1) | 0x80;
  }
  return;
}


// ===== FUN_01018cf2 @ 01018cf2

void FUN_01018cf2(void)

{
  FUN_0101ab3e(DAT_01018d0c);
  return;
}


// ===== FUN_01018d10 @ 01018d10

void FUN_01018d10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 unaff_r6;
  int iVar6;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  local_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  FUN_0101c420();
  iVar5 = DAT_01019114;
  if (param_1 != 0) {
    unaff_r6 = *(undefined1 *)(DAT_01019114 + 1);
    iVar2 = 0;
    do {
      *(char *)((int)&local_20 + iVar2) =
           (char)((*(byte *)(iVar2 * 2 + DAT_01019114 + 10) & 7) >> 1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
  }
  FUN_0101f430(DAT_01019118);
  thunk_EXT_FUN_0000425c(10);
  FUN_0101c420();
  FUN_0101f4b4(DAT_0101911c,DAT_01019114,0x100);
  if (param_1 != 0) {
    iVar2 = 0;
    *(undefined1 *)(iVar5 + 1) = unaff_r6;
    do {
      iVar3 = iVar2 * 2 + iVar5;
      pbVar1 = (byte *)((int)&local_20 + iVar2);
      iVar2 = iVar2 + 1;
      *(byte *)(iVar3 + 10) = *(byte *)(iVar3 + 10) & 0xf9 | (*pbVar1 & 3) << 1;
    } while (iVar2 < 8);
  }
  iVar2 = DAT_01019120;
  iVar3 = 0;
  do {
    FUN_0101f520(iVar3 * 0x20 + iVar2,iVar3 * 0x20 + iVar5,0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  FUN_0101c420();
  FUN_0101f4b4(DAT_01019128,DAT_01019124,0x200);
  iVar5 = DAT_01019124;
  iVar2 = 0;
  do {
    iVar3 = 0;
    iVar6 = iVar2 * 0x200 + DAT_0101912c;
    do {
      FUN_0101f520(iVar6 + iVar3 * 0x20,iVar3 * 0x20 + iVar5,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  FUN_0101c420();
  FUN_0101f1de(DAT_01019124,0x200);
  iVar2 = 0;
  do {
    iVar3 = 0;
    iVar6 = iVar2 * 0x100 + DAT_01019130;
    do {
      FUN_0101f520(iVar6 + iVar3 * 0x20,iVar3 * 0x20 + iVar5,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  FUN_0101c420();
  FUN_0101f4b4(DAT_01019134,DAT_01019124,0xa0);
  iVar2 = DAT_01019134;
  iVar3 = 0;
  do {
    FUN_0101f520(iVar3 * 0x20 + iVar2,iVar3 * 0x20 + iVar5,0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  FUN_0101c420();
  iVar2 = 0;
  do {
    FUN_0101f4b4(iVar2 * 0x180 + DAT_01019138,DAT_01019124,0x180);
    iVar3 = 0;
    iVar6 = iVar2 * 0x180 + DAT_0101913c;
    do {
      FUN_0101f520(iVar6 + iVar3 * 0x20,iVar3 * 0x20 + iVar5,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xc);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  FUN_0101c420();
  FUN_0101f4b4(DAT_01019140,DAT_01019124,0x1f8);
  iVar2 = 0;
  do {
    iVar3 = 0;
    iVar6 = iVar2 * 0x200 + DAT_01019144;
    do {
      FUN_0101f520(iVar6 + iVar3 * 0x20,iVar3 * 0x20 + iVar5,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    thunk_EXT_FUN_00004404(iVar6,iVar6 + 0x200);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  FUN_0101f4b4(DAT_01019148,DAT_01019124,0x1f8);
  iVar5 = 0;
  do {
    iVar2 = 0;
    iVar3 = iVar5 * 0x200 + DAT_01019144;
    do {
      FUN_0101f520(iVar3 + iVar2 * 0x20 + 0x400,iVar2 * 0x20 + DAT_01019124,0x20);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x10);
    thunk_EXT_FUN_00004404(iVar3 + 0x400,iVar3 + 0x600);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  FUN_0101c420();
  FUN_0101f1de(DAT_01019124,0x200);
  iVar5 = DAT_0101914c;
  uVar4 = 0;
  do {
    FUN_0101f520(uVar4 * 0x20 + iVar5,DAT_01019124,0x20);
    FUN_0101c420();
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x167);
  FUN_0101c420();
  thunk_EXT_FUN_00004404(DAT_01019120,DAT_01019150);
  FUN_0101c420();
  return;
}


// ===== FUN_01018f0c @ 01018f0c

void FUN_01018f0c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_01019154;
  iVar1 = DAT_01019118;
  iVar4 = 0;
  do {
    FUN_0101c420();
    iVar3 = FUN_0101f57c(iVar4 * 0x20 + iVar1,0x20);
    if (iVar3 != 0) {
      FUN_01018d10(0);
      return;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < iVar2);
  return;
}


// ===== FUN_01018f48 @ 01018f48

void FUN_01018f48(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_108;
  undefined1 local_107 [255];
  
  if (*(char *)(DAT_01019158 + 2) != '\0') {
    *(undefined1 *)(DAT_01019158 + 2) = 0;
    FUN_0101f1de(&local_108,0x100);
    FUN_0101f4b4(DAT_01019120,DAT_01019114,0x100);
    *(undefined1 *)(DAT_0101915c + 8) = 1;
    FUN_0101f61c(DAT_01019160,&local_108,0x100);
    iVar1 = DAT_01019164;
    *(undefined1 *)(DAT_01019164 + 1) = local_108;
    iVar2 = 0;
    do {
      *(undefined1 *)(iVar1 + iVar2 + 2) = local_107[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xff);
  }
  return;
}


// ===== FUN_01018f9c @ 01018f9c

undefined4 FUN_01018f9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (-1 < (int)((uint)*DAT_01019168 << 0x1c)) {
    if (*(char *)(DAT_01019158 + 0x13) != '\0') {
      FUN_0101b686(1,0,param_3,param_4,param_4);
      FUN_01010730(7);
      FUN_0101c420();
      thunk_EXT_FUN_0000425c(10);
      iVar2 = DAT_01019114;
      iVar3 = param_1 * 0x20 + DAT_01019120;
      if (param_1 == 5) {
        iVar2 = 5;
        do {
          iVar1 = iVar2 * 0x20 + DAT_01019120;
          FUN_0101f3dc();
          FUN_0101f520(iVar1,iVar2 * 0x20 + DAT_01019114,0x20);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 8);
        iVar2 = iVar3 + 0x60;
      }
      else {
        FUN_0101f3dc(iVar3);
        FUN_0101f520(iVar3,param_1 * 0x20 + iVar2,0x20);
        iVar2 = iVar3 + 0x20;
      }
      thunk_EXT_FUN_00004404(iVar3,iVar2);
      FUN_0101233e(0xf,0);
      *(undefined1 *)(DAT_01019158 + 0x13) = 0;
      iVar2 = DAT_0101915c;
      if (*(char *)(DAT_0101915c + 9) != '\0') {
        *(undefined1 *)(DAT_0101915c + 9) = 0;
        *DAT_0101916c = *DAT_0101916c | 9;
        *DAT_01019164 = 0;
        *(undefined4 *)(iVar2 + 4) = 0;
        *(undefined1 *)(iVar2 + 8) = 1;
      }
      FUN_0101b686(1);
      return 0;
    }
    thunk_EXT_FUN_0000425c(10);
    FUN_0101233e(0xf,1,0);
    thunk_EXT_FUN_0000425c(10);
    *(undefined1 *)(DAT_01019158 + 0x13) = 1;
  }
  return 1;
}


// ===== FUN_01019070 @ 01019070

void FUN_01019070(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_118;
  undefined1 local_117 [259];
  
  iVar4 = DAT_01019158;
  if (*(char *)(DAT_01019158 + 3) == '\0') {
    if (*(char *)(DAT_01019158 + 4) != '\0') {
      uVar2 = FUN_01018f9c(0);
      *(undefined1 *)(iVar4 + 4) = uVar2;
    }
    if (*(char *)(iVar4 + 5) != '\0') {
      uVar2 = FUN_01018f9c(1);
      *(undefined1 *)(iVar4 + 5) = uVar2;
    }
    if (*(char *)(iVar4 + 6) != '\0') {
      uVar2 = FUN_01018f9c(2);
      *(undefined1 *)(iVar4 + 6) = uVar2;
    }
    if (*(char *)(iVar4 + 7) != '\0') {
      uVar2 = FUN_01018f9c(3);
      *(undefined1 *)(iVar4 + 7) = uVar2;
    }
    if (*(char *)(iVar4 + 8) != '\0') {
      uVar2 = FUN_01018f9c(4);
      *(undefined1 *)(iVar4 + 8) = uVar2;
    }
    if (*(char *)(iVar4 + 9) != '\0') {
      uVar2 = FUN_01018f9c(5);
      *(undefined1 *)(iVar4 + 9) = uVar2;
    }
  }
  else if (-1 < (int)((uint)*DAT_01019168 << 0x1c)) {
    if (*(char *)(DAT_01019158 + 0x13) == '\0') {
      *(undefined1 *)(DAT_01019158 + 0x13) = 1;
      thunk_EXT_FUN_0000425c(6);
      FUN_0101233e(0xf,1,0);
      thunk_EXT_FUN_0000425c(6);
    }
    else {
      FUN_0101b686(1,0);
      FUN_01010730(7);
      FUN_0101c420();
      thunk_EXT_FUN_0000425c(10);
      iVar5 = 0;
      do {
        iVar3 = iVar5 * 0x20 + DAT_01019120;
        FUN_0101f3dc();
        FUN_0101f520(iVar3,iVar5 * 0x20 + DAT_01019114,0x20);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      thunk_EXT_FUN_00004404(DAT_01019120,DAT_01019170);
      FUN_0101233e(0xf,0);
      *(undefined1 *)(iVar4 + 0x13) = 0;
      iVar5 = DAT_0101915c;
      *(undefined1 *)(iVar4 + 3) = 0;
      puVar1 = DAT_01019164;
      if (*(char *)(iVar5 + 9) != '\0') {
        *(undefined1 *)(iVar5 + 9) = 0;
        *DAT_0101916c = *DAT_0101916c | 9;
        *puVar1 = 0;
        *(undefined4 *)(iVar5 + 4) = 0;
        *(undefined1 *)(iVar5 + 8) = 1;
      }
      FUN_0101f1de(&local_118,0x100);
      FUN_0101f61c(DAT_01019160,&local_118,0x100);
      puVar1[1] = local_118;
      iVar4 = 0;
      do {
        puVar1[iVar4 + 2] = local_117[iVar4];
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0xff);
      FUN_0101b686(1);
    }
  }
  return;
}


// ===== FUN_0101920e @ 0101920e

void FUN_0101920e(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  
  if ((*(char *)(DAT_010195f4 + 10) != '\0') && (-1 < (int)((uint)*DAT_010195f8 << 0x1c))) {
    if (*(char *)(DAT_010195f4 + 0x13) == '\0') {
      *(undefined1 *)(DAT_010195f4 + 0x13) = 1;
      FUN_0101233e(0xf,1,0,in_r3,in_r3);
      return;
    }
    FUN_0101b686(1,0);
    FUN_01010730(7);
    FUN_0101c420();
    iVar2 = DAT_01019600;
    pbVar1 = DAT_010195fc;
    iVar3 = 0;
    do {
      iVar4 = iVar3 * 0x20;
      FUN_0101f3dc((uint)*pbVar1 * 0x200 + iVar2 + iVar4);
      FUN_0101f520((uint)*pbVar1 * 0x200 + iVar2 + iVar4,iVar4 + DAT_01019604,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    iVar2 = (uint)*pbVar1 * 0x200 + iVar2;
    thunk_EXT_FUN_00004404(iVar2,iVar2 + 0x200);
    FUN_0101233e(0xf,0);
    iVar2 = DAT_010195f4;
    *(undefined1 *)(DAT_010195f4 + 0x13) = 0;
    *(undefined1 *)(iVar2 + 10) = 0;
    FUN_0101b686(1);
  }
  return;
}


// ===== FUN_010192a0 @ 010192a0

void FUN_010192a0(void)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_38 [36];
  
  iVar3 = DAT_010195f4;
  if ((*(char *)(DAT_010195f4 + 0xf) != '\0') && (-1 < (int)((uint)*DAT_010195f8 << 0x1c))) {
    if (*(char *)(DAT_010195f4 + 0x13) == '\0') {
      *(undefined1 *)(DAT_010195f4 + 0x13) = 1;
      FUN_0101233e(0xf,1,0);
    }
    else {
      bVar2 = *DAT_01019608;
      uVar6 = (uint)(bVar2 >> 3);
      iVar8 = uVar6 * 0x20;
      FUN_0101b686(1,0);
      FUN_01010730(7);
      pbVar4 = DAT_010195fc;
      FUN_0101f4b4((uint)*DAT_010195fc * 0x200 + DAT_01019600 + iVar8,auStack_38,0x20);
      iVar5 = 0;
      do {
        iVar7 = iVar5 + (bVar2 & 7) * 4;
        puVar1 = (undefined1 *)(DAT_01019604 + iVar5);
        iVar5 = iVar5 + 1;
        auStack_38[iVar7] = *puVar1;
      } while (iVar5 < 4);
      FUN_0101c420();
      iVar5 = DAT_01019600;
      FUN_0101f3dc((uint)*pbVar4 * 0x200 + DAT_01019600 + iVar8);
      FUN_0101f520((uint)*pbVar4 * 0x200 + iVar5 + iVar8,auStack_38,0x20);
      iVar5 = (uint)*pbVar4 * 0x200 + iVar5 + uVar6 * 0x20;
      thunk_EXT_FUN_00004404(iVar5,iVar5 + 0x20);
      FUN_0101233e(0xf,0);
      *(undefined1 *)(iVar3 + 0x13) = 0;
      *(undefined1 *)(iVar3 + 0xf) = 0;
      FUN_0101b686(1);
    }
  }
  return;
}


// ===== FUN_0101935c @ 0101935c

void FUN_0101935c(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  
  if ((*(char *)(DAT_010195f4 + 0xb) != '\0') && (-1 < (int)((uint)*DAT_010195f8 << 0x1c))) {
    if (*(char *)(DAT_010195f4 + 0x13) == '\0') {
      *(undefined1 *)(DAT_010195f4 + 0x13) = 1;
      FUN_0101233e(0xf,1,0,in_r3,in_r3);
      return;
    }
    FUN_0101c420();
    FUN_0101b686(1,0);
    FUN_01010730(7);
    iVar2 = DAT_0101960c;
    pbVar1 = DAT_010195fc;
    iVar3 = 0;
    do {
      iVar4 = iVar3 * 0x20;
      FUN_0101f3dc(((pbVar1[(uint)*pbVar1 * 2 + 10] & 7) >> 1) * 0x400 + iVar2 +
                   (uint)*DAT_01019610 * 0x200 + iVar4);
      FUN_0101f520(((pbVar1[(uint)*pbVar1 * 2 + 10] & 7) >> 1) * 0x400 + iVar2 +
                   (uint)*DAT_01019610 * 0x200 + iVar4,iVar4 + DAT_01019604,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    iVar2 = ((pbVar1[(uint)*pbVar1 * 2 + 10] & 7) >> 1) * 0x400 + iVar2 +
            (uint)*DAT_01019610 * 0x200;
    thunk_EXT_FUN_00004404(iVar2,iVar2 + 0x200);
    FUN_0101233e(0xf,0);
    iVar2 = DAT_010195f4;
    *(undefined1 *)(DAT_010195f4 + 0x13) = 0;
    *(undefined1 *)(iVar2 + 0xb) = 0;
    FUN_0101b686(1);
  }
  return;
}


// ===== FUN_01019424 @ 01019424

void FUN_01019424(void)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_38 [36];
  
  iVar4 = DAT_010195f4;
  if ((*(char *)(DAT_010195f4 + 0xc) != '\0') && (-1 < (int)((uint)*DAT_010195f8 << 0x1c))) {
    if (*(char *)(DAT_010195f4 + 0x13) == '\0') {
      *(undefined1 *)(DAT_010195f4 + 0x13) = 1;
      FUN_0101233e(0xf,1,0);
    }
    else {
      FUN_0101c420();
      FUN_0101b686(1,0);
      FUN_01010730(7);
      pbVar5 = DAT_010195fc;
      bVar2 = *DAT_01019608;
      bVar3 = *DAT_010195fc;
      uVar8 = (uint)(bVar2 >> 3);
      iVar10 = uVar8 * 0x20;
      FUN_0101f4b4(((DAT_010195fc[(uint)bVar3 * 2 + 10] & 7) >> 1) * 0x400 + DAT_0101960c +
                   (uint)*DAT_01019610 * 0x200 + iVar10,auStack_38,0x20);
      pbVar6 = DAT_01019610;
      iVar7 = 0;
      do {
        iVar9 = iVar7 + (bVar2 & 7) * 4;
        puVar1 = (undefined1 *)(DAT_01019604 + iVar7);
        iVar7 = iVar7 + 1;
        auStack_38[iVar9] = *puVar1;
      } while (iVar7 < 4);
      FUN_0101f3dc(((pbVar5[(uint)bVar3 * 2 + 10] & 7) >> 1) * 0x400 + DAT_0101960c +
                   (uint)*DAT_01019610 * 0x200 + iVar10);
      FUN_0101f520(((pbVar5[(uint)bVar3 * 2 + 10] & 7) >> 1) * 0x400 + DAT_0101960c +
                   (uint)*pbVar6 * 0x200 + iVar10,auStack_38,0x20);
      iVar7 = ((pbVar5[(uint)bVar3 * 2 + 10] & 7) >> 1) * 0x400 + DAT_0101960c +
              (uint)*pbVar6 * 0x200 + uVar8 * 0x20;
      thunk_EXT_FUN_00004404(iVar7,iVar7 + 0x20);
      FUN_0101233e(0xf,0);
      *(undefined1 *)(iVar4 + 0x13) = 0;
      *(undefined1 *)(iVar4 + 0xc) = 0;
      FUN_0101b686(1);
    }
  }
  return;
}


// ===== FUN_01019514 @ 01019514

void FUN_01019514(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  
  if ((*(char *)(DAT_010195f4 + 0xe) != '\0') && (-1 < (int)((uint)*DAT_010195f8 << 0x1c))) {
    if (*(char *)(DAT_010195f4 + 0x13) == '\0') {
      *(undefined1 *)(DAT_010195f4 + 0x13) = 1;
      FUN_0101233e(0xf,1,0,in_r3,in_r3);
      return;
    }
    FUN_0101c420();
    FUN_0101b686(1,0);
    FUN_01010730(7);
    iVar2 = DAT_01019614;
    pbVar1 = DAT_01019610;
    iVar3 = 0;
    do {
      iVar4 = iVar3 * 0x20;
      FUN_0101f3dc((uint)*pbVar1 * 0x100 + iVar2 + iVar4);
      FUN_0101f520((uint)*pbVar1 * 0x100 + iVar2 + iVar4,iVar4 + DAT_01019604,0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    iVar2 = (uint)*pbVar1 * 0x100 + iVar2;
    thunk_EXT_FUN_00004404(iVar2,iVar2 + 0x100);
    FUN_0101233e(0xf,0);
    iVar2 = DAT_010195f4;
    *(undefined1 *)(DAT_010195f4 + 0x13) = 0;
    *(undefined1 *)(iVar2 + 0xe) = 0;
    FUN_0101b686(1);
  }
  return;
}


// ===== FUN_010195a4 @ 010195a4

void FUN_010195a4(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 in_r3;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((*(char *)(DAT_010195f4 + 0xd) != '\0') && (-1 < (int)((uint)*DAT_010195f8 << 0x1c))) {
    if (*(char *)(DAT_010195f4 + 0x13) == '\0') {
      *(undefined1 *)(DAT_010195f4 + 0x13) = 1;
      FUN_0101233e(0xf,1,0,in_r3,in_r3);
    }
    else {
      FUN_0101c420();
      FUN_0101b686(1,0);
      FUN_01010730(7);
      pbVar1 = DAT_01019610;
      uVar4 = (*DAT_01019618 & 0x1fff) >> 5;
      if ((*DAT_01019618 & 0x1f) != 0) {
        uVar4 = uVar4 + 1 & 0xff;
      }
      for (iVar3 = 0; uVar2 = (uint)*pbVar1, iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
        iVar5 = iVar3 * 0x20;
        FUN_0101f3dc(uVar2 * 0x100 + DAT_01019a18 + iVar5);
        FUN_0101f520((uint)*pbVar1 * 0x100 + DAT_01019a18 + iVar5,iVar5 + DAT_01019a1c,0x20);
      }
      iVar3 = uVar2 * 0x100 + DAT_01019a18;
      thunk_EXT_FUN_00004404(iVar3,iVar3 + uVar4 * 0x20);
      FUN_0101233e(0xf,0);
      iVar3 = DAT_01019a20;
      *(undefined1 *)(DAT_01019a20 + 0x13) = 0;
      *(undefined1 *)(iVar3 + 0xd) = 0;
      FUN_0101b686(1);
    }
  }
  return;
}


// ===== FUN_01019670 @ 01019670

void FUN_01019670(void)

{
  return;
}


// ===== FUN_01019672 @ 01019672

void FUN_01019672(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 in_r3;
  int iVar4;
  int iVar5;
  
  if ((*(char *)(DAT_01019a20 + 0x10) != '\0') && (-1 < (int)((uint)*DAT_01019a24 << 0x1c))) {
    if (*(char *)(DAT_01019a20 + 0x13) == '\0') {
      *(undefined1 *)(DAT_01019a20 + 0x13) = 1;
      FUN_0101233e(0xf,1,0,in_r3,in_r3);
    }
    else {
      FUN_0101c420();
      FUN_0101b686(1,0);
      FUN_01010730(7);
      iVar1 = DAT_01019a2c;
      iVar3 = DAT_01019a28;
      iVar4 = 0;
      do {
        iVar5 = iVar4 * 0x20;
        FUN_0101f3dc((uint)(*(byte *)((uint)*(byte *)(DAT_01019a2c + -0x66) + iVar1) >> 4) * 0x180 +
                     iVar3 + iVar5);
        FUN_0101f520((uint)(*(byte *)((uint)*(byte *)(DAT_01019a2c + -0x66) + iVar1) >> 4) * 0x180 +
                     iVar3 + iVar5,iVar5 + DAT_01019a1c,0x20);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0xc);
      iVar3 = (uint)(*(byte *)((uint)*(byte *)(DAT_01019a2c + -0x66) + iVar1) >> 4) * 0x180 + iVar3;
      thunk_EXT_FUN_00004404(iVar3,iVar3 + 0x180);
      FUN_0101233e(0xf,0);
      pbVar2 = DAT_01019a30;
      iVar3 = DAT_01019a20;
      *(undefined1 *)(DAT_01019a20 + 0x13) = 0;
      *pbVar2 = *pbVar2 | 1;
      *(undefined1 *)(iVar3 + 0x10) = 0;
      FUN_0101b686(1,1);
    }
  }
  return;
}


// ===== FUN_01019730 @ 01019730

void FUN_01019730(void)

{
  undefined1 *puVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_58 [64];
  undefined1 *local_18;
  
  iVar2 = DAT_01019a20;
  if ((*(char *)(DAT_01019a20 + 0x11) != '\0') && (-1 < (int)((uint)*DAT_01019a24 << 0x1c))) {
    if (*(char *)(DAT_01019a20 + 0x13) == '\0') {
      *(undefined1 *)(DAT_01019a20 + 0x13) = 1;
      FUN_0101233e(0xf,1,0);
    }
    else {
      FUN_0101c420();
      FUN_0101b686(1,0);
      FUN_01010730(7);
      FUN_0101f1de(auStack_58,0x40);
      pbVar3 = DAT_01019a38;
      uVar7 = (uint)*DAT_01019a34 * 3 & 0xffffffe0;
      uVar8 = (uint)*DAT_01019a34 * 0x18000000 >> 0x1b;
      FUN_0101f4b4((uint)*DAT_01019a38 * 0x180 + DAT_01019a28 + uVar7,auStack_58,0x20);
      iVar5 = DAT_01019a28;
      if (uVar8 < 0x1e) {
        iVar4 = 0;
        do {
          iVar6 = iVar4 + uVar8;
          puVar1 = (undefined1 *)(DAT_01019a1c + iVar4);
          iVar4 = iVar4 + 1;
          auStack_58[iVar6] = *puVar1;
        } while (iVar4 < 3);
        FUN_0101f3dc((uint)*pbVar3 * 0x180 + DAT_01019a28 + uVar7);
        FUN_0101f520((uint)*pbVar3 * 0x180 + iVar5 + uVar7,auStack_58,0x20);
        iVar5 = (uint)*pbVar3 * 0x180 + iVar5 + uVar7;
        iVar4 = iVar5 + 0x20;
      }
      else {
        local_18 = auStack_58 + 0x20;
        FUN_0101f4b4((uint)*pbVar3 * 0x180 + DAT_01019a28 + uVar7 + 0x20,local_18,0x20);
        pbVar3 = DAT_01019a38;
        iVar4 = 0;
        do {
          iVar6 = iVar4 + uVar8;
          puVar1 = (undefined1 *)(DAT_01019a1c + iVar4);
          iVar4 = iVar4 + 1;
          auStack_58[iVar6] = *puVar1;
        } while (iVar4 < 3);
        FUN_0101f3dc((uint)*DAT_01019a38 * 0x180 + iVar5 + uVar7);
        FUN_0101f520((uint)*pbVar3 * 0x180 + iVar5 + uVar7,auStack_58,0x20);
        FUN_0101f3dc((uint)*pbVar3 * 0x180 + iVar5 + uVar7 + 0x20);
        FUN_0101f520((uint)*pbVar3 * 0x180 + iVar5 + uVar7 + 0x20,local_18,0x20);
        iVar5 = (uint)*pbVar3 * 0x180 + iVar5 + uVar7;
        iVar4 = iVar5 + 0x40;
      }
      thunk_EXT_FUN_00004404(iVar5,iVar4);
      FUN_0101233e(0xf,0);
      pbVar3 = DAT_01019a30;
      *(undefined1 *)(iVar2 + 0x13) = 0;
      *pbVar3 = *pbVar3 | 1;
      *(undefined1 *)(iVar2 + 0x11) = 0;
      FUN_0101b686(1,1);
    }
  }
  return;
}


// ===== FUN_010198ac @ 010198ac

void FUN_010198ac(void)

{
  int iVar1;
  
  iVar1 = DAT_01019a20;
  if ((*(char *)(DAT_01019a20 + 0x12) != '\0') && (-1 < (int)((uint)*DAT_01019a24 << 0x1c))) {
    if (*(char *)(DAT_01019a20 + 0x13) == '\0') {
      *(undefined1 *)(DAT_01019a20 + 0x13) = 1;
      thunk_EXT_FUN_0000425c(5);
      FUN_0101233e(0xf,1,0);
      thunk_EXT_FUN_0000425c(5);
      return;
    }
    FUN_0101c420();
    thunk_EXT_FUN_0000425c(10);
    FUN_0101394a();
    FUN_0101b686(1,0);
    FUN_01010730(7);
    FUN_01011cb6();
    FUN_0101b686(1,0);
    FUN_01018d10(1);
    FUN_0101233e(0xf,0);
    *(undefined1 *)(iVar1 + 0x13) = 0;
    *(undefined1 *)(iVar1 + 0x12) = 0;
    *DAT_01019a30 = *DAT_01019a30 | 1;
    FUN_0101351e();
    FUN_010134d8();
    FUN_01013738();
    FUN_01013768();
    FUN_0101c420();
    FUN_0101385c();
    FUN_0101e318(1,0);
    FUN_0101b686(1);
  }
  return;
}


// ===== FUN_01019966 @ 01019966

void FUN_01019966(void)

{
  char *pcVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte local_118;
  byte local_117 [259];
  
  iVar4 = DAT_01019a3c;
  pcVar1 = DAT_01019a20;
  if (*DAT_01019a20 == '\x01') {
    if ((-1 < (int)((uint)*DAT_01019a24 << 0x1c)) && (DAT_01019a20[0x13] == '\0')) {
      DAT_01019a20[0x13] = '\x01';
      *pcVar1 = '\x02';
      FUN_0101233e(0xf,1,0);
    }
  }
  else if ((*DAT_01019a20 == '\x02') && (-1 < (int)((uint)*DAT_01019a24 << 0x1c))) {
    FUN_0101c420();
    FUN_0101b686(1,0);
    FUN_01010730(7);
    FUN_0101f5f4(iVar4);
    FUN_0101f5f4(0x1060000);
    FUN_0101f5f4(DAT_01019a40);
    FUN_0101f5f4(DAT_01019a44);
    FUN_0101233e(0xf,0);
    pcVar1[0x13] = '\0';
    *pcVar1 = '\0';
    FUN_0101b686(1);
  }
  if (pcVar1[1] != '\0') {
    pcVar1[1] = '\0';
    pbVar2 = DAT_01019a48;
    FUN_0101f680((uint)*DAT_01019a48 * 0x200 + iVar4,DAT_01019a4c,0x200);
    if ((uint)*pbVar2 == pbVar2[1] - 1) {
      FUN_0101f1de(&local_118,0x100);
      uVar3 = DAT_01019a88;
      local_118 = pbVar2[1];
      iVar4 = 0;
      do {
        iVar5 = iVar4 + 1;
        local_117[iVar4] = pbVar2[iVar4 + 2];
        iVar4 = iVar5;
      } while (iVar5 < 0xff);
      FUN_0101f658(DAT_01019a88);
      FUN_0101f680(uVar3,&local_118,0x100);
      *(undefined1 *)(DAT_01019a8c + 0x1a) = 0x42;
      iVar4 = DAT_01019a90;
      pcVar1[4] = '\x01';
      *(undefined1 *)(iVar4 + 9) = 1;
    }
  }
  return;
}


// ===== FUN_01019a94 @ 01019a94

void FUN_01019a94(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_38 [36];
  
  FUN_0101f1de(local_38,0x20);
  uVar3 = 0;
  *DAT_01019e9c = 0;
  FUN_0101c420();
  FUN_01014bc4();
  FUN_0101b686(1,0);
  FUN_01010730(7);
  uVar1 = DAT_01019ea0;
  while (((((local_38[0] != -0x56 || (local_38[1] != 'U')) || (local_38[2] != -0x56)) ||
          (local_38[3] != 'U')) && (uVar3 = uVar3 + 1, uVar3 < 1000))) {
    FUN_0101f3dc(uVar1);
    local_38[0] = -0x56;
    local_38[1] = 'U';
    local_38[2] = -0x56;
    local_38[3] = 'U';
    iVar2 = 4;
    do {
      local_38[iVar2] = -1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x20);
    FUN_0101f520(uVar1,local_38,0x20);
    FUN_0101f4b4(uVar1,local_38,4);
  }
  if (uVar3 < 1000) {
    FUN_0101176c();
    FUN_0101e1de();
  }
  else {
    FUN_0101b686(1);
  }
  return;
}


// ===== FUN_01019b3a @ 01019b3a

void FUN_01019b3a(void)

{
  int iVar1;
  int iVar2;
  
  *DAT_01019e9c = 0;
  iVar2 = DAT_01019ea8;
  iVar1 = DAT_01019ea4;
  if (*(char *)(DAT_01019ea4 + 1) == '\x01') {
    *(undefined1 *)(DAT_01019ea8 + 0xd) = 0xfd;
  }
  if (*(char *)(iVar1 + 1) == '\x02') {
    *(undefined1 *)(iVar2 + 0xd) = 0xfe;
  }
  return;
}


// ===== FUN_01019b5a @ 01019b5a

void FUN_01019b5a(void)

{
  *DAT_01019e9c = 0;
  FUN_0101f1de(DAT_01019ea4,0x40);
  *DAT_01019eac = 0;
  *DAT_01019eb0 = 0;
  *DAT_01019eb4 = 0;
  *DAT_01019eb8 = 0;
  *DAT_01019ebc = 0;
  *DAT_01019ec0 = 0;
  *DAT_01019ec4 = 0;
  *DAT_01019ec8 = 0;
  *DAT_01019ecc = 0;
  *DAT_01019ed0 = 0;
  *DAT_01019ed4 = 0;
  *DAT_01019ed8 = 0;
  *DAT_01019edc = 0;
  *DAT_01019ee0 = 0;
  return;
}


// ===== FUN_01019bbe @ 01019bbe

void FUN_01019bbe(void)

{
  *(byte *)(DAT_01019ee4 + 2) = *(byte *)(DAT_01019ee4 + 2) | 2;
  return;
}


// ===== FUN_01019bca @ 01019bca

void FUN_01019bca(void)

{
  int iVar1;
  
  iVar1 = DAT_01019ea4;
  *(undefined1 *)(DAT_01019ea4 + 1) = 0xaa;
  *(undefined1 *)(iVar1 + 2) = 0xaa;
  *(undefined1 *)(iVar1 + 3) = 0x55;
  *(undefined1 *)(iVar1 + 4) = 0x55;
  *(undefined1 *)(iVar1 + 5) = 0;
  *(undefined1 *)(iVar1 + 6) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  iVar1 = DAT_01019e9c;
  *(undefined4 *)(DAT_01019e9c + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0x40;
  *(byte *)(DAT_01019ee4 + 2) = *(byte *)(DAT_01019ee4 + 2) | 1;
  return;
}


// ===== FUN_01019bf4 @ 01019bf4

void FUN_01019bf4(void)

{
  int iVar1;
  
  *(undefined1 *)(DAT_01019ea4 + 1) = *(undefined1 *)(DAT_01019ee8 + 0x10);
  iVar1 = DAT_01019e9c;
  *(undefined4 *)(DAT_01019e9c + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0x40;
  return;
}


// ===== FUN_01019c08 @ 01019c08

void FUN_01019c08(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_01019ee8;
  iVar2 = DAT_01019ea4;
  uVar1 = *(undefined2 *)(DAT_01019ee8 + 8);
  *(char *)(DAT_01019ea4 + 1) = (char)uVar1;
  *(char *)(iVar2 + 2) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(iVar3 + 0xc);
  *(char *)(iVar2 + 3) = (char)uVar1;
  *(char *)(iVar2 + 4) = (char)((ushort)uVar1 >> 8);
  iVar3 = DAT_01019ee8;
  uVar1 = *(undefined2 *)(DAT_01019ee8 + 10);
  *(char *)(iVar2 + 5) = (char)uVar1;
  *(char *)(iVar2 + 6) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(iVar3 + 0xe);
  *(char *)(iVar2 + 7) = (char)uVar1;
  *(char *)(iVar2 + 8) = (char)((ushort)uVar1 >> 8);
  iVar2 = DAT_01019e9c;
  *(undefined4 *)(DAT_01019e9c + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0x40;
  return;
}


// ===== FUN_01019d1c @ 01019d1c

void FUN_01019d1c(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = DAT_01019e9c;
  bVar1 = *(byte *)(DAT_01019ea4 + 1);
  DAT_01019e9c[3] = bVar1;
  *(undefined **)(puVar2 + 8) = PTR_DAT_01019ef8 + (uint)bVar1 * 0x14;
  *(undefined4 *)(puVar2 + 0xc) = 0x40;
  *puVar2 = 0;
  puVar2[1] = 1;
  return;
}


// ===== FUN_01019d98 @ 01019d98

void FUN_01019d98(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_01019ee8;
  iVar2 = DAT_01019ea4;
  iVar4 = DAT_01019ee8 + -0x20;
  bVar1 = *(byte *)(DAT_01019ee8 + -6);
  *(byte *)(DAT_01019ea4 + 1) = bVar1;
  *(undefined1 *)(iVar2 + 2) = *(undefined1 *)((uint)*(byte *)(iVar2 + 1) + iVar3 + 0x20);
  *(undefined1 *)(iVar2 + 3) = *(undefined1 *)((uint)*(byte *)(iVar2 + 1) + iVar3 + 0x40);
  *(undefined1 *)(iVar2 + 4) = *(undefined1 *)((uint)*(byte *)(iVar2 + 1) + iVar3 + 0x60);
  iVar4 = (uint)bVar1 * 3 + iVar4;
  *(undefined1 *)(iVar2 + 5) = *(undefined1 *)(iVar4 + 0xa0);
  *(undefined1 *)(iVar2 + 6) = *(undefined1 *)(iVar4 + 0xa1);
  *(undefined1 *)(iVar2 + 7) = *(undefined1 *)(iVar4 + 0xa2);
  iVar2 = DAT_01019e9c;
  *(undefined4 *)(DAT_01019e9c + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0x40;
  return;
}


// ===== FUN_01019e4a @ 01019e4a

void FUN_01019e4a(void)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  iVar2 = DAT_01019f00;
  iVar1 = DAT_01019ea4;
  *(undefined1 *)(DAT_01019ea4 + 1) = *(undefined1 *)(DAT_01019f00 + 0xc);
  if ((*(char *)(DAT_01019ea8 + 0xc) == '\x06') || (*(char *)(iVar2 + 0x1e) != '\0')) {
    *(undefined1 *)(iVar1 + 2) = 1;
    return;
  }
  uVar3 = 0;
  if (*(char *)(iVar2 + 0x1f) != '\0') {
    uVar3 = 2;
  }
  *(undefined1 *)(iVar1 + 2) = uVar3;
  return;
}


// ===== FUN_01019f08 @ 01019f08

void FUN_01019f08(void)

{
  int iVar1;
  
  iVar1 = DAT_0101a304;
  *(undefined1 *)(DAT_0101a304 + 1) = 7;
  *(undefined1 *)(iVar1 + 2) = 5;
  iVar1 = DAT_0101a308;
  *(undefined4 *)(DAT_0101a308 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0x40;
  return;
}


// ===== FUN_01019fa8 @ 01019fa8

void FUN_01019fa8(void)

{
  *DAT_0101a308 = 0;
  *(byte *)(DAT_0101a320 + 2) = *(byte *)(DAT_0101a320 + 2) | 1;
  return;
}


// ===== FUN_01019fba @ 01019fba

void FUN_01019fba(void)

{
  *DAT_0101a308 = 0;
  *(byte *)(DAT_0101a320 + 1) = *(byte *)(DAT_0101a320 + 1) | 0x80;
  *(uint *)(DAT_0101a324 + 0x60) =
       (uint)*(ushort *)(DAT_0101a304 + 1) |
       (uint)*(byte *)(DAT_0101a304 + 3) << 0x10 | (uint)*(byte *)(DAT_0101a304 + 4) << 0x18;
  return;
}


// ===== FUN_01019fe6 @ 01019fe6

void FUN_01019fe6(void)

{
  *DAT_0101a308 = 0;
  *(byte *)(DAT_0101a320 + 1) = *(byte *)(DAT_0101a320 + 1) | 0x10;
  return;
}


// ===== FUN_01019ff8 @ 01019ff8

void FUN_01019ff8(void)

{
  int iVar1;
  
  *DAT_0101a308 = 0;
  iVar1 = DAT_0101a324;
  *(undefined2 *)(DAT_0101a324 + 0x68) = *(undefined2 *)(DAT_0101a304 + 1);
  *(undefined2 *)(iVar1 + 0x6a) = 0;
  *(byte *)(DAT_0101a320 + 1) = *(byte *)(DAT_0101a320 + 1) | 0x20;
  iVar1 = DAT_0101a324;
  *(undefined1 *)(DAT_0101a324 + 0x6e) = 1;
  *(undefined4 *)(iVar1 + 100) = 0;
  return;
}


// ===== FUN_0101a028 @ 0101a028

void FUN_0101a028(void)

{
  int iVar1;
  int iVar2;
  
  *DAT_0101a308 = 0;
  iVar2 = DAT_0101a324;
  iVar1 = DAT_0101a304;
  *(undefined1 *)(DAT_0101a324 + 0x57) = *(undefined1 *)(DAT_0101a304 + 8);
  *(undefined1 *)(iVar2 + 0x58) = *(undefined1 *)(iVar1 + 0xe);
  FUN_0101e318(1,0);
  return;
}


// ===== FUN_0101a064 @ 0101a064

void FUN_0101a064(void)

{
  int iVar1;
  
  *DAT_0101a308 = 0;
  if ((((*(char *)(DAT_0101a304 + 1) == 'U') && (*(char *)(DAT_0101a304 + 2) == -0x56)) &&
      (*(char *)(DAT_0101a304 + 3) == 'U')) && (*(char *)(DAT_0101a304 + 4) == -0x56)) {
    *(byte *)(DAT_0101a320 + 1) = *(byte *)(DAT_0101a320 + 1) | 8;
    iVar1 = DAT_0101a324;
    *(undefined1 *)(DAT_0101a324 + 0x6c) = 0;
    *(undefined1 *)(iVar1 + 0x6d) = 0;
  }
  return;
}


// ===== FUN_0101a0d4 @ 0101a0d4

void FUN_0101a0d4(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_0101a304;
  *(undefined1 *)(DAT_0101a308 + 2) = *DAT_0101a304;
  puVar2 = DAT_0101a324;
  *(undefined1 *)(DAT_0101a324 + 0x13) = puVar1[1];
  *(undefined1 *)((int)puVar2 + 0x4b) = puVar1[2];
  *(undefined1 *)((int)puVar2 + 0x4a) = puVar1[3];
  *(undefined1 *)(puVar2 + 0x11) = puVar1[4];
  *(undefined1 *)((int)puVar2 + 0x45) = puVar1[5];
  *(undefined1 *)((int)puVar2 + 0x46) = puVar1[8];
  *(undefined1 *)((int)puVar2 + 0x47) = puVar1[9];
  *(undefined1 *)(puVar2 + 0x12) = puVar1[10];
  *(undefined1 *)((int)puVar2 + 0x49) = puVar1[0xb];
  puVar3 = DAT_0101a324;
  *(undefined2 *)(DAT_0101a324 + 2) = *(undefined2 *)(puVar2 + 0x11);
  *DAT_0101a320 = *DAT_0101a320 | 0x80;
  *(undefined1 *)((int)puVar2 + 0x4e) = 0;
  *(undefined1 *)((int)puVar2 + 0x4d) = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined1 *)(puVar2 + 0x13) = 0;
  *(undefined1 *)((int)puVar2 + 0x4f) = 0;
  *(undefined1 *)(puVar2 + 0x14) = 0;
  *(undefined1 *)((int)puVar2 + 0x52) = 0;
  *(undefined1 *)((int)puVar2 + 0x51) = 0;
  return;
}


// ===== FUN_0101a81c @ 0101a81c

bool FUN_0101a81c(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = '\0';
  if ((*param_1 == '\a') || (*param_1 == '\b')) {
    iVar4 = 0;
    cVar3 = '\0';
    do {
      pcVar1 = param_1 + iVar4;
      iVar4 = iVar4 + 1;
      cVar3 = *pcVar1 + cVar3;
    } while (iVar4 < 8);
    cVar2 = param_1[8];
  }
  else {
    iVar4 = 0;
    do {
      pcVar1 = param_1 + iVar4;
      iVar4 = iVar4 + 1;
      cVar3 = *pcVar1 + cVar3;
    } while (iVar4 < 7);
    cVar2 = param_1[7];
  }
  return (char)(cVar2 + cVar3) == -1;
}


// ===== FUN_0101a85c @ 0101a85c
// decompile failed
// ===== FUN_0101ab3e @ 0101ab3e

undefined4 FUN_0101ab3e(undefined1 *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  
  iVar2 = DAT_0101ab7c;
  pcVar1 = DAT_0101ab6c;
  iVar3 = 0;
  if (*DAT_0101ab6c == '\0') {
    if (DAT_0101ab6c[1] == '\0') {
      return 0;
    }
    DAT_0101ab6c[1] = '\0';
    uVar6 = *(uint *)(pcVar1 + 0xc);
    for (uVar4 = 0; iVar2 = DAT_0101abd4, uVar4 < uVar6 >> 2; uVar4 = uVar4 + 1) {
      puVar5 = *(ushort **)(pcVar1 + 8);
      *(uint *)(DAT_0101abd4 + uVar4 * 4) =
           (uint)(byte)puVar5[1] << 0x10 | (uint)*(byte *)((int)puVar5 + 3) << 0x18 | (uint)*puVar5;
      *(ushort **)(pcVar1 + 8) = puVar5 + 2;
    }
    iVar3 = 0;
    do {
      *param_1 = *(undefined1 *)(iVar2 + iVar3);
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x40);
  }
  else {
    *DAT_0101ab6c = '\0';
    do {
      *param_1 = *(undefined1 *)(iVar2 + iVar3);
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x40);
  }
  return 1;
}


// ===== FUN_0101abd8 @ 0101abd8

void FUN_0101abd8(uint param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (2 < param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_gpi_0101afe4,0xe,DAT_0101afe0);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_gpi_0101afe4,0xf,DAT_0101afe0);
  }
  iVar1 = DAT_0101b008;
  uVar2 = 0;
  do {
    if ((1 << (uVar2 & 0xff) & param_2) != 0) {
      *(undefined1 *)(param_1 * 0x10 + uVar2 + iVar1) = param_3;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}


// ===== FUN_0101af4e @ 0101af4e

void FUN_0101af4e(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (2 < param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_gpi_0101afe4,0x96,DAT_0101afe0 + 0x79,param_4,
                 param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_gpi_0101afe4,0x97,DAT_0101afe0 + 0x79);
  }
  iVar1 = DAT_0101b008;
  uVar3 = 0;
  do {
    if ((1 << (uVar3 & 0xff) & param_2) != 0) {
      pbVar2 = (byte *)(param_1 * 0x10 + uVar3 + iVar1);
      *pbVar2 = (*pbVar2 | 0x3f) & 0xfe;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x10);
  return;
}


// ===== FUN_0101b01a @ 0101b01a

void FUN_0101b01a(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (2 < param_1) {
    FUN_0101e25a(DAT_0101b194,0xaa,DAT_0101b190,param_4,param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_0101e25a(DAT_0101b194,0xab,DAT_0101b190);
  }
  iVar1 = DAT_0101b198;
  uVar3 = 0;
  do {
    if ((1 << (uVar3 & 0xff) & param_2) != 0) {
      pbVar2 = (byte *)(param_1 * 0x10 + uVar3 + iVar1);
      *pbVar2 = *pbVar2 | 0x3f;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x10);
  return;
}


// ===== FUN_0101b0bc @ 0101b0bc

void FUN_0101b0bc(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (2 < param_1) {
    FUN_0101e25a(DAT_0101b194,0xbe,DAT_0101b190 + 0xd,param_4,param_4);
  }
  uVar2 = 0;
  do {
    uVar1 = 1 << (uVar2 & 0xff);
    if ((uVar1 & param_2) >> (uVar2 & 0xff) == 0) {
      FUN_0101af4e(param_1,uVar1 & 0xffff);
    }
    else {
      FUN_0101b01a(param_1,uVar1 & 0xffff);
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}


// ===== FUN_0101b1e8 @ 0101b1e8

void FUN_0101b1e8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0xf3,DAT_0101b570 + 0x73);
  }
  if ((param_2 != 1) && (param_2 != 2)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0xf4,DAT_0101b570 + 0x73);
  }
  if (param_1 == 0) {
    iVar2 = DAT_0101b598;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    iVar2 = DAT_0101b59c;
  }
  if (param_2 != 2) {
    if (param_2 == 1) {
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0x7fffffff;
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | param_3 << 0x1f;
    }
    return;
  }
  if (param_3 == 0) {
    uVar1 = *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  }
  else {
    uVar1 = *(uint *)(iVar2 + 0x1c) | 0x100;
  }
  *(uint *)(iVar2 + 0x1c) = uVar1;
  return;
}


// ===== FUN_0101b256 @ 0101b256

undefined4 FUN_0101b256(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 == 0) {
    iVar2 = DAT_0101b598;
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    iVar2 = DAT_0101b59c;
  }
  if (((*(uint *)(iVar2 + 0x1c) & 0xffff) >> 8 == 0) || (*(int *)(iVar2 + 0x28) >> 0x10 < 1)) {
    if (*(int *)(iVar2 + 0x1c) < 0) {
      return 1;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


// ===== FUN_0101b286 @ 0101b286

void FUN_0101b286(void)

{
  undefined4 uVar1;
  undefined4 extraout_r3;
  
  uVar1 = FUN_0101b256();
  FUN_0101b1e8(extraout_r3,uVar1,0);
  return;
}


// ===== FUN_0101b29a @ 0101b29a

void FUN_0101b29a(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x41,DAT_0101b570 + 0x15);
  }
  if (param_1 == 0) {
    iVar1 = DAT_0101b598;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    iVar1 = DAT_0101b59c;
  }
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}


// ===== FUN_0101b326 @ 0101b326

void FUN_0101b326(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x9a,DAT_0101b570 + 0x31,param_4,
                 param_4);
  }
  if ((*param_2 != 0x40) && (*param_2 != 0)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x9b,DAT_0101b570 + 0x31);
  }
  if ((*(uint *)(param_2 + 4) < 0x5b9) || (DAT_0101b5a4 <= *(uint *)(param_2 + 4))) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x9c,DAT_0101b570 + 0x31);
  }
  if ((param_2[10] != 0) && (param_2[10] != 2)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x9d,DAT_0101b570 + 0x31);
  }
  if ((param_2[0xb] != 0) && (param_2[0xb] != 0x10)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x9e,DAT_0101b570 + 0x31);
  }
  if ((param_2[9] != 0) && (param_2[9] != 8)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x9f,DAT_0101b570 + 0x31);
  }
  iVar7 = FUN_0101f134(DAT_0101b5a8,*(undefined4 *)(param_2 + 4));
  iVar6 = DAT_0101b59c;
  iVar8 = DAT_0101b598;
  bVar1 = param_2[10];
  bVar2 = param_2[8];
  bVar3 = param_2[0xb];
  bVar4 = param_2[9];
  bVar5 = *param_2;
  if (param_1 == 0) {
    *(undefined4 *)(DAT_0101b598 + 0x1c) = 0;
    uVar9 = DAT_0101b5b0;
  }
  else {
    *(undefined4 *)(DAT_0101b59c + 0x1c) = 0;
    iVar8 = iVar6;
    uVar9 = DAT_0101b5ac;
  }
  *(undefined4 *)(iVar8 + 4) = uVar9;
  *(undefined4 *)(iVar8 + 8) = 0x400;
  *(undefined1 *)(iVar8 + 0xc) = 1;
  *(byte *)(iVar8 + 0xf) = *(byte *)(iVar8 + 0xf) | 0x20;
  *(byte *)(iVar8 + 0xf) = *(byte *)(iVar8 + 0xf) & 0xdf;
  *(undefined4 *)(iVar8 + 0x1c) = 0;
  *(uint *)(iVar8 + 0x1c) =
       (uint)(byte)(bVar1 | bVar2 | bVar4 | bVar3 | bVar5) | iVar7 << 0x10 | 0x81;
  return;
}


// ===== FUN_0101b42c @ 0101b42c

bool FUN_0101b42c(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DAT_0101b598;
  }
  else {
    if (param_1 != 1) {
      FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0xd7,DAT_0101b570 + 0x4d);
    }
    iVar1 = DAT_0101b59c;
  }
  return *(int *)(iVar1 + 0x28) >> 0x10 != 0;
}


// ===== FUN_0101b49e @ 0101b49e

uint FUN_0101b49e(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x138,DAT_0101b570 + 0x92,param_4,
                 param_4);
  }
  if (param_2 == 0) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_uar_0101b574,0x139,DAT_0101b570 + 0x92);
  }
  if (param_1 == 0) {
    piVar2 = (int *)(DAT_0101b598 + 0x28);
    puVar1 = (undefined1 *)(DAT_0101b598 + 0x24);
  }
  else {
    piVar2 = (int *)(DAT_0101b59c + 0x28);
    puVar1 = (undefined1 *)(DAT_0101b59c + 0x24);
  }
  for (; (0 < *piVar2 >> 0x10 && (uVar3 < param_3)); uVar3 = uVar3 + 1) {
    *(undefined1 *)(param_2 + uVar3) = *puVar1;
  }
  return uVar3;
}


// ===== FUN_0101b5b4 @ 0101b5b4

void FUN_0101b5b4(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_8 [4];
  
  puVar2 = DAT_0101b670;
  puVar1 = DAT_0101b66c;
  if (param_1 == 0) {
    *DAT_0101b670 = local_8;
    puVar2[2] = (puVar2[2] & 0xffff) + 0x10000;
    *(undefined1 *)((int)puVar2 + 0xf) = 0x80;
    do {
    } while ((puVar2[4] & 1) == 0);
    return;
  }
  *DAT_0101b66c = local_8;
  puVar1[2] = (puVar1[2] & 0xffff) + 0x10000;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  do {
  } while ((puVar1[4] & 1) == 0);
  return;
}


// ===== FUN_0101b600 @ 0101b600

void FUN_0101b600(int param_1,int param_2)

{
  if (param_1 == 0) {
    *(uint *)(DAT_0101b670 + 0x1c) = *(uint *)(DAT_0101b670 + 0x1c) & 0xffff00ff | param_2 << 8;
    return;
  }
  if (param_1 != 1) {
    FUN_0101e25a(DAT_0101b678,0x18e,DAT_0101b674);
  }
  *(uint *)(DAT_0101b66c + 0x1c) = *(uint *)(DAT_0101b66c + 0x1c) & 0xffff00ff | param_2 << 8;
  return;
}


// ===== FUN_0101b648 @ 0101b648

uint FUN_0101b648(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DAT_0101b670;
  }
  else {
    if (param_1 != 1) {
      FUN_0101e25a(DAT_0101b678,0x1a7,DAT_0101b674 + 0x10);
    }
    iVar1 = DAT_0101b66c;
  }
  return *(uint *)(iVar1 + 0x28) >> 0x10;
}


// ===== thunk_EXT_FUN_00004238 @ 0101b67c

void thunk_EXT_FUN_00004238(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101b67e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101b8e0)();
  return;
}


// ===== thunk_EXT_FUN_0000425c @ 0101b680

void thunk_EXT_FUN_0000425c(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101b684. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_0101b8e0 + 0x24))();
  return;
}


// ===== FUN_0101b686 @ 0101b686

void FUN_0101b686(uint param_1,int param_2)

{
  uint uVar1;
  
  if (8 < param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_tim_0101b8e8,0x21,DAT_0101b8e4);
  }
  uVar1 = 1 << ((param_1 & 0x3f) << 2);
  if (param_2 == 1) {
    if (7 < param_1) {
      uVar1 = *(uint *)(DAT_0101b910 + 0xc) | 1;
      goto LAB_0101b6ca;
    }
    uVar1 = *(uint *)(DAT_0101b910 + 8) | uVar1;
  }
  else {
    if (7 < param_1) {
      uVar1 = *(uint *)(DAT_0101b910 + 0xc) & 0xfffffffe;
LAB_0101b6ca:
      *(uint *)(DAT_0101b910 + 0xc) = uVar1;
      return;
    }
    uVar1 = *(uint *)(DAT_0101b910 + 8) & ~uVar1;
  }
  *(uint *)(DAT_0101b910 + 8) = uVar1;
  return;
}


// ===== FUN_0101b6ce @ 0101b6ce

void FUN_0101b6ce(byte *param_1)

{
  if (8 < *param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_tim_0101b8e8,0x10,DAT_0101b8e4 + 8);
  }
  FUN_0101b686(*param_1,0);
  *(undefined4 *)((uint)*param_1 * 8 + DAT_0101b910 + -0x40) = *(undefined4 *)(param_1 + 4);
  if (*param_1 < 8) {
    *(uint *)(DAT_0101b910 + 8) = *(uint *)(DAT_0101b910 + 8) | 0xc << ((*param_1 & 0x3f) << 2);
    return;
  }
  *(uint *)(DAT_0101b910 + 0xc) = *(uint *)(DAT_0101b910 + 0xc) | 0xc;
  return;
}


// ===== FUN_0101b724 @ 0101b724

void FUN_0101b724(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (8 < param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_tim_0101b8e8,0x35,DAT_0101b8e4 + 0x11);
  }
  iVar1 = DAT_0101b910;
  uVar2 = 4 << ((param_1 & 0x3f) << 2);
  if (param_2 == 1) {
    if (7 < param_1) {
      uVar2 = *(uint *)(DAT_0101b910 + 0xc) | 4;
      goto LAB_0101b77a;
    }
    uVar2 = *(uint *)(DAT_0101b910 + 8) | uVar2;
  }
  else {
    if (param_2 != 0) {
      FUN_0101e25a(s_____________Librarier_sdk_yc_tim_0101b8e8,0x36,DAT_0101b8e4 + 0x11);
    }
    if (7 < param_1) {
      uVar2 = *(uint *)(iVar1 + 0xc) & 0xfffffffb;
LAB_0101b77a:
      *(uint *)(iVar1 + 0xc) = uVar2;
      return;
    }
    uVar2 = *(uint *)(iVar1 + 8) & ~uVar2;
  }
  *(uint *)(iVar1 + 8) = uVar2;
  return;
}


// ===== FUN_0101b7a0 @ 0101b7a0

void FUN_0101b7a0(byte *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (8 < *param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_tim_0101b8e8,0x51,DAT_0101b8e4 + 0x2e);
  }
  FUN_0101b686(*param_1,0);
  iVar1 = DAT_0101b910 + -0x40;
  *(undefined4 *)((uint)*param_1 * 8 + iVar1) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((uint)*param_1 * 8 + iVar1 + 4) = *(undefined4 *)(param_1 + 4);
  iVar1 = DAT_0101b910;
  uVar2 = (uint)*param_1;
  if (param_1[0xc] == 1) {
    if (7 < uVar2) {
      uVar2 = *(uint *)(DAT_0101b910 + 0xc) | 2;
      goto LAB_0101b80a;
    }
    uVar2 = *(uint *)(DAT_0101b910 + 8) | 2 << ((uVar2 & 0x3f) << 2);
  }
  else {
    if (7 < uVar2) {
      uVar2 = *(uint *)(DAT_0101b910 + 0xc) & 0xfffffffd;
LAB_0101b80a:
      *(uint *)(DAT_0101b910 + 0xc) = uVar2;
      goto LAB_0101b80c;
    }
    uVar2 = *(uint *)(DAT_0101b910 + 8) & ~(2 << ((uVar2 & 0x3f) << 2));
  }
  *(uint *)(DAT_0101b910 + 8) = uVar2;
LAB_0101b80c:
  if (*param_1 < 8) {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & ~(4 << ((*param_1 & 0x3f) << 2));
    return;
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffb;
  return;
}


// ===== FUN_0101bbb0 @ 0101bbb0

void FUN_0101bbb0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 * 0x100 + DAT_0101bd14);
  *puVar1 = param_2;
  puVar1[1] = param_4;
  puVar1[2] = param_3 << 0x10 | param_5;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  return;
}


// ===== FUN_0101bbca @ 0101bbca

void FUN_0101bbca(int param_1)

{
  do {
  } while ((*(uint *)(param_1 * 0x100 + DAT_0101bd14 + 0x10) & 1) == 0);
  return;
}


// ===== FUN_0101bbd8 @ 0101bbd8

void FUN_0101bbd8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0101bbb0(6,param_2,param_3,param_1,param_3);
  FUN_0101bbca(6);
  return;
}


// ===== FUN_0101bc92 @ 0101bc92

void FUN_0101bc92(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_0101bd08;
  if (*DAT_0101bd08 == '\0') {
    *DAT_0101bd24 = 0x800;
    *pcVar1 = '\x01';
    *(undefined1 *)(DAT_0101bd0c + 0x1c) = 0x94;
    thunk_EXT_FUN_0000425c(10);
    FUN_0101c18a(1,0xd00000);
    thunk_EXT_FUN_0000425c(1);
    DAT_000c8010 = 1;
    thunk_EXT_FUN_0000425c(1);
    do {
    } while (-1 < (int)((uint)*(byte *)(DAT_0101bd1c + 0x23) << 0x18));
    *(byte *)(DAT_0101bd1c + 0x23) = *(byte *)(DAT_0101bd1c + 0x23) & 0x7f;
  }
  return;
}


// ===== FUN_0101be90 @ 0101be90

void FUN_0101be90(uint param_1)

{
  int iVar1;
  
  if (DAT_0101bfd0 < param_1) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_sys_0101bf94,0x42,DAT_0101bf90 + 0x22);
  }
  iVar1 = DAT_0101bfc4;
  *(uint *)(DAT_0101bfc4 + 0x10) = *(uint *)(DAT_0101bfc4 + 0x10) & 0xfffffffe;
  *(uint *)(iVar1 + 0x14) = param_1 - 1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *DAT_0101bfd4 = 0;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 7;
  return;
}


// ===== FUN_0101bec6 @ 0101bec6

void FUN_0101bec6(void)

{
  int iVar1;
  
  iVar1 = DAT_0101bfc4;
  *(uint *)(DAT_0101bfc4 + 0x10) = *(uint *)(DAT_0101bfc4 + 0x10) & 0xfffffffe;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *DAT_0101bfd4 = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  return;
}


// ===== FUN_0101beea @ 0101beea

void FUN_0101beea(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_0101bfc4 + 0x10) & 0xfffffffe;
  }
  else {
    uVar1 = *(uint *)(DAT_0101bfc4 + 0x10) | 1;
  }
  *(uint *)(DAT_0101bfc4 + 0x10) = uVar1;
  return;
}


// ===== FUN_0101bf1a @ 0101bf1a

undefined4 FUN_0101bf1a(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_1 = *DAT_0101bfd4 - param_1;
  if (param_1 < 0) {
    param_1 = param_1 + DAT_0101bfd8;
  }
  uVar1 = FUN_0101f134(DAT_0101bfc0,(*(uint *)(DAT_0101bfbc + 0x20) & 0xf) + 2);
  uVar1 = FUN_0101f134(uVar1,1000);
  uVar2 = FUN_0101f134(param_1 * *(int *)(DAT_0101bfc4 + 0x14),uVar1);
  if (uVar2 < param_2) {
    return 0;
  }
  return 1;
}


// ===== FUN_0101c01e @ 0101c01e

void FUN_0101c01e(uint param_1)

{
  *(uint *)(DAT_0101c0fc + 0x1c) = *(uint *)(DAT_0101c0fc + 0x1c) | 0x80;
  *(uint *)(DAT_0101c0f4 + 0x20) = *(uint *)(DAT_0101c0f4 + 0x20) & 0xfffffff0 | param_1;
  return;
}


// ===== FUN_0101c036 @ 0101c036

void FUN_0101c036(uint param_1)

{
  if (param_1 == 0) {
    (*DAT_0101c104)(DAT_0101c100,DAT_0101c100 + 0x40);
    FUN_0101c01e(0);
    return;
  }
  if (((param_1 != 2) && (param_1 != 6)) && (param_1 != 0xe)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_sys_0101c0cc,0x1f,DAT_0101c0c8 + 0x2d);
  }
  *(uint *)(DAT_0101c0f4 + 0x20) = *(uint *)(DAT_0101c0f4 + 0x20) & 0xfffffff0 | param_1;
  return;
}


// ===== thunk_EXT_FUN_00004480 @ 0101c118

void thunk_EXT_FUN_00004480(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101c11a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101c178)();
  return;
}


// ===== thunk_EXT_FUN_0000442c @ 0101c11c

void thunk_EXT_FUN_0000442c(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101c120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_0101c178 + -0x54))();
  return;
}


// ===== thunk_EXT_FUN_00004c80 @ 0101c180

void thunk_EXT_FUN_00004c80(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101c182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101c3d4)();
  return;
}


// ===== thunk_EXT_FUN_00004c9c @ 0101c184

void thunk_EXT_FUN_00004c9c(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101c188. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_0101c3d4 + 0x1c))();
  return;
}


// ===== FUN_0101c18a @ 0101c18a

void FUN_0101c18a(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  *(uint *)(DAT_0101c3d8 + 0x2c) = *(uint *)(DAT_0101c3d8 + 0x2c) & 0xffffdfff;
  iVar1 = DAT_0101c3dc;
  *(char *)(DAT_0101c3dc + 0xc) = (char)param_2;
  thunk_EXT_FUN_000000c6(10);
  *(char *)(iVar1 + 0xd) = (char)((uint)param_2 >> 8);
  thunk_EXT_FUN_000000c6(10);
  *(char *)(iVar1 + 0xe) = (char)((uint)param_2 >> 0x10);
  thunk_EXT_FUN_000000c6(10);
  *(char *)(iVar1 + 0xf) = (char)((uint)param_2 >> 0x18);
  thunk_EXT_FUN_000000c6(10);
  DAT_000c8005 = (char)(1 << (param_1 & 0xff));
  return;
}


// ===== FUN_0101c1ce @ 0101c1ce

uint FUN_0101c1ce(int param_1)

{
  uint uVar1;
  
  if ((param_1 == 2) || (param_1 == 3)) {
    uVar1 = (*(code *)(DAT_0101c3d4 + 0xa4))();
    return uVar1 >> 2;
  }
  uVar1 = (*(code *)(DAT_0101c3d4 + 0xa4))();
  return uVar1;
}


// ===== thunk_EXT_FUN_00004d68 @ 0101c1e6

void thunk_EXT_FUN_00004d68(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101c1ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_0101c3d4 + 0xe8))();
  return;
}


// ===== FUN_0101c1ec @ 0101c1ec

void FUN_0101c1ec(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101c1f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101c3e0)();
  return;
}


// ===== FUN_0101c20c @ 0101c20c

void FUN_0101c20c(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = DAT_0101c3e4;
  iVar3 = 0;
  do {
    pbVar2 = (byte *)(iVar3 + iVar1);
    if (((*pbVar2 == 0) || (*pbVar2 == 4)) || (*pbVar2 == 5)) {
      *pbVar2 = *pbVar2 | 0x80;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x30);
  return;
}


// ===== FUN_0101c236 @ 0101c236

void FUN_0101c236(void)

{
  int iVar1;
  
  if (*DAT_0101c3e8 == '\x01') {
    *DAT_0101c3e8 = '\0';
    iVar1 = DAT_0101c3d8;
    *(undefined1 *)(DAT_0101c3d8 + -0x1d) = 0;
    *(byte *)(DAT_0101c3dc + 3) = *(byte *)(DAT_0101c3dc + 3) & 0x7f;
    *DAT_0101c3ec = 0x800;
    *(undefined1 *)(iVar1 + -4) = 0x90;
    FUN_0101c18a(2,0);
    thunk_EXT_FUN_00004238(1000);
    FUN_0101c18a(3,0);
    thunk_EXT_FUN_00004238(1000);
    FUN_0101c18a(5,0);
    thunk_EXT_FUN_00004238(1000);
    FUN_0101c18a(1,0xd80000);
    thunk_EXT_FUN_00004238(1000);
    FUN_0101c18a(4,0xffffffff);
    thunk_EXT_FUN_00004238(1000);
  }
  return;
}


// ===== FUN_0101c2b0 @ 0101c2b0

void FUN_0101c2b0(void)

{
  FUN_0101c036(0xe);
  return;
}


// ===== FUN_0101c3bc @ 0101c3bc

void FUN_0101c3bc(void)

{
  uint uVar1;
  
  uVar1 = FUN_0101c1ce(1);
  FUN_0101c18a(1,uVar1 & 0xfffdffff);
  return;
}


// ===== FUN_0101c3fc @ 0101c3fc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101c3fc(uint param_1)

{
  if ((param_1 == 0) || (0x1f < param_1)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_wdt_0101c47c,0xe,DAT_0101c478);
  }
  _DAT_000f0000 = _DAT_000f0000 & 0xe0 | param_1;
  return;
}


// ===== FUN_0101c420 @ 0101c420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101c420(void)

{
  _DAT_000f0008 = DAT_0101c4a0;
  return;
}


// ===== FUN_0101c42a @ 0101c42a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101c42a(void)

{
  _DAT_000f0000 = _DAT_000f0000 | 0x40;
  return;
}


// ===== FUN_0101c438 @ 0101c438

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101c438(int param_1)

{
  uint uVar1;
  
  _DAT_000f0000 = _DAT_000f0000 & 0xffffffdf | param_1 << 5;
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_0101c4a4 + 0x34) | 2;
  }
  else {
    uVar1 = *(uint *)(DAT_0101c4a4 + 0x34) & 0xfffffffd;
  }
  *(uint *)(DAT_0101c4a4 + 0x34) = uVar1;
  return;
}


// ===== FUN_0101c53a @ 0101c53a

void FUN_0101c53a(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_ssc_0101c8a8,0x3d,DAT_0101c8a4 + 0x29);
  }
  iVar2 = DAT_0101c8cc + 0x10;
  uVar1 = thunk_EXT_FUN_00004c80(iVar2);
  if (param_1 == 1) {
    uVar1 = uVar1 | 0x100000;
  }
  else if (param_1 == 0) {
    uVar1 = uVar1 & 0xffefffff;
  }
  thunk_EXT_FUN_00004c9c(iVar2,uVar1);
  return;
}


// ===== FUN_0101c7ec @ 0101c7ec

void FUN_0101c7ec(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((param_2 == 0) || (0x20 < param_2)) || (0x20 < param_2 + param_3)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_ssc_0101c8a8,0xd5,DAT_0101c8a4 + 0x88,param_4,
                 param_4);
  }
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = thunk_EXT_FUN_00004c80((uVar2 + param_3 & 0xff) * 4 + DAT_0101c8cc + 0x7c);
    *(undefined4 *)(param_1 + uVar2 * 4) = uVar1;
  }
  return;
}


// ===== FUN_0101c82e @ 0101c82e

void FUN_0101c82e(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  
  if (((param_2 == 0) || (0x20 < param_2)) || (0x20 < param_2 + param_3)) {
    FUN_0101e25a(s_____________Librarier_sdk_yc_ssc_0101c8a8,0xe2,DAT_0101c8a4 + 0x97,param_4,
                 param_4);
  }
  FUN_0101c53a(0);
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    thunk_EXT_FUN_00004c9c
              ((uVar1 + param_3 & 0xff) * 4 + DAT_0101c8cc + 0x7c,
               *(undefined4 *)(param_1 + uVar1 * 4));
  }
  FUN_0101c53a(1);
  return;
}


// ===== FUN_0101c9a0 @ 0101c9a0

void FUN_0101c9a0(void)

{
  *(undefined1 *)(DAT_0101c9b4 + 0x23) = 0;
  return;
}


// ===== FUN_0101c9c4 @ 0101c9c4

void FUN_0101c9c4(void)

{
  int iVar1;
  
  DAT_000f6000 = 0;
  thunk_EXT_FUN_0000425c(1);
  iVar1 = DAT_0101cdd8;
  DAT_000f6010 = 0xc0;
  DAT_000f6000 = 0x3c;
  *(undefined1 *)(DAT_0101cdd8 + 6) = 0xff;
  *(undefined1 *)(iVar1 + 7) = 0xff;
  DAT_000f6004 = 0;
  DAT_000f6001 = 0x70;
  DAT_000f6002 = 0xf0;
  DAT_000f6003 = 0xff;
  return;
}


// ===== FUN_0101c9f2 @ 0101c9f2

void FUN_0101c9f2(void)

{
  FUN_0101cebc(6);
  FUN_0101c9c4();
  FUN_0101f1de(DAT_0101cddc,0x180);
  FUN_0101d7ee(DAT_0101cddc,1,DAT_0101cde8,DAT_0101cde4,DAT_0101cde0);
  *DAT_0101cdec = *DAT_0101cdec | 1;
  return;
}


// ===== FUN_0101ca24 @ 0101ca24

void FUN_0101ca24(void)

{
  FUN_0101d456(DAT_0101cddc);
  return;
}


// ===== FUN_0101ca2e @ 0101ca2e

int FUN_0101ca2e(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 != 0) && ((int)((uint)*DAT_0101cdf0 << 0x1b) < 0)) {
    FUN_0101d31e(DAT_0101cddc,0x81,param_2,param_3);
    param_1 = 0;
  }
  return param_1;
}


// ===== FUN_0101ca4c @ 0101ca4c

int FUN_0101ca4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 != 0) && ((int)((uint)*DAT_0101cdf0 << 0x19) < 0)) {
    FUN_0101d31e(DAT_0101cddc,0x82,param_2,param_3);
    param_1 = 0;
  }
  return param_1;
}


// ===== FUN_0101ca6c @ 0101ca6c

void FUN_0101ca6c(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  pbVar1 = DAT_0101cdf4;
  if ((int)((uint)*DAT_0101cdf0 << 0x1e) < 0) {
    if ((int)((uint)*DAT_0101cdf4 << 0x1b) < 0) {
      bVar3 = FUN_0101ca2e((*DAT_0101cdf4 & 0x1f) >> 4,DAT_0101cdf8,8);
      *pbVar1 = *pbVar1 & 0xef | (bVar3 & 1) << 4;
    }
    puVar2 = DAT_0101cdfc;
    if ((int)((uint)*pbVar1 << 0x1a) < 0) {
      *DAT_0101cdfc = 1;
      bVar3 = FUN_0101ca4c((*pbVar1 & 0x3f) >> 5,puVar2,0x10);
      *pbVar1 = *pbVar1 & 0xdf | (bVar3 & 1) << 5;
    }
    puVar2 = DAT_0101ce00;
    if ((*pbVar1 & 1) != 0) {
      *DAT_0101ce00 = 6;
      bVar3 = FUN_0101ca4c(*pbVar1 & 1,puVar2,8);
      *pbVar1 = *pbVar1 & 0xfe | bVar3 & 1;
      if ((*pbVar1 & 1) == 0) {
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[7] = 0;
      }
    }
    puVar2 = DAT_0101ce04;
    if ((int)((uint)*pbVar1 << 0x1e) < 0) {
      *DAT_0101ce04 = 3;
      bVar3 = FUN_0101ca4c((*pbVar1 & 3) >> 1,puVar2,3);
      *pbVar1 = *pbVar1 & 0xfd | (bVar3 & 1) << 1;
    }
    puVar2 = DAT_0101ce08;
    if ((int)((uint)*pbVar1 << 0x1c) < 0) {
      *DAT_0101ce08 = 5;
      bVar3 = FUN_0101ca4c((*pbVar1 & 0xf) >> 3,puVar2,4);
      *pbVar1 = *pbVar1 & 0xf7 | (bVar3 & 1) << 3;
    }
    puVar2 = DAT_0101ce0c;
    if ((int)((uint)*pbVar1 << 0x1d) < 0) {
      *DAT_0101ce0c = 2;
      bVar3 = FUN_0101ca4c((*pbVar1 & 7) >> 2,puVar2,2);
      *pbVar1 = *pbVar1 & 0xfb | (bVar3 & 1) << 2;
    }
  }
  return;
}


// ===== FUN_0101cb6e @ 0101cb6e

void FUN_0101cb6e(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  
  pbVar8 = DAT_0101cdf0;
  uVar10 = 0;
  *DAT_0101cdf0 = *DAT_0101cdf0 & 0xfe;
  FUN_010108bc();
  FUN_0101c20c();
  *(undefined1 *)((uint)*DAT_0101ce10 * 0x10 + DAT_0101ce14 + 2) = 0x3f;
  FUN_0101c9a0();
  FUN_0101c2b0();
  FUN_010109d6();
  iVar7 = DAT_0101cdd8;
  *(undefined1 *)(DAT_0101cdd8 + 9) = 0;
  *(undefined1 *)(iVar7 + 10) = 0;
  thunk_EXT_FUN_0000425c(5);
  *(undefined2 *)(DAT_0101ce18 + 8) = *(undefined2 *)(iVar7 + 9);
  FUN_0101c420();
  iVar9 = DAT_0101ce18;
  if ((int)((uint)*pbVar8 << 0x1c) < 0) {
    while( true ) {
      FUN_0101c420();
      uVar1 = *(ushort *)(DAT_0101ce14 + 0x3e);
      uVar2 = *(ushort *)(DAT_0101ce14 + 0x3e);
      uVar3 = *(ushort *)(DAT_0101ce14 + 0x3e);
      uVar4 = *(ushort *)(DAT_0101ce14 + 0x3c);
      uVar5 = *(ushort *)(DAT_0101ce14 + 0x3c);
      uVar6 = *(ushort *)(DAT_0101ce14 + 0x3c);
      thunk_EXT_FUN_0000425c(1);
      if (((uVar1 & 7) >> 2 | uVar2 & 2 | (uVar3 & 1) << 2 | ((uVar4 & 0x3fff) >> 0xd) << 3 |
           ((uVar5 & 0x1fff) >> 0xc) << 4 | ((uVar6 & 0xfff) >> 0xb) << 5 | 0xc0) != 0xff) break;
      if ((-1 < (int)((uint)*pbVar8 << 0x1c)) || (thunk_EXT_FUN_0000425c(1), (*pbVar8 & 1) != 0))
      goto LAB_0101cc72;
      thunk_EXT_FUN_0000425c(1);
      if (*(short *)(DAT_0101ce18 + 8) != *(short *)(iVar7 + 9)) goto LAB_0101cc72;
    }
    uVar10 = 1;
  }
  else {
    *(undefined2 *)(DAT_0101ce18 + 8) = *(undefined2 *)(iVar7 + 9);
    do {
      FUN_0101c420();
      thunk_EXT_FUN_0000425c(1);
      if ((*pbVar8 & 1) != 0) break;
    } while (*(short *)(iVar9 + 8) == *(short *)(iVar7 + 9));
  }
LAB_0101cc72:
  *pbVar8 = *pbVar8 & 0xfb;
  FUN_0101c036(0);
  thunk_EXT_FUN_0000425c(1);
  if (((*pbVar8 & 0xf) >> 3 & uVar10) != 0) {
    FUN_0101d1e2(*(undefined4 *)(DAT_0101cdf0 + -4));
  }
  FUN_01010d6e();
  FUN_0101c420();
  return;
}


// ===== FUN_0101ccc6 @ 0101ccc6

void FUN_0101ccc6(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_20;
  
  disableIRQinterrupts();
  FUN_0101cebc(6);
  DAT_000f6000 = 0;
  thunk_EXT_FUN_0000425c(1);
  DAT_000f6000 = 0x30;
  *(undefined4 *)(DAT_0101ce20 + 0x10) = DAT_0101ce1c;
  iVar3 = DAT_0101ce20;
  *(uint *)(DAT_0101ce20 + 0x48) = *(uint *)(DAT_0101ce20 + 0x48) & 0xfffff0ff;
  *(uint *)(iVar3 + 0x48) = *(uint *)(iVar3 + 0x48) | 0xd00;
  iVar4 = 0;
  iVar3 = 3;
  FUN_0101e226(s_start_0101ce24);
  do {
    do {
      local_20 = 0;
      uVar1 = 0;
      while (*(short *)(DAT_0101cdd8 + 9) == *(short *)(DAT_0101cdd8 + 9)) {
        local_20 = local_20 + 1;
        if (DAT_0101ce2c < local_20) {
          enableIRQinterrupts();
          return;
        }
      }
      while (*(short *)(DAT_0101cdd8 + 9) == *(short *)(DAT_0101cdd8 + 9)) {
        uVar1 = uVar1 + 1;
        if (DAT_0101cedc < uVar1) {
          enableIRQinterrupts();
          return;
        }
      }
      uVar1 = *(int *)(DAT_0101ce20 + 0x58) - *(int *)(DAT_0101ce20 + 0x58);
    } while (0x257ff < uVar1);
    iVar2 = FUN_0101f134(uVar1 * 1000,0x60);
    iVar2 = iVar2 * 0x18;
    FUN_0101e226(s_freq____d_0101ce30,iVar2);
    if (iVar4 == 0) {
      if ((uint)(iVar2 + DAT_0101ce40) <= DAT_0101ce44) goto LAB_0101ce70;
      if (iVar2 < DAT_0101ce3c) {
        iVar4 = 1;
      }
      else {
        iVar4 = 2;
      }
    }
    else if (iVar4 == 1) {
      if (DAT_0101ce3c <= iVar2) {
        iVar4 = 2;
        goto LAB_0101cd88;
      }
    }
    else if (iVar2 <= DAT_0101ce3c) {
      iVar4 = 1;
LAB_0101cd88:
      if (iVar3 != 3) {
LAB_0101ce70:
        *(uint *)(DAT_0101cecc + 0x2c) = *(uint *)(DAT_0101cecc + 0x2c) | 0x40;
        DAT_000f6000 = 0;
        *(undefined4 *)(DAT_0101ced0 + 0x10) = 0;
        *(uint *)(DAT_0101ced0 + 0x48) = *(uint *)(DAT_0101ced0 + 0x48) & 0xfffff0ff;
        FUN_0101e226(&DAT_0101ced4);
        enableIRQinterrupts();
        return;
      }
      iVar3 = 1;
    }
    do {
    } while ((int)((uint)*(byte *)(DAT_0101ce4c + 0x1d) << 0x19) < 0);
    if (iVar2 < DAT_0101ce3c) {
      iVar2 = iVar3 * 0x100;
    }
    else {
      iVar2 = iVar3 * -0x100;
    }
    *DAT_0101ce48 =
         *(uint *)(DAT_0101ce4c + -0x10) & DAT_0101ce54 |
         iVar2 + (DAT_0101ce50 & *(uint *)(DAT_0101ce4c + -0x10));
  } while( true );
}


// ===== FUN_0101cebc @ 0101cebc

void FUN_0101cebc(uint param_1)

{
  *(uint *)(DAT_0101cecc + 0x2c) = *(uint *)(DAT_0101cecc + 0x2c) & ~(1 << (param_1 & 0xff));
  return;
}


// ===== FUN_0101cee0 @ 0101cee0

void FUN_0101cee0(int param_1,undefined1 *param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 3) == '\0') {
    for (; uVar1 < param_4; uVar1 = uVar1 + 1 & 0xff) {
      **(undefined1 **)(param_3 * 4 + param_1 + 0x14) = *param_2;
      param_2 = param_2 + 1;
    }
  }
  return;
}


// ===== FUN_0101cf06 @ 0101cf06

void FUN_0101cf06(undefined4 param_1,undefined1 *param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_4; uVar1 = uVar1 + 1 & 0xff) {
    *param_2 = (&DAT_000f6018)[param_3];
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_0101cf22 @ 0101cf22

undefined4 FUN_0101cf22(undefined1 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_1[3] = 0;
  param_1[2] = 1;
  *(undefined2 *)(param_1 + 4) = 0x40;
  if (param_2 == 1) {
    param_1[0xb] = 1;
    param_1[1] = 4;
    *(undefined2 *)(param_1 + 6) = 0x40;
    param_1[8] = 2;
  }
  else if (param_2 == 0) {
    param_1[0xb] = 0;
    *param_1 = 8;
    param_1[1] = 4;
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  *(undefined1 **)(param_1 + 0xc) = &DAT_000f6000;
  *(int *)(param_1 + 0x10) = DAT_0101d20c;
  uVar1 = 0;
  iVar2 = DAT_0101d20c + 8;
  do {
    iVar4 = uVar1 * 4;
    iVar3 = uVar1 + iVar2;
    uVar1 = uVar1 + 1;
    *(int *)(param_1 + iVar4 + 0x14) = iVar3;
  } while (uVar1 < 4);
  uVar1 = 0;
  iVar2 = DAT_0101d20c + 0x10;
  do {
    iVar4 = uVar1 * 4;
    iVar3 = uVar1 + iVar2;
    uVar1 = uVar1 + 1;
    *(int *)(param_1 + iVar4 + 0x24) = iVar3;
  } while (uVar1 < 4);
  *(int *)(param_1 + 0x34) = DAT_0101d20c + 0x15;
  return 0;
}


// ===== FUN_0101cf92 @ 0101cf92

undefined4 FUN_0101cf92(void)

{
  return 0;
}


// ===== FUN_0101cf96 @ 0101cf96

undefined4 FUN_0101cf96(int param_1,int param_2)

{
  if ((param_2 != 1) && (param_2 == 0)) {
    *(int *)(param_1 + 0xdc) = param_1 + 0x164;
    *(undefined4 *)(param_1 + 0xe4) = 8;
  }
  return 0;
}


// ===== FUN_0101cff2 @ 0101cff2

undefined4 FUN_0101cff2(void)

{
  return 1;
}


// ===== FUN_0101cff6 @ 0101cff6

undefined4 FUN_0101cff6(undefined4 param_1,sbyte *param_2)

{
  byte *pbVar1;
  
  pbVar1 = DAT_0101d210;
  if (*param_2 == 1) {
    *DAT_0101d210 = *DAT_0101d210 & 0xef;
  }
  if (*param_2 == 2) {
    *pbVar1 = *pbVar1 & 0xbf;
  }
  if (*param_2 == 3) {
    pbVar1[1] = pbVar1[1] & 0xfe;
  }
  DAT_000f6010 = (char)(1 << *param_2);
  return 0;
}


// ===== FUN_0101d034 @ 0101d034

undefined4 FUN_0101d034(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 extraout_r12;
  undefined4 uVar5;
  undefined4 extraout_r12_00;
  undefined4 extraout_r12_01;
  undefined4 extraout_r12_02;
  undefined4 extraout_r12_03;
  
  uVar4 = (uint)*param_2;
  if (param_2[1] == 1) {
    if ((*(char *)(param_1 + 3) != '\0') && (uVar4 == 1)) {
      return 0;
    }
    iVar2 = *(int *)(param_2 + 0x14);
    uVar3 = *(int *)(param_2 + 0x10) - iVar2;
    *(uint *)(param_2 + 0x18) = uVar3;
    if (uVar3 == param_2[7]) {
      FUN_0101cee0(param_1,*(int *)(param_2 + 8) + iVar2);
      *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + (uint)param_2[7];
      FUN_0101cff6(param_1,param_2);
      param_2[0x18] = 0;
      param_2[0x19] = 0;
      param_2[0x1a] = 0;
      param_2[0x1b] = 0;
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
      *(undefined1 *)(param_1 + 0x17c) = 1;
      return extraout_r12_00;
    }
    if (uVar3 == 0) {
      FUN_0101cee0(param_1,*(int *)(param_2 + 8) + iVar2,uVar4,0);
      uVar5 = extraout_r12_02;
    }
    else {
      if (param_2[7] < uVar3) {
        FUN_0101cee0(param_1,*(int *)(param_2 + 8) + iVar2);
        FUN_0101cff6(param_1,param_2);
        iVar2 = *(int *)(param_2 + 0x14);
        *(uint *)(param_2 + 0x14) = iVar2 + (uint)param_2[7];
        iVar2 = *(int *)(param_2 + 0x10) - (iVar2 + (uint)param_2[7]);
        uVar5 = extraout_r12_01;
        goto LAB_0101d072;
      }
      FUN_0101cee0(param_1,*(int *)(param_2 + 8) + iVar2,uVar4,uVar3 & 0xff);
      FUN_0101cff6(param_1,param_2);
      uVar5 = extraout_r12_03;
    }
    param_2[0x18] = 0;
    param_2[0x19] = 0;
    param_2[0x1a] = 0;
    param_2[0x1b] = 0;
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
  }
  else {
    bVar1 = **(byte **)(uVar4 * 4 + param_1 + 0x24);
    *DAT_0101d214 = bVar1;
    FUN_0101cf06(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,(uint)bVar1);
    uVar4 = *(int *)(param_2 + 0x14) + (uint)bVar1;
    *(uint *)(param_2 + 0x14) = uVar4;
    if (uVar4 < *(uint *)(param_2 + 0x10)) {
      param_2[0x18] = 0;
      param_2[0x19] = 0;
      param_2[0x1a] = 0;
      param_2[0x1b] = 0;
      *(uint *)(param_2 + 0x10) = uVar4;
      return extraout_r12;
    }
    iVar2 = uVar4 - *(uint *)(param_2 + 0x10);
    uVar5 = extraout_r12;
LAB_0101d072:
    *(int *)(param_2 + 0x18) = iVar2;
  }
  return uVar5;
}


// ===== FUN_0101d114 @ 0101d114

undefined4 FUN_0101d114(int param_1,sbyte *param_2)

{
  **(undefined1 **)(param_1 + 0x10) = (char)(0x10 << *param_2);
  return 0;
}


// ===== FUN_0101d124 @ 0101d124

undefined4 FUN_0101d124(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  
  if (param_2[1] == '\x01') {
    uVar1 = *(uint *)(param_2 + 0x18);
    if (uVar1 == 0) {
      if ((*(int *)(param_2 + 0x10) != 0) &&
         (FUN_0101f134(*(int *)(param_2 + 0x10),param_2[7],param_3,param_4,param_4),
         extraout_r1 == 0)) {
        FUN_0101d114(param_1,param_2);
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
    }
    else {
      if ((byte)param_2[7] < uVar1) {
        FUN_0101cee0(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),0);
        iVar2 = *(int *)(param_2 + 0x14);
        *(uint *)(param_2 + 0x14) = iVar2 + (uint)(byte)param_2[7];
        *(uint *)(param_2 + 0x18) = *(int *)(param_2 + 0x10) - (iVar2 + (uint)(byte)param_2[7]);
      }
      else {
        FUN_0101cee0(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),0,uVar1 & 0xff);
        *(undefined4 *)(param_2 + 0x18) = 0;
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
      }
      FUN_0101cff6(param_1,param_2);
    }
  }
  else if (*(uint *)(param_2 + 0x10) != 0) {
    FUN_0101cf06(param_1,*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14),*param_2,
                 *(uint *)(param_2 + 0x10) & 0xff);
    *(int *)(param_2 + 8) = param_1 + 0x164;
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  return 0;
}


// ===== FUN_0101d1e2 @ 0101d1e2

void FUN_0101d1e2(void)

{
  byte bVar1;
  
  bVar1 = DAT_000f6000;
  DAT_000f6000 = DAT_000f6000 | 0xc0;
  thunk_EXT_FUN_0000425c(2);
  thunk_EXT_FUN_00004238(500);
  DAT_000f6000 = bVar1 & 0x3f;
  return;
}


// ===== FUN_0101d21c @ 0101d21c

void FUN_0101d21c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_0101cf22();
  *(undefined1 *)(param_1 + 0x3a) = 1;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 1); uVar2 = uVar2 + 1) {
    iVar1 = uVar2 * 0x24 + param_1;
    *(undefined1 *)(iVar1 + 0x45) = 1;
    *(char *)(iVar1 + 0x44) = (char)uVar2;
    *(char *)(iVar1 + 0x4a) = (char)uVar2;
    *(undefined1 *)(iVar1 + 0x47) = 0;
    *(undefined1 *)(iVar1 + 0x4b) = 0x40;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x54) = 0;
  }
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 1); uVar2 = uVar2 + 1) {
    iVar1 = uVar2 * 0x24 + param_1;
    *(undefined1 *)(iVar1 + 0xd5) = 0;
    *(char *)(iVar1 + 0xd4) = (char)uVar2;
    *(char *)(iVar1 + 0xda) = (char)uVar2;
    *(undefined1 *)(iVar1 + 0xd7) = 0;
    *(undefined1 *)(iVar1 + 0xdb) = 0x40;
    *(undefined4 *)(iVar1 + 0xdc) = 0;
    *(undefined4 *)(iVar1 + 0xe4) = 0;
  }
  FUN_0101cf92(param_1);
  FUN_0101cf96(param_1,0);
  return;
}


// ===== FUN_0101d31e @ 0101d31e

undefined4 FUN_0101d31e(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  param_2 = param_2 & 0x7f;
  param_1 = param_2 * 0x24 + param_1;
  *(undefined1 *)(param_1 + 0x45) = 1;
  *(char *)(param_1 + 0x44) = (char)param_2;
  *(undefined4 *)(param_1 + 0x4c) = param_3;
  *(undefined4 *)(param_1 + 0x54) = param_4;
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (param_2 == 0) {
    FUN_0101d124();
  }
  else {
    FUN_0101d034();
  }
  return 0;
}


// ===== FUN_0101d384 @ 0101d384

undefined4 FUN_0101d384(int param_1,uint param_2)

{
  int iVar1;
  int extraout_r1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  uVar4 = 0;
  do {
    if (param_2 == 0) {
      return 1;
    }
    iVar3 = uVar4 * 0x24 + param_1;
    puVar5 = (undefined1 *)(iVar3 + 0x44);
    *(undefined1 *)(iVar3 + 0x45) = 1;
    *puVar5 = (char)uVar4;
    if ((param_2 & 1) != 0) {
      if (*(int *)(iVar3 + 0x5c) == 0) {
        iVar1 = *(int *)(uVar4 * 0x24 + param_1 + 0x54);
        if ((iVar1 != 0) && (FUN_0101f134(iVar1,*(undefined1 *)(iVar3 + 0x4b)), extraout_r1 == 0)) {
          FUN_0101d114(param_1,puVar5);
          *(undefined4 *)(iVar3 + 0x54) = 0;
        }
        return 0;
      }
      iVar1 = *(int *)(iVar3 + 0x58);
      uVar2 = *(int *)(iVar3 + 0x54) - iVar1;
      if (uVar2 < *(byte *)(iVar3 + 0x4b)) {
        FUN_0101cee0(param_1,*(int *)(iVar3 + 0x4c) + iVar1,uVar4 & 0xff,uVar2 & 0xff);
        FUN_0101cff6(param_1,puVar5);
        *(undefined4 *)(iVar3 + 0x5c) = 0;
        *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar3 + 0x54);
        (**(code **)(*DAT_0101d6e0 + 4))(param_1,uVar4 & 0xff);
        *(undefined1 *)(param_1 + 0x17c) = 0;
      }
      else {
        FUN_0101cee0(param_1,*(int *)(iVar3 + 0x4c) + iVar1,uVar4 & 0xff);
        FUN_0101cff6(param_1,puVar5);
        iVar1 = *(int *)(iVar3 + 0x58) + (uint)*(byte *)(iVar3 + 0x4b);
        *(int *)(iVar3 + 0x58) = iVar1;
        *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x54) - iVar1;
        *(undefined1 *)(param_1 + 0x17c) = 1;
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
    param_2 = param_2 >> 1;
  } while( true );
}


// ===== FUN_0101d456 @ 0101d456

uint FUN_0101d456(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 local_58;
  undefined4 local_54;
  uint local_18;
  
  uVar10 = 0;
  FUN_0101f1de(&local_58,0x40);
  iVar4 = FUN_0101cff2(param_1);
  iVar7 = DAT_0101d6e4;
  if (iVar4 == 0) {
    return 0;
  }
  bVar1 = *(byte *)(DAT_0101d6e4 + 6);
  local_18 = (uint)bVar1;
  *(byte *)(DAT_0101d6e4 + 6) = bVar1;
  bVar2 = *(byte *)(iVar7 + 7);
  *DAT_0101d6e8 = bVar2;
  if ((bVar1 == 0) && (bVar2 == 0)) {
    return 0;
  }
  if ((int)(local_18 << 0x1a) < 0) {
    if ((int)((uint)*DAT_0101d6ec << 0x1e) < 0) {
      bVar8 = *DAT_0101d6ec | 4;
    }
    else {
      bVar8 = *DAT_0101d6ec & 0xfb;
    }
    *DAT_0101d6ec = bVar8;
  }
  if ((char)bVar1 < '\0') {
    uVar10 = (**(code **)(*DAT_0101d6e0 + 0x10))(param_1);
    pbVar5 = DAT_0101d6ec;
    *DAT_0101d6ec = *DAT_0101d6ec | 1;
    *pbVar5 = *pbVar5 & 0xfb;
    *pbVar5 = *pbVar5 & 0xfd;
    *pbVar5 = *pbVar5 | 0x10;
    *pbVar5 = *pbVar5 | 0x40;
    pbVar5[1] = pbVar5[1] | 1;
    *(undefined1 *)(DAT_0101d6f0 + 8) = 1;
    FUN_0101f1de(DAT_0101d6f4,0x2a0);
    FUN_01010730(7);
    if (*(char *)(DAT_0101d6f8 + 0x10) != '\0') {
      pbVar5 = (byte *)(DAT_0101d6f8 + -0x20);
      pbVar5[(uint)*pbVar5 * 2 + 10] = pbVar5[(uint)*pbVar5 * 2 + 10] & 0xf9;
    }
  }
  pbVar5 = DAT_0101d6e8;
  if ((local_18 & 1) == 0) goto LAB_0101d574;
  pbVar9 = DAT_0101d6e8 + -2;
  if (*pbVar9 != 0) {
    *(byte *)(*(int *)(param_1 + 0xc) + 4) = *(byte *)(*(int *)(param_1 + 0xc) + 4) | 0x80;
    *pbVar9 = 0;
  }
  pbVar9 = DAT_0101d6e8;
  iVar7 = DAT_0101d6e4;
  cVar3 = **(char **)(param_1 + 0x24);
  if (cVar3 != '\b') {
    if (cVar3 == '\t') {
      pbVar5[-1] = 1;
    }
    else if ((cVar3 == '\x01') || (cVar3 == '@')) {
      if (DAT_0101d6e8[2] == 1) {
        if (DAT_0101d6e8[3] == 2) {
          DAT_0101d6e8[2] = 0;
          for (iVar7 = 0; iVar7 < (int)(uint)pbVar9[5]; iVar7 = iVar7 + 1) {
            pbVar5[1] = DAT_000f6018;
          }
          FUN_0101d114(param_1,0);
          *DAT_0101d6fc = *DAT_0101d6fc | 1;
          goto LAB_0101d574;
        }
        if (DAT_0101d6e8[3] != 3) goto LAB_0101d574;
        DAT_0101d6e8[2] = 0;
        for (iVar7 = 0; iVar7 < (int)(uint)pbVar9[5]; iVar7 = iVar7 + 1) {
          *(byte *)(DAT_0101d700 + iVar7) = DAT_000f6018;
        }
      }
      else {
        if (cVar3 != '@') goto LAB_0101d574;
        *(undefined1 *)(DAT_0101d6e4 + 6) = 0x40;
        for (; iVar7 < DAT_0101d704; iVar7 = iVar7 + 1) {
          if ((int)((uint)*(byte *)(DAT_0101d6e4 + 6) << 0x19) < 0) {
            *(undefined1 *)(DAT_0101d6e4 + 6) = 1;
            FUN_0101cf06(param_1,&local_58,0,0x40);
            *(undefined4 *)(param_1 + 0x168) = local_54;
            *(undefined4 *)(param_1 + 0x164) = local_58;
            break;
          }
        }
        (**(code **)(*DAT_0101d6e0 + 8))(param_1);
        iVar7 = DAT_0101d6e4;
        iVar4 = 0x40;
        *(undefined1 *)(DAT_0101d6e4 + 6) = 0x40;
        pbVar5 = DAT_0101d6e8;
        while ((iVar4 < DAT_0101d704 && (-1 < (int)((uint)*(byte *)(iVar7 + 6) << 0x19)))) {
          iVar4 = iVar4 + 1;
        }
        DAT_0101d6e8[2] = 0;
        pbVar5[5] = **(byte **)(param_1 + 0x24);
        *(undefined1 *)(iVar7 + 6) = 1;
        for (iVar7 = 0; iVar7 < (int)(uint)pbVar5[5]; iVar7 = iVar7 + 1) {
          *(byte *)(DAT_0101d700 + iVar7) = DAT_000f6018;
        }
      }
      FUN_0101d114(param_1,0);
      FUN_0101a85c();
      goto LAB_0101d574;
    }
  }
  FUN_0101cf06(param_1,param_1 + 0x164,0,8);
  (**(code **)(*DAT_0101d6e0 + 8))(param_1);
LAB_0101d574:
  if ((bVar2 & 1) != 0) {
    thunk_EXT_FUN_00004238(10);
    *(undefined1 *)(DAT_0101d6e4 + 7) = 1;
    uVar6 = FUN_0101d384(param_1,bVar2 & 1);
    uVar10 = uVar10 | uVar6;
  }
  pbVar5 = DAT_0101d6e8;
  if ((bVar2 & 0xf) >> 1 != 0) {
    if ((int)((uint)*DAT_0101d6e8 << 0x1e) < 0) {
      thunk_EXT_FUN_00004238(10);
      *(undefined1 *)(DAT_0101d6e4 + 7) = 2;
      *DAT_0101d6ec = *DAT_0101d6ec | 0x10;
    }
    if ((int)((uint)*pbVar5 << 0x1d) < 0) {
      thunk_EXT_FUN_00004238(10);
      *(undefined1 *)(DAT_0101d6e4 + 7) = 4;
      *DAT_0101d6ec = *DAT_0101d6ec | 0x40;
    }
    if ((int)((uint)*pbVar5 << 0x1c) < 0) {
      thunk_EXT_FUN_00004238(10);
      *(undefined1 *)(DAT_0101d6e4 + 7) = 8;
      DAT_0101d6ec[1] = DAT_0101d6ec[1] | 1;
    }
  }
  return uVar10;
}


// ===== FUN_0101d7ee @ 0101d7ee

void FUN_0101d7ee(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  *(undefined4 *)(param_1 + 0x170) = param_5;
  *(undefined4 *)(param_1 + 0x16c) = param_4;
  *(undefined4 *)(param_1 + 0x174) = param_3;
  FUN_0101d21c();
  return;
}


// ===== FUN_0101e178 @ 0101e178

undefined4 FUN_0101e178(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (param_1 & 3) << 3;
  uVar3 = 0xff << iVar4;
  uVar2 = ((param_2 & 3) << 6) << iVar4;
  if ((int)param_1 < 0) {
    iVar4 = ((param_1 & 0xf) - 8 & 0xfffffffc) + DAT_0101e1f8;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & ~uVar3 | uVar2;
  }
  else {
    puVar1 = (uint *)((param_1 & 0xfffffffc) + DAT_0101e1fc);
    *puVar1 = *puVar1 & ~uVar3 | uVar2;
  }
  return 1;
}


// ===== FUN_0101e1c4 @ 0101e1c4

void FUN_0101e1c4(uint param_1)

{
  *DAT_0101e200 = *DAT_0101e200 | 1 << (param_1 & 0xff);
  return;
}


// ===== FUN_0101e1d2 @ 0101e1d2

void FUN_0101e1d2(uint param_1)

{
  *(int *)(DAT_0101e200 + 0x80) = 1 << (param_1 & 0xff);
  return;
}


// ===== FUN_0101e1de @ 0101e1de

void FUN_0101e1de(void)

{
  *(uint *)(DAT_0101e204 + 0x34) = *(uint *)(DAT_0101e204 + 0x34) | 1;
  *(undefined4 *)(DAT_0101e204 + 0x3c) = 0x55;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0101e1ee @ 0101e1ee

void FUN_0101e1ee(void)

{
  return;
}


// ===== FUN_0101e226 @ 0101e226

void FUN_0101e226(void)

{
  return;
}


// ===== FUN_0101e228 @ 0101e228

void FUN_0101e228(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  FUN_0101e226(s__s__0101e25c,param_3,param_3,param_4,param_4);
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    if ((uVar1 & 0xf) == 0) {
      FUN_0101e226(s__08x__0101e264,iVar2);
      iVar2 = iVar2 + 0x10;
    }
    FUN_0101e226(s__02x_0101e26c,*(undefined1 *)(param_1 + uVar1));
  }
  return;
}


// ===== FUN_0101e25a @ 0101e25a

void FUN_0101e25a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0101e318 @ 0101e318

void FUN_0101e318(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0101e708;
  if (*(char *)(DAT_0101e708 + 0x15) == '\0') {
    if ((*(char *)(DAT_0101e708 + 0x2c) == '\0') && (*(char *)(DAT_0101e708 + -0xd) == '\0')) {
      *DAT_0101e70c = *DAT_0101e70c | 2;
      *(char *)(iVar1 + -0x34) = (char)param_1;
      *(char *)((uint)*(byte *)(iVar1 + -0x34) + iVar1 + -0x33) = (char)param_2;
    }
    if ((param_1 == 1) && (param_2 == 2)) {
      *(undefined1 *)(iVar1 + 0x15) = 1;
    }
  }
  return;
}


// ===== FUN_0101e358 @ 0101e358

ulonglong FUN_0101e358(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_0101e1c4(6);
  FUN_0101abd8(0,0x200,0xd);
  FUN_0101abd8(0,0x400,0xc);
  uVar1 = DAT_0101e710;
  FUN_0101b326(1);
  FUN_0101b1e8(1,2);
  FUN_0101b600(1);
  return CONCAT44(uVar1,param_1) & 0xffffffffffffff00;
}


// ===== FUN_0101e39e @ 0101e39e

void FUN_0101e39e(void)

{
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(DAT_0101e70c + -4) = 0;
  iVar1 = DAT_0101e714;
  uVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + uVar2) = 0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 200);
  return;
}


// ===== FUN_0101e3b4 @ 0101e3b4

void FUN_0101e3b4(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar1 = DAT_0101e708;
  if (*(char *)(DAT_0101e708 + 0x19) != '\0') {
    uVar2 = *(int *)(DAT_0101e708 + 0x1c) + 1;
    *(uint *)(DAT_0101e708 + 0x1c) = uVar2;
    if (1999 < uVar2) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      iVar1 = DAT_0101e714;
      puVar4 = (undefined1 *)(DAT_0101e714 + 200);
      *puVar4 = 0x55;
      *(undefined2 *)(iVar1 + 0xca) = 2;
      *(undefined1 *)(iVar1 + 0xcc) = 0x26;
      *(undefined1 *)(iVar1 + 0x11d) = 0;
      for (iVar3 = 1; iVar3 < 5; iVar3 = iVar3 + 1) {
        *(char *)(iVar1 + 0x11d) = *(char *)(iVar1 + 0x11d) + puVar4[iVar3];
      }
      *DAT_0101e70c = *DAT_0101e70c | 1;
    }
  }
  return;
}


// ===== FUN_0101e40a @ 0101e40a

void FUN_0101e40a(void)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  iVar2 = DAT_0101e718;
  if (((*(char *)(DAT_0101e708 + 0x2e) == '\0') && (*(char *)(DAT_0101e718 + 0x14) != '\0')) &&
     (uVar4 = *(int *)(DAT_0101e718 + 0x18) + 1, *(uint *)(DAT_0101e718 + 0x18) = uVar4,
     pbVar1 = DAT_0101e70c, 399 < uVar4)) {
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *pbVar1 = *pbVar1 | 1;
    bVar3 = *(char *)(iVar2 + 0x15) + 1;
    *(byte *)(iVar2 + 0x15) = bVar3;
    if (0x27 < bVar3) {
      *pbVar1 = *pbVar1 & 0xfe;
      *(undefined1 *)(iVar2 + 0x14) = 0;
    }
  }
  return;
}


// ===== FUN_0101e450 @ 0101e450

void FUN_0101e450(void)

{
  int iVar1;
  
  iVar1 = DAT_0101e718;
  *(undefined1 *)(DAT_0101e718 + 0xc) = 0;
  *(undefined1 *)(iVar1 + 0xd) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  return;
}


// ===== FUN_0101e45c @ 0101e45c

void FUN_0101e45c(void)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  iVar2 = DAT_0101e718;
  if (((*(char *)(DAT_0101e708 + 0x2e) == '\0') && (*(char *)(DAT_0101e718 + 0xc) != '\0')) &&
     (uVar4 = *(int *)(DAT_0101e718 + 0x10) + 1, *(uint *)(DAT_0101e718 + 0x10) = uVar4,
     pbVar1 = DAT_0101e70c, 399 < uVar4)) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *pbVar1 = *pbVar1 | 1;
    bVar3 = *(char *)(iVar2 + 0xd) + 1;
    *(byte *)(iVar2 + 0xd) = bVar3;
    if (0x27 < bVar3) {
      *pbVar1 = *pbVar1 & 0xfe;
      FUN_0101e450();
      return;
    }
  }
  return;
}


// ===== FUN_0101e4a0 @ 0101e4a0

void FUN_0101e4a0(void)

{
  int iVar1;
  
  iVar1 = DAT_0101e718;
  *(undefined1 *)(DAT_0101e718 + 0x14) = 1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}


// ===== FUN_0101e4ac @ 0101e4ac

void FUN_0101e4ac(void)

{
  int iVar1;
  
  iVar1 = DAT_0101e718;
  *(undefined1 *)(DAT_0101e718 + 0x14) = 0;
  *(undefined1 *)(iVar1 + 0x15) = 0;
  return;
}


// ===== FUN_0101e4b6 @ 0101e4b6

void FUN_0101e4b6(char *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0101e71c;
  if (*param_1 == '\0') {
    *DAT_0101e71c = 0xb1;
    puVar1[1] = 0x55;
    *(undefined1 *)(DAT_0101e708 + 0x2d) = 1;
    return;
  }
  *(undefined1 *)(DAT_0101e718 + 6) = 1;
  *puVar1 = 0xb1;
  puVar1[1] = 0xaa;
  return;
}


// ===== FUN_0101e4dc @ 0101e4dc

void FUN_0101e4dc(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e4ea @ 0101e4ea

void FUN_0101e4ea(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e4f8 @ 0101e4f8

void FUN_0101e4f8(char *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0101e71c;
  if (*param_1 == '\0') {
    *DAT_0101e71c = 0xb0;
    puVar1[1] = 1;
  }
  else {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
    *puVar1 = 0xb0;
    puVar1[1] = 0;
  }
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  return;
}


// ===== FUN_0101e524 @ 0101e524

void FUN_0101e524(char *param_1)

{
  if (*param_1 == '\0') {
    *(undefined1 *)(DAT_0101e708 + 0x2c) = 1;
    return;
  }
  *(undefined1 *)(DAT_0101e718 + 6) = 1;
  return;
}


// ===== FUN_0101e53a @ 0101e53a

void FUN_0101e53a(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e548 @ 0101e548

void FUN_0101e548(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e556 @ 0101e556

void FUN_0101e556(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e564 @ 0101e564

void FUN_0101e564(char *param_1)

{
  if (*param_1 != '\0') {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e572 @ 0101e572

void FUN_0101e572(char *param_1)

{
  if (*param_1 == '\0') {
    if (*(char *)(DAT_0101e708 + 0x15) != '\0') {
      *(undefined1 *)(DAT_0101e708 + 0x15) = 0;
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_0101e718 + 6) = 1;
  }
  return;
}


// ===== FUN_0101e58e @ 0101e58e

void FUN_0101e58e(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  
  puVar4 = DAT_0101e720;
  iVar3 = DAT_0101e714;
  bVar1 = *(byte *)(DAT_0101e714 + 2);
  cVar2 = *(char *)(DAT_0101e714 + 3);
  if (bVar1 == 0xa6) {
    if (cVar2 == '\0') {
      *(undefined1 *)(DAT_0101e708 + 0x19) = 0;
      FUN_0101233e(0x2c,0);
      return;
    }
  }
  else {
    if (bVar1 < 0xa7) {
      if (bVar1 == 0xa1) {
        FUN_0101e556(DAT_0101e714 + 3);
        return;
      }
      if (bVar1 < 0xa2) {
        if (bVar1 == 0x81) {
          FUN_0101e572(DAT_0101e714 + 3);
          return;
        }
        if (bVar1 == 0x82) {
          FUN_0101e548(DAT_0101e714 + 3);
          return;
        }
        if (bVar1 == 0xa0) {
          FUN_0101e564(DAT_0101e714 + 3);
        }
        return;
      }
      if (bVar1 == 0xa2) {
        FUN_0101e53a(DAT_0101e714 + 3);
        return;
      }
      if (bVar1 == 0xa3) {
        if (cVar2 == '\0') {
          *DAT_0101e720 = 0xa5;
          puVar4[1] = 1;
        }
        else {
          *(undefined1 *)(DAT_0101e718 + 6) = 1;
          *puVar4 = 0xa5;
          puVar4[1] = 0;
        }
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
        puVar4[8] = 0;
        puVar4[9] = 0;
        puVar4[10] = 0;
        puVar4[0xb] = 0;
        if (*(char *)(DAT_0101e724 + 0xc) != '\x06') {
          *(byte *)(DAT_0101e728 + 1) = *(byte *)(DAT_0101e728 + 1) | 0x80;
        }
        iVar3 = DAT_0101e708;
        *(undefined4 *)(DAT_0101e708 + -8) = 0;
        *(undefined1 *)(iVar3 + -0xd) = 1;
        *(undefined1 *)(iVar3 + -0xc) = 1;
        FUN_0101b686(1,0);
        *DAT_0101e72c = *DAT_0101e72c | 9;
        return;
      }
      if (bVar1 != 0xa4) {
        return;
      }
    }
    else {
      if (bVar1 == 0xbc) {
        FUN_0101e4dc(DAT_0101e714 + 3);
        return;
      }
      if (0xbc < bVar1) {
        if (bVar1 == 0xbd) {
          FUN_0101e4ea(DAT_0101e714 + 3);
          return;
        }
        if (bVar1 == 0xbe) {
          FUN_0101e4f8(DAT_0101e714 + 3);
          return;
        }
        if (bVar1 == 0xbf) {
          FUN_0101e524(DAT_0101e714 + 3);
          return;
        }
        return;
      }
      if (bVar1 == 0xa7) {
        if (cVar2 == '\0') {
          *DAT_0101e720 = 0xad;
          puVar4[1] = *(undefined1 *)(iVar3 + 4);
          puVar4[2] = *(undefined1 *)(iVar3 + 5);
        }
        else {
          *(undefined1 *)(DAT_0101e718 + 6) = 1;
          *puVar4 = 0xad;
          puVar4[1] = 0;
          puVar4[2] = 0;
        }
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
        return;
      }
      if (bVar1 != 0xb0) {
        if (bVar1 == 0xbb) {
          FUN_0101e4b6(DAT_0101e714 + 3);
          return;
        }
        return;
      }
    }
    if (cVar2 == '\0') {
      return;
    }
  }
  *(undefined1 *)(DAT_0101e718 + 6) = 1;
  return;
}


// ===== FUN_0101e6ce @ 0101e6ce

void FUN_0101e6ce(void)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  
  pcVar2 = DAT_0101e718;
  cVar4 = '\0';
  if (*DAT_0101e718 == '\0') {
    return;
  }
  cVar1 = DAT_0101e718[1];
  DAT_0101e718[1] = cVar1 + 1U;
  if ((byte)(cVar1 + 1U) < 4) {
    return;
  }
  pcVar2[1] = '\0';
  *pcVar2 = '\0';
  if (pcVar2[0xc] == '\0') goto LAB_0101e764;
  iVar5 = *(int *)(DAT_0101e70c + -4);
  if ((uint)*(byte *)(DAT_0101e714 + 1) == iVar5 - 2U) {
    for (uVar3 = 1; uVar3 < iVar5 - 1U; uVar3 = uVar3 + 1) {
      cVar4 = *(char *)(DAT_0101e714 + uVar3) + cVar4;
    }
    if (*(char *)(DAT_0101e714 + iVar5 + -1) != cVar4) goto LAB_0101e74c;
    pcVar2[2] = '\x01';
LAB_0101e752:
    pcVar2[2] = '\0';
    pcVar2[6] = '\0';
    FUN_0101e58e();
    if (pcVar2[6] == '\0') {
      FUN_0101e4ac();
      goto LAB_0101e764;
    }
  }
  else {
LAB_0101e74c:
    if (pcVar2[2] != '\0') goto LAB_0101e752;
  }
  FUN_0101e4a0();
LAB_0101e764:
  FUN_0101e39e();
  FUN_0101e450();
  return;
}


// ===== FUN_0101e774 @ 0101e774

void FUN_0101e774(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  puVar4 = DAT_0101eb74;
  pbVar1 = DAT_0101eb70;
  if ((*DAT_0101eb70 & 1) != 0) {
    FUN_0101b5b4(1,*DAT_0101eb74,param_3,param_4,param_4);
    FUN_0101b5b4(1,puVar4[2]);
    FUN_0101b5b4(1,*(ushort *)(puVar4 + 2) >> 8);
    if (puVar4[4] == '!') {
      FUN_0101c420();
      FUN_0101b5b4(1,puVar4[4]);
      FUN_0101b5b4(1,puVar4[5]);
      FUN_0101b5b4(1,puVar4[6]);
      iVar3 = DAT_0101eb78;
      iVar5 = 0;
      puVar4 = (undefined1 *)((uint)*(byte *)(DAT_0101eb78 + 0x10) * 0x1000 + DAT_0101eb78 + 0x2f);
      do {
        FUN_0101b5b4(1,*puVar4);
        puVar4 = puVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x1000);
      bVar2 = *(char *)(iVar3 + 0x10) + 1;
      *(byte *)(iVar3 + 0x10) = bVar2;
      if (9 < bVar2) {
        *(undefined1 *)(iVar3 + 0x10) = 0;
      }
    }
    else {
      for (iVar3 = 0; iVar3 < (int)(*(ushort *)(puVar4 + 2) - 1); iVar3 = iVar3 + 1) {
        FUN_0101b5b4(1,puVar4[iVar3 + 4]);
      }
    }
    FUN_0101b5b4(1,DAT_0101eb74[0x55]);
    *pbVar1 = *pbVar1 & 0xfe;
    puVar4 = DAT_0101eb74;
    *(undefined4 *)(DAT_0101eb74 + 0x68) = 0;
    puVar4[100] = 1;
  }
  return;
}


// ===== FUN_0101e82c @ 0101e82c

void FUN_0101e82c(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 4;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 7; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e86a @ 0101e86a

void FUN_0101e86a(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 5;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[7] = *(undefined1 *)((uint)*(byte *)(DAT_0101eb7c + 0x1a) + DAT_0101eb7c + 0x40);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e8b2 @ 0101e8b2

void FUN_0101e8b2(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 5;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[7] = *(undefined1 *)((uint)*(byte *)(DAT_0101eb7c + 0x1a) + DAT_0101eb7c + 0x60);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e8fa @ 0101e8fa

void FUN_0101e8fa(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 5;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[7] = *(undefined1 *)(DAT_0101eb7c + 0x1a);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e93e @ 0101e93e

void FUN_0101e93e(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 8;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 0xb; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e97c @ 0101e97c

void FUN_0101e97c(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 5;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e9ba @ 0101e9ba

void FUN_0101e9ba(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 5;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101e9f8 @ 0101e9f8

void FUN_0101e9f8(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0101eb74;
  uVar1 = *(ushort *)(DAT_0101eb74 + 2);
  for (iVar3 = 1; iVar3 < (int)(uVar1 + 3); iVar3 = iVar3 + 1) {
    *(char *)(iVar2 + 0x55) = *(char *)(iVar2 + 0x55) + *(char *)(iVar2 + iVar3);
  }
  return;
}


// ===== FUN_0101ea18 @ 0101ea18

void FUN_0101ea18(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0101eb74;
  uVar1 = *(ushort *)(DAT_0101eb74 + 2);
  for (iVar3 = 1; iVar3 < (int)(uVar1 + 3); iVar3 = iVar3 + 1) {
    *(char *)(iVar2 + 0x55) = *(char *)(iVar2 + 0x55) + *(char *)(iVar2 + iVar3);
  }
  return;
}


// ===== FUN_0101ea38 @ 0101ea38

void FUN_0101ea38(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0101eb74;
  uVar1 = *(ushort *)(DAT_0101eb74 + 2);
  for (iVar3 = 1; iVar3 < (int)(uVar1 + 3); iVar3 = iVar3 + 1) {
    *(char *)(iVar2 + 0x55) = *(char *)(iVar2 + 0x55) + *(char *)(iVar2 + iVar3);
  }
  return;
}


// ===== FUN_0101ea58 @ 0101ea58

void FUN_0101ea58(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 0xb;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[7] = (char)*(undefined2 *)(iVar2 + -0x16);
  puVar1[8] = (char)((ushort)*(undefined2 *)(iVar2 + -0x16) >> 8);
  iVar2 = DAT_0101eb78;
  puVar1[9] = *(undefined1 *)(DAT_0101eb78 + -0x14);
  puVar1[10] = *(undefined1 *)(iVar2 + -0x13);
  puVar1[0xb] = *(undefined1 *)(iVar2 + -0x12);
  puVar1[0xc] = *(undefined1 *)(iVar2 + -0x11);
  puVar1[0xd] = *(undefined1 *)(iVar2 + -0x10);
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 0xe; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101eaba @ 0101eaba

void FUN_0101eaba(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar1 + 2) = 5;
  puVar1[4] = 1;
  iVar2 = DAT_0101eb78;
  puVar1[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar2 + -0x34) + iVar2 + -0x33);
  puVar1[7] = 99;
  puVar1[0x55] = 0;
  for (iVar2 = 1; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar2];
  }
  return;
}


// ===== FUN_0101eafc @ 0101eafc

void FUN_0101eafc(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = DAT_0101eb74;
  *DAT_0101eb74 = 0x55;
  *(undefined2 *)(puVar2 + 2) = 0xf;
  puVar2[4] = 1;
  iVar5 = DAT_0101eb78;
  puVar2[5] = *(undefined1 *)(DAT_0101eb78 + -0x34);
  iVar4 = DAT_0101eb80;
  puVar2[6] = *(undefined1 *)((uint)*(byte *)(iVar5 + -0x34) + iVar5 + -0x33);
  bVar1 = *(byte *)(iVar4 + 0xc);
  puVar2[7] = bVar1;
  if (4 < bVar1) {
    puVar2[7] = bVar1 - 2;
  }
  puVar2[8] = (char)((DAT_0101eb7c[(uint)*DAT_0101eb7c * 2 + 10] & 7) >> 1);
  puVar2[9] = *(undefined1 *)(DAT_0101eb84 + 0xc);
  puVar2[10] = *(undefined1 *)(iVar4 + 0x16);
  puVar2[0xb] = *(undefined1 *)(DAT_0101eb88 + 2);
  puVar2[0xc] = *(undefined1 *)(DAT_0101eb78 + -0xf);
  iVar5 = DAT_0101eb78;
  puVar2[0xd] = *(undefined1 *)(DAT_0101eb78 + 0x17);
  puVar2[0xe] = *(undefined1 *)(iVar5 + 0x16);
  puVar2[0xf] = *(undefined1 *)(iVar5 + 0x13);
  puVar2[0x10] = *(undefined1 *)(iVar5 + 0x14);
  puVar2[0x11] = *(undefined1 *)(iVar5 + 0x18);
  puVar3 = DAT_0101eb74;
  DAT_0101eb74[0x55] = 0;
  for (iVar5 = 1; iVar5 < 0x12; iVar5 = iVar5 + 1) {
    puVar3[0x55] = puVar3[0x55] + puVar2[iVar5];
  }
  return;
}


// ===== FUN_0101eba4 @ 0101eba4

void FUN_0101eba4(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = DAT_0101ef8c;
  *DAT_0101ef8c = 0x55;
  *(undefined2 *)(puVar1 + 2) = 9;
  puVar1[4] = 1;
  iVar3 = DAT_0101ef90;
  puVar1[5] = *(undefined1 *)(DAT_0101ef90 + 0xc);
  iVar2 = DAT_0101ef94;
  puVar1[6] = *(undefined1 *)((uint)*(byte *)(iVar3 + 0xc) + iVar3 + 0xd);
  puVar1[7] = *(undefined1 *)(iVar2 + 0xc);
  puVar1[8] = (char)((DAT_0101ef98[(uint)*DAT_0101ef98 * 2 + 10] & 7) >> 1);
  puVar1[9] = *(undefined1 *)(DAT_0101ef9c + 0xc);
  puVar1[10] = *(undefined1 *)(iVar2 + 0x16);
  puVar1[0xb] = *(undefined1 *)(DAT_0101efa0 + 2);
  puVar1[0x55] = 0;
  for (iVar3 = 1; iVar3 < 0xc; iVar3 = iVar3 + 1) {
    puVar1[0x55] = puVar1[0x55] + puVar1[iVar3];
  }
  return;
}


// ===== FUN_0101ec06 @ 0101ec06

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x0101ec3e) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Removing unreachable block (ram,0x0101ec84) */
/* WARNING: Removing unreachable block (ram,0x0101ec3e) */
/* WARNING: Removing unreachable block (ram,0x0101ec84) */

void FUN_0101ec06(void)

{
  ushort uVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte bVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *unaff_r6;
  byte *unaff_r7;
  byte *pbVar15;
  undefined4 uVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr9;
  undefined4 in_cr11;
  undefined4 in_cr12;
  undefined4 in_cr13;
  undefined4 in_cr14;
  undefined4 in_cr15;
  undefined8 in_d5;
  undefined8 in_d7;
  undefined8 unaff_d9;
  undefined8 unaff_d11;
  undefined8 uVar20;
  undefined8 in_d17;
  undefined8 in_d20;
  undefined8 in_d24;
  undefined1 auStack_94 [128];
  
  pbVar14 = DAT_0101efa8;
  if ((*(char *)(DAT_0101ef9c + 0x16) != '\0') &&
     ((int)((uint)*(ushort *)(DAT_0101efa4 + 0x1c) << 0x19) < 0)) {
    return;
  }
  if ((*DAT_0101efa8 & 1) != 0) {
    return;
  }
  if (DAT_0101ef8c[100] != 0) {
    return;
  }
  pbVar13 = (byte *)0x1;
  bVar12 = 1;
  if (-1 < (int)((uint)*DAT_0101efa8 * 0x40000000)) goto switchD_0101ec3e_caseD_51;
  bVar3 = DAT_0101ef90[0xc];
  pbVar8 = (byte *)(uint)bVar3;
  bVar19 = SCARRY4((int)DAT_0101ef90,0xd);
  pbVar4 = DAT_0101ef90 + 0xd;
  bVar18 = pbVar8 == (byte *)0x0;
  bVar17 = false;
  uVar16 = 0x101ec43;
  pbVar2 = pbVar8;
  if ((byte *)(uint)bRam0101ec42 <= pbVar8) {
    pbVar2 = (byte *)(uint)bRam0101ec42;
  }
  pbVar10 = (byte *)((uint)pbVar2[0x101ec43] * 2);
  pbVar15 = pbVar10 + 0x101ec43;
  pbVar6 = DAT_0101ef90;
  pbVar11 = pbVar10;
  switch(pbVar2[0x101ec43]) {
  case 0:
    pbVar14 = (byte *)((int)pbVar4 * 0x10000);
  case 1:
switchD_0101ec3e_caseD_2:
    pbVar4 = pbRam0101ed20;
switchD_0101ec3e_caseD_3:
    pbVar8 = (byte *)((int)DAT_0101ef90 << 1);
switchD_0101ec3e_caseD_4:
    FUN_0101eba4(pbVar4,DAT_0101ef90,pbVar8);
switchD_0101ec3e_caseD_6:
    break;
  case 2:
    goto switchD_0101ec3e_caseD_2;
  case 3:
    goto switchD_0101ec3e_caseD_3;
  case 4:
    goto switchD_0101ec3e_caseD_4;
  case 5:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 6:
    goto switchD_0101ec3e_caseD_6;
  case 7:
    pbVar6 = (byte *)(uint)DAT_0101ef90[0xc];
  case 8:
    pbVar4 = (byte *)(uint)pbVar6[(int)pbVar4];
switchD_0101ec3e_caseD_9:
    bVar18 = pbVar4 == (byte *)0x0;
switchD_0101ec3e_caseD_a:
    if (bVar18) {
switchD_0101ec3e_caseD_12:
      FUN_0101eafc();
switchD_0101ec3e_caseD_14:
    }
    else {
switchD_0101ec3e_caseD_b:
      bVar18 = pbVar4 == (byte *)0x1;
switchD_0101ec3e_caseD_c:
      if (bVar18) goto switchD_0101ec3e_caseD_15;
switchD_0101ec3e_caseD_d:
      bVar18 = pbVar4 == (byte *)0x2;
switchD_0101ec3e_caseD_e:
      if (bVar18) goto switchD_0101ec3e_caseD_18;
switchD_0101ec3e_caseD_f:
      bVar18 = pbVar4 == (byte *)0x3;
switchD_0101ec3e_caseD_10:
      if (bVar18) {
switchD_0101ec3e_caseD_11:
        goto switchD_0101ec3e_caseD_1b;
      }
    }
    break;
  case 9:
    goto switchD_0101ec3e_caseD_9;
  case 10:
    goto switchD_0101ec3e_caseD_a;
  case 0xb:
    goto switchD_0101ec3e_caseD_b;
  case 0xc:
    goto switchD_0101ec3e_caseD_c;
  case 0xd:
    goto switchD_0101ec3e_caseD_d;
  case 0xe:
    goto switchD_0101ec3e_caseD_e;
  case 0xf:
    goto switchD_0101ec3e_caseD_f;
  case 0x10:
    goto switchD_0101ec3e_caseD_10;
  case 0x11:
    goto switchD_0101ec3e_caseD_11;
  case 0x12:
    goto switchD_0101ec3e_caseD_12;
  case 0x13:
    uVar20 = VectorAdd(unaff_d9,in_d20,1,1);
    SatQ(uVar20,1,1);
  case 0x15:
switchD_0101ec3e_caseD_15:
    FUN_0101eaba();
switchD_0101ec3e_caseD_17:
    break;
  case 0x14:
    goto switchD_0101ec3e_caseD_14;
  case 0x16:
    uVar20 = VectorAdd(in_d5,in_d17,4,1);
    SatQ(uVar20,4,1);
  case 0x18:
switchD_0101ec3e_caseD_18:
    FUN_0101ea58();
switchD_0101ec3e_caseD_1a:
    break;
  case 0x17:
    goto switchD_0101ec3e_caseD_17;
  case 0x19:
    coprocessor_function2(0,0xf,1,in_cr14,in_cr1,in_cr14);
  case 0x1b:
switchD_0101ec3e_caseD_1b:
    FUN_0101ea38();
switchD_0101ec3e_caseD_1d:
    break;
  case 0x1a:
    goto switchD_0101ec3e_caseD_1a;
  case 0x1c:
    coprocessor_function2(0,0xd,1,in_cr14,in_cr14,in_cr11);
  case 0x1e:
    pbVar6 = (byte *)(uint)DAT_0101ef90[0xc];
switchD_0101ec3e_caseD_1f:
    pbVar4 = (byte *)(uint)pbVar6[(int)pbVar4];
switchD_0101ec3e_caseD_20:
    bVar17 = (int)pbVar4 < 0;
    bVar18 = pbVar4 == (byte *)0x0;
    pbVar11 = pbVar4;
switchD_0101ec3e_caseD_21:
    uVar16 = 0x101ec89;
    if ((byte *)(uint)bRam0101ec88 <= pbVar11) {
      pbVar11 = (byte *)(uint)bRam0101ec88;
    }
    pbVar10 = (byte *)((uint)pbVar11[0x101ec89] * 2);
    pbVar15 = pbVar10 + 0x101ec89;
    bVar5 = 1;
    switch(pbVar11[0x101ec89]) {
    case 0:
code_r0x0101ec88:
    case 1:
      goto switchD_0101ec3e_caseD_24;
    case 2:
      goto switchD_0101ec3e_caseD_25;
    case 3:
      goto switchD_0101ec3e_caseD_26;
    case 4:
      goto switchD_0101ec3e_caseD_27;
    case 5:
switchD_0101ec3e_caseD_28:
      coprocessor_moveto(0,6,0,uVar16,in_cr2,in_cr15);
    case 7:
switchD_0101ec3e_caseD_2a:
      FUN_0101e9f8();
switchD_0101ec3e_caseD_2c:
      goto switchD_0101ec3e_caseD_4a;
    case 6:
      goto switchD_0101ec3e_caseD_29;
    case 8:
switchD_0101ec3e_caseD_2b:
      coprocessor_moveto(0,5,0,uVar16,in_cr15,in_cr12);
    case 10:
switchD_0101ec3e_caseD_2d:
      FUN_0101e9ba();
switchD_0101ec3e_caseD_2f:
      goto switchD_0101ec3e_caseD_4a;
    case 9:
      goto switchD_0101ec3e_caseD_2c;
    case 0xb:
switchD_0101ec3e_caseD_2e:
      coprocessor_moveto(0,4,0,uVar16,in_cr13,in_cr9);
    case 0xd:
switchD_0101ec3e_caseD_30:
      FUN_0101e97c();
switchD_0101ec3e_caseD_32:
      goto switchD_0101ec3e_caseD_4a;
    case 0xc:
      goto switchD_0101ec3e_caseD_2f;
    case 0xe:
switchD_0101ec3e_caseD_31:
      coprocessor_moveto(0,3,0,uVar16,in_cr11,in_cr6);
    case 0x10:
switchD_0101ec3e_caseD_33:
      FUN_0101e93e();
switchD_0101ec3e_caseD_35:
      goto switchD_0101ec3e_caseD_4a;
    case 0xf:
      goto switchD_0101ec3e_caseD_32;
    case 0x11:
switchD_0101ec3e_caseD_34:
      coprocessor_moveto(0,2,0,uVar16,in_cr9,in_cr3);
    case 0x13:
switchD_0101ec3e_caseD_36:
      pbVar6 = (byte *)(uint)pbVar6[0xc];
switchD_0101ec3e_caseD_37:
      pbVar4 = (byte *)(uint)pbVar6[(int)pbVar4];
switchD_0101ec3e_caseD_38:
      bVar18 = pbVar4 == (byte *)0x0;
switchD_0101ec3e_caseD_39:
      if (bVar18) {
switchD_0101ec3e_caseD_3f:
        FUN_0101e8fa();
switchD_0101ec3e_caseD_41:
      }
      else {
switchD_0101ec3e_caseD_3a:
        bVar18 = pbVar4 == (byte *)0x1;
switchD_0101ec3e_caseD_3b:
        if (bVar18) goto switchD_0101ec3e_caseD_42;
switchD_0101ec3e_caseD_3c:
        bVar18 = pbVar4 == (byte *)0x2;
switchD_0101ec3e_caseD_3d:
        if (bVar18) {
switchD_0101ec3e_caseD_3e:
          goto switchD_0101ec3e_caseD_45;
        }
      }
      goto switchD_0101ec3e_caseD_4a;
    case 0x12:
      goto switchD_0101ec3e_caseD_35;
    case 0x14:
      goto switchD_0101ec3e_caseD_37;
    case 0x15:
      goto switchD_0101ec3e_caseD_38;
    case 0x16:
      goto switchD_0101ec3e_caseD_39;
    case 0x17:
      goto switchD_0101ec3e_caseD_3a;
    case 0x18:
      goto switchD_0101ec3e_caseD_3b;
    case 0x19:
      goto switchD_0101ec3e_caseD_3c;
    case 0x1a:
      goto switchD_0101ec3e_caseD_3d;
    case 0x1b:
      goto switchD_0101ec3e_caseD_3e;
    case 0x1c:
      goto switchD_0101ec3e_caseD_3f;
    case 0x1d:
switchD_0101ec3e_caseD_40:
      coprocessor_function2(0,1,0,in_cr14,in_cr11,in_cr7);
    case 0x1f:
switchD_0101ec3e_caseD_42:
      FUN_0101e8b2();
switchD_0101ec3e_caseD_44:
      goto switchD_0101ec3e_caseD_4a;
    case 0x1e:
      goto switchD_0101ec3e_caseD_41;
    case 0x20:
switchD_0101ec3e_caseD_43:
      pbVar13 = (byte *)0x11;
      coprocessor_loadlong(0,in_cr14,0x11);
    case 0x22:
switchD_0101ec3e_caseD_45:
      FUN_0101e86a();
switchD_0101ec3e_caseD_47:
      goto switchD_0101ec3e_caseD_4a;
    case 0x21:
      goto switchD_0101ec3e_caseD_44;
    case 0x23:
switchD_0101ec3e_caseD_46:
      coprocessor_storelong(0,in_cr14,auStack_94 + 0x84);
    case 0x25:
switchD_0101ec3e_caseD_48:
      FUN_0101e82c();
      goto switchD_0101ec3e_caseD_4a;
    case 0x24:
      goto switchD_0101ec3e_caseD_47;
    case 0x26:
switchD_0101ec3e_caseD_49:
      VectorComplexMultiplyAccumulate(in_d7,unaff_d11,in_d24,0x10e,2);
      break;
    case 0x27:
      goto switchD_0101ec3e_caseD_4a;
    case 0x29:
      goto switchD_0101ec3e_caseD_4c;
    case 0x2a:
      goto switchD_0101ec3e_caseD_4d;
    case 0x2b:
      goto switchD_0101ec3e_caseD_4e;
    case 0x2c:
      goto switchD_0101ec3e_caseD_4f;
    case 0x2d:
      goto switchD_0101ec3e_caseD_50;
    case 0x2e:
      goto switchD_0101ec3e_caseD_51;
    case 0x2f:
      goto switchD_0101ec3e_caseD_52;
    case 0x30:
      goto switchD_0101ec3e_caseD_53;
    case 0x31:
      goto switchD_0101ec3e_caseD_54;
    case 0x32:
      goto switchD_0101ec3e_caseD_55;
    case 0x33:
      goto switchD_0101ec3e_caseD_56;
    case 0x34:
      goto switchD_0101ec3e_caseD_57;
    case 0x35:
      goto switchD_0101ec3e_caseD_58;
    case 0x36:
      goto switchD_0101ec3e_caseD_59;
    case 0x37:
      goto switchD_0101ec3e_caseD_5a;
    case 0x38:
      goto switchD_0101ec3e_caseD_5b;
    case 0x39:
      goto switchD_0101ec3e_caseD_5c;
    case 0x3a:
      goto switchD_0101ec3e_caseD_5d;
    case 0x3b:
      goto switchD_0101ec3e_caseD_5e;
    case 0x3c:
      goto switchD_0101ec3e_caseD_5f;
    case 0x3d:
      goto switchD_0101ec3e_caseD_60;
    case 0x3e:
      goto switchD_0101ec3e_caseD_61;
    case 0x3f:
      goto switchD_0101ec3e_caseD_62;
    case 0x40:
      goto switchD_0101ec3e_caseD_63;
    case 0x41:
      goto switchD_0101ec3e_caseD_64;
    case 0x42:
      goto switchD_0101ec3e_caseD_65;
    case 0x43:
      goto switchD_0101ec3e_caseD_66;
    case 0x44:
LAB_0101ef08:
      return;
    case 0x45:
      goto switchD_0101ec3e_caseD_68;
    case 0x46:
      goto switchD_0101ec3e_caseD_69;
    case 0x47:
      goto switchD_0101ec3e_caseD_6a;
    case 0x48:
      goto switchD_0101ec3e_caseD_6b;
    case 0x49:
      goto switchD_0101ec3e_caseD_6c;
    case 0x4a:
      goto switchD_0101ec3e_caseD_6d;
    case 0x4b:
      goto switchD_0101ec3e_caseD_6e;
    case 0x4c:
      goto code_r0x0101ed20;
    case 0x4d:
      goto switchD_0101ec3e_caseD_70;
    case 0x4e:
      goto switchD_0101ec3e_caseD_71;
    case 0x4f:
      goto switchD_0101ec3e_caseD_72;
    case 0x50:
      goto switchD_0101ec3e_caseD_73;
    case 0x51:
      goto switchD_0101ec3e_caseD_74;
    case 0x52:
      goto switchD_0101ec3e_caseD_75;
    case 0x53:
      goto switchD_0101ec3e_caseD_76;
    case 0x54:
      goto switchD_0101ec3e_caseD_77;
    case 0x55:
      goto switchD_0101ec3e_caseD_78;
    case 0x56:
      goto switchD_0101ec3e_caseD_79;
    case 0x57:
      goto switchD_0101ec3e_caseD_7a;
    case 0x58:
      goto switchD_0101ec3e_caseD_7b;
    case 0x59:
      goto switchD_0101ec3e_caseD_7c;
    case 0x5a:
      goto switchD_0101ec3e_caseD_7d;
    case 0x5b:
      goto switchD_0101ec3e_caseD_7e;
    case 0x5c:
      goto switchD_0101ec3e_caseD_7f;
    case 0x5d:
      goto switchD_0101ec3e_caseD_80;
    case 0x5e:
      goto switchD_0101ec3e_caseD_81;
    case 0x5f:
      goto switchD_0101ec3e_caseD_82;
    case 0x60:
      goto switchD_0101ec3e_caseD_83;
    case 0x61:
      goto switchD_0101ec3e_caseD_84;
    case 0x62:
      goto switchD_0101ec3e_caseD_85;
    case 99:
      goto switchD_0101ec3e_caseD_86;
    case 100:
      goto switchD_0101ec3e_caseD_87;
    case 0x65:
      goto switchD_0101ec3e_caseD_88;
    case 0x66:
      goto switchD_0101ec3e_caseD_89;
    case 0x67:
      goto switchD_0101ec3e_caseD_8a;
    case 0x68:
      goto switchD_0101ec3e_caseD_8b;
    case 0x69:
      goto switchD_0101ec3e_caseD_8c;
    case 0x6a:
      goto switchD_0101ec3e_caseD_8d;
    case 0x6b:
      goto switchD_0101ec3e_caseD_8e;
    case 0x6c:
      goto switchD_0101ec3e_caseD_8f;
    case 0x6d:
      goto switchD_0101ec3e_caseD_90;
    case 0x6e:
      goto switchD_0101ec3e_caseD_91;
    case 0x6f:
      goto switchD_0101ec3e_caseD_92;
    case 0x70:
      goto switchD_0101ec3e_caseD_93;
    case 0x71:
      goto switchD_0101ec3e_caseD_94;
    case 0x72:
      goto switchD_0101ec3e_caseD_95;
    case 0x73:
      goto switchD_0101ec3e_caseD_96;
    case 0x74:
      goto switchD_0101ec3e_caseD_97;
    case 0x75:
      goto switchD_0101ec3e_caseD_98;
    case 0x76:
      goto switchD_0101ec3e_caseD_99;
    case 0x77:
      goto switchD_0101ec3e_caseD_9a;
    case 0x78:
      goto switchD_0101ec3e_caseD_9b;
    case 0x79:
      goto switchD_0101ec3e_caseD_9c;
    case 0x7a:
      goto switchD_0101ec3e_caseD_9d;
    case 0x7b:
      goto switchD_0101ec3e_caseD_9e;
    case 0x7c:
      goto switchD_0101ec3e_caseD_9f;
    case 0x7d:
      goto switchD_0101ec3e_caseD_a0;
    case 0x7e:
      goto switchD_0101ec3e_caseD_a1;
    case 0x7f:
      goto switchD_0101ec3e_caseD_a2;
    case 0x80:
      goto switchD_0101ec3e_caseD_a3;
    case 0x81:
      goto switchD_0101ec3e_caseD_a4;
    case 0x82:
      goto switchD_0101ec3e_caseD_a5;
    case 0x83:
      goto switchD_0101ec3e_caseD_a6;
    case 0x84:
      goto switchD_0101ec3e_caseD_a7;
    case 0x85:
      goto switchD_0101ec3e_caseD_a8;
    case 0x86:
      goto switchD_0101ec3e_caseD_a9;
    case 0x87:
      goto switchD_0101ec3e_caseD_aa;
    case 0x88:
      goto switchD_0101ec3e_caseD_ab;
    case 0x89:
      goto switchD_0101ec3e_caseD_ac;
    case 0x8a:
      goto switchD_0101ec3e_caseD_ad;
    case 0x8b:
      goto switchD_0101ec3e_caseD_ae;
    case 0x8c:
      goto switchD_0101ec3e_caseD_af;
    case 0x8d:
      goto switchD_0101ec3e_caseD_b0;
    case 0x8e:
      goto switchD_0101ec3e_caseD_b1;
    case 0x8f:
      goto switchD_0101ec3e_caseD_b2;
    case 0x90:
      goto switchD_0101ec3e_caseD_b3;
    case 0x91:
      goto switchD_0101ec3e_caseD_b4;
    case 0x92:
      goto switchD_0101ec3e_caseD_b5;
    case 0x93:
      goto switchD_0101ec3e_caseD_b6;
    case 0x94:
      goto switchD_0101ec3e_caseD_b7;
    case 0x95:
      goto switchD_0101ec3e_caseD_b8;
    case 0x96:
      goto switchD_0101ec3e_caseD_b9;
    case 0x97:
      goto switchD_0101ec3e_caseD_ba;
    case 0x98:
      goto switchD_0101ec3e_caseD_bb;
    case 0x99:
      goto switchD_0101ec3e_caseD_bc;
    case 0x9a:
      goto switchD_0101ec3e_caseD_bd;
    case 0x9b:
      goto switchD_0101ec3e_caseD_be;
    case 0x9c:
      goto switchD_0101ec3e_caseD_bf;
    case 0x9d:
      goto switchD_0101ec3e_caseD_c0;
    case 0x9e:
      goto switchD_0101ec3e_caseD_c1;
    case 0x9f:
      goto switchD_0101ec3e_caseD_c2;
    case 0xa0:
      goto switchD_0101ec3e_caseD_c3;
    case 0xa1:
      goto switchD_0101ec3e_caseD_c4;
    case 0xa2:
      goto switchD_0101ec3e_caseD_c5;
    case 0xa3:
      goto switchD_0101ec3e_caseD_c6;
    case 0xa4:
      goto switchD_0101ec3e_caseD_c7;
    case 0xa5:
      goto switchD_0101ec3e_caseD_c8;
    case 0xa6:
      goto switchD_0101ec3e_caseD_c9;
    case 0xa7:
      goto switchD_0101ec3e_caseD_ca;
    case 0xa8:
      goto switchD_0101ec3e_caseD_cb;
    case 0xa9:
      goto switchD_0101ec3e_caseD_cc;
    case 0xaa:
      goto switchD_0101ec3e_caseD_cd;
    case 0xab:
      goto switchD_0101ec3e_caseD_ce;
    case 0xac:
      goto switchD_0101ec3e_caseD_cf;
    case 0xad:
      goto switchD_0101ec3e_caseD_d0;
    case 0xae:
      goto switchD_0101ec3e_caseD_d1;
    case 0xaf:
      goto switchD_0101ec3e_caseD_d2;
    case 0xb0:
      goto switchD_0101ec3e_caseD_d3;
    case 0xb1:
      goto switchD_0101ec3e_caseD_d4;
    case 0xb2:
      goto switchD_0101ec3e_caseD_d5;
    case 0xb3:
      goto switchD_0101ec3e_caseD_d6;
    case 0xb4:
      goto switchD_0101ec3e_caseD_d7;
    case 0xb5:
      goto switchD_0101ec3e_caseD_d8;
    case 0xb6:
      goto switchD_0101ec3e_caseD_d9;
    case 0xb7:
      goto switchD_0101ec3e_caseD_da;
    case 0xb8:
      goto switchD_0101ec3e_caseD_db;
    case 0xb9:
      goto switchD_0101ec3e_caseD_dc;
    case 0xba:
      goto switchD_0101ec3e_caseD_dd;
    case 0xbb:
      goto switchD_0101ec3e_caseD_de;
    case 0xbc:
      goto switchD_0101ec3e_caseD_df;
    case 0xbd:
      goto switchD_0101ec3e_caseD_e0;
    case 0xbe:
      goto switchD_0101ec3e_caseD_e1;
    case 0xbf:
      goto switchD_0101ec3e_caseD_e2;
    case 0xc0:
      goto switchD_0101ec3e_caseD_e3;
    case 0xc1:
      goto switchD_0101ec3e_caseD_e4;
    case 0xc2:
      goto switchD_0101ec3e_caseD_e5;
    case 0xc3:
      goto switchD_0101ec3e_caseD_e6;
    case 0xc4:
      goto switchD_0101ec3e_caseD_e7;
    case 0xc5:
      goto switchD_0101ec3e_caseD_e8;
    case 0xc6:
      goto switchD_0101ec3e_caseD_e9;
    case 199:
      goto switchD_0101ec3e_caseD_ea;
    case 200:
      goto switchD_0101ec3e_caseD_eb;
    case 0xc9:
      goto switchD_0101ec3e_caseD_ec;
    case 0xca:
      goto switchD_0101ec3e_caseD_ed;
    case 0xcb:
      goto switchD_0101ec3e_caseD_ee;
    case 0xcc:
      goto switchD_0101ec3e_caseD_ef;
    case 0xcd:
      goto switchD_0101ec3e_caseD_f0;
    case 0xce:
      goto switchD_0101ec3e_caseD_f1;
    case 0xcf:
      goto switchD_0101ec3e_caseD_f2;
    case 0xd0:
      goto switchD_0101ec3e_caseD_f3;
    case 0xd1:
      goto switchD_0101ec3e_caseD_f4;
    case 0xd2:
      goto switchD_0101ec3e_caseD_f5;
    case 0xd3:
      goto switchD_0101ec3e_caseD_f6;
    case 0xd4:
      goto switchD_0101ec3e_caseD_f7;
    case 0xd5:
      goto switchD_0101ec3e_caseD_f8;
    case 0xd6:
      goto switchD_0101ec3e_caseD_f9;
    case 0xd7:
      goto switchD_0101ec3e_caseD_fa;
    case 0xd8:
      goto switchD_0101ec3e_caseD_fb;
    case 0xd9:
      goto switchD_0101ec3e_caseD_fc;
    case 0xda:
      goto switchD_0101ec3e_caseD_fd;
    case 0xdb:
      goto switchD_0101ec3e_caseD_fe;
    case 0xdc:
      goto switchD_0101ec3e_caseD_ff;
    case 0xdd:
      goto switchD_0101ec84_caseD_dd;
    case 0xde:
      goto switchD_0101ec84_caseD_de;
    case 0xdf:
      goto switchD_0101ec84_caseD_df;
    case 0xe0:
      goto switchD_0101ec84_caseD_e0;
    case 0xe1:
      goto switchD_0101ec84_caseD_e1;
    case 0xe2:
      goto switchD_0101ec84_caseD_e2;
    case 0xe3:
      goto switchD_0101ec84_caseD_e3;
    case 0xe4:
      goto switchD_0101ec84_caseD_e4;
    case 0xe5:
      goto switchD_0101ec84_caseD_e5;
    case 0xe6:
      goto switchD_0101ec84_caseD_e6;
    case 0xe7:
      goto switchD_0101ec84_caseD_e7;
    case 0xe8:
      goto switchD_0101ec84_caseD_e8;
    case 0xe9:
      goto switchD_0101ec84_caseD_e9;
    case 0xea:
      goto switchD_0101ec84_caseD_ea;
    case 0xeb:
      goto switchD_0101ec84_caseD_eb;
    case 0xec:
      goto switchD_0101ec84_caseD_ec;
    case 0xed:
      goto switchD_0101ec84_caseD_ed;
    case 0xee:
      goto switchD_0101ec84_caseD_ee;
    case 0xef:
      goto switchD_0101ec84_caseD_ef;
    case 0xf0:
      goto switchD_0101ec84_caseD_f0;
    case 0xf1:
      goto switchD_0101ec84_caseD_f1;
    case 0xf2:
      goto switchD_0101ec84_caseD_f2;
    case 0xf3:
      goto switchD_0101ec84_caseD_f3;
    case 0xf4:
      goto switchD_0101ec84_caseD_f4;
    case 0xf5:
      goto switchD_0101ec84_caseD_f5;
    case 0xf6:
      goto switchD_0101ec84_caseD_f6;
    case 0xf7:
      goto switchD_0101ec84_caseD_f7;
    case 0xf8:
      goto switchD_0101ec84_caseD_f8;
    case 0xf9:
      goto switchD_0101ec84_caseD_f9;
    case 0xfa:
      goto switchD_0101ec84_caseD_fa;
    case 0xfb:
      goto switchD_0101ec84_caseD_fb;
    case 0xfc:
      goto switchD_0101ec84_caseD_fc;
    case 0xfd:
      goto switchD_0101ec84_caseD_fd;
    case 0xfe:
      goto switchD_0101ec84_caseD_fe;
    case 0xff:
      goto switchD_0101ec84_caseD_ff;
    }
    goto switchD_0101ec3e_caseD_4b;
  case 0x1d:
    goto switchD_0101ec3e_caseD_1d;
  case 0x1f:
    goto switchD_0101ec3e_caseD_1f;
  case 0x20:
    goto switchD_0101ec3e_caseD_20;
  case 0x21:
    goto switchD_0101ec3e_caseD_21;
  case 0x22:
    pbVar13 = DAT_0101efa8 + (int)pbVar4;
  case 0x24:
switchD_0101ec3e_caseD_24:
switchD_0101ec3e_caseD_25:
    pbVar14 = (byte *)((int)pbVar6 >> 0x20);
switchD_0101ec3e_caseD_26:
switchD_0101ec3e_caseD_27:
    FUN_0101ea18();
switchD_0101ec3e_caseD_29:
    break;
  case 0x23:
    goto code_r0x0101ec88;
  case 0x25:
    goto switchD_0101ec3e_caseD_25;
  case 0x26:
    goto switchD_0101ec3e_caseD_26;
  case 0x27:
    goto switchD_0101ec3e_caseD_27;
  case 0x28:
    goto switchD_0101ec3e_caseD_28;
  case 0x29:
    goto switchD_0101ec3e_caseD_29;
  case 0x2a:
    goto switchD_0101ec3e_caseD_2a;
  case 0x2b:
    goto switchD_0101ec3e_caseD_2b;
  case 0x2c:
    goto switchD_0101ec3e_caseD_2c;
  case 0x2d:
    goto switchD_0101ec3e_caseD_2d;
  case 0x2e:
    goto switchD_0101ec3e_caseD_2e;
  case 0x2f:
    goto switchD_0101ec3e_caseD_2f;
  case 0x30:
    goto switchD_0101ec3e_caseD_30;
  case 0x31:
    goto switchD_0101ec3e_caseD_31;
  case 0x32:
    goto switchD_0101ec3e_caseD_32;
  case 0x33:
    goto switchD_0101ec3e_caseD_33;
  case 0x34:
    goto switchD_0101ec3e_caseD_34;
  case 0x35:
    goto switchD_0101ec3e_caseD_35;
  case 0x36:
    goto switchD_0101ec3e_caseD_36;
  case 0x37:
    goto switchD_0101ec3e_caseD_37;
  case 0x38:
    goto switchD_0101ec3e_caseD_38;
  case 0x39:
    goto switchD_0101ec3e_caseD_39;
  case 0x3a:
    goto switchD_0101ec3e_caseD_3a;
  case 0x3b:
    goto switchD_0101ec3e_caseD_3b;
  case 0x3c:
    goto switchD_0101ec3e_caseD_3c;
  case 0x3d:
    goto switchD_0101ec3e_caseD_3d;
  case 0x3e:
    goto switchD_0101ec3e_caseD_3e;
  case 0x3f:
    goto switchD_0101ec3e_caseD_3f;
  case 0x40:
    goto switchD_0101ec3e_caseD_40;
  case 0x41:
    goto switchD_0101ec3e_caseD_41;
  case 0x42:
    goto switchD_0101ec3e_caseD_42;
  case 0x43:
    goto switchD_0101ec3e_caseD_43;
  case 0x44:
    goto switchD_0101ec3e_caseD_44;
  case 0x45:
    goto switchD_0101ec3e_caseD_45;
  case 0x46:
    goto switchD_0101ec3e_caseD_46;
  case 0x47:
    goto switchD_0101ec3e_caseD_47;
  case 0x48:
    goto switchD_0101ec3e_caseD_48;
  case 0x49:
    goto switchD_0101ec3e_caseD_49;
  case 0x4a:
    break;
  case 0x4b:
    goto switchD_0101ec3e_caseD_4b;
  case 0x4c:
    goto switchD_0101ec3e_caseD_4c;
  case 0x4d:
    goto switchD_0101ec3e_caseD_4d;
  case 0x4e:
    goto switchD_0101ec3e_caseD_4e;
  case 0x4f:
    goto switchD_0101ec3e_caseD_4f;
  case 0x50:
    goto switchD_0101ec3e_caseD_50;
  case 0x51:
    goto switchD_0101ec3e_caseD_51;
  case 0x52:
    goto switchD_0101ec3e_caseD_52;
  case 0x53:
    goto switchD_0101ec3e_caseD_53;
  case 0x54:
    goto switchD_0101ec3e_caseD_54;
  case 0x55:
    goto switchD_0101ec3e_caseD_55;
  case 0x56:
    goto switchD_0101ec3e_caseD_56;
  case 0x57:
    goto switchD_0101ec3e_caseD_57;
  case 0x58:
    goto switchD_0101ec3e_caseD_58;
  case 0x59:
    goto switchD_0101ec3e_caseD_59;
  case 0x5a:
    goto switchD_0101ec3e_caseD_5a;
  case 0x5b:
    goto switchD_0101ec3e_caseD_5b;
  case 0x5c:
    goto switchD_0101ec3e_caseD_5c;
  case 0x5d:
    goto switchD_0101ec3e_caseD_5d;
  case 0x5e:
    goto switchD_0101ec3e_caseD_5e;
  case 0x5f:
    goto switchD_0101ec3e_caseD_5f;
  case 0x60:
    goto switchD_0101ec3e_caseD_60;
  case 0x61:
    goto switchD_0101ec3e_caseD_61;
  case 0x62:
    goto switchD_0101ec3e_caseD_62;
  case 99:
    goto switchD_0101ec3e_caseD_63;
  case 100:
    goto switchD_0101ec3e_caseD_64;
  case 0x65:
    goto switchD_0101ec3e_caseD_65;
  case 0x66:
    goto switchD_0101ec3e_caseD_66;
  case 0x67:
    goto LAB_0101ef08;
  case 0x68:
    goto switchD_0101ec3e_caseD_68;
  case 0x69:
    goto switchD_0101ec3e_caseD_69;
  case 0x6a:
    goto switchD_0101ec3e_caseD_6a;
  case 0x6b:
    goto switchD_0101ec3e_caseD_6b;
  case 0x6c:
    goto switchD_0101ec3e_caseD_6c;
  case 0x6d:
    goto switchD_0101ec3e_caseD_6d;
  case 0x6e:
    goto switchD_0101ec3e_caseD_6e;
  case 0x6f:
    goto code_r0x0101ed20;
  case 0x70:
    goto switchD_0101ec3e_caseD_70;
  case 0x71:
    goto switchD_0101ec3e_caseD_71;
  case 0x72:
    goto switchD_0101ec3e_caseD_72;
  case 0x73:
    goto switchD_0101ec3e_caseD_73;
  case 0x74:
    goto switchD_0101ec3e_caseD_74;
  case 0x75:
    goto switchD_0101ec3e_caseD_75;
  case 0x76:
    goto switchD_0101ec3e_caseD_76;
  case 0x77:
    goto switchD_0101ec3e_caseD_77;
  case 0x78:
    goto switchD_0101ec3e_caseD_78;
  case 0x79:
    goto switchD_0101ec3e_caseD_79;
  case 0x7a:
    goto switchD_0101ec3e_caseD_7a;
  case 0x7b:
    goto switchD_0101ec3e_caseD_7b;
  case 0x7c:
    goto switchD_0101ec3e_caseD_7c;
  case 0x7d:
    goto switchD_0101ec3e_caseD_7d;
  case 0x7e:
    goto switchD_0101ec3e_caseD_7e;
  case 0x7f:
    goto switchD_0101ec3e_caseD_7f;
  case 0x80:
    goto switchD_0101ec3e_caseD_80;
  case 0x81:
    goto switchD_0101ec3e_caseD_81;
  case 0x82:
    goto switchD_0101ec3e_caseD_82;
  case 0x83:
    goto switchD_0101ec3e_caseD_83;
  case 0x84:
    goto switchD_0101ec3e_caseD_84;
  case 0x85:
    goto switchD_0101ec3e_caseD_85;
  case 0x86:
    goto switchD_0101ec3e_caseD_86;
  case 0x87:
    goto switchD_0101ec3e_caseD_87;
  case 0x88:
    goto switchD_0101ec3e_caseD_88;
  case 0x89:
    goto switchD_0101ec3e_caseD_89;
  case 0x8a:
    goto switchD_0101ec3e_caseD_8a;
  case 0x8b:
    goto switchD_0101ec3e_caseD_8b;
  case 0x8c:
    goto switchD_0101ec3e_caseD_8c;
  case 0x8d:
    goto switchD_0101ec3e_caseD_8d;
  case 0x8e:
    goto switchD_0101ec3e_caseD_8e;
  case 0x8f:
    goto switchD_0101ec3e_caseD_8f;
  case 0x90:
    goto switchD_0101ec3e_caseD_90;
  case 0x91:
    goto switchD_0101ec3e_caseD_91;
  case 0x92:
    goto switchD_0101ec3e_caseD_92;
  case 0x93:
    goto switchD_0101ec3e_caseD_93;
  case 0x94:
    goto switchD_0101ec3e_caseD_94;
  case 0x95:
    goto switchD_0101ec3e_caseD_95;
  case 0x96:
    goto switchD_0101ec3e_caseD_96;
  case 0x97:
    goto switchD_0101ec3e_caseD_97;
  case 0x98:
    goto switchD_0101ec3e_caseD_98;
  case 0x99:
    goto switchD_0101ec3e_caseD_99;
  case 0x9a:
    goto switchD_0101ec3e_caseD_9a;
  case 0x9b:
    goto switchD_0101ec3e_caseD_9b;
  case 0x9c:
    goto switchD_0101ec3e_caseD_9c;
  case 0x9d:
    goto switchD_0101ec3e_caseD_9d;
  case 0x9e:
    goto switchD_0101ec3e_caseD_9e;
  case 0x9f:
    goto switchD_0101ec3e_caseD_9f;
  case 0xa0:
    goto switchD_0101ec3e_caseD_a0;
  case 0xa1:
    goto switchD_0101ec3e_caseD_a1;
  case 0xa2:
    goto switchD_0101ec3e_caseD_a2;
  case 0xa3:
    goto switchD_0101ec3e_caseD_a3;
  case 0xa4:
    goto switchD_0101ec3e_caseD_a4;
  case 0xa5:
    goto switchD_0101ec3e_caseD_a5;
  case 0xa6:
    goto switchD_0101ec3e_caseD_a6;
  case 0xa7:
    goto switchD_0101ec3e_caseD_a7;
  case 0xa8:
    goto switchD_0101ec3e_caseD_a8;
  case 0xa9:
    goto switchD_0101ec3e_caseD_a9;
  case 0xaa:
    goto switchD_0101ec3e_caseD_aa;
  case 0xab:
    goto switchD_0101ec3e_caseD_ab;
  case 0xac:
    goto switchD_0101ec3e_caseD_ac;
  case 0xad:
    goto switchD_0101ec3e_caseD_ad;
  case 0xae:
    goto switchD_0101ec3e_caseD_ae;
  case 0xaf:
    goto switchD_0101ec3e_caseD_af;
  case 0xb0:
    goto switchD_0101ec3e_caseD_b0;
  case 0xb1:
    goto switchD_0101ec3e_caseD_b1;
  case 0xb2:
    goto switchD_0101ec3e_caseD_b2;
  case 0xb3:
    goto switchD_0101ec3e_caseD_b3;
  case 0xb4:
    goto switchD_0101ec3e_caseD_b4;
  case 0xb5:
    goto switchD_0101ec3e_caseD_b5;
  case 0xb6:
    goto switchD_0101ec3e_caseD_b6;
  case 0xb7:
    goto switchD_0101ec3e_caseD_b7;
  case 0xb8:
    goto switchD_0101ec3e_caseD_b8;
  case 0xb9:
    goto switchD_0101ec3e_caseD_b9;
  case 0xba:
    goto switchD_0101ec3e_caseD_ba;
  case 0xbb:
    goto switchD_0101ec3e_caseD_bb;
  case 0xbc:
    goto switchD_0101ec3e_caseD_bc;
  case 0xbd:
    goto switchD_0101ec3e_caseD_bd;
  case 0xbe:
    goto switchD_0101ec3e_caseD_be;
  case 0xbf:
    goto switchD_0101ec3e_caseD_bf;
  case 0xc0:
    goto switchD_0101ec3e_caseD_c0;
  case 0xc1:
    goto switchD_0101ec3e_caseD_c1;
  case 0xc2:
    goto switchD_0101ec3e_caseD_c2;
  case 0xc3:
    goto switchD_0101ec3e_caseD_c3;
  case 0xc4:
    goto switchD_0101ec3e_caseD_c4;
  case 0xc5:
    goto switchD_0101ec3e_caseD_c5;
  case 0xc6:
    goto switchD_0101ec3e_caseD_c6;
  case 199:
    goto switchD_0101ec3e_caseD_c7;
  case 200:
    goto switchD_0101ec3e_caseD_c8;
  case 0xc9:
    goto switchD_0101ec3e_caseD_c9;
  case 0xca:
    goto switchD_0101ec3e_caseD_ca;
  case 0xcb:
    goto switchD_0101ec3e_caseD_cb;
  case 0xcc:
    goto switchD_0101ec3e_caseD_cc;
  case 0xcd:
    goto switchD_0101ec3e_caseD_cd;
  case 0xce:
    goto switchD_0101ec3e_caseD_ce;
  case 0xcf:
    goto switchD_0101ec3e_caseD_cf;
  case 0xd0:
    goto switchD_0101ec3e_caseD_d0;
  case 0xd1:
    goto switchD_0101ec3e_caseD_d1;
  case 0xd2:
    goto switchD_0101ec3e_caseD_d2;
  case 0xd3:
    goto switchD_0101ec3e_caseD_d3;
  case 0xd4:
    goto switchD_0101ec3e_caseD_d4;
  case 0xd5:
    goto switchD_0101ec3e_caseD_d5;
  case 0xd6:
    goto switchD_0101ec3e_caseD_d6;
  case 0xd7:
    goto switchD_0101ec3e_caseD_d7;
  case 0xd8:
    goto switchD_0101ec3e_caseD_d8;
  case 0xd9:
    goto switchD_0101ec3e_caseD_d9;
  case 0xda:
    goto switchD_0101ec3e_caseD_da;
  case 0xdb:
    goto switchD_0101ec3e_caseD_db;
  case 0xdc:
    goto switchD_0101ec3e_caseD_dc;
  case 0xdd:
    goto switchD_0101ec3e_caseD_dd;
  case 0xde:
    goto switchD_0101ec3e_caseD_de;
  case 0xdf:
    goto switchD_0101ec3e_caseD_df;
  case 0xe0:
    goto switchD_0101ec3e_caseD_e0;
  case 0xe1:
    goto switchD_0101ec3e_caseD_e1;
  case 0xe2:
    goto switchD_0101ec3e_caseD_e2;
  case 0xe3:
    goto switchD_0101ec3e_caseD_e3;
  case 0xe4:
    goto switchD_0101ec3e_caseD_e4;
  case 0xe5:
    goto switchD_0101ec3e_caseD_e5;
  case 0xe6:
    goto switchD_0101ec3e_caseD_e6;
  case 0xe7:
    goto switchD_0101ec3e_caseD_e7;
  case 0xe8:
    goto switchD_0101ec3e_caseD_e8;
  case 0xe9:
    goto switchD_0101ec3e_caseD_e9;
  case 0xea:
    goto switchD_0101ec3e_caseD_ea;
  case 0xeb:
    goto switchD_0101ec3e_caseD_eb;
  case 0xec:
    goto switchD_0101ec3e_caseD_ec;
  case 0xed:
    goto switchD_0101ec3e_caseD_ed;
  case 0xee:
    goto switchD_0101ec3e_caseD_ee;
  case 0xef:
    goto switchD_0101ec3e_caseD_ef;
  case 0xf0:
    goto switchD_0101ec3e_caseD_f0;
  case 0xf1:
    goto switchD_0101ec3e_caseD_f1;
  case 0xf2:
    goto switchD_0101ec3e_caseD_f2;
  case 0xf3:
    goto switchD_0101ec3e_caseD_f3;
  case 0xf4:
    goto switchD_0101ec3e_caseD_f4;
  case 0xf5:
    goto switchD_0101ec3e_caseD_f5;
  case 0xf6:
    goto switchD_0101ec3e_caseD_f6;
  case 0xf7:
    goto switchD_0101ec3e_caseD_f7;
  case 0xf8:
    goto switchD_0101ec3e_caseD_f8;
  case 0xf9:
    goto switchD_0101ec3e_caseD_f9;
  case 0xfa:
    goto switchD_0101ec3e_caseD_fa;
  case 0xfb:
    goto switchD_0101ec3e_caseD_fb;
  case 0xfc:
    goto switchD_0101ec3e_caseD_fc;
  case 0xfd:
    goto switchD_0101ec3e_caseD_fd;
  case 0xfe:
    goto switchD_0101ec3e_caseD_fe;
  case 0xff:
    goto switchD_0101ec3e_caseD_ff;
  }
switchD_0101ec3e_caseD_4a:
  pbVar4 = (byte *)(uint)*pbVar14;
switchD_0101ec3e_caseD_4b:
  pbVar6 = (byte *)0xfd;
switchD_0101ec3e_caseD_4c:
  pbVar4 = (byte *)((uint)pbVar4 & (uint)pbVar6);
switchD_0101ec3e_caseD_4d:
  *pbVar14 = (byte)pbVar4;
switchD_0101ec3e_caseD_4e:
  pbVar4 = (byte *)(uint)*pbVar14;
switchD_0101ec3e_caseD_4f:
  pbVar4 = (byte *)((uint)pbVar4 | (uint)pbVar13);
switchD_0101ec3e_caseD_50:
  *pbVar14 = (byte)pbVar4;
switchD_0101ec3e_caseD_51:
  pbVar4 = DAT_0101efa8;
switchD_0101ec3e_caseD_52:
  pbVar4 = (byte *)(uint)pbVar4[2];
switchD_0101ec3e_caseD_53:
  pbVar10 = DAT_0101ef8c;
switchD_0101ec3e_caseD_54:
  pbVar8 = (byte *)((int)pbVar4 << 0x1f);
switchD_0101ec3e_caseD_55:
  pbVar6 = DAT_0101ef90;
switchD_0101ec3e_caseD_56:
  pbVar4 = pbVar10;
  pbVar10 = pbVar4;
switchD_0101ec3e_caseD_57:
  pbVar14 = (byte *)0x0;
switchD_0101ec3e_caseD_58:
  pbVar6 = pbVar6 + 0x40;
switchD_0101ec3e_caseD_59:
  pbVar4 = pbVar4 + 0x40;
switchD_0101ec3e_caseD_5a:
  bVar18 = pbVar8 == (byte *)0x0;
switchD_0101ec3e_caseD_5b:
  if (bVar18) {
switchD_0101ec3e_caseD_7b:
    pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_7c:
    pbVar8 = (byte *)(uint)pbVar8[2];
switchD_0101ec3e_caseD_7d:
    bVar17 = (int)pbVar8 << 0x1e < 0;
switchD_0101ec3e_caseD_7e:
    if (bVar17 != false) {
switchD_0101ec3e_caseD_7f:
      bVar3 = 0x55;
switchD_0101ec3e_caseD_80:
      *pbVar10 = bVar3;
switchD_0101ec3e_caseD_81:
      unaff_r6 = (byte *)0x2;
switchD_0101ec3e_caseD_82:
      *(short *)(pbVar10 + 2) = (short)unaff_r6;
switchD_0101ec3e_caseD_83:
      bVar3 = 0x27;
switchD_0101ec3e_caseD_84:
      pbVar10[4] = bVar3;
switchD_0101ec3e_caseD_85:
      pbVar8 = (byte *)0x1;
switchD_0101ec3e_caseD_86:
      unaff_r6 = unaff_r6 + 3;
switchD_0101ec3e_caseD_87:
      pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec3e_caseD_88:
      pbVar15 = unaff_r6;
switchD_0101ec3e_caseD_89:
switchD_0101ec3e_caseD_8f:
      while( true ) {
        bVar19 = SBORROW4((int)pbVar15,(int)pbVar8);
        bVar17 = (int)pbVar15 - (int)pbVar8 < 0;
        bVar18 = pbVar15 == pbVar8;
switchD_0101ec3e_caseD_90:
        if (bVar18 || bVar17 != bVar19) break;
switchD_0101ec3e_caseD_8a:
        unaff_r6 = (byte *)(uint)pbVar4[0x15];
switchD_0101ec3e_caseD_8b:
        unaff_r7 = (byte *)(uint)pbVar10[(int)pbVar8];
switchD_0101ec3e_caseD_8c:
        unaff_r6 = unaff_r6 + (int)unaff_r7;
switchD_0101ec3e_caseD_8d:
        pbVar4[0x15] = (byte)unaff_r6;
switchD_0101ec3e_caseD_8e:
        pbVar8 = pbVar8 + 1;
      }
switchD_0101ec3e_caseD_91:
      pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_92:
      unaff_r6 = (byte *)(uint)pbVar8[2];
switchD_0101ec3e_caseD_93:
      unaff_r7 = (byte *)0xfd;
switchD_0101ec3e_caseD_94:
      unaff_r6 = (byte *)((uint)unaff_r6 & (uint)unaff_r7);
switchD_0101ec3e_caseD_95:
      pbVar8[2] = (byte)unaff_r6;
switchD_0101ec3e_caseD_96:
      unaff_r6 = (byte *)(uint)*pbVar8;
switchD_0101ec3e_caseD_97:
      unaff_r6 = (byte *)((uint)unaff_r6 | (uint)pbVar13);
switchD_0101ec3e_caseD_98:
      *pbVar8 = (byte)unaff_r6;
    }
  }
  else {
switchD_0101ec3e_caseD_5c:
    bVar3 = 0x55;
switchD_0101ec3e_caseD_5d:
    *pbVar10 = bVar3;
switchD_0101ec3e_caseD_5e:
    unaff_r6 = (byte *)0x2;
switchD_0101ec3e_caseD_5f:
    *(short *)(pbVar10 + 2) = (short)unaff_r6;
switchD_0101ec3e_caseD_60:
    bVar3 = 0x25;
switchD_0101ec3e_caseD_61:
    pbVar10[4] = bVar3;
switchD_0101ec3e_caseD_62:
    pbVar8 = (byte *)0x1;
switchD_0101ec3e_caseD_63:
    unaff_r6 = unaff_r6 + 3;
switchD_0101ec3e_caseD_64:
    pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec3e_caseD_65:
    pbVar15 = unaff_r6;
switchD_0101ec3e_caseD_66:
switchD_0101ec3e_caseD_6d:
    while( true ) {
      bVar19 = SBORROW4((int)pbVar15,(int)pbVar8);
      bVar17 = (int)pbVar15 - (int)pbVar8 < 0;
      bVar18 = pbVar15 == pbVar8;
switchD_0101ec3e_caseD_6e:
      if (bVar18 || bVar17 != bVar19) break;
switchD_0101ec3e_caseD_68:
      unaff_r6 = (byte *)(uint)pbVar4[0x15];
switchD_0101ec3e_caseD_69:
      unaff_r7 = (byte *)(uint)pbVar10[(int)pbVar8];
switchD_0101ec3e_caseD_6a:
      unaff_r6 = unaff_r6 + (int)unaff_r7;
switchD_0101ec3e_caseD_6b:
      pbVar4[0x15] = (byte)unaff_r6;
switchD_0101ec3e_caseD_6c:
      pbVar8 = pbVar8 + 1;
    }
code_r0x0101ed20:
    pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_70:
    unaff_r6 = (byte *)(uint)pbVar8[2];
switchD_0101ec3e_caseD_71:
    unaff_r6 = (byte *)((uint)unaff_r6 >> 1);
switchD_0101ec3e_caseD_72:
    unaff_r6 = (byte *)((int)unaff_r6 << 1);
switchD_0101ec3e_caseD_73:
    pbVar8[2] = (byte)unaff_r6;
switchD_0101ec3e_caseD_74:
    unaff_r6 = (byte *)(uint)*pbVar8;
switchD_0101ec3e_caseD_75:
    unaff_r6 = (byte *)((uint)unaff_r6 | (uint)pbVar13);
switchD_0101ec3e_caseD_76:
    *pbVar8 = (byte)unaff_r6;
switchD_0101ec3e_caseD_77:
    pbVar6[0x19] = (byte)pbVar13;
switchD_0101ec3e_caseD_78:
    pbVar8 = DAT_0101ef90;
switchD_0101ec3e_caseD_79:
    *(byte **)(pbVar8 + 0x5c) = pbVar14;
switchD_0101ec3e_caseD_7a:
  }
switchD_0101ec3e_caseD_99:
  pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_9a:
  pbVar8 = (byte *)(uint)pbVar8[1];
switchD_0101ec3e_caseD_9b:
  bVar17 = (int)pbVar8 << 0x1e < 0;
switchD_0101ec3e_caseD_9c:
  if (bVar17 != false) {
switchD_0101ec3e_caseD_9d:
    bVar3 = 0x55;
switchD_0101ec3e_caseD_9e:
    *pbVar10 = bVar3;
switchD_0101ec3e_caseD_9f:
    unaff_r6 = (byte *)0x5;
switchD_0101ec3e_caseD_a0:
    *(short *)(pbVar10 + 2) = (short)unaff_r6;
switchD_0101ec3e_caseD_a1:
    bVar3 = 0x22;
switchD_0101ec3e_caseD_a2:
    pbVar10[4] = bVar3;
switchD_0101ec3e_caseD_a3:
    pbVar8 = DAT_0101ef90;
switchD_0101ec3e_caseD_a4:
    pbVar8 = pbVar8 + 0x20;
switchD_0101ec3e_caseD_a5:
    bVar3 = pbVar8[0x12];
switchD_0101ec3e_caseD_a6:
    pbVar10[5] = bVar3;
switchD_0101ec3e_caseD_a7:
    pbVar8 = DAT_0101ef90;
switchD_0101ec3e_caseD_a8:
    unaff_r7 = (byte *)(uint)pbVar8[10];
switchD_0101ec3e_caseD_a9:
    pbVar10[6] = (byte)unaff_r7;
switchD_0101ec3e_caseD_aa:
    bVar3 = pbVar8[0xb];
switchD_0101ec3e_caseD_ab:
    pbVar10[7] = bVar3;
switchD_0101ec3e_caseD_ac:
    pbVar8 = (byte *)0x1;
switchD_0101ec3e_caseD_ad:
    unaff_r6 = unaff_r6 + 3;
switchD_0101ec3e_caseD_ae:
    pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec3e_caseD_af:
    pbVar15 = unaff_r6;
switchD_0101ec3e_caseD_b0:
switchD_0101ec3e_caseD_b6:
    while( true ) {
      bVar19 = SBORROW4((int)pbVar15,(int)pbVar8);
      bVar17 = (int)pbVar15 - (int)pbVar8 < 0;
      bVar18 = pbVar15 == pbVar8;
switchD_0101ec3e_caseD_b7:
      if (bVar18 || bVar17 != bVar19) break;
switchD_0101ec3e_caseD_b1:
      unaff_r6 = (byte *)(uint)pbVar4[0x15];
switchD_0101ec3e_caseD_b2:
      unaff_r7 = (byte *)(uint)pbVar10[(int)pbVar8];
switchD_0101ec3e_caseD_b3:
      unaff_r6 = unaff_r6 + (int)unaff_r7;
switchD_0101ec3e_caseD_b4:
      pbVar4[0x15] = (byte)unaff_r6;
switchD_0101ec3e_caseD_b5:
      pbVar8 = pbVar8 + 1;
    }
switchD_0101ec3e_caseD_b8:
    pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_b9:
    unaff_r6 = (byte *)(uint)pbVar8[1];
switchD_0101ec3e_caseD_ba:
    unaff_r7 = (byte *)0xfd;
switchD_0101ec3e_caseD_bb:
    unaff_r6 = (byte *)((uint)unaff_r6 & (uint)unaff_r7);
switchD_0101ec3e_caseD_bc:
    pbVar8[1] = (byte)unaff_r6;
switchD_0101ec3e_caseD_bd:
    unaff_r6 = (byte *)(uint)*pbVar8;
switchD_0101ec3e_caseD_be:
    unaff_r6 = (byte *)((uint)unaff_r6 | (uint)pbVar13);
switchD_0101ec3e_caseD_bf:
    *pbVar8 = (byte)unaff_r6;
  }
switchD_0101ec3e_caseD_c0:
  pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_c1:
  pbVar8 = (byte *)(uint)pbVar8[1];
switchD_0101ec3e_caseD_c2:
  bVar17 = (int)pbVar8 << 0x1d < 0;
switchD_0101ec3e_caseD_c3:
  if (bVar17 != false) {
switchD_0101ec3e_caseD_c4:
    bVar3 = 0x55;
switchD_0101ec3e_caseD_c5:
    *pbVar10 = bVar3;
switchD_0101ec3e_caseD_c6:
    unaff_r6 = (byte *)0x2;
switchD_0101ec3e_caseD_c7:
    *(short *)(pbVar10 + 2) = (short)unaff_r6;
switchD_0101ec3e_caseD_c8:
    bVar3 = 0x30;
switchD_0101ec3e_caseD_c9:
    pbVar10[4] = bVar3;
switchD_0101ec3e_caseD_ca:
    pbVar8 = (byte *)0x1;
switchD_0101ec3e_caseD_cb:
    unaff_r6 = unaff_r6 + 3;
switchD_0101ec3e_caseD_cc:
    pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec3e_caseD_cd:
    pbVar15 = unaff_r6;
switchD_0101ec3e_caseD_ce:
switchD_0101ec3e_caseD_d4:
    while( true ) {
      bVar19 = SBORROW4((int)pbVar15,(int)pbVar8);
      bVar17 = (int)pbVar15 - (int)pbVar8 < 0;
      bVar18 = pbVar15 == pbVar8;
switchD_0101ec3e_caseD_d5:
      if (bVar18 || bVar17 != bVar19) break;
switchD_0101ec3e_caseD_cf:
      unaff_r6 = (byte *)(uint)pbVar4[0x15];
switchD_0101ec3e_caseD_d0:
      unaff_r7 = (byte *)(uint)pbVar10[(int)pbVar8];
switchD_0101ec3e_caseD_d1:
      unaff_r6 = unaff_r6 + (int)unaff_r7;
switchD_0101ec3e_caseD_d2:
      pbVar4[0x15] = (byte)unaff_r6;
switchD_0101ec3e_caseD_d3:
      pbVar8 = pbVar8 + 1;
    }
switchD_0101ec3e_caseD_d6:
    pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_d7:
    unaff_r6 = (byte *)(uint)pbVar8[1];
switchD_0101ec3e_caseD_d8:
    unaff_r7 = (byte *)0xfb;
switchD_0101ec3e_caseD_d9:
    unaff_r6 = (byte *)((uint)unaff_r6 & (uint)unaff_r7);
switchD_0101ec3e_caseD_da:
    pbVar8[1] = (byte)unaff_r6;
switchD_0101ec3e_caseD_db:
    unaff_r6 = (byte *)(uint)*pbVar8;
switchD_0101ec3e_caseD_dc:
    unaff_r6 = (byte *)((uint)unaff_r6 | (uint)pbVar13);
switchD_0101ec3e_caseD_dd:
    *pbVar8 = (byte)unaff_r6;
  }
switchD_0101ec3e_caseD_de:
  pbVar8 = DAT_0101efa8;
switchD_0101ec3e_caseD_df:
  pbVar8 = (byte *)(uint)*pbVar8;
switchD_0101ec3e_caseD_e0:
  bVar18 = (uint)pbVar8 >> 7 == 0;
switchD_0101ec3e_caseD_e1:
  if (!bVar18) {
switchD_0101ec3e_caseD_e2:
    bVar3 = 0x55;
switchD_0101ec3e_caseD_e3:
    *pbVar10 = bVar3;
switchD_0101ec3e_caseD_e4:
    unaff_r6 = (byte *)0xa;
switchD_0101ec3e_caseD_e5:
    *(short *)(pbVar10 + 2) = (short)unaff_r6;
switchD_0101ec3e_caseD_e6:
    bVar3 = 0x23;
switchD_0101ec3e_caseD_e7:
    pbVar10[4] = bVar3;
switchD_0101ec3e_caseD_e8:
    bVar3 = pbVar6[0xb];
switchD_0101ec3e_caseD_e9:
    pbVar10[5] = bVar3;
switchD_0101ec3e_caseD_ea:
    bVar3 = pbVar6[10];
switchD_0101ec3e_caseD_eb:
    pbVar10[6] = bVar3;
switchD_0101ec3e_caseD_ec:
    bVar3 = pbVar6[4];
switchD_0101ec3e_caseD_ed:
    pbVar10[7] = bVar3;
switchD_0101ec3e_caseD_ee:
    bVar3 = pbVar6[5];
switchD_0101ec3e_caseD_ef:
    pbVar10[8] = bVar3;
switchD_0101ec3e_caseD_f0:
    bVar3 = pbVar6[6];
switchD_0101ec3e_caseD_f1:
    pbVar10[9] = bVar3;
switchD_0101ec3e_caseD_f2:
    bVar3 = pbVar6[7];
switchD_0101ec3e_caseD_f3:
    pbVar10[10] = bVar3;
switchD_0101ec3e_caseD_f4:
    bVar3 = pbVar6[8];
switchD_0101ec3e_caseD_f5:
    pbVar10[0xb] = bVar3;
switchD_0101ec3e_caseD_f6:
    bVar3 = pbVar6[9];
switchD_0101ec3e_caseD_f7:
    pbVar10[0xc] = bVar3;
switchD_0101ec3e_caseD_f8:
    pbVar8 = (byte *)0x1;
switchD_0101ec3e_caseD_f9:
    unaff_r6 = unaff_r6 + 3;
switchD_0101ec3e_caseD_fa:
    pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec3e_caseD_fb:
    pbVar15 = unaff_r6;
switchD_0101ec3e_caseD_fc:
switchD_0101ec84_caseD_df:
    while( true ) {
      bVar19 = SBORROW4((int)pbVar15,(int)pbVar8);
      bVar17 = (int)pbVar15 - (int)pbVar8 < 0;
      bVar18 = pbVar15 == pbVar8;
switchD_0101ec84_caseD_e0:
      if (bVar18 || bVar17 != bVar19) break;
switchD_0101ec3e_caseD_fd:
      unaff_r6 = (byte *)(uint)pbVar4[0x15];
switchD_0101ec3e_caseD_fe:
      unaff_r7 = (byte *)(uint)pbVar10[(int)pbVar8];
switchD_0101ec3e_caseD_ff:
      unaff_r6 = unaff_r6 + (int)unaff_r7;
switchD_0101ec84_caseD_dd:
      pbVar4[0x15] = (byte)unaff_r6;
switchD_0101ec84_caseD_de:
      pbVar8 = pbVar8 + 1;
    }
switchD_0101ec84_caseD_e1:
    pbVar8 = DAT_0101efa8;
switchD_0101ec84_caseD_e2:
    unaff_r6 = (byte *)(uint)*pbVar8;
switchD_0101ec84_caseD_e3:
    unaff_r6 = (byte *)((int)unaff_r6 << 0x19);
switchD_0101ec84_caseD_e4:
    unaff_r6 = (byte *)((uint)unaff_r6 >> 0x19);
switchD_0101ec84_caseD_e5:
    *pbVar8 = (byte)unaff_r6;
switchD_0101ec84_caseD_e6:
    unaff_r6 = (byte *)(uint)*pbVar8;
switchD_0101ec84_caseD_e7:
    unaff_r6 = (byte *)((uint)unaff_r6 | (uint)pbVar13);
switchD_0101ec84_caseD_e8:
    *pbVar8 = (byte)unaff_r6;
  }
switchD_0101ec84_caseD_e9:
  unaff_r7 = DAT_0101efa8;
switchD_0101ec84_caseD_ea:
  pbVar8 = (byte *)(uint)unaff_r7[1];
switchD_0101ec84_caseD_eb:
  bVar18 = ((uint)pbVar8 & 1) == 0;
switchD_0101ec84_caseD_ec:
  bVar12 = (byte)pbVar13;
  if (bVar18) {
    bVar3 = (byte)pbVar14;
    if ((*unaff_r7 & 0x7f) >> 3 != 0) {
      *pbVar10 = 0x55;
      *(short *)(pbVar10 + 2) = (short)DAT_0101efac;
      pbVar10[4] = 0x21;
      if (pbVar6[0xe] == 0) {
        pbVar10[5] = pbVar6[0xc];
        pbVar10[6] = pbVar6[0xd];
      }
      else {
        pbVar6[0xe] = bVar3;
        pbVar10[5] = pbVar6[0xc] - 1;
        pbVar10[6] = pbVar6[0xd];
        pbVar6[0xd] = bVar3;
      }
      pbVar4[0x15] = pbVar10[5] + 0x35 + pbVar10[6];
      pbVar14 = DAT_0101ef90;
      iVar9 = 0;
      do {
        iVar7 = iVar9 + (uint)pbVar6[0x10] * 0x1000;
        iVar9 = iVar9 + 1;
        pbVar4[0x15] = pbVar4[0x15] + pbVar14[iVar7 + 0x6f];
      } while (iVar9 < 0x1000);
      *unaff_r7 = *unaff_r7 & 0x87 | (byte)((((*unaff_r7 & 0x7f) >> 3) - 1 & 0xf) << 3);
      goto LAB_0101ef02;
    }
    if ((int)((uint)unaff_r7[1] << 0x1c) < 0) {
      *pbVar10 = 0x55;
      pbVar10[2] = 2;
      pbVar10[3] = 0;
      pbVar10[4] = 0x3f;
      pbVar4[0x15] = bVar3;
      for (iVar9 = 1; iVar9 < 5; iVar9 = iVar9 + 1) {
        pbVar14 = (byte *)(((uint)pbVar14 & 0xff) + (uint)pbVar10[iVar9]);
        pbVar4[0x15] = (byte)pbVar14;
      }
      bVar3 = unaff_r7[1];
      bVar5 = 0xf7;
    }
    else if ((int)((uint)unaff_r7[1] << 0x1b) < 0) {
      *pbVar10 = 0x55;
      pbVar10[2] = 2;
      pbVar10[3] = 0;
      pbVar10[4] = 0x3e;
      pbVar4[0x15] = bVar3;
      for (iVar9 = 1; iVar9 < 5; iVar9 = iVar9 + 1) {
        pbVar14 = (byte *)(((uint)pbVar14 & 0xff) + (uint)pbVar10[iVar9]);
        pbVar4[0x15] = (byte)pbVar14;
      }
      bVar3 = unaff_r7[1];
      bVar5 = 0xef;
    }
    else if ((int)((uint)unaff_r7[1] << 0x1a) < 0) {
      *pbVar10 = 0x55;
      pbVar10[2] = 4;
      pbVar10[3] = 0;
      pbVar10[4] = 0x3d;
      pbVar10[5] = (byte)*(undefined2 *)(pbVar6 + 0x28);
      pbVar10[6] = (byte)((ushort)*(undefined2 *)(pbVar6 + 0x28) >> 8);
      pbVar4[0x15] = bVar3;
      for (iVar9 = 1; iVar9 < 7; iVar9 = iVar9 + 1) {
        pbVar14 = (byte *)(((uint)pbVar14 & 0xff) + (uint)pbVar10[iVar9]);
        pbVar4[0x15] = (byte)pbVar14;
      }
      bVar3 = unaff_r7[1];
      bVar5 = 0xdf;
    }
    else {
      if (-1 < (int)((uint)unaff_r7[1] << 0x19)) {
        if (-1 < (char)unaff_r7[1]) {
          return;
        }
        *pbVar10 = 0x55;
        pbVar10[2] = 6;
        pbVar10[3] = 0;
        pbVar10[4] = 0x3b;
        iVar9 = DAT_0101f120;
        pbVar10[5] = (byte)*(undefined4 *)(DAT_0101f120 + 0x60);
        pbVar10[6] = (byte)((uint)*(undefined4 *)(iVar9 + 0x60) >> 8);
        pbVar10[7] = (byte)((uint)*(undefined4 *)(iVar9 + 0x60) >> 0x10);
        pbVar10[8] = (byte)((uint)*(undefined4 *)(iVar9 + 0x60) >> 0x18);
        pbVar4[0x15] = bVar3;
        for (iVar9 = 1; iVar9 < 9; iVar9 = iVar9 + 1) {
          pbVar14 = (byte *)(((uint)pbVar14 & 0xff) + (uint)pbVar10[iVar9]);
          pbVar4[0x15] = (byte)pbVar14;
        }
        bVar3 = unaff_r7[1] & 0x7f;
        goto LAB_0101f04c;
      }
      *pbVar10 = 0x55;
      pbVar10[2] = 0x42;
      pbVar10[3] = 0;
      pbVar10[4] = 0x3c;
      iVar9 = 0;
      do {
        iVar7 = iVar9 + 1;
        pbVar10[iVar9 + 5] = *(byte *)(DAT_0101f11c + iVar9);
        iVar9 = iVar7;
      } while (iVar7 < 0x40);
      pbVar4[0x15] = bVar3;
      uVar1 = *(ushort *)(pbVar10 + 2);
      for (iVar9 = 1; iVar9 < (int)(uVar1 + 3); iVar9 = iVar9 + 1) {
        pbVar14 = (byte *)(((uint)pbVar14 & 0xff) + (uint)pbVar10[iVar9]);
        pbVar4[0x15] = (byte)pbVar14;
      }
      bVar3 = unaff_r7[1];
      bVar5 = 0xbf;
    }
    bVar3 = bVar3 & bVar5;
  }
  else {
switchD_0101ec84_caseD_ed:
    pbVar6 = &DAT_00000055;
switchD_0101ec84_caseD_ee:
    *pbVar10 = (byte)pbVar6;
switchD_0101ec84_caseD_ef:
    pbVar8 = (byte *)0x2;
switchD_0101ec84_caseD_f0:
    *(short *)(pbVar10 + 2) = (short)pbVar8;
switchD_0101ec84_caseD_f1:
    pbVar6 = &Reserved3;
switchD_0101ec84_caseD_f2:
    pbVar10[4] = (byte)pbVar6;
switchD_0101ec84_caseD_f3:
    pbVar6 = (byte *)0x1;
switchD_0101ec84_caseD_f4:
    pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec84_caseD_f5:
    pbVar8 = pbVar8 + 3;
switchD_0101ec84_caseD_f6:
switchD_0101ec84_caseD_fc:
    while( true ) {
      bVar19 = SBORROW4((int)pbVar8,(int)pbVar6);
      bVar17 = (int)pbVar8 - (int)pbVar6 < 0;
      bVar18 = pbVar8 == pbVar6;
switchD_0101ec84_caseD_fd:
      bVar5 = (byte)pbVar13;
      if (bVar18 || bVar17 != bVar19) break;
switchD_0101ec84_caseD_f7:
      unaff_r6 = (byte *)(uint)pbVar10[(int)pbVar6];
switchD_0101ec84_caseD_f8:
      pbVar14 = (byte *)((uint)pbVar14 & 0xff);
switchD_0101ec84_caseD_f9:
      pbVar14 = pbVar14 + (int)unaff_r6;
switchD_0101ec84_caseD_fa:
      pbVar4[0x15] = (byte)pbVar14;
switchD_0101ec84_caseD_fb:
      pbVar6 = pbVar6 + 1;
    }
switchD_0101ec84_caseD_fe:
    bVar12 = bVar5;
    pbVar4 = (byte *)(uint)unaff_r7[1];
switchD_0101ec84_caseD_ff:
    bVar3 = (byte)pbVar4 & 0xfe;
  }
LAB_0101f04c:
  unaff_r7[1] = bVar3;
LAB_0101ef02:
  *unaff_r7 = *unaff_r7 | bVar12;
  return;
}


// ===== FUN_0101f050 @ 0101f050

void FUN_0101f050(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((-1 < (int)((uint)*(ushort *)(DAT_0101f124 + 0x1c) << 0x17)) &&
     (*(char *)(DAT_0101f128 + 0x1b) != '\0')) {
    FUN_0101e3b4();
    FUN_0101ec06();
    FUN_0101e774();
    FUN_0101e6ce();
    FUN_0101e45c();
    FUN_0101e40a();
    iVar1 = DAT_0101f120;
    if (*(char *)(DAT_0101f120 + 0x33) != '\0') {
      if (*(char *)(DAT_0101f120 + 0x34) != '\0') {
        *(undefined1 *)(DAT_0101f120 + 0x34) = 0;
        iVar3 = 0;
        do {
          FUN_01013996(0);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x10);
        FUN_01010730(7);
        FUN_0101b686(0);
        FUN_0101382e(7,0);
        FUN_0101b686(0,1);
      }
      uVar2 = *(int *)(iVar1 + 0x38) + 1;
      *(uint *)(iVar1 + 0x38) = uVar2;
      if (0x4af < uVar2) {
        *(undefined4 *)(iVar1 + 0x38) = 0;
        *(undefined1 *)(iVar1 + 0x33) = 0;
        FUN_0101b686(1);
        *DAT_0101f12c = *DAT_0101f12c | 1;
        *(byte *)(DAT_0101f130 + 1) = *(byte *)(DAT_0101f130 + 1) | 1;
      }
    }
    iVar3 = DAT_0101f120;
    if ((*(char *)(DAT_0101f120 + 0x6e) != '\0') &&
       (uVar2 = *(int *)(iVar1 + 100) + 1, *(uint *)(iVar1 + 100) = uVar2, 599 < uVar2)) {
      *(undefined1 *)(iVar3 + 0x6e) = 0;
      *(undefined4 *)(iVar1 + 100) = 0;
    }
    if (*(char *)(iVar3 + 0x6c) != '\0') {
      FUN_0101b686(1,0);
      FUN_01010730(7);
    }
  }
  return;
}


// ===== FUN_0101f134 @ 0101f134

int FUN_0101f134(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0x20;
  while (uVar3 = uVar2 - 1, 0 < (int)uVar2) {
    uVar2 = uVar3;
    if (param_2 <= param_1 >> (uVar3 & 0xff)) {
      param_1 = param_1 - (param_2 << (uVar3 & 0xff));
      iVar1 = iVar1 + (1 << (uVar3 & 0xff));
    }
  }
  return iVar1;
}


// ===== FUN_0101f160 @ 0101f160

int FUN_0101f160(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = param_1 < 0;
  if (bVar2) {
    param_1 = -param_1;
  }
  bVar3 = param_2 < 0;
  if (bVar3) {
    param_2 = -param_2;
  }
  iVar1 = FUN_0101f134(param_1,param_2);
  if (bVar2 != bVar3) {
    iVar1 = -iVar1;
  }
  return iVar1;
}


// ===== FUN_0101f188 @ 0101f188

uint FUN_0101f188(void)

{
  uint uVar1;
  
  uVar1 = DAT_0101f1a4 * *DAT_0101f1a0 + DAT_0101f1a8;
  *DAT_0101f1a0 = uVar1;
  return uVar1 >> 1;
}


// ===== FUN_0101f1ac @ 0101f1ac

void FUN_0101f1ac(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


// ===== FUN_0101f1d0 @ 0101f1d0

void FUN_0101f1d0(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_0101f1de @ 0101f1de

void FUN_0101f1de(undefined4 param_1,undefined4 param_2)

{
  FUN_0101f1d0(param_1,param_2,0);
  return;
}


// ===== FUN_0101f208 @ 0101f208

void FUN_0101f208(void)

{
  byte bVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  uint uVar12;
  longlong lVar13;
  
  puVar3 = puRam0101f228;
  for (puVar11 = puRam0101f224; puVar11 < puVar3; puVar11 = puVar11 + 4) {
    (*(code *)puVar11[3])(*puVar11,puVar11[1],puVar11[2]);
  }
  lVar13 = thunk_FUN_01010482();
  do {
    uVar2 = (ulonglong)lVar13 >> 0x20;
    iVar4 = (int)lVar13;
    do {
      pbVar6 = (byte *)((ulonglong)lVar13 >> 0x20);
      pbVar10 = (byte *)lVar13;
      uVar12 = (uint)*pbVar10;
      pbVar5 = pbVar10 + 1;
      uVar9 = uVar12 & 7;
      if ((*pbVar10 & 7) == 0) {
        uVar9 = (uint)*pbVar5;
        pbVar5 = pbVar10 + 2;
      }
      uVar7 = (int)uVar12 >> 4;
      if (uVar7 == 0) {
        uVar7 = (uint)*pbVar5;
        pbVar5 = pbVar5 + 1;
      }
      while (uVar9 = uVar9 - 1, uVar9 != 0) {
        *pbVar6 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      }
      if ((int)(uVar12 << 0x1c) < 0) {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        pbVar10 = pbVar6 + -(uint)bVar1;
        iVar8 = uVar7 + 2;
        while (iVar8 = iVar8 + -1, -1 < iVar8) {
          *pbVar6 = *pbVar10;
          pbVar6 = pbVar6 + 1;
          pbVar10 = pbVar10 + 1;
        }
      }
      else {
        while (uVar7 = uVar7 - 1, -1 < (int)uVar7) {
          *pbVar6 = 0;
          pbVar6 = pbVar6 + 1;
        }
      }
      lVar13 = CONCAT44(pbVar6,pbVar5);
    } while (pbVar6 < (byte *)((int)uVar2 + iVar4 * 0x10));
    lVar13 = ZEXT48(pbVar6) << 0x20;
  } while( true );
}


// ===== FUN_0101f22c @ 0101f22c

void FUN_0101f22c(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  pbVar6 = param_2 + param_3;
  do {
    uVar7 = (uint)*param_1;
    uVar4 = uVar7 & 7;
    pbVar5 = param_1 + 1;
    if ((*param_1 & 7) == 0) {
      uVar4 = (uint)param_1[1];
      pbVar5 = param_1 + 2;
    }
    param_1 = pbVar5;
    uVar2 = (int)uVar7 >> 4;
    if (uVar2 == 0) {
      uVar2 = (uint)*param_1;
      param_1 = param_1 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int)(uVar7 << 0x1c) < 0) {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      pbVar5 = param_2 + -(uint)bVar1;
      iVar3 = uVar2 + 2;
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        *param_2 = *pbVar5;
        param_2 = param_2 + 1;
        pbVar5 = pbVar5 + 1;
      }
    }
    else {
      while (uVar2 = uVar2 - 1, -1 < (int)uVar2) {
        *param_2 = 0;
        param_2 = param_2 + 1;
      }
    }
  } while (param_2 < pbVar6);
                    /* WARNING: Could not recover jumptable at 0x0101f280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0);
  return;
}


// ===== thunk_EXT_FUN_000000c6 @ 0101f284

void thunk_EXT_FUN_000000c6(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0101f28a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101f28c)(param_1);
  return;
}


// ===== __ARM_common_switch8 @ 0101f290

/* WARNING: This is an inlined function */

void __ARM_common_switch8(void)

{
  uint in_r3;
  uint uVar1;
  int unaff_lr;
  
  uVar1 = (uint)*(byte *)(unaff_lr + -1);
  if (in_r3 < *(byte *)(unaff_lr + -1)) {
    uVar1 = in_r3;
  }
                    /* WARNING: Could not recover jumptable at 0x0101f2a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_lr + (uint)*(byte *)(unaff_lr + uVar1) * 2))();
  return;
}


// ===== FUN_0101f2c8 @ 0101f2c8

undefined8 FUN_0101f2c8(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 local_20;
  
  puVar1 = DAT_0101f350;
  uVar5 = 1;
  uVar2 = DAT_0101f350[7];
  iVar3 = 5;
  uVar4 = (uVar2 & 0xffffff) >> 0x10;
  local_20 = CONCAT13((char)param_1,
                      CONCAT12((char)((uint)param_1 >> 8),
                               CONCAT11((char)((uint)param_1 >> 0x10),
                                        (char)((uVar2 & 0xffffff) >> 0x10))));
  if ((uVar4 != 0xbb) && ((uVar4 < 0xbc || ((uVar4 != 0xe7 && (uVar4 != 0xeb)))))) {
    iVar3 = 4;
  }
  DAT_0101f350[7] = uVar2 & DAT_0101f354;
  *puVar1 = &local_20;
  puVar1[1] = param_3;
  puVar1[2] = iVar3 << 0x10 | param_2;
  *(undefined1 *)(puVar1 + 3) = 0;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x20;
  *(byte *)((int)puVar1 + 0xf) = *(byte *)((int)puVar1 + 0xf) & 0xdf;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  iVar3 = 0;
  do {
    if ((puVar1[4] & 1) != 0) goto LAB_0101f346;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10001);
  uVar5 = 0;
LAB_0101f346:
  puVar1[7] = uVar2;
  return CONCAT44(local_20,uVar5);
}


// ===== FUN_0101f358 @ 0101f358

undefined4 FUN_0101f358(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_124 [4];
  undefined1 local_120 [256];
  int local_20;
  uint uStack_1c;
  int local_18;
  
  local_20 = param_1;
  uStack_1c = param_2;
  local_18 = param_3;
  FUN_0101f1de(auStack_124,0x104);
  uVar1 = param_2 + 0xff;
  uVar5 = 0;
  while( true ) {
    if (uVar1 >> 8 <= uVar5) {
      return 1;
    }
    uVar4 = 0x100;
    if (param_2 < 0x101) {
      uVar4 = param_2;
    }
    (*DAT_0101f3d4)(auStack_124,2,uVar5 * 0x100 + local_20);
    for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
      local_120[uVar2] = *(undefined1 *)(local_18 + uVar5 * 0x100 + uVar2);
    }
    iVar3 = (*(DAT_0101f3d4 + -0x14))();
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = (*DAT_0101f3d8)(auStack_124,uVar4 + 4);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = (*(DAT_0101f3d4 + -0xa4))();
    if (iVar3 == 0) break;
    param_2 = param_2 - uVar4;
    uVar5 = uVar5 + 1;
  }
  return 0;
}


// ===== FUN_0101f3dc @ 0101f3dc

void FUN_0101f3dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint local_14;
  
  local_14 = param_4;
  FUN_0101e1ee();
  local_14 = 0;
  disableIRQinterrupts();
  thunk_EXT_FUN_0000442c();
  (*DAT_0101f428)(param_1,&local_14,0,0,0);
  thunk_EXT_FUN_00004480();
  local_14 = local_14 << 0x18 | (local_14 >> 8 & 0xff) << 0x10 | (local_14 >> 0x10 & 0xff) << 8 |
             local_14 >> 0x18;
  uVar1 = FUN_0101f5a8();
  thunk_EXT_FUN_00004404(DAT_0101f42c,DAT_0101f42c + 0xb2);
  FUN_0101f6ac(local_14);
  FUN_0101f55c(uVar1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_0101f430 @ 0101f430

void FUN_0101f430(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_94 [128];
  
  iVar5 = ((param_1 & 0x7fffff) >> 0xf) * 0x9000;
  iVar1 = DAT_0101f4b0 + 0x80;
  iVar2 = DAT_0101f4b0 + 0x80;
  iVar3 = DAT_0101f4b0 + 0x80;
  iVar4 = DAT_0101f4b0 + 0x80;
  iVar7 = iVar5 + 0x1000000;
  FUN_0101f61c(iVar7,auStack_94 + DAT_0101f4b0 + 0x80,0x10);
  FUN_0101f658(iVar7);
  FUN_0101f680(iVar7,auStack_94 + iVar1,0x10);
  uVar8 = iVar5 + 0x1009000;
  for (uVar6 = iVar5 + 0x1001000; uVar6 < uVar8; uVar6 = uVar6 + 0x1000) {
    FUN_0101f658(uVar6);
  }
  FUN_0101f61c(uVar8,auStack_94 + iVar2,0x1000);
  FUN_0101f658(uVar8);
  FUN_0101f1d0(auStack_94 + iVar3,0x10,0xff);
  FUN_0101f680(uVar8,auStack_94 + iVar4,0x1000);
  return;
}


// ===== FUN_0101f4b4 @ 0101f4b4

void FUN_0101f4b4(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  uVar4 = 0x20 - (param_1 & 0x1f);
  if (param_3 < uVar4) {
    uVar4 = param_3;
  }
  iVar3 = 0;
  while (param_3 != 0) {
    iVar1 = FUN_0101f57c(param_1,uVar4);
    if (iVar1 == 0) {
      thunk_EXT_FUN_00004404(param_1,param_1 + uVar4);
      for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
        *(undefined1 *)(param_2 + iVar3) = *(undefined1 *)(param_1 + uVar2);
        iVar3 = iVar3 + 1;
      }
    }
    else {
      FUN_0101f1d0(param_2 + iVar3,uVar4,0xff);
      iVar3 = iVar3 + uVar4;
    }
    param_1 = param_1 + uVar4;
    param_3 = param_3 - uVar4;
    if (param_3 < 0x20) {
      uVar4 = param_3;
    }
    else {
      uVar4 = 0x20;
    }
  }
  enableIRQinterrupts();
  return;
}


// ===== FUN_0101f520 @ 0101f520

void FUN_0101f520(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  uVar1 = FUN_0101f5a8();
  thunk_EXT_FUN_0000442c();
  (*DAT_0101f558)(param_1,param_2,param_3,1,0);
  thunk_EXT_FUN_00004480();
  FUN_0101f55c(uVar1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_0101f55c @ 0101f55c

void FUN_0101f55c(uint param_1)

{
  thunk_EXT_FUN_00004404(DAT_0101f578,DAT_0101f578 + 0x40);
  FUN_0101f740(param_1 & 0xffffff80,param_1 & 0xf);
  return;
}


// ===== FUN_0101f57c @ 0101f57c

undefined4 FUN_0101f57c(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  thunk_EXT_FUN_0000442c();
  uVar1 = (*DAT_0101f5a4)(param_1 & 0xffffffe0,param_1 + param_2);
  thunk_EXT_FUN_00004480();
  enableIRQinterrupts();
  return uVar1;
}


// ===== FUN_0101f5a8 @ 0101f5a8

uint FUN_0101f5a8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = *(uint *)(DAT_0101f5e4 + 0x20) & 0xf;
  if ((*(uint *)(DAT_0101f5e0 + 0x1c) & 0x80) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = uVar2 | uVar1;
  thunk_EXT_FUN_00004404(DAT_0101f5e8,DAT_0101f5e8 + 0x40);
  if (uVar1 == 0) {
    uVar1 = 2;
  }
  FUN_0101f740(0,uVar1);
  return uVar2;
}


// ===== thunk_EXT_FUN_00004404 @ 0101f5ec

void thunk_EXT_FUN_00004404(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101f5ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101f5f0)();
  return;
}


// ===== FUN_0101f5f4 @ 0101f5f4

undefined4 FUN_0101f5f4(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  uVar1 = FUN_0101f5a8();
  uVar2 = (*DAT_0101f618)(param_1);
  FUN_0101f55c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_0101f61c @ 0101f61c

undefined4 FUN_0101f61c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  uVar1 = FUN_0101f5a8();
  thunk_EXT_FUN_00004404(DAT_0101f654,DAT_0101f654 + 0x100);
  uVar2 = FUN_0101f2c8(param_1,param_3,param_2);
  FUN_0101f55c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_0101f658 @ 0101f658

undefined4 FUN_0101f658(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  uVar1 = FUN_0101f5a8();
  uVar2 = (*DAT_0101f67c)(param_1);
  FUN_0101f55c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_0101f680 @ 0101f680

undefined4 FUN_0101f680(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0101e1ee();
  disableIRQinterrupts();
  uVar1 = FUN_0101f5a8();
  uVar2 = FUN_0101f358(param_1,param_3,param_2);
  FUN_0101f55c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_0101f6ac @ 0101f6ac

void FUN_0101f6ac(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  undefined1 auStack_94 [128];
  
  iVar2 = DAT_0101f734;
  iVar1 = DAT_0101f734 + 0x80;
  FUN_0101f1de(auStack_94 + DAT_0101f734 + 0x80,0x1000);
  uVar6 = param_1 & 0xfff;
  param_1 = param_1 & 0xfffff000;
  if (uVar6 + 0x24 < 0x1001) {
    cVar5 = '\x01';
  }
  else {
    cVar5 = '\x02';
  }
  if (cVar5 == '\x02') {
    uVar3 = -uVar6;
  }
  else {
    uVar3 = 0x24;
  }
  while( true ) {
    if (cVar5 == '\0') break;
    (*DAT_0101f738)(param_1,0x1000,auStack_94 + iVar1);
    (*(DAT_0101f738 + -0x42))(param_1);
    for (iVar4 = 0; iVar4 < (int)(uVar3 & 0xff); iVar4 = iVar4 + 1) {
      auStack_94[uVar6 + iVar4 + iVar2 + 0x80] = 0xff;
    }
    (*DAT_0101f73c)(param_1,0x1000);
    param_1 = param_1 + 0x1000;
    uVar6 = 0;
    uVar3 = 0x24 - (uVar3 & 0xff);
    cVar5 = cVar5 + -1;
  }
  return;
}


// ===== FUN_0101f740 @ 0101f740

void FUN_0101f740(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_0101f764 + 0x1c) & 0xffffff7f;
  }
  else {
    uVar1 = *(uint *)(DAT_0101f764 + 0x1c) | 0x80;
  }
  *(uint *)(DAT_0101f764 + 0x1c) = uVar1;
  *(uint *)(DAT_0101f768 + 0x20) = *(uint *)(DAT_0101f768 + 0x20) & 0xfffffff0 | param_2 & 0xf;
  return;
}


