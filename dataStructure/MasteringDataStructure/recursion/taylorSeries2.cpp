/*
    Taylor Series using Horner's Rule!

    Number of Multiplications required:

        n(n + 1) = O(n²)

    We can separate common multiplications:
    Ex: n == 4

    e^x = 1 + x/1*[ 1 + x/2*[1 + x/3*[1 + x/4]]]

    ==> this transform in linear fashion O(n)!
*/

#include <iostream>

double e(int x, int n){
    static double s;
    if(n == 0){
        return s;
    }

    s = 1 + x * s/n;
    return e(x, n-1);
}

int main(){
    std::cout << e(1, 10) << std::endl;
    return 0;
}