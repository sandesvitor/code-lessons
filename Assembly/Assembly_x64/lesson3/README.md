# DATA SIZES
---

### **Bit**: 
Short for binary digit. can be a 0 or a 1. The value of a single
bit can be represent anything with two states, be it On/Off, 0/1, 
True/False. Computers never use single bits, they always act on 
collections of bits.

### **Byte**: 
Eight bits together make a byte. There are 256 different combinations
of 1's and 0's we can make with a single byte. The byte is the smallest
entity computers usually deal with.

### **Word**:
Sixteen bits or two bytes go together to make a word.
These are called "short int" in some high level languages.

### **Dword/Long**:
Four bytes or 32 bits makes a dword (Intel Syntax) or Long Word(AT&T Syntax).
These are the same as "int" in high level languages.

### **Qword/quad**:
These are 64 bits wide, qword (Intel Syntax) is short for "quad-word"
since they are the same as 4 words together. Quad is used in AT&T Syntax.

---
## General Syntax:

Assembly is written as a sequence of instructions, each occupying
one line;

*Intel*:
```Assembly
mov al, 23
mov bl, 6
add al, bl
```

*AT&T*:
```Assembly
movb $23, %al
movb $6, %bl
addv %bl, %al
```

### Source and Destination Operands:
*Source* => Operand/s used to perform a calculation.

*Destination* => The operand/s to where the results are stored.

One of the most obvious differences between Intel and AT&T syntax
is that the source and destination operands swap places.

                mov eax, 100    movl $100, %eax

## Registers:

Registers are small memory spaces which reside on the CPU, they
are part of the CPU and they are probably the most important variables
in the whole computer!

The CPU reads data from RAM into its registers, performs calculations
with them and then writes the data back to RAM. The CPU cannot manipulate
data directly, it needs to copy the data to the registers.

Registers have no address (unlike RAM) and they have no data type
(or more properly, they are all data types at once!).

### **x86 Register Set**:
Register can be used in many different ways.
Firstly, let's look at some of them:

**AL** is an 8 bit register. It's a byte Long. It can be used for signed or unsigned arithmetic or working with single ASCII.

**AH** is another 8 bit register. THe two can be used completly independently but they can also be used together as **AX**!

**AX** is composed of **AL** and **AH**. **AH** is the "high" byte of it, and **AL** is the "low" byte, hence the "H" and "L". **AX** is a 16bit\* register, good for arithmetic on short integers:

\* *These were the only registers available on the early 16bit machines. When we speak about a 16bit, 32bit or 64bit CPU we are, in part, referring to the register size!*

Then there is the **32bit versions** of those registers, with a prefix "e", meaning "extra".

For instance **EAX** is the 32bit version of **AX**, and **AX** is the low 16 bits of **EAX**. Furthermore, there is no way to access the top 16bits of **EAX** like we could with **AX** using **AH**, but the low part can be accessed it.

Finnaly, the **64bit version** of **EAX** is called **RAX**, and its lowest 32bit part is the **EAX** register (again, in this case, we cannot access the top 32bit of **RAX**).

In conclusion, in an x64 CPU there are a total of 16 registers, with basically the same abilities as RAX. Each can be accessed as a 64bit, 32bit, 16bit or as a byte (8bit). 
Collectivly they are called **GENERAL PURPOSE REGISTERS** (or **GPR**). Many of them have specific roles wich they usually do but at any point, a programmer is able to use any of the GPR for general arithmetic.

64 Bits | Low 32 Bits | Low 16 Bits | Low 8 Bits | Notes |
--- | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |---
RAX | EAX | AX | AH/AL | Accumulator |
RBX | EBX | BX | BH/BL | Base |
RCX | ECX | CX | CH/CL | Counter |
RDX | EDX | DX | DH/DL | Data |
RSP | ESX | SP | SPL | Stack Pointer |
RBP | EBX | BP | BPL | Base Pointer |
RSI | ESI | SI | SIL | Source Index |
RDI | EDI | DI | DIL | Destination Index |
R7 | R7D | R7W | R7B | Only on 64bit |
R8 | R8D | R8W | R8B | Only on 64bit |
R9 | R9D | R9W | R9B | Only on 64bit |
R10 | R10D | R10W | R10B | Only on 64bit |
R11 | R11D | R11W | R11B | Only on 64bit |
R12 | R12D | R12W | R12B | Only on 64bit |
R13 | R13D | R13W | R13B | Only on 64bit |
R14 | R14D | R14W | R14B | Only on 64bit |
R15 | R15D | R15W | R15B | Only on 64bit |

---

### **Special Registers**:
1. **RIP**
The *instruction pointer*, points to the memory addres in RAM where the instructions are being read from.

2. **RFLAGS**
The *flags register*, maintains flags so we can check the conditions from recent instructions.

3. **S[]**
The x86 *floating point unit* uses its own register set. The x87 is largely legacy nowadays.

4. **SIMD**
There's many different SIMD register sets wich might be available depending on your CPU.

5. **Machine Specific, Debbuging, etc...**
There are any number of CPU registers for debugging, counting clock ticks and measuring performance of branching etc. Each CPU has its own collection.

---

### **Basic Instructions**:
Mneumonic | Meaning | Intel | AT&T |
--- | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |---
MOV | Move/Copy data | mov eax, 24 | movl $24, %eax |
ADD | Addition | add rcx, 16 | addq $16, %rcx |
SUB | Subtraction | sub di, es | subw %es, %di |
INC | Increment | inc rcx | inc %rcx |
DEC | Decrement | dec bh | dec %bh |