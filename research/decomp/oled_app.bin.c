// ===== thunk_FUN_0101046c @ 01010408

void thunk_FUN_0101046c(void)

{
  (*DAT_0101040c)();
  return;
}


// ===== FUN_01010418 @ 01010418

ulonglong FUN_01010418(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_01013ed8(5);
  FUN_0101247c(1,0x20,9);
  FUN_0101247c(1,0x40,8);
  uVar1 = DAT_0101064c;
  FUN_01012bca();
  FUN_01012a8c(0,2,1);
  FUN_01012ea4(0,1);
  return CONCAT44(uVar1,param_1) & 0xffffffffffffff00;
}


// ===== FUN_01010458 @ 01010458

void FUN_01010458(void)

{
  FUN_01013ca0(0x1d);
  FUN_01013cdc(0);
  FUN_01013cce();
  return;
}


// ===== FUN_0101046c @ 0101046c

void FUN_0101046c(void)

{
  int iVar1;
  char *pcVar2;
  
  FUN_010138da(0);
  FUN_01010458();
  FUN_01013536();
  FUN_01010418();
  FUN_01013734(DAT_01010650);
  FUN_01010e5c();
  FUN_01013f88();
  FUN_01014314();
  iVar1 = DAT_01010654;
  *(undefined1 *)(DAT_01010654 + 0x18) = 0;
  *(undefined1 *)(iVar1 + 7) = 0x3f;
  pcVar2 = DAT_01010658;
  do {
    do {
      FUN_01013cc4();
    } while (*pcVar2 == '\0');
    *pcVar2 = '\0';
    FUN_010141fe();
    FUN_0101427e();
    FUN_0101195c();
    FUN_010140a8();
    FUN_01014314();
    FUN_01011860();
    FUN_010118d2();
    FUN_01011232();
    FUN_010112fa();
    FUN_0101149c();
    FUN_01011b20();
  } while( true );
}


// ===== FUN_01010678 @ 01010678

void FUN_01010678(undefined4 param_1)

{
  *(undefined1 *)(DAT_01010a60 + 9) = 0x3f;
  FUN_01013df4(1,param_1);
  return;
}


// ===== FUN_010106ac @ 010106ac

void FUN_010106ac(undefined4 param_1)

{
  *(undefined1 *)(DAT_01010a60 + 9) = 0x3e;
  FUN_01013df4(1,param_1);
  return;
}


// ===== FUN_010106be @ 010106be

void FUN_010106be(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 + param_3) - 1;
  uVar2 = (param_2 + param_4) - 1;
  FUN_010106ac(0x2b);
  FUN_01010678((param_1 & 0xffff) >> 8);
  FUN_01010678(param_1 & 0xff);
  FUN_01010678((uVar1 & 0xffff) >> 8);
  FUN_01010678(uVar1 & 0xff);
  FUN_010106ac(0x2a);
  FUN_01010678((param_2 & 0xffff) >> 8);
  FUN_01010678(param_2 & 0xff);
  FUN_01010678((uVar2 & 0xffff) >> 8);
  FUN_01010678(uVar2 & 0xff);
  FUN_010106ac(0x2c);
  return;
}


// ===== FUN_01010714 @ 01010714

void FUN_01010714(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    FUN_010106be();
    for (uVar1 = 0; uVar1 < (uint)(param_4 * param_3); uVar1 = uVar1 + 1) {
      FUN_01010678(param_5 >> 8);
      FUN_01010678(param_5 & 0xff);
    }
  }
  return;
}


// ===== FUN_01010742 @ 01010742

void FUN_01010742(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  
  pbVar2 = DAT_01010a68;
  iVar1 = DAT_01010a64;
  local_1c = param_3;
  local_18 = param_4;
  FUN_0101247c(*DAT_01010a68,*(undefined2 *)(DAT_01010a64 + 0x10),0,param_4,param_2);
  iVar3 = (uint)*pbVar2 * 0x10 + DAT_01010a60;
  *(undefined1 *)(iVar3 + 8) = 0x3e;
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x12),0);
  *(undefined1 *)(iVar3 + 9) = 0x3f;
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x18),0);
  *(undefined1 *)(iVar3 + 0xc) = 0x3f;
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x16),0);
  *(undefined1 *)(iVar3 + 0xb) = 0x3f;
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x14),0);
  *(undefined1 *)(iVar3 + 10) = 0x3f;
  local_1c = 0x102000;
  local_18 = CONCAT31(local_18._1_3_,1);
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x18),0x18);
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x16),0x19);
  FUN_0101247c(*pbVar2,*(undefined2 *)(iVar1 + 0x14),0x1a);
  FUN_01013d4c(1,&local_1c);
  *(undefined1 *)(DAT_01010a60 + 8) = 0x3f;
  thunk_EXT_FUN_0000425c(10);
  *(undefined1 *)(DAT_01010a60 + 8) = 0x3e;
  thunk_EXT_FUN_0000425c(10);
  *(undefined1 *)(DAT_01010a60 + 8) = 0x3f;
  thunk_EXT_FUN_0000425c(1);
  FUN_010106ac(0x11);
  thunk_EXT_FUN_0000425c(10);
  FUN_010106ac(0x36);
  FUN_01010678(0x20);
  FUN_010106ac(0x3a);
  FUN_01010678(5);
  FUN_010106ac(0xb2);
  FUN_01010678(0x1f);
  FUN_01010678(0x1f);
  FUN_01010678(0);
  FUN_01010678(0x33);
  FUN_01010678(0x33);
  FUN_010106ac(0xb7);
  FUN_01010678(0x12);
  FUN_010106ac(0xbb);
  FUN_01010678(0x35);
  FUN_010106ac(0xc0);
  FUN_01010678(0x2c);
  FUN_01010678(0xc2);
  FUN_01010678(1);
  FUN_010106ac(0xc3);
  FUN_01010678(0x15);
  FUN_010106ac(0xc4);
  FUN_01010678(0x20);
  FUN_010106ac(0xc6);
  FUN_01010678(0x13);
  FUN_010106ac(0xd0);
  FUN_01010678(0xa4);
  FUN_01010678(0xa1);
  FUN_010106ac(0xd6);
  FUN_01010678(0xa1);
  FUN_010106ac(0xe0);
  FUN_01010678(0xf0);
  FUN_01010678(6);
  FUN_01010678(0xd);
  FUN_01010678(0xb);
  FUN_01010678(10);
  FUN_01010678(7);
  FUN_01010678(0x2e);
  FUN_01010678(0x43);
  FUN_01010678(0x45);
  FUN_01010678(0x38);
  FUN_01010678(0x14);
  FUN_01010678(0x13);
  FUN_01010678(0x25);
  FUN_01010678(0x29);
  FUN_010106ac(0xe1);
  FUN_01010678(0xf0);
  FUN_01010678(7);
  FUN_01010678(10);
  FUN_01010678(8);
  FUN_01010678(7);
  FUN_01010678(0x23);
  FUN_01010678(0x2e);
  FUN_01010678(0x33);
  FUN_01010678(0x44);
  FUN_01010678(0x3a);
  FUN_01010678(0x16);
  FUN_01010678(0x17);
  FUN_01010678(0x26);
  FUN_01010678(0x2c);
  FUN_010106ac(0xe4);
  FUN_01010678(0x1d);
  FUN_01010678(0);
  FUN_01010678(0);
  FUN_010106ac(0x21);
  FUN_010106ac(0x2a);
  FUN_01010678(0);
  FUN_01010678(0);
  FUN_01010678(0);
  FUN_01010678(0xef);
  FUN_010106ac(0x2b);
  FUN_01010678(0);
  FUN_01010678(0);
  FUN_01010678(0);
  FUN_01010678(0xef);
  FUN_010106ac(0x2c);
  FUN_01010714(0,0,0xf0,0xf0,0);
  thunk_EXT_FUN_0000425c(10);
  FUN_010106ac(0x29);
  return;
}


// ===== FUN_010109d4 @ 010109d4

void FUN_010109d4(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_30;
  
  local_30 = param_3 * (param_4 >> 3);
  if ((param_4 & 7) == 0) {
    uVar3 = param_4;
  }
  else {
    local_30 = local_30 + param_3;
    uVar3 = (param_4 & 0xfffffff8) + 8;
  }
  FUN_010106be(param_1,param_2,param_3,param_4);
  iVar4 = param_2;
  for (uVar1 = 0; uVar1 < local_30; uVar1 = uVar1 + 1) {
    iVar5 = 0;
    uVar6 = (uint)*(byte *)(param_6 + uVar1);
    do {
      if ((uint)(iVar4 - param_2) < param_4) {
        if ((int)(uVar6 << 0x18) < 0) {
          FUN_01010678(param_5 >> 8);
          uVar2 = param_5 & 0xff;
        }
        else {
          FUN_01010678(0);
          uVar2 = 0;
        }
        FUN_01010678(uVar2);
      }
      iVar4 = iVar4 + 1;
      if (iVar4 - param_2 == uVar3) {
        iVar4 = param_2;
      }
      uVar6 = (uVar6 & 0x7f) << 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
  }
  return;
}


// ===== FUN_01010a6c @ 01010a6c

void FUN_01010a6c(int param_1,int param_2,int param_3,uint param_4,undefined4 param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_30;
  int local_24;
  
  local_30 = param_3 * (param_4 >> 3);
  if ((param_4 & 7) == 0) {
    uVar3 = param_4;
  }
  else {
    local_30 = local_30 + param_3;
    uVar3 = (param_4 & 0xfffffff8) + 8;
  }
  FUN_010106be(param_1,param_2,param_3,param_4);
  uVar4 = 0;
  iVar7 = param_2;
  local_24 = param_1;
  do {
    iVar2 = DAT_01010e48;
    if (local_30 <= uVar4) {
      return;
    }
    iVar8 = 0;
    uVar9 = (uint)*(byte *)(param_6 + uVar4);
    do {
      if (*(char *)(iVar2 + 0x1f) != '\0') {
        return;
      }
      if ((uint)(iVar7 - param_2) < param_4) {
        if ((int)(uVar9 << 0x18) < 0) {
          iVar5 = local_24 * 4 + DAT_01010e4c;
          bVar1 = *(byte *)(iVar5 + -0x91);
          uVar6 = (uint)(*(byte *)(iVar5 + -0x92) >> 2) << 5;
          FUN_01010678(((uint)(*(byte *)(iVar5 + -0x93) >> 3) << 0xb | uVar6) >> 8);
          uVar6 = uVar6 & 0xff | (uint)(bVar1 >> 3);
        }
        else {
          FUN_01010678(0);
          uVar6 = 0;
        }
        FUN_01010678(uVar6);
      }
      iVar7 = iVar7 + 1;
      if (iVar7 - param_2 == uVar3) {
        local_24 = local_24 + 1;
        iVar7 = param_2;
      }
      uVar9 = (uVar9 & 0x7f) << 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    uVar4 = uVar4 + 1;
  } while( true );
}


// ===== FUN_01010bf6 @ 01010bf6

void FUN_01010bf6(undefined4 param_1,uint param_2,int param_3,uint param_4,uint param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_30;
  
  local_30 = param_3 * (param_4 >> 3);
  if ((param_4 & 7) == 0) {
    uVar3 = param_4;
  }
  else {
    local_30 = local_30 + param_3;
    uVar3 = (param_4 & 0xfffffff8) + 8;
  }
  FUN_010106be(param_1,param_2,param_3,param_4);
  uVar4 = param_2;
  for (uVar1 = 0; uVar1 < local_30; uVar1 = uVar1 + 1) {
    iVar5 = 0;
    uVar6 = (uint)*(byte *)(param_7 + local_30 * (param_6 + -0x20) + uVar1);
    do {
      if (uVar4 - param_2 < param_4) {
        if ((int)(uVar6 << 0x18) < 0) {
          FUN_01010678(param_5 >> 8);
          uVar2 = param_5 & 0xff;
        }
        else {
          FUN_01010678(0);
          uVar2 = 0;
        }
        FUN_01010678(uVar2);
      }
      uVar4 = uVar4 + 1 & 0xff;
      if (uVar4 - param_2 == uVar3) {
        uVar4 = param_2;
      }
      uVar6 = (uVar6 & 0x7f) << 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
  }
  return;
}


// ===== FUN_01010c8c @ 01010c8c

void FUN_01010c8c(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 char *param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  iVar2 = param_3;
  for (; *param_6 != '\0'; param_6 = param_6 + 1) {
    FUN_01010bf6(param_1,param_2,param_3,param_4,param_5,*param_6,param_7,uVar1,param_2,iVar2);
    param_1 = param_1 + param_3 & 0xff;
  }
  return;
}


// ===== FUN_01010dc0 @ 01010dc0

void FUN_01010dc0(char *param_1,uint param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  
LAB_01010e3a:
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
LAB_01010dea:
      param_1[1] = (char)uVar1;
    }
    else {
      param_1[1] = -1;
LAB_01010e2e:
      *param_1 = '\x01';
    }
  }
  if (cVar2 == '\x01') {
    if ((uint)(byte)param_1[2] + param_3 < 0xff) {
      param_1[2] = (char)((uint)(byte)param_1[2] + param_3);
      uVar1 = (uint)(byte)param_1[1] - param_3;
      goto LAB_01010dea;
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
          goto LAB_01010e2e;
        }
        param_1[1] = (char)((uint)(byte)param_1[1] + param_3);
        param_1[3] = param_1[3] - (char)param_3;
      }
      goto LAB_01010e3a;
    }
    if ((uint)(byte)param_1[3] + param_3 < 0xff) {
      param_1[3] = (char)((uint)(byte)param_1[3] + param_3);
      param_1[2] = param_1[2] - (char)param_3;
      goto LAB_01010e3a;
    }
    param_1[3] = -1;
    param_1[2] = '\0';
    cVar2 = '\x03';
  }
  *param_1 = cVar2;
  goto LAB_01010e3a;
}


// ===== FUN_01010e5c @ 01010e5c

void FUN_01010e5c(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  int iVar3;
  undefined4 local_18;
  
  local_18 = in_r3;
  FUN_01010742();
  FUN_0101465a(DAT_0101125c,DAT_01011258);
  iVar1 = DAT_01011260;
  *(undefined1 *)(DAT_01011260 + 9) = 1;
  *(undefined1 *)(iVar1 + 0x20) = 1;
  iVar3 = 0;
  local_18 = *(undefined4 *)PTR_DAT_01011264;
  do {
    FUN_01010dc0(&local_18,9,1);
    iVar2 = (0x55 - iVar3) * 4 + iVar1 + 0x34;
    *(undefined1 *)(iVar2 + 4) = (undefined1)local_18;
    *(undefined1 *)(iVar2 + 5) = local_18._1_1_;
    *(undefined1 *)(iVar2 + 6) = local_18._2_1_;
    iVar3 = iVar3 + 1;
    *(undefined1 *)(iVar2 + 7) = local_18._3_1_;
  } while (iVar3 < 0x56);
  FUN_01013cc4();
  return;
}


// ===== FUN_01010eb6 @ 01010eb6

void FUN_01010eb6(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0101125c;
  if (((*(char *)(DAT_01011260 + -4) != '\0') && (*(char *)(DAT_0101125c + 10) == '\x04')) &&
     (*(byte *)(*(int *)(DAT_0101125c + 0x2c) + DAT_0101125c + 0x57) <=
      *(byte *)(DAT_0101125c + 0x2b))) {
    *(undefined1 *)(DAT_0101125c + 0x2b) = 0;
    uVar2 = *(int *)(iVar1 + 0x34) + 1;
    *(uint *)(iVar1 + 0x34) = uVar2;
    if (*(byte *)(*(int *)(iVar1 + 0x2c) + iVar1 + 0x5d) <= uVar2) {
      *(undefined4 *)(iVar1 + 0x34) = 0;
    }
    *(undefined1 *)(DAT_01011260 + 0xb) = 1;
  }
  return;
}


// ===== FUN_01011232 @ 01011232
// decompile failed
// ===== FUN_010112d2 @ 010112d2

void FUN_010112d2(void)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = DAT_010116cc;
  if ((*(char *)(DAT_010116cc + 0x18) == '\x01') &&
     (bVar2 = *(char *)(DAT_010116cc + 0x1a) + 1, *(byte *)(DAT_010116cc + 0x1a) = bVar2,
     0x1f < bVar2)) {
    *(undefined1 *)(iVar1 + 0x1a) = 0;
    bVar2 = *(char *)(iVar1 + 0x19) + 1;
    *(byte *)(iVar1 + 0x19) = bVar2;
    if (100 < bVar2) {
      *(undefined1 *)(iVar1 + 0x19) = 0;
    }
  }
  return;
}


// ===== FUN_010112fa @ 010112fa

void FUN_010112fa(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = DAT_010116cc;
  if (*(char *)(DAT_010116d0 + 0x1d) != '\0') {
    uVar2 = 0x7e0;
    if (*(char *)(DAT_010116cc + 0x18) == '\x01') {
      FUN_01010714(0xb2,0xd,4,0xc,0x7e0);
      FUN_01010714(0xb6,7,0x36,2,0x7e0);
      FUN_01010714(0xb6,0x1d,0x36,2,0x7e0);
      FUN_01010714(0xb6,9,2,0x14,0x7e0);
      FUN_01010714(0xea,9,2,0x14,0x7e0);
      FUN_01010714(0xea - (uint)(*(byte *)(iVar1 + 0x19) >> 1),9,*(byte *)(iVar1 + 0x19) >> 1,0x14,
                   0x7e0);
      uVar3 = (uint)(*(byte *)(iVar1 + 0x19) >> 1);
    }
    else {
      uVar3 = (uint)*(byte *)(DAT_010116cc + 0x15);
      if (*(char *)(DAT_010116cc + 0x18) == '\x02') {
        uVar3 = 100;
      }
      else if (uVar3 < 0x3c) {
        if (uVar3 < 0x15) {
          uVar2 = 0xf800;
        }
        else {
          uVar2 = DAT_010116d4;
        }
      }
      FUN_01010714(0xb2,0xd,4,0xc,uVar2);
      FUN_01010714(0xb6,7,0x36,2,uVar2);
      FUN_01010714(0xb6,0x1d,0x36,2,uVar2);
      FUN_01010714(0xb6,9,2,0x14,uVar2);
      FUN_01010714(0xea,9,2,0x14,uVar2);
      uVar3 = uVar3 >> 1;
      FUN_01010714(0xea - uVar3,9,uVar3,0x14,uVar2);
    }
    FUN_01010714(0xb8,9,0x32 - uVar3,0x14,0);
  }
  return;
}


// ===== FUN_01011400 @ 01011400

