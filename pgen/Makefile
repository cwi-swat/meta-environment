# $Id$
#
# Directory: pgen

SUBDIRS		= c-files c-source fastgen addeqs

all doc clean install uninstall distclean:
	@for DIR in ${SUBDIRS};	\
	do \
		echo Make $@ in $$DIR; \
		cd $$DIR; \
		${MAKE} -${MAKEFLAGS} $@; \
		cd ..; \
	done


