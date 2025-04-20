// 函数栈帧的创建和销毁
// 一个函数调用 = 创建一个栈帧
// 函数返回 = 销毁这个栈帧

// eax：通用寄存器，保留临时数据，常用于返回值
// ebx：通用寄存器，保留临时数据
// ebp：栈底寄存器
// esp：栈顶寄存器
// eip：指令寄存器，保存当前指令的下一条指令的地址

// mov：数据转移指令
// push：数据入栈，同时esp栈顶寄存器也要发生改变
// pop：数据弹出至指定位置，同时esp栈顶寄存器也要发生改变
// sub：减法命令
// add：加法命令
// call：函数调用，1. 压入返回地址 2. 转入目标函数
// jump：通过修改eip，转入目标函数，进行调用
// ret：恢复返回地址，压入eip，类似pop eip命令


// 压栈是放在 低地址方向 
// 在大多数系统（如 x86 架构）中，栈是从高地址向低地址增长的
// ^
// | 低地址
// |
// |
// |
// |
// |
// |
// | 高地址


// 每次压栈时，esp（栈顶指针）会减小
// 每次出栈时，esp 会增大

// 压栈是放在“栈顶”
// 但这里的“栈顶”不是高地址，而是当前 esp 所指的位置，即栈当前最“活跃”的部分


// 地址      内容
// ───────┬────────────────────────
// 0x0FEC |
// 0x0FED |
// 0x0FEE |
// 0x0FEF |
// 0x0FF0 │ ← 当前栈顶 esp
// 0x0FF4 │ 
// 0x0FF8 │ 
// 0x0FFC │ 
// 0x1000 │ ← 栈底（固定）


// push eax
// 当前 esp = 0x0FF0
// push eax 会把 esp -= 4 → esp = 0x0FEC
// 然后把 eax 里的值放进地址 0x0FEC ~ 0x0FEF

// --------------------字符串函数------------------

// strlen
// size_t strlen ( const char * str )
// size_t ----> unsigned int

// 求字符串长度函数的实现
// #include <stdio.h>
// #include <assert.h>
// unsigned int my_strlen(const char* str) {
//     assert(str);
//     unsigned int count = 0;
//     while (*str != '\0') {
//         count++;
//         str++;
//     }
//     return count;
// }
// int main() {
//     char arr[] = "abcdef";
//     unsigned int ret = my_strlen(arr);

//     printf("%u\n", ret);
// }


//复制字符串函数
// char * strcpy ( char * destination, const char * source );
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// char* my_strcpy (char* des, const char* src) {
//     assert(des && src);
//     char* ret = des;
//     while (*src != '\0') {
//         *des = *src;

//         des++;
//         src++;
//     }
//     *des = *src;//\0
//     //返回起始地址
//     return ret;
// }

// //实现
// int main () {
//     char arr1[] = "abcdef";
//     char arr2[20] = {0};
//     my_strcpy(arr2, arr1);

//     printf("%s\n", arr2);
// }





// int main () {
//     char arr[20] = {0};
//     strcpy(arr, "zhang\0san");

//     printf("%s\n", arr);
// }


//字符串追加函数
// char * strcat ( char * destination, const char * source );
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// char* my_strcat (char* dest, const char* src) {
//     assert(dest && src);
//     char* ret = dest;
//     while (*dest) {
//         dest++;
//     }
//     while (*src) {
//         *dest = *src;

//         dest++;
//         src++;
//     }
//     *dest = *src;

//     return ret;
// }
// int main() {
//     char arr[20] = "hello ";
//     my_strcat(arr, "world");

//     printf("%s\n", arr);
//     return 0;
// }


//字符串比较函数
// int strcmp ( const char * str1, const char * str2 );
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// //法1
// int my_strcmp(const char* str1, const char* str2) {
//     assert(str1 && str2);
//     while (*str1 || *str2) {
//         if (*str1 > *str2) {
//             return 1;
//         }
//         else if (*str1 < *str2) {
//             return -1;
//         }
//         else {
//             str1++;
//             str2++;            
//         }
//     }
//     return 0;
// }
// //法2
// int my_strcmp(const char* str1, const char* str2) {
//     assert(str1 && str2);
//     while (*str1 == *str2) {
//         if (*str1 == '\0') {
//             return 0;
//         }
//         str1++;
//         str2++;
//     }
//     return (*str1 - *str2);
// }
// int main() {
//     char arr1[20] = "abcdef";
//     char arr2[] = "abcdef";
//     // char arr2[] = "abq";