void FUN_01011400(void)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_010116d0;
  uVar4 = *(int *)(DAT_010116d0 + 0x18) + 1;
  *(uint *)(DAT_010116d0 + 0x18) = uVar4;
  if (299 < uVar4) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    bVar2 = FUN_010145c4(2);
    *(byte *)(iVar1 + 0xc) = bVar2 & 0x7f;
    bVar2 = FUN_010145c4(3);
    *(byte *)(iVar1 + 0xd) = bVar2 & 0x7f;
    bVar2 = FUN_010145c4(4);
    *(byte *)(iVar1 + 0xe) = bVar2 & 0x3f;
    bVar2 = FUN_010145c4(5);
    *(byte *)(iVar1 + 0xf) = bVar2 & 0x3f;
    bVar2 = FUN_010145c4(7);
    *(byte *)(iVar1 + 0x10) = bVar2 & 0x1f;
    FUN_010145c4(8);
    iVar5 = FUN_010145fc();
    iVar6 = FUN_01014620(*(undefined4 *)(iVar1 + 0x14),100);
    *(int *)(iVar1 + 0x14) = iVar6 * 100 + iVar5;
    uVar3 = FUN_010145fc(*(undefined1 *)(iVar1 + 0x10));
    *(undefined1 *)(iVar1 + 0x10) = uVar3;
    uVar3 = FUN_010145fc(*(undefined1 *)(iVar1 + 0xf));
    *(undefined1 *)(iVar1 + 0xf) = uVar3;
    uVar3 = FUN_010145fc(*(undefined1 *)(iVar1 + 0xe));
    *(undefined1 *)(iVar1 + 0xe) = uVar3;
    uVar3 = FUN_010145fc(*(undefined1 *)(iVar1 + 0xd));
    *(undefined1 *)(iVar1 + 0xd) = uVar3;
    uVar3 = FUN_010145fc(*(undefined1 *)(iVar1 + 0xc));
    *(undefined1 *)(iVar1 + 0xc) = uVar3;
    *(undefined1 *)(iVar1 + 0x1c) = 1;
  }
  return;
}


// ===== FUN_0101149c @ 0101149c

void FUN_0101149c(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  
  iVar5 = DAT_010116d0;
  if ((*(char *)(DAT_010116d0 + 0x1c) != '\0') && (*(char *)(DAT_010116d0 + 0x1d) != '\0')) {
    *(undefined1 *)(DAT_010116d0 + 0x1c) = 0;
    uVar1 = *(undefined1 *)(iVar5 + 0xe);
    uVar2 = *(undefined1 *)(iVar5 + 0xd);
    uVar10 = *(uint *)(iVar5 + 0x14);
    uVar12 = (uint)*(byte *)(iVar5 + 0x10);
    bVar3 = *(byte *)(iVar5 + 0xf);
    if ((uVar12 == 1) || (uVar9 = uVar12, uVar11 = uVar10, uVar12 == 2)) {
      uVar9 = uVar12 + 0xc & 0xff;
      uVar11 = uVar10 - 1;
    }
    iVar5 = FUN_01014620((uVar9 + 1) * 3,5);
    iVar6 = FUN_01014620(uVar11,400);
    iVar7 = FUN_01014620(uVar11,100);
    FUN_01014620((iVar5 + uVar9 * 2 + (uint)bVar3 + uVar11 + (uVar11 >> 2) + iVar6) - iVar7,7);
    uVar4 = DAT_010116d8;
    FUN_01010714(0,0x42,0xf0,1,DAT_010116d8);
    FUN_01010714(0xa2,0x43,1,0xad,uVar4);
    FUN_01010714(0xa8,100,0x48,1,uVar4);
    FUN_01010714(0xa8,0xaa,0x48,1,uVar4);
    uVar13 = FUN_01014620(uVar10,1000);
    iVar6 = DAT_010116e0;
    iVar5 = DAT_010116dc;
    FUN_01010bf6(10,0x24,0xe,0x1c,uVar4,*(undefined1 *)(DAT_010116dc + (int)uVar13),DAT_010116e0);
    uVar13 = FUN_01014620((int)((ulonglong)uVar13 >> 0x20),100);
    FUN_01010bf6(0x18,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)uVar13),iVar6);
    uVar13 = FUN_01014620((int)((ulonglong)uVar13 >> 0x20),10);
    FUN_01010bf6(0x26,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)uVar13),iVar6);
    FUN_01010bf6(0x34,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)((ulonglong)uVar13 >> 0x20)),
                 iVar6);
    FUN_01010bf6(0x42,0x24,0xe,0x1c,uVar4,0x2f,iVar6);
    uVar13 = FUN_01014620(uVar12,10);
    FUN_01010bf6(0x50,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)uVar13),iVar6);
    FUN_01010bf6(0x5e,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)((ulonglong)uVar13 >> 0x20)),
                 iVar6);
    FUN_01010bf6(0x6c,0x24,0xe,0x1c,uVar4,0x2f,iVar6);
    uVar13 = FUN_01014620((uint)bVar3,10);
    FUN_01010bf6(0x7a,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)uVar13),iVar6);
    FUN_01010bf6(0x8c,0x24,0xe,0x1c,uVar4,*(undefined1 *)(iVar5 + (int)((ulonglong)uVar13 >> 0x20)),
                 iVar6);
    uVar13 = FUN_01014620(uVar1,10);
    iVar5 = DAT_010116e4;
    FUN_010109d4(10,5,0x10,0x20,uVar4,(int)uVar13 * 0x40 + DAT_010116e4);
    FUN_010109d4(0x1a,5,0x10,0x20,uVar4,(int)((ulonglong)uVar13 >> 0x20) * 0x40 + iVar5);
    FUN_010109d4(0x2a,5,0x10,0x20,uVar4,DAT_010116e8);
    uVar13 = FUN_01014620(uVar2,10);
    FUN_010109d4(0x3a,5,0x10,0x20,uVar4,(int)uVar13 * 0x40 + iVar5);
    FUN_010109d4(0x4a,5,0x10,0x20,uVar4,(int)((ulonglong)uVar13 >> 0x20) * 0x40 + iVar5);
    FUN_010109d4(100,0x10,0x48,0x10,uVar4,extraout_r1 * 0x90 + DAT_01011aec);
    iVar7 = DAT_01011af0;
    FUN_010109d4(0xda,0x82,0x18,0x18,uVar4,(uint)*(byte *)(DAT_01011af0 + 2) * 0x48 + iVar6 + -0x90)
    ;
    FUN_010109d4(0xaa,0x69,0x20,0x10,uVar4,DAT_01011af4);
    if (*(byte *)(iVar7 + 1) < 100) {
      iVar8 = FUN_01014620(*(undefined1 *)(iVar7 + 1),100);
      uVar14 = 0;
    }
    else {
      iVar8 = FUN_01014620(*(undefined1 *)(iVar7 + 1),100);
      uVar14 = uVar4;
    }
    FUN_010109d4(0xaa,0x87,0x10,0x20,uVar14,iVar8 * 0x40 + iVar5);
    FUN_01014620(*(undefined1 *)(iVar7 + 1),100);
    if ((extraout_r1_00 < 10) &&
       ((FUN_01014620(*(undefined1 *)(iVar7 + 1),100), 9 < extraout_r1_01 ||
        (*(byte *)(iVar7 + 1) < 100)))) {
      FUN_01014620(*(undefined1 *)(iVar7 + 1),100);
      iVar8 = FUN_01014620(extraout_r1_03,10);
      uVar14 = 0;
    }
    else {
      FUN_01014620(*(undefined1 *)(iVar7 + 1),100);
      iVar8 = FUN_01014620(extraout_r1_02,10);
      uVar14 = uVar4;
    }
    FUN_010109d4(0xba,0x87,0x10,0x20,uVar14,iVar8 * 0x40 + iVar5);
    FUN_01014620(*(undefined1 *)(iVar7 + 1),100);
    FUN_01014620(extraout_r1_04,10);
    FUN_010109d4(0xca,0x87,0x10,0x20,uVar4,extraout_r1_05 * 0x40 + iVar5);
    FUN_01010c8c(0xaa,0xaf,0xe,0x1c,uVar4,&DAT_01011af8,iVar6);
    if (*(byte *)(iVar7 + 3) < 10) {
      iVar6 = FUN_01014620(*(undefined1 *)(iVar7 + 3),10);
      uVar14 = 0;
    }
    else {
      iVar6 = FUN_01014620(*(undefined1 *)(iVar7 + 3),10);
      uVar14 = uVar4;
    }
    FUN_010109d4(0xaa,0xcb,0x10,0x20,uVar14,iVar6 * 0x40 + iVar5);
    FUN_01014620(*(undefined1 *)(iVar7 + 3),10);
    FUN_010109d4(0xba,0xcb,0x10,0x20,uVar4,extraout_r1_06 * 0x40 + iVar5);
    FUN_010109d4(0xca,0xcb,0x10,0x20,uVar4,DAT_01011aec + -0x40);
  }
  return;
}


// ===== FUN_01011860 @ 01011860

void FUN_01011860(void)

{
  int iVar1;
  undefined4 in_r3;
  int iVar2;
  
  iVar1 = DAT_01011af0;
  if ((((*(char *)(DAT_01011afc + 10) == '\0') && (*(char *)(DAT_01011afc + 0x17) == '\x01')) &&
      (*(char *)(DAT_01011af0 + -0x24) != '\0')) && (*(char *)(DAT_01011af0 + -3) != '\0')) {
    *(undefined1 *)(DAT_01011af0 + 4) = 0;
    if (*(char *)(iVar1 + 5) != *(char *)(iVar1 + 4)) {
      *(undefined1 *)(iVar1 + 5) = *(undefined1 *)(iVar1 + 4);
      FUN_01010714(0,0x43,0xa2,0xad,0,in_r3);
    }
    iVar1 = DAT_01011af0;
    iVar2 = 0;
    do {
      FUN_01010dc0(iVar2 * 4 + iVar1 + 0x18,1,4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x56);
    FUN_01010a6c(0x26,0x74,0x55,0x48,DAT_01011b04,DAT_01011b00);
  }
  return;
}


// ===== FUN_010118d2 @ 010118d2

void FUN_010118d2(void)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = DAT_01011b0c;
  uVar3 = DAT_01011b08;
  puVar2 = DAT_01011afc;
  if (*(char *)(DAT_01011af0 + -0x24) != '\0') {
    cVar1 = *(char *)((int)DAT_01011afc + DAT_01011b0c + -3);
    if (*(char *)((int)DAT_01011afc + 0x17) == '\x01') {
      if (((cVar1 != '\0') && (*(char *)((int)DAT_01011afc + 10) != (char)DAT_01011afc[3])) &&
         (uVar5 = *DAT_01011afc, *DAT_01011afc = uVar5 + 1, uVar3 <= uVar5 + 1)) {
        *puVar2 = 0;
        *(char *)((int)puVar2 + 10) = (char)puVar2[3];
        *(char *)((int)puVar2 + iVar4 + 4) = (char)puVar2[3];
        FUN_01010714(0,0x43,0xa2,0xad,0);
        *(undefined1 *)((int)puVar2 + iVar4 + -1) = 0;
      }
    }
    else if (((cVar1 != '\0') &&
             ((*(char *)((int)DAT_01011afc + 10) != '\x01' ||
              (*(char *)((int)DAT_01011afc + *(byte *)((int)DAT_01011afc + 10) + 5) != '\0')))) &&
            (uVar5 = *DAT_01011afc, *DAT_01011afc = uVar5 + 1, uVar3 <= uVar5 + 1)) {
      *puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 10) = 1;
      *(undefined1 *)((int)puVar2 + *(byte *)((int)puVar2 + 10) + 5) = 0;
      *(undefined1 *)((int)puVar2 + iVar4 + 4) = 10;
      *(undefined1 *)((int)puVar2 + iVar4 + -0x15) = 1;
      return;
    }
  }
  return;
}


// ===== FUN_0101195c @ 0101195c

void FUN_0101195c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  int iVar6;
  int extraout_r1;
  int extraout_r1_00;
  undefined4 uVar7;
  
  uVar4 = DAT_01011b14;
  iVar3 = DAT_01011b10;
  uVar2 = DAT_01011b04;
  iVar1 = DAT_01011afc;
  if ((*(char *)(DAT_01011af0 + -0x24) == '\0') && (*(char *)(DAT_01011af0 + -3) != '\0')) {
    if (*(char *)(DAT_01011afc + 0x2a) != '\0') {
      *(undefined1 *)(DAT_01011afc + 0x2a) = 0;
      FUN_01010714(0,0x43,0xa2,0xad,0,param_3,param_4);
      FUN_01010714(0,0x8c,0x66,1,uVar2);
      FUN_01010714(0,0xa1,0x66,1,uVar2);
      FUN_01010714(0,0x8d,1,0x14,uVar2);
      FUN_01010714(0x65,0x8d,1,0x14,uVar2);
      FUN_01014620(*(undefined1 *)(iVar1 + 0x28),10);
      FUN_01010bf6(0x83,0x8e,0xe,0x1c,uVar2,*(undefined1 *)(iVar3 + extraout_r1),uVar4);
      param_3 = 0x25;
      param_4 = uVar4;
      FUN_01010bf6(0x91,0x8e,0xe,0x1c,uVar2,0x25,uVar4);
    }
    if (*(char *)(iVar1 + 0x29) != '\0') {
      *(undefined1 *)(iVar1 + 0x29) = 0;
      uVar5 = FUN_01014620(*(int *)(DAT_01011afc + 0x20) * 100,*(undefined4 *)(DAT_01011afc + 0x1c))
      ;
      *(undefined1 *)(iVar1 + 0x28) = uVar5;
      FUN_01010714(1,0x8d,*(undefined1 *)(iVar1 + 0x28),0x14,uVar2,param_3,param_4);
      FUN_01010714(*(byte *)(iVar1 + 0x28) + 1,0x8d,100 - (uint)*(byte *)(iVar1 + 0x28),0x14,0);
      if (*(byte *)(iVar1 + 0x28) < 100) {
        FUN_01010bf6(0x67,0x8a,0xe,0x1c,0,0x20,uVar4);
        if (*(byte *)(iVar1 + 0x28) < 10) {
          uVar5 = 0x20;
          uVar7 = 0;
        }
        else {
          iVar6 = FUN_01014620(*(undefined1 *)(iVar1 + 0x28),10);
          uVar5 = *(undefined1 *)(iVar3 + iVar6);
          uVar7 = uVar2;
        }
        FUN_01010bf6(0x75,0x8a,0xe,0x1c,uVar7,uVar5,uVar4);
        FUN_01014620(*(undefined1 *)(iVar1 + 0x28),10);
        FUN_01010bf6(0x83,0x8a,0xe,0x1c,uVar2,*(undefined1 *)(iVar3 + extraout_r1_00),uVar4);
        FUN_01010bf6(0x91,0x8a,0xe,0x1c,uVar2,0x25,uVar4);
        return;
      }
      FUN_01010c8c(0x67,0x8a,0xe,0x1c,uVar2,&DAT_01011b18,uVar4);
    }
  }
  return;
}


// ===== FUN_01011b20 @ 01011b20

void FUN_01011b20(void)

{
  undefined4 in_r3;
  
  if ((*(char *)(DAT_01011b6c + 8) == '\0') || (*(char *)(DAT_01011b6c + -3) == '\0')) {
    if (*(char *)(DAT_01011b6c + 9) != '\0') {
      *(undefined1 *)(DAT_01011b6c + 9) = 0;
      FUN_01010714(0xbe,0x23,0x1b,0x18,0,in_r3);
      return;
    }
  }
  else {
    FUN_010109d4(0xbe,0x23,0x18,0x18,DAT_01011b74,
                 (uint)*(byte *)(DAT_01011b6c + 7) * 0x48 + DAT_01011b70);
  }
  return;
}


// ===== FUN_01011b78 @ 01011b78

void FUN_01011b78(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined4 *)(switchD_01011f46::caseD_7 + 4) = 0;
  uVar2 = uRam01011f60;
  iVar1 = iRam01011f5c;
  uVar3 = 0;
  do {
    *(undefined1 *)(iVar1 + uVar3) = 0;
    uVar3 = uVar3 + 1;
  } while (uVar3 < uVar2);
  return;
}


// ===== FUN_01011b8e @ 01011b8e

void FUN_01011b8e(void)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char local_38 [36];
  
  puVar2 = switchD_01011f46::caseD_d;
  pbVar1 = switchD_01011f46::caseD_7;
  if ((*switchD_01011f46::caseD_7 & 1) != 0) {
    FUN_01012e58(0,*switchD_01011f46::caseD_d);
    for (iVar4 = 0; iVar4 < (int)(uint)(byte)puVar2[1]; iVar4 = iVar4 + 1) {
      FUN_01012e58(0,puVar2[iVar4 + 1]);
    }
    FUN_01012e58(0,switchD_01011f46::caseD_d[0x53]);
    *pbVar1 = *pbVar1 & 0xfe;
    iVar4 = switchD_01011f46::caseD_f;
    if (*(char *)(switchD_01011f46::caseD_f + 0x11) != '\0') {
      *(undefined1 *)(switchD_01011f46::caseD_f + 0x11) = 0;
      *(undefined1 *)(iVar4 + 0x10) = 1;
    }
    if (*(char *)(switchD_01011f46::caseD_11 + 4) != '\0') {
      FUN_01013cc4();
      FUN_0101465a(local_38,0x20);
      uVar3 = switchD_01011f46::caseD_13;
      uVar5 = 0;
      while (((((local_38[0] != -0x56 || (local_38[1] != 'U')) || (local_38[2] != -0x56)) ||
              (local_38[3] != 'U')) && (uVar5 = uVar5 + 1, uVar5 < 1000))) {
        FUN_010146fc(uVar3);
        local_38[0] = -0x56;
        local_38[1] = 'U';
        local_38[2] = -0x56;
        local_38[3] = 'U';
        iVar4 = 4;
        do {
          local_38[iVar4] = -1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x20);
        FUN_010147bc(uVar3,local_38,0x20);
        FUN_01014750(uVar3,local_38,4);
      }
      if (uVar5 < 1000) {
        *(undefined1 *)(switchD_01011f46::caseD_15 + 8) = 0x3e;
        FUN_01013ef2();
      }
    }
  }
  return;
}


// ===== FUN_01011c6a @ 01011c6a

void FUN_01011c6a(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = switchD_01011f46::caseD_11;
  *(undefined1 *)(switchD_01011f46::caseD_11 + 0xe) = *param_2;
  *(undefined1 *)(iVar1 + 10) = 0;
  *(undefined1 *)(switchD_01011f46::caseD_f + -0x18) = 1;
  return;
}


// ===== FUN_01011c7e @ 01011c7e

void FUN_01011c7e(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined1 *)(switchD_01011f46::caseD_f + -0x24) = 0;
  iVar1 = switchD_01011f46::caseD_11;
  *(undefined4 *)(switchD_01011f46::caseD_11 + 0x24) = 0;
  *(undefined1 *)(iVar1 + 0x38) = *param_2;
  iVar2 = 0;
  iVar4 = iVar1 + iRam01011f78;
  param_2 = param_2 + 2;
  do {
    *(undefined1 *)(*(int *)(iVar1 + 0x70) * 0x1000 + iVar1 + iVar2 + 0x7c) = *param_2;
    *(uint *)(iVar4 + 4) =
         *(int *)(iVar4 + 4) +
         (uint)*(byte *)(*(int *)(iVar1 + 0x70) * 0x1000 + iVar1 + iVar2 + 0x7c);
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 1;
  } while (iVar2 < 0x1000);
  if (*(char *)(iVar1 + 0x3d) == '\x01') {
    uVar3 = (uint)*(byte *)(iVar1 + 0x38);
  }
  else {
    uVar3 = 5;
  }
  *(uint *)(iVar1 + 0x2c) = uVar3;
  *(int *)(iVar1 + 0x74) = *(int *)(iVar1 + 0x74) + 1;
  uVar3 = *(int *)(iVar1 + 0x70) + 1;
  *(uint *)(iVar1 + 0x70) = uVar3;
  if (9 < uVar3) {
    *(undefined4 *)(iVar1 + 0x70) = 0;
  }
  return;
}


