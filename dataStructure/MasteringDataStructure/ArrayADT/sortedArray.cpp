/*
    Steps:
        - Inserting a new element in a sorted array;
        - Check if the array is sorted;
        - Arranging negative elements on the left side and positive on the righ

*/

#include <iostream>
#include <bits/stdc++.h>

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


void Insert(Array *arr, int x){
    int i = arr->lenght - 1;
    if(arr->lenght == arr->size){
        return;
    }
    while(arr->A[i] > x){
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->lenght++;
}


bool isArraySorted(Array arr){
    for(int i = 0; i < arr.lenght - 1; i++){
        if(arr.A[i] > arr.A[i + 1]){
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    Array arr;
    arr.size = 10;
    arr.A = (int *)malloc(arr.size * sizeof(int));

    Append(&arr, 4);
    Append(&arr, 8);
    Append(&arr, 13);
    Append(&arr, 16);
    Append(&arr, 20);
    Append(&arr, 25);
    Append(&arr, 28);
    Append(&arr, 33);
    Display(arr);

    Insert(&arr, 18);
    Display(arr);

    std::cout << isArraySorted(arr) << std::endl;

    free(arr.A);
    return 0;
}