

lib_LIBRARIES = libasf-builtins.a

libasf_builtins_a_SOURCES := builtins.c

CLEANFILES+=builtins.c builtins.h

%.c: %.c.gen
	chmod +x $< && ./$< ${top_srcdir}/src/LIB > $@

%.h : %.h.gen
	chmod +x $< && ./$< ${top_srcdir}/src/LIB > $@
