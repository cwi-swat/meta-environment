# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sglr.idef
CLEANFILES = sglr.tifs sglr.tif.[ch]

INCLUDES = \
	-I$(top_srcdir)/libsglr \
	-I$(PT_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

pkgdata_DATA = sglr.idef
noinst_HEADERS = getopt.h

bin_PROGRAMS = sglr 

sglr_SOURCES = sglr.tif.c sglr.tif.h sglr-main.c getopt.c getopt1.c
sglr_LDADD = \
	-L$(top_builddir)/libsglr -lsglr \
	-L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)
