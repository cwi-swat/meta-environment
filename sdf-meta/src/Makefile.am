# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      def-dump \
	      sdf-meta-config \
	      sdf-meta \
	      pt-dump

CLEANFILES = \
	     def-dump \
	     sdf-meta-config \
	     sdf-meta \
	     pt-dump

% : %.sh.src Makefile
	sed "s@__TOOLBUS__@${TOOLBUS}@g;\
	     s@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TOOLBUSFLAGS)@g;" < $< > $@ && chmod +x $@
