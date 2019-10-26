;Badita Marin-Georgian, grupa 211, 10/24/2017, laboratorul 4, problema 5, op pe biti


;Se dau octetii A si B. Sa se obtina dublucuvantul C:
;bitii 16-31 ai lui C sunt 1
;bitii 0-3 ai lui C coincid cu bitii 3-6 ai lui B
;bitii 4-7 ai lui C au valoarea 0
;bitii 8-10 ai lui C au valoarea 110
;bitii 11-15 ai lui C coincid cu bitii 0-4 ai lui A

bits 32

    a db 01010111b
    b db 10111110b
    c dd 0

global start        
   
extern exit              
import exit msvcrt.dll
segment data use32 class=data

; our code starts here
segment code use32 class=code
    start:
       
        mov EBX, 0 ;in EBX vom calcula rezultatul
        
        mov EAX, [c]
        or EAX, 11111111111111110000000000000000b ;Schimbam bitii 16 - 31 ai lui C in 1
        
        mov EBX, EAX ;punem in BX rezultatul de pana acum
        
        mov AL, [b]; Al = b
        and AL, 01111000b ;izolam bitii 3 - 6 ai lui b
        mov CL, 3 ;CL = 3
        ror AL, CL ;rotim 3 pozitii spre dreapta
        cbw ;convert AL -> AX
        cwd ;convert AX -> EAX
        or EBX, EAX ;punem in EBX rezultatul
        
        and EBX, 11111111111111111111111100001111b ;facem bitii 4-7 din rezultat sa fie 0
        
        mov EAX, 00000000000000000000011000000000b ;punem in EAX masca
        or EBX, EAX ;punem in bitii 8 - 11 valoarea 110
        
        mov EAX, 0
        mov AL, [a] ;AL = a
        and AL, 00010111b ;izolam bitii 0 - 4 ai lui a
        cbw ;convertim AL -> AX
        cwd ;convertim AX -> EAX
        mov CL, 11 ;CL = 11
        rol EAX, CL ;deplasam bitii 11 pozitii spre stanga
        or EBX, EAX ;punem bitii in rezultat
        
        mov [c], EBX ;punem in C rezultatul
        push    dword 0      
        call    [exit]      
