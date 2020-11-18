#include <iostream>

class Person
{
public:
    std::string name;
    Person(std::string name){
        this->name = name;
        std::cout << "Hello! My name is " << this->name << std::endl;
    }

    // destructor works inside each scope!
    // objects will be destroyed at the end of each scope!
    ~Person(){
        std::cout << name << " saying good bye!" << std::endl;
    }
};

void createPerson(std::string name){
    Person p(name);
}

int main() {
    Person p1("Peter");
    createPerson("John");

    {
        Person p2("John");
    }

    std::cout << "End of code!" << std::endl;

    return 0;
}