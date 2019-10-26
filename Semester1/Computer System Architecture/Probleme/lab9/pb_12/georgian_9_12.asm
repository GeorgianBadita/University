bits 32 


global start        


extern exit, fopen, fprintf, scanf, fclose, printf               
import exit msvcrt.dll    
import fopen msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll


segment data use32 class=data
    ; ...
    nume_fisier db "input.txt", 0
    mod_access db "a", 0
    descriptor_fis dd -1
    numar times 10 db 0
    format_read db "%s", 0
    space db " ", 0
segment code use32 class=code
    start:
        ;FILE *f = freopen("input.txt", "w", stdin)
        push DWORD mod_access           ;modul de acces pe stiva
        push DWORD nume_fisier          ;numele fisierului pe stiva
        call [fopen]                    ;apelam functia fopen
        add ESP, 4*2                    ;eliberam parametrii de pe stiva
        
        cmp EAX, 0                      
        je final                        ;daca EAX a returnat eroare sarim la eticheta final;
        
        mov [descriptor_fis], EAX       ;salvam valoarea descriptorului de fisier
        bucla:
            push DWORD numar
            push DWORD format_read
            call [scanf]
            add ESP, 4*2
            
            mov AL, BYTE [numar]
            sub AL, '0'
            cmp AL, 0
            je cleanup
            
            push DWORD numar
            push DWORD [descriptor_fis]
            call [fprintf]
            add ESP, 4*2
            
            push DWORD space
            push DWORD [descriptor_fis]
            call [fprintf]
            add ESP, 4*2
        jmp bucla
        
        cleanup:
            push DWORD [descriptor_fis]
            call [fclose]
            add ESP, 4*1
        
        final:
        push    dword 0      
        call    [exit]       
