# $Id$

DICTTOC			= $(ATERM)/bin/dicttoc
TIFSTOC			= ${top_builddir}/aterm/tifstoc
TOOLBUS			= ${top_builddir}/toolbus/toolbus

INCLUDES		= -I$(ATERM)/include
LDFLAGS			= -L$(ATERM)/lib

lib_LIBRARIES		= libATB.a
bin_PROGRAMS		= tifstoc tblog
include_HEADERS		= atb-tool.h

libATB_a_SOURCES	= atb-tool.c

tifstoc_SOURCES		= tifstoc.c atb-tool.h
tifstoc_LDADD		= libATB.a -lATerm

tblog_SOURCES		= tblog.c atb-tool.h
tblog_LDADD		= tblog_dict.o logger.tif.o -lATB -lATerm

EXTRA_DIST		= tblog-interface.tb tblog.dict

CLEANFILES		= logger.tif.[ch] tblog_dict.[ch] tblog-interface.tifs

tblog.o: tblog_dict.h logger.tif.h

logger.tif.c logger.tif.h: tblog-interface.tifs
	$(TIFSTOC) -tool logger $<

%_dict.c %_dict.h: %.dict
	$(DICTTOC) -dict $<

tblog-interface.tifs: tblog-interface.tb
	$(TOOLBUS) -gentifs $<
	cp $@ ${top_srcdir}/aterm
