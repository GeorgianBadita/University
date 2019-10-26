;Write a program that reads a decimal number from the keyboard. The number is unsigned, the maximum number of digits before and after the decimal point is 4. Add the value of pi (3.1415) to this number and write the result in a file. The name of the file is also read from the keyboard.

;Example:
;Input number: 23.543
;File name: result.txt
;Outcome: the file result.txt will contain the string '26.6845'.


bits 32


global start        


extern exit, scanf, fopen, fprintf, fclose, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
segment data use32 class=data
    ; ...
    format_scan_str db "%s", 0
    format_print db "%d", 0
    len equ 20
    string times len db -1
    fract db 0
    zece db 10
; our code starts here
segment code use32 class=code
    start:
       
       push DWORD string
       push DWORD format_scan_str
       call [scanf]
       add ESP, 4*2
       
       ;PI = 3.1415
       mov ECX, len
       mov EDX, 0
       jecxz sf_prg
       repeta:
        mov AL, [string + EDX]
        cmp AL, -1
        je sf_prg
        inc EDX
        cmp AL, '.'
        je sf_prg
    loop repeta
        
    
    sf_prg:
    
    mov EAX, len
    sbb EAX, ECX
    mov ECX, EAX
    mov EDX, ECX
    mov EAX, len
    sbb EAX, EDX
    mov ECX, EAX
    inc EDX
  
    fract_part:
    
        mov AL, [fract]
        mul BYTE [zece]
        mov BYTE AX,[string + EDX]
        sbb AX, '0'
        add AX, BX
        mov [fract], AX
        
    loop fract_part
    
    mov AL, [fract]
    cbw
    cwde
    push DWORD EAX
    push DWORD format_print
    call [printf]
    add ESP, 4*2
    
        push    dword 0      
        call    [exit]      
