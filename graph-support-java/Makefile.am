
include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

# API Java code generation, is broken since it generates a jar file
# instead of a source directory.

if MAINTAINER_MODE
api: c-api java-api

c-api: Graph.adt
    adt-to-c --input $< --name Graph

java-api: Graph.adt
    adt-to-java \                                                               
        --input Graph.adt \                                                     
        --package nl.cwi.sen1 \                                                 
        --name graph \                                                          
        --version ${VERSION}
    mv graph-${VERSION}.jar graph.jar
endif
