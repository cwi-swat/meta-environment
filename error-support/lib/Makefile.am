# $Id$

lib_LIBRARIES=libmerrors.a

include_HEADERS=\
	Errors.h\
	Errors_dict.h\
	ParsedErrors.h\
	ParsedErrors_dict.h

libmerrors_a_SOURCES = \
	Errors.c \
	Errors_dict.c\
	ParsedErrors.c \
	ParsedErrors_dict.c \
	lift.c

CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
INCLUDES                = -I${ATERM}/include

SOURCE_MODULES=basic/Feedback basic/Locations
ABSOLUTE_SOURCE_MODULES=\
  $(foreach i, ${SOURCE_MODULES}, ${top_srcdir}/../asf-library/library/$i.sdf)

MetaErrors.def: Makefile
	@(echo "definition"; \
	  cat ${ABSOLUTE_SOURCE_MODULES} ${top_srcdir}/lib/Lexicals.sdf) > $@
	
MetaErrors.impl.def: Makefile
	@(echo "definition"; \
	  cat ${ABSOLUTE_SOURCE_MODULES}) > $@

api: parsed-api imploded-api 

parsed-api: MetaErrors.def Makefile  
	sdf2-to-c --input $< --prefix PME_ --output ParsedErrors
	indent ParsedErrors.h

imploded-api: MetaErrors.impl.def Makefile 
	sdf2-to-c --imploded --input $< --prefix ME_ --output Errors
	indent Errors.h

api-clean:
	${RM} MEPT.[ch] MEPT_dict.[ch] MEPT.dict
