;(a*2+b/2+e)/(c-d)+x/a
;a-word; b,c,d-byte; e-doubleword; x-qword

bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    a dw 10
    b db 5
    c db 1
    d db 3
    e dd 12
    x dq 5
; our code starts here
segment code use32 class=code
    start:
    mov AX, [a] ;AX = a
    mov BX, 2 ;BX = 2
    
    imul BX ;DX:AX = BX*AX = 2*a
    
    push DX ;DX pe stiva
    push AX ;AX pe stiva
    pop EBX ;EBX = DX:AX
    
    mov AL, [b] ;AL = b
    cbw ;AL = AX
    mov CX, 2; CX = 2
    idiv CX; AL = AX / C = b/2
    cbw ;AL = AX 
    cwd ;AX = DX:AX
    
    push DX ;DX pe stiva 
    push AX ;AX pe stiva
    pop EAX ;EAX = DX:AX
    
    add EAX, EBX ;EAX = EAX + EBX
    adc EAX, [e] ;EAX = a*2 + b/2 + e
    
    mov EDX, EAX ;EDX = EAX
    
    mov AL, [c] ;AL = c
    sub AL, [d] ;AL = c - d
    cbw ;convert AL la AX
    cwd ;convert AX to DX:AX
    
    push DX ;
    push AX ;
    pop ECX ; ECX = c - d
    
        push    dword 0      
        call    [exit]      
