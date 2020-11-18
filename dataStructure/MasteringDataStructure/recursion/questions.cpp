/*
    fun(5)
    x = 1
    for(k = 1; k<n;k++){
        x = x + fun(k) * fun(n - k);
    }
    return x;
*/

#include <iostream>

int count(int n){
    static int d = 1;

    std::cout << n << std::endl;
    std::cout << d << std::endl;

    d += 1;

    if(n > 1) count(n - 1);
    std::cout << d << std::endl;

}

int main(int argc, char* argv[]) {
    count(3);
    
    return 0;
}