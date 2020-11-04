#include <iostream>
using namespace std;

int main(){
    // type inference
    int a = 1;
    double b = 1.2;
    bool c = false;
    
    auto d = 1;
    auto e = 1.2;
    auto f = false;

    cout << typeid(a).name() << endl
        << typeid(b).name() << endl
        << typeid(c).name() << endl;

    cout << typeid(d).name() << endl
        << typeid(e).name() << endl
        << typeid(f).name() << endl;

    return 0;
}