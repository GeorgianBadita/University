;Badita Marin-Georgian, gr. 211, 20.11.2017, tema lab 7, problema 4
;4. Dandu-se doua siruri de octeti sa se calculeze toate pozitiile unde al doilea sir apare ca subsir in primul sir.
bits 32


global start        


extern exit, printf            
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    s db "abcdbecdbec0"
    ;sirul initial
    s1 db "bec" ;sirul de verificat a fi subsir
    len_S equ s1 - s ;lungimea sirului s
    len_S1 equ $ - s1 ;lungimea sirului s1
    rez times len_S db -1 ;rezultatul
    poz db 0 ;pozitia curenta
    cnt dw 0 ;numarul de potriviri
    format_print db "%d",10, 0

; our code starts here
segment code use32 class=code
    start:
        cld; setam DF la 0 pentru parcurgere de la stanga la dreapta
        mov ECX, len_S - len_S1 + 1;parcurgem sirul intr-un loop de |s| - |s1| + 1 ori (|s| notat cardinal de s)
        mov EDX, 0; punem in EDX 0, pentru a juca rol de contor pentru sirul de pozitii
        cmp ECX, 0; comparam dimensiunea lui ECX cu 0, pentru ca in cazul in care |s1| > |s| sa nu avem ciclu infinit
        jng sf_Prg
        jecxz sf_Prg
        for_1:
            mov ESI, s;punem sirul sursa in ESI
            mov AL, [poz] ;punem in AL, pozitia curenta
            cbw ;AL -> AX
            cwde; AX -> EAX
            add ESI, EAX ;adunam la baza sirului sursa, pozitia curenta
            mov AL, [poz]  ;punem pozitia in AL
            inc AL           ;incrementam pozitia
            mov [poz], AL  
            mov EDI, s1 ;punem sirul destinatie in EDI
            push ECX ;salvam ECX pe stiva
            mov ECX, len_S1; punem in ECX lungimea lui S1
            mov AX, 0
            mov [cnt], AX ;setam numarul de potriviri de la pozitia curenta cu 0
            for_2:
                cmpsb ;compar element cu elemnt sirul de lungime len_S1 ce incepe la pozitia curenta din sirul sursa, cu elementele sirului destinatie
                je isEq ;daca sunt egale
                jne notEq
                isEq:
                mov AL, [cnt] 
                inc AL ;numar o potrivire
                mov [cnt], AL
                notEq:
                loop for_2 ;in caz de neegalitate refacem loop-ul
                
            mov AX, [cnt]  ;punem numarul de potriviri de la pozitia curenta in AX
            mov BX, len_S1 ;punem lungimea sirului S1 in BX
            cmp AX, BX ;comparam cele doua valori
            je savePos ;daca numarul de potriviri este egal cu lungimea sirului, salvam pozitia
            jne notSave;daca numarul de potriviri nu este egal cu lungimea sirului, refacem loop-ul
            savePos:
                mov AL, [poz] ;punem pozitia la care ne aflam in AL
                sbb AL, 1 ;o decrementam cu 1, pentru a face indexarea de la 0
                mov [rez + EDX], AL ;in sirul rezultat, la pozitia EDX, salvam pozitia 
                inc EDX ;incrementam EDX
            notSave:
            pop ECX ;restauram valoarea lui ECX
            loop for_1;facem inca odata loop la for_1
            
        sf_Prg: ;eticheta de sfarsit de program
        mov ECX, len_S ;punem in ECX lungimea sirului S, respectiv lungimea sirului rez
        mov ESI, rez ;punem in sirul sursa, sirul rezultat
        for_afisare: ;eticheta de afisare
            lodsb ;punem in AL, elementul de la pozitia curenta din sursa
            cmp AL, -1 ;comparam valoarea cu -1
            jg save ;in caz ca valoarea este mai mare decat -1 o salvam
            jng loop_again ;altfel ne reintoarcem la loop
        save:
            cwd ;in caz ca salvam, trecem valoarea din AL in AX
            cwde ;trecem valoarea din AX in EAX
            pushad ;salvam valorile registriilor
            push DWORD EAX ;punem EAX pe stiva
            push DWORD format_print ;punem formatul de printare pe stiva
            call [printf] ;apelam functia print
            add ESP, 4*2; eliberam stiva
            popad;restauram valoarea registrilor
        loop_again:    
        loop for_afisare
        push    dword 0      
        call    [exit]      
