# $Id: Makefile.am 19998 2006-07-28 14:51:00Z jurgenv $

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      java-meta

CLEANFILES = \
	     java-meta

% : %.sh.src Makefile
	sed "s@__TOOLBUS__@${TOOLBUS_PREFIX}@g;\
	     s@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TOOLBUSFLAGS) -I${prefix}/share/sdf-meta@g;" < $< > $@ && chmod +x $@
