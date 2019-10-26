bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    sir dw 0, 1,2 ,3 
; our code starts here
segment code use32 class=code
    start:
        
        mov AX, 0feh
        mov BL, 0feh ;Division overflow restul nu intra in AH
        idiv BL
        push    dword 0      
        call    [exit]      
