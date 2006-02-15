include $(top_srcdir)/make_rules

TESTS		= test-chars


INCLUDES	= \
		  ${ASC_INCLUDES} \
		  -I${SDF_SUPPORT}/include

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

test_chars_SOURCES	= test-chars.c characters.c pgen-symbol.c
test_chars_LDADD	= -L$(ATERM)/lib -lATerm \
                        $(SOCKLIBS)


parsetablegen_SOURCES = $(SRCS) $(HDRS)
parsetablegen_DEPENDENCIES = 
parsetablegen_LDADD   = -L$(SDF_SUPPORT)/lib -lSDFME -lSDF2PT $(ASC_LD_FLAGS) 

CLEANFILES = \
	parse-sdf2 \
	sdf2table \
	sdf2table.1 \
	sdf2table.test \
	parsetablegen.idef

# we create one sdf2table that uses source tree binaries and data 
# this is needed for testing
%.test: %.src Makefile
	sed 's@__BINDIR__@$(top_builddir)/src@g;\
             s@__ACTIVATE__@0@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
             s@__DATADIR__@$(top_srcdir)/grammar@g;' < $< > $@ && \
	chmod +x $@

# and one sdf2table for installed binaries and data
% : %.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
             s@__ACTIVATE__@1@g;\
             s@__PREFIX__@${prefix}@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;' < $< > $@ && \
	chmod +x $@

asfc: Sdf2-Normalization.eqs
	asfc -i Sdf2-Normalization.eqs -o Sdf2-Normalization.c -v

Sdf2-Normalization.eqs:
	eqs-dump -m languages/sdf2/normalization/Sdf2-Normalization -o $@

