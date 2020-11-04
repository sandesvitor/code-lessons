#include <iostream>
using namespace std;

void incCopy(int value){
    value++;
}

void incRef(int& value){
    value++;
}

int main() {
    int x = 1;

    incCopy (x);
    cout << x << endl;
    
    incRef (x);
    cout << x << endl;

    cout << &x << "\t" << *&x << endl;

    return 0;
}