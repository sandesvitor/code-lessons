#include <iostream>
#include <sstream>

class Date
{
public:
    int day;
    int month;
    int year;

    std::string toString(){
        std::stringstream ss;
        ss << day << "/" << month << "/" << year;
        return ss.str();
    }
};

int main() {
    Date d1;
    d1.day = 3;
    d1.month = 11;
    d1.year = 2023;
    std::cout << d1.toString() << std::endl;

    Date d2;
    d2.day = 31;
    d2.month = 1;
    d2.year = 2020;
    std::cout << d2.toString() << std::endl;

    std::cout << &d1 << std::endl;
    std::cout << &d2 << std::endl;

    return 0;
}