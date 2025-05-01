// ---------------------------动态内存管理-----------------------

// ---------------------------malloc-----------------------

// #include <stdlib.h>
// malloc
// void* malloc (size_t size);
// Allocate memory block
// Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
//开辟一块size字节的空间，返回一个指针指向空间的起始位置,失败返回空指针

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main() {
//     //在栈区开辟
//     int arr[10] = {0};
//     //开辟内存  在堆区开辟
//     // 动态的一般都在堆区
//     int* p = (int*)malloc(40);
//     if (p == NULL) {
//         // char * strerror ( int errnum );
//         // strerror 返回的是指向静态区的字符串，不需要 free()。
//         // errno 是一个全局变量，发生错误时，系统会自动设置它。
//         // strerror(errno) 就是把这个错误码翻译成可读的错误信息。
//         printf("%s\n", strerror(errno));
//         return 1;
//     }
//     //使用
//     int i = 0;
//     for (i = 0; i < 10; i++) {
//         *(p + i) = i;
//     }
//     for (i = 0; i < 10; i++) {
//         printf("%d ", *(p + i));
//     }
//     // free只是解放了p之前所被编程者输入的内容(p还是指向原来的地址)，而真正解放p本身的是把指针p变为空指针
//     free(p);
//     p = NULL;
//     return 0;
// }


// ---------------------------calloc-----------------------
// void* calloc (size_t num, size_t size);
// free函数用来释放动态开辟的内存。
// 如果参数ptr指向的空间不是动态开辟的，那free函数的行为是未定义的。
// 如果参数ptr是NULL指针，则函数什么事都不做。
// malloc和free都声明在 stdlib.h头文件中。 
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     //申请
//     // void* calloc (size_t num, size_t size);
//     int* p = (int*)calloc(10, sizeof(int));
//     if (p == NULL) {
//         printf("申请失败\n");
//         return 1;
//     }

//     int i = 0;
//     //打印
//     for (i = 0; i < 10; i++) {
//         printf("%d ", *(p + i));
//     }
//     //释放
//     free(p);
//     p = NULL;
//     return 0;
// }


// ---------------------------realloc-----------------------

// calloc会初始化
// 函数的功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0。
// 与函数malloc的区别只在于calloc会在返回地址之前把申请的空间的每个字节初始化为全0。


// realloc函数的出现让动态内存管理更加灵活。

// 有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，
// 那为了合理的时候内存，我们一定会对内存的大小做灵活的调整。
// 那realloc函数就可以做到对动态开辟内存大小的调整。

// 函数原型如下：
// void* realloc (void* ptr, size_t size);

// ptr是要调整的内存地址
// size调整之后新大小
// 返回值为调整之后的内存起始位置。

// 这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到新的空间。
// realloc在调整内存空间的是存在两种情况：
// 情况1：原有空间之后有足够大的空间,直接在原来的基础上进行扩容
// 情况2：原有空间之后没有足够大的空间,拷贝数据到一块新的地址，那边的总大小符合扩容的大小的要求


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main() {
//     //申请
//     int* p = (int*)malloc(40);
//     if (p == NULL) {
//         printf("申请失败\n");
//         return 1;
//     }
//     //使用
//     int i = 0;
//     for (i = 0; i < 10; i++) {
//         *(p + i) = i + 1;
//     }
//     //扩容
//     int* ptr = (int*)realloc(p, 80);
//     if (ptr != NULL) {
//         p = ptr;
//     }
//     // 使用
//     for (i = 0; i < 10; i++) {
//         printf("%d ", *(p + i));
//     }
//     free(p);
//     p = NULL;
//     return 0;
// }

// ---------------------------柔性数组-----------------------
// 也许你从来没有听说过柔性数组（flexible array）这个概念，但是它确实是存在的。
// C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。


// 结构中的柔性数组成员前面必须至少一个其他成员。
// sizeof 返回的这种结构大小不包括柔性数组的内存。
// 包含柔性数组成员的结构用 malloc () 函数进行内存的动态分配，
// 并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

// #include <stdio.h>
// #include <stdlib.h>
// struct S {
//     int n;
//     int arr[];//柔性数组成员
// };

// int main() {
//     printf("%d\n", sizeof(struct S));//4

//     // 开辟空间使用柔性数组
//     struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);
//     if (ps == NULL) {
//         return 1;
//     }
//     ps->n = 100;
//     int i = 0;
//     for (i = 0; i < 10; i++) {
//         ps->arr[i] = i;
//     }
//     for (i = 0; i < 10; i++) {
//         printf("%d ", ps->arr[i]);
//     }
//     printf("\n");
//     printf("%d ", ps->n);
//     //可以对数组扩容
//     struct S* ptr = (struct S*)realloc(ps, sizeof(struct S*) + 80);
//     if (ptr != NULL) {
//         ps = ptr;
//         ptr = NULL;
//     }
//     //使用完后
//     //释放
//     free(ps);
//     ps = NULL;
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// struct S {
//     int n;//4
//     int* arr;//8
// };

// int main() {
//     printf("%d\n", sizeof(struct S));//16
//     //开辟空间
//     struct S* ps = (struct S*)malloc(sizeof(struct S));
//     if (ps == NULL) {
//         return 1;
//     }
//     ps->n = 100;
//     ps->arr = (int *)malloc(40);
//     if (ps->arr == NULL) {
//         return 1;
//     }
//     int i = 0;
//     for (i = 0 ; i < 10; i++) {
//         ps->arr[i] = i;
//     }
//     for (i = 0; i < 10; i++) {
//         printf("%d ", ps->arr[i]);
//     }
//     //扩容
//     int* ptr = (int*)realloc(ps->arr, 80);
//     if (ptr == NULL) {
//         return 1;
//     }
//     ps->arr = ptr;
//     ptr = NULL;
//     //使用
//     //释放
//     free(ps->arr);
//     free(ps);
//     ps->arr = NULL;
//     ps = NULL;

//     return 0;
// }


// ---------------------------文件操作-----------------------
// 只要打开一个文件就会有一个文件信息区

// 不同的 C 编译器的 FILE 类型包含的内容不完全相同，但是大同小异。
// 每当打开一个文件的时候，系统会根据文件的情况自动创建一个 FILE 结构的变量，并填充其中的信息，使用者不必关心细节。
// 一般都是通过一个 FILE 的指针来维护这个 FILE 结构的变量，这样使用起来更加方便。
// 下面我们可以创建一个 FILE的指针变量:
// FILE* pf; // 文件指针变量
// 定义 pf 是一个指向 FILE 类型数据的指针变量。
// 可以使 pf 指向某个文件的文件信息区（是一个结构体变量）。
// 通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件。


// "r"	以只读方式打开一个已存在的文本文件。若文件不存在，打开失败。
// "w"	以写入方式打开文本文件，若文件存在会被清空，若文件不存在会创建。
// "a"	以追加方式打开文本文件，若文件不存在会创建，写入从文件末尾开始。
// "rb"	以只读方式打开一个二进制文件。等价于 "r"，但处理的是二进制数据。
// "wb"	以写入方式打开一个二进制文件，文件存在则清空，不存在则创建。
// "ab"	以追加方式打开一个二进制文件。文件不存在则创建。
// "r+"	以读写方式打开一个文本文件，文件必须存在。
// "w+"	以读写方式打开一个文本文件，文件存在会清空，不存在则创建。
// "a+"	以读写追加方式打开文本文件。读写从文件末尾开始，文件不存在则创建。
// "rb+" / "r+b"	以读写方式打开二进制文件（不清空）。
// "wb+" / "w+b"	以读写方式打开二进制文件（清空或创建）。
// "ab+" / "a+b"	以读写方式打开二进制文件（写入从末尾开始）。

// #include <stdio.h>
// fopen
// FILE* fopen( const char* filename, const char* mode );

// fclose
// int fclose ( FILE * stream );

// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// int main() {
//     FILE* pf = fopen("test.txt", "r");//No such file or directory
//     if (pf == NULL) {
//         printf("%s\n", strerror(errno));
//         return 1;
//     }
//     //读文件

//     //关闭文件
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }


// 字符输入函数	        fgetc	    所有输入流  读取
// fgetc
// int fgetc ( FILE * stream );

// 字符输出函数	        fputc	    所有输出流  写入
// fputc
// int fputc ( int character, FILE * stream );

// 文本行输入函数	    fgets	    所有输入流
// fgets
// char * fgets ( char * str, int num, FILE * stream );

// 文本行输出函数	    fputs	    所有输出流
// fputs
// int fputs ( const char * str, FILE * stream );

// 格式化输入函数	    fscanf	    所有输入流
// fscanf
// int fscanf ( FILE * stream, const char * format, ... );

// scanf
// int scanf ( const char * format, ... );

// 格式化输出函数	    fprintf	    所有输出流
// fprintf
// int fprintf ( FILE * stream, const char * format, ... );

// printf
// int printf ( const char * format, ... );

// 二进制输入	        fread	    文件
// fread
// size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );

// 二进制输出	        fwrite	    文件
// fwrite
// size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );

// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// int main() {
//     //打开文件
//     FILE* pf = fopen("test.txt", "w");
//     if (pf == NULL) {
//         printf("%s\n", strerror(errno));
//     }
//     //写入
//     int i = 0;
//     for (i = 'a'; i <= 'z'; i++) {
//         fputc(i, pf);
//     }
//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// int main() {
//     //打开文件
//     FILE* pf = fopen("test.txt", "r");
//     if (pf == NULL) {
//         printf("%s\n", strerror(errno));
//     }
//     //读取
//     // int i = 0;
//     // for (i = 1; i <= 26; i++) {
//     //     int c = fgetc(pf);
//     //     printf("%c ", c);
//     // }
//     int c;
//     while ((c = fgetc(pf)) != EOF) {
//         printf("%c ", c);
//     }
//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

//写入一行
// fputs("hello world", pf);

//读取一行
// char arr[20] = {0};
//从pf指向的文件中读取4个字符到arr数组里,因为最后一个要补上\0,所以要只会读取4个
// fgets(arr, 5, pf);

// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// struct S {
//     char arr[20];
//     int age;
//     float f;
// };
// int main() {
//     //打开文件
//     FILE* pf = fopen("test.txt", "w");
//     if (pf == NULL) {
//         //打印出错误信息时的格式是："fopen:错误信息"
//         perror("fopen");
//     }
//     //写入
//     struct S s = {"zhangsan", 18, 50.5f};
//     fprintf(pf, "%s %d %f", s.arr, s.age, s.f);
//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// struct S {
//     char arr[20];
//     int age;
//     float f;
// };
// int main() {
//     //打开文件
//     FILE* pf = fopen("test.txt", "r");
//     if (pf == NULL) {
//         //打印出错误信息时的格式是："fopen:错误信息"
//         perror("fopen");
//     }
//     //读取
//     struct S s = {0};
//     fscanf(pf, "%s %d %f", s.arr, &(s.age), &(s.f));

//     printf("%s %d %f", s.arr, s.age, s.f);
//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }


// 建议这么理解:printf是打印（输出）在屏幕上，fprintf自然就是输出到文件中，那就是写，对应w


// 是的，一个 C 语言程序在运行时默认会打开 3 个标准 I/O 流，分别是：

// 流名	类型	    标准宏	            作用
// 标准输入流	FILE*	stdin	默认从键盘读取输入数据，供 scanf()、getchar() 等函数使用。
// 标准输出流	FILE*	stdout	默认向屏幕输出信息，用于 printf()、puts() 等函数输出。
// 标准错误流	FILE*	stderr	默认向屏幕输出错误信息，常用于错误提示（不会被重定向）。

// #include <stdio.h>

// int main() {
//     fprintf(stdout, "这是标准输出\n");
//     fprintf(stderr, "这是标准错误输出\n");
//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// struct S {
//     char arr[20];
//     int age;
//     float score;
// };
// int main() {
//     struct S s = {"zhangsan", 18, 50.5f};
//     //打开文件
//     FILE* pf = fopen("test.txt", "wb");
//     if (pf == NULL) {
//         perror("fopen");
//         return 1;
//     }
//     // 二进制写入
//     fwrite(&s, sizeof(struct S), 1, pf);

//     //关闭
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// struct S {
//     char arr[20];
//     int age;
//     float score;
// };
// int main() {
//     struct S s = {0};
//     //打开文件
//     FILE* pf = fopen("test.txt", "rb");
//     if (pf == NULL) {
//         perror("fopen");
//         return 1;
//     }
//     // 二进制读取
//     fread(&s, sizeof(struct S), 1, pf);
//     printf("%s %d %f\n", s.arr, s.age, s.score);

//     //关闭
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }


