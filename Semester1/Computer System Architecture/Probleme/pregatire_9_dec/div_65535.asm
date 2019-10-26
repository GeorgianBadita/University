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
       cwd
       mov BX, 7
       div BX ;INTEGER_OVERFLOW cwd - conversie cu semn, div imaprtire fara semn!
       
       
       push    dword 0      
       call    [exit]      
