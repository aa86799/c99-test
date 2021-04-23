//
// Created by austin stone on 2020/2/17.
//

#include "signal-test.h"
#include <stdlib.h>
sig_atomic_t signaled = 0; //信息处理变量
void my_handler (int param)
{
    signaled = 1;
    printf("param=%d\n", param);
}

void signal_test()
{
    /*
     * signal.h 头文件定义了一个变量类型 sig_atomic_t、两个函数调用和一些宏来处理程序执行期间报告的不同信号
     * sig_atomic_t 这是 int 类型，在信号处理程序中作为变量使用。它是一个对象的整数类型
     * 宏
     *      SIG_DFL 默认的信号处理程序
     *      SIG_ERR 表示一个信号错误
     *      SIG_IGN 忽视信号
     *
     *      SIGABRT 程序异常终止
     *      SIGFPE 算术运算出错，如除数为 0 或溢出
     *      SIGILL  非法函数映象，如非法指令
     *      SIGINT  中断信号，如 ctrl-C
     *      SIGSEGV 非法访问存储器，如访问不存在的内存单元。
     *      SIGTERM 发送给本程序的终止请求信号
     *      SIG命名的宏，总共有二三十个，具体见 signal.h
     *
     * void（* signal（int sig，void（* func）（int）））（int）
     *      sig指定的信号编号，及处理信号的方法。
     *      处理方式：默认处理（SIG_DFL）、忽略信号（SIG_IGN）、使用函数来处理.
     *      返回指向特定处理函数的指针
     * int	raise(int);
     *      传入信号，根据 signal 函数的设置，判断是否调用 相应的处理函数。
     */

    void (*prev_handler)(int); //接收 signal 函数的返回值
    prev_handler = signal(SIGCHLD, my_handler); //设定某个信号的处理函数
//    prev_handler = signal(SIGCHLD, SIG_DFL); //设定某个信号的处理函数, 默认处理
    int result = raise(SIGALRM); //提起信号
    printf ("signaled is %d. result=%d\n", signaled, result);
    free(prev_handler);

   //void（     * signal（  int sig，void（* func）（int）  ）    ）（int）
   //返回值 ( 函数指针 ) (int 参数)
   //       函数指针： * signal(  int sig, void( func)(int)  )
}