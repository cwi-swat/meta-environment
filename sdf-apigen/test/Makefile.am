#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#
include PeanoMakeRules.am

SGLR			= ${SGLRBIN}/sglr
SDF2TABLE		= ${PGENBIN}/sdf2table
SDF2JAVA                = ${top_builddir}/utils/sdf2-to-java.test
SDF2C                   = ${top_builddir}/utils/sdf2-to-c.test

JTESTS			= PeanoTest
TESTS			= booltest $(foreach j, ${JTESTS}, $j.java.test)
check_PROGRAMS		= booltest


# C programs
INCLUDES                = -I${ATERM}/include
booltest_SOURCES	= Booleans.c Booleans_dict.c Booleans_bottom.c booltest.c
booltest_LDADD		= -L$(ATERM)/lib -lATerm
booltest_DEPENDENCIES	= booltest.pt

# Java programs
javadir = ${top_builddir}/test/classfiles
JAVAROOT = ${top_builddir}
CLASSPATH_ENV=CLASSPATH=${top_builddir}:${EXTERNAL_JARS}:${srcdir}/$(JAVAROOT)

check_JAVA = ${PeanoAPI} PeanoTest.java

CLEANFILES		= ${noinst_PROGRAMS} ${noinst_LIBRARIES} \
			Booleans.[ch] Booleans.dict \
			Booleans_dict.[ch] Booleans.trm.tbl Booleans.adt \
			booltest.pt ${PeanoAPI} libBooleans.a Booleans_bottom.c\
 			Peano.adt

EXTRA_DIST		= Booleans.sdf Booleans.pro booltest.trm Peano.sdf

Booleans.c Booleans.h: Booleans.sdf 
	${SDF2C} \
		--input $< \
		--prefix SDF \
		--compat-term \
		--verbose

booltest.pt: Booleans.trm.tbl booltest.trm 
	${SGLR} -p Booleans.trm.tbl -i ${top_srcdir}/test/booltest.trm -o $@

%.trm.tbl: %.sdf
	${SDF2TABLE} -m `basename $< .sdf` -i $< -o $@

${PeanoAPI}: Peano.sdf
	${SDF2JAVA} --input $< \
                    --output ${top_builddir}/test \
                    --package test \
                    --name Peano \
		    --verbose
	mv ${srcdir}/PeanoMakeRules ${srcdir}/PeanoMakeRules.am

%.java.test: %.java Makefile
	@(echo "#! /bin/sh";\
          echo "CLASSPATH=${top_builddir}:${EXTERNAL_JARS}";\
          echo "export CLASSPATH";\
          echo "java test.$*") > $@ && chmod +x $@
