/*
    In C, arrays ONLY can be allocated in the main memory
    at COMPILE TIME, therefore, we must ALWAYS defined its size 
    beforehand.

    In C++, we can declare the size at RUN TIME.
*/

#include <iostream>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    
    // STACK allocation of array:
    int A[5];

    // HEAP allocation of array in C
    int *p1;
    p1 = (int*)malloc(5 * sizeof(int));

    // HEAP allocation of array in C++
    int *p2;
    p2 = new int[5];    

    for(int i=0; i < 5; i++){
        p2[i] = 2 * i;
    }

    for(int i=0; i < 5; i++){
        std::cout << p2[i] << "\t" << &p2[i] << std::endl;
    }

    // WE MUST MANUALLY FREE HEAP MEMORY, OTHERWISE MEMORY LEAK
    // MIGHT OCCOR...
    free(p1); // C way
    delete []p2; // C++ way (also works on Objects, calling its Destructor Function!)

    return 0;
}