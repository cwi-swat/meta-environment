# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST  = meta.sh.src pt-dump.sh.src eqs-dump.sh.src meta.pod meta.1

bin_SCRIPTS = meta pt-dump eqs-dump

man_MANS    = meta.1

CLEANFILES  = meta meta.1 pt-dump eqs-dump

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__METASTUDIO_DEF__@$(METASTUDIO_DEF)@g;\
	     s@__ATERM__@$(ATERM)@g;\
	     s@__TOOLBUS__@$(TOOLBUS)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__ASF__@$(ASF)@g;\
	     s@__ASF_LIBRARY__@$(ASF_LIBRARY)@g;\
	     s@__WISH__@$(WISH)@g;\
	     s@__XEMACS__@$(XEMACS)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;' < $< > $@ && \
	chmod +x $@


