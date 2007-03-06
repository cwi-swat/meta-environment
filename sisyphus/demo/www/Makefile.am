
SUBDIRS		= config

www_DATA 	=

wwwdir		= $(pkgdatadir)/demo/www

install-data-hook: 
	ln -s -f $(DESTDIR)${pkgdatadir}/www/script $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/log $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/components $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/public $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/vendor $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/test $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/doc $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/app $(DESTDIR)$(wwwdir)/ ;\
	ln -s -f $(DESTDIR)${pkgdatadir}/www/lib $(DESTDIR)$(wwwdir)/

uninstall-hook:
	rm -rf $(DESTDIR)$(wwwdir)