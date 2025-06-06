//-----------------------------------------------初识c----------------------------------------


// 局部变量     -{}内部定义的变量
// 全局变量     -{}外部定义的变量


// int a = 10; //全局变量
// int main() {
//     int b = 10;
//     return 0;   //局部变量
// }

//全局变量和局部变量名字相同的时候优先局部变量
//局部变量的生命周期：在进入作用域时开始,出作用域时结束
//全局变量的生命周期是整个程序的生命周期


//常量
//1.字面常量
// 3.14
// 123

//2.const修饰常变量
//const int a = 10;
//a的本质是变量，不能修改，其具有常量的属性

//3.define 定义的标识符常量
//#define MAX 100
//#define STR "abcdef"

//4.枚举常量
// --------------------------------------------------------------------------------

// #include <stdio.h>
// #include <string.h>

// int main() {
//     int len = strlen("abc");    //求字符串的长度
//     printf("%d\n", len);    
// }


//'\0'是字符串的停止标志，如打印终止或者计算字符长度终止
// #include <stdio.h>
// int main() {
//     printf("jjj\0jjj");
// }

//转义符：转变字符意思的符号
// #include <stdio.h>
// int main() {
//     printf("\"");    打印一个双引号
// }

//tab键和\t(水平制符表)效果一样

//  \ddd ddd表示1到3个的八进制数字 如：\130 x
//  \xdd dd表示2个十六进制的数字 如\x63 c

// #include <stdio.h>修饰过后的局部变量，

// int main() {
//     printf("%c\n",'\130');
//     printf("%c\n",'\x63');
// }

//printf("%d\n",strlen("c:\test\628\test.c"));
//一共14个字符\t算一个\62算一个

// #include <stdio.h>
// int Add(int x, int y) {
//     int z = 0;
//     z = x + y;
//     return z;
// }

// int main() {
//     int a = 0;
//     int b = 0;
//     //输入
//     scanf("%d %d", &a, &b);
//     int sum = Add(a,b);
//     printf("a + b = %d\n",sum);
//     return 0;
// }


//int a = 0;    初始化
//a = 10;       赋值

//int a = 10;
//int b = a++;
//int b = a; a = a + 1;
//后置++，先使用后++

//后置++，先++后使用
//--同理

//  && 与
//  || 或

//typedef(类型重命名) 相当于重命名 python中的as

//static局部变量出作用域后，不销毁
//本质上。static修饰局部变量的时候，改变了变量的存储位置
//改变了生命周期，生命周期变长

// 栈区     局部变量

// 堆区

// 静态区   静态变量

//函数前面的    void    意思是不需要任何的返回

//extern    在文件中声明其他文件的变量，函数，从而使用其他文件的东西，应该相当于python的import
//static修饰全局变量的时候其它.c文件无法调用(外部链接属性变成内部链接属性)

// #include <stdio.h>
// int main() {
//     int a = 1;
//     printf("%p\n",&a); //%p打印地址
//     int* p = &a;

//     //* 说明p是指针变量
//     //int 说明了指针指向的变量是int类型
//     //p 是指针变量

//     *p = 2;
//     //解引用操作符，通过p中存放的地址找到p指向的对象
//     printf("%d\n",a);
//     return 0;
// }

//结构体
//像python里的类

//学生
// #include <stdio.h>
// struct Stu {

//     //成员
//     char name[20];
//     int age;
//     char sex[10];
//     char tale[12];
// };

// //指针变量ps指向struct Stu类型
// //*ps就是s(指向s内存地址)
// void print(struct Stu* ps) {
//     printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tale);

//     // ->
//     //结构体指针变量->成员名
//     printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tale);
// }

// int main() {

//     struct Stu s = {"zhangsan", 20, "nan", "10086"};

//     //结构体.成员
//     // printf("%s %d %s %s\n", s.name, s.age, s.sex, s.tale);  //%s用于打印 字符串（char 数组或 char 指针）

