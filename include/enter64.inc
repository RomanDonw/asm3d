%ifndef ENTER64_INC
%define ENTER64_INC

%macro enter64 1
    push rbp
    mov rbp, rsp

    sub rsp, %1
%endmacro

%macro enteralign64 1
    enter64 %1

    and rsp, ~16
    sub rsp, 32
%endmacro

%macro leave64 0
    mov rsp, rbp
    pop rbp
%endmacro

%endif