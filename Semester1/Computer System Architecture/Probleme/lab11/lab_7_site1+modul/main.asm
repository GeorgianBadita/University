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


extern exit, printf
extern sortare  
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    s dd 12345678h,5bcfh,45327h,1798dfeh,0f112233h
    len equ ($ - s)/3 + 1 ;initializam lungimea sirului
    rez times len db 0 ;initializam rezultatul
    format db "%x "
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
        
        push DWORD len
        push DWORD rez
        call sortare
        
        mov ECX, len
        mov EAX, 0
        afiseaza:
            push ECX
            push EAX
            push DWORD [rez + EAX]
            push DWORD format
            call [printf]
            add ESP, 4*2
            pop EAX
            inc EAX
            pop ECX
        loop afiseaza
            
        push    dword 0      
        call    [exit]      
