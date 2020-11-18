#include <iostream>


int main() {
    std::string names[] = { "Hanna", "Peter", "Mary", "Mike", "James" };
    names[1] = "John";

    // int length = sizeof(names)/sizeof(names[0]);
    // for(int i = 0; i < length; i++)
    //     std::cout << names[i] << std::endl;
    
    for(std::string name : names)
        std::cout << name << std::endl;

    return 0;
}