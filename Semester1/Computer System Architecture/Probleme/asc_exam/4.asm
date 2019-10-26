bits 32 


global start        


extern exit, printf               
import exit msvcrt.dll    
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    sir dw 21520, -6, "xy", 0f5b2h, -129
    len_sir equ ($-sir)/2
    max_ db 0
    min_ db 0
    fmt_print db "%x", 10,13, 0
segment code use32 class=code
    start:
        
        mov ESI, sir
        mov ECX, len_sir - 1
        lodsb
        mov BYTE [max_], AL
        lodsb
        mov BYTE [min_], AL
        get_max_min:
            lodsb
            mov AH, [max_]
            cmp AL, AH
            jna next_byte
                mov [max_], AL
            next_byte:
                lodsb
                mov AH, [min_]
                cmp AL, AH
                ja again
                mov [min_], AL
            again:
        loop get_max_min
        
        mov EDX, 0
        mov EAX, 0
        mov AL, [max_]
        mov BX, 0
        mov BL, [min_]
        div BX
        
        pushad
        push EAX
        push fmt_print
        call [printf]
        add ESP, 4*2
        popad
        
        mov EAX, 0
        mov AX, DX
        
        push EAX
        push fmt_print
        call [printf]
        add ESP, 4*2
        push    dword 0      
        call    [exit]       
