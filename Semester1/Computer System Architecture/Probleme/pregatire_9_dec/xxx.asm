bits 32


global start        


extern exit, printf            
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    ; ...
    format db '%x %x %x', 0
    a dq 0x12345678abcdef01
    b db 0, 1, 2, 3, 4, 5
; our code starts here
segment code use32 class=code
    start:
        
        push dword [b]
        push dword [a + 2]
        push dword [a]
        push dword format
        call [printf]
        push    dword 0      
        call    [exit]      
