SUBDIRS = user-manual
DIST_SUBDIRS = user-manual

EXTRA_DIST = reconf make-rules asf+sdf-user-manual.pdf meta-doc-$(VERSION).pkg

docdir   = $(prefix)/doc

doc_DATA = asf+sdf-user-manual.pdf

asf+sdf-user-manual.pdf:
	( cd user-manual; ${MAKE} $@ )
	cp user-manual/manual.pdf $@
