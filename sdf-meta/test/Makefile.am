EXTRA_DIST = \
	timeout.tb \
	pt-dump.sh.src \
	def-dump.sh.src

TESTS = \
	pt-dump.sh \
	def-dump.sh

GENERATED_BY_TESTS = \
	test.ref \
	booleans.def \
	booleans.pt

CLEANFILES = \
	$(TESTS) \
	$(GENERATED_BY_TESTS)

% : %.src Makefile
	sed "s@__TOP_BUILDDIR__@$(top_builddir)@g" < $< > $@
	chmod +x $@
