;Se dau doua siruri de octeti. Sa se parcurga cel mai scurt sir dintre cele doua siruri si sa se construiasca un al treilea sir care va contine cel mai mare element de acelasi rang din cele doua siruri, iar pana la lungimea celui mai lung sir, sirul al treilea se va completa alternativ cu valoarea 1 respectiv 0.

bits 32


global start        
    
extern exit              
import exit msvcrt.dll
segment data use32 class=data
    s1 db 0, 3, 5, 9 
    l1 equ $ - s1
    s2 db  1, 2, 3, 4, 5, 6, 7
    l2 equ $ - s2

; our code starts here
segment code use32 class=code
    start:
    mov AX, l2
    mov BX, l1
    cmp AX, BX
    mov EDX, 0
    jge put_l2
    jng put_l1
    put_l1:
        mov ECX, l2
        mov ESI, s2
        mov EDI, s1
        mov EBX, ECX
        mov EAX, l1
        jmp repeta
    put_l2:
        mov ECX, l1
        mov ESI, s1
        mov EDI, s2
        mov EBX, ECX
        mov EAX, l2
    repeta:
        cmpsb 
        jng just_loop
        jge change
        change:
            dec ESI
            dec EDI
            movsb
            loop repeta
            jecxz sf_prg
        just_loop:
            jecxz sf_prg
            loop repeta
        sf_prg:
        sbb EAX, EBX
        mov ECX, EAX
        dec ECX
        mov EDX, 0
        mov AL, 1
        stosb
        repeta1:
          dec EDI
          mov AL, [EDI]
          inc EDI
          cmp AL, 1
          je este_1
          jne este_0
          este_1:
            mov AL, 0
            stosb
            jecxz final
            loop repeta1
          este_0:
            mov AL, 1
            stosb
            jecxz final
            loop repeta1
         
            
            
        final:
    
    
        push    dword 0      
        call    [exit]      
