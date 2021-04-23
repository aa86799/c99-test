//
// Created by austin stone on 2020/2/16.
//

#include "locale-test.h"
void locale_test() {
    /*
     * locale.h 头文件定义了特定地域的设置，比如日期格式和货币符号。
     * 宏
     *      LC_ALL  设置下面的所有选项。
     *      LC_COLLATE  影响 strcoll 和 strxfrm 函数。
     *      LC_CTYPE  影响所有字符函数。
     *      LC_MONETARY  影响 localeconv 函数提供的货币信息。
     *      LC_NUMERIC  影响 localeconv 函数提供的小数点格式化和信息。
     *      LC_TIME  影响 strftime 函数。
     * 函数
     *      char *setlocale(int category, const char *locale)  设置或读取地域化信息。  位于 locale.h
     *          category 属性使用上面的宏. locale 值为 地域-语言 字符串
     *          对于不同的平台和不同的编译器，地域设置的 locale值 可能会不同，C语言标准没有干预太多。
     *          C语言标准只是规定，各个组织在实现编译器时至少要支持以下三个名称：
     *              "C"是一种非常中立的地域设置，不偏向于任何一个地区，它会尽量少地包含地域设置信息，这些信息只是让C语言程序能够正常运行。
     *                  大多数情况下，"C"仅仅是对小数点进行了设置（设置为.），其它的信息都被置空。
     *              "" 空白设置，可以根据操作系统的版本自动地选语言、地域。并不是所有的编译器都能很好的支持。
     *              NULL 不会对地域设置进行任何修改，仅仅是返回系统的地域设置的名称。
     *
     *      struct lconv *localeconv(void)  设置或读取地域化信息。     位于 _locale.h
     *
     * 依赖了 _locale.h
     *      内部定义了结构体 lconv
     */
#define pd(no, n) printf("%s %d\n", no, n)
#define ps(no, n) printf("%s %s\n", no, n)
    ps("a.", setlocale(LC_ALL, "C")); //C
    ps("b.", setlocale(LC_ALL, "")); //en_US.UTF-8
    ps("c.", setlocale(LC_ALL, NULL)); //en_US.UTF-8
    ps("d.", setlocale(LC_ALL, "zh_CN")); //zh_CN
    ps("e.", setlocale(LC_ALL, "en_US")); //en_US
    struct lconv *lc = localeconv();
    ps("f. decimal_point: ", lc->decimal_point);//非货币值的小数点字符
    ps("g. thousands_sep: ", lc->thousands_sep);//非货币值的千位分隔符
    ps("h. grouping: ", lc->grouping);//非货币量中每组数字大小的字符串，没啥用。
    ps("i. int_curr_symbol: ", lc->int_curr_symbol);//国际货币符号使用的字符串。前三个字符是由 ISO 4217:1987 指定的，第四个字符用于分隔货币符号和货币量。
    ps("j. currency_symbol: ", lc->currency_symbol);//货币的本地符号
    ps("k. mon_decimal_point: ", lc->mon_decimal_point);//货币值的小数点字符
    ps("l. mon_thousands_sep: ", lc->mon_thousands_sep);//货币值的千位分隔符
    ps("m. mon_grouping: ", lc->mon_grouping);//没啥用
    ps("n. positive_sign: ", lc->positive_sign);//正货币值的字符
    ps("o. negative_sign: ", lc->negative_sign);//负货币值的字符
    pd("p. int_frac_digits:", lc->int_frac_digits);//国际货币值中小数点后要显示的位数
    pd("q. frac_digits:", lc->frac_digits);//货币值中小数点后要显示的位数
    pd("u. p_cs_precedes:", lc->p_cs_precedes);//如果等于 1，则 currency_symbol 出现在正货币值之前。如果等于 0，则 currency_symbol 出现在正货币值之后。
    pd("v. n_cs_precedes:", lc->n_cs_precedes);//如果等于 1，则 currency_symbol 出现在负货币值之前。如果等于 0，则 currency_symbol 出现在负货币值之后。
    pd("w. p_sep_by_space:", lc->p_sep_by_space);//如果等于 1，则 currency_symbol 和正货币值之间使用空格分隔。如果等于 0，则 currency_symbol 和正货币值之间不使用空格分隔。
    pd("x. n_sep_by_space:", lc->n_sep_by_space);//如果等于 1，则 currency_symbol 和负货币值之间使用空格分隔。如果等于 0，则 currency_symbol 和负货币值之间不使用空格分隔。
    pd("y. p_sign_posn:", lc->p_sign_posn);//正货币值中正号的位置
    pd("z. n_sign_posn:", lc->n_sign_posn);//负货币值中负号的位置
    pd("A. int_p_cs_precedes:", lc->int_p_cs_precedes);//国际货币中
    pd("B. int_n_cs_precedes:", lc->int_n_cs_precedes);//国际货币中
    pd("C. int_p_sep_by_space:", lc->int_p_sep_by_space);//国际货币中
    pd("D. int_n_sep_by_space:", lc->int_n_sep_by_space);//国际货币中
    pd("E. int_p_sign_posn:", lc->int_p_sign_posn);//国际货币中
    pd("F. int_n_sign_posn:", lc->int_n_sign_posn);//国际货币中

    char str[10][4] = { "C","堃","趙","B","孫","李","周","吳","鄭","王" };
    //stdlib::qsort 快速排序    string::strcoll 字符串比较
    qsort(str, 10, 4, (int (*)(const void *, const void *)) strcoll);
    printf("\n按音序排序："); //汉字的音序比较，对mac os 不支持，对windows和linux是可以的。
    for (int i = 0; i < 10; ++i) {
        printf("%s", str[i]);
    }
}