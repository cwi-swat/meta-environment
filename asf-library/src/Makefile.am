include ${top_srcdir}/templates/make_rules

BUILTIN_NAMES=$(shell cat ${srcdir}/builtins.lst | sed 's@^.*:@@g')
BUILTIN_OBJECTS=$(shell cat ${srcdir}/objects.lst | sed 's@:@/@g')
LIB_OBJECTS=$(foreach o,$(BUILTIN_OBJECTS),${top_builddir}/$o)

CLEANFILES+=builtins.o forward.c asf-builtins.h

lib_LIBRARIES=libasf-builtins.a
libasf_builtins_a_LIBADD=builtins.o
libasf_builtins_a_SOURCES=forward.c
include_HEADERS=asf-builtins.h

builtins.o: $(LIB_OBJECTS)
	$(LD) -r $(LIB_OBJECTS) -o $@

forward.c: $(LIB_OBJECTS)
	$(top_builddir)/utils/gen-forward.sh "${BUILTIN_NAMES}" > $@

asf-builtins.h: $(LIB_OBJECTS)
	$(top_builddir)/utils/gen-protos.sh "${BUILTIN_NAMES}" > $@

CLEANFILES+=asf-builtins.h asf-forward.c

INCLUDES=-I$(ATERM)/include -I$(PT_SUPPORT)/include
