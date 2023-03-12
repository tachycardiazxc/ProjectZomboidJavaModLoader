cmake_minimum_required(VERSION 3.24)
project(ModLoader C)

set(CMAKE_C_STANDARD 11)
set(JNI_INCLUDE_DIRS "C:\\Program Files\\Java\\jdk-17.0.2\\include")
set(LIBWINPTHREAD_LIB .\\libs)

add_executable(
        main main.c
        utils/jvmPropertiesCreationUtils.c utils/jvmPropertiesCreationUtils.h
        utils/jvmPropertiesCreationConstantUtils.h utils/exitCodeUtils.c utils/exitCodeUtils.h
        utils/checkOnErrorsInVM.c utils/checkOnErrorsInVM.h
        utils/compilerUtils/vmOpcodes.h
        jvm/directVMInteractions.c jvm/directVMInteractions.h
        jvm/jvmThreadInteractions.c jvm/jvmThreadInteractions.h
        jvm/insideVMInteractions.c jvm/insideVMInteractions.c
        jvm/bodyRewriter.c jvm/bodyRewriter.h
        )

include_directories(utils jvm)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
target_link_libraries(main ${JNI_LIBRARIES})
