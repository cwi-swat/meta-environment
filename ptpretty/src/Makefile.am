# $Id$

INCLUDES = \
	-I$(top_srcdir)/libsglr \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(ATERM)/include

bin_PROGRAMS = ptpretty 

noinst_HEADERS = pretty.h
ptpretty_SOURCES = main.c pretty.c
ptpretty_LDADD = \
	-L$(SDF_SUPPORT)/lib -lSDFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ATERM)/lib -lATerm 
