global _start

section .bss
	buf resb 16

section .data
_start:	
	pop rbx
	pop rsi
	pop rsi

	mov rbx,0
	mov bl,byte[rsi]
	sub bl,48


	mov rax,1
l1:	mul rbx
	dec rbx
	jnz l1

	mov rcx,16
	mov rsi,buf
l2:	rol rax,4
	mov dl,al
	and dl,0fh
	cmp dl,9
	jbe c1
	add dl,07
c1:	add dl,48
	mov byte[rsi],dl
	inc rsi
	loop l2

	mov rax,1
	mov rdi,1
	mov rsi,buf
	mov rdx,16
	syscall

	mov rax,60
	syscall
