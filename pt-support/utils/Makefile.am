# $Id$

SUBDIRS = implodePT 

EXTRA_DIST		= unparsePT.idef addPosInfo.idef \
                          apply-function.idef

bin_PROGRAMS		= flattenPT unparsePT unparseProd \
                          addPosInfo ambtracker tree2dot apply-function \
                          parsePT

INCLUDES		= -I${top_srcdir}/libmept \
                        -I${top_srcdir}/libasfix2 \
                        -I${top_srcdir}/libconversion \
                        -I${top_srcdir}/libptmept \
			-I${ATERM}/include \
			-I${TOOLBUSLIB}/include

pkgdata_DATA		= unparsePT.idef addPosInfo.idef \
                          apply-function.idef

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

parsePT_SOURCES	= parsePT-main.c
parsePT_LDADD		= -L../libmept -lmept \
                        -L../libptmept -lPTMEPT \
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

IDEF=idef2tif
TIFS=tifstoc

tif:
	for i in `ls *.idef`; do \
	  ${IDEF} $$i; \
	  ${TIFS} -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
	done

tif-clean:
	rm -f *.tifs *.tif.[ch]
