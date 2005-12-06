# $Id$

pkgdata_DATA = configapi.jar

EXTRA_DIST = configapi.jar

api: config-api

config-api: java-config-api

java-config-api: configuration.adt Makefile
	adt-to-java \
		--visitable \
		--input $< \
		--package nl.cwi.sen1 \
		--name configapi \
		--output . \
		--version ${VERSION}
	mv configapi-${VERSION}.jar configapi.jar
