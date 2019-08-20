%include "asm_io.inc"

segment .data

segment .bss
	nw resd 1
segment .txt
	global _asm_main
_asm_main:
	call read_int
	neg ax
	movsx [nw], ax
	mov eax, [nw]
	call print_int

leave
ret