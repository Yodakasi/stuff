extern printf
extern puts

SECTION .data
length:       dd 8
array:   dd 43,1,76,45,8,2,45,78
line:    db "halo general kenobi", 0
format:  db "%d", 10, 0

SECTION .text
    global main
main:
    push ebp
    mov ebp, esp
    mov edi, dword [length]
    mov ebx, 0
    push dword line
    call halo
loop_start:
    cmp edi, 0
    je loop_end
    push dword [array + 4 * ebx]
    push dword format
    call printf
    dec edi
    inc ebx
    jmp loop_start
loop_end:
    mov esp, ebp
    pop ebp
    mov	eax, 0
    ret


halo:
    push ebp
    mov ebp, esp
    push dword [ebp + 0x8]
    call puts
    leave
    ret
