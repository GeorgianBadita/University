;Dandu-se un sir de octeti sa se obtina un sir de cuvinte care sa contina in octetii inferiori multimea caracterelor din sirul de octeti, iar octetul superior al unui cuvant sa contina numarul de aparitii al octetului inferior din acel cuvant in sirul de octeti dat.

bits 32


global start        
    
extern exit       
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    sir db 2, 4, 2, 5, 2, 2, 4, 4, 6, 6, 6       ;sirul dat
    len equ $ - sir                     ;lungimea sirului
    nr_ap times 10 db 0                 ;consideram vectorul de frecventa nr_ap am setat dimensiunea la 10, pentru acest exemplu
    numere times 10 db 0                ;dar dimensiunea lui, in mod normal este = cu maximul sirului sir
    rez times 10 dw 0                   ;variabila unde va fi stocat rezultatul
    copie db 0                          ;variabila auxiliara ce ne va ajuta in rezolvarea problemei
    
; our code starts here
segment code use32 class=code
    start:
        cld                             ;setam DF la 0 pentru parcurgere de la st -> dr
        mov ESI, sir                    ;punem in ESI baza sirului sir
        mov ECX, len                    ;punem in ECX lungimea sirului pentru a itera
        mov EBX, 0                      ;punem in EBX 0 pentru a-l folosi pe post de oncotr mai tarziu
        jecxz sf_prg
        repeta:
            lodsb                       ;AL = elementul curent din sirul sir
            cbw                         ;convertim din AL in AX
            cwde                        ;convertim din AX in EAX
            mov [copie], EAX            ;salvam valoarea curenta in variabila [copie]
            mov AL, [nr_ap + EAX]       ;am convertit din AL in EAX pentru a putea aplica formula de la 2 noaptea 
            cmp AL, 0                   ;comparam Valoarea lui AL cu 0, unde AL acum retine numarul de aparitii al elementuli
                                        ;curent si comparam cu 0 pentru a vedea daca am mai vizitat elementul sau nu
            je nevizitat                ;in caz ca nu l-am vizitat sarim la eticheta nevizitat
            jne vizitat                 ;in caz ca l-am vizitat sarim la eticheta vizitat
            nevizitat:
                mov EAX, [copie]        ;restauram valoarea lui EAX la valoarea curenta din sir
                mov EDX, [nr_ap + EAX]  ;punem in EDX numarul de apartitii al numarului stocat in EAX
                inc EDX                 ;incrementam cu 1, deoarece l-am vizitat
                mov [nr_ap + EAX], EDX  ;punem in vectorul de frecventa aparitia
                mov [numere + EBX], EAX ;pentru ca trebuie sa afisam elementele distincte, elementele deja vizitate le stocam
                                        ;in alt sir
                inc EBX                 ;folosim EBX ca si contor pentru cel de-al 2-lea sir
                jecxz sf_prg            ;daca ECX a ajuns la 0, sarim la finalul programului
                loop repeta             ;daca nu refacem loop-ul
            vizitat:    
                mov EAX, [copie]
                mov EDX, [nr_ap + EAX]  ;in cazul elementelor deja vizitate, doar contorizam aparitie, nu mai punem valoarea
                inc EDX                 ;in cel de-al 2-lea vector
                mov [nr_ap + EAX], EDX  
                jecxz sf_prg
                loop repeta
        
        mov ECX, EBX                    
        mov ESI, numere                ;pregatim sirurile, contoarele si ECX pentru unirea celor 2 siruri
        mov EDI, rez                   ;in octetul superior o sa punem numarul de aparitii al unui element
        jecxz sf_prg
        mov EDX, 0                     ;iar in octetul inferior, valoarea sa
        pune:
           lodsb                       ;AL = numarul curent
           stosb                       ;stocam valoarea in byte-ul low
           cbw
           cwde
           mov AL, [nr_ap + EAX]       ;facem conversia pentru formula de la 2 noaptea si luam numarul de aparitii al numarului
           stosb                       ;stocam numarul de aparitii
           
        loop pune                       ;repetam procesul
        
        sf_prg:
        push    dword 0      
        call    [exit]      

        