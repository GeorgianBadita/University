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
    a dw 5
    b db 3
    c db 4
    d db 2
    e dd 6
    x dq 8
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(a*2+b/2+e)/(c-d)+x/a
        ;a*2 + b/2 + e = 17
        ;c - d = -2
        mov AL, [a] ;AL = a
        mov AH, 2 ;AH = 2
        mul AH ;AX = a*2
        
        mov DX, AX; DX = AX = 2*a
        
        mov AL, [b]; AL = b
        cbw ;converteste AL la AX -> trecere de la 8 la 16 biti
        
        mov CL, 2; CL = 2
        div CL; AL = AX/CL; AH = AX % CL
        
        add AX, DX ;DX = DX + AX
        
        cwd ;converteste AX la DX:AX
        
        push DX; DX pe stiva
        push AX; AX pe stiva
        ;mov EBX, 0
        pop EBX; EBX = DX:AX
        
        ;add EBX, [e]; EBX = EBX + e = (a*2 + b/2 + 3)
        ;(a*2+b/2+e)/(c-d)+x/a
        
        mov BX: [c]; BX = c
        sub BX, [d]; BX = c - d 
        mov BH, 0;
        ;cbw ; converteste AL la AX
        idiv BX; AX = DX:AX/BX
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
