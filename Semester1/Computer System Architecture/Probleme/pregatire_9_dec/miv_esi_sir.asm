bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    a db 5
    b db 6
    sir dd 1, 2, 3, 4
    ex dw 1234h, 5678h
; our code starts here
segment code use32 class=code
    start:
        mov ESI, sir
        push    dword 0      
        call    [exit]      
