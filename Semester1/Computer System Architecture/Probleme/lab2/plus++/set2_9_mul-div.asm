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
    a db 5
    b db 9
    c db 7
    d db 3
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov AH, [a]; AH = a
        mov AL, [b]; AL = b
        
        sub AL, [c]; AL = b - c
        add AH, AL; a +( b - c )
        
        mov AL, AH; AL = AH
        mov DH, 3; DH = 3
        mul DH; AX = AL*DH = AL * 3 = (a +(b-c))*3
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
