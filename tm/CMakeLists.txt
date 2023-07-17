cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)

add_compile_options(-fexceptions -frtti)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE tm_SRC CONFIGURE_DEPENDS *.cpp *.c)
add_library(tm STATIC ${tm_SRC})

target_include_directories(tm PUBLIC . fib hello)
target_include_directories(react_codegen_AppSpecs PUBLIC .)

target_link_libraries(tm
        jsi
        react_nativemodule_core
        react_codegen_AppSpecs)
