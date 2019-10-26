;Se da cuvantul A. Sa se obtina numarul intreg n reprezentat de bitii 0-2 ai lui A. Sa se obtina apoi in B cuvântul rezultat prin rotirea spre ;dreapta (fara carry) a lui A cu n pozitii. Sa se obtina dublucuvantul C:
;bitii 8-15 ai lui C sunt 0
;bitii 16-23 ai lui C coincid cu bitii lui 2-9 ai lui B
;bitii 24-31 ai lui C coincid cu bitii lui 7-14 ai lui A
;bitii 0-7 ai lui C sunt 1
bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data

    A dw 0111011101010111b
         ;1010111011101110
    B dw 0
    C dd 0
    n db 0
; our code starts here
segment code use32 class=code
    start:
    mov AX, [A] ;AX = A 
   
    and AX, 0000000000000111b
    mov [n], AX
       
    mov CL, [n] ;CL = n
    mov AX, [A] ;AX = A
    ror AX, CL ;rotim cu n pozitii la stanga fara carry
    mov [B], AX ;B = A rotit la stanga cu n pozitii
    
    mov EBX, 0
    mov EAX, 0
    mov AX, [B]; AX = B
    and AX, 0000001111111100b ;izolam bitii 2-9 ai lui B
    cwde ;AX -> EAX
    rol EAX, 14
    or EBX, EAX ;bitii 16-23 ai lui EBX coincid cu bitii 2 - 9 ai lui A
    
    mov AX, [A]
    and AX, 0111111110000000b ;izolam bitii 7 - 14 ai lui A
    cwde ;AX -> EAX
    rol EAX, 17 ;rotim la stanga cu 17 biti
    or EBX, EAX ;punem bitii in rezultat
    
    xor EBX, 00000000000000000000000011111111b ;facem biti  0 - 7 ai lui EBX 1
    
    mov [C], EBX ;punem in C rezultatul
             
        push    dword 0      
        call    [exit]      
