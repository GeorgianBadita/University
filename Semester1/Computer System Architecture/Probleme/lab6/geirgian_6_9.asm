;Se da un sir de octeti S. Sa se construiasca un sir D1 care sa contina toate numerele pozitive si un sir D2 care sa contina toate numerele negative din S. 

bits 32


global start  


extern exit       
import exit msvcrt.dll
segment data use32 class=data
    s db -1, -3, -2, -5, -3, -8, -5, 7 ;declaram sirul s
    l equ $ - s; stabilirea lungimii sirului destinatie
    d1 times l db 0
    d2 times l db 0
; our code starts here
segment code use32 class=code
    start:
       
        mov ECX, l ;punem lungimea sirului in ECX pentru a putea realiza bucla loop de ECX ori
        mov ESI, 0 ;punem 0 in contor cu care iteram prin sir
        mov EBX, 0 ;punem 0 in contorul cu care iteram prin d1
        mov EDX, 0 ;punem in 0 contorul cu care iteram prin d2
        jecxz Sf_prog
        Repeta:
            mov AL, [s + ESI] ;punem in AL, elementul de pe pozitia ESI din sir
            cmp AL, 0 ;comparam valoarea din AL cu 0
            jl negative ;in caz ca AL < 0 mergem la eticheta negative
            jge positive ;in caz in care AL >= 0 mergem la eticheta positive
            
            negative:
            
                mov [d2 + EDX], AL ;punem in pozitia curenta din d2 pe AL
                inc EDX ;incrementam EDX
                inc ESI ;incrementam contorul general
                loop Repeta ;mergem inapoi la loop pentru a nu intra si pe cazul pozitiv
                jecxz Sf_prog; ne asiguram ca in cazul in care ultimul element din sir este negativ, nu va fi pus si in d1
           
            positive:
             
                mov [d1 + EBX], AL ;punem in pozitia curenta din d1 pe EBX
                inc EBX ;incrementam pe EBX
                inc ESI ;incrementam contorul general si revenim la eticheta Repeta
        loop Repeta
        Sf_prog:
        
        push    dword 0      
        call    [exit]      
