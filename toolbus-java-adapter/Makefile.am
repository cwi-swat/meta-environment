SUBDIRS = src toolbus

data_DATA = ${JARFILE}

ACLOCAL_FLAGS = -I .

EXTRA_DIST = program-check.m4 reconf \
             ${PACKAGE}-config.sh.src \
	     $(wildcard *.pkg)

bin_SCRIPTS = ${PACKAGE}-config

CLEANFILES = ${PACKAGE}-config ${PACKAGE}-${VERSION}.pkg ${JARFILE}

JARFILE = ${PACKAGE}-${VERSION}.jar

${JARFILE}: Makefile
	jar cf ${JARFILE} \
	  `cd ${top_builddir} && find . -name '*.class'`

% : %.sh.src
	sed 's@__PREFIX__@$(prefix)@g' < $< > $@ && \
	chmod +x $@

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: ${PACKAGE}.pkg Makefile
	sed 's#__VERSION__#${VERSION}#g;\
             s#__PACKAGE__#${PACKAGE}#g' < $< > $@
