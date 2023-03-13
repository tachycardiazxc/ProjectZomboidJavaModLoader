#ifndef MODLOADER_BODYREWRITER_H
#define MODLOADER_BODYREWRITER_H

#include <jni.h>
#include <jvmti.h>

typedef struct {
    unsigned char *bytecode;
    jint bytesCount;
} getByteCodeRetVal;

void rewriteBody(JNIEnv **env, jvmtiEnv **jvmti, jclass *class);

#endif //MODLOADER_BODYREWRITER_H
