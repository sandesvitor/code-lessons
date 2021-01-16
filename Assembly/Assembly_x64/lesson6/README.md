# Shifting
---
We can shift the bits left or right in our binary numbers. Shifting the bits of a binary number left is the same as multiplying it by powers of 2, and shifting the bits right is the same as dividing by powers of 2!

## **Shifting is Fast**:
Shifting is very fast for the CPU, multiplying is fairly fast, but not as fast as shifting. Division is extremely slow, one of the slowest instructions on the CPU!

You mights alread be used to multiplying and dividing by shifting in C++ using the << and >> operators. C++ knows if a data type is signed and will pick the correct >>.

Division with a shift and a negative number does not always give exactly the same answer, shifting truncates toward -infinity, division truncates towards 0.

## **The Instructions**:

```Assembly
SHL [op1], [op2]    ; Shift Left
SHR [op1], [op2]    ; Shift Right
SAR [op1], [op2]    ; Shift Arithmetic Right
```

Each instruction takes two operands. The first operand can be memory or a register, and the second can be either an 8 bit immediate value or the **CL** register. The bits in [op1] are shifted left or right by the amount specified in the [op2]. The results are saved to [op1]. The **Carry Flag** contains the last bit shifted out on the left or right.

The difference between SHR and SAR is that with SHR, 0's enter from the left hand side, and with SAR, the sign bit is copied. SAR is used for division of signed, negative numbers!

If[op2] is an immediative value and it happens to be 1, then a special version of the instructio is often used which affects the **Overflow Flag** as well as the carry!

## **Masking Bits**:
Shifting in conjunction with AND can be used to mask a particular bit/s, for instance, if we want to read bits 5, 6, 7 and 8 (using zero based counting) from EAX, but we don't want to read the others:

```Assembly
SHR EAX, 5
AND EAX, 0xF    ; 0xF == 1111
```

The instructions above shifts the bits of **EAX** right by 5, then masks out all but the first 4 bits with AND. **EAX** would then be an integer of only the required bits.

## **Examples**:
```Assembly
; Intel Syntax

SHL EAX, 5  ; <- Multiply EAX by 2⁵
SHR RDX, CL ; <- Unsigned Divide RDX by 2^cl
SAR EAX, 3  ; <- Signed divide EAX by 2³
SAR BL, 8   ; <- Paste BL's sign bit across all bits


; AT&T Syntax

SHLL $5, %EAX
SHRQ %CL, %RDX
SAR $3, %EAX    ; If there's no memory operands GAS can also infer data sizes
SAR $8, %BL
```

## **Challenge**:
Make a function in Assembly called ReverseBits, which takes a byte as a parameter and returns the exact mirror or reverse of its bits. So *01101011* should return *11010110*.

The prototype should be:
```cpp
unsigned char ReverseBits(unsigned char c);
```

You can use any technique you like, I will use shifting and the Boolean instructions since that's what we've been talking about. We haven't looked at loops and labels yet, but if you happen to know about those, you can use a loop.
