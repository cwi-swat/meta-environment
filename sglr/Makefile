# $Id$
#
# Directory: sglr

SUBDIRS		= a2toa1 client tree2dot parser dump

all doc clean install uninstall distclean:
	@for DIR in $(SUBDIRS);	\
	do \
		echo Make $@ in $$DIR; \
		cd $$DIR; \
		$(MAKE) $@; \
		cd ..; \
	done


