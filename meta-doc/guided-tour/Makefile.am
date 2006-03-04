# $Id$

include $(top_srcdir)/make-rules

docdir = ${prefix}/doc
doc_DATA = asf+sdf-guided-tour.pdf
noinst_DATA = ${doc_DATA}
EXTRA_DIST = ${doc_DATA}

if MAINTAINER_MODE

MANUAL	= guided-tour.ltx

PSJES = $(wildcard *.ps)
EPSJES = ${PSJES:.ps=.eps}
PDFJES = ${EPSJES:.eps=.pdf}

CLEANFILES = guided-tour.aux guided-tour.bbl guided-tour.blg guided-tour.dvi \
             guided-tour.ilg guided-tour.ind guided-tour.idx guided-tour.log \
             guided-tour.ps  guided-tour.pdf guided-tour.toc guided-tour.out \
             $(PDFJES)

asf+sdf-guided-tour.ps: asf+sdf-guided-tour.pdf
	acroread -toPostScript $<

spell:
	detex guided-tour.ltx | spell -b +words.txt

asf+sdf-guided-tour.ps: asf+sdf-guided-tour.dvi $(PSJES)
	dvips -o $@ $<

asf+sdf-guided-tour.pdf: $(MANUAL) $(PDFJES)
	latex guided-tour.ltx
	makeindex guided-tour.idx
	bibtex guided-tour
	latex guided-tour.ltx
	latex guided-tour.ltx
	dvipdf guided-tour.dvi $@

endif
