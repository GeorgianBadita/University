;Dandu-se un sir de cuvinte sa se obtina sirul (de octeti) cifrelor in baza zece ale fiecarui cuvant din acest sir.

bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    sir dw 12345, 20778, 4596 
    len equ ($ - sir)/2
    len_1 equ ($ - sir)*3
    rez times len_1 db 0
    n db 10
; our code starts here
segment code use32 class=code
    start:
       mov ECX, len
       mov ESI, sir
       mov EDX, 0
       
       repeta:
        lodsw
        ;mov AX, [sir + EDX]
        push ECX
        mov ECX, 5
        put_digits:
            div BYTE [n]
            mov [rez + EDX], AH
            inc EDX
            cbw
            cmp AX, 0
            je stop_loop
            loop put_digits
        
        stop_loop:
            pop ECX
            loop repeta
        
        
        push    dword 0      
        call    [exit]      
