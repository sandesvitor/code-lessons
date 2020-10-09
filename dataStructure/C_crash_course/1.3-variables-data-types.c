#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a = 10;
    printf("Size of Integer: %d bytes\n", sizeof(a));

    double b = 10.5;
    // double precision => 8 bytes = 64 bite number
    printf("Size of Double: %lu bytes\n", sizeof(b)); // "lu" ---> unassigned long (positiv long)

    float c = 10.5;
    // single precision => 4 bytes = 32 bite number
    printf("Size of Float: %lu bytes\n", sizeof(c));

    char d = 'a';
    char e[] = "char array"; // aka String!
    bool f = false;

    // implicit type conversion:
    int zero = .99999999999;
    printf("Zero is %d\n", zero);

    // type casting:
    int slice = 17; // slices of pizza
    int people = 2;

    double slicesPerPerson = slice / people; // ---> expected: 8.5 slices/person
    // result int/int ---> 8
    printf("Slices per person = %lf\n", slicesPerPerson);

    double slicesPerPerson2 = (double)slice / people;
    // explicit type conversion (casting)
    printf("Slices per person (refactored) = %lf\n", slicesPerPerson2);

    double test1 = (25 / 2) * 2;       // 24.0
    double test2 = (25 / 2) * 2.0;     //24.0
    double test3 = (double)25 / 2 * 2; // 25.0

    printf("test1: %f\n", test1);
    printf("test2: %f\n", test2);
    printf("test3: %f\n", test3);

    return 0;
}