# $Id$

SUBDIRS=test

bin_PROGRAMS		= implodePT 

INCLUDES = \
	-I${top_srcdir}/libmept \
	-I${ERROR_SUPPORT}/include \
	-I${ATERM}/include 


implodePT_SOURCES	= implodePT-main.c
implodePT_LDADD	=\
	-L${top_builddir}/libmept -lmept \
	-L${ERROR_SUPPORT}/lib -lErrorAPI \
	-L${ATERM}/lib -lATerm
