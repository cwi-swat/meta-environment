SUBDIRS = guided-tour user-manual
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
