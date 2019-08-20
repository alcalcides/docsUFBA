;a - (b+c)
%include "asm_io.inc"

segment .data
  prompt1 db "Valor a: ", 0
  prompt2 db "Valor b: ", 0
  prompt3 db "Valor c: ", 0

segment .bss
  a  resd 1
  b  resd 1
  c  resd 1

segment .text
  global _asm_main
_asm_main:

  mov eax, prompt1
  call print_string
  call read_int
  mov [a], eax

  mov eax, prompt2
  call print_string
  call read_int
  mov [b], eax

  mov eax, prompt3
  call print_string
  call read_int
  mov [c], eax

  add eax, [b] ; eax = c+b
  mov [b], eax ; b = c+b
  mov eax, [a] ; eax = a
  sub eax, [b] ; eax = a - b
  call print_int
  call print_nl

leave
ret
