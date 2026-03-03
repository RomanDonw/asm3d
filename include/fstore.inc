%ifndef FSTORE_INC
%define FSTORE_INC

%macro fstore32 2
    mov dword %1, %%value

    jmp %%skip
        %%value dd %2
    %%skip:
%endmacro

%macro fstore64 2
    mov qword %1, %%value

    jmp %%skip
        %%value dq %2
    %%skip:
%endmacro

%endif