# $Id$

noinst_LIBRARIES	= libASFAPI.a
noinst_HEADERS		= ASFAPI.h ASFAPI_dict.h
libASFAPI_a_SOURCES	= ASFAPI.c ASFAPI_dict.c 

CFLAGS			= -g -Wall -O2
#CFLAGS			= -DNO_SHARING -g -Wall -O2
INCLUDES		= -I${ATERM}/include
LDFLAGS			= -L${ATERM}/lib
LDADD			= -lATerm
