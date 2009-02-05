# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libsglr.la

bin_PROGRAMS= \
	sglr 

INCLUDES= \
	-I$(top_srcdir)/src/parseForest \
	-I$(top_srcdir)/src/parser \
	-I$(top_srcdir)/src/parseTable \
	-I$(top_srcdir)/src/utils \
	-I$(top_srcdir)/src/gss \
	$(ATERM_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(PTABLE_SUPPORT_CFLAGS) \
	$(C_LIBRARY_CFLAGS) \
	-DFAST_API 
#	-DSGLR_COLLECT_STATISTICS

pkgdata_DATA= \
	sglr.idef

include_HEADERS= \
	sglrInterface.h \
	inputStringBuilder.h \
	inputString-data.h \
	inputString-api.h \
	mainOptions.h \
        parseForest/filterOptions.h \
	parser/parserOptions.h \
	parseForest/filters.h \
        parseTable/parseTableDB.h \
        parseTable/parseTable.h \
        tokens.h

noinst_HEADERS=\
	commandLineInterface.h \
	toolbusInterface.h \
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
        parseForest/ambi-tables.h \
        parseForest/levels.h \
        parseTable/parseTableBuilder.h \
	parser/parser.h \
	parser/parserStatistics.h \
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
        parseForest/ambi-tables.c \
        parseForest/filterOptions.c \
        parseForest/levels.c \
        parseTable/parseTable.c \
        parseTable/parseTableBuilder.c \
        parseTable/parseTableDB.c \
        parser/parser.c \
	parser/parserStatistics.c \
        parser/parserOptions.c \
        utils/bitmap.c \
        utils/marking.c \
        utils/posmap.c \
        utils/list.c \
        utils/statusBar.c

libsglr_la_LDFLAGS = -avoid-version -no-undefined $(AM_LDFLAGS) #-L/export/scratch1/economop/tools/google-perftools-0.93/lib -ltcmalloc

libsglr_la_LIBADD = \
	-L$(top_builddir)/src \
	$(PT_SUPPORT_LIBS) \
	$(PTABLE_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(CONFIG_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) \
	$(C_LIBRARY_LIBS)

sglr_SOURCES= \
	sglr.isrc \
	main.c \
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
