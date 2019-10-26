bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        stc
        mov ECX, -1<<12 ;CH = -16, CF - ramane neschimbat
        
        push    dword 0      
        call    [exit]      
