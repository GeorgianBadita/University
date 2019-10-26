;Se da un nume de fisier, si un text cu spatii, se cere sa se afiseze pe ecran cuvintele din text care au numar par de litere

bits 32 


global start        


extern exit, fopen, fclose, fread, scanf, printf
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    len equ 100
    len_fis equ 20
    descriptor_fis dd -1
    buffer times len+1 db 0
    mod_access db "r+", 0
    nume_fisier times len_fis+1 db 0
    mod_citire db "%s", 0
    mod_print db "%s", 10, 13, 0
    eroare_ db "Eroare la deschiderea fisierului", 0
    rez times len_fis+1 db 0
    
segment code use32 class=code
    start:
        
        push DWORD nume_fisier
        push DWORD mod_citire
        call [scanf]
        add ESP, 4*2
        
        
        push DWORD mod_access
        push DWORD nume_fisier
        call [fopen]
        add ESP, 4*2
        
        cmp EAX, 0
        je print_err
        
        mov [descriptor_fis], EAX
        mov EDI, rez
        
        bucla:
            pushad
            push DWORD [descriptor_fis]
            push DWORD 1
            push DWORD 1
            push DWORD buffer
            call [fread]
            add ESP, 4*4
            cmp EAX, 0
            je clean_up
            popad
            mov AL, [buffer]
            cmp AL, ' '
            je print_cuv
            stosb
            inc DL
            jmp again
            print_cuv:
                mov AX, 0
                mov AL, DL
                cbw
                mov DL, 2
                div DL
                cmp AH, 0
                jne jump
                pushad
                push DWORD rez
                push DWORD mod_print
                call [printf]
                add ESP, 4*2 
                popad
                jump:
                mov EAX, 0
                mov EDI, rez
                clear:
                    mov BL, [EDI + EAX]
                    mov [EDI + EAX], BYTE 0
                    inc EAX
                    cmp BL, 0
                    jne clear
            again:
            
        jmp bucla
        
        clean_up:
            push DWORD [descriptor_fis]
            call [fclose]
            add ESP, 4*1
            
        jmp final
        print_err:
            push DWORD eroare_
            call [printf]
            add ESP, 4*1
        final:
        push    dword 0      
        call    [exit]       
