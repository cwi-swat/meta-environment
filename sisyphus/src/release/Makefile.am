
RUBY_FILES = $(wildcard *.rb)

releasedir = $(pkgdatadir)/release

release_DATA = $(RUBY_FILES)

EXTRA_DIST = $(RUBY_FILES) test.sh.src

CLEANFILES = test

noinst_SCRIPTS = test

% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__BINDIR__@$(bindir)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g;\
		s@__SUBVERSION_BINDIR__@$(SUBVERSION)/bin@g;\
		s@__RUBY__@$(RUBY)/bin/ruby@g;\
		s@__RUBYGEMS_PATH__@$(RUBYGEMS)/lib/ruby/site_ruby/1.8@g;\
		s@__VERSION__@$(VERSION)@g;" < $< > $@ && \
        chmod +x $@




