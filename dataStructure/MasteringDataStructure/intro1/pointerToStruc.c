#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int lenght;
    int width;
} Rectangle;

main()
{
    printf("Pointer to Strucure");
    Rectangle r = {10, 5};
    Rectangle *p = &r;

    r.lenght = 15;
    p->lenght = 20;

    // creating dinamically:
    // Rectangle *q;
    // q = (Rectangle *)mallock(sizeof(Rectangle));
    // q->lenght = 10;
    // q->width = 5;
    // // created in Heap!
    // printf("%d %d", q->lenght, q->width);

    return 0;
}