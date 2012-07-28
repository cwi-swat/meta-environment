# $Id$

include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

if MAINTAINER_MODE
MODULE_MODULES = Modules NatCon

# This is broken; clone from module-support.
api: module-api

ABS_MODULE_MODULES = \
	$(foreach i, \
	${MODULE_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

MetaModules.def: Makefile
	@(echo "definition"; cat ${ABS_MODULE_MODULES}) > $@

module-api: java-module-api

java-module-api: MetaModules.def Makefile
	sdf2-to-java \
		--imploded \
		--visitable \
		--input $< \
		--package nl.cwi.sen1 \
		--name moduleapi \
		--output . \
		--version ${VERSION}
	mv moduleapi-${VERSION}.jar moduleapi.jar
endif
