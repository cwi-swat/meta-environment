# $Id$

INCLUDES	= -I${ATERM}/include \
		-I${PT_SUPPORT}/include \
		-I${SDF_SUPPORT}/include \
		-I${ASF_SUPPORT}/include \
		-I${ASC_SUPPORT}/include

bin_PROGRAMS	= parsetablegen
bin_SCRIPTS	= sdf2table 
noinst_SCRIPTS	= sdf2table.test
data_DATA	= parsetablegen.idef
man_MANS	= sdf2table.1

EXTRA_DIST   = parsetablegen.idef sdf2table.src \
               parsetablegen.tif.h parsetablegen.tif.c sdf2table.pod

SRCS         = parsetablegen.c ksdf2table.c atsets.c flatten.c \
               characters.c first.c follow.c goto.c parse-table.c \
               predicted.c priorities.c reductions.c sdf-help.c statistics.c

HDRS         = atsets.h ksdf2table.h statistics.h flatten.h


parsetablegen_SOURCES = $(SRCS) $(HDRS)
parsetablegen_LDADD   = parsetablegen.tif.o \
                        -L$(top_builddir)/c-source -lSdf2-Normalization \
                        -L$(top_builddir)/c-lib -lnative \
                        -L$(ASC_SUPPORT)/lib -lasc-support \
                        -L$(PT_SUPPORT)/libasfix-old/libasfix -lAsFix \
                        -L$(PT_SUPPORT)/lib -lPT \
                        -L$(SDF_SUPPORT)/lib -lSDF \
                        -L$(ASF_SUPPORT)/lib -lASF \
                        -L$(ATERM)/lib -lATB -lATerm \
                        $(SOCKLIBS)

# remove built files during "make clean"
CLEANFILES = parsetablegen.tifs sdf2table sdf2table.1 sdf2table.test

parsetablegen.o : parsetablegen.tif.h
sdf-help.o : parsetablegen.tif.h

%.tif.c %.tif.h: %.tifs
	@PATH=$(ATERM)/bin:$(PATH) tifstoc -tool $* $<

%.tifs: %.idef
	@PATH=${TOOLBUS}/bin:${PATH} idef2tif $<
	@if [ "a${VPATH}" != "a" ]; then \
		mv ${srcdir}/$@ $@ ;\
	fi

POD2MAN	= pod2man
CENTER	= "Meta-Environment Documentation"

%.1: %.pod
	-$(POD2MAN) --center=${CENTER} --release=${VERSION} --section=1 $< > $@

# we create one sdf2table that uses source tree binaries and data 
# this is needed for testing
%.test: %.src Makefile
	sed 's@__BINDIR__@$(top_builddir)/src@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__DATADIR__@$(top_srcdir)/grammar@g;' < $< > $@ && \
	chmod +x $@

# and one sdf2table for installed binaries and data
% : %.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;' < $< > $@ && \
	chmod +x $@
