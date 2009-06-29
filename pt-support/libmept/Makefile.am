# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libmept.la

include_HEADERS = \
	MEPT.h \
	MEPT-utils.h \
	MEPT_dict.h \
	MEPT-ambtracker.h \
	MEPT-annotations.h \
	MEPT-apply.h \
	MEPT-args.h \
	MEPT-characters.h \
	MEPT-flatten.h \
	MEPT-implode.h \
	MEPT-layout.h \
	MEPT-length.h \
	MEPT-ordering.h \
	MEPT-origins.h \
	MEPT-posinfo.h \
	MEPT-productions.h \
	MEPT-renaming.h \
	MEPT-start.h \
	MEPT-symbols.h \
	MEPT-tree.h \
	MEPT-visitors.h \
	MEPT-yield.h \
	MEPT-yieldprod.h

libmept_la_CPPFLAGS = $(ERROR_SUPPORT_CFLAGS) $(ATERM_CFLAGS) -DDISABLE_DYNAMIC_CHECKING -DFAST_API
libmept_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libmept_la_LIBADD   = $(ERROR_SUPPORT_LIBS) $(ATERM_LIBS)
libmept_la_SOURCES = \
		    MEPT.c \
		    MEPT_dict.c \
		    MEPT-ambtracker.c \
		    MEPT-annotations.c \
		    MEPT-apply.c \
		    MEPT-args.c \
		    MEPT-characters.c \
		    MEPT-flatten.c \
		    MEPT-implode.c \
		    MEPT-layout.c \
		    MEPT-length.c \
		    MEPT-ordering.c \
		    MEPT-origins.c \
		    MEPT-posinfo.c \
		    MEPT-productions.c \
		    MEPT-renaming.c \
		    MEPT-start.c \
		    MEPT-symbols.c \
		    MEPT-tree.c \
		    MEPT-visitors.c \
		    MEPT-yield.c \
		    MEPT-yieldprod.c

api: MEPT.adt
	adt-to-c \
		--prefix PT_ \
		--name MEPT \
		--input $<

api-clean:
	$(RM) MEPT.[ch] MEPT_dict.[ch] MEPT.dict
