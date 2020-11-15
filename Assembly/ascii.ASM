format MZ

main:
	push	cs
	pop	ds

	xor	cx,cx
	ascii_loop:
	;{

		push	cx
		call	putchar
		add	sp,2

		push	\n
		call	putchar
		add	sp,2

		inc	cx
		cmp	cx,0xff
		jbe	ascii_loop
	;}

	jmp	exit

exit:
	mov	ah,EXIT_PROGRAM
	mov	al,EXIT_SUCCESS
	int	21h

include "include\stdio.inc"

EXIT_PROGRAM	= 0x4c
EXIT_SUCCESS	= 0x00