# $Id$

CFLAGS += -Werror

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(top_srcdir)/editors/structure/src \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-DLIBDIR="\"$(libdir)\"" \
	-DDATADIR="\"$(datadir)\""

EXTRA_DIST = \
	meta.vim.src

CLEANFILES = $(data_DATA)

COMMONLIB = $(top_builddir)/editors/text/common/libTextEditor.a

bin_PROGRAMS = gvim-connector
lib_LTLIBRARIES = lib_gvim.la
data_DATA = meta.vim


gvim_connector_SOURCES = connector.c
gvim_connector_DEPENDENCIES = $(COMMONLIB)

gvim_connector_LDADD = \
	$(COMMONLIB) \
	-L$(top_builddir)/editors/structure/src -lStructure \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

lib_gvim_la_SOURCES = comm.c startup.c

meta.vim: meta.vim.src
	sed 's@__LIBDIR__@$(libdir)@g' < $< > $@
