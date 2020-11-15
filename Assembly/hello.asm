format MZ
entry main:start

segment main use16

start:
	push	cs
	pop	ds

	push	string
	call	puts
	add	sp,2

	push	string2
	call	gets
	add	sp,2

	push	string1
	call	puts
	add	sp,2

	push	bx
	call	puts
	add	sp,2

	call	printf

	jmp	exit

exit:
	mov	ah,EXIT_PROGRAM
	mov	al,EXIT_SUCCESS
	int	21h

include "include/stdio.inc"

EXIT_PROGRAM = 0x4c
EXIT_SUCCESS = 0x00
EXIT_FAILURE = 0x01

string	db	"Hello. What is your name?",0xd,0xa,0
string1 db	0x0d,0x0a,"Hello, ",0
string2 db	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0