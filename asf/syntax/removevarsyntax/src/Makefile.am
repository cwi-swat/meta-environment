# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = removevarsyntax
man_MANS     = removevarsyntax.1

data_DATA    = removevarsyntax.idef

EXTRA_DIST   = removevarsyntax.idef removevarsyntax.tif.c removevarsyntax.tif.h \
               removevarsyntax.pod removevarsyntax.1

removevarsyntax_SOURCES = removevarsyntax.c Remove-Var-Syntax.c
removevarsyntax_LDADD   = removevarsyntax.tif.o \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = removevarsyntax.tifs removevarsyntax.1

removevarsyntax.o : removevarsyntax.tif.h
