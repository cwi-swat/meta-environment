# $Id$

SUBDIRS = add-labels

bin_PROGRAMS = Sdf2-to-ADT Sdf2-to-Imploded-ADT

pkgdata_DATA = Sdf2-to-ADT.trm.tbl

EXTRA_DIST = \
	$(wildcard *.sdf) \
	$(wildcard *.asf) \
	$(wildcard *.tbl) \
	$(wildcard *.eqs)

Sdf2_to_ADT_CPPFLAGS = -DASF_MAIN $(ASC_SUPPORT_CFLAGS)
Sdf2_to_ADT_SOURCES = Sdf2-to-AsFix2ME-ADT.c
Sdf2_to_ADT_LDADD = $(ASC_SUPPORT_LIBS)

Sdf2_to_Imploded_ADT_CPPFLAGS = -DASF_MAIN $(ASC_SUPPORT_CFLAGS)
Sdf2_to_Imploded_ADT_SOURCES = Sdf2-to-Imploded-ADT.c
Sdf2_to_Imploded_ADT_LDADD = $(ASC_SUPPORT_LIBS)

table:
	pt-dump -m Sdf2-to-AsFix2ME-ADT -o Sdf2-to-ADT.trm.tbl

compile-spec: dump asfc

dump:
	eqs-dump -m Sdf2-to-AsFix2ME-ADT -o Sdf2-to-AsFix2ME-ADT.eqs
	eqs-dump -m Sdf2-to-Imploded-ADT -o Sdf2-to-Imploded-ADT.eqs

asfc:
	asfc -i Sdf2-to-AsFix2ME-ADT.eqs -o Sdf2-to-AsFix2ME-ADT.c -v
	asfc -i Sdf2-to-Imploded-ADT.eqs -o Sdf2-to-Imploded-ADT.c -v
