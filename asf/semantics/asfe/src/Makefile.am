include $(top_srcdir)/Makefile.meta

bin_PROGRAMS      = asfe

pkgdata_DATA      = asfe.idef

noinst_HEADERS = \
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
	asfe.isrc \
	main.c\
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
	$(PTABLE_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(ASC_SUPPORT_LIBS) 

AM_CPPFLAGS += \
	$(PTABLE_SUPPORT_CFLAGS) \
	$(ASC_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) 
