# $Id$

include $(top_srcdir)/java_make_rules

SUBDIRS = script

ACLOCAL_FLAGS = -I .

TOOLNAME = toolbus-java-adapter
PACKAGE = toolbus
JARFILE = $(TOOLNAME)-$(VERSION).jar

bin_SCRIPTS = $(TOOLNAME)-config
pkgdata_DATA = $(JARFILE)
noinst_SCRIPTS = $(TOOLNAME)-$(VERSION).pkg

EXTRA_DIST = package build.xml $(JARFILE) 

CLEANFILES = \
	$(TOOLNAME)-$(VERSION).pkg \
	$(TOOLNAME)-config

$(TOOLNAME)-$(VERSION).pkg: package Makefile
	cp $< $@

$(TOOLNAME)-config: Makefile
	echo "#! /bin/sh" > $@
	echo "echo $(pkgdatadir)/$(JARFILE):$(EXTERNAL_JARS)" >> $@
	chmod +x $@
