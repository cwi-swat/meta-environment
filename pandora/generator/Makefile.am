# $Id$

#AM_CFLAGS = -Werror

INCLUDES = \
	-I$(ASC_SUPPORT)/include \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

EXTRA_DIST = \
	Box_dict.c \
	Box_dict.h

bin_PROGRAMS = pandora 

noinst_HEADERS = pandora.h Box.h Box-utils.h

pandora_SOURCES = main.c pandora.c Box.c Box-utils.c Box_dict.c Box-to-Text.c
pandora_LDADD = \
	-L$(ASC_SUPPORT)/lib -lasc-support-me \
	-L$(SGLR)/lib -lsglr \
	-L$(ASF_SUPPORT)/lib -lASFME \
	-L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm-dbg \
	-lefence

api:
	unparsePT < Box.def.pt > Box.def
	sdf2-to-c -i Box.def --prefix BOX_ -v
