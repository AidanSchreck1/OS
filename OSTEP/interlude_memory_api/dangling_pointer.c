#include <stdio.h>

int *makePointer() {
    int local = 42;
    return &local;
}

int main() {
    int *p = makePointer();
    printf("%d\n", *p);
    return 0;
}
