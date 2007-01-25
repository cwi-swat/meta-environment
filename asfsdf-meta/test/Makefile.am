EXTRA_DIST = \
	timeout.tb \
	booleans-eqs.sh.src

TESTS = \
	booleans-eqs.sh

GENERATED_BY_TESTS = \
	booleans.eqs

CLEANFILES = \
	$(TESTS) \
	$(GENERATED_BY_TESTS)

% : %.src Makefile
	sed "s@__TOP_BUILDDIR__@$(top_builddir)@g" < $< > $@
	chmod +x $@
