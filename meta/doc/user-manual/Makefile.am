
include ${top_srcdir}/doc/general-make

MANUAL		= manual.ltx

EXTRA_DIST	= $(MANUAL) manual.ps
CLEANFILES	= manual.{aux,bbl,blg,dvi,ilg,ind,idx,log,ps,toc}

all: manual.ps

doc: manual.ps

manual.dvi: $(MANUAL)

spell:
	detex manual.ltx | spell -b +words.txt

# when manual.dvi is up-to-date, it will have created manual.idx
# we need to run makeindex on this file, then re-latex and convert
# the dvi to postscript
manual.ps: manual.dvi
	makeindex manual.idx
	latex manual.ltx
	dvips -o $@ $<
