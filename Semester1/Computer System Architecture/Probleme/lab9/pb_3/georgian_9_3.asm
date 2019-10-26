bits 32
global start        


extern exit, fprintf, fopen, fclose, fread, printf              
import exit msvcrt.dll    
import fprintf msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "input.txt", 0       ;numele fisierului
    mod_access db "r+", 0               ;modul de acces r+
    descriptor_fisier dd -1             ;descriptorul fisierului
    nr_car_citite dd 0                  ;numarul de caractere citite la fiecare tura
    len equ 1                           ;lungimea unui buffer de caractere citit 
    buffer times len db 0               ;rezervarea spatiului pentru buffer
    counter dd 0                        ;numarul in care vom contoriza nr de cifre
    rez times 100 db 0                  ;sirul rezultat
    
    format_print db "Numarul de cifre pare este %d", 10, 13, 0
    format_print_1 db "Acestea sunt %s",0
        
segment code use32 class=code
    start:
        
        push DWORD mod_access           ;punem modul de acces pe stiva
        push DWORD nume_fisier          ;punem numele fisierului pe stiva 
        call [fopen]                    ;apelam functioa fopen
        add ESP, 4*2                    ;curatam stiva de parametrii
        
        cmp EAX, 0
        je final
        
        mov [descriptor_fisier], EAX    ;punem valoarea lui EAX in descriptor_fisier daca nu avem eroare
        mov EBX, 0                      ;contorul de cifre
        
        mov EDI, rez                    ;punem adresa de inceput a sirului rez in sirul destinatie
        
        bucla:
            ;citim o parte (50 de caractere) din textul in fisierul deschis, folosind functia fread
            
            push DWORD  [descriptor_fisier]
            push DWORD len
            push DWORD 1
            push DWORD buffer
            call [fread]
            add ESP, 4*4
            
            ;EAX <- nr de caractere citite 
            
            cmp EAX, 0
            je cleanup
            mov [nr_car_citite], EAX
            
            mov AL, [buffer]
            sub AL, '0'
            mov AH, 0
            cmp AL, AH
            jge check_9
            jmp bucla
            check_9:
                mov AH, 9
                cmp AL, AH
                jnge is_dig
                jmp bucla
                is_dig:
                    cbw
                    mov DL, 2
                    div DL
                    mov AL, 0
                    cmp AL, AH
                    je is_even
                    jmp bucla
                    is_even:
                        mov AL, [buffer]
                        inc EBX
                        stosb
            
        jmp bucla
        
        cleanup:
            push DWORD [descriptor_fisier]
            call [fclose]
            add ESP, 4*1
            
            push DWORD EBX
            push DWORD format_print
            call [printf]
            add ESP, 4*2
            
            push DWORD rez
            push DWORD format_print_1
            call [printf]
            add ESP, 4*2
            
        final:
        
        push    dword 0      
        call    [exit]       