//     print(&s);
//     return 0;
// }

//define 不是关键字，是预处理指令

//-----------------------------------------------初阶c----------------------------------------

//字符本质上也是整型
// switch (整型表达式) {
//     语句项：
// }

// case 整型常量表达式：
//     语句；
//分支中的break只会终止分支的代码


//--------while循环---------
//break 跳出循环
//continue 跳过后面的代码，直接开始下一轮循环

//--------for循环---------

// for (初始化表达式; 条件判断; 调整部分)
//先进行初始化表达式，然后进行条件判断，执行完循环的代码后才进行表达式的更新
//break和continue作用在当前的for中,嵌套循环不会对所有起作用

//--------do while循环---------
//至少循环一次

// goto语句
//比较适合退出多层循环

// #include <stdio.h>
// int main() {
// again:
//     printf("hehe\n");
//     printf("hehe\n");
//     printf("hehe\n");
//     printf("hehe\n");
//     goto again;
//     return 0;
// }

//自定义函数

//比较两个数字的大小
//三目运算符(exp1?exp2:exp3)，若exp1成立，执行exp2，反之执行exp3
// int get_max(int x, int y) {
//     return (x > y ? x : y);
// }
// #include <stdio.h>
// int main() {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     int m = get_max(a, b);
//     printf("%d", m);
//     return 0;
// }

//交换两个变量的值

// #include <stdio.h>

// //形式参数
// void swap(int x, int y) {
//     int z = 0;
//     z = x;
//     x = y;
//     y = z;
// }
// void swap(int* px, int* py) {
//     int z = *px;//z = x
//     *px = *py;//x = y
//     *py = z;//y = z
// }

// //当实参传递给形参的时候,形参是实参的一份临时拷贝
// //对形参的修改不会影响实参
// int main() {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     //交换
//     printf("交换前:a=%d b=%d", a, b);
// //传递实参
//     // swap(a, b);
//     swap(&a,&b);
//     printf("交换后:a=%d b=%d", a, b);
//     return 0;
// }

//实参:传递给函数的真实的值
//形参:定义函数的时候的传入值,形式参数相当于局部变量,作用域在定义的函数内部
//形参通常存放在栈区

//传值调用:形参和实参分别占有不同的内存块,函数内部对形参的修改不会影响实参
//传址调用:将函数外部创建的变量的内存地址传递给函数,形参和实参这时建立起真正的联系

//递归(避免栈溢出)
//1.要具有限制条件
//2.每次递归调用完后越来越接近限制条件

//c99标准之前,数组的大小必须是常量或者常量表达式
//c99标准之后,数组的大小可以是变量,为了支持变长数组
// #include <stdio.h>
// int main() {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     // 打印每个数组元素的地址
//     for (i = 0; i < sz; i++) {
//         printf("arr[%d] = %p\n", i, &arr[i]);
//     }
//     return 0;
// }
//数组在内存中是连续存放的
// arr[0] = 00000001929ff8f0
// arr[1] = 00000001929ff8f4
// arr[2] = 00000001929ff8f8
// arr[3] = 00000001929ff8fc
// arr[4] = 00000001929ff900
// arr[5] = 00000001929ff904
// arr[6] = 00000001929ff908
// arr[7] = 00000001929ff90c
// arr[8] = 00000001929ff910
// arr[9] = 00000001929ff914
//每个元素差4
//int 4个字节

//二维数组的创建
// int arr[行][列]

// 列不能省略
// int arr[][4] = {{1,2,3,4},{2,3}};

//二维数组的基本访问
// #include <stdio.h>
// int main() {
//     int arr[3][4] = {1,2,3,4,2,3,4,5,4,5,6,7};
//     int i = 0;
//     for (i = 0; i < 3; i++) {
//         int j = 0;
//         for (j = 0; j < 4; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// ％p，打印地址，后面加上取地址符号
// #include <stdio.h>
// int main() {
//     int arr[3][4] = {1,2,3,4,2,3,4,5,4,5,6,7};
//     int i = 0;
//     for (i = 0; i < 3; i++) {
//         int j = 0;
//         for (j = 0; j < 4; j++) {
//             printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//         }
//     }
//     return 0; 
// }

