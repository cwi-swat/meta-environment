# $Id$
include ${top_srcdir}/make-rules

EXTRA_DIST = manual.ps

noinst_DATA = manual.ps

MANUAL	= manual.ltx

PSJES = Bool-example.asf.ps Bool-example.sdf2.ps Bool-example.trm.ps \
	Bool-example.trm2.ps Bool-example.trm3.ps Pico-Booleans.asf.ps \
	Pico-Booleans.sdf2.ps compiler-dir.ps compiler-warning.ps \
	debug-menu.ps edit-menu.ps file-menu.ps graph-menu.ps help-menu.ps \
	meta-Bool-example.ps meta-Pico-syntax.ps meta-booleans.ps \
	meta-env-menu.ps meta-env-menu1.ps meta-env-menu2.ps meta-pico.ps \
	meta-start.ps module-menu.ps move-menu.ps new-open.ps open-file.ps \
	printer-setup.ps reduct.out.ps viewer.ps CobolEditor.ps newarch.eps


CLEANFILES = manual.{aux,bbl,blg,dvi,ilg,ind,idx,log,ps,toc}

manual.dvi: $(MANUAL)

spell:
	detex manual.ltx | spell -b +words.txt

manual.ps: manual.dvi $(PSJES)
	makeindex manual.idx ;\
	latex manual.ltx ;\
	dvips -o $@ $<
