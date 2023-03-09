cmake_minimum_required(VERSION 3.24)
project(ModLoader C)

set(CMAKE_C_STANDARD 11)
set(JNI_INCLUDE_DIRS C:\\Program Files\\Java\\jdk-17.0.2\\include)

add_executable(main main.c utils.c utils.h jvmInteractions.c jvmInteractions.h)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
target_link_libraries(main ${JNI_LIBRARIES})
