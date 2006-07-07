# $Id$

include $(top_srcdir)/make-rules

SUBDIRS=. html

docdir = ${prefix}/doc
doc_DATA = asfsdf-user-manual.pdf

noinst_DATA = ${doc_DATA} html
EXTRA_DIST = ${doc_DATA}

if MAINTAINER_MODE
MANUAL	= manual.ltx

PSJES = newarch.eps artefacts.ps architecture.ps
EPSJES = ${PSJES:.ps=.eps}
PDFJES = ${EPSJES:.eps=.pdf}

CLEANFILES = manual.aux manual.bbl manual.blg manual.dvi \
             manual.ilg manual.ind manual.idx manual.log \
             manual.ps  manual.pdf manual.toc manual.out \
             $(PDFJES)

manual: asfsdf-user-manual.pdf

manual.ps: $(MANUAL)
	pdflatex manual.ltx
	makeindex manual.idx
	bibtex manual
	pdflatex manual.ltx
	pdflatex manual.ltx
	acroread -toPostScript manual.pdf

spell:
	detex manual.ltx | spell -b +words.txt

asfsdf-user-manual.ps: manual.dvi $(PSJES)
	dvips -o $@ $<

asfsdf-user-manual.pdf: $(MANUAL) $(PDFJES)
	latex manual.ltx
	makeindex manual.idx
	bibtex manual
	latex manual.ltx
	latex manual.ltx
	dvipdf manual.dvi $@

html: $(MANUAL)
	latex2html $(MANUAL) \
		-t "ASF+SDF Meta-Environment Manual 2.0" \
		-dir html \
		-reuse 2 \
		-top_navigation 


endif
