SUBDIRS		= metastudio scripts .

include ${top_srcdir}/make_rules

EXTRA_DIST	=

data_DATA	= meta-studio.jar

CLEANFILES	= meta-studio.jar

JARCLASSDIRS	= metastudio metastudio/graph
JARCLASSES	= ${JARCLASSDIRS:%=%/*.class}
JARIMAGES	= ${srcdir}/images/*.gif
JARFILES	= ${srcdir}/META-INF/MANIFEST.MF \
		${srcdir}/META-INF/default.properties \
		${JARIMAGES} ${JARCLASSES}

meta-studio.jar: ${JARFILES}
	FILES="${JARFILES}"; \
	jar cf meta-studio.jar $$FILES
