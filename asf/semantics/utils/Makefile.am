# $Id$

include $(top_srcdir)/Makefile.meta

INCLUDES	  = $(PT_SUPPORT_CFLAGS) \
                    $(ATERM_CFLAGS) \
                    $(ERROR_SUPPORT_CFLAGS) \
                    $(ASF_SUPPORT_CFLAGS) 

bin_PROGRAMS	  = concat-asf lift-asf

concat_asf = concat-asf.c
concat_asf_LDADD   = $(ASF_SUPPORT_LIBS) $(PT_SUPPORT_LIBS)

lift_asf = lift-asf.c
lift_asf_LDADD   = $(ASF_SUPPORT_LIBS) $(PT_SUPPORT_LIBS)
