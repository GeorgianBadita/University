bits 32
segment use32 public code
    rez dd 0                ;variabila intermediara pentru rezultat
    ten dd 10               ;variabila de tip dd pentru inmultirea cu 10
global circ_perm
    circ_perm:
        mov EBX, [ESP + 4]          ;parametrul de pe stiva ce reprezinta numarul nostru
        mov ECX, [ESP + 8]          ;luam primul parametru de pe stiva, care este puterea lui 10 mai mica decat numarul nostru
        mov [rez], EBX              ;punem in variabila rez, numarul nostru
        mov EDX, 0                  ;ne asiguram ca in partea HIGH din EDX:EAX, avem 0
        mov EAX, [rez]              ;punem in EAX, variabila rezultat
        div ECX                     ;imprtim prin ECX, asa incat in EDX avem ultimele n-1 cifre din numar, iar in EAX avem cifra de pe pozitia 1
        mov EBX, EDX                ;punem in EBX, cele n-1 cifre
        mov ECX, EAX                ;punem in ECX, prima cifra
        mov EAX, EBX                ;punem in EAX cele n - 1 cifre
        mov EDX, 0                  ;punem 0 in EDX
        mul DWORD [ten]
        add EAX, ECX                ;in EAX ar trebui sa fii obtinut rezultatul
        ret
        