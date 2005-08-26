# $Id$

pkgdata_DATA = moduleapi.jar

EXTRA_DIST = moduleapi.jar

MODULE_MODULES = Modules

api: module-api

ABS_MODULE_MODULES = \
	$(foreach i, \
	${MODULE_MODULES}, \
	${top_srcdir}/../asf-library/library/basic/$i.sdf)

MetaErrors.def: Makefile
	@(echo "definition"; cat ${ABS_MODULE_MODULES}) > $@

module-api: java-module-api

java-module-api: MetaModules.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--package nl.cwi.sen1
		--name moduleapi \
		--output . \
		--version ${VERSION}
	mv moduleapi-${VERSION}.jar moduleapi.jar
