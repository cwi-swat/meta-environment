# $Id$

bin_PROGRAMS		= implodePT 

INCLUDES		= -I${top_srcdir}/libmept \
			-I${ATERM}/include 


implodePT_SOURCES	= implodePT-main.c
implodePT_LDADD		= -L${top_builddir}/libmept -lmept \
			-L${ATERM}/lib -lATerm
