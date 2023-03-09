#include <jni.h>
#include <jvmti.h>
#include <windows.h>
#include <pthread.h>

#ifndef MODLOADER_JVMINTERACTIONS_H
#define MODLOADER_JVMINTERACTIONS_H

typedef jint (JNICALL *JNI_CreateJavaVM_func)(JavaVM **pVM, void **pEnv, void *args);

typedef struct SuspendAndResumeThreadListArgs {
    jvmtiEnv **jvmtiEnv_ptr;
    jint *threadsCount;
    jthread **jthread_ptr;
} suspendAndResumeThreadListArgs;

typedef struct GetThreadsReturnValue {
    jthread **threads;
    jint *threadCount;
} getThreadsReturnValue;

void *suspendJVMThreads(void *args_ptr);
void *resumeJVMThreads(void *args_ptr);
HINSTANCE loadJVMDll();
void freeLibrary(HMODULE jvmDll);
JNI_CreateJavaVM_func getJNI_CreateJavaVM_func(HMODULE jvmDll);
void createVM(JNI_CreateJavaVM_func createJavaVm_func, JavaVM **jvm, JNIEnv **env);
void attachJVMTI(JavaVM **jvm, jvmtiEnv **jvmti);
getThreadsReturnValue getThreads(jvmtiEnv *jvmti);
void attachCurrentThreadToJVM(JavaVM **jvm);
pthread_t startThread(void *(*func)(void *), suspendAndResumeThreadListArgs **args);
void getEntryClass(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz);
void getEntryMethod(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz, jmethodID *jmethod);
void getClassByName(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz, char *className);
void set_working_directory(JNIEnv **env, const char *path, jclass *clazz);


#endif //MODLOADER_JVMINTERACTIONS_H
