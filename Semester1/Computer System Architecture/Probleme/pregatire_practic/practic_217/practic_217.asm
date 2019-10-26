bits 32 

global start        

; declare external functions needed by our program
extern exit, fopen, fread, fclose, printf, scanf
import exit msvcrt.dll  
import fopen msvcrt.dll  
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    nume_fisier times 20 db 0 
    mod_acces db "r", 0         
                                 
    len equ 100                              
    text times (len+1) db 20h    
    descriptor_fis dd -1         
    
    mod_citire db "%s", 0  
    cuvant times 20 db 0
    par db 0
    fmt db "%s", 10, 13, 0

; our code starts here
segment code use32 class=code
    start:
       
        
        push dword nume_fisier
        push dword mod_citire
        call [scanf]
        add ESP, 4*2
        
        
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2                ; eliberam parametrii de pe stiva

        mov [descriptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final
        
        ; citim textul in fisierul deschis folosind functia fread
        ; eax = fread(text, 1, len, descriptor_fis)
        push dword [descriptor_fis]
        push dword len
        push dword 1
        push dword text        
        call [fread]
        add esp, 4*4                 ; dupa apelul functiei fread EAX contine numarul de caractere citite din fisier
        
        
        mov ESI, text
        mov EDI, cuvant
        mov ECX, EAX
        inc ECX
        mov [par], BYTE 0
        repeta:
            lodsb
            stosb
            cmp AL, 20h
            je end_cuv
            jmp again
            end_cuv:
                mov DL, [par]
                cmp DL, 0
                je do_this
                jmp do_that
                do_this:
                mov DL, 1
                mov [par], DL
                pushad
                push DWORD cuvant
                push DWORD fmt
                call [printf]
                add ESP, 4*2
                popad
                jmp to_clear
                do_that:
                    mov DL, 0
                    mov [par], DL
                to_clear:
                mov EBX, 0
                clear:
                    mov [cuvant + EBX], BYTE 0
                    inc EBX
                    cmp EBX, 20
                    je next
                    jmp clear
                next:
                cut_spaces:
                    lodsb 
                    cmp AL, 20h
                    je cut_spaces
                    dec ESI
                mov EDI, cuvant
            again:
        loop repeta
        
 
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
      final:
        
        ; exit(0)
        push    dword 0      
        call    [exit]       