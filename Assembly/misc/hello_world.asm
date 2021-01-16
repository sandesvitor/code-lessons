; PATH OF C HEADER CONTAINING ALL SYSCALLS! 
; /usr/include/x86_64-linux-gnu/asm/unistd_32.h 

; $ man 2 write

; #include <unistd.h>
; ssize_t write(int fd, const void *buf, size_t count);


global _start:


section .data
    message: db "Hello World!", 0xA     ; "0xA" represents "\n" == "10"
    message_length equ $-message        ; NASM will compile that to the length


section .text

_start:
    mov eax, 0x4            ; use the "write" syscall
    mov ecx, 1              ; use stdout as fd (file descriptor)
    mov ecx, message        ; use the message as the buffer
    mov edx, message_length ; and suplly the length   
    int 0x80                ; invoke the syscall

    mov eax, 0x1            ; use the "exit" syscall
    mov ebx, 0              ; it needs a return value (0 means success)
    int 0x80




 
