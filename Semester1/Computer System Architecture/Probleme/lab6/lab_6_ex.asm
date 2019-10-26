bits 32


global start        


extern exit              
import exit msvcrt.dll
segment data use32 class=data
    s1 db 'abcdef', 'g', 'h', 'i'
    s dw 'abcdefx', 'g', 'h', 'i'
    l_s_var1 equ ($ - s)/2 ;nr cuv din s
    l_s1 db (s-s1)/2
    l_s_var2 db (l_s1 - s)/2
    d resb l_s_var1
    test_ dw -1
    ;rezervare spatiu mem cu times
    d2 times l_s_var1 db 0
    test_1 dw -1

; our code starts here
segment code use32 class=code
    start:
       
        push    dword 0      
        call    [exit]      
