#include <stdio.h>

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

int main()
{
    int x = 5;
    x *= x;
    printf("5 * 5 = %d\n", x);

    int result1 = square(9);
    printf("9 * 9 = %d\n", result1);

    int result2 = cube(21);
    printf("21 ^ 3 = %d\n", result2);

    int result3 = power(2, 2);
    printf("2 ^ 2 = %d\n", result3);

    int result4 = power(3, 3);
    printf("3 ^ 3 = %d\n", result4);

    int value = 5;
    changeVal(&value);
    printf("%d\n", value);

    // arrays and functions
    int size = 7;
    int ages[] = {1, 4, 5, 150, 20, 52, 100};
    printf("%d\n", oldestAge(ages, size));
    return 0;
}