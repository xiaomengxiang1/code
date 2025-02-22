#include <stdio.h>

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d",&arr[i]);
    }

    for (int a = 0; a < 5; a++) {
        printf("arr[%d]=%d\n",a,arr[a]);
    }
}