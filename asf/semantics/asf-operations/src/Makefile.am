# $Id$

include $(top_srcdir)/make_rules

INCLUDES = $(ASC_INCLUDES)

bin_PROGRAMS = asfoperations
noinst_LTLIBRARIES = libasfnormalization.la

pkgdata_DATA    = asfoperations.idef

EXTRA_DIST   = asfoperations.idef.src 

CLEANFILES = asfoperations.idef

noinst_HEADERS 	= \
	asfoperations.tif.h \
	asfnormalization.h 

libErrorAPI_la_CPPFLAGS = $(ATERM_CFLAGS)
libErrorAPI_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libErrorAPI_la_LIBADD = $(ATERM_LIBS)
asfoperations_SOURCES = \
	asfoperations.c \
	asfoperations.tif.c \
	asfnormalization.c \
	ASF-Normalization.c

asfoperations_LDADD = $(ASC_LD_FLAGS)

libasfnormalization_a_SOURCES = \
			  asfnormalization.c \
			  ASF-Normalization.c 

# NOTE: the -a option to asfc activates rewriting with annotations,
#       which is essential here.
asfc:
	asfc -i ASF-Normalization.eqs -o ASF-Normalization.c -v -a	

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

