global Question1
global Question2
global Question3
global Question4

segment .text

Question1:
    mov eax, edi
    or eax, esi
    ret

Question2:
    mov eax, edi
    xor eax, esi
    ret

Question3:
    mov eax, edi
    xor eax, esi
    xor eax, esi
    ret

Question4:
    mov eax, edi
    not eax
    inc eax
    ret