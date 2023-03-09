#ifndef MODLOADER_JVMINTERACTIONS_H
#define MODLOADER_JVMINTERACTIONS_H

#include <jni.h>
#include <jvmti.h>
#include <windows.h>
#include <pthread.h>

typedef jint (JNICALL *JNI_CreateJavaVM_func)(JavaVM **pVM, void **pEnv, void *args);

HINSTANCE loadJVMDll();
void freeLibrary(HMODULE jvmDll);
JNI_CreateJavaVM_func getJNI_CreateJavaVM_func(HMODULE jvmDll);
void createVM(JNI_CreateJavaVM_func createJavaVm_func, JavaVM **jvm, JNIEnv **env);
void attachJVMTI(JavaVM **jvm, jvmtiEnv **jvmti);


#endif //MODLOADER_JVMINTERACTIONS_H
