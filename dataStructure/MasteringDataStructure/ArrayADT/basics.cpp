/*
    ADT = Abstract Data Type

    Data:
        1. Array Space;
        2. Size;
        3. Length;
    
    Operations:
        1. Display();
        2. Add(x)/Append(x);
        3. Insert(index, x);
        4. Delete(index);
        5. Search(x);
        6. Get(index);
        7. Set(index, x);
        8. Max()/Min();
        9. Reverse()
        10. Shift()/Rotate()
*/

#include <iostream>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int lenght;
} typedef Array;

void Display(Array arr){
    int i;
    std::cout << "Elements are: ";
    for(i = 0; i < arr.lenght; i++){
        std::cout << arr.A[i] << " ";
    }
}

int main(int argc, char* argv[]) {

    Array arr;
    std::cout << "Enter size of an array:" << std::endl;
    std::cin >> arr.size;
    
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.lenght = 0;

    int n;
    std::cout << "Enter number of numbers:" << std::endl;
    std::cin >> n;

    std::cout << "Enter " << n << "element(s)" << std::endl;
    for(int i = 0; i < n; i++){
        std::cin >> arr.A[i];
    }
    arr.lenght = n;
    
    Display(arr);

    free(arr.A);

    return 0;
}