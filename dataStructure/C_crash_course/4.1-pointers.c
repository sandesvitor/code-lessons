#include <stdio.h>

void square(int *num)
{
    *num *= *num;
}

void sizeExample(int ages[])
{
    printf("memory size of ages = %lu\n", sizeof(ages));
}

int main()
{
    int a = 100;
    int *b = &a;

    printf("a = %d\n", a);
    printf("*b = %d\n", *b); //dereferencing a pointer

    a = 200;

    printf("a = %d\n", a);
    printf("*b = %d\n", *b); //dereferencing a pointer

    *b = 300;

    printf("*b = %d\n", *b); //dereferencing a pointer
    printf("a = %d\n", a);

    int c = 6000;
    b = &c;

    a = 4000;

    printf("*b = %d\n", *b); //dereferencing a pointer
    printf("a = %d\n", a);

    c = 1000;
    printf("*b = %d\n", *b); //dereferencing a pointer

    int x = 5;
    printf("x (before) = %d\n", x);
    square(&x);

    printf("x (after) = %d\n", x);

    int size = 6;
    int ages[] = {2, 43, 6000, 23, 05, 53};

    printf("memory size of ages = %lu\n", sizeof(ages));
    sizeExample(ages[size]);

    return 0;
}