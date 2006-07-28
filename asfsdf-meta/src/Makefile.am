# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      asfsdf-meta \
	      eqs-dump 

CLEANFILES = \
	     asfsdf-meta \
	     eqs-dump

% : %.sh.src Makefile
	sed "s@__TOOLBUS__@${TOOLBUS_PREFIX}@g;\
	     s@__PREFIX__@${prefix}@g;\
	     s@__TBSCRIPTS__@${TOOLBUSFLAGS} -I${prefix}/share/asfsdf-meta@g;" < $< > $@ && chmod +x $@
