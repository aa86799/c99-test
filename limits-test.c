//
// Created by austin stone on 2020/2/16.
//

#include "limits-test.h"
void limits_test()
{
    /*
     * limits.h 头文件决定了各种变量类型的各种属性。在该头文件中的宏限制了各种变量类型（比如 char、int 和 long）的值.
     * 不同位数计算机，这些界限值不同。mac 本机 64位的。
     */
#define pi(no, n) printf("%s %d\n", no, n)//n 类型 为 int
#define pd(no, n) printf("%s %ld\n", no, n)//n 类型 为 long int。 对于 long long (int) 使用 %lld
#define pu(no, n) printf("%s %u\n", no, n)//n 类型 为 unsigned int
#define plu(no, n) printf("%s %lu\n", no, n)//n 类型 为 unsigned long int
#define pf(no, n) printf("%s %.10e\n", no, n) //10位有效数字，科学计数法(小写e)，n 类型为 double
#define pl(no, n) printf("%s %.10LE\n", no, n) //10位有效数字，科学计数法(大写e)，n 类型为 long double

    pi("a.", CHAR_BIT); //一个字节的比特数 8 bits
    pi("b.", SCHAR_MIN); //一个有符号字符的最小值 -128
    pi("c.", SCHAR_MAX); //一个有符号字符的最大值 127
    pi("d.", UCHAR_MAX); //一个无符号字符的最大值 255，(最小值为0)
    pi("e.", CHAR_MIN); //char 的最小值，如果 char 表示负值，则它的值等于 SCHAR_MIN，否则等于 0。
    pi("f.", CHAR_MAX); //char 的最大值，如果 char 表示负值，则它的值等于 SCHAR_MAX，否则等于 UCHAR_MAX。
    pi("g.", MB_LEN_MAX); //多字节字符中的最大字节数。
    pi("h.", SHRT_MIN); //一个短整型的最小值。 -32768 -->  -(1<<15) --> -(2^15)
    pi("i.", SHRT_MAX); //一个短整型的最大值。 32767  -->  1<<15 -1 --> 2^15 -1
    pi("j.", USHRT_MAX); //一个无符号短整型的最大值. 65535  -->  1<<16 -1 --> 2^16 -1
    pi("k.", INT_MIN); //一个整型的最小值. -(1<<31)
    pi("l.", INT_MAX); //一个整型的最大值. 1<<31 -1
    pu("m.", UINT_MAX); //一个无符号整型的最大值. 1<<32 -1
    pd("n.", LONG_MIN); //一个长整型的最小值.  -(1<<63)
    pd("o.", LONG_MAX); //一个长整型的最大值. 1<<63-1
    plu("p.", ULONG_MAX); //一个无符号长整型的最大值. 1<<64-1
    double v = ULONG_MAX;
    pf("q.", v);
    pd("r.", sizeof(v)); //double 所占字节
    long double vv = v;//将 double 赋值给 long double，类型升级
    pl("s.", vv);
    pd("t.", sizeof(vv));//long double 所占字节

//    long long aax = 88;
//    printf("%lld", aax);
}