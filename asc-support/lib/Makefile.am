# $Id$

#SUBDIRS=tb

BUILTIN_NAMES_ARITY=\
        set-anno_3\
	get-anno_2\
	get-term-anno_2 \
	read-term-from-file_1 \
	write-term-to-file_2\
	shell_1 \
	term-compare_2\
	lift-to-tree_1 \
	lift-to-term_1 \
	unparse_1

BUILTIN_SOURCEFILES=\
	builtin-common.c \
	builtin-common.h \
	builtin-annos.c \
	builtin-fileio.c \
	builtin-shell.c \
	builtin-term-compare.c \
	builtin-lifting.c\
	builtin-unparse.c

#The names of the modules that need to be included in a generated lib
LIBRARY_MODULES=basic/Booleans utilities/Measure

lib_LIBRARIES = libasc-support-me.a 

include_HEADERS = \
	asc-support-me.h \
	asc-support2-me.h  \
	asc-traversals.h \
	asc-builtins.h

libasc_support_me_a_SOURCES = \
	asc-main.c\
	asc-support.c \
	asc-nametable.c \
	asc-traversals.c \
	asc-prod2str.c  \
	asc-prod2str.h  \
	asc-muasf2pt.c \
	asc-muasf2pt.h \
	builtin-forward.c\
	Library.c\
	Library.h\
	Library_dict.c\
	Library_dict.h\
	Library_bottom.c\
	${BUILTIN_SOURCEFILES} 

# Default include directories
INCLUDES = \
	-I$(PT_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(ATERM)/include 

TESTS=builtin-link-test

#Below here should not be changed when adding a builtin:

EXTRA_DIST = Library.def 

# To check whether we implemented all the builtins mentioned we
# generate a program that calls all builtins and try to compile and link 
# it:
check_PROGRAMS=builtin-link-test
builtin_link_test_SOURCES=builtin-link-test.c
builtin_link_test_LDADD=\
	-L. -lasc-support-me\
	-L${ASF_SUPPORT}/lib -lASFME \
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${TOOLBUSLIB}/lib -lATB  \
	-L${ATERM}/lib -lATerm \
	${SOCKLIBS}

UTILS=${top_srcdir}/utils
GENFWD=${UTILS}/gen-forward.sh
GENPRTS=${UTILS}/gen-protos.sh
GENLNKTST=${UTILS}/gen-link-test.sh

CLEANFILES+=builtin-forward.c asc-builtins.h builtin-link-test.c

builtin-forward.c: asc-builtins.h ${BUILTIN_SOURCEFILES} Makefile
	${GENFWD} "${BUILTIN_NAMES_ARITY}" > $@

asc-builtins.h: ${BUILTIN_SOURCES} Makefile
	${GENPRTS} "${BUILTIN_NAMES_ARITY}" > $@

builtin-link-test.c: asc-builtins.h ${BUILTIN_SOURCEFILES} Makefile 
	${GENLNKTST} "${BUILTIN_NAMES_ARITY}" > $@

# Developers only:
api: Library.def
	sdf2-to-c -i $< -P CO_ -o Library

api-clean:
	rm -f Library.[ch] Library_dict.* Library.adt Library_bottom.c

LIBRARYLIST=\
$(foreach i,${LIBRARY_MODULES},${top_srcdir}/../asf-library/library/$i.sdf)

Library.def:
	@(echo "definition" ; \
          cat ${LIBRARYLIST}) > \
	  $@
