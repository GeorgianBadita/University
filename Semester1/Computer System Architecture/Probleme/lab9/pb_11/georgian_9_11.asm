bits 32

global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose, scanf
import exit msvcrt.dll  
import fopen msvcrt.dll  
import fprintf msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "input.txt", 0  ; numele fisierului care va fi creat
    mod_acces db "a", 0          ; modul de deschidere a fisierului - 
                                 ; a - pentru adaugare. daca fiserul nu exista, se va crea      
    text times 20 db 0
    format db "%s", 0
    new_space db 32 , 0         
    descriptor_fis dd -1         ; variabila in care vom salva descriptorul fisierului - necesar pentru a putea face referire la fisier
    mod_acces1 db "w"
                                    
; our code starts here
segment code use32 class=code
    start:
    
    
        push dword mod_acces1    
        push dword nume_fisier
        call [fopen]
        add esp, 4*2                ; eliberam parametrii de pe stiva

        mov [descriptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
        
        ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
        cmp eax, 0
        je final
        
        ; scriem textul in fisierul deschis folosind functia fprintf
        ; fprintf(descriptor_fis, text)
        push dword text
        push dword [descriptor_fis]
        call [fprintf]
        add esp, 4*2
        
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
    
    
        repeta:
        
            push dword text
            push dword format
            call [scanf]
            add esp, 4*2
            
            mov al, [text]
            cbw
            cwde
            cmp eax, '$'
            je final
            
            
            push dword mod_acces     
            push dword nume_fisier
            call [fopen]
            add esp, 4*2                ; eliberam parametrii de pe stiva

            mov [descriptor_fis], eax   ; salvam valoarea returnata de fopen in variabila descriptor_fis
            
            ; verificam daca functia fopen a creat cu succes fisierul (daca EAX != 0)
            cmp eax, 0
            je final
            
            ; adaugam/scriem textul in fisierul deschis folosind functia fprintf
            ; fprintf(descriptor_fis, text)
            push dword text
            push dword [descriptor_fis]
            call [fprintf]
            add esp, 4*2
            
            push dword new_space
            push dword [descriptor_fis]
            call [fprintf]
            add esp, 4*2
            
            ; apelam functia fclose pentru a inchide fisierul
            ; fclose(descriptor_fis)
            push dword [descriptor_fis]
            call [fclose]
            add esp, 4
        jmp repeta
      final:
        
        ; exit(0)
        push    dword 0      
        call    [exit]       