# $Id$

include ${top_srcdir}/make_rules

INCLUDES	  = -I$(PT_SUPPORT)/include -I$(ATERM)/include

bin_PROGRAMS	  = apply-function concat-asf

bin_SCRIPTS	  = genmakefile genamakefile

data_DATA         = genmakefile.proto
EXTRA_DIST	  = genamakefile.sh.src genmakefile.proto

GENERIC_LDADD = -L$(PT_SUPPORT)/lib -lmept \
         	-L$(ATERM)/lib -lATerm

apply_function_SOURCES	= apply-function.c
apply_function_LDADD   = $(GENERIC_LDADD)

concat_asf = concat-asf.c
concat_asf_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME $(GENERIC_LDADD)

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
             s@__DATADIR__@$(datadir)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
             s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
             s@__VERSION__@$(VERSION)@g;\
             s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@

