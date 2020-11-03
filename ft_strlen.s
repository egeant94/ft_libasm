			section			.text
			global			ft_strlen

ft_strlen:
			mov				rax, 0					; set rax, the return value, to 0
			jmp				compare					; jump to compare section
increment:
			inc				rax						; increment rax
compare:
			cmp				BYTE [rdi + rax], 0		; compare BYTE (char *) of pointer rdi (1st argument passed to the function, so the str) + rax, our increment, to the value 0.
			jne				increment				; if comparaison !=, jump to increment
done:
			ret										; return rax