# $Id: Makefile.am 25129 2008-04-28 11:24:47Z bruntink $

include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

# This is broken; clone from config-support.
if MAINTAINER_MODE
CONFIG_MODULES = Keys Colors Configuration

api: config-api

ABS_CONFIG_MODULES = \
	$(foreach i, \
	${CONFIG_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

MetaConfig.def: Makefile
	@(echo "definition"; cat ${ABS_CONFIG_MODULES}) > $@

config-api: c-config-api java-config-api

java-config-api: MetaConfig.def Makefile
	sdf2-to-java \
		--imploded \
		--input $< \
		--package nl.cwi.sen1 \
		--name configapi \
		--output . \
		--version ${VERSION}
	mv configapi-${VERSION}.jar configapi.jar

c-config-api: MetaConfig.def Makefile
	sdf2-to-c \
		--imploded \
		--input $< \
		--prefix CFG_ \
		--output Config 
	indent Config.h
endif
