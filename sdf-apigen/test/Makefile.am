#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

include ${top_srcdir}/make_rules

SGLR			= ${SGLRBIN}/sglr
SDF2TABLE		= ${PGENBIN}/sdf2table
ADT_TO_C		= ${APIGEN}/bin/adt-to-c
ADTJAVA                 = ${APIGEN}/bin/adt-to-java
SDF2_TO_ADT		= ${top_builddir}/utils/sdf2-to-adt
SDF2JAVA                = ${top_builddir}/utils/sdf2-to-java
GENERATOR		= ${top_builddir}/spec/Sdf2-to-ADT
PARSETABLE		= ${top_srcdir}/spec/Sdf2-to-ADT.trm.tbl 
LABEL_EQS		= ${top_srcdir}/spec/add-labels/AddLabels.eqs 

JTESTS			= PeanoTest
TESTS			= booltest $(foreach j, ${JTESTS}, $j.java.test)
check_PROGRAMS		= booltest
check_LIBRARIES		= libBooleans.a

# C programs
libBooleans_a_SOURCES	= Booleans.c Booleans_dict.c
booltest_SOURCES	= booltest.c
booltest_LDADD		= -L. -lBooleans -L$(PT_SUPPORT)/lib -lmept \
			-L$(ATERM)/lib -lATerm
booltest_DEPENDENCIES	= booltest.pt libBooleans.a

# Java programs
javadir = ${top_builddir}/test/classfiles
JAVAROOT = ${top_builddir}
CLASSPATH_ENV = CLASSPATH=${top_builddir}:${SHARED_OBJECTS}:${JAVA_ATERM}:${srcdir}/$(JAVAROOT)::$$CLASSPATH

PeanoTestAPI = CHARLIST.java Nat_Zero.java PeanoConstructor.java \
               CHARLISTImpl.java Nat_ZeroImpl.java PeanoFactory.java \
               CHARLIST_String.java OptLayout.java \
               CHARLIST_StringImpl.java OptLayoutImpl.java Start.java \
               Nat.java OptLayout_Absent.java StartImpl.java \
               NatImpl.java OptLayout_AbsentImpl.java Start_Nat.java \
               Nat_Suc.java OptLayout_Present.java Start_NatImpl.java \
               Nat_SucImpl.java OptLayout_PresentImpl.java

check_JAVA = ${PeanoTestAPI} PeanoTest.java

CLEANFILES		= ${noinst_PROGRAMS} ${noinst_LIBRARIES} \
			Booleans.[ch] Booleans.dict \
			Booleans_dict.[ch] Booleans.trm.tbl Booleans.adt \
			booltest.pt ${PeanoTestAPI}

EXTRA_DIST		= Booleans.sdf Booleans.pro booltest.trm

Booleans.c Booleans.h: Booleans.adt
	${ADT_TO_C} \
		--input Booleans.adt \
		--prologue ${top_srcdir}/test/Booleans.pro \
		--prefix SDF \
		--compat-term 

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

${PeanoTestAPI}: 
	${ADTJAVA} --input ${top_srcdir}/test/Peano.adt \
                   --output ${top_builddir}/test \
                   --package test \
                   --name peano
	${SDF2JAVA} --name Peano -b --package test \
	            --input ${top_srcdir}/test/Peano.adt

%.java.test: %.java Makefile
	@(echo "#! /bin/sh";\
          echo "CLASSPATH=${top_builddir}:${JAVA_ATERM}:${SHARED_OBJECTS}";\
          echo "export CLASSPATH";\
          echo "java test.$*") > $@ && chmod +x $@


