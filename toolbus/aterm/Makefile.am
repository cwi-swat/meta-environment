# $Id$

bin_PROGRAMS = tifstoc tblog merge-tifs

EXTRA_DIST = \
	tblog-interface.tb \
	tblog.dict

CLEANFILES = \
	logger.tif.[ch] \
	tblog_dict.[ch] \
	tblog-interface.tifs

ATINC = $(ATERM)/include
ATBIN = $(ATERM)/bin
ATLIB = $(ATERM)/lib
TBDIR = ${top_builddir}/toolbus
ATBLIB = $(TOOLBUSLIB)/lib

INCLUDES = \
	-I$(TOOLBUSLIB)/include \
	-I$(ATINC)

tblog_SOURCES = tblog_dict.c logger.tif.c tblog.c
tblog_LDADD = \
	-L$(ATBLIB) -lATB \
	-L$(ATLIB) -lATerm

tifstoc_SOURCES = tifs.c tifstoc.c
tifstoc_LDADD = \
	-L$(ATBLIB) -lATB \
	-L$(ATLIB) -lATerm

merge_tifs_SOURCES = tifs.c merge-tifs.c
merge_tifs_LDADD = \
	-L$(ATBLIB) -lATB \
	-L$(ATLIB) -lATerm

noinst_HEADERS = logger.tif.h  tblog_dict.h  tifs.h

tblog.o: tblog_dict.h logger.tif.h

logger.tif.c logger.tif.h: tblog-interface.tifs
	$(top_builddir)/aterm/tifstoc -tool logger $<

%_dict.c %_dict.h: %.dict
	$(ATBIN)/dicttoc -dict $<

tblog-interface.tifs: tblog-interface.tb
	$(TBDIR)/toolbus -gentifs $< -output $@
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/tblog-interface.tifs $@ ;\
	fi
