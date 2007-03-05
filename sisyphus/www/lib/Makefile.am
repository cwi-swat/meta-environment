include $(top_srcdir)/www/make_rules

SUBDIRS = tasks

EXTRA_DIST += $(wildcard *.rb.src)

CLEANFILES = graphviz.rb

www_DATA += graphviz.rb

%.rb : %.rb.src Makefile
	sed "s@__GRAPHVIZ__@$(GRAPHVIZ_PREFIX)@g" < $< > $@
