
SUBDIRS		= toolbus lib-c tide META-INF images examples scripts .

EXTRA_DIST      = $(wildcard *.pkg)

data_DATA	= tide.jar

JARCLASSDIRS	= tide tide/tool tide/tool/support \
		tide/tool/proclist tide/tool/ruleinspector tide/tool/srcviewer \
		tide/tool/prefeditor tide/tool/stackviewer

JARCLASSES	= ${JARCLASSDIRS:%=%/*.class}
JARIMAGES	= ${srcdir}/images/*.gif
JARFILES	= ${srcdir}/META-INF/MANIFEST.MF \
		${srcdir}/META-INF/tide-defaults.properties \
		${JARIMAGES}  ${JARCLASSES}

tide.jar: ${JARFILES}
	FILES="${JARFILES}"; \
	jar cf tide.jar $$FILES

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@

