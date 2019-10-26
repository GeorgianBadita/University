;Consider a string of double words. Obtain the ascending ordered sequence of bytes of rank multiple of 3 of the given string. 
;Example: let the double word string be
;s dd 12345678h,5bcfh,45327h,1798dfeh,0f112233h
;This string will be represented in memory as:
;| 78h| 56h| 34h| 12h| 0cfh| 5bh| 00h| 00h| 27h| 53h| 04h| 00h| 0feh| 8dh| 79h| 01h| 33h| 22h| 11h| 0fh|
;The sequence of bytes of rank multiple of 3 of the string s is obtained by concatenating the bytes from positions 0,3,6,9,..:
;| 78h| 12h| 00h| 53h| 0feh| 01h| 11h|
;This sequence must be in ascending order.
bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    s dd 12345678h,5bcfh,45327h,1798dfeh,0f112233h
    len equ ($ - s)/3 + 1 ;initializam lungimea sirului
    rez times len db 0 ;initializam rezultatul
; our code starts here
segment code use32 class=code
    start:
        
        cld
        mov ECX, len ;initializam ECX cu lungimea sirului pentru a itera
        mov ESI, s ;punem s in ESI
        mov EDI, rez ;punem rez in EDI
        repeta:
            lodsb; punem byte-ul de pe pozitie multiplu de 3 in AL
            stosb; facem store in sirul rez la AL
            lodsb; trecem la byte-ul 3k + 1
            lodsb; trecem la byte-ul 3k + 2
        loop repeta
        
        mov ECX, len ;initializam ECX cu lungimea sirului
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
            
        
        push    dword 0      
        call    [exit]      
