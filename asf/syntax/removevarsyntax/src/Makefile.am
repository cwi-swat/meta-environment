# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUS)/include \
			-I$(ATERM)/include

bin_PROGRAMS = removevarsyntax
man_MANS     = removevarsyntax.1

data_DATA    = removevarsyntax.idef

EXTRA_DIST   = removevarsyntax.idef removevarsyntax.tif.c removevarsyntax.tif.h \
               removevarsyntax.pod

removevarsyntax_SOURCES = removevarsyntax.c RemoveVarSyntax.c
removevarsyntax_LDADD   = removevarsyntax.tif.o \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUS)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = removevarsyntax.tifs removevarsyntax.1

removevarsyntax.o : removevarsyntax.tif.h
