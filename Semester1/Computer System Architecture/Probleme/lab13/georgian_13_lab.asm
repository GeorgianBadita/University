;Se da un nume de fisier si un nume
;Spuneti de cate ori apare acel nume in fisier
bits 32 


global start        


extern exit, fopen, fprintf, fread, printf, fclose        
import exit msvcrt.dll    
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fread  msvcrt.dll
import printf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    ; ...
    nume db "Alexandra", 0
    len_nume equ $-nume
    len equ 100
    nume_fisier db "fisier.txt", 0
    mod_access db "r+", 0
    descriptor_fis dd -1
    buffer times len + 1 db 0
    eroare db "Eroare la deschiderea fisierului",0
    fmt_print db "%s", 10, 13, 0
    cnt dd 0
    format_sol db "%d", 0
    
segment code use32 class=code
    start:
        
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
            push DWORD buffer
            call [fread]
            add ESP, 4*4
            
            cmp EAX, 0
            je cleanUp
            
            mov EDI, nume
            mov ECX, len
            
            check_ap:
                mov EAX, len
                sub EAX, ECX
                mov ESI, buffer
                add ESI, EAX
                mov BX, len_nume -1
                mov EDI, nume
                verif:
                    lodsb
                    scasb
                    jne stop
                    dec BX
                    cmp BX, 0
                    je incr
                    jmp verif
            incr:
                mov EDX, [cnt]
                inc EDX
                mov [cnt], EDX
            stop:
            loop check_ap
        jmp bucla
        
        cleanUp:
            push DWORD [descriptor_fis]
            call [fclose]
            add ESP, 4*1
            
            mov EAX, [cnt]
            push DWORD EAX
            push DWORD format_sol
            call [printf]
            add ESP, 4*2
        push    dword 0      
        call    [exit]   
        
        final:
        
        push DWORD eroare
        call [printf]
        add ESP, 4*1
        
        push    dword 0      
        call    [exit]   
        
            
