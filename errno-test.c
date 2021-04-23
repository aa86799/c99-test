//
// Created by austin stone on 2020/2/16.
//

#include "errno-test.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void errno_test()
{
    /*
     * errno.h 头文件定义了整数变量 errno，它是通过系统调用设置的，表明在错误事件中的某些库函数发生了错误。
     * 该宏扩展为类型为 int 的可更改的左值，因此它可以被一个程序读取和修改。
     * 在程序启动时，errno 设置为零，C 标准库中的特定函数修改它的值为一些非零值以表示某些类型的错误。您也可以在适当的时候修改它的值或重置为零。
     * errno.h 头文件定义了一系列表示不同错误代码的宏，这些宏应扩展为类型为 int 。
     *
     */
    errno; //这是通过系统调用设置的宏，在错误事件中的某些库函数，发生了错误

    EDOM; //这个宏表示一个域错误，它在输入参数超出数学函数定义的域时发生，errno 被设置为 EDOM

    ERANGE; //这个宏表示一个范围错误，它在输入参数超出数学函数定义的范围时发生，errno 被设置为 ERANGE。

    // <errno.h> 中还有很多的宏，它们后面都有相应的注释，表示一个什么样的错误

    FILE *file = fopen("aaaa", "r");
    if (file == NULL) {
        printf("打开文件发生了错误，错误说明是：%s\n", strerror(errno));
    }

//    printf("%d\n", aa);

    //重置为零
    errno = 0;
}