#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

SUBDIRS		= add-labels

bin_PROGRAMS	= Sdf2-to-ADT Sdf2-to-Imploded-ADT

CFLAGS		= -g -Wall -Wno-unused -O2 -DASF_MAIN

INCLUDES	= -I$(ASCINC) \
		-I$(PT_SUPPORT)/include \
		-I$(ASF_SUPPORT)/include \
		-I$(ATERM)/include

pkgdata_DATA	= Sdf2-to-ADT.trm.tbl
CLEANFILES	= ${pkgdata_DATA}

EXTRA_DIST	= \
	$(wildcard *.sdf) \
	$(wildcard *.asf) \
	$(wildcard *.tbl) \
	$(wildcard *.eqs)

Sdf2_to_ADT_SOURCES	= Sdf2-to-AsFix2ME-ADT.c
Sdf2_to_ADT_LDADD	= -L$(ASCLIB) -lasc-support-me \
			-L$(SGLR)/lib -lsglr \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
			-L$(ATERM)/lib -lATerm

Sdf2_to_Imploded_ADT_SOURCES = Sdf2-to-Imploded-ADT.c
Sdf2_to_Imploded_ADT_LDADD = -L$(ASCLIB) -lasc-support-me \
			-L$(SGLR)/lib -lsglr \
			-L$(ASF_SUPPORT)/lib -lASFME \
			-L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
			-L$(ATERM)/lib -lATerm

table:
	pt-dump -m Sdf2-to-AsFix2ME-ADT -o Sdf2-to-ADT.trm.tbl

compile-spec: dump asfc

dump:
	eqs-dump -m Sdf2-to-AsFix2ME-ADT -o Sdf2-to-AsFix2ME-ADT.eqs
	eqs-dump -m Sdf2-to-Imploded-ADT -o Sdf2-to-Imploded-ADT.eqs

asfc:
	asfc -i Sdf2-to-AsFix2ME-ADT.eqs -o Sdf2-to-AsFix2ME-ADT.c -v
	asfc -i Sdf2-to-Imploded-ADT.eqs -o Sdf2-to-Imploded-ADT.c -v
