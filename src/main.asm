default rel

section .data

format_str db "%s", 12, 0
out_str db "This program cannot be run in DOS mode.", 0

section .text

global main

extern printf
extern glfwCreateWindow

%include "enter64.inc"

main:
	;push rbp
	;mov rbp, rsp
	;and rsp, ~16
	;sub rsp, 32
	enteralign64 0


	lea rcx, [format_str]
	lea rdx, [out_str]
	call printf


	leave64
	;mov rsp, rbp
	;pop rbp

	xor rax, rax
	ret