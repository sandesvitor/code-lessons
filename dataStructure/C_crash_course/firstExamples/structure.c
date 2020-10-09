#include <stdio.h>

struct Rectangle
{
    int length;
    int height;
};

struct Complex
{
    int real;
    int img;
};

struct Student
{
    int roll;
    char name[25];
    char dept[10];
    char address[50];
};

int main()
{
    struct Rectangle r;
    r.length = 15;
    r.height = 10;

    printf("Area of Rectangle is %d\n", r.length * r.height);

    struct Complex c = {2, 7};

    printf("Complex Number = %d + %d i\n", c.real, c.img);

    return 0;
}