#include <iostream>
using namespace std;

int main(){

    // "::" scope resolution operator
    std::cout << "Good mornung!" << std::endl;

    // when using std namespace, we don't need the 
    // scope resolution operator

    cout << "Without the '::'" << endl;
    return 0;
}