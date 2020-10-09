#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

//Passing parameters as values:
void swapByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Passing parameter as address:
void swapByAddress(int *x, int *y) // ---> must be pointers!!!
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Passing parameter as address (ONLY AVAILABLE IN C++)
//
// reference is just a alias, so, the formal parameters in the function
// declaration are the same as the real parameters in Main()!
void swapByReference(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);
    printf("%d + %d = %d\n", x, y, z);

    int a, b, c, d;
    a = 10;
    b = 300;
    c = 1000;
    d = 3000;

    swapByValue(a, b);
    printf("By Value\na = %d\nb = %d\n", a, b);

    // Function acessing memory of main indirectly using pointers
    swapByAddress(&a, &b);
    printf("By Address\na = %d\nb = %d\n", a, b);

    // in here, swap is part of main function in the Stack(more like
    // Monalitic Programming)
    swapByReference(c, d);
    printf("By Reference(C++)\nc = %d\nd = %d\n", c, d);

    return 0;
}