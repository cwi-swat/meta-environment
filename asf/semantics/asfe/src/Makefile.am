include $(top_srcdir)/make_rules

bin_PROGRAMS      = asfe

pkgdata_DATA      = asfe.idef
EXTRA_DIST        = asfe.idef.src

CLEANFILES = asfe.idef

noinst_HEADERS = \
	asfe.tif.h \
	matching.h \
	reduction.h \
	environment.h\
	values.h \
	errors.h\
	debug.h\
	traversalfunctions.h\
	equations.h \
	memotable.h\
	evaluator.h\
	test-runner.h\
	builtins.h

asfe_SOURCES =\
	asfe.tif.c\
	asfe.c\
	evaluator.c\
	equations.c\
	debug.c\
	traversalfunctions.c\
	memotable.c\
	matching.c\
	reduction.c\
	environment.c\
	values.c\
	errors.c\
	test-runner.c\
	builtins.c

asfe_LDADD = \
	     -L$(ERROR_SUPPORT)/lib -lLocationAPI \
	     $(ASC_LD_FLAGS)

INCLUDES = $(ASC_INCLUDES) \
	     -I$(ERROR_SUPPORT)/include \
	     ${TRAVERSALSDEF} ${LAYOUTDEF}

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
