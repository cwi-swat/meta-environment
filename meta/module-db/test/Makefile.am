# $Id$

TESTS      = module-db-test

TBSCRIPTS =  module-db-test-1.tb.src module-db-test-2.tb.src \
             module-db-test-3.tb.src module-db-test-4.tb.src

noinst_SCRIPTS = ${TBSCRIPTS:.src=}

EXTRA_DIST = Pico-Booleans.asf Pico-Booleans.asf.baf Pico-Booleans.sdf \
             Pico-Booleans.sdf.baf Test.asf Test.sdf Test.sdf.baf \
             module-db-test.src ${TBSCRIPTS}

CLEANFILES = module-db-test ${TBSCRIPTS:.src=}

% : %.src Makefile
	sed 's@__TOOLBUS__@$(TOOLBUS)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__SRCDIR__@$(srcdir)@g;\
	     s@__TOP_SRCDIR__@$(top_srcdir)@g;\
	     s@__BUILDDIR__@$(top_builddir)/module-db/test@g;\
	     s@__TOP_BUILDDIR__@$(top_builddir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g' < $< >$@ && \
	chmod +x $@

	
