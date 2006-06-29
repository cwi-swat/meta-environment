# $Id: Makefile.am 18882 2006-06-27 08:49:58Z jurgenv $

EXTRA_DIST = Doxyfile.src  

if MAINTAINER_MODE

.PHONY: doc

doc: Doxyfile 
	doxygen

Doxyfile: Doxyfile.src
	sed 's@__PACKAGE__@${PACKAGE}@g' < $< > $@

endif
