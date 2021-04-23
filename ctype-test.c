//
// Created by austin stone on 2020/2/15.
//

#include "ctype-test.h"
void ctype_test(int c) {
    pp("a.", isalnum(c)); //是否是字母和数字
    pp("b.",isalpha(c)); //是否是字母
    pp("c.",iscntrl(0x05)); //是否是控制字符
    pp("d.",iscntrl(127)); //是否是控制字符。见ascii中的控制字符表 https://baike.baidu.com/item/%E6%8E%A7%E5%88%B6%E5%AD%97%E7%AC%A6/6913704?fr=aladdin
    pp("e.",isdigit(c));//是否是十进制数字
    pp("f.",isxdigit(c));//是否是十六进制数字
    pp("g.", isgraph(c));//是否为图形字符.会在屏幕上显示出来，这些字符就是图形字符.但是有个别的字符只占用位置却不显示,如空格 ' '
    pp("h.",islower(c));//是否为小写字母
    pp("i.", isupper(c));//是否为大写字母
    pp("j.",isprint(c));//是否为可打印的
    pp("k.",ispunct(c));//是否为标点符号字符. ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
    pp("l.",isspace(c));//是否为空白字符. 制表符、换行符、垂直制表符、换页符、回车符、空格符的集合。
//    pp( toascii(' '));//字符的 ascii 值.  好像是非标准库的函数

    printf("转成小写字符的int值，所对应的原字符是 %c\n", tolower(c));
    printf("转成大写字符的int值，所对应的原字符是 %c\n", toupper(c));
}