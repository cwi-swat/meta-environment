# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(ATERM)/include

CFLAGS += -DASF_MAIN
bin_PROGRAMS = ActionScriptChecker

ActionScriptChecker_SOURCES = ActionScriptChecker.c 
ActionScriptChecker_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(PT_SUPPORT)/lib -lmept \
			-L$(SDF_SUPPORT)/lib -lSDFME \
			-L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(ATERM)/lib -lATerm
