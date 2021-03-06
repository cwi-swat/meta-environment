
include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

# API Java code generation, is broken since it generates a jar file
# instead of a source directory.

if MAINTAINER_MODE
#AM_CFLAGS += -DDISABLE_DYNAMIC_CHECKING

BASIC_MODULES = StrCon NatCon Whitespace
LOCATION_MODULES = Locations Areas Slices
ERROR_MODULES = Errors

api: error-api location-api

ABS_ERROR_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${ERROR_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

MetaErrors.def: Makefile
	@(echo "definition"; cat ${ABS_ERROR_MODULES}) > $@

error-api: parsed-error-api imploded-error-api java-error-api

parsed-error-api: MetaErrors.def Makefile  
	sdf2-to-c --input $< --prefix PERR_ --output ParsedError
	indent ParsedError.h

imploded-error-api: MetaErrors.def Makefile 
	sdf2-to-c --imploded --input $< --prefix ERR_ --output Error
	indent Error.h

java-error-api: MetaErrors.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--name errorapi \
		--output . \
		--version ${VERSION}
	mv errorapi-${VERSION}.jar errorapi.jar

ABS_LOCATION_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

Location.def: Makefile
	@(echo "definition"; cat ${ABS_LOCATION_MODULES}) > $@

location-api: parsed-location-api imploded-location-api java-location-api

parsed-location-api: Location.def Makefile
	sdf2-to-c --input $< --prefix PLOC_ --output ParsedLocation
	indent ParsedLocation.h

imploded-location-api: Location.def Makefile
	sdf2-to-c --imploded --input $< --prefix LOC_ --output Location
	indent Location.h

java-location-api: Location.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--name locationapi \
		--output . \
		--version ${VERSION}
	mv locationapi-${VERSION}.jar locationapi.jar
endif
