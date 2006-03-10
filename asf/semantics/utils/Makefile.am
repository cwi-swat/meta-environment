# $Id$

include ${top_srcdir}/make_rules

INCLUDES	  = -I$(PT_SUPPORT)/include \
                    -I$(ATERM)/include \
                    -I$(ERROR_SUPPORT)/include \
                    -I$(ASF_SUPPORT)/include

bin_PROGRAMS	  = concat-asf lift-asf

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

GENERIC_LDADD = -L$(PT_SUPPORT)/lib -lPTMEPT -lmept \
         	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
         	-L$(ATERM)/lib -l$(ATERM_LIB)

concat_asf = concat-asf.c
concat_asf_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME $(GENERIC_LDADD)

lift_asf = lift-asf.c
lift_asf_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME $(GENERIC_LDADD)
