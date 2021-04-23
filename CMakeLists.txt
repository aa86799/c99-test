cmake_minimum_required(VERSION 3.19)
project(c99_test C)

set(CMAKE_C_STANDARD 99)

# 如，将另一个项目 untitled 做为共享库 SHARED， 并 链接
#add_library(untitled SHARED library.cpp library.h)

#默认无配置就是编译出 Debug版本。如下显式配置 Debug 或 Release
SET(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_BUILD_TYPE "Release")


add_executable(c99_Program main.c
        varlist.c varlist.h
        assert-test.c assert-test.h
        ctype-test.c ctype-test.h
        errno-test.c errno-test.h
        float-test.c float-test.h
        limits-test.c limits-test.h
        locale-test.c locale-test.h
        math-test.c math-test.h
        setjmp-test.c setjmp-test.h
        signal-test.c signal-test.h
        stddef-test.c stddef-test.h
        stdio-test.c stdio-test.h
        stdlib-test.c stdlib-test.h
        string-test.c string-test.h
        time-test.c time-test.h
        )