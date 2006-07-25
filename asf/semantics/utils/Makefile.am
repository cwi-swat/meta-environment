# $Id$

include ${top_srcdir}/Makefile.meta

INCLUDES	  = $(PT_SUPPORT_CFLAGS) \
                    $(ATERM_CFLAGS) \
                    $(ERROR_SUPPORT_CFLAGS) \
                    $(ASF_SUPPORT_CFLAGS) 

bin_PROGRAMS	  = concat-asf lift-asf

GENERIC_LDADD = $(PT_SUPPORT_LIBS) \
         	$(ERROR_SUPPORT_LIBS) \
         	$(ATERM_LIBS) 

concat_asf = concat-asf.c
concat_asf_LDADD   = $(ASF_SUPPORT_LIBS) 

lift_asf = lift-asf.c
lift_asf_LDADD   = $(ASF_SUPPORT_LIBS) 
