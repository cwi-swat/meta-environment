# $Id$
#
# Directory: sglr

SUBDIRS		= a2toa1 client tree2dot parser dump sdf1tosdf2

.SILENT:

all doc install:	libs

libs:	config.status

all libs doc clean install uninstall distclean test:
	@for DIR in $(SUBDIRS);	\
	do \
		if [ -d $$DIR ]; then \
			echo Make $@ in $$DIR; \
			cd $$DIR; \
			$(MAKE) $@; \
			cd ..; \
		fi \
	done

config.status:	configure
	@echo "Warning: no up to date configuration"
	@if [ ! -f $@ ] ; then eche "Configure,  please" ; false ; fi
	@echo "Please consider rerunning configure"

configure:	configure.in
	@echo "Warning: configure script is out of date"
	@echo "Please consider (re)running autoconf"
