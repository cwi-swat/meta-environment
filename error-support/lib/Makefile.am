# $Id$

lib_LIBRARIES=libErrorAPI.a

include_HEADERS=\
	ErrorAPI.h\
	ErrorAPI_dict.h\
	ParsedErrorAPI.h\
	ParsedErrorAPI_dict.h\
	ErrorAPI-utils.h

libErrorAPI_a_SOURCES = \
	ErrorAPI.c \
	ErrorAPI_dict.c\
	ParsedErrorAPI.c \
	ParsedErrorAPI_dict.c \
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
	sdf2-to-c --input $< --prefix PME_ --output ParsedErrorAPI
	indent ParsedErrorAPI.h

imploded-api: MetaErrors.impl.def Makefile 
	sdf2-to-c --imploded --input $< --prefix ME_ --output ErrorAPI
	indent ErrorAPI.h

api-clean:
	${RM} MEPT.[ch] MEPT_dict.[ch] MEPT.dict
