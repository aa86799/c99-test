//
// Created by austin stone on 2020/2/20.
//

#include <zconf.h>
#include <errno.h>
#include "stdio-test.h"

void readFile(FILE *file, long seek_offset, int whence);
void writeFile(FILE *file, FILE *outFile);

void stdio_test()
{
    /*
     * stdio .h 头文件定义了三个变量类型、一些宏和各种函数来执行输入和输出。
     * size_t   这是无符号整数类型，它是 sizeof 关键字的结果。
     * FILE     这是一个适合存储文件流信息的对象类型。
     * pos_t    这是一个适合存储文件中任何位置的对象类型。
     * 宏
     *      NULL    一个空指针常量的值。
     *      _IOFBF、_IOLBF 和 _IONBF  这些宏扩展了带有特定值的整型常量表达式，并适用于 setvbuf 函数的第三个参数。
     *      BUFSIZ  一个整数，该整数代表了 setbuf 函数使用的缓冲区大小。
     *      EOF     一个表示已经到达文件结束的负整数
     *      FOPEN_MAX 一个整数，该整数代表了系统可以同时打开的文件数量。
     *      FILENAME_MAX 一个整数，该整数代表了字符数组可以存储的文件名的最大长度。如果实现没有任何限制，则该值应为推荐的最大值。
     *      L_tmpnam    一个整数，该整数代表了字符数组可以存储的由 tmpnam 函数创建的临时文件名的最大长度。
     *      SEEK_CUR、SEEK_END 和 SEEK_SET    这些宏是在 fseek 函数中使用，用于在一个文件中定位不同的位置。
     *      TMP_MAX    tmpnam 函数可生成的独特文件名的最大数量。
     *      stderr、stdin 和 stdout  指向 FILE 类型的指针，分别对应于标准错误、标准输入和标准输出流。
     */

    /*
     *  fopen(char * __filename, char * mode); //指定要打开的文件名和，打开模式
     *  "r" = "rt"
打开一个文本文件，文件必须存在，只允许读
"r+" = "rt+"
打开一个文本文件，文件必须存在，允许读写
"rb"
打开一个二进制文件，文件必须存在，只允许读
“rb+”
打开一个二进制文件，文件必须存在，允许读写
"w" = “wt”
新建一个文本文件，已存在的文件将内容清空，只允许写
"w+" = "wt+"
新建一个文本文件，已存在的文件将内容清空，允许读写
“wb”
新建一个二进制文件，已存在的文件将内容清空，只允许写
“wb+”
新建一个二进制文件，已存在的文件将内容清空，允许读写
"a" = "at"
打开或新建一个文本文件，只允许在文件末尾追写
"a+" = "at+"
打开或新建一个文本文件，可以读，但只允许在文件末尾追写
“ab”
打开或新建一个二进制文件，只允许在文件末尾追写
“ab+”
打开或新建一个二进制文件，可以读，但只允许在文件末尾追写

对于文件使用方式有以下几点说明：
1) 文件使用方式由r,w,a,t,b，+六个字符拼成，各字符的含义是：
r(read): 只读
w(write): 只写
a(append): 追加
t(text): 文本文件，可省略不写
b(binary): 二进制文件
+: 读和写
2) 凡用“r”打开一个文件时，该文件必须已经存在，且只能从该文件读出。
3) 用“w”打开的文件只能向该文件写入。若打开的文件不存在，则以指定的文件名建立该文件，若打开的文件已经存在，则将该文件内容清空。
4) 若要向一个已存在的文件追加新的信息，用“a”方式打开文件。如果指定文件不存在则尝试创建该文件。
5) 在打开一个文件时，如果出错，fopen将返回一个空指针值NULL。在程序中可以用这一信息来判别是否完成打开文件的工作，并作相应的处理。
     */
    FILE *file = fopen("/Users/stone/CLionProjects/c99-test/float-test.c", "r");
    if (file == NULL) {
        printf("无法打开文件");
    }

    readFile(file, 0, SEEK_SET);

    //freopen(), 把一个新的文件名 filename 与给定的打开的流 stream 关联，同时关闭流中的旧文件。
    if (!freopen("/Users/stone/CLionProjects/c99-test/math-test.c", "rw", file)) {
        printf("无法打开文件");
    }
    readFile(file, sizeof(char) * 10, SEEK_CUR); //从当前位置，偏移10个字符的字节

    fpos_t pos;
    int getPos = fgetpos(file, &pos); //如果成功，函数返回 0
    printf("操作是否成功: %d, 当前位置 %lld\n", getPos == 0, pos);

    pos -= 100;
    fsetpos(file, &pos); //相比fseek() ，是一个绝对定位功能。
    getPos = fgetpos(file, &pos); //如果成功，函数返回 0
    printf("操作是否成功: %d, 重设位置后，当前位置 %lld\n", getPos == 0, pos);
    printf("当前位置 %ld\n", ftell(file)); //简单 返回 当前位置；而 fgetpos 需要 传入 fpos_t* 参数。

    //读取指定文件，写入到 outFile
    FILE *outFile = fopen("/Users/stone/CLionProjects/c99-test/out-file", "w");
    writeFile(file, outFile);
    fclose(outFile);

    //删除给定的文件
//    remove("/Users/stone/CLionProjects/c99-test/out-file");

    //重命名文件
    rename("/Users/stone/CLionProjects/c99-test/out-file", "/Users/stone/CLionProjects/c99-test/out-newfile");

    //以二进制更新模式(wb+)创建临时文件
    FILE *tmp = tmpfile();
    //在 mac os的 unix 中，被标记过时了，使用 POSIX的<unistd.h> mkstemp(char*)。 POSIX 表示可移植操作系统接口
    //    tempnam("/Users/stone/CLionProjects/c99-test/", "notExists"); //生成并返回一个有效的临时文件名，该文件名之前是不存在的

    FILE *outFile2 = fopen("/Users/stone/CLionProjects/c99-test/out-newfile", "wt+");
    int fd = fileno(outFile2);
    off_t setLen = 1024*4;
    int truncattRes =  ftruncate(fd, setLen);
    /*
     * 会将参数fd指定的文件大小改为参数length指定的大小。参数fd为已打开的文件描述词，而且必须是以写入模式打开的文件。
     * 如果原来的文件件大小比参数length大，则超过的部分会被删去
     * 返 回  值：0、-1
        错误原因：errno
          EBADF     参数fd文件描述词为无效的或该文件已关闭.   Bad file descriptor
          EINVAL    参数fd为一socket并非文件，或是该文件并非以写入模式打开. Invalid argument
     */
    printf("truncattRes=%d\n", truncattRes);
    printf("errno=%d\n", ferror(outFile2));

//    printf() //格式化输出到标准输出流 stdout
//    sprintf() //格式化输出到字符串
//    fprintf() //格式化输出到指定文件流
//    vfprintf() //格式化输出到指定文件流，实际变量列表，是一个va_list 的可变参数
//    vprintf() //格式化输出到标准输出 stdout，实际变量列表，是一个va_list 的可变参数
//    vsprintf() //格式化输出到字符串，实际变量列表，是一个va_list 的可变参数
//    scanf() //从标准输入 stdin 读取格式化输入
//    fscanf() //从流 stream 读取格式化输入
//    sscanf() //从字符串读取格式化输入

//    getc() //从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。
//    fgetc()//从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。
    //上面两个的区别在于内部实现上，f开头的，是以函数来实现的。没有f的是通过宏来实现的。
    //fgetc一定是一个函数，所以可以得到其地址。这就允许将fgetc的地址作为一个参数传送给另一个函数。
    //调用fgetc所需时间很可能长于调用getc，因为调用函数通常所需的时间长于调用宏
//    getchar();//从标准输入 stdin 获取一个字符（一个无符号字符）。
//    gets()//从标准输入 stdin 读取一行，并把它存储在 str 所指向的字符串中。当读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
//    fgets()//从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。与上个实现有区别

//    putc()//把参数 char 指定的字符（一个无符号字符）写入到指定的流 stream 中，并把位置标识符往前移动。
//    fputc()// 和 putc()功能一样，实际有区别
//    puts() //把一个字符串写入到标准输出 stdout，直到空字符，但不包括空字符。换行符会被追加到输出中。
//    fputs() //把字符串写入到指定的流 stream 中，但不包括空字符。与上个实现有区别

//    ungetc() //把字符 char（一个无符号字符）推入到指定的流 stream 中，以便它是下一个被读取到的字符。
    perror("error: xxxxx"); //把一个描述性错误消息输出到标准错误 stderr。首先输出字符串 str，后跟一个冒号，然后是一个空格。

//    snprintf() //格式字符串到 str 中.
/*
 * char *str [out],把生成的格式化的字符串存放在这里.
size_t size [in], str可接受的最大字符数 [1]  (非字节数，UNICODE一个字符两个字节),防止产生数组越界.
const char *format [in], 指定输出格式的字符串，它决定了你需要提供的可变参数的类型、个数和顺序。
va_list ap [in], va_list变量. va:variable-argument:可变参数
 */
//    vsnprintf(char* str, size_t size, const char* format, va_list ap) //格式字符串到 str 中。

    if (feof(file)) {//测试到达文件流的结束符
        printf("到达文件流的结束符, 关闭文件");
        fclose(file);
    } else {
        clearerr(file); //清除给定流 stream 的文件结束和错误标识符
        //再读一次
    }

}

