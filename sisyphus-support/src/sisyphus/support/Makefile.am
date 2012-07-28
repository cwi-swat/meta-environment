
SUBDIRS = model utils

RUBY_FILES = $(wildcard *.rb)

supportdir = $(pkgdatadir)/sisyphus/support

support_DATA = $(RUBY_FILES) irb-sisyphus.rb

EXTRA_DIST = $(RUBY_FILES) irb-sisyphus.rb.src

CLEANFILES = irb-sisyphus.rb


%.rb: %.rb.src
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__DATABASE_HOST__@$(DATABASE_HOST)@g; \
		s@__DATABASE_PORT__@$(DATABASE_PORT)@g; \
		s@__DATABASE_USER__@$(DATABASE_USER)@g; \
		s@__DATABASE_NAME__@$(DATABASE_NAME)@g; \
		s@__POSTGRESQL_PREFIX__@$(POSTGRESQL_PREFIX)@g; \
		s@__RUBY_PREFIX__@$(RUBY_PREFIX)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g; \
		s@__VERSION__@$(VERSION)@g;" < $< > $@
