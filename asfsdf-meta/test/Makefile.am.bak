EXTRA_DIST = \
	timeout.tb \
	booleans-eqs.sh.src \
	test-integers-eqs.sh.src

TESTS = \
	booleans-eqs.sh \
	test-integers-eqs.sh

GENERATED_BY_TESTS = \
	test.ref \
	booleans.eqs \
	integers.eqs \
	test-integers.eqs

CLEANFILES = \
	$(TESTS) \
	$(GENERATED_BY_TESTS)

% : %.src Makefile
	sed "s@__ATERM__@$(ATERM_PREFIX)@g;\
	     s@__ASF__@$(ASF_PREFIX)@g;\
	     s@__TOP_BUILDDIR__@$(top_builddir)@g" < $< > $@ && chmod +x $@
