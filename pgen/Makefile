# $Id$
#
# Directory: pgen

SUBDIRS		= c-files c-source addeqs/c-source

all doc clean install uninstall distclean:
	@for DIR in $(SUBDIRS);	\
	do \
		echo Make $@ in $$DIR; \
		cd $$DIR; \
		$(MAKE) $@; \
		cd ..; \
	done


