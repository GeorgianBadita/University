;Sa se citeasca un nume de fisier dat de la tastatura, sa se citeasca un text din acest fisier si sa se afiseze 
;pozitia din alfabet a fiecarei litere - caracterele pot fi litere mari, litere mici si caractere speciale, cifre
;se vor modifica doar literele mari si literele mici, iar cifrele vor fi inlocuite cu litera din alfabet corespunzatoare
bits 32 


global start        


extern exit, scanf, fopen, fread, fprintf, printf, fclose               
import exit msvcrt.dll    
import scanf msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    len equ 100
    text times (len + 1) db 0
    descriptor_fis dd -1
    nume_fisier times 20 db 0
    mod_access db "r+", 0
    fisier_intermediar db "intermediar.txt", 0
    fmt_citire db "%s", 0
    final_txt db "Eroare la deschiderea fisierului", 0
    rez times (len+1) db 0
    mod_acces2 db "w+", 0
    descriptor_fis2 dd -1
    rez1 times (len+1) db 0
    
segment code use32 class=code
    start:
        
        push DWORD nume_fisier      ;punem pe stiva numele fisierului
        push DWORD fmt_citire       ;punem pe stiva formatul de citire
        call [scanf]                ;apelam functia scanf
        add ESP, 4*2                ;eliberam parametrii de pe stiva


        push DWORD mod_access       ;punem modul de acces pe stiva
        push DWORD nume_fisier      ;punem numele fisierului pe stiva
        call [fopen]                ;apelam fopen pentru deschiderea fisierului
        add ESP, 4*2                ;eliberam parametrii de pe stiva
        
        cmp EAX, 0                  ;verificam daca functia a returnat eroare la deschidere
        je open_err                 ;daca da, afisam mesajul de eroare
        mov [descriptor_fis], EAX   ;punem in descriptor_fis, valoarea returnata de EAX
        
            pushad
            push DWORD mod_acces2
            push DWORD fisier_intermediar
            call [fopen]
            add ESP, 4*2
            mov [descriptor_fis2], EAX
            popad
        
        
        bucla:
            push DWORD [descriptor_fis]     
            push DWORD len
            push DWORD 1
            push DWORD text                 ;citim cate un buffer
            call [fread]
            add ESP, 4*4
            
            cmp EAX, 0                      ;daca s-au citit 0 caractere am terminat
            je clean_up                     ;sarim la clean_up
            
            ;push DWORD text
            ;push DWORD fmt_citire
            ;call [printf]
            ;add ESP, 4*2
            
            mov ECX, EAX                    ;punem numarul de caractere citite in ECX
            mov ESI, text
            mov EDI, rez
            repet:
               lodsb
               cmp AL, 'a'
               jae test_z
               jmp test_A
               test_z:
                   cmp AL, 'z'
                   jbe is_lower
                   jmp test_A
                   is_lower:
                     sub AL, 'a'
                     add AL, '0'
                     stosb
                     jmp base
                test_A:
                    cmp AL, 'A'
                    jae test_Z
                    jmp test_1
                    test_Z:
                        cmp AL, 'Z'
                        jbe is_upper
                        jmp test_1
                        is_upper:
                            sub AL, 'A'
                            add AL, '0'
                            stosb
                            jmp base
                
                test_1:
                    cmp AL, '1'
                    jae test_9
                    jmp simple_store
                    test_9:
                        cmp AL, '9'
                        jbe is_dig
                        jmp simple_store
                        is_dig:
                            sub AL, '0'
                            add AL, 'a'
                            stosb
                            jmp base
            simple_store:
                stosb
            base:            
            loop repet
            
            
            pushad
            push DWORD rez
            push DWORD [descriptor_fis2]
            call [fprintf]
            add ESP, 4*2
            popad
            
        jmp bucla
        
        clean_up:
            
            push DWORD [descriptor_fis2]
            push DWORD len
            push DWORD 1
            push DWORD text
            call [fread]
            add ESP, 4*4
            
           
            push DWORD text
            push DWORD [descriptor_fis]
            call [fprintf]
            add ESP, 4*2
            
            
            push DWORD [descriptor_fis2]
            call [fclose]
            add ESP, 4*1
            push DWORD [descriptor_fis]
            call [fclose]                   ;inchidem fisierul
            add ESP, 4*1
        
        
        jmp final                   ;sarim la final (nu avem eroare)
        
        open_err:
        push DWORD final_txt        ;punem mesajul de eroare pe stiva
        call [printf]               ;apelam printf
        add ESP, 4*1                ;eliberam stiva
        final:
        push    dword 0      
        call    [exit]       
