;Se dau cuvintele A si B. Se cere dublucuvantul C:
;bitii 0-2 ai lui C au valoarea 0
;bitii 3-5 ai lui C au valoarea 1
;bitii 6-9 ai lui C coincid cu bitii 11-14 ai lui A
;bitii 10-15 ai lui C coincid cu bitii 1-6 ai lui B
;bitii 16-31 ai lui C au valoarea 1
bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    A dw 0111011101010111b
    B dw 1001101110111110b
    C dw 0

; our code starts here
segment code use32 class=code
    start:
        ;bitii 0-2 ai lui C au valoarea 0
        mov EBX, 0
        ;bitii 3-5 ai lui C au valoarea 1
        or EBX, 00000000000000000000000000111000b
        ;bitii 6-9 ai lui C coincid cu bitii 11-14 ai lui A
        mov AX, [A]; 
        and AX, 0111100000000000b
        cwde
        ror EAX, 5
        
        or  EBX, EAX
        ;bitii 10-15 ai lui C coincid cu bitii 1-6 ai lui B
        
        mov AX, [B]; AX = B
        and AX, 0000000001111110b
        cwde
        rol EAX, 9
        or EBX, EAX
        or EBX, 11111111111111110000000000000000b
        
       
        push    dword 0      
        call    [exit]      
