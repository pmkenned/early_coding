set_color:
	push	bp
	mov	bp,sp
	add	bp,2

	add	bp,2	; arg1 = color
	mov	bx,[bp] ; move arg1 to bx

	pop	bp
	ret

mov_cursor:
	push	bp
	mov	bp,sp
	add	bp,2

	add	bp,2	; arg2 = col
	mov	dh,[bp] ; move col to dh
	add	bp,2	; arg1 = row
	mov	dl,[bp] ; move row to dl
	push	ax	; back up ax
	mov	ah,02h	; fn#2 - move cursor
	xor	bh,bh	; video page 0
	int	10h	; call int 10h function 2
	pop	ax	; retrieve ax

	pop	bp
	ret

set_vid_mode:
	push	bp
	mov	bp,sp
	add	bp,2

			; Prepare for writing to the video buffer
	mov  di, 0a000h ; Put the video segment into DI
	mov  es, di	;  so it can easily be put into ES
	xor  di, di	; Start writing at coordinates (0,0)

	add	bp,2	; arg1 = vid mode
	push	ax	; back up ax
	mov	ah,00h	; fn#0 - set vid mode
	mov	al,[bp] ; move vid mode to al
	int	10h	; call int 10h function 0
	pop	ax

	pop	bp
	ret

plot_pt:
	push	bp
	mov	bp,sp
	add	bp,2

	add	bp,2		; arg3 = col
	mov	ax, 320 	; mov 320 into ax
	mul	dword [bp]	; mul ax by col
	add	bp,2		; arg2 = row
	mov	di, ax		; mov ax into video segment
	add	di, [bp]	; add row
	add	bp,2		; arg1 = color
	mov	al, [bp]	; mov color to al
				;
	stosb			; plot point

	pop	bp
	ret

clear_scr:

	; THIS FUNCTION IS NOT DONE YET

	xor	cx,cx

	clear_scr0:

	mov	ax,320
	mul	[Y]
	mov	di,ax
	add	di,5
	mov	al,7

	stosb

	ret

TXT	=      03h
VGA	=      13h