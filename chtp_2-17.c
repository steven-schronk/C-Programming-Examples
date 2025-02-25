#include <stdio.h>

int main(){
    int u, a, t;
    printf("Initial Velocity:");
    scanf("%d", &u);
    
    printf("Initial Acceleration:");
    scanf("%d", &a);

    printf("Time:");
    scanf("%d", &t);

    int v =  u + (a*t);
    int d = u * t + .5 * a* (t*t);

    printf("Velocity:%d\n", v);
    printf("Distance:%d\n", d);
    
}
