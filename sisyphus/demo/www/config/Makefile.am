EXTRA_DIST	= database.yml.src

DEMO_DB		= sisyphus-demo.db

config_DATA 	= database.yml $(DEMO_DB)

configdir 	= ${pkgdatadir}/demo/www/config

CLEANFILES 	= database.yml $(DEMO_DB)

$(DEMO_DB) : ${top_srcdir}/sql/sisyphus.sql Makefile
	rm -f $@ ; \
	cat $< \
	| sed -e 's/serial/integer/' \
	| sed -e 's/primary key/primary key autoincrement/' \
	| sed -e 's/^drop.*$$//' \
	| sqlite3 $@ ; \
	echo "insert into si_components values (null, 'meta-autotools');" | sqlite3 $@ ; \
	echo "insert into si_components values (null, 'meta-build-env');" | sqlite3 $@ ; \
	echo "insert into si_components values (null, 'aterm');" | sqlite3 $@ ; \
	echo "insert into si_components values (null, 'balanced-binary-aterms');" | sqlite3 $@ ; \
	echo "insert into si_components values (null, 'relational-aterms');" | sqlite3 $@ 


%.yml : %.yml.src Makefile
	sed "s@__DATABASE__@$(configdir)/$(DEMO_DB)@g" < $< > $@

install-data-hook: 
	ln -s -f $(DESTDIR)${pkgdatadir}/www/config/*.rb $(DESTDIR)$(configdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/config/environments $(DESTDIR)$(configdir)/ 

uninstall-hook:
	rm -rf $(DESTDIR)$(configdir)
