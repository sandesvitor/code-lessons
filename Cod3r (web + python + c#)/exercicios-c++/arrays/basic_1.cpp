#include <iostream>


int main() {
    std::string names[5];
    names[0] = "Hanna";
    names[1] = "Peter";
    names[2] = "Mary";
    names[3] = "Mike";
    names[4] = "James";

    // o c++ vai acessar esse espaço de memória:
    // CUIDADO!
    // std::cout << names[5] << std::endl;


    return 0;
}