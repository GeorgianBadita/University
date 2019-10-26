bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    a times 4 dd 2
    l equ 10
    b dw a + 1
    cst equ $
; our code starts here
segment code use32 class=code
    start:
        mov ECX, cst
        push    dword 0      
        call    [exit]      
