#include <iostream>
using namespace std;

void func1(){
    int x = 3;
}

int add(int x, int y){
    return x + y;
}

int add(int x, int y, int z){
    return x + y + z;
}

double add(double x, int y){
    return x + y + 1000;
}

double add(int x, double y){
    return x + y + 2000;
}

int main() {
    int x = 10;
    {
        int x = 1002020020;
    }
    cout << x << endl;

    cout << add(10, 20) << endl;
    cout << add(10, 20, 30) << endl;
    cout << add(10.0, 30) << endl;
    cout << add(10, 30.0) << endl;

    return 0;
}