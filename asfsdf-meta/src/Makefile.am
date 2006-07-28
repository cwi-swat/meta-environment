# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      asfsdf-meta \
	      eqs-dump \
	      asfsdf-meta-config

CLEANFILES = \
	     asfsdf-meta \
	     asfsdf-meta-config \
	     eqs-dump

% : %.sh.src Makefile
	sed "s@__TOOLBUS__@${TOOLBUS}@g;\
	     s@__PREFIX__@${prefix}@g;\
	     s@__TBSCRIPTS__@${TOOLBUSFLAGS}@g;" < $< > $@ && chmod +x $@
