bits 32 


global start        


extern exit, printf, fread, fopen, fclose               
import exit msvcrt.dll    
import printf msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    ; ...
    nume_fisier db "input.txt", 0
    mod_access db "r+", 0
    descriptor_fis dd -1
    len equ 1
    text times len db 0

    frq times 27  db 0
    big_L db "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    max_p db 0, 0
    nr_ap db 0, 0
    format_print db "%c", 0
    format_print1 db "%d", 0
segment code use32 class=code
    start:
        
        mov EBX, 0
        mov EAX, 0
        push DWORD mod_access
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
            push DWORD text
            call [fread]
            add ESP, 4*4
            
            cmp EAX, 0
            je cleanup
            
            mov AL, [text]
            cmp AL, 41H
            jge test_Z
            jmp base
            test_Z:
                cmp AL, 5Ah
                jnge is_big
                jmp base
                is_big:
                    sub AL, 'A'
                    ;sub AL, '0'
                    mov AH, 0
                    mov EBX, [frq + EAX]
                    inc EBX
                    mov [frq + EAX], EBX
                    jmp base
                    
        base:
        jmp bucla
        
        cleanup:
            push DWORD [descriptor_fis]
            call [fclose]
            add ESP, 4*1
            
            mov AL, [frq]
            mov [nr_ap], AL
            mov ECX, 26
            mov EBX, 1
            get_max:
                mov AL, [frq + EBX]
                mov AH, [nr_ap]
                cmp AL, AH
                jg mai_mare
                jmp base1
                mai_mare:
                    mov [max_p], EBX
                    mov [nr_ap], AL
            base1:    
            inc EBX
            loop get_max
            
            mov AL, [max_p]
            mov EBX, big_L
            xlat
            cbw 
            cwde
            push DWORD EAX
            push DWORD format_print
            call [printf]
            add ESP, 4*2
            
            mov AL, [nr_ap]
            cbw 
            cwde
            push DWORD EAX
            push DWORD format_print1
            call [printf]
            add ESP, 4*2
            
        final:
        
        push    dword 0      
        call    [exit]       
