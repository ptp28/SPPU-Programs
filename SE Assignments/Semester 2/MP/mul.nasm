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

%macro accept 2
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
buf	resb 4
cho	resb 1

section .data
	
	msg4 db 0AH, "Enter method : "
	len4 equ $-msg4

	msg1 db 0Ah, "Enter the first number : "
	len1 equ $-msg1
	
	msg2 db 0Ah, "Enter the second number : "
	len2 equ $-msg2
	
	msg3 db 0Ah,0AH, "THE ANSWER IS : "
	len3 equ $-msg3

;$
section .text
_start:	
	display msg4,len4
	accept cho,2
	mov dx,00
	mov ah,00
	display msg1,len1
	call acc
	mov al,bl
	display msg2,len2
	call acc
	
	cmp byte[cho],31h
	je multi1
	call mul2	;call subroutine ///// (SUCCESSIVE ADDITION)
	jmp next
multi1:	call mul1	;call subroutine ///// (SHIFT &ADD)

next:	display msg3,len3
	call dis	
	
	mov rax,60
	syscall	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

acc:	push rax
	push rdx
	push rcx
	
	accept buf,3	;///// will store num of keys entered & also it calls the accept macro
	
	dec rax
	mov rcx,rax
	mov bl,0
	mov rsi,buf
l10:	mov al,byte[rsi]
	cmp al,57
	jbe l1
	sub al,07
l1:	sub al,48
	shl bl,4
	add bl,al
	inc rsi
	loop l10
	
	pop rcx
	pop rdx
	pop rax
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

dis:	push rax
	push rbx
	push rcx
	
	mov rsi,buf
	mov rcx,4
	
con:	rol dx,4
	mov al,dl
	and al,0Fh
	cmp al,9
	jbe l12
	add al,7
l12:	add al,48
	mov byte[rsi],al
	inc rsi
	loop con
	mov byte[rsi],10
	display buf,5
	
	pop rcx
	pop rbx
	pop rax
	ret
mul1:				;shift and add
	mov rcx,8
up:	ror bl,1
	jnc cont
	add dx,ax
cont:	shl ax,1
	loop up
	
	ret

mul2:				;successive addition
add:	add dx,ax
	dec bl
	jnz add
	ret	
