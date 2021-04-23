//
// Created by austin stone on 2020/2/22.
//

#include "string-test.h"
#include <mm_malloc.h>
#include <errno.h>
void string_test() {
    /*
     * string .h 头文件定义了一个变量类型、一个宏和各种操作字符数组的函数。
     *
     * size_t  这是无符号整数类型，它是 sizeof 关键字的结果。
     */

    char *str = "st中one";
    printf("a. %lu\n", strlen(str)); //字符串的字节长度，直到空结束字符，但不包括空结束字符

    /*
     *  memchr(const void *buf, int c, size_t n)
     *  str 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）的位置。
     *  返回 void* ，指向 第一个字符开始及之后所有字符 组成的字符串
     */
    void *p = memchr(str, 'o',   6); //当前utf8，汉字占3个字节。前6个字节中才有字符 'o'
    printf("b. %s\n", p);

    printf("c. 把两个字符串前 n 个字节进行比较，结果=%d\n", memcmp("stcne", "stone", 3)); //前n个字节比较，比较结果0是相等，负数排序在前，正负数排序在后

    char *dst = malloc(sizeof(char) * 5);
    printf("d. %s\n", memcpy(dst, str, 5)); //从 src 复制 n 个字节到 dest.  dst和str的内存区域不能重叠
    printf("e. %s\n", memmove(dst, str, 5)); //上面的结果是一样的。区别是，当内存发生局部重叠的时候，memmove保证拷贝的结果是正确的，memcpy不保证拷贝的结果的正确
    printf("f. dst=%s\n", dst); //设置dst中第n个位置的字符。
//    printf("%s\n", memset(dst, 'x', 2)); //设置dst中前n个字节的字符。

    printf("g. %s, contact 后: %s\n", strcat(dst, str), dst); //dst后追加字符串，会改变 dst
    printf("h. %s\n", strchr(dst, 't')); //dst中第一个字符及之后所有的 组成的 字符串
    printf("i. %s\n", strrchr(dst, 't')); //dst中最后一个字符及之后所有的 组成的 字符串
    printf("j. %d\n", strcmp(dst, str)); //比较两个字符串。比较结果0是相等，负数排序在前，正负数排序在后
    printf("k. %d\n", strncmp(dst, "sto", 3)); //比较前n个字节
    printf("l. %d， %s\n", strcoll(dst, "sto"), dst); //比较两个字符串。结果取决于 LC_COLLATE 的位置设置。
    printf("m. %s, %s\n", strcpy(dst, "abc"), dst); //将字符串复制给dst，并返回 dst 指向的字符串。   这时dst="abc"。 但dst之前的所在的连续内存空间并没有消除。 改变dst。
    printf("n. %s, %s\n", strncpy(dst, "中xyz", 3), dst); //将 n 个字节复制给dst。并返回 dst 指向的字符串。 改变dst
    printf("o. %s, %s\n", strncpy(dst, "中xyz", 4), dst); //将 n 个字节复制给dst。并返回 dst 指向的字符串。 当覆盖了dst之前所在的脏的连续空间时，会连带脏空间表示的所有字符一起输出。改变dst
    printf("p. %ld, %s\n", strcspn(dst, "中ab"), dst); //dst中，从头开始，连续几个字节，不包含后面的字符串中的任意字符。
    printf("q. %ld, %s\n", strcspn(dst, "abx"), dst); //dst中，从头开始，连续几个字节，不包含后面的字符串中的任意字符。
    printf("r. %ld, %s\n", strcspn(dst, "ymn"), dst); //dst中有n，第1个n出现 第12个字节。
    printf("s. %ld, %s\n", strspn(dst, "中x�st中"), dst); //返回字符串 dst 开头连续包含 后面字符串内的字符数目。 完全包含 输出10
    printf("s2. %ld, %s\n", strspn(dst, "中x"), dst); //返回字符串 dst 开头连续包含 后面字符串内的字符数目。完全包含输出5
    printf("s2. %ld, %s\n", strspn(dst, "x"), dst); //返回字符串 dst 开头连续包含 后面字符串内的字符数目。第一个字符就不同，输出0

    printf("t. error text : %s\n", strerror(EISDIR)); //通过<errno.h>中的标准错误的标号，获得错误的描述字符串

    printf("u. %s, %s\n", strpbrk(dst, "石tx"), dst); //从dst中依次检验 后面的字符串含有的字符。t、x在dst中都含有，dst中x靠前，返回x及以后的所有字符。不改变dst

    printf("v. %s, %s\n", strstr(dst, "t中"), dst); //返回 dst中完全匹配后面的字符串 开始及以后的所有字符。不完全匹配返回null， 不改变dst。

    printf("w. %ld, %s\n", strxfrm(dst, "y国", 5), dst); //根据程序当前的区域选项中的 LC_COLLATE 来转换。将dst的前 n 个字节，设置成 指定的字符串，并返回。会修改dst。
    printf("x. %s, %s\n", strncpy(dst, "abcdef", 6), dst); //证明，内存空间的连续区域上，超出 上面设的5个字节后，之前的脏数据依然存在。 所以，要注意字符串的 字节的复制操作。


}