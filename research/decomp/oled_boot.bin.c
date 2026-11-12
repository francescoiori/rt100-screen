// ===== FUN_010002f8 @ 010002f8

void FUN_010002f8(void)

{
  *(undefined4 *)*DAT_010003b4 = 1;
                    /* WARNING: Could not recover jumptable at 0x01000304. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*DAT_010003b8)();
  return;
}


// ===== FUN_01000316 @ 01000316

void FUN_01000316(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== thunk_FUN_0100090e @ 01000408

void thunk_FUN_0100090e(void)

{
  (*DAT_0100040c)();
  return;
}


// ===== FUN_01000414 @ 01000414

undefined4 FUN_01000414(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (param_1 & 3) << 3;
  uVar3 = 0xff << iVar4;
  uVar2 = ((param_2 & 3) << 6) << iVar4;
  if ((int)param_1 < 0) {
    iVar4 = ((param_1 & 0xf) - 8 & 0xfffffffc) + DAT_01000494;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & ~uVar3 | uVar2;
  }
  else {
    puVar1 = (uint *)((param_1 & 0xfffffffc) + DAT_01000498);
    *puVar1 = *puVar1 & ~uVar3 | uVar2;
  }
  return 1;
}


// ===== FUN_01000460 @ 01000460

void FUN_01000460(uint param_1)

{
  *DAT_0100049c = *DAT_0100049c | 1 << (param_1 & 0xff);
  return;
}


// ===== FUN_0100047a @ 0100047a

void FUN_0100047a(void)

{
  *(uint *)(DAT_010004a0 + 0x34) = *(uint *)(DAT_010004a0 + 0x34) | 1;
  *(undefined4 *)(DAT_010004a0 + 0x3c) = 0x55;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0100048a @ 0100048a

void FUN_0100048a(void)

{
  return;
}


// ===== FUN_010006fc @ 010006fc

void FUN_010006fc(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_01000728 @ 01000728

void FUN_01000728(undefined4 param_1,int param_2)

{
  int iVar1;
  
  FUN_010023a0(param_1,DAT_01000a10,0x40);
  iVar1 = 0;
  do {
    if (*(char *)(DAT_01000a10 + iVar1) != *(char *)(param_2 + iVar1)) {
      *(int *)(DAT_01000a14 + 0x50) = *(int *)(DAT_01000a14 + 0x50) + 1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return;
}


// ===== FUN_01000752 @ 01000752

void FUN_01000752(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(char *)(DAT_01000a14 + 0x44) != '\0') && (*(char *)(DAT_01000a14 + 0x45) != '\0')) {
    *(undefined1 *)(DAT_01000a14 + 0x44) = 0;
    iVar1 = DAT_01000a14;
    uVar2 = 0;
    do {
      iVar3 = iVar1 + uVar2;
      uVar2 = uVar2 + 1 & 0xff;
      *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) + (uint)*(byte *)(iVar3 + 4);
      iVar3 = DAT_01000a18;
    } while (uVar2 < 0x40);
    FUN_01002420((uint)*(ushort *)(iVar1 + 2) * 0x40 + DAT_01000a18,iVar1 + 4,0x40);
    FUN_01000728((uint)*(ushort *)(iVar1 + 2) * 0x40 + iVar3,iVar1 + 4);
    *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 1;
    *(undefined4 *)(DAT_01000a1c + 0x18) = 0;
  }
  return;
}


// ===== FUN_010007a6 @ 010007a6

void FUN_010007a6(void)

{
  if ((*(char *)(DAT_01000a1c + 1) != '\0') && (*(char *)(DAT_01000a14 + 0x45) != '\0')) {
    FUN_0100047a();
  }
  return;
}


// ===== FUN_010007c0 @ 010007c0

void FUN_010007c0(int param_1)

{
  if (((*DAT_01000a20 & 1) == 0) && (param_1 != 0)) {
    if (*(char *)(DAT_01000a14 + 0x4c) == '\0') {
      thunk_EXT_FUN_0000425c(0x32);
      FUN_0100234c(DAT_01000a24);
    }
    else {
      thunk_EXT_FUN_0000425c(0x32);
    }
    FUN_0100047a();
  }
  return;
}


// ===== FUN_010007f2 @ 010007f2

void FUN_010007f2(void)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = DAT_01000a10;
  *(undefined1 *)(DAT_01000a10 + -0x40) = 0xab;
  *(undefined1 *)(iVar1 + -0x3f) = 0xc2;
  *(undefined1 *)(iVar1 + -0x3e) = *(undefined1 *)(iVar1 + -0x7e);
  puVar2 = DAT_01000a1c;
  *(undefined1 *)(iVar1 + -0x3d) = *(undefined1 *)(iVar1 + -0x7d);
  iVar4 = *(int *)(puVar2 + 0x14);
  *(char *)(iVar1 + -0x3b) = (char)iVar4;
  *(char *)(iVar1 + -0x3a) = (char)((uint)iVar4 >> 8);
  *(char *)(iVar1 + -0x39) = (char)((uint)iVar4 >> 0x10);
  *(char *)(iVar1 + -0x38) = (char)((uint)iVar4 >> 0x18);
  uVar3 = FUN_010020d6(iVar1 + -0x7c);
  if ((uVar3 & 0xffffff) == *(uint *)(puVar2 + 0x10)) {
    if (iVar4 == 0) {
      *(undefined1 *)(iVar1 + -0x3c) = 0x55;
    }
    else {
      *(undefined1 *)(iVar1 + -0x3c) = 0xaa;
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 0x14) = 0;
    }
  }
  else {
    *(undefined1 *)(iVar1 + -0x3c) = 0xaa;
    *puVar2 = 0;
  }
  puVar2[5] = 1;
  return;
}


// ===== FUN_0100084e @ 0100084e

void FUN_0100084e(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_01000a10;
  uVar3 = FUN_010020d6(DAT_01000a10 + -0x7c);
  iVar2 = DAT_01000a1c;
  *(uint *)(DAT_01000a1c + 0xc) = uVar3 & 0xffffff;
  *(undefined2 *)(iVar2 + 6) = *(undefined2 *)(iVar1 + -0x7e);
  *(undefined2 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined1 *)(iVar2 + 3) = 1;
  *(undefined1 *)(iVar1 + -0x40) = 0xab;
  *(undefined1 *)(iVar1 + -0x3f) = 0xc0;
  *(undefined1 *)(iVar1 + -0x3e) = *(undefined1 *)(iVar1 + -0x7e);
  *(undefined1 *)(iVar1 + -0x3d) = *(undefined1 *)(iVar1 + -0x7d);
  *(undefined1 *)(iVar2 + 5) = 1;
  return;
}


// ===== FUN_0100088e @ 0100088e

void FUN_0100088e(void)

{
  byte *pbVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  
  iVar5 = DAT_01000a1c;
  if (*(char *)(DAT_01000a1c + 4) != '\0') {
    *(undefined1 *)(DAT_01000a1c + 4) = 0;
    puVar6 = (ushort *)(DAT_01000a10 + -0x80);
    if (*(char *)(iVar5 + 3) == '\0') {
      iVar5 = (uint)*puVar6 + DAT_01000a28;
      if (iVar5 == 0) {
        FUN_0100084e();
        return;
      }
      if (iVar5 == 0x200) {
        FUN_010007f2();
        return;
      }
    }
    else {
      uVar4 = 0;
      do {
        pbVar1 = (byte *)((int)puVar6 + uVar4);
        uVar4 = uVar4 + 1 & 0xff;
        *(uint *)(iVar5 + 0x10) = (uint)*pbVar1 + *(int *)(iVar5 + 0x10);
        iVar2 = DAT_01000a18;
      } while (uVar4 < 0x40);
      FUN_01002420((uint)*(ushort *)(iVar5 + 8) * 0x40 + DAT_01000a18,DAT_01000a10 + -0x80,0x40);
      FUN_01000728((uint)*(ushort *)(iVar5 + 8) * 0x40 + iVar2,DAT_01000a10 + -0x80);
      sVar3 = *(short *)(iVar5 + 8) + 1;
      *(short *)(iVar5 + 8) = sVar3;
      if (*(short *)(iVar5 + 6) == sVar3) {
        *(undefined1 *)(iVar5 + 3) = 0;
      }
      *(undefined4 *)(iVar5 + 0x18) = 0;
    }
  }
  return;
}


// ===== FUN_0100090e @ 0100090e

undefined4 FUN_0100090e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_01000a66();
  FUN_01000414(5,1);
  FUN_01000414(0xffffffff);
  FUN_010023a0(DAT_01000a24,DAT_01000a10 + -0xa0,0x20);
  iVar2 = DAT_01000a1c;
  *(undefined1 *)(DAT_01000a1c + 1) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  if ((((*(char *)(DAT_01000a10 + -0xa0) == -1) && (*(char *)(DAT_01000a10 + -0x9f) == -1)) &&
      (*(char *)(DAT_01000a10 + -0x9e) == -1)) && (*(char *)(DAT_01000a10 + -0x9d) == -1)) {
    FUN_010002f8();
    return 0;
  }
  FUN_01001d9a(0);
  FUN_01000c28();
  FUN_01002268(DAT_01000a2c,0x50000);
  iVar3 = DAT_01000a30;
  iVar1 = DAT_01000a14;
  *(undefined1 *)(DAT_01000a14 + 0x54) = 0;
  uVar4 = FUN_0100206c(DAT_01000a34,(*(uint *)(iVar3 + 0x20) & 0xf) + 2);
  FUN_0100206c(uVar4,1000);
  FUN_01001f54();
  do {
    do {
      FUN_0100088e();
      FUN_010007c0(*(undefined1 *)(iVar1 + 0x54));
      FUN_010007a6();
      FUN_01000752();
    } while (*(char *)(iVar2 + 2) == '\0');
    *(undefined1 *)(iVar2 + 2) = 0;
    FUN_01000f00();
    FUN_01000cb8();
  } while( true );
}


// ===== FUN_01000a3c @ 01000a3c

uint FUN_01000a3c(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    uVar2 = (uint)*(byte *)(param_2 + iVar1) ^ (param_1 >> 8 | param_1 << 8);
    uVar2 = (uVar2 & 0xff) >> 4 ^ uVar2;
    uVar2 = uVar2 << 0xc ^ uVar2;
    param_1 = (uVar2 & 0xff) << 5 ^ uVar2 & 0xffff;
  }
  return param_1;
}


// ===== FUN_01000a66 @ 01000a66

void FUN_01000a66(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 uStack00000000;
  undefined1 uStack00000004;
  undefined1 uStack0000000c;
  undefined1 uStack00000010;
  undefined1 uStack00000014;
  undefined1 uStack00000018;
  undefined1 uStack00000028;
  int aiStack_214 [128];
  
  uVar9 = DAT_01000bf8;
  iVar7 = DAT_01000bf0;
  iVar12 = DAT_01000bf0 + 0x200;
  iVar2 = DAT_01000bf0 + 0x200;
  iVar3 = DAT_01000bf0 + 0x200;
  iVar10 = DAT_01000bf0 + 0x200;
  iVar4 = DAT_01000bf0 + 0x200;
  iVar5 = DAT_01000bf0 + 0x200;
  iVar6 = DAT_01000bf0 + 0x200;
  uVar11 = *DAT_01000bf4;
  uVar13 = DAT_01000bf4[1];
  *(undefined4 *)(&uStack0000000c + DAT_01000bf0) = 0;
  *(undefined4 *)((int)aiStack_214 + DAT_01000bf0 + 0x20c) = uVar13;
  *(undefined4 *)((int)aiStack_214 + DAT_01000bf0 + 0x208) = uVar11;
  puVar1 = &uStack00000018 + DAT_01000bf0;
  uVar14 = 0;
  *(undefined4 *)(&uStack00000010 + DAT_01000bf0) = DAT_01000bf8;
  FUN_0100251c(0x1000000,puVar1);
  *(undefined1 **)((int)aiStack_214 + iVar7 + 0x210) = &uStack00000028 + iVar7;
  FUN_0100251c(0x1000000);
  FUN_0100251c(DAT_01000bfc,(int)aiStack_214 + iVar10,8);
  FUN_0100251c(DAT_01000bfc,(int)aiStack_214 + DAT_01000c00 + iVar7 + 0x200,8);
  uVar9 = FUN_01000a3c(uVar9,puVar1,0x10);
  *(undefined4 *)(&uStack00000014 + iVar7) = uVar9;
  iVar10 = FUN_010020bc(puVar1,*(undefined4 *)((int)aiStack_214 + iVar7 + 0x210),0x10);
  if (iVar10 != 0) {
    return;
  }
  iVar10 = FUN_010020bc((int)aiStack_214 + iVar4,(int)aiStack_214 + DAT_01000c00 + iVar7 + 0x200,8);
  if (iVar10 != 0) {
    return;
  }
  if (*(int *)((int)aiStack_214 + iVar7 + 0x204) == *(int *)(&uStack00000014 + iVar7)) {
    iVar12 = *(int *)((int)aiStack_214 + iVar12);
    if (iVar12 == DAT_01000c04) {
      return;
    }
    if (iVar12 == 0) {
      return;
    }
  }
  FUN_01000f90(0,2,8);
  FUN_01000f90(0,1,9);
  *(undefined4 *)(&uStack00000000 + iVar7) = 0xe1000;
  *(undefined4 *)(&uStack00000004 + iVar7) = 0;
  *(undefined1 *)((int)aiStack_214 + iVar7 + 0x210) = 0;
  FUN_010016e2(0,(int)aiStack_214 + iVar7 + 0x210);
  FUN_010023a0(DAT_01000c08,&uStack0000000c + iVar7,4);
  *(undefined1 *)((int)aiStack_214 + iVar7 + 0x20c) = 0;
  if ((*(int *)(&uStack0000000c + iVar7) == 0) || (*(int *)(&uStack0000000c + iVar7) == -1)) {
    bVar8 = 2;
  }
  else {
    for (; uVar9 = DAT_01000bfc, uVar14 < *(uint *)(&uStack0000000c + iVar7);
        uVar14 = uVar14 + uVar15) {
      uVar15 = *(uint *)(&uStack0000000c + iVar7) - uVar14;
      if (0x1000 < uVar15) {
        uVar15 = 0x1000;
      }
      FUN_0100240a(uVar14 + DAT_01000c0c,puVar1,uVar15);
      uVar9 = FUN_01000a3c(*(undefined4 *)(&uStack00000010 + iVar7),puVar1,uVar15);
      *(undefined4 *)(&uStack00000010 + iVar7) = uVar9;
    }
    if (*(int *)(&uStack00000010 + iVar7) == 0) {
      *(undefined1 *)((int)aiStack_214 + iVar7 + 0x20c) = 0;
      *(int *)((int)aiStack_214 + iVar3) = DAT_01000c04;
    }
    else {
      *(byte *)((int)aiStack_214 + iVar7 + 0x20c) = *(byte *)((int)aiStack_214 + iVar7 + 0x20c) | 1;
      *(undefined4 *)((int)aiStack_214 + iVar2) = 0;
    }
    *(undefined4 *)((int)aiStack_214 + iVar7 + 0x204) = *(undefined4 *)(&uStack00000014 + iVar7);
    FUN_01002558(DAT_01000bfc);
    thunk_EXT_FUN_0000425c(10);
    FUN_01002580(uVar9,(int)aiStack_214 + iVar5,8);
    thunk_EXT_FUN_0000425c(10);
    iVar12 = (int)aiStack_214 + DAT_01000c00 + iVar7 + 0x200;
    FUN_0100251c(uVar9,iVar12,8);
    iVar12 = FUN_010020bc((int)aiStack_214 + iVar6,iVar12,8);
    if (iVar12 == 0) goto LAB_01000bba;
    bVar8 = *(byte *)((int)aiStack_214 + iVar7 + 0x20c) | 4;
  }
  *(byte *)((int)aiStack_214 + iVar7 + 0x20c) = bVar8;
LAB_01000bba:
  iVar12 = (int)aiStack_214 + iVar7 + 0x208;
  (*DAT_01000c10)(iVar12,5);
  FUN_010018b6(0,iVar12,7);
  thunk_EXT_FUN_0000425c(10);
  FUN_01001656(0);
  return;
}


// ===== FUN_01000c14 @ 01000c14

void FUN_01000c14(void)

{
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(DAT_01000f84 + 4) = 0;
  iVar1 = DAT_01000f88;
  uVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + uVar2) = 0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 100);
  return;
}


// ===== FUN_01000c28 @ 01000c28

ulonglong FUN_01000c28(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_01000c14();
  FUN_01000460(5);
  FUN_01000f90(1,0x20,9);
  FUN_01000f90(1,0x40,8);
  uVar1 = DAT_01000f8c;
  FUN_010016e2();
  FUN_010015a4(0,2,1);
  FUN_010019c0(0,1);
  return CONCAT44(uVar1,param_1) & 0xffffffffffffff00;
}


// ===== FUN_01000cb8 @ 01000cb8

void FUN_01000cb8(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar2 = DAT_01000f88;
  pbVar1 = DAT_01000f84;
  if ((*DAT_01000f84 & 1) != 0) {
    puVar4 = (undefined1 *)(DAT_01000f88 + 100);
    FUN_01001974(0,*puVar4);
    for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(iVar2 + 0x65); iVar3 = iVar3 + 1) {
      FUN_01001974(0,puVar4[iVar3 + 1]);
    }
    FUN_01001974(0,*(undefined1 *)(DAT_01000f88 + 0xb7));
    *pbVar1 = *pbVar1 & 0xfe;
  }
  return;
}


// ===== FUN_01000e7c @ 01000e7c
// decompile failed
// ===== FUN_01000f00 @ 01000f00

void FUN_01000f00(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar2 = DAT_01000f88;
  cVar5 = '\0';
  pcVar7 = DAT_01000f88 + 0xb8;
  if (*pcVar7 == '\0') {
    return;
  }
  cVar1 = DAT_01000f88[0xb9];
  DAT_01000f88[0xb9] = cVar1 + 1U;
  if ((byte)(cVar1 + 1U) < 2) {
    return;
  }
  pcVar2[0xb9] = '\0';
  pcVar3 = DAT_01000f88;
  *pcVar7 = '\0';
  if (*pcVar3 == 'U') {
    iVar6 = *(int *)(DAT_01000f84 + 4);
    if (iVar6 - 3U == (uint)*(ushort *)(pcVar3 + 1)) {
      for (uVar4 = 1; uVar4 < iVar6 - 1U; uVar4 = uVar4 + 1) {
        cVar5 = pcVar3[uVar4] + cVar5;
      }
      if (pcVar3[iVar6 + -1] == cVar5) {
        pcVar2[0xba] = '\x01';
      }
    }
    pcVar2[0xbf] = '\0';
    if (pcVar2[0xba] != '\0') {
      pcVar2[0xba] = '\0';
      pcVar2[0xbe] = '\0';
      FUN_01000e7c();
      if (pcVar2[0xbe] == '\0') goto LAB_01000f76;
    }
    pcVar2[0xbf] = '\x01';
  }
LAB_01000f76:
  FUN_01000c14();
  return;
}


// ===== FUN_01000f90 @ 01000f90

void FUN_01000f90(uint param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (2 < param_1) {
    FUN_010006fc(s________________Librarier_sdk_yc__0100139c,0xe,DAT_01001398);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_010006fc(s________________Librarier_sdk_yc__0100139c,0xf,DAT_01001398);
  }
  iVar1 = DAT_010013c4;
  uVar2 = 0;
  do {
    if ((1 << (uVar2 & 0xff) & param_2) != 0) {
      *(undefined1 *)(param_1 * 0x10 + uVar2 + iVar1) = param_3;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}


// ===== FUN_01001306 @ 01001306

void FUN_01001306(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (2 < param_1) {
    FUN_010006fc(s________________Librarier_sdk_yc__0100139c,0x96,DAT_01001398 + 0x79,param_4,
                 param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_010006fc(s________________Librarier_sdk_yc__0100139c,0x97,DAT_01001398 + 0x79);
  }
  iVar1 = DAT_010013c4;
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


// ===== FUN_010013d6 @ 010013d6

void FUN_010013d6(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (2 < param_1) {
    FUN_010006fc(DAT_01001550,0xaa,DAT_0100154c,param_4,param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_010006fc(DAT_01001550,0xab,DAT_0100154c);
  }
  iVar1 = DAT_01001554;
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


// ===== FUN_01001478 @ 01001478

void FUN_01001478(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (2 < param_1) {
    FUN_010006fc(DAT_01001550,0xbe,DAT_0100154c + 0xd,param_4,param_4);
  }
  uVar2 = 0;
  do {
    uVar1 = 1 << (uVar2 & 0xff);
    if ((uVar1 & param_2) >> (uVar2 & 0xff) == 0) {
      FUN_01001306(param_1,uVar1 & 0xffff);
    }
    else {
      FUN_010013d6(param_1,uVar1 & 0xffff);
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}


// ===== FUN_010015a4 @ 010015a4

void FUN_010015a4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0xf3,DAT_0100192c + 0x73);
  }
  if ((param_2 != 1) && (param_2 != 2)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0xf4,DAT_0100192c + 0x73);
  }
  if (param_1 == 0) {
    iVar2 = DAT_01001958;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    iVar2 = DAT_0100195c;
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


// ===== FUN_01001612 @ 01001612

undefined4 FUN_01001612(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 == 0) {
    iVar2 = DAT_01001958;
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    iVar2 = DAT_0100195c;
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


// ===== FUN_01001642 @ 01001642

void FUN_01001642(void)

{
  undefined4 uVar1;
  undefined4 extraout_r3;
  
  uVar1 = FUN_01001612();
  FUN_010015a4(extraout_r3,uVar1,0);
  return;
}


// ===== FUN_01001656 @ 01001656

void FUN_01001656(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x41,DAT_0100192c + 0x15);
  }
  if (param_1 == 0) {
    iVar1 = DAT_01001958;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    iVar1 = DAT_0100195c;
  }
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}


// ===== FUN_010016e2 @ 010016e2

void FUN_010016e2(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x9a,DAT_0100192c + 0x31,param_4,
                 param_4);
  }
  if ((*param_2 != 0x40) && (*param_2 != 0)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x9b,DAT_0100192c + 0x31);
  }
  if ((*(uint *)(param_2 + 4) < 0x5b9) || (DAT_01001964 <= *(uint *)(param_2 + 4))) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x9c,DAT_0100192c + 0x31);
  }
  if ((param_2[10] != 0) && (param_2[10] != 2)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x9d,DAT_0100192c + 0x31);
  }
  if ((param_2[0xb] != 0) && (param_2[0xb] != 0x10)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x9e,DAT_0100192c + 0x31);
  }
  if ((param_2[9] != 0) && (param_2[9] != 8)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x9f,DAT_0100192c + 0x31);
  }
  iVar7 = FUN_0100206c(DAT_01001968,*(undefined4 *)(param_2 + 4));
  iVar6 = DAT_0100195c;
  iVar8 = DAT_01001958;
  bVar1 = param_2[10];
  bVar2 = param_2[8];
  bVar3 = param_2[0xb];
  bVar4 = param_2[9];
  bVar5 = *param_2;
  if (param_1 == 0) {
    *(undefined4 *)(DAT_01001958 + 0x1c) = 0;
    uVar9 = DAT_01001970;
  }
  else {
    *(undefined4 *)(DAT_0100195c + 0x1c) = 0;
    iVar8 = iVar6;
    uVar9 = DAT_0100196c;
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


// ===== FUN_010017e8 @ 010017e8

bool FUN_010017e8(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DAT_01001958;
  }
  else {
    if (param_1 != 1) {
      FUN_010006fc(s________________Librarier_sdk_yc__01001930,0xd7,DAT_0100192c + 0x4d);
    }
    iVar1 = DAT_0100195c;
  }
  return *(int *)(iVar1 + 0x28) >> 0x10 != 0;
}


// ===== FUN_0100185a @ 0100185a

uint FUN_0100185a(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x138,DAT_0100192c + 0x92,param_4,
                 param_4);
  }
  if (param_2 == 0) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x139,DAT_0100192c + 0x92);
  }
  if (param_1 == 0) {
    piVar2 = (int *)(DAT_01001958 + 0x28);
    puVar1 = (undefined1 *)(DAT_01001958 + 0x24);
  }
  else {
    piVar2 = (int *)(DAT_0100195c + 0x28);
    puVar1 = (undefined1 *)(DAT_0100195c + 0x24);
  }
  for (; (0 < *piVar2 >> 0x10 && (uVar3 < param_3)); uVar3 = uVar3 + 1) {
    *(undefined1 *)(param_2 + uVar3) = *puVar1;
  }
  return uVar3;
}


// ===== FUN_010018b6 @ 010018b6

void FUN_010018b6(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x158,DAT_0100192c + 0x9f);
  }
  if (param_2 == 0) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x159,DAT_0100192c + 0x9f);
  }
  if (DAT_01001960 <= param_3) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001930,0x15a,DAT_0100192c + 0x9f);
  }
  piVar2 = DAT_0100195c;
  piVar1 = DAT_01001958;
  if (param_1 == 0) {
    *DAT_01001958 = param_2;
    piVar1[2] = piVar1[2] & 0xffffU | param_3 << 0x10;
    *(undefined1 *)((int)piVar1 + 0xf) = 0x80;
    do {
    } while ((piVar1[4] & 1U) == 0);
    return;
  }
  *DAT_0100195c = param_2;
  piVar2[2] = piVar2[2] & 0xffffU | param_3 << 0x10;
  *(undefined1 *)((int)piVar2 + 0xf) = 0x80;
  do {
  } while ((piVar2[4] & 1U) == 0);
  return;
}


// ===== FUN_01001974 @ 01001974

void FUN_01001974(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_8 [4];
  
  puVar2 = DAT_01001a30;
  puVar1 = DAT_01001a2c;
  if (param_1 == 0) {
    *DAT_01001a30 = local_8;
    puVar2[2] = (puVar2[2] & 0xffff) + 0x10000;
    *(undefined1 *)((int)puVar2 + 0xf) = 0x80;
    do {
    } while ((puVar2[4] & 1) == 0);
    return;
  }
  *DAT_01001a2c = local_8;
  puVar1[2] = (puVar1[2] & 0xffff) + 0x10000;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  do {
  } while ((puVar1[4] & 1) == 0);
  return;
}


// ===== FUN_010019c0 @ 010019c0

void FUN_010019c0(int param_1,int param_2)

{
  if (param_1 == 0) {
    *(uint *)(DAT_01001a30 + 0x1c) = *(uint *)(DAT_01001a30 + 0x1c) & 0xffff00ff | param_2 << 8;
    return;
  }
  if (param_1 != 1) {
    FUN_010006fc(DAT_01001a38,0x18e,DAT_01001a34);
  }
  *(uint *)(DAT_01001a2c + 0x1c) = *(uint *)(DAT_01001a2c + 0x1c) & 0xffff00ff | param_2 << 8;
  return;
}


// ===== thunk_EXT_FUN_0000425c @ 01001a40

void thunk_EXT_FUN_0000425c(void)

{
                    /* WARNING: Could not recover jumptable at 0x01001a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_01001ca0 + 0x24))();
  return;
}


// ===== FUN_01001ae4 @ 01001ae4

void FUN_01001ae4(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (8 < param_1) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001ca8,0x35,DAT_01001ca4 + 0x11);
  }
  iVar1 = DAT_01001cd0;
  uVar2 = 4 << ((param_1 & 0x3f) << 2);
  if (param_2 == 1) {
    if (7 < param_1) {
      uVar2 = *(uint *)(DAT_01001cd0 + 0xc) | 4;
      goto LAB_01001b3a;
    }
    uVar2 = *(uint *)(DAT_01001cd0 + 8) | uVar2;
  }
  else {
    if (param_2 != 0) {
      FUN_010006fc(s________________Librarier_sdk_yc__01001ca8,0x36,DAT_01001ca4 + 0x11);
    }
    if (7 < param_1) {
      uVar2 = *(uint *)(iVar1 + 0xc) & 0xfffffffb;
LAB_01001b3a:
      *(uint *)(iVar1 + 0xc) = uVar2;
      return;
    }
    uVar2 = *(uint *)(iVar1 + 8) & ~uVar2;
  }
  *(uint *)(iVar1 + 8) = uVar2;
  return;
}


// ===== thunk_EXT_FUN_00004480 @ 01001cd8

void thunk_EXT_FUN_00004480(void)

{
                    /* WARNING: Could not recover jumptable at 0x01001cda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01001d38)();
  return;
}


// ===== thunk_EXT_FUN_0000442c @ 01001cdc

void thunk_EXT_FUN_0000442c(void)

{
                    /* WARNING: Could not recover jumptable at 0x01001ce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_01001d38 + -0x54))();
  return;
}


// ===== FUN_01001d82 @ 01001d82

void FUN_01001d82(uint param_1)

{
  *(uint *)(DAT_01001e64 + 0x1c) = *(uint *)(DAT_01001e64 + 0x1c) | 0x80;
  *(uint *)(DAT_01001e5c + 0x20) = *(uint *)(DAT_01001e5c + 0x20) & 0xfffffff0 | param_1;
  return;
}


// ===== FUN_01001d9a @ 01001d9a

void FUN_01001d9a(uint param_1)

{
  if (param_1 == 0) {
    (*DAT_01001e6c)(DAT_01001e68,DAT_01001e68 + 0x40);
    FUN_01001d82(0);
    return;
  }
  if (((param_1 != 2) && (param_1 != 6)) && (param_1 != 0xe)) {
    FUN_010006fc(s________________Librarier_sdk_yc__01001e30,0x1f,DAT_01001e2c + 0x2d);
  }
  *(uint *)(DAT_01001e5c + 0x20) = *(uint *)(DAT_01001e5c + 0x20) & 0xfffffff0 | param_1;
  return;
}


// ===== FUN_01001f54 @ 01001f54

void FUN_01001f54(uint param_1)

{
  int iVar1;
  
  if (DAT_01002060 < param_1) {
    FUN_010006fc(s________________Librarier_sdk_yc__01002020,0x42,DAT_0100201c + 0x22);
  }
  iVar1 = DAT_01002054;
  *(uint *)(DAT_01002054 + 0x10) = *(uint *)(DAT_01002054 + 0x10) & 0xfffffffe;
  *(uint *)(iVar1 + 0x14) = param_1 - 1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *DAT_01002064 = 0;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 7;
  return;
}


// ===== FUN_01001fa8 @ 01001fa8

undefined4 FUN_01001fa8(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_1 = *DAT_01002064 - param_1;
  if (param_1 < 0) {
    param_1 = param_1 + DAT_01002068;
  }
  uVar1 = FUN_0100206c(DAT_01002050,(*(uint *)(DAT_0100204c + 0x20) & 0xf) + 2);
  uVar1 = FUN_0100206c(uVar1,1000);
  uVar2 = FUN_0100206c(param_1 * *(int *)(DAT_01002054 + 0x14),uVar1);
  if (uVar2 < param_2) {
    return 0;
  }
  return 1;
}


// ===== FUN_0100206c @ 0100206c

int FUN_0100206c(uint param_1,uint param_2)

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


// ===== FUN_01002098 @ 01002098

void FUN_01002098(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_010020a6 @ 010020a6

void FUN_010020a6(undefined4 param_1,undefined4 param_2)

{
  FUN_01002098(param_1,param_2,0);
  return;
}


// ===== FUN_010020bc @ 010020bc

void FUN_010020bc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 < param_3 && (*(char *)(param_1 + uVar1) == *(char *)(param_2 + uVar1)));
      uVar1 = uVar1 + 1) {
  }
  return;
}


// ===== FUN_010020d6 @ 010020d6

uint FUN_010020d6(int param_1,undefined4 param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 3;
  pbVar1 = (byte *)(param_1 + 4);
  do {
    pbVar1 = pbVar1 + -1;
    param_3 = param_3 << 8 | (uint)*pbVar1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return param_3;
}


// ===== FUN_010020ec @ 010020ec

void FUN_010020ec(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = puRam0100210c;
  for (puVar3 = puRam01002108; puVar3 < puVar1; puVar3 = puVar3 + 4) {
    (*(code *)puVar3[3])(*puVar3,puVar3[1],puVar3[2]);
  }
  iVar2 = thunk_FUN_0100090e();
                    /* WARNING: Could not recover jumptable at 0x01002116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01002118)(iVar2 << 8);
  return;
}


// ===== thunk_EXT_FUN_000000c6 @ 01002110

void thunk_EXT_FUN_000000c6(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x01002116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01002118)(param_1);
  return;
}


// ===== __ARM_common_switch8 @ 0100211c

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
                    /* WARNING: Could not recover jumptable at 0x01002134. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_lr + (uint)*(byte *)(unaff_lr + uVar1) * 2))();
  return;
}


// ===== thunk_FUN_0100213e @ 01002136

void thunk_FUN_0100213e(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_0100213e @ 0100213e

void FUN_0100213e(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_01002154 @ 01002154

undefined8 FUN_01002154(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 local_20;
  
  puVar1 = DAT_010021dc;
  uVar5 = 1;
  uVar2 = DAT_010021dc[7];
  iVar3 = 5;
  uVar4 = (uVar2 & 0xffffff) >> 0x10;
  local_20 = CONCAT13((char)param_1,
                      CONCAT12((char)((uint)param_1 >> 8),
                               CONCAT11((char)((uint)param_1 >> 0x10),
                                        (char)((uVar2 & 0xffffff) >> 0x10))));
  if ((uVar4 != 0xbb) && ((uVar4 < 0xbc || ((uVar4 != 0xe7 && (uVar4 != 0xeb)))))) {
    iVar3 = 4;
  }
  DAT_010021dc[7] = uVar2 & DAT_010021e0;
  *puVar1 = &local_20;
  puVar1[1] = param_3;
  puVar1[2] = iVar3 << 0x10 | param_2;
  *(undefined1 *)(puVar1 + 3) = 0;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x20;
  *(byte *)((int)puVar1 + 0xf) = *(byte *)((int)puVar1 + 0xf) & 0xdf;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  iVar3 = 0;
  do {
    if ((puVar1[4] & 1) != 0) goto LAB_010021d2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10001);
  uVar5 = 0;
LAB_010021d2:
  puVar1[7] = uVar2;
  return CONCAT44(local_20,uVar5);
}


// ===== FUN_010021e4 @ 010021e4

undefined4 FUN_010021e4(int param_1,uint param_2,int param_3)

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
  FUN_010020a6(auStack_124,0x104);
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
    (*DAT_01002260)(auStack_124,2,uVar5 * 0x100 + local_20);
    for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
      local_120[uVar2] = *(undefined1 *)(local_18 + uVar5 * 0x100 + uVar2);
    }
    iVar3 = (*(DAT_01002260 + -0x14))();
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = (*DAT_01002264)(auStack_124,uVar4 + 4);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = (*(DAT_01002260 + -0xa4))();
    if (iVar3 == 0) break;
    param_2 = param_2 - uVar4;
    uVar5 = uVar5 + 1;
  }
  return 0;
}


// ===== FUN_01002268 @ 01002268

undefined4 FUN_01002268(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int aiStack_214 [128];
  
  iVar3 = DAT_01002344;
  iVar1 = DAT_01002344 + 0x200;
  iVar2 = DAT_01002344 + 0x200;
  iVar5 = (int)aiStack_214 + DAT_01002344 + 0x204;
  FUN_010020a6(iVar5,0x1000);
  if (param_2 != 0) {
    uVar7 = ((param_1 & 0xffffff) >> 0xf) * 0x9000 | 0x1000000;
    uVar6 = ((param_1 & 0xffffff) + param_2 + DAT_01002348 >> 0xf) * 0x9000 + 0x1000 | 0x1000000;
    FUN_0100251c(uVar7,iVar5,0x10);
    iVar4 = FUN_01002558(uVar7);
    if ((iVar4 == 1) && (iVar4 = FUN_01002580(uVar7,iVar5,0x10), iVar4 == 1)) {
      *(uint *)((int)aiStack_214 + iVar1) = uVar6 - 0x1000;
      FUN_0100251c(uVar6 - 0x1000,iVar5,0x1000);
      iVar5 = 0;
      do {
        *(undefined1 *)((int)aiStack_214 + iVar5 + iVar3 + 0x204) = 0xff;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x10);
      do {
        uVar7 = uVar7 + 0x1000;
        if ((uVar7 & 0x7fff) == 0) {
          while( true ) {
            if (uVar6 < uVar7 + 0x8000) {
              while( true ) {
                if (uVar6 <= uVar7) {
                  iVar5 = FUN_01002580(*(undefined4 *)((int)aiStack_214 + iVar2),
                                       (int)aiStack_214 + iVar3 + 0x204,0x1000);
                  if (iVar5 == 1) {
                    return 1;
                  }
                  return 0;
                }
                iVar5 = FUN_01002558(uVar7);
                if (iVar5 != 1) break;
                uVar7 = uVar7 + 0x1000;
              }
              return 0;
            }
            iVar5 = FUN_010024f4(uVar7);
            if (iVar5 != 1) break;
            uVar7 = uVar7 + 0x8000;
          }
          return 0;
        }
        iVar5 = FUN_01002558(uVar7);
      } while (iVar5 == 1);
    }
  }
  return 0;
}


// ===== FUN_0100234c @ 0100234c

void FUN_0100234c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint local_14;
  
  local_14 = param_4;
  FUN_0100048a();
  local_14 = 0;
  disableIRQinterrupts();
  thunk_EXT_FUN_0000442c();
  (*DAT_01002398)(param_1,&local_14,0,0,0);
  thunk_EXT_FUN_00004480();
  local_14 = local_14 << 0x18 | (local_14 >> 8 & 0xff) << 0x10 | (local_14 >> 0x10 & 0xff) << 8 |
             local_14 >> 0x18;
  uVar1 = FUN_010024a8();
  thunk_EXT_FUN_00004404(DAT_0100239c,DAT_0100239c + 0xb2);
  FUN_010025ac(local_14);
  FUN_0100245c(uVar1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_010023a0 @ 010023a0

void FUN_010023a0(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  FUN_0100048a();
  disableIRQinterrupts();
  uVar4 = 0x20 - (param_1 & 0x1f);
  if (param_3 < uVar4) {
    uVar4 = param_3;
  }
  iVar3 = 0;
  while (param_3 != 0) {
    iVar1 = FUN_0100247c(param_1,uVar4);
    if (iVar1 == 0) {
      thunk_EXT_FUN_00004404(param_1,param_1 + uVar4);
      for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
        *(undefined1 *)(param_2 + iVar3) = *(undefined1 *)(param_1 + uVar2);
        iVar3 = iVar3 + 1;
      }
    }
    else {
      FUN_01002098(param_2 + iVar3,uVar4,0xff);
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


// ===== FUN_0100240a @ 0100240a

void FUN_0100240a(undefined4 param_1,undefined4 param_2)

{
  disableIRQinterrupts();
  (*(code *)&SUB_000001d8)(param_2,param_1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_01002420 @ 01002420

void FUN_01002420(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0100048a();
  disableIRQinterrupts();
  uVar1 = FUN_010024a8();
  thunk_EXT_FUN_0000442c();
  (*DAT_01002458)(param_1,param_2,param_3,1,0);
  thunk_EXT_FUN_00004480();
  FUN_0100245c(uVar1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_0100245c @ 0100245c

void FUN_0100245c(uint param_1)

{
  thunk_EXT_FUN_00004404(DAT_01002478,DAT_01002478 + 0x40);
  FUN_01002640(param_1 & 0xffffff80,param_1 & 0xf);
  return;
}


// ===== FUN_0100247c @ 0100247c

undefined4 FUN_0100247c(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_0100048a();
  disableIRQinterrupts();
  thunk_EXT_FUN_0000442c();
  uVar1 = (*DAT_010024a4)(param_1 & 0xffffffe0,param_1 + param_2);
  thunk_EXT_FUN_00004480();
  enableIRQinterrupts();
  return uVar1;
}


// ===== FUN_010024a8 @ 010024a8

uint FUN_010024a8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = *(uint *)(DAT_010024e4 + 0x20) & 0xf;
  if ((*(uint *)(DAT_010024e0 + 0x1c) & 0x80) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = uVar2 | uVar1;
  thunk_EXT_FUN_00004404(DAT_010024e8,DAT_010024e8 + 0x40);
  if (uVar1 == 0) {
    uVar1 = 2;
  }
  FUN_01002640(0,uVar1);
  return uVar2;
}


// ===== thunk_EXT_FUN_00004404 @ 010024ec

void thunk_EXT_FUN_00004404(void)

{
                    /* WARNING: Could not recover jumptable at 0x010024ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_010024f0)();
  return;
}


// ===== FUN_010024f4 @ 010024f4

undefined4 FUN_010024f4(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0100048a();
  disableIRQinterrupts();
  uVar1 = FUN_010024a8();
  uVar2 = (*DAT_01002518)(param_1);
  FUN_0100245c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_0100251c @ 0100251c

undefined4 FUN_0100251c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0100048a();
  disableIRQinterrupts();
  uVar1 = FUN_010024a8();
  thunk_EXT_FUN_00004404(DAT_01002554,DAT_01002554 + 0x100);
  uVar2 = FUN_01002154(param_1,param_3,param_2);
  FUN_0100245c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_01002558 @ 01002558

undefined4 FUN_01002558(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0100048a();
  disableIRQinterrupts();
  uVar1 = FUN_010024a8();
  uVar2 = (*DAT_0100257c)(param_1);
  FUN_0100245c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_01002580 @ 01002580

undefined4 FUN_01002580(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0100048a();
  disableIRQinterrupts();
  uVar1 = FUN_010024a8();
  uVar2 = FUN_010021e4(param_1,param_3,param_2);
  FUN_0100245c(uVar1);
  enableIRQinterrupts();
  return uVar2;
}


// ===== FUN_010025ac @ 010025ac

void FUN_010025ac(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  undefined1 auStack_94 [128];
  
  iVar2 = DAT_01002634;
  iVar1 = DAT_01002634 + 0x80;
  FUN_010020a6(auStack_94 + DAT_01002634 + 0x80,0x1000);
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
    (*DAT_01002638)(param_1,0x1000,auStack_94 + iVar1);
    (*(DAT_01002638 + -0x42))(param_1);
    for (iVar4 = 0; iVar4 < (int)(uVar3 & 0xff); iVar4 = iVar4 + 1) {
      auStack_94[uVar6 + iVar4 + iVar2 + 0x80] = 0xff;
    }
    (*DAT_0100263c)(param_1,0x1000);
    param_1 = param_1 + 0x1000;
    uVar6 = 0;
    uVar3 = 0x24 - (uVar3 & 0xff);
    cVar5 = cVar5 + -1;
  }
  return;
}


// ===== FUN_01002640 @ 01002640

void FUN_01002640(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_01002664 + 0x1c) & 0xffffff7f;
  }
  else {
    uVar1 = *(uint *)(DAT_01002664 + 0x1c) | 0x80;
  }
  *(uint *)(DAT_01002664 + 0x1c) = uVar1;
  *(uint *)(DAT_01002668 + 0x20) = *(uint *)(DAT_01002668 + 0x20) & 0xfffffff0 | param_2 & 0xf;
  return;
}


