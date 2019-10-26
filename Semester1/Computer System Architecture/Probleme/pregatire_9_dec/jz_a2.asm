bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    x dw 0fffdh
; our code starts here
segment code use32 class=code
    start:
    mov AX, 054ah
    add [x],  2 ;Operand zie not specifed (WORD inainte de 2)
    jz a2
    
    
    a2:
        push    dword 0      
        call    [exit]      
