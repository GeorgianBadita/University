bits 32 


global start        


extern exit, fopen, fclose, fprintf, printf   
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    text db "ACESTA ESTE UN text perfectr !!@%!!~~PeNTRU PB MEA", 0
    len equ $ - text
    rez times len db 0
    mod_acces db "w", 0
    nume_fisier db "input.txt", 0
    format_print db "%s", 0
    descriptor_fisier dd -1

segment code use32 class=code
    start:
        mov ECX, len            ;punem valoarea lungimii sirului in ECX
        mov ESI, text           ;punem adresa de inceput a textului in ESI
        mov EDI, rez            ;punem adresa de inceput a rezultatului in EDI
        repeta:
            lodsb               ;punem in AL, caracterul curent
            cmp AL, 41h
            jge cmp_Z
            jmp base
            cmp_Z:
                cmp AL, 5Ah
                jnge is_big_lett
                jmp base
                is_big_lett:
                    add AL, 32
                    jmp base
            base:
                stosb
                loop repeta
        
        push DWORD mod_acces
        push DWORD nume_fisier
        call [fopen]
        add ESP, 4*2
        
        cmp EAX, 0
        je final
         
         mov [descriptor_fisier], EAX
         
         push DWORD rez
         push DWORD [descriptor_fisier]
         call [fprintf]
         add ESP, 4*2
         
         push DWORD [descriptor_fisier]
         call [fclose]
         add ESP, 4*1
         
        final:
        push    dword 0      
        call    [exit]       
