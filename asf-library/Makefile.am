SUBDIRS=asf basic containers functions aterm system sdf2 \
        strategies disambiguation

Everything.sdf:
	echo "module Everything " > $@;
	for i in `find . -name "*.sdf"`; do \
          echo "imports $$i" | sed 's/\.\///g;s/\.sdf//g' >> $@; \
        done
 
clean:
	rm -f $(top_builddir)/src/*.lst

uninstall:
	chmod -R ugo+wr $(DESTDIR)$(pkgdatadir)
	rm -r $(DESTDIR)$(pkgdatadir)

