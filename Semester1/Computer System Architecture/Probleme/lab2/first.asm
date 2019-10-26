bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a  db 10
	b  dd 40
    c  db 3
; our code starts here
segment code use32 class=code
    start:
        ;Connect to APM API
MOV     AX,5301
XOR     BX,BX
INT     15h

;Try to set APM version (to 1.2)
MOV     AX, 530Eh
XOR     BX,BX
MOV     CX,0102
INT     15h

;Turn off the system
MOV     AX,5307
MOV     BX,0001
MOV     CX,0003
INT     15h

;Exit (for good measure and in case of failure)
RET
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
