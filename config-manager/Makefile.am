# $Id$

ACLOCAL_FLAGS = -I .

include ${top_srcdir}/make_rules

EXTRA_DIST = make_rules package

CLEANFILES = ${PACKAGE}-${VERSION}.pkg ${bin_SCRIPTS}

SUBDIRS = src

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

bin_SCRIPTS = ${PACKAGE}-config

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
	
${PACKAGE}-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo ${prefix}/share/${PACKAGE}/metaconfig-${VERSION}.jar" \
	) > $@ && chmod +x $@

