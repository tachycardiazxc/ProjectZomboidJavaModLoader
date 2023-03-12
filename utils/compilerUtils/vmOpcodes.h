//
// Created by tachycardiazxc on 12.03.2023.
//

#ifndef MODLOADER_METHODOPCODES_H
#define MODLOADER_METHODOPCODES_H

typedef struct ConstantOpcodes {
    unsigned int nop:8;
    unsigned int aconst_null:8;
    unsigned int iconst_m1:8;
    unsigned int iconst_0:8;
    unsigned int iconst_1:8;
    unsigned int iconst_2:8;
    unsigned int iconst_3:8;
    unsigned int iconst_4:8;
    unsigned int iconst_5:8;
    unsigned int lconst_0:8;
    unsigned int lconst_1:8;
    unsigned int fconst_0:8;
    unsigned int fconst_1:8;
    unsigned int fconst_2:8;
    unsigned int dconst_0:8;
    unsigned int dconst_1:8;
    unsigned int bipush:8;
    unsigned int sipush:8;
    unsigned int ldc:8;
    unsigned int ldc_w:8;
    unsigned int ldc2_w:8;
} constOps;

typedef struct {
    unsigned int iload:8;
    unsigned int lload:8;
    unsigned int fload:8;
    unsigned int dload:8;
    unsigned int aload:8;
    unsigned int iload_0:8;
    unsigned int iload_1:8;
    unsigned int iload_2:8;
    unsigned int iload_3:8;
    unsigned int lload_0:8;
    unsigned int lload_1:8;
    unsigned int lload_2:8;
    unsigned int lload_3:8;
    unsigned int fload_0:8;
    unsigned int fload_1:8;
    unsigned int fload_2:8;
    unsigned int fload_3:8;
    unsigned int dload_0:8;
    unsigned int dload_1:8;
    unsigned int dload_2:8;
    unsigned int dload_3:8;
    unsigned int aload_0:8;
    unsigned int aload_1:8;
    unsigned int aload_2:8;
    unsigned int aload_3:8;
    unsigned int iaload:8;
    unsigned int laload:8;
    unsigned int faload:8;
    unsigned int daload:8;
    unsigned int aaload:8;
    unsigned int baload:8;
    unsigned int caload:8;
    unsigned int saload:8;
} loadOps;

typedef struct {
    unsigned int istore:8;
    unsigned int lstore:8;
    unsigned int fstore:8;
    unsigned int dstore:8;
    unsigned int astore:8;
    unsigned int istore_0:8;
    unsigned int istore_1:8;
    unsigned int istore_2:8;
    unsigned int istore_3:8;
    unsigned int lstore_0:8;
    unsigned int lstore_1:8;
    unsigned int lstore_2:8;
    unsigned int lstore_3:8;
    unsigned int fstore_0:8;
    unsigned int fstore_1:8;
    unsigned int fstore_2:8;
    unsigned int fstore_3:8;
    unsigned int dstore_0:8;
    unsigned int dstore_1:8;
    unsigned int dstore_2:8;
    unsigned int dstore_3:8;
    unsigned int astore_0:8;
    unsigned int astore_1:8;
    unsigned int astore_2:8;
    unsigned int astore_3:8;
    unsigned int iastore:8;
    unsigned int lastore:8;
    unsigned int fastore:8;
    unsigned int dastore:8;
    unsigned int aastore:8;
    unsigned int bastore:8;
    unsigned int castore:8;
    unsigned int sastore:8;
} storeOps;

typedef struct {
    unsigned int pop:8;
    unsigned int pop2:8;
    unsigned int dup:8;
    unsigned int dup_x1:8;
    unsigned int dup_x2:8;
    unsigned int dup2:8;
    unsigned int dup2_x1:8;
    unsigned int dup2_x2:8;
    unsigned int swap:8;
} stackOps;

