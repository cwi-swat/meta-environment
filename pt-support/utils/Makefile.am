# $Id$

SUBDIRS = implodePT

EXTRA_DIST		= unparsePT.idef addPosInfo.idef \
                          apply-function.idef 

bin_PROGRAMS		= flattenPT unparsePT unparseProd \
                          addPosInfo ambtracker tree2dot apply-function

INCLUDES		= -I${top_srcdir}/libmept \
                        -I${top_srcdir}/libasfix2 \
                        -I${top_srcdir}/libconversion \
			-I${ATERM}/include \
			-I${TOOLBUSLIB}/include

pkgdata_DATA		= unparsePT.idef addPosInfo.idef apply-function.idef

noinst_HEADERS		= unparsePT.tif.h apply-function.tif.h \
                          addPosInfo.tif.h

apply_function_SOURCES  = apply-function.tif.c apply-function.c
apply_function_LDADD    = -L../libmept -lmept \
			-L${TOOLBUSLIB}/lib -lATB \
			-L${ATERM}/lib -lATerm \
			${SOCKLIBS}

addPosInfo_SOURCES      = addPosInfo.tif.c addPosInfo.c
addPosInfo_LDADD        = -L../libmept -lmept \
			-L${TOOLBUSLIB}/lib -lATB \
                        -L${ATERM}/lib -lATerm \
                        ${SOCKLIBS}

flattenPT_SOURCES	= flattenPT-main.c
flattenPT_LDADD		= -L../libconversion -lconversion \
                        -L../libmept -lmept \
                        -L../libasfix2 -lasfix2 \
			-L${ATERM}/lib -lATerm

unparsePT_SOURCES	= unparsePT.tif.c unparsePT-main.c
unparsePT_LDADD		= -L../libmept -lmept \
			-L${TOOLBUSLIB}/lib -lATB \
			-L${ATERM}/lib -lATerm \
			${SOCKLIBS}

unparseProd_SOURCES	= unparseProd-main.c
unparseProd_LDADD	= -L../libmept -lmept \
			-L${ATERM}/lib -lATerm

ambtracker_SOURCES      = ambtracker-main.c
ambtracker_LDADD        = -L../libmept -lmept \
                        -L${ATERM}/lib -lATerm

tree2dot_SOURCES        = tree2dot-main.c
tree2dot_LDADD          = -L../libmept -lmept \
                          -L${ATERM}/lib -lATerm

IDEF=${TOOLBUS}/bin/idef2tif
TIFS=${TOOLBUS}/bin/tifstoc

tif:
	${IDEF} unparsePT.idef
	${TIFS} -tool unparsePT unparsePT.tifs
	${IDEF} addPosInfo.idef
	${TIFS} -tool addPosInfo addPosInfo.tifs 
	${IDEF} apply-function.idef
	${TIFS} -tool apply-function apply-function.tifs

tif-clean:
	rm -f *.tifs *.tif.[ch]
