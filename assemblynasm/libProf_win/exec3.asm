%include "asm_io.inc"

segment .data
	mPrompt1 db "Enter a number: ", 0
	mPar db "par", 0
	mImpar db "impar", 0
	mH db "1", 0
	mL db "0", 0

segment .bss
	num resd 1
	ehpar resd 1

segment .text
	global _asm_main
_asm_main:
	;mov eax, mPrompt1
	;call print_string
	call read_int
	mov [num], eax
	
	shr eax, 1
	jc impar
	jnc par

par:
	mov eax, 1
	mov [ehpar], eax
jmp varrer

impar:
	mov eax, 0
	mov [ehpar], eax
jmp varrer

varrer:
	mov edx, [num]
	mov ecx, 16
	l1:
		shl dx, 1
		jc vai1
		jnc vai0
		vai1:
			mov eax, mH
			call print_string
			jmp vaiparaoloop
		vai0:
			mov eax, mL
			call print_string
		vaiparaoloop:
	loop l1	
	call print_nl

saida:
	mov eax, [ehpar]
	cmp eax, 1
	je spar
		mov eax, mImpar
		jmp segue
	spar:
		mov eax, mPar
	segue:
	call print_string
	call print_nl


leave
ret	