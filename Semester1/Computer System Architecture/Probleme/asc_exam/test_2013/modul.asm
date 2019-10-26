bits 32
global ultimul
var db 0
segment code use32 public code class = 'code'
    ultimul:
        
        mov ECX, [ESP + 4]
        mov ESI, [ESP + 8]

        repet:
            mov AH, AL
            lodsb
        loop repet
        ret
        
        