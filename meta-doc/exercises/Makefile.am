include ${top_srcdir}/doc/general-make

INPUTS = ${srcdir}

EXERCISES	= exercises.ltx pico.ltx

EXTRA_DIST	= $(EXERCISES) exercises.ps

CLEANFILES	= exercises.{aux,dvi,log,ps}

all:

doc: exercises.ps

exercises.ps: exercises.dvi
exercises.dvi: $(EXERCISES)

dist: exercises.ps
	cp exercises.ps ${DISTDIR}
