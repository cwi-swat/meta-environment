SUBDIRS = src toolbus

data_DATA = ${JARFILE}

ACLOCAL_FLAGS = -I .

EXTRA_DIST = program-check.m4 reconf \
             ${PACKAGE}-config.sh.src \
	     package

bin_SCRIPTS = ${PACKAGE}-config

CLEANFILES = ${PACKAGE}-config ${PACKAGE}-${VERSION}.pkg ${JARFILE}

JARFILE = ${PACKAGE}-${VERSION}.jar

.PHONY: ${JARFILE}
${JARFILE}:
	jar cf ${JARFILE} \
	  `cd ${top_builddir} && find . -name '*.class'`

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
             s@__VERSION__@$(VERSION)@g;\
             s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g' < $< > $@ \
        && chmod +x $@

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@

