include $(top_srcdir)/Makefile.meta

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


asfe_DEPENDENCIES =
asfe_LDADD = \
	     $(ERROR_SUPPORT_LIBS) \
	     $(ASC_SUPPORT_LIBS)

INCLUDES = $(ASC_SUPPORT_CFLAGS) \
	     $(ERROR_SUPPORT_CFLAGS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
