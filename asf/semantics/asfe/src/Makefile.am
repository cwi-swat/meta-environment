# $Id$

SUBDIRS=api

include $(top_srcdir)/make_rules

bin_PROGRAMS      = asfe

pkgdata_DATA         = asfe.idef
EXTRA_DIST        = asfe.idef
CLEANFILES        = asfe.tif.c asfe.tif.h asfe.tifs

noinst_HEADERS = asf-api.h matching.h reduction.h environment.h values.h \
                 errors.h debug.h traversalfunctions.h equations.h \
                 pre-post.h memotable.h  evaluator.h

asfe_SOURCES = asfe.c evaluator.c equations.c debug.c traversalfunctions.c \
               memotable.c asf-api.c matching.c reduction.c environment.c \
               values.c errors.c pre-post.c

asfe_LDADD		= asfe.tif.o \
                        -L$(PT_SUPPORT)/lib -lmept \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(ASF_LIBRARY)/lib -lasf-builtins \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
                        -L./api -lASFAPI \
			${TIDELIB} $(SOCKLIBS)

INCLUDES		= ${TIDEINC} \
			-I$(ASC)/include \
			-I$(PT_SUPPORT)/include \
			-I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(ASF_LIBRARY)/include \
                        -I$(srcdir)/api \
			${TIDEDEF} ${TRAVERSALSDEF} ${LAYOUTDEF}
