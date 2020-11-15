format MZ

main:
	push	cs
	pop	ds

	push	VGA
	call	set_vid_mode

	top:

	mov	cx,[VER_POS]
	draw_paddle:
	push	30
	push	0
	push	cx
	call	plot_pt
	inc	cx
	cmp	cx,100
	jb	draw_paddle

	mov	ah,01
	int	16h

	cmp	al,80d
	je	up_press
	jne	no_key

	up_press:
	add	[VER_POS],2

	no_key:
	jmp	top

        xor     ah,ah
        int     21h

        call    getche

        jmp     top

	push	TXT
	call	set_vid_mode

	call	getchar

	jmp	exit

exit:
	mov	ah,EXIT_PROGRAM
	mov	al,EXIT_SUCCESS
	int	21h

include "include\stdio.inc"
include "include\video.inc"

EXIT_PROGRAM	=	4ch
EXIT_SUCCESS	=	00h

VER_POS 	dw	90d
Y		dw	5