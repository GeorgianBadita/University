bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
       
       mov AX, 65535
       mov BL, 10
       div BL ;Execution error, nu incape in AL rezultatul
       
        push    dword 0      
        call    [exit]      
