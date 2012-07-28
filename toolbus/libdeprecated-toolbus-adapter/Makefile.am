include $(top_srcdir)/Makefile.meta

noinst_LTLIBRARIES   = libdeprecated-toolbus-adapter.la

libdeprecated_toolbus_adapter_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libdeprecated_toolbus_adapter_la_SOURCES = client.c evq.c sockets.c symbol.c \
                  terms.c tool.c tool2.c utils.c 

include_HEADERS  = procs.h sockets.h terms.h tool2.h toolbus.h tools.h \
                   utils.h symbol.h evq.h TB.h tool.h
