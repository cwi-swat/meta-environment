SUBDIRS = aterm

ACLOCAL_FLAGS = -I .

EXTRA_DIST = program-check.m4 reconf \
             toolbuslib-config.sh.src \
	     package

bin_SCRIPTS = toolbuslib-config

CLEANFILES = toolbuslib-config ${PACKAGE}-${VERSION}.pkg

% : %.sh.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

EXTRA_DIST+=Doxyfile.src  

if MAINTAINER_MODE

CLEANFILES+=Doxyfile

.PHONY: doc

doc: Doxyfile 
	doxygen

Doxyfile: Doxyfile.src
	sed 's@__PACKAGE__@${PACKAGE}@g' < $< > $@

endif
