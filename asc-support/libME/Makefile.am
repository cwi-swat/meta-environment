# $Id$

lib_LIBRARIES            = libasc-support-me.a

include_HEADERS          = asc-apply-me.h \
                           asc-support-me.h \
                           asc-support2-me.h 

noinst_HEADERS = muasf2pt.h \
                 prod2str.h

libasc_support_me_a_SOURCES = asc-apply.c \
                              asc-support.c \
                              nametable.c \
                              muasf2pt.c \
                              prod2str.c \
                              main.c

#CFLAGS += -DNO_SHARING
#CFLAGS += -pg -DNO_SHARING
#CFLAGS += -pg

# Default include directories
INCLUDES   = -I$(PT_SUPPORT)/include \
             -I$(ATERM)/include