// ===== FUN_01011cea @ 01011cea

void FUN_01011cea(void)

{
  int iVar1;
  
  iVar1 = switchD_01011f46::caseD_11;
  *(undefined1 *)(switchD_01011f46::caseD_11 + 0x2b) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined1 *)(switchD_01011f46::caseD_f + -0x18) = 1;
  return;
}


// ===== FUN_01011d00 @ 01011d00

void FUN_01011d00(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = switchD_01011f46::caseD_f;
  cVar1 = *(char *)((uint)*(byte *)(switchD_01011f46::caseD_11 + 10) +
                   switchD_01011f46::caseD_11 + 5);
  if (cVar1 == '\0') {
    *(undefined1 *)(switchD_01011f46::caseD_11 + 0xf) = *(undefined1 *)(param_2 + 2);
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(switchD_01011f46::caseD_11 + 0x10) = *(undefined1 *)(param_2 + 2);
  }
  else {
    if (cVar1 != '\x02') {
      return;
    }
    *(undefined1 *)(switchD_01011f46::caseD_11 + 0x11) = *(undefined1 *)(param_2 + 2);
  }
  *(undefined1 *)(iVar2 + -0x15) = 1;
  return;
}


// ===== FUN_01011d30 @ 01011d30

undefined1 FUN_01011d30(void)

{
  return *(undefined1 *)
          ((uint)*(byte *)(switchD_01011f46::caseD_11 + 10) + switchD_01011f46::caseD_11 + 5);
}


// ===== FUN_01011d3a @ 01011d3a

void FUN_01011d3a(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 extraout_r1;
  uint extraout_r1_00;
  
  piVar3 = switchD_01011f46::caseD_11;
  iVar2 = switchD_01011f46::caseD_f;
  bVar5 = *(byte *)((int)switchD_01011f46::caseD_11 + 10);
  cVar1 = *(char *)((int)switchD_01011f46::caseD_11 + bVar5 + 5);
  if (cVar1 == '\0') {
    if (((*(char *)((int)switchD_01011f46::caseD_11 + 0x16) != *(char *)(param_2 + 2)) ||
        (*(char *)((int)switchD_01011f46::caseD_11 + 0x17) != *(char *)(param_2 + 6))) ||
       (*(char *)((int)switchD_01011f46::caseD_11 + 0x12) != *(char *)(param_2 + 3))) {
      *(char *)((int)switchD_01011f46::caseD_11 + 0x16) = *(char *)(param_2 + 2);
      *(undefined1 *)((int)piVar3 + 0x12) = *(undefined1 *)(param_2 + 3);
      *(undefined1 *)((int)piVar3 + 0x15) = *(undefined1 *)(param_2 + 4);
      *(undefined1 *)(piVar3 + 6) = *(undefined1 *)(param_2 + 5);
      *(undefined1 *)((int)piVar3 + 0x17) = *(undefined1 *)(param_2 + 6);
      *(undefined1 *)(iVar2 + 1) = *(undefined1 *)(param_2 + 8);
      *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(param_2 + 9);
      if (*(char *)(iVar2 + 2) != *(char *)(param_2 + 0xc)) {
        *(char *)(iVar2 + 2) = *(char *)(param_2 + 0xc);
        *(undefined1 *)(iVar2 + -0x18) = 1;
      }
      *(undefined1 *)(iVar2 + -0x15) = 1;
      return;
    }
    if (*(char *)((int)switchD_01011f46::caseD_11 + 0x17) != '\x01') {
      return;
    }
    if (*(char *)((int)switchD_01011f46::caseD_11 + 0xb) != *(char *)(param_2 + 7)) {
      *(char *)((int)switchD_01011f46::caseD_11 + 0xb) = *(char *)(param_2 + 7);
      uVar7 = 0;
      if ((char)piVar3[3] == '\0') {
        while (*(char *)((int)piVar3 + uVar7 + 99) == '\0') {
          if (uVar7 == 5) {
            *(char *)((int)piVar3 + 10) = (char)piVar3[3];
            *piVar3 = 0;
          }
          uVar7 = uVar7 + 1;
          if (5 < (int)uVar7) {
            return;
          }
        }
LAB_01011e9c:
        *(undefined1 *)(piVar3 + 3) = 4;
        piVar3[0xb] = uVar7;
      }
      else {
        if ((piVar3[0xb] & 0xffU) != 5) {
          uVar7 = (piVar3[0xb] & 0xffU) + 1 & 0xff;
          do {
            if (5 < uVar7) {
              return;
            }
            if (*(char *)((int)piVar3 + uVar7 + 99) != '\0') goto LAB_01011e9c;
            uVar7 = uVar7 + 1 & 0xff;
          } while (uVar7 != 6);
        }
        *(undefined1 *)(piVar3 + 3) = 0;
      }
      *(undefined1 *)(iVar2 + -0x18) = 1;
      return;
    }
    if (*(char *)(switchD_01011f46::caseD_f + 8) != *(char *)(param_2 + 0xb)) {
      *(char *)(switchD_01011f46::caseD_f + 8) = *(char *)(param_2 + 0xb);
      *(undefined1 *)(iVar2 + 6) = *(undefined1 *)(param_2 + 10);
      *(undefined1 *)(iVar2 + 8) = 1;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      if (*(char *)(iVar2 + 6) == '\x02') {
        bVar5 = *(char *)(iVar2 + 7) + 1;
        *(byte *)(iVar2 + 7) = bVar5;
        if (4 < bVar5) {
          *(undefined1 *)(iVar2 + 7) = 0;
        }
      }
      else if ((*(char *)(iVar2 + 6) == '\x01') &&
              (bVar5 = *(char *)(iVar2 + 7) - 1, *(byte *)(iVar2 + 7) = bVar5, 4 < bVar5)) {
        *(undefined1 *)(iVar2 + 7) = 4;
      }
    }
    *(undefined1 *)((int)piVar3 + 0x15) = *(undefined1 *)(param_2 + 4);
    *(undefined1 *)(piVar3 + 6) = *(undefined1 *)(param_2 + 5);
    *(undefined1 *)(iVar2 + 1) = *(undefined1 *)(param_2 + 8);
    *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(param_2 + 9);
    if (*(char *)(iVar2 + 2) != *(char *)(param_2 + 0xc)) {
      *(char *)(iVar2 + 2) = *(char *)(param_2 + 0xc);
      *(undefined1 *)(iVar2 + -0x18) = 1;
    }
    if (*piVar3 != 0) {
      return;
    }
    *(char *)((int)piVar3 + 10) = (char)piVar3[3];
    *(char *)(iVar2 + 4) = (char)piVar3[3];
  }
  else {
    if (cVar1 == '\x01') {
      *(undefined1 *)((int)switchD_01011f46::caseD_11 + 0x15) = *(undefined1 *)(param_2 + 2);
      return;
    }
    if (cVar1 != '\x02') {
      return;
    }
    *(undefined4 *)(switchD_01011f46::caseD_f + -8) = 0;
    uVar4 = *(undefined1 *)(param_2 + 2);
    *(uint *)(iVar2 + -0xc) = (uint)*(ushort *)(param_2 + 2);
    *(undefined1 *)(iVar2 + -0x10) = *(undefined1 *)(param_2 + 4);
    *(undefined1 *)(iVar2 + -0x11) = *(undefined1 *)(param_2 + 5);
    *(undefined1 *)(iVar2 + -0x12) = *(undefined1 *)(param_2 + 6);
    *(undefined1 *)(iVar2 + -0x13) = *(undefined1 *)(param_2 + 7);
    *(undefined1 *)(iVar2 + -0x14) = *(undefined1 *)(param_2 + 8);
    FUN_01014620(*(undefined4 *)(iVar2 + -0xc),1000,uVar4,(uint)bVar5,param_4);
    FUN_01014620(extraout_r1,100);
    uVar6 = FUN_0101460c(extraout_r1_00 & 0xff);
    uVar4 = FUN_0101460c(*(undefined1 *)(iVar2 + -0x10));
    *(undefined1 *)(iVar2 + -0x10) = uVar4;
    uVar4 = FUN_0101460c(*(undefined1 *)(iVar2 + -0x11));
    *(undefined1 *)(iVar2 + -0x11) = uVar4;
    uVar4 = FUN_0101460c(*(undefined1 *)(iVar2 + -0x12));
    *(undefined1 *)(iVar2 + -0x12) = uVar4;
    uVar4 = FUN_0101460c(*(undefined1 *)(iVar2 + -0x13));
    *(undefined1 *)(iVar2 + -0x13) = uVar4;
    uVar4 = FUN_0101460c(*(undefined1 *)(iVar2 + -0x14));
    *(undefined1 *)(iVar2 + -0x14) = uVar4;
    FUN_01014596(0);
    FUN_01014596(1,0x11);
    FUN_01014596(2,*(undefined1 *)(iVar2 + -0x14));
    FUN_01014596(3,*(undefined1 *)(iVar2 + -0x13));
    FUN_01014596(4,*(undefined1 *)(iVar2 + -0x12));
    FUN_01014596(5,*(undefined1 *)(iVar2 + -0x11));
    FUN_01014596(7,*(undefined1 *)(iVar2 + -0x10));
    FUN_01014596(8,uVar6);
    *(undefined1 *)(iVar2 + -0x18) = 1;
  }
  *(undefined1 *)(iVar2 + -1) = 0;
  return;
}


// ===== FUN_01011f2a @ 01011f2a

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x01011f46) */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x01011f46) */
/* WARNING: Type propagation algorithm not settling */

