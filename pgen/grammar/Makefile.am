EXTRA_DIST = Sdf2.def Sdf2.baf
CLEANFILES = Sdf2.asfix

pkgdata_DATA = Sdf2.baf

LIBRARY_DIR = ../../asf-library/library

TOP_MODULE = languages/sdf2/syntax/Sdf2
SDF_MODULES = `find ${LIBRARY_DIR}/languages/sdf2/syntax -name '*.sdf'`
ATERM_MODULES = `find ${LIBRARY_DIR}/languages/aterm/syntax -name '*.sdf'`
BASIC_MODULES = `find ${LIBRARY_DIR}/basic -name '*.sdf'`

# For developers only!
Sdf2.def: 
	(printf "%%%% Do not edit!!!\n\ndefinition\nmodule Main\nimports ${TOP_MODULE}\n"; \
	 cat ${SDF_MODULES}; echo "" ;\
	 cat ${ATERM_MODULES}; echo "" ;\
	 cat ${BASIC_MODULES}) \
	> $@

bootstrap: Sdf2.def
	/ufs/jurgenv/glt/installed/head/bin/sglr -p $(srcdir)/Sdf2-bootstrap.tbl \
		-i $(srcdir)/Sdf2.def \
		-o Sdf2.asfix
	/ufs/jurgenv/glt/installed/head/bin/parsetablegen < Sdf2.asfix > Sdf2.baf
