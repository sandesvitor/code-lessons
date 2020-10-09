#include "3.2-libraries.h"
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