
include $(top_srcdir)/Makefile.top.meta

SUBDIRS = src schemas script

ACLOCAL_AMFLAGS = -I .

if MAINTAINER_MODE

.PHONY: doc

doc:
	(cd src; make doc)

endif



