SUBDIRS=lift-error

bin_SCRIPTS = ${PACKAGE}-config

CLEANFILES=${bin_SCRIPTS}

${PACKAGE}-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo ${prefix}/share/meta-errors/errorapi-${VERSION}.jar" \
	) > $@ && chmod +x $@
