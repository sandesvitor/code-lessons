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


void Insert(Array *arr, int index, int x){
    if(arr->size == arr->lenght){
        std::cout << "Array memory is full!" << std::endl;
        return;
    }
    if(index >= 0 && index <= arr->lenght){
        for(int i = arr->lenght; i > index; i--){
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->lenght++;
    }

}


int Delete(Array *arr, int index){
    int x = 0;

    if(index < 0 || index > arr->lenght){
        std::cout << "Index out of range!" << std::endl;
        return 0;
    }
    
    x = arr->A[index];
    for(int i = index; i < arr->lenght-1; i++){
        arr->A[i] = arr->A[i + 1];
    }
    arr->lenght--;
    return x;
}


int main(int argc, char* argv[]) {
   
    Array arr;
    arr.size = 5;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    Display(arr);

    Append(&arr, 11);
    Display(arr);
    
    Append(&arr, 89);
    Display(arr);

    Append(&arr, 9);
    Display(arr);

    Append(&arr, 1);
    Display(arr);

    Insert(&arr, 2, 1000);
    Display(arr);

    std::cout << "Element Deleted: " << Delete(&arr, 1) << std::endl;
    Display(arr);

    free(arr.A);
    return 0;
}