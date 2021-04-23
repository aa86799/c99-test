//
// Created by austin stone on 2020/2/15.
//

#include "varlist.h"
//第一个参数表示后面可变参数的个数
void stdarg_test(int num, ...) {
    va_list list;
    /* 为 num 个参数初始化 list */
    va_start(list, num); //这时，就把 ... 表示的可变参数 赋给了 list

    double sum = 0.0;
    /* 访问所有赋给 list 的参数 */
    for (int i = 0; i < num; ++i) {
        sum += va_arg(list, int); //宏检索函数参数列表中类型为 type 的下一个参数
        printf("sum=%f\n", sum);
    }
    /* 清理为 list 保留的内存. 与 va_start 宏 必须成对使用 */
    va_end(list);
    printf("arg=%.2f\n", sum/num);
}