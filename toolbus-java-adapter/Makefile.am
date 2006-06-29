# $Id$

include $(top_srcdir)/java_make_rules

SUBDIRS = script

ACLOCAL_FLAGS = -I .

TOOLNAME = toolbus-java-adapter
JARFILE = $(TOOLNAME)-$(VERSION).jar
JAVA_PACKAGE = toolbus
MAIN_CLASS = $(JAVA_PACKAGE).JavaTif

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
JAVA_PACKAGES=toolbus
