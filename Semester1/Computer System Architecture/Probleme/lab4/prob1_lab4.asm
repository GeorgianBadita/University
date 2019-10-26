;Se dau cuvintele A si B. Sa se obtina dublucuvantul C:
;bitii 0-4 ai lui C coincid cu bitii 11-15 ai lui A
;bitii 5-11 ai lui C au valoarea 1
;bitii 12-15 ai lui C coincid cu bitii 8-11 ai lui B
;bitii 16-31 ai lui C coincid cu bitii lui A

bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    
    A dw 0111011101010111b
    B dw 
    
    C dd 0
; our code starts here
segment code use32 class=code
    start:
        ;Bitii 0 - 4 ai lui C sunt bitii 11-15 ai lui A
        
        mov EBX, 0
        mov AX, [A] ;AX = A
        
        and AX, 1111100000000000b ;Izolam bitii 11-15 ai lui A
        
        mov CL, 11 ;CL = 10
        
        ror AX, CL ;rotim 11 pozitii spre dreapta
        
        cwde
        or EBX, EAX ;punem bitii in rezultat
        
        or EBX, 00000000000000000000111111100000b ;setam bitii 5-11 ai lui C
        
        
        mov AX, [B]
        and AX, 0000111100000000b ;Izolez bitii 8 - 11 ai lui B
        
        mov CL, 4 ;CL = 4
        rol AX, CL ;rotim 4 pozitii spre dreapta
        
        or EBX, EAX ;punem bitii in rezultat
        
        ;bitii 16 - 31 coincid cu bitii lui A
        mov AX, [A]
        cwde
        
        rol EAX, 16
        
        or EBX, EAX
        
        mov [C], EBX
        
        push    dword 0      
        call    [exit]      