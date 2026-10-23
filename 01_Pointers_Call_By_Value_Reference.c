#include <stdio.h>

void callByValue(int x) { x = 20; }
void callByReference(int *x) { *x = 20; }

int main() {
    int a = 10, b = 10;
    printf("Before: a=%d, b=%d\n", a, b);
    callByValue(a);
    callByReference(&b);
    printf("After Call by Value: a=%d\n", a);
    printf("After Call by Reference: b=%d\n", b);
    return 0;
}
