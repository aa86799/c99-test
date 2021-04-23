//
// Created by austin stone on 2020/2/16.
//

#include "setjmp-test.h"

jmp_buf buf;

void doAction() {
    printf("in doAction() \n");
    longjmp(buf, 1);

    printf("you'll never see this,because i longjmp'd");
}

void setjpm_test() {
    /*
     * setjmp 和longjmp 是C语言独有的，只有将它们结合起来使用，才能达到程序控制流有效转移的目的.
     *      按照程序员的预先设计的意图，去实现对程序中可能出现的异常进行集中处理。
     * int setjmp(jmp_buf envbuf); 设置缓冲区
     *      缓冲区envbuf保存系统堆栈的内容，以便后续的longjmp函数使用。setjmp函数初次启用时返回0值.
     * void longjmp(jmp_buf envbuf, int val);
     *      envbuf是由setjmp函数所保存的环境堆栈，val设置 setjmp 函数的返回值。
     *
     * 初次执行 setjmp(buf), 返回0；当调用 longjmp(buf, val)，跳转到buf的堆栈位置，执行下次setjmp()，使返回值为val。
     *      buf表示的堆栈指针，在longjmp后会被恢复
     */
    if (setjmp(buf)) {
        printf("2\n");
    } else {
        printf("1\n");
        doAction();
    }
    //如上例，输出： 1, in doAction(), 2

    //从一个函数跳到另一个函数 使用 setjmp() longjmp()

    int a[5][3] = {80, 75, 92, 61, 65, 71, 59, 63, 70, 85, 87, 90, 76, 77, 85};
    int i, j;  //二维数组下标
    float sum = 0;  //当前科目的总成绩
    float v[5]; //各科目的平均分
    for (i = 0; i < 5; ++i) {//行
        for (j = 0; j < 3; ++j) {//列
            sum += (float)a[i][j]; //一行3列，一个学生三个科目的总成绩
        }
        v[i] = sum / 3;
        sum = 0;
    }
    float all = 0;  //各学生平均分的总和
    for (i = 0; i < 5; i++) {
        printf("科目%d平均分%.2f\n", i, v[i]);
        all += v[i];
    }
    printf("所有科目总的平均分%.2f\n", all / 5);
}