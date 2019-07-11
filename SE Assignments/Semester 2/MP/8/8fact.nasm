global _start

%macro print 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
syscall
%endm

section .bss
num1 resb 1
num2 resb 1
num3 resb 1
num4 resb 1

section .text

_start:

pop rcx
pop rsi
pop rsi

mov rax,0h
mov rbx,0h

mov bl,byte[rsi]
cmp bl,30h
je zero

cmp bl,31h
je zero

sub bl,30h
mov bh,00
mov ax,bx

dec bx
up:
	mul bx
	dec bx
	jnz up
	
	
	mov bl,0h
	mov cl,0h
	mov bh,0h
	mov ch,0h
	
	mov cl,al
	mov ch,ah
	
	
	and ch,0Fh
	cmp ch,0Ah
	jb add3
	add ch,07h
add3:
	add ch,30h
	
	mov bh,ch
	mov [num4],bh
	
	rol ah,4
	
	and ah,0Fh
	cmp ah,0Ah
	jb add3000
	add ah,07h
add3000:
	add ah,30h
	
	mov bh,ah
	mov [num3],bh
	
	
	
	and cl,0Fh
	cmp cl,0Ah
	jb add300
	add cl,07h
add300:
	add cl,30h
	
	mov bl,cl
	mov [num2],bl
	
	rol al,4
	
	and al,0Fh
	cmp al,0Ah
	jb add30
	add al,07h
add30:
	add al,30h
	
	mov bl,al
	mov [num1],bl
	
	print num3,1
	print num4,1
	
	print num1,1
	print num2,1
	
	jmp exit
	
zero:
	mov cl,30h
	mov al,31h
	mov [num2],al
	mov [num1],cl
	
	print num1,1
	print num2,1
	
	jmp exit
	
exit:	mov rax,60
	syscall