void readFile(FILE *file, long seek_offset, int whence)
{
    printf("-----------read begin-----------\n");
    char ptr[BUFSIZ]; //缓冲区数组
    size_t readCount;
    size_t _size = sizeof(char);
    size_t _count = BUFSIZ;
    int isEof;
    int error;
    fpos_t pos;
    int getPos;
    /*
     * 设置文件内部位置指针。从 whence 开始偏移 seek_offset个字节
     * whence: 文件头0 (SEEK_SET)，当前位置 1(SEEK_CUR)，文件尾 2(SEEK_END)
     */
    fseek(file, seek_offset, whence);
    while (!feof(file)) {
        readCount = fread(ptr, _size, _count, file); //从给定流 stream 读取数据到 ptr 所指向的数组中。两个size_t参数，第一个为单个元素的字节数，第二个是要读或写的元素个数，这些元素在 ptr 所指的内存空间中连续存放，共占“size*n”个字节
        isEof = feof(file);
        printf ("读取到 %lu 个字符；是否到达文件末尾：%d\n", readCount, isEof);

        getPos = fgetpos(file, &pos); //如果成功，函数返回 0
        printf("操作是否成功: %d, 当前位置 %lld\n", getPos == 0, pos);

        error = ferror(file); //测试给定流 stream 的错误标识符
        printf("是否出现 error : %s\n", strerror(error));
        printf("\n");
    }
    printf("-----------read end-----------\n");
}

