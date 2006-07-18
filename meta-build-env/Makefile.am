
# Warning: the meta-build.m4 macro is NOT included in the local aclocal.m4

bin_SCRIPTS 	= meta-build 
pkgdata_DATA 	= \
		  meta-build.m4 \
		  Makefile.meta \
		  Makefile.top.meta \
		  meta-build.xml \
		  Doxyfile.meta

EXTRA_DIST	= meta-build.src $(pkgdata_DATA)

CLEANFILES = meta-build

meta-build: meta-build.src
	sed "s@__prefix__@${prefix}@g;\
	     s@__datadir__@${datadir}@g;\
	     s@__PACKAGE__@${PACKAGE}@g" < $< > $@ && chmod +x $@
