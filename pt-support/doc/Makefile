include general-make

# fig2dev-3.2 is essential
FIG2DEV = fig2dev

doc: PTdoc.ps

all:

PTdoc.dvi: PTdoc.ltx      

PTdoc.ps: PTdoc.dvi
	#makeindex PTdoc.idx
	latex PTdoc.ltx
	dvips -o $@ $<

spell: PTdoc.ltx
	detex PTdoc.ltx | spell -b +words.txt

clean:
	rm -f *~ PTdoc.idx PTdoc.dvi PTdoc.ps

dist: PTdoc.ps
	cp PTdoc.ps ${DISTDIR}

install:    
