lib_LIBRARIES   = libtb.a

libtb_a_SOURCES = client.c evq.c sockets.c symbol.c \
                  terms.c tool.c tool2.c utils.c \
                  $(ALLINCLUDES)

PUBLIC_INCL     = procs.h sockets.h terms.h tool2.h toolbus.h tools.h \
                  utils.h symbol.h evq.h TB.h tool.h

ALLINCLUDES     = $(PUBLIC_INCL)

include_HEADERS = $(ALLINCLUDES)

INCLUDES        = -I$(srcdir)
