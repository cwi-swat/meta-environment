# $Id$

ATINC			= $(ATERM)/include
ATBIN			= $(ATERM)/bin
ATLIB			= $(ATERM)/lib
TBDIR			= ${top_builddir}/toolbus
ATBDIR			= ${top_builddir}/aterm

INCLUDES		= -I$(ATINC)

lib_LIBRARIES		= libATB.a
bin_PROGRAMS		= tifstoc
include_HEADERS		= atb-tool.h

libATB_a_SOURCES	= atb-tool.c

tifstoc_SOURCES		= tifstoc.c atb-tool.h
tifstoc_LDADD		= -L$(ATBDIR) -lATB -L$(ATLIB) -lATerm


