
SECTION .text
    global main
main: 
    push ebp
    mov ebp, esp
    xor eax, eax
    push eax
    push 0x73000000
    push 0x7361702e
    push 0x2f433262
    push 0x616c2f65
    push 0x6d6f682f ; push the file name to the stack
    mov ebx, esp
    mov eax, 5
    mov ecx, 0
    int 0x80
    mov eax, 3
    mov ebx, eax
    mov ecx, esp
    mov edx, 0x25
    int 0x80
    mov eax, 4
    mov ebx, 1
    int 0x80
    mov eax, 1
    mov ebx, 0
    int 0x80
    leave
    ret
