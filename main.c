#include <stdio.h>

#include "varlist.h"
#include "assert-test.h"
#include "ctype-test.h"
#include "errno-test.h"
#include "float-test.h"
#include "limits-test.h"
#include "locale-test.h"
#include "math-test.h"
#include "setjmp-test.h"
#include "signal-test.h"
#include "stddef-test.h"
#include "stdio-test.h"
#include "stdlib-test.h"
#include "string-test.h"
#include "time-test.h"

struct sdf {
    int cc;
    int dd;
};

void xxxd(struct sdf s) {
    
}

int main() {
//    stdarg_test(3, 77, 99, 100);
//    assert_test();
//    ctype_test('A');
//    errno_test();
//    float_test();
//    limits_test();
//    locale_test();
//    math_test();
//    setjpm_test();
//    signal_test();
//    stddef_test();
//    stdio_test();
//    stdlib_test();
//    string_test();
    time_test();
    printf("\nHello, World!\n");

    return 0;
}
