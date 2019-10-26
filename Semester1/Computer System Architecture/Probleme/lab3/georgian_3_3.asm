;Badita Marin-Georgian, grupa 211, 10/17/2017, problema 6 inmultiri-impartiri
;x+a/b+c*d-b/c+e
;a,b,d-byte; c-word; e-doubleword; x-qword

bits 32


global start        


extern exit      
import exit msvcrt.dll        
segment data use32 class=data
    ; ...
    a db 4
    b db 3
    d db 1
    c dw -2
    e dd 4
    x dq 2
    rez dq 0
; our code starts here
segment code use32 class=code
    start:
    
    ;x+a/b+c*d-b/c+e = 6
    mov AL, [a] ;AL = a
    cbw ;Convertesc AL la AX
    mov BL, [b] ;BL = b
    
    idiv BL ;AL = AX / BL = a/b
    
    mov BL, AL ;BL = a/b
    
    mov AL, [d] ;AL = d
    cbw ;Convertesc AL la AX
    imul WORD [c] ;DX:AX = c*d
    
    push DX ;DX pe stiva
    push AX ;AX pe stiva
    pop ECX ;ECX = c*d
    
    mov AL, BL ;AL = a/b
    cbw ;Convertesc AL la AX
    cwd ;Convertesc AX la DX:AX
    
    push DX ;DX pe stiva
    push AX ;AX pe stiva
    pop EAX ;EAX = a/b
    
    add EAX, ECX ;EAX = a/b + c*d
    add EAX, [e] ;EAX = a/b + c*d + e
    
    mov ECX, EAX ;EDX = a/b + c*d + e
    mov AL, [b] ;AL = b
    cbw ;Convertesc AL la AX
    cwd ;Convertesc AX la DX:AX
    
    mov BX, [c] ;BX = c
    idiv BX ;AX = b/c
    
    cwd ;Convertesc AX la DX:AX
    push DX ;DX pe stiva
    push AX ;AX pe stiva
    pop EAX; EAX = DX:AX = b/c
    
    sub ECX, EAX; EDX = a/b + c*d + e - b/c = a/b + c*d - b/c + e
    
    mov EAX, ECX ;EAX = a/b + c*d - b/c + e
    
    cdq ;convertesc EAX la EDX:EAX
    
    add EAX, DWORD [x] ;Adun la EAX wordul care incepe la x
    adc EDX, DWORD [x + 4]; Adun la EDX wordul de la x  +4 + CF
    
    mov [rez], EAX
    mov [rez +4], EDX ;rez = EDX:EAX
    
        push    dword 0      
        call    [exit]      
