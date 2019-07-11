EXTERN str1,bl,cnt,cnt2,cnt3
global cnob,cnol,cocc
global _s
section .text
_s:
	cnob:
		mov cl,30h
	 	l2:
	 		cmp byte[rsi],20h
	 		jne l1
	 		inc byte[cnt]
	 	l1:
	 		inc rsi
	 		dec cl
	 		jnz l2
	 	mov ch,[cnt]
	 	add ch,30h
	 	mov[cnt],ch
		ret
	cnol:
		mov cl,30h
		l3:
			cmp byte[rsi],0Ah
			jne l4
			inc byte[cnt2]	
		l4:
			 inc rsi
			 dec cl
			 jnz l3
		mov ch,[cnt2]
		add ch,30h
		mov [cnt2],ch
		ret		
 	cocc:
		mov cl,30h
		l5:	
			cmp byte[rsi],bl
			jne l6
			inc byte[cnt3]
		l6:
			inc rsi
			dec cl
			jnz l5	
		mov ch,[cnt3]
		add ch,30h
		sub ch,01h
		mov [cnt3],ch
		ret

	mov rax,60
	syscall