void FUN_01011f2a(byte *param_1,byte *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte bVar10;
  byte *pbVar11;
  byte *unaff_r6;
  uint unaff_r7;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  uint *puVar16;
  undefined4 in_cr0;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr6;
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr13;
  undefined4 in_cr14;
  undefined4 in_cr15;
  undefined8 in_d0;
  undefined8 in_d1;
  undefined1 in_q12 [16];
  undefined8 in_d26;
  uint uStack_28;
  byte *pbStack_24;
  byte *pbStack_20;
  
  iVar5 = switchD_01011f46::caseD_11;
  puVar16 = (uint *)((int)register0x00000054 + -0x10);
  *(byte *)(switchD_01011f46::caseD_11 + 10) = *param_2;
  bVar10 = *(byte *)(iVar5 + 10);
  pbVar11 = (byte *)(uint)bVar10;
  pbVar11[iVar5 + 5] = param_2[1];
  bVar15 = SBORROW4(switchD_01011f46::caseD_f,0x20);
  pbVar9 = (byte *)(switchD_01011f46::caseD_f + -0x20);
  *(undefined1 *)(switchD_01011f46::caseD_f + -1) = 1;
  pbVar4 = DAT_01012380;
  pbVar7 = (byte *)(uint)*(byte *)(iVar5 + 10);
  bVar14 = pbVar7 == (byte *)0x0;
  bVar13 = false;
  pbVar6 = pbVar7;
  if ((byte *)(uint)bRam01011f4a <= pbVar7) {
    pbVar6 = (byte *)(uint)bRam01011f4a;
  }
  uVar8 = (uint)pbVar6[0x1011f4b] * 2;
  pbVar12 = (byte *)(uVar8 + 0x1011f4b);
  bVar2 = bVar14;
  switch(pbVar6[0x1011f4b]) {
  case 0:
  case 1:
switchD_01011f46_caseD_2:
switchD_01011f46_caseD_3:
switchD_01011f46_caseD_4:
    FUN_01011d3a();
switchD_01011f46_caseD_6:
    return;
  case 2:
    goto switchD_01011f46_caseD_2;
  case 3:
    goto switchD_01011f46_caseD_3;
  case 4:
    goto switchD_01011f46_caseD_4;
  case 5:
    coprocessor_movefromRt(0xd,7,3,in_cr2,in_cr0);
  case 7:
    param_1 = unaff_r6;
switchD_01011f46_caseD_8:
switchD_01011f46_caseD_9:
switchD_01011f46_caseD_a:
    pbVar7 = param_1;
switchD_01011f46_caseD_b:
    pbVar9 = (byte *)((int)pbVar9 >> 1);
switchD_01011f46_caseD_c:
    bVar13 = (int)param_1 < 0;
    bVar14 = param_1 == (byte *)0x0;
switchD_01011f46_caseD_d:
    bVar2 = pbVar9 != (byte *)0x0;
    pbVar9 = (byte *)0x0;
    if (bVar2) {
switchD_01011f46_caseD_e:
code_r0x01011f68:
code_r0x01011f6a:
code_r0x01011f6c:
      pbVar9 = (byte *)((int)param_2 << 1);
code_r0x01011f6e:
switchD_01011f46_caseD_13:
      param_1 = (byte *)((int)pbVar9 << 4);
switchD_01011f46_caseD_14:
      param_1 = (byte *)((int)param_1 << 4);
switchD_01011f46_caseD_15:
      *(short *)(param_1 + 0x38) = (short)param_1;
switchD_01011f46_caseD_16:
switchD_01011f46_caseD_17:
      param_1 = (byte *)0x101217c;
switchD_01011f46_caseD_18:
switchD_01011f46_caseD_19:
      FUN_01011d30(param_1);
switchD_01011f46_caseD_1b:
      return;
    }
switchD_01011f46_caseD_38:
    param_1 = (byte *)(uint)param_1[1];
switchD_01011f46_caseD_39:
    bVar2 = false;
    if (bVar14) {
switchD_01011f46_caseD_63:
      param_2 = param_2 + 4;
switchD_01011f46_caseD_64:
      FUN_01011c6a(param_1,param_2);
switchD_01011f46_caseD_66:
      param_1 = DAT_0101237c;
      goto switchD_01011f46_caseD_67;
    }
switchD_01011f46_caseD_3a:
    if (!bVar2 && bVar13 == bVar15) {
switchD_01011f46_caseD_40:
      param_1 = DAT_01012388;
switchD_01011f46_caseD_41:
      bVar14 = unaff_r7 == 0x23;
switchD_01011f46_caseD_42:
      if (bVar14) {
switchD_01011f46_caseD_8d:
        unaff_r6 = (byte *)0x1;
switchD_01011f46_caseD_8e:
        pbVar9[0x1d] = (byte)unaff_r6;
switchD_01011f46_caseD_8f:
        param_2 = DAT_01012378;
switchD_01011f46_caseD_90:
        param_2 = (byte *)(uint)param_2[4];
switchD_01011f46_caseD_91:
        param_1[0x1d] = (byte)param_2;
switchD_01011f46_caseD_92:
        param_2 = DAT_01012378;
switchD_01011f46_caseD_93:
        param_2 = (byte *)(uint)param_2[5];
switchD_01011f46_caseD_94:
        param_1[0x1e] = (byte)param_2;
switchD_01011f46_caseD_95:
        param_2 = DAT_01012378;
switchD_01011f46_caseD_96:
        param_2 = (byte *)(uint)*(ushort *)(param_2 + 6);
switchD_01011f46_caseD_97:
        *(byte **)pbVar9 = param_2;
switchD_01011f46_caseD_98:
        param_2 = DAT_01012378;
switchD_01011f46_caseD_99:
        param_2 = (byte *)(uint)param_2[8];
switchD_01011f46_caseD_9a:
        param_1[0x19] = (byte)param_2;
switchD_01011f46_caseD_9b:
        unaff_r6 = DAT_01012378;
switchD_01011f46_caseD_9c:
        unaff_r7 = (uint)unaff_r6[9];
switchD_01011f46_caseD_9d:
        param_1[0x1a] = (byte)unaff_r7;
switchD_01011f46_caseD_9e:
        unaff_r6 = (byte *)(uint)unaff_r6[10];
switchD_01011f46_caseD_9f:
        param_2 = unaff_r6 + -(int)param_2;
switchD_01011f46_caseD_a0:
        param_1[0x1b] = (byte)param_2;
switchD_01011f46_caseD_a1:
        param_2 = DAT_01012378;
switchD_01011f46_caseD_a2:
        param_2 = (byte *)(uint)param_2[0xb];
switchD_01011f46_caseD_a3:
        param_2 = param_2 + -unaff_r7;
switchD_01011f46_caseD_a4:
        param_1[0x1c] = (byte)param_2;
switchD_01011f46_caseD_a5:
        unaff_r6 = DAT_01012388;
switchD_01011f46_caseD_a6:
        unaff_r6 = unaff_r6 + 0xffffffe0;
switchD_01011f46_caseD_a7:
        *(byte **)(unaff_r6 + 0x6c) = pbVar11;
switchD_01011f46_caseD_a8:
        *(byte **)(unaff_r6 + 0x70) = pbVar11;
switchD_01011f46_caseD_a9:
        *(byte **)(unaff_r6 + 0x74) = pbVar11;
switchD_01011f46_caseD_aa:
        *(byte **)(unaff_r6 + 0x78) = pbVar11;
switchD_01011f46_caseD_ab:
        *(byte **)(pbVar9 + 4) = pbVar11;
switchD_01011f46_caseD_ac:
        param_2 = *(byte **)pbVar9;
switchD_01011f46_caseD_ad:
        bVar14 = ((uint)param_2 & 0xfff) == 0;
switchD_01011f46_caseD_ae:
        param_2 = *(byte **)pbVar9;
switchD_01011f46_caseD_af:
        if (bVar14) {
switchD_01011f46_caseD_b7:
          pbVar9 = (byte *)(uint)param_1[0x1d];
switchD_01011f46_caseD_b8:
          param_2 = (byte *)((uint)param_2 >> 0xc);
        }
        else {
switchD_01011f46_caseD_b0:
          param_2 = (byte *)((uint)param_2 >> 0xc);
switchD_01011f46_caseD_b1:
          pbVar9 = (byte *)(uint)param_1[0x1d];
switchD_01011f46_caseD_b2:
switchD_01011f46_caseD_b5:
          param_2 = param_2 + 1;
switchD_01011f46_caseD_b6:
        }
switchD_01011f46_caseD_b9:
        param_2 = (byte *)((int)pbVar9 * (int)param_2);
switchD_01011f46_caseD_ba:
        *(byte **)(unaff_r6 + 0x1c) = param_2;
switchD_01011f46_caseD_bb:
        *(byte **)(unaff_r6 + 0x20) = pbVar11;
switchD_01011f46_caseD_bc:
        param_1[8] = (byte)pbVar11;
switchD_01011f46_caseD_bd:
        param_2 = (byte *)0x1;
switchD_01011f46_caseD_be:
        param_1[10] = (byte)param_2;
switchD_01011f46_caseD_bf:
        param_1[9] = (byte)param_2;
switchD_01011f46_caseD_c0:
        *(byte **)(unaff_r6 + 0x24) = pbVar11;
switchD_01011f46_caseD_c1:
        param_1 = DAT_01012384;
switchD_01011f46_caseD_c2:
        param_1 = param_1 + 0xffffffc0;
switchD_01011f46_caseD_c3:
        param_1[0x1c] = (byte)pbVar11;
switchD_01011f46_caseD_c4:
        param_2 = DAT_01012380;
switchD_01011f46_caseD_c5:
        param_1 = (byte *)0x44;
switchD_01011f46_caseD_c6:
        param_2 = param_2 + 0xffffffac;
switchD_01011f46_caseD_c7:
        *param_2 = (byte)param_1;
switchD_01011f46_caseD_c8:
        pbVar9 = (byte *)0x3;
switchD_01011f46_caseD_c9:
        param_2[1] = (byte)pbVar9;
switchD_01011f46_caseD_ca:
        param_1 = (byte *)0xa3;
switchD_01011f46_caseD_cb:
        param_2[2] = (byte)param_1;
switchD_01011f46_caseD_cc:
        param_1 = pbVar12;
switchD_01011f46_caseD_cd:
        bVar14 = param_1 == (byte *)0x0;
switchD_01011f46_caseD_ce:
switchD_01011f46_caseD_d1:
        if (bVar14) {
switchD_01011f46_caseD_d5:
          param_2[3] = (byte)pbVar11;
        }
        else {
switchD_01011f46_caseD_d2:
          param_1 = (byte *)0x7f;
switchD_01011f46_caseD_d3:
          param_2[3] = (byte)param_1;
switchD_01011f46_caseD_d4:
        }
switchD_01011f46_caseD_d6:
        param_1 = (byte *)0x1;
switchD_01011f46_caseD_d7:
        pbVar7[0x13] = (byte)pbVar11;
switchD_01011f46_caseD_d8:
        pbVar9 = pbVar9 + 1;
switchD_01011f46_caseD_d9:
switchD_01011f46_caseD_df:
        while( true ) {
          bVar10 = (byte)pbVar11;
          bVar15 = SBORROW4((int)pbVar9,(int)param_1);
          bVar13 = (int)pbVar9 - (int)param_1 < 0;
          bVar14 = pbVar9 == param_1;
switchD_01011f46_caseD_e0:
          if (bVar14 || bVar13 != bVar15) break;
switchD_01011f46_caseD_da:
          unaff_r6 = (byte *)(uint)param_2[(int)param_1];
switchD_01011f46_caseD_db:
          pbVar11 = (byte *)(uint)bVar10;
switchD_01011f46_caseD_dc:
          pbVar11 = pbVar11 + (int)unaff_r6;
switchD_01011f46_caseD_dd:
          pbVar7[0x13] = (byte)pbVar11;
switchD_01011f46_caseD_de:
          param_1 = param_1 + 1;
        }
switchD_01011f46_caseD_e1:
        bVar10 = (byte)uVar8;
LAB_010122f6:
        *DAT_0101237c = bVar10;
        return;
      }
switchD_01011f46_caseD_43:
      bVar14 = unaff_r7 == 0x24;
switchD_01011f46_caseD_44:
      if (bVar14) {
switchD_01011f46_caseD_45:
switchD_01011f46_caseD_e2:
        param_2 = (byte *)0x1;
switchD_01011f46_caseD_e3:
        pbVar9[8] = (byte)param_2;
switchD_01011f46_caseD_e4:
        unaff_r6 = DAT_01012388;
switchD_01011f46_caseD_e5:
        param_2 = &Reset;
switchD_01011f46_caseD_e6:
        unaff_r6 = unaff_r6 + 0xffffffe0;
switchD_01011f46_caseD_e7:
        unaff_r6[0xc] = (byte)param_2;
switchD_01011f46_caseD_e8:
        unaff_r6 = (byte *)*puVar16;
switchD_01011f46_caseD_e9:
        param_2 = (byte *)0xff;
switchD_01011f46_caseD_ea:
        unaff_r6[4] = (byte)param_2;
switchD_01011f46_caseD_eb:
        unaff_r6[5] = (byte)param_2;
switchD_01011f46_caseD_ec:
        unaff_r6 = (byte *)(uint)param_1[0x19];
switchD_01011f46_caseD_ed:
        param_2 = DAT_01012388;
switchD_01011f46_caseD_ee:
        param_2 = param_2 + 0xffffffe0;
switchD_01011f46_caseD_ef:
        unaff_r7 = *(uint *)(param_2 + 0x2c);
switchD_01011f46_caseD_f0:
        param_2 = param_2 + 0x3f;
switchD_01011f46_caseD_f1:
        param_2[unaff_r7] = (byte)unaff_r6;
switchD_01011f46_caseD_f2:
        unaff_r6 = (byte *)(uint)param_1[0x1a];
switchD_01011f46_caseD_f3:
        param_2 = param_2 + -0x3f;
switchD_01011f46_caseD_f4:
        unaff_r7 = *(uint *)(param_2 + 0x2c);
switchD_01011f46_caseD_f5:
        param_2 = param_2 + 0x45;
switchD_01011f46_caseD_f6:
        param_2[unaff_r7] = (byte)unaff_r6;
switchD_01011f46_caseD_f7:
        unaff_r6 = (byte *)(uint)param_1[0x1b];
switchD_01011f46_caseD_f8:
        param_2 = param_2 + -0x45;
switchD_01011f46_caseD_f9:
        unaff_r7 = *(uint *)(param_2 + 0x2c);
switchD_01011f46_caseD_fa:
        param_2 = param_2 + 0x4b;
switchD_01011f46_caseD_fb:
        param_2[unaff_r7] = (byte)unaff_r6;
switchD_01011f46_caseD_fc:
        unaff_r6 = (byte *)(uint)param_1[0x1c];
switchD_01011f46_caseD_fd:
        param_2 = param_2 + -0x4b;
switchD_01011f46_caseD_fe:
        unaff_r7 = *(uint *)(param_2 + 0x2c);
switchD_01011f46_caseD_ff:
        bVar10 = (byte)uVar8;
        param_2[unaff_r7 + 0x51] = (byte)unaff_r6;
        param_2[*(int *)(param_2 + 0x2c) + 0x57] = param_1[0x1e];
        pbVar6 = DAT_01012388;
        DAT_01012388[*(int *)(DAT_01012388 + 0xc) + 0x3d] = param_1[0x1d];
        bVar3 = (byte)pbVar11;
        if (*(int *)(pbVar9 + 4) == 0) {
          pbVar6[*(int *)(DAT_01012388 + 0xc) + 0x43] = bVar3;
        }
        else {
          pbVar6[*(int *)(pbVar6 + 0xc) + 0x43] = 1;
        }
        pbVar6 = DAT_01012388;
        iVar5 = 0;
        do {
          if (*(int *)(pbVar6 + 0xc) == iVar5) {
            if (pbVar6[iVar5 + 0x43] == 0) {
              pbVar6[0xffffffec] = bVar3;
            }
            else {
              pbVar6[0xffffffec] = 4;
            }
          }
          pbVar9 = DAT_01012380;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 6);
        pbVar6 = DAT_01012380 + 0xffffffac;
        *pbVar6 = 0x44;
        pbVar9[-0x53] = 3;
        pbVar9[-0x52] = 0xa4;
        if (pbVar12 == (byte *)0x0) {
          pbVar9[-0x51] = bVar3;
        }
        else {
          pbVar9[-0x51] = 0x7f;
        }
        pbVar7[0x13] = bVar3;
        for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
          pbVar11 = (byte *)(((uint)pbVar11 & 0xff) + (uint)pbVar6[iVar5]);
          pbVar7[0x13] = (byte)pbVar11;
        }
        goto LAB_010122f6;
      }
switchD_01011f46_caseD_52:
      param_1 = DAT_01012380;
switchD_01011f46_caseD_53:
      param_1[6] = (byte)unaff_r6;
switchD_01011f46_caseD_54:
      return;
    }
switchD_01011f46_caseD_3b:
    bVar14 = unaff_r7 == 1;
switchD_01011f46_caseD_3c:
    if (bVar14) {
switchD_01011f46_caseD_55:
      param_2 = param_2 + 4;
switchD_01011f46_caseD_56:
      FUN_01011f2a(param_1,param_2);
switchD_01011f46_caseD_58:
      param_1 = DAT_0101237c;
      goto switchD_01011f46_caseD_59;
    }
switchD_01011f46_caseD_3d:
    bVar14 = unaff_r7 == 0x21;
switchD_01011f46_caseD_3e:
    if (!bVar14) goto switchD_01011f46_caseD_52;
switchD_01011f46_caseD_3f:
switchD_01011f46_caseD_5c:
    param_2 = param_2 + 4;
switchD_01011f46_caseD_5d:
    FUN_01011c7e(param_1,param_2);
switchD_01011f46_caseD_5f:
    param_1 = DAT_0101237c;
switchD_01011f46_caseD_60:
    pbVar7 = &NMI;
switchD_01011f46_caseD_61:
    param_2 = (byte *)(uint)*param_1;
switchD_01011f46_caseD_62:
    break;
  case 6:
    goto switchD_01011f46_caseD_6;
  case 8:
    goto switchD_01011f46_caseD_8;
  case 9:
    goto switchD_01011f46_caseD_9;
  case 10:
    goto switchD_01011f46_caseD_a;
  case 0xb:
    goto switchD_01011f46_caseD_b;
  case 0xc:
    goto switchD_01011f46_caseD_c;
  case 0xd:
    goto switchD_01011f46_caseD_d;
  case 0xe:
    goto switchD_01011f46_caseD_e;
  case 0xf:
    goto code_r0x01011f68;
  case 0x10:
    goto code_r0x01011f6a;
  case 0x11:
    goto code_r0x01011f6c;
  case 0x12:
    goto code_r0x01011f6e;
  case 0x13:
    goto switchD_01011f46_caseD_13;
  case 0x14:
    goto switchD_01011f46_caseD_14;
  case 0x15:
    goto switchD_01011f46_caseD_15;
  case 0x16:
    goto switchD_01011f46_caseD_16;
  case 0x17:
    goto switchD_01011f46_caseD_17;
  case 0x18:
    goto switchD_01011f46_caseD_18;
  case 0x19:
    goto switchD_01011f46_caseD_19;
  case 0x1a:
    coprocessor_function2(7,0xd,7,in_cr14,in_cr8,in_cr9);
  case 0x1c:
    FUN_01011d00();
switchD_01011f46_caseD_1e:
    return;
  case 0x1b:
    goto switchD_01011f46_caseD_1b;
  case 0x1d:
    coprocessor_function2(7,0xb,7,in_cr14,in_cr13,in_cr6);
  case 0x1f:
    FUN_01011cea();
switchD_01011f46_caseD_21:
    return;
  case 0x1e:
    goto switchD_01011f46_caseD_1e;
  case 0x20:
    coprocessor_function2(7,10,7,in_cr14,in_cr15,in_cr3);
  case 0x22:
    pbStack_20 = pbVar11;
    pbStack_24 = pbVar9;
    puVar16 = &uStack_28;
    uStack_28 = uVar8;
switchD_01011f46_caseD_23:
    param_1 = DAT_0101237c;
switchD_01011f46_caseD_24:
    param_2 = DAT_01012378;
switchD_01011f46_caseD_25:
    uVar8 = (uint)*param_1;
switchD_01011f46_caseD_26:
    param_1 = DAT_01012380;
switchD_01011f46_caseD_27:
    pbVar7 = DAT_01012380;
switchD_01011f46_caseD_28:
    param_1 = (byte *)(uint)param_1[7];
switchD_01011f46_caseD_29:
    unaff_r7 = (uint)param_2[3];
switchD_01011f46_caseD_2a:
    pbVar12 = param_1;
switchD_01011f46_caseD_2b:
    param_1 = DAT_01012384;
switchD_01011f46_caseD_2c:
    unaff_r6 = (byte *)0x1;
switchD_01011f46_caseD_2d:
    pbVar9 = param_1;
switchD_01011f46_caseD_2e:
    uVar8 = uVar8 | (uint)unaff_r6;
switchD_01011f46_caseD_2f:
    pbVar11 = (byte *)0x0;
switchD_01011f46_caseD_30:
    pbVar7 = pbVar7 + 0xffffffec;
switchD_01011f46_caseD_31:
    pbVar9 = pbVar9 + 0xffffffe0;
switchD_01011f46_caseD_32:
    *puVar16 = (uint)param_1;
switchD_01011f46_caseD_33:
    bVar15 = SBORROW4(unaff_r7,0x25);
    bVar13 = (int)(unaff_r7 - 0x25) < 0;
    bVar14 = unaff_r7 == 0x25;
switchD_01011f46_caseD_34:
    bVar2 = false;
    if (bVar14) {
switchD_01011f46_caseD_b3:
      bVar10 = (byte)uVar8;
      pbVar9[0x1d] = (byte)unaff_r6;
      pbVar6 = DAT_01012380;
      pbVar9 = DAT_01012380 + 0xffffffac;
      *pbVar9 = 0x44;
      pbVar6[-0x53] = 3;
      pbVar6[-0x52] = 0xa5;
      if (pbVar12 == (byte *)0x0) {
        pbVar6[-0x51] = (byte)pbVar11;
      }
      else {
        pbVar6[-0x51] = 0x7f;
      }
      pbVar7[0x13] = (byte)pbVar11;
      for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
        pbVar11 = (byte *)(((uint)pbVar11 & 0xff) + (uint)pbVar9[iVar5]);
        pbVar7[0x13] = (byte)pbVar11;
      }
      *(byte *)(*puVar16 + 0x11) = (byte)unaff_r6;
      goto LAB_010122f6;
    }
switchD_01011f46_caseD_35:
    if (bVar2 || bVar13 != bVar15) {
switchD_01011f46_caseD_36:
      param_1 = DAT_01012378;
switchD_01011f46_caseD_37:
      bVar15 = SBORROW4(unaff_r7,0x22);
      bVar13 = (int)(unaff_r7 - 0x22) < 0;
      bVar14 = unaff_r7 == 0x22;
      goto switchD_01011f46_caseD_38;
    }
switchD_01011f46_caseD_46:
    bVar15 = SBORROW4(unaff_r7,0x30);
    bVar13 = (int)(unaff_r7 - 0x30) < 0;
    bVar14 = unaff_r7 == 0x30;
switchD_01011f46_caseD_47:
    bVar2 = false;
    if (bVar14) {
switchD_01011f46_caseD_70:
      pbVar9[0x1d] = (byte)pbVar11;
switchD_01011f46_caseD_71:
      pbVar9[0x1e] = (byte)unaff_r6;
switchD_01011f46_caseD_72:
      param_2 = DAT_01012380;
switchD_01011f46_caseD_73:
      param_1 = (byte *)0x44;
switchD_01011f46_caseD_74:
      param_2 = param_2 + 0xffffffac;
switchD_01011f46_caseD_75:
      *param_2 = (byte)param_1;
switchD_01011f46_caseD_76:
      pbVar9 = (byte *)0x3;
switchD_01011f46_caseD_77:
      param_2[1] = (byte)pbVar9;
switchD_01011f46_caseD_78:
      param_1 = (byte *)0xb0;
switchD_01011f46_caseD_79:
      param_2[2] = (byte)param_1;
switchD_01011f46_caseD_7a:
      param_1 = pbVar12;
switchD_01011f46_caseD_7b:
      bVar14 = param_1 == (byte *)0x0;
switchD_01011f46_caseD_7c:
      if (bVar14) {
switchD_01011f46_caseD_80:
        param_2[3] = (byte)pbVar11;
      }
      else {
switchD_01011f46_caseD_7d:
        param_1 = (byte *)0x7f;
switchD_01011f46_caseD_7e:
        param_2[3] = (byte)param_1;
switchD_01011f46_caseD_7f:
      }
switchD_01011f46_caseD_81:
      param_1 = (byte *)0x1;
switchD_01011f46_caseD_82:
      pbVar7[0x13] = (byte)pbVar11;
switchD_01011f46_caseD_83:
      pbVar9 = pbVar9 + 1;
switchD_01011f46_caseD_84:
switchD_01011f46_caseD_8a:
      while( true ) {
        bVar10 = (byte)pbVar11;
        bVar15 = SBORROW4((int)pbVar9,(int)param_1);
        bVar13 = (int)pbVar9 - (int)param_1 < 0;
        bVar14 = pbVar9 == param_1;
switchD_01011f46_caseD_8b:
        if (bVar14 || bVar13 != bVar15) break;
switchD_01011f46_caseD_85:
        unaff_r6 = (byte *)(uint)param_2[(int)param_1];
switchD_01011f46_caseD_86:
        pbVar11 = (byte *)(uint)bVar10;
switchD_01011f46_caseD_87:
        pbVar11 = pbVar11 + (int)unaff_r6;
switchD_01011f46_caseD_88:
        pbVar7[0x13] = (byte)pbVar11;
switchD_01011f46_caseD_89:
        param_1 = param_1 + 1;
      }
switchD_01011f46_caseD_8c:
      bVar10 = (byte)uVar8;
      goto LAB_010122f6;
    }
switchD_01011f46_caseD_48:
    if (bVar2 || bVar13 != bVar15) {
switchD_01011f46_caseD_49:
      bVar14 = unaff_r7 == 0x26;
switchD_01011f46_caseD_4a:
      if (bVar14) {
switchD_01011f46_caseD_b4:
        bVar10 = (byte)uVar8;
        pbVar9[0x1d] = (byte)unaff_r6;
        pbVar6 = DAT_01012380;
        pbVar9 = DAT_01012380 + 0xffffffac;
        *pbVar9 = 0x44;
        pbVar6[-0x53] = 3;
        pbVar6[-0x52] = 0xa6;
        if (*(char *)(*puVar16 + 0x12) == '\0') {
          pbVar6[-0x51] = (byte)pbVar11;
        }
        else {
          pbVar6[-0x51] = 0x7f;
        }
        pbVar7[0x13] = (byte)pbVar11;
        for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
          pbVar11 = (byte *)(((uint)pbVar11 & 0xff) + (uint)pbVar9[iVar5]);
          pbVar7[0x13] = (byte)pbVar11;
        }
        goto LAB_010122f6;
      }
switchD_01011f46_caseD_4b:
      bVar14 = unaff_r7 == 0x27;
switchD_01011f46_caseD_4c:
      if (bVar14) {
switchD_01011f46_caseD_4d:
        bVar10 = (byte)uVar8;
        pbVar9[0x1d] = (byte)unaff_r6;
        pbVar6 = DAT_01012380;
        pbVar9 = DAT_01012380 + 0xffffffac;
        *pbVar9 = 0x44;
        pbVar6[-0x53] = 5;
        pbVar6[-0x52] = 0xa7;
        bVar3 = (byte)pbVar11;
        if (pbVar12 == (byte *)0x0) {
          pbVar6[-0x51] = bVar3;
          pbVar6[0xffffffb0] = 6;
          pbVar6[-0x4f] = 5;
        }
        else {
          pbVar6[-0x51] = 0x7f;
          pbVar6[0xffffffb0] = bVar3;
          pbVar6[-0x4f] = bVar3;
        }
        pbVar7[0x13] = bVar3;
        for (iVar5 = 1; iVar5 < 6; iVar5 = iVar5 + 1) {
          pbVar11 = (byte *)(((uint)pbVar11 & 0xff) + (uint)pbVar9[iVar5]);
          pbVar7[0x13] = (byte)pbVar11;
        }
        goto LAB_010122f6;
      }
    }
    else {
switchD_01011f46_caseD_4e:
      bVar14 = unaff_r7 == 0x3e;
switchD_01011f46_caseD_4f:
      if (bVar14) {
switchD_01011f46_caseD_cf:
        bVar10 = (byte)uVar8;
        pbVar6 = DAT_01012380 + 0xffffffac;
        *pbVar6 = 0x44;
        pbVar4[-0x53] = 3;
        pbVar4[-0x52] = 0xbe;
        pbVar4[-0x51] = 0x7f;
        pbVar7[0x13] = (byte)pbVar11;
        for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
          pbVar11 = (byte *)(((uint)pbVar11 & 0xff) + (uint)pbVar6[iVar5]);
          pbVar7[0x13] = (byte)pbVar11;
        }
        goto LAB_010122f6;
      }
