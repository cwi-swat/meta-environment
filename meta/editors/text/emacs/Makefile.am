# $Id$

SCRIPT = gnu-emacs.el

#AM_CFLAGS = -Werror

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(ATERM)/include \
	-I$(PT_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ERROR_SUPPORT)/include \
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
	-L$(TOOLBUSLIB)/lib -lATB \
        -L$(ERROR_SUPPORT)/lib -lLocationAPI \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

lib_gnu_emacs_la_SOURCES = startup.c
