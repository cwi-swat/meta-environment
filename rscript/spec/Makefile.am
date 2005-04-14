include $(top_srcdir)/make_rules

bin_PROGRAMS    = RscriptCalculator Rstore RscriptTestsuites

RscriptCalculator_SOURCES	= RscriptCalculator.c

Rstore_SOURCES	= Rstore.c

RscriptTestsuites_SOURCES = RscriptTestsuites.c

EXTRA_DIST      = $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  $(wildcard *.tbl) \
		  $(wildcard *.eqs) \
		  meta.buttons

specdir         = $(pkgdatadir)

spec_DATA        = Rscript.trm.tbl \
                  Rstore.trm.tbl \
		  $(wildcard *.sdf) \
		  $(wildcard *.asf) 

