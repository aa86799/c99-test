//
// Created by austin stone on 2020/2/21.
//

#include "stdlib-test.h"

void stdlib_test() {
    /*
     * stdlib .h 头文件定义了四个变量类型、一些宏和各种通用工具函数。
     * 变量
     *  size_t   这是无符号整数类型，它是 sizeof 关键字的结果。
     *  wchar_t  这是一个宽字符常量大小的整数类型。
     *  div_t    这是 div 函数返回的结构。
     *  ldiv_t  这是 ldiv 函数返回的结构
     *  宏
     *      NULL 这个宏是一个空指针常量的值。
     *      EXIT_FAILURE    这是 exit 函数失败时要返回的值。
     *      EXIT_SUCCESS    这是 exit 函数成功时要返回的值。
     *      RAND_MAX    这个宏是 rand 函数返回的最大值。
     *      MB_CUR_MAX  这个宏表示在多字节字符集中的最大字符数，不能大于 MB_LEN_MAX。
     */

//    gcvt()：将浮点型数转换为字符串，取四舍五入。
//    ecvt()：将双精度浮点型值转换为字符串，转换结果中不包含十进制小数点。
//    fcvt()：指定位数为转换精度，其余同ecvt()

//    atof()//把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型)
//    atoi()//把参数 str 所指向的字符串转换为一个整数（类型为 int 型)
//    atol()////把参数 str 所指向的字符串转换为一个浮点数（类型为 long int 型)

/*
 * strtod()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，到出现非数字或字符串结束时('\0')才结束转换，
 * 并将结果返回。若endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr传回。
 * 参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分。如123.456或123e-2
 */
//    strtod(const char *nptr,char **endptr)) //把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）.
//    strtof() //float
//    strtol() //long int
//    strtold() //long double
//    strtoll() //long long (int)
//    strtoul() //unsigned long
//    strtoull() //unsigned long long

/* toq touq 不知道内部是啥动作，结果随便参数变化 */
//    long long r1 = strtoq("99", NULL, 15);
//    printf("%lld", r1);
//    strtouq()

    //内存分配
//    malloc() malloc/_malloc.h
//    calloc() malloc/_malloc.h
//    realloc() malloc/_malloc.h
//    alloca() //栈内存分配 alloca.h
//    free() //释放堆内存 malloc/_malloc.h
    size_t len = 10;
    int *ary = calloc(len, sizeof(int));//分配连续空间并初始化
    for (int i = 0; i < len; ++i)
    {
        ary[i] = rand() / (RAND_MAX + 1.0) * 10; //[0,1) 间的随机数 *10
    }
    for (int i = 0; i < len; i++)
    {
        ary++;
        printf("元素%d=%d\n", i, *ary);
    }

//    abort(); //使一个异常程序终止。
//    int atexit(void (*func)(void));// 当程序正常终止时，调用指定的函数 func。
//    exit(int) //使程序正常终止。
//    char* getenv(char*) //搜索 name 所指向的环境字符串，并返回相关的值给字符串。
//    int system(char*) //由 string 指定的命令传给要被命令处理器执行的主机环境。
//    bsearch() //二分查找
//    qsort() //数组排序
//    abs() //绝对值
//    labs() //绝对值，long int
    printf("r=%d, =%d\n", div(14, 3).quot, div(14, 3).rem); //除法 14/3， 返回div_t， 内部两个变量，商多少，余多少
    printf("r=%ld, =%ld\n", ldiv(14, 3).quot, ldiv(14, 3).rem); //除法 14/3， 返回 ldiv_t，内部两个变量， 商多少，余多少

    printf("%d\n", rand()); //返回一个范围在 0 到 RAND_MAX 之间的伪随机数。
    printf("%d\n", rand()); //返回一个范围在 0 到 RAND_MAX 之间的伪随机数。
    unsigned int t;
    printf("%d, %d\n", rand_r(&t), t); //返回一个范围在 0 到 RAND_MAX 之间的伪随机数。并赋值给 &t
    unsigned int tt = 100;
//   printf("%d, %d\n", srand(tt), t); //srand 和rand()配合使用产生伪随机数序列

//    int mblen(const char *str, size_t n) //返回参数 str 所指向的多字节字符的长度。
//    size_t mbstowcs(schar_t *pwcs, const char *str, size_t n) //把参数 str 所指向的多字节字符的字符串转换为参数 pwcs 所指向的数组
//    int mbtowc(whcar_t *pwc, const char *str, size_t n) //检查参数 str 所指向的多字节字符。
//    size_t wcstombs(char *str, const wchar_t *pwcs, size_t n) //把数组 pwcs 中存储的编码转换为多字节字符，并把它们存储在字符串 str 中
//    int wctomb(char *str, wchar_t wchar) //检查对应于参数 wchar 所给出的多字节字符的编码
}