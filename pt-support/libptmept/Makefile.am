# $Id$

lib_LIBRARIES		= libPTMEPT.a
include_HEADERS		= PTMEPT.h PTMEPT-utils.h PTMEPT_dict.h SDF2PT.h

libPTMEPT_a_SOURCES	= PTMEPT.c PTMEPT_dict.c PTMEPT_bottom.c ${UTILSRCS}
UTILSRCS		= 

EXTRA_DIST		= AsFix.def

INCLUDES		= -I${ATERM}/include \
                          -I${PT_SUPPORT}/include

# Developers only:
api: AsFix.def
	sdf2-to-c -i $< -r -P PTPT_ -o PTMEPT

api-clean:
	rm -f PTMEPT.[ch] PTMEPT_dict.* PTMEPT.adt PTMEPT_bottom.c
