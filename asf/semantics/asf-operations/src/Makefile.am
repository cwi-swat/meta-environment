# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = asfoperations
noinst_LTLIBRARIES = libasfnormalization.la

pkgdata_DATA    = asfoperations.idef

noinst_HEADERS 	= \
	asfnormalization.h 

AM_CPPFLAGS += $(ASC_SUPPORT_CFLAGS)
asfoperations_LDADD = \
     -L${top_builddir}/semantics/asf-operations/src -lasfnormalization \
     $(ASC_SUPPORT_LIBS) 
asfoperations_SOURCES = \
	asfoperations.idef \
	main.c \
	asfnormalization.c \
	ASF-Normalization.c

libasfnormalization_la_CPPFLAGS = $(ASC_SUPPORT_CFLAGS)
libasfnormalization_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libasfnormalization_la_SOURCES = \
			  asfnormalization.c \
			  ASF-Normalization.c 

# NOTE: the -a option to asfc activates rewriting with annotations,
#       which is essential here.
asfc:
	asfc -i ASF-Normalization.eqs -o ASF-Normalization.c -v -a	

