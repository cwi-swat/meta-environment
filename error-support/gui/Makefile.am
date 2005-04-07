# $Id$

pkgdata_DATA = ${JARFILE}

CLASSFILES = `find . -name "*.class"`
CLEANFILES = \
	     ${JARFILE} \
	     ${CLASSFILES}

JARFILE = error-viewer.jar

JARS_ENV = JARS=${EXTERNAL_JARS}:${top_srcdir}/lib/errorapi-${VERSION}.jar:${top_srcdir}/gui/lib/jlfgr-1_0.jar

${JARFILE}:
	${JARS_ENV} ant
