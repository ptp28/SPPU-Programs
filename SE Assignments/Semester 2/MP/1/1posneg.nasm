%macro output 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endm

global _start:

section .data
msg1 db 10,"Positive numbers are : "
len1 equ $-msg1
msg2 db 10,"Negative numbers are : "
len2 equ $-msg2
arr dq 9100000000000000h,2500000000000000h,8500000000000000h,3400000000000000h,6300000000000000h

section .bss
pcnt resb 1
ncnt resb 1

section .text
_start:
	mov cl,05
	mov rsi,arr
up : 	mov rax,[rsi]
	bt rax,63
	jc down
	inc byte[pcnt]
	jmp down1
down :	inc byte[ncnt]
down1 : add rsi,8
	dec cl
	jnz up
	add byte[pcnt],30h
	add byte[ncnt],30h

	output msg1,len1
	output pcnt,1
	output msg2,len2
	output ncnt,1
	
mov rax,60
mov rdi,0
syscall
