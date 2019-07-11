%macro output 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endm
%macro content 3
	mov rbx,%1
	mov rsi,%2
	mov rdi,%3
%endm

global _start
section .data
msg db 10,"GDTR Content: ",10
msglen equ $-msg

msg1 db 10,"LDTR Content: ",10
msg1len equ $-msg1

msg2 db 10,"IDTR Content: ",10
msg2len equ $-msg2

msg3 db 0Ah,"TR Content:  "
msg3len equ $-msg3

msg4 db 0Ah,"MSW Content:  "
msg4len equ $-msg4

msgreal db "the system is in real mode"
lenreal equ $-msgreal

section .bss
gdtr_val resb 6
gdtr_ascii resb 24
ldtr_val resb 2
ldtr_ascii resb 8
idtr_val resb 6
idtr_ascii resb 24
tr_val resb 6
tr_ascii resb 24
msw_val resb 6
msw_ascii resb 24
section .text
_start:

smsw bx

shr bx,1
jnc dn

    sgdt [gdtr_val]
    content [gdtr_val],gdtr_val,gdtr_ascii
    call procedure
    output msg,msglen
    output gdtr_ascii,12
    
    sldt [ldtr_val]
    content [ldtr_val],ldtr_val,ldtr_ascii
    call procedure
    output msg1,msg1len
    output ldtr_ascii,12
    
    sidt [idtr_val]
    content [idtr_val],idtr_val,idtr_ascii
    call procedure
    output msg2,msg2len
    output idtr_ascii,12
    
    str [tr_val]
    content [tr_val],tr_val,tr_ascii
    call procedure
    output msg3,msg3len
    output tr_ascii,12
    
    smsw [msw_val]
    content [msw_val],msw_val,msw_ascii
    call procedure
    output msg4,msg4len
    output msw_ascii,12
    jmp ext
dn: output msgreal,lenreal
    
ext: mov rax,60
syscall


procedure:

	add rsi,5
	mov ch,6
l4: 	mov cl,2
	mov al,[rsi]
l3: 	rol al,4
	mov bl,al
	and al,0fh
	cmp al,9h
	ja l5
	add al,30h
	jmp next
l5: 	add al,37h

next: 	mov [rdi],al
	inc rdi
	mov al,bl
	dec cl
	jnz l3
	dec rsi
	dec ch
	jnz l4
	ret
