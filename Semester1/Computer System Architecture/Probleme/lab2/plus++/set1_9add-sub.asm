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
    b db 7
    c db 20
    d db 13

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov AL, [d] ; AL = d
        add AL, [d] ; AL = AL + d = d + d
        sub AL, [b] ; AL = AL - b = (d + d - b)
        
        mov AH, [c] ; AH = c
        sub AH, [a] ; AH = c - a
        
        ADD AH, AL ;AH = AH + AL = (d + d - b) + (c - a)
        ADD AH, [d];AH = AH + d = (d + d - b) + (c - a) + d
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
