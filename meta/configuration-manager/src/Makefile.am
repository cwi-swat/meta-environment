# $Id$

include $(top_srcdir)/make_rules

KERNEL_CONFIGURATION = "$(pkgdatadir)/meta-kernel.properties"
USER_CONFIGURATION = "./meta.buttons"
LIBRARY_PATH = 
API_VERSION=1.0

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include

bin_PROGRAMS = configmanager
bin_SCRIPTS = metaconfig-config
noinst_SCRIPTS = metaconfig-config.local
noinst_LIBRARIES = libMetaConfig.a

pkgdata_DATA = \
	configuration-manager.idef \
	kernel-configuration.tb \
	user-configuration.tb \
	meta-kernel.properties \
	metaconfig-${API_VERSION}.jar

CLEANFILES = \
	kernel-configuration.tb \
	user-configuration.tb \
	${noinst_SCRIPTS} \
	${bin_SCRIPTS}

EXTRA_DIST = \
	metaconfig-config.src \
	metaconfig-${API_VERSION}.jar \
	configuration-manager.idef \
	kernel-configuration.tb.src \
	user-configuration.tb.src \
	meta-kernel.properties \
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

%.local: %.src Makefile
	sed     's@__VERSION__@${API_VERSION}@g;\
	        s@__PREFIX__@${absolute_srcdir}@g' \
	< $< > $@ && chmod +x $@

%: %.src Makefile
	sed     's@__VERSION__@${API_VERSION}@g;\
                 s@__PREFIX__@${prefix}share/meta@g' \
        < $< > $@ && chmod +x $@

%.tb: %.tb.src Makefile
	sed 's@__KERNEL_CONFIGURATION__@$(KERNEL_CONFIGURATION)@g;\
	    s@__USER_CONFIGURATION__@$(USER_CONFIGURATION)@g;' < $< > $@

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
