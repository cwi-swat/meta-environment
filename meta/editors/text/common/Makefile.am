# $Id$

CFLAGS += -Werror

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUS)/include

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
	adt-to-c --prefix TE_ --input $<
