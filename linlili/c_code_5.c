// #include <stdio.h>

// int main() {
//     char letter = 'A';
//     printf("The character is: %c\n", letter);  // 输出：The character is: A
//     return 0;
// }

// %c 是格式说明符，用于输出单个字符

// 如果你传入的是一个整数，它会根据对应的 ASCII 值输出字符
// int num = 65;
// printf("Character: %c\n", num);  // 输出：Character: A


//int 存储4byte 32bit 其中1 bit表示正负
//char存储1byte 8bit  最多表示2的8次方(256)个符号 根据ASCII表
//%c 用于输出单个字符（char 类型）
//%d：表示以十进制格式输出整数

// #include <stdio.h>

// int main() {
//     char gender_1 = 'M';
//     char gender_2 = 'A';
//     printf("性别1：%d\n性别2：%d\n", gender_1,gender_2);
//     printf("性别1：%c\n性别2：%c\n", gender_1,gender_2);
//     return 0;
// }

#include <stdio.h>

int main() {
    int int_1 = 80;
    printf("int_1:%d\n",int_1);
    char char_1 = 'A';
    printf("char_1的字符:%c\nchar_1对应的ASCII码值:%d\n",char_1,char_1);
    char char_2;
    char_2 = int_1;
    printf("%c",char_2);
    printf("char字符型在内存中所占用的字节数：%zu\n",sizeof(int));
    //sizeof(int)打印整数字符型在内存中所占用的字节数
    printf("char字符型在内存中所占用的字节数：%zu",sizeof(char));
    return 0;
}