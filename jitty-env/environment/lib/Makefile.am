EXTRA_DIST=make_rules

SUBDIRS=syntax

clean:
	rm -f $(top_builddir)/src/*.lst

uninstall:
	chmod -R ugo+wr $(DESTDIR)$(pkgdatadir)
	rm -r $(DESTDIR)$(pkgdatadir)

