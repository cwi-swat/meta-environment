
SUBDIRS		= src www

bin_SCRIPTS	= sisyphus-demo

CONFIG_REPO	= config-repo

CONFIG_REPO_TAR	= $(CONFIG_REPO).tar.gz

DEMO_CONFIG	= dbconfig.yml

demo_DATA 	= $(DEMO_CONFIG)

demodir		= $(pkgdatadir)/demo

EXTRA_DIST	= \
		$(wildcard *.sh.src) \
		$(wildcard *.yml.src) \
		$(CONFIG_REPO_TAR)

CLEANFILES	= sisyphus-demo $(DEMO_CONFIG)

dbconfig.yml: www/config/database.yml Makefile
	cat $< | head -n 3 | tail -2 | sed -e 's/  //' > $@

backup:
	cd $(demodir) ; \
	tar zcvf $(CONFIG_REPO_TAR) $(CONFIG_REPO); \
	cd - ; \
	cp $(demodir)/$(CONFIG_REPO_TAR) . 

% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__BIN_DIR__@$(bindir)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g;\
		s@__SUBVERSION_BINDIR__@$(SUBVERSION_PREFIX)/bin@g;\
		s@__RUBY__@$(RUBY_PREFIX)/bin/ruby@g;\
		s@__RUBYGEMS_PATH__@$(RUBYGEMS_PREFIX)/lib/ruby/site_ruby/1.8@g;\
		s@__VERSION__@$(VERSION)@g;" < $< > $@ && \
        chmod +x $@

install-data-hook: 
	( \
		rm -rf $(demodir)/$(CONFIG_REPO); \
		cp $(CONFIG_REPO_TAR) $(demodir); \
		cd $(demodir); \
		gunzip -c $(CONFIG_REPO_TAR) | tar xvf - \
	)

