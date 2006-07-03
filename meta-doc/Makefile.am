SUBDIRS = 

EXTRA_DIST = make-rules package

ACLOCAL_FLAGS = -I .

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg
bin_SCRIPTS = ${PACKAGE}-config

CLEANFILES = ${bin_SCRIPTS} ${noinst_SCRIPTS}

${PACKAGE}-${VERSION}.pkg: package
	cp $< $@

${PACKAGE}-config: Makefile
	(echo "#! /bin/sh" ; \
	 echo "echo \"${prefix}\"" ) > $@ && chmod +x $@
