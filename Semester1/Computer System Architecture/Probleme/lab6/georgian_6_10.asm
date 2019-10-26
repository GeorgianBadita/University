;Se da un sir de octeti S. Sa se obtina in sirul D multimea elementelor din S. 

bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    s db 1, 4, 2, 4, 8, 2, 1, 1
    l equ $ - s
    d resb l

; our code starts here
segment code use32 class=code
    start:
       
        push    dword 0      
        call    [exit]      
