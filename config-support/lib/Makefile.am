# $Id$

pkgdata_DATA = configapi.jar

EXTRA_DIST = configapi.jar

lib_LIBRARIES = libConfigAPI.a

include_HEADERS = \
	Config.h \
	Config_dict.h \
	options.h

libConfigAPI_a_SOURCES = \
	Config.c \
	Config_dict.c \
	options.c

AM_CFLAGS = -DDISABLE_DYNAMIC_CHECKING

INCLUDES = ${ATERM_CFLAGS}

if MAINTAINER_MODE
CONFIG_MODULES = Keys Colors Configuration

api: config-api

ABS_CONFIG_MODULES = \
	$(foreach i, \
	${CONFIG_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

MetaConfig.def: Makefile
	@(echo "definition"; cat ${ABS_CONFIG_MODULES}) > $@

config-api: c-config-api java-config-api

java-config-api: MetaConfig.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--package nl.cwi.sen1 \
		--name configapi \
		--output . \
		--version ${VERSION}
	mv configapi-${VERSION}.jar configapi.jar

c-config-api: MetaConfig.def Makefile
	sdf2-to-c \
		--imploded \
		--input $< \
		--prefix CFG_ \
		--output Config 
	indent Config.h
endif
