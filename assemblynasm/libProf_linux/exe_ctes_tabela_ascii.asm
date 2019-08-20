%include "asm_io.inc"

segment .data


segment .bss
	letra	equ	'A'	;guarda um caracter
	num		equ 65	;uma constante é dado de 4 bytes

segment .text
	global asm_main
asm_main:
	mov		eax, letra
	call	print_int
	call	print_nl

	mov		eax, letra
	call	print_char
	call	print_nl

	mov		eax, num
	call	print_int
	call	print_nl

	mov		eax, num
	call	print_char
	call	print_nl
	


leave
ret