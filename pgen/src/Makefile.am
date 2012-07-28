include $(top_srcdir)/Makefile.meta

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(ASF_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS) \
	$(PTABLE_SUPPORT_CFLAGS) \
	$(CONFIG_SUPPORT_CFLAGS) \
	$(C_LIBRARY_CFLAGS) 
#	-DPGEN_COLLECT_STATISTICS

TESTS		= $(check_PROGRAMS)
check_PROGRAMS	= test-chars
bin_PROGRAMS	= sdf2table
lib_LTLIBRARIES = libsdftablegen.la
pkgdata_DATA	= parsetablegen.idef

noinst_HEADERS = \
	normalize.h \
	load.h \
	atsets.h \
	flatten.h \
	predicted.h \
	goto.h \
	follow.h \
	intset.h \
	characters.h \
	item.h \
	first.h \
	priorities.h \
	itemset.h \
	pgen-symbol.h \
	pgenOptions.h \
	parseTable-stats.h

include_HEADERS=\
	sdf-generate.h \
	ksdf2table.h \
	parseTable-data.h 

libsdftablegen_la_SOURCES =  \
	generate.c \
	ksdf2table.c \
	atsets.c \
	flatten.c \
	characters.c \
	first.c \
	follow.c \
	goto.c \
	predicted.c \
	priorities.c \
	intset.c \
	item.c \
	itemset.c \
	pgen-symbol.c \
	pgenOptions.c \
	parseTable-data.c \
	normalize.c \
	Sdf2-Normalization.c  \
	parseTable-stats.c

sdf2table_SOURCES = \
	parsetablegen.isrc \
	load.c \
	main.c \
	Sdf2-Load.c 

test_chars_SOURCES	= test-chars.c 
test_chars_LDADD	= \
	-L. -lsdftablegen \
	$(ATERM_LIBS) \
	$(PT_SUPPORT_LIBS)

sdf2table_LDADD = \ 
	-L. -lsdftablegen \
	$(ASC_SUPPORT_LIBS) \
	$(SDF_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(ASF_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) \
	$(PTABLE_SUPPORT_LIBS) \
	$(CONFIG_SUPPORT_LIBS) \
	$(C_LIBRARY_LIBS)

libsdftablegen_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libsdftablegen_la_LIBADD   = \
	$(ASC_SUPPORT_LIBS) \
	$(SDF_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(ASF_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) \
	$(PTABLE_SUPPORT_LIBS) \
	$(CONFIG_SUPPORT_LIBS) \
	$(C_LIBRARY_LIBS)

CLEANFILES += \
	parse-sdf2 \
	sdf2table \
	sdf2table.test 

# we create one sdf2table that uses source tree binaries and data 
# this is needed for testing
%.test: %.src Makefile
	sed "s@__BINDIR__@$(top_builddir)/src@g;\
             s@__ACTIVATE__@0@g;\
             s@__SGLR__@$(SGLR_PREFIX)@g;\
             s@__CHECKERDIR__@$(top_builddir)/sdf-checker/src@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;\
             s@__DATADIR__@$(top_srcdir)/grammar@g;" < $< > $@ && \
	chmod +x $@

# and one sdf2table for installed binaries and data
% : %.src Makefile
	sed "s@__BINDIR__@$(bindir)@g;\
             s@__ACTIVATE__@1@g;\
             s@__PREFIX__@$(prefix)@g;\
	     s@__CHECKERDIR__@$(bindir)@g;\
             s@__SGLR__@$(SGLR_PREFIX)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;" < $< > $@ && \
	chmod +x $@

asfc: Sdf2-Normalization.eqs
	asfc -i Sdf2-Normalization.eqs -o Sdf2-Normalization.c -v

Sdf2-Normalization.eqs:
	eqs-dump -m languages/sdf2/normalization/Sdf2-Normalization -o $@

asfc-load: Sdf2-Load.eqs
	asfc -v -i Sdf2-Load.eqs -p ${top_builddir}/grammar/Sdf2.saf -o Sdf2-Load.c

Sdf2-Load.eqs:
	eqs-dump -m languages/sdf2/load/Sdf2 -o $@

