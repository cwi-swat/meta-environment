EXTRA_DIST = $(wildcard *.sh.src)

libexec_PROGRAMS = OffSide
bin_SCRIPTS = offside
noinst_SCRIPTS = offside.test

OffSide_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
               -L$(ASF_SUPPORT)/lib -lASFME \
               -L$(PT_SUPPORT)/lib -lmept \
               -L$(ATERM)/lib -lATerm

INCLUDES  = -I$(ASC_SUPPORT)/include \
            -I$(PT_SUPPORT)/include \
            -I$(ASF_SUPPORT)/include \
            -I$(ATERM)/include \
            -DASF_MAIN


OffSide.c: $(top_srcdir)/spec/OffSide.eqs
	$(ASF)/bin/asfc -i $< -o $@ -n $* -v

% : %.sh.src Makefile
	sed 's@__DATADIR__@$(datadir)@g;\
             s@__LIBEXECDIR__@$(libexecdir)@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT)@g' < $< > $@ && chmod +x $@	

%.test: %.sh.src Makefile
	sed 's@__DATADIR__@${top_builddir}/spec@g;\
             s@__LIBEXECDIR__@${top_builddir}/src@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT)@g' < $< > $@ && chmod +x $@	



CLEANFILES += $(bin_SCRIPTS)
