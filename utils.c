#include <jvmti.h>
#include <windows.h>
#include "utils.h"

const int OK_EXIT = 1;
const int ERROR_EXIT = -1;

const char *CLASS_PATH_TO_PZ = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\";
const char *CLASS_PATH_TO_COMMONS = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\commons-compress-1.18.jar";
const char *CLASS_PATH_TO_ISTACK = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\istack-commons-runtime.jar";
const char *CLASS_PATH_TO_JASSIMP = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\jassimp.jar";
const char *CLASS_PATH_TO_JAVACORD = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\javacord-2.0.17-shaded.jar";
const char *CLASS_PATH_TO_JAVAX = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\javax.activation-api.jar";
const char *CLASS_PATH_TO_JAXB_API = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\jaxb-api.jar";
const char *CLASS_PATH_TO_JAXB_RUNTIME = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\jaxb-runtime.jar";
const char *CLASS_PATH_TO_LWJGL = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl.jar";
const char *CLASS_PATH_TO_LWJGL_NATIVES = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-natives-windows.jar";
const char *CLASS_PATH_TO_LWJGL_GLFW = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-glfw.jar";
const char *CLASS_PATH_TO_LWJGL_GLFW_NATIVES = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-glfw-natives-windows.jar";
const char *CLASS_PATH_TO_LWJGL_JEMALLOC = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-jemalloc.jar";
const char *CLASS_PATH_TO_LWJGL_JEMALLOC_NATIVES = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-jemalloc-natives-windows.jar";
const char *CLASS_PATH_TO_LWJGL_OPENGL = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-opengl.jar";
const char *CLASS_PATH_TO_LWJGL_OPENGL_NATIVES = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl-opengl-natives-windows.jar";
const char *CLASS_PATH_TO_LWJGL_UTIL= "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\lwjgl_util.jar";
const char *CLASS_PATH_TO_SQLITE = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\sqlite-jdbc-3.27.2.1.jar";
const char *CLASS_PATH_TO_TROVE = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\trove-3.0.3.jar";
const char *CLASS_PATH_TO_UNCOMMONS = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\ProjectZomboid\\uncommons-maths-1.2.3.jar";
const char *PATH_SEPARATOR = ";";

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
