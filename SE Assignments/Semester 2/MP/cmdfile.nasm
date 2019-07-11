global _start

%macro display 2
	push rax
	push rbx
	push rcx
	push rdx

	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2	
	syscall

	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

%macro input 2
	push rbx
	push rcx
	push rdx

	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2	
	syscall
	
	pop rdx
	pop rcx
	pop rbx
%endmacro


section .bss
	dis resb 1
	string resb 100

section .data
	st db "type"
	msg1 db 10,10,"THE CONTENTS OF THE FILE ARE : ",10,10
	len1 equ $-msg1
	msg2 db 10,10,"INVALID COMMAND",10,10
	len2 equ $-msg2

section .text
_start:	pop rbx
	pop rsi
	pop rdi
	mov rsi,st
	mov rcx,4
l:	mov al,byte[rsi]
	cmp al,byte[rdi]
	jne l1
	inc rsi
	inc rdi
	loop l

	pop rdi
	mov rax,2	
	mov rsi,0	;/0 readonly /1 writeonly /2 readwrite /65 create file
	syscall

	display msg1,len1
	mov rdi,rax
	mov rax,0
	mov rsi,string
	mov rdx,100
	syscall

	mov rdx,rax
	mov rax,1
	mov rdi,1
	mov rsi,string
	syscall	
	jmp exit
	
l1:	display msg2,len2
exit:	mov rax,60
	syscall
