#include <iostream>
using namespace std;

int main() {
    int arr[] = {47, 33, 72, 13, 88};
    
    
    // aritimética de ponteiros!
    // Percorrendo os encereços de memória pelos ponteiros:
    int* p1 = &arr[0];
    cout << p1 << endl;
    cout << *p1 << endl;

    p1++;
    cout << p1 << endl;
    cout << *p1 << endl;
    
    p1++;
    cout << p1 << endl;
    cout << *p1;
    
    p1++;
    cout << p1 << endl;
    cout << *p1 << endl;

    cout << "....." << endl;
    cout << p1[0] << endl; // [0] same as *

    return 0;
}