include ../make-rules

EXERCISES	= exercises.ltx pico.ltx

EXTRA_DIST	= $(EXERCISES) exercises.ps

CLEANFILES	= exercises.{aux,dvi,log,ps}

all:

doc: exercises.ps

exercises.ps: exercises.dvi
exercises.dvi: $(EXERCISES)

