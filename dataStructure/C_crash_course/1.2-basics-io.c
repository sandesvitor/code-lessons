#include <stdio.h>

int main()
{
    printf("[%s] World\n", "Hello");

    int x = 10;
    int y;
    y = 10;

    printf("(x: [%d], y: [%d])\n", x, y);

    // User input:
    int radius;
    printf("Type the radius of circle: ");
    scanf("%d", &radius); // address-of-operator (pointer)

    printf("Circle radius = %d\n", radius);

    char name[20];
    // char array of 20 characters ---> you got to reserve '\0'
    printf("Type your name: ");
    scanf("%19s", name); // ---> don't need '&'
    printf("Your name is [%s]", name);
    return 0;
}