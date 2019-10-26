;lab13
;se citeste de la tastatura un nume de fisier si un nume(<100)
;sa se afiseze de cate ori apare numele in fisier
bits 32
 
global start        
 
extern exit,fseek,scanf,fopen,fclose,printf,fread        
import exit msvcrt.dll  
import fseek msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll
segment data use32 class=data
    nume_f          times 20 db 0
    desc_f          dd          -1
    l               equ         100
    nume            times l db  0
    buffer          times l db  0
    x               db          0
    format_citire   db          "%s %s",0
    eroare          db          "Eroare fisier!",0
    mod_acces       db          "r",0
    diferenta       dd          0
    lungime_nume    dd          0
    cat_am_citit    dd          0
    contor          dd          0
    format_afisare  db          "Nr. aparitii: %u",0
   
segment code use32 class=code
    start:
       
        push    dword nume
        push    dword nume_f
        push    dword format_citire
        call    [scanf]
        add     esp,     4*3
       
        push    dword mod_acces
        push    dword nume_f
        call    [fopen]
       
        cmp     eax,    0
        je      .eroare_f
       
        mov     [desc_f],   eax
       
        mov     ecx,    0
       
        .lungime:
            cmp     byte [nume+ecx],    0
            je      .gata_lungime
            inc     ecx
        jmp .lungime
        .gata_lungime:
       
        mov     [lungime_nume], ecx
       
       
        .citeste:
            push    dword [desc_f]
            push    dword l
            push    dword 1
            push    dword buffer
            call    [fread]
            add     esp,    4*4
            mov     [cat_am_citit], eax
           
            ;daca citim mai putine caract decat lungimea cuv, am terminat
            cmp     eax,    [lungime_nume]
            jb      .gata_citeste
           
            mov     ecx,    eax
            sub     ecx,    [lungime_nume]
            inc     ecx ;de cate ori verificam
           
            mov     ebx,    0; de pe ce pozitie incepem verificarea in buffer
           
            .repeta:
                mov     esi,    buffer
                add     esi,    ebx;esi: de unde incepem in buffer
                mov     edi,    nume;edi: nume
               
                push    ecx
                mov     ecx,    [lungime_nume]
               
                ;verificam daca octetii coincid
                .compara:
                    cmpsb
                    jne     .gata_compara
                loop .compara
                .gata_compara:
               
                cmp     ecx,    0
                jne     .nuebun
                inc     dword [contor]
               
                .nuebun:
                pop     ecx
                inc ebx
           
            loop .repeta
           
            ;daca nu mai putem citi, am terminat
            cmp     dword [cat_am_citit],   l
            jne     .gata_citeste
           
            ;daca mai putem citi, ducem inapoi pointerul in fisier cu -(lungime_nume-1)
            mov     eax,    [lungime_nume]
            dec     eax
            neg     eax
           
            push    dword 1; 1 = SEEK_CUR
            push    eax
            push    dword [desc_f]
            call    [fseek]
            add     esp,    4*3
           
        jmp  .citeste
        .gata_citeste:
       
        ;afisare
        push    dword [contor]
        push    dword format_afisare
        call    [printf]
        add     esp,    4*2
       
        push    dword 0      
        call    [exit]      
   
   
    .eroare_f:
       
        push    dword eroare
        call    [printf]
        add     esp,    4
       
        push    dword 0      
        call    [exit]