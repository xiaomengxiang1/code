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

#include <stdio.h>
#include <string.h>
#include <errno.h>
int main() {
    FILE* pf = fopen("test.txt", "r");//No such file or directory
    if (pf == NULL) {
        printf("%s\n", strerror(errno));
        return 1;
    }
    //读文件

    //关闭文件
    fclose(pf);
    pf = NULL;

    return 0;
}