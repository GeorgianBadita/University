bits 32 

global start        

extern exit, printf, scanf             
import exit msvcrt.dll  
import printf msvcrt.dll
import scanf msvcrt.dll   

segment data use32 class=data
     
    a dd -22
    b dw -8
    rez dd 0
    format_scan db "%d", 0
    format_print db "%d mod %d = %d", 0


    ; Se dau doua numere natural a si b (a: dword, b: word, definite in segmentul de date). Sa se calculeze a/b si sa se afiseze restul impartirii in urmatorul format: "<a>/<b> = <cat>" Exemplu: pentru a = 23 si b = 5 se va afisa: "23 mod 5  = 3". Valorile vor fi afisate in format decimal (baza 10) cu semn.

segment code use32 class=code
    start:
        
        mov AX, WORD[a] ;punem in AX WORD-ul care incepe la a
        mov DX, WORD[a+2] ;punem in DX WORD-ul care incepe la a+2
         ;avem in DX:AX DWORD-ul a, idiv

      
        idiv WORD[b] ;AX = DX:AX / b   DX = DX:AX % b
        
        mov AX, DX ;mutam in AX restul impartirii, pentru a-l putea converti la DWORD
        cwde ;AX -> EAX
        mov [rez], EAX         
        mov AX, [b]
        cwde
        
        push DWORD [rez]
        push DWORD EAX
        push DWORD [a]
        push DWORD format_print
        call [printf]
        add ESP, 4*4
        
        push    dword 0
        call [exit]