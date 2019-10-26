bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    a dd 0a344dh, 30h, 11223344h, 46ab89ch

; our code starts here
segment code use32 class=code
    start:
       
        push    dword 0      
        call    [exit]      
