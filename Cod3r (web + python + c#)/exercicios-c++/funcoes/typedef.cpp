#include <iostream>
using namespace std;

typedef int id;
using counter = long;

int main() {
    id a = 5;
    id b = 10;
    counter c = 1000;

    cout << a + b << endl;
    cout << typeid(a).name() << endl;
    cout << typeid(c).name() << endl;

    return 0;
}