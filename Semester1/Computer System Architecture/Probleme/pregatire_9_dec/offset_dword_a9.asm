bits 32


global start        



extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    ; ...
    a dd 0a344dh, 30h, 11223344h, 46ab89ch 
    format db '%d', 0
; our code starts here
segment code use32 class=code
    start:
    
    
    mov AL, BYTE [a + 9]
    cbw
    cwde
    push DWORD EAX
    push DWORD format
    call [printf]
    add ESP, 4*2
    
    
    push    dword 0      
    call    [exit]      
