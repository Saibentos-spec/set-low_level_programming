section .data
    message db "Hello, ALX", 10, 0

section .text
    global main
    extern printf

main:
    mov rdi, message
    xor rax, rax
    call printf

    mov rax, 0
    ret
