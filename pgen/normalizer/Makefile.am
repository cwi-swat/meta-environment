# $Id$

INCLUDES	= -I${ATERM}/include \
		-I${PT_SUPPORT}/include \
		-I${SDF_SUPPORT}/include \
		-I${ASF_SUPPORT}/include \
		-I${ASC_SUPPORT}/include

bin_PROGRAMS = normalizer
bin_SCRIPTS  = normalize-sdf

EXTRA_DIST   = normalize-sdf.sh.src normalize-normalize-check.sh.src \
               normalize-test.sdf

CLEANFILES   = normalize-sdf normalize-normalize-check

normalizer_SOURCES = normalizer.c asf-interface.c asf-interface.h
normalizer_LDADD   = -L$(top_builddir)/c-source -lSdf2-Normalization \
                     -L$(top_builddir)/c-lib -lnative \
                     -L$(ASC_SUPPORT)/lib -lasc-support \
                     -L$(ASF_SUPPORT)/lib -lASF \
                     -L$(SDF_SUPPORT)/lib -lSDF \
                     -L$(PT_SUPPORT)/lib -lPT \
                     -L$(ATERM)/lib -lATB -lATerm \
                     $(SOCKLIBS)

% : %.sh.src Makefile
	sed 's@__PKGDATADIR__@$(pkgdatadir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__BINDIR__@$(bindir)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__VERSION__@$(VERSION)@g;'\
	   < $< > $@
	chmod 755 $@
