
#   Unix make file for random test program

CFLAGS = -g
#CFLAGS = -O

ent:	ent.o iso8859.o randtest.o
	cc -O ent.o iso8859.o randtest.o -o ent -lm

ent.c:	iso8859.h randtest.h

DISTFILES = Makefile ent.c ent.exe ent.html \
	    entitle.gif entest.bat entest.mas \
	    iso8859.c iso8859.h randtest.c randtest.h

release:
	rm -f random.zip
	zip random.zip $(DISTFILES)

TESTFILE = entitle.gif

test:	ent
	sh entest.bat
	diff entest.mas entest.bak

lint:
	lint *.c

clean:
	rm -f *.o *.bak ent ent.zip
