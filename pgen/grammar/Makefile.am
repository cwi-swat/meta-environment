EXTRA_DIST = Sdf2.def Sdf2.baf
CLEANFILES = Sdf2.asfix

pkgdata_DATA = Sdf2.baf

LIBRARY_DIR = ../../sdf-library/library

TOP_MODULE = languages/sdf2/syntax/Sdf2
SDF_MODULES = `find ${LIBRARY_DIR}/languages/sdf2/syntax -name '*.sdf'`
ATERM_MODULES = `find ${LIBRARY_DIR}/languages/aterm/syntax -name '*.sdf'`
BASIC_MODULES = \
		${LIBRARY_DIR}/basic/StrCon.sdf  \
		${LIBRARY_DIR}/basic/NatCon.sdf \
	      	${LIBRARY_DIR}/basic/Comments.sdf \
	       	${LIBRARY_DIR}/basic/IdentifierCon.sdf \
	       	${LIBRARY_DIR}/basic/Whitespace.sdf

# For developers only!
Sdf2.def: 
	(printf "%%%% Do not edit!!!\n\ndefinition\nmodule Main\nimports ${TOP_MODULE}\n"; \
	 cat ${SDF_MODULES}; echo "" ;\
	 cat ${ATERM_MODULES}; echo "" ;\
	 cat ${BASIC_MODULES}) \
	> $@

bootstrap: Sdf2.def
	sglr -p $(srcdir)/Sdf2-bootstrap.tbl \
		-i $(srcdir)/Sdf2.def \
		-o Sdf2.asfix
	parsetablegen < Sdf2.asfix > Sdf2.baf
#	~markvdb/glt/asf-sdf-meta/install/bin/parsetablegen < Sdf2.asfix > Sdf2.baf
