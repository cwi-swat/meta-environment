# $Id$

bin_PROGRAMS = filtereqssyntax

noinst_HEADERS		=	filtereqssyntax.h
filtereqssyntax_SOURCES	=	main.c filtereqssyntax.c
filtereqssyntax_LDADD	=	-L${ASF_SUPPORT}/lib -lASFME \
				-L${PT_SUPPORT}/lib -lmept \
				-L${ATERM}/lib -lATerm 

INCLUDES		=	-I${ATERM}/include \
				-I${PT_SUPPORT}/include \
				-I${ASF_SUPPORT}/include
