bits 32
segment use32 public code
global sortare
rez dd 0
sortare:
        mov ECX, [ESP + 8]
        mov EBX, [ESP + 4]
        mov [rez], EBX
        dec ECX ;decrementam ECX
        next_Scan: 
            mov EBX, ECX ;salvam valoarea lui ECX in EBX
            mov ESI, 0 ;punem 0 in ESI
        next_com:
            mov AL, [rez + ESI] ;punem elementul curent in AL
            mov DL, [rez + ESI + 1] ;punem elementul urmator in DL
            cmp AL, DL ;comparam AL, DL
            jb no_Swap ;AL < DL nu avem nevoie de modificari
                mov [rez + ESI], DL ;facem swap
                mov [rez + ESI + 1], AL; facem swap
            no_Swap:
                inc ESI ;trecem la elementul urmator
                dec EBX ;decrementam EBX
                jnz next_com ;daca EBX nu e 0, trecem la urmatoarea comparatie
        loop next_Scan ;trecem la urmatoarea scanare
            ret 8
        