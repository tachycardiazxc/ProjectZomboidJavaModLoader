#include "jvmThreadInteractions.h"
#include "exitCodeUtils.h"

void *suspendJVMThreads(void *args_ptr) {
    suspendAndResumeThreadListArgs args = *((suspendAndResumeThreadListArgs *) args_ptr);

    jvmtiEnv *jvmti = *args.jvmtiEnv_ptr;

    jvmtiError suspendingThreadListError;
    (*jvmti)->SuspendThreadList(jvmti, *args.threadsCount, *args.jthread_ptr, &suspendingThreadListError);
    if (suspendingThreadListError != JVMTI_ERROR_NONE) {
        printf("Failed to suspend thread list");
        pthread_exit((void *) &ERROR_EXIT);
    }

    pthread_exit((void *) &OK_EXIT);
}

void *resumeJVMThreads(void *args_ptr) {
    suspendAndResumeThreadListArgs args = *((suspendAndResumeThreadListArgs *) args_ptr);

    jvmtiEnv *jvmti = *args.jvmtiEnv_ptr;

    jvmtiError resumingThreadListError;
    (*jvmti)->ResumeThreadList(jvmti, *args.threadsCount, *args.jthread_ptr, &resumingThreadListError);
    if (resumingThreadListError != JVMTI_ERROR_NONE) {
        printf("Failed to resume thread list");
        pthread_exit((void *) &ERROR_EXIT);
    }

    pthread_exit((void *) &OK_EXIT);
}

getThreadsReturnValue getThreads(jvmtiEnv *jvmti) {
    jthread *threads;
    jint threadsCount;
    jvmtiError gettingThreadError = (*jvmti)->GetAllThreads(jvmti, &threadsCount, &threads);
    if (gettingThreadError != JVMTI_ERROR_NONE) {
        printf("Failed to get all threads");
        exit(ERROR_EXIT);
    }

    getThreadsReturnValue retVal;
    retVal.threads = &threads;
    retVal.threadCount = &threadsCount;
    return retVal;
}

void attachCurrentThreadToJVM(JavaVM **jvm) {
    JavaVM *localVM = *jvm;

    JavaVMAttachArgs attachArgs;
    attachArgs.version = JNI_VERSION_1_8;

    JNIEnv *currentEnv;
    jint result = (*localVM)->AttachCurrentThread(localVM, (void **) &currentEnv, (void *) &attachArgs);
    if (result != JNI_OK) {
        printf("Failed to attach current thread to VM");
        exit(ERROR_EXIT);
    }
}

pthread_t startThread(void *(*func)(void *), suspendAndResumeThreadListArgs **args) {
    suspendAndResumeThreadListArgs *localArgs = *args;

    pthread_t pthread;
    pthread_create(&pthread, NULL, func, (void *) localArgs);
    return pthread;
}
