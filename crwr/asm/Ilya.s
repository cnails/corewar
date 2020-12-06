.name "Real talk bot Ilya"
.comment "Be careful with our bot"

# comment line

lablik:	ld	%-5, r5
		ld	%1024,r4
push:	ld	%-5, r3
lol:	live %42
		sti	r4, %:lablik, r3
		add	r3, r5, r3
		sti	r4, %:lablik, r3
		add	r3, r5, r3
		sti	r4, %:lablik, r3
		add	r3, r5, r3
		sti	r4, %:lablik, r3
		add	r3, r5, r3
		sti	r4, %:lablik, r3
		add	r3, r5, r3
		xor	r3,%-430,r15
		zjmp	%:push
		and	r6, %0, r6
		zjmp	%:lol

how:	live	%42
		fork	%:lablik
		zjmp	%:how

