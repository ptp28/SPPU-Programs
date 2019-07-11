%macro read 3
	mov rax,0
	mov rdi,%1
	mov rsi,%2
	mov rdx,%3
	syscall
%endm
%macro file 1
	mov rax,2
	mov rdi,%1
   	mov rsi,0102o
	mov rdx,0666o
	syscall
%endm
%macro close 1
	mov rax,3
	mov rdi,%1
	syscall
%endm
%macro output 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endm	
EXTERN cnob,cnol,cocc
global str1,bl,cnt,cnt2,cnt3
global _start
section .data
	msg db 10,13,"Enter 1.No. of spaces",10, "2.No. of lines",10," 3.No. of occurence",10, "4.Exit",10
	msglen equ $-msg
	msg2 db 10,13,"Enter a character to searched:"
	msg2len equ $-msg2
	msg3 db 10,13,"No of spaces:"
	msglen3 equ $-msg3
	msg4 db 10,13,"No of lines:"
	msglen4 equ $-msg4
	msg5 db 10,13,"No of characters:"
	msglen5 equ $-msg5

	fn db 'a.txt'
 	cnt db 00
 	cnt2 db 00
 	cnt3 db 00
 	len db 30h 

section .bss
	str1 resb 30
	fh resb 8
	no resb 2
 	choice resb 2
 
 section .text
_start:
 	file fn
 	mov [fh],rax
		 
label:
 	output msg,msglen
	read 0,choice,2
	mov dl,[choice]
	cmp dl,'1'
 	jne p
  	read [fh],str1,30
	call cnob
	output msg3,msglen3
	output cnt,1
	jmp _start
p:
	cmp dl,'2'
	jne q
	read [fh],str1,30
	call cnol
	output msg4,msglen4
	output cnt2,1
	jmp _start
q:
	cmp dl,'3'
	jne s
	output msg2,msg2len
	read 0,no,1
	mov bl,[no]
	read [fh],str1,30
	call cocc
	output msg5,msglen5
	output cnt3,1
	jmp _start
s:
	mov rax,60
	syscall	

