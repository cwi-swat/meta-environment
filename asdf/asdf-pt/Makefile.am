EXTRA_DIST=make_rules

bin_SCRIPTS=dump_term gen_asdf_pt gen_asf gen_sdf \
	get_imports get_module_name typecheck

CLEANFILES=gen_asdf_pt gen_asf gen_sdf get_imports \
	get_module_name typecheck

SUBDIRS=asdf type-check src 

% : %.sh.src
	sed 's@__META__@${META}@g' < $< > $@ && chmod +x $@

uninstall:
	rm -rf ${pkgdatadir}/asdf-pt
