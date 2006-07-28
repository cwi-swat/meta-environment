
bin_SCRIPTS     = initialize-sisyphus-database

EXTRA_DIST      = $(wildcard *.sh.src)

CLEANFILES      = initialize-sisyphus-database

% : %.sh.src
	sed "s@__PREFIX__@$(prefix)@g;\
		s@__DATABASE_HOST__@$(DATABASE_HOST)@g; \
		s@__DATABASE_PORT__@$(DATABASE_PORT)@g; \
		s@__DATABASE_USER__@$(DATABASE_USER)@g; \
		s@__DATABASE_NAME__@$(DATABASE_NAME)@g; \
		s@__POSTGRESQL_PREFIX__@$(POSTGRESQL_PREFIX)@g; \
		s@__DATA_DIR__@$(pkgdatadir)@g; \
		s@__VERSION__@$(VERSION)@g;" < $< > $@ &&  \
	chmod +x $@





