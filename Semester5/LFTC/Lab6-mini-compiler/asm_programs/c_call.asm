global _start
extern printf

section .text
_start:

fld qword [anumber]
    sub esp, 8
    fstp qword [esp]
    push msg
    push fmt
    call printf
    add esp, 16

mov eax, 1
    xor ebx, ebx
    int 80h

;section .data
    fmt db "%s%f", 10, 0
    msg db "The answer is: ", 0
    anumber dq 42.0