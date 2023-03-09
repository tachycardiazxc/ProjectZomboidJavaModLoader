#ifndef MODLOADER_INSIDEVMINTERACTIONS_H
#define MODLOADER_INSIDEVMINTERACTIONS_H

#include <jni.h>
#include <jvmti.h>

void getEntryClass(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz);
void getEntryMethod(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz, jmethodID *jmethod);
void getClassByName(JNIEnv **env, jvmtiEnv **jvmti, jclass *jclazz, char *className);
void set_working_directory(JNIEnv **env, const char *path, jclass *clazz);

#endif //MODLOADER_INSIDEVMINTERACTIONS_H
