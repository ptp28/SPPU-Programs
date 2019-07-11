global _start

section .bss
	buf resb 2

section .text
_start: pop rbx		;first pop will give no. of parameters passed
	add bl,48
	mov rsi,buf
	mov byte[rsi],bl
	inc rsi
	mov byte[rsi],10

	mov rax,1
	mov rdi,1
	mov rsi,buf
	mov rdx,2
	syscall

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	pop rsi
	;pop rsi

	mov rax,1
	mov rdi,1
	mov rdx,6
	syscall

	pop rsi
	mov rax,1
	mov rdi,1
	mov rdx,6
	syscall

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	mov rax,60
	syscall
