# $Id$

lib_LIBRARIES           = libmept.a
include_HEADERS         = MEPT.h MEPT_dict.h MEPT-utils.h
libmept_a_SOURCES 	= MEPT.c MEPT_dict.c MEPT-utils.c  \
                          implodePT.c yieldPT.c yieldProd.c \
                          posInfo.c reportAmbs.c
                          

#CFLAGS                  = -pg -Wall -O2 -DDISABLE_DYNAMIC_CHECKING
CFLAGS                  = -g -Wall -Werror -O2 -DDISABLE_DYNAMIC_CHECKING
INCLUDES                = -I${ATERM}/include
