#include "directVMInteractions.h"
#include "jvmPropertiesCreationUtils.h"
#include "exitCodeUtils.h"

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
                              "D:\\IT\\Java\\PetProjects\\javaAgentTest\\";
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
