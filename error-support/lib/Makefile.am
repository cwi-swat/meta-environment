# $Id$

pkgdata_DATA = errorapi-${VERSION}.jar locationapi-${VERSION}.jar

EXTRA_DIST = errorapi-${VERSION}.jar locationapi-${VERSION}.jar

lib_LIBRARIES = libErrorAPI.a libLocationAPI.a

include_HEADERS = \
	LocationAPI.h \
	LocationAPI_dict.h \
	ParsedLocationAPI.h \
	ParsedLocationAPI_dict.h \
	ErrorAPI.h \
	ErrorAPI_dict.h \
	ParsedErrorAPI.h \
	ParsedErrorAPI_dict.h \
	ErrorAPI-utils.h

libErrorAPI_a_SOURCES = \
	ErrorAPI.c \
	ErrorAPI_dict.c \
	ParsedErrorAPI.c \
	ParsedErrorAPI_dict.c \
	init.c \
	display.c \
	lift.c \
	lower.c

libLocationAPI_a_SOURCES = \
	LocationAPI.c \
	LocationAPI_dict.c \
	ParsedLocationAPI.c \
	ParsedLocationAPI_dict.c

#CFLAGS += -DDISABLE_DYNAMIC_CHECKING
INCLUDES = -I${ATERM}/include

BASIC_MODULES = basic/StrCon basic/NatCon
LOCATION_MODULES = basic/Locations
FEEDBACK_MODULES = basic/Feedback

api: error-api location-api

ABS_ERROR_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${FEEDBACK_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../asf-library/library/$i.sdf)

MetaErrors.def: Makefile
	@(echo "definition"; cat ${ABS_ERROR_MODULES}) > $@

error-api: parsed-error-api imploded-error-api errorapi-${VERSION}.jar

parsed-error-api: MetaErrors.def Makefile  
	sdf2-to-c --input $< --prefix PERR_ --output ParsedErrorAPI
	indent ParsedErrorAPI.h

imploded-error-api: MetaErrors.def Makefile 
	sdf2-to-c --imploded --input $< --prefix ERR_ --output ErrorAPI
	indent ErrorAPI.h

errorapi-${VERSION}.jar: MetaErrors.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--name errorapi \
		--output . \
		--version ${VERSION}

ABS_LOCATION_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../asf-library/library/$i.sdf)

Location.def: Makefile
	@(echo "definition"; cat ${ABS_LOCATION_MODULES}) > $@

location-api: parsed-location-api imploded-location-api locationapi-${VERSION}.jar

parsed-location-api: Location.def Makefile
	sdf2-to-c --input $< --prefix PLOC_ --output ParsedLocationAPI
	indent ParsedLocationAPI.h

imploded-location-api: Location.def Makefile
	sdf2-to-c --imploded --input $< --prefix LOC_ --output LocationAPI
	indent LocationAPI.h

locationapi-${VERSION}.jar: Location.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--name locationapi \
		--output . \
		--version ${VERSION}
