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