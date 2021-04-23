//
// Created by austin stone on 2020/2/23.
//

#include "time-test.h"

void time_test() {
    /*
     * time.h 头文件定义了四个变量类型、两个宏和各种操作日期和时间的函数。
     *
     * size_t       是无符号整数类型，它是 sizeof 关键字的结果。 unsigned long
     * clock_t      这是一个适合存储处理器时间的类型。 本质是 unsigned long
     * time_t is    这是一个适合存储日历时间类型。  本质是 long
     * struct tm    这是一个用来保存时间和日期的结构
     * struct tm {
     *  int	tm_sec;		秒 [0,59]
     *  int	tm_min;		分 [0-59]
     *  int	tm_hour;	时 [0-23]
     *  int	tm_mday;	一月中的第几天，[1-31]
     *  int	tm_mon;		月，1月是0， [0-11]
     *  int	tm_year;	年，自 1900 年起的年数
     *  int	tm_wday;	一周中的第几天， [0-6]
     *  int	tm_yday;	一年中的第几天，[0-365]
     *  int	tm_isdst;	夏令时 标志
     *  long	tm_gmtoff;	以秒为单位的UTC时间。
     *  char	*tm_zone;	时区缩写
     * }
     *
     * 宏
     *  NULL            这个宏是一个空指针常量的值。
     *  CLOCKS_PER_SEC  这个宏表示每秒的处理器时钟个数。
     *
     *  下面的函数，time_t 和 tm 互转，从 time_t 和 tm 解析时间日期
     */

    clock_t start = clock();//返回程序执行起（一般为程序的开头），cpu所使用的时间。

    time_t tl;
    printf("a. %ld\n", time(&tl)); //计算当前日历时间，并把它编码成 time_t 格式
    struct tm *cur = localtime(&tl); //time_t 的值被分解为 tm 结构，并用本地时区表示。
    //返回的字符串格式为：Www Mmm dd hh:mm:ss yyyy。其中Www为星期；Mmm为月份；dd为日；hh为时；mm为分；ss为秒；yyyy为年份。
    printf("b. %s", asctime(cur)); //tm结构体中储存的时间转换为字符串。 自带换行符
    printf("c. %s", ctime(&tl)); //返回一个表示当地时间的字符串，当地时间是基于time_t 参数。自带换行符

    struct timespec ts;// = {3, 15000};
    ts.tv_sec = 3; //秒
    ts.tv_nsec = 1500;
    nanosleep(&ts, NULL); //当前线程睡眠 ts参数的秒值 时间。
    time_t ntl;
    printf("d. %f\n", difftime(tl, time(&ntl))); //前一个 time_t 减后一个 time_t 的差值秒数。返回值为 double

    //time_t 的值被分解为 tm 结构，并用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。
    struct tm *tmg = gmtime(&tl);//由于东八区，早(快)了8小时，所以时间，比当前少8小时。
    printf("e. %s", asctime(tmg));//tm结构体中储存的时间转换为字符串。 自带换行符
    printf("f. %ld\n", mktime(tmg));//所指向的结构转换为一个依据本地时区的 time_t 值

    char str[20];
    /*
     * size_t strftime(char *strDest, size_t maxsize, const char *format, const  struct tm *timeptr);
     * 根据format指向字符串中格式命令把timeptr中保存的时间信息放在strDest指向的字符串中，最多向strDest中存放maxsize个字符。
     * 该函数返回向strDest指向的字符串中放置的字符数，如果发生错误返回零。
     *
     * 格式化后的结果，若为  2020-02-23 12:13:53    这是19个字符，加个结尾的结束符'\0'，一共是20个字符。
     */
    size_t dstSize = strftime(str, 20, "%Y-%m-%d %T", tmg);
    //上面 maxsize =20， dstSize=19；  maxsize=19，dstSize=0
    printf("g. %s, dstSize=%lu\n", str, dstSize);

    printf("h. 程序所使用的时间：%lu\n", clock() - start);//发现clock()不含有线程睡眠花掉的时间。但线程睡眠的进入与唤醒会花费额外时间。
}
/*
 * strftime 中的 fromat格式化参数
 * %a 星期几的简写
%A 星期几的全称
%b 月份的简写
%B 月份的全称
%c 标准的日期的时间串
%C 年份的前两位数字
%d 十进制表示的每月的第几天
%D 月/天/年
%e 在两字符域中，十进制表示的每月的第几天
%F 年-月-日
%g 年份的后两位数字，使用基于周的年
%G 年份，使用基于周的年
%h 简写的月份名
%H 24小时制的小时
%I 12小时制的小时
%j 十进制表示的每年的第几天
%m 十进制表示的月份
%M 十时制表示的分钟数
%n 新行符
%p 本地的AM或PM的等价显示
%r 12小时的时间
%R 显示小时和分钟：hh:mm
%S 十进制的秒数
%t 水平制表符
%T 显示时分秒：hh:mm:ss
%u 每周的第几天，星期一为第一天 （值从1到7，星期一为1）
%U 第年的第几周，把星期日作为第一天（值从0到53）
%V 每年的第几周，使用基于周的年
%w 十进制表示的星期几（值从0到6，星期天为0）
%W 每年的第几周，把星期一做为第一天（值从0到53）
%x 标准的日期串
%X 标准的时间串
%y 不带世纪的十进制年份（值从0到99）
%Y 带世纪部分的十制年份
%z，%Z 时区名称，如果不能得到时区名称则返回空字符。
%% 百分号
 */