//
// Created by austin stone on 2020/2/16.
//

#include "float-test.h"

void float_test()
{

#define pf(n) printf("%.2f\n", n)
    pf(3999.8888);

    /*
     * 浮点数在内存中以科学计数法的形式来存储，具体形式为：
     * flt = $ (-1)^sign × mantissa × base^exponent $
     *      flt 是要表示的浮点数。
     *      sign 用来表示 flt 的正负号，它的取值只能是 0 或 1：取值为 0 表示 flt 是正数，取值为 1 表示 flt 是负数。
     *      base 是基数，或者说进制，它的取值大于等于 2（例如，2 表示二进制、10 表示十进制、16 表示十六进制……）。
     *      mantissa 为尾数，或者说精度，是 base 进制的小数，并且 1 ≤ mantissa ＜ base，这意味着，小数点前面只能有一位数字。
     *      exponent 为指数，是一个整数，可正可负，并且为了直观一般采用十进制表示。
     *
     *
     * 以下宏的值是系统 特定实现的。
     * FLT 是指类型 float，DBL 是指类型 double，LDBL 是指类型 long double。
     */

    /*
     * 定义浮点加法的舍入模式，它可以是下列任何一个值：
     *  -1 - 无法确定
     *  0 - 趋向于零
     *  1 - 舍入到最接近的值。如对1.55保留1位精度， 是1.6；而 -1.55 是-1.5
     *  2 - 趋向于正无穷，向上舍入
     *  3 - 趋向于负无穷，向下舍入
     */
#define pi(no, n) printf("%s %d\n", no, n)
    pi("a.", FLT_ROUNDS);

    pi("b.", FLT_RADIX); //这个宏定义了指数表示的基数。基数 2 表示二进制，基数 10 表示十进制，基数 16 表示十六进制。一般为 2

    pi("c.", FLT_MANT_DIG); //float. 这三个宏定义了 基数（进制）为 FLT_RADIX 时，尾数 mantissa 的最大位数，注意，这里所说的长度包含了整数部分和小数部分。
    pi("d.", DBL_MANT_DIG); //double
    pi("e.", LDBL_MANT_DIG); //long double

    pi("f.", FLT_DIG); //float. 转换成十进制形式后，小数点后精确数字（能够保证精度的数字）的位数
    pi("g.", DBL_DIG); //double.
    pi("h.", LDBL_DIG); //long double.

    pi("i.", FLT_MIN_EXP); //float. 基数（进制）为 FLT_RADIX 时，规格化浮点数的指数（也即 exponent）的最小值（为负数）。
    pi("j.", DBL_MIN_EXP); //double.
    pi("k.", LDBL_MIN_EXP); //long double.

    pi("l.", FLT_MIN_10_EXP); //float. 转换成十进制形式后，规格化浮点数的指数的最小值（为负数）。
    pi("m.", DBL_MIN_10_EXP); //double.
    pi("n.", LDBL_MIN_10_EXP); //long double.

    pi("o.", FLT_MAX_EXP); //float. 基数（进制）为 FLT_RADIX 时，规格化浮点数的指数（也即 exponent）的最大值（为正数）。
    pi("p.", DBL_MAX_EXP); //double.
    pi("q.", LDBL_MAX_EXP); //long double.

    pi("r.", FLT_MAX_10_EXP); //float. 转换成十进制形式后，规格化浮点数的指数的最大值（为正数）。
    pi("s.", DBL_MAX_10_EXP); //double.
    pi("t.", LDBL_MAX_10_EXP); //long double.

#define pe(no, n) printf("%s %.5e\n", no, n) //科学记数法，小数位5位有效数字
    pe("u.", FLT_MAX); //float. 最大的有效浮点数的值（为正数），即浮点数的最大值。 正数
    pe("v.", DBL_MAX); //double.
#define ple(no, n) printf("%s %.5Le\n", no, n) //科学记数法，小数位5位有效数字。 long double
    ple("w. ", LDBL_MAX); //long double.

    pe("x. ", FLT_EPSILON); //float. 1 和大于 1 的最小浮点数之间的差值。 为负数
    pe("y. ", DBL_EPSILON); //double.
    ple("z. ", LDBL_EPSILON); //long double.

    pe("a. ", FLT_MIN); //float. 最小的有效浮点数的值（为负数），即浮点数的最小值。负数
    pe("b. ", DBL_MIN); //double.
    ple("c. ", LDBL_MIN); //long double.

    pe("d. ", FLT_MIN); //float. 最小的有效浮点数的值（为负数），即浮点数的最小值。负数
    pe("e. ", DBL_MIN); //double.
    ple("f. ", LDBL_MIN); //long double.

    /*
     * 指明在表达式求值（尤其是数学运算）过程中是否需要提升浮点数的类型，可能的取值有：
     * -1：未知的，不确定的。
     * 0：不提升类型，使用当前的类型。
     * 1：将浮点数提升到 double 类型，大于等于 double 类型的保持不变；也就是说，将 float 类型提升为 double 类型，double 和 long double 类型不变。
     * 2：将浮点数提升到 long double；也就是说，将 float、double 提升到 long double 类型，long double 类型保持不变。
     * FLT_EVAL_METHOD 对所有浮点数类型（float、double 和 long double）都有效，也就是说，所有浮点数类型都必须采用相同的类型提升.
     * > 提升类型能够提高浮点数的精度，让表达式的结果更加精确。
     * > 对于 GCC，在 32 位 x86 环境下，FLT_EVAL_METHOD 默认为 2；在 64 位 x86 环境下，
     *   FLT_EVAL_METHOD 默认为 0（可以通过编译选项 -mfpmath=387 将 FLT_EVAL_METHOD 的值设置为 2）。
     *
     */
    pi("g. ", FLT_EVAL_METHOD);

    /*
     * 在不损失精度精度的情况下，能够将 long double 转换成至少 DECIMAL_DIG 个十进制数字；
     * 反过来，也能将至少 DECIMAL_DIG 个十进制数字转换成 long double。
     * 也就是说，DECIMAL_DIG 是用于 long double 序列化和反序列化时的十进制精度。
     */
    pi("h. ", DECIMAL_DIG);

    //注意，FLT_EVAL_METHOD 和 DECIMAL_DIG 是在 C99 标准中新加入的两个宏。
}