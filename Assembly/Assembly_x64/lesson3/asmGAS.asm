.section .text

.global GetValueFromGAS

GetValueFromGAS:
    movq $15, %rax
    addq $100, %rax
    subq $1, %rax
    ret
