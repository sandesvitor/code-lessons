#include <iostream>


class Date
{
public:
    int day;
    int month;
    int year;

    // default constructor:
    Date(){
        day = 1;
        month = 1;
        year = 1970;
    }
};

int main() {

    Date d1;

    std::cout << d1.day << "/" << d1.month << "/" << d1.year << std::endl;
    return 0;
}