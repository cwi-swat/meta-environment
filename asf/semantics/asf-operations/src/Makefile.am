# $Id$

include ${top_srcdir}/make_rules

INCLUDES = \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(SGLR)/include \
	-I$(TIDE_SUPPORT)/include \
	-I$(ASC_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

bin_PROGRAMS = asfoperations

pkgdata_DATA    = asfoperations.idef

EXTRA_DIST   = asfoperations.idef 

noinst_HEADERS 	= \
	asfoperations.tif.h \
	asfnormalization.h 

asfoperations_SOURCES = \
	asfoperations.c \
	asfoperations.tif.c \
	asfnormalization.c \
	ASF-Normalization.c

asfoperations_LDADD = \
	-L$(ASF_SUPPORT)/lib -lASFME \
	-L$(ASC_SUPPORT)/lib -lasc-support-me \
	-L$(SGLR)/lib -lsglr \
	-L$(TIDE_SUPPORT)/lib -ltide-adapter \
	-L$(PT_SUPPORT)/lib -lPTMEPT -lmept \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

# NOTE: the -a option to asfc activates rewriting with annotations,
#       which is essential here.
asfc:
	asfc -i ASF-Normalization.eqs -o ASF-Normalization.c -v -a	
