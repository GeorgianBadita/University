;Se dau doua siruri de caractere ordonate alfabetic s1 si s2. Sa se construiasca prin interclasare sirul ordonat s3 care sa contina toate elementele din s1 si s2.
bits 32


global start        


extern exit         
import exit msvcrt.dll
segment data use32 class=data
    ; ...
    s1 db 'aceg' ;primul sir in ordine alfabetica
    len_s1 equ ($ - s1) ;lungimea primului sir
    s2 db 'bdfhij' ;al 2-lea sir in ordine alfabetica
    len_s2 equ ($ - s2) ;lungimea celui de-al 2-lea sir
    rez times len_s1 + len_s2 db 0
    str_reminder dd 0
; our code starts here
segment code use32 class=code
    start:
        cld ;setam direction flag la 0 pentru parcurgere stanga-dreapta
        mov ESI, s1 ;punem s1 in sursa
        mov EDI, s2 ;punem s2 in destinatie
       
        mov ECX, len_s1 + len_s2 ;punem maximul de parcurgeri in ECX, adica suma lungimilor sirului
        mov EBX, 0 ;contor care ne va arata cate elemente din sirul 2 am parcurs
        mov EAX, 0 ;contor care ne va arata cate elemente din sirul 1 am parcurs
        mov EDX, 0 ;contorul pentru pozitia curenta din sirul rezultat
        repeta:
            cmpsb ;comparam elementele din cele 2 siruri 
            jng smaller_s1 ;daca s1[poz] < s2[poz]
            jg larger_s1 ;daca s1[poz] > s2[poz]
            je equals; daca s1[poz] = s2[poz]
            smaller_s1:
                dec ESI ;pentru cazul 1 decrementam ESI
                dec EDI ;decrementam EDI
                mov [str_reminder], EAX ;salvam valoarea lui EAX
                lodsb ;punem in AL valoarea curenta din ESI
                mov [rez + EDX], AL ;punem in rezultat pe pozitia EDX valoarea din AL
                mov EAX, [str_reminder] ;restauaram valoarea din EAX
                inc EDX ;incrementam EDX
                inc EAX ;incrementam EAX
                cmp EAX, len_s1 ;daca am terminat teremenii din s1
                jge sf_prg ;sarim la eticheta sf_prg
                loop repeta ;repetam loop-ul
                jecxz sf_prg ;daca ecx e 0, din nou sarim la eticheta de final de loop
            larger_s1:
                dec EDI
                dec ESI
                mov [str_reminder], EAX
                mov AL, [EDI]
                mov [rez + EDX], AL
                mov EAX, [str_reminder]
                inc EDI         ;rationament asemanator pentru cazul s1[i] > s2[i] si s1[i] = s2[i]
                inc EDX         ;practic aplic interclasarea cum am invatat-o la liceu
                inc EBX
                cmp EBX, len_s2
                jge sf_prg
                loop repeta
                jecxz sf_prg
            equals:
                dec ESI
                mov [str_reminder], EAX
                lodsb
                mov [rez + EDX], AL
                mov EAX, [str_reminder]
                inc EDX
                inc EBX
                cmp EBX, len_s2
                jge sf_prg
                inc EAX
                cmp EAX, len_s1
                jge sf_prg
                loop repeta
                jecxz sf_prg
        sf_prg:
        cmp EAX, len_s1 ;comparam EAX cu lungimea sirului 1, daca EAX = len_s1 atunci am terminat termenii lui s1 
        je ebx_bigger; si mai avem de completat cu termenii lui s2
        jne ebx_smaller ;daca EAX nu e egal cu len_s1 atunci am terminat teremenii sirulu s2 si mai avem de pus 
        ebx_bigger: ;termenii din s1 ramasi
            mov ECX, len_s2
            sbb ECX, EBX
            repeat_:
                mov AL, [EDI]
                mov [rez + EDX], AL
                inc EDX
                inc EDI
            loop repeat_
            jmp end_prg
        ebx_smaller:
            mov ECX, len_s1
            sbb ECX, EAX
            repeat__:
                lodsb
                mov [rez + EDX], AL
                inc EDX
            loop repeat__
        
        
        end_prg:
        push    dword 0      
        call    [exit]      
