format MZ

main:
	push	cs
	pop	ds

	push	VGA
	call	set_vid_mode
	add	sp,2

	push	[Color]
	push	[X]
	push	[Y]
	call	plot_pt
	add	sp,6

	call	getchar

	push	TXT
	call	set_vid_mode
	add	sp,2

	jmp	exit

exit:
	mov	ah,EXIT_PROGRAM
	mov	al,EXIT_SUCCESS
	int	21h

include "include/stdio.inc"
include "include/video.inc"

EXIT_PROGRAM	=	4ch
EXIT_SUCCESS	=	00h

Text		db	"Paul Kennedy",0
X		dw	20
Y		dw	5
Color		dw	7