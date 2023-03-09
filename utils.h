#ifndef MODLOADER_UTILS_H
#define MODLOADER_UTILS_H

extern const int OK_EXIT;
extern const int ERROR_EXIT;

extern const char *CLASS_PATH_TO_PZ;
extern const char *CLASS_PATH_TO_COMMONS;
extern const char *CLASS_PATH_TO_ISTACK;
extern const char *CLASS_PATH_TO_JASSIMP;
extern const char *CLASS_PATH_TO_JAVACORD;
extern const char *CLASS_PATH_TO_JAVAX;
extern const char *CLASS_PATH_TO_JAXB_API;
extern const char *CLASS_PATH_TO_JAXB_RUNTIME;
extern const char *CLASS_PATH_TO_LWJGL;
extern const char *CLASS_PATH_TO_LWJGL_NATIVES;
extern const char *CLASS_PATH_TO_LWJGL_GLFW;
extern const char *CLASS_PATH_TO_LWJGL_GLFW_NATIVES;
extern const char *CLASS_PATH_TO_LWJGL_JEMALLOC;
extern const char *CLASS_PATH_TO_LWJGL_JEMALLOC_NATIVES;
extern const char *CLASS_PATH_TO_LWJGL_OPENGL;
extern const char *CLASS_PATH_TO_LWJGL_OPENGL_NATIVES;
extern const char *CLASS_PATH_TO_LWJGL_UTIL;
extern const char *CLASS_PATH_TO_SQLITE;
extern const char *CLASS_PATH_TO_TROVE;
extern const char *CLASS_PATH_TO_UNCOMMONS;
extern const char *PATH_SEPARATOR;

jvmtiCapabilities getCapabilities();
char *formClassPath();

#endif //MODLOADER_UTILS_H
