# $Id$

lib_LIBRARIES		= libASFME.a
include_HEADERS		= ASFME.h ASFME_dict.h ASFME-utils.h
libASFME_a_SOURCES	= ASFME.c ASFME_dict.c ASFME-utils.c

INCLUDES		= -I${ATERM}/include -I${PT_SUPPORT}/include
CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
#CFLAGS			+= -pg -DDISABLE_DYNAMIC_CHECKING

EXTRA_DIST		= Developer.make
