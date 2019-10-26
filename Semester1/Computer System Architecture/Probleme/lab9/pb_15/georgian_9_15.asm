

bits 32


global start        


extern exit, fopen, fread, fclose, printf, fprintf    
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    ; ...
    nume_fisier db "input.txt", 0 ;numele fisierului care ca fi creat
    mod_acces db "r", 0           ;modul de deschidere a fisierului
    len equ 100                   ;numarul maxim de elemente cititie din fisier
    buffer times (len + 1) db 0     ;sirul in care se va citit textul din fisier de dimensiune (len + 1)
    descrptor_fis dd -1           ;variabila in care vom salva descriptorul fisierului - necesar pentru a putea face referire la fisier
    format db "%s", 0 ;formatul - utilizat pentru afisarea numarului de consoane din textul cititi
; our code starts here
    nr_car_citite dd 0 ;variabila in care vom salva numarul de caractere
    numar_voc dd 0   ;variabila care numara cate consoane avem
    text times 200 db 0
    mod_acces1 db "w"
segment code use32 class=code
    start:
        ;apelam fopen pentru a deschide fisierului
        ;functia va returna in EAX descriptorul fisierului sau 0 in caz de eroare
        ;EAX = fopen(nume_fisier, mod_acces)
        
        push DWORD mod_acces
        push DWORD nume_fisier
        call [fopen]
        add ESP, 4*2    ;eliberam parametrii de pe stiva
       
        mov [descrptor_fis], EAX ;salvam valoarea returnata de fopen in variabila descrptor_fis
        
        ;verificam daca functia fopen a accesat cu succes fisierul (daca EAX != 0)
        mov EDX, 0
        cmp EAX, 0
        je final
        ;citim textul din fisierul deschis folosind functia fread
        ;EAX = fread(text, 1, len, descrptor_fis)
        
        bucla:
            ;citim o parte(100 de caractere) din textul in fisierul deschis folosind fread
            ;EAX = fread(buffer, 1, len, descrptor_fis)
            push DWORD [descrptor_fis]
            push DWORD len
            push DWORD 1
            push DWORD buffer
            call [fread]
            add ESP, 4*4
            
            ;EAX = numar de caractere /bytes citite
            cmp EAX, 0  ;daca numarul de caractere citite este  0, am terminat de parcurs fisierul
            je clean_up
            
            mov [nr_car_citite], EAX ;salvam numarul de caractere citite
            mov EDX, 0      ;punem 0 in EDX, deoarece il vom folosi ca si contor
            mov ECX, [nr_car_citite] ;punem in ECX nr_car_citite ca sa iteram 
            cld ;setam directia de parcurgere de la stanga la dreapta
            cmp ECX, 0
            je final
            mov EBX, 0
            constr:
                mov AL, [buffer + EBX]
                cmp AL, '0'
                je base_case
                jnge change
                jmp cmp_lower_z
                change:
                    mov AL, 'X'
                    mov [buffer + EBX], AL
                    jmp base_case
                
                cmp_lower_z:
                    cmp AL, 'z'
                    je base_case
                    jge change
                    jmp cmp_9
                    
                    cmp_9:
                        cmp AL, '9'
                        je base_case
                        jng base_case
                        jmp cmp_A
                        
                        cmp_A:
                            cmp AL, 'A'
                            je base_case
                            jnge change
                            jmp cmp_Z
                            
                            cmp_Z:
                                cmp AL, 'Z'
                                je base_case
                                jnge base_case
                                jmp cmp_a
                                
                                cmp_a:
                                    cmp AL, 'a'
                                    je base_case
                                    jnge change
                                    jmp base_case
                
                base_case:
                    inc EBX
                    loop constr
            jmp bucla ;refacem citirea
  
  
        clean_up:
           
           
            
            
        final:
        ; apelam fopen pentru a crea fisierul
        ; functia va returna in EAX descriptorul fisierului sau 0 in caz de eroare
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces1     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2                ; eliberam parametrii de pe stiva

        mov [descrptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final1
        
        ; scriem textul in fisierul deschis folosind functia fprintf
        ; fprintf(descriptor_fis, text)
        push dword buffer
        push dword [descrptor_fis]
        call [fprintf]
        add esp, 4*2
        
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [descrptor_fis]
        call [fclose]
        add esp, 4
        final1:
        push    dword 0      
        call    [exit]      
