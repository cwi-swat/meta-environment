# $Id$

AM_CFLAGS = -Werror

INCLUDES = \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

EXTRA_DIST = \
	Box_dict.c \
	Box_dict.h

bin_PROGRAMS = pandora 

noinst_HEADERS = pandora.h Box.h

pandora_SOURCES = main.c pandora.c Box.c Box_dict.c
pandora_LDADD = \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ATERM)/lib -lATerm-dbg \
	-lefence

api:
	unparsePT < Box.def.pt > Box.def
	sdf2-to-c -i Box.def --prefix BOX_ -v
