#include <stdio.h>

typedef struct Rectangle
{
    int length;
    int width;
} Rectangle;

int areaByValue(Rectangle r1)
{
    return r1.length * r1.width;
}

int areaByReferemce(Rectangle &r1)
{
    return r1.length * r1.width;
}

int changeDimensionsByAddress(Rectangle *p, int newLength, int newWidth)
{
    p->length = newLength;
    p->width = newWidth;
}

int main()
{
    Rectangle rec1 = {10, 5};
    printf("Area of Rectangle = %dm2\n", areaByValue(rec1));

    Rectangle rec2 = {100, 50};
    printf("Area of Rectangle = %dm2\n", areaByReferemce(rec2));

    changeDimensionsByAddress(&rec1, 43, 78);
    printf("Rec1 new dimensions:\nLength = %d\nWidth = %d", rec1.length, rec1.width);
    return 0;
}