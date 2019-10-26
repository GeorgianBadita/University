bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        mov AL, 2255
        add AL, -1
        push    dword 0      
        call    [exit]      
