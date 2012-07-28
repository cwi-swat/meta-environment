# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libPTMEPT.la
include_HEADERS = \
	PTMEPT.h \
	PTMEPT-utils.h \
	PTMEPT_dict.h 

libPTMEPT_la_CPPFLAGS = -I${top_srcdir}/libmept $(ERROR_SUPPORT_CFLAGS) $(ATERM_CFLAGS) -DDISABLE_DYNAMIC_CHECKING
libPTMEPT_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libPTMEPT_la_LIBADD   = ../libmept/libmept.la $(ERROR_SUPPORT_LIBS) $(ATERM_LIBS)
libPTMEPT_la_SOURCES = PTMEPT.c PTMEPT_dict.c $(UTILSRCS)


UTILSRCS = lift.c lower.c
EXTRA_DIST += AsFix.def

# Developers only:
LIBRARY=../../sdf-library/library

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
