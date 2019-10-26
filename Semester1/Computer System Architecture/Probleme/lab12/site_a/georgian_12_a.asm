bits 32 

global start        


extern exit, scanf, printf             
import exit msvcrt.dll  
import scanf msvcrt.dll
import printf msvcrt.dll  

segment data use32 class=data
  my_str times 101 db 0
  format_scan db "%s", 0
  format_print db "Numarul de cifre in baza 16 este :%x", 0
  digits db 0

segment code use32 class=code
    start:
        
      
        
        push DWORD my_str
        push DWORD format_scan
        call [scanf]
        add ESP, 4*2
        
        mov ESI, my_str
        repeta:
            lodsb
            cmp AL, 0
            je stop
            cmp AL, '0'
            jge comp_9
                comp_9:
                    cmp AL, '9'
                    jnge increment
                    jmp repeta
                    increment:
                        mov BL, [digits]
                        inc BL
                        mov [digits], BL
                        jmp repeta
        stop:
            
        push DWORD [digits]
        push DWORD format_print
        call [printf]
        add ESP, 4*2
        push    dword 0     
        call    [exit]      
