# $Id$

include ${top_srcdir}/make_rules

SUBDIRS     = config editors graph-browser \
              in-output module-db utils tbscripts demo \
              configuration-manager

EXTRA_DIST  = make_rules meta.sh.src meta.pod reconf

bin_SCRIPTS = meta

man_MANS    = meta.1

CLEANFILES  = meta meta.1

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__ATERM__@$(ATERM)@g;\
	     s@__TOOLBUS__@$(TOOLBUS)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__ASF__@$(ASF)@g;\
	     s@__WISH__@$(WISH)@g;\
	     s@__XEMACS__@$(XEMACS)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;' < $< > $@ && \
	chmod +x $@


