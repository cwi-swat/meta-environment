# $Id$

lib_LIBRARIES           = libmept.a
include_HEADERS         = MEPT.h MEPT-utils.h MEPT_dict.h
libmept_a_SOURCES 	= MEPT.c MEPT_dict.c MEPT-utils.c  \
                          implodePT.c yieldPT.c yieldProd.c \
                          posInfo.c reportAmbs.c PT2dot.c apply.c
                          

#CFLAGS                 += -pg -DDISABLE_DYNAMIC_CHECKING
#CFLAGS                  += -DDISABLE_DYNAMIC_CHECKING
#CFLAGS                  += -DNO_SHARING -DDISABLE_DYNAMIC_CHECKING
#CFLAGS                  += -pg -DNO_SHARING -DDISABLE_DYNAMIC_CHECKING
CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
INCLUDES                = -I${ATERM}/include
