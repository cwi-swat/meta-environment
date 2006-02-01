# $Id$

include ${top_srcdir}/make_rules

INCLUDES = $(ASC_INCLUDES)

bin_PROGRAMS = asfoperations

pkgdata_DATA    = asfoperations.idef

EXTRA_DIST   = asfoperations.idef.src 

noinst_HEADERS 	= \
	asfoperations.tif.h \
	asfnormalization.h 

asfoperations_SOURCES = \
	asfoperations.c \
	asfoperations.tif.c \
	asfnormalization.c \
	ASF-Normalization.c

asfoperations_LDADD = $(ASC_LD_FLAGS)

# NOTE: the -a option to asfc activates rewriting with annotations,
#       which is essential here.
asfc:
	asfc -i ASF-Normalization.eqs -o ASF-Normalization.c -v -a	

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

