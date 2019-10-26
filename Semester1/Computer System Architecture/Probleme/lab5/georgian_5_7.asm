;Se dau doua numere natural a si b (a: dword, b: word, definite in segmentul de date). Sa se calculeze a/b si sa se afiseze restul impartirii in urmatorul format:
;"<a>/<b> = <cat>"
;Exemplu: pentru a = 23 si b = 5 se va afisa: "23 mod 5 = 3"
;Valorile vor fi afisate in format decimal (baza 10) cu semn.

bits 32


global start        


extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    a dd 0
    b dw 0
    rez dw 3
    format_scan db "%d", 0
    format_printf db "%d mod %d = %d", 0
    
; our code starts here
segment code use32 class=code
    start: 
        
        push DWORD a
        push DWORD format_scan
        call [scanf]
        add ESP, 4*2
        
        push DWORD b
        push DWORD format_scan
        call [scanf]
        add ESP, 4*2
        
        
        mov EAX, [a]
        cdq ;EAX:EDX = a
        
        mov ECX, EDX ;ECX = EDX
        mov EBX, EAX ;EBX = EAX
        
        mov AX, [b] ;pun b in AX
        cwde; AX->EAX
        
        mov ESI, EAX ;ESI = EAX
        
        mov EDX, ECX ;restauram numarul
        mov EAX, EBX ;restauram numarul
        
        idiv ESI ;impartim EAX:EDX la ESI
        
        
        push DWORD EDX
        push DWORD [b]
        push DWORD [a]
        push DWORD format_printf
        call [printf]
        add ESP, 4*4
        push    dword 0      
        call    [exit]      
