# $Id$

EXTRA_DIST		= unparsePT.idef

bin_PROGRAMS		= flattenPT unparsePT implodePT unparseProd \
                          addPosInfo ambtracker

CFLAGS			= -g -Wall -Werror -O2
INCLUDES		= -I${top_srcdir}/libmept \
                        -I${top_srcdir}/libasfix2 \
                        -I${top_srcdir}/libconversion \
			-I${ATERM}/include \
			-I${TOOLBUS}/include

data_DATA		= unparsePT.idef

CLEANFILES		= unparsePT.tifs unparsePT.tif.[ch]

noinst_HEADERS		= unparsePT.tif.h

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
			-L${TOOLBUS}/lib -lATB \
			-L${ATERM}/lib -lATerm \
			${SOCKLIBS}

unparseProd_SOURCES	= unparseProd-main.c
unparseProd_LDADD	= -L../libmept -lmept \
			-L${ATERM}/lib -lATerm

implodePT_SOURCES	= implodePT-main.c
implodePT_LDADD		= -L../libmept -lmept \
			-L${ATERM}/lib -lATerm

ambtracker_SOURCES      = ambtracker.c
ambtracker_LDADD        = -L../libmept -lmept \
                        -L${ATERM}/lib -lATerm

%.tif.c %.tif.h: %.tifs
	$(TOOLBUS)/bin/tifstoc -tool $* $<

%.tifs: %.idef
	$(TOOLBUS)/bin/idef2tif $<
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/$@ $@ ;\
	fi
