# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      def-dump \
	      sdf-meta-config \
	      sdf-meta \
	      pt-dump

TBSCRIPTS = \
	    -I$(prefix)/share/sdf-meta \
	    -I$(PGEN)/share/pgen \
	    -I$(SDF_SUPPORT)/share/sdf-support \
	    `$(META)/bin/meta-config --toolbus-includes`

CLEANFILES = \
	     def-dump \
	     sdf-meta-config \
	     sdf-meta \
	     pt-dump

% : %.sh.src Makefile
	sed "s@__TOOLBUS__@${TOOLBUS}@g;\
	     s@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TBSCRIPTS)@g;" < $< > $@ && chmod +x $@
