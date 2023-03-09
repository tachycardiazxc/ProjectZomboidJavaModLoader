#include <unistd.h>
#include "directVMInteractions.h"
#include "insideVMInteractions.h"
#include "jvmThreadInteractions.h"
#include "exitCodeUtils.h"

int main() {
    chdir("..\\..");

    HINSTANCE jvmDll = loadJVMDll();
    JNI_CreateJavaVM_func JNI_createJavaVM_ptr = getJNI_CreateJavaVM_func(jvmDll);

    JavaVM *jvm = malloc(1);
    JNIEnv *env = malloc(1);
    jvmtiEnv *jvmti = malloc(1);
    createVM(JNI_createJavaVM_ptr, &jvm, &env);
    attachJVMTI(&jvm, &jvmti);

    getThreadsReturnValue threadsReturnValue = getThreads(jvmti);
    attachCurrentThreadToJVM(&jvm);
    suspendAndResumeThreadListArgs *passingArgsToSuspendAndResumeMethod = malloc(1);
    passingArgsToSuspendAndResumeMethod->jvmtiEnv_ptr = &jvmti;
    passingArgsToSuspendAndResumeMethod->jthread_ptr = threadsReturnValue.threads;
    passingArgsToSuspendAndResumeMethod->threadsCount = threadsReturnValue.threadCount;

    pthread_t pthread_suspend = startThread(suspendJVMThreads, &passingArgsToSuspendAndResumeMethod);

    /* START OF JAVA EXECUTION */

    jclass jclazz;
    jmethodID jmethod;
    getEntryClass(&env, &jvmti, &jclazz);
    getEntryMethod(&env, &jvmti, &jclazz, &jmethod);

    const jchar *jcharArray = L"42";
    jstring jstr = (*env)->NewString(env, jcharArray, 2);
    jclass stringClass;
    getClassByName(&env, &jvmti, &stringClass, "java/lang/String");
    jobjectArray stringArray = (*env)->NewObjectArray(env, 1, stringClass, jstr);


    jclass systemClass;
    getClassByName(&env, &jvmti, &systemClass, "java/lang/System");
    set_working_directory(&env, "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid", &systemClass);

    (*env)->CallStaticVoidMethod(env, jclazz, jmethod, stringArray);

    /* END OF JAVA EXECUTION */

    pthread_t pthread_resume = startThread(resumeJVMThreads, &passingArgsToSuspendAndResumeMethod);

    int *exitCodeResumeThreads;
    int *exitCodeSuspendThread;
    pthread_join(pthread_resume, (void **) &exitCodeResumeThreads);
    pthread_join(pthread_suspend, (void **) &exitCodeSuspendThread);

    (*jvm)->DetachCurrentThread(jvm);
    (*jvm)->DestroyJavaVM(jvm);

    freeLibrary(jvmDll);

    if (*exitCodeResumeThreads == ERROR_EXIT || *exitCodeSuspendThread == ERROR_EXIT) {
        exit(ERROR_EXIT);
    }

    exit(OK_EXIT);

}
