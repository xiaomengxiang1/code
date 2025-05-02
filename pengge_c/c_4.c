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


// memcpy   内存拷贝函数    拷贝任意类型    不能处理重叠内存之间的数据拷贝
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

//使用memmove函数处理重叠内存之间的数据拷贝
// void * memcpy ( void * destination, const void * source, size_t num );
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// void* my_memmove(void* dest, const void* src, size_t num) {
//     //dest的地址在src的前面 src从前向后拷贝
//     //dest的地址在src的后面 src从后向前拷贝
//     // 1 2 3 4 5 6 7 8 9 10
//     // -------------------------------->
//     // 低地址                      高地址
//     assert(dest && src);
//     void* ret = dest;
//     if (dest < src) {
//         //从前向后拷贝
//         while (num--) {
//             *((char*)dest) = *((char*)src);
//             // void* 类型不能直接加减
//             dest = (char*)dest + 1;
//             src = (char*)src + 1;
//         }
//     }
//     else {
//         //从后向前拷贝
//         while (num--) {

//             *((char*)dest + num) = *((char*)src + num);
//         }
//     }
//     return ret;
// }

// int main () {
//     int arr1[] = {1,2,3,4,5,6,7,8,9,10};
//     my_memmove(arr1, arr1 + 2, 20);

//     int i = 0;
//     for (i = 0; i < 10; i++) {
//         printf("%d ", arr1[i]);
//     }
// }



//内存比较函数  比价每一对字节的内容    大于返回正  小于返回负  相等返回0
// int memcmp ( const void * ptr1, const void * ptr2, size_t num );
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// int main() {
//     int arr1[] = {1,2,3,4,5};//内存 //01 00 00 00 //02 00 00 00 //03 00 00 00
//     int arr2[] = {1,3,2};//内存     //01 00 00 00 //03 00 00 00 //02 00 00 00
//     int ret = memcmp(arr1, arr2, 12);
//     printf("%d\n", ret);//-1    

// }

//内存设置函数
// memset
// void * memset ( void * ptr, int value, size_t num );
// ptr
// Pointer to the block of memory to fill.
// value
// Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
// num
// Number of bytes to be set to the value.
// size_t is an unsigned integral type.

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// int main() {

//     char arr[] = "hello world";
//     memset(arr, 'x', 5);
//     printf("%s\n", arr);
//     return 0;
// }


// ---------------------------自定义类型-----------------------


// ----------------结构体类型-----------
// struct Stu {
//     int age;
//     char name[20];
// } s1, s2;//全局变量

// int main() {

//     struct Stu s3;//局部变量
//     return 0;
// }

//匿名结构体类型
//一次性使用
// struct {
//     int age;
//     char name[20];
// } s1;

//链表
//根据一个节点(两个部分)找到下一个节点    内存中并不是线性存放
//两个部分分为  数据域  指针域
// struct Node {
//     int data;
//     struct Node* next;
// };

// ----------------结构体类型初始化-----------
// struct Point {
//     int x;
//     int y;
// }p1 = {2, 3}; //创建结构体时初始化

// struct Score {
//     int n;
//     char subject[20];
// };
// struct Stu {
//     char name[20];
//     int age;
//     struct Score s;
// };
// #include <stdio.h>
// int main() {
//     struct Point p2 = {3,4};
//     struct Stu s1 = {"zhangsan", 18, {90, "shuxue"}};
//     printf("%s %d %d %s\n", s1.name, s1.age, s1.s.n, s1.s.subject);
//     return 0;
// }

// ----------------结构体内存对齐-----------
// 首先得掌握结构体的对齐规则：

// 1.第一个成员在与结构体变量偏移量为0的地址处。
// 2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。   （先对齐到某个位置再进行存储，不是存储到对齐的位置）
//   对齐数=编译器默认的一个对齐数与该成员大小的较小值。VS中默认的值为8
    // int 为4字节 编译器默认对齐数是8   取较小的一个值 就是4
    // char 为1字节 编译器默认对齐数是8   取较小的一个值 就是1

// 3.结构体总大小为最大对齐数（每个成员变量都有一个对齐数）（取最大的一个对齐数）的整数倍。
// 4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
//   结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

// 返回结构体成员的偏移量
// #include <stddef.h>
// offsetof
// offsetof (type,member)
// struct Stu {
//     char c1;
//     int i;
//     char c2;
// };

// struct Peo {
//     char c1;
//     char c2;
//     int i;
// };
// #include <stdio.h>
// #include <stddef.h>
// int main () {
//     printf("%d\n", offsetof(struct Stu, c1));   //0
//     printf("%d\n", offsetof(struct Stu, i));    //4
//     printf("%d\n", offsetof(struct Stu, c2));   //8

