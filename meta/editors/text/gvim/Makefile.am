# $Id$

CFLAGS += -Werror

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(top_srcdir)/editors/structure/src \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-DLIBDIR="\"$(libdir)\"" \
	-DDATADIR="\"$(pkgdatadir)\""

EXTRA_DIST = \
	meta.vim.src

CLEANFILES = $(data_DATA)

COMMONLIB = $(top_builddir)/editors/text/common/libTextEditor.a

bin_PROGRAMS = gvim-connector
lib_LTLIBRARIES = lib_gvim.la
pkgdata_DATA = meta.vim
noinst_HEADERS = protocol.h

gvim_connector_SOURCES = connector.c
gvim_connector_DEPENDENCIES = $(COMMONLIB)

gvim_connector_LDADD = \
	$(COMMONLIB) \
	-L$(top_builddir)/editors/structure/src \
	-L$(TOOLBUSLIB)/lib \
	-L$(ATERM)/lib \
	-lStructure \
	-lATB \
	-lATerm \
	$(SOCKLIBS)

lib_gvim_la_SOURCES = comm.c startup.c

meta.vim: meta.vim.src
	sed 's@__LIBDIR__@$(libdir)@g' < $< > $@
