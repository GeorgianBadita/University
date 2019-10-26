;Se da un numar natural negativ a (a: dword). Sa se afiseze valoarea lui in baza 10 si in baza 16, in urmatorul format: "a = <base_10> (baza 10), a = <base_16> (baza 16)"
bits 32


global start        


extern exit, printf 
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
        a dd -3
        format_print dw "a = %d , a = %x", 0
; our code starts here
segment code use32 class=code
    start:
        push DWORD [a]
        push DWORD [a]
        push DWORD format_print
        call [printf]
        
        add ESP, 4*3
        push    dword 0      
        call    [exit]      
