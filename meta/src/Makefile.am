# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST  = generic-meta.sh.src 

bin_SCRIPTS = generic-meta 

CLEANFILES  = generic-meta meta.1 

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__METASTUDIO_DEF__@$(METASTUDIO_DEF)@g;\
	     s@__ATERM__@$(ATERM)@g;\
	     s@__TOOLBUS__@$(TOOLBUS)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__XEMACS__@$(XEMACS)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;' < $< > $@ && \
	chmod +x $@


