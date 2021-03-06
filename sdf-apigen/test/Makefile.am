# $Id$
include $(top_srcdir)/Makefile.meta

SGLR			= ${SGLR_PREFIX}/bin/sglr
SDF2TABLE		= ${PGEN_PREFIX}/bin/sdf2table
SDF2JAVA                = ${top_builddir}/utils/sdf2-to-java.test
SDF2C                   = ${top_builddir}/utils/sdf2-to-c.test

JTESTS			= Peano
TESTS			= booltest $(foreach j, ${JTESTS}, $j.java.test)
check_PROGRAMS		= booltest

Peano_Main = PeanoTest

# C programs
INCLUDES                = ${ATERM_CFLAGS}

booltest_SOURCES	= Booleans.c Booleans_dict.c booltest.c
booltest_LDADD		= $(ATERM_LIBS) 
booltest_DEPENDENCIES	= booltest.pt

# Java programs
JAVAC = javac

CLEANFILES		+= ${noinst_PROGRAMS}  \
			Booleans.[ch] Booleans.dict \
			Booleans_dict.[ch] Booleans.trm.tbl Booleans.adt \
			booltest.pt libBooleans.a \
 			Peano.adt apigen.env ${TESTS} *.class *.pro *.jar

BUILT_SOURCES = \
	Booleans.c \
	Booleans.h \
	Booleans_dict.c \
	Booleans_dict.h \
	Booleans.trm.tbl \
	Booleans.dict 

distclean-local: clean-local

clean-local:
	rm -rf peano

EXTRA_DIST = \
	$(wildcard *.trm) \
	$(wildcard *.sdf) \
	$(wildcard *.java)

Booleans.c Booleans.h: Booleans.sdf 
	${SDF2C} \
		--input $< \
		--prefix SDF \
		--verbose

booltest.pt: Booleans.trm.tbl booltest.trm  Makefile
	${SGLR} -t -p Booleans.trm.tbl -i ${top_srcdir}/test/booltest.trm -o $@

%.trm.tbl: %.sdf
	${SDF2TABLE} -m `basename $< .sdf` -i $< -o $@

%.java.test: %.sdf Makefile 
	${SDF2JAVA} --input $< \
                    --output ${top_builddir} \
                    --name $* \
		    --version 0.0 \
		    --package test 
	${JAVAC} -classpath ${top_builddir}:${top_srcdir}:${ATERM_JAVA_INSTALLED_JARS} \
		${top_srcdir}/test/$($*_Main).java \
		-d ${top_builddir}
	@(echo "#! /bin/sh";\
          echo "CLASSPATH=.:${top_builddir}:${EXTERNAL_JARS}";\
          echo "export CLASSPATH";\
          echo "java test.$($*_Main) ${top_srcdir}/test") > $@ && chmod +x $@
