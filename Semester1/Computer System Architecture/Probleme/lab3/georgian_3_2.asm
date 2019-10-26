;Badita Marin-Georgian, grupa 211, 10/17/2017, problema 6 adunari-scaderi set2
;c-(d+a)+(b+c)
;a, b, c, d quadWords

bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    a dq 10
    b dq -5
    c dq 3
    d dq 7
; our code starts here
segment code use32 class=code
    start:
    ;c-(d+a)+(b+c) = 3 - 16 - 2 = -16
    mov EAX, DWORD [c] ;pun in EAX dwordul de la adresa c
    mov EDX, DWORD [c + 4];pun in EDX, dwordul de la adresa c +4
    
    sub EAX, DWORD [d]
    sbb EDX, DWORD [d + 4]; EDX:EAX = c - d - CF
    
    sub EAX, DWORD [a] 
    sbb EDX, DWORD [a + 4] ;EDX:EAX = c - (d + a) - CF
    
    add EAX, DWORD [b]
    adc EDX, DWORD [b + 4] ;EDX:EAX = c - (d + a) + b + CF
    
    add EAX, DWORD [c]
    adc EDX, DWORD [c + 4] ;EDX:EAX = c - (d + a) + (b + c) + CF
    
    
        push    dword 0      
        call    [exit]      
