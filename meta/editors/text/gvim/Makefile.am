# $Id$

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(top_srcdir)/configuration-manager/src \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-DLIBDIR="\"$(libdir)\"" \
	-DDATADIR="\"$(pkgdatadir)\""

EXTRA_DIST = \
	meta.vim.src

CLEANFILES = meta.vim $(data_DATA)

COMMONLIB = $(top_builddir)/editors/text/common/libTextEditor.a

bin_PROGRAMS = gvim-connector
lib_LTLIBRARIES = lib_gvim.la
pkgdata_DATA = meta.vim
noinst_HEADERS = protocol.h

gvim_connector_SOURCES = connector.c
gvim_connector_DEPENDENCIES = $(COMMONLIB)

gvim_connector_LDADD = \
	$(COMMONLIB) \
	-L$(TOOLBUSLIB)/lib -lATB \
        -L$(ERROR_SUPPORT)/lib -lLocationAPI \
	-L$(top_builddir)/configuration-manager/src -lMetaConfig \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

lib_gvim_la_SOURCES = comm.c startup.c
lib_gvim_la_LDFLAGS = -module

meta.vim: meta.vim.src
	sed 's@__LIBDIR__@$(libdir)@g' < $< > $@
