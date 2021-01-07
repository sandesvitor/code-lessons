#include <iostream>


int GetValueFromASMInlineAssembler() {
    asm("movl $254, %eax"); 
    // AT&T Syntax != from Intel Syntax
}

extern "C" int GetValueFromASM();

int main(int argc, char* argv[]){   
    
    std::cout << 
        "Inline ASM AT&T syntax said " 
        << GetValueFromASMInlineAssembler() 
    << std::endl;
    
    std::cout <<
        "NASM ASM Intel Syntax says "
        << GetValueFromASM()
    << std::endl;
    
    return 0;
}