// &arr[0][0] = 000000751efff9f0
// &arr[0][1] = 000000751efff9f4
// &arr[0][2] = 000000751efff9f8
// &arr[0][3] = 000000751efff9fc
// &arr[1][0] = 000000751efffa00
// &arr[1][1] = 000000751efffa04
// &arr[1][2] = 000000751efffa08
// &arr[1][3] = 000000751efffa0c
// &arr[2][0] = 000000751efffa10
// &arr[2][1] = 000000751efffa14
// &arr[2][2] = 000000751efffa18
// &arr[2][3] = 000000751efffa1c
// 二维数组在内存中也是连续存放的


// 数组越界访问
// 其实arr就是指针，越界了就是指针往后走了，指向了数组后面的空间

// 越界
// #include <stdio.h>
// int main() {
//     int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
//     int i = 0;
//     for (i = 0; i < 3; i++) {
//         int j = 0;
//         for (j = 0; j <= 4; j++) {
//             printf("%d ", arr[i][j]);
//         }
//     }
//     return 0;
// }
// 1 2 3 4 5 5 6 7 8 9 9 10 11 12 -549163912



// 数组的传参的两种形式
// 1.数组
// 传的是元素首地址,并不是创建一个数组的形参


// 传给形参的是数组的头元素的地址，所以不能再定义的函数中计算实参数组的元素个数
// void bubble_sort(int arr[], int sz) {
//     //  总的排序次数
//     // int sz = sizeof(arr) / sizeof(arr[0]); //不能直接在函数内部计算数组长度  这边是指针变量之间的计算
//     int i = 0;
//     for (i = 0; i < sz - 1; i++) {
//         // 一趟排序几次 9个数两两比较要8次
//         // 重头开始比较
//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 //交换
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }

//     }
// }

// // 2.指针

// #include <stdio.h>
// int main() {
//     //将数组改为升序
//     //冒泡排序
//     // 一趟排序将一个数放到位置上
//     // n个数据排序n-1次
//     int arr[] = {7,6,5,4,3,2,1};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, sz);

//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         printf("%d", arr[i]);
//     }
//     return 0;
// }


// 数组名
// 数组名确实能表示首元素的地址
// 有两个例外
// 1.sizeof(arr)     这里表示整个数组
// 2.&数组名      这里的数组名表示整个数组的地址，取出的是整个数组的地址

// #include <stdio.h>
// int main() {
//     int arr[10] = {0};
    
//     printf("%p\n", arr);
//     printf("%p\n", arr + 1);
//     printf("--------------------------\n");
//     printf("%p\n", &arr[0]);
//     printf("%p\n", &arr[0] + 1);
//     printf("--------------------------\n");
//     printf("%p\n", &arr);
    // printf("%p\n", &arr + 1);   //加1表示跳过当前整个数组
// }    
    // 0000006c213ffb10
    // 0000006c213ffb14
    // --------------------------
    // 0000006c213ffb10
    // 0000006c213ffb14
    // --------------------------
    // 0000006c213ffb10
    // 0000006c213ffb38


//二维数组    
// int arr[3][4];
// arr;
//这里的arr表示的也是二维数组的首元素(首行，并不是[0][0])的地址
// #include <stdio.h>
// int main() {
//     int arr[3][4] = {0};
//     int sz_hang = sizeof(arr) / sizeof(arr[0]);
//     int sz_lie = sizeof(arr[0]) / sizeof(arr[0][0]);
//     int sz_zong = sizeof(arr) / sizeof(arr[0][0]);

//     printf("%d, %d, %d\n", sz_hang, sz_lie, sz_zong);
//     return 0;
// }