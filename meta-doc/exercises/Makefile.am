include ${top_srcdir}/doc/general-make

EXERCISES	= exercises.ltx pico.ltx

EXTRA_DIST	= $(EXERCISES)
CLEANFILES	= exercises.{aux,dvi,log,ps}

all:

doc: exercises.ps

exercises.ps: exercises.dvi
exercises.dvi: $(EXERCISES)
