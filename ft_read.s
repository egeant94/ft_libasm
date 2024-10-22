			section			.text
			global			ft_read
			extern			__errno_location

ft_read:
			mov				rax, 0				; 0 is the call for read
			syscall
			cmp				rax, 0
			jl				error				; if result < 0, call error
			ret

error:
			neg				rax					; positive the error code
			mov				rdi, rax			; save error code on slack
			call			__errno_location	; call errno localtion which returns errno adress in rax
			mov				[rax], rdi			; put the error code on rax address
			mov				rax, -1				; set return value to -1
			ret									; and return it 