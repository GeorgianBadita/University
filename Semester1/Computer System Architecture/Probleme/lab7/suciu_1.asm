;Given two strings of words, a and b, obtain a third string c in the following way: concatenate the string of the least significant bytes from the words of the first string with the string of most significant bytes of the words from the second string. String c must be ordered ascending, bytes are signed numbers.

bits 32


global start        


extern exit            
import exit msvcrt.dll
segment data use32 class=data
    a dw 1234h, 5678h, 90h
    lenA equ ($ - a)/2
    b dw 4h, 0abcdh, 10h, 1122h
    lenB equ ($ - b) / 2
    dest times lenA + lenB db 0
    c times lenA + lenB db 0
    saveSort dd 0
    aux db 0
 
;c should be 34h, 78h, 90h, 00h, abh, 00h, 11h
; our code starts here
segment code use32 class=code
    start:
        mov esi, a 
        mov ebx, 0 ;contorul pt sirul nostru
        cld ;parcurgem sirul de la stanga la dreapta
        mov ecx, lenA ;parcurgem elementele sirului cu un loop de lenA ori
        repeta:
            lodsb ;in al vom avea octetul cel mai putin al cuvantulu din sir
            mov [dest + ebx], al
            inc ebx
            lodsb
        loop repeta
        
        mov esi, b
        cld 
        lodsb
        lodsb
        mov [dest + ebx], al
        inc ebx
        mov ecx, lenB - 1 ;parcurgem de lenB ori
        repeta1:
            lodsb
            lodsb
            mov [dest + ebx], al
            inc ebx
        loop repeta1
        
        mov ECX, lenA + lenB ;punem lungimea sirului 
        dec ECX ;decrementam ECX
        nextScan:
            mov EBX, ECX ;salvam valoarea lui ECX in EBX
            mov ESI, 0 ;punem 0 in ESI
        nextComp:
            mov AL, [dest + ESI] ;AL este valoarea curenta din dest
            mov DL, [dest + ESI + 1] ;DL este vaoarea urmatoare
            cmp AL, DL ;comparam AL cu DL
            jc noSwap ;daca AL < DL nu facem swap
            mov [dest + ESI], DL ;facem swap
            mov [dest + ESI + 1], AL
        noSwap:
            inc ESI ;trecem la elementul urmator
            dec EBX ;decrementam EBX
            jnz nextComp ;mergem la urmatoarea comparatie
        loop nextScan ;mergem la urmatoarea scanare
       
        push    dword 0      
        call    [exit]      

        