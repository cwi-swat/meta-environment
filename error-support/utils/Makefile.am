SUBDIRS=lift-error

bin_SCRIPTS = meta-errors-config

CLEANFILES=${bin_SCRIPTS}

meta-errors-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo ${prefix}/share/meta-errors/errorAPI-${VERSION}.jar" \
	) > $@ && chmod +x $@
