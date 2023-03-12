#include <stdlib.h>
#include "bodyRewriter.h"
#include "checkOnErrorsInVM.h"

getByteCodeRetVal getByteCode(JNIEnv *env, jstring className) {
    // Get the system class loader
    jclass systemClass = (*env)->FindClass(env, "java/lang/ClassLoader");
    jmethodID getSystemClassLoader = (*env)->GetStaticMethodID(env, systemClass, "getSystemClassLoader", "()Ljava/lang/ClassLoader;");
    jobject systemClassLoaderObj = (*env)->CallStaticObjectMethod(env, systemClass, getSystemClassLoader);

    // Get the resource as a stream
    jclass stringClass = (*env)->FindClass(env, "java/lang/String");
    jmethodID getResourceAsStream = (*env)->GetMethodID(env, (*env)->GetObjectClass(env, systemClassLoaderObj), "getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;");
    jstring resourceName;
    resourceName = (*env)->CallObjectMethod(env, className, (*env)->GetMethodID(env, stringClass, "replace", "(CC)Ljava/lang/String;"), '.', '/');
    checkOnErrors(&env);
    jmethodID concatMethod = (*env)->GetMethodID(env, stringClass, "concat", "(Ljava/lang/String;)Ljava/lang/String;");
    checkOnErrors(&env);
    resourceName = (*env)->CallObjectMethod(env, resourceName, concatMethod, (*env)->NewStringUTF(env, ".class"));
    jboolean b = JNI_TRUE;
    const char* chars = (*env)->GetStringUTFChars(env, resourceName, &b);
    checkOnErrors(&env);
    jobject streamObj = (*env)->CallObjectMethod(env, systemClassLoaderObj, getResourceAsStream, resourceName);
    checkOnErrors(&env);

    // Read the bytecode into a buffer
    jclass streamClass = (*env)->GetObjectClass(env, streamObj);
    jmethodID read = (*env)->GetMethodID(env, streamClass, "read", "([B)I");
    jbyteArray buffer = (*env)->NewByteArray(env, 1024);
    jbyteArray bytecode = NULL;
    jint bytesRead = 0;
    do {
        bytesRead = (*env)->CallIntMethod(env, streamObj, read, buffer);
        if (bytesRead > 0) {
            if (bytecode == NULL) {
                bytecode = (*env)->NewByteArray(env, bytesRead);
                (*env)->SetByteArrayRegion(env, bytecode, 0, bytesRead, (jbyte*)buffer);
            }
            else {
                int currentLength = (*env)->GetArrayLength(env, bytecode);
                int newLength = currentLength + bytesRead;
                (*env)->SetByteArrayRegion(env, bytecode, currentLength, bytesRead, (jbyte*)buffer);
            }
        }

        jbyte *elements = (*env)->GetByteArrayElements(env, buffer, NULL);
        if (elements == NULL) {
            // Handle error
        }
        unsigned char *bytes = (unsigned char *)elements;

        for (int i = 0; i < 2048; ++i) {
            printf("%c", bytes[i]);
        }
        int a = 1;
    } while (bytesRead > 0);

    exit(-1);

//    (*env)->ReleaseByteArrayElements(env, bytecode, elements, 0);

    // Clean up
    (*env)->DeleteLocalRef(env, systemClass);
    (*env)->DeleteLocalRef(env, systemClassLoaderObj);
    (*env)->DeleteLocalRef(env, resourceName);
    (*env)->DeleteLocalRef(env, streamObj);
    (*env)->DeleteLocalRef(env, buffer);

    getByteCodeRetVal retVal;
    retVal.bytecode = NULL;
    retVal.bytesCount = bytesRead;

    return retVal;
}

void rewriteBody(JNIEnv **env, jvmtiEnv **jvmti, jclass *class) {
    JNIEnv *localEnv = *env;
    jvmtiEnv *localJvmti = *jvmti;
    jstring className = (*localEnv)->NewStringUTF(localEnv, "zombie.gameStates.MainScreenState");

    getByteCodeRetVal retVal = getByteCode(localEnv, className);

    jvmtiClassDefinition classDefinitionData;
    classDefinitionData.class_bytes = retVal.bytecode;
    classDefinitionData.class_byte_count = retVal.bytesCount;
    classDefinitionData.klass = *class;

    jvmtiError error = (*localJvmti)->RedefineClasses(localJvmti, 1, &classDefinitionData);
    int a = 1;
}