switchD_01011f46_caseD_50:
      bVar14 = unaff_r7 == 0x3f;
switchD_01011f46_caseD_51:
      if (bVar14) {
switchD_01011f46_caseD_d0:
        bVar10 = (byte)uVar8;
        pbVar9 = DAT_01012380 + 0xffffffac;
        *pbVar9 = 0x44;
        pbVar4[-0x53] = 3;
        pbVar4[-0x52] = 0xbf;
        pbVar6 = DAT_01012388;
        if (pbVar12 == (byte *)0x0) {
          pbVar4[-0x51] = (byte)pbVar11;
          pbVar6[0xffffffe4] = (byte)unaff_r6;
        }
        else {
          pbVar4[-0x51] = 0x7f;
        }
        pbVar7[0x13] = (byte)pbVar11;
        for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
          pbVar11 = (byte *)(((uint)pbVar11 & 0xff) + (uint)pbVar9[iVar5]);
          pbVar7[0x13] = (byte)pbVar11;
        }
        goto LAB_010122f6;
      }
    }
    goto switchD_01011f46_caseD_52;
  case 0x21:
    goto switchD_01011f46_caseD_21;
  case 0x23:
    goto switchD_01011f46_caseD_23;
  case 0x24:
    goto switchD_01011f46_caseD_24;
  case 0x25:
    goto switchD_01011f46_caseD_25;
  case 0x26:
    goto switchD_01011f46_caseD_26;
  case 0x27:
    goto switchD_01011f46_caseD_27;
  case 0x28:
    goto switchD_01011f46_caseD_28;
  case 0x29:
    goto switchD_01011f46_caseD_29;
  case 0x2a:
    goto switchD_01011f46_caseD_2a;
  case 0x2b:
    goto switchD_01011f46_caseD_2b;
  case 0x2c:
    goto switchD_01011f46_caseD_2c;
  case 0x2d:
    goto switchD_01011f46_caseD_2d;
  case 0x2e:
    goto switchD_01011f46_caseD_2e;
  case 0x2f:
    goto switchD_01011f46_caseD_2f;
  case 0x30:
    goto switchD_01011f46_caseD_30;
  case 0x31:
    goto switchD_01011f46_caseD_31;
  case 0x32:
    goto switchD_01011f46_caseD_32;
  case 0x33:
    goto switchD_01011f46_caseD_33;
  case 0x34:
    goto switchD_01011f46_caseD_34;
  case 0x35:
    goto switchD_01011f46_caseD_35;
  case 0x36:
    goto switchD_01011f46_caseD_36;
  case 0x37:
    goto switchD_01011f46_caseD_37;
  case 0x38:
    goto switchD_01011f46_caseD_38;
  case 0x39:
    goto switchD_01011f46_caseD_39;
  case 0x3a:
    goto switchD_01011f46_caseD_3a;
  case 0x3b:
    goto switchD_01011f46_caseD_3b;
  case 0x3c:
    goto switchD_01011f46_caseD_3c;
  case 0x3d:
    goto switchD_01011f46_caseD_3d;
  case 0x3e:
    goto switchD_01011f46_caseD_3e;
  case 0x3f:
    goto switchD_01011f46_caseD_3f;
  case 0x40:
    goto switchD_01011f46_caseD_40;
  case 0x41:
    goto switchD_01011f46_caseD_41;
  case 0x42:
    goto switchD_01011f46_caseD_42;
  case 0x43:
    goto switchD_01011f46_caseD_43;
  case 0x44:
    goto switchD_01011f46_caseD_44;
  case 0x45:
    goto switchD_01011f46_caseD_45;
  case 0x46:
    goto switchD_01011f46_caseD_46;
  case 0x47:
    goto switchD_01011f46_caseD_47;
  case 0x48:
    goto switchD_01011f46_caseD_48;
  case 0x49:
    goto switchD_01011f46_caseD_49;
  case 0x4a:
    goto switchD_01011f46_caseD_4a;
  case 0x4b:
    goto switchD_01011f46_caseD_4b;
  case 0x4c:
    goto switchD_01011f46_caseD_4c;
  case 0x4d:
    goto switchD_01011f46_caseD_4d;
  case 0x4e:
    goto switchD_01011f46_caseD_4e;
  case 0x4f:
    goto switchD_01011f46_caseD_4f;
  case 0x50:
    goto switchD_01011f46_caseD_50;
  case 0x51:
    goto switchD_01011f46_caseD_51;
  case 0x52:
    goto switchD_01011f46_caseD_52;
  case 0x53:
    goto switchD_01011f46_caseD_53;
  case 0x54:
    goto switchD_01011f46_caseD_54;
  case 0x55:
    goto switchD_01011f46_caseD_55;
  case 0x56:
    goto switchD_01011f46_caseD_56;
  case 0x57:
    uVar1 = VectorGetElement(in_d0,3,2,0);
    VectorMultiply(in_q12,uVar1,2);
  case 0x59:
switchD_01011f46_caseD_59:
    pbVar7 = (byte *)0x2;
switchD_01011f46_caseD_5a:
    param_2 = (byte *)(uint)*param_1;
switchD_01011f46_caseD_5b:
    break;
  case 0x58:
    goto switchD_01011f46_caseD_58;
  case 0x5a:
    goto switchD_01011f46_caseD_5a;
  case 0x5b:
    goto switchD_01011f46_caseD_5b;
  case 0x5c:
    goto switchD_01011f46_caseD_5c;
  case 0x5d:
    goto switchD_01011f46_caseD_5d;
  case 0x5e:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x5f:
    goto switchD_01011f46_caseD_5f;
  case 0x60:
    goto switchD_01011f46_caseD_60;
  case 0x61:
    goto switchD_01011f46_caseD_61;
  case 0x62:
    goto switchD_01011f46_caseD_62;
  case 99:
    goto switchD_01011f46_caseD_63;
  case 100:
    goto switchD_01011f46_caseD_64;
  case 0x65:
    uVar1 = VectorGetElement(in_d1,1,2,0);
    VectorMultiplyAddLongScalar(in_d26,uVar1,1);
  case 0x67:
switchD_01011f46_caseD_67:
    pbVar7 = &Reserved2;
switchD_01011f46_caseD_68:
    param_2 = (byte *)(uint)*param_1;
    break;
  case 0x66:
    goto switchD_01011f46_caseD_66;
  case 0x68:
    goto switchD_01011f46_caseD_68;
  case 0x69:
    break;
  case 0x6a:
    goto switchD_01011f46_caseD_6a;
  case 0x6b:
    goto switchD_01011f46_caseD_6b;
  case 0x6c:
    goto switchD_01011f46_caseD_6c;
  case 0x6d:
    goto switchD_01011f46_caseD_6d;
  case 0x6e:
    goto switchD_01011f46_caseD_6e;
  case 0x6f:
    goto switchD_01011f46_caseD_6f;
  case 0x70:
    goto switchD_01011f46_caseD_70;
  case 0x71:
    goto switchD_01011f46_caseD_71;
  case 0x72:
    goto switchD_01011f46_caseD_72;
  case 0x73:
    goto switchD_01011f46_caseD_73;
  case 0x74:
    goto switchD_01011f46_caseD_74;
  case 0x75:
    goto switchD_01011f46_caseD_75;
  case 0x76:
    goto switchD_01011f46_caseD_76;
  case 0x77:
    goto switchD_01011f46_caseD_77;
  case 0x78:
    goto switchD_01011f46_caseD_78;
  case 0x79:
    goto switchD_01011f46_caseD_79;
  case 0x7a:
    goto switchD_01011f46_caseD_7a;
  case 0x7b:
    goto switchD_01011f46_caseD_7b;
  case 0x7c:
    goto switchD_01011f46_caseD_7c;
  case 0x7d:
    goto switchD_01011f46_caseD_7d;
  case 0x7e:
    goto switchD_01011f46_caseD_7e;
  case 0x7f:
    goto switchD_01011f46_caseD_7f;
  case 0x80:
    goto switchD_01011f46_caseD_80;
  case 0x81:
    goto switchD_01011f46_caseD_81;
  case 0x82:
    goto switchD_01011f46_caseD_82;
  case 0x83:
    goto switchD_01011f46_caseD_83;
  case 0x84:
    goto switchD_01011f46_caseD_84;
  case 0x85:
    goto switchD_01011f46_caseD_85;
  case 0x86:
    goto switchD_01011f46_caseD_86;
  case 0x87:
    goto switchD_01011f46_caseD_87;
  case 0x88:
    goto switchD_01011f46_caseD_88;
  case 0x89:
    goto switchD_01011f46_caseD_89;
  case 0x8a:
    goto switchD_01011f46_caseD_8a;
  case 0x8b:
    goto switchD_01011f46_caseD_8b;
  case 0x8c:
    goto switchD_01011f46_caseD_8c;
  case 0x8d:
    goto switchD_01011f46_caseD_8d;
  case 0x8e:
    goto switchD_01011f46_caseD_8e;
  case 0x8f:
    goto switchD_01011f46_caseD_8f;
  case 0x90:
    goto switchD_01011f46_caseD_90;
  case 0x91:
    goto switchD_01011f46_caseD_91;
  case 0x92:
    goto switchD_01011f46_caseD_92;
  case 0x93:
    goto switchD_01011f46_caseD_93;
  case 0x94:
    goto switchD_01011f46_caseD_94;
  case 0x95:
    goto switchD_01011f46_caseD_95;
  case 0x96:
    goto switchD_01011f46_caseD_96;
  case 0x97:
    goto switchD_01011f46_caseD_97;
  case 0x98:
    goto switchD_01011f46_caseD_98;
  case 0x99:
    goto switchD_01011f46_caseD_99;
  case 0x9a:
    goto switchD_01011f46_caseD_9a;
  case 0x9b:
    goto switchD_01011f46_caseD_9b;
  case 0x9c:
    goto switchD_01011f46_caseD_9c;
  case 0x9d:
    goto switchD_01011f46_caseD_9d;
  case 0x9e:
    goto switchD_01011f46_caseD_9e;
  case 0x9f:
    goto switchD_01011f46_caseD_9f;
  case 0xa0:
    goto switchD_01011f46_caseD_a0;
  case 0xa1:
    goto switchD_01011f46_caseD_a1;
  case 0xa2:
    goto switchD_01011f46_caseD_a2;
  case 0xa3:
    goto switchD_01011f46_caseD_a3;
  case 0xa4:
    goto switchD_01011f46_caseD_a4;
  case 0xa5:
    goto switchD_01011f46_caseD_a5;
  case 0xa6:
    goto switchD_01011f46_caseD_a6;
  case 0xa7:
    goto switchD_01011f46_caseD_a7;
  case 0xa8:
    goto switchD_01011f46_caseD_a8;
  case 0xa9:
    goto switchD_01011f46_caseD_a9;
  case 0xaa:
    goto switchD_01011f46_caseD_aa;
  case 0xab:
    goto switchD_01011f46_caseD_ab;
  case 0xac:
    goto switchD_01011f46_caseD_ac;
  case 0xad:
    goto switchD_01011f46_caseD_ad;
  case 0xae:
    goto switchD_01011f46_caseD_ae;
  case 0xaf:
    goto switchD_01011f46_caseD_af;
  case 0xb0:
    goto switchD_01011f46_caseD_b0;
  case 0xb1:
    goto switchD_01011f46_caseD_b1;
  case 0xb2:
    goto switchD_01011f46_caseD_b2;
  case 0xb3:
    goto switchD_01011f46_caseD_b3;
  case 0xb4:
    goto switchD_01011f46_caseD_b4;
  case 0xb5:
    goto switchD_01011f46_caseD_b5;
  case 0xb6:
    goto switchD_01011f46_caseD_b6;
  case 0xb7:
    goto switchD_01011f46_caseD_b7;
  case 0xb8:
    goto switchD_01011f46_caseD_b8;
  case 0xb9:
    goto switchD_01011f46_caseD_b9;
  case 0xba:
    goto switchD_01011f46_caseD_ba;
  case 0xbb:
    goto switchD_01011f46_caseD_bb;
  case 0xbc:
    goto switchD_01011f46_caseD_bc;
  case 0xbd:
    goto switchD_01011f46_caseD_bd;
  case 0xbe:
    goto switchD_01011f46_caseD_be;
  case 0xbf:
    goto switchD_01011f46_caseD_bf;
  case 0xc0:
    goto switchD_01011f46_caseD_c0;
  case 0xc1:
    goto switchD_01011f46_caseD_c1;
  case 0xc2:
    goto switchD_01011f46_caseD_c2;
  case 0xc3:
    goto switchD_01011f46_caseD_c3;
  case 0xc4:
    goto switchD_01011f46_caseD_c4;
  case 0xc5:
    goto switchD_01011f46_caseD_c5;
  case 0xc6:
    goto switchD_01011f46_caseD_c6;
  case 199:
    goto switchD_01011f46_caseD_c7;
  case 200:
    goto switchD_01011f46_caseD_c8;
  case 0xc9:
    goto switchD_01011f46_caseD_c9;
  case 0xca:
    goto switchD_01011f46_caseD_ca;
  case 0xcb:
    goto switchD_01011f46_caseD_cb;
  case 0xcc:
    goto switchD_01011f46_caseD_cc;
  case 0xcd:
    goto switchD_01011f46_caseD_cd;
  case 0xce:
    goto switchD_01011f46_caseD_ce;
  case 0xcf:
    goto switchD_01011f46_caseD_cf;
  case 0xd0:
    goto switchD_01011f46_caseD_d0;
  case 0xd1:
    goto switchD_01011f46_caseD_d1;
  case 0xd2:
    goto switchD_01011f46_caseD_d2;
  case 0xd3:
    goto switchD_01011f46_caseD_d3;
  case 0xd4:
    goto switchD_01011f46_caseD_d4;
  case 0xd5:
    goto switchD_01011f46_caseD_d5;
  case 0xd6:
    goto switchD_01011f46_caseD_d6;
  case 0xd7:
    goto switchD_01011f46_caseD_d7;
  case 0xd8:
    goto switchD_01011f46_caseD_d8;
  case 0xd9:
    goto switchD_01011f46_caseD_d9;
  case 0xda:
    goto switchD_01011f46_caseD_da;
  case 0xdb:
    goto switchD_01011f46_caseD_db;
  case 0xdc:
    goto switchD_01011f46_caseD_dc;
  case 0xdd:
    goto switchD_01011f46_caseD_dd;
  case 0xde:
    goto switchD_01011f46_caseD_de;
  case 0xdf:
    goto switchD_01011f46_caseD_df;
  case 0xe0:
    goto switchD_01011f46_caseD_e0;
  case 0xe1:
    goto switchD_01011f46_caseD_e1;
  case 0xe2:
    goto switchD_01011f46_caseD_e2;
  case 0xe3:
    goto switchD_01011f46_caseD_e3;
  case 0xe4:
    goto switchD_01011f46_caseD_e4;
  case 0xe5:
    goto switchD_01011f46_caseD_e5;
  case 0xe6:
    goto switchD_01011f46_caseD_e6;
  case 0xe7:
    goto switchD_01011f46_caseD_e7;
  case 0xe8:
    goto switchD_01011f46_caseD_e8;
  case 0xe9:
    goto switchD_01011f46_caseD_e9;
  case 0xea:
    goto switchD_01011f46_caseD_ea;
  case 0xeb:
    goto switchD_01011f46_caseD_eb;
  case 0xec:
    goto switchD_01011f46_caseD_ec;
  case 0xed:
    goto switchD_01011f46_caseD_ed;
  case 0xee:
    goto switchD_01011f46_caseD_ee;
  case 0xef:
    goto switchD_01011f46_caseD_ef;
  case 0xf0:
    goto switchD_01011f46_caseD_f0;
  case 0xf1:
    goto switchD_01011f46_caseD_f1;
  case 0xf2:
    goto switchD_01011f46_caseD_f2;
  case 0xf3:
    goto switchD_01011f46_caseD_f3;
  case 0xf4:
    goto switchD_01011f46_caseD_f4;
  case 0xf5:
    goto switchD_01011f46_caseD_f5;
  case 0xf6:
    goto switchD_01011f46_caseD_f6;
  case 0xf7:
    goto switchD_01011f46_caseD_f7;
  case 0xf8:
    goto switchD_01011f46_caseD_f8;
  case 0xf9:
    goto switchD_01011f46_caseD_f9;
  case 0xfa:
    goto switchD_01011f46_caseD_fa;
  case 0xfb:
    goto switchD_01011f46_caseD_fb;
  case 0xfc:
    goto switchD_01011f46_caseD_fc;
  case 0xfd:
    goto switchD_01011f46_caseD_fd;
  case 0xfe:
    goto switchD_01011f46_caseD_fe;
  case 0xff:
    goto switchD_01011f46_caseD_ff;
  }
  param_2 = (byte *)((uint)param_2 | (uint)pbVar7);
switchD_01011f46_caseD_6a:
  *param_1 = (byte)param_2;
switchD_01011f46_caseD_6b:
  pbVar9[0x1d] = (byte)unaff_r6;
switchD_01011f46_caseD_6c:
  param_1 = DAT_01012388;
switchD_01011f46_caseD_6d:
  param_1 = param_1 + 0xffffffe0;
switchD_01011f46_caseD_6e:
  *(byte **)param_1 = pbVar11;
switchD_01011f46_caseD_6f:
  return;
}


// ===== caseD_22 @ 01011f8e

