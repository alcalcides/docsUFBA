%include "asm_io.inc"

segment .data
        prompt1         db      "Enter a number: ", 0       ; don't forget nul terminator
        outmsg1         db      "You entered ", 0
        nprimo          db      "Nao eh primo", 0
        ok              db      "Primo", 0


segment .bss
        num          resd    1 


segment .text
        global  _asm_main
_asm_main:
        enter   0,0               ; setup routine
        pusha

        ;mov     eax, prompt1      ; print out prompt
        ;call    print_string

        call    read_int          ; read integer
        mov     [num], eax        ; store into num

        ;mov     eax, outmsg1      ; print out prompt
        ;call    print_string
        ;mov     eax, [num]
        ;call    print_int
        ;call    print_nl

        mov eax, 1
        cmp [num], eax
        jz naoprimo
        mov eax, 0
        cmp [num], eax
        jz naoprimo

        mov eax, [num]
        mov ecx, 2
        div ecx
        mov ecx, eax

l1:     
        cmp ecx, 1
        jz ehprimo
        mov edx, 0
        mov eax, [num] 
        div ecx
        ;mov eax, edx
        ;call print_int
        ;call print_nl
        cmp edx, 0
        jz naoprimo
        loop l1

ehprimo:
        mov eax, ok
        jmp next

naoprimo:
        mov eax, nprimo
        jmp next
       

next:
        
        call print_string
        call print_nl

        popa
        mov     eax, 0            ; return back to C
        leave                     
        ret


