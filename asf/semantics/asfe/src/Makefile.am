# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS      = asfe

pkgdata_DATA      = asfe.idef
EXTRA_DIST        = asfe.idef

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
	pre-post.h\
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
	pre-post.c\
	test-runner.c\
	builtins.c

asfe_LDADD		= \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(ASC_SUPPORT)/lib -lasc-support-me \
                        -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			${TIDELIB} $(SOCKLIBS)

INCLUDES		= ${TIDEINC} \
			-I$(PT_SUPPORT)/include \
			-I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(ASC_SUPPORT)/include \
			-I$(top_builddir)/semantics/builtins/lib \
			${TIDEDEF} ${TRAVERSALSDEF} ${LAYOUTDEF}
