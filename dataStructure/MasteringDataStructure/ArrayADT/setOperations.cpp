#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

struct Array
{
    int *A;
    int size;
    int lenght = 0;

} typedef Array;

void Display(Array arr){
    int i;

    if(arr.lenght == 0) {
        std::cout << "There is 0 elements in this array." << std::endl;
        return;    
    }
    std::cout << "Elements are: ";
    for(i = 0; i < arr.lenght; i++){
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}

void Append(Array *arr, int x){
    if(arr->size == arr->lenght){
        std::cout << "Array memory is full!" << std::endl;
        return;
    }
    arr->A[arr->lenght] = x;
    arr->lenght++;
}

Array* UnionSorted(Array *arr1, Array *arr2){
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = (Array *)malloc(sizeof(Array));

    while (i < arr1->lenght && j < arr2->lenght)
    {
        if(arr1->lenght && j < arr2->lenght)
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr1->A[i++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->lenght;i++)
        arr3->A[k++] = arr1->A[i];
    for(;k<arr2->lenght;j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->lenght = k;
    arr3->size = arr1->size + arr2->size;
    
    return arr3;
}


int main(int argc, char* argv[]) {

    Array A;
    A.size = 5;
    A.A = (int *)malloc(A.size * sizeof(int));
    Append(&A, 3);
    Append(&A, 5);
    Append(&A, 10);
    Append(&A, 4);
    Append(&A, 6);
    
    Array B;
    B.size = 5;
    B.A = (int *)malloc(B.size * sizeof(int));
    Append(&B, 12);
    Append(&B, 4);
    Append(&B, 7);
    Append(&B, 2);
    Append(&B, 5);
    
    std::cout << "Set Operations with Unsorted Arrays:" << std::endl;
    Display(A);
    Display(B);
    std::cout << "\n" << std::endl;

    // UNION: O(n²)

    Array *C;
    C = UnionSorted(&A, &B);
    Display(*C);
    
    // INTERSECTION (COMPARING ALL ELEMENTS): O(n²)
    



    std::sort<int *>(A.A, A.A + A.size);
    std::sort<int *>(B.A, B.A + B.size);
    std::cout << "Set Operations with Sorted Arrays:" <<std::endl;
    Display(A);
    Display(B);
    std::cout << "\n" << std::endl;
    
    // UNION == MERGING: O(n)

    // INTERSECTION (COPYING ONLY DUPLICATES): O(n)



    free(A.A);
    free(B.A);

    return 0;
}
