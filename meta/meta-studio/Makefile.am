include ${top_srcdir}/make_rules

SUBDIRS		= META-INF images metastudio scripts . 


EXTRA_DIST	=

pkgdata_DATA	= meta-studio.jar

CLEANFILES	= meta-studio.jar

JARCLASSES	= `find . -name '*.class'`
JARIMAGES	= $(wildcard ${srcdir}/images/*.gif)

JARFILES = \
	 ${srcdir}/META-INF/MANIFEST.MF \
	 ${srcdir}/META-INF/default.properties \
	 ${JARIMAGES} \
	${JARCLASSES}

meta-studio.jar: always
	FILES="${JARFILES}"; \
	jar cf meta-studio.jar $$FILES
	
always:
