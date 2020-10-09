#include <stdio.h>

typedef struct
{
    int lenght;
    int width;
} Rectangle;

typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    char owner[30];
    Rectangle rectangle;
    Position position;
} BuildingPlan;

int main()
{
    Rectangle myRectangle = {5, 10};
    printf("Leght: %d\nWidth: %d\n", myRectangle.lenght, myRectangle.width);

    BuildingPlan myHouse = {"Caleb CUrry", {5, 10}, {32, 48}};
    printf("The house at [%d] [%d] (size [%d] [%d]) is owned by %s\n",
           myHouse.position.x,
           myHouse.position.y,
           myHouse.rectangle.lenght,
           myHouse.rectangle.width,
           myHouse.owner);

    int size = 3;
    Position path[] = {{0, 1}, {1, 2}, {3, 4}};

    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", path[i].x, path[i].y);
    }

    BuildingPlan *structPointer = &myHouse;
    printf("structPointer->position.x = %d", structPointer->position.x);

    return 0;
}