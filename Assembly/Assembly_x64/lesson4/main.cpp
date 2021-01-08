#include <iostream>

extern "C" int AddInts(int a, int b, int c, int d);
extern "C" int MulBy17(int a);
extern "C" int Sub5x(int a, int b);


int main(){

    int a, b, c, d;

    std::cout << "Give us a number: ";
    std::cin >> a;
    
    std::cout << "2nd number: ";
    std::cin >> b;

    std::cout << "3rd number: ";
    std::cin >> c;

    std::cout << "4th number: ";
    std::cin >> d;

    std::cout << "Challange 1 = "
        << AddInts(a, b, c, d)
    << std::endl;
    std::cout << "Challange 2 = "
        << MulBy17(a)
    << std::endl;
    std::cout << "Challange 3 = "
        << Sub5x(a, b)
    << std::endl;
    return 0;
}