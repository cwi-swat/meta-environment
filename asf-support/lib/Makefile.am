# $Id$

lib_LIBRARIES		= libASFME.a
noinst_HEADERS          = ASFME_dict.h
include_HEADERS		= ASFME.h ASFME-utils.h
libASFME_a_SOURCES	= ASFME.c ASFME_dict.c ASFME-utils.c lex-cons.c

INCLUDES		= -I${ATERM}/include -I${PT_SUPPORT}/include
CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
#CFLAGS			+= -pg -DDISABLE_DYNAMIC_CHECKING

EXTRA_DIST		= Developer.make
