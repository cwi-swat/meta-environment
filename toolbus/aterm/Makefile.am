# $Id$

EXTRA_DIST		= tblog-interface.tb tblog.dict

ATINC			= $(ATERM)/include
ATBIN			= $(ATERM)/bin
ATLIB			= $(ATERM)/lib
TBDIR			= ${top_builddir}/toolbus
ATBLIB			= $(TOOLBUSLIB)/lib

INCLUDES		= -I$(TOOLBUSLIB)/include -I$(ATINC)

bin_PROGRAMS		= tifstoc tblog


tblog_SOURCES		= tblog_dict.c logger.tif.c tblog.c
tblog_LDADD		= -L$(ATBLIB) -lATB -L$(ATLIB) -lATerm

tifstoc_SOURCES         = tifstoc.c
tifstoc_LDADD           = -L$(ATBLIB) -lATB -L$(ATLIB) -lATerm

CLEANFILES		= logger.tif.[ch] tblog_dict.[ch] tblog-interface.tifs

tblog.o: tblog_dict.h logger.tif.h

logger.tif.c logger.tif.h: tblog-interface.tifs
	$(top_builddir)/aterm/tifstoc -tool logger $<

%_dict.c %_dict.h: %.dict
	$(ATBIN)/dicttoc -dict $<

tblog-interface.tifs: tblog-interface.tb
	$(TBDIR)/toolbus -gentifs $<
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/tblog-interface.tifs $@ ;\
	fi