// 所谓“输入”就是 外部 → 程序
// 所谓“输出”就是 程序 → 外部

// | 操作         | 方向           | 理解                                       |
// |--------------|----------------|--------------------------------------------|
// | 从**文件中读取** | 文件 ➜ 程序    | 程序**输入**数据                            |
// | 向**文件中写入** | 程序 ➜ 文件    | 程序**输出**数据（写东西出去）              |

// scanf 是针对标准输入的格式化输入语句
// printf 是针对标准输出的格式化输出语句

// fscanf 是针对所有输入流的格式化输入语句
// fprintf 是针对所有输出流的格式化输出语句

// sscanf 从一个字符串中转化处一个格式化的数据
// sprintf 是把一个格式化的数据转化成字符串


//--------------文件随机读写----------------
// fseek
// int fseek ( FILE * stream, long int offset, int origin );
// offset  偏移量


// Constant	Reference position
// SEEK_SET	Beginning of file
// SEEK_CUR	Current position of the file pointer
// SEEK_END	End of file *

// #include <stdio.h>
// #include <string.h>
// #include <errno.h>

// int main() {
//     //打开文件
//     FILE* pf = fopen("test.txt", "r");
//     if (pf == NULL) {
//         //打印出错误信息时的格式是："fopen:错误信息"
//         perror("fopen");
//     }
//     //读取
//     char ch = 0;
//     ch = fgetc(pf);
//     printf("%c\n", ch);\
//     //计算相对于起始位置的偏移量
//     printf("%d\n", ftell(pf));//1

//     //设置文件指针
//     fseek(pf, -1, SEEK_END);
//     ch = fgetc(pf);
//     printf("%c\n", ch);
//     printf("%d\n", ftell(pf));//6

//     fseek(pf, -2, SEEK_CUR);
//     ch = fgetc(pf);
//     printf("%c\n", ch);
//     printf("%d\n", ftell(pf));//5

//     //设置问价指针回到起始位置
//     rewind(pf);
//     ch = fgetc(pf);
//     printf("%c\n", ch);
//     printf("%d\n", ftell(pf));//1
//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }



