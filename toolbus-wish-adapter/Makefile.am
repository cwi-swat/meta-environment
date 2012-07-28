include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

pkgdata_DATA = tb.tcl

bin_SCRIPTS = wish-adapter

CLEANFILES += wish-adapter

EXTRA_DIST += tb.tcl $(wildcard *.src)

% : %.sh.src Makefile
	sed "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g;\
	s@__WISH_JAR__@$(prefix)/share/$(JAVA_JAR)@g;\
	s@__TBTCL__@\"$(pkgdatadir)/tb.tcl\"@g;\
	s@__LIBDIR__@\"$(pkgdatadir)\"@g;" < $< > $@ && chmod +x $@
