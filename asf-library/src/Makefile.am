include ${top_srcdir}/templates/make_rules

include_HEADERS=asf-builtins.h
lib_LIBRARIES=libasf-builtins.a

libasf_builtins_a_SOURCES=asf-builtins.h asf-builtins.c 

CLEANFILES+=${include_HEADERS} ${libasf_builtins_a_SOURCES}

INCLUDES=-I$(ATERM)/include -I$(PT_SUPPORT)/include

%.c: %.c.gen 
	chmod +x $< && ./$< ${LIBROOT} > $@

%.h : %.h.gen
	chmod +x $< && ./$< ${LIBROOT} > $@