void switchD_01011f46::caseD_22(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  undefined1 *puVar12;
  byte bVar13;
  uint *puVar14;
  char cVar15;
  
  puVar6 = DAT_01012388;
  iVar8 = DAT_01012384;
  iVar5 = DAT_01012380;
  bVar10 = *DAT_0101237c;
  cVar1 = *(char *)(DAT_01012380 + 7);
  bVar13 = *(byte *)(DAT_01012378 + 3);
  cVar15 = '\0';
  puVar14 = (uint *)(DAT_01012384 + -0x20);
  if (bVar13 == 0x25) {
    *(undefined1 *)(DAT_01012384 + -3) = 1;
    iVar9 = DAT_01012380;
    puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
    *puVar12 = 0x44;
    *(undefined1 *)(iVar9 + -0x53) = 3;
    *(undefined1 *)(iVar9 + -0x52) = 0xa5;
    if (cVar1 == '\0') {
      *(undefined1 *)(iVar9 + -0x51) = 0;
    }
    else {
      *(undefined1 *)(iVar9 + -0x51) = 0x7f;
    }
    *(undefined1 *)(iVar5 + -1) = 0;
    for (iVar9 = 1; iVar9 < 4; iVar9 = iVar9 + 1) {
      cVar15 = cVar15 + puVar12[iVar9];
      *(char *)(iVar5 + -1) = cVar15;
    }
    *(undefined1 *)(iVar8 + 0x11) = 1;
  }
  else {
    if (bVar13 < 0x26) {
      uVar2 = *(undefined1 *)(DAT_01012378 + 1);
      if (bVar13 == 0x22) {
        FUN_01011c6a(uVar2,DAT_01012378 + 4);
        bVar13 = 0x20;
        bVar10 = *DAT_0101237c;
      }
      else {
        if (0x22 < bVar13) {
          if (bVar13 == 0x23) {
            *(undefined1 *)(DAT_01012384 + -3) = 1;
            *(undefined1 *)((int)puVar6 + 0x1d) = *(undefined1 *)(DAT_01012378 + 4);
            *(undefined1 *)((int)puVar6 + 0x1e) = *(undefined1 *)(DAT_01012378 + 5);
            *puVar14 = (uint)*(ushort *)(DAT_01012378 + 6);
            cVar3 = *(char *)(DAT_01012378 + 8);
            *(char *)((int)puVar6 + 0x19) = cVar3;
            iVar9 = DAT_01012378;
            cVar4 = *(char *)(DAT_01012378 + 9);
            *(char *)((int)puVar6 + 0x1a) = cVar4;
            *(char *)((int)puVar6 + 0x1b) = *(char *)(iVar9 + 10) - cVar3;
            *(char *)(puVar6 + 7) = *(char *)(DAT_01012378 + 0xb) - cVar4;
            puVar7 = DAT_01012388;
            DAT_01012388[0x13] = 0;
            puVar7[0x14] = 0;
            puVar7[0x15] = 0;
            puVar7[0x16] = 0;
            *(undefined4 *)(iVar8 + -0x1c) = 0;
            if ((*puVar14 & 0xfff) == 0) {
              bVar13 = *(byte *)((int)puVar6 + 0x1d);
              uVar11 = *puVar14 >> 0xc;
            }
            else {
              bVar13 = *(byte *)((int)puVar6 + 0x1d);
              uVar11 = (*puVar14 >> 0xc) + 1;
            }
            puVar7[-1] = bVar13 * uVar11;
            *puVar7 = 0;
            *(undefined1 *)(puVar6 + 2) = 0;
            *(undefined1 *)((int)puVar6 + 10) = 1;
            *(undefined1 *)((int)puVar6 + 9) = 1;
            puVar7[1] = 0;
            *(undefined1 *)(DAT_01012384 + -0x24) = 0;
            iVar8 = DAT_01012380;
            puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
            *puVar12 = 0x44;
            *(undefined1 *)(iVar8 + -0x53) = 3;
            *(undefined1 *)(iVar8 + -0x52) = 0xa3;
            if (cVar1 == '\0') {
              *(undefined1 *)(iVar8 + -0x51) = 0;
            }
            else {
              *(undefined1 *)(iVar8 + -0x51) = 0x7f;
            }
            *(undefined1 *)(iVar5 + -1) = 0;
            for (iVar8 = 1; iVar8 < 4; iVar8 = iVar8 + 1) {
              cVar15 = cVar15 + puVar12[iVar8];
              *(char *)(iVar5 + -1) = cVar15;
            }
          }
          else {
            if (bVar13 != 0x24) goto switchD_01011f46_caseD_52;
            *(undefined1 *)(DAT_01012384 + -0x18) = 1;
            *(undefined1 *)(DAT_01012388 + -5) = 4;
            *(undefined1 *)(iVar8 + 4) = 0xff;
            *(undefined1 *)(iVar8 + 5) = 0xff;
            puVar7 = DAT_01012388;
            *(undefined1 *)((int)DAT_01012388 + DAT_01012388[3] + 0x1f) =
                 *(undefined1 *)((int)puVar6 + 0x19);
            *(undefined1 *)((int)puVar7 + puVar7[3] + 0x25) = *(undefined1 *)((int)puVar6 + 0x1a);
            *(undefined1 *)((int)puVar7 + puVar7[3] + 0x2b) = *(undefined1 *)((int)puVar6 + 0x1b);
            *(undefined1 *)((int)puVar7 + puVar7[3] + 0x31) = *(undefined1 *)(puVar6 + 7);
            *(undefined1 *)((int)puVar7 + puVar7[3] + 0x37) = *(undefined1 *)((int)puVar6 + 0x1e);
            puVar7 = DAT_01012388;
            *(undefined1 *)((int)DAT_01012388 + DAT_01012388[3] + 0x3d) =
                 *(undefined1 *)((int)puVar6 + 0x1d);
            if (*(int *)(iVar8 + -0x1c) == 0) {
              *(undefined1 *)((int)puVar7 + DAT_01012388[3] + 0x43) = 0;
            }
            else {
              *(undefined1 *)((int)puVar7 + puVar7[3] + 0x43) = 1;
            }
            puVar6 = DAT_01012388;
            iVar8 = 0;
            do {
              if (puVar6[3] == iVar8) {
                if (*(char *)((int)puVar6 + iVar8 + 0x43) == '\0') {
                  *(undefined1 *)(puVar6 + -5) = 0;
                }
                else {
                  *(undefined1 *)(puVar6 + -5) = 4;
                }
              }
              iVar9 = DAT_01012380;
              iVar8 = iVar8 + 1;
            } while (iVar8 < 6);
            puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
            *puVar12 = 0x44;
            *(undefined1 *)(iVar9 + -0x53) = 3;
            *(undefined1 *)(iVar9 + -0x52) = 0xa4;
            if (cVar1 == '\0') {
              *(undefined1 *)(iVar9 + -0x51) = 0;
            }
            else {
              *(undefined1 *)(iVar9 + -0x51) = 0x7f;
            }
            *(undefined1 *)(iVar5 + -1) = 0;
            for (iVar8 = 1; iVar8 < 4; iVar8 = iVar8 + 1) {
              cVar15 = cVar15 + puVar12[iVar8];
              *(char *)(iVar5 + -1) = cVar15;
            }
          }
          goto LAB_010122f6;
        }
        if (bVar13 == 1) {
          FUN_01011f2a(uVar2,DAT_01012378 + 4);
          bVar13 = 2;
          bVar10 = *DAT_0101237c;
        }
        else {
          if (bVar13 != 0x21) goto switchD_01011f46_caseD_52;
          FUN_01011c7e(uVar2,DAT_01012378 + 4);
          bVar13 = 8;
          bVar10 = *DAT_0101237c;
        }
      }
      *DAT_0101237c = bVar10 | bVar13;
      *(undefined1 *)(iVar8 + -3) = 1;
      DAT_01012388[-8] = 0;
      return;
    }
    if (bVar13 == 0x30) {
      *(undefined1 *)(DAT_01012384 + -3) = 0;
      *(undefined1 *)(iVar8 + -2) = 1;
      iVar8 = DAT_01012380;
      puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
      *puVar12 = 0x44;
      *(undefined1 *)(iVar8 + -0x53) = 3;
      *(undefined1 *)(iVar8 + -0x52) = 0xb0;
      if (cVar1 == '\0') {
        *(undefined1 *)(iVar8 + -0x51) = 0;
      }
      else {
        *(undefined1 *)(iVar8 + -0x51) = 0x7f;
      }
      *(undefined1 *)(iVar5 + -1) = 0;
      for (iVar8 = 1; iVar8 < 4; iVar8 = iVar8 + 1) {
        cVar15 = cVar15 + puVar12[iVar8];
        *(char *)(iVar5 + -1) = cVar15;
      }
    }
    else if (bVar13 < 0x31) {
      if (bVar13 == 0x26) {
        *(undefined1 *)(DAT_01012384 + -3) = 1;
        iVar9 = DAT_01012380;
        puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
        *puVar12 = 0x44;
        *(undefined1 *)(iVar9 + -0x53) = 3;
        *(undefined1 *)(iVar9 + -0x52) = 0xa6;
        if (*(char *)(iVar8 + 0x12) == '\0') {
          *(undefined1 *)(iVar9 + -0x51) = 0;
        }
        else {
          *(undefined1 *)(iVar9 + -0x51) = 0x7f;
        }
        *(undefined1 *)(iVar5 + -1) = 0;
        for (iVar8 = 1; iVar8 < 4; iVar8 = iVar8 + 1) {
          cVar15 = cVar15 + puVar12[iVar8];
          *(char *)(iVar5 + -1) = cVar15;
        }
      }
      else {
        if (bVar13 != 0x27) {
switchD_01011f46_caseD_52:
          *(undefined1 *)(DAT_01012380 + 6) = 1;
          return;
        }
        *(undefined1 *)(DAT_01012384 + -3) = 1;
        iVar8 = DAT_01012380;
        puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
        *puVar12 = 0x44;
        *(undefined1 *)(iVar8 + -0x53) = 5;
        *(undefined1 *)(iVar8 + -0x52) = 0xa7;
        if (cVar1 == '\0') {
          *(undefined1 *)(iVar8 + -0x51) = 0;
          *(undefined1 *)(iVar8 + -0x50) = 6;
          *(undefined1 *)(iVar8 + -0x4f) = 5;
        }
        else {
          *(undefined1 *)(iVar8 + -0x51) = 0x7f;
          *(undefined1 *)(iVar8 + -0x50) = 0;
          *(undefined1 *)(iVar8 + -0x4f) = 0;
        }
        *(undefined1 *)(iVar5 + -1) = 0;
        for (iVar8 = 1; iVar8 < 6; iVar8 = iVar8 + 1) {
          cVar15 = cVar15 + puVar12[iVar8];
          *(char *)(iVar5 + -1) = cVar15;
        }
      }
    }
    else if (bVar13 == 0x3e) {
      puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
      *puVar12 = 0x44;
      *(undefined1 *)(iVar5 + -0x53) = 3;
      *(undefined1 *)(iVar5 + -0x52) = 0xbe;
      *(undefined1 *)(iVar5 + -0x51) = 0x7f;
      *(undefined1 *)(iVar5 + -1) = 0;
      for (iVar8 = 1; iVar8 < 4; iVar8 = iVar8 + 1) {
        cVar15 = cVar15 + puVar12[iVar8];
        *(char *)(iVar5 + -1) = cVar15;
      }
    }
    else {
      if (bVar13 != 0x3f) goto switchD_01011f46_caseD_52;
      puVar12 = (undefined1 *)(DAT_01012380 + -0x54);
      *puVar12 = 0x44;
      *(undefined1 *)(iVar5 + -0x53) = 3;
      *(undefined1 *)(iVar5 + -0x52) = 0xbf;
      puVar6 = DAT_01012388;
      if (cVar1 == '\0') {
        *(undefined1 *)(iVar5 + -0x51) = 0;
        *(undefined1 *)(puVar6 + -7) = 1;
      }
      else {
        *(undefined1 *)(iVar5 + -0x51) = 0x7f;
      }
      *(undefined1 *)(iVar5 + -1) = 0;
      for (iVar8 = 1; iVar8 < 4; iVar8 = iVar8 + 1) {
        cVar15 = cVar15 + puVar12[iVar8];
        *(char *)(iVar5 + -1) = cVar15;
      }
    }
  }
LAB_010122f6:
  *DAT_0101237c = bVar10 | 1;
  return;
}


// ===== FUN_010122fc @ 010122fc

void FUN_010122fc(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  
  pcVar3 = DAT_01012380;
  cVar5 = '\0';
  if (*DAT_01012380 == '\0') {
    return;
  }
  cVar1 = DAT_01012380[1];
  DAT_01012380[1] = cVar1 + 1U;
  if ((byte)(cVar1 + 1U) < 4) {
    return;
  }
  pcVar3[1] = '\0';
  pcVar2 = DAT_01012378;
  *pcVar3 = '\0';
  if (*pcVar2 == 'U') {
    iVar6 = *(int *)(DAT_0101237c + 4);
    if (iVar6 - 3U == (uint)*(ushort *)(pcVar2 + 1)) {
      for (uVar4 = 1; uVar4 < iVar6 - 1U; uVar4 = uVar4 + 1) {
        cVar5 = pcVar2[uVar4] + cVar5;
      }
      if (pcVar2[iVar6 + -1] == cVar5) {
        pcVar3[2] = '\x01';
      }
    }
    pcVar3[7] = '\0';
    if (pcVar3[2] != '\0') {
      pcVar3[2] = '\0';
      pcVar3[6] = '\0';
      switchD_01011f46::caseD_22();
      if (pcVar3[6] == '\0') goto LAB_01012370;
    }
    pcVar3[7] = '\x01';
  }
LAB_01012370:
  FUN_01011b78();
  return;
}


// ===== FUN_01012392 @ 01012392

void FUN_01012392(void)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar4 = DAT_01012478;
  bVar1 = *DAT_01012474;
  cVar2 = *(char *)(DAT_01012478 + 7);
  puVar6 = (undefined1 *)(DAT_01012478 + -0x54);
  if ((int)((uint)bVar1 * 0x40000000) < 0) {
    *puVar6 = 0x44;
    *(undefined1 *)(iVar4 + -0x53) = 3;
    *(undefined1 *)(iVar4 + -0x52) = 0x81;
    if (cVar2 == '\0') {
      *(undefined1 *)(iVar4 + -0x51) = 0;
    }
    else {
      *(undefined1 *)(iVar4 + -0x51) = 0x7f;
    }
    *(undefined1 *)(iVar4 + -1) = 0;
    for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
      *(char *)(iVar4 + -1) = *(char *)(iVar4 + -1) + puVar6[iVar5];
    }
    *DAT_01012474 = bVar1 & 0xfd | 1;
  }
  bVar1 = *DAT_01012474;
  if ((int)((uint)bVar1 << 0x1a) < 0) {
    *puVar6 = 0x44;
    *(undefined1 *)(iVar4 + -0x53) = 3;
    *(undefined1 *)(iVar4 + -0x52) = 0xa2;
    if (cVar2 == '\0') {
      *(undefined1 *)(iVar4 + -0x51) = 0;
    }
    else {
      *(undefined1 *)(iVar4 + -0x51) = 0x7f;
    }
    *(undefined1 *)(iVar4 + -1) = 0;
    for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
      *(char *)(iVar4 + -1) = *(char *)(iVar4 + -1) + puVar6[iVar5];
    }
    *DAT_01012474 = bVar1 & 0xdf | 1;
  }
  pbVar3 = DAT_01012474;
  bVar1 = *DAT_01012474;
  if ((int)((uint)bVar1 << 0x1c) < 0) {
    *puVar6 = 0x44;
    *(undefined1 *)(iVar4 + -0x53) = 3;
    *(undefined1 *)(iVar4 + -0x52) = 0xa1;
    if (cVar2 == '\0') {
      *(undefined1 *)(iVar4 + -0x51) = 0;
    }
    else {
      *(undefined1 *)(iVar4 + -0x51) = 0x7f;
    }
    *(undefined1 *)(iVar4 + -1) = 0;
    for (iVar5 = 1; iVar5 < 4; iVar5 = iVar5 + 1) {
      *(char *)(iVar4 + -1) = *(char *)(iVar4 + -1) + puVar6[iVar5];
    }
    *pbVar3 = bVar1 & 0xf7 | 1;
  }
  return;
}


// ===== FUN_0101247c @ 0101247c

void FUN_0101247c(uint param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (2 < param_1) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_gpi_01012888,0xe,DAT_01012884);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_gpi_01012888,0xf,DAT_01012884);
  }
  iVar1 = DAT_010128ac;
  uVar2 = 0;
  do {
    if ((1 << (uVar2 & 0xff) & param_2) != 0) {
      *(undefined1 *)(param_1 * 0x10 + uVar2 + iVar1) = param_3;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}


// ===== FUN_010127f2 @ 010127f2

void FUN_010127f2(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (2 < param_1) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_gpi_01012888,0x96,DAT_01012884 + 0x79,param_4,
                 param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_gpi_01012888,0x97,DAT_01012884 + 0x79);
  }
  iVar1 = DAT_010128ac;
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


// ===== FUN_010128be @ 010128be

void FUN_010128be(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (2 < param_1) {
    FUN_01013f6e(DAT_01012a38,0xaa,DAT_01012a34,param_4,param_4);
  }
  if (((((param_2 != 1) && (param_2 != 2)) && (param_2 != 4)) &&
      (((param_2 != 8 && (param_2 != 0x10)) &&
       ((param_2 != 0x20 && ((param_2 != 0x40 && (param_2 != 0x80)))))))) &&
     ((param_2 != 0x100 &&
      (((((param_2 != 0x200 && (param_2 != 0x400)) && (param_2 != 0x800)) &&
        ((param_2 != 0x1000 && (param_2 != 0x2000)))) &&
       ((param_2 != 0x4000 && (param_2 != 0x8000)))))))) {
    FUN_01013f6e(DAT_01012a38,0xab,DAT_01012a34);
  }
  iVar1 = DAT_01012a3c;
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


// ===== FUN_01012960 @ 01012960

void FUN_01012960(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (2 < param_1) {
    FUN_01013f6e(DAT_01012a38,0xbe,DAT_01012a34 + 0xd,param_4,param_4);
  }
  uVar2 = 0;
  do {
    uVar1 = 1 << (uVar2 & 0xff);
    if ((uVar1 & param_2) >> (uVar2 & 0xff) == 0) {
      FUN_010127f2(param_1,uVar1 & 0xffff);
    }
    else {
      FUN_010128be(param_1,uVar1 & 0xffff);
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}


// ===== FUN_01012a8c @ 01012a8c

void FUN_01012a8c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0xf3,DAT_01012e14 + 0x73);
  }
  if ((param_2 != 1) && (param_2 != 2)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0xf4,DAT_01012e14 + 0x73);
  }
  if (param_1 == 0) {
    iVar2 = DAT_01012e3c;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    iVar2 = DAT_01012e40;
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


// ===== FUN_01012afa @ 01012afa

undefined4 FUN_01012afa(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 == 0) {
    iVar2 = DAT_01012e3c;
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    iVar2 = DAT_01012e40;
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


// ===== FUN_01012b2a @ 01012b2a

void FUN_01012b2a(void)

{
  undefined4 uVar1;
  undefined4 extraout_r3;
  
  uVar1 = FUN_01012afa();
  FUN_01012a8c(extraout_r3,uVar1,0);
  return;
}


// ===== FUN_01012bca @ 01012bca

void FUN_01012bca(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x9a,DAT_01012e14 + 0x31,param_4,
                 param_4);
  }
  if ((*param_2 != 0x40) && (*param_2 != 0)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x9b,DAT_01012e14 + 0x31);
  }
  if ((*(uint *)(param_2 + 4) < 0x5b9) || (DAT_01012e48 <= *(uint *)(param_2 + 4))) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x9c,DAT_01012e14 + 0x31);
  }
  if ((param_2[10] != 0) && (param_2[10] != 2)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x9d,DAT_01012e14 + 0x31);
  }
  if ((param_2[0xb] != 0) && (param_2[0xb] != 0x10)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x9e,DAT_01012e14 + 0x31);
  }
  if ((param_2[9] != 0) && (param_2[9] != 8)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x9f,DAT_01012e14 + 0x31);
  }
  iVar7 = FUN_01014620(DAT_01012e4c,*(undefined4 *)(param_2 + 4));
  iVar6 = DAT_01012e40;
  iVar8 = DAT_01012e3c;
  bVar1 = param_2[10];
  bVar2 = param_2[8];
  bVar3 = param_2[0xb];
  bVar4 = param_2[9];
  bVar5 = *param_2;
  if (param_1 == 0) {
    *(undefined4 *)(DAT_01012e3c + 0x1c) = 0;
    uVar9 = DAT_01012e54;
  }
  else {
    *(undefined4 *)(DAT_01012e40 + 0x1c) = 0;
    iVar8 = iVar6;
    uVar9 = DAT_01012e50;
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


// ===== FUN_01012cd0 @ 01012cd0

bool FUN_01012cd0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DAT_01012e3c;
  }
  else {
    if (param_1 != 1) {
      FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0xd7,DAT_01012e14 + 0x4d);
    }
    iVar1 = DAT_01012e40;
  }
  return *(int *)(iVar1 + 0x28) >> 0x10 != 0;
}


