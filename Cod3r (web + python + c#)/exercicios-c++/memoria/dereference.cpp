#include <iostream>
using namespace std;

int main() {
    double pi = 3.14;
    double& piRef = pi;

    cout << piRef << endl;
    cout << &pi << endl;

    // * -> dereference operator:
    // Think of as 'Get Value at Reference...'
    cout << *&pi << endl;
    cout << *&piRef << endl;
    
    // * is used to create a pointer!
    
    return 0;
}