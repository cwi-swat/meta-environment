# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      def-dump \
	      sdf-meta \
	      pt-dump

CLEANFILES = \
	     def-dump \
	     sdf-meta \
	     pt-dump

% : %.sh.src Makefile
	sed "s@__TOOLBUS__@${TOOLBUS_PREFIX}@g;\
	     s@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TOOLBUSFLAGS) -I${prefix}/share/sdf-meta@g;" < $< > $@ && chmod +x $@
