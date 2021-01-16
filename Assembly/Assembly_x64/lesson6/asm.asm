global ReverseBits

segment .text

; Reapeat 7 times
; Copy first bit on the right from input to output
; Shift input to the right one
; Shift output to the left one

; Copy the final bit

; al ReverseBits(unsigned char dil)
ReverseBits:
    xor rax, rax    ; clearing rax

    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left
    
    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left
    
    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left

    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left

    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left

    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left

    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al
    shr dil, 1      ; Shift DIL to next bit
    shl al, 1       ; Shift AL to the left

    mov cl, dil     ; Copy DIL to cl
    and cl, 1       ; Mask all the bits in CL except for the first bit
    or al, cl       ; Copy it to al


    ret