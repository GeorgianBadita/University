

bits 32


global start        


extern exit, fopen, fread, fclose, printf     
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    nume_fisier db "input.txt", 0 ;numele fisierului care ca fi creat
    mod_acces db "r", 0           ;modul de deschidere a fisierului
    len equ 100                   ;numarul maxim de elemente cititie din fisier
    buffer times (len + 1) db 0     ;sirul in care se va citit textul din fisier de dimensiune (len + 1)
    descrptor_fis dd -1           ;variabila in care vom salva descriptorul fisierului - necesar pentru a putea face referire la fisier
    format db "Numarul de vocale din text este %d", 0 ;formatul - utilizat pentru afisarea numarului de consoane din textul cititi
; our code starts here
    nr_car_citite dd 0 ;variabila in care vom salva numarul de caractere
    numar_voc dd 0   ;variabila care numara cate consoane avem
    voc_mici db "aeiou"
    voc_Mari db "AEIOU"
    aux dd 0
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
            
            mov EDX, 0
            num_voc:
                push ECX
                mov ECX, 5
                mov EBX, 0
                mov AL, [buffer + EDX]
                inc EDX
                check_voc:
                    mov AH, [voc_Mari + EBX]
                    cmp AL, AH
                    je cnt_voc1
                    jmp next
                    cnt_voc1:
                        mov [aux], EBX
                        mov EBX, [numar_voc]
                        inc EBX
                        mov [numar_voc], EBX
                        mov EBX, [aux]
                    next:
                        mov AH, [voc_mici + EBX]
                        cmp AL, AH
                        je cnt_voc2
                        jmp last_step
                        cnt_voc2:
                            mov [aux], EBX
                            mov EBX, [numar_voc]
                            inc EBX
                            mov [numar_voc], EBX
                            mov EBX, [aux]
                        last_step:
                            inc EBX
                            loop check_voc
                pop ECX
            loop num_voc
            jmp bucla ;refacem citirea
            
        clean_up:
           
            ;cand am terminat de prelucrat sirul, afisam numarul de consoane
            
            push DWORD [numar_voc]
            push DWORD format
            call [printf]
            add ESP, 4*2
            
            ;apelam functia fclose pentru a inchide fisierul
            ;fclose(descrptor_fis)
            push DWORD descrptor_fis
            call [fclose]
            add ESP, 4
            
            
        final:
        push    dword 0      
        call    [exit]      
