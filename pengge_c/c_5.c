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

