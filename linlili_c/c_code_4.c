//c中声明一个变量的时候计算机会开辟一块空间储存变量，然后再往里面存储值
//  int money = 0;
//  int money = 123;
//重复声明会报错

//python中，计算机会开辟一块内存储存值如123，然后定义一个变量指向它的内存地址
//赋值时并不会复制对象本身，而是创建一个新的引用指向同一对象

#include <stdio.h>


//打印变量的时候和python的站位字符一个写法
//%d：表示以十进制格式输出整数

int main() {
    int mike_score = 89;
    int john_score = 98;
    mike_score = john_score;
    john_score = 89; 
    printf("mike的成绩是：%d\njohn的成绩是：%d", mike_score, john_score);
    return 0;
}