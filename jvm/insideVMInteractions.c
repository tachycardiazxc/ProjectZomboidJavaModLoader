#include <windows.h>
#include <unistd.h>
#include "insideVMInteractions.h"

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
