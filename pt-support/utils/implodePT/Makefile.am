# $Id$

include $(top_srcdir)/Makefile.meta

SUBDIRS = test

bin_PROGRAMS = implodePT 

INCLUDES = \
	-I$(top_srcdir)/libmept \
	$(ERROR_SUPPORT_CFLAGS)

implodePT_SOURCES = implodePT-main.c
implodePT_LDADD	=\
	-L$(top_builddir)/libmept -lmept \
	$(ERROR_SUPPORT_LIBS)
