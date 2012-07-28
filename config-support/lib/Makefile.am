# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libConfigAPI.la

include_HEADERS = \
	Config.h \
	Config_dict.h \
	options.h

libConfigAPI_la_CPPFLAGS = $(ATERM_CFLAGS)
libConfigAPI_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libConfigAPI_la_LIBADD = $(ATERM_LIBS)
libConfigAPI_la_SOURCES = \
	Config.c \
	Config_dict.c \
	options.c

AM_CPPFLAGS += -DDISABLE_DYNAMIC_CHECKING ${ATERM_CFLAGS}

if MAINTAINER_MODE
CONFIG_MODULES = Keys Colors Configuration

api: config-api

ABS_CONFIG_MODULES = \
	$(foreach i, \
	${CONFIG_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

MetaConfig.def: Makefile
	@(echo "definition"; cat ${ABS_CONFIG_MODULES}) > $@

config-api: c-config-api 

c-config-api: MetaConfig.def Makefile
	sdf2-to-c \
		--imploded \
		--input $< \
		--prefix CFG_ \
		--output Config 
	indent Config.h
endif
