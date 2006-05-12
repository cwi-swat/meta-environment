
bin_SCRIPTS	= si-cli boot-roll roll

EXTRA_DIST	= $(wildcard *.sh.src)

CLEANFILES	= si-cli boot-roll roll

% : %.sh.src 
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__BINDIR__@$(bindir)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g;\
		s@__SUBVERSION_BINDIR__@$(SUBVERSION)/bin@g;\
		s@__RUBY__@$(RUBY)/bin/ruby@g;\
		s@__RUBYGEMS_PATH__@$(RUBYGEMS)/lib/ruby/site_ruby/1.8@g;\
		s@__VERSION__@$(VERSION)@g;" < $< > $@ && \
        chmod +x $@


