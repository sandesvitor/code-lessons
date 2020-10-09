#include "3.2-libraries.h"

int square(int num)
{
    return num * num;
}

int cube(int num)
{
    return num * num * num;
}

int power(int base, int exponent)
{
    int total = 1;
    for (int i = 0; i < exponent; i++)
    {
        total *= base;
    }
    return total;
}

// recursion:
int recursivePower(int base, int exponent)
{
    if (exponent < 1)
    {
        return 1;
    }
    return base * recursivePower(base, exponent - 1);
}

void changeVal(int *input) // pointer!
{
    *input = 90000;
}

int oldestAge(int ages[], int size)
{
    int largest = ages[0];
    for (int i = 1; i < size; i++)
    {
        if (ages[i] > largest)
        {
            largest = ages[i];
        }
    }

    return largest;
}