# $Id: Makefile.am 22332 2007-04-04 12:21:59Z kooiker $

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = tree2relation

INCLUDES = \
  -I$(top_srcdir)/lib \
  ${PT_SUPPORT_CFLAGS} \
  ${RSTORE_SUPPORT_CFLAGS} \
  ${ERROR_SUPPORT_CFLAGS} \
  ${ATERM_CFLAGS} \
  ${TOOLBUSLIB_CFLAGS}

pkgdata_DATA = tree2relation.idef

noinst_HEADERS = \
	PT2relation.h

tree2relation_SOURCES = \
	tree2relation.isrc \
	PT2relation.c \
	tree2relation-main.c

tree2relation_LDADD = \
   -L${top_builddir}/lib/ -lGraph \
   $(PT_SUPPORT_LIBS) \
   $(RSTORE_SUPPORT_LIBS) \
   $(TOOLBUSLIB_LIBS) \
   $(ERROR_SUPPORT_LIBS) \
   $(ERROR_SUPPORT_LIBS) \
   $(ATERM_LIBS) \
   ${SOCKLIBS}
