# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS       = meta-paths imports
bin_SCRIPTS        = ps-dot sdf2stats metascript

data_DATA          = lang.types

noinst_LIBRARIES   = libutils.a

EXTRA_DIST         = ps-dot.sh.src test-help test-version \
                     lang.types sdf2stats.sh.src 

CLEANFILES         = ps-dot sdf2stats

meta_paths_SOURCES = meta-paths.c
meta_paths_LDADD   = libutils.a \
                     -L$(ATERM)/lib -lATerm

imports_SOURCES    = imports.c
imports_LDADD      = libutils.a \
                     -L$(SDF_SUPPORT)/lib -lSDFME \
                     -L$(PT_SUPPORT)/lib -lmept \
                     -L$(ATERM)/lib -lATerm

libutils_a_SOURCES = meta-utils.c meta-utils.h module-utils.c module-utils.h

INCLUDES           = -I$(SDF_SUPPORT)/include \
                     -I$(PT_SUPPORT)/include \
                     -I$(ATERM)/include

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
	     s@__VERSION__@$(VERSION)@g;\
	     s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@

%: %.pl.src Makefile
	sed 's@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@
