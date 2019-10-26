bits 32


global start        


extern exit , printf, scanf             
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
segment data use32 class=data
    ; ...
    n dd  0 ;alocare de memorie fara asignare
   format_scan db "%d", 0
   format_printf db "%d",10, 13, 0

; our code starts here
segment code use32 class=code
    start:
        push dword n
        push dword format_scan
        call [scanf]
        add ESP, 4*2
        ;afisez n
        push DWORD [n] ;pentru afisare punem valoarea
        push format_printf
        call [printf]
        call [printf]
        
        add ESP, 4*2
        push    dword 0      
        call    [exit]      
