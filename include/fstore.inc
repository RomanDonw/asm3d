%ifndef FSTORE_INC
%define FSTORE_INC

%macro fstore32 2
    push rax
        mov eax, [%%value]
        mov %1, eax
    pop rax

    jmp %%skip
        %%value dd %2
    %%skip:
%endmacro

%macro fstore64 2
    push rax
        mov rax, [%%value]
        mov %1, rax
    pop rax

    jmp %%skip
        %%value dq %2
    %%skip:
%endmacro

%endif