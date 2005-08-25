# $Id$

include $(top_srcdir)/make_rules

USER_CONFIGURATION = "./meta.buttons"
LIBRARY_PATH = 
API_VERSION=1.0

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include

bin_PROGRAMS = configmanager
noinst_LIBRARIES = libMetaConfig.a

pkgdata_DATA = \
	configuration-manager.idef \
	user-configuration.tb \
	metaconfig-${API_VERSION}.jar

CLEANFILES = \
	user-configuration.tb \
	${noinst_SCRIPTS} \
	${bin_SCRIPTS}

EXTRA_DIST = \
	metaconfig-${API_VERSION}.jar \
	configuration-manager.idef \
	user-configuration.tb.src \
	metaconfig-${API_VERSION}.jar

noinst_HEADERS = \
	configuration-manager.tif.h \
	configmanager.h

include_HEADERS = \
	MetaConfig.h \
	MetaConfig_dict.h 

configmanager_SOURCES = \
	MetaConfig.c \
	MetaConfig_dict.c \
	configmanager.c \
	configuration-manager.tif.c

libMetaConfig_a_SOURCES = \
	MetaConfig.c \
	MetaConfig_dict.c 

configmanager_LDADD = \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

absolute_srcdir=$(shell cd ${srcdir}; pwd)

%.tb: %.tb.src Makefile
	sed 's@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@

api:
	adt-to-c \
		--input configuration.adt \
		--name MetaConfig \
		--prefix MC_ \
		--output . 
	adt-to-java \
                --input configuration.adt \
                --name metaconfig \
                --output . \
                --version ${API_VERSION}
