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

// #include <stdio.h>

// int main() {
//     printf("%c\n",'\130');
//     printf("%c\n",'\x63');
// }

//printf("%d\n",strlen("c:\test\628\test.c"));
//一共14个字符\t算一个\62算一个

#include <stdio.h>
int Add(int x, int y) {
    int z = 0;
    z = x + y;
    return z;
}

int main() {
    int a = 0;
    int b = 0;
    //输入
    scanf("%d %d", &a, &b);
    int sum = Add(a,b);
    printf("a + b = %d\n",sum);
    return 0;
}

