

bits 32


global start        


extern exit, printf        
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    a dw -8
    b dw -2
    format_print db "%d * %d = %d", 0 ;formatul de afisare

; our code starts here
segment code use32 class=code
    start:
        mov AX, [a] ;punem in AX a
        imul WORD [b] ;inmultim cu word-ul b si avem in DX:AX a*b
        push DX; punem DX pe stiva
        push AX; punem AX pe stiva
        pop ECX ;ECX = DX:AX extragem de pe stiva
        
        mov AX, [a]
        cwde ;convertim cu semn AX la EAX
        mov EBX, EAX; punem a cu semn in EBX
        mov AX, [b] 
        cwde ;convertim cu semn b si il lasam in EAX
        
        push DWORD ECX ;punem rezultatul pe stiva
        push DWORD EAX ;punem b pe stiva
        push DWORD EBX ;punem a pe stiva
        push DWORD format_print
        call [printf] ;apelam functia printf
        add ESP, 4*4 ;eliberam stiva de parameterii
        push    dword 0      
        call    [exit]      
