include ${top_srcdir}/templates/make_rules


BUILTIN_NAMES:=$(shell cd $(top_srcdir)/lib; grep -r "built-in" * | \
                       sed -e 's@.*built-in(\"\(.*\)\").*@\1@g' | \
                       sed -e 's@-@_@g')

include_HEADERS=asf-builtins.h
lib_LIBRARIES=libasf-builtins.a

libasf_builtins_a_SOURCES=asf-builtins.h asf-builtins.c asf-forward.c 

EXTRA_DIST=$(wildcard *.gen)
CLEANFILES+=asf-builtins.h asf-forward.c

INCLUDES=-I$(ATERM)/include -I$(PT_SUPPORT)/include

noinst_PROGRAMS=link-test
link_test_SOURCES=link-test.c
link_test_LDADD=-L. -lasf-builtins \
                -L${PT_SUPPORT}/lib -lmept \
                -L${ATERM}/lib -lATerm

%.h: %.h.gen
	chmod +x $< && ${srcdir}/$< "$(BUILTIN_NAMES)" > $@

%.c: %.c.gen
	chmod +x $< && ${srcdir}/$< "$(BUILTIN_NAMES)" > $@
