include $(top_srcdir)/make_rules

bin_PROGRAMS    = RscriptCalculator Rstore

pkgdata_DATA    = Rscript.trm.tbl Rstore.trm.tbl RscriptChecker.eqs

EXTRA_DIST      = $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  $(wildcard *.tbl) \
		  $(wildcard *.eqs)

RscriptCalculator_SOURCES	= RscriptCalculator.c

Rstore_SOURCES	= Rstore.c


