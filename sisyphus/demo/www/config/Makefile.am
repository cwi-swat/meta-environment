EXTRA_DIST	= database.yml.src

DEMO_DB		= sisyphus-demo.db

config_DATA 	= database.yml $(DEMO_DB)

configdir 	= ${pkgdatadir}/demo/www/config

CLEANFILES 	= database.yml $(DEMO_DB)

# This presumes the sql stuff is installed before the demo...
# So you can't make the DB when doing just make...
$(DEMO_DB) : 
	cat $(pkgdatadir)/sql/sisyphus.sqlite3 | sqlite3 $@

%.yml : %.yml.src Makefile
	sed "s@__DATABASE__@$(configdir)/$(DEMO_DB)@g" < $< > $@

install-data-hook: 
	ln -s -f ${pkgdatadir}/www/config/*.rb --target-directory ${pkgdatadir}/demo/www/config ;\
	ln -s -f ${pkgdatadir}/www/environments --target-directory ${pkgdatadir}/demo/www/config 

uninstall-hook:
	rm -rf ${pkgdatadir}/demo/www/config
