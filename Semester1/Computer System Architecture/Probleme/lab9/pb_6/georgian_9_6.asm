bits 32
global start        


extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll    
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    nume_fisier db "input.txt", 0          ;numele fisierului folosit
    mod_acces   db "r+", 0                 ;modul de acces
    len equ 1
    buffer times len db 0               ;rezervam spatiu pentru citire
    descriptor_fis dd -1                ;descriptorul de fisier
    freq times 10 db 0
    print_f db "%d", 10, 13,  0
    max_pos db 0
    max db 0
    test_ db -1
   
segment code use32 class=code
    start:
        
        push DWORD mod_acces
        push DWORD nume_fisier
        call [fopen]
        add ESP, 4*2
        
        cmp EAX, 0
        je final
        
        mov [descriptor_fis], EAX
        
        bucla:
           push DWORD [descriptor_fis]
           push DWORD len
           push DWORD 1
           push DWORD buffer
           call [fread]
           add ESP, 4*4
           
           cmp EAX, 0
           je cleanup
           
           mov AL, [buffer]
           
           sub AL, '0'
           mov AH, 0
           
           cmp AL, AH
           jge check_9
           jmp bucla
           
           check_9:
               mov AH, 9
               cmp AL, AH
               jnge is_dig 
               jmp bucla
               is_dig:
                   cbw
                   cwde
                   mov ECX, [freq + EAX]
                   inc ECX
                   mov [freq + EAX], ECX
        
        jmp bucla
                
        
        cleanup:
            push DWORD [descriptor_fis]
            call [fclose]
            add ESP, 4*1
            
        
        mov EBX, 1
        mov [max_pos], DWORD 0
        mov CL, [freq]
        mov [max], CL
        
        get_max:
            mov AL, [freq + EBX]
            mov CL, [max]
            cmp AL, CL
            jg bigger
            inc EBX
            mov EDX, 10
            cmp EBX, EDX
            je afisare
            jng get_max
            bigger:
                mov [max_pos], EBX
                mov [max], AL
                inc EBX
                jmp get_max
                
        afisare:
            mov EAX, 0
            mov EAX, [max]
            push DWORD EAX
            push DWORD print_f
            call [printf]
            add ESP, 4*2
            
            mov EAX, 0
            mov EAX, [max_pos]
            
            push DWORD [max_pos]
            push DWORD print_f
            call [printf]
            add ESP, 4*2
            
            
        
        final:
        
        
        push    dword 0      
        call    [exit]       
