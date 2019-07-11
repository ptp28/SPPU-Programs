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
	a dd 01.0
	b dd -04.00
	c dd 04.00
	two dd 02.00
	four dd 04.00
	one dd -01.00
	h100 dq 10000
	msg db 10,13
	msgl equ $-msg
	
section .bss
madd resd 2
mean resd 2
nc resd 2
vb resd 2
p resd 2
mean1 rest 1
dev resd 2
dev2 resd 2
va resd 2
dev1 rest 1
z rest 1
devi resb 7
meanascii resb 7
vari resb 7
var resb 1
section .text
_start:
finit
fldz
mov rsi,b
fadd dword[rsi]
fmul dword[b]
fst dword[va]


fld dword[a]
fmul dword[c]
fmul dword[four]
fst dword[madd]
fld dword[va]
fsub dword[madd]
fsqrt
fst dword[mean]
fld dword[b]
fmul dword[one]
fst dword[vb]
fadd dword[mean]
fst dword[dev2]
fld dword[a]
fmul dword[two]
fst dword[p]
fld dword[dev2]
fdiv dword[p]
fimul dword[h100]
fbstp tword[dev1]
mov rsi,dev1
mov ch,09h
asd:
     inc rsi
     dec ch
     jnz asd
     
mov al,byte[rsi]
bt ax,7
jnC next
mov ah,'-'
mov [var],ah
output var,1


next:
mov rsi,dev1
add rsi,2
mov rdi,devi
call procedure
output devi,7
output msg,msgl
fld dword[vb]
fsub dword[mean]
fdiv dword[p]
fimul dword[h100]
fbstp tword[z]

mov rsi,z
mov ch,09h
asd1:
     inc rsi
     dec ch
     jnz asd1
     
mov al,byte[rsi]
bt ax,7
jnC next1
mov ah,'-'
mov [var],ah
output var,1

next1:
mov rsi,z
add rsi,2
mov rdi,vari
call procedure
output vari,7
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





