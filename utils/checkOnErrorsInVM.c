#include <stdlib.h>
#include "checkOnErrorsInVM.h"
#include "exitCodeUtils.h"

void checkOnErrors(JNIEnv **env) {
    JNIEnv *localEnv = *env;

    if ((*localEnv)->ExceptionCheck(localEnv)) {
        (*localEnv)->ExceptionDescribe(localEnv);
        exit(ERROR_EXIT);
    }
}
