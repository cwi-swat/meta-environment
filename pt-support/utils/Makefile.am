# $Id$

SUBDIRS = implodePT

EXTRA_DIST		= unparsePT.idef

bin_PROGRAMS		= flattenPT unparsePT unparseProd \
                          addPosInfo ambtracker tree2dot apply-function

INCLUDES		= -I${top_srcdir}/libmept \
                        -I${top_srcdir}/libasfix2 \
                        -I${top_srcdir}/libconversion \
			-I${ATERM}/include \
			-I${TOOLBUSLIB}/include

data_DATA		= unparsePT.idef

CLEANFILES		= unparsePT.tifs unparsePT.tif.[ch]

noinst_HEADERS		= unparsePT.tif.h

apply_function_SOURCES  = apply-function.c
apply_function_LDADD    = -L../libmept -lmept \
                        -L${ATERM}/lib -lATerm

addPosInfo_SOURCES      = addPosInfo.c
addPosInfo_LDADD        = -L../libmept -lmept \
                        -L${ATERM}/lib -lATerm

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

%.tif.c %.tif.h: %.tifs
	PATH=$(TOOLBUS)/bin:$${PATH} tifstoc -tool $* $<

%.tifs: %.idef
	PATH=$(TOOLBUS)/bin:$${PATH} idef2tif $<
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/$@ $@ ;\
	fi
