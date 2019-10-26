bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 10
    b db 31
    c db 15
    d dw 24

; our code starts here
segment code use32 class=code
    start:
        ; ...  
        ;[-1+d-2*(b+1)]/a
        mov AL, [b] ;AL = b
        add AL, 1 ;AL = b + 1
        
        mov AH, 2 ; AH = 2
        mul AH ;AX = AH * AL = 2*(b + 1)
        
        mov DX, [d] ;DX = d
        sub DX, AX ;DX = d - 2*(b + 1)
        sub DX, 1 ;DX = -1 + d - 2*(b + 1)
        
        mov AX, DX; AX = DX
        mov CL, [a]; CL = add
        
        idiv CL; AL = AX / CL, AH = AX % CL
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
