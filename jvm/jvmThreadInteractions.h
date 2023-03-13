#ifndef MODLOADER_JVMTHREADINTERACTIONS_H
#define MODLOADER_JVMTHREADINTERACTIONS_H

#include <pthread.h>
#include <jvmti.h>

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
getThreadsReturnValue getThreads(jvmtiEnv *jvmti);
void attachCurrentThreadToJVM(JavaVM **jvm);
pthread_t startThread(void *(*func)(void *), suspendAndResumeThreadListArgs **args);

#endif //MODLOADER_JVMTHREADINTERACTIONS_H
