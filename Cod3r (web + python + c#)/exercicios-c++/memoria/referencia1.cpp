#include <iostream>
using namespace std;

int main() {
    int a = 10;
    cout << a << "\t" << &a << endl;

    string name = "Paul";
    cout << name << "\t" << &name << endl;

    // variable for representing the referency
    int x = 7;
    int& xRef = x;

    /*
        Why not  "int& xRef = &x;"?
        -------------------------------------
        At compile time all instances of xRef
        are replaced with the address of 'x'
    */

    cout << x << '\t' << &x << endl;
    cout << xRef << '\t' << &xRef << endl;

    x++;

    cout << xRef << '\t' << x << endl;

    xRef--;

    cout << xRef << '\t' << x << endl;


    return 0;
}