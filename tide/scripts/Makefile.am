
EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS	= tide tide-gdb

noinst_SCRIPTS	= tide-test tide-passive tide-control

CLEANFILES = ${bin_SCRIPTS} ${noinst_SCRIPTS}

%: %.src Makefile
	sed "s@__JARDIR__@${datadir}@g;\
	     s@__TBDIR__@${pkgdatadir}@g;\
	     s@__TOOLBUSFLAGS__@${TOOLBUSFLAGS}@g;\
	     s@__EXTERNALS__@${EXTERNAL_JARS}@g;\
	     s@__BUILDDIR__@${top_builddir}@g;\
	" < $< > $@ && chmod +x $@


