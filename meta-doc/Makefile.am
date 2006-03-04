SUBDIRS = guided-tour user-manual

EXTRA_DIST = make-rules package

ACLOCAL_FLAGS = -I .

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package
	cp $< $@
