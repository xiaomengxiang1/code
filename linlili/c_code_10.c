#include <stdio.h>

int main() {
    int user_type;
    float price;
    price = 180;
    user_type = 2;
    if (user_type == 1) {
        if (price >= 100) {
            price = price * 0.95;
        }
    }
    else {
        if (price >= 200) {
            price = price * 0.9;
        }
        else {
            price = price * 0.79;
        }
    }
    printf("最终的金额为:%.2f",price);
    return 0;
}