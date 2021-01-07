#include <iostream>

extern "C" int GetValueFromGAS();

int main(){
   
     std::cout << "GAS said "
        << GetValueFromGAS()
    << std::endl;
 
    return 0;
}
