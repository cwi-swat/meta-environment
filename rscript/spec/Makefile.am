include $(top_srcdir)/make_rules

bin_PROGRAMS    = RscriptCalculator Rstore RscriptTestsuites

pkgdata_DATA    = Rscript.trm.tbl Rstore.trm.tbl \
			$(wildcard *.sdf) \
			$(wildcard *.asf) 

EXTRA_DIST      = $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  $(wildcard *.tbl) \
		  $(wildcard *.eqs) \
		  meta.buttons

RscriptCalculator_SOURCES	= RscriptCalculator.c

Rstore_SOURCES	= Rstore.c

RscriptTestsuites_SOURCES = RscriptTestsuites.c


