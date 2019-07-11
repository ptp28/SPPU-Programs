global _start

%macro open 1
	mov rax,2
	mov rdi,filename
	mov rsi,2
	mov rdx,%1
	syscall
%endm

%macro read 0
	mov rax,0
	mov rdi,[fd2]
	mov rsi,arr
	mov rdx,10
	syscall
%endm

%macro write 0
	mov rax,1
	mov rdi,[fd2]
	mov rsi,arr
	mov rdx,10
	syscall
%endm

%macro close 0
	mov rax,3
	mov rdi,[fd2]
	syscall
%endm
%macro inout 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endm

section .bss
	arr resb 50
	a resb 1
	n resb 1
	choice resb 1

section .data
	filename db 'sort.txt'
	fd1 dq 0
	fd2 dq 0
	m1 db 10,'1.Display file 2.Ascending order 3.Descending order 4.Exit',10
	l1 equ $-m1
	m2 db 10,'Ascending :',10
	l2 equ $-m2
	m3 db 10,'Descending :',10
	l3 equ $-m3

section .text
_start:

	open 0
	mov [fd2],rax
	read
	call total_num
	close

menu:	inout 1,1,m1,l1
	inout 0,0,choice,2
	cmp byte[choice],'1'
	je c1
	cmp byte[choice],'3'
	jbe c2
	
	mov rax,60
	mov rdx,0
	syscall

c1:	call display_array
	jmp menu

c2:	call sorting
	jmp menu

display_array:

	mov rbp,arr
	mov al,byte[rbp]

loop1:	cmp al,00h
	je done1
	mov byte[a],al
	inout 1,1,a,1
	inc rbp
	mov al,byte[rbp]
	jmp loop1
done1:
	ret

ret

total_num:

	mov rbp,arr
	mov al,byte[rbp]
	mov byte[n],00h

loop2:	cmp al,00h
	je done2
	inc byte[n]
	inc rbp
	mov al,byte[rbp]
	jmp loop2
done2:
	cmp byte[n],00h
	je out
	dec byte[n]
out:	
	ret

ret

sorting:

	mov dl,byte[n]
strt1:
	mov rsi,arr
	mov cl,byte[n]
	dec cl

	strt:	mov rdi,rsi
		inc rdi
		mov bl,byte[rdi]
		mov al,byte[rsi]

		cmp byte[choice],'2'
		je asc
		jmp des
		
	asc:	cmp al,bl
		ja swap
		jmp noswap

	des:	cmp al,bl
		jb swap
		jmp noswap

	swap:	mov [rdi],al
		mov [rsi],bl

	noswap:
		inc rsi
		dec cl
		jnz strt

	dec dl
	jnz strt1

	cmp byte[choice],'2'
	je ascnd
	
	inout 1,1,m3,l3
	jmp pr
ascnd:	inout 1,1,m2,l2
pr:	call display_array

	open 1
	mov [fd2],rax
	write
	close
ret
