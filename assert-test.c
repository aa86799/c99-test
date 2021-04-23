//
// Created by austin stone on 2020/2/15.
//

#include "assert-test.h"
void assert_test() {
    char *p = "stone";
    assert(p);
    char *q;
    assert(q);
    assert(3 > 0);
    assert(3 > 4); //断言失败，程序退出。 ASSERT 只有在 Debug 版本中才有效，如果编译为 Release 版本则被忽略。
}