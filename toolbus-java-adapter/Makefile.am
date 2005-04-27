# $Id$

include $(top_srcdir)/java_make_rules

SUBDIRS = script

ACLOCAL_FLAGS = -I .

TOOLNAME = toolbus-java-adapter
JARFILE = $(TOOLNAME)-$(VERSION).jar

bin_SCRIPTS = $(TOOLNAME)-config tifstojava
pkgdata_DATA = $(JARFILE)
noinst_SCRIPTS = $(TOOLNAME)-$(VERSION).pkg

EXTRA_DIST = package build.xml $(JARFILE) 

CLEANFILES = \
	$(TOOLNAME)-$(VERSION).pkg \
	$(TOOLNAME)-config \
	tifstojava

$(TOOLNAME)-$(VERSION).pkg: package Makefile
	cp $< $@

$(TOOLNAME)-config: Makefile
	echo "#! /bin/sh" > $@
	echo "echo $(pkgdatadir)/$(JARFILE):$(EXTERNAL_JARS)" >> $@
	chmod +x $@

tifstojava: Makefile
	(echo "#! /bin/sh " ;\
	 printf "java -classpath $(EXTERNAL_JARS) -jar $(pkgdatadir)/$(JARFILE) \0044\0100\n" ) > $@ && chmod +x $@
