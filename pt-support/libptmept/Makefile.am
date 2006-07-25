# $Id$

lib_LIBRARIES = libPTMEPT.a
include_HEADERS = \
	PTMEPT.h \
	PTMEPT-utils.h \
	PTMEPT_dict.h 

libPTMEPT_a_SOURCES = PTMEPT.c PTMEPT_dict.c ${UTILSRCS}
UTILSRCS = lift.c lower.c

EXTRA_DIST = AsFix.def

INCLUDES = \
	-I${top_srcdir}/libmept \
	${ERROR_SUPPORT_CFLAGS} \
	${ATERM_CFLAGS}

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

# Developers only:
LIBRARY=../../asf-library/library

AsFix.def:
	(echo "definition"; \
	echo ""; \
	cat ${LIBRARY}/languages/asfix/syntax/*.sdf ; \
	cat ${LIBRARY}/languages/aterm/syntax/*.sdf ; \
	cat ${LIBRARY}/basic/StrCon.sdf ; \
	cat ${LIBRARY}/basic/NatCon.sdf ; \
	cat ${LIBRARY}/basic/IdentifierCon.sdf ; \
	cat ${LIBRARY}/basic/Whitespace.sdf) > $@

api: 
	sdf2-to-c -i AsFix.def --prefix PTPT_ -o PTMEPT

api-clean:
	rm -f PTMEPT.[ch] PTMEPT_dict.* PTMEPT.adt
