# $Id$

SUBDIRS = metaedit

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
pkgdata_DATA = swing-editor.jar

CLEANFILES = \
	swing-editor.jar \
	swing-editor

EXTRA_DIST = swing-editor.src

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

TEXTEDITORAPI_JAR = $(shell ${top_builddir}/editors/text/common/texteditorapi-config)
METACONFIG_JAR = $(shell ${top_builddir}/configuration-manager/src/metaconfig-config)

% : %.src Makefile
	sed 's@__JARS@${EXTERNAL_JARS}:${TEXTEDITORAPI_JAR}:${METACONFIG_JAR}:${prefix}/share/swing-editor.jar@g' \
	< $< > $@ && chmod +x $@

JARCLASSES = `find . -name '*.class'`
JARIMAGES = \
	$(wildcard ${srcdir}/metaedit/images/*gif) \
	$(wildcard ${srcdir}/metaedit/images/*png)

JARFILES = \
	${JARIMAGES} \
	${JARCLASSES}

.PHONY: swing-editor.jar
	FILES = "${JARFILES}"; \
	jar cf $@ $$FILES
