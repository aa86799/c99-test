//
// Created by austin stone on 2020/2/20.
//

#include "stddef-test.h"
void stddef_test()
{
    /*
     * 标准定义 头文件
     * stddef .h 头文件定义了各种变量类型和宏。这些定义中的大部分也出现在其它头文件中
     * ptrdiff_t    这是有符号整数类型，它是两个指针相减的结果。
     * size_t       这是无符号整数类型，它是 sizeof 关键字的结果
     * wchar_t      这是一个宽字符常量大小的整数类型。
     * 宏
     *      NULL 空指针常量
     *      offsetof(type, member-designator)
     *              会生成一个类型为 size_t 的整型常量，是某个结构体、共用体的特定成员在结构体里面的偏移量
     *              成员是由 member-designator 给定的，结构的名称是在 type 中给定的。
     */
    struct T {
        int a;
        float b;
        char c;
    } s;
//    s.a = 10;
//    s.b = 8.5f;
//    s.c = 's';
    printf("偏移字节 %ld\n", offsetof(struct T, a));
    printf("偏移字节 %ld\n", offsetof(struct T, b));
    printf("偏移字节 %ld\n", offsetof(struct T, c));
    printf("\n");

    union TT {
        double d;
        struct T t;
        int x;
    };
    //对于共用体(联合体)来说，成员变量的地址是相同的，偏移量始终是0
    printf("偏移字节 %ld\n", offsetof(union TT, d));
    printf("偏移字节 %ld\n", offsetof(union TT, t));
    printf("偏移字节 %ld\n", offsetof(union TT, x));
    printf("\n");


}