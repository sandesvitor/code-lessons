#include <iostream>
using namespace std;

int main(){
    // any number != 0 is True; 0 == False;
    // cout ==> 1 || 0;
    cout << "BOOL TYPE:" << endl;
    bool isAdmin = 0;
    bool isAwake = false;
    bool isOn = 2000;
    bool isTrue = true;
    cout << isAdmin << endl;
    cout << isAwake << endl;
    cout << isOn << endl;
    cout << isTrue << endl << endl;

    // char MUST BE DEFINED wit SINGLE QUOTE ('');
    cout << "CHAR TYPE:" << endl;
    char symbol = '#';
    cout << symbol << endl << endl;

    cout << "INT TYPE:" << endl;
    short int age = 31;
    long int apiKey = 32331312314125674242352342425323582421;
    signed short int minusOne = -1;
    unsigned short int dayOfWeek = 7;
    cout << age << endl;
    cout << apiKey << endl;
    cout << minusOne << endl;
    cout << dayOfWeek << endl << endl;

    cout << "FLOAT TYPE:" << endl;
    float pi = 3.14; // 32 bits - single precision floating point type
    const double PI = 3.1415; // 64 bits - double " " " "
    cout << pi << endl;
    cout << PI << endl << endl;

    cout << "SIZE OF TYPES (in BYTES):" << endl;
    cout << "1 byte == 8 bits" << endl;
    cout << "char " << sizeof(char) << " byte" << endl;
    cout << "int " << sizeof(int) << " byte" << endl;
    cout << "long int " << sizeof(long int) << " byte" << endl;
    cout << "long long int " << sizeof(long long int) << " byte" << endl;
    cout << "float " << sizeof(float) << " byte" << endl;
    cout << "double " << sizeof(double) << " byte" << endl;

    return 0;
}