# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS      = asfe
noinst_LIBRARIES  = libeval.a

data_DATA         = asfe.idef

EXTRA_DIST        = asfe.idef

CLEANFILES        = asfe.tif.c asfe.tif.h asfe.tifs

libeval_a_SOURCES = asfe.c asfe.h asfix_utils.c asfix_utils.h \
                    preparation.c preparation.h eval-tide.c eval-tide.h \
                    traversals.c traversals.h memotable.h memotable.c

libeval_a_LIBADD  = asfe.tif.o

asfe_SOURCES		= main.c
asfe_LDADD		= libeval.a \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			${TIDELIB} $(SOCKLIBS)

INCLUDES		= ${TIDEINC} \
			-I$(ASC)/include \
			-I$(PT_SUPPORT)/include \
			-I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ASF_SUPPORT)/include \
			${TIDEDEF} ${TRAVERSALSDEF} ${LAYOUTDEF}

asfe.o : asfe.tif.h
