# $Id$

pkgdata_DATA = $(wildcard *.idef)

bin_PROGRAMS=ASFSDFApigen

ASFSDFApigen_SOURCES = \
	ASFSDFApigen.c \
	toolASFSDFApigen.tif.c

ASFSDFApigen_LDADD =\
	-L${ASC_SUPPORT}/lib -lasc-support-me \
	-L${SGLR}/lib -lsglr \
	-L${ASF_SUPPORT}/lib -lASFME \
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${ERROR_SUPPORT}/lib -lErrorAPI \
	-L${TOOLBUSLIB}/lib -lATB \
	-L${ATERM}/lib -lATerm 

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

asfc: ${top_builddir}/semantics/asf-api/spec/ASFSDFApigen.eqs
	asfc -i $< -o ASFSDFApigen.c -t -v 
