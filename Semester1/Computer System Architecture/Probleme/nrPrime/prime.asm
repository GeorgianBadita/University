bits 32


global start        


extern exit, scanf, printf              
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    n dw 0
    divzori dw 0
    format_scan db "%d"

; our code starts here
segment code use32 class=code
    start:
        push DWORD n ;punem parametrul n pe stiva
        push DWORD format_scan ;punem formatul de citire pe stiva
        call [scanf] ;apelam functia scanf
        add ESP, 4*2 ;eliberam stiva
        mov AX, [n] ;punem n in AX
        cwde ;convertim la EAX
        mov ECX, EAX ;punem EAX in ECX
        mov EAX, 0 ;punem 0 in EAX
        mov AX, [n]; punem n in AX
   
        
        jecxz finalPrg
        repeta:
            loop repeta
        finalPrg:
        push    dword 0      
        call    [exit]      
