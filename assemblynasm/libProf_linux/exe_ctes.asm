%include "asm_io.inc"

segment .data


segment .bss
	cr		equ	50
	lf		equ 60
	;nl		equ cr,lf ;como concatenar constantes?


segment .text
	global asm_main
asm_main:
	mov		eax, lf
	call	print_string
	call	print_nl
	


leave
ret