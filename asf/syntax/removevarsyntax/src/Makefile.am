# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include


EXTRA_DIST = removevarsyntax.idef 
pkgdata_DATA = removevarsyntax.idef
noinst_HEADERS = removevarsyntax.tif.h
bin_PROGRAMS = removevarsyntax
removevarsyntax_SOURCES = removevarsyntax.c Remove-Var-Syntax.c \
			  removevarsyntax.tif.c
removevarsyntax_LDADD   = \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)
