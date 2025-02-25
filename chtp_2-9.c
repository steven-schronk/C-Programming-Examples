#include <stdio.h>

int main(){
    printf("%s", "Have a nice day.");
    int a = 0, b = 1, c = 2;
    a = b+c;
    if(a > b){ c = a - b; }
    printf("%d", a);
    int p, q, r, x;
    x = scanf("%d %d %d", &p, &q, &r);
    printf("%d, %d, %d, %d", p,q,r,x);

    return 0;
}
