bits 32


global start        


extern exit, scanf, printf              
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    n dd 0
    rez dd 0
    format_nr db "%u", 0

; our code starts here
segment code use32 class=code
    start:
       
        ;citire
        push DWORD n
        push DWORD format_nr
        call [scanf]
        add ESP, 4*2
        
        ;calc sum
        mov ECX, [n]
        jecxz final_prg
        repeta:
            add [rez], ECX
        loop repeta
        
        final_prg
        
        ;print sum
        push DWORD [rez]
        push DWORD format_nr
        call [printf]
        
        add ESP, 4*2
        push    dword 0      
        call    [exit]      
