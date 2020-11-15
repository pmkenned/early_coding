atoi:
	; THIS FUNCTION IS NOT DONE YET

	push	bp
	mov	bp,sp
	add	bp,2

	add	bp,2
	mov	bx,[bp]

	xor	ax,ax
	xor	cx,cx

	add	bx,cx
	cmp	[bx],0x30

	ret