include ${top_srcdir}/make_rules

SUBDIRS		= META-INF images metastudio scripts . 

EXTRA_DIST	=

pkgdata_DATA	= meta-studio.jar \
		  jlfgr-1_0.jar

CLEANFILES	= meta-studio.jar

JARCLASSES	= `find . -name '*.class'`

JARFILES = \
	${srcdir}/META-INF/MANIFEST.MF \
	${srcdir}/META-INF/default.properties \
	${JARCLASSES}

meta-studio.jar: always
	FILES="${JARFILES}"; \
	jar cf meta-studio.jar $$FILES
	
always:
