# $Id$

pkgdata_DATA = $(wildcard *.idef)

EXTRA_DIST = $(wildcard *.idef)

noinst_HEADERS = toolAsdfsupport.tif.h

bin_PROGRAMS=Asdfsupport

Asdfsupport_SOURCES = \
	asdfsupport.c \
	toolAsdfsupport.tif.c

Asdfsupport_LDADD =\
	-L${ASC_SUPPORT}/lib -lasc-support-me \
	-L${SGLR}/lib -lsglr \
	-L${ASF_SUPPORT}/lib -lASFME \
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${ERROR_SUPPORT}/lib -lErrorAPI \
	-L${TOOLBUSLIB}/lib -lATB \
	-L${ATERM}/lib -lATerm \
	${SOCKLIBS}

INCLUDES = \
	-DASF_MAIN\
	-DTOOLBUS\
	-I${ASC_SUPPORT}/include \
	-I${SGLR}/include \
	-I${ASF_SUPPORT}/include \
	-I${PT_SUPPORT}/include \
	-I${ERROR_SUPPORT}/include \
	-I${TOOLBUSLIB}/include  \
	-I${ATERM}/include 

asfc: ${top_builddir}/asdf-pt/asdf/asdfsupport.eqs
	asfc -i $< -o asdfsupport.c -t -v -c
