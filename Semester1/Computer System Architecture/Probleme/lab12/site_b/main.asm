bits 32
global start        


extern exit, scanf, printf 
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    format_scan db "%d", 0
    number dw 0
    a dw 0
    b dw 0
segment code use32 class=code
    readInteger:
        
        push DWORD number
        push DWORD format_scan
        call [scanf]
        add ESP, 4*2
        mov WORD EAX, [number]
        ret
    start:
        call readInteger
        mov [a], EAX
        call readInteger
        mov [b], EAX
        
        add EAX, [a]
        
        
        
        
        
        push    dword 0      
        call    [exit]       
