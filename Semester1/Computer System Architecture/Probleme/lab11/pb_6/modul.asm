bits 32



segment use32 public code
global concat
    concat:
        mov ESI, [ESP + 4]
        mov EDI, [ESP + 8]
        mov AL, 0
        
        
        get_final:
            scasb
            je stop
            jmp get_final
        stop:
            dec EDI
            .concat:
                lodsb
                cmp AL, 0
                je go_ret
                stosb
                jmp .concat
            go_ret:
                
                ret
        