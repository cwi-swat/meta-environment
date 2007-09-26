# $Id$

include $(top_srcdir)/Makefile.meta

data_DATA = ioapi.jar

EXTRA_DIST += ioapi.jar

lib_LTLIBRARIES = libIOAPI.la

include_HEADERS = \
		  IO.h \
		  IO_dict.h

libIOAPI_la_CPPFLAGS = $(ATERM_CFLAGS)
libIOAPI_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libIOAPI_la_LIBADD = $(ATERM_LIBS)
libIOAPI_la_SOURCES = \
		     IO.c \
		     IO_dict.c

if MAINTAINER_MODE
IO_MODULES = File Path StrCon

api: io-api

ABS_IO_MODULES = \
	$(foreach i, \
	${IO_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

MetaIO.def: Makefile
	@(echo "definition"; cat ${ABS_IO_MODULES}) > $@

io-api: c-api java-api

c-api: MetaIO.def Makefile
	sdf2-to-c --imploded --input $< --prefix IO_ --output IO
	indent IO.h

java-api: MetaIO.def Makefile
	sdf2-to-java \
		--imploded \
		--visitable \
		--input $< \
		--package nl.cwi.sen1 \
		--name ioapi \
		--output . \
		--version ${VERSION}
	mv ioapi-${VERSION}.jar ioapi.jar
endif
