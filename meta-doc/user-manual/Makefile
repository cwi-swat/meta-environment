include general-make

CHAPS	= 
PICS	= 

# fig2dev-3.2 is essential
#FIG2DEV	= /home/mdejonge/bin/fig2dev-3.2
FIG2DEV	= fig2dev

doc: manual.ps

all: 

manual.dvi: manual.ltx

# when manual.dvi is up-to-date, it will have created manual.idx
# we need to run makeindex on this file, then re-latex and convert
# the dvi to postscript
manual.ps: manual.dvi
	makeindex manual.idx
	latex manual.ltx
	dvips -o $@ $<

spell: at.ltx
#	detex at.ltx | spell +words.txt
	detex manual.ltx | spell -b +words.txt

clean:
	rm -f *~ manual.idx \
		manual.dvi manual.ps

dist: manual.ps
	cp manual.ps ${DISTDIR}

install:

# end of Makefile
