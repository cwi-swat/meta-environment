
EXTRA_DIST	= tide-test.src tide-passive.src tide-control.src tide.src

bin_SCRIPTS	= tide

noinst_SCRIPTS	= tide-test tide-passive tide-control

%: %.src Makefile
	sed 's@__JARDIR__@${pkgdatadir}@g;\
	     s@__TBDIR__@${pkgdatadir}@g;\
	     s@__ATERM__@${ATERM}@g;\
	     s@__TOOLBUS__@${TOOLBUS}@g;\
	     s@__BUILDDIR__@${top_builddir}@g;\
	' < $< > $@ && chmod +x $@


