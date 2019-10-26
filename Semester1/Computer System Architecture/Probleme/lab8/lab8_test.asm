;codificare cezar a unui strig citit de la tastatura
bits 32


global start        


extern exit, scanf, printf              
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    ; ...
    format_scan_str db "%s", 0
    format_print db "%s", 0
    format_scan_int db "%u", 0
    len equ 15
    string times len db 0
    key db 0
; our code starts here
segment code use32 class=code
    start:
        PUSHAD  ;salvamm valorile registriilor
        push DWORD string       ;punem adresa string-ului 
        push DWORD format_scan_str ;punem formatul de citire al stringului
        call [scanf] ;apelam functia scanf
        add ESP, 4*2 ;eliberam stiva
        POPAD ;restauram valorile registriilor
        PUSHAD ;salvamm
        push DWORD key ;punem adresa variabilei key
        push DWORD format_scan_int ;punem pe stiva formatul de citire al unui numar intreg
        call [scanf] ;apelam functia scanf
        add ESP, 4*2 ;eliberam stiva de valor
        POPAD ;restauram
        
        mov AL, [key] ;punem valoarea key in AL
        mov AH, 0 ;convertim fara semn AL la AX
        mov BL, 26 ;punem numarul de litere din alfabetul englez in BL
        div BL ;impartim prin BL
        mov [key], AH ;punem inapoi valoarea variabilei key
        
        mov ESI, string ;punem in sursa sirul string
        mov EDI, string ;punem in destinatie sirul string
        mov ECX, len ;punem lungimea maxima a stringului
        jecxz sf_Prg ;daca ECX e 0 sarim la sf_Prg
        repeta:
            lodsb ;incarcam in AL, litera curenta
            cmp AL, 0 ;o comparam cu 0
            je sf_Prg ;daca e 0, inseamna ca am terminat sirul
            add AL, [key]
            cmp AL, 122
            jbe store
            jnb store_higher
            store:
                stosb
                loop repeta
            store_higher:
                sbb AL, 122
                add AL, 96
                stosb
        loop repeta
        sf_Prg:
        
        push DWORD string
        push DWORD format_print
        call [printf]
        add ESP, 4*2
        push    dword 0      
        call    [exit]      