typedef struct {
    unsigned int iadd:8;
    unsigned int ladd:8;
    unsigned int fadd:8;
    unsigned int dadd:8;
    unsigned int isub:8;
    unsigned int lsub:8;
    unsigned int fsub:8;
    unsigned int dsub:8;
    unsigned int imul:8;
    unsigned int lmul:8;
    unsigned int fmul:8;
    unsigned int dmul:8;
    unsigned int idiv:8;
    unsigned int ldiv:8;
    unsigned int fdiv:8;
    unsigned int ddiv:8;
    unsigned int irem:8;
    unsigned int lrem:8;
    unsigned int frem:8;
    unsigned int drem:8;
    unsigned int ineg:8;
    unsigned int lneg:8;
    unsigned int fneg:8;
    unsigned int dneg:8;
    unsigned int ishl:8;
    unsigned int lshl:8;
    unsigned int ishr:8;
    unsigned int lshr:8;
    unsigned int iushr:8;
    unsigned int lushr:8;
    unsigned int iand:8;
    unsigned int land:8;
    unsigned int ior:8;
    unsigned int lor:8;
    unsigned int ixor:8;
    unsigned int lxor:8;
    unsigned int iinc:8;
} mathOps;

typedef struct {
    unsigned int i2l:8;
    unsigned int i2f:8;
    unsigned int i2d:8;
    unsigned int l2i:8;
    unsigned int l2f:8;
    unsigned int l2d:8;
    unsigned int f2i:8;
    unsigned int f2l:8;
    unsigned int f2d:8;
    unsigned int d2i:8;
    unsigned int d2l:8;
    unsigned int d2f:8;
    unsigned int i2b:8;
    unsigned int i2c:8;
    unsigned int i2s:8;
} conversionOps;

typedef struct {
    unsigned int lcmp:8;
    unsigned int fcmpl:8;
    unsigned int fcmpg:8;
    unsigned int dcmpl:8;
    unsigned int dcmpg:8;
    unsigned int ifeq:8;
    unsigned int ifne:8;
    unsigned int iflt:8;
    unsigned int ifge:8;
    unsigned int ifgt:8;
    unsigned int ifle:8;
    unsigned int if_icmpeq:8;
    unsigned int if_icmpne:8;
    unsigned int if_icmplt:8;
    unsigned int if_icmpge:8;
    unsigned int if_icmpgt:8;
    unsigned int if_icmple:8;
    unsigned int if_acmpeq:8;
    unsigned int if_acmpne:8;
} comparisonsOps;

typedef struct {
    unsigned int getstatic:8;
    unsigned int putstatic:8;
    unsigned int getfield:8;
    unsigned int putfield:8;
    unsigned int invokevirtual:8;
    unsigned int invokespecial:8;
    unsigned int invokestatic:8;
    unsigned int invokeinterface:8;
    unsigned int invokedynamic:8;
    unsigned int new:8;
    unsigned int newarray:8;
    unsigned int anewarray:8;
    unsigned int arraylength:8;
    unsigned int athrow:8;
    unsigned int checkcast:8;
    unsigned int instanceof:8;
    unsigned int monitorenter:8;
    unsigned int monitorexit:8;
} referencesOps;

typedef struct {
    unsigned int Goto:8;
    unsigned int jsr:8;
    unsigned int ret:8;
    unsigned int tableswitch:8;
    unsigned int lookupswitch:8;
    unsigned int ireturn:8;
    unsigned int lreturn:8;
    unsigned int freturn:8;
    unsigned int dreturn:8;
    unsigned int areturn:8;
    unsigned int Return:8;
} controlOps;

typedef struct {
    unsigned int wide:8;
    unsigned int multianewarray:8;
    unsigned int ifnull:8;
    unsigned int ifnonnull:8;
    unsigned int goto_w:8;
    unsigned int jsr_w:8;
} extendedOps;

typedef struct {
    unsigned int breakpoint:8;
    unsigned int impdep1:8;
    unsigned int impdep2:8;
} reservedOps;

