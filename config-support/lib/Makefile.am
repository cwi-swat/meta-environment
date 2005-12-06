# $Id$

pkgdata_DATA = configapi.jar

EXTRA_DIST = configapi.jar

lib_LIBRARIES = libConfigAPI.a

include_HEADERS = \
	Config.h \
	Config_dict.h

libConfigAPI_a_SOURCES = \
	Config.c
	Config_dict.c

INCLUDES = -I${ATERM}/include

api: config-api

config-api: c-config-api java-config-api

java-config-api: configuration.adt Makefile
	adt-to-java \
		--visitable \
		--input $< \
		--package nl.cwi.sen1 \
		--name configapi \
		--output . \
		--version ${VERSION}
	mv configapi-${VERSION}.jar configapi.jar

c-config-api: configuration.adt Makefile
	adt-to-c \
		--input $< \
		--name Config \
		--prefix CFG_ \
		--output .
