SUBDIRS = lift-error lower-error error-diff

EXTRA_DIST = \
	error-support.idef

pkgdata_DATA = \
	error-support.idef

noinst_HEADERS = \
	error-support.tif.h

bin_SCRIPTS = ${PACKAGE}-config

bin_PROGRAMS = \
	error-support

INCLUDES = \
	-I${top_srcdir}/lib \
	-I${ATERM}/include \
	-I${TOOLBUSLIB}/include 

error_support_SOURCES = \
	error-support.tif.c \
	error-support.c

error_support_LDADD = \
	-L../lib -lErrorAPI \
	-L${TOOLBUSLIB}/lib -lATB \
	-L${ATERM}/lib -lATerm \
	${SOCKLIBS}

CLEANFILES=${bin_SCRIPTS}

${PACKAGE}-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo ${prefix}/share/${PACKAGE}/errorapi-${VERSION}.jar:${prefix}/share/${PACKAGE}/locationapi-${VERSION}.jar" \
	) > $@ && chmod +x $@

IDEF = idef2tif
TIFS = tifstoc

tif:
	for i in `ls *.idef`; do \
	  ${IDEF} $$i; \
	  ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
	done

tif-clean:
	rm -f *.tifs *.tif.[ch]

