# $Id$

lib_LIBRARIES            = libtb-asc-support-me.a

include_HEADERS = tb-asc-client.h

libtb_asc_support_me_a_SOURCES = tb-asc-support.c \
                              tb-nametable.c \
                              tb-muasf2pt.c \
                              tb-asc-traversals.c \
                              tb-prod2str.c \
                              tb-main.c \
                              client.c
 
tb-%.c : ${top_srcdir}/lib/%.c
	cp -f $< $@

CLEANFILES+=tb-*.c

# Default include directories
INCLUDES   = -DTOOLBUS  \
             -I${top_srcdir}/lib \
             -I$(PT_SUPPORT)/include \
             -I$(ASF_SUPPORT)/include \
             -I$(TOOLBUSLIB)/include \
             -I$(ATERM)/include
