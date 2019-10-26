bits 32 


global start        


extern exit, scanf, printf, concat              
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

 
segment data use32 class=data
    
    len equ 11
    len_rez equ 31
    sir1 times len db 0
    sir2 times len db 0
    sir3 times len db 0
    rez times len db 0
    format_read db "%s", 0


segment code use32 class=code
    start:
        
        push DWORD sir1
        push DWORD format_read
        call [scanf]
        add ESP, 4*2
        
        push DWORD sir2
        push DWORD format_read
        call [scanf]
        add ESP, 4*2
        
        push DWORD sir3
        push DWORD format_read
        call [scanf]
        add ESP, 4*2
        
        push DWORD rez
        push DWORD sir1
        call concat
        add ESP, 4*2
        
        push DWORD rez
        push DWORD sir2
        call concat
        add ESP, 4*2
        
        push DWORD rez
        push DWORD sir3
        call concat
        add ESP, 4*2
        
        push DWORD rez
        push DWORD format_read
        call [printf]
        add ESP, 4*2
        
        push    dword 0      
        call    [exit]       
