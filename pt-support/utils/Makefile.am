# $Id$

include $(top_srcdir)/Makefile.meta

SUBDIRS = implodePT filterPT

bin_PROGRAMS = \
	flattenPT \
	unparsePT \
	unparseProd \
	addPosInfo \
	ambtracker \
	apply-function \
	liftPT\
	comparePT \
	orderPT

INCLUDES = \
	-I$(top_srcdir)/libmept \
	-I$(top_srcdir)/libasfix2 \
	-I$(top_srcdir)/libconversion \
	-I$(top_srcdir)/libptmept  \
	$(ATERM_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS)

pkgdata_DATA = \
	unparser.idef \
	position-annotator.idef \
	apply-function.idef \
	ambiguity-reporter.idef 

apply_function_SOURCES = \
	apply-function.isrc \
	apply-function-main.c

apply_function_LDADD = \
	-L../libmept -lmept \
	$(TOOLBUSLIB_LIBS)

addPosInfo_SOURCES = \
	position-annotator.isrc \
	addPosInfo.c

addPosInfo_LDADD = \
	-L../libmept -lmept \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS)

flattenPT_SOURCES = flattenPT-main.c

flattenPT_LDADD	= \
	-L../libmept -lmept \
	$(ATERM_LIBS)

liftPT_SOURCES	= liftPT-main.c

liftPT_LDADD = \
	-L../libptmept -lPTMEPT \
	-L../libmept -lmept \
	$(ATERM_LIBS)

unparsePT_SOURCES = \
	unparser.isrc \
	unparsePT-main.c

unparsePT_LDADD = \
	../libmept/libmept.la \
	$(TOOLBUSLIB_LIBS)

comparePT_SOURCES = \
	comparePT-main.c

comparePT_LDADD = \
	-L../libmept -lmept \
	$(ATERM_LIBS)

orderPT_SOURCES = \
	orderPT-main.c

orderPT_LDADD = \
	-L../libmept -lmept \
	$(ATERM_LIBS)

unparseProd_SOURCES = unparseProd-main.c

unparseProd_LDADD = \
	-L../libmept -lmept \
	${ATERM_LIBS}

ambtracker_SOURCES = \
	ambtracker-main.c \
	ambiguity-reporter.isrc

ambtracker_LDADD = \
	-L../libmept -lmept \
	$(TOOLBUSLIB_LIBS) \
	$(ERROR_SUPPORT_LIBS)
