#include <jvmti.h>
#include <windows.h>
#include "jvmPropertiesCreationConstantUtils.h"

jvmtiCapabilities getCapabilities() {
    jvmtiCapabilities capabilities = {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
    };
    return capabilities;
}

char *formClassPath() {
    char *optionPrefix = "-Djava.class.path=";
    char *classPathOption = malloc(
            strlen(optionPrefix) +
            (strlen(PATH_SEPARATOR) * 19) +
            strlen(CLASS_PATH_TO_PZ) +
            strlen(CLASS_PATH_TO_COMMONS) +
            strlen(CLASS_PATH_TO_ISTACK) +
            strlen(CLASS_PATH_TO_JASSIMP) +
            strlen(CLASS_PATH_TO_JAVACORD) +
            strlen(CLASS_PATH_TO_JAVAX) +
            strlen(CLASS_PATH_TO_JAXB_API) +
            strlen(CLASS_PATH_TO_JAXB_RUNTIME) +
            strlen(CLASS_PATH_TO_LWJGL) +
            strlen(CLASS_PATH_TO_LWJGL_NATIVES) +
            strlen(CLASS_PATH_TO_LWJGL_GLFW) +
            strlen(CLASS_PATH_TO_LWJGL_GLFW_NATIVES) +
            strlen(CLASS_PATH_TO_LWJGL_JEMALLOC) +
            strlen(CLASS_PATH_TO_LWJGL_JEMALLOC_NATIVES) +
            strlen(CLASS_PATH_TO_LWJGL_OPENGL) +
            strlen(CLASS_PATH_TO_LWJGL_OPENGL_NATIVES) +
            strlen(CLASS_PATH_TO_LWJGL_UTIL) +
            strlen(CLASS_PATH_TO_SQLITE) +
            strlen(CLASS_PATH_TO_TROVE) +
            strlen(CLASS_PATH_TO_UNCOMMONS)
    );

    strcpy(classPathOption, optionPrefix);
    strcat(classPathOption, CLASS_PATH_TO_PZ);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_COMMONS);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_ISTACK);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_JASSIMP);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_JAVACORD);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_JAVAX);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_JAXB_API);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_JAXB_RUNTIME);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_NATIVES);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_GLFW);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_GLFW_NATIVES);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_JEMALLOC);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_JEMALLOC_NATIVES);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_OPENGL);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_OPENGL_NATIVES);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_LWJGL_UTIL);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_SQLITE);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_TROVE);
    strcat(classPathOption, PATH_SEPARATOR);
    strcat(classPathOption, CLASS_PATH_TO_UNCOMMONS);

    return classPathOption;
}
