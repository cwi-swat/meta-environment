# $Id$

SUBDIRS=api

include $(top_srcdir)/make_rules

bin_PROGRAMS      = asfe

pkgdata_DATA      = asfe.idef
EXTRA_DIST        = asfe.idef

noinst_HEADERS = asfe.tif.h asf-api.h matching.h reduction.h environment.h\
		 values.h \
                 errors.h debug.h traversalfunctions.h equations.h \
                 pre-post.h memotable.h  evaluator.h

asfe_SOURCES = asfe.tif.c asfe.c evaluator.c equations.c debug.c \
	       traversalfunctions.c \
               memotable.c asf-api.c matching.c reduction.c environment.c \
               values.c errors.c pre-post.c

asfe_LDADD		= \
                        -L$(PT_SUPPORT)/lib -lmept \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(top_builddir)/semantics/builtins/lib \
			-lasf-builtins \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
                        -L./api -lASFAPI \
			${TIDELIB} $(SOCKLIBS)

INCLUDES		= ${TIDEINC} \
			-I$(PT_SUPPORT)/include \
			-I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(top_builddir)/semantics/builtins/lib \
                        -I$(srcdir)/api \
			${TIDEDEF} ${TRAVERSALSDEF} ${LAYOUTDEF}
