include $(top_srcdir)/make_rules

# ---- extract-java

bin_SCRIPTS 	= extract-java

bin_PROGRAMS	= JavaAnalysis

pkgdata_DATA    =  $(wildcard *.sdf) \
		   $(wildcard *.asf) 

EXTRA_DIST	= $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  $(wildcard *.tbl) \
		  $(wildcard *.eqs) \
		  meta.buttons \
		  meta.conf

CLEANFILES	= extract-java

# ---- dumped extraction specification

javadir         = $(pkgdatadir)/demo/java

# ---- extraction specification itself

javaextractiondir= $(pkgdatadir)/demo/java/extraction

JAVAEXTRACTION 	=  \
		  JavaAnalysis.eqs \
		  $(wildcard *.sdf) \
		  $(wildcard *.asf) \
		  meta.buttons \
		  meta.conf

JavaAnalysis_SOURCES = JavaAnalysis.c

javaextraction_DATA = $(JAVAEXTRACTION)



