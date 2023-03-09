#include <jvmti.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
#include "jvmInteractions.h"
#include "utils.h"

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

HINSTANCE loadJVMDll() {
    return LoadLibraryA("C:\\Program Files\\Java\\jdk-17.0.2\\bin\\server\\jvm.dll");
}

void freeLibrary(HMODULE jvmDll) {
    FreeLibrary(jvmDll);
}

JNI_CreateJavaVM_func getJNI_CreateJavaVM_func(HMODULE jvmDll) {
    JNI_CreateJavaVM_func JNI_CreateJavaVM_ptr = (JNI_CreateJavaVM_func) GetProcAddress(jvmDll, "JNI_CreateJavaVM");
    if (!JNI_CreateJavaVM_ptr) {
        printf("Failed to get address of JNI_CreateJavaVM function\n");
        exit(ERROR_EXIT);
    }
    return JNI_CreateJavaVM_ptr;
}

void createVM(JNI_CreateJavaVM_func createJavaVm_func, JavaVM **jvm, JNIEnv **env) {
    JavaVM *localVM;
    JNIEnv *localEnv;

    int optionsCount = 25;
    JavaVMOption options[optionsCount];
    JavaVMInitArgs args;

    options[0].optionString = "-Djava.compiler=JIT";
    options[1].optionString = formClassPath();
    options[2].optionString = "-Djava.library.path="
                              "D:\\IT\\Java\\PetProjects\\javaAgentTest\\out\\production\\javaAgentTest\\com\\tachycardiazxc\\native;.";
    options[3].optionString = "-verbose:jni";
    options[4].optionString = "-verbose:gc";
    options[5].optionString = "-verbose:class";
    options[6].optionString = "-Djava.awt.headless=true";
    options[7].optionString = "-Xms7G";
    options[8].optionString = "-Xmx8G";
    options[9].optionString = "-Dzomboid.steam=1";
    options[10].optionString = "-Dzomboid.znetlog=1";
    options[11].optionString = "-XX:-CreateCoredumpOnCrash";
    options[12].optionString = "-XX:-OmitStackTraceInFastThrow";
    options[13].optionString = "-XX:+UnlockExperimentalVMOptions";
    options[14].optionString = "-XX:+UseZGC";
    options[15].optionString = "-XX:NewSize=384m";
    options[16].optionString = "-XX:MaxNewSize=768m";
    options[17].optionString = "-XX:+AlwaysPreTouch";
    options[18].optionString = "-XX:SurvivorRatio=3";
    options[19].optionString = "-XX:TargetSurvivorRatio=90";
    options[20].optionString = "-XX:+UseCompressedOops";
    options[21].optionString = "-XX:+UseStringDeduplication";
    options[22].optionString = "-XX:+UseBiasedLocking";
    options[23].optionString = "-XX:+EnableJVMCI";
    options[24].optionString = "-XX:+EagerJVMCI";

    args.version = JNI_VERSION_1_8;
    args.nOptions = optionsCount;
    args.options = options;
    args.ignoreUnrecognized = JNI_FALSE;

    jint status = createJavaVm_func(&localVM, (void **) &localEnv, (void *) &args);
    if (status != JNI_OK) {
        printf("Failed to create JVM");
        exit(ERROR_EXIT);
    }

    *jvm = localVM;
    *env = localEnv;
}

