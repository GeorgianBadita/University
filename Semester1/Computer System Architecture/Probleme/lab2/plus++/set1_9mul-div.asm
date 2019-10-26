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
    a db 1
    b db 2
    c db 3
    d dw 4
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov AL, [b] ;AL = b
        sub AL, [a] ;AL = b - a
        add AL, 2 ; AL = b - a + 2
        
        mov DH, 20 ;DH = 20
        mul DH; AX = AL * DH = (b - a + 2)*20
        mov DX, AX ;DX = AX
        
        mov DH, 10 ;DH = 10
        mov AL, [c] ; AL = c
        mul DH; AX = 10*c
        
        sub DX, AX ; DX = DX - AX
        
        mov AL, [d]; AL = d
        sub AL, 3 ; AL = d - 3
       
        mov DH, 2 ; DH = 2
        mul DH ; DH = 2*(d-3)
        
        add DX, AX; DX = DX + AX = 3*[20*(b-a+2)-10*c]+2*(d-3) a = 1 b = 2 c = 3 d = 4
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
