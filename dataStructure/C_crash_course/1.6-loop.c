#include <stdio.h>

int main()
{
    int size = 10;
    int ages[] = {12, 43, 545, 3, 4, 54, 6, 7, 87, 12};
    int calculateSize = sizeof(ages) / sizeof(ages[0]);

    for (int i = 0; i < calculateSize; i++)
    {
        printf("ages[%d] = %d\n", i, ages[i]);
    }
}