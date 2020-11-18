#include <iostream>

/*
    Combinatory Analisys:

    nCr = n!/(r!(n - r)!) ==> O(n)

    fact(n) = 1 * 2 * 3 * ... * n
    = (n - 1) * n
*/

int fact(int n){
    if(n <= 1) return 1;
    return fact(n - 1) * n;
}

int combination(int n, int r){
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1/(t2 * t3);
}

int combinationPascalTriangle(int n, int r){
    if(r == 0 || n == r){
        return 1;
    } else {
        return combinationPascalTriangle(n-1, r-1) +
                combinationPascalTriangle(n-1, r);
    }
}

int main() {
    std::cout << combination(5,1) << std::endl;
    std::cout << combinationPascalTriangle(5,1) << std::endl;
    return 0;
}