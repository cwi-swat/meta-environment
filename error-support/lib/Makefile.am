# $Id$

lib_LIBRARIES=libmerrors.a

libmerrors_a_SOURCES = \
	Errors.c \
	Errors_dict.c\
	ParsedErrors.c \
	ParsedErrors_dict.c \
	ParsedErrors_bottom.c

CFLAGS			+= -DDISABLE_DYNAMIC_CHECKING
INCLUDES                = -I${ATERM}/include

SOURCE_MODULES=basic/Feedback basic/Locations
ABSOLUTE_SOURCE_MODULES=\
  $(foreach i, ${SOURCE_MODULES}, ${top_srcdir}/../asf-library/library/$i.sdf)

MetaErrors.def: Makefile
	@(echo "definition"; \
	  cat ${ABSOLUTE_SOURCE_MODULES}) > $@
	
api: parsed-api imploded-api 

parsed-api: MetaErrors.def Makefile  
	sdf2-to-c --input $< --prefix PME_ --output ParsedErrors	

imploded-api: MetaErrors.def Makefile 
	sdf2-to-c --imploded --input $< --prefix ME_ --output Errors	

api-clean:
	${RM} MEPT.[ch] MEPT_dict.[ch] MEPT.dict
