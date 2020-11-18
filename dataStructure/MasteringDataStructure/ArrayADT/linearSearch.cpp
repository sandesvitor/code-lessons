#include <iostream>

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


int LinearSearch(Array *arr, int element){
    for(int i = 0; i < arr->lenght; i++){
        if(element == arr->A[i]) return i;
    }
    return -1;
}


int main(int argc, char* argv[]) {
    Array arr;
    arr.size = 10;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    
    Append(&arr, 10);
    Append(&arr, 1);
    Append(&arr, 90);
    Append(&arr, 12);
    Append(&arr, 47);
    Append(&arr, 29);

    Display(arr);

    int x;
    std::cout << "Type element to search (linear search): ";
    std::cin >> x;
    std::cout << "Element " << x << " is in index " << LinearSearch(&arr, x) << std::endl;


    return 0;
}
