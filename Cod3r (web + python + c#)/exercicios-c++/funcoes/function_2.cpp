#include <iostream>
#include "function_2.h"
using namespace std;

int main() {

    log(1, 1);
    log(1, false);
    log(2, 0);
    log(6, true);

    return 0;
}

void log(int number, bool newLine){
    cout << "Number: " << number;
    newLine ? cout << endl : cout << " ";
}