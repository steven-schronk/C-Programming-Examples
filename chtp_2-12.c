#include <stdio.h>

int main(){
    int a = 15, b = 4, c = 7;
    printf("%d\n", a % b);
    printf("%d\n", a % c + b);
    printf("b=\n");
    printf("a = 15\n");
    printf("%d = a + b\n", a + b);
    printf("Enter an integer:\n");
    scanf("%d%d", &a, &b);
    printf("%d, %d\n", a , b);

    a = 2; b = 4;
    a = b * a;

    printf("a = %d, b = %d \n", a, b);
    printf("Enter an integer:\n");
    scanf("%d", &a);
    printf("Enter an integer:\n");
    scanf("%d", &b);

    printf("a = %d, b = %d \n", a, b);
    puts("Hello World");

    return 0;
}
