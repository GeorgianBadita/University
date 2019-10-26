;Badita Marin-Georgian, 211, 7/11/2017, tema lab 6, 4

;Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte diferenta dintre fiecare 2 elemente consecutive din S. 
bits 32


global start        


extern exit, printf              
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    s db 1, 2, 4, 6, 10, 20, 25 ;declararea sirului s
    l equ $ - s - 1 ;stabilirea lungimii sirului initial l - 1
    d times l db 0, 0 ;rezervarea unui spatiu de memorie de dimensiune l pentru sirul destinatie d si initializarea acestuia
    format_sir db "%s", 0
; our code starts here
segment code use32 class=code
    start:
    
    mov ECX, l; punem lungimea in ECX pentru a putea realiza bucla loop de ecx ori
    mov ESI, 0; punem 0 in contor cu care iteram prin sir
    jecxz Sf_prog
    Repeta:
        mov AL, [s + ESI] ;punem in AL, elementul de pe pozitia ESI din sir
        mov BL, [s + ESI + 1] ;punem in AL, urmatorul element dupa elementul de pe pozitia ESI
        sub BL, AL ;facem scaderea elementelor consecutive
        add BL, '0' ;convertim
        mov [d + ESI], BL; punem in d rezultatul dorit
        inc ESI ;incrementam ESI pentru a trece la urmatoarea valoare
    loop Repeta  
    
    Sf_prog: ;terminarea programului
    ;afisarea sirului
    
    push DWORD d ;punem parametrul d pe stiva
    push DWORD format_sir; punem formatul de afisare a sirului
    call [printf] ;apelam functia printf
    add ESP, 4*2 ;eliberam stiva
        push    dword 0      
        call    [exit]      
