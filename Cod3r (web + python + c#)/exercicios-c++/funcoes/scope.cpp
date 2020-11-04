#include <iostream>
using namespace std;

int globalVar = 1;

void func3(){
    int globalVar = 1000;
    cout << "exec..." << endl;
}

void func2(){
    func3();
}

void func1(){
    globalVar++;
    func2();
}

int main() {
    func1();

    cout << globalVar << endl;

    {
        int a = 3;
        cout << a << endl;
    }

    // cout << a << endl;
    return 0;
}

// C++ has BLOCK SCOPE FOR VARIABLES!

/*
#### stack #####
---- func3() ---
---- func2() ---   
---- func1() ---
---- main() ----
#### stack #####

*/