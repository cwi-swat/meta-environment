# $Id$

include $(top_srcdir)/Makefile.meta


bin_PROGRAMS	  = concat-asf lift-asf

concat_asf_CPPFLAGS   = $(ASF_SUPPORT_CFLAGS) $(PT_SUPPORT_CFLAGS) 
concat_asf = concat-asf.c
concat_asf_LDADD   = $(ASF_SUPPORT_LIBS) $(PT_SUPPORT_LIBS)

lift_asf_CPPFLAGS   = $(ASF_SUPPORT_CFLAGS) $(PT_SUPPORT_CFLAGS) 
lift_asf = lift-asf.c
lift_asf_LDADD   = $(ASF_SUPPORT_LIBS) $(PT_SUPPORT_LIBS)
