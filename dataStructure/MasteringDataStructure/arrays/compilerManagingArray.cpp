#include <iostream>

/*
    Formulas Stipulated By the Compiler:

    1 Dimension:
        - Addr(A[i]) = (baseAddress) + index * sizeOfDataType
    

    *(multiple deimensions are allocated linearlly)
    2 Dimensions:
        *(both are equilly efficient)
        1) Row major Mapping (elemnts stored ROW by ROW)
        2) Column Major Mapping (elements stored COLUMN by COLUMN)

        Ex: A[m][n] 
        1 - Addr(A[i][j]) = (baseAddress) + (i*n + j) + sizeOfDataType
        2 - Addr(A[i][j]) = (baseAddres) + (j*m + i) + sizeOfDataType

        * C and C++ follows Row Major Formula!
    

    N Dimensions:
        *(Row major)

        Ex: Type A[d1][d2][d3][d4] (4 Dimensions)

        Addr(A[i1][i2][i3][i4]) = base + (i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4)*size


        General Formula:
        Addr(A[i1]...[in]) = Base + Sigma(from p=1 to p=n)(ip * Q(from p + 1 to n)d) * size





*/

int main(int argc, char* argv[]) {

    int A[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++){
        std::cout << &A[i] << std::endl;
    }
    return 0;
}