bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    b dd 0xAB
    a times 3 dw 10
    test_ db -1
; our code starts here
segment code use32 class=code
    start:
       
        
        push    dword 0      
        call    [exit]      