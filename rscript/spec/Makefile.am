EXTRA_DIST=make_rules

SUBDIRS=languages

dump_run : 
	eqs-dump -m languages/rscript/run/Rscript -o ../bin/run/RScript-Calculator.eqs

dump_test : 
	eqs-dump -m languages/rscript/test/Rscript -o ../bin/test/RScript-Test-Suite.eqs


#bin_PROGRAMS    = RscriptCalculator Rstore RscriptTestsuites RscriptChecker
#
#RscriptCalculator_SOURCES	= RscriptCalculator.c
#
#Rstore_SOURCES	= Rstore.c
#
#RscriptTestsuites_SOURCES = RscriptTestsuites.c
#
#RscriptChecker_SOURCES = RscriptChecker.c
#
#EXTRA_DIST      = $(wildcard *.tbl) \
#		  $(wildcard *.eqs) \
#		  meta.buttons \
#		  meta.conf
#
#CLEANFILES =     rscript.meta.buttons \
#		 rscript.meta.conf \
#		 Rscript.trm.tbl \
#		 Rstore.trm.tbl
#
#
#specdir         = $(pkgdatadir)
#
#spec_DATA        = Rscript.trm.tbl \
#                   Rstore.trm.tbl \
#		   rscript.meta.buttons \
#		   rscript.meta.conf
#
#rscript.meta.conf : meta.conf Makefile
#	sed 's@^\.\./@$(pkgdatadir)/@g;\
#	     s@^\.@$(pkgdatadir)/@g;' < $< > $@
#
#rscript.meta.buttons : meta.buttons Makefile
#	sed 's@\./@$(bindir)/@g;' < $< > $@
#
#include $(top_srcdir)/make_rules
#
#RscriptCalculator.c: relation-calculus/RscriptCalculator.c
#	cp $< $@
