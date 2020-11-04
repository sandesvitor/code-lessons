#include <iostream>
using namespace std;

int main() {

    int values1[5];
    int values2[] = {31, 44, 58, 91, 25, 100};

    cout << "Number of bytes in array = " << sizeof values2 << endl;

    int length = sizeof values2 / sizeof values2[0];

    for (int i = 0; i < length; i++){
        cout << values2[i] << endl;
    }

    return 0;
}