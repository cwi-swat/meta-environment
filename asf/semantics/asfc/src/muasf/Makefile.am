# $Id$

noinst_LIBRARIES	= libMuASF.a
noinst_HEADERS		= MuASF.h MuASF_dict.h
libMuASF_a_SOURCES	= MuASF.c MuASF_dict.c MuASF_bottom.c

EXTRA_DIST		= MuASF.label.def

CFLAGS			= -g -Wall -O2
#CFLAGS			= -DNO_SHARING -g -Wall -O2
INCLUDES		= -I${ATERM}/include
LDFLAGS			= -L${ATERM}/lib
LDADD			= -lATerm

# Developers only:
api: MuASF.label.def
	sdf2-to-c -i $< -r -P MA_ -o MuASF

api-clean:
	rm -f SDFME.[ch] SDFME_dict.* SDFME.adt SDFME_bottom.c
