# $Id$

#AM_CFLAGS = -Werror
API_VERSION=1.0

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include

EXTRA_DIST = \
	TextEditor.c \
	TextEditor.h \
	TextEditor_dict.c \
	TextEditor_dict.h \
	texteditorapi-config.src \
	texteditorapi-${API_VERSION}.jar

pkgdata_DATA = texteditorapi-${API_VERSION}.jar

lib_LIBRARIES = libTextEditor.a

include_HEADERS = \
	TextEditor.h \
	connector.h \
	external-startup.h

libTextEditor_a_SOURCES = \
	connector.c \
	TextEditor.c \
	TextEditor_dict.c

noinst_SCRIPTS = texteditorapi-config.local
bin_SCRIPTS = texteditorapi-config

CLEANFILES = ${noinst_SCRIPTS} ${bin_SCRIPTS}

absolute_srcdir = $(shell cd ${srcdir}; pwd)

%.local: %.src Makefile
	sed	's@__VERSION__@${API_VERSION}@g; \
		 s@__PREFIX__@${absolute_srcdir}@g' \
	< $< > $@ && chmod +x $@

%: %.src Makefile
	sed	's@__VERSION__@${API_VERSION}@g; \
		 s@__PREFIX__@${prefix}share/meta@g' \
	< $< > $@ && chmod +x $@

api: TextEditor.adt
	adt-to-c \
		--input $< \
		--name TextEditor \
		--prefix TE_
	adt-to-java \
		--input $< \
		--name texteditorapi \
		--version ${API_VERSION}
