bits 32 


global start        


extern exit, printf, circ_perm
import exit msvcrt.dll    
import printf msvcrt.dll

segment data use32 class=data
    ; ...
    a dd 987654321              ;=3ADE68B1h
    format_print db "Numarul in baza 16 este: %x",13, 10, 0            ;formatul de afisare al numarului in baza 16
    format_print1 db "Numarul este %d", 13, 10,0                       ;formatul de afisare al numarului in baza 10
    zece dd 10
    nr_cifre dd 0
    power dd 0
segment code use32 class=code
    nr_cif:                                 ;eticheta de apelare a functiei nr_cif, care returneaza in CL, nr de cifre al unui numar transmis ca si parametru
            mov ECX, 0                      ;punem 0 in ECX
            mov CL, 1                       ;punem in CL valoarea 1, acesta va fi contorul pentru numarul de cifre
            mov EAX, 1                      ;punem valoarea 1 in EAX, aici se vor calcula puterile lui 10
            .repeta:                    
                mul  DWORD [zece]           ;inmultim cu DWORDUL 10, asa incat in EDX:EAX, vom avea 10*EAX
                
                mov EDX, [ESP + 4]          ;punem in EDX valoarea parametrului transmis
                cmp EAX, EDX                ;comparam cele doua valori, in cazul in care 10^(CL + 1) > EDX, inseamna ca nr de cifre al parametruului este CL
                jg .stop                    ;eticheta de oprire
                inc CL                      ;in cazul in care nu ne oprim, incrementam puterea lui 10
                jmp .repeta                 ;sarim la eticheta de repetare
            .stop:
                ret                         ;ret care ne va reintoarce in program
                
    start:
       push DWORD [a]                       ;punem valoarea variabilei pe stiva
       push DWORD format_print              ;punem formatul de printare (baza 16 %x)
       call [printf]                        ;apelam functia printf
       add ESP, 4*2                         ;eliberam parametrii de pe stiva
       ;1234                                |
       ;2341                                | => permutari circulare
       ;3412                                |
       ;4123                                |
      
       push DWORD [a]                       ;punem valoarea variabilei pe stiva
       call nr_cif                          ;apelam functia creata de noi nr_cif, iar in CL, vom avea numarul de cifre
       add ESP, 4*1                         ;eliberam parametrii de pe stiva
       
       mov [nr_cifre], ECX       ;salvam numarul de cifre intr-o variabila

       mov EDX, 0                ;punem 0 in partea HIGH din EDX:EAX, pentru a nu avea IntegerOverFlow
       idiv DWORD [zece]         ;impartim la 10, pentru a obtine puterea imediat mai mica decat numarul nostru
       
       mov [power], EAX
       repeta:
           push DWORD EAX            ;punem puterea imediat mai mica decat numarul nostru, pe stiva           
           push DWORD [a]            ;punem numarul pe stiva ca si parametru
           call circ_perm            ;apelam permutarea circulara
           add ESP, 4*2              ;curatam stiva de paraemntrii
           
           mov [a], EAX              ;urmatorul numar [a] va fi EAX
           push DWORD EAX            ;punem numarul permutat pe stiva
           push DWORD format_print1  ;punem formatul de printare pentru numere in b10 pe stiva
           call [printf]             ;apelam functia print
           add ESP, 4*2              ;curatam parametrii de pe stiva
           
           mov CL, [nr_cifre]        ;punem in CL, numarul curent de fire (cate permutari circulare mai avem)
           dec CL                    ;decrementam acest numar
           cmp CL, 0                 ;daca numarul de cifre a ajuns la 0 (daca nu mai avem permutari circulare)
           jng final                 ;sarim la finalul programului
           mov [nr_cifre], CL        ;actualizam numarul de cifre din variabila nr_cifre
           mov EAX, [power]          ;repunem puterea lui 10 imediat mai mica decat numarul nostru initial
           jmp repeta                ;revenim la eticheta repeta
           
        
        final:                       ;eticheta de final de program
        push    dword 0      
        call    [exit]       
