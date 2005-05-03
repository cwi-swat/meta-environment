include $(top_srcdir)/make_rules

bin_PROGRAMS    = RscriptCalculator Rstore RscriptTestsuites RscriptChecker

RscriptCalculator_SOURCES	= RscriptCalculator.c

Rstore_SOURCES	= Rstore.c

RscriptTestsuites_SOURCES = RscriptTestsuites.c

RscriptChecker_SOURCES = RscriptChecker.c

EXTRA_DIST      = $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  $(wildcard *.tbl) \
		  $(wildcard *.eqs) \
		  meta.buttons \
		  meta.conf

CLEANFILES =     rscript.meta.buttons \
		 rscript.meta.conf \
		 Rscript.trm.tbl \
		 Rstore.trm.tbl


specdir         = $(pkgdatadir)

spec_DATA        = Rscript.trm.tbl \
                   Rstore.trm.tbl \
	           $(wildcard *.sdf) \
		   $(wildcard *.asf) \
		   rscript.meta.buttons \
		   rscript.meta.conf

rscript.meta.conf : meta.conf Makefile
	sed 's@^\.\./@$(pkgdatadir)/@g;\
	     s@^\.@$(pkgdatadir)/@g;' < $< > $@

rscript.meta.buttons : meta.buttons Makefile
	sed 's@\./@$(bindir)/@g;' < $< > $@

