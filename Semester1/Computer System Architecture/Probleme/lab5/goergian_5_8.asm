;Badita Marin-Georgian, 211, 31-10-2017, tema lab 5, problema 8

  ;Se da un numar natural a (a: dword, definit in segmentul de date). Sa se citeasca un numar natural b si sa se calculeze: a + a\b. Sa se afiseze rezultatul operatiei. Valorile vor fi afisate in format decimal (baza 10) cu semn.

bits 32

global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    
    a dd 13
    b dd 0
    rez dd 0
    format_scan db "%u", 0
    format_print1 db "b=", 0
    format_print db "%d", 10, 0
    
 segment code use32 class=code
     start:
       ;citim numarul natural b
       push DWORD format_print1
       call [printf]
       add ESP, 4*1
       
       push DWORD b
       push DWORD format_scan
       call [scanf]
       add ESP, 4*2
       
       ;EAX = a
       mov EAX, DWORD[a]
       cdq ;convertim WORD-ul a la QWORD, EDX:EAX = a
       
       ;impartim la DWORD-ul b, avem EAX = EDX:EAX / b
       idiv DWORD[b]
 
       ;adunam a la a/b, EAX = a + a/b
       add EAX, DWORD[a]
       
       
       ;afisam rezultatul
       push DWORD EAX
       push DWORD format_print
       call [printf]
       add ESP, 4*2
       
       push dword 0
       call [exit]