#include <stdio.h>
#include <stdbool.h>

int isTrue()
{
    return true;
}

int main()
{
    if (!isTrue())
    {
        printf("This is true!");
    }
    else
    {
        printf("This is false...");
    }

    double balance = -5000;

    bool hasMoney = balance > 0 ? true : false;

    return 0;
}