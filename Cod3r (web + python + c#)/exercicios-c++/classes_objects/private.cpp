#include <iostream>

const double MINIMUM_WAGE = 1500;

class Employee
{
    public:
        std::string name;
    
    private:
        double wage;

    public:
        double getWage(){
            return wage > MINIMUM_WAGE ? wage : MINIMUM_WAGE;
        }

        void setWage(double w){
            if(w >= MINIMUM_WAGE) wage = w;
        }
};

int main() {

    Employee emp1;
    emp1.name = "Paul Smith";
    emp1.setWage(300);
    
    std::cout << emp1.name << " US$" << emp1.getWage() << std::endl;
    return 0;
}