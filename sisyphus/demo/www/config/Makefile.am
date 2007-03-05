EXTRA_DIST	= database.yml.src

config_DATA 	= database.yml

CLEANFILES 	= database.yml 

configdir 	= ${pkgdatadir}/demo/www/config

database.yml: ${top_srcdir}/demo/dbconfig.yml Makefile
	echo "development:" > $@
	cat $< | sed -e "s/^\(.*\)$$/  \1/" >> $@
	echo "production:" >> $@
	echo "  development">> $@

install-data-hook: 
	ln -s -f ${pkgdatadir}/www/config/*.rb --target-directory ${pkgdatadir}/demo/www/config ;\
	ln -s -f ${pkgdatadir}/www/environments --target-directory ${pkgdatadir}/demo/www/config 


uninstall-hook:
	rm -rf ${pkgdatadir}/demo/www/config
