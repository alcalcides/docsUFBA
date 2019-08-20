%include "asm_io.inc"

segment .data
	entrada	db 	"Entrada: ", 0
	saida	db	"Saida: ", 0	
segment .bss
        letra   resw    1
        desl    resb    1
        msg     resb    10

segment .text
        global  asm_main
asm_main:
	;[desl] = k
        call    read_int
	
        mov     [desl], al
        ;movzx   eax, byte [desl] ;word dword

	;msg[] = input
        call    read_char       
        mov     ecx, 10
	mov 	ebx, 0
        lerMsg:
		call	read_char
		mov	[msg + ebx], al
		inc	ebx
        loop	lerMsg      

	;print msg[]
	mov	eax, entrada
	call	print_string
	mov 	ebx, 0
	mov 	ecx, 10
	escreverMsgLida:
		mov	al, [msg + ebx]
		call 	print_char
		inc	ebx
	loop	escreverMsgLida
        call	print_nl

	;codifica msg[]
	mov	ebx, 0
	mov	ecx, 10
	decodificarMsg:
		mov	al,[msg + ebx]
		add	al,[desl]
		cmp	al, 91
		jb	copiar	
			sub	al, 26
		copiar:
		mov	[msg + ebx], al
		inc	ebx
	loop 	decodificarMsg


	;print msg[] codificada
	mov	eax, saida
	call	print_string
	mov 	ebx, 0
	mov 	ecx, 10
	escreverMsgCriptografada:
		mov	al, [msg + ebx]
		call 	print_char
		inc	ebx
	loop	escreverMsgCriptografada
        call	print_nl










leave                     
ret


