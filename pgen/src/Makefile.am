include $(top_srcdir)/make_rules

TESTS		= test-chars

INCLUDES	= -I${ATERM}/include \
		-I${TOOLBUSLIB}/include \
		-I${PT_SUPPORT}/include \
		-I${SDF_SUPPORT}/include \
		-I${ASF_SUPPORT}/include \
		-I${ASC_SUPPORT}/include

check_PROGRAMS	= test-chars
bin_PROGRAMS	= parsetablegen
bin_SCRIPTS	= sdf2table parse-sdf2
noinst_SCRIPTS	= sdf2table.test
pkgdata_DATA	= parsetablegen.idef
man_MANS	= sdf2table.1

EXTRA_DIST	= parsetablegen.idef \
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
parsetablegen_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
                        -L$(SDF_SUPPORT)/lib -lSDFME -lSDF2PT \
                        -L$(ASF_SUPPORT)/lib -lASFME \
                        -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
                        -L$(TOOLBUSLIB)/lib -lATB \
                        -L$(ATERM)/lib -lATerm \
                        $(SOCKLIBS)

CLEANFILES	= sdf2table sdf2table.1 \
		  sdf2table.test 

# we create one sdf2table that uses source tree binaries and data 
# this is needed for testing
%.test: %.src Makefile
	sed 's@__BINDIR__@$(top_builddir)/src@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__DATADIR__@$(top_builddir)/grammar@g;' < $< > $@ && \
	chmod +x $@

# and one sdf2table for installed binaries and data
% : %.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;' < $< > $@ && \
	chmod +x $@
