//int a
//scanf("%d", &a);

//声明整型变量a,先在内部中开辟一块内存用于存储a
//&为取地址符，指向变量a的地址，将用户输入的数字存储到指定地址中

//char b
//scanf(" %c", &b)
//占位符前面加一个空格可以使scanf忽略掉空白字符

#include <stdio.h>

int main() {
    char category;
    float price;

    // 修正输入格式，防止 scanf 读取错误
    printf("请输入商品类别 (A 代表电子产品, B 代表服装) 和价格（格式: A,500）：\n");
    scanf(" %c,%f", &category, &price);

    if (category == 'A') {
        if (price < 500) {
            printf("电子产品价格较低，无优惠。\n");
        } else if (price <= 1000) {
            printf("电子产品可享受 5%% 的优惠。\n");
        } else {
            printf("电子产品可享受 10%% 的优惠。\n");
        }
    } else if (category == 'B') {
        if (price < 200) {
            printf("服装价格较低，无优惠。\n");
        } else if (price <= 500) {
            printf("服装可享受 8%% 的优惠。\n");
        } else {
            printf("服装可享受 15%% 的优惠。\n");
        }
    } else {
        printf("输入错误，请输入 A 或 B。\n");
    }

    return 0;
}
