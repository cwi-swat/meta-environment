# $Id$

noinst_LIBRARIES	= libMuASF.a
noinst_HEADERS		= MuASF.h MuASF_dict.h

libMuASF_a_SOURCES	= MuASF.c MuASF_dict.c

EXTRA_DIST		= MuASF.label.def

AM_CFLAGS		= -g -Wall -O2
INCLUDES		= -I${ATERM}/include

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

LDADD = -l$(ATERM_LIB)

if MAINTAINER_MODE

LIBRARY=../../../../../asf-library/library
SPEC=${LIBRARY}/languages/asf/compiler/

MuASF.label.def:
	(echo "definition"; \
	cat ${SPEC}/muasf/MuASF.sdf ; echo ""; \
	cat ${LIBRARY}/basic/Whitespace.sdf; echo ""; \
	cat ${LIBRARY}/basic/StrCon.sdf; echo ""; \
	cat ${LIBRARY}/basic/NatCon.sdf; echo ""; \
	cat ${LIBRARY}/basic/IdentifierCon.sdf ) > $@

api: MuASF.label.def
	sdf2-to-c \
		--input $< \
		--output MuASF \
		--prefix MA_ 

api-clean:
	rm -f MuASF.[ch] MuASF_dict.* MuASF.adt

endif
