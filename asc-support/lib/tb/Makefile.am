# $Id$

lib_LIBRARIES            = libtb-asc-support-me.a

include_HEADERS = tb-asc-client.h

COPIED =\
	tb-Library.c\
	tb-Library_dict.c\
	tb-asc-main.c\
	tb-asc-muasf2pt.c\
	tb-asc-nametable.c\
	tb-asc-parsetable.c\
	tb-asc-prod2str.c\
	tb-asc-support.c\
	tb-asc-traversals.c\
	tb-builtin-annos.c\
	tb-builtin-common.c\
	tb-builtin-io.c\
	tb-builtin-forward.c\
	tb-builtin-implode.c\
	tb-builtin-lifting.c\
	tb-builtin-link-test.c\
	tb-builtin-shell.c\
	tb-builtin-term-compare.c

libtb_asc_support_me_a_SOURCES = client.c ${COPIED}
 
tb-%.c : ${top_srcdir}/lib/%.c
	cp -f $< $@

CLEANFILES+=tb-*.c

BUILT_SOURCES = ${COPIED}

# Default include directories
INCLUDES   = -DTOOLBUS  \
             -I${top_srcdir}/lib \
             -I${top_srcdir}/builtins/lib \
             -I$(PT_SUPPORT)/include \
             -I$(ASF_SUPPORT)/include \
             -I$(TOOLBUSLIB)/include \
             -I$(ATERM)/include
