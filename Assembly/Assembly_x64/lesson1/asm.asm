global GetValueFromASM

segment .data

segment .text
GetValueFromASM:
    mov rax, 100
    imul rax, rax, 30
    ret
