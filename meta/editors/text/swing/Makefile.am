# $Id$

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-DLIBDIR="\"$(libdir)\"" \
	-DDATADIR="\"$(pkgdatadir)\""

COMMONLIB = $(top_builddir)/editors/text/common/libTextEditor.a

bin_PROGRAMS = swing-connector
bin_SCRIPTS = swing-editor
lib_LTLIBRARIES = lib_swing.la

swing_connector_SOURCES = connector.c
swing_connector_DEPENDENCIES = $(COMMONLIB)

swing_connector_LDADD = \
	$(COMMONLIB) \
	-L$(TOOLBUSLIB)/lib \
        -L$(ERROR_SUPPORT)/lib -lLocationAPI \
	-L$(ATERM)/lib \
	-lATB \
	-lATerm \
	$(SOCKLIBS)

lib_swing_la_SOURCES = startup.c
lib_swing_la_LDFLAGS = -module