void attachJVMTI(JavaVM **jvm, jvmtiEnv **jvmti) {
    JavaVM *localVM = *jvm;
    jvmtiEnv *localJvmti;

    (*localVM)->GetEnv(localVM, (void **) &localJvmti, JVMTI_VERSION_1_0);

    jvmtiCapabilities capabilities = getCapabilities();
    (*localJvmti)->AddCapabilities(localJvmti, &capabilities);
    (*localJvmti)->SetEventNotificationMode(localJvmti, JVMTI_ENABLE, JVMTI_EVENT_METHOD_ENTRY, NULL);

    *jvmti = localJvmti;
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

void getEntryClass(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz) {
    JNIEnv *localEnv = *env;
    jvmtiEnv *localJvmti = *jvmti;
    jclass localJClazz;

    (*localEnv)->FindClass(localEnv, "zombie/gameStates/GameState");
    (*localEnv)->FindClass(localEnv, "zombie/gameStates/MainScreenState");
    if ((*localEnv)->ExceptionCheck(localEnv)) {
        (*localEnv)->ExceptionDescribe(localEnv);
    }
    localJClazz = (*localEnv)->FindClass(localEnv, "zombie/gameStates/MainScreenState");
    if (localJClazz != NULL) {
        printf("Found my clazz\n");

        char *clazzSignature;
        char *clazzGeneric;

        (*localJvmti)->GetClassSignature(localJvmti, localJClazz, &clazzSignature, &clazzGeneric);

        printf("%s", clazzSignature);
        printf("%c", '\n');
    }

    *jclazz = localJClazz;
}

void getEntryMethod(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz, jmethodID *jmethod) {
    JNIEnv *localEnv = *env;
    jvmtiEnv *localJvmti = *jvmti;
    jclass localJClazz = *jclazz;
    jmethodID localMethod;

    localMethod = (*localEnv)->GetStaticMethodID(localEnv, localJClazz, "main", "([Ljava/lang/String;)V");

    if (localMethod != NULL) {
        printf("Found main method\n");

        char *methodName;
        char *methodSignature;
        char *methodGeneric;

        (*localJvmti)->GetMethodName(localJvmti, localMethod, &methodName, &methodSignature, &methodGeneric);

        printf("%s", methodName);
        printf("%c", '\n');
    }

    *jmethod = localMethod;
}

void getClassByName(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz, char *className) {
    JNIEnv *localEnv = *env;
    jvmtiEnv *localJvmti = *jvmti;
    jclass localJClazz;

    localJClazz = (*localEnv)->FindClass(localEnv, className);
    if (localJClazz != NULL) {
        printf("Found my clazz\n");

        char *clazzSignature;
        char *clazzGeneric;

        (*localJvmti)->GetClassSignature(localJvmti, localJClazz, &clazzSignature, &clazzGeneric);

        printf("%s", clazzSignature);
        printf("%c", '\n');
    }

    *jclazz = localJClazz;
}

void set_working_directory(JNIEnv **env, const char *path, jclass *clazz) {
    JNIEnv *localEnv = *env;

    jmethodID set_property_method = (*localEnv)->GetStaticMethodID(localEnv, *clazz, "setProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jmethodID get_property_method = (*localEnv)->GetStaticMethodID(localEnv, *clazz, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");

    jstring property_get_name = (*localEnv)->NewStringUTF(localEnv, "user.dir");
    jstring propertyValue = (*localEnv)->CallStaticObjectMethod(localEnv, *clazz, get_property_method, property_get_name);

    jboolean isCopy = TRUE;
    char* charString = (char *) (*localEnv)->GetStringUTFChars(localEnv, propertyValue, &isCopy);
    char *replaceValue = malloc(strlen(charString) - 28);
    strncpy(replaceValue, charString, strlen(charString) - 28);
    replaceValue[strlen(charString) - 28] = '\0';

    jstring property_name = (*localEnv)->NewStringUTF(localEnv, "user.dir");
    jstring property_value = (*localEnv)->NewStringUTF(localEnv, path);
    (*localEnv)->CallStaticObjectMethod(localEnv, *clazz, set_property_method, property_name, property_value);
    (*localEnv)->DeleteLocalRef(localEnv, property_name);
    (*localEnv)->DeleteLocalRef(localEnv, property_value);
    (*localEnv)->DeleteLocalRef(localEnv, *clazz);
    if (chdir(path) != 0) {
        printf("Error: failed to set working directory.\n");
    }
}
