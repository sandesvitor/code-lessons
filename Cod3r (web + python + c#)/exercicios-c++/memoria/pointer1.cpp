#include <iostream>
using namespace std;

int main() {
    /*
        What is a pointer?
        -------------------------------------
        Pointer is a variable whose value is
        the address of another variable, i.e.,
        direct address of the momory location.
    */

    int value = 98765;
    int& ref = value;
    int *pointer = &value;

    cout << value << '\t' << ref << '\t' << pointer << endl;

    // to accesss the value of wich the pointer is pointing:
    cout << *pointer << endl;

    return 0;
}