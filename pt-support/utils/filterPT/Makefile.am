
SUBDIRS = test

bin_PROGRAMS = filterPT

noinst_HEADERS = \
	minmax.h \
	flattenAgain.h

INCLUDES = \
        -I${top_srcdir}/libmept \
        ${ERROR_SUPPORT_CFLAGS}

filterPT_SOURCES = \
	main.c \
	minmax.c \
	flattenAgain.c

filterPT_LDADD =\
        -L${top_builddir}/libmept -lmept \
        ${ERROR_SUPPORT_LIBS}
