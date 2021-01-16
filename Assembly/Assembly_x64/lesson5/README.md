# Boolean Instructions (Bitwise instructions)
---

\* "0" is generally considered False, and "1" (or any other number not "0") is True.

## Truth Table
Boolean instructions work with individual bits. A bit can be either 0 or 1. The Boolean instructions take one or two operands and return a single value, the output. When describing exactly what a particular Boolean instruction does, we often use a truth table.

### **AND** (Conjunction):
In ASM the instruction is: AND RAX, RDX

|  A  |  B  |  O  |
| --- | --- | --- |
|  0  |  0  |  0  |
|  0  |  1  |  0  |
|  1  |  0  |  0  |
|  1  |  1  |  1  |

### **OR** (Disjunction):
In ASM the instruction is: OR RAX, RDX

|  A  |  B  |  O  |
| --- | --- | --- |
|  0  |  0  |  0  |
|  0  |  1  |  1  |
|  1  |  0  |  1  |
|  1  |  1  |  1  |

### **NOT** (Bitwise Complement):
In ASM the instruction is: NOT RAX

\* It flips the bit. If the bit is 1, it becomes 0, and if it's 0 it becomes 1. If you NOT a value twice, you get back the original!

|  A  |  O  |  
| --- | --- | 
|  0  |  1  | 
|  1  |  0  |


### **XOR** (NOT equal to):
In ASM the instruction is: XOR RAX, RDX

\* This is not one of the original operands defined by the mathematician George Bool in the 1800's. XOR means "Either A or B but not both", it is slighly different to Boolean OR. If A does not equal B, then the result is true. And, you can XOR two parameters, then NOT the result to see wich bits are the same!

|  A  |  B  |  O  |
| --- | --- | --- |
|  0  |  0  |  0  |
|  0  |  1  |  1  |
|  1  |  0  |  1  |
|  1  |  1  |  0  |

## Bytes, Words, Dwors and Qwords
The CPU does not perform operations on single bits. It deals with 8 bits, 16 bits, 32 or 64 bits. Whey a Boolean instruction is performed between two operands, it is performed in parallel. FOr bytes, this means the instruction will be performed between all 8 bits. For 64 bit words, the instruction is performed 64 times in parallel:

The example bellow illustrate an AND operation between two bytes, occoring in parallel for every single bit:
|  1  |  0  |  0  |  1  |  1  |  0  |  1  |  1  |
| --- | --- | --- | --- | --- | --- | --- | --- |
|  &  |  &  |  &  |  &  |  &  |  &  |  &  |  &  |
|  1  |  0  |  0  |  0  |  1  |  1  |  0  |  0  |
|  =  |  =  |  =  |  =  |  =  |  =  |  =  |  =  |
|  1  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |

## That's good, but who cares?!
Since the CPU is just a gigantic collection of **transistors**, and the transistors make this boolean operations with **logical gates**!

What is surprising is taht all finite logical operations and mathematical statements can be modelling using only AND, OR, XOR and NOT (actually you don't even need that)!

For instance, when a computer ADDS two integers together, it doesn't use base 10 like humans (it doesn't even uses binary), ir uses Boolean operations. When you XOR two bits together, you get the result from adding the two bits, and when you AND two bits you get a carry, just like in base 10 only it's in binary!

A CPU can add two million-digit numbers in the blink of an eye, but what's actually doing is many more of these Boolean operations with electrical signals coming in and out of its pins. It can multiply, square root, play an FPS, a song or a movie.


## Coding:

For these we will make a C++ program that can print out the bits of a 32 integer. These functions will use ASM and it'll call them from the C++, printing out the results.

- Question 1:
OR 2783 with 1552 in ASM and print the bits.

- Question 2:
XOR 2783 with 1552 in ASM and print the bits.

- Question 3:
What happens if you XOR the results from the above with 1552 again?

- Question 4:
NOT 129 and increment your result with INC, what do you get?