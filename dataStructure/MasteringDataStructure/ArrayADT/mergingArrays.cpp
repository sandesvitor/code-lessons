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

Array* MergedArray(Array *A, Array *B){
    int i,j, k = 0;

    // C.lenght = A->lenght + B->lenght;
    Array *C = (Array *)malloc(sizeof(Array));

    while(i < A->lenght && j < B->lenght){
        if(A->A[i] < B->A[j]){
            C->A[k++] = A->A[i++];
        } else {
            C->A[k++] = B->A[j++];
        }
    }
    for(;i<A->lenght;i++){
        C->A[k++] = A->A[i];
    }
    for(;j<B->lenght;j++){
        C->A[k++] = B->A[j];
    }

    C->lenght = A->lenght + B->lenght;
    C->size = 10;
    return C;
}


int main(int argc, char* argv[]) {

    Array a;
    a.size = 10;
    a.A = (int *)malloc(a.size * sizeof(int));
    Append(&a, 3);
    Append(&a, 8);
    Append(&a, 16);
    Append(&a, 20);
    Append(&a, 25);
    
    Array b;
    b.size = 10;
    b.A = (int *)malloc(b.size * sizeof(int));
    Append(&b, 4);
    Append(&b, 10);
    Append(&b, 12);
    Append(&b, 22);
    Append(&b, 23);


    Array* c = MergedArray(&a, &b);
    Display(*c);

    free(a.A);
    free(b.A);
    free(c->A);
    
    return 0;
}