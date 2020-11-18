#include <iostream>

// acessar por ReferÊncia é BEM MAIS RÁPIDO do que criar uma cópia!

int main() {
    std::string names[] = { "Hanna", "Peter", "Mary", "Mike", "James" };
    names[1] = "John";


    std::cout << "Foreach #01 (Copy)...\n";
    for(std::string name : names){
        name.append("!!!!!");
        std::cout << name << std::endl; 
    }
    std::cout << names[0] << std::endl;


    std::cout << "Foreach #02 (Reference)...\n";
    for(std::string &name : names){
        name.append("!!!!!!");
        std::cout << name << std::endl;
    }
    std::cout << names[0] << std::endl;

    return 0;
}