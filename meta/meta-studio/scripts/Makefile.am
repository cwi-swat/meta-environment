
EXTRA_DIST	= meta-studio.src

bin_SCRIPTS	= meta-studio

CLEANFILES	= meta-studio

%: %.src Makefile
	reldir_to_absdir=`cd ${top_builddir}; pwd`/meta-studio; \
	sed "\
	     s@__JAVA__@${JAVA}@g;\
	     s@__JARDIR__@${pkgdatadir}@g;\
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g;\
	     s@__BUILDDIR__@$$reldir_to_absdir@g;\
	     s@__TIDEDEF__@${TIDEDEF}@g;\
	" < $< > $@ && chmod +x $@
