//
// Created by austin stone on 2020/2/16.
//

#include "math-test.h"
void math_test()
{
    /*
     * math.h 头文件定义了各种数学函数和一个宏。库中所有可用的功能都带有一个 double 类型的参数，且都返回 double 类型的结果。
     * 宏
     *   HUGE_VAL
     *      当函数的结果不可以表示为浮点数时。如果是因为结果的幅度太大以致于无法表示，则函数会设置 errno 为 ERANGE 来表示范围错误，
     *      并返回一个由宏 HUGE_VAL 或者它的否定（- HUGE_VAL）命名的一个特定的很大的值.
     *      如果结果的幅度太小，则会返回零值。在这种情况下，errno 可能会被设置为 ERANGE，也有可能不会被设置为 ERANGE。
     *   M_ 开头的 常量宏
     *      M_E 自然对数 e
     *      M_LOG2E  log2(e) 2为底，e的对数,   2^对数值=e
     *      还有其它与圆周率 PI，和根号2相关的一些常量宏
     *
     */
#define pf(n) printf("%.2f\n", n)
#define pi(n) printf("%.3Le\n", n)
//    pf(M_PI);
//    pf(M_LOG10E);
    pf(acos(-1));//对double x 反余弦。输入值在区间[-1, 1]. x是弧度值。
    pf(acosh(1));//对double x 反双曲余弦。参数必须大于或等于 1。
    pf(acosf(0.5f));//对float x 反余弦。输入值在区间[-1, 1]. x是弧度值。
    pf(acoshf(M_PI));//对float x 反双曲余弦。参数必须大于或等于 1。
    pi(acosl(M_1_PI));//对long double x 反余弦。输入值在区间[-1, 1]. x是弧度值。
    pi(acoshl(99));//对long double x 反双曲余弦。参数必须大于或等于 1。
//  同样的有 反正弦、反双曲正弦 asin() asinh() ...
//  同样的有 余弦、双曲余弦 cos() cosh() ...
//  同样的有 正弦、双曲正弦 sin() sinh() ...
//  同样的有 正切、双曲正切 tan() tanh() ...

    pf(atan(18.5)); //反正切  x是弧度值
    //atan2(y,x) 弧度表示的 y/x 值的反正切，y 和 x 的值的符号决定了正确的象限。右上角第一象限，顺时针。
    pf(atan2(10, 18.5));

    pf(exp(5)); //自然对数e的n次幂

    int exponent;//指数
    double mantissa = frexp(5.8899, &exponent);//把一个浮点数分解为尾数和指数. 返回尾数，指数存到指针变量中。
    pf(mantissa);//尾数
    pf(mantissa * pow(2, exponent));// mantissa(尾数) * 2 ^ exponent = 原来的 数值。

    pf(ldexp(5, 8)); //n * 2 ^ exponent.  5*2^8
    pf(log(5)); //基数为 e 的 n 的对数
    pf(log10(5)); //基数为 10 的 n 的对数
    pf(log2(5)); //基数为 2 的 n 的对数

    double headInteger;
    pf(modf(10.889, &headInteger)); //返回值为小数部分，并设置 dv 为整数部分。
    pf(headInteger); //整数部分

    pf(sqrt(8)); //开平方
    pf(fabs(-8.99)); //绝对值
    pf(fmod(8, 3)); //x % y

    pf(ceil(8.5)); //返回大于或等于 x 的最小的整数值
    pf(ceil(-8.5)); //返回大于或等于 x 的最小的整数值
    pf(floor(8.5)); //返回小于或等于 x 的最大的整数值
    pf(floor(-8.5)); //返回小于或等于 x 的最大的整数值

}