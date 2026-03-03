default rel
%include "enter64.inc"

section .data

format_str db "%s", 12, 0
out_str db "This program cannot be run in DOS mode.", 0
glfwInit_ok__string db "glfwInit success.", 0

scanf_f_str db "%c", 0
scanf_out_char db 0

windowtitle__string db "Assembly OpenGL demo.", 0

section .text

global main

extern scanf
extern printf

%include "glfw.inc"
%include "glad.inc"

%define WIN_W 800
%define WIN_H 600

; Stack frame:
;   [RBP - 8] = window struct addr (GLFWwindow *).
;   ... - "shadow space".

main:
	enteralign64 0

	lea rcx, [format_str]
	lea rdx, [out_str]
	call printf

    ; init GLFW.

	call glfwInit
	test eax, eax
	jnz .glfwInit_ok
		mov rax, 1
		jmp .quit
	.glfwInit_ok:

    lea rcx, [format_str]
    lea rdx, [glfwInit_ok__string]
    call printf

    ; set OpenGL version & profile.

    mov ecx, GLFW_CONTEXT_VERSION_MAJOR
    mov edx, 4
    call glfwWindowHint

    mov ecx, GLFW_CONTEXT_VERSION_MINOR
    mov edx, 6
    call glfwWindowHint

    mov ecx, GLFW_OPENGL_PROFILE
    mov edx, GLFW_OPENGL_CORE_PROFILE
    call glfwWindowHint

    lea rcx, [format_str]
    lea rdx, [glfwInit_ok__string]
    call printf

    ; create window.

    mov ecx, WIN_W
    mov edx, WIN_H
    lea r8, [windowtitle__string]
    xor r9, r9

    ;mov r12, rsp
    ;    push r9
    ;
    ;    ;sub rsp, 8 + 32
    ;    and rsp, ~16
    ;    sub rsp, 32
    ;;enteralign64 0
    ;    call glfwCreateWindow
    ; 
    ;;leave64
    ;;pop r9
    ;mov rsp, r12

    mov r12, rsp ; save RSP for manipulations
        and rsp, ~16 ; align RSP by 16 bytes.

        sub rsp, 8 ; push 5th arg to stack & save alignment.
        push r9

        sub rsp, 32 ; shadow space.
        call glfwCreateWindow
    mov rsp, r12 ; restore RSP

    test rax, rax
    jnz .glfwCreateWindow_ok
        call glfwTerminate

        mov rax, 2
        jmp .quit
    .glfwCreateWindow_ok:
    mov [rbp - 8], rax

    ; make created window as current.

    mov rcx, rax
    call glfwMakeContextCurrent

    lea rcx, [format_str]
    lea rdx, [glfwInit_ok__string]
    call printf

    ; load OpenGL functions (init GLAD).
    mov rcx, glfwGetProcAddress
    call gladLoadGLLoader

    test eax, eax
    jnz .gladLoadGLLoader_ok
        xor rcx, rcx
        call glfwMakeContextCurrent

        call glfwTerminate

        mov rax, 3
        jmp .quit
    .gladLoadGLLoader_ok:

    lea rcx, [format_str]
    lea rdx, [glfwInit_ok__string]
    call printf

    xor ecx, ecx
    mov edx, ecx
    mov r8, WIN_W
    mov r9, WIN_H
    call glViewport

    lea rcx, [scanf_f_str]
    lea rdx, [scanf_out_char]
    call scanf

	xor rax, rax
	.quit:

	leave64
	ret