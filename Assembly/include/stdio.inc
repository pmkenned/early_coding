getch:
	xor	ax,ax	; fn#0 - wait for key-press
	int	16h	; keyboard interrupt
	ret

getche:
	call	getch
	and	ax,0x00FF	; mask out scan code in ah
	push	ax		; arg for putchar
	call	putchar 	; print al
	add	sp,2
	ret

getchar:
	mov	ah,01h	; fn#1 - wait for and print character
	int	21h	; call int 21h function 1
	ret

gets:
	push	bp	; push base pointer onto the stack
	mov	bp,sp	; move stack pointer into base pointer
	add	bp,2

	add	bp,2	; move base pointer to arg1
	mov	bx,[bp] ; move address of arg1 (string) to bx
	dec	bx

	call	getche		; echo kery-press and store ASCII code in ax
	and	ax,0x00FF	; mask out scan code in ah
	gets1:			; loop label
	mov	[bx],ax 	; move first char into ax
	call	getche		; echo key-press and store ASCII code in ax
	and	ax,0x00FF	; mask out scan code in ah
	inc	bx		; increment bx 
	cmp	ax,0x0d 	; if user didn't press 'enter'
	jne	gets1		; then continue loop

	mov	byte [bx],NULL	; terminate string with NULL
	mov	bx,[bp] 	; move begining of string to bx

	pop	bp		; retrieve base pointer
	ret

kbhit:
	mov	ah,01	; fn#1 - returns key to ax if char is in buffer (but does not remove)
	int	16h	; keyboard interrupt
	ret

putchar:
	push	bp	; push base pointer onto stack
	mov	bp,sp	; move stack pointer into base pointer
	add	bp,2

	add	bp,2	; move base pointer to arg1
	mov	dl,[bp] ; move arg1 into dl
	push	ax	; backup ax
	mov	ah,02h	; fn#2 - print character
	int	21h	; call int 21h function 2
	pop	ax	; retrieve ax

	pop	bp	; retrieve base pointer
	ret

puts:
	push	bp		; push base pointer onto stack
	mov	bp,sp		; move stack pointer into base pointer
	add	bp,2

	add	bp,2		; move base pointer to arg1
	mov	bx,[bp] 	; move address of arg1 to bx
	and	bx,0x00FF	; mask out high byte (leaving ASCII)

	puts1:
	push	word [bx]
	call	putchar
	add	sp,2
	inc	bx
	cmp	byte [bx],NULL
	jne	puts1

	pop	bp
	ret

printf:
	push	bp	; push base pointer onto stack
	mov	bp,sp	; move stack pointer into base pointer
	add	bp,2

	; THIS FUNCTION IS NOT DONE YET

	add	bp,2
	mov	bx,[bp]

	printf0:

	cmp	[bx],byte 0x25	; '%'
	jne	printf2

	printf1:

	inc	bx
	cmp	[bx],byte 0x64	; 'd'
	je	printf_d
	cmp	[bx],byte 0x66	; 'f'
	je	printf_f
	cmp	[bx],byte 0x63	; 'c'
	je	printf_c

	jmp	printf3

	printf_d:
	jmp	printf3

	printf_f:
	jmp	printf3

	printf_c:
	add	bp,2
	mov	dl,[bp]
	mov	ah,02
	int	21h
	sub	bp,2
	jmp	printf3

	printf_s:
	jmp	printf3

	printf2:
	push	word [bx]
	call	putchar
	add	sp,2

	printf3:

	inc	bx
	cmp	[bx],byte 0
	jne	printf0

	pop	bp
	ret

stdin		= 0
stdout		= 1
stderr		= 2

SEEK_CUR	= 1
SEEK_END	= 2
SEEK_SET	= 0

NULL		= 0
EOF		= -1
BUFSIZE		= 512

\a		= 0x07
\b		= 0x08
\n		= 0x0a
\t		= 0x09