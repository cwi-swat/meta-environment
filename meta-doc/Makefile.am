SUBDIRS = user-manual
DIST_SUBDIRS = user-manual


EXTRA_DIST = reconf make-rules asf+sdf-user-manual.ps meta-doc-$(VERSION).pkg

docdir   = $(prefix)/doc

doc_DATA = asf+sdf-user-manual.ps


asf+sdf-user-manual.ps:
	( cd user-manual; ${MAKE} )
	cp user-manual/manual.ps asf+sdf-user-manual.ps


