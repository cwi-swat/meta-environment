bin_SCRIPTS = ${PACKAGE}-config

CLEANFILES = ${bin_SCRIPTS}

${PACKAGE}-config: Makefile
	@(	echo "#! /bin/sh";\
		echo "echo ${prefix}/share/${PACKAGE}/configapi.jar" \
	) > $@ && chmod +x $@

