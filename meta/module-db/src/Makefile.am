# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS		= term-base
pkgdata_DATA		= term-base.idef

EXTRA_DIST		= term-base.idef

noinst_HEADERS		= term-base.tif.h \
                          table.h table-store.h
term_base_SOURCES	= term-base.tif.c term-base.c \
                          table.c table-store.c

term_base_LDADD	= -L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES	        = -I$(PT_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include  \
			-I$(ATERM)/include  \
			-I$(SDF_SUPPORT)/include
