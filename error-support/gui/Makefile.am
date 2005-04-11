# $Id$
include ${top_srcdir}/make_rules

pkgdata_DATA = ${JARFILE} error-viewer.idef
EXTRA_DIST = ${JARFILE} error-viewer.idef

bin_SCRIPTS = error-viewer-config

JARFILE = error-viewer.jar
JARFILE_ENV = JAR=${JARFILE}

JARS_ENV = JARS=${EXTERNAL_JARS}:${top_srcdir}/lib/errorapi-${VERSION}.jar:${top_srcdir}/gui/lib/jlfgr-1_0.jar

error-viewer-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo ${prefix}/share/${PACKAGE}/error-viewer.jar" \
	) > $@ && chmod +x $@

if MAINTAINER_MODE
${JARFILE}:
	${JARS_ENV} ant dist

jtif:
	${IDEF} error-viewer.idef
	${TOOLBUS}/bin/tifstojava -tool error-viewer -tifs error-viewer.tifs \
		-package nl.cwi.sen1.error.viewer -swing

clean-local:
	${JARFILE_ENV} ant clean
endif
