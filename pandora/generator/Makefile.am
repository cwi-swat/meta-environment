# $Id$

CFLAGS += -Werror

INCLUDES = \
	-I$(PT_SUPPORT)/include \
	-I$(ATERM)/include

bin_PROGRAMS = pandora 

noinst_HEADERS = pandora.h Box.h

pandora_SOURCES = main.c pandora.c Box.c Box_dict.c
pandora_LDADD = \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ATERM)/lib -lATerm 

api:
	unparsePT < Box.def.pt > Box.def
	sdf2-to-c -i Box.def --prefix BOX_ -v
