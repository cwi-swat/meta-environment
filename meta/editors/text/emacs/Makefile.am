# $Id$

CFLAGS += -Werror

SCRIPT = gnu-emacs.el

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(top_srcdir)/editors/structure/src \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-DSTARTUP_SCRIPT="\"$(datadir)/meta/$(SCRIPT)\""

COMMONLIB = $(top_builddir)/editors/text/common/libTextEditor.a

EXTRA_DIST = $(SCRIPT)

bin_PROGRAMS = emacs-connector
lib_LTLIBRARIES = lib_gnu-emacs.la

pkgdata_DATA = $(SCRIPT)

emacs_connector_SOURCES = connector.c
emacs_connector_DEPENDENCIES = $(COMMONLIB)

emacs_connector_LDADD = \
	$(COMMONLIB) \
	-L$(top_builddir)/editors/structure/src -lStructure \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm

lib_gnu_emacs_la_SOURCES = startup.c
