;Se da un sir de dublucuvinte. Sa se ordoneze descrescator sirul cuvintelor inferioare ale acestor dublucuvinte. Cuvintele superioare raman neschimbate.
;sir DD 12345678h 1256ABCDh, 12AB4344h
;rez DD 1234ABCDh, 12565678h, 12AB4344h.
bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    sir dd 12345678h, 1256ABCDh, 12AB4344h
    len equ ($-sir)/4
    rez times len dw 0
    poz db 0
    new_ecx db 0
; our code starts here
segment code use32 class=code
    start:
        
        cld ;setam DF la 0 ca sa parcurgem de la stanga la dreapta 
        mov ECX, len ;punem in ECX lungimea sirului pentru a tiera
        mov ESI, sir ;punem in sursa sirul sir
        mov EDI, rez ;punem in destinatie sirul rezultat
        jecxz sf_prg ;daca ECX  = 0, sarim la sf_prg
        repeta:
            lodsw ;punem in AX valoarea cuvantului inferior
            stosw ;punem in sirul rez valoarea cuvantului superior
            lodsw ;mai apleam inca odata lodsw, pentru a trece la cuvantul superior
        loop repeta
        
        sf_prg:
        ;_______________
         ;for(int i = 0; i<n - 1; i++) {
            ;for(j = i; j<n; j++) {
             ;   if(v[i] < v[j) {
              ;      aux = v[i];
               ;     v[i] = v[j]
                ;    v[j] = aux
                ;}
            ;}
         ;}
        mov ECX, len
        dec ECX
        nextScan:
            mov EBX, ECX ;punem ECX in EBX
            mov ESI, 0 ;contorizaom de la pozitia 0
        nextComp: 
            mov AX, [rez + ESI] ;AX reprezinta rez[ESI] ;cuvantul de la rez[ESI]
            mov DX, [rez + ESI + 2] ;AX reprezinta rez[ESI + 2] ;cuvantul de la rez[ESI + 2]
            cmp AX, DX ;comparam rez[ESI], rez[ESI + 2]
            jnc noSwap ; ;in cazul in care AX > DX
            mov [rez + ESI], DX ;facem interschimbarea
            mov [rez + ESI + 2], AX ;facem interschimbarea
        noSwap:
            inc ESI ;incrementam ESI cu 2 pozitii pentru a ajunge la urmatorul cuvant
            inc ESI
            dec EBX
            jnz nextComp ;daca EBX nu e 0 atunci facem urmatoarea comparatie 
        loop nextScan ;facem urmatoarea scanare a sirului
        
        cld ;setam DF la 0 ca sa parcurgem de la stanga la dreapta 
        mov ECX, len ;punem in ECX lungimea sirului pentru a itera
        mov ESI, rez ;punem in sursa sirul rezultat
        mov EDI, sir ;punem in destinatie sirul de la care am plecat
        repeta_1:
            lodsw  ;punem in AX valoarea curenta din rezultat
            stosw ;punem in sirul sir valoarea corespunzatoare din sirul sortat la nivel de cuvant!
            inc EDI ;incrementam EDI cu 2 pozitii, adica sirul sir pentru a ajunge la cuvantul superior
            inc EDI ;incrementam EDI cu 2 pozitii, adica sirul sir pentru a ajunge la cuvantul superior
        loop repeta_1 ;repetam din nou procedeul
        
        push dword 0
        call [exit]