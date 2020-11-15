	.386p
	ifdef ??version
	if    ??version GT 500H
	.mmx
	endif
	endif
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "foo.c"
	?debug	T "foo.c"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_TEXT	segment dword public use32 'CODE'
_foo	proc	near
?live1@0:
   ;	
   ;	int foo(int a, int b)
   ;	
	push      ebp
	mov       ebp,esp
   ;	
   ;	{
   ;	  int c = a+b;
   ;	
@1:
	mov       eax,dword ptr [ebp+8]
	add       eax,dword ptr [ebp+12]
   ;	
   ;	  return c;
   ;	
?live1@32: ; EAX = c
   ;	
   ;	}
   ;	
?live1@48: ; 
@3:
@2:
	pop       ebp
	ret 
_foo	endp
_main	proc	near
?live1@64:
   ;	
   ;	int main()
   ;	
	push      ebp
	mov       ebp,esp
	push      ebx
   ;	
   ;	{
   ;	  int x = 5;
   ;	
@4:
	mov       ebx,5
   ;	
   ;	  printf("Hello");
   ;	
?live1@96: ; EBX = x
	push      offset s@
	call      _printf
	pop       ecx
   ;	
   ;	  foo(3,x);
   ;	
	push      ebx
	push      3
	call      _foo
	add       esp,8
   ;	
   ;	  return 0;
   ;	
?live1@128: ; 
	xor       eax,eax
   ;	
   ;	}
   ;	
@6:
@5:
	pop       ebx
	pop       ebp
	ret 
_main	endp
_TEXT	ends
_DATA	segment dword public use32 'DATA'
s@	label	byte
	;	s@+0:
	db	"Hello",0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
	public	_foo
	public	_main
 extrn   _printf:near
	?debug	D "C:\Program Files\Borland\include\_nfile.h" 10459 12320
	?debug	D "C:\Program Files\Borland\include\_null.h" 10459 12320
	?debug	D "C:\Program Files\Borland\include\_defs.h" 10459 12320
	?debug	D "C:\Program Files\Borland\include\_stddef.h" 10459 12320
	?debug	D "C:\Program Files\Borland\include\stdio.h" 10459 12320
	?debug	D "foo.c" 13502 41789
	end
