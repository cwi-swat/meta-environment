
bin_SCRIPTS	= si-cli boot-roll roll ariadne ophion

EXTRA_DIST	= $(wildcard *.sh.src)

CLEANFILES	= si-cli boot-roll roll ariadne ophion

% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__BINDIR__@$(bindir)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g;\
		s@__SUBVERSION_BINDIR__@$(SUBVERSION_PREFIX)/bin@g;\
		s@__RUBY__@$(RUBY_PREFIX)/bin/ruby@g;\
		s@__RUBYGEMS_PATH__@$(RUBYGEMS_PREFIX)/lib/ruby/site_ruby/1.8@g;\
		s@__VERSION__@$(VERSION)@g;" < $< > $@ && \
        chmod +x $@

