EXTRA_DIST = Sdf2.def Sdf2-bootstrap.tbl
CLEANFILES = Sdf2.baf Sdf2.asfix

pkgdata_DATA = Sdf2.baf

%.baf: %.asfix
	${top_builddir}/src/parsetablegen < $< > $@
	
%.asfix: %.def
	${SGLR}/bin/sglr \
		-m \
		-p $(srcdir)/Sdf2-bootstrap.tbl \
		-i $(srcdir)/Sdf2.def \
		-o $@

LIBRARY_DIR = ../../asf/library

TOP_MODULE = sdf2/syntax/Sdf2
SDF_MODULES = `find ${LIBRARY_DIR}/sdf2/syntax -name '*.sdf'`
ATERM_MODULES = `find ${LIBRARY_DIR}/aterm -name '*.sdf'`

# For developers only!
Sdf2.def: 
	(printf "%%%% Do not edit!!!\n\ndefinition\nmodule Main\nimports ${TOP_MODULE}\n"; \
	 cat ${SDF_MODULES}; \
	 cat ${ATERM_MODULES}) \
	> $@
