include $(top_srcdir)/make_rules

# ---- extract-java

bin_SCRIPTS 	= extract-java

EXTRA_DIST	= $(wildcard *.sh.src)

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

EXTRA_DIST 	+= $(JAVAEXTRACTION)

javaextraction_DATA = $(JAVAEXTRACTION)



