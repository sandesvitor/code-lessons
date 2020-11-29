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



// Get, Set, Max, Min:

int Get(Array arr, int index){
    if(index >= 0 && index < arr.lenght)
        return arr.A[index];
}

void Set(Array *arr, int index, int x){
    if(index >= 0 && index < arr->lenght)
        arr->A[index] = x;
}

int Max(Array arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.lenght; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(Array arr){
    int min = arr.A[0];
    for(int i = 0; i < arr.lenght; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(Array arr){
    int total = 0;
    for(int i = 0; i < arr.lenght; i++){
        total += arr.A[i];
    }

    return total;
}

int SumWitRecursion(Array arr, int n){
    int total = 0;
    if(n < 0) {
        return 0;
    } else {
        return SumWitRecursion(arr, n - 1) + arr.A[n];
    }
}

int Average(Array arr){
    int total = 0;
    for(int i = 0; i < arr.lenght; i++){
        total += arr.A[i];
    }
    return total/arr.lenght;
}


int main(int argc, char* argv[]) {

    Array arr;
    arr.size = 15;
    arr.A = (int *)malloc(arr.size * sizeof(int));

    Append(&arr, 4);
    Append(&arr, 8);
    Append(&arr, 10);
    Append(&arr, 15);
    Append(&arr, 18);
    Append(&arr, 1);
    Append(&arr, 24);
    Append(&arr, 700);
    Append(&arr, 29);
    Append(&arr, 33);
    Append(&arr, 34);
    Append(&arr, 37);
    Append(&arr, 39);
    Append(&arr, 41);
    Append(&arr, 43);
    
    Display(arr);

    std::cout << "Max Value: " << Max(arr) << std::endl;
    std::cout << "Min Value: " << Min(arr) << std::endl;
    std::cout << "Sum of Values: " << Sum(arr) << std::endl;
    std::cout << "Sum of Values (recursive): " << SumWitRecursion(arr, arr.lenght - 1) << std::endl;
    std::cout << "Average: " << Average(arr) << std::endl;

    delete arr.A;
    return 0;
}