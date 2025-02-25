#include <stdio.h>
int main(){
    int h, m, s;
    printf("Seconds:");
    scanf("%d", &s);
    //h = s % (60*60);
    h = s/3600;
    s %= 3600 * h;
    m = s / 60;
    s %= 60 * m;

    printf("H: %d, M: %d, S: %d\n", h,m,s);
}
