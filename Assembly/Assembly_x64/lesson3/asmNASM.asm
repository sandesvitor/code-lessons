global GetValueFromNASM

segment .data

segment .text
GetValueFromNASM:
    mov rax, 100
    imul rax, rax, 30
    ret