SUBDIRS = guided-tour user-manual

ACLOCAL_FLAGS = -I .

DIST_SUBDIRS = guided-tour user-manual

EXTRA_DIST = reconf make-rules guided-tour.pdf asf+sdf-user-manual.pdf meta-doc-$(VERSION).pkg

docdir   = $(prefix)/doc

doc_DATA = asf+sdf-user-manual.pdf guided-tour.pdf

asf+sdf-user-manual.pdf:
	( cd user-manual; ${MAKE} $@ )
	cp user-manual/manual.pdf $@

guided-tour.pdf:
	( cd guided-tour; ${MAKE} $@ )
	cp guided-tour/guided-tour.pdf $@

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@
