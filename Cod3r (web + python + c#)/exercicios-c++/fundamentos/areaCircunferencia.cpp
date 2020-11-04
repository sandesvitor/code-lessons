#include <iostream>
using namespace std;

int main(){
    const double PI = 3.1415;
    double radius;

    cout << "Inser radius: " << endl;
    cin >> radius;

    double area = PI * radius * radius;
    cout << "Area = " << area << endl;
    return 0;
}