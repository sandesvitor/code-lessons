#include <stdio.h>
#include <string.h>

int main()
{
    char name[20]; // '\0'
    printf("Type your Name: ");
    scanf("%19s", name);

    int letter = 0;
    while (name[letter] != '\0')
    {
        letter++;
    }

    printf("Size of name is %d\n", letter);

    char copy[20];
    strcpy(copy, name);
    printf("Copy of name is %s\n", copy);

    char lastName[] = "Curry";
    strcat(copy, lastName); // append to copy
    printf("Full name %s\n", copy);
    return 0;
}