// ===== FUN_01012d42 @ 01012d42

uint FUN_01012d42(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x138,DAT_01012e14 + 0x92,param_4,
                 param_4);
  }
  if (param_2 == 0) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_uar_01012e18,0x139,DAT_01012e14 + 0x92);
  }
  if (param_1 == 0) {
    piVar2 = (int *)(DAT_01012e3c + 0x28);
    puVar1 = (undefined1 *)(DAT_01012e3c + 0x24);
  }
  else {
    piVar2 = (int *)(DAT_01012e40 + 0x28);
    puVar1 = (undefined1 *)(DAT_01012e40 + 0x24);
  }
  for (; (0 < *piVar2 >> 0x10 && (uVar3 < param_3)); uVar3 = uVar3 + 1) {
    *(undefined1 *)(param_2 + uVar3) = *puVar1;
  }
  return uVar3;
}


// ===== FUN_01012e58 @ 01012e58

void FUN_01012e58(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_8 [4];
  
  puVar2 = DAT_01012f14;
  puVar1 = DAT_01012f10;
  if (param_1 == 0) {
    *DAT_01012f14 = local_8;
    puVar2[2] = (puVar2[2] & 0xffff) + 0x10000;
    *(undefined1 *)((int)puVar2 + 0xf) = 0x80;
    do {
    } while ((puVar2[4] & 1) == 0);
    return;
  }
  *DAT_01012f10 = local_8;
  puVar1[2] = (puVar1[2] & 0xffff) + 0x10000;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  do {
  } while ((puVar1[4] & 1) == 0);
  return;
}


// ===== FUN_01012ea4 @ 01012ea4

void FUN_01012ea4(int param_1,int param_2)

{
  if (param_1 == 0) {
    *(uint *)(DAT_01012f14 + 0x1c) = *(uint *)(DAT_01012f14 + 0x1c) & 0xffff00ff | param_2 << 8;
    return;
  }
  if (param_1 != 1) {
    FUN_01013f6e(DAT_01012f1c,0x18e,DAT_01012f18);
  }
  *(uint *)(DAT_01012f10 + 0x1c) = *(uint *)(DAT_01012f10 + 0x1c) & 0xffff00ff | param_2 << 8;
  return;
}


// ===== FUN_01012eec @ 01012eec

uint FUN_01012eec(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DAT_01012f14;
  }
  else {
    if (param_1 != 1) {
      FUN_01013f6e(DAT_01012f1c,0x1a7,DAT_01012f18 + 0x10);
    }
    iVar1 = DAT_01012f10;
  }
  return *(uint *)(iVar1 + 0x28) >> 0x10;
}


// ===== thunk_EXT_FUN_00004238 @ 01012f20

void thunk_EXT_FUN_00004238(void)

{
                    /* WARNING: Could not recover jumptable at 0x01012f22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01013184)();
  return;
}


// ===== thunk_EXT_FUN_0000425c @ 01012f24

void thunk_EXT_FUN_0000425c(void)

{
                    /* WARNING: Could not recover jumptable at 0x01012f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_01013184 + 0x24))();
  return;
}


// ===== FUN_01012fc8 @ 01012fc8

void FUN_01012fc8(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (8 < param_1) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_tim_0101318c,0x35,DAT_01013188 + 0x11);
  }
  iVar1 = DAT_010131b4;
  uVar2 = 4 << ((param_1 & 0x3f) << 2);
  if (param_2 == 1) {
    if (7 < param_1) {
      uVar2 = *(uint *)(DAT_010131b4 + 0xc) | 4;
      goto LAB_0101301e;
    }
    uVar2 = *(uint *)(DAT_010131b4 + 8) | uVar2;
  }
  else {
    if (param_2 != 0) {
      FUN_01013f6e(s_____________Librarier_sdk_yc_tim_0101318c,0x36,DAT_01013188 + 0x11);
    }
    if (7 < param_1) {
      uVar2 = *(uint *)(iVar1 + 0xc) & 0xfffffffb;
LAB_0101301e:
      *(uint *)(iVar1 + 0xc) = uVar2;
      return;
    }
    uVar2 = *(uint *)(iVar1 + 8) & ~uVar2;
  }
  *(uint *)(iVar1 + 8) = uVar2;
  return;
}


// ===== FUN_01013454 @ 01013454

void FUN_01013454(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 * 0x100 + DAT_010135b8);
  *puVar1 = param_2;
  puVar1[1] = param_4;
  puVar1[2] = param_3 << 0x10 | param_5;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  return;
}


// ===== FUN_0101346e @ 0101346e

void FUN_0101346e(int param_1)

{
  do {
  } while ((*(uint *)(param_1 * 0x100 + DAT_010135b8 + 0x10) & 1) == 0);
  return;
}


// ===== FUN_0101347c @ 0101347c

void FUN_0101347c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_01013454(6,param_2,param_3,param_1,param_3);
  FUN_0101346e(6);
  return;
}


// ===== FUN_01013536 @ 01013536

void FUN_01013536(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_010135ac;
  if (*DAT_010135ac == '\0') {
    *DAT_010135c8 = 0x800;
    *pcVar1 = '\x01';
    *(undefined1 *)(DAT_010135b0 + 0x1c) = 0x94;
    thunk_EXT_FUN_0000425c(10);
    FUN_01013a2e(1,0xd00000);
    thunk_EXT_FUN_0000425c(1);
    DAT_000c8010 = 1;
    thunk_EXT_FUN_0000425c(1);
    do {
    } while (-1 < (int)((uint)*(byte *)(DAT_010135c0 + 0x23) << 0x18));
    *(byte *)(DAT_010135c0 + 0x23) = *(byte *)(DAT_010135c0 + 0x23) & 0x7f;
  }
  return;
}


// ===== FUN_01013734 @ 01013734

void FUN_01013734(uint param_1)

{
  int iVar1;
  
  if (DAT_01013874 < param_1) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_sys_01013838,0x42,DAT_01013834 + 0x22);
  }
  iVar1 = DAT_01013868;
  *(uint *)(DAT_01013868 + 0x10) = *(uint *)(DAT_01013868 + 0x10) & 0xfffffffe;
  *(uint *)(iVar1 + 0x14) = param_1 - 1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *DAT_01013878 = 0;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 7;
  return;
}


// ===== FUN_0101378e @ 0101378e

void FUN_0101378e(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_01013868 + 0x10) & 0xfffffffe;
  }
  else {
    uVar1 = *(uint *)(DAT_01013868 + 0x10) | 1;
  }
  *(uint *)(DAT_01013868 + 0x10) = uVar1;
  return;
}


// ===== FUN_010137be @ 010137be

undefined4 FUN_010137be(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_1 = *DAT_01013878 - param_1;
  if (param_1 < 0) {
    param_1 = param_1 + DAT_0101387c;
  }
  uVar1 = FUN_01014620(DAT_01013864,(*(uint *)(DAT_01013860 + 0x20) & 0xf) + 2);
  uVar1 = FUN_01014620(uVar1,1000);
  uVar2 = FUN_01014620(param_1 * *(int *)(DAT_01013868 + 0x14),uVar1);
  if (uVar2 < param_2) {
    return 0;
  }
  return 1;
}


// ===== FUN_010138c2 @ 010138c2

void FUN_010138c2(uint param_1)

{
  *(uint *)(DAT_010139a0 + 0x1c) = *(uint *)(DAT_010139a0 + 0x1c) | 0x80;
  *(uint *)(DAT_01013998 + 0x20) = *(uint *)(DAT_01013998 + 0x20) & 0xfffffff0 | param_1;
  return;
}


// ===== FUN_010138da @ 010138da

void FUN_010138da(uint param_1)

{
  if (param_1 == 0) {
    (*DAT_010139a8)(DAT_010139a4,DAT_010139a4 + 0x40);
    FUN_010138c2(0);
    return;
  }
  if (((param_1 != 2) && (param_1 != 6)) && (param_1 != 0xe)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_sys_01013970,0x1f,DAT_0101396c + 0x2d);
  }
  *(uint *)(DAT_01013998 + 0x20) = *(uint *)(DAT_01013998 + 0x20) & 0xfffffff0 | param_1;
  return;
}


// ===== thunk_EXT_FUN_00004480 @ 010139bc

void thunk_EXT_FUN_00004480(void)

{
                    /* WARNING: Could not recover jumptable at 0x010139be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01013a1c)();
  return;
}


// ===== thunk_EXT_FUN_0000442c @ 010139c0

void thunk_EXT_FUN_0000442c(void)

{
                    /* WARNING: Could not recover jumptable at 0x010139c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(DAT_01013a1c + -0x54))();
  return;
}


// ===== FUN_01013a2e @ 01013a2e

void FUN_01013a2e(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  *(uint *)(DAT_01013c7c + 0x2c) = *(uint *)(DAT_01013c7c + 0x2c) & 0xffffdfff;
  iVar1 = DAT_01013c80;
  *(char *)(DAT_01013c80 + 0xc) = (char)param_2;
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


// ===== FUN_01013ca0 @ 01013ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01013ca0(uint param_1)

{
  if ((param_1 == 0) || (0x1f < param_1)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_wdt_01013d20,0xe,DAT_01013d1c);
  }
  _DAT_000f0000 = _DAT_000f0000 & 0xe0 | param_1;
  return;
}


// ===== FUN_01013cc4 @ 01013cc4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01013cc4(void)

{
  _DAT_000f0008 = DAT_01013d44;
  return;
}


// ===== FUN_01013cce @ 01013cce

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01013cce(void)

{
  _DAT_000f0000 = _DAT_000f0000 | 0x40;
  return;
}


// ===== FUN_01013cdc @ 01013cdc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01013cdc(int param_1)

{
  uint uVar1;
  
  _DAT_000f0000 = _DAT_000f0000 & 0xffffffdf | param_1 << 5;
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_01013d48 + 0x34) | 2;
  }
  else {
    uVar1 = *(uint *)(DAT_01013d48 + 0x34) & 0xfffffffd;
  }
  *(uint *)(DAT_01013d48 + 0x34) = uVar1;
  return;
}


// ===== FUN_01013d4c @ 01013d4c

void FUN_01013d4c(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  if ((*param_2 != 0) && (*param_2 != 8)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_spi_01013e5c,0xf,DAT_01013e58);
  }
  bVar1 = param_2[3];
  if (((((bVar1 != 0) && (bVar1 != 1)) && (bVar1 != 2)) && ((bVar1 != 3 && (bVar1 != 4)))) &&
     ((bVar1 != 5 && ((bVar1 != 6 && (bVar1 != 7)))))) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_spi_01013e5c,0x10,DAT_01013e58);
  }
  if ((param_2[1] != 0x20) && (param_2[1] != 0)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_spi_01013e5c,0x11,DAT_01013e58);
  }
  if ((param_2[2] != 0) && (param_2[2] != 0x10)) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_spi_01013e5c,0x12,DAT_01013e58);
  }
  if ((param_2[4] == 0) || (0x7e < param_2[4])) {
    FUN_01013f6e(s_____________Librarier_sdk_yc_spi_01013e5c,0x13,DAT_01013e58);
  }
  if (param_1 == 1) {
    iVar2 = DAT_01013e84;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    iVar2 = DAT_01013e80;
  }
  *(uint *)(iVar2 + 0x1c) =
       (uint)CONCAT11(param_2[4],*param_2 | param_2[3] | param_2[1] | param_2[2]);
  return;
}


// ===== FUN_01013df4 @ 01013df4

void FUN_01013df4(int param_1)

{
  undefined4 *puVar1;
  undefined1 local_8 [4];
  
  puVar1 = (undefined4 *)(param_1 * 0x100 + DAT_01013e88);
  *puVar1 = local_8;
  puVar1[2] = 0x10000;
  *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
  do {
  } while ((puVar1[4] & 1) == 0);
  return;
}


// ===== FUN_01013e32 @ 01013e32

void FUN_01013e32(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  
  if (param_3 != 0) {
    puVar1 = (undefined4 *)(param_1 * 0x100 + DAT_01013e88);
    *puVar1 = param_2;
    puVar1[1] = param_4;
    puVar1[2] = param_3 << 0x10 | param_5;
    *(undefined1 *)((int)puVar1 + 0xf) = 0x80;
    do {
    } while ((puVar1[4] & 1) == 0);
  }
  return;
}


// ===== FUN_01013ed8 @ 01013ed8

void FUN_01013ed8(uint param_1)

{
  *DAT_01013f14 = *DAT_01013f14 | 1 << (param_1 & 0xff);
  return;
}


// ===== FUN_01013ef2 @ 01013ef2

void FUN_01013ef2(void)

{
  *(uint *)(DAT_01013f18 + 0x34) = *(uint *)(DAT_01013f18 + 0x34) | 1;
  *(undefined4 *)(DAT_01013f18 + 0x3c) = 0x55;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_01013f02 @ 01013f02

void FUN_01013f02(void)

{
  return;
}


// ===== FUN_01013f3a @ 01013f3a

void FUN_01013f3a(void)

{
  return;
}


// ===== FUN_01013f3c @ 01013f3c

void FUN_01013f3c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  FUN_01013f3a(s__s__01013f70,param_3,param_3,param_4,param_4);
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    if ((uVar1 & 0xf) == 0) {
      FUN_01013f3a(s__08x__01013f78,iVar2);
      iVar2 = iVar2 + 0x10;
    }
    FUN_01013f3a(s__02x_01013f80,*(undefined1 *)(param_1 + uVar1));
  }
  return;
}


// ===== FUN_01013f6e @ 01013f6e

void FUN_01013f6e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_01013f88 @ 01013f88

void FUN_01013f88(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  iVar2 = DAT_01014388;
  iVar1 = DAT_01014384;
  local_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  FUN_0101247c(*(undefined1 *)(DAT_01014388 + 1),*(undefined2 *)(DAT_01014384 + 0x1c),0);
  iVar3 = (uint)*(byte *)(iVar2 + 1) * 0x10 + DAT_0101438c;
  *(undefined1 *)(iVar3 + 0xe) = 0x3f;
  FUN_0101247c(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar1 + 0x18),0);
  *(undefined1 *)(iVar3 + 0xc) = 0x3f;
  FUN_0101247c(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar1 + 0x16),0);
  *(undefined1 *)(iVar3 + 0xb) = 0x3f;
  FUN_0101247c(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar1 + 0x1e),0);
  *(undefined1 *)(iVar3 + 0xf) = 0x3f;
  local_20 = 0x1102000;
  local_1c = CONCAT31(local_1c._1_3_,1);
  FUN_0101247c(*(undefined1 *)(iVar2 + 2),*(undefined2 *)(iVar1 + 4),0x30);
  FUN_0101247c(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar1 + 0x18),0x31);
  FUN_0101247c(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar1 + 0x16),0x32);
  FUN_0101247c(*(undefined1 *)(iVar2 + 1),*(undefined2 *)(iVar1 + 0x1e),0x34);
  FUN_01013d4c(2,&local_20);
  return;
}


// ===== FUN_0101400e @ 0101400e

void FUN_0101400e(void)

{
  int iVar1;
  
  iVar1 = DAT_0101438c;
  *(undefined1 *)(DAT_0101438c + 0x1e) = 0x3e;
  FUN_01013df4(2,6);
  *(undefined1 *)(iVar1 + 0x1e) = 0x3f;
  return;
}


// ===== FUN_01014024 @ 01014024

ulonglong FUN_01014024(undefined1 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  
  iVar1 = DAT_0101438c;
  local_14 = param_3 & 0xffffff00;
  _local_10 = CONCAT31((int3)((uint)param_4 >> 8),param_1);
  *(undefined1 *)(DAT_0101438c + 0x1e) = 0x3e;
  FUN_01013e32(2,&local_10,1,&local_14);
  *(undefined1 *)(iVar1 + 0x1e) = 0x3f;
  return CONCAT44(1,local_14) & 0xffffffff000000ff;
}


// ===== FUN_0101404e @ 0101404e

void FUN_0101404e(void)

{
  uint uVar1;
  
  while( true ) {
    uVar1 = FUN_01014024(5);
    if ((uVar1 & 1) == 0) break;
    FUN_01013cc4();
    thunk_EXT_FUN_00004238(10);
  }
  return;
}


// ===== FUN_01014068 @ 01014068

void FUN_01014068(uint param_1)

{
  int iVar1;
  
  FUN_0101400e();
  FUN_0101404e();
  iVar1 = DAT_0101438c;
  *(undefined1 *)(DAT_0101438c + 0x1e) = 0x3e;
  FUN_01013df4(2,0x20);
  FUN_01013df4(2,(param_1 & 0xffffff) >> 0x10);
  FUN_01013df4(2,(param_1 & 0xffff) >> 8);
  FUN_01013df4(2,param_1 & 0xff);
  *(undefined1 *)(iVar1 + 0x1e) = 0x3f;
  FUN_0101404e();
  return;
}


// ===== FUN_010140a8 @ 010140a8

void FUN_010140a8(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_01014390;
  if (*(char *)(DAT_01014390 + 0x10) != '\0') {
    *(undefined1 *)(DAT_01014390 + 0x10) = 0;
    FUN_01010714(0,0,0xf0,0xf0,0);
    FUN_0101400e();
    FUN_0101404e();
    iVar1 = DAT_0101438c;
    *(undefined1 *)(DAT_0101438c + 0x1e) = 0x3e;
    FUN_01013df4(2,199);
    *(undefined1 *)(iVar1 + 0x1e) = 0x3f;
    *(undefined1 *)(iVar2 + 0x12) = 1;
    FUN_0101404e();
    *(undefined1 *)(iVar2 + 0x12) = 0;
    *(undefined1 *)(iVar2 + -0x17) = 1;
  }
  return;
}


// ===== FUN_010140f0 @ 010140f0

void FUN_010140f0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  FUN_0101400e();
  iVar1 = DAT_0101438c;
  *(undefined1 *)(DAT_0101438c + 0x1e) = 0x3e;
  FUN_01013df4(2);
  FUN_01013df4(2,(param_2 & 0xffffff) >> 0x10);
  FUN_01013df4(2,(param_2 & 0xffff) >> 8);
  FUN_01013df4(2,param_2 & 0xff);
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    FUN_01013df4(2,*(undefined1 *)(param_1 + uVar2));
  }
  *(undefined1 *)(iVar1 + 0x1e) = 0x3f;
  FUN_0101404e();
  return;
}


// ===== FUN_01014142 @ 01014142

void FUN_01014142(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  if (param_3 < 0x100) {
    FUN_010140f0(param_1,param_2,0x100,param_4,param_4);
    return;
  }
  for (uVar1 = 0; uVar1 < param_3 >> 8; uVar1 = uVar1 + 1) {
    FUN_010140f0(param_1,param_2,0x100);
    param_2 = param_2 + 0x100;
    param_1 = param_1 + 0x100;
  }
  return;
}


// ===== FUN_0101417c @ 0101417c

void FUN_0101417c(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
  iVar1 = DAT_0101438c;
  _local_14 = CONCAT13((char)param_2,
                       CONCAT12((char)((uint)param_2 >> 8),CONCAT11((char)((uint)param_2 >> 0x10),3)
                               ));
  *(undefined1 *)(DAT_0101438c + 0x1e) = 0x3e;
  FUN_01013e32(2,&local_14,4,param_1,param_3);
  *(undefined1 *)(iVar1 + 0x1e) = 0x3f;
  return;
}


// ===== FUN_010141fe @ 010141fe

void FUN_010141fe(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_01014394;
  if (*(int *)(DAT_01014394 + 0x74) != 0) {
    *(int *)(DAT_01014394 + 0x74) = *(int *)(DAT_01014394 + 0x74) + -1;
    *(int *)(iVar1 + 0x78) = *(int *)(iVar1 + 0x78) + 1;
    iVar3 = DAT_01014398;
    if (*(int *)(iVar1 + 0x2c) == 5) {
      FUN_01014068(*(int *)(iVar1 + 0x78) << 0xc);
      iVar3 = *(int *)(iVar1 + 0x78) << 0xc;
    }
    else {
      FUN_01014068(*(int *)(iVar1 + 0x2c) * 0xe000 + *(int *)(iVar1 + 0x78) * 0x1000 + DAT_01014398)
      ;
      iVar3 = *(int *)(iVar1 + 0x2c) * 0xe000 + *(int *)(iVar1 + 0x78) * 0x1000 + iVar3;
    }
    FUN_01014142(*(int *)(iVar1 + 0x6c) * 0x1000 + iVar1 + 0x7c,iVar3,0x1000);
    *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + 1;
    *(undefined1 *)(DAT_01014394 + 0x29) = 1;
    uVar2 = *(int *)(iVar1 + 0x6c) + 1;
    *(uint *)(iVar1 + 0x6c) = uVar2;
    if (9 < uVar2) {
      *(undefined4 *)(iVar1 + 0x6c) = 0;
    }
  }
  return;
}


// ===== FUN_0101427e @ 0101427e

void FUN_0101427e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_118 [42];
  undefined1 local_ee;
  undefined1 local_ed;
  undefined1 local_ec;
  undefined1 local_eb;
  undefined1 local_ea;
  undefined1 local_e9;
  undefined1 local_1a;
  undefined1 local_19;
  
  iVar2 = DAT_01014390;
  if (*(char *)(DAT_01014390 + -0x18) != '\0') {
    *(undefined1 *)(DAT_01014390 + -0x18) = 0;
    FUN_0101465a(local_118,0x100);
    iVar3 = 0;
    do {
      iVar4 = DAT_01014394 + iVar3;
      iVar1 = iVar3 * 7;
      local_118[iVar1] = *(undefined1 *)(iVar4 + 0x3f);
      local_118[iVar1 + 1] = *(undefined1 *)(iVar4 + 0x45);
      local_118[iVar1 + 2] = *(undefined1 *)(iVar4 + 0x4b);
      local_118[iVar1 + 3] = *(undefined1 *)(iVar4 + 0x51);
      local_118[iVar1 + 4] = *(undefined1 *)(iVar4 + 0x57);
      local_118[iVar1 + 5] = *(undefined1 *)(iVar4 + 0x5d);
      iVar3 = iVar3 + 1;
      local_118[iVar1 + 6] = *(undefined1 *)(iVar4 + 99);
    } while (iVar3 < 6);
    local_ee = (undefined1)*(undefined4 *)(DAT_01014394 + 0x2c);
    local_ed = *(undefined1 *)(DAT_01014394 + 0xc);
    local_ec = (undefined1)*(undefined4 *)(iVar2 + -0xc);
    local_eb = (undefined1)((uint)*(undefined4 *)(iVar2 + -0xc) >> 8);
    local_ea = *(undefined1 *)(DAT_01014394 + 0xe);
    local_e9 = *(undefined1 *)(DAT_01014390 + 2);
    local_1a = 0x55;
    local_19 = 0xaa;
    FUN_01014068(0);
    FUN_01014142(local_118,0,0x100);
    *(undefined1 *)(iVar2 + -0x17) = 1;
  }
  return;
}


// ===== FUN_01014314 @ 01014314

void FUN_01014314(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined1 local_118 [42];
  byte local_ee;
  undefined1 local_ed;
  ushort local_ec;
  undefined1 local_ea;
  undefined1 local_e9;
  char local_1a;
  char local_19;
  
  iVar1 = DAT_01014390;
  piVar6 = (int *)(DAT_01014390 + -0x20);
  if (*(char *)(DAT_01014390 + -0x17) != '\0') {
    *(undefined1 *)(DAT_01014390 + -0x17) = 0;
    FUN_0101465a(local_118,0x100);
    FUN_0101404e();
    FUN_0101417c(local_118,0,0x100);
    iVar2 = DAT_01014390;
    if ((local_1a == 'U') && (local_19 == -0x56)) {
      iVar3 = 0;
      do {
        iVar4 = iVar3 * 7;
        iVar7 = DAT_0101447c + iVar3;
        *(undefined1 *)(iVar7 + 0x3f) = local_118[iVar4];
        *(undefined1 *)(iVar7 + 0x45) = local_118[iVar4 + 1];
        *(undefined1 *)(iVar7 + 0x4b) = local_118[iVar4 + 2];
        *(undefined1 *)(iVar7 + 0x51) = local_118[iVar4 + 3];
        *(undefined1 *)(iVar7 + 0x57) = local_118[iVar4 + 4];
        *(undefined1 *)(iVar7 + 0x5d) = local_118[iVar4 + 5];
        *(undefined1 *)(iVar7 + 99) = local_118[iVar4 + 6];
        iVar4 = DAT_0101447c;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
      *(uint *)(DAT_0101447c + 0x2c) = (uint)local_ee;
      *(undefined1 *)(iVar4 + 0xc) = local_ed;
      uVar5 = (uint)local_ec;
    }
    else {
      iVar4 = 0;
      do {
        iVar3 = iVar4 * 7;
        local_118[iVar3] = 0;
        iVar7 = DAT_01014394 + iVar4;
        *(undefined1 *)(iVar7 + 0x3f) = 0;
        local_118[iVar3 + 1] = 0;
        *(undefined1 *)(iVar7 + 0x45) = 0;
        local_118[iVar3 + 2] = 0;
        *(undefined1 *)(iVar7 + 0x4b) = 0;
        local_118[iVar3 + 3] = 0;
        *(undefined1 *)(iVar7 + 0x51) = 0;
        local_118[iVar3 + 4] = 0;
        *(undefined1 *)(iVar7 + 0x57) = 0;
        local_118[iVar3 + 5] = 0;
        *(undefined1 *)(iVar7 + 0x5d) = 0;
        local_118[iVar3 + 6] = 0;
        *(undefined1 *)(iVar7 + 99) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 6);
      local_ee = 0;
      local_ed = 0;
      local_ec = 0x7e6;
      local_ea = 1;
      local_e9 = 0;
      local_1a = 0x55;
      local_19 = 0xaa;
      FUN_01014068(0);
      FUN_01014142(local_118,0,0x100);
      iVar4 = DAT_0101447c;
      *(uint *)(DAT_0101447c + 0x2c) = (uint)local_ee;
      *(undefined1 *)(iVar4 + 0xc) = local_ed;
      uVar5 = DAT_01014480;
    }
    *(uint *)(iVar1 + -0xc) = uVar5;
    *(undefined1 *)(iVar4 + 0xe) = local_ea;
    *(undefined1 *)(iVar2 + 2) = local_e9;
    iVar2 = DAT_0101447c;
    *piVar6 = (uint)*(byte *)(*(int *)(DAT_0101447c + 0x2c) + DAT_0101447c + 0x51) *
              (uint)*(byte *)(*(int *)(DAT_0101447c + 0x2c) + DAT_0101447c + 0x4b) * 2;
    *(undefined1 *)(iVar2 + 10) = *(undefined1 *)(iVar2 + 0xc);
    *(undefined1 *)(DAT_01014484 + 0x1c) = 1;
    *(undefined1 *)(iVar1 + -0x15) = 1;
    if (*(char *)(iVar2 + 10) == '\x04') {
      *(undefined4 *)(iVar2 + 0x34) = 0;
      *(undefined1 *)(iVar2 + 0x2b) = 0;
      *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar2 + 0x2c);
    }
    *(undefined1 *)(iVar1 + -1) = 0;
  }
  return;
}


// ===== FUN_01014488 @ 01014488

void FUN_01014488(void)

{
  int iVar1;
  
  iVar1 = DAT_0101461c;
  *(undefined1 *)(DAT_0101461c + 7) = 0x3f;
  *(undefined1 *)(iVar1 + 6) = 0x3f;
  thunk_EXT_FUN_00004238(1);
  *(undefined1 *)(iVar1 + 7) = 0x3e;
  thunk_EXT_FUN_00004238(1);
  *(undefined1 *)(iVar1 + 6) = 0x3e;
  thunk_EXT_FUN_00004238(1);
  return;
}


// ===== FUN_010144ac @ 010144ac

void FUN_010144ac(void)

{
  int iVar1;
  
  iVar1 = DAT_0101461c;
  *(undefined1 *)(DAT_0101461c + 6) = 0x3f;
  thunk_EXT_FUN_00004238(1);
  *(undefined1 *)(iVar1 + 7) = 0x3e;
  thunk_EXT_FUN_00004238(1);
  *(undefined1 *)(iVar1 + 7) = 0x3f;
  thunk_EXT_FUN_00004238(1);
  return;
}


// ===== FUN_010144ce @ 010144ce

void FUN_010144ce(void)

{
  int iVar1;
  byte bVar2;
  ushort *puVar3;
  
  iVar1 = DAT_0101461c;
  *(undefined1 *)(DAT_0101461c + 7) = 0;
  *(undefined1 *)(iVar1 + 6) = 0x3f;
  thunk_EXT_FUN_00004238(1);
  puVar3 = (ushort *)(DAT_0101461c + 0x20);
  for (bVar2 = 0; ((int)((uint)*puVar3 << 0x18) < 0 && (bVar2 < 0x1e)); bVar2 = bVar2 + 1) {
    thunk_EXT_FUN_00004238(1);
  }
  *(undefined1 *)(iVar1 + 6) = 0x3e;
  thunk_EXT_FUN_00004238(1);
  return;
}


// ===== FUN_01014506 @ 01014506

void FUN_01014506(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0101461c;
  uVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + 6) = 0x3e;
    if ((0x80U >> (uVar2 & 0xff) & param_1) == 0) {
      *(undefined1 *)(iVar1 + 7) = 0x3e;
    }
    else {
      *(undefined1 *)(iVar1 + 7) = 0x3f;
    }
    thunk_EXT_FUN_00004238(1);
    *(undefined1 *)(iVar1 + 6) = 0x3f;
    thunk_EXT_FUN_00004238(1);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 8);
  *(undefined1 *)(iVar1 + 6) = 0x3e;
  thunk_EXT_FUN_00004238(1);
  return;
}


// ===== FUN_01014540 @ 01014540

uint FUN_01014540(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_0101461c;
  uVar2 = 0;
  *(undefined1 *)(DAT_0101461c + 7) = 0;
  *(undefined1 *)(iVar1 + 6) = 0x3e;
  iVar3 = 0;
  do {
    uVar2 = (uVar2 & 0x7f) << 1;
    if ((int)((uint)*(ushort *)(DAT_0101461c + 0x20) << 0x18) < 0) {
      uVar2 = uVar2 | 1;
    }
    *(undefined1 *)(iVar1 + 6) = 0x3f;
    thunk_EXT_FUN_00004238(1);
    *(undefined1 *)(iVar1 + 6) = 0x3e;
    thunk_EXT_FUN_00004238(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  *(undefined1 *)(iVar1 + 7) = 0x3f;
  thunk_EXT_FUN_00004238(1);
  *(undefined1 *)(iVar1 + 6) = 0x3f;
  thunk_EXT_FUN_00004238(1);
  *(undefined1 *)(iVar1 + 6) = 0x3e;
  thunk_EXT_FUN_00004238(1);
  return uVar2;
}


// ===== FUN_01014596 @ 01014596

void FUN_01014596(undefined4 param_1,undefined4 param_2)

{
  FUN_01014488();
  FUN_01014506(0xa2);
  FUN_010144ce();
  FUN_01014506(param_1);
  FUN_010144ce();
  FUN_01014506(param_2);
  FUN_010144ce();
  FUN_010144ac();
  return;
}


// ===== FUN_010145c4 @ 010145c4

undefined4 FUN_010145c4(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_01014488();
  FUN_01014506(0xa2);
  FUN_010144ce();
  FUN_01014506(param_1);
  FUN_010144ce();
  FUN_01014488();
  FUN_01014506(0xa3);
  FUN_010144ce();
  uVar1 = FUN_01014540();
  FUN_010144ac();
  return uVar1;
}


// ===== FUN_010145fc @ 010145fc

uint FUN_010145fc(uint param_1)

{
  return (param_1 & 0xf) + (param_1 >> 4) * 10 & 0xff;
}


// ===== FUN_0101460c @ 0101460c

uint FUN_0101460c(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_01014620(param_1,10);
  return ((int)uVar1 << 4 | (uint)((ulonglong)uVar1 >> 0x20)) & 0xff;
}


// ===== FUN_01014620 @ 01014620

int FUN_01014620(uint param_1,uint param_2)

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


// ===== FUN_0101464c @ 0101464c

void FUN_0101464c(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_0101465a @ 0101465a

void FUN_0101465a(undefined4 param_1,undefined4 param_2)

{
  FUN_0101464c(param_1,param_2,0);
  return;
}


// ===== FUN_01014694 @ 01014694

void FUN_01014694(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = puRam010146b4;
  for (puVar3 = puRam010146b0; puVar3 < puVar1; puVar3 = puVar3 + 4) {
    (*(code *)puVar3[3])(*puVar3,puVar3[1],puVar3[2]);
  }
  uVar2 = thunk_FUN_0101046c();
                    /* WARNING: Could not recover jumptable at 0x010146be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_010146c0)(uVar2);
  return;
}


// ===== thunk_EXT_FUN_000000c6 @ 010146b8

void thunk_EXT_FUN_000000c6(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x010146be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_010146c0)(param_1);
  return;
}


// ===== __ARM_common_switch8 @ 010146c4

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
                    /* WARNING: Could not recover jumptable at 0x010146dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_lr + (uint)*(byte *)(unaff_lr + uVar1) * 2))();
  return;
}


// ===== thunk_FUN_010146e6 @ 010146de

void thunk_FUN_010146e6(undefined4 *param_1,undefined4 *param_2,int param_3)

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


// ===== FUN_010146e6 @ 010146e6

void FUN_010146e6(undefined4 *param_1,undefined4 *param_2,int param_3)

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


// ===== FUN_010146fc @ 010146fc

void FUN_010146fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint local_14;
  
  local_14 = param_4;
  FUN_01013f02();
  local_14 = 0;
  disableIRQinterrupts();
  thunk_EXT_FUN_0000442c();
  (*DAT_01014748)(param_1,&local_14,0,0,0);
  thunk_EXT_FUN_00004480();
  local_14 = local_14 << 0x18 | (local_14 >> 8 & 0xff) << 0x10 | (local_14 >> 0x10 & 0xff) << 8 |
             local_14 >> 0x18;
  uVar1 = FUN_01014844();
  thunk_EXT_FUN_00004404(DAT_0101474c,DAT_0101474c + 0xb2);
  FUN_01014890(local_14);
  FUN_010147f8(uVar1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_01014750 @ 01014750

void FUN_01014750(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  FUN_01013f02();
  disableIRQinterrupts();
  uVar4 = 0x20 - (param_1 & 0x1f);
  if (param_3 < uVar4) {
    uVar4 = param_3;
  }
  iVar3 = 0;
  while (param_3 != 0) {
    iVar1 = FUN_01014818(param_1,uVar4);
    if (iVar1 == 0) {
      thunk_EXT_FUN_00004404(param_1,param_1 + uVar4);
      for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
        *(undefined1 *)(param_2 + iVar3) = *(undefined1 *)(param_1 + uVar2);
        iVar3 = iVar3 + 1;
      }
    }
    else {
      FUN_0101464c(param_2 + iVar3,uVar4,0xff);
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


// ===== FUN_010147bc @ 010147bc

void FUN_010147bc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_01013f02();
  disableIRQinterrupts();
  uVar1 = FUN_01014844();
  thunk_EXT_FUN_0000442c();
  (*DAT_010147f4)(param_1,param_2,param_3,1,0);
  thunk_EXT_FUN_00004480();
  FUN_010147f8(uVar1);
  enableIRQinterrupts();
  return;
}


// ===== FUN_010147f8 @ 010147f8

void FUN_010147f8(uint param_1)

{
  thunk_EXT_FUN_00004404(DAT_01014814,DAT_01014814 + 0x40);
  FUN_01014924(param_1 & 0xffffff80,param_1 & 0xf);
  return;
}


// ===== FUN_01014818 @ 01014818

undefined4 FUN_01014818(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_01013f02();
  disableIRQinterrupts();
  thunk_EXT_FUN_0000442c();
  uVar1 = (*DAT_01014840)(param_1 & 0xffffffe0,param_1 + param_2);
  thunk_EXT_FUN_00004480();
  enableIRQinterrupts();
  return uVar1;
}


// ===== FUN_01014844 @ 01014844

uint FUN_01014844(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = *(uint *)(DAT_01014880 + 0x20) & 0xf;
  if ((*(uint *)(DAT_0101487c + 0x1c) & 0x80) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = uVar2 | uVar1;
  thunk_EXT_FUN_00004404(DAT_01014884,DAT_01014884 + 0x40);
  if (uVar1 == 0) {
    uVar1 = 2;
  }
  FUN_01014924(0,uVar1);
  return uVar2;
}


// ===== thunk_EXT_FUN_00004404 @ 01014888

void thunk_EXT_FUN_00004404(void)

{
                    /* WARNING: Could not recover jumptable at 0x0101488a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0101488c)();
  return;
}


// ===== FUN_01014890 @ 01014890

void FUN_01014890(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  undefined1 auStack_94 [128];
  
  iVar2 = DAT_01014918;
  iVar1 = DAT_01014918 + 0x80;
  FUN_0101465a(auStack_94 + DAT_01014918 + 0x80,0x1000);
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
    (*DAT_0101491c)(param_1,0x1000,auStack_94 + iVar1);
    (*(DAT_0101491c + -0x42))(param_1);
    for (iVar4 = 0; iVar4 < (int)(uVar3 & 0xff); iVar4 = iVar4 + 1) {
      auStack_94[uVar6 + iVar4 + iVar2 + 0x80] = 0xff;
    }
    (*DAT_01014920)(param_1,0x1000);
    param_1 = param_1 + 0x1000;
    uVar6 = 0;
    uVar3 = 0x24 - (uVar3 & 0xff);
    cVar5 = cVar5 + -1;
  }
  return;
}


// ===== FUN_01014924 @ 01014924

void FUN_01014924(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)(DAT_01014948 + 0x1c) & 0xffffff7f;
  }
  else {
    uVar1 = *(uint *)(DAT_01014948 + 0x1c) | 0x80;
  }
  *(uint *)(DAT_01014948 + 0x1c) = uVar1;
  *(uint *)(DAT_0101494c + 0x20) = *(uint *)(DAT_0101494c + 0x20) & 0xfffffff0 | param_2 & 0xf;
  return;
}


