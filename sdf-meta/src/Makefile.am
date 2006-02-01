# $Id$

EXTRA_DIST  = $(wildcard *.src)

bin_SCRIPTS = sdf-meta-config

TBSCRIPTS = \
	    -I$(PGEN)/share/pgen \
	    `$(META)/bin/meta-config --toolbus-includes`

CLEANFILES  = sdf-meta-config

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TBSCRIPTS)@g;' < $< > $@ && chmod +x $@
