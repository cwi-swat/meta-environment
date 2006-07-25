# $Id$

SUBDIRS = implodePT 

EXTRA_DIST = \
	unparser.idef.src \
	position-annotator.idef.src \
	apply-function.idef.src \
	ambiguity-reporter.idef.src

CLEANFILES = \
	     unparser.idef \
	     position-annotator.idef \
	     apply-function.idef \
	     ambiguity-reporter.idef

bin_PROGRAMS = \
	flattenPT \
	unparsePT \
	unparseProd \
	addPosInfo \
	ambtracker \
	apply-function \
	liftPT\
	comparePT

INCLUDES = \
	-I${top_srcdir}/libmept \
	-I${top_srcdir}/libasfix2 \
	-I${top_srcdir}/libconversion \
	-I${top_srcdir}/libptmept  \
	${ATERM_CFLAGS} \
	${ERROR_SUPPORT_CFLAGS} \
	${TOOLBUSLIB_CFLAGS}

pkgdata_DATA = \
	unparser.idef \
	position-annotator.idef \
	apply-function.idef \
	ambiguity-reporter.idef 

noinst_HEADERS = \
	unparser.tif.h \
	apply-function.tif.h \
	position-annotator.tif.h  \
	ambiguity-reporter.tif.h 

apply_function_SOURCES = \
	apply-function.tif.c \
	apply-function.c

apply_function_LDADD = \
	-L../libmept -lmept \
	${TOOLBUSLIB_LIBS} 

addPosInfo_SOURCES = \
	position-annotator.tif.c \
	addPosInfo.c

addPosInfo_LDADD = \
	-L../libmept -lmept \
	${ERROR_SUPPORT_LIBS} \
	${TOOLBUSLIB_LIBS} 

flattenPT_SOURCES = flattenPT-main.c

flattenPT_LDADD	= \
	-L../libmept -lmept \
	${ATERM_LIBS}

liftPT_SOURCES	= liftPT-main.c

liftPT_LDADD = \
	-L../libptmept -lPTMEPT \
	-L../libmept -lmept \
	${ATERM_LIBS}

unparsePT_SOURCES = \
	unparser.tif.c \
	unparsePT-main.c

unparsePT_LDADD = \
	../libmept/libmept.a \
	${TOOLBUSLIB_LIBS}

comparePT_SOURCES = \
	comparePT-main.c

comparePT_LDADD = \
	-L../libmept -lmept \
	${ATERM_LIBS}

unparseProd_SOURCES = unparseProd-main.c

unparseProd_LDADD = \
	-L../libmept -lmept \
	${ATERM_LIBS}

ambtracker_SOURCES = \
	ambtracker-main.c \
	ambiguity-reporter.tif.c

ambtracker_LDADD = \
	-L../libmept -lmept \
	${TOOLBUSLIB_LIBS} \
	${ERROR_SUPPORT_LIBS} 

IDEF = idef2tif
TIFS = tifstoc

tif:
	for i in `ls *.idef`; do \
	  ${IDEF} $$i; \
	  ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
	done

tif-clean:
	rm -f *.tifs *.tif.[ch]

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
