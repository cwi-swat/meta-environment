# $Id$

EXTRA_DIST		= tblog-interface.tb tblog.dict

ATINC			= $(ATERM)/include
ATBIN			= $(ATERM)/bin
ATLIB			= $(ATERM)/lib
TBDIR			= ${top_builddir}/toolbus
ATBDIR			= ${top_builddir}/aterm

INCLUDES		= -I$(ATINC)

lib_LIBRARIES		= libATB.a
bin_PROGRAMS		= tifstoc tblog
include_HEADERS		= atb-tool.h

libATB_a_SOURCES	= atb-tool.c

tifstoc_SOURCES		= tifstoc.c atb-tool.h
tifstoc_LDADD		= -L$(ATBDIR) -lATB -L$(ATLIB) -lATerm

tblog_SOURCES		= tblog_dict.c logger.tif.c tblog.c atb-tool.h
tblog_LDADD		= -L$(ATBDIR) -lATB -L$(ATLIB) -lATerm

CLEANFILES		= logger.tif.[ch] tblog_dict.[ch] tblog-interface.tifs

tblog.o: tblog_dict.h logger.tif.h

logger.tif.c logger.tif.h: tblog-interface.tifs
	$(ATBDIR)/tifstoc -tool logger $<

%_dict.c %_dict.h: %.dict
	$(ATBIN)/dicttoc -dict $<

tblog-interface.tifs: tblog-interface.tb
	$(TBDIR)/toolbus -gentifs $<
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/tblog-interface.tifs $@ ;\
	fi
