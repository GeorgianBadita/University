bits 32 


global start        


extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    ; ...
    

segment code use32 class=code
    start:
        
        mov AL, -7
        mov BL, -6
        add AL, BL
        
        
        
        push    dword 0      
        call    [exit]       
