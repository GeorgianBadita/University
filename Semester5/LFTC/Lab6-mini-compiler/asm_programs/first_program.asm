section .text

global _start

_start:

  mov  eax,4		;sys_wite
  mov  ebx,1		;To stdout
  mov  ecx,msg		;'Input some data: '
  mov  edx,msg_size	
  int  80h		;Call kernel

  mov  eax,3		;sys_read. Read what user inputs
  mov  ebx,0		;From stdin
  mov  ecx,inp_buf	;Save user input to buffer.
  int    80h

  push eax

  mov  eax,4
  mov  ebx,1
  mov  ecx,msg2		;'You entered: '
  mov  edx,msg2_size
  int    80h

  mov  eax,4		
  mov  ebx,1	
  mov  ecx,inp_buf
  pop  edx
  int  80h

  mov  eax,1
  mov  ebx,0
  int  80h

section .bss

inp_buf resb 16

section .data

msg: db 'Input some data: '
msg_size: equ $-msg

msg2: db 'You entered: '
msg2_size: equ $-msg2