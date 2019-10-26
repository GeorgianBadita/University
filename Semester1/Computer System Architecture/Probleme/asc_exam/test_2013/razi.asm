bits 32 


global start        


extern exit, printf        
import exit msvcrt.dll    
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    a dd $-a
    fmt db "%d", 0
segment code use32 class=code
    start:
        
      mov AH, -126
      mov AL, 3
      cmp AH, AL
        
        push    dword 0      
        call    [exit]       
