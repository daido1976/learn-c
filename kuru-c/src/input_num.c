#include <stdio.h>

int main(void)
{
    int data1, data2;
    printf("data1 に入力してください\n");
    scanf("%d", &data1);
    printf("data2 に入力してください\n");
    scanf("%d", &data2);
    printf("足すと%dです\n", data1 + data2);
    return 0;
}
