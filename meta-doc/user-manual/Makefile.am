# $Id$

include $(top_srcdir)/make-rules

if BUILD_MANUAL
noinst_DATA = asf+sdf-user-manual.pdf
endif

EXTRA_DIST = $(wildcard *.ltx) \
             $(wildcard *.ps) \
             $(wildcard *.pdf) \
             $(wildcard *.sty) \
             $(wildcard *.fig)

MANUAL	= manual.ltx

PSJES = newarch.eps

EPSJES = ${PSJES:.ps=.eps}
PDFJES = ${EPSJES:.eps=.pdf}

CLEANFILES = manual.aux manual.bbl manual.blg manual.dvi \
             manual.ilg manual.ind manual.idx manual.log \
             manual.ps  manual.pdf manual.toc manual.out \
             $(PDFJES)

manual: asf+sdf-user-manual.pdf

manual.ps: $(MANUAL)
	pdflatex manual.ltx
	makeindex manual.idx
	bibtex manual
	pdflatex manual.ltx
	pdflatex manual.ltx
	acroread -toPostScript manual.pdf

spell:
	detex manual.ltx | spell -b +words.txt

asf+sdf-user-manual.ps: manual.dvi $(PSJES)
	dvips -o $@ $<

asf+sdf-user-manual.pdf: $(MANUAL) $(PDFJES)
	latex manual.ltx
	makeindex manual.idx
	bibtex manual
	latex manual.ltx
	latex manual.ltx
	dvipdf manual.dvi
