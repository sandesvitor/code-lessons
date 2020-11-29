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


// Reverse, Shift Right, Shift Left, Rotate Right, Rotate Left:
void Reverse(Array *arr){
    int i, j;
    Array tmp;
    tmp.size = arr->size;
    tmp.A = (int *)malloc(tmp.size * sizeof(int));

    for(i = arr->lenght - 1, j = 0; i >= 0; i--, j++){
        tmp.A[j] = arr->A[i];
    }

    for(int i = 0; i < arr->lenght; i++){
        arr->A[i] = tmp.A[i];
    }

    delete tmp.A;
}

void ReverseWithSwap(Array *arr){
    int i, j;
    int tmp;
    for(i = 0, j = arr->lenght - 1; i < j; i++, j--){
        tmp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = tmp;
    }
}

void LeftShift(){

}

void LeftRotation(){
    
}


int main(int argc, char* argv[]) {
    Array arr;
    arr.size = 10;
    arr.A = (int *)malloc(arr.size * sizeof(int));

    Append(&arr, 8);
    Append(&arr, 3);
    Append(&arr, 9);
    Append(&arr, 15);
    Append(&arr, 6);
    Append(&arr, 10);
    Append(&arr, 7);
    Append(&arr, 2);
    Append(&arr, 12);
    Append(&arr, 4);
    Display(arr);

    Reverse(&arr);
    Display(arr);

    ReverseWithSwap(&arr); // more optimized!
    Display(arr);

    delete arr.A;

    return 0;
}