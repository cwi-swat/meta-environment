# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = removevarsyntax

pkgdata_DATA    = removevarsyntax.idef


removevarsyntax_SOURCES = removevarsyntax.c Remove-Var-Syntax.c
removevarsyntax_LDADD   = removevarsyntax.tif.o \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = removevarsyntax.tifs 

removevarsyntax.o : removevarsyntax.tif.h
