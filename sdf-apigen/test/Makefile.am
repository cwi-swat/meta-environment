# $Id$

SGLR			= ${SGLRBIN}/sglr
SDF2TABLE		= ${PGENBIN}/sdf2table
SDF2JAVA                = ${top_builddir}/utils/sdf2-to-java.test
SDF2C                   = ${top_builddir}/utils/sdf2-to-c.test

JTESTS			= Peano
TESTS			= booltest $(foreach j, ${JTESTS}, $j.java.test)
check_PROGRAMS		= booltest

Peano_Main = PeanoTest

# C programs
INCLUDES                = -I${ATERM}/include
booltest_SOURCES	= Booleans.c Booleans_dict.c Booleans_bottom.c booltest.c
booltest_LDADD		= -L$(ATERM)/lib -lATerm
booltest_DEPENDENCIES	= booltest.pt

# Java programs
JAVAC = javac

CLEANFILES		= ${noinst_PROGRAMS} ${noinst_LIBRARIES} \
			Booleans.[ch] Booleans.dict \
			Booleans_dict.[ch] Booleans.trm.tbl Booleans.adt \
			booltest.pt libBooleans.a Booleans_bottom.c\
 			Peano.adt apigen.env ${TESTS} *.class *.pro

clean:
	rm -rf peano

EXTRA_DIST = \
	$(wildcard *.trm) \
	$(wildcard *.sdf) \
	$(wildcard *.java)

Booleans.c Booleans.h: Booleans.sdf 
	${SDF2C} \
		--input $< \
		--prefix SDF \
		--term-compatibility \
		--verbose

booltest.pt: Booleans.trm.tbl booltest.trm 
	${SGLR} -p Booleans.trm.tbl -i ${top_srcdir}/test/booltest.trm -o $@

%.trm.tbl: %.sdf
	${SDF2TABLE} -m `basename $< .sdf` -i $< -o $@

%.java.test: %.sdf Makefile 
	${SDF2JAVA} --input $< \
                    --output ${top_srcdir} \
                    --name $* \
		    --package test \
		    --verbose
	${JAVAC} -classpath ${top_srcdir}:${JAVA_ATERM} \
		${top_srcdir}/test/$($*_Main).java
	@(echo "#! /bin/sh";\
          echo "CLASSPATH=.:${top_srcdir}:${EXTERNAL_JARS}";\
          echo "export CLASSPATH";\
          echo "java test.$($*_Main) ${top_srcdir}/test") > $@ && chmod +x $@
