# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libsglr.la

bin_PROGRAMS= \
	sglr 

EXTRA_DIST = sglr.idef.src

CLEANFILES += sglr.idef

INCLUDES= \
	$(ATERM_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(PTABLE_SUPPORT_CFLAGS) \
	$(C_LIBRARY_CFLAGS) \
	-I$(top_srcdir)/src/parseForest \
	-I$(top_srcdir)/src/parser \
	-I$(top_srcdir)/src/parseTable \
	-I$(top_srcdir)/src/utils \
	-I$(top_srcdir)/src/gss

pkgdata_DATA= \
	sglr.idef

include_HEADERS= \
	sglrInterface.h \
	sglr.tif.h \
	inputStringBuilder.h \
	inputString-data.h \
	mainOptions.h \
        parseForest/filterOptions.h \
	parser/parserOptions.h 

noinst_HEADERS=\
	inputString-api.h \
	commandLineInterface.h \
	toolbusInterface.h \
	tokens.h \
	sglr-termstore.h \
        gss/gssNodeList.h \
        gss/gssEdgeList.h \
        gss/gssNode-data.h \
        gss/gssNode-api.h \
        gss/gssEdge-data.h \
        gss/gssEdge-api.h \
        gss/gss.h \
        gss/gssGarbageCollector.h \
        gss/reductionPath.h \
        gss/shiftQueue.h \
        parseForest/filters.h \
        parseForest/filterStats.h \
        parseForest/ambi-tables.h \
        parseForest/levels.h \
        parseTable/parseTable.h \
        parseTable/parseTableBuilder.h \
        parseTable/parseTableDB.h \
	parser/parser.h \
        utils/mem-alloc.h \
        utils/bitmap.h \
        utils/marking.h \
        utils/posmap.h \
        utils/memoryManagerGenerator.h \
        utils/list.h \
        utils/statusBar.h

libsglr_la_SOURCES= \
	sglrInterface.c \
	mainOptions.c \
	inputString.c \
	inputStringBuilder.c \
	sglr-termstore.c \
        gss/gssNodeList.c \
        gss/gssEdgeList.c \
        gss/gssNode.c \
        gss/gssEdge.c \
        gss/gss.c \
        gss/gssGarbageCollector.c \
        gss/reductionPath.c \
        gss/shiftQueue.c \
        parseForest/filters.c \
        parseForest/filterStats.c \
        parseForest/ambi-tables.c \
        parseForest/filterOptions.c \
        parseForest/levels.c \
        parseTable/parseTable.c \
        parseTable/parseTableBuilder.c \
        parseTable/parseTableDB.c \
        parser/parser.c \
        parser/parserOptions.c \
        utils/bitmap.c \
        utils/marking.c \
        utils/posmap.c \
        utils/list.c \
        utils/statusBar.c

libsglr_la_LDFLAGS = -avoid-version -no-undefined $(AM_LDFLAGS)

#libsglr_la_CPPFLAGS = -DFAST_API

sglr_SOURCES= \
	sglr.tif.c \
	sglr.c \
	toolbusInterface.c \
	commandLineInterface.c 

# The object files that need to be linked by the executable.
sglr_LDADD = \
	-L$(top_builddir)/src -lsglr \
	$(PT_SUPPORT_LIBS) \
	$(PTABLE_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(CONFIG_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) \
	$(C_LIBRARY_LIBS)

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

IDEF=idef2tif
TIFS=tifstoc

tif:
	for i in `ls *.idef`; do \
	  ${IDEF} $$i; \
	  ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs ;\
	done

tif-clean:
	rm -f *.tifs *.tif.[ch]
