EXTRA_DIST=make_rules

SUBDIRS=asf basic aterm sdf2 system \
        disambiguation containers strategies functions \
        asfix

clean:
	rm -f $(top_builddir)/src/*.lst

uninstall:
	chmod -R ugo+wr $(DESTDIR)$(pkgdatadir)
	rm -r $(DESTDIR)$(pkgdatadir)

