bits 32
global sufix                                   ;marcam sufix ca fiind global, deoarece aceasta functie este apelata din modulul modul.main
extern result                                  ;spunem asamblorului despre variabila restul ca exista undeva in exterior
segment code use32 public code class = 'code'
sufix:
    mov EDI, EAX                                ;punem in EDI adresa sirului stocata in EAX
    mov ESI, EBX                                ;punem in ESI adresa sirului stocata in EBX
    mov EDX, 0                                  ;punem 0 in EDX
    mov ECX, 8
    mov [result], BYTE 0
    .rep:
        mov [result + ECX], BYTE 0              ;punem 0 in sirul restul pentru a ne asigura ca nu exista 'reziduri' de la celelalte apelari
    loop .rep
    std                                         ;setam DF = 1
    .repeta:
        lodsb                                   ;punem in AL pe rand elementele din sirul 1
        scasb                                   ;comparam valorile din AL cu elementele din sirul destinatie
        je .increment                           ;daca sunt egale salvam elementele pe rand in sirul result
        jmp .out_loop                           ;daca intalnim 2 caractere pe aceeasi pozitie care nu sunt egale, iesim din loop
        .increment:
            mov [result + EDX], AL
            inc EDX
            jmp .repeta
    .out_loop:
        cld                                      ;setam DF la 0
        ret                                      ;apelam ret
    
    