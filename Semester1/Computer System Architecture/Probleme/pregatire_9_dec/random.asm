bits 32


global start        


extern exit, printf             
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    ; ...
    a db 1, 1, 2, 3, 4, 5
; our code starts here
segment code use32 class=code
    start:
        mov eax, [a]
        mov eax, [a + 1]
        mov eax, [a + 2]
        
        ;mov eax, ecx
        ;add eax, esp
        ;add eax, 1
        mov al, -2
        sbb al, 2
        push    dword 0      
        call    [exit]      
