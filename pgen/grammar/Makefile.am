pkgdata_DATA = Sdf2.baf

EXTRA_DIST = Sdf2.sdf2 Sdf2-bootstrap.tbl
CLEANFILES = Sdf2.baf

TABLEGEN=${top_builddir}/src/parsetablegen

%.baf : %.asfix
	$(TABLEGEN) < $< > $@
	
%.asfix : %.sdf2
	PATH=$(SGLR)/bin:$$PATH; export PATH ;\
	sglr -p $(srcdir)/Sdf2-bootstrap.tbl -1 -i $(srcdir)/Sdf2.sdf2 -o $@

