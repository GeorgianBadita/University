bits 32 


global start        


extern exit, scanf, printf, fopen, fclose, fprintf      
import exit msvcrt.dll    
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll

segment data use32 class=data
    ; ...
    mod_acces db "w", 0
    nume_fisier times 31 db 0
    text  times 121 db 0
    descriptor_fis dd -1
    read_format db "%s", 0
segment code use32 class=code
    start:
        
        push DWORD nume_fisier
        push DWORD read_format
        call [scanf]
        add ESP, 4*2
        
        push DWORD text
        push DWORD read_format
        call [scanf]
        add ESP, 4*2
        
        
        push DWORD mod_acces
        push DWORD nume_fisier
        call [fopen]
        add ESP, 4*2
        
        cmp EAX, 0
        je final
            mov [descriptor_fis], EAX
            
            push DWORD text
            push DWORD [descriptor_fis]
            call [fprintf]
            add ESP, 4*2
        final:
        
        
        push    dword 0      
        call    [exit]       
