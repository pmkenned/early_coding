format MZ

main:
	push	cs
	pop	ds

	mov	bx,0x80
	mov	cx,0x08

	call	getchar

	top:
	dec	cx

	mov	dx,insert
a0:	cmp	cx,6
	jne	a1
	mov	dx,caps
a1:	cmp	cx,5
	jne	a2
	mov	dx,num
a2:	cmp	cx,4
	jne	a3
	mov	dx,scroll
a3:	cmp	cx,3
	jne	a4
	mov	dx,alt
a4:	cmp	cx,2
	jne	a5
	mov	dx,ctrl
a5:	cmp	cx,1
	jne	a6
	mov	dx,lshift
a6:	cmp	cx,0
	jne	a7
	mov	dx,rshift
a7:	call	puts

	call	get_flags

	mov	dl,al
	and	dl,bl
	shr	dl,cl
	add	dl,0x30

	call	putchar

	shr	bx,1

	cmp	cx,0
	jne	top

	jmp	exit

exit:
	mov	ax,4c00h
	int	21h

getchar:
	mov	ah,01
	int	21h
	ret

putchar:
	push	ax
	mov	ah,02h
	int	21h
	pop	ax
	ret

puts:
	mov	ah,09h
	int	21h
	ret

get_flags:
	mov	ah,12h
	int	16h
	ret

prompt	db	"Press a key:",24h
insert	db	0xD,0xA,"Insert:",9,9,24h
caps	db	0xD,0xA,"Caps lock:",9,24h
num	db	0xD,0xA,"Num lock:",9,24h
scroll	db	0xD,0xA,"Scroll lock:",9,24h
alt	db	0xD,0xA,"Alt pressed:",9,24h
ctrl	db	0xD,0xA,"Ctrl pressed:",9,24h
lshift	db	0xD,0xA,"Left shift:",9,24h
rshift	db	0xD,0xA,"Right shift:",9,24h