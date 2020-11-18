#include <iostream>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    
    int *p, *q;

    p = (int*)malloc(5 * sizeof(int));
    
    p[0] = 3;
    p[1] = 5;
    p[2] = 10;
    p[3] = 22;
    p[4] = 1;

    for(int i = 0; i < 5; i++){
        std::cout << p[i] << std::endl;
    }

    // making a temp pointer!
    q = (int*)malloc(10 * sizeof(int));
    for(int i = 0; i < 5; i++){
        q[i] = p[i];
    }

    std::cout << "\n##############\n" << std::endl;

    // making the exchange:
    free(p);
    p = q;
    q = nullptr;

    for(int i = 0; i < 5; i++){
        std::cout << p[i] << std::endl;
    }

    return 0;
}