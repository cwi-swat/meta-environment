include $(top_srcdir)/make_rules

EXTRA_DIST=jite.idef
pkgdata_DATA=jite.idef

bin_PROGRAMS = jite 

noinst_HEADERS = jitty.h jite.tif.h
ATERMLIB = -L$(ATERM)/lib -lATerm -lATB -lmept

INCLUDES = -I$(ATERM)/include 

jite_SOURCES = jite.c jitty.c jite.tif.c
jite_LDADD = $(ATERMLIB) 

