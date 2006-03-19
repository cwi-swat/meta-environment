
EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS	= tide tide-gdb

noinst_SCRIPTS	= tide-test tide-passive tide-control

CLEANFILES = ${bin_SCRIPTS} ${noinst_SCRIPTS}

%: %.src Makefile
	sed "s@__JARDIR__@${pkgdatadir}@g;\
	     s@__TBDIR__@${pkgdatadir}@g;\
	     s@__SUPPORT__@${TIDE_SUPPORT}/share/tide-support@g;\
	     s@__STUDIO__@${META_STUDIO}/share/meta-studio@g;\
	     s@__EXTERNALS__@${EXTERNAL_JARS}@g;\
	     s@__BUILDDIR__@${top_builddir}@g;\
	" < $< > $@ && chmod +x $@


