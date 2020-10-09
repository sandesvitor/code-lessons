#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("\nForce procedence with ()\n");
    int x = 2 * (3 + 3);
    int y = 2 * 3 + 3;

    printf("x = %d\ny = %d", x, y);

    printf("\nModulus operator:");
    int m = 10 % 3;
    printf("10 %% 3 = %d", m);

    return 0;
}