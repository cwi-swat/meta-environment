# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = tifstoc tblog merge-tifs

EXTRA_DIST += \
	tblog-interface.tb \
	tblog.dict

CLEANFILES += \
	logger.[ch] \
	tblog_dict.[ch] \
	tblog-interface.tifs

INCLUDES = \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS)

tblog_SOURCES = tblog_dict.c logger.c tblog.c
tblog_LDADD = $(TOOLBUSLIB_LIBS)

tifstoc_SOURCES = tifs.c tifstoc.c
tifstoc_LDADD = $(TOOLBUSLIB_LIBS)

merge_tifs_SOURCES = tifs.c merge-tifs.c
merge_tifs_LDADD = $(TOOLBUSLIB_LIBS)

noinst_HEADERS = tblog_dict.h  tifs.h

tblog.o: tblog_dict.h logger.h

logger.c logger.h: tblog-interface.tifs
	$(top_builddir)/aterm/tifstoc -tool logger  $<

%_dict.c %_dict.h: %.dict
	$(ATERM_PREFIX)/bin/dicttoc -dict $<

tblog-interface.tifs: tblog-interface.tb
	$(top_builddir)/toolbus/toolbus -gentifs -output $@ $<
