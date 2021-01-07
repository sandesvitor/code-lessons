#include <iostream>

extern "C" int GetValueFromGAS();
extern "C" int GetValueFromNASM();

int main(){
   
     std::cout << "GAS said "
        << GetValueFromGAS()
    << std::endl;
    
    std::cout << "NASM said "
        << GetValueFromNASM()
    << std::endl;
 
    return 0;
}
