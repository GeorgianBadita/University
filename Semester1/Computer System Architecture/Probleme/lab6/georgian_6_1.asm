;Se dau doua siruri de octeti S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor din sirul S1 1uate de la stanga spre dreapta si a elementelor din sirul S2 luate de la dreapta spre stanga.
bits 32


global start        


extern exit              

import exit msvcrt.dll
segment data use32 class=data
    S1 db 1, 2, 3, 4, 5, 6, 7
    l_S1 equ $ - S1
    S2 db 8, 9
    l_S2 equ $ - S2
    d resb l_S1 + l_S2
    
; our code starts here
segment code use32 class=code
    start:
        mov ECX, l_S1
        mov ESI, 0
        jecxz Sf_Prog
        Repeta:
            mov AL, [S1 + ESI]
            mov [d + ESI], AL
            inc ESI
        loop Repeta
        
        mov ECX, l_S2
        jecxz Sf_Prog
        mov EDX, ESI
        mov ESI, l_S2 - 1
        Repeta1:
           mov AL, [S2 + ESI]
           mov [d + EDX], AL
           dec ESI
           inc EDX
        loop Repeta1
        Sf_Prog:
        push    dword 0      
        call    [exit]      
