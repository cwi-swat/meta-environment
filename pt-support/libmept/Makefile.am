# $Id$

lib_LIBRARIES           = libmept.a
include_HEADERS         = MEPT.h MEPT-utils.h MEPT_dict.h
libmept_a_SOURCES 	= MEPT.c MEPT_dict.c MEPT-utils.c  \
                          implodePT.c yieldPT.c yieldProd.c \
                          posInfo.c reportAmbs.c apply.c \
                          symbol-renaming.c
                          
CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
INCLUDES                = -I${ATERM}/include

api: 
	adt-to-c --compat-term -i MEPT.adt --prefix PT_ -o MEPT

api-clean:
	${RM} MEPT.[ch] MEPT_dict.[ch] MEPT.dict
