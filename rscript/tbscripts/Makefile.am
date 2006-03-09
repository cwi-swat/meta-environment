
EXTRA_DIST = standard.relation-calculus.actions.src

pkgdata_DATA = standard.relation-calculus.actions
CLEANFILES=${pkgdata_DATA}

standard.relation-calculus.actions:  standard.relation-calculus.actions.src Makefile
	sed 's@__LIBRARY__@${ASF_LIBRARY}/share/relation-calculus/library@g' < $< > $@
