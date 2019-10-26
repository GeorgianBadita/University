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
    a db 49
    b db 21
    c db 31
    d dw 67
; our code starts here
segment code use32 class=code
    start:
        ;expresia d*(d+2*a)/(b*c)
        ; ...
        mov AL, [a] ;AL = a
        mov AH, 2 ;AH = a
        mul AH ;AX = AL * AH = 2*a
        add AX, [d] ;AX = AX + d = 2*a + d
        
        mov DX, [d] ;DX = d
        mul DX ;DX:AX = DX*AX = d*(d + 2*a)
        
        mov [d], AX; d = AX
        mov AL, [b]; AL = b
        mov AH, [c]; AH = c
        mul AH; AX = AL*AH
        
        mov SI, AX  ;SI = AX
        mov AX, [d] ;AX = d
        
        div SI ;AX = DX:AX/SI, DX = DX:AX % SI
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
