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

TESTS		= $(check_PROGRAMS)
check_PROGRAMS	= test-chars
bin_PROGRAMS	= parsetablegen
bin_SCRIPTS	= sdf2table parse-sdf2
noinst_SCRIPTS	= sdf2table.test
pkgdata_DATA	= parsetablegen.idef

EXTRA_DIST	+= sdf2table.src \
                  parse-sdf2.src 

noinst_HEADERS = \
	atsets.h \
	ksdf2table.h \
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
	parseTable-data.h \
	parseTable-stats.h

parsetablegen_SOURCES = \
	parsetablegen.idef \
	main.c \
	ksdf2table.c \
	atsets.c \
	flatten.c \
	characters.c \
	first.c \
	follow.c \
	goto.c \
	predicted.c \
	priorities.c \
	Sdf2-Normalization.c \
	intset.c \
	item.c \
	itemset.c \
	pgen-symbol.c \
	pgenOptions.c \
	parseTable-data.c \
	parseTable-stats.c

test_chars_SOURCES	= test-chars.c characters.c pgen-symbol.c
test_chars_LDADD	= \
	$(ATERM_LIBS) \
	$(PT_SUPPORT_LIBS)

parsetablegen_LDADD = \
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

