#include <stdio.h>
#include <stdlib.h>

// you can write fun(int *A, int size){...}
void fun(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}

void fun2(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i] = i * A[i];
    }
}

// Return array
int *fun3(int n)
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return (p);
}

int main()
{
    // ARRAYS MUST BE PASS AS ADRESSES, NOT VALUE!

    int A[5] = {2, 3, 4, 5, 8};
    fun(A, 5);

    int B[5] = {1, 30, 41, 6, 10};
    fun2(B, 5);

    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", B[i]);
    }

    int *C;
    C = fun3(5);
    return 0;
}