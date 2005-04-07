# $Id$

SUBDIRS = error

pkgdata_DATA = ${JARFILE}

JARFILE = error-viewer.jar

CLEANFILES = ${JARFILE}

JARCLASSES = `find . -name '*.class'`

.PHONY: ${JARFILE}
${JARFILE}:
	jar cf $@ ${JARCLASSES}
