;Dandu-se un sir de octeti se cere ordonarea acestuia in ordine grescatoare

bits 32 


global start        


extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    ; ...
    sir db 5, 2, 3, 1, 9, 9, 0
    len equ $-sir

segment code use32 class=code
    start:
    
    
    ;for(int i = 0; i<n - 1; i++) {
    ;   for(int j = i + 1; j<n; j++) {
    ;           if(v[i] > v[j]) {
    ;               aux = v[i]
    ;               v[i] = v[j]
    ;               v[j] = aux
    ;       }
    ;   }          
    ;}
    ;
    
        mov ESI, sir            ;ESI - offset de inceput pt sir
        mov EDX, 0
        repet:
            mov BL, [ESI + EDX] ;in BL punem v[i] 
            mov BH, DL          ;in BH, punem i 
            inc BH              ;in BH  punem i + 1
            mov EAX, 0      ;punem 0 in EAX
            compare:
                mov AH, 0       
                mov AL, BH      ;punem in AL, j
                mov AH, [ESI + EAX] ;punem in AL, v[j] (AL a fost convertit fara semn la EAX)
                cmp BL, AH      ;comparam v[i], v[j]
                ja swap
                jmp not_swap
                swap: 
                    mov CL, BL      ;in CL <- ESI + EDX aux = v[i]
                    mov CH, AH      ;in CH <- ESI + EAX
                    mov AH, 0
                    mov [ESI + EDX], CH ;v[i] = v[j]
                    mov [ESI + EAX], CL ;v[j] = aux
                not_swap:
                    inc EAX         
                    cmp EAX, len-1
                    je go_to_repet
                    jmp compare
                    
        go_to_repet:
        inc EDX
        cmp EDX, len-1
        je final
        jmp repet
        
        final:
   
        
        push    dword 0      
        call    [exit]       
