#include <iostream>


int main(int argc, char* argv[]) {
    int* a;
    *a = 1000;
    std::cout << *a << " - " << *&a << std::endl;
   
    return 0;
}