void writeFile(FILE *file, FILE *outFile)
{
    printf("-----------write begin-----------\n");
//    fseek(file, 0, SEEK_SET); //要读取的文件，设置到开始位置
    rewind(file); //设置到开始位置

    //写入模式，文件不存在，会自动创建
    if (outFile == NULL) {
        printf("无法打开文件");
    }

    char ptr[BUFSIZ];
    size_t readCount;
    size_t writeCount;
    size_t sumWriteCount = 0;
    size_t _size = sizeof(char);
    size_t _count = BUFSIZ;

    /*
     * stdin 、stdout 、stderr  标准输入、输出、错误流
     *
     * 系统中有三种可用的buffer类型，分别为无Buffer(Unbuffered)，块Buffer(Block Bufferd)和行Buffer(Line Buffered)
     * 宏：_IONBF(无buffer)  _IOLBF(行buffer)  _IOFBF(full buffer，buffer整体，块buffer)
     * 当一个流是Unbufferd的时候，往这个Stream中写入的信息会立刻写入目标文件。
     * 当Buffer类型是Block Buffered时，往该Stream中写入的信息会先暂存在Buffer中，每次实际的写入都是以块(Block)大小为单位写入目标文件。
     * 而当Buffer类型是Line Buffered时，往该Stream中输入或输出的信息都会先暂存在Buffer中直到遇到新的一行。fflush()可以强制将Buffer提前清空。
     *
     * 通常所有的文件和设备都是Block Buffered，如果任何一个流涉及到终端（例如stdin）那它将是Line Buffer类型。而标准错误流stderr的默认Buffer类型永远是Unbuffered类型。
     */
    char buf[256*4*4];
//    setbuffer(FILE *stream, char *buf, size_t size)
//    setlinebuf(FILE *stream) //行输出
//    setvbuf(stdout, buf, _IONBF, BUFSIZ); //直接输出，是完整的
//    setvbuf(stdout, buf, _IOLBF, BUFSIZ); //行输出，是完整的
//    setvbuf(stdout, buf, _IOFBF, BUFSIZ); //块输出，size的不同，可能不完整
    setbuf(stdout, buf); //网上说相当于setvbuf(stream, buf, buf?_IOFBF:_IONBF,BUFSIZ);  实际测试发现，不同的size值，可能造成标准输出时乱码，即块，输出不完整

    while (!feof(file)) {
        readCount = fread(ptr, _size, _count, file);
        if (readCount > 0) {
            writeCount = fwrite(ptr, _size, readCount, outFile);
            int flush = fflush(file);//刷新流 stream 的输出缓冲区; 立即把输出缓冲区的数据进行物理写入时。 如果成功刷新,返回0。指定的流没有缓冲区或者只读打开时也返回0值。返回EOF(-1)表示错误。
            printf("写入字节数 %lu, flush=%d\n", writeCount, flush);
            sumWriteCount += writeCount;
        }
    }
    printf("共写入字节数：%lu\n", sumWriteCount);
    printf("-----------write end-----------\n");
}