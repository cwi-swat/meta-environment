EXTRA_DIST=make_rules

bin_SCRIPTS=dump_term eval_action gen_asdf_pt gen_asf gen_sdf \
	get_imports get_module_name

CLEANFILES=eval_action gen_asdf_pt gen_asf gen_sdf get_imports get_module_name

SUBDIRS=asdf src

% : %.sh.src
	sed 's@__META__@${META}@g' < $< > $@ && chmod +x $@

uninstall:
	rm -rf ${pkgdatadir}/asdf-pt
