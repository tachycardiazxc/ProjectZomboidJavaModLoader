#ifndef MODLOADER_JVMPROPERTIESCREATIONUTILS_H
#define MODLOADER_JVMPROPERTIESCREATIONUTILS_H

#include <jvmti.h>

jvmtiCapabilities getCapabilities();
char *formClassPath();

#endif //MODLOADER_JVMPROPERTIESCREATIONUTILS_H
