#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("%d\n", **pp);

    **pp = 100;
    printf("%d\n", x);

    return 0;
}
