# $Id$

pkgdata_DATA = $(wildcard *.idef)

EXTRA_DIST = $(wildcard *.idef)

noinst_HEADERS = toolAsdfsupport.tif.h\
	toolTypecheck.tif.h\
	toolEval.tif.h

bin_PROGRAMS=Asdfsupport\
	Typecheck\
	Eval

Asdfsupport_SOURCES = \
	asdfsupport.c \
	toolAsdfsupport.tif.c

Typecheck_SOURCES = \
	typecheck.c \
	toolTypecheck.tif.c

Eval_SOURCES = \
	eval.c \
	toolEval.tif.c

Asdfsupport_LDADD =\
	-L${ASC_SUPPORT}/lib -lasc-support-me \
	-L${SGLR}/lib -lsglr \
	-L${ASF_SUPPORT}/lib -lASFME \
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${ERROR_SUPPORT}/lib -lErrorAPI \
	-L${TOOLBUSLIB}/lib -lATB \
	-L${ATERM}/lib -lATerm \
	${SOCKLIBS}

Typecheck_LDADD =\
	-L${ASC_SUPPORT}/lib -lasc-support-me \
	-L${SGLR}/lib -lsglr \
	-L${ASF_SUPPORT}/lib -lASFME \
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${ERROR_SUPPORT}/lib -lErrorAPI \
	-L${TOOLBUSLIB}/lib -lATB \
	-L${ATERM}/lib -lATerm \
	${SOCKLIBS}

Eval_LDADD =\
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

support: ${top_builddir}/asdf-pt/asdf/Asdfsupport.eqs
	${prefix}/bin/asfc -i $< -o asdfsupport.c -t -v -c

typecheck: ${top_builddir}/asdf-pt/type-check/typecheck.eqs
	asfc -i $< -o typecheck.c -t -v -c

eval: ${top_builddir}/asdf-pt/asdf/Eval.eqs
	${prefix}/bin/asfc -i $< -o eval.c -t -v -c
