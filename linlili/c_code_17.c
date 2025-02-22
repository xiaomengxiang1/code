//指针变量存储内存地址
//可以通过指针找到数据并且修改
//python中变量存储内存地址，并且指向存储的数据

#include <stdio.h>

int main() {
    char ch = 'A';
    char* ptr = &ch;

    printf("before:%c\n",ch);
    *ptr = 'a';
    printf("now:%c\n",ch);
    // printf("now:%c\n",*ptr);     这么写也可以，说明指针指向数据
    return 0;
}