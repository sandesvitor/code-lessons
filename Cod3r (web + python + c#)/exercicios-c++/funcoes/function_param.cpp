#include <iostream>
using namespace std;

//typedef C++ 11
// a pointer that returns a integer and receve 2 ints as paramethers:
using binaryop = int(*)(int, int);

int exec(binaryop func, int a, int b){
    // using pointer to dereference binaryop func, and get value!
    return (*func)(a, b);
}

int add(int a, int b){
    return a + b;
}

int main() {
    
    cout << exec(add, 10, 20) << endl;

    return 0;
}