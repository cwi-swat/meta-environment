# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      asfsdf-meta \
	      eqs-dump  \
	      test-eqs-dump

CLEANFILES = \
	     asfsdf-meta \
	     eqs-dump \
	     test-eqs-dump

% : %.sh.src Makefile
	sed "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g;\
	     s@__PREFIX__@${prefix}@g;\
	     s@__CONFIG_MANAGER__@${CONFIG_MANAGER_PREFIX}@g;\
	     s@__CONSOLE_GRABBER__@${CONSOLE_GRABBER_PREFIX}@g;\
	     s@__TBSCRIPTS__@${TOOLBUSFLAGS} -I${prefix}/share/asfsdf-meta@g;" < $< > $@ && chmod +x $@
