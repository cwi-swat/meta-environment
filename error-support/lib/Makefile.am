# $Id$
include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libErrorAPI.la libLocationAPI.la

include_HEADERS = \
	Location.h \
	Location_dict.h \
	ParsedLocation.h \
	ParsedLocation_dict.h \
	Error.h \
	Error_dict.h \
	ParsedError.h \
	ParsedError_dict.h \
	Error-utils.h \
	Error-manager.h

libErrorAPI_la_CPPFLAGS = $(ATERM_CFLAGS)
libErrorAPI_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libErrorAPI_la_LIBADD = $(ATERM_LIBS)
libErrorAPI_la_SOURCES = \
	Error.c \
	Error_dict.c \
	ParsedError.c \
	ParsedError_dict.c \
	init.c \
	display.c \
	lift.c \
	lower.c \
	manager.c \
	Error-utils.c

libLocationAPI_la_CPPFLAGS = $(ATERM_CFLAGS)
libLocationAPI_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libLocationAPI_la_LIBADD = $(ATERM_LIBS)
libLocationAPI_la_SOURCES = \
	Location.c \
	Location_dict.c \
	ParsedLocation.c \
	ParsedLocation_dict.c

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

endif
