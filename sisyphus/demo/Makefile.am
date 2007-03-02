
SUBDIRS		= src

bin_SCRIPTS	= sisyphus-demo

CONFIG_REPO	= config-repo.tar.gz

DEMO_DB		= sisyphus-demo.db

demo_DATA 	= dbconfig.yml $(DEMO_DB)

demodir		= $(pkgdatadir)/demo

EXTRA_DIST	= \
		$(wildcard *.sh.src) \
		$(wildcard *.yml.src) \
		$(CONFIG_REPO)

CLEANFILES	= sisyphus-demo $(DEMO_DB)

$(DEMO_DB) :
	cat ${top_srcdir}/sql/si.sql \
	| sed -e 's/serial/integer/' \
	| sed -e 's/primary key/primary key autoincrement/' \
	| sed -e 's/^drop.*$$//' \
	| sqlite3 $@


% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__BIN_DIR__@$(bindir)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g;\
		s@__SUBVERSION_BINDIR__@$(SUBVERSION_PREFIX)/bin@g;\
		s@__RUBY__@$(RUBY_PREFIX)/bin/ruby@g;\
		s@__RUBYGEMS_PATH__@$(RUBYGEMS_PREFIX)/lib/ruby/site_ruby/1.8@g;\
		s@__VERSION__@$(VERSION)@g;" < $< > $@ && \
        chmod +x $@


%.yml : %.yml.src 
	sed "s@__DATABASE__@$(pkgdatadir)/demo/$(DEMO_DB)@g" < $< > $@

install-data-hook: 
	( \
		cp $(CONFIG_REPO) $(demodir); \
		cd $(DEMO_DIR); \
		gunzip -c $(CONFIG_REPO) | tar xvf - \
	)

