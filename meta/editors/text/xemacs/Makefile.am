# $Id$

CFLAGS += -Werror

SCRIPT = xemacs.el

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(top_srcdir)/editors/structure/src \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-DSTARTUP_SCRIPT="\"$(datadir)/meta/$(SCRIPT)\""

EXTRA_DIST = $(SCRIPT)

bin_PROGRAMS = xemacs-connector
lib_LTLIBRARIES = lib_xemacs.la

pkgdata_DATA = $(SCRIPT)

xemacs_connector_SOURCES = connector.c

xemacs_connector_LDADD = \
	-L$(top_builddir)/editors/text/common -lTextEditor \
	-L$(top_builddir)/editors/structure/src -lStructure \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

lib_xemacs_la_SOURCES = startup.c
