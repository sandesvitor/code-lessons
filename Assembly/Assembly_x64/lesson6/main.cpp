#include <iostream>

extern "C" unsigned char ReverseBits(unsigned char c);

void PrintByte(unsigned char c){
   for(int i = 7; i >= 0; i--){
       std::cout << ( (c>>i) & 1); 
   } 
       std::cout << std::endl;
}

int main(){
    unsigned char byte = 128;
    unsigned char reverse_byte = ReverseBits(byte);
    PrintByte(byte);
    PrintByte(reverse_byte);
    

    return 0;
}