bits 32 


global start        


extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    ; ...
    a db -2, 0, 1
    b dd 2
    c dw 12345678h
    ;d db a
    e dd b
    f dw c


segment code use32 class=code
    start:
        
        mov EAX, a
        mov BX, a+2
        lea ECX, [c]
        mov EAX, [ECX]
        inc EBX
        ;mov EDX:EAX, DS:[EBX]
        ;mov DX, DS:[EBX]
        push    dword 0      
        call    [exit]       
