# $Id$

include $(top_srcdir)/make-rules

if BUILD_MANUAL
noinst_DATA = manual.pdf
endif

EXTRA_DIST = $(wildcard *.ltx) \
             $(wildcard *.ps) \
             $(wildcard *.pdf) \
             $(wildcard *.sty) \
             $(wildcard *.fig)


MANUAL	= manual.ltx

PSJES = Bool-example_asf.ps Bool-example_sdf2.ps Bool-example_trm.ps \
	Bool-example_trm2.ps Bool-example_trm3.ps Pico-Booleans_asf.ps \
	Pico-Booleans_sdf2.ps \
	debug-menu.ps edit-menu.ps file-menu.ps graph-menu.ps help-menu.ps \
	meta-Bool-example.ps meta-Pico-syntax.ps \
	meta-env-menu1.ps meta-env-menu2.ps meta-pico.ps \
	meta-start.ps module-menu.ps move-menu.ps new-open.ps open-file.ps \
	printer-setup.ps reduct_out.ps viewer.ps newarch.eps

EPSJES = ${PSJES:.ps=.eps}
PDFJES = ${EPSJES:.eps=.pdf}

CLEANFILES = manual.{aux,bbl,blg,dvi,ilg,ind,idx,log,ps,pdf,toc}

manual: asf+sdf-user-manual.pdf

manual.dvi: $(MANUAL)

spell:
	detex manual.ltx | spell -b +words.txt

asf+sdf-user-manual.ps: manual.dvi $(PSJES)
	makeindex manual.idx ;\
	latex manual.ltx ;\
	dvips -o $@ $<

asf+sdf-user-manual.pdf: $(MANUAL) $(PDFJES)
	makeindex manual.idx ;\
	pdflatex manual.ltx
