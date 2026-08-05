#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);
    printf("*p = %d\n", *p);

    *p = 20;
    printf("x = %d\n", x);

    return 0;
}
