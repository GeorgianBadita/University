
;a*b-(100-c)/(b*b)+e+x
;a-word; b,c-byte; e-doubleword; x-qword
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
    a dw 1
    b db -2
    c db 90
    e dd 1
    x dq 2
    rez dq 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
    mov AL, 100 ;AL = 100
    sub AL, [c] ; AL = 100 - c
    
    mov Bl, AL; AL = Bl
    mov AL, [b]; AL = b
    imul BYTE [b]; AX = AL * b = b * b
    mov CX, AX; CX = AX = b*b
    
    mov AL, BL ;AL, BL
    cbw ;AX 100 - c
    cwd ;DX:AX = 100 - c
    idiv CX ;AX = (100-c)/b*b; DX = (100-c)%b*b
    
    mov CX, AX; CX = AX
    
    mov AL, [b]; AL = b
    cbw
    imul WORD [a] ; DX:AX a*b
    
    push DX
    push AX
    pop EBX ; EBX = a*b
    
    mov AX, CX;  AX = CX
    cwd ;DX:AX (100-c)/b*b
    
    push DX
    push AX
    pop EAX
    sub EBX, EAX ;a*b - (100 -c)/b*b
    add EBX, DWORD [e];EBX = EBX + e
    mov EAX, EBX ;EAX = EBX
    cdq 
    add EAX, DWORD [x]
    adc EDX, DWORD[x + 4] ;EDX:EAX = a*b-(100-c)/(b*b)+e+x
    
    mov [rez], EAX; rez = EAX
    mov [rez + 4], EDX; rez = EAX:EDX
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
