# $Id$

include ../make_rules 

# The following libraries are compiled to static libraries.   
lib_LIBRARIES           = libmept.a libmept-prof.a

ALLSRCS                 = MEPT.c MEPT_dict.c MEPT-utils.c  \
			  implodePT.c yieldPT.c yieldProd.c \
			  posInfo.c reportAmbs.c PT2dot.c   
include_HEADERS         = MEPT.h MEPT_dict.h MEPT-utils.h

#CFLAGS                 += -pg -DDISABLE_DYNAMIC_CHECKING
CFLAGS                  +=  -DDISABLE_DYNAMIC_CHECKING

INCLUDES                = -I${ATERM}/include
CFLAGS                  = -Wall -g -O2 -DDISABLE_DYNAMIC_CHECKING
CFLAGS_PROF                  = -Wall -pg -DDISABLE_DYNAMIC_CHECKING

libmept_a_SOURCES	=
libmept_prof_a_SOURCES	=
  
libmept_a_LIBADD       = $(ALLSRCS:.c=.o)  
libmept_prof_a_LIBADD  = $(ALLSRCS:.c=-prof.o)  
                        
#CFLAGS                  = -pg -Wall -O2 -DDISABLE_DYNAMIC_CHECKING
