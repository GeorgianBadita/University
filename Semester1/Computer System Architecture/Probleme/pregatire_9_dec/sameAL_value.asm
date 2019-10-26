bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        mov AL, 250 >> 4
        mov AL, 0FFFFh >> 4
        mov AL, 0EFFFh >> 12
        mov AL, -1 >> 4
        mov AL, -1>>12
        push    dword 0      
        call    [exit]      
