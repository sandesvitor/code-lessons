#include <iostream>
using namespace std;

// Lambda Function = Anonimous Function!

auto add = [](int x, int y) -> int { return x + y; };
auto subtract = [](int x, int y) { return x - y; };

using binaryop = int(*)(int, int);

int exec(binaryop func, int a, int b){
    // using pointer to dereference binaryop func, and get value!
    return (*func)(a, b);
}


int main() {
    cout << add(1,2) << endl;
    cout << subtract(6,2) << endl;

    cout << exec([](int x, int y){ return x * y; }, 10, 70) << endl;
    return 0;
}