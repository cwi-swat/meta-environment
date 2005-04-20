include $(top_srcdir)/make_rules

bin_PROGRAMS    = RscriptCalculator Rstore RscriptTestsuites

RscriptCalculator_SOURCES	= RscriptCalculator.c

Rstore_SOURCES	= Rstore.c

RscriptTestsuites_SOURCES = RscriptTestsuites.c

EXTRA_DIST      = $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  $(wildcard *.tbl) \
		  $(wildcard *.eqs) \
		  meta.buttons.installed \
		  meta.conf.installed

CLEANFILES =  meta.buttons.installed meta.conf.installed


specdir         = $(pkgdatadir)

spec_DATA        = Rscript.trm.tbl \
                  Rstore.trm.tbl \
		  $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  meta.buttons.installed \
		  meta.conf.installed


# This is kinda iffy...
%.conf.installed : %.conf Makefile
	sed 's@\.\.@$(pkgdatadir)@g;' < $< \
		| sed 's@\.@$(pkgdatadir)@g;' > $@

%.buttons.installed : %.buttons Makefile
	sed 's@\./@$(bindir)/@g;' < $< > $@

