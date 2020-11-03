			section			.text
			global			ft_strcpy

ft_strcpy:
			mov				rcx, 0						; rcx is my counter, I set it to 0, i = 0
			jmp				compare						; jump to label compare
copy:
			mov				dl, BYTE [rsi + rcx]		; copy src[i] into a temp char value dl
			mov				BYTE [rdi + rcx], dl		; copy the temp into dest[i]
			inc				rcx							; increment i
compare:
			cmp				BYTE [rsi + rcx], 0			; compare src[i]
			jne				copy						; if the result of the comparaison is !=, jump to copy
			mov				dl, BYTE [rsi + rcx]		; else copy src[i] to dest[i] (through dl), which should be \0
			mov				BYTE [rdi + rcx], dl
done:
			mov				rax, rdi					; move dest pointer to return value
			ret