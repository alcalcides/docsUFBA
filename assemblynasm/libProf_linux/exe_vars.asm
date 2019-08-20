%include "asm_io.inc"

segment .data
	;temp	dd 10, 8, 7
	temp1	db 10, 8, 7 ;como navegar neste vetor de byte?

segment .bss


segment .text
	global asm_main
asm_main:
	;mov	eax, [temp + 8]
	;call	print_int
	;call	print_nl

	movsx 	eax, [temp1 + 0];falha de sementação!
	call	print_int
	call	print_nl
	


leave
ret