#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //required for the memory functions!
#include <string.h>

typedef struct User
{
    char name[30];
    int age;
    bool isVerified;
} User;

User *createUser(char name[], int age, bool isVerified)
{
    User *newUser = malloc(sizeof(User));
    strcpy(newUser->name, name);
    newUser->age = age;
    newUser->isVerified = isVerified;
    return newUser;
}

int main()
{
    int size;
    printf("How many elements you need?: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int)); // determes a poiter!
    if (arr == 0)
    {
        printf("Invalid pointer. Error allocating memory\n");
        return -1;
    }
    else
    {
        printf("yOU'RE A GOOD TO GO!\n");
    }

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Your array\n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    printf("Memory freed!\n");

    User *me = createUser("Caleb Curry", 72, false);

    printf("Caleb is %d years olf\n", me->age);
    return 0;
}