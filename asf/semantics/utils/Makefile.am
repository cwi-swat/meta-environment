# $Id$

include ${top_srcdir}/make_rules

INCLUDES	  = -I$(PT_SUPPORT)/include \
                    -I$(ATERM)/include \
                    -I$(ASF_SUPPORT)/include

bin_PROGRAMS	  = apply-function concat-asf

GENERIC_LDADD = -L$(PT_SUPPORT)/lib -lmept \
         	-L$(ATERM)/lib -lATerm

apply_function_SOURCES	= apply-function.c
apply_function_LDADD   = $(GENERIC_LDADD)

concat_asf = concat-asf.c
concat_asf_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME $(GENERIC_LDADD)
