bits 32 


global start        


extern exit, printf            
import exit msvcrt.dll   
import printf msvcrt.dll
 


segment data use32 class=data
    ; ...
    sir db 10, 12, 13, 15, 0
    len_sir equ $-sir
    fmt_ db "%s", 0
    var db 082h
segment code use32 class=code
    start:
        
        mov AL, 80h
        mov BL, 80h
        sub AL, BL
        push    dword 0      
        call    [exit]        
