;Badita Marin-Georgian, gr. 211, 18/12/2018, tema lab 11, problema 13
;Se dau trei siruri de caractere. Sa se afiseze cel mai lung sufix comun pentru fiecare din cele trei perechi de cate doua siruri ce se pot forma.
bits 32
global start        


extern exit, printf
extern sufix                           ;spunem asamblorului ca vom avea nevoie de functia sufix, care exista undeva in exterior
import exit msvcrt.dll    
import printf msvcrt.dll
global result                          ;marcam variabila restult ca si global pentru ca avem nevoie de ea in modulul modul.asm
segment data use32 class=data
    ; ...
    sir1 db "abcdefgh11023", 0                   ;primul sir
    lens_1 equ $-sir1 - 1
    sir2 db "szcasaefgh03", 0                 ;sirul 2
    lens_2 equ $ - sir2 - 1
    sir3 db "qwertzbcdefgh0", 0              ;sirul 3
     lens_3 equ $ - sir3 - 1                      ;dimensiunea sirului 3
    len equ 9                          ;dimensiunea maxima a unui sufix = min(lens_1, lens_2, lens_3)
                           ;dimensiunea primului sir
                           ;dimensiunea sirului 2
   
    format db "Sufixul comun dintre sirul %d si %d este: %s", 10, 0 ;formatul de afisare
    result times len db 0              ;sirul rezultat
    new_result times len db 0          ;sirul rezultat dupa oglindire
    vid db "vid", 0
    
segment code use32 class=code
    reverse:
        
        mov ECX, len - 1 ;punem in ECX lungimea maxima a unui sufix
        mov [new_result], BYTE 0
        .put0:
            mov [new_result + ECX], BYTE 0  ;punem 0 in new_result pentru a ne asigura ca nu avem 'reziduri' ramase de la celalalte apelari
        loop .put0
        mov ESI, result                 ;punem in ESI adresa sirului restult
        mov EBX, 0                      ;iar in EBX, 0
        .repeta:
            lodsb
            cmp AL, 0
            je .new
            inc EBX                     ;facem un loop pentru a afla lungimea sirului restult
            jmp .repeta
        .new:
            mov ESI, result             ;punem din nou in ESI adresa de inceput a sirului restult
            add ESI, EBX                ;la care adaugam lungimea sirului 
            sub ESI, 1                  ;si scadem 1 pentru a fi la ultimul elemnt
            std                         ;setam DF pentru a parcurge descrescator
            mov EDX, 0
            mov ECX, EBX
            .put_char:
                lodsb
                mov [new_result + EDX], AL  ;punem in new_result caracterele din restult, dar in ordine inversa
                inc EDX     
                dec ECX
                jz .stop
                jmp .put_char
        .stop:
            cld                 ;setam DF la 0, deoarece se pare ca functia exit nu functioneaza cand DF = 1
            ret                 ;apelam ret
    start:
        
       
        
        mov EAX, sir1 + lens_1 - 1     ;punem in EAX, adresa ultimului element din sirul 1
        mov EBX, sir2 + lens_2 - 1     ;punem in EBX adresa ultimului element din sirul 2
        call sufix                     ;apelam functia sufix din modulul modul.asm care returneaza cel mai lung sufix comun a 2 siruri, dar oglindit
        call reverse                ;apelam functia reverse din modulul main pentru a intoarce sirul
        
        push DWORD new_result       ;puem sirul new_result pe stiva
        push DWORD 2                ;punem 2 pentru a indica ca ne referim la sirul 2
        push DWORD 1                ;punem 1 pentru a indica ca ne referim la sirul 1
        push DWORD format           ;punem formatul de afisare
        call [printf]               ;apelam functia printf
        add ESP, 4*4                ;eliberam parametrii de pe stiva


        ;-----------------------------------
        ;|Aplicam exact acelasi rationament|
        ;|pentru sirurile 1,3 respectiv 2,3|
        ;-----------------------------------


        
        mov EAX, sir3 + lens_3 - 1
        mov EBX, sir1 + lens_1 - 1
        call sufix
        mov EAX, [result]
        cmp EAX,  0
        je next
        jmp new_afis1
        call reverse
        next:
         push DWORD vid
        push DWORD 2
        push DWORD 3
        push DWORD format
        call [printf]
        add ESP, 4*4
        new_afis1:
        push DWORD new_result
        push DWORD 3
        push DWORD 1
        push DWORD format
        call [printf]
        add ESP, 4*4
        
        mov EAX, sir2 + lens_2 - 1
        mov EBX, sir3 + lens_3 - 1
        
        call sufix
        mov EAX, [result]
        cmp EAX,  0
        je final
        jmp new_afis
        push DWORD vid
        push DWORD 2
        push DWORD 3
        push DWORD format
        call [printf]
        add ESP, 4*4
        new_afis:
        call reverse
        
        push DWORD new_result
        push DWORD 2
        push DWORD 3
        push DWORD format
        call [printf]
        add ESP, 4*4
        final:
        push    dword 0      
        call    [exit]       
