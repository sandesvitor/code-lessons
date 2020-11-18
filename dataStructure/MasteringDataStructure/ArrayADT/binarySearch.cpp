/*
    For Binary Search, the list of elements must be SORTED!
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


int BinarySearch(Array arr, int key){
   int high = arr.lenght - 1;
   int low = 0;
   int mid;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if(key == arr.A[mid]){
            return mid;
        } else if (key < arr.A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int BinarySearchWithRecursion(int a[], int l, int h, int key){
    int mid;

    if(l <= h){
        mid = (h + l)/2;
        if(key == a[mid]){
            return mid;
        } else if (key < a[mid]){
            return BinarySearchWithRecursion(a, l, mid-1, key);
        } else {
            return BinarySearchWithRecursion(a, mid+1, h, key);
        }
    }
}


int main(int argc, char* argv[]) {
    Array arr;
    arr.size = 10;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    
    Append(&arr, 1);
    Append(&arr, 3);
    Append(&arr, 9);
    Append(&arr, 12);
    Append(&arr, 47);
    Append(&arr, 290);
    Display(arr);


    int x;
    std::cout << "Type element to search (binary search): ";
    std::cin >> x;
    std::cout << "Element " << x << " is in index " << BinarySearchWithRecursion(arr.A, 0, arr.lenght - 1, x) << std::endl;


    return 0;
}
