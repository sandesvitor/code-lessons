#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int *A[3]; // array of 3 pointers!

    for(int i = 0; i < 3; i++){
        A[i] = new int[4];
    }

    // or:
    // for(int i = 0; i < 3; i++){
    //     A[i] = (int*)malloc(4 * sizeof(int));
    // }

    // double pointer:
    int** B; // only this double pointers is in STACK
    B = new int*[3];
    for(int i = 0; i < 3; i++){
        B[i] = new int[4];
    }


    delete []A;
    delete []B;

    std::cout << "Hello, Friend!" << std::endl;
    return 0;
}