//     int ret = my_strcmp(arr1, arr2);
//     if (ret > 0) {
//         printf("arr1 > arr2");
//     }
//     else if (ret == 0) {
//         printf("arr1 == arr2");
//     }
//     else {
//         printf("arr1 < arr2");
//     }


//     //err   实际上比较的是地址
//     // if (arr1 == arr2) {
//     //     printf("==\n");
//     // }
//     // else {
//     //     printf("!=\n");
//     // }
//     // return 0;
// }

// ---------------------以上是长度不受限制的字符串函数-------------------



// ---------------------以下是长度不受限制的字符串函数-------------------
// size_t num 拷贝多少字节的内容
// strncpy
// char * strncpy ( char * destination, const char * source, size_t num );

// strncat
// char * strncat ( char * destination, const char * source, size_t num );

// strncmp
// int strncmp ( const char * str1, const char * str2, size_t num );

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char arr1[20] = "abcdef";
//     char arr2[] = "hello";
//     strncpy(arr1, arr2, 5);
//     printf("%s\n", arr1);//hellof
//     return 0;
// }


// strstr
// 查找子串的一个函数
// const char * strstr ( const char * str1, const char * str2 );
// 查找str1中是否有str2 返回的是子字符串的地址  若无返回空指针

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// int main() {
//     char arr1[30] = "abcedfljy666";
//     char arr2[] = "ljy";

//     char* ret = strstr(arr1, arr2);
//     if (ret == NULL) {
//         printf("不存在");
//     }
//     else {
//         printf("%s\n", ret);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// char* my_strstr(const char* str1, const char* str2) {
//     assert(str1 && str2);
//     const char* s1 = str1;
//     const char* s2 = str2;
//     const char* p = str1;

//     while (*p) {
//         s1 = p;
//         s2 = str2;
//         while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
//             s1++;
//             s2++;
//         }
//         if (*s2 == '\0') {
//             return (char*)p;
//         }
//         p++;
//     }
//     return NULL;
// }

// int main() {
//     char arr1[30] = "abc bbbc ledf";
//     char arr2[] = "bbc";

//     char* ret = my_strstr(arr1, arr2);
//     if (ret == NULL) {
//         printf("不存在");
//     }
//     else {
//         printf("%s\n", ret);
//     }

//     return 0;
// }


// strtok
//切割字符串
// char * strtok ( char * str, const char * delimiters );
// delimiters参数是一个字符串，定义了作用分隔符的集合
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// int main() {
//     const char* sep = "@.";
//     char email[] = "1797727234@qq.com";
//     char cp[30] = {0};
//     strcpy(cp, email);

//     char* ret = NULL;
//     for (ret = strtok(cp, sep); ret != NULL; ret = strtok(NULL, sep)) {
//         printf("%s\n", ret);
//     }

//     //该操作会改变原来的字符串,分隔符会替换成'\0',使用之前尽量拷贝一份数据
//     //返回的是第一个字段的头地址
//     //若第一个参数不为NULL，则返回第一个字段的头地址
//     //若第一个参数为NULL，则下次开始时的地址为上一次标记的地方
//     // char* ret = strtok(cp, sep);
//     // if (ret != NULL)
//     //     printf("%s\n", ret);

//     // ret = strtok(NULL, sep);
//     // if (ret != NULL)
//     //     printf("%s\n", ret);

//     // ret = strtok(NULL, sep);
//     // if (ret != NULL)
//     //     printf("%s\n", ret);

//     // 1797727234
//     // qq
//     // com
//     return 0;
// }


//strerror


// memcpy   内存拷贝函数    拷贝任意类型
// void * memcpy ( void * destination, const void * source, size_t num );
// #include <stdio.h>
// #include <string.h>
// int main () {
//     int arr1[] = {1,2,3,4,5,6,7};
//     int arr2[10] = {0};
//     memcpy(arr2, arr1, 28);
// }


// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// void* my_memcpy(void* dest, const void* src, size_t num ) {
//     assert(dest && src);
//     void* ret = dest;
//     int i = 0;
//     for (i = 0; i < num; i++) {
//         *((char*)dest) = *((char*)src);
//         //重新转换类型,确保跳过1字节  
//         dest = (char*)dest + 1;
//         src = (char*)src + 1;  
//     }
//     return ret;
    
// }
// int main () {
//     int arr1[] = {1,2,3,4,5,6,7};
//     int arr2[10] = {0};
//     my_memcpy(arr2, arr1, 28);
// }