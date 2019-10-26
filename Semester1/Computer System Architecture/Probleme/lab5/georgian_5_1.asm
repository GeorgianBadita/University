;Se citesc doua numere in baza 10 a si b de la tastatura, sa se afiseze produsul lor

bits 32


global start        


extern exit, scanf, printf              
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dw 0
    b dw 0
    rez dd 0
    format_scan db "%d", 0
    format_print db "Rezultatul este: %d", 10, 0

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
        
        mov AX, [a] ;AX = a
        imul WORD [b] ;DX:AX = a * b
        
        push DX ;punem DX pe stiva
        push AX ;punem AX pe stiva
        pop EAX ;Extragem DX:AX in EAX
        
        mov [rez], EAX ;punem rezultatul in variabila rez
        
        push DWORD [rez] ;punem rez pe stiva
        push DWORD format_print ;punem formatul pe stiva
        call [printf] ;apelam functia printf
        add ESP, 4*2 ;golim stiva 
        push    dword 0      
        call    [exit]      
 