#include <iostream>


int main() {
    std::string abc = "abcdefghijklmnopqrstuvxz";

    abc[9] = '?';

    for(char l : abc)
        std::cout << l << ", ";

    return 0;
}