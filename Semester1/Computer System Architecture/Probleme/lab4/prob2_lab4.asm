;Se dau cuvintele A si B. Se cere dublucuvantul C:
;bitii 0-3 ai lui C coincid cu bitii 5-8 ai lui B
;bitii 4-8 ai lui C coincid cu bitii 0-4 ai lui A
;bitii 9-15 ai lui C coincid cu bitii 6-12 ai lui A
;bitii 16-31 ai lui C coincid cu bitii lui B

bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    A dw 0111011101010111b
    B dw 1001101110111110b
    C dd 0

; our code starts here
segment code use32 class=code
    start:
        ;bitii 0-3 ai lui C coincid cu bitii 5-8 ai lui B
        mov EBX, 0 ;EBX = 0
        mov AX, [B]
        and AX, 0000000111100000b ;Izolam bitii 5 - 8
        ror AX, 5 ;rotim cu 5 pozitii la dreapta
        
        ;bitii 4-8 ai lui C coincid cu bitii 0-4 ai lui A
        
        cwde ;AX->EAX
        
        or EBX, EAX
        
        mov AX, [A]
        and AX, 0000000000011111b
        
        rol AX, 4 ;rotim 4 pozitii la stanga
        cwde
        or EBX, EAX
        
        ;bitii 9-15 ai lui C coincid cu bitii 6-12 ai lui A
        
        mov AX, [A]; AX = A
        and AX, 0001111111000000b
        rol AX, 3
        or EBX, EAX
        
        mov AX, [B]
        cwde
        rol EAX, 16
        or EBX, EAX
        push    dword 0      
        call    [exit]      