static constOps constantOpcodes = {
        0x00,
        0x01,
        0x02,
        0x03,
        0x04,
        0x05,
        0x06,
        0x07,
        0x08,
        0x09,
        0x0a,
        0x0b,
        0x0c,
        0x0d,
        0x0e,
        0x0f,
        0x10,
        0x11,
        0x12,
        0x13,
        0x14
};

static loadOps loadOpcodes = {
        0x15,
        0x16,
        0x17,
        0x18,
        0x19,
        0x1a,
        0x1b,
        0x1c,
        0x1d,
        0x1e,
        0x1f,
        0x20,
        0x21,
        0x22,
        0x23,
        0x24,
        0x25,
        0x26,
        0x27,
        0x28,
        0x29,
        0x2a,
        0x2b,
        0x2c,
        0x2d,
        0x2e,
        0x2f,
        0x30,
        0x31,
        0x32,
        0x33,
        0x34,
        0x35
};

static storeOps storeOpcodes = {
        0x36,
        0x37,
        0x38,
        0x39,
        0x3a,
        0x3b,
        0x3c,
        0x3d,
        0x3e,
        0x3f,
        0x40,
        0x41,
        0x42,
        0x43,
        0x44,
        0x45,
        0x46,
        0x47,
        0x48,
        0x49,
        0x4a,
        0x4b,
        0x4c,
        0x4d,
        0x4e,
        0x4f,
        0x50,
        0x51,
        0x52,
        0x53,
        0x54,
        0x55,
        0x56
};

static stackOps stackOpcodes = {
        0x57,
        0x58,
        0x59,
        0x5a,
        0x5b,
        0x5c,
        0x5d,
        0x5e,
        0x5f
};

static mathOps mathOpcodes = {
        0x60,
        0x61,
        0x62,
        0x63,
        0x64,
        0x65,
        0x66,
        0x67,
        0x68,
        0x69,
        0x6a,
        0x6b,
        0x6c,
        0x6d,
        0x6e,
        0x6f,
        0x70,
        0x71,
        0x72,
        0x73,
        0x74,
        0x75,
        0x76,
        0x77,
        0x78,
        0x79,
        0x7a,
        0x7b,
        0x7c,
        0x7d,
        0x7e,
        0x7f,
        0x80,
        0x81,
        0x82,
        0x83,
        0x84
};

static conversionOps conversionOpcodes = {
        0x85,
        0x86,
        0x87,
        0x88,
        0x89,
        0x8a,
        0x8b,
        0x8c,
        0x8d,
        0x8e,
        0x8f,
        0x90,
        0x91,
        0x92,
        0x93
};

static comparisonsOps comparisonsOpcodes = {
        0x94,
        0x95,
        0x96,
        0x97,
        0x98,
        0x99,
        0x9a,
        0x9b,
        0x9c,
        0x9d,
        0x9e,
        0x9f,
        0xa0,
        0xa1,
        0xa2,
        0xa3,
        0xa4,
        0xa5,
        0xa6
};

static referencesOps referencesOpcodes = {
        0xb2,
        0xb3,
        0xb4,
        0xb5,
        0xb6,
        0xb7,
        0xb8,
        0xb9,
        0xba,
        0xbb,
        0xbc,
        0xbd,
        0xbe,
        0xbf,
        0xc0,
        0xc1,
        0xc2,
        0xc3
};

static controlOps controlOpcodes = {
        0xa7,
        0xa8,
        0xa9,
        0xaa,
        0xab,
        0xac,
        0xad,
        0xae,
        0xaf,
        0xb0,
        0xb1
};

static extendedOps extendedOpcodes = {
        0xc4,
        0xc5,
        0xc6,
        0xc7,
        0xc8,
        0xc9
};

static reservedOps reservedOpcodes = {
        0xca,
        0xfe,
        0xff
};


#endif //MODLOADER_METHODOPCODES_H
