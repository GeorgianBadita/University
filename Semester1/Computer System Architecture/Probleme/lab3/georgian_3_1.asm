;Badita Marin-Georgian, grupa 211, 10/17/2017, problema 6 adunari-scaderi set1
;(a+b)-(a+d)+(c-a)
;a,b,c,d - dword


bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    a dd 10
    b dd 5
    c dd 11
    d dd 2
; our code starts here
segment code use32 class=code
    start:
    mov EAX, [a] ;EAX = a
    adc EAX, [b] ;EAX = a + b + CF
    
    mov EDX, [a] ;EAX = a
    adc EDX, [d] ;EDX = a + d + CF
    
    sbb EAX, EDX; EAX = EAX - EDX = (a + b) - (a + d) - CF
    
    mov EDX, [c] ;EDX = c
    sbb EDX, [a] ;EDX = c - a - CF
    
    adc EAX, EDX ;EAX = (a + b) - (a + d) + (c - a) + CF
        push    dword 0      
        call    [exit]      
