# $Id$

ATINC = $(ATERM)/include

INCLUDES = -I$(ATINC) # -DTERM_SIZE_WARNING_THRESHOLD=512

lib_LIBRARIES = libATB.a
include_HEADERS = atb-tool.h

libATB_a_SOURCES = atb-tool.c

bin_PROGRAMS = tbunpack

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

tbunpack_SOURCES = tbunpack.c atb-tool.c
tbunpack_LDADD = -L$(ATERM)/lib -l$(ATERM_LIB)

