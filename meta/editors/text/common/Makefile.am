# $Id$

#AM_CFLAGS = -Werror

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include

EXTRA_DIST = \
	TextEditor.c \
	TextEditor.h \
	TextEditor_dict.c \
	TextEditor_dict.h

lib_LIBRARIES = libTextEditor.a

include_HEADERS = \
	TextEditor.h \
	connector.h \
	external-startup.h

libTextEditor_a_SOURCES = \
	connector.c \
	TextEditor.c \
	TextEditor_dict.c

api: TextEditor.adt
	upgrade-adt -i $< -o $<.upgraded
	adt-to-c \
		--input $<.upgraded \
		--name TextEditor \
		--prefix TE_ \
		--version 1.1
	rm -f $<.upgraded
