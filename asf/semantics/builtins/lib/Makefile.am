SUBDIRS=booleans

# Let's find those warnings before this gets shipped
CFLAGS += -Werror

BUILTIN_NAMES=\
              set-anno get-anno\
              get-term-anno \
	      asf-normalize \
	      read-term-from-file write-term-to-file\
	      shell \
	      hashtable-lookup hashtable-store hashtable-delete \
	      strategy-some strategy-all strategy-one \
              toolbus-event toolbus-term-event \
	      term-compare-less

BUILTIN_SOURCES=common.c \
                annos.c \
		fileio.c \
		hashtable.c \
		normalize.c \
		shell.c \
		traversal.c \
                toolbus.c \
		term-compare.c \
		${srcdir}/booleans/Booleans.c \
		${srcdir}/booleans/Booleans_dict.c \
		${srcdir}/booleans/Booleans_bottom.c

noinst_LIBRARIES=libasf-builtins.a
noinst_HEADERS=asf-builtins.h common.h
libasf_builtins_a_SOURCES=forward.c ${BUILTIN_SOURCES} ./booleans/libBooleans.a

# To check whether we implemented all the builtins mentioned we
# generate a program that calls all builtins and try to compile and link 
# it:
noinst_PROGRAMS=link-test
link_test_SOURCES=$(BUILTIN_SOURCES) link-test.c
link_test_LDADD=-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
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

