# $Id$

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
	sdf2-to-c --imploded --input $< --prefix PME_ --output Errors	

api-clean:
	${RM} MEPT.[ch] MEPT_dict.[ch] MEPT.dict
