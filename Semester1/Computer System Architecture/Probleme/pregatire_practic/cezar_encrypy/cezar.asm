bits 32 


global start        


extern exit, fopen, fclose, fprintf, fread, scanf, printf               
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll


segment data use32 class=data
    ; ...
    nume_fisier db "fisier.txt", 0
    mod_access db "r+", 0
    descriptor_fis dd -1
    mod_read db "%d", 0
    mesaj db "Eroare la deschiderea fisierului", 0
    len equ 100
    buffer times len+1 db 0
    rez times len+1 db 0
    fmt db "%s", 0
    n db 0


segment code use32 class=code
    start:
        push DWORD n
        push DWORD mod_read
        call [scanf]
        add ESP, 4*2
        
        
        push DWORD mod_access
        push DWORD nume_fisier
        call [fopen]
        add ESP, 4*2
        
        cmp EAX, 0
        je err_
        
        mov [descriptor_fis], EAX
        
        mov AX, 0
        mov AL, [n]
        mov CL, 26
        div CL
        mov [n], AH
        mov EDI, rez
        bucla:
            push DWORD [descriptor_fis]
            push DWORD len
            push DWORD 1
            push DWORD buffer
            call [fread]
            add ESP, 4*4
            cmp EAX, 0
            je clean_up
            mov ESI, buffer
            mov ECX, len
            change:
                lodsb
                cmp AL, ' '
                je prt
                add AL, [n]
                cmp AL, 'z'
                ja substract
                jmp next
                substract:
                    sub AL, 26
                next:
                stosb
            loop change
            prt:
            push DWORD rez
            push DWORD fmt
            call [printf]
            add ESP, 4*2
            
        jmp bucla
        
        
        clean_up:
            push DWORD [descriptor_fis]
            call [fclose]
            add ESP, 4*1
        
        jmp final
        err_:
        push DWORD mesaj
        call [printf]
        add ESP, 4*1
        final:
        
        
        push    dword 0      
        call    [exit]       
