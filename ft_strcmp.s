			section			.text
			global			ft_strcmp

ft_strcmp:
			mov				rcx,0					; rcx : i=0, rdi = s1, rsi = s2, dl = temp char
			mov				rax,0					; rax = return value
			jmp				compare					; skipping the increment
increment:
			inc rcx									; incrementing i
compare:
			mov				dl, BYTE [rdi + rcx]	; moving s1[i] into a temp char
			cmp				dl, 0					; comparing it to 0 (null char)
			je				done					; if null, go to end
			cmp				BYTE [rsi + rcx], 0		; if s2[i]==0
			je				done					; end
			cmp				BYTE [rsi + rcx], dl
			je				increment				; if s1[i]==s2[i], i++ and restart
done:
			sub				dl, BYTE [rsi + rcx]	; tempchar = s1[i] - s2[i]
			cmp				dl, 0
			jg				positive				; if char > 0 jump to positive
			je				equal					; if char == 0 jump to equal
			jmp				negative				; else jump to negative
equal:
			mov				rax, 0					; set return value to 0, and return it
			ret
negative:
			mov				rax, -1
			ret
positive:
			mov				rax, 1
			ret