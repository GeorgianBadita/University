;se citeste de la tatatura un nume de fisier, un car special s si un nr n, fisierul are cuv separate prin spatii
;sa se scrie in output.txt primele n caractere din fiecare cuvant, daca nr car < n cuvantul se va completa cu car special s
;input.txt mere +, n = 6 (mere++)
bits 32 


global start        


extern exit, fopen, fclose, scanf, fprintf, fread, printf           
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    len equ 100
    len_fis equ 20
    descriptor_fis1 dd -1
    nume_fisier times len_fis db 0
    mod_access db "r", 0
    mod_access1 db "w", 0
    fmt_read_str db "%s", 0
    fmt_read_char db "%s", 0
    fmt_read_int db "%d", 0
    msg_err db "Eroare la deschiderea fisierului", 0
    chr db 0
    n db 0
    buffer db 0
    cuv times len_fis db 0
    descriptor_fis2 dd -1
    nume_fisier2 db "output.txt", 0


segment code use32 class=code
    start:
         
         push DWORD nume_fisier
         push DWORD fmt_read_str
         call [scanf]
         add ESP, 4*2
        
         
         push DWORD chr
         push DWORD fmt_read_char
         call [scanf]
         add ESP, 4*2
         
         
         push DWORD n
         push DWORD fmt_read_int
         call [scanf]
         add ESP, 4*2
         
        
         push DWORD mod_access
         push DWORD nume_fisier
         call [fopen]
         add ESP, 4*2
         
         cmp EAX, 0
         je err_
         
         mov [descriptor_fis1], EAX
         mov EDI, cuv
         
         push DWORD mod_access1
         push DWORD nume_fisier2
         call [fopen]
         add ESP, 4*2
         mov [descriptor_fis2], EAX
         
         bucla:
            push DWORD [descriptor_fis1]
            push DWORD 1
            push DWORD 1
            push DWORD buffer
            call [fread]
            add ESP, 4*4
            cmp EAX, 0
            je clean_up
            
            mov AL, [buffer]
            cmp AL, ' '
            je prt_cuv
            stosb
            jmp again
            prt_cuv:
                
                mov EAX, 0
                mov AL, [n]
                mov [cuv + EAX], BYTE 0
                mov ESI, cuv
                mov EAX, 0
                mov AL, [n]
                mov ECX, EAX
                mov EAX, 0
                repet:
                    mov BL, [ESI + EAX]
                    cmp BL, 0
                    je put_special
                    jmp to_loop
                    put_special:
                        mov BH, [chr]
                        mov [ESI + EAX], BH
                    to_loop:
                    inc EAX
                loop repet
                mov EAX, 0
                mov AL, [n]
                mov [cuv + EAX], BYTE 20h
                add EAX, 1
                mov [cuv + EAX], BYTE 0
                push DWORD cuv
                push DWORD  [descriptor_fis2]
                call [fprintf]
                add ESP, 4*2
                mov EBX, 0
                mov EDI, cuv
                clear:
                    mov AL, [cuv + EBX]
                    mov [cuv + EBX], BYTE 0
                    inc EBX
                    cmp AL, 0
                    jne clear
               clear_spaces:
                push DWORD [descriptor_fis1]
                push DWORD 1
                push DWORD 1
                push DWORD buffer
                call [fread]
                add ESP, 4*4
                cmp EAX, 0
                je clean_up
                mov AL, [buffer]
                cmp AL, ' '
                jne do_this
                jmp clear_spaces
                do_this:
                    stosb
                    jmp again
                
            
         again:   
         jmp bucla
         
         clean_up:
            push DWORD [descriptor_fis2]
            call [fclose]
            add ESP, 4*1

            
            push DWORD [descriptor_fis1]
            call [fclose]
            add ESP, 4*1
         
         jmp final
         err_:
         push DWORD msg_err
         call [printf]
         add ESP, 4*1
         final:
        
        push    dword 0      
        call    [exit]       
