
SUBDIRS		= src www

bin_SCRIPTS	= sisyphus-demo-client \
			sisyphus-demo-console \
			sisyphus-demo-web \
			checkout-demo-config \
			checkout-demo-sources

SOURCE_REPO	= source-repo

CONFIG_REPO	= config-repo

SOURCE_REPO_TAR = $(SOURCE_REPO).tar.gz

CONFIG_REPO_TAR	= $(CONFIG_REPO).tar.gz

demo_DATA 	= 

demodir		= $(pkgdatadir)/demo

EXTRA_DIST	= \
		$(wildcard *.sh.src) \
		$(wildcard *.yml.src) \
		$(CONFIG_REPO_TAR) \
		$(SOURCE_REPO_TAR)

CLEANFILES	= sisyphus-demo-client \
			sisyphus-demo-console \
			sisyphus-demo-web \
			checkout-demo-config \
			checkout-demo-sources

dbconfig.yml: www/config/database.yml Makefile
	cat $< | head -n 3 | tail -2 | sed -e 's/  //' > $@

backup:
	cd $(demodir) ; \
	tar zcvf $(CONFIG_REPO_TAR) $(CONFIG_REPO); \
	cd - ; \
	cp $(demodir)/$(CONFIG_REPO_TAR) . ; \
	cd $(demodir) ; \
	tar zcvf $(SOURCE_REPO_TAR) $(SOURCE_REPO); \
	cd - ; \
	cp $(demodir)/$(SOURCE_REPO_TAR) . 

% : %.sh.src Makefile
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__BIN_DIR__@$(bindir)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g;\
		s@__SUBVERSION_BINDIR__@$(SUBVERSION_PREFIX)/bin@g;\
		s@__RUBY__@$(RUBY_PREFIX)/bin/ruby@g;\
		s@__RUBYGEMS_PATH__@$(RUBYGEMS_PREFIX)/lib/ruby/site_ruby/1.8@g;\
		s@__VERSION__@$(VERSION)@g;" < $< > $@ && \
        chmod +x $@


#sed --in-place -e 's/location: .*$/location: bla/' sources.yml

install-data-hook: 
	( \
		rm -rf $(demodir)/$(CONFIG_REPO); \
		cp $(CONFIG_REPO_TAR) $(demodir); \
		cd $(demodir); \
		gunzip -c $(CONFIG_REPO_TAR) | tar xvf -  \
	) ; \
	( \
		$(SUBVERSION_PREFIX)/bin/svn co \
			file://$(demodir)/$(CONFIG_REPO)/demo DEMO_CONFIG ; \
		cd DEMO_CONFIG/config ; \
		sed --in-place -e \
			's@location: .*$$@location: $(demodir)/$(SOURCE_REPO)@' \
			sources.yml ; \
		$(SUBVERSION_PREFIX)/bin/svn commit \
			 -m "Updated demo source repository location" ; \
		cd ../../ ; \
		rm -rf DEMO_CONFIG \
	) ; \
	( \
		rm -rf $(demodir)/$(SOURCE_REPO); \
		cp $(SOURCE_REPO_TAR) $(demodir); \
		cd $(demodir); \
		gunzip -c $(SOURCE_REPO_TAR) | tar xvf - \
	)

