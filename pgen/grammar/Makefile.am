EXTRA_DIST = Sdf2.sdf2 Sdf2-bootstrap.tbl
CLEANFILES = Sdf2.baf

pkgdata_DATA = Sdf2.baf

%.baf: %.asfix
	${top_builddir}/src/parsetablegen < $< > $@
	
%.asfix: %.sdf2
	${SGLR}/bin/sglr \
		-p $(srcdir)/Sdf2-bootstrap.tbl \
		-i $(srcdir)/Sdf2.sdf2 \
		-o $@

