# $Id$

EXTRA_DIST  = $(wildcard *.src)

bin_SCRIPTS = sdf-meta-config sdf-meta

TBSCRIPTS = \
	    -I$(prefix)/share/sdf-meta \
	    -I$(PGEN)/share/pgen \
	    -I$(SDF_SUPPORT)/share/sdf-support \
	    `$(META)/bin/meta-config --toolbus-includes`

CLEANFILES  = sdf-meta-config sdf-meta

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TBSCRIPTS)@g;' < $< > $@ && chmod +x $@
