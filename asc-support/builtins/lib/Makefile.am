BUILTIN_NAMES=\
              set-anno get-anno\
	      asf-normalize \
	      read-term-from-file write-term-to-file\
	      shell \
	      hashtable-lookup hashtable-store hashtable-delete \
	      strategy-some strategy-all strategy-one

BUILTIN_SOURCES=\
                annos.c \
		fileio.c \
		hashtable.c \
		normalize.c \
		shell.c \
		traversal.c

noinst_LIBRARIES=libasf-builtins.a
noinst_HEADERS=asf-builtins.h
libasf_builtins_a_SOURCES=forward.c ${BUILTIN_SOURCES}

# To check whether we implemented all the builtins mentioned we
# generate a program that calls all builtins and try to compile and link 
# it:
noinst_PROGRAMS=link-test
link_test_SOURCES=$(BUILTIN_SOURCES) link-test.c
link_test_LDADD=-L${PT_SUPPORT}/lib -lmept \
		-L${ATERM}/lib -lATerm
INCLUDES=-I$(ATERM)/include -I$(PT_SUPPORT)/include

UTILS=${top_srcdir}/semantics/builtins/utils
GENFWD=${UTILS}/gen-forward.sh
GENPRTS=${UTILS}/gen-protos.sh
GENLNKTST=${UTILS}/gen-link-test.sh

CLEANFILES+=forward.c asf-builtins.h link-test.c

forward.c: ${BUILTIN_SOURCES} Makefile
	${GENFWD} "${BUILTIN_NAMES}" > $@

asf-builtins.h: ${BUILTIN_SOURCES} Makefile
	${GENPRTS} "${BUILTIN_NAMES}" > $@

link-test.c: Makefile asf-builtins.h ${BUILTIN_SOURCES}
	${GENLNKTST} "${BUILTIN_NAMES}" > $@

