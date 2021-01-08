# Calling Convention
---

C++ uses a calling convention. In our C++ file, we mark our functions as "C", wich means we want the compiler to pass variables using the "C" calling convention.

The "C" calling convention is a complicated beast and it's different on different O.S., so we'll only look at some basics to get up and coding in ASM without worrying about the details too much.

## Passing Integer Values:

In x64, the first 6 integer variables are passed in registers, this include **bool**, **char**, **enum** and just about anything that is inherently stored as an integer.

|   Parameter | Register    |
| ----------- | ----------- |
| 1           | RDI         |
| 2           | RSI         |
| 3           | RDI         |
| 4           | RCX         |
| 5           | R8*         |
| 6           | R9*         |
| >6          | Stack       |

\* **R8** and **R9** are two extra registers we get using the GNU COMPILER COLLECTION (gcc) before we need to enter the Stack Memory.


Example os a function prototype:
```cpp
void SomeFunction(int a, char b, unsigned long q);
```

The **first parameter** is a 32 bit "int", so it will be passed in **EDI**!

The **second parameter** is "char", they're 8 bit integers so this will be passed in SIL, the byte version of **RSI**!

The **third parameter** is a 64 bit "unsigned integer", so it will be passed in **RDX**!

## Returning Integer Values:

Integer values are returned to C++ in **RAX**. This is why in the first turorial we used the "mov" instruction to set value of **RAX** and returned an integer to C++.

|  C++ Data Type | Version of RAX |
| -------------- | -------------- |
| char/bool      | AL             |
| short          | AX             |
| int            | EAX            |
| long           | RAX            |

\* Remember that register **AL** is the "low" byte of **AX**, that itself is the "low" 16 bits of **EAX** (in the same direction, **EAX** is the low 32bit of **RAX**)

## Instructions:

|  Name             | Intel Syntax       | AT&T Syntax        |
| ----------------- | ------------------ | ------------------ |
| Move              | MOV [dest], [src]  | MOVx [src], [dest] |
| Add               | ADD [dest], [src]  | ADDx [src], [dest] |
| Subtract          | SUB [dest], [src]  | SUBx [src], [dest] |
| Increment         | INC [dest]         | INCx [dest]        |
| Decrement         | DEC [dest]         | DECx [dest]        |
| Negate            | NEG [dest]         | NEGx [dest]        |
| Signed Multiply   | IMUL [dest]        | IMULx [src], [dest]|
| Return            | RET                | RET                |

* Negate makes a negative number positive and *vice versa*;
* Signed multiply multiplies two signed numbers and stores the product;
* Return returns from a sub function.

\* The "x" in the AT&T syntax is the suffixes:

b=Byte                        eg. **AL**

w=Word                        eg. **AX**

l=Long (32 bit dword)         eg. **EAX**

q=qword                       eg. **RAX**

---

## Challange!

1. Write a function called AddInts(a, b, c, d) that add fous integers passed ffrom C++ and returns the sum;
2. Write a function called MulBy17(a) that multiplies a signed integer by 17;
3. Write a function called Sub5x(a,b) that subtracts 5x the integer b from the integer a.