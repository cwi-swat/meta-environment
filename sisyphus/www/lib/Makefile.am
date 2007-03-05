include $(top_srcdir)/www/make_rules

SUBDIRS = tasks

EXTRA_DIST += $(wildcard *.rb.src)

CLEANFILES = graphviz.rb subversion.rb

www_DATA += graphviz.rb subversion.rb

%.rb : %.rb.src Makefile
	sed "s@__GRAPHVIZ__@$(GRAPHVIZ_PREFIX)@g;\
		s@__SUBVERSION__@$(SUBVERSION_PREFIX)@g" < $< > $@
