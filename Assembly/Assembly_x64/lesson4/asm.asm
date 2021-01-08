;   INTEL                  AT&T

global AddInts      ; .global AddInts
global MulBy17      ; .global MulBy17   
global Sub5x        ; .global Sub5x

section .text       ; .section .text

AddInts:             ; AddInts:
    mov eax, edi    ;   movl %edi, %eax
    add eax, esi    ;   movl %esi, %eax
    add eax, ecx    ;   movl %ecx, %eax
    add eax, edx    ;   movl %edx, %eax
    ret             ;   ret

MulBy17:            ; MulBy17:
    imul edi, 17    ;   imull $17, %edi
    mov eax, edi    ;   movl %edi, %eax
    ret             ;   ret

Sub5x:              ; Sub5x:
    imul esi, 5     ;   imull $5, %esi
    sub edi, esi    ;   subl %esi, %edi
    mov eax, edi    ;   movl %edi, %eax
    ret             ;   ret
