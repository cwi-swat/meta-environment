# $Id$

pkgdata_DATA = errorapi-${VERSION}.jar locationapi-${VERSION}.jar

EXTRA_DIST = errorapi-${VERSION}.jar locationapi-${VERSION}.jar

lib_LIBRARIES = libErrorAPI.a libLocationAPI.a

include_HEADERS = \
	Location.h \
	Location_dict.h \
	ParsedLocation.h \
	ParsedLocation_dict.h \
	Error.h \
	Error_dict.h \
	ParsedError.h \
	ParsedError_dict.h \
	Error-utils.h

libErrorAPI_a_SOURCES = \
	Error.c \
	Error_dict.c \
	ParsedError.c \
	ParsedError_dict.c \
	init.c \
	display.c \
	lift.c \
	lower.c

libLocationAPI_a_SOURCES = \
	Location.c \
	Location_dict.c \
	ParsedLocation.c \
	ParsedLocation_dict.c

#CFLAGS += -DDISABLE_DYNAMIC_CHECKING
INCLUDES = -I${ATERM}/include

BASIC_MODULES = StrCon NatCon
LOCATION_MODULES = Locations Areas Slices
ERROR_MODULES = Errors

api: error-api location-api

ABS_ERROR_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${ERROR_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../asf-library/library/basic/$i.sdf)

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

ABS_LOCATION_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../asf-library/library/basic/$i.sdf)

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
