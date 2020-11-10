			section			.text
			global			ft_strdup
			extern			malloc

ft_strdup:
			mov				rcx, 0					; i = 0
			push			rdi						; save str pointer
			jmp				compare					; skip increment
increment:
			inc				rcx						; i++
compare:
			cmp				BYTE [rdi + rcx], 0		; rdi = first argument, here s
			jne				increment
allocate:
			inc				rcx						; add 1 to i for the null character \0
			mov				edi, ecx 				; edi = ecx, where ecx is 32bits version of i, and edi is 32bits 1# argument that will go into malloc. 
			call			malloc					; call malloc(lenght+1), return address in rax
			pop				rdi						; retrieve str pointer and put it back to rdi
			cmp				rax, 0					; if malloc = 0, return 0
			je				error
			mov				rcx, 0					; i = 0
			jmp				copy					; skip incre
incre:
			inc				rcx						; i++
copy:
			cmp				BYTE [rdi + rcx], 0		; compare str[i] with 0
			mov				dl, BYTE [rdi + rcx]	; temp = str[i]
			mov				BYTE [rax + rcx], dl	; result[i] = temp
			jne				incre					; if str[i] != 0, loop
end:
			ret										; return rax and finish
error:
			mov				rax, 0					; set return value to 0
			ret										; return rax and finish