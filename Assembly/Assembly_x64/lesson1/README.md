# INTRODUCTION TO MODERN ASSEMBLY x64 
---
**PROS**:

- Teaches us how the hardware works (CPU=ASM);
- Write drivers, operating systems, kernels, compilers, embedded devices;
- Optimise programs for speed or size.


**CONS**:

- Difficult to debbug and maintain;
- It does not offer any abilities taht hight-level languages do not 
  alread offer.

An Assembly is a program that translate ASM code into machine code so the 
CPU can execute it (instead of 'compiling' it's supposed to 'assembling')

In this first example, we will use AT&T syntax to showcase inline assembly code,
whereas the Intel syntax will be use by an external code, and linked with the 
main.cpp file after compilation.

---
*main.cpp*
```c++
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
```
---
asm.asm
```Assembly
global GetValueFromASM

segment .data

segment .text
GetValueFromASM:
    mov rax, 100
    imul rax, rax, 30
    ret
```

---
**LINKING NASM ASSEMBLY TO GNU C COMPILER**:
- Link object file with .cpp file on gcc or g++;
- Make an object file with nasm compiler using elf64 f flag;

*Makefile example:*
```Makefile
runme: main.cpp asm.o
    g++ main.cpp asm.o -o runme -Wall

asm.o: asm.asm
    nasm -f elf64 asm.asm -o asm.o
```
---
**RESULTS**:
```zsh
└─[$] ./runme                                                               
Inline ASM AT&T syntax said 254
NASM ASM Intel Syntax says 3000
```