//     printf("%d\n", offsetof(struct Peo, c1));   //0
//     printf("%d\n", offsetof(struct Peo, c2));   //1
//     printf("%d\n", offsetof(struct Peo, i));   //4
//     return 0;
// }

//设计结构体成员时，尽量让占用空间小的成员集中在一起


// ----------------修改对齐数-----------
// #include <stdio.h>
// #include <stddef.h>

// #pragma pack(4) //修改对齐数为4
// struct Peo {
//     int i;// 0 ~ 3
//     double a;//4 ~ 11   
//     // 总共12个字节
// };
// #pragma pack()

// int main () {
//     printf("%d\n", sizeof(struct Peo));//12 
//     return 0;
// }


// ----------------位(bit位)段-----------
// 一个字节的空间中存放时,前面的成员优先使用低位的空间
// 如下：
// 0000 0000
// 后几位0先使用
// // 通常是int , unsigned int , signed int , char等

//冒号后面限制了存储的位数
// struct A {
//     int a : 2;
//     int b : 3;
//     int c : 5;
// };

// 1.位段的成员可以是int unsigned int signed int或者是char(属于整形家族)类型

// 2.位段的空间上是按照需要以4个字节（int）或者1个字节（char）的方式来开辟的。

// 3.位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。

// struct A {
//     int a : 2;
//     int b : 5;
//     int c : 10;
//     int d : 30;
// };
// #include <stdio.h>
// int main() {
//     printf("%d\n", sizeof(struct A));//8
//     return 0;
// }

// 位段数据的存放

// VS2019中，位域成员不会强行按 int 的大小占4字节，
// 会根据实际需要最少分配字节数，并加上必要的补齐，最终结果是3字节。
// struct A {
//     int a : 3;
//     int b : 4;
//     int c : 5;
//     int d : 4;
// };
// #include <stdio.h>
// int main () {
//     printf("%d\n", sizeof(struct A));   //4

//     struct A s = {0};
//     s.a = 10;//截断存储在3bit中
//     s.b = 12;
//     s.c = 3;
//     s.d = 4;

//     return 0;
// }



// ----------------枚举-----------
// 枚举
// enum Day {
//     mon,
//     tues,
//     wed,
//     thur,
//     fir,
//     sat,
//     sun,
// };

// 结构体
// struct point {
//     int x;
//     int y;
// };


//默认0 1 2 3 4  5...
// #include <stdio.h>
// // 枚举有类型 而#define 定义的常量没有类型
// enum Day {
//     //枚举常量
//     mon = 1,
//     tues,
//     wed,
//     thur,
//     fri,
//     sat,
//     sun,
// };

// int main() {
//     // enum Day d = fri;
//     printf("%d\n", mon);
//     printf("%d\n", tues);
//     printf("%d\n", wed);
//     printf("%d\n", thur);
//     printf("%d\n", fri);
//     printf("%d\n", sat);
//     printf("%d\n", sun);

//     return 0;
// }



// ----------------联合(共用体)-----------
// union Un {
//     int a;
//     char b;
// };

// struct St {
//     int a;
//     int b;
// };
// #include <stdio.h>
// int main() {
//     union Un u;
//     printf("%d\n", sizeof(u));//4

//     printf("%p\n", &u);
//     printf("%p\n", &(u.a));
//     printf("%p\n", &(u.b));
//     // 共用4字节
// // 000000000061FE1C
// // 000000000061FE1C
// // 000000000061FE1C

//     return 0;
// }

//联合体的大小,至少是最大的成员的大小(至少得要存储的了最大的那个)

//判断计算机是大小端存储
// #include <stdio.h>
// int main() {
//     int a = 1;//0x00 00 00 01
//     //小 01 00 00 00
//     //大 00 00 00 01
//     char* p = (char*)&a;
//     if (*p == 1) {
//         printf("小端存储\n");
//     }
//     else {
//         printf("大端存储\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// int check_sys() {
//     // union Un {
//     //     char c;
//     //     int i;
//     // }u;
//     // u.i = 1;
//     //可以直接写成匿名联合 因为只使用了一次

//     union {
//         char c;
//         int i;
//     }u;
//     u.i = 1;
//     return u.c;
// }
// int main() {
//     int ret = check_sys();
//     if (ret == 1) {
//         printf("小端存储\n");
//     }
//     else {
//         printf("大端存储\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// union Un {
//     //这里相当于5个char
//     char arr[5];
//     int i;
// };

// int main() {
//     printf("%d\n", sizeof(union Un));//8
//     return 0;
// }
// 联合也存在对齐，i的对齐数取4,所以联合的内存大小为4的倍数,一共浪费了3字节


