#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

include ${top_srcdir}/make_rules

SGLR			= ${SGLRBIN}/sglr
SDF2TABLE		= ${PGENBIN}/sdf2table
ADT_TO_C		= ${top_builddir}/utils/adt-to-c
SDF2_TO_ADT		= ${top_builddir}/utils/sdf2-to-adt
GENERATOR		= ${top_builddir}/spec/Sdf2-to-ADT
PARSETABLE		= ${top_srcdir}/spec/Sdf2-to-ADT.trm.tbl 
LABEL_EQS		= ${top_srcdir}/spec/add-labels/AddLabels.eqs 

TESTS			= booltest 
noinst_PROGRAMS		= ${TESTS}
noinst_LIBRARIES	= libBooleans.a

libBooleans_a_SOURCES	= Booleans.c Booleans_dict.c
booltest_SOURCES	= booltest.c
booltest_LDADD		= -L. -lBooleans -L$(PT_SUPPORT)/lib -lmept \
			-L$(ATERM)/lib -lATerm
booltest_DEPENDENCIES	= booltest.pt libBooleans.a

CLEANFILES		= ${noinst_PROGRAMS} ${noinst_LIBRARIES} \
			Booleans.[ch] Booleans.dict \
			Booleans_dict.[ch] Booleans.trm.tbl Booleans.adt \
			booltest.pt

EXTRA_DIST		= Booleans.sdf Booleans.pro booltest.trm

Booleans.c Booleans.h: Booleans.adt
	${ADT_TO_C} \
		--input Booleans.adt \
		--prologue ${top_srcdir}/test/Booleans.pro \
		--prefix SDF \
		--compat-term \
		--classpath ${top_builddir}:${ATERM}/classes

booltest.pt: Booleans.trm.tbl booltest.trm
	${SGLR} -p Booleans.trm.tbl -i ${top_srcdir}/test/booltest.trm -o $@

%.adt: %.sdf ${PARSETABLE} ${LABEL_EQS} ${GENERATOR}
	${SDF2_TO_ADT} \
		--input $< \
		--output $@ \
		--table ${PARSETABLE} \
		--label ${LABEL_EQS} \
		--generator ${GENERATOR}

%.trm.tbl: %.sdf
	${SDF2TABLE} -m `basename $< .sdf` -i $< -o $@
