
include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

# API Java code generation, is broken since it generates a jar file
# instead of a source directory.

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
	sdf2-to-java \                                                                                           --imploded \                                                                                        --visitable \                                                                                       --input $< \                                                                                        --package nl.cwi.sen1 \                                                                             --name ioapi \                                                                                      --output . \                                                                                        --version ${VERSION}
	mv ioapi-${VERSION}.jar ioapi.jar

endif
