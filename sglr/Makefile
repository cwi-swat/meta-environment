# $Id$
#
# Directory: sglr

SUBDIRS		= a2toa1 client tree2dot parser dump sdf1tosdf2

.SILENT:

all doc install:	libs

all libs doc clean install uninstall distclean:
	@for DIR in $(SUBDIRS);	\
	do \
		if [ -d $$DIR ]; then \
			echo Make $@ in $$DIR; \
			cd $$DIR; \
			$(MAKE) -${MAKEFLAGS} $@; \
			cd ..; \
		fi \
	done


