# $Id$

lib_LIBRARIES            = libasc-support-me.a

include_HEADERS          = asc-support-me.h \
                           asc-support2-me.h  \
                           asc-traversals.h

noinst_HEADERS = muasf2pt.h \
                 prod2str.h 

libasc_support_me_a_SOURCES = asc-support.c \
                              nametable.c \
                              muasf2pt.c \
                              asc-traversals.c \
                              prod2str.c \
                              main.c

# Default include directories
INCLUDES   = -I$(PT_SUPPORT)/include \
             -I$(ASF_SUPPORT)/include \
             -I$(ATERM)/include
