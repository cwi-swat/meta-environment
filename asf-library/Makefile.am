SUBDIRS=asf basic aterm sdf2 system \
        disambiguation containers strategies functions 

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

