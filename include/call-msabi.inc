%ifndef CALL_MSABI_INC
%define CALL_MSABI_INC

%macro call_msabi 1
    sub rsp, 32
    call %1
    add rsp, 32
%endif