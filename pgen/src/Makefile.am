include $(top_srcdir)/Makefile.meta
include $(top_srcdir)/man_make_rules

TESTS		= $(check_PROGRAMS)
check_PROGRAMS	= test-chars
bin_PROGRAMS	= parsetablegen
bin_SCRIPTS	= sdf2table parse-sdf2
noinst_SCRIPTS	= sdf2table.test
pkgdata_DATA	= parsetablegen.idef
man_MANS	= sdf2table.1

EXTRA_DIST	= parsetablegen.idef.src \
                  sdf2table.src \
                  parse-sdf2.src \
                  sdf2table.pod \
                  sdf2table.1

SRCS		= parsetablegen.tif.c parsetablegen.c ksdf2table.c atsets.c \
		flatten.c characters.c first.c follow.c goto.c parse-table.c \
		predicted.c priorities.c statistics.c \
		Sdf2-Normalization.c intset.c item.c itemset.c pgen-symbol.c

HDRS         = parsetablegen.tif.h atsets.h ksdf2table.h statistics.h \
		flatten.h predicted.h goto.h follow.h intset.h \
		characters.h item.h first.h priorities.h itemset.h \
		pgen-symbol.h

AM_CPPFLAGS += \
	$(ASC_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(ASF_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS)

test_chars_SOURCES	= test-chars.c characters.c pgen-symbol.c
test_chars_LDADD	= $(ATERM_LIBS) 

parsetablegen_SOURCES = $(SRCS) $(HDRS)
parsetablegen_DEPENDENCIES = 
parsetablegen_LDADD = \
	$(ASC_SUPPORT_LIBS) \
	$(SDF_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(ASF_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS)

CLEANFILES += \
	parse-sdf2 \
	sdf2table \
	sdf2table.1 \
	sdf2table.test \
	parsetablegen.idef

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

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

