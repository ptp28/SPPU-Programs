%macro output 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endm
global _start

section .data
n dd 0002.0
	array_x dd 7.375,2.952,1.375
	h100 dq 10000
	msg db "mean  "
	len equ $-msg
	msg1 db 0Ah,10,"Varience  "
	len1 equ $-msg1
	msg2 db 0Ah,10,"Deviation  "
	len2 equ $-msg2
	

section .bss
madd resd 2
mean resd 2
mean1 rest 1
dev resd 2
dev2 resd 2
va resd 2
dev1 rest 1
z rest 1
devi resb 7
meanascii resb 7
vari resb 7
section .text
_start:
finit
	fldz
	mov rsi,array_x
	mov cx,2
loopmean: fadd dword[rsi]
	add rsi,4
	loop loopmean
	fst dword[madd]
	fdiv dword[n]
	fst dword[mean]
fimul dword[h100]
fbstp tword[mean1]

mov rsi,mean1
add rsi,2
mov rdi,meanascii
call procedure
output msg,len
output meanascii,5

fldz	
mov rsi,madd
fsub dword[mean]
fst dword[dev]
fmul dword[dev]
fdiv dword[n]

fst dword[va]
fimul dword[h100]
fbstp tword[dev1]

mov rsi,dev1
add rsi,2
mov rdi,vari
call procedure
output msg1,len1
output vari,5

fldz
mov rsi,madd
fsub dword[mean]
fst dword[dev2]
fmul dword[dev2]
fdiv dword[n]
fsqrt
fimul dword[h100]
fbstp tword[z]

mov rsi,z
add rsi,2
mov rdi,devi
call procedure
output msg2,len2
output devi,5
mov rax,60
syscall
procedure:
mov ch,2

up1:mov cl,2
mov al,[rsi]
up: rol al,4
mov bl,al
and al,0fh
add al,30h
mov [rdi],al
mov al,bl
inc rdi
dec cl
jnz up	
inc rdi
mov byte[rdi],'.'
inc rdi
dec rsi
dec ch
jnz up1
ret





