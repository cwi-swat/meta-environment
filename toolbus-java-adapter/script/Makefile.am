# $Id$

EXTRA_DIST = java-adapter tifstojava.src

CLEANFILES = tifstojava 

bin_SCRIPTS = java-adapter tifstojava

%: %.src Makefile
	sed -e 's@__BINDIR__@$(bindir)@g'\
	    -e 's@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g'\
	    -e 's@__JARFILE__@$(JARFILE)@g'\
	    < $< > $@ && chmod +x $@
