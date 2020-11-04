#include <iostream>
using namespace std;

class Object
{
};

int main() {
    cout << "Copy VS Reference" << endl;
    
    // Copy Attribution:
    int a = 2;
    int b = a;
    int c;

    // memory addresses (pointers)
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl; 
    
    return 0;
}