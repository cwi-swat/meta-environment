# $Id$

include ${top_srcdir}/make_rules

INCLUDES	  = -I$(PT_SUPPORT)/include \
                    -I$(ATERM)/include \
                    -I$(ERROR_SUPPORT)/include \
                    -I$(ASF_SUPPORT)/include

bin_PROGRAMS	  = concat-asf

GENERIC_LDADD = -L$(PT_SUPPORT)/lib -lmept \
         	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
         	-L$(ATERM)/lib -lATerm

concat_asf = concat-asf.c
concat_asf_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME $(GENERIC_LDADD)
