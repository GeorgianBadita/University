bits 32


global start        


extern exit, printf, scanf              
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    a dd 0
    format_scan dw "%d", 0
    format_print dw "%x", 0
; our code starts here
segment code use32 class=code
    start:
        push DWORD a
        push DWORD format_scan
        call [scanf]
        add ESP, 4*2
        
        push DWORD [a]
        push DWORD format_print
        call [printf]
        add ESP, 4*2
        push    dword 0      
        call    [exit]      
