BUILTIN_NAMES=\
              set-anno get-anno\
              get-term-anno \
	      asf-normalize \
	      read-term-from-file write-term-to-file\
	      shell \
	      strategy-some strategy-all strategy-one \
              toolbus-event toolbus-term-event \
	      term-compare\
	      lift-to-tree lift-to-term \
	      unparse

BUILTIN_SOURCES=common.c \
                annos.c \
		fileio.c \
		normalize.c \
		shell.c \
		traversal.c \
                toolbus.c \
		term-compare.c \
		lifting.c\
		unparse.c

#The names of the modules that need to be included in a generated lib
LIBRARY_MODULES=basic/Booleans utilities/Measure

#Below here should not be changed when adding a builtin:

EXTRA_DIST = Library.def

noinst_LIBRARIES=libasf-builtins.a
noinst_HEADERS=asf-builtins.h common.h Library.h Library_dict.h

libasf_builtins_a_SOURCES=\
	forward.c\
	Library.c\
	Library_dict.c\
	Library_bottom.c\
	${BUILTIN_SOURCES} 

# To check whether we implemented all the builtins mentioned we
# generate a program that calls all builtins and try to compile and link 
# it:
noinst_PROGRAMS=link-test
link_test_SOURCES=link-test.c
link_test_LDADD=\
	-L. -lasf-builtins\
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${TOOLBUSLIB}/lib -lATB  \
	-L${ATERM}/lib -lATerm \
	${SOCKLIBS}

INCLUDES=-I$(ATERM)/include -I$(PT_SUPPORT)/include -I$(TOOLBUSLIB)/include \
	 -I$(srcdir)/booleans

UTILS=${top_srcdir}/semantics/builtins/utils
GENFWD=${UTILS}/gen-forward.sh
GENPRTS=${UTILS}/gen-protos.sh
GENLNKTST=${UTILS}/gen-link-test.sh

CLEANFILES+=forward.c asf-builtins.h link-test.c

forward.c: asf-builtins.h ${BUILTIN_SOURCES} Makefile
	${GENFWD} "${BUILTIN_NAMES}" > $@

asf-builtins.h: ${BUILTIN_SOURCES} Makefile
	${GENPRTS} "${BUILTIN_NAMES}" > $@

link-test.c: asf-builtins.h ${BUILTIN_SOURCES} Makefile 
	${GENLNKTST} "${BUILTIN_NAMES}" > $@

# Developers only:
api: Library.def
	sdf2-to-c -i $< -P CO_ -o Library

api-clean:
	rm -f Library.[ch] Library_dict.* Library.adt Library_bottom.c

LIBRARY=$(foreach i,${LIBRARY_MODULES},${top_srcdir}/../asf-library/library/$i.sdf)

Library.def:
	@(echo "definition" ; \
          cat ${LIBRARY}) > \
	  